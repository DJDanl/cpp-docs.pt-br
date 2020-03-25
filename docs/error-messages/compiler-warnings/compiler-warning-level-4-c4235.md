---
title: Aviso do compilador (nível 4) C4235
ms.date: 11/04/2016
f1_keywords:
- C4235
helpviewer_keywords:
- C4235
ms.assetid: d4214799-d62c-4674-b4e2-9e201c303303
ms.openlocfilehash: df80bec2294929be463425d74d4bf00421b368e6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198426"
---
# <a name="compiler-warning-level-4-c4235"></a>Aviso do compilador (nível 4) C4235

extensão não padrão usada: palavra-chave ' keyword ' sem suporte nesta arquitetura

O compilador não oferece suporte à palavra-chave usada.

Esse aviso é promovido automaticamente para um erro. Se você quiser modificar esse comportamento, use [#pragma Aviso](../../preprocessor/warning.md). Por exemplo, para tornar o C4235 em um aviso de nível 2, use a seguinte linha de código

```cpp
#pragma warning(2:4235)
```

no arquivo de código-fonte.
