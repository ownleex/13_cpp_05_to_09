/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:21:43 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/05/16 23:09:18 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

// Constructeurs et destructeur
Intern::Intern() {
}

Intern::Intern(const Intern& src) {
    *this = src;
}

Intern::~Intern() {
}

// Opérateur d'affectation
Intern& Intern::operator=(const Intern& rhs) {
    (void)rhs; // L'interne n'a pas d'attributs, donc rien à copier
    return *this;
}

// Méthode pour créer un formulaire
AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* form = NULL;

    int i;
    for (i = 0; i < 3; i++) {
        if (formName == formNames[i])
            break;
    }
    switch (i) {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;
        default:
            throw Intern::InvalidForm();
    }
    
    std::cout << "Intern crée " << form->getName() << std::endl;
    return form;
}

// Exception personnalisée
const char* Intern::InvalidForm::what() const throw() {
    return "Type de formulaire inconnu";
}