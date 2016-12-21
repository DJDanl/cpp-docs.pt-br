---
title: "Destruindo janelas com moldura | Microsoft Docs"
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
  - "PostNcDestroy"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método Default"
  - "destruindo janelas com moldura"
  - "Método DestroyWindow"
  - "janelas de documento com moldura, destruindo"
  - "janelas com moldura [C++], destruindo"
  - "MFC [C++], janelas com moldura"
  - "Método OnClose"
  - "Método OnNcDestroy, e janelas com moldura"
  - "Método PostNcDestroy"
  - "janelas [C++], destruindo"
ms.assetid: 5affca77-1999-4507-a2b2-9aa226611b4b
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Destruindo janelas com moldura
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A estrutura de MFC gerencia a destruição bem como a criação da janela para as janelas associadas com documentos e as exibições da estrutura.  Se você criar janelas adicionais, você é responsável por destrui\-las.  
  
 Na estrutura, quando o usuário fecha a janela do quadro, o manipulador padrão de [OnClose](../Topic/CWnd::OnClose.md) da janela chama [DestroyWindow](../Topic/CWnd::DestroyWindow.md).  A função de membro a última chamada quando a janela do windows é destruída é [OnNcDestroy](../Topic/CWnd::OnNcDestroy.md), que faz qualquer limpeza, chama a função de membro de [Opção](../Topic/CWnd::Default.md) para executar a limpeza do windows, e chama alteração da função de membro virtual [PostNcDestroy](../Topic/CWnd::PostNcDestroy.md).  A implementação de [CFrameWnd](../mfc/reference/cframewnd-class.md) de `PostNcDestroy` exclui o objeto da janela C\+\+.  Você nunca deve usar o operador C\+\+ **delete** em uma janela do quadro.  Use `DestroyWindow` em vez disso.  
  
 Quando a janela principal fecha, o aplicativo será fechada.  Se houver documentos não salvas alterados, a estrutura exibe uma caixa de mensagem para perguntar se os documentos são salvos e garante que os documentos apropriadas estão salvos se necessário.  
  
## Que você deseja saber mais?  
  
-   [Criando o windows do quadro do documento](../Topic/Creating%20Document%20Frame%20Windows.md)  
  
## Consulte também  
 [Usando janelas com moldura](../Topic/Using%20Frame%20Windows.md)