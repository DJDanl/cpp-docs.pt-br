---
title: Erro do compilador C3172
ms.date: 11/04/2016
f1_keywords:
- C3172
helpviewer_keywords:
- C3172
ms.assetid: 1834e2fd-6036-4c33-aff2-b51bc7c99441
ms.openlocfilehash: 1da2676d660d23e3fb71b56263779b1f1edacbf9
ms.sourcegitcommit: 16fa847794b60bf40c67d20f74751a67fccb602e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/03/2019
ms.locfileid: "74761732"
---
# <a name="compiler-error-c3172"></a>Erro do compilador C3172

' module_name ': não é possível especificar diferentes atributos de idl_module em um projeto

[idl_module](../../windows/idl-module.md) atributos com o mesmo nome, mas diferentes `dllname` ou `version` parâmetros foram encontrados em dois dos arquivos em uma compilação. Somente um atributo de `idl_module` exclusivo pode ser especificado por compilação.

Atributos de `idl_module` idênticos podem ser especificados em mais de um arquivo de código-fonte.

Por exemplo, se os seguintes atributos de `idl_module` foram encontrados:

```cpp
// C3172.cpp
[module(name="MyMod")];
[ idl_module(name="x", dllname="file.dll", version="1.1") ];
int main() {}
```

E, em seguida,

```cpp
// C3172b.cpp
// compile with: C3172.cpp
// C3172 expected
[ idl_module(name="x", dllname="file.dll", version="1.0") ];
```

o compilador geraria C3172 (Observe os valores de versão diferentes).
