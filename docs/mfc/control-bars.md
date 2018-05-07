---
title: Barras de controle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: bd25089594d31de21a3a315d997ee01111aff4fd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="control-bars"></a>Barras de controle
"Barra de controle" é o nome geral para barras de ferramentas, barras de status e barras da caixa de diálogo. Classes MFC `CToolBar`, `CStatusBar`, `CDialogBar`, `COleResizeBar`, e **CReBar** deriva da classe [CControlBar](../mfc/reference/ccontrolbar-class.md), que implementa a funcionalidade comum.  
  
 Barras de controle são janelas que exibem linhas de controles com a qual os usuários podem selecionar opções, executar comandos ou obter informações sobre o programa. Tipos de barras de controle incluem barras de ferramentas, barras de caixa de diálogo e barras de status.  
  
-   Barras de ferramentas na classe [CToolBar](../mfc/reference/ctoolbar-class.md)  
  
-   Barras de status, na classe [CStatusBar](../mfc/reference/cstatusbar-class.md)  
  
-   Barras da caixa de diálogo, na classe [CDialogBar](../mfc/reference/cdialogbar-class.md)  
  
-   Rebars na classe [CReBar](../mfc/reference/crebar-class.md)  
  
> [!IMPORTANT]
>  A partir da versão 4.0 do MFC, barras de ferramentas, barras de status e dicas de ferramenta são implementadas usando a funcionalidade do sistema implementada em comctl32.dll em vez da implementação anterior específica para MFC. Em MFC versão 6.0, **CReBar**, que também inclui a funcionalidade de comctl32.dll, foi adicionado.  
  
 Execute as breves apresentações para os tipos de barra de controle. Para obter mais informações, consulte os links abaixo.  
  
## <a name="control-bars"></a>Barras de controle  
 Barras de controle aumentam muito a usabilidade do programa, proporcionando rápida, ações de comando em uma única etapa. Classe `CControlBar` fornece a funcionalidade comum de todas as barras de ferramentas, barras de status e barras da caixa de diálogo. `CControlBar` fornece a funcionalidade para posicionar a barra de controle em sua janela do quadro pai. Como uma barra de controle normalmente é uma janela filho de uma janela do quadro pai, é um "irmão" para o modo de exibição do cliente ou o cliente MDI da janela do quadro. Um objeto de barra de controle usa informações sobre o retângulo do cliente da sua janela pai para se posicionar. Em seguida, ele altera o retângulo de janela de cliente restantes do pai para que a exibição de cliente ou a janela do cliente MDI preenche o restante da janela do cliente.  
  
> [!NOTE]
>  Se um botão na barra de controle não tem um **comando** ou **UPDATE_COMMAND_UI** manipulador, a estrutura automaticamente desativa o botão.  
  
## <a name="toolbars"></a>Barras de ferramentas  
 Uma barra de ferramentas é uma barra de controle que exibe uma linha de botões de bitmap que executam comandos. Pressionar um botão de barra de ferramentas é equivalente a escolher um item de menu; ele chama o mesmo manipulador mapeado para um item de menu se esse item de menu tem a mesma ID como o botão de barra de ferramentas. Os botões podem ser configurados para aparecem e se comportam como pushbuttons, botões de opção ou caixas de seleção. Uma barra de ferramentas geralmente é alinhada à parte superior de uma janela do quadro, mas uma barra de ferramentas MFC pode "encaixar" para qualquer lado da sua janela pai ou float em sua própria janela do quadro simplificado. Uma barra de ferramentas também pode "flutuar" e você pode alterar seu tamanho e arraste-o com o mouse. Uma barra de ferramentas também pode exibir dicas de ferramenta que o usuário move o mouse sobre os botões da barra de ferramentas. Uma dica de ferramenta é uma janela pop-up pequeno que descreva resumidamente o propósito do botão.  
  
> [!NOTE]
>  A partir da versão 4.0 do MFC, classe [CToolBar](../mfc/reference/ctoolbar-class.md) usa o controle comum de barra de ferramentas do Windows. Um `CToolBar` contém um [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md). Barras de ferramentas mais antigas ainda são suportadas, no entanto. Consulte o artigo [barras de ferramentas](../mfc/mfc-toolbar-implementation.md).  
  
## <a name="status-bars"></a>Barras de status  
 Uma barra de status é uma barra de controle que contém os painéis de saída de texto ou "indicadores". Os painéis de saída são usados como linhas de mensagem e indicadores de status. Exemplos de linha de mensagem incluem as linhas de mensagem de Ajuda do comando que explicam rapidamente o menu selecionado ou o comando da barra de ferramentas no painel mais à esquerda da barra de status padrão criado pelo Assistente de aplicativo MFC. Exemplos de indicador de status incluem o bloqueio de ROLAGEM, NUM LOCK e outras chaves. Barras de status geralmente são alinhadas com a parte inferior da janela do quadro. Consulte a classe [CStatusBar](../mfc/reference/cstatusbar-class.md) e classe [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md).  
  
## <a name="dialog-bars"></a>Barras da caixa de diálogo  
 Uma barra da caixa de diálogo é uma barra de controle, com base em um recurso de modelo de caixa de diálogo, com a funcionalidade de uma caixa de diálogo sem janela restrita. Barras da caixa de diálogo podem conter Windows, personalizados ou controles ActiveX. Como uma caixa de diálogo, o usuário pode usar tab entre os controles. Barras da caixa de diálogo podem ser alinhadas à parte superior, inferior, esquerda ou direita de uma janela do quadro e também pode ser flutuante em sua própria janela do quadro. Consulte a classe [CDialogBar](../mfc/reference/cdialogbar-class.md).  
  
## <a name="rebars"></a>Rebars  
 Um [rebar](../mfc/using-crebarctrl.md) é uma barra de controle que fornece informações de encaixe, layout, estado e persistência de controles rebar. Um objeto de rebar pode conter uma variedade de janelas filho, geralmente outros controles, incluindo caixas de edição, barras de ferramentas e caixas de listagem. Um objeto de rebar pode exibir janelas filho em um bitmap especificado. Ele pode ser feito manualmente ou automaticamente redimensionado clicando ou arrastando sua barra dupla. Consulte a classe [CReBar](../mfc/reference/crebar-class.md).  
  
## <a name="see-also"></a>Consulte também  
 [Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)
