---
title: Barras de controle
ms.date: 11/04/2016
helpviewer_keywords:
- command bars [MFC], types of
- toolbars [MFC], control bars
- control bars [MFC]
- MFC, control bars
- control bars [MFC], types of
- CDialogBar class [MFC], control bars
- status bars [MFC], control bars
- CControlBar class [MFC], MFC control bars
- dialog bars [MFC], control bars
- CToolBar class [MFC], control bars
- CStatusBar class [MFC], control bars
ms.assetid: 31831910-3d23-4d70-9e71-03cc02f01ec4
ms.openlocfilehash: a2d3683b744493bb5566456b9e1358c1ddc418d4
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615970"
---
# <a name="control-bars"></a>Barras de controle

"Barra de controle" é o nome geral para barras de ferramentas, barras de status e barras de diálogo. Classes do MFC,,, `CToolBar` `CStatusBar` `CDialogBar` `COleResizeBar` e `CReBar` derivam da classe [CControlBar](reference/ccontrolbar-class.md), que implementa sua funcionalidade comum.

As barras de controle são janelas que exibem linhas de controles com os quais os usuários podem selecionar opções, executar comandos ou obter informações do programa. Os tipos de barras de controle incluem barras de ferramentas, barras de diálogo e barras de status.

- Barras de ferramentas, na classe [CToolBar](reference/ctoolbar-class.md)

- Barras de status, na classe [CStatusBar](reference/cstatusbar-class.md)

- Barras de diálogo, na classe [CDialogBar](reference/cdialogbar-class.md)

- Rebarras, na classe [CReBar](reference/crebar-class.md)

> [!IMPORTANT]
> A partir da versão 4,0 do MFC, barras de ferramentas, barras de status e dicas de ferramenta são implementadas usando a funcionalidade do sistema implementada no *Comctl32. dll* em vez da implementação anterior específica do MFC. No MFC versão 6,0, `CReBar` , que também encapsula a funcionalidade Comctl32. dll, foi adicionado.

Seguem as breves introduções para os tipos de barra de controle. Para obter mais informações, consulte os links abaixo.

## <a name="control-bars"></a>Barras de controle

As barras de controle aprimoram muito a usabilidade de um programa fornecendo ações rápidas de comando de uma etapa. `CControlBar`A classe fornece a funcionalidade comum de todas as barras de ferramentas, barras de status e barras de diálogo. `CControlBar`fornece a funcionalidade para posicionar a barra de controle em sua janela de quadro pai. Como uma barra de controle geralmente é uma janela filho de uma janela de quadro pai, ela é um "irmão" para a exibição de cliente ou cliente MDI da janela do quadro. Um objeto de barra de controle usa informações sobre o retângulo do cliente da janela pai para posicioná-lo em si. Em seguida, ele altera o retângulo da janela do cliente restante do pai para que a janela do cliente ou a exibição de cliente do MDI preencha o restante da janela do cliente.

> [!NOTE]
> Se um botão na barra de controle não tiver um **comando** ou um manipulador de **UPDATE_COMMAND_UI** , a estrutura desabilitará automaticamente o botão.

## <a name="toolbars"></a>Barras de Ferramentas

Uma barra de ferramentas é uma barra de controle que exibe uma linha de botões de bitmap que executam comandos. Pressionar um botão da barra de ferramentas é equivalente a escolher um item de menu; Ele chama o mesmo manipulador mapeado para um item de menu se esse item de menu tiver a mesma ID que o botão da barra de ferramentas. Os botões podem ser configurados para aparecerem e se comportarem como botões de opção ou caixas de seleção. Uma barra de ferramentas geralmente está alinhada à parte superior de uma janela do quadro, mas uma barra de ferramentas do MFC pode "encaixar" em qualquer lado da janela pai ou flutuar em sua própria janela de mini-quadro. Uma barra de ferramentas também pode "flutuar" e você pode alterar seu tamanho e arrastá-la com um mouse. Uma barra de ferramentas também pode exibir dicas de ferramenta à medida que o usuário move o mouse sobre os botões da barra de ferramentas. Uma dica de ferramenta é uma pequena janela pop-up que descreve brevemente a finalidade do botão.

> [!NOTE]
> A partir da versão 4,0 do MFC, a classe [CToolBar](reference/ctoolbar-class.md) usa o controle comum da barra de ferramentas do Windows. Um `CToolBar` contém um [CToolBarCtrl](reference/ctoolbarctrl-class.md). No entanto, as barras de ferramentas mais antigas ainda têm suporte. Consulte as [barras de ferramentas](mfc-toolbar-implementation.md)do artigo.

## <a name="status-bars"></a>Barras de status

Uma barra de status é uma barra de controle que contém painéis de saída de texto ou "indicadores". Os painéis de saída são comumente usados como linhas de mensagem e como indicadores de status. Os exemplos de linha de mensagem incluem as linhas de mensagem de ajuda do comando que explicam brevemente o menu selecionado ou o comando da barra de ferramentas no painel mais à esquerda da barra de status padrão criada pelo assistente de aplicativo do MFC. Exemplos de indicadores de status incluem o SCROLL LOCK, NUM LOCK e outras chaves. Barras de status geralmente são alinhadas à parte inferior de uma janela do quadro. Consulte Class [CStatusBar](reference/cstatusbar-class.md) e Class [CStatusBarCtrl](reference/cstatusbarctrl-class.md).

## <a name="dialog-bars"></a>Barras da caixa de diálogo

Uma barra de diálogo é uma barra de controle, com base em um recurso de modelo de caixa de diálogo, com a funcionalidade de uma caixa de diálogo sem janela restrita. As barras de diálogo podem conter controles Windows, Custom ou ActiveX. Como em uma caixa de diálogo, o usuário pode se tabular entre os controles. As barras de diálogo podem ser alinhadas ao lado superior, inferior, esquerdo ou direito de uma janela do quadro e também podem ser flutuadas em sua própria janela do quadro. Consulte classe [CDialogBar](reference/cdialogbar-class.md).

## <a name="rebars"></a>Rebarras

Um [rebar](using-crebarctrl.md) é uma barra de controle que fornece informações de encaixe, layout, estado e persistência para controles Rebar. Um objeto rebar pode conter uma variedade de janelas filhas, geralmente outros controles, incluindo caixas de edição, barras de ferramentas e caixas de listagem. Um objeto rebar pode exibir suas janelas filhas em um bitmap especificado. Ele pode ser redimensionado automaticamente ou manualmente clicando ou arrastando sua barra de garra. Consulte classe [CReBar](reference/crebar-class.md).

## <a name="see-also"></a>Consulte também

[Elementos da interface do usuário](user-interface-elements-mfc.md)
