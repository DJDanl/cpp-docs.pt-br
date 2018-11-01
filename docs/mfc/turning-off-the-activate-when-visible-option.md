---
title: Desativando a opção Ativar Quando Visível
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], activate options
- Activate When Visible option [MFC]
ms.assetid: 8f7ddc5a-a7a6-4da8-bcb9-1b569f0ecb48
ms.openlocfilehash: 42dbec7a55085235e43fa14ab6406bfb3526afdb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50464825"
---
# <a name="turning-off-the-activate-when-visible-option"></a>Desativando a opção Ativar Quando Visível

Um controle tem dois estados básicos: ativas e inativas. Tradicionalmente, esses estados foram diferenciados por se o controle tinha uma janela. Um controle ativo tinha uma janela; um controle inativo não faziam isso. Com a introdução da ativação sem janelas, essa distinção não é universal, mas ainda se aplica a muitos controles.

Em comparação com o restante da inicialização normalmente executada por um controle ActiveX, a criação de uma janela é uma operação muito cara. O ideal é que um controle seria adiam a criação de sua janela até que absolutamente necessário.

Muitos controles não precisa estar ativo o tempo todo, que eles são visíveis em um contêiner. Geralmente, um controle pode permanecer no estado inativo até que o usuário executa uma operação que exige que ele se torne ativo (por exemplo, clicando com o mouse ou pressionando a tecla TAB). Para fazer com que um controle permanecerá ativo até que o contêiner precisa ativá-lo, remova os **OLEMISC_ACTIVATEWHENVISIBLE** sinalizador de sinalizadores de diversos do controle:

[!code-cpp[NVC_MFC_AxOpt#9](../mfc/codesnippet/cpp/turning-off-the-activate-when-visible-option_1.cpp)]

O **OLEMISC_ACTIVATEWHENVISIBLE** sinalizador for omitido automaticamente se você desativar o **Ativar quando visível** opção o [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página do ActiveX MFC Assistente de controle quando você criar seu controle.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC: otimização](../mfc/mfc-activex-controls-optimization.md)

