---
title: C2081 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2081
dev_langs:
- C++
helpviewer_keywords:
- C2081
ms.assetid: 7db9892d-364d-4178-a49d-f8398ece09a0
caps.latest.revision: 7
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
ms.openlocfilehash: e8d652dcd44772653ea1b09397a2fff0f7a36ac3
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2081"></a>C2081 de erro do compilador
'identifier': nome ilegal de lista formal de parâmetros  
  
 O identificador causou um erro de sintaxe.  
  
 Esse erro pode ser causado por meio de estilo antigo para a lista de parâmetros formais. Você deve especificar o tipo de parâmetros formais na lista de parâmetros formais.  
  
 O exemplo a seguir gera C2081:  
  
```  
// C2081.c  
void func( int i, j ) {}  // C2081, no type specified for j  
```  
  
 Resolução possível:  
  
```  
// C2081b.c  
// compile with: /c  
void func( int i, int j ) {}  
```
