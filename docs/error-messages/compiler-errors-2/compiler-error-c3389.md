---
title: Erro do compilador C3389
ms.date: 11/04/2016
f1_keywords:
- C3389
helpviewer_keywords:
- C3389
ms.assetid: eaaffe17-23f2-413c-b1ad-f7220cfa1334
ms.openlocfilehash: b166096390169939f01bcb976a57612f10f7df2e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80201130"
---
# <a name="compiler-error-c3389"></a>Erro do compilador C3389

> __declspec (*palavra-chave*) não pode ser usada com/CLR: pure ou/CLR: safe

## <a name="remarks"></a>Comentários

As opções de compilador **/CLR: Pure** e **/CLR: safe** são preteridas no Visual Studio 2015 e sem suporte no Visual Studio 2017.

Um modificador de [__declspec](../../cpp/declspec.md) usado implica um estado por processo.  [/CLR: Pure](../../build/reference/clr-common-language-runtime-compilation.md) implica um estado por [AppDomain](../../cpp/appdomain.md) .  Portanto, declarar uma variável com o modificador `keyword` **__declspec** e compilar com **/CLR: Pure** não é permitido.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3389:

```cpp
// C3389.cpp
// compile with: /clr:pure /c
__declspec(dllexport) int g2 = 0;   // C3389
```
