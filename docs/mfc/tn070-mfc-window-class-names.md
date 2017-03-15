---
title: "TN070: nomes de classe da janela MFC | Microsoft Docs"
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
  - "vc.mfc.classes"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "TN070"
  - "nomes de classe de janela"
ms.assetid: 90617912-dd58-4a7c-9082-ced71736d7cd
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# TN070: nomes de classe da janela MFC
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

> [!NOTE]
>  A nota técnica a seguir não foi atualizada desde que ela foi incluída pela primeira vez na documentação online.  Como resultado, alguns procedimentos e tópicos podem estar incorretos ou expirados.  Para obter as informações mais recentes, é recomendável que você procure o tópico de interesse no índice de documentação online.  
  
 As janelas de MFC usam um nome de classe criado dinamicamente a refletir os recursos da janela.  MFC O gerencia nomes da classe dinamicamente para o windows do quadro, exibições, e as janelas pop\-up geradas pelo aplicativo.  As caixas de diálogo e os controles gerados por um aplicativo MFC o têm o nome fornecido para a classe de janela em questão.  
  
 Você pode substituir o nome da classe dinamicamente fornecido para sua própria classe da janela e a em uma substituição de [PreCreateWindow](../Topic/CWnd::PreCreateWindow.md).  Os nomes da classe MFC\- fornecidos se ajustaram a um dos dois formatos a seguir:  
  
```  
Afx:%x:%x  
Afx:%x:%x:%x:%x:%x  
```  
  
 Os dígitos hexadecimais que substituem os caracteres de `%x` são convertidos dos dados da estrutura de [WNDCLASS](http://msdn.microsoft.com/library/windows/desktop/ms633576) .  MFC O usa essa técnica de modo que várias classes C\+\+ que requerem estruturas idênticas de **WNDCLASS** podem compartilhar a mesma classe registrada da janela.  Ao contrário da maioria dos aplicativos simples do Win32, os aplicativos MFC tem apenas um **WNDPROC**, para que você possa compartilhar facilmente estruturas de **WNDCLASS** para economizar tempo e memória.  Os valores substituíveis para os caracteres de `%x` citados acima são os seguintes:  
  
-   **WNDCLASS.hInstance**  
  
-   **WNDCLASS.style**  
  
-   **WNDCLASS.hCursor**  
  
-   **WNDCLASS.hbrBackground**  
  
-   **WNDCLASS.hIcon**  
  
 O primeiro formulário`Afx:%x:%x`\(\) é usado quando **hCursor**, **hbrBackground**, e **hIcon** é qualquer **nulo**.  
  
## Consulte também  
 [Observações técnicas por número](../mfc/technical-notes-by-number.md)   
 [Observações técnicas por categoria](../mfc/technical-notes-by-category.md)   
 [TN020: convenções de nomenclatura de ID e numeração](../mfc/tn020-id-naming-and-numbering-conventions.md)