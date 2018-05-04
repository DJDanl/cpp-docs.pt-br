---
title: Exceção bad_cast | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- bad_cast
- bad_cast_cpp
dev_langs:
- C++
helpviewer_keywords:
- exceptions [C++], bad_cast
- bad_cast keyword [C++]
ms.assetid: 31eae1e7-d8d5-40a0-9fef-64a6a4fc9021
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7c09754e44b2cf1d7bda4bde35b8d76335d96711
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="badcast-exception"></a>Exceção bad_cast
A exceção `bad_cast` é lançada pelo operador `dynamic_cast` como resultado de uma conversão em um tipo de referência que falhou.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
catch (bad_cast)  
   statement  
```  
  
## <a name="remarks"></a>Comentários  
 A interface de `bad_cast` é:  
  
```  
class bad_cast : public exception {  
public:  
   bad_cast(const char * _Message = "bad cast");  
   bad_cast(const bad_cast &);  
   virtual ~bad_cast();  
};  
```  
  
 O código a seguir contém um exemplo de `dynamic_cast` com falha que lança a exceção `bad_cast`.  
  
```  
// expre_bad_cast_Exception.cpp  
// compile with: /EHsc /GR  
#include <typeinfo.h>  
#include <iostream>  
  
class Shape {  
public:  
   virtual void virtualfunc() const {}  
};  
  
class Circle: public Shape {  
public:  
   virtual void virtualfunc() const {}  
};  
  
using namespace std;  
int main() {  
   Shape shape_instance;  
   Shape& ref_shape = shape_instance;  
   try {  
      Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);   
   }  
   catch (bad_cast b) {  
      cout << "Caught: " << b.what();  
   }  
}  
```  
  
 A exceção é lançada porque o objeto que está sendo convertido (uma forma) não é derivado do tipo convertido especificado (círculo). Para evitar a exceção, adicione estas declarações a `main`:  
  
```  
Circle circle_instance;  
Circle& ref_circle = circle_instance;  
```  
  
 Depois, inverta o sentido da conversão no bloco `try` como segue:  
  
```  
Shape& ref_shape = dynamic_cast<Shape&>(ref_circle);  
```  
  
## <a name="see-also"></a>Consulte também  
 [Operador dynamic_cast](../cpp/dynamic-cast-operator.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Tratamento de exceções em C++](../cpp/cpp-exception-handling.md)