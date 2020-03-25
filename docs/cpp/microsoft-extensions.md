---
title: Extensões da Microsoft
ms.date: 11/04/2016
helpviewer_keywords:
- Microsoft extensions to C/C++
ms.assetid: 68654516-24ef-4f33-aae2-175f86cc1979
ms.openlocfilehash: a2d0846e55122f177b4868c2e80c4f1d27267f5e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80179400"
---
# <a name="microsoft-extensions"></a>Extensões da Microsoft

*instrução ASM*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__asm***de instruções de assembly* **;** <sub>aceitar</sub><br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__asm {** *assembly-Instruction-List* **};** <sub>aceitar</sub>

*lista de instruções de assembly*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*instrução de assembly* **;** <sub>aceitar</sub> <br/>
&nbsp;&nbsp;&nbsp;&nbsp;*assembly-Instruction* **;** *assembly – instrução-List* **;** <sub>aceitar</sub>

*MS-modificador-List*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;o *MS-modificador* *MS-modificador de lista*<sub>opt</sub>

*MS-modificador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__cdecl**<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__fastcall**<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__stdcall**<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__syscall** (reservado para implementações futuras)<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__oldcall** (reservado para implementações futuras)<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__unaligned** (reservado para implementações futuras)<br/>
&nbsp;&nbsp;&nbsp;*modificador baseado* em &nbsp;

*com base em modificador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp; **__based (** *tipo baseado* **)**

*tipo baseado em*:<br/>
&nbsp;&nbsp;*nome* do &nbsp;&nbsp;
