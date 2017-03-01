---
title: "Compilador aviso (nível 2) C4150 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4150
dev_langs:
- C++
helpviewer_keywords:
- C4150
ms.assetid: ff1760ec-0d9f-4d45-b797-94261624becf
caps.latest.revision: 6
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
ms.openlocfilehash: 0976309dba7d8c40e450ac0e45cb2173c4693df8
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-2-c4150"></a>Compilador C4150 de aviso (nível 2)
exclusão de ponteiro para tipo incompleto 'type'; Nenhum destruidor chamado  
  
 O **excluir** operador é chamado para excluir um tipo que foi declarado mas não definido, e o compilador não pode localizar um destruidor.  
  
 O exemplo a seguir gera C4150:  
  
```  
// C4150.cpp  
// compile with: /W2  
class  IncClass;  
  
void NoDestruct( IncClass* pIncClass )  
{  
   delete pIncClass;  
} // C4150, define class to resolve  
  
int main()  
{  
}  
```
