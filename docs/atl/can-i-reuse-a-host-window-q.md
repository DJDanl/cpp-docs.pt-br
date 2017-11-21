---
title: Posso reutilizar uma janela do Host? | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: host windows
ms.assetid: bcd08ab1-cfcf-49e3-b4e8-ac134d141005
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 3c7ec1a356382451fecda37fa4aba2facc8c9d02
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="can-i-reuse-a-host-window"></a>Posso reutilizar uma janela do Host?
Não é recomendável que você reutilize windows de host. Para garantir a robustez do seu código, você deve associar o tempo de vida da janela do host para o tempo de vida de um único controle.  
  
## <a name="see-also"></a>Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)

