---
title: "Compilador aviso (nível 1) C4090 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4090
dev_langs:
- C++
helpviewer_keywords:
- C4090
ms.assetid: baad469d-23d4-45aa-ad9c-305b32d61e9a
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
ms.openlocfilehash: 9fd28754f68282ea43feb792a97d313417c1f248
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4090"></a>Compilador C4090 de aviso (nível 1)
'operation': qualificadores diferentes 'modificador'  
  
 Uma variável usada em uma operação é definida com um modificador especificado que impede que ele seja modificado sem detecção pelo compilador. A expressão é compilada sem modificação.  
  
 Esse aviso pode ser causado quando um ponteiro para um **const** ou `volatile` item for atribuído a um ponteiro não declarado como apontando para **const** ou `volatile`.  
  
 Esse aviso é emitido para programas em C. Em um programa C++, o compilador emitirá um erro: [C2440](../../error-messages/compiler-errors-1/compiler-error-c2440.md).  
  
 O exemplo a seguir gera C4090:  
  
```  
// C4090.c  
// compile with: /W1  
int *volatile *p;  
int *const *q;  
int **r;  
  
int main() {  
   p = q;   // C4090  
   p = r;  
   q = p;   // C4090  
   q = r;  
   r = p;   // C4090  
   r = q;   // C4090  
}  
```
