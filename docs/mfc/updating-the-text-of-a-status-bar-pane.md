---
title: Atualizando o texto de um painel da barra de status
ms.date: 11/04/2016
helpviewer_keywords:
- updating user interface objects [MFC]
- ON_UPDATE_COMMAND_UI macro [MFC]
- user interface objects [MFC], updating
- text, status bar
- CStatusBar class [MFC], updating
- SetText method [MFC]
- panes, status bar
- status bars [MFC], updating
ms.assetid: 4984a3f4-9905-4d8c-a927-dca19781053b
ms.openlocfilehash: 20cd519f15fa9b218bca3dd1348659cfd0d5e473
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907631"
---
# <a name="updating-the-text-of-a-status-bar-pane"></a>Atualizando o texto de um painel da barra de status

Este artigo explica como alterar o texto que aparece em um painel de barra de status do MFC. Uma barra de status — um objeto Window da classe [CStatusBar](../mfc/reference/cstatusbar-class.md) — contém vários "painéis". Cada painel é uma área retangular da barra de status que você pode usar para exibir informações. Por exemplo, muitos aplicativos exibem o status do CAPS LOCK, NUM LOCK e outras chaves nos painéis mais à direita. Normalmente, os aplicativos também exibem texto informativo no painel mais à esquerda (painel 0), às vezes chamado de "painel de mensagens". Por exemplo, a barra de status padrão do MFC usa o painel de mensagens para exibir uma cadeia de caracteres explicando o item de menu selecionado no momento ou o botão da barra de ferramentas. A figura nas [barras de status](../mfc/status-bar-implementation-in-mfc.md) mostra uma barra de status de um aplicativo MFC criado pelo assistente de aplicativo.

Por padrão, o MFC não habilita um `CStatusBar` painel quando ele cria o painel. Para ativar um painel, você deve usar a macro ON_UPDATE_COMMAND_UI para cada painel na barra de status e atualizar os painéis. Como os painéis não enviam mensagens WM_COMMAND (eles não são como botões da barra de ferramentas), você deve digitar o código manualmente.

Por exemplo, suponha que um painel `ID_INDICATOR_PAGE` tenha como seu identificador de comando e que ele contenha o número de página atual em um documento. O procedimento a seguir descreve como criar um novo painel na barra de status.

### <a name="to-make-a-new-pane"></a>Para criar um novo painel

1. Defina a ID de comando do painel.

   No menu **Exibir** , clique em **modo de exibição de recursos**. Clique com o botão direito do mouse no recurso do projeto e clique em **símbolos de recurso**. Na caixa de diálogo símbolos de recurso, `New`clique em. Digite um nome de ID de comando: por `ID_INDICATOR_PAGE`exemplo,. Especifique um valor para a ID ou aceite o valor sugerido pela caixa de diálogo símbolos de recurso. Por exemplo, para `ID_INDICATOR_PAGE`, aceite o valor padrão. Feche a caixa de diálogo símbolos de recurso.

1. Defina uma cadeia de caracteres padrão para exibir no painel.

   Com Modo de Exibição de Recursos aberto, clique duas vezes em **tabela de cadeia de caracteres** na janela que lista os tipos de recursos para seu aplicativo. Com o editor de **tabela de cadeia de caracteres** aberto, escolha **nova cadeia de caracteres** no menu **Inserir** . Selecione a ID de comando do painel (por exemplo `ID_INDICATOR_PAGE`,) e digite um valor de cadeia de caracteres padrão, como "página". Feche o editor de cadeia de caracteres. (Você precisa de uma cadeia de caracteres padrão para evitar um erro do compilador.)

1. Adicione o painel à matriz de *indicadores* .

   No arquivo MAINFRM. CPP, localize a matriz de *indicadores* . Essa matriz lista as IDs de comando para todos os indicadores da barra de status, na ordem da esquerda para a direita. No ponto apropriado na matriz, insira a ID de comando do painel, conforme mostrado aqui para `ID_INDICATOR_PAGE`:

   [!code-cpp[NVC_MFCDocView#10](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_1.cpp)]

A maneira recomendada para exibir texto em um painel é chamar a `SetText` função de membro da classe `CCmdUI` em uma função de manipulador de atualização para o painel. Por exemplo, você pode desejar configurar uma variável de número inteiro *m_nPage* que contenha o número de página atual `SetText` e usar para definir o texto do painel como uma versão de cadeia de caracteres desse número.

> [!NOTE]
>  A `SetText` abordagem é recomendada. É possível executar essa tarefa em um nível um pouco menor chamando a função `CStatusBar` `SetPaneText`de membro. Mesmo assim, você ainda precisa de um manipulador de atualização. Sem esse manipulador para o painel, o MFC desabilita automaticamente o painel, apagando seu conteúdo.

O procedimento a seguir mostra como usar uma função de manipulador de atualização para exibir texto em um painel.

#### <a name="to-make-a-pane-display-text"></a>Para fazer com que um painel exiba texto

1. Adicione um manipulador de atualização de comando para o comando.

   Adicione manualmente um protótipo para o manipulador, conforme mostrado aqui para `ID_INDICATOR_PAGE` (em MainFrm. H):

   [!code-cpp[NVC_MFCDocView#11](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_2.h)]

1. No apropriado. Arquivo cpp, adicione a definição do manipulador, conforme mostrado aqui para `ID_INDICATOR_PAGE` (em MainFrm. CPP):

   [!code-cpp[NVC_MFCDocView#12](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_3.cpp)]

   As últimas três linhas desse manipulador são o código que exibe o texto.

1. No mapa de mensagens apropriado, adicione a macro ON_UPDATE_COMMAND_UI, conforme mostrado aqui para `ID_INDICATOR_PAGE` (em MainFrm. CPP):

   [!code-cpp[NVC_MFCDocView#13](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_4.cpp)]

Depois de definir o valor da variável de membro *m_nPage* (da classe `CMainFrame`), essa técnica faz com que o número da página apareça no painel durante o processamento de ociosidade da mesma maneira que o aplicativo atualiza outros indicadores. Se *m_nPage* for alterado, a exibição será alterada durante o próximo loop ocioso.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Atualizando objetos da interface do usuário (como atualizar os botões da barra de ferramentas e os itens de menu conforme as condições do programa mudam)](../mfc/how-to-update-user-interface-objects.md)

## <a name="see-also"></a>Consulte também

[Implementação da barra de status no MFC](../mfc/status-bar-implementation-in-mfc.md)<br/>
[Classe CStatusBar](../mfc/reference/cstatusbar-class.md)
