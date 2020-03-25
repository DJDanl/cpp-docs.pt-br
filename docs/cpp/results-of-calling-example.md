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
ms.openlocfilehash: edbeb187e568b833673d91ef70ff57fbd460659c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179049"
---
# <a name="results-of-calling-example"></a>Resultados do exemplo de chamada

**Seção específica da Microsoft**

## <a name="__cdecl"></a>__cdecl

O nome da função decorada C é `_MyFunc`.

![Convenção de chamada CDECL](../cpp/media/vc37i01.gif "Convenção de chamada CDECL") <br/>
A Convenção de chamada **__cdecl**

## <a name="__stdcall-and-thiscall"></a>__stdcall e thiscall

O nome decorado C ( **__stdcall**) é `_MyFunc@20`. O C++ nome decorado é específico da implementação.

![&#95;&#95;convenções de chamada stdcall e thiscall](../cpp/media/vc37i02.gif "&#95;&#95;convenções de chamada stdcall e thiscall") <br/>
As convenções de chamada __stdcall e thiscall

## <a name="__fastcall"></a>__fastcall

O nome decorado C ( **__fastcall**) é `@MyFunc@20`. O C++ nome decorado é específico da implementação.

![Convenção de chamada &#95; &#95;para fastcall](../cpp/media/vc37i03.gif "Convenção de chamada &#95; &#95;para fastcall") <br/>
A convenção de chamada __fastcall

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Exemplo de chamada: protótipo de função e chamada](../cpp/calling-example-function-prototype-and-call.md)
