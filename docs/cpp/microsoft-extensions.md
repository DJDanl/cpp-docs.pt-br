---
title: Extensões da Microsoft | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- Microsoft extensions to C/C++
ms.assetid: 68654516-24ef-4f33-aae2-175f86cc1979
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5699ce82a6e8537f12da50fdcb8288da167ecca3
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43752233"
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