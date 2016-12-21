---
title: "Manipuladores para comandos e notifica&#231;&#245;es de controle | Microsoft Docs"
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
  - "comandos, manipuladores para"
  - "controles [MFC], notificações"
  - "funções [C++], manipulador"
  - "manipuladores"
  - "manipuladores, comando"
  - "manipuladores, notificação de controle"
  - "notificações, manipuladores para controle"
ms.assetid: 20f57f4a-f577-4c09-80a2-43faf32a1c2e
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipuladores para comandos e notifica&#231;&#245;es de controle
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Não há nenhum manipulador padrão para comandos ou controle\- mensagens de notificação.  Em virtude disso, você está associado somente por convenção de nomeação dos manipuladores para essas categorias de mensagens.  Quando você mapeia uma notificação ao comando ou de controle para um manipulador, as janelas Propriedades proposta um nome com base no código de identificador ou de controle\- notificação de comando.  Você pode aceitar o nome proposto, altere\-o, ou substitui.  
  
 A convenção sugere que você nomeie manipuladores em ambas as categorias para o objeto da interface do usuário que representam o.  Para um manipulador para o comando de divisão no menu editar pode ser nomeado  
  
 [!CODE [NVC_MFCMessageHandling#4](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCMessageHandling#4)]  
  
 Como o comando de divisão é implementado como normalmente em aplicativos, a estrutura predefine a ID de comando do comando como recortar **ID\_EDIT\_CUT**.  Para obter uma lista de todas as IDs predefinidos de comando, consulte o arquivo. AFXRES.H.  Para obter mais informações, consulte [Comandos padrão](../mfc/standard-commands.md).  
  
 Além disso, a convenção sugere que um manipulador para a notificação de **BN\_CLICKED** de um botão rotulado como “my botão” pode ser nomeado  
  
 [!CODE [NVC_MFCMessageHandling#5](../CodeSnippet/VS_Snippets_Cpp/NVC_MFCMessageHandling#5)]  
  
 Você pode atribuir a esse comando um ID de `IDC_MY_BUTTON` porque é equivalente a um objeto da interface do usuário específico do aplicativo.  
  
 Ambas as categorias de mensagens não têm nenhum argumento e não retornará nenhum valor.  
  
## Consulte também  
 [Declarando funções de manipulador de mensagens](../mfc/declaring-message-handler-functions.md)