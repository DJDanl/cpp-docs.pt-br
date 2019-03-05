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
ms.openlocfilehash: a926a9e31f7c43ab625220a4d759f6d536c2a77f
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57326225"
---
# <a name="managing-the-current-view"></a>Gerenciando a exibição atual

Como parte da implementação padrão de janelas de quadro, uma janela de quadro controla de um modo de exibição ativo no momento. Se a janela do quadro contiver mais de uma exibição, como para o exemplo em uma janela separadora, o modo de exibição atual é a exibição mais recente em uso. O modo ativo é independente da janela ativa no Windows ou o foco de entrada atual.

Quando altera o modo ativo, o framework notifica a exibição atual chamando seus [OnActivateView](../mfc/reference/cview-class.md#onactivateview) função de membro. Você pode informar se o modo de exibição está sendo ativada ou desativada, examinando `OnActivateView`do *bActivate* parâmetro. Por padrão, `OnActivateView` define o foco para o modo de exibição atual na ativação. Você pode substituir `OnActivateView` para executar qualquer processamento especial quando a exibição seja desativada ou reativada. Por exemplo, você talvez queira fornecer dicas visuais especiais para distinguir a exibição ativa de outras exibições inativas.

Uma janela de quadro encaminha comandos ao seu modo de exibição atual (ativo), conforme descrito em [roteamento de comando](../mfc/command-routing.md), como parte de roteamento de comando padrão.

## <a name="see-also"></a>Consulte também

[Usando janelas com moldura](../mfc/using-frame-windows.md)
