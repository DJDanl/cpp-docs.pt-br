---
title: "substituir especificador | Microsoft Docs"
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
  - "Identificador de substituição"
ms.assetid: b286fb46-9374-4ad8-b2e7-4607119b6133
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# substituir especificador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode usar a palavra\-chave `override` para designar as funções membro que substituem uma função virtual em uma classe base.  
  
## Sintaxe  
  
```  
  
function-declaration override;  
```  
  
## Comentários  
 `override` é contextual e tem um significado especial somente quando usada após uma declaração de função membro. Caso contrário, não é uma palavra\-chave reservada.  
  
## Exemplo  
 Use `override` para ajudar a impedir comportamentos de herança inadequados em seu código.  O exemplo a seguir mostra onde, sem usar `override`, o comportamento da função membro da classe derivada pode não ser o esperado.  O compilador não emite erros para esse código.  
  
```cpp  
class BaseClass  
{  
    virtual void funcA();  
    virtual void funcB() const;  
    virtual void funcC(int = 0);  
    void funcD();  
};  
  
class DerivedClass: public BaseClass  
{  
    virtual void funcA(); // ok, works as intended  
  
    virtual void funcB(); // DerivedClass::funcB() is non-const, so it does not  
                          // override BaseClass::funcB() const and it is a new member function  
  
    virtual void funcC(double = 0.0); // DerivedClass::funcC(double) has a different  
                                      // parameter type than BaseClass::funcC(int), so  
                                      // DerivedClass::funcC(double) is a new member function  
  
};  
  
```  
  
 Quando você usa `override`, o compilador gera erros em vez de criar silenciosamente novas funções membro.  
  
```cpp  
class BaseClass  
{  
    virtual void funcA();  
    virtual void funcB() const;  
    virtual void funcC(int = 0);  
    void funcD();  
};  
  
class DerivedClass: public BaseClass  
{  
    virtual void funcA() override; // ok  
  
    virtual void funcB() override; // compiler error: DerivedClass::funcB() does not   
                                   // override BaseClass::funcB() const  
  
    virtual void funcC( double = 0.0 ) override; // compiler error:   
                                                 // DerivedClass::funcC(double) does not   
                                                 // override BaseClass::funcC(int)  
  
    void funcD() override; // compiler error: DerivedClass::funcD() does not   
                           // override the non-virtual BaseClass::funcD()  
};  
  
```  
  
 Para especificar que as funções não podem ser substituídas e que as classes não podem ser herdadas, use a palavra\-chave [final](../cpp/final-specifier.md).  
  
## Consulte também  
 [especificador final](../cpp/final-specifier.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [\(NOTINBUILD\) C\+\+ Type Names](http://msdn.microsoft.com/pt-br/b53ba470-e583-4e5c-b634-6018f6110674)