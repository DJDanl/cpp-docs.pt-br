---
title: Compilador (nível 4) de aviso C4233 | Microsoft Docs
ms.custom: ''
ms.date: 10/25/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4233
dev_langs:
- C++
helpviewer_keywords:
- C4233
ms.assetid: 9aa51fc6-8ef3-43b5-bafb-c9333cf60de3
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a933d41fd8e7cf3b94e458efff72193b8ce5e187
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-warning-level-4-c4233"></a>Compilador C4233 de aviso (nível 4)

> extensão não padrão usada: '*palavra-chave*' palavra-chave só tem suportada em C++, não em C

O compilador compilados seu código-fonte como C em vez de C++, e você usou uma palavra-chave que só é válida em C++. O compilador compila o arquivo de origem como C, se a extensão do arquivo de origem é. c ou se você usar [/Tc](../../build/reference/tc-tp-tc-tp-specify-source-file-type.md).

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para tornar um problema do aviso de nível 4 C4233, adicione esta linha ao seu arquivo de código de origem:

```cpp
#pragma warning(4:4233)
```
