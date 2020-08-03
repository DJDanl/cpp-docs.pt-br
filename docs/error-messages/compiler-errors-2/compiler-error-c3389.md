---
title: Erro do compilador C3389
ms.date: 11/04/2016
f1_keywords:
- C3389
helpviewer_keywords:
- C3389
ms.assetid: eaaffe17-23f2-413c-b1ad-f7220cfa1334
ms.openlocfilehash: 8a040e649074e115b1b86ea56db6c9ef48f4c0d0
ms.sourcegitcommit: f2a135d69a2a8ef1777da60c53d58fe06980c997
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/03/2020
ms.locfileid: "87520455"
---
# <a name="compiler-error-c3389"></a>Erro do compilador C3389

> __declspec (*palavra-chave*) não pode ser usada com/CLR: pure ou/CLR: safe

## <a name="remarks"></a>Comentários

As **`/clr:pure`** **`/clr:safe`** Opções de compilador e são preteridas no visual Studio 2015 e sem suporte no visual Studio 2017.

Um [`__declspec`](../../cpp/declspec.md) modificador usado implica em um estado por processo.  [`/clr:pure`](../../build/reference/clr-common-language-runtime-compilation.md)implica um por [`appdomain`](../../cpp/appdomain.md) estado.  Portanto, a declaração de uma variável com o modificador de *palavra-chave* **`__declspec`** e a compilação com **`/clr:pure`** não é permitida.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3389:

```cpp
// C3389.cpp
// compile with: /clr:pure /c
__declspec(dllexport) int g2 = 0;   // C3389
```
