/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:09:15 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/15 17:53:06 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructeurs et destructeur
AForm::AForm() 
    : _name("default"), _signed(false), _gradeToSign(150), 
      _gradeToExecute(150), _target("default") {
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), 
      _gradeToExecute(gradeToExecute), _target(target) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) 
    : _name(src._name), _signed(src._signed), 
      _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute),
      _target(src._target) {
}

AForm::~AForm() {
}

// Opérateur d'affectation
AForm& AForm::operator=(const AForm& rhs) {
    if (this != &rhs) {
        // On ne peut pas modifier les constantes (_name, _gradeToSign, _gradeToExecute, _target)
        _signed = rhs._signed;
    }
    return *this;
}

// Getters
const std::string& AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

const std::string& AForm::getTarget() const {
    return _target;
}

// Fonction de signature
void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

// Fonction d'exécution
void AForm::execute(Bureaucrat const& executor) const {
    if (!_signed)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw AForm::GradeTooLowException();
    action();
}

// Classes d'exception
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade trop élevé";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade trop bas";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Formulaire non signé";
}

// Surcharge de l'opérateur de flux
std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Formulaire " << form.getName() << ":"
       << "\n - Cible: " << form.getTarget()
       << "\n - Signé: " << (form.isSigned() ? "Oui" : "Non")
       << "\n - Grade requis pour signer: " << form.getGradeToSign()
       << "\n - Grade requis pour exécuter: " << form.getGradeToExecute();
    return os;
}