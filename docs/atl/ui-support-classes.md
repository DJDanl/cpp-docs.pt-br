---
title: Classes de suporte de interface do usuário (ATL)
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- vc.atl.ui
helpviewer_keywords:
- user interfaces, support classes
- user interfaces, ATL classes
ms.assetid: 313dfc95-308a-4118-b919-5a3c3673b865
ms.openlocfilehash: 09b7aa26fc2f4597f741865ec94222bd65b85665
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57297028"
---
# <a name="ui-support-classes"></a>Classes de suporte de interface do usuário

As classes a seguir fornecem suporte geral da interface do usuário:

- [IDocHostUIHandlerDispatch](../atl/reference/idochostuihandlerdispatch-interface.md) uma interface para a análise de HTML da Microsoft e o mecanismo de renderização.

- [IOleObjectImpl](../atl/reference/ioleobjectimpl-class.md) fornece os principais métodos por meio do qual um contêiner se comunica com um controle. Gerencia a ativação e desativação dos controles no local.

- [IOleInPlaceObjectWindowlessImpl](../atl/reference/ioleinplaceobjectwindowlessimpl-class.md) gerencia a reativação dos controles no local. Permite que um controle sem janelas para receber mensagens, bem como para participar em operações de arrastar e soltar.

- [IOleInPlaceActiveObjectImpl](../atl/reference/ioleinplaceactiveobjectimpl-class.md) auxilia a comunicação entre um controle no local e seu contêiner.

- [IViewObjectExImpl](../atl/reference/iviewobjecteximpl-class.md) permite que um controle para exibir a mesmo diretamente e notificar o contêiner de alterações em sua exibição. Fornece suporte para desenho sem cintilação, controles não retangulares e transparentes e teste de clique.

## <a name="related-articles"></a>Artigos relacionados

[Tutorial da ATL](../atl/active-template-library-atl-tutorial.md)

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../atl/atl-class-overview.md)
