---
title: "Quando é necessário chamar AtlAxWinInit? | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: AtlAxWinInit
dev_langs: C++
helpviewer_keywords: AtlAxWinInit method
ms.assetid: 080b9cfe-d85a-4439-a9e9-ab3966ebaa8e
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 2ec7d8d15b8219071b593368ed539d92ff3c9032
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="when-do-i-need-to-call-atlaxwininit"></a>Quando é necessário chamar AtlAxWinInit?

[AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit) registra o **"AtlAxWin80"** classe de janela (além de algumas mensagens de janela personalizada) para essa função deve ser chamada antes de tentar criar uma janela do host. No entanto, não sempre é necessário chamar essa função explicitamente, desde a hospedagem de APIs (e as classes que usá-las) esta função é chamada para você. Não há nenhum problema em mais de uma vez ao chamar essa função. .  
  
## <a name="see-also"></a>Consulte também  
 Quando é necessário chamar AtlAxWinTerm     
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)
