---
title: Aviso do compilador (nível 1 e nível 4) C4949
ms.date: 11/04/2016
f1_keywords:
- C4949
helpviewer_keywords:
- C4949
ms.assetid: 34f45a05-c115-49cb-9f67-0bd4f0735d9b
ms.openlocfilehash: f2876813131271ebb2561f8ea7435bb96dc2ce17
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73627409"
---
# <a name="compiler-warning-level-1-and-level-4-c4949"></a>Aviso do compilador (nível 1 e nível 4) C4949

pragmas "Managed" e "Unmanaged" são significativos somente quando compilados com "/CLR [: Option]"

O compilador ignora os pragmas [gerenciados](../../preprocessor/managed-unmanaged.md) e não gerenciados se o código-fonte não for compilado com [/CLR](../../build/reference/clr-common-language-runtime-compilation.md). Esse aviso é informativo.

O exemplo a seguir gera C4949:

```cpp
// C4949.cpp
// compile with: /LD /W1
#pragma managed   // C4949
```

Quando **#pragma não gerenciado** é usado sem **/CLR**, C4949 é um aviso de nível 4.

O exemplo a seguir gera C4949:

```cpp
// C4949b.cpp
// compile with: /LD /W4
#pragma unmanaged   // C4949
```