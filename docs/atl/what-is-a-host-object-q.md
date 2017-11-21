---
title: "O que é um objeto de Host? (ATL) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: host objects
ms.assetid: 4f8da992-b27e-45e8-b5e0-c8b1dcae4fac
caps.latest.revision: "12"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: ab37e9a9d3a19f250f52d5f5c60de41968012625
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="what-is-a-host-object"></a>O que é um objeto de Host?
Um objeto de host é um objeto COM que representa o contêiner de controle ActiveX fornecido pelo ATL para uma janela específica. O objeto de host subclasses de janela de contêiner que pode refletir mensagens para o controle, ele fornece as interfaces necessárias contêiner a ser usado pelo controle e expõe o [IAxWinHostWindow](../atl/reference/iaxwinhostwindow-interface.md) e [ IAxWinAmbientDispatch](../atl/reference/iaxwinambientdispatch-interface.md) interfaces para permitir que você configure o ambiente do controle.  
  
 Você pode usar o objeto de host para definir as propriedades de ambiente do contêiner.  
  
## <a name="see-also"></a>Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)

