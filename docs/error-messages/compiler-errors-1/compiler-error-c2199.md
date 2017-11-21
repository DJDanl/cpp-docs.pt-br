---
title: Erro de compilador c2199 (compilador) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2199
dev_langs: C++
helpviewer_keywords: C2199
ms.assetid: 6a92a1b7-7906-49e6-a31f-e8bffbc7706a
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 28410dfc8ced15c7c3cddd55b5403f45d1b15e78
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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