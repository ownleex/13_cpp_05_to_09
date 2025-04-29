/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:21:43 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/30 00:21:45 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Initialisation des membres statiques
const std::string Intern::FORM_NAMES[Intern::NB_FORMS] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
};

// Initialisation du tableau de pointeurs sur fonction membre
const Intern::FormCreator Intern::FORM_CREATORS[Intern::NB_FORMS] = {
    &Intern::createShrubberyForm,
    &Intern::createRobotomyForm,
    &Intern::createPresidentialPardonForm
};

// Constructeurs et destructeur
Intern::Intern() {
}

Intern::Intern(const Intern& src) {
    (void)src; // L'interne n'a pas d'attributs, donc rien à copier
}

Intern::~Intern() {
}

// Opérateur d'affectation
Intern& Intern::operator=(const Intern& rhs) {
    (void)rhs; // L'interne n'a pas d'attributs, donc rien à copier
    return *this;
}

// Méthodes privées pour créer chaque type de formulaire
AForm* Intern::createShrubberyForm(const std::string& target) const {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyForm(const std::string& target) const {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const {
    return new PresidentialPardonForm(target);
}

// Méthode pour créer un formulaire
AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
    for (int i = 0; i < NB_FORMS; i++) {
        if (formName == FORM_NAMES[i]) {
            AForm* form = (this->*FORM_CREATORS[i])(target);
            std::cout << "Intern crée " << form->getName() << std::endl;
            return form;
        }
    }
    
    // Si on arrive ici, le formulaire n'a pas été trouvé
    throw FormNotFoundException();
}

// Exception pour formulaire non trouvé
const char* Intern::FormNotFoundException::what() const throw() {
    return "Type de formulaire inconnu";
}