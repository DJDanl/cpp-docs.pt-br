---
title: Erro do compilador C3171
ms.date: 11/04/2016
f1_keywords:
- C3171
helpviewer_keywords:
- C3171
ms.assetid: 1ce26997-7ef1-4c9f-84da-003ea1a4251e
ms.openlocfilehash: a3af19fa6b4f4def9bb42325f648109cfafcdaef
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761745"
---
# <a name="compiler-error-c3171"></a>Erro do compilador C3171

' module ': não é possível especificar atributos de módulo diferentes em um projeto

atributos de [módulo](../../windows/module-cpp.md) com listas de parâmetros diferentes foram encontrados em dois dos arquivos em uma compilação. Somente um atributo de `module` exclusivo pode ser especificado por compilação.

Atributos de `module` idênticos podem ser especificados em mais de um arquivo de código-fonte.

Por exemplo, se os seguintes atributos de `module` foram encontrados:

```cpp
// C3171.cpp
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f", version="1.0") ];
int main() {}
```

E, em seguida,

```cpp
// C3171b.cpp
// compile with: C3171.cpp
// C3171 expected
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f", version="1.1") ];
```

o compilador geraria C3171 (Observe os valores de versão diferentes).
