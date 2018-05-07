---
title: Compilador (nível 1) de aviso C4090 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4090
dev_langs:
- C++
helpviewer_keywords:
- C4090
ms.assetid: baad469d-23d4-45aa-ad9c-305b32d61e9a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9a28924b2cf176524a2ecd3156394dd7530cfb9f
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-1-c4090"></a>Compilador C4090 de aviso (nível 1)
'operação de ': qualificadores 'modificador' diferente  
  
 Uma variável usada em uma operação é definida com um modificador especificado que impede que ele seja modificado sem detecção pelo compilador. A expressão é compilada sem modificação.  
  
 Esse aviso pode ser causado quando um ponteiro para um **const** ou `volatile` item é atribuído a um ponteiro não declarado como apontando para **const** ou `volatile`.  
  
 Esse aviso é emitido para programas do C. Em um programa C++, o compilador emite um erro: [C2440](../../error-messages/compiler-errors-1/compiler-error-c2440.md).  
  
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