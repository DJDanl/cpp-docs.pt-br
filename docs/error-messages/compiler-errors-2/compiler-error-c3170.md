---
title: Erro do compilador C3170
ms.date: 11/04/2016
f1_keywords:
- C3170
helpviewer_keywords:
- C3170
ms.assetid: ca9a59d6-7df3-42f0-b028-c09d0af3ac2a
ms.openlocfilehash: 5ef39e4580601dd90b5695d9115902bb5b834409
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62174699"
---
# <a name="compiler-error-c3170"></a>Erro do compilador C3170

não é possível ter identificadores de módulo diferentes em um projeto

[módulo](../../windows/module-cpp.md) atributos com nomes diferentes foram encontrados em dois dos arquivos em uma compilação. Somente um exclusivo `module` atributo pode ser especificado por compilação.

Idêntico `module` atributos podem ser especificados em mais de um arquivo de código de origem.

Por exemplo, se os atributos de módulo a seguir foram encontrados:

```
// C3170.cpp
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f") ];
int main() {}
```

E, em seguida,

```
// C3170b.cpp
// compile with: C3170.cpp
// C3170 expected
[ module(name="MyModule1", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f") ];
```

o compilador geraria C3170 (Observe os nomes diferentes).