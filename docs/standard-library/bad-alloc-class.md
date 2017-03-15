---
title: "Classe bad_alloc | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
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
  - "bad_alloc class"
ms.assetid: 6429a8e6-5a49-4907-8d56-f4a4ec8131d0
caps.latest.revision: 26
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
translation.priority.ht: 
  - "cs-cz"
  - "de-de"
  - "es-es"
  - "fr-fr"
  - "it-it"
  - "ja-jp"
  - "ko-kr"
  - "pl-pl"
  - "pt-br"
  - "ru-ru"
  - "tr-tr"
  - "zh-cn"
  - "zh-tw"
---
# <a name="badalloc-class"></a>Classe bad_alloc
A classe descreve uma exceção gerada para indicar que uma solicitação de alocação não teve êxito.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class bad_alloc : public exception {  
    bad_alloc();
virtual ~bad_alloc();

};  
```  
  
## <a name="remarks"></a>Comentários  
 O valor retornado por **o quê** é uma cadeia de caracteres C definida pela implementação. Nenhuma das funções de membro lança exceções.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<new>  
  
 **Namespace:** std  
  
## <a name="example"></a>Exemplo  
  
```cpp  
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
  
## <a name="sample-output"></a>Saída de Exemplo  
  
```  
bad allocation  
```  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** \<new>  
  
## <a name="see-also"></a>Consulte também
 [Classe exception](../standard-library/exception-class.md)  
 [Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)

