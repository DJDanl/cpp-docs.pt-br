---
title: "Exceção bad_cast | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- bad_cast_cpp
dev_langs:
- C++
helpviewer_keywords:
- exceptions, bad_cast
- bad_cast keyword [C++]
ms.assetid: 31eae1e7-d8d5-40a0-9fef-64a6a4fc9021
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 70758ca099853f94ad06b8a9f5029203a480a772
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

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
