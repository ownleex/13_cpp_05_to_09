/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:09:38 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/30 00:09:44 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructeurs et destructeur
ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation", 145, 137, "default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
    : AForm("Shrubbery Creation", 145, 137, target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) 
    : AForm(src) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

// Opérateur d'affectation
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
    }
    return *this;
}

// Action spécifique
void ShrubberyCreationForm::action() const {
    std::string filename = getTarget() + "_shrubbery";
    std::ofstream file(filename.c_str());
    
    if (!file) {
        throw std::runtime_error("Impossible de créer le fichier " + filename);
    }
    
    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\" << std::endl;
    file << std::endl;
    
    file << "       _-_" << std::endl;
    file << "    /~~   ~~\\" << std::endl;
    file << " /~~         ~~\\" << std::endl;
    file << "{               }" << std::endl;
    file << " \\  _-     -_  /" << std::endl;
    file << "   ~  \\\\ //  ~" << std::endl;
    file << "_- -   | | _- _" << std::endl;
    file << "  _ -  | |   -_" << std::endl;
    file << "      // \\\\" << std::endl;
    
    file.close();
    
    std::cout << "Création du fichier " << filename << " avec des ASCII trees" << std::endl;
}