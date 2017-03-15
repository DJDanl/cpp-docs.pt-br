---
title: "Impress&#227;o e visualiza&#231;&#227;o de impress&#227;o | Microsoft Docs"
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
  - "visualizando a impressão"
  - "visualizar impressão"
  - "imprimindo [C++]"
  - "imprimindo [C++], visualizar impressão"
  - "imprimindo [MFC]"
ms.assetid: d15059cd-32de-4450-95f7-e73aece238f6
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Impress&#227;o e visualiza&#231;&#227;o de impress&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

MFC O oferece suporte a impressão e a visualização de impressão para documentos do programa pela classe [CView](../Topic/CView%20Class.md).  Para impressão e a visualização de impressão básicos, substitua apenas a função de membro de [OnDraw](../Topic/CView::OnDraw.md) da sua classe da exibição, que você deve fazer de qualquer maneira.  Essa função pode tirar à exibição na tela, a um contexto do dispositivo de impressora para uma impressora real, ou a um contexto do dispositivo que simular a impressora na tela.  
  
 Você também pode adicionar código para gerenciar a impressão e visualização de várias páginas do documento, a seus documentos impressos, e para adicionar\-lhes cabeçalhos e rodapés.  
  
 Esta família de artigos explica como imprimindo é implementado na biblioteca de classes do Microsoft \(MFC\) e como se beneficiar da arquitetura de impressão já criada na estrutura.  Os artigos também explicam como MFC o oferece suporte à implementação fácil da funcionalidade de visualização de impressão e como você pode usar e modificar essa funcionalidade.  
  
## Que você deseja saber mais?  
  
-   [Imprimindo](../mfc/printing.md)  
  
-   [Arquitetura de visualização de impressão](../mfc/print-preview-architecture.md)  
  
-   [Amostra](../top/visual-cpp-samples.md)  
  
## Consulte também  
 [Elementos da interface do usuário](../mfc/user-interface-elements-mfc.md)