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
ms.openlocfilehash: 5687adfada8657ae26edd9001db8990ff08864e9
ms.sourcegitcommit: d10a2382832373b900b1780e1190ab104175397f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2018
ms.locfileid: "43894688"
---
# <a name="results-of-calling-example"></a>Resultados do exemplo de chamada

**Seção específica da Microsoft**

## <a name="cdecl"></a>__cdecl
O nome decorado de função C é `_MyFunc`.

![Convenção de chamada CDECL](../cpp/media/vc37i01.gif "vc37I01")  
O **cdecl** convenção de chamada

## <a name="stdcall-and-thiscall"></a>__stdcall e thiscall

O nome decorado C (**stdcall**) é `_MyFunc@20`. O nome decorado C++ é específico da implementação.

![&#95;&#95;stdcall e convenções de chamada thiscall](../cpp/media/vc37i02.gif "vc37I02")  
As convenções de chamada __stdcall e thiscall

## <a name="fastcall"></a>__fastcall

O nome decorado C (**fastcall**) é `@MyFunc@20`. O nome decorado C++ é específico da implementação.

![Chamando convenção para &#95; &#95;fastcall](../cpp/media/vc37i03.gif "vc37I03")  
A convenção de chamada __fastcall

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Exemplo de chamada: protótipo de função e chamada](../cpp/calling-example-function-prototype-and-call.md)