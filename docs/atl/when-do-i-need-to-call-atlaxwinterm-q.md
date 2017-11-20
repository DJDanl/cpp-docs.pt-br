---
title: "Quando é necessário chamar AtlAxWinTerm? | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: AtlAxWinTerm
dev_langs: C++
helpviewer_keywords: AtlAxWinTerm method
ms.assetid: 0088d494-2d8d-45b4-b582-2af726bd6cbd
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: cdba5255560f220a80a016f17e574721b12f486d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="when-do-i-need-to-call-atlaxwinterm"></a>Quando é necessário chamar AtlAxWinTerm?
[AtlAxWinTerm](reference/composite-control-global-functions.md#atlaxwinterm) cancela o registro de **"AtlAxWin80"** classe de janela. Você deve chamar essa função (se você não precisa criar janelas de host), depois que todas as janelas de host existente tiveram sido destruídas. Se você não chamar essa função, a classe de janela será cancelada automaticamente quando o processo é encerrado.  
  
## <a name="see-also"></a>Consulte também  
 Quando é necessário chamar AtlAxWinInit  
[Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)

