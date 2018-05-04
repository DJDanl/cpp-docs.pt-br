---
title: Quando é necessário chamar AtlAxWinInit? | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- AtlAxWinInit
dev_langs:
- C++
helpviewer_keywords:
- AtlAxWinInit method
ms.assetid: 080b9cfe-d85a-4439-a9e9-ab3966ebaa8e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bd9aa1dd14ccae555d4ab9acbbac15e9b66cafe6
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="when-do-i-need-to-call-atlaxwininit"></a>Quando é necessário chamar AtlAxWinInit?

[AtlAxWinInit](reference/composite-control-global-functions.md#atlaxwininit) registra o **"AtlAxWin80"** classe de janela (além de algumas mensagens de janela personalizada) para essa função deve ser chamada antes de tentar criar uma janela do host. No entanto, não sempre é necessário chamar essa função explicitamente, desde a hospedagem de APIs (e as classes que usá-las) esta função é chamada para você. Não há nenhum problema em mais de uma vez ao chamar essa função. .  
  
## <a name="see-also"></a>Consulte também  
 Quando é necessário chamar AtlAxWinTerm     
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)
