---
title: Compilador (nível 1) de aviso C4618 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4618
dev_langs:
- C++
helpviewer_keywords:
- C4618
ms.assetid: 6ff10d0a-6d5b-4373-8196-1d57bb6b1611
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e53f8542983a6e15f353ff181efa280815fea9d8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33282516"
---
# <a name="compiler-warning-level-1-c4618"></a>Compilador C4618 de aviso (nível 1)
parâmetros de pragma incluíram uma cadeia de caracteres vazia; pragma ignorado  
  
 Uma cadeia de caracteres nula foi fornecida como um argumento para um **#pragma**.  
  
 O pragma foi processado sem o argumento.  
  
 O exemplo a seguir gera C4618:  
  
```  
// C4618.cpp  
// compile with: /W1 /LD  
#pragma code_seg("")   // C4618  
```