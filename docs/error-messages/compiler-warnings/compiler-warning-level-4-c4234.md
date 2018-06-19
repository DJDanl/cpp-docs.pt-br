---
title: Compilador (nível 4) de aviso C4234 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4234
dev_langs:
- C++
helpviewer_keywords:
- C4234
ms.assetid: f7fecd5c-8248-4fde-8446-502aedc357ca
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b8d5b7a2999b77c0b34ee925f5dd85a0a27c63f5
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33293511"
---
# <a name="compiler-warning-level-4-c4234"></a>Compilador C4234 de aviso (nível 4)
extensão não padrão usada: palavra-chave de 'palavra-chave' reservada para uso futuro  
  
 O compilador ainda não implementa a palavra-chave que você usou.  
  
 Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para tornar um problema do aviso de nível 4, C4234  
  
```  
#pragma warning(2:4234)  
```  
  
 no arquivo de código fonte.