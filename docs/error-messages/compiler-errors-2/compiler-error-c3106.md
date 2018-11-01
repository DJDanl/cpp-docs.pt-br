---
title: Erro do compilador C3106
ms.date: 11/04/2016
f1_keywords:
- C3106
helpviewer_keywords:
- C3106
ms.assetid: 39d97a32-0905-4702-87d3-7f8ce473fb93
ms.openlocfilehash: 072c87c0264afd585326e5207a494dfb45961b24
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50434496"
---
# <a name="compiler-error-c3106"></a>Erro do compilador C3106

'attribute': argumentos sem nome devem preceder argumentos nomeados

Argumentos sem nome devem ser passados para um atributo antes de argumentos nomeados.

Para obter mais informações, consulte [atributos definidos pelo usuário](../../windows/user-defined-attributes-cpp-component-extensions.md).

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3106.

```
// C3106.cpp
// compile with: /c
[module(name="MyLib", dll)];   // C3106
[module(dll, name="MyLib")];   // OK
```