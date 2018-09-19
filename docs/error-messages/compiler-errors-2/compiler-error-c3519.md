---
title: Erro do compilador C3519 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3519
dev_langs:
- C++
helpviewer_keywords:
- C3519
ms.assetid: ca24b2bc-7e90-4448-ae84-3fedddf9bca7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8ac9c1bfe01cee659ae8b637df23a86315b5310f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46072778"
---
# <a name="compiler-error-c3519"></a>Erro do compilador C3519

'invalid_param': parâmetro inválido para atributo embedded_idl

Foi passado um parâmetro para o `embedded_idl` atributo de [#import](../../preprocessor/hash-import-directive-cpp.md), mas o compilador não reconheceu o parâmetro.

Os únicos parâmetros que têm permissão para `embedded_idl` estão `emitidl` e `no_emitidl`.

O exemplo a seguir gera C3519:

```
// C3519.cpp
// compile with: /LD
[module(name="MyLib2")];
#import "C:\testdir\bin\importlib.tlb" embedded_idl("no_emitidcl")
// C3519
#import "C:\testdir\bin\importlib.tlb" embedded_idl("no_emitidl")
// OK
```