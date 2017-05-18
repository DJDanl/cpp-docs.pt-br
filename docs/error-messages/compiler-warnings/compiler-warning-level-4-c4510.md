---
title: "Compilador aviso (nível 4) C4510 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4510
dev_langs:
- C++
helpviewer_keywords:
- C4510
ms.assetid: fd28d1d4-ad27-4dad-94c0-9dba46c93180
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 527b3ddfcd291d2e18a38af180db595fc6630abd
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4510"></a>Compilador C4510 de aviso (nível 4)
'class': não foi possível gerar o construtor padrão  
  
 O compilador não pode gerar um construtor padrão para a classe especificada e nenhum construtor definido pelo usuário foi criada. Você não poderá criar objetos desse tipo.  
  
 Há várias situações que impedem que o compilador gera um construtor padrão, incluindo:  
  
-   Um membro de dados const.  
  
-   Um membro de dados que é uma referência.  
  
 Você precisa criar um construtor padrão definido pelo usuário para a classe que inicializa esses membros.  
  
 O exemplo a seguir gera C4510:  
  
```  
// C4510.cpp  
// compile with: /W4  
struct A {  
   const int i;  
   int &j;  
   A& operator=( const A& ); // C4510 expected  
   // uncomment the following line to resolve this C4510  
   // A(int ii, int &jj) : i(ii), j(jj) {}  
};   // C4510  
  
int main() {  
}  
```
