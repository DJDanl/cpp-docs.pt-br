---
title: "Vantagens da arquitetura de documento/exibi&#231;&#227;o | Microsoft Docs"
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
  - "arquitetura de documento/exibição, vantagens de"
  - "modos de exibição, vantagens"
ms.assetid: 0bc27071-e120-4889-939c-ce1e61fb9cb3
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vantagens da arquitetura de documento/exibi&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A vantagem importante para usar a arquitetura do documento\/exibição MFC é que a arquitetura da suporte a várias exibições do mesmo documento bem particularmente. \(Se você não precisar de várias exibições e a pequena sobrecarga do documento\/exibição é excessiva em seu aplicativo, você pode impedir a arquitetura.  [Alternativas a arquitetura do documento\/exibição](../mfc/alternatives-to-the-document-view-architecture.md).\)  
  
 Suponhamos que seu aplicativo permite que dados numéricos de exibição de usuários no formulário da planilha ou em formato de gráfico.  Um usuário pode querer ver simultaneamente os dados brutos, no formato da planilha, e um gráfico que resulta de dados.  Você exibe essas exibições separadas no windows separadas do quadro ou em painéis do separador em uma única janela.  Agora suponha que o usuário pode editar os dados na planilha e ver as alterações refletidas imediatamente no gráfico.  
  
 MFC no, a exibição da planilha e a exibição de gráfico serão baseadas nas diferentes classes derivadas de CView.  Ambas as exibições são associadas a um único objeto de documento.  Os repositórios de documento os dados \(ou talvez a obtenção de um base de dados\).  Ambas as exibições acessam o documento e exibem os dados que recuperam deles.  
  
 Quando um usuário atualiza uma das exibições, esse objeto de exibição chama `CDocument::UpdateAllViews`.  A função que notifica as exibições de todo o documento, e as atualizações de cada a própria exibição que usam os dados mais recentes do documento.  O única chamada para `UpdateAllViews` sincroniza as exibições diferentes.  
  
 Este cenário seria difícil de código sem a divisão da exibição, especialmente se as exibições que se encontra os dados são exibidos.  Com documento\/exibição, é fácil.  A estrutura faz a maioria do trabalho de coordenação para você.  
  
## Que você deseja saber mais?  
  
-   [Documentar alternativas\/exibição](../mfc/alternatives-to-the-document-view-architecture.md)  
  
-   [CDocument](../Topic/CDocument%20Class.md)  
  
-   [CView](../Topic/CView%20Class.md)  
  
-   [CDocument::UpdateAllViews](../Topic/CDocument::UpdateAllViews.md)  
  
-   [CView::GetDocument](../Topic/CView::GetDocument.md)  
  
## Consulte também  
 [Arquitetura de documento\/exibição](../Topic/Document-View%20Architecture.md)