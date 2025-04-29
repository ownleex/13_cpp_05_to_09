/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:10:05 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/30 00:10:08 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructeurs et destructeur
RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request", 72, 45, "default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
    : AForm("Robotomy Request", 72, 45, target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) 
    : AForm(src) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

// Opérateur d'affectation
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

// Action spécifique
void RobotomyRequestForm::action() const {
    // Initialisation de la graine pour la fonction aléatoire
    std::srand(std::time(NULL));
    
    // Bruits de forage
    std::cout << "* BRRR... VRRR... DRRRR... *" << std::endl;
    std::cout << "* Bruits de forage intenses *" << std::endl;
    
    // 50% de chances de réussite
    if (std::rand() % 2) {
        std::cout << getTarget() << " a été robotomisé avec succès !" << std::endl;
    } else {
        std::cout << "La robotomisation de " << getTarget() << " a échoué..." << std::endl;
    }
}