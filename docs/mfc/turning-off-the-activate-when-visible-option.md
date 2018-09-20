---
title: Desativando a opção Ativar quando visível | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC ActiveX controls [MFC], activate options
- Activate When Visible option [MFC]
ms.assetid: 8f7ddc5a-a7a6-4da8-bcb9-1b569f0ecb48
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7cb585496e6acf1c0ad94a43500e6d9a4830a2ac
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46381270"
---
# <a name="turning-off-the-activate-when-visible-option"></a>Desativando a opção Ativar Quando Visível

Um controle tem dois estados básicos: ativas e inativas. Tradicionalmente, esses estados foram diferenciados por se o controle tinha uma janela. Um controle ativo tinha uma janela; um controle inativo não faziam isso. Com a introdução da ativação sem janelas, essa distinção não é universal, mas ainda se aplica a muitos controles.

Em comparação com o restante da inicialização normalmente executada por um controle ActiveX, a criação de uma janela é uma operação muito cara. O ideal é que um controle seria adiam a criação de sua janela até que absolutamente necessário.

Muitos controles não precisa estar ativo o tempo todo, que eles são visíveis em um contêiner. Geralmente, um controle pode permanecer no estado inativo até que o usuário executa uma operação que exige que ele se torne ativo (por exemplo, clicando com o mouse ou pressionando a tecla TAB). Para fazer com que um controle permanecerá ativo até que o contêiner precisa ativá-lo, remova os **OLEMISC_ACTIVATEWHENVISIBLE** sinalizador de sinalizadores de diversos do controle:

[!code-cpp[NVC_MFC_AxOpt#9](../mfc/codesnippet/cpp/turning-off-the-activate-when-visible-option_1.cpp)]

O **OLEMISC_ACTIVATEWHENVISIBLE** sinalizador for omitido automaticamente se você desativar o **Ativar quando visível** opção o [configurações de controle](../mfc/reference/control-settings-mfc-activex-control-wizard.md) página do ActiveX MFC Assistente de controle quando você criar seu controle.

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC: otimização](../mfc/mfc-activex-controls-optimization.md)

