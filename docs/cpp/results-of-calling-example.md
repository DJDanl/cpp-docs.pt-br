---
title: Os resultados do exemplo de chamada | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 0e7b022925e22f021a2ddad1b3b9ef52924b25a3
ms.sourcegitcommit: 1fd1eb11f65f2999dfd93a2d924390ed0a0901ed
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/10/2018
ms.locfileid: "37939101"
---
# <a name="results-of-calling-example"></a>Resultados do exemplo de chamada
## <a name="microsoft-specific"></a>Específico da Microsoft  
  
## <a name="cdecl"></a>__cdecl  
 O nome decorado de função C é “_MyFunc”.  
  
 ![Convenção de chamada CDECL](../cpp/media/vc37i01.gif "vc37I01")  
A convenção de chamada __cdecl  
  
## <a name="stdcall-and-thiscall"></a>__stdcall e thiscall  
 O nome decorado C (**stdcall**) é "_MyFunc@20." O nome decorado C++ é proprietário.  
  
 ![&#95;&#95;stdcall e convenções de chamada thiscall](../cpp/media/vc37i02.gif "vc37I02")  
As convenções de chamada __stdcall e thiscall  
  
## <a name="fastcall"></a>__fastcall  
 O nome decorado C (**fastcall**) é "@MyFunc@20." O nome decorado C++ é proprietário.  
  
 ![Chamando convenção para &#95; &#95;fastcall](../cpp/media/vc37i03.gif "vc37I03")  
A convenção de chamada __fastcall  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de chamada: protótipo de função e chamada](../cpp/calling-example-function-prototype-and-call.md)