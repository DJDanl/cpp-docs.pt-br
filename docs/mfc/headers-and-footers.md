---
title: "Cabe&#231;alhos e rodap&#233;s | Microsoft Docs"
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
  - "rodapés, imprimindo"
  - "cabeçalhos, imprimindo"
  - "rodapés de página"
  - "rodapés de página, imprimindo"
  - "cabeçalhos de página"
  - "cabeçalhos de página, imprimindo"
  - "imprimindo [MFC], cabeçalhos e rodapés"
  - "imprimindo [MFC], documentos multipágina"
ms.assetid: b0be9c53-5773-4955-a777-3c15da745128
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cabe&#231;alhos e rodap&#233;s
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como adicionar cabeçalhos e rodapés para um documento impresso.  
  
 Quando você examina um documento na tela, o nome do documento e seu local atual no documento são exibidos normalmente na barra de título e em uma barra de status.  Ao examinar uma cópia impressa de um documento, é útil ter o nome e o número da página mostrados em um cabeçalho ou rodapé.  Essa é uma forma comum em mesmo que os programas de WYSIWYG diferem em execução como ótica a visualização de impressão e.  
  
 A função de membro de [OnPrint](../Topic/CView::OnPrint.md) é o local apropriado para imprimir cabeçalhos ou rodapés porque é chamada para cada página, e porque é chamada somente imprimindo, não para a visualização ótica.  Você pode definir uma função separada para imprimir um cabeçalho ou rodapé, e transfira o contexto do dispositivo de impressora de `OnPrint`.  Talvez seja necessário ajustar a origem ou a extensão da janela antes de chamar [OnDraw](../Topic/CView::OnDraw.md) para evitar que o corpo da página sobreposição do cabeçalho ou rodapé.  Você também pode precisar alterar `OnDraw` porque a quantidade de documento que se ajusta na página pudesse ser reduzida.  
  
 Uma maneira de compensar a área do cabeçalho ou o rodapé é usar o membro de **m\_rectDraw** de [CPrintInfo](../mfc/reference/cprintinfo-structure.md).  Cada vez que uma página é impressa, este membro está inicializado com a área utilizável da página.  Se você imprime um cabeçalho ou rodapé antes que imprimir o corpo da página, você pode reduzir o tamanho do retângulo armazenado em **m\_rectDraw** para a conta para a área do cabeçalho ou o rodapé.  Em `OnPrint` pode se referir a **m\_rectDraw** para saber quanto a área permanece imprimindo o corpo da página.  
  
 Você não pode imprimir um cabeçalho, ou qualquer outra coisa, de [OnPrepareDC](../Topic/CView::OnPrepareDC.md), porque é chamado antes que a função de membro de `StartPage` de [CDC](../Topic/CDC%20Class.md) seja chamada.  Nesse ponto, o contexto do dispositivo de impressora é considerado estar em um limite de página.  Você pode executar somente imprimir da função de membro de `OnPrint` .  
  
## Que você deseja saber mais?  
  
-   [Imprimindo documentos de várias páginas](../mfc/multipage-documents.md)  
  
-   [Alocando recursos de GDI para imprimir](../mfc/allocating-gdi-resources.md)  
  
## Consulte também  
 [Imprimindo](../mfc/printing.md)