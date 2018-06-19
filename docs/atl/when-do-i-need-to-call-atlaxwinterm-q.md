---
title: Quando é necessário chamar AtlAxWinTerm? | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- AtlAxWinTerm
dev_langs:
- C++
helpviewer_keywords:
- AtlAxWinTerm method
ms.assetid: 0088d494-2d8d-45b4-b582-2af726bd6cbd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 61830023d3fb67d331784769f32cda4eee8355b5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32360156"
---
# <a name="when-do-i-need-to-call-atlaxwinterm"></a>Quando é necessário chamar AtlAxWinTerm?
[AtlAxWinTerm](reference/composite-control-global-functions.md#atlaxwinterm) cancela o registro de **"AtlAxWin80"** classe de janela. Você deve chamar essa função (se você não precisa criar janelas de host), depois que todas as janelas de host existente tiveram sido destruídas. Se você não chamar essa função, a classe de janela será cancelada automaticamente quando o processo é encerrado.  
  
## <a name="see-also"></a>Consulte também  
 Quando é necessário chamar AtlAxWinInit  
[Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)

