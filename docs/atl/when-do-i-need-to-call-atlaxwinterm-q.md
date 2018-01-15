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
ms.workload: cplusplus
ms.openlocfilehash: c52c5295108ef01dc23ea9f945850e91a9806d6f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="when-do-i-need-to-call-atlaxwinterm"></a>Quando é necessário chamar AtlAxWinTerm?
[AtlAxWinTerm](reference/composite-control-global-functions.md#atlaxwinterm) cancela o registro de **"AtlAxWin80"** classe de janela. Você deve chamar essa função (se você não precisa criar janelas de host), depois que todas as janelas de host existente tiveram sido destruídas. Se você não chamar essa função, a classe de janela será cancelada automaticamente quando o processo é encerrado.  
  
## <a name="see-also"></a>Consulte também  
 Quando é necessário chamar AtlAxWinInit  
[Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)

