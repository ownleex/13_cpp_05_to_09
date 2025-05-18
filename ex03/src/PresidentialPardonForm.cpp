/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:10:32 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/30 00:10:38 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructeurs et destructeur
PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon", 25, 5, "default") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
    : AForm("Presidential Pardon", 25, 5, target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) 
    : AForm(src) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

// Opérateur d'affectation
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

// Action spécifique
void PresidentialPardonForm::action() const {
    std::cout << getTarget() << " a été pardonné par Zaphod Beeblebrox." << std::endl;
}