---
title: 'Controles ATL: Classes de suporte geral | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.atl.controls
dev_langs:
- C++
helpviewer_keywords:
- controls [ATL]
- general support classes
ms.assetid: cf73f1d2-7542-48e3-b8c8-9d3abf29f85b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 18bf4bf2d2081402762026d6f26bd4650f9908fe
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43751440"
---
# <a name="controls-general-support-classes"></a>Controles: Classes de suporte geral

As classes a seguir fornecem suporte geral para controles ATL:

- [CComControl](../atl/reference/ccomcontrol-class.md) consiste em membros de dados e funções auxiliares que são essenciais para controles da ATL.

- [IOleControlImpl](../atl/reference/iolecontrolimpl-class.md) fornece os métodos necessários para controles.

- [IOleObjectImpl](../atl/reference/ioleobjectimpl-class.md) fornece os principais métodos por meio do qual um contêiner se comunica com um controle. Gerencia a ativação e desativação dos controles no local.

- [IQuickActivateImpl](../atl/reference/iquickactivateimpl-class.md) combina a inicialização em uma única chamada para ajudar a evitar atrasos durante o carregamento de controles de contêineres.

- [IPointerInactiveImpl](../atl/reference/ipointerinactiveimpl-class.md) fornece interação do mouse mínima para um controle caso contrário, inativa.

## <a name="sample-program"></a>Programa de exemplo

[ATLFire](../visual-cpp-samples.md)

## <a name="related-articles"></a>Artigos relacionados

[Tutorial da ATL](../atl/active-template-library-atl-tutorial.md)

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../atl/atl-class-overview.md)

