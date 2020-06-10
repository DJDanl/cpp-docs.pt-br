---
title: Gerenciando a exibição atual
ms.date: 11/04/2016
helpviewer_keywords:
- views [MFC], and OnActivateView method [MFC]
- views [MFC], deactivating
- views [MFC], activating
- frame windows [MFC], current view
- OnActivateView method [MFC]
- views [MFC], current
- deactivating views [MFC]
- current view in frame window [MFC]
ms.assetid: 0a1cc22d-d646-4536-9ad2-3cb6d7092e4a
ms.openlocfilehash: d2ce9d77234260ebcb1946dd381264fb6654a91c
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621318"
---
# <a name="managing-the-current-view"></a>Gerenciando a exibição atual

Como parte da implementação padrão das janelas de quadros, uma janela de quadro controla uma exibição atualmente ativa. Se a janela do quadro contiver mais de uma exibição, como por exemplo em uma janela divisora, a exibição atual será a exibição mais recente em uso. O modo de exibição ativo é independente da janela ativa no Windows ou do foco de entrada atual.

Quando o modo de exibição ativo é alterado, o Framework notifica a exibição atual chamando sua função de membro [OnActivateView](reference/cview-class.md#onactivateview) . Você pode saber se a exibição está sendo ativada ou desativada examinando o `OnActivateView` parâmetro *bActivate* . Por padrão, `OnActivateView` o define o foco para a exibição atual na ativação. Você pode substituir `OnActivateView` para executar qualquer processamento especial quando a exibição for desativada ou reativada. Por exemplo, talvez você queira fornecer indicações visuais especiais para distinguir o modo de exibição ativo de outras exibições inativas.

Uma janela de quadro encaminha comandos para sua exibição atual (ativa), conforme descrito no [Roteamento de comando](command-routing.md), como parte do roteamento de comandos padrão.

## <a name="see-also"></a>Consulte também

[Usando janelas de quadros](using-frame-windows.md)
