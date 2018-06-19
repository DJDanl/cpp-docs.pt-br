---
title: Posso reutilizar uma janela do Host? | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- host windows
ms.assetid: bcd08ab1-cfcf-49e3-b4e8-ac134d141005
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e8a108c8c4e9b515a75399f82e333b00a5210e8d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32353699"
---
# <a name="can-i-reuse-a-host-window"></a>Posso reutilizar uma janela do Host?
Não é recomendável que você reutilize windows de host. Para garantir a robustez do seu código, você deve associar o tempo de vida da janela do host para o tempo de vida de um único controle.  
  
## <a name="see-also"></a>Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)

