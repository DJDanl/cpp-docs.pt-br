---
title: "Compilador aviso (nível 1) C4342 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4342
dev_langs:
- C++
helpviewer_keywords:
- C4342
ms.assetid: 47d4d5ab-069f-4cdc-98c3-10d649577a37
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
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4755edcc99a9b8fca00972611bbd633a68eb8ec7
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4342"></a>Compilador C4342 de aviso (nível 1)
alteração de comportamento: 'function' chamado, mas um operador de membro foi chamado em versões anteriores  
  
 Nas versões anteriores do Visual C++, um membro foi chamado, mas esse comportamento foi alterado e o compilador irá encontrar a melhor correspondência no escopo de namespace.  
  
 Se um operador de membro for encontrado, o compilador anteriormente não consideram qualquer namespace operadores de escopo. Se houver uma correspondência melhor no escopo de namespace, o compilador atual corretamente chamará, enquanto os compiladores anteriores não considerá-la.  
  
 Esse aviso deve ser desabilitado após você com êxito porta seu código para a versão atual.  O compilador pode resultar em falsos positivos, gerando esse aviso de código onde não há nenhuma alteração de comportamento.  
  
 Esse aviso é desativada por padrão. Para obter mais informações, consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md).  
  
 O exemplo a seguir gera C4342:  
  
```  
// C4342.cpp  
// compile with: /EHsc /W1  
#include <fstream>  
#pragma warning(default: 4342)  
using namespace std;  
struct X : public ofstream {  
   X();  
};  
  
X::X() {  
   open( "ofs_bug_ev.txt." );  
   if ( is_open() ) {  
      *this << "Text" << "<-should be text" << endl;   // C4342  
      *this << ' ' << "<-should be space symbol" << endl;   // C4342  
   }  
}  
  
int main() {  
   X b;  
   b << "Text" << "<-should be text" << endl;  
   b << ' ' << "<-should be space symbol" << endl;  
}  
```
