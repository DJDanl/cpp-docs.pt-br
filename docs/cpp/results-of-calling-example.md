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
ms.openlocfilehash: dcd1f9002362b7726883c6ce4f74fda9ab593544
ms.sourcegitcommit: 9e891eb17b73d98f9086d9d4bfe9ca50415d9a37
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2018
ms.locfileid: "52175399"
---
# <a name="results-of-calling-example"></a>Resultados do exemplo de chamada

**Seção específica da Microsoft**

## <a name="cdecl"></a>__cdecl

O nome decorado de função C é `_MyFunc`.

![Convenção de chamada CDECL](../cpp/media/vc37i01.gif "convenção de chamada CDECL") <br/>
O **cdecl** convenção de chamada

## <a name="stdcall-and-thiscall"></a>__stdcall e thiscall

O nome decorado C (**stdcall**) é `_MyFunc@20`. O nome decorado C++ é específico da implementação.

![&#95;&#95;stdcall e convenções de chamada thiscall](../cpp/media/vc37i02.gif "&#95;&#95;stdcall e thiscall convenções de chamada") <br/>
As convenções de chamada __stdcall e thiscall

## <a name="fastcall"></a>__fastcall

O nome decorado C (**fastcall**) é `@MyFunc@20`. O nome decorado C++ é específico da implementação.

![Chamando convenção para &#95; &#95;fastcall](../cpp/media/vc37i03.gif "chamando convenção para &#95; &#95;fastcall") <br/>
A convenção de chamada __fastcall

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Exemplo de chamada: protótipo de função e chamada](../cpp/calling-example-function-prototype-and-call.md)