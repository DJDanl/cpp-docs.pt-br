---
title: Compilador aviso (nível 4) C4235 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4235
dev_langs:
- C++
helpviewer_keywords:
- C4235
ms.assetid: d4214799-d62c-4674-b4e2-9e201c303303
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c9e709017e51101efe53a8697bb145014f200871
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46031815"
---
# <a name="compiler-warning-level-4-c4235"></a>Compilador aviso (nível 4) C4235

extensão não padrão usada: palavra-chave de 'palavra-chave' não tem suportada nesta arquitetura

O compilador não oferece suporte a palavra-chave que você usou.

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para transformar C4235 em um aviso de nível 2, use a seguinte linha de código

```
#pragma warning(2:4235)
```

no arquivo de código fonte.