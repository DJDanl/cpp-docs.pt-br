---
title: Erro do compilador C3170
ms.date: 11/04/2016
f1_keywords:
- C3170
helpviewer_keywords:
- C3170
ms.assetid: ca9a59d6-7df3-42f0-b028-c09d0af3ac2a
ms.openlocfilehash: c4eb4a2551312791d05c8badb66af0070e74b630
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508331"
---
# <a name="compiler-error-c3170"></a>Erro do compilador C3170

Não é possível ter identificadores de módulo diferentes em um projeto

atributos de [módulo](../../windows/attributes/module-cpp.md) com nomes diferentes foram encontrados em dois dos arquivos em uma compilação. Somente um `module` atributo exclusivo pode ser especificado por compilação.

Atributos idênticos `module` podem ser especificados em mais de um arquivo de código-fonte.

Por exemplo, se os seguintes atributos de módulo foram encontrados:

```cpp
// C3170.cpp
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f") ];
int main() {}
```

Assim,

```cpp
// C3170b.cpp
// compile with: C3170.cpp
// C3170 expected
[ module(name="MyModule1", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f") ];
```

o compilador geraria C3170 (Observe os diferentes nomes).
