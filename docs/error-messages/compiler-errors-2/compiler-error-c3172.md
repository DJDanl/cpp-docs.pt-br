---
title: Erro do compilador C3172
ms.date: 11/04/2016
f1_keywords:
- C3172
helpviewer_keywords:
- C3172
ms.assetid: 1834e2fd-6036-4c33-aff2-b51bc7c99441
ms.openlocfilehash: 5c9c1561b63c740b9f7f5d85b2bf3e04de2542c0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62175180"
---
# <a name="compiler-error-c3172"></a>Erro do compilador C3172

'module_name': não é possível especificar atributos de idl_module diferentes em um projeto

[idl_module](../../windows/idl-module.md) atributos com o mesmo nome, mas diferentes `dllname` ou `version` parâmetros foram encontrados em dois dos arquivos em uma compilação. Somente um exclusivo `idl_module` atributo pode ser especificado por compilação.

Idêntico `idl_module` atributos podem ser especificados em mais de um arquivo de código de origem.

Por exemplo, se o seguinte `idl_module` atributos foram encontrados:

```
// C3172.cpp
[module(name="MyMod")];
[ idl_module(name="x", dllname="file.dll", version="1.1") ];
int main() {}
```

E, em seguida,

```
// C3172b.cpp
// compile with: C3172.cpp
// C3172 expected
[ idl_module(name="x", dllname="file.dll", version="1.0") ];
```

o compilador geraria C3172 (Observe os valores de versão diferente).