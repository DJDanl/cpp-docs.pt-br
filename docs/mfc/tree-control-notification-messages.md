---
title: Mensagens de notificação do controle de árvore
ms.date: 11/04/2016
helpviewer_keywords:
- notifications [MFC], tree controls
- messages [MFC], notification
- CTreeCtrl class [MFC], notifications
- notifications [MFC], CTreeCtrl
- tree controls [MFC], notification messages
ms.assetid: ac7013b4-91dd-4668-bd75-439ca0680ef9
ms.openlocfilehash: 90e2e112d7862dfed7d8af31cfb72ff45633a2c1
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57278387"
---
# <a name="tree-control-notification-messages"></a>Mensagens de notificação do controle de árvore

Um controle de árvore ([CTreeCtrl](../mfc/reference/ctreectrl-class.md)) envia as seguintes mensagens de notificação como mensagens WM_NOTIFY:

|Mensagem de notificação|Descrição|
|--------------------------|-----------------|
|TVN_BEGINDRAG|Sinaliza o início de uma operação de arrastar e soltar|
|TVN_BEGINLABELEDIT|Sinaliza o início da edição de rótulos no local|
|TVN_BEGINRDRAG|Sinaliza o início de uma operação de arrastar e soltar, usando o botão direito do mouse|
|TVN_DELETEITEM|Sinaliza a exclusão de um item específico|
|TVN_ENDLABELEDIT|Sinaliza o término da edição de rótulos|
|TVN_GETDISPINFO|Solicita que o controle de árvore requer para exibir um item de informações|
|TVN_ITEMEXPANDED|Sinais de que a lista de um item pai dos itens filhos foi expandida ou recolhida|
|TVN_ITEMEXPANDING|Sinais de que a lista de um item pai dos itens filhos está prestes a ser expandido ou recolhido|
|TVN_KEYDOWN|Sinaliza um evento de teclado|
|TVN_SELCHANGED|Sinais de que a seleção foi alterada de um item para outro|
|TVN_SELCHANGING|Sinais de que a seleção está prestes a ser alterada de um item para outro|
|TVN_SETDISPINFO|Notificação para atualizar as informações mantidas para um item|

## <a name="see-also"></a>Consulte também

[Usando CTreeCtrl](../mfc/using-ctreectrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
