---
title: Compilador aviso (nível 4) C4235
ms.date: 11/04/2016
f1_keywords:
- C4235
helpviewer_keywords:
- C4235
ms.assetid: d4214799-d62c-4674-b4e2-9e201c303303
ms.openlocfilehash: 80ad388b26b2b972aa1301c1f335d0361a75f15f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62401040"
---
# <a name="compiler-warning-level-4-c4235"></a>Compilador aviso (nível 4) C4235

extensão não padrão usada: palavra-chave de 'palavra-chave' não tem suportada nesta arquitetura

O compilador não oferece suporte a palavra-chave que você usou.

Esse aviso é promovido automaticamente a um erro. Se você quiser modificar esse comportamento, use [#pragma aviso](../../preprocessor/warning.md). Por exemplo, para transformar C4235 em um aviso de nível 2, use a seguinte linha de código

```
#pragma warning(2:4235)
```

no arquivo de código fonte.