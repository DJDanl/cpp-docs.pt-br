---
title: Resultados do exemplo de chamada
ms.date: 11/19/2018
helpviewer_keywords:
- examples [C++], results of calling
- results, thiscall call
- results, __fastcall keyword call
- results, __cdecl call
- results, __stdcall call
ms.assetid: aa70a7cb-ba1d-4aa6-bd0a-ba783da2e642
ms.openlocfilehash: 1bf5fe62b8ef2b7a37bf72b7a40e5d47af3f3961
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87225872"
---
# <a name="results-of-calling-example"></a>Resultados do exemplo de chamada

**Específico da Microsoft**

## <a name="__cdecl"></a>__cdecl

O nome da função decorada C é `_MyFunc` .

![Convenção de chamada CDECL](../cpp/media/vc37i01.gif "Convenção de chamada CDECL") <br/>
A **`__cdecl`** Convenção de chamada

## <a name="__stdcall-and-thiscall"></a>__stdcall e thiscall

O nome decorado C ( **`__stdcall`** ) é `_MyFunc@20` . O nome decorado em C++ é específico da implementação.

![&#95;&#95;convenções de chamada stdcall e thiscall](../cpp/media/vc37i02.gif "&#95;&#95;convenções de chamada stdcall e thiscall") <br/>
As convenções de chamada __stdcall e thiscall

## <a name="__fastcall"></a>__fastcall

O nome decorado C ( **`__fastcall`** ) é `@MyFunc@20` . O nome decorado em C++ é específico da implementação.

![Convenção de chamada para &#95;&#95;fastcall](../cpp/media/vc37i03.gif "Convenção de chamada para &#95;&#95;fastcall") <br/>
A convenção de chamada __fastcall

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Exemplo de chamada: protótipo de função e chamada](../cpp/calling-example-function-prototype-and-call.md)
