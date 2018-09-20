---
title: Gerenciando a exibição atual | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ca9738f9b6083ef88c2f72e1608121f849f8e909
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46425349"
---
# <a name="managing-the-current-view"></a>Gerenciando a exibição atual

Como parte da implementação padrão de janelas de quadro, uma janela de quadro controla de um modo de exibição ativo no momento. Se a janela do quadro contiver mais de uma exibição, como para o exemplo em uma janela separadora, o modo de exibição atual é a exibição mais recente em uso. O modo ativo é independente da janela ativa no Windows ou o foco de entrada atual.

Quando altera o modo ativo, o framework notifica a exibição atual chamando seus [OnActivateView](../mfc/reference/cview-class.md#onactivateview) função de membro. Você pode informar se o modo de exibição está sendo ativada ou desativada, examinando `OnActivateView`do *bActivate* parâmetro. Por padrão, `OnActivateView` define o foco para o modo de exibição atual na ativação. Você pode substituir `OnActivateView` para executar qualquer processamento especial quando a exibição seja desativada ou reativada. Por exemplo, você talvez queira fornecer dicas visuais especiais para distinguir a exibição ativa de outras exibições inativas.

Uma janela de quadro encaminha comandos ao seu modo de exibição atual (ativo), conforme descrito em [roteamento de comando](../mfc/command-routing.md), como parte de roteamento de comando padrão.

## <a name="see-also"></a>Consulte também

[Usando janelas com moldura](../mfc/using-frame-windows.md)

