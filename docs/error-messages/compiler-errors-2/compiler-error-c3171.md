---
title: Erro do compilador C3171
ms.date: 11/04/2016
f1_keywords:
- C3171
helpviewer_keywords:
- C3171
ms.assetid: 1ce26997-7ef1-4c9f-84da-003ea1a4251e
ms.openlocfilehash: 602c9ca1051646fca2c5788c036354047fad2522
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50599466"
---
# <a name="compiler-error-c3171"></a>Erro do compilador C3171

'module': não é possível especificar atributos de módulo diferentes em um projeto

[módulo](../../windows/module-cpp.md) atributos com listas de parâmetros diferentes foram encontrados em dois dos arquivos em uma compilação. Somente um exclusivo `module` atributo pode ser especificado por compilação.

Idêntico `module` atributos podem ser especificados em mais de um arquivo de código de origem.

Por exemplo, se o seguinte `module` atributos foram encontrados:

```
// C3171.cpp
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f", version="1.0") ];
int main() {}
```

E, em seguida,

```
// C3171b.cpp
// compile with: C3171.cpp
// C3171 expected
[ module(name="MyModule", uuid="373a1a4e-469b-11d3-a6b0-00c04f79ae8f", version="1.1") ];
```

o compilador geraria C3171 (Observe os valores de versão diferente).