---
title: Erro do compilador C3455
ms.date: 11/04/2016
f1_keywords:
- C3455
helpviewer_keywords:
- C3455
ms.assetid: 218e5cfe-5391-4eeb-81c2-85c47e3a6cd2
ms.openlocfilehash: 4451ddbd8d5a7125112ef8e1c58e8843095bffd4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50614390"
---
# <a name="compiler-error-c3455"></a>Erro do compilador C3455

'attribute': nenhum dos construtores de atributo corresponderam aos argumentos

Um valor inválido foi usado para declarar um atributo.  Ver [atributo](../../windows/attributes/attribute.md) para obter mais informações.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3455.

```
// C3455.cpp
// compile with: /clr /c
using namespace System;

[attribute("MyAt")]   // C3455
// try the following line instead
// [attribute(All)]
ref struct MyAttr {
   MyAttr() {}
};
```