---
title: Criando um objeto CToolBarCtrl
ms.date: 11/04/2016
helpviewer_keywords:
- toolbar controls [MFC], creating
- CToolBarCtrl class [MFC], creating toolbars
ms.assetid: a4f6bf0c-0195-4dbf-a09e-aee503e19dc3
ms.openlocfilehash: 2627f9aaceeab7760e15b23435233e124c5ea6f0
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84618997"
---
# <a name="creating-a-ctoolbarctrl-object"></a>Criando um objeto CToolBarCtrl

Os objetos [CToolBarCtrl](reference/ctoolbarctrl-class.md) contêm várias estruturas de dados internas — uma lista de bitmaps de imagem de botão, uma lista de cadeias de caracteres de rótulo de botão e uma lista de `TBBUTTON` estruturas — que associam uma imagem e/ou cadeia de caracteres com a posição, o estilo, o estado e a ID de comando do botão. Cada um dos elementos dessas estruturas de dados é referenciado por um índice baseado em zero. Para poder usar um `CToolBarCtrl` objeto, você deve configurar essas estruturas de dados. Para obter uma lista das estruturas de dados, consulte [controles da barra de ferramentas](controls-mfc.md) na SDK do Windows. A lista de cadeias de caracteres só pode ser usada para rótulos de botão; Não é possível recuperar cadeias de caracteres da barra de ferramentas.

Para usar um `CToolBarCtrl` objeto, você normalmente seguirá estas etapas:

### <a name="to-use-a-ctoolbarctrl-object"></a>Para usar um objeto CToolBarCtrl

1. Construa o objeto [CToolBarCtrl](reference/ctoolbarctrl-class.md) .

1. Chame [Create](reference/ctoolbarctrl-class.md#create) para criar o controle comum da barra de ferramentas do Windows e anexe-o ao `CToolBarCtrl` objeto. Se você quiser imagens de bitmap para botões, adicione os bitmaps de botão à barra de ferramentas chamando [AddBitmap](reference/ctoolbarctrl-class.md#addbitmap). Se você quiser rótulos de cadeia de caracteres para botões, adicione as cadeias para a barra de ferramentas chamando [AddString](reference/ctoolbarctrl-class.md#addstring) e/ou [AddString](reference/ctoolbarctrl-class.md#addstrings). Depois de chamar `AddString` and/or `AddStrings` , você deve chamar [AutoSize](reference/ctoolbarctrl-class.md#autosize) para que a cadeia de caracteres ou cadeias sejam exibidas.

1. Adicione estruturas de botão à barra de ferramentas chamando [AddButtons](reference/ctoolbarctrl-class.md#addbuttons).

1. Se você quiser dicas de ferramenta, manipule **TTN_NEEDTEXT** mensagens na janela do proprietário da barra de ferramentas, conforme descrito em [manipulando notificações de dica de ferramenta](handling-tool-tip-notifications.md).

1. Se você quiser que o usuário seja capaz de personalizar a barra de ferramentas, manipule mensagens de notificação de personalização na janela do proprietário, conforme descrito em [lidando com notificações de personalização](handling-customization-notifications.md).

## <a name="see-also"></a>Consulte também

[Usando CToolBarCtrl](using-ctoolbarctrl.md)<br/>
[Controles](controls-mfc.md)
