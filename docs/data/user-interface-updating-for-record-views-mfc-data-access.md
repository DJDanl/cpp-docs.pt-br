---
title: "Atualiza&#231;&#227;o de interface do usu&#225;rio para exibi&#231;&#245;es de registro (Acesso a dados MFC) | Microsoft Docs"
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
  - "menus, atualizando como alterações de contexto"
  - "exibições de registro, interface do usuário"
  - "interfaces do usuário, atualizando"
ms.assetid: 2c7914b6-2dc3-40c3-b2f2-8371da2a4063
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atualiza&#231;&#227;o de interface do usu&#225;rio para exibi&#231;&#245;es de registro (Acesso a dados MFC)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

`CRecordView` and `CDaoRecordView` também fornecem manipuladores de atualização de interface do usuário padrão para os comandos de navegação.  Esses manipuladores automatizam habilitando e desabilitando os objetos de interface do usuário – itens de menu e botões da barra de ferramentas.  O Assistente de aplicativo fornece menus padrão e, se você escolher, a opção **Ferramentas Acoplável**, um conjunto de botões da barra de ferramentas para os comandos.  Se você criar uma classe de exibição do registro usando `CRecordView`, poderá adicionar objetos de interface do usuário semelhantes ao seu aplicativo.  
  
### Para criar recursos de menu com o editor de menu  
  
1.  Consultando as informações sobre como usar o [editor de menu](../Topic/Menu%20Editor.md), crie seu próprio menu com os mesmos quatro comandos.  
  
#### Para criar os botões da barra de ferramentas com o editor de gráficos  
  
1.  Consultando as informações sobre como usar o [editor da barra de ferramentas](../mfc/toolbar-editor.md), edite o recurso da barra de ferramentas para adicionar botões da barra de ferramentas aos comandos de navegação doe registro.  
  
## Consulte também  
 [Dando suporte à navegação em uma exibição de registro](../Topic/Supporting%20Navigation%20in%20a%20Record%20View%20%20\(MFC%20Data%20Access\).md)   
 [Usando uma exibição de registro](../data/using-a-record-view-mfc-data-access.md)