---
title: "Compilador (nível 4) de aviso C4232 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4232
dev_langs: C++
helpviewer_keywords: C4232
ms.assetid: f92028a5-4ddd-43c1-97f5-4f724e5e14af
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: ae768c40ceca96da8c9f1b933d7006d08ed5e6e3
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
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