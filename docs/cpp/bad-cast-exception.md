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
ms.openlocfilehash: b50995ff1d5eb730bf6593679194d32d5300b9d7
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37942114"
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
  
```cpp 
class bad_cast : public exception {  
public:  
   bad_cast(const char * _Message = "bad cast");  
   bad_cast(const bad_cast &);  
   virtual ~bad_cast();  
};  
```  
  
 O código a seguir contém um exemplo de `dynamic_cast` com falha que lança a exceção `bad_cast`.  
  
```cpp 
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
  
 A exceção é lançada porque o objeto que está sendo convertido (uma forma) não é derivado do tipo convertido especificado (círculo). Para evitar a exceção, adicione estas declarações a **principal**:  
  
```cpp 
Circle circle_instance;  
Circle& ref_circle = circle_instance;  
```  
  
 Em seguida, inverta o sentido da conversão na **tente** bloquear da seguinte maneira:  
  
```cpp 
Shape& ref_shape = dynamic_cast<Shape&>(ref_circle);  
```  
  
## <a name="see-also"></a>Consulte também  
 [Operador dynamic_cast](../cpp/dynamic-cast-operator.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)   
 [Tratamento de exceções em C++](../cpp/cpp-exception-handling.md)