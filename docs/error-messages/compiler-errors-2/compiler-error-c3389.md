---
title: Erro do compilador C3389
ms.date: 11/04/2016
f1_keywords:
- C3389
helpviewer_keywords:
- C3389
ms.assetid: eaaffe17-23f2-413c-b1ad-f7220cfa1334
ms.openlocfilehash: 823b28deae3e3cfc18cdad8d37007bf8e8cff494
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221049"
---
# <a name="compiler-error-c3389"></a>Erro do compilador C3389

> __declspec (*palavra-chave*) não pode ser usada com/CLR: pure ou/CLR: safe

## <a name="remarks"></a>Comentários

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Um modificador de [__declspec](../../cpp/declspec.md) usado implica um estado por processo.  [/CLR: Pure](../../build/reference/clr-common-language-runtime-compilation.md) implica um estado por [AppDomain](../../cpp/appdomain.md) .  Portanto, a declaração de uma variável com o `keyword` **`__declspec`** modificador e a compilação com **/CLR: Pure** não é permitida.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3389:

```cpp
// C3389.cpp
// compile with: /clr:pure /c
__declspec(dllexport) int g2 = 0;   // C3389
```
