---
title: Erro de compilador c2199 (compilador) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2199
dev_langs:
- C++
helpviewer_keywords:
- C2199
ms.assetid: 6a92a1b7-7906-49e6-a31f-e8bffbc7706a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 31164597c9427dc5e915f5a0315d8e2bb7825e8e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33169004"
---
# <a name="compiler-error-c2199"></a>C2199 de erro do compilador
Erro de sintaxe: encontrado ' identificador (' no escopo global (uma declaração estava planejada?)  
  
 O contexto especificado causou um erro de sintaxe. Pode haver sintaxe de declaração incorreto.  
  
 O exemplo a seguir gera C2199:  
  
```  
// C2199.cpp  
// compile with: /c  
int j = int(1) int(1);   // C2199  
int j = 1;   // OK  
```