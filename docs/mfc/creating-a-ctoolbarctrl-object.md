---
title: Criando um objeto CToolBarCtrl
ms.date: 11/04/2016
f1_keywords:
- CToolBarCtrl
helpviewer_keywords:
- toolbar controls [MFC], creating
- CToolBarCtrl class [MFC], creating toolbars
ms.assetid: a4f6bf0c-0195-4dbf-a09e-aee503e19dc3
ms.openlocfilehash: d0f41731e3a4db7b15d4f2a7ebaac94135d5350d
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57265100"
---
# <a name="creating-a-ctoolbarctrl-object"></a>Criando um objeto CToolBarCtrl

[CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) objetos contêm várias estruturas de dados interno — uma lista de bitmaps de imagem do botão, uma lista de cadeias de caracteres de rótulo de botão e uma lista de `TBBUTTON` estruturas — que associar uma imagem e/ou de cadeia de caracteres com a posição, estilo, estado, e ID de comando do botão. Cada um dos elementos dessas estruturas de dados é chamada por um índice baseado em zero. Antes de poder usar um `CToolBarCtrl` do objeto, você deve configurar essas estruturas de dados. Para obter uma lista das estruturas de dados, consulte [controles de barra de ferramentas](controls-mfc.md) no SDK do Windows. A lista de cadeias de caracteres só pode ser usada para rótulos de botões; Você não pode recuperar cadeias de caracteres na barra de ferramentas.

Para usar um `CToolBarCtrl` do objeto, você normalmente seguirá estas etapas:

### <a name="to-use-a-ctoolbarctrl-object"></a>Para usar um objeto CToolBarCtrl

1. Construir o [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) objeto.

1. Chame [Create](../mfc/reference/ctoolbarctrl-class.md#create) para criar o controle comum de barra de ferramentas do Windows e anexá-lo para o `CToolBarCtrl` objeto. Se você quiser imagens bitmap para botões, adicione os bitmaps de botão na barra de ferramentas chamando [AddBitmap](../mfc/reference/ctoolbarctrl-class.md#addbitmap). Se você desejar rótulos de cadeia de caracteres para botões, adicionar as cadeias de caracteres na barra de ferramentas, chamando [AddString](../mfc/reference/ctoolbarctrl-class.md#addstring) e/ou [AddStrings](../mfc/reference/ctoolbarctrl-class.md#addstrings). Depois de chamar `AddString` e/ou `AddStrings`, você deve chamar [AutoSize](../mfc/reference/ctoolbarctrl-class.md#autosize) para obter a cadeia de caracteres ou cadeias de caracteres apareça.

1. Adicionar estruturas de botão na barra de ferramentas, chamando [AddButtons](../mfc/reference/ctoolbarctrl-class.md#addbuttons).

1. Se você desejar dicas de ferramenta, manipular **TTN_NEEDTEXT** mensagens na janela do proprietário da barra de ferramentas, conforme descrito em [manipulando notificações da dica de ferramenta](../mfc/handling-tool-tip-notifications.md).

1. Se você quiser que o usuário seja capaz de personalizar a barra de ferramentas, lidar com mensagens de notificação de personalização na janela do proprietário conforme descrito em [manipulando notificações de personalização](../mfc/handling-customization-notifications.md).

## <a name="see-also"></a>Consulte também

[Usando CToolBarCtrl](../mfc/using-ctoolbarctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
