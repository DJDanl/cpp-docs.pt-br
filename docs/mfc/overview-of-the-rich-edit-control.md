---
title: Visão geral do controle de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- rich edit controls [MFC]
ms.assetid: ad589b9f-a3fd-4820-bf1f-6b1965997e68
ms.openlocfilehash: 9ef696bc348dfb18b797b487224b97261020e11c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366867"
---
# <a name="overview-of-the-rich-edit-control"></a>Visão geral do controle de edição avançada

> [!IMPORTANT]
> Se você estiver usando um rico controle de edição em uma caixa de diálogo (independentemente de seu aplicativo ser Baseado em SDI, MDI ou diálogo), você deve chamar [AfxInitRichEdit](../mfc/reference/application-information-and-management.md#afxinitrichedit) uma vez antes que a caixa de diálogo seja exibida. Um lugar típico para chamar essa função `InitInstance` está na função de membro do seu programa. Você não precisa chamá-lo para cada vez que você exibir a caixa de diálogo, apenas na primeira vez. Você não tem `AfxInitRichEdit` que ligar se `CRichEditView`estiver trabalhando com.

Os controles de edição ricos[(CRichEditCtrl)](../mfc/reference/cricheditctrl-class.md)fornecem uma interface de programação para formatação de texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para tornar as operações de formatação disponíveis para o usuário. Ou seja, o rico controle de edição suporta a alteração dos atributos de caractere ou parágrafo do texto selecionado. Alguns exemplos de atributos de caracteres são negrito, itálico, família de fontes e tamanho do ponto. Exemplos de atributos de parágrafo incluem alinhamento, margens e guias. No entanto, cabe a você fornecer a interface do usuário, seja botões de barra de ferramentas, itens de menu ou uma caixa de diálogo de caracteres de formato. Há também funções para consultar o rico controle de edição para os atributos da seleção atual. Use essas funções para exibir as configurações atuais para os atributos, por exemplo, definindo uma marca de seleção na ui de comando se a seleção tiver o atributo de formatação de caracteres em negrito.

Para obter mais informações sobre a formatação de caracteres e parágrafos, consulte [Formatação de caracteres](../mfc/character-formatting-in-rich-edit-controls.md) e [formatação de parágrafos](../mfc/paragraph-formatting-in-rich-edit-controls.md) mais tarde neste tópico.

Os controles de edição ricos suportam quase todas as operações e mensagens de notificação usadas com controles de edição multilinha. Assim, aplicativos que já usam controles de edição podem ser facilmente alterados para usar controles de edição ricos. Mensagens e notificações adicionais permitem que os aplicativos acessem a funcionalidade exclusiva para controles de edição ricos. Para obter informações sobre controles de edição, consulte [CEdit](../mfc/reference/cedit-class.md).

Para obter mais informações sobre notificações, consulte [Notificações de um Rich Edit Control](../mfc/notifications-from-a-rich-edit-control.md) mais tarde neste tópico.

## <a name="see-also"></a>Confira também

[Usando CRichEditCtrl](../mfc/using-cricheditctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)
