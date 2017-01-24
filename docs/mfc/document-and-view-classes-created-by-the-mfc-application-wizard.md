---
title: "Classes de documento e exibi&#231;&#227;o criadas pelo Assistente de Aplicativo MFC | Microsoft Docs"
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
  - "assistentes de aplicativo [C++], classes de documento/exibição criadas"
  - "classes de documento"
  - "classes de documento, criadas por assistentes de aplicativo"
  - "classes de exibição, criadas por assistentes de aplicativo"
ms.assetid: 70c34a60-2701-4981-acea-c08a5787d8e6
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de documento e exibi&#231;&#227;o criadas pelo Assistente de Aplicativo MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O assistente de aplicativo MFC oferece um avanço no desenvolvimento de programas criando classes armazenados esqueléticos do documento e de exibição para você.  Você pode então [comandos e mensagens do mapa a essas classes](../Topic/Mapping%20Messages%20to%20Functions.md) e usar o editor de origem do Visual C\+\+ para escrever suas funções de membro.  
  
 A classe do documento criada pelo assistente de aplicativo MFC é derivada da classe [CDocument](../Topic/CDocument%20Class.md).  A classe da exibição é derivada de [CView](../Topic/CView%20Class.md).  Os nomes que o assistente do aplicativo dessas classes e os arquivos que contêm os base no nome de projeto que você fornece na caixa de diálogo do assistente do aplicativo.  No assistente do aplicativo, você pode usar a página gerado a partir das classes para alterar os nomes padrão.  
  
 Alguns aplicativos podem precisar de mais de uma classe do documento, a classe da exibição, ou a classe de quadro\- janela.  Para obter mais informações, consulte [Vários tipos de documento, exibições, e janelas do quadro](../mfc/multiple-document-types-views-and-frame-windows.md).  
  
## Consulte também  
 [Arquitetura de documento\/exibição](../Topic/Document-View%20Architecture.md)