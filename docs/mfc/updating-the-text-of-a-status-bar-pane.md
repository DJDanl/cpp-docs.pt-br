---
title: Atualizando o texto de um painel da barra de Status | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ae8b15431edbdd24a7afd6c7e25be6b9eadb4107
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50081383"
---
# <a name="updating-the-text-of-a-status-bar-pane"></a>Atualizando o texto de um painel da barra de status

Este artigo explica como alterar o texto que aparece em um painel de barra de status do MFC. Uma barra de status — um objeto window da classe [CStatusBar](../mfc/reference/cstatusbar-class.md) — contém vários "painéis". Cada painel é uma área retangular da barra de status que você pode usar para exibir informações. Por exemplo, muitos aplicativos exibem o status da tecla CAPS LOCK, NUM LOCK e outras chaves nos painéis mais à direita. Aplicativos também geralmente exibem texto informativo no painel mais à esquerda (painel 0), às vezes chamado de "painel de mensagem". Por exemplo, a barra de status MFC padrão usa o painel para exibir uma cadeia de caracteres explicando o botão de barra de ferramentas ou item de menu selecionado no momento. A figura no [barras de Status](../mfc/status-bar-implementation-in-mfc.md) mostra uma barra de status de um aplicativo criado pelo Assistente de aplicativo MFC.

Por padrão, o MFC não habilita um `CStatusBar` painel quando ele cria o painel. Para ativar um painel, você deve usar a macro ON_UPDATE_COMMAND_UI para cada painel na barra de status e atualizar os painéis. Porque os painéis não enviam mensagens WM_COMMAND (eles não são como botões da barra de ferramentas), você deve digitar o código manualmente.

Por exemplo, suponha que tem um painel `ID_INDICATOR_PAGE` como seu identificador de comando e que ele contém o número da página atual em um documento. O procedimento a seguir descreve como criar um novo painel na barra de status.

### <a name="to-make-a-new-pane"></a>Para fazer um novo painel

1. Definir a ID de comando. do painel

   Sobre o **modo de exibição** menu, clique em **exibição de recurso**. O recurso do projeto com o botão direito e clique em **símbolos de recurso**. Na caixa de diálogo símbolos de recurso, clique em `New`. Digite um nome de ID de comando: por exemplo, `ID_INDICATOR_PAGE`. Especifique um valor para a ID ou aceite o valor sugerido pela caixa de diálogo símbolos de recurso. Por exemplo, para `ID_INDICATOR_PAGE`, aceite o valor padrão. Feche a caixa de diálogo símbolos de recurso.

1. Defina uma cadeia de caracteres padrão para exibir no painel.

   Com a exibição de recurso aberta, clique duas vezes **tabela de cadeia de caracteres** na janela que lista os tipos de recursos para seu aplicativo. Com o **tabela de cadeia de caracteres** editor aberto, escolha **nova cadeia de caracteres** do **inserir** menu. Na janela Propriedades de cadeia de caracteres, selecione a ID de comando do seu painel (por exemplo, `ID_INDICATOR_PAGE`) e digite um valor de cadeia de caracteres de padrão, como "Página". Feche o editor de cadeia de caracteres. (Você precisa de uma cadeia de caracteres padrão para evitar um erro do compilador).

1. Adicionar o painel para o *indicadores* matriz.

   No arquivo MAINFRM. CPP, localize o *indicadores* matriz. Essa matriz lista de IDs de comando para todos os indicadores da barra de status, na ordem da esquerda para a direita. No ponto apropriado na matriz, insira a ID de comando do seu painel, conforme mostrado aqui para `ID_INDICATOR_PAGE`:

   [!code-cpp[NVC_MFCDocView#10](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_1.cpp)]

A maneira recomendada para exibir o texto em um painel é chamar o `SetText` função de membro da classe `CCmdUI` em uma função de manipulador de atualização para o painel. Por exemplo, você talvez queira configurar uma variável de inteiro *m_nPage* que contém o número da página atual e use `SetText` para definir o texto do painel para uma versão de cadeia de caracteres desse número.

> [!NOTE]
>  O `SetText` abordagem é recomendada. É possível executar essa tarefa em um nível um pouco inferior ao chamar o `CStatusBar` função de membro `SetPaneText`. Mesmo assim, você ainda precisa de um manipulador de atualização. Sem tal um manipulador para o painel, MFC desabilita automaticamente o painel, apagar seu conteúdo.

O procedimento a seguir mostra como usar uma função de manipulador de atualização para exibir o texto em um painel.

#### <a name="to-make-a-pane-display-text"></a>Para tornar um painel exibir texto

1. Adicione um manipulador de atualização de comando para o comando.

   Adicionar manualmente um protótipo para o manipulador, conforme mostrado aqui para `ID_INDICATOR_PAGE` (em MAINFRM. H):

   [!code-cpp[NVC_MFCDocView#11](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_2.h)]

1. Em apropriado. CPP do arquivo, adicione a definição do manipulador, conforme mostrado aqui para `ID_INDICATOR_PAGE` (em MAINFRM. CPP):

   [!code-cpp[NVC_MFCDocView#12](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_3.cpp)]

   As três últimas linhas desse manipulador são o código que exibe seu texto.

1. No mapa de mensagens apropriado, adicione a macro ON_UPDATE_COMMAND_UI, conforme mostrado aqui para `ID_INDICATOR_PAGE` (em MAINFRM. CPP):

   [!code-cpp[NVC_MFCDocView#13](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_4.cpp)]

Depois de definir o valor da *m_nPage* variável de membro (da classe `CMainFrame`), essa técnica faz com que o número de páginas que aparecem no painel de durante o processamento ocioso da mesma maneira que o aplicativo atualiza a outros indicadores. Se *m_nPage* alterações, a exibição é alterada durante o próximo loop ocioso.

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Atualizando objetos de interface do usuário (como atualizar itens de menu e botões da barra de ferramentas, como alteração de condições do programa)](../mfc/how-to-update-user-interface-objects.md)

## <a name="see-also"></a>Consulte também

[Implementação da barra de status no MFC](../mfc/status-bar-implementation-in-mfc.md)<br/>
[Classe CStatusBar](../mfc/reference/cstatusbar-class.md)
