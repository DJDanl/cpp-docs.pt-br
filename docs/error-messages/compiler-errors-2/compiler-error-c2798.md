---
title: C2798 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2798
dev_langs:
- C++
helpviewer_keywords:
- C2798
ms.assetid: fb0cd861-b228-4f81-8090-e28344a727e0
caps.latest.revision: 8
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
ms.openlocfilehash: 8b516b2ba9dc566a39060956fd8283ffb44797e3
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2798"></a>C2798 de erro do compilador
'super::member' é ambíguo  
  
 Várias estruturas herdadas contêm o membro referenciado com [super](../../cpp/super.md). Você pode corrigir o erro ao:  
  
-   Removendo B1 ou B2 na lista de herança de D.  
  
-   Alterando o nome do membro de dados em B1 ou B2.  
  
 O exemplo a seguir gera C2798:  
  
```  
// C2798.cpp  
struct B1 {  
   int i;  
};  
  
struct B2 {  
   int i;  
};  
  
struct D : B1, B2 {  
   void g() {  
      __super::i = 4; // C2798  
   }  
};  
```
