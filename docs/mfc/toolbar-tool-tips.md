---
title: Dicas de ferramenta da barra de ferramentas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- tool tips [MFC], activating
- CBRS_TOOLTIPS constant [MFC]
- tool tips [MFC], adding text
- updates [MFC]
- CBRS_FLYBY constant [MFC]
- tool tips [MFC]
- updating status bar messages
- updates, status bar messages
- status bars [MFC], tool tips
- flyby status bar updates
ms.assetid: d1696305-b604-4fad-9f09-638878371412
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 248c975c51a2f44f6c9b17094d6b05082a9016a8
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="toolbar-tool-tips"></a>Dicas de ferramenta da barra de ferramentas
Dicas de ferramenta são as janelas de pop-up pequeno que apresentam breves descrições de finalidade de um botão barra de ferramentas quando você posiciona o mouse sobre um botão para um período de tempo. Quando você cria um aplicativo com o Assistente de aplicativo que tem uma barra de ferramentas, suporte de dica de ferramenta é fornecido para você. Este artigo explica as duas o suporte de dica ferramenta criado pelo Assistente do aplicativo e como adicionar suporte de dica de ferramenta para seu aplicativo.  
  
 Este artigo aborda:  
  
-   [Ativar dicas de ferramenta](#_core_activating_tool_tips)  
  
-   [Atualizações da barra de status flyby](#_core_fly_by_status_bar_updates)  
  
##  <a name="_core_activating_tool_tips"></a>Ativar dicas de ferramenta  
 Para ativar dicas de ferramenta em seu aplicativo, você deve fazer duas coisas:  
  
-   Adicionar o `CBRS_TOOLTIPS` estilo nos outros estilos (como **WS_CHILD**, **WS_VISIBLE**e outros **CBRS_** estilos) passado como o `dwStyle` parâmetro para o [ CToolBar::Create](../mfc/reference/ctoolbar-class.md#create) função ou no [SetBarStyle](../mfc/reference/ccontrolbar-class.md#setbarstyle).  
  
-   Conforme descrito no procedimento a seguir, acrescente o texto da dica de ferramentas, separado por um caractere de nova linha ("\n"), para o recurso de cadeia de caracteres que contém o prompt de linha de comando para o comando da barra de ferramentas. O recurso de cadeia de caracteres compartilha a ID do botão da barra de ferramentas.  
  
#### <a name="to-add-the-tool-tip-text"></a>Para adicionar o texto da dica de ferramenta  
  
1.  Enquanto você estiver editando a barra de ferramentas do editor de barra de ferramentas, abra o **propriedades de botão da barra de ferramentas** janela para um determinado botão.  
  
2.  No **Prompt** , especifique o texto a ser exibido na dica de ferramenta para esse botão.  
  
> [!NOTE]
>  Configurar o texto como uma propriedade do botão no editor de barra de ferramentas substitui o procedimento anterior, era necessário abrir e editar o recurso de cadeia de caracteres.  
  
 Se uma barra de controle com dicas de ferramenta habilitado tem controles filho em, a barra de controle exibirá uma dica de ferramenta para cada controle filho na barra de controle, desde que ele atenda aos seguintes critérios:  
  
-   A ID do controle é não - 1.  
  
-   A entrada da tabela de cadeia de caracteres com a mesma ID que o controle filho no arquivo de recurso tem uma cadeia de caracteres de dica de ferramenta.  
  
##  <a name="_core_fly_by_status_bar_updates"></a>Atualizações da barra de Status flyby  
 Um recurso relacionado a dicas de ferramenta é a barra de atualização de status de "flyby". Por padrão, a mensagem na barra de status descreve apenas um botão de barra de ferramentas específica quando o botão estiver ativado. Incluindo `CBRS_FLYBY` na sua lista de estilos passado para `CToolBar::Create`, você pode ter essas mensagens atualizadas quando o cursor do mouse passa sobre a barra de ferramentas sem realmente ativar o botão.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Implementação de barra de ferramentas MFC (informações de visão geral das barras de ferramentas)](../mfc/mfc-toolbar-implementation.md)  
  
-   [Encaixando e flutuando barras de ferramentas](../mfc/docking-and-floating-toolbars.md)  
  
-   O [CToolBar](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) classes  
  
-   [Trabalhando com o controle de barra de ferramentas](../mfc/working-with-the-toolbar-control.md)  
  
-   [Usando as barras de ferramentas antigas](../mfc/using-your-old-toolbars.md)  
  
## <a name="see-also"></a>Consulte também  
 [Implementação da barra de ferramentas do MFC](../mfc/mfc-toolbar-implementation.md)

