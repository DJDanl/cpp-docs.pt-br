---
title: "Compilador aviso (nível 4) C4629 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4629
dev_langs:
- C++
helpviewer_keywords:
- C4629
ms.assetid: 158cde12-bae5-4d43-b575-b52b35aaa0b9
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: cf2899b004bf13b3b4a8fad8c2c1e1e0fd6be34c
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4629"></a>Compilador C4629 de aviso (nível 4)
digraph usado, a sequência de caracteres 'digraph' interpretada como token 'char' (inserir um espaço entre os dois caracteres se for não pretende)  
  
 Em [/Za](../../build/reference/za-ze-disable-language-extensions.md), o compilador emitirá um aviso quando detecta um digraph.  
  
 O exemplo a seguir gera C4629:  
  
```  
// C4629.cpp  
// compile with: /Za /W4  
int main()  
<%   // C4629 <% digraph for {  
}  
```
