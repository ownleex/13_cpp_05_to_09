/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:21:24 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/30 00:21:28 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern {
private:
    // Types de formulaires disponibles
    static const int NB_FORMS = 3;
    static const std::string FORM_NAMES[NB_FORMS];
    
    // Pointeur sur fonction membre
    typedef AForm* (Intern::*FormCreator)(const std::string& target) const;
    static const FormCreator FORM_CREATORS[NB_FORMS];
    
    // Méthodes privées pour créer chaque type de formulaire
    AForm* createShrubberyForm(const std::string& target) const;
    AForm* createRobotomyForm(const std::string& target) const;
    AForm* createPresidentialPardonForm(const std::string& target) const;

public:
    // Constructeurs et destructeur
    Intern();
    Intern(const Intern& src);
    ~Intern();
    
    // Opérateur d'affectation
    Intern& operator=(const Intern& rhs);
    
    // Méthode pour créer un formulaire
    AForm* makeForm(const std::string& formName, const std::string& target) const;
    
    // Exception pour formulaire non trouvé
    class FormNotFoundException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif