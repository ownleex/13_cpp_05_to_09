/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:11:02 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/15 17:46:40 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructeurs et destructeur
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {
}

Bureaucrat::~Bureaucrat() {
}

// Opérateur d'affectation
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
    if (this != &rhs) {
        // On ne peut pas modifier _name car c'est une constante
        _grade = rhs._grade;
    }
    return *this;
}

// Getters
const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// Fonctions de modification du grade
void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

// Fonction pour signer un formulaire
void Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " a signé " << form.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << _name << " n'a pas pu signer " << form.getName() 
                  << " car " << e.what() << std::endl;
    }
}

// Fonction pour exécuter un formulaire
void Bureaucrat::executeForm(AForm const& form) const {
    try {
        form.execute(*this);
        std::cout << _name << " a exécuté " << form.getName() << std::endl;
    }
    catch (std::exception& e) {
        std::cout << _name << " n'a pas pu exécuter " << form.getName() 
                  << " car " << e.what() << std::endl;
    }
}

// Classes d'exception
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade trop élevé";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade trop bas";
}

// Surcharge de l'opérateur de flux
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}