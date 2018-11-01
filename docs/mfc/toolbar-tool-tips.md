---
title: Dicas de ferramenta da barra de ferramentas
ms.date: 11/04/2016
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
ms.openlocfilehash: b7dbae03b23c26c96aa0db740b749ba728a353d6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50475602"
---
# <a name="toolbar-tool-tips"></a>Dicas de ferramenta da barra de ferramentas

Dicas de ferramenta são as janelas de pop-up pequeno que apresentam breves descrições sobre a finalidade de um botão barra de ferramentas quando você posiciona o mouse sobre um botão para um período de tempo. Quando você cria um aplicativo com o Assistente de aplicativo que tem uma barra de ferramentas, suporte à dica de ferramenta é fornecido para você. Este artigo explica os dois o suporte de dica ferramenta criado pelo Assistente de aplicativo e como adicionar suporte à dica de ferramenta para seu aplicativo.

Este artigo aborda:

- [Ativar dicas de ferramenta](#_core_activating_tool_tips)

- [Atualizações da barra de status flyby](#_core_fly_by_status_bar_updates)

##  <a name="_core_activating_tool_tips"></a> Ativar dicas de ferramenta

Para ativar dicas de ferramenta em seu aplicativo, você deve fazer duas coisas:

- Adicionar o estilo CBRS_TOOLTIPS outros estilos (como WS_CHILD, WS_VISIBLE e outras **CBRS_** estilos) passado como o *dwStyle* parâmetro para o [CToolBar::Create](../mfc/reference/ctoolbar-class.md#create) função ou no [SetBarStyle](../mfc/reference/ccontrolbar-class.md#setbarstyle).

- Conforme descrito no procedimento a seguir, acrescente o texto da dica de ferramentas, separado por um caractere de nova linha ('\n'), para o recurso de cadeia de caracteres que contém o prompt de linha de comando para o comando da barra de ferramentas. O recurso de cadeia de caracteres compartilha a ID do botão de barra de ferramentas.

#### <a name="to-add-the-tool-tip-text"></a>Para adicionar o texto da dica de ferramenta

1. Enquanto você estiver editando a barra de ferramentas no editor de barra de ferramentas, abra o **propriedades do botão de barra de ferramentas** janela para um botão especificado.

1. No **Prompt** , especifique o texto que você deseja que apareça na dica de ferramenta para esse botão.

> [!NOTE]
>  Definindo o texto como uma propriedade de botão no editor de barra de ferramentas substitui o procedimento anterior, era necessário abrir e editar o recurso de cadeia de caracteres.

Se uma barra de controle com dicas de ferramenta habilitado tem controles filho colocados nele, a barra de controle exibirá uma dica de ferramenta para cada controle filho na barra de controle, desde que ele atende aos seguintes critérios:

- A ID do controle é não - 1.

- A entrada da tabela de cadeia de caracteres com a mesma ID que o controle filho no arquivo de recurso tem uma cadeia de caracteres de dica de ferramenta.

##  <a name="_core_fly_by_status_bar_updates"></a> Atualizações da barra de Status flyby

Um recurso relacionado a dicas de ferramenta é a barra de atualização de status de "flyby". Por padrão, a mensagem na barra de status descreve apenas um botão de barra de ferramentas específica quando o botão é ativado. Incluindo CBRS_FLYBY na sua lista de estilos passado para `CToolBar::Create`, você pode ter essas mensagens atualizadas quando o cursor do mouse passa sobre a barra de ferramentas sem, na verdade, ativar o botão.

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Implementação de barra de ferramentas MFC (informações de visão geral das barras de ferramentas)](../mfc/mfc-toolbar-implementation.md)

- [Encaixando e flutuando barras de ferramentas](../mfc/docking-and-floating-toolbars.md)

- O [CToolBar](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md) classes

- [Trabalhando com o controle de barra de ferramentas](../mfc/working-with-the-toolbar-control.md)

- [Usando as barras](../mfc/using-your-old-toolbars.md)

## <a name="see-also"></a>Consulte também

[Implementação da barra de ferramentas do MFC](../mfc/mfc-toolbar-implementation.md)

