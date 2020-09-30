---
title: Erro do compilador C3172
ms.date: 11/04/2016
f1_keywords:
- C3172
helpviewer_keywords:
- C3172
ms.assetid: 1834e2fd-6036-4c33-aff2-b51bc7c99441
ms.openlocfilehash: ca0eab35f6e60d81a324156905619ceb7ace8830
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508282"
---
# <a name="compiler-error-c3172"></a>Erro do compilador C3172

' module_name ': não é possível especificar diferentes atributos de idl_module em um projeto

[idl_module](../../windows/attributes/idl-module.md) atributos com o mesmo nome mas diferentes `dllname` ou `version` parâmetros foram encontrados em dois dos arquivos em uma compilação. Somente um `idl_module` atributo exclusivo pode ser especificado por compilação.

Atributos idênticos `idl_module` podem ser especificados em mais de um arquivo de código-fonte.

Por exemplo, se os seguintes `idl_module` atributos foram encontrados:

```cpp
// C3172.cpp
[module(name="MyMod")];
[ idl_module(name="x", dllname="file.dll", version="1.1") ];
int main() {}
```

Assim,

```cpp
// C3172b.cpp
// compile with: C3172.cpp
// C3172 expected
[ idl_module(name="x", dllname="file.dll", version="1.0") ];
```

o compilador geraria C3172 (Observe os valores de versão diferentes).
