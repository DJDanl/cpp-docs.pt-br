---
title: "Manipulando comandos no documento | Microsoft Docs"
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
  - "WM_COMMAND"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tratamento de comandos"
  - "tratamento de comandos, comandos em documentos"
  - "documentos, tratando mensagens em"
  - "documentos, mapas de mensagem"
  - "lidando com erros, Mensagens WM_COMMAND"
  - "mapas de mensagem, em classe de documento"
  - "WM_COMMAND"
ms.assetid: c7375584-27af-4275-b2fd-afea476785d0
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Manipulando comandos no documento
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A classe do documento também pode tratar certos comandos gerados por itens de menu, por botões da barra de ferramentas, ou por teclas de aceleração.  Por padrão, **CDocument** trata a salvar e salve como comandos no menu arquivo, usando a serialização.  Outros comandos que afetam os dados também podem ser tratados pelas funções de membro do documento.  Por exemplo, no programa de garrancho, a classe `CScribDoc` fornece um manipulador para o espaço livre de edição qualquer comando, que exclui todos os dados armazenados atualmente no documento.  Os documentos podem ter mapas da mensagem, mas diferente de outras exibições, os documentos não podem tratar mensagens padrão do windows somente mensagens de **WM\_COMMAND** , ou “comandos.”  
  
## Consulte também  
 [Usando documentos](../mfc/using-documents.md)