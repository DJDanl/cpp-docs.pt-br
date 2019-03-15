---
title: 'Controles ATL: Classes de suporte geral'
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- controls [ATL]
- general support classes
ms.assetid: cf73f1d2-7542-48e3-b8c8-9d3abf29f85b
ms.openlocfilehash: c3d6f7588e333a27a8bc766d982660aaa4d984c9
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57818603"
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
