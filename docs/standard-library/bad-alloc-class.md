---
title: "Classe bad_alloc | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "std::bad_alloc"
  - "new/std:bad_alloc"
  - "bad_alloc"
  - "std.bad_alloc"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe bad_alloc"
ms.assetid: 6429a8e6-5a49-4907-8d56-f4a4ec8131d0
caps.latest.revision: 26
caps.handback.revision: 26
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Classe bad_alloc
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe descreve uma exceção gerada para indicar que uma solicitação de alocação não teve êxito.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class bad_alloc : public exception {  
    bad_alloc();
virtual ~bad_alloc();

};  
```  
  
## <a name="remarks"></a>Comentários  
 O valor retornado por **que** é uma cadeia de caracteres C definido pela implementação. Nenhuma das funções de membro lançar exceções.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< novo>  
  
 **Namespace:** std  
  
## <a name="example"></a>Exemplo  
  
```  
// bad_alloc.cpp  
// compile with: /EHsc  
#include<new>  
#include<iostream>  
using namespace std;  
  
int main() {  
   char* ptr;  
   try {  
      ptr = new char[(~unsigned int((int)0)/2) - 1];  
      delete[] ptr;  
   }  
   catch( bad_alloc &ba) {  
      cout << ba.what( ) << endl;  
   }  
}  
```  
  
## <a name="sample-output"></a>Saída de exemplo  
  
```  
bad allocation  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \< novo>  
  
## <a name="see-also"></a>Consulte também
 [Classe Exception](../standard-library/exception-class1.md)  
 [Segurança de threads na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

