---
title: Usando dicas de ferramenta em um objeto CStatusBarCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- tool tips [MFC], using in status bars
- status bars [MFC], tool tips
- CStatusBarCtrl class [MFC], tool tips
ms.assetid: a77597a7-43ef-4b8f-87bc-a8ea1dc63dc3
ms.openlocfilehash: a607a5fb8c9470df42d12c771865b924891b2dac
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79442548"
---
# <a name="using-tooltips-in-a-cstatusbarctrl-object"></a>Usando dicas de ferramenta em um objeto CStatusBarCtrl

Para habilitar dicas de ferramenta para um controle de barra de status, crie o objeto `CStatusBarCtrl` com o estilo de SBT_TOOLTIPS.

> [!NOTE]
>  Se você estiver usando um objeto `CStatusBar` para implementar sua barra de status, use a função `CStatusBar::CreateEx`. Ele permite que você especifique estilos adicionais para o objeto de `CStatusBarCtrl` inserido.

Depois que o objeto de `CStatusBarCtrl` tiver sido criado com êxito, use [CStatusBarCtrl:: SetTipText](../mfc/reference/cstatusbarctrl-class.md#settiptext) e [CStatusBarCtrl:: GetTipText](../mfc/reference/cstatusbarctrl-class.md#gettiptext) para definir e recuperar o texto da dica para um painel específico.

Depois que a dica de ferramenta tiver sido definida, ela será exibida somente se a parte tiver um ícone e nenhum texto, ou se todo o texto não puder ser exibido dentro da parte. Não há suporte para dicas de ferramenta no modo simples.

## <a name="see-also"></a>Consulte também

[Usando CStatusBarCtrl](../mfc/using-cstatusbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
