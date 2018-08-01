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
ms.openlocfilehash: 8a37ae011ec2f06a505063678f481e6e41696c86
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39401361"
---
# <a name="badcast-exception"></a>Exceção bad_cast
O **bad_cast** exceção é lançada pela **dynamic_cast** operador como o resultado de uma falha na conversão em um tipo de referência.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
catch (bad_cast)  
   statement  
```  
  
## <a name="remarks"></a>Comentários  
 A interface para **bad_cast** é:  
  
```cpp 
class bad_cast : public exception {  
public:  
   bad_cast(const char * _Message = "bad cast");  
   bad_cast(const bad_cast &);  
   virtual ~bad_cast();  
};  
```  
  
 O código a seguir contém um exemplo de uma falha na **dynamic_cast** que gera a **bad_cast** exceção.  
  
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
  
 A exceção é lançada porque o objeto que está sendo convertido (uma forma) não é derivado do tipo convertido especificado (círculo). Para evitar a exceção, adicione estas declarações a `main`:  
  
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