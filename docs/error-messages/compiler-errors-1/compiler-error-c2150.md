---
title: Erro do compilador C2150 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2150
dev_langs:
- C++
helpviewer_keywords:
- C2150
ms.assetid: 21e82a10-c1d4-4c0d-9dc6-c5d92ea42a31
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ef0920c98fe59fe5bca49bba4c62a486a61c0a55
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46024704"
---
# <a name="compiler-error-c2150"></a>Erro do compilador C2150

> '*identificador*': campo de bits deve possuir tipo 'int', 'signed int' ou 'unsigned int'

O tipo base para um campo de bits é necessário para ser `int`, `signed int`, ou `unsigned int`.

## <a name="example"></a>Exemplo

Este exemplo mostra como você pode encontrar C2150 e como corrigi-lo:

```cpp
// C2150.cpp
// compile with: /c
struct A {
   float a : 8;    // C2150
   int i : 8;      // OK
};
```