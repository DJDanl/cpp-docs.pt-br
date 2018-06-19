---
title: Compilador (nível 4) de aviso C4629 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4629
dev_langs:
- C++
helpviewer_keywords:
- C4629
ms.assetid: 158cde12-bae5-4d43-b575-b52b35aaa0b9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d77f0d5343952919577845bb5c20ef4f8cb14cca
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33315458"
---
# <a name="compiler-warning-level-4-c4629"></a>Compilador C4629 de aviso (nível 4)
dígrafo usado, a sequência de caracteres 'dígrafo' interpretada como token 'char' (Insira um espaço entre os dois caracteres se for não pretende)  
  
 Em [/Za](../../build/reference/za-ze-disable-language-extensions.md), o compilador avisa quando ele detecta um dígrafo.  
  
 O exemplo a seguir gera C4629:  
  
```  
// C4629.cpp  
// compile with: /Za /W4  
int main()  
<%   // C4629 <% digraph for {  
}  
```