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
ms.openlocfilehash: 1762931b75734801659fd6271377260bd0473614
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373453"
---
# <a name="toolbar-tool-tips"></a>Dicas de ferramenta da barra de ferramentas

As dicas de ferramentas são as pequenas janelas pop-up que apresentam descrições curtas do propósito de um botão de barra de ferramentas quando você posiciona o mouse sobre um botão por um período de tempo. Quando você cria um aplicativo com o Assistente de Aplicativo que tem uma barra de ferramentas, o suporte à dica da ferramenta é fornecido para você. Este artigo explica tanto o suporte à dica da ferramenta criado pelo Assistente de Aplicativo quanto como adicionar suporte à ponta da ferramenta ao seu aplicativo.

Este artigo cobre:

- [Ativando dicas de ferramentas](#_core_activating_tool_tips)

- [Atualizações da barra de status flyby](#_core_fly_by_status_bar_updates)

## <a name="activating-tool-tips"></a><a name="_core_activating_tool_tips"></a>Ativando dicas de ferramentas

Para ativar as dicas de ferramentas em seu aplicativo, você deve fazer duas coisas:

- Adicione o estilo CBRS_TOOLTIPS aos outros estilos (como WS_CHILD, WS_VISIBLE e outros estilos **CBRS_)** passados como parâmetro *dwStyle* para a [função CToolBar::Criar](../mfc/reference/ctoolbar-class.md#create) ou no [SetBarStyle](../mfc/reference/ccontrolbar-class.md#setbarstyle).

- Conforme descrito no procedimento abaixo, anexar o texto da barra de ferramentas, separado por um caractere newline ('\n'), ao recurso string contendo o prompt de linha de comando para o comando da barra de ferramentas. O recurso string compartilha o ID do botão barra de ferramentas.

#### <a name="to-add-the-tool-tip-text"></a>Para adicionar o texto da dica da ferramenta

1. Enquanto estiver editando a barra de ferramentas no editor da barra de ferramentas, abra a janela **Propriedades do botão da barra de ferramentas** para obter um determinado botão.

1. Na **caixa Prompt,** especifique o texto que deseja aparecer na ponta da ferramenta para esse botão.

> [!NOTE]
> Definir o texto como uma propriedade de botão no editor da barra de ferramentas substitui o procedimento anterior, no qual você teve que abrir e editar o recurso de string.

Se uma barra de controle com as pontas das ferramentas habilitadas tiver os controles de criança colocados nela, a barra de controle exibirá uma dica de ferramenta para cada controle infantil na barra de controle, desde que atenda aos seguintes critérios:

- A id do controle não é 1.

- A entrada de tabela de strings com o mesmo ID que o controle de criança no arquivo de recursos tem uma seqüência de ponta de ferramenta.

## <a name="flyby-status-bar-updates"></a><a name="_core_fly_by_status_bar_updates"></a>Atualizações da barra de status do flyby

Um recurso relacionado às dicas de ferramentas é a atualização da barra de status "flyby". Por padrão, a mensagem na barra de status descreve apenas um botão de barra de ferramentas particular quando o botão é ativado. Ao incluir CBRS_FLYBY em sua `CToolBar::Create`lista de estilos passados, você pode ter essas mensagens atualizadas quando o cursor do mouse passa sobre a barra de ferramentas sem realmente ativar o botão.

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Implementação da barra de ferramentas do MFC (informações de visão geral sobre barras de ferramentas)](../mfc/mfc-toolbar-implementation.md)

- [Barras de ferramentas flutuantes e de acoplamento](../mfc/docking-and-floating-toolbars.md)

- As classes [CToolBarCtrl](../mfc/reference/ctoolbar-class.md) e [CToolBarCtrl](../mfc/reference/ctoolbarctrl-class.md)

- [Trabalhando com o controle da barra de ferramentas](../mfc/working-with-the-toolbar-control.md)

- [Usando suas barras de ferramentas antigas](../mfc/using-your-old-toolbars.md)

## <a name="see-also"></a>Confira também

[Implementação da barra de ferramentas MFC](../mfc/mfc-toolbar-implementation.md)
