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
ms.openlocfilehash: ceae20c89d9a6d3f4393f838b3594938107785f5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81353580"
---
# <a name="control-bars"></a>Barras de controle

"Barra de controle" é o nome geral para barras de ferramentas, barras de status e barras de diálogo. As classes `CToolBar` `CStatusBar`MFC `COleResizeBar`, `CReBar` , `CDialogBar`, e derivam da classe [CControlBar,](../mfc/reference/ccontrolbar-class.md)que implementa sua funcionalidade comum.

As barras de controle são janelas que exibem linhas de controles com as quais os usuários podem selecionar opções, executar comandos ou obter informações do programa. Os tipos de barras de controle incluem barras de ferramentas, barras de diálogo e barras de status.

- Barras de ferramentas, na classe [CToolBar](../mfc/reference/ctoolbar-class.md)

- Barras de status, na classe [CStatusBar](../mfc/reference/cstatusbar-class.md)

- Barras de diálogo, na classe [CDialogBar](../mfc/reference/cdialogbar-class.md)

- Vergalhão, na classe [CReBar](../mfc/reference/crebar-class.md)

> [!IMPORTANT]
> A partir da versão 4.0 do MFC, barras de ferramentas, barras de status e dicas de ferramentas são implementadas usando a funcionalidade do sistema implementada no *comctl32.dll* em vez da implementação anterior específica do MFC. Na versão 6.0 `CReBar`do MFC, que também envolve a funcionalidade comctl32.dll, foi adicionada.

Breves introduções aos tipos de barras de controle seguem. Para mais informações, consulte os links abaixo.

## <a name="control-bars"></a>Barras de controle

As barras de controle aumentam muito a usabilidade de um programa, fornecendo ações rápidas de comando de uma etapa. A `CControlBar` classe fornece a funcionalidade comum de todas as barras de ferramentas, barras de status e barras de diálogo. `CControlBar`fornece a funcionalidade para posicionar a barra de controle em sua janela de quadro pai. Como uma barra de controle geralmente é uma janela de filho de uma janela de quadro dos pais, ela é um "irmão" para a visão do cliente ou cliente MDI da janela do quadro. Um objeto de barra de controle usa informações sobre o retângulo do cliente da janela pai para se posicionar. Em seguida, altera o retângulo restante da janela cliente do pai para que a visualização do cliente ou a janela do cliente MDI preencha o resto da janela do cliente.

> [!NOTE]
> Se um botão na barra de controle não tiver um manipulador **COMMAND** ou **UPDATE_COMMAND_UI,** a estrutura desativará automaticamente o botão.

## <a name="toolbars"></a>Barras de Ferramentas

Uma barra de ferramentas é uma barra de controle que exibe uma linha de botões bitmapped que executam comandos. Pressionar um botão de barra de ferramentas equivale a escolher um item do menu; ele chama o mesmo manipulador mapeado para um item de menu se esse item do menu tiver o mesmo ID que o botão da barra de ferramentas. Os botões podem ser configurados para aparecer e se comportar como botões, botões de rádio ou caixas de seleção. Uma barra de ferramentas geralmente está alinhada ao topo de uma janela de quadro, mas uma barra de ferramentas MFC pode "doca" para qualquer lado de sua janela pai ou flutuar em sua própria janela de mini-quadro. Uma barra de ferramentas também pode "flutuar" e você pode mudar seu tamanho e arrastá-lo com um mouse. Uma barra de ferramentas também pode exibir dicas de ferramentas à medida que o usuário move o mouse sobre os botões da barra de ferramentas. Uma dica de ferramenta é uma pequena janela pop-up que descreve brevemente o propósito do botão.

> [!NOTE]
> A partir da versão 4.0 do MFC, a classe [CToolBar](../mfc/reference/ctoolbar-class.md) usa o controle comum da barra de ferramentas do Windows. A `CToolBar` contém um [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md). No entanto, as barras de ferramentas mais antigas ainda são suportadas. Consulte o artigo [Barras de Ferramentas](../mfc/mfc-toolbar-implementation.md).

## <a name="status-bars"></a>Barras de status

Uma barra de status é uma barra de controle que contém painéis de saída de texto ou "indicadores". Os painéis de saída são comumente usados como linhas de mensagem e como indicadores de status. Exemplos de linha de mensagens incluem as linhas de mensagem de ajuda de comando que explicam brevemente o menu selecionado ou o comando da barra de ferramentas no painel mais à esquerda da barra de status padrão criada pelo Assistente de Aplicativo do MFC. Os exemplos do indicador de status incluem o SCROLL LOCK, NUM LOCK e outras teclas. As barras de status geralmente estão alinhadas à parte inferior de uma janela de quadro. Consulte a classe [CStatusBar](../mfc/reference/cstatusbar-class.md) e a classe [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md).

## <a name="dialog-bars"></a>Barras da caixa de diálogo

Uma barra de diálogo é uma barra de controle, baseada em um recurso de modelo de diálogo, com a funcionalidade de uma caixa de diálogo modelada. As barras de diálogo podem conter controles Windows, personalizado ou ActiveX. Como em uma caixa de diálogo, o usuário pode fazer uma guia entre os controles. As barras de diálogo podem ser alinhadas ao lado superior, inferior, esquerdo ou direito de uma janela de quadro e também podem ser flutuadas em sua própria janela de quadro. Consulte a classe [CDialogBar](../mfc/reference/cdialogbar-class.md).

## <a name="rebars"></a>Rebars

Um [vergalhão](../mfc/using-crebarctrl.md) é uma barra de controle que fornece informações de acoplamento, layout, estado e persistência para controles de vergalhões. Um objeto de vergalhões pode conter uma variedade de janelas de crianças, geralmente outros controles, incluindo caixas de edição, barras de ferramentas e caixas de lista. Um objeto de vergalhões pode exibir suas janelas filho sobre um bitmap especificado. Ele pode ser redimensionado automaticamente ou manualmente clicando ou arrastando sua barra de aperto. Ver classe [CReBar](../mfc/reference/crebar-class.md).

## <a name="see-also"></a>Confira também

[Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)
