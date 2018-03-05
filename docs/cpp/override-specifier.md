---
title: "Especificador de substituição | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- override Identifier
ms.assetid: b286fb46-9374-4ad8-b2e7-4607119b6133
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 677a6a0e0107f3ed0d0dc402f36e9d6dd4505c7f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="override-specifier"></a>substituir especificador
Você pode usar a palavra-chave `override` para designar as funções membro que substituem uma função virtual em uma classe base.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
function-declaration override;  
```  
  
## <a name="remarks"></a>Comentários  
 `override` é contextual e tem um significado especial somente quando usada após uma declaração de função membro. Caso contrário, não é uma palavra-chave reservada.  
  
## <a name="example"></a>Exemplo  
 Use `override` para ajudar a impedir comportamentos de herança inadequados em seu código. O exemplo a seguir mostra onde, sem usar `override`, o comportamento da função membro da classe derivada pode não ser o esperado. O compilador não emite erros para esse código.  
  
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
  
 Para especificar que as funções não podem ser substituídas e que as classes não podem ser herdadas, use o [final](../cpp/final-specifier.md) palavra-chave.  
  
## <a name="see-also"></a>Consulte também  
 [Especificador final](../cpp/final-specifier.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 