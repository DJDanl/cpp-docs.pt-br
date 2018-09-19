---
title: Erro do compilador C3171 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3171
dev_langs:
- C++
helpviewer_keywords:
- C3171
ms.assetid: 1ce26997-7ef1-4c9f-84da-003ea1a4251e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 32c58f2ecd9651c347f45c29139ffe0ed65a6e3b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46082255"
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