---
title: Os resultados do exemplo de chamada | Microsoft Docs
ms.custom: ''
ms.date: 09/05/2018
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- examples [C++], results of calling
- results, thiscall call
- results, __fastcall keyword call
- results, __cdecl call
- results, __stdcall call
ms.assetid: aa70a7cb-ba1d-4aa6-bd0a-ba783da2e642
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a8f09109aab5823f339de76a1337eea77a0794cb
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46037743"
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