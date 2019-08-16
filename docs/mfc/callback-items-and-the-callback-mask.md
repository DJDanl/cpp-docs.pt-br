---
title: Itens e máscara de retorno de chamada
ms.date: 11/04/2016
helpviewer_keywords:
- callback items in CListCtrl class [MFC]
- CListCtrl class [MFC], callback item and callback mask
ms.assetid: 67c1f76f-6144-453e-9376-6712f89430ae
ms.openlocfilehash: 5c326d8498ea297936254a8650f666103ea3c772
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69509141"
---
# <a name="callback-items-and-the-callback-mask"></a>Itens e máscara de retorno de chamada

Para cada um de seus itens, um controle de exibição de lista normalmente armazena o texto do rótulo, o índice da lista de imagens dos ícones do item e um conjunto de sinalizadores de bits para o estado do item. Você pode definir itens individuais como itens de retorno de chamada, que são úteis se seu aplicativo já armazena algumas das informações de um item.

Você define um item como um item de retorno de chamada especificando os valores `pszText` apropriados `iImage` para os membros `LVITEM` e da estrutura (consulte [CListCtrl:: GetItem](../mfc/reference/clistctrl-class.md#getitem)). Se o aplicativo mantiver o texto do item ou do subitem, especifique o valor de LPSTR_TEXTCALLBACK `pszText` para o membro. Se o aplicativo acompanhar o ícone do item, especifique o valor de **I_IMAGECALLBACK** para o `iImage` membro.

Além de definir itens de retorno de chamada, você também pode modificar a máscara de retorno de chamada do controle. Essa máscara é um conjunto de sinalizadores de bits que especificam os Estados de item para os quais o aplicativo, em vez do controle, armazena os dados atuais. A máscara de retorno de chamada aplica-se a todos os itens do controle, diferentemente da designação do item de retorno de chamada, que se aplica a um item específico. A máscara de retorno de chamada é zero por padrão, o que significa que o controle controla todos os Estados de item. Para alterar esse comportamento padrão, inicialize a máscara para qualquer combinação dos seguintes valores:

- **LVIS_CUT** O item é marcado para uma operação de recortar e colar.

- **LVIS_DROPHILITED** O item é realçado como um destino do tipo "arrastar e soltar".

- **LVIS_FOCUSED** O item tem o foco.

- **LVIS_SELECTED** O item é selecionado.

- **LVIS_OVERLAYMASK** O aplicativo armazena o índice da lista de imagens da imagem de sobreposição atual para cada item.

- **LVIS_STATEIMAGEMASK** O aplicativo armazena o índice da lista de imagens da imagem de estado atual para cada item.

Para obter mais informações sobre como recuperar e definir essa máscara, consulte [CListCtrl:: GetCallbackMask](../mfc/reference/clistctrl-class.md#getcallbackmask) e [CListCtrl:: SetCallbackMask](../mfc/reference/clistctrl-class.md#setcallbackmask).

## <a name="see-also"></a>Consulte também

[Usando CListCtrl](../mfc/using-clistctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
