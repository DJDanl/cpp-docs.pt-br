---
title: Erro do compilador C3389
ms.date: 11/04/2016
f1_keywords:
- C3389
helpviewer_keywords:
- C3389
ms.assetid: eaaffe17-23f2-413c-b1ad-f7220cfa1334
ms.openlocfilehash: 6a9568f3c3be88438eae1f28e12dc780301ead0b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50584295"
---
# <a name="compiler-error-c3389"></a>Erro do compilador C3389

> declspec (*palavra-chave*) não pode ser usado com /clr: pure ou /CLR: safe

## <a name="remarks"></a>Comentários

O **/clr: pure** e **/CLR: safe** opções do compilador são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Um [declspec](../../cpp/declspec.md) modificador usado implica um segundo o estado do processo.  [/CLR: pure](../../build/reference/clr-common-language-runtime-compilation.md) implica um por [appdomain](../../cpp/appdomain.md) estado.  Assim, declarando uma variável com o `keyword` **declspec** modificador e compilar com **/clr: pure** não é permitido.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3389:

```cpp
// C3389.cpp
// compile with: /clr:pure /c
__declspec(dllexport) int g2 = 0;   // C3389
```