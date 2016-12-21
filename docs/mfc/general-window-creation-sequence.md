---
title: "Sequ&#234;ncia de cria&#231;&#227;o da janela geral | Microsoft Docs"
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
  - "janelas com moldura [C++], criando"
  - "sequência [C++]"
  - "sequência [C++], criação de janelas"
  - "janelas [C++], criando"
ms.assetid: 9cd8c7ea-5e24-429e-b6d9-d7b6041d8ba6
caps.latest.revision: 8
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sequ&#234;ncia de cria&#231;&#227;o da janela geral
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você cria uma janela de seu próprio, como uma janela filho, a estrutura muito usa o mesmo processo que o descrita em [Criação de documento\/exibição](../mfc/document-view-creation.md).  
  
 Todas as classes da janela fornecidas por MFC empregam [construção de dois estágios](../mfc/one-stage-and-two-stage-construction-of-objects.md).  Ou seja, durante uma invocação de operador C\+\+ **new** , o construtor aloca e inicializa o objeto c criando mas não uma janela correspondente do windows.  Isso é feito mais tarde chamando a função de membro de [Crie](../Topic/CWnd::Create.md) do objeto da janela.  
  
 A função de membro de **Criar** faz a janela do windows e armazena o `HWND` no membro de dados público [m\_hWnd](../Topic/CWnd::m_hWnd.md)do objeto C\+\+.  **Criar** fornece a flexibilidade total sobre os parâmetros de criação.  Antes de chamar **Criar**, talvez você queira registrar uma classe do windows com a função global [AfxRegisterWndClass](../Topic/AfxRegisterWndClass.md) para definir os estilos do ícone e da classe para o quadro.  
  
 Para o windows do quadro, você pode usar a função de membro de [LoadFrame](../Topic/CFrameWnd::LoadFrame.md) em vez de **Criar**.  `LoadFrame` faz a janela do windows usando menos parâmetros.  Obtém muitos valores padrão de recursos, incluindo a legenda do quadro, o ícone, a tabela de aceleração, e o menu.  
  
> [!NOTE]
>  Os ícones, tabela de aceleração, e recursos no menu devem ter uma ID de recurso comuns, como **IDR\_MAINFRAME**, para que sejam carregados por LoadFrame.  
  
## Que você deseja saber mais?  
  
-   [Objetos da janela](../mfc/window-objects.md)  
  
-   [Registrar a janela “classificar”](../mfc/registering-window-classes.md)  
  
-   [Objetos de destruição da janela](../mfc/destroying-window-objects.md)  
  
-   [Criando o windows do quadro do documento](../Topic/Creating%20Document%20Frame%20Windows.md)  
  
## Consulte também  
 [Criando janelas](../Topic/Creating%20Windows.md)