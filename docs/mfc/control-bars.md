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
ms.openlocfilehash: 8583b0ceba041ba9b99cb78e523d78bba71414a5
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46439621"
---
# <a name="control-bars"></a>Barras de controle

"Barra de controle" é o nome geral para barras de ferramentas, barras de status e as barras de caixa de diálogo. Classes MFC `CToolBar`, `CStatusBar`, `CDialogBar`, `COleResizeBar`, e `CReBar` deriva da classe [CControlBar](../mfc/reference/ccontrolbar-class.md), que implementa a funcionalidade comum.

Barras de controle são janelas que exibem linhas de controles com os quais os usuários podem selecionar opções, executar comandos ou obter informações sobre o programa. Tipos de barras de controle incluem barras de ferramentas, barras de caixa de diálogo e barras de status.

- Barras de ferramentas, na classe [CToolBar](../mfc/reference/ctoolbar-class.md)

- Barras de status, na classe [CStatusBar](../mfc/reference/cstatusbar-class.md)

- Barras da caixa de diálogo, na classe [CDialogBar](../mfc/reference/cdialogbar-class.md)

- Rebars na classe [CReBar](../mfc/reference/crebar-class.md)

> [!IMPORTANT]
>  A partir da versão 4.0 do MFC, barras de ferramentas, barras de status e ferramenta de dicas são implementadas usando a funcionalidade do sistema implementada de *comctl32.dll* em vez da implementação anterior específica ao MFC. Na versão 6.0, do MFC `CReBar`, que também encapsula a funcionalidade do comctl32.dll, foi adicionado.

Siga breves introduções aos tipos de barra de controle. Para obter mais informações, consulte os links a seguir.

## <a name="control-bars"></a>Barras de controle

Barras de controle aumentam muito a usabilidade de um programa, fornecendo rápido, ações de comando em uma etapa. Classe `CControlBar` fornece a funcionalidade comum de todas as barras de ferramentas, barras de status e as barras de caixa de diálogo. `CControlBar` fornece a funcionalidade para posicionar a barra de controle em sua janela de quadro do pai. Como uma barra de controle geralmente é uma janela filho de uma janela do quadro pai, ele é um "irmão" para o modo de exibição do cliente ou o cliente do MDI da janela do quadro. Um objeto de barra de controle usa informações sobre o retângulo do cliente da sua janela pai para posicionar em si. Em seguida, ela altera do retângulo do pai restantes janela do cliente para que a exibição de cliente ou a janela do cliente MDI preenche o restante da janela do cliente.

> [!NOTE]
>  Se um botão na barra de controle não tem um **comando** ou **UPDATE_COMMAND_UI** manipulador, o framework desabilita automaticamente o botão.

## <a name="toolbars"></a>Barras de ferramentas

Uma barra de ferramentas é uma barra de controle que exibe uma linha de botões de bitmap que executam comandos. Pressionar um botão de barra de ferramentas é equivalente a escolher um item de menu; ele chama o mesmo manipulador mapeado para um item de menu, se esse item de menu tem a mesma ID como o botão de barra de ferramentas. Os botões podem ser configurados para parecerem e se comportam como comportarem, botões de opção ou caixas de seleção. Geralmente, uma barra de ferramentas é alinhada à parte superior de uma janela de quadro, mas uma barra de ferramentas MFC pode "encaixe" para qualquer lado da sua janela pai ou float em sua própria janela com minimoldura. Uma barra de ferramentas também pode "flutuar" e você pode alterar seu tamanho e arraste-o com o mouse. Uma barra de ferramentas também pode exibir dicas de ferramenta quando o usuário move o mouse sobre os botões da barra de ferramentas. Uma dica de ferramenta é uma janela pop-up pequeno que descreve resumidamente a finalidade do botão.

> [!NOTE]
>  A partir do MFC versão 4.0, a classe [CToolBar](../mfc/reference/ctoolbar-class.md) usa o controle comum de barra de ferramentas do Windows. Um `CToolBar` contém uma [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md). Barras de ferramentas mais antigas ainda são suportadas, no entanto. Consulte o artigo [barras de ferramentas](../mfc/mfc-toolbar-implementation.md).

## <a name="status-bars"></a>Barras de status

Uma barra de status é uma barra de controle que contém os painéis de saída de texto, ou "indicadores". Os painéis de saída normalmente são usados como linhas de mensagem e como os indicadores de status. Exemplos de linha de mensagem incluem as linhas de mensagem de ajuda de comando que explicam resumidamente o menu selecionado ou o comando de barra de ferramentas no painel mais à esquerda da barra de status padrão criado pelo Assistente de aplicativo do MFC. Exemplos de indicador de status incluem SCROLL LOCK, NUM LOCK e outras chaves. Barras de status geralmente são alinhadas à parte inferior de uma janela do quadro. Consulte a classe [CStatusBar](../mfc/reference/cstatusbar-class.md) e a classe [CStatusBarCtrl](../mfc/reference/cstatusbarctrl-class.md).

## <a name="dialog-bars"></a>Barras da caixa de diálogo

Uma barra de diálogo é uma barra de controle, com base em um recurso de modelo de caixa de diálogo, com a funcionalidade de uma caixa de diálogo sem janela restrita. Barras da caixa de diálogo podem conter o Windows, personalizados ou controles ActiveX. Como em uma caixa de diálogo, o usuário pode pressionar tab entre os controles. Barras da caixa de diálogo podem ser alinhadas à parte superior, inferior, esquerda ou direita de uma janela de quadro e também pode ser flutuante em sua própria janela de quadro. Consulte a classe [CDialogBar](../mfc/reference/cdialogbar-class.md).

## <a name="rebars"></a>Rebars

Um [rebar](../mfc/using-crebarctrl.md) é uma barra de controle que fornece informações de encaixe, layout, estado e persistência de controles rebar. Um objeto de rebar pode conter uma variedade de janelas filho, geralmente outros controles, incluindo caixas de listagem, barras de ferramentas e caixas de edição. Um objeto de rebar pode exibir suas janelas filho ao longo de um bitmap especificado. Ele pode ser feito manualmente ou automaticamente redimensionado clicando ou arrastando sua barra de garra. Consulte a classe [CReBar](../mfc/reference/crebar-class.md).

## <a name="see-also"></a>Consulte também

[Elementos da Interface do usuário](../mfc/user-interface-elements-mfc.md)
