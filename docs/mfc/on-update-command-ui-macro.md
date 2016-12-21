---
title: "Macro ON_UPDATE_COMMAND_UI | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "ON_UPDATE_COMMAND_UI"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "macros de manipulador de comando"
  - "Macro ON_UPDATE_COMMAND_UI"
  - "atualizar manipuladores"
  - "atualizando objetos de interface do usuário"
ms.assetid: 3e72b50f-4119-4c82-81cf-6e09b132de05
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Macro ON_UPDATE_COMMAND_UI
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Use a janela de **Propriedades** para conectar um objeto da interface do usuário para um manipulador de comando\- UPDATE em um objeto de comando\- destino.  Se conectará automaticamente a ID de objeto da interface de usuário para macro de `ON_UPDATE_COMMAND_UI` e criará um manipulador do objeto que tratará a atualização.  Consulte [Mensagens de mapeamento a funções](../Topic/Mapping%20Messages%20to%20Functions.md) para obter mais informações.  
  
 Por exemplo, para atualizar um espaço livre qualquer comando no menu da edição do programa, use a janela de **Propriedades** para adicionar uma entrada retornadas mapa na classe escolhida, uma declaração de função para um manipulador de comando\- UPDATE chamado `OnUpdateEditClearAll` na declaração de classe, e um modelo vazio da função no arquivo de implementação da classe.  Os aspectos de protótipo da função tem a seguinte aparência:  
  
 [!code-cpp[NVC_MFCDocView#2](../mfc/codesnippet/CPP/on-update-command-ui-macro_1.h)]  
  
 Como todos os manipuladores, a função mostra a palavra\-chave de **afx\_msg** .  Como todos os manipuladores de atualização, usa um argumento, um ponteiro para um objeto de `CCmdUI` .  
  
## Consulte também  
 [Como atualizar objetos de interface do usuário](../mfc/how-to-update-user-interface-objects.md)