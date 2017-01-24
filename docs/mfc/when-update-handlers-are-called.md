---
title: "Quando manipuladores de atualiza&#231;&#227;o s&#227;o chamados | Microsoft Docs"
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
  - "roteamento de comando, comandos de atualização"
  - "roteamento de comando, atualizar manipuladores"
  - "desabilitando itens de menu"
  - "desabilitando botões de barra de ferramentas"
  - "itens de menu, ativando"
  - "menus [C++], inicializando"
  - "menus [C++], atualizando como alterações de contexto"
  - "botões da barra de ferramentas [C++], ativando"
  - "controles de barra de ferramentas [MFC], atualizado durante o método OnIdle"
  - "barras de ferramentas [C++], atualizando"
  - "atualizar manipuladores"
  - "atualizar manipuladores, Chamando "
  - "atualizando objetos de interface do usuário"
ms.assetid: 7359f6b1-4669-477d-bd99-690affed08d9
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Quando manipuladores de atualiza&#231;&#227;o s&#227;o chamados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Suponha o usuário ao mouse em no menu arquivo, que gerencia uma mensagem de `WM_INITMENUPOPUP` .  O mecanismo de atualização da estrutura atualiza coletivamente todos os itens no menu arquivo antes de remover o menu para baixo para que o usuário pode exibi\-lo.  
  
 Para fazer isso, os comandos de atualização das rotas da estrutura para todos os itens de menu no menu suspenso ao longo de roteamento de comando padrão.  Os destinos de roteamento no comando têm uma oportunidade de atualizar todos os itens de menu correspondendo o comando de atualização com uma entrada apropriada retornadas \(mapa do formulário `ON_UPDATE_COMMAND_UI`“\) e a invocação de uma função de manipulador atualização”.  Assim, para um menu com seis itens de menu, seis comandos de atualização são mandados.  Se um manipulador de atualização existe para a ID do item de menu, é chamado para fazer atualização.  Caso contrário, a estrutura verifica a existência de um manipulador para esse ID do comando e habilita ou desabilita o item de menu conforme apropriado.  
  
 Se a estrutura não encontra uma entrada de `ON_UPDATE_COMMAND_UI` durante o roteamento de comando, habilita automaticamente o objeto da interface de usuário se houver uma entrada de `ON_COMMAND` em algum lugar com a mesma ID de comando  Se não, desabilitar o objeto da interface do usuário.  Em virtude disso, para garantir que um objeto da interface do usuário está habilitado, forneça um manipulador para o comando que gerencia o objeto ou fornecer um manipulador de atualização para ele.  Consulte a figura [Objetos de interface do usuário e IDs de comando](../mfc/user-interface-objects-and-command-ids.md)no tópico.  
  
 É possível desabilitar desabilitar padrão dos objetos de interface do usuário.  Para obter mais informações, consulte o membro de [m\_bAutoMenuEnable](../Topic/CFrameWnd::m_bAutoMenuEnable.md) da classe `CFrameWnd`*na referência de MFC*.  
  
 A inicialização do menu é automático na estrutura, ocorrendo quando o aplicativo recebe uma mensagem de `WM_INITMENUPOPUP` .  Durante o loop ociosa, a estrutura pesquisa o comando que o roteamento para manipuladores de atualização do botão da mesma forma como ele faz para menus.  
  
## Consulte também  
 [Como atualizar objetos de interface do usuário](../mfc/how-to-update-user-interface-objects.md)