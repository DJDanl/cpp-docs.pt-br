---
title: "Classes de suporte de interface do usuário (ATL) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.atl.ui
dev_langs: C++
helpviewer_keywords:
- user interfaces, support classes
- user interfaces, ATL classes
ms.assetid: 313dfc95-308a-4118-b919-5a3c3673b865
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 717e6cfc00c3d2442426698d910baac3c7fcb829
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ui-support-classes"></a>Classes de suporte de interface do usuário
As classes a seguir fornecem suporte geral de interface do usuário:  
  
-   [IDocHostUIHandlerDispatch](../atl/reference/idochostuihandlerdispatch-interface.md) uma interface para a análise de HTML da Microsoft e o mecanismo de renderização.  
  
-   [IOleObjectImpl](../atl/reference/ioleobjectimpl-class.md) fornece os principais métodos por meio do qual um contêiner se comunica com um controle. Gerencia a ativação e desativação de controles no local.  
  
-   [IOleInPlaceObjectWindowlessImpl](../atl/reference/ioleinplaceobjectwindowlessimpl-class.md) gerencia a reativação de controles no local. Permite que um controle sem janelas para receber mensagens, bem como para participar de operações de arrastar e soltar.  
  
-   [IOleInPlaceActiveObjectImpl](../atl/reference/ioleinplaceactiveobjectimpl-class.md) ajuda a comunicação entre um controle no local e o contêiner.  
  
-   [IViewObjectExImpl](../atl/reference/iviewobjecteximpl-class.md) permite um controle para exibir próprio diretamente e notificar o contêiner de alterações em sua exibição. Fornece suporte para desenho cintilação, controles não retangulares e transparentes e teste de clique.  
  
## <a name="related-articles"></a>Artigos relacionados  
 [Tutorial da ATL](../atl/active-template-library-atl-tutorial.md)  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../atl/atl-class-overview.md)

