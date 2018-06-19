---
title: O que é um objeto de Host? (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- host objects
ms.assetid: 4f8da992-b27e-45e8-b5e0-c8b1dcae4fac
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8d197f02949f6eaaeee50b428338684135d1db27
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32357728"
---
# <a name="what-is-a-host-object"></a>O que é um objeto de Host?
Um objeto de host é um objeto COM que representa o contêiner de controle ActiveX fornecido pelo ATL para uma janela específica. O objeto de host subclasses de janela de contêiner que pode refletir mensagens para o controle, ele fornece as interfaces necessárias contêiner a ser usado pelo controle e expõe o [IAxWinHostWindow](../atl/reference/iaxwinhostwindow-interface.md) e [ IAxWinAmbientDispatch](../atl/reference/iaxwinambientdispatch-interface.md) interfaces para permitir que você configure o ambiente do controle.  
  
 Você pode usar o objeto de host para definir as propriedades de ambiente do contêiner.  
  
## <a name="see-also"></a>Consulte também  
 [Perguntas frequentes sobre contenção de controle](../atl/atl-control-containment-faq.md)

