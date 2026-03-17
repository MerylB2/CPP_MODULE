#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : _name("Default_AForm"), _target("default"),
      _isSigned(false), _signGrade(150), _execGrade(150)
{
}

AForm::AForm(const std::string& name, const std::string& target,
    int signGrade, int execGrade)
    : _name(name), _target(target), _isSigned(false),
      _signGrade(signGrade), _execGrade(execGrade)
{
    if (_signGrade < 1 || _execGrade < 1)
        throw GradeTooHighException();
    if (_signGrade > 150 || _execGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _target(other._target), _isSigned(other._isSigned),
      _signGrade(other._signGrade), _execGrade(other._execGrade)
{
}

AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm()
{
}

const std::string& AForm::getName() const
{
    return _name;
}

const std::string& AForm::getTarget() const
{
    return _target;
}

bool AForm::getIsSigned() const
{
    return _isSigned;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecGrade() const
{
    return _execGrade;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    // A worse numerical grade means the bureaucrat is not allowed to sign.
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
    // The base class enforces shared execution rules for every derived form.
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _execGrade)
        throw GradeTooLowException();
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return "form is not signed!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << form.getName()
        << ", target: " << form.getTarget()
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", sign grade " << form.getSignGrade()
        << ", exec grade " << form.getExecGrade() << ".";
    return os;
}
