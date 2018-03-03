---
title: "Compilador (nível 1) de aviso C4177 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4177
dev_langs:
- C++
helpviewer_keywords:
- C4177
ms.assetid: 2b05a5b3-696e-4f21-818e-227b9335e748
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a0cfe64a25c4813a726b539cef2ce37533a9a2ff
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4177"></a>Compilador C4177 de aviso (nível 1)
\#pragma pragma deve estar no escopo global  
  
 O [pragma](../../preprocessor/pragma-directives-and-the-pragma-keyword.md) pragma não deve ser usado em um escopo local. O **pragma** não será válida até que o escopo global é encontrado após o escopo atual.  
  
 O exemplo a seguir gera C4177:  
  
```  
// C4177.cpp  
// compile with: /W1  
// #pragma bss_seg("global")   // OK  
  
int main() {  
   #pragma bss_seg("local")    // C4177  
}  
```