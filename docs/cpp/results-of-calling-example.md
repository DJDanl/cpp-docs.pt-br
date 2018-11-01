---
title: Resultados do exemplo de chamada
ms.date: 09/05/2018
helpviewer_keywords:
- examples [C++], results of calling
- results, thiscall call
- results, __fastcall keyword call
- results, __cdecl call
- results, __stdcall call
ms.assetid: aa70a7cb-ba1d-4aa6-bd0a-ba783da2e642
ms.openlocfilehash: 96582e48912bb591d869bbc4df179299e6459f1e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50500927"
---
# <a name="results-of-calling-example"></a>Resultados do exemplo de chamada

**Seção específica da Microsoft**

## <a name="cdecl"></a>__cdecl

O nome decorado de função C é `_MyFunc`.

![Convenção de chamada CDECL](../cpp/media/vc37i01.gif "vc37I01") o **cdecl** convenção de chamada

## <a name="stdcall-and-thiscall"></a>__stdcall e thiscall

O nome decorado C (**stdcall**) é `_MyFunc@20`. O nome decorado C++ é específico da implementação.

![&#95;&#95;stdcall e convenções de chamada thiscall](../cpp/media/vc37i02.gif "vc37I02") o stdcall e thiscall convenções de chamada

## <a name="fastcall"></a>__fastcall

O nome decorado C (**fastcall**) é `@MyFunc@20`. O nome decorado C++ é específico da implementação.

![Chamando convenção para &#95; &#95;fastcall](../cpp/media/vc37i03.gif "vc37I03") a convenção de chamada fastcall

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Exemplo de chamada: protótipo de função e chamada](../cpp/calling-example-function-prototype-and-call.md)