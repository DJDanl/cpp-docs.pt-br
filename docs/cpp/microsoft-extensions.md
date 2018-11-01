---
title: Extensões da Microsoft
ms.date: 11/04/2016
helpviewer_keywords:
- Microsoft extensions to C/C++
ms.assetid: 68654516-24ef-4f33-aae2-175f86cc1979
ms.openlocfilehash: d8104c2df2335e11dcb711108d566e0fdd069762
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50592199"
---
# <a name="microsoft-extensions"></a>Extensões da Microsoft

*instrução ASM*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**ASM***instrução de assembly* **;** <sub>otimizado  </sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp;**ASM {***lista de instruções de assembly***};** <sub>otimizado    </sub>

*lista de instruções de assembly*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de assembly* **;** <sub>otimizado</sub> <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de assembly* **;** *lista de instruções de assembly* **;** <sub>otimizado</sub>

*lista de modificador MS*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*MS-modifier* *modificador-ms-list*<sub>otimizado</sub>

*MS-modifier*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**cdecl**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**fastcall**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**stdcall**<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**syscall** (reservado para implementações futuras)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**{1&gt;__oldcall&lt;1** (reservado para implementações futuras)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**unaligned** (reservado para implementações futuras)<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*modificador com base em*

*modificador com base em*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**based (** *tipo com base em* **)**

*texto com base em*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Nome*