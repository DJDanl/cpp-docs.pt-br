---
title: Atualizando o texto de um painel da barra de Status | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0fb0f9bdaa032340256eee4781bfd775767f62ee
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="updating-the-text-of-a-status-bar-pane"></a>Atualizando o texto de um painel da barra de status
Este artigo explica como alterar o texto que aparece em um painel de barra de status do MFC. Uma barra de status — um objeto window da classe [CStatusBar](../mfc/reference/cstatusbar-class.md) — contém vários "painéis". Cada painel é uma área retangular da barra de status que você pode usar para exibir informações. Por exemplo, muitos aplicativos exibem o status da tecla CAPS LOCK, NUM LOCK e outras chaves nos painéis na extrema direita. Aplicativos normalmente exibem texto informativo na extrema esquerdo painel de (0), às vezes chamado de "painel de mensagem". Por exemplo, a barra de status MFC padrão usa o painel para exibir uma cadeia de caracteres explicando o botão de item ou a barra de ferramentas do menu selecionado no momento. A figura no [barras de Status](../mfc/status-bar-implementation-in-mfc.md) mostra uma barra de status de um aplicativo criado pelo Assistente de aplicativo MFC.  
  
 Por padrão, o MFC não permitem uma `CStatusBar` painel quando ele cria o painel. Para ativar um painel, você deve usar o `ON_UPDATE_COMMAND_UI` macro para cada painel do status de barras e atualizar os painéis. Porque painéis não enviar **WM_COMMAND** mensagens (eles não são como os botões de barra de ferramentas), você deve digitar o código manualmente.  
  
 Por exemplo, suponha que um painel tem `ID_INDICATOR_PAGE` como seu identificador de comando e que contém o número da página atual em um documento. O procedimento a seguir descreve como criar um novo painel na barra de status.  
  
### <a name="to-make-a-new-pane"></a>Para tornar um novo painel  
  
1.  Definir a ID de comando. do painel  
  
     Sobre o **exibição** menu, clique em **exibição de recursos**. O recurso de projeto de atalho e clique em **símbolos de recurso**. Na caixa de diálogo símbolos de recurso, clique em `New`. Digite um nome de identificação de comando: por exemplo, `ID_INDICATOR_PAGE`. Especifique um valor para a ID ou aceite o valor sugerido pela caixa de diálogo símbolos de recurso. Por exemplo, para `ID_INDICATOR_PAGE`, aceite o valor padrão. Feche a caixa de diálogo símbolos de recurso.  
  
2.  Defina uma cadeia de caracteres padrão para exibir no painel.  
  
     Com a exibição de recurso abrir, clique duas vezes em **tabela de cadeia de caracteres** na janela que lista os tipos de recursos para seu aplicativo. Com o **tabela de cadeia de caracteres** editor aberto, escolha **nova cadeia de caracteres** do **inserir** menu. Na janela de propriedades de cadeia de caracteres, selecione a ID de comando do painel (por exemplo, `ID_INDICATOR_PAGE`) e digite um valor de cadeia de caracteres padrão, como "Página". Feche o editor de cadeia de caracteres. (Você precisa de uma cadeia de caracteres padrão para evitar um erro do compilador).  
  
3.  Adicionar um painel para o **indicadores** matriz.  
  
     No arquivo MAINFRM. CPP, localize o **indicadores** matriz. Esta matriz de lista de IDs de comando para todos os indicadores da barra de status, na ordem da esquerda para a direita. No ponto apropriado na matriz, insira a ID de comando do painel, como mostrado aqui para `ID_INDICATOR_PAGE`:  
  
     [!code-cpp[NVC_MFCDocView#10](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_1.cpp)]  
  
 A maneira recomendada para exibir texto em um painel é chamar o **SetText** função de membro de classe `CCmdUI` em uma função de manipulador de atualização para o painel. Por exemplo, você talvez queira configurar uma variável de inteiro `m_nPage` que contém o número da página atual e o uso **SetText** para definir o texto do painel para uma versão de cadeia de caracteres do número.  
  
> [!NOTE]
>  O **SetText** abordagem é recomendada. É possível executar essa tarefa em um nível inferior ligeiramente chamando o `CStatusBar` função de membro `SetPaneText`. Mesmo assim, você ainda precisa de um manipulador de atualização. Sem essa um manipulador para o painel, MFC desabilitará automaticamente o painel, apagar seu conteúdo.  
  
 O procedimento a seguir mostra como usar uma função de manipulador de atualização para exibir texto em um painel.  
  
#### <a name="to-make-a-pane-display-text"></a>Para fazer com que um painel exibir texto  
  
1.  Adicione um manipulador de atualização de comando para o comando.  
  
     Adicionar manualmente um protótipo para o manipulador, conforme mostrado aqui para `ID_INDICATOR_PAGE` (em MAINFRM. H):  
  
     [!code-cpp[NVC_MFCDocView#11](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_2.h)]  
  
2.  Em apropriado. CPP de arquivo, adicione a definição do manipulador, conforme mostrado aqui para `ID_INDICATOR_PAGE` (em MAINFRM. CPP):  
  
     [!code-cpp[NVC_MFCDocView#12](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_3.cpp)]  
  
     As três últimas linhas deste manipulador são o código que exibe o texto.  
  
3.  No mapa de mensagem apropriado, adicione o `ON_UPDATE_COMMAND_UI` macro, conforme mostrado aqui para `ID_INDICATOR_PAGE` (em MAINFRM. CPP):  
  
     [!code-cpp[NVC_MFCDocView#13](../mfc/codesnippet/cpp/updating-the-text-of-a-status-bar-pane_4.cpp)]  
  
 Depois de definir o valor da `m_nPage` variável de membro (classe `CMainFrame`), essa técnica faz com que o número da página seja exibido no painel de durante o processamento ocioso da mesma maneira que o aplicativo atualiza a outros indicadores. Se `m_nPage` alterações, a exibição é alterada durante o próximo loop ocioso.  
  
### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Atualizando objetos de interface do usuário (como atualizar itens de menu e botões de barra de ferramentas, como alteração de condições de programa)](../mfc/how-to-update-user-interface-objects.md)  
  
## <a name="see-also"></a>Consulte também  
 [Implementação da barra de status no MFC](../mfc/status-bar-implementation-in-mfc.md)   
 [Classe CStatusBar](../mfc/reference/cstatusbar-class.md)
