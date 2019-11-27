---
title: Aviso do compilador (nível 4) C4235
ms.date: 11/04/2016
f1_keywords:
- C4235
helpviewer_keywords:
- C4235
ms.assetid: d4214799-d62c-4674-b4e2-9e201c303303
ms.openlocfilehash: 3e3cb2e40ed42b24ee52252003b26ec09cd86710
ms.sourcegitcommit: 3ee06ec53153cf21910fc8cfef78a4f25f9633f3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/26/2019
ms.locfileid: "74541756"
---
# <a name="compiler-warning-level-4-c4235"></a>Aviso do compilador (nível 4) C4235

extensão não padrão usada: palavra-chave ' keyword ' sem suporte nesta arquitetura

O compilador não oferece suporte à palavra-chave usada.

Esse aviso é promovido automaticamente para um erro. Se você quiser modificar esse comportamento, use [#pragma Aviso](../../preprocessor/warning.md). Por exemplo, para tornar o C4235 em um aviso de nível 2, use a seguinte linha de código

```cpp
#pragma warning(2:4235)
```

no arquivo de código-fonte.