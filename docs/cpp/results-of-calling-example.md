---
title: Resultados do exemplo de chamada | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- examples [C++], results of calling
- results, thiscall call
- results, __fastcall keyword call
- results, __cdecl call
- results, __stdcall call
ms.assetid: aa70a7cb-ba1d-4aa6-bd0a-ba783da2e642
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 960dab7458af70d79fbcbc575e2fcd0e5678c3c6
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="results-of-calling-example"></a>Resultados do exemplo de chamada
## <a name="microsoft-specific"></a>Específico da Microsoft  
  
## <a name="cdecl"></a>__cdecl  
 O nome decorado de função C é “_MyFunc”.  
  
 ![Convenção de chamada CDECL](../cpp/media/vc37i01.gif "vc37I01")  
A convenção de chamada __cdecl  
  
## <a name="stdcall-and-thiscall"></a>__stdcall e thiscall  
 O C decorado nome (`__stdcall`) é "_MyFunc@20." O nome decorado C++ é proprietário.  
  
 ![&#95; &#95; stdcall e convenções de chamada thiscall](../cpp/media/vc37i02.gif "vc37I02")  
As convenções de chamada __stdcall e thiscall  
  
## <a name="fastcall"></a>__fastcall  
 O C decorado nome (`__fastcall`) é "@MyFunc@20." O nome decorado C++ é proprietário.  
  
 ![Convenção de chamada para #95; &#95; fastcall](../cpp/media/vc37i03.gif "vc37I03")  
A convenção de chamada __fastcall  
  
**Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo de chamada: protótipo de função e chamada](../cpp/calling-example-function-prototype-and-call.md)