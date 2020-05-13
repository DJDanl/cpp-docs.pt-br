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
ms.openlocfilehash: 723046fc1721cc46608e00f19a4431ef081be13d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366689"
---
# <a name="updating-the-text-of-a-status-bar-pane"></a>Atualizando o texto de um painel da barra de status

Este artigo explica como alterar o texto que aparece em um painel de barra de status MFC. Uma barra de status — um objeto de janela da classe [CStatusBar](../mfc/reference/cstatusbar-class.md) — contém vários "painéis". Cada painel é uma área retangular da barra de status que você pode usar para exibir informações. Por exemplo, muitos aplicativos exibem o status do CAPS LOCK, NUM LOCK e outras teclas nos painéis mais à direita. As aplicações também exibem frequentemente texto informativo no painel mais à esquerda (painel 0), às vezes chamado de "painel de mensagem". Por exemplo, a barra de status padrão do MFC usa o painel de mensagens para exibir uma seqüência explicando o item do menu ou o botão da barra de ferramentas atualmente selecionado. A figura em [Barras de status](../mfc/status-bar-implementation-in-mfc.md) mostra uma barra de status de um aplicativo MFC criado pelo Assistente de Aplicativo.

Por padrão, o MFC `CStatusBar` não habilita um painel quando cria o painel. Para ativar um painel, você deve usar a ON_UPDATE_COMMAND_UI macro para cada painel na barra de status e atualizar os painéis. Como os painéis não enviam mensagens WM_COMMAND (não são como botões de barra de ferramentas), você deve digitar o código manualmente.

Por exemplo, suponha `ID_INDICATOR_PAGE` que um painel tenha como identificador de comando e que contenha o número da página atual em um documento. O procedimento a seguir descreve como criar um novo painel na barra de status.

### <a name="to-make-a-new-pane"></a>Para fazer um novo painel

1. Defina o ID de comando do painel.

   No menu **Exibir,** clique **em Exibição de recursos**. Clique com o botão direito do mouse no recurso do projeto e clique **em Símbolos de recursos**. Na caixa de diálogo Símbolos de recursos, clique em `New`. Digite um nome de id de comando: por exemplo, `ID_INDICATOR_PAGE`. Especifique um valor para o ID ou aceite o valor sugerido pela caixa de diálogo Símbolos de recursos. Por exemplo, `ID_INDICATOR_PAGE`para, aceitar o valor padrão. Feche a caixa de diálogo Símbolos de recursos.

1. Defina uma seqüência padrão a ser exibida no painel.

   Com a exibição de recursos aberta, clique duas vezes em **Tabela de strings** na janela que lista os tipos de recursos para o seu aplicativo. Com o editor **da tabela de strings** aberto, escolha **Nova string** no menu **Inserir.** Selecione o ID de comando do `ID_INDICATOR_PAGE`painel (por exemplo) e digite um valor de string padrão, como "Page". Feche o editor de cordas. (Você precisa de uma seqüência padrão para evitar um erro do compilador.)

1. Adicione o painel à matriz de *indicadores.*

   No arquivo MAINFRM. CPP, localize o array de *indicadores.* Esta matriz lista IDs de comando para todos os indicadores da barra de status, em ordem da esquerda para a direita. No ponto apropriado da matriz, digite o ID de comando `ID_INDICATOR_PAGE`do painel, conforme mostrado aqui para:

   [!code-cpp[NVC_MFCDocView#10](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_1.cpp)]

A maneira recomendada de exibir texto em um `SetText` painel é `CCmdUI` chamar a função de membro da classe em uma função de manipulador de atualização para o painel. Por exemplo, você pode querer configurar uma variável inteira *m_nPage* que `SetText` contém o número da página atual e usar para definir o texto do painel para uma versão de seqüência desse número.

> [!NOTE]
> Recomenda-se `SetText` a abordagem. É possível executar essa tarefa em um nível `CStatusBar` ligeiramente mais baixo, chamando a função `SetPaneText`de membro . Mesmo assim, você ainda precisa de um manipulador de atualização. Sem esse manipulador para o painel, o MFC desativa automaticamente o painel, apagando seu conteúdo.

O procedimento a seguir mostra como usar uma função de manipulador de atualização para exibir texto em um painel.

#### <a name="to-make-a-pane-display-text"></a>Para fazer um texto de exibição de painel

1. Adicione um manipulador de atualização de comando para o comando.

   Adicione manualmente um protótipo para o `ID_INDICATOR_PAGE` manipulador, como mostrado aqui para (em MAINFRM. H):

   [!code-cpp[NVC_MFCDocView#11](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_2.h)]

1. No caso apropriado. Arquivo CPP, adicione a definição do manipulador, conforme mostrado aqui para `ID_INDICATOR_PAGE` (em MAINFRM. CPP):

   [!code-cpp[NVC_MFCDocView#12](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_3.cpp)]

   As últimas três linhas deste manipulador são o código que exibe seu texto.

1. No mapa de mensagens apropriado, adicione a `ID_INDICATOR_PAGE` ON_UPDATE_COMMAND_UI macro, conforme mostrado aqui (no MAINFRM. CPP):

   [!code-cpp[NVC_MFCDocView#13](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_4.cpp)]

Uma vez que você *m_nPage* define o valor `CMainFrame`da variável membro m_nPage (de classe), essa técnica faz com que o número da página apareça no painel durante o processamento ocioso da mesma forma que o aplicativo atualiza outros indicadores. Se *m_nPage* mudar, o visor será alterado durante o próximo ciclo ocioso.

### <a name="what-do-you-want-to-know-more-about"></a>O que você quer saber mais sobre

- [Atualizar objetos de interface do usuário (como atualizar botões de barra de ferramentas e itens de menu à medida que as condições do programa mudam)](../mfc/how-to-update-user-interface-objects.md)

## <a name="see-also"></a>Confira também

[Implementação da barra de status no MFC](../mfc/status-bar-implementation-in-mfc.md)<br/>
[Classe CStatusBar](../mfc/reference/cstatusbar-class.md)
