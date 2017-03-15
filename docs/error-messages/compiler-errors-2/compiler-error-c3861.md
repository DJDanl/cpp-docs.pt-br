---
title: C3861 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3861
dev_langs:
- C++
helpviewer_keywords:
- C3861
ms.assetid: 0a1eee30-b3db-41b1-b1e5-35949c3924d7
caps.latest.revision: 10
author: corob-msft
ms.author: corob
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
translationtype: Machine Translation
ms.sourcegitcommit: 65e7a7bd56096fbeec61b651ab494d82edef9c90
ms.openlocfilehash: 177890dcd3ff2abf07f5d9e282efd4a9fd7121a7
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3861"></a>C3861 de erro do compilador
'identifier': identificador não encontrado  
  
O compilador não foi capaz de resolver uma referência a um identificador, mesmo usando a pesquisa dependente de argumento.  
  
Para corrigir esse erro, verifique se a declaração do identificador de caso e a ortografia. Verifique [operadores de resolução do escopo](../../cpp/scope-resolution-operator.md) e namespace [usando diretivas](../../cpp/namespaces-cpp.md#using_directives) são usados corretamente. Se o identificador for declarado em um arquivo de cabeçalho, verifique se o cabeçalho incluído antes que ela é referenciada. Verifique também se o identificador não é excluído por [diretivas de compilação condicional](../../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md).  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3861.  
  
```cpp  
// C3861.cpp  
void f2(){}  
int main() {  
   f();   // C3861  
   f2();   // OK  
}  
```  
  
## <a name="example"></a>Exemplo  
Classes de exceção na biblioteca padrão C++ agora estão no `std` namespace.  
  
```cpp  
// C3861_b.cpp  
// compile with: /EHsc  
#include <iostream>  
int main() {  
   try {  
      throw exception("Exception");   // C3861  
      // try the following line instead  
      // throw std::exception("Exception");  
   }  
   catch (...) {  
      std::cout << "caught an exception" << std::endl;  
   }  
}  
```
