---
title: "Vis&#227;o geral das fun&#231;&#245;es de membro | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "funções embutidas, tratando funções de membro como"
  - "funções de membro, definição em declaração de classe"
  - "funções de membro não estático"
  - "este ponteiro, e funções de membro não estático"
ms.assetid: 9f77a438-500e-40bb-a6c6-544678f3f4c8
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vis&#227;o geral das fun&#231;&#245;es de membro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

As funções membro são estáticas ou não estáticas.  O comportamento das funções membro estáticas é diferente de outras funções membro, pois as funções membro estáticas não têm nenhum argumento **this** implícito.  As funções membro não estáticas têm um ponteiro **this**.  As funções membro, sejam elas estáticas ou não estáticas, podem ser definidas dentro ou fora da declaração da classe.  
  
 Se uma função membro for definida dentro de uma declaração de classe, ela será tratada como uma função embutida, e não há necessidade de qualificar o nome da função com o nome da sua classe.  Embora as funções definidas dentro de declarações de classe já sejam tratadas como funções embutidas, você pode usar a palavra\-chave **inline** para documentar o código.  
  
 Este é um exemplo de declaração de uma função dentro de uma declaração de classe:  
  
```  
// overview_of_member_functions1.cpp  
class Account  
{  
public:  
    // Declare the member function Deposit within the declaration  
    //  of class Account.  
    double Deposit( double HowMuch )  
    {  
        balance += HowMuch;  
        return balance;  
    }  
private:  
    double balance;  
};  
  
int main()  
{  
}  
```  
  
 Se uma definição de função membro estiver fora da declaração de classe, ela será tratada como uma função embutida somente se for declarada explicitamente como **inline**.  Além disso, o nome da função na definição deve ser qualificado com o nome da sua classe usando o operador de resolução de escopo \(`::`\).  
  
 O exemplo a seguir é idêntico à declaração de classe `Account`anterior, com exceção da função `Deposit`, que é definida fora de declaração da classe:  
  
```  
// overview_of_member_functions2.cpp  
class Account  
{  
public:  
    // Declare the member function Deposit but do not define it.  
    double Deposit( double HowMuch );  
private:  
    double balance;  
};  
  
inline double Account::Deposit( double HowMuch )  
{  
    balance += HowMuch;  
    return balance;  
}  
  
int main()  
{  
}  
```  
  
> [!NOTE]
>  Embora as funções membro possam ser definidas dentro de uma declaração de classe ou separadamente, nenhuma função membro pode ser adicionada a uma classe depois que a classe é definida.  
  
 As classes que contêm funções membro podem ter muitas declarações, mas as próprias funções membro devem ter apenas uma definição em um programa.  Várias definições geram uma mensagem de erro em tempo de vinculação.  Se uma classe contiver definições de função embutidas, as definições de função devem ser idênticas para observar a regra de "uma definição".  
  
## Consulte também  
 [Funções membro](../Topic/Member%20Functions%20\(C++\).md)