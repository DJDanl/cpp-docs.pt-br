---
title: C.1 notação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a23b2631-8096-4bf3-ac23-ba4f4bd7a52a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3d3ada700955c3acd2e96aa3e8a98c25c51393c1
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43766146"
---
# <a name="c1-notation"></a>C.1 Notação
As regras de gramática consistem no nome de um não terminal, seguido por dois-pontos, seguido por alternativas de substituição em linhas separadas.

O termo de expressão sintática<sub>opt</sub> indica que o termo é opcional dentro da substituição.

A expressão sintática *termo*<sub>optseq</sub> é equivalente a *termo seq*<sub>aceitar</sub> com as seguintes regras adicionais:

*termo seq* :<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Termo*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*termo-seq* *termo*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*termo-seq* **,** *termo*