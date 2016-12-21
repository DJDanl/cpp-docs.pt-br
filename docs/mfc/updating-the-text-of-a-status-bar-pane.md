---
title: "Atualizando o texto de um painel da barra de status | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CStatusBar, atualizando"
  - "Macro ON_UPDATE_COMMAND_UI"
  - "painéis, barra de status"
  - "Método SetText"
  - "barras de status, atualizando"
  - "texto, barra de status"
  - "atualizando objetos de interface do usuário"
  - "objetos de interface do usuário, atualizando"
ms.assetid: 4984a3f4-9905-4d8c-a927-dca19781053b
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atualizando o texto de um painel da barra de status
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como modificar o texto que aparece em um painel barra de status MFC.  Uma barra de status — um objeto da janela da classe [CStatusBar](../mfc/reference/cstatusbar-class.md) — “contém vários painéis.” Cada painel é uma área retangular na barra de status que você pode usar para exibir as informações.  Por exemplo, muitos aplicativos exibem o status de CAPS LOCK, LOCK NUMERIC, e outras chaves nos painéis mais à direita.  Os aplicativos também exibem que frequência o texto informativo no painel mais à esquerda \(o painel 0\), às vezes chamado de “do painel mensagem”. Por exemplo, a barra de status MFC da opção usa o painel de mensagem para exibir uma cadeia de caracteres que explica o item de menu ou no botão da barra de ferramentas selecionado.  Em [Barras de status](../mfc/status-bar-implementation-in-mfc.md) a figura mostra uma barra de status de um aplicativo criado no aplicativo MFC.  
  
 Por padrão, o MFC não habilita um painel de `CStatusBar` quando cria o painel.  Para ativar um painel, você deve usar a macro de `ON_UPDATE_COMMAND_UI` para cada painel na barra de status e atualizar os painéis.  Como os painéis não envia mensagens de **WM\_COMMAND** \(não são como os botões da barra de ferramentas\), você deve digitar o código manualmente.  
  
 Por exemplo, suponha que um painel tem `ID_INDICATOR_PAGE` como seu identificador do comando e que contém o número da página atual em um documento.  O procedimento a seguir descreve como criar um novo painel na barra de status.  
  
### Para criar um novo painel  
  
1.  Define a ID de comando do painel  
  
     No menu de **Exibir** , clique em **Modo de Exibição de Recurso**.  Clique com o botão direito do mouse no recurso de projeto e clique **Símbolos do recurso**.  Na caixa de diálogo dos símbolos de recurso, clique `New`.  Digite um nome para o ID do comando: por exemplo, `ID_INDICATOR_PAGE`.  Especifique um valor para o ID, ou aceite o valor sugerido pela caixa de diálogo dos símbolos de recurso.  Por exemplo, para `ID_INDICATOR_PAGE`, aceite o valor padrão.  Feche a caixa de diálogo dos símbolos de recurso.  
  
2.  Define uma cadeia de caracteres padrão a ser exibida no painel.  
  
     Com a exibição de recursos aberta, clique duas vezes em **Tabela de Cadeias de Caracteres** na janela que lista os tipos de recurso para seu aplicativo.  Com o editor de **Tabela de Cadeias de Caracteres** aberto, escolha **Nova cadeia de caracteres** no menu de **Inserir** .  Na janela Propriedades da cadeia de caracteres, selecione a ID de comando do painel \(por exemplo, `ID_INDICATOR_PAGE`\) e digite um valor de cadeia de caracteres padrão, como “página”.  Feche o editor de cadeia de caracteres. \(Você precisa de uma cadeia de caracteres padrão de evitar um erro do compilador.\)  
  
3.  Adicionar o painel para a matriz de **indicators** .  
  
     No arquivo MAINFRM.CPP, localize a matriz de **indicators** .  As listas dessa matriz comando IDs para todos os indicadores da barra de status, na ordem da esquerda para a direita.  No ponto correto na matriz, digite a ID de comando do painel, conforme mostrado aqui para `ID_INDICATOR_PAGE`:  
  
     [!code-cpp[NVC_MFCDocView#10](../mfc/codesnippet/CPP/updating-the-text-of-a-status-bar-pane_1.cpp)]  
  
 A maneira recomendada de exibir o texto em um painel é chamar a função de membro de **SetText** da classe `CCmdUI` em uma função de manipulador de atualização para o painel.  Por exemplo, você pode desejar configurar uma variável de inteiro `m_nPage` que contém o número da página atual e o uso **SetText** definir o texto do painel para uma versão de cadeia de caracteres do número.  
  
> [!NOTE]
>  A abordagem de **SetText** é recomendada.  É possível executar um pouco esta tarefa em um nível inferior chamando a função de membro `SetPaneText`de `CStatusBar` .  No entanto, você ainda precisa de um manipulador de atualização.  Sem essa manipulador para o painel, o MFC desabilita o painel automaticamente, apagando seu conteúdo.  
  
 O procedimento a seguir mostra como usar uma função de manipulador de atualização para exibir o texto em um painel.  
  
#### Para fazer um painel exibir o texto  
  
1.  Adicionar um manipulador de atualização de comando para o comando.  
  
     Adicione manualmente um protótipo para o manipulador, como mostrado aqui para `ID_INDICATOR_PAGE` \(em MAINFRM.H\):  
  
     [!code-cpp[NVC_MFCDocView#11](../mfc/codesnippet/CPP/updating-the-text-of-a-status-bar-pane_2.h)]  
  
2.  No arquivo apropriado de .CPP, adicione a definição do manipulador, como mostrado aqui para `ID_INDICATOR_PAGE` \(em MAINFRM.CPP\):  
  
     [!code-cpp[NVC_MFCDocView#12](../mfc/codesnippet/CPP/updating-the-text-of-a-status-bar-pane_3.cpp)]  
  
     As três linhas as mais recentes manipulador deste é o código que exibe o texto.  
  
3.  No mapa apropriado de mensagem, adicione a macro de `ON_UPDATE_COMMAND_UI` , como mostrado aqui para `ID_INDICATOR_PAGE` \(em MAINFRM.CPP\):  
  
     [!code-cpp[NVC_MFCDocView#13](../mfc/codesnippet/CPP/updating-the-text-of-a-status-bar-pane_4.cpp)]  
  
 Depois de definir o valor da variável de membro de `m_nPage` \(da classe `CMainFrame`\), essa técnica o número da página aparecer no painel durante o processamento de ociosidade da mesma forma que o aplicativo atualizará outros indicadores.  Se `m_nPage` for alterada, a exibição será alterado durante o loop ocioso seguir.  
  
### Que você deseja saber mais?  
  
-   [Atualizando objetos de interface do usuário \(como atualizar os botões da barra de ferramentas e os itens de menu como a alteração das condições de programa\)](../mfc/how-to-update-user-interface-objects.md)  
  
## Consulte também  
 [Implementação da barra de status no MFC](../mfc/status-bar-implementation-in-mfc.md)   
 [Classe de CStatusBar](../mfc/reference/cstatusbar-class.md)