---
title: Visão geral do controle de edição avançada
ms.date: 11/04/2016
helpviewer_keywords:
- rich edit controls [MFC]
ms.assetid: ad589b9f-a3fd-4820-bf1f-6b1965997e68
ms.openlocfilehash: b99a5c6faaae4679b6aef67f240febbfb0f596e8
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84617717"
---
# <a name="overview-of-the-rich-edit-control"></a>Visão geral do controle de edição avançada

> [!IMPORTANT]
> Se você estiver usando um controle de edição rico em uma caixa de diálogo (independentemente de seu aplicativo ser SDI, MDI ou baseado em caixa de diálogo), você deve chamar [AfxInitRichEdit](reference/application-information-and-management.md#afxinitrichedit) uma vez antes que a caixa de diálogo seja exibida. Um lugar típico para chamar essa função é na função de membro do programa `InitInstance` . Você não precisa chamá-lo para cada vez que exibir a caixa de diálogo, somente na primeira vez. Você não precisará chamar `AfxInitRichEdit` se estiver trabalhando com o `CRichEditView` .

[CRichEditCtrl](reference/cricheditctrl-class.md)(Rich Edit Controls) fornecem uma interface de programação para formatar texto. No entanto, um aplicativo deve implementar quaisquer componentes de interface do usuário necessários para disponibilizar as operações de formatação para o usuário. Ou seja, o controle de edição rico dá suporte à alteração dos atributos de caractere ou parágrafo do texto selecionado. Alguns exemplos de atributos de caractere são negrito, itálico, família de fontes e tamanho do ponto. Exemplos de atributos de parágrafo incluem alinhamento, margens e paradas de tabulação. No entanto, cabe a você fornecer a interface do usuário, seja eles botões da barra de ferramentas, itens de menu ou uma caixa de diálogo Formatar caractere. Também há funções para consultar o controle de edição rico para os atributos da seleção atual. Use essas funções para exibir as configurações atuais dos atributos, por exemplo, definindo uma marca de seleção na interface do usuário do comando se a seleção tiver o atributo de formatação de caractere em negrito.

Para obter mais informações sobre formatação de caracteres e parágrafos, consulte [formatação de caracteres](character-formatting-in-rich-edit-controls.md) e [formatação de parágrafo](paragraph-formatting-in-rich-edit-controls.md) mais adiante neste tópico.

Os controles de edição avançados dão suporte a quase todas as operações e mensagens de notificação usadas com controles de edição de várias linhas. Assim, os aplicativos que já usam controles de edição podem ser facilmente alterados para usar controles de edição avançados. Mensagens e notificações adicionais permitem que os aplicativos acessem a funcionalidade exclusiva para controles de edição avançados. Para obter informações sobre controles de edição, consulte [CEdit](reference/cedit-class.md).

Para obter mais informações sobre notificações, consulte [notificações de um controle rich edit](notifications-from-a-rich-edit-control.md) mais adiante neste tópico.

## <a name="see-also"></a>Consulte também

[Usando CRichEditCtrl](using-cricheditctrl.md)<br/>
[Controles](controls-mfc.md)
