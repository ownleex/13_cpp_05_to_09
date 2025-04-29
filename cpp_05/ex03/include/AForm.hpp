/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 00:08:50 by ayarmaya          #+#    #+#             */
/*   Updated: 2025/04/30 00:08:54 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat; // Déclaration anticipée

class AForm {
private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
    const std::string _target;

public:
    // Constructeurs et destructeur
    AForm();
    AForm(const std::string& name, int gradeToSign, int gradeToExecute, const std::string& target);
    AForm(const AForm& src);
    virtual ~AForm();
    
    // Opérateur d'affectation
    AForm& operator=(const AForm& rhs);
    
    // Getters
    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    const std::string& getTarget() const;
    
    // Fonction de signature
    void beSigned(const Bureaucrat& bureaucrat);
    
    // Fonction d'exécution (abstraite)
    void execute(Bureaucrat const & executor) const;
    
    // Méthode abstraite pour l'action spécifique du formulaire
    virtual void action() const = 0;
    
    // Classes d'exception
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class FormNotSignedException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Surcharge de l'opérateur de flux
std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif