---
title: "Exce&#231;&#227;o bad_typeid | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "bad_typeid"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Exceção bad_typeid"
  - "exceções, bad_typeid"
ms.assetid: 5963ed58-4ede-4597-957d-f7bbd06299c2
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exce&#231;&#227;o bad_typeid
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A exceção `bad_typeid` é lançada pelo [operador typeid](../cpp/typeid-operator.md) quando o operando de `typeid` é um ponteiro NULL.  
  
## Sintaxe  
  
```  
  
      catch (bad_typeid)  
   statement  
```  
  
## Comentários  
 A interface de `bad_typeid` é:  
  
```  
class bad_typeid : public exception  
{  
public:  
   bad_typeid(const char * _Message = "bad typeid");  
   bad_typeid(const bad_typeid &);  
   virtual ~bad_typeid();  
};  
```  
  
 O exemplo a seguir mostra o operador `typeid` lançando uma exceção `bad_typeid`.  
  
```  
// expre_bad_typeid.cpp  
// compile with: /EHsc /GR  
#include <typeinfo.h>  
#include <iostream>  
  
class A{  
public:  
   // object for class needs vtable  
   // for RTTI  
   virtual ~A();  
};  
  
using namespace std;  
int main() {  
A* a = NULL;  
  
try {  
   cout << typeid(*a).name() << endl;  // Error condition  
   }  
catch (bad_typeid){  
   cout << "Object is NULL" << endl;  
   }  
}  
```  
  
## Saída  
  
```  
Object is NULL  
```  
  
## Consulte também  
 [Informações de tipo de tempo de execução](../Topic/Run-Time%20Type%20Information.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)