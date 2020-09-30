---
title: Erro do compilador C3171
ms.date: 11/04/2016
f1_keywords:
- C3171
helpviewer_keywords:
- C3171
ms.assetid: 1ce26997-7ef1-4c9f-84da-003ea1a4251e
ms.openlocfilehash: 14f0cedc5448005a29d74f05ae3e68e74eb5cf1c
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508299"
---
# <a name="compiler-error-c3171"></a>Erro do compilador C3171

' module ': não é possível especificar atributos de módulo diferentes em um projeto

atributos de [módulo](../../windows/attributes/module-cpp.md) com listas de parâmetros diferentes foram encontrados em dois dos arquivos em uma compilação. Somente um `module` atributo exclusivo pode ser especificado por compilação.

Atributos idênticos `module` podem ser especificados em mais de um arquivo de código-fonte.

Por exemplo, se os seguintes `module` atributos foram encontrados:

```cpp
// C3171.cpp
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f", version="1.0") ];
int main() {}
```

Assim,

```cpp
// C3171b.cpp
// compile with: C3171.cpp
// C3171 expected
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f", version="1.1") ];
```

o compilador geraria C3171 (Observe os valores de versão diferentes).
