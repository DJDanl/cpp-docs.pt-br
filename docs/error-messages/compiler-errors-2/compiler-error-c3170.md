---
title: Erro do compilador C3170
ms.date: 11/04/2016
f1_keywords:
- C3170
helpviewer_keywords:
- C3170
ms.assetid: ca9a59d6-7df3-42f0-b028-c09d0af3ac2a
ms.openlocfilehash: e2d74a637e2902fcf636b49068882f32aa706f94
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761758"
---
# <a name="compiler-error-c3170"></a>Erro do compilador C3170

Não é possível ter identificadores de módulo diferentes em um projeto

atributos de [módulo](../../windows/module-cpp.md) com nomes diferentes foram encontrados em dois dos arquivos em uma compilação. Somente um atributo de `module` exclusivo pode ser especificado por compilação.

Atributos de `module` idênticos podem ser especificados em mais de um arquivo de código-fonte.

Por exemplo, se os seguintes atributos de módulo foram encontrados:

```cpp
// C3170.cpp
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f") ];
int main() {}
```

E, em seguida,

```cpp
// C3170b.cpp
// compile with: C3170.cpp
// C3170 expected
[ module(name="MyModule1", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f") ];
```

o compilador geraria C3170 (Observe os diferentes nomes).
