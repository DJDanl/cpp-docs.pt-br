---
title: Erro do compilador C3172 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3172
dev_langs:
- C++
helpviewer_keywords:
- C3172
ms.assetid: 1834e2fd-6036-4c33-aff2-b51bc7c99441
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 25c3b1fd9132c6b170fdf74b1619a35d83959f90
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46117628"
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