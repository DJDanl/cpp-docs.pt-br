---
title: Funções virtuais
ms.date: 11/04/2016
helpviewer_keywords:
- functions [C++], virtual functions
- derived classes [C++], virtual functions
- virtual functions
ms.assetid: b3e1ed88-2a90-4af8-960a-16f47deb3452
ms.openlocfilehash: 07dfd8a602dca93c89a078b2eb69e04cf9d4a7a9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62393838"
---
# <a name="virtual-functions"></a>Funções virtuais

Uma função virtual é uma função membro que espera-se que seja redefinida em classes derivadas. Quando você faz referência um objeto da classe derivada usando um ponteiro ou uma referência à classe base, pode chamar uma função virtual para esse objeto e executar a versão da classe derivada da função.

As funções virtuais asseguram que a função correta seja chamada para um objeto, independentemente da expressão usada para fazer a chamada de função.

Suponha que uma classe base contém uma função declarada como [virtual](../cpp/virtual-cpp.md) e uma classe derivada defina a mesma função. A função a partir da classe derivada é chamada para objetos da classe derivada, mesmo se ela for chamada usando um ponteiro ou uma referência à classe base. O exemplo a seguir mostra uma classe base que fornece uma implementação da função de `PrintBalance` e de duas classes derivadas

```cpp
// deriv_VirtualFunctions.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

class Account {
public:
   Account( double d ) { _balance = d; }
   virtual double GetBalance() { return _balance; }
   virtual void PrintBalance() { cerr << "Error. Balance not available for base type." << endl; }
private:
    double _balance;
};

class CheckingAccount : public Account {
public:
   CheckingAccount(double d) : Account(d) {}
   void PrintBalance() { cout << "Checking account balance: " << GetBalance() << endl; }
};

class SavingsAccount : public Account {
public:
   SavingsAccount(double d) : Account(d) {}
   void PrintBalance() { cout << "Savings account balance: " << GetBalance(); }
};

int main() {
   // Create objects of type CheckingAccount and SavingsAccount.
   CheckingAccount *pChecking = new CheckingAccount( 100.00 ) ;
   SavingsAccount  *pSavings  = new SavingsAccount( 1000.00 );

   // Call PrintBalance using a pointer to Account.
   Account *pAccount = pChecking;
   pAccount->PrintBalance();

   // Call PrintBalance using a pointer to Account.
   pAccount = pSavings;
   pAccount->PrintBalance();
}
```

No código anterior, as chamadas para `PrintBalance` são idênticas, com exceção objeto ao qual `pAccount` aponta. Como `PrintBalance` é virtual, a versão da função definida para cada objeto é chamada. A função `PrintBalance` nas classes derivadas `CheckingAccount` e `SavingsAccount` “substitui” a função na classe base `Account`.

Se uma classe que não fornece uma implementação substituta da função `PrintBalance` for chamada, a implementação padrão da classe base `Account` será usada.

As funções nas classes derivadas substituem as funções virtuais nas classes base apenas se o tipo for o mesmo. Uma função em uma classe derivada não pode ser diferente de uma função virtual em uma classe base apenas no tipo de retorno; a lista de argumentos também deve ser diferente.

Ao chamar uma função usando ponteiros ou referências, as seguintes regras se aplicam:

- Uma chamada a uma função virtual é resolvida de acordo com o tipo subjacente de objeto para o qual ela é chamada.

- Uma chamada a uma função não virtual é resolvida de acordo com o tipo de ponteiro ou de referência.

O exemplo a seguir mostra como as funções virtuais e não virtuais se comportam quando chamadas por ponteiros:

```cpp
// deriv_VirtualFunctions2.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

class Base {
public:
   virtual void NameOf();   // Virtual function.
   void InvokingClass();   // Nonvirtual function.
};

// Implement the two functions.
void Base::NameOf() {
   cout << "Base::NameOf\n";
}

void Base::InvokingClass() {
   cout << "Invoked by Base\n";
}

class Derived : public Base {
public:
   void NameOf();   // Virtual function.
   void InvokingClass();   // Nonvirtual function.
};

// Implement the two functions.
void Derived::NameOf() {
   cout << "Derived::NameOf\n";
}

void Derived::InvokingClass() {
   cout << "Invoked by Derived\n";
}

int main() {
   // Declare an object of type Derived.
   Derived aDerived;

   // Declare two pointers, one of type Derived * and the other
   //  of type Base *, and initialize them to point to aDerived.
   Derived *pDerived = &aDerived;
   Base    *pBase    = &aDerived;

   // Call the functions.
   pBase->NameOf();           // Call virtual function.
   pBase->InvokingClass();    // Call nonvirtual function.
   pDerived->NameOf();        // Call virtual function.
   pDerived->InvokingClass(); // Call nonvirtual function.
}
```

### <a name="output"></a>Saída

```Output
Derived::NameOf
Invoked by Base
Derived::NameOf
Invoked by Derived
```

Observe que, independentemente da função `NameOf` ser chamada por um ponteiro para `Base` ou um ponteiro para `Derived`, ela chama a função para `Derived`. Ela chama a função para `Derived` porque `NameOf` é uma função virtual, e `pBase` e `pDerived` apontam para um objeto do tipo `Derived`.

Como funções virtuais são chamadas apenas para objetos de tipos de classe, você não pode declarar funções globais ou estáticas como **virtual**.

O **virtual** palavra-chave pode ser usada ao declarar funções substitutas em uma classe derivada, mas é desnecessária; as substituições de funções virtuais são sempre virtuais.

Funções virtuais em uma classe base devem ser definidas, a menos que elas são declaradas usando o *especificador puro*. (Para obter mais informações sobre funções virtuais puras, consulte [Classes abstratas](../cpp/abstract-classes-cpp.md).)

O mecanismo de chamada de funções virtuais pode ser suprimido ao qualificar explicitamente o nome da função usando o operador scope-resolution (`::`). Veja o exemplo anterior que envolve a classe `Account`. Para chamar `PrintBalance` na classe base, use um código como este:

```cpp
CheckingAccount *pChecking = new CheckingAccount( 100.00 );

pChecking->Account::PrintBalance();  //  Explicit qualification.

Account *pAccount = pChecking;  // Call Account::PrintBalance

pAccount->Account::PrintBalance();   //  Explicit qualification.
```

As duas chamadas a `PrintBalance` no exemplo anterior suprimem o mecanismo de chamada de função virtual.