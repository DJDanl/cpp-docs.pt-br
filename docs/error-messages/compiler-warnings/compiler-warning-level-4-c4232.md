---
title: "Compilador (nível 4) de aviso C4232 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4232
dev_langs:
- C++
helpviewer_keywords:
- C4232
ms.assetid: f92028a5-4ddd-43c1-97f5-4f724e5e14af
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d0b8725ca2a7ee6c5f512559eecdb6b01ac4c6a6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4232"></a>Compilador C4232 de aviso (nível 4)
extensão não padrão usada: 'Identificador': endereço de dllimport 'dllimport' não é estático, identidade não garantida  
  
 Em extensões da Microsoft (/Ze), você pode conceder um valor não estático como o endereço de uma função declarada com o **dllimport** modificador. Em compatibilidade ANSI ([/Za](../../build/reference/za-ze-disable-language-extensions.md)), isso causará um erro.  
  
 O exemplo a seguir gera C4232:  
  
```  
// C4232.c  
// compile with: /W4 /Ze /c  
int __declspec(dllimport) f();  
int (*pfunc)() = &f;   // C4232  
```