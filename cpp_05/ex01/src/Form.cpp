/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 23:54:02 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/14 00:46:45 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructeurs et destructeur
Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& src) : _name(src._name), _signed(src._signed), 
      _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {
}

Form::~Form() {
}

// Opérateur d'affectation
Form& Form::operator=(const Form& rhs) {
    if (this != &rhs) {
        // On ne peut pas modifier les constantes (_name, _gradeToSign, _gradeToExecute)
        _signed = rhs._signed;
    }
    return *this;
}

// Getters
const std::string& Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

// Fonction de signature
void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

// Classes d'exception
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade trop élevé";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade trop bas";
}

// Surcharge de l'opérateur de flux
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << ":"
       << "\n - Signé: " << (form.isSigned() ? "Oui" : "Non")
       << "\n - Grade requis pour signer: " << form.getGradeToSign()
       << "\n - Grade requis pour exécuter: " << form.getGradeToExecute();
    return os;
}