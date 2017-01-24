---
title: "Alocando recursos GDI | Microsoft Docs"
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
  - "objetos GDI, alocando durante a impressão"
  - "imprimindo [MFC], alocando recursos GDI"
  - "recursos [MFC], imprimindo"
ms.assetid: cef7e94d-5a27-4aea-a9ee-8369fc895d3a
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Alocando recursos GDI
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo explica como alocar e desalocar os objetos GDI \(interface\) do Windows graphics dispositivo necessários para a impressão.  
  
> [!NOTE]
>  GDI\+ é incluído no Windows XP e está disponível como um redistribuível para Windows NT 4.0 SP6, Windows 2000, Windows 98 e Windows Me.  Para baixar o redistribuível mais recente, consulte  [http:\/\/www.microsoft.com\/msdownload\/platformsdk\/sdkupdate\/psdkredist.htm](http://www.microsoft.com/msdownload/platformsdk/sdkupdate/psdkredist.htm).  Para obter mais informações, consulte a documentação de GDI\+ SDK no MSDN: [http:\/\/msdn.microsoft.com\/library\/default.asp?url\=\/library\/gdicpp\/GDIPlus\/GDIPlus.asp](http://msdn.microsoft.com/library/default.asp?url=/library/gdicpp/GDIPlus/GDIPlus.asp).  
  
 Suponha que você precise usar determinadas fontes, canetas ou outros objetos GDI para impressão, mas não para exibição na tela.  Devido à memória de que necessitam, é ineficiente para alocar esses objetos quando o aplicativo é iniciado.  Quando o aplicativo não imprimir um documento, essa memória poderá ser necessária para outras finalidades.  É melhor alocá\-las quando começa a impressão e, em seguida, excluí\-los durante a impressão termina.  
  
 Para alocar esses objetos GDI, substituir o [OnBeginPrinting](../Topic/CView::OnBeginPrinting.md) função de membro.  Essa função é ideal para essa finalidade por dois motivos: o framework chama essa função uma vez no início de cada trabalho de impressão e, ao contrário de [OnPreparePrinting](../Topic/CView::OnPreparePrinting.md), essa função tem acesso a [CDC](../Topic/CDC%20Class.md) objeto que representa o driver de impressora.  Você pode armazenar esses objetos para uso durante o trabalho de impressão com a definição de variáveis de membro em sua classe de modo que apontem para objetos GDI \(por exemplo, **CFont \*** membros e assim por diante\).  
  
 Para usar os objetos GDI que você criou, selecione\-as no contexto de dispositivo de impressora no [OnPrint](../Topic/CView::OnPrint.md) função de membro.  Se você precisar objetos GDI diferentes para diferentes páginas do documento, você pode examinar o `m_nCurPage` membro a [CPrintInfo](../mfc/reference/cprintinfo-structure.md) estrutura e selecione o objeto GDI adequadamente.  Se você precisar de um objeto GDI para várias páginas consecutivas, Windows requer que você selecioná\-lo no contexto de dispositivo sempre que `OnPrint` é chamado.  
  
 Para desalocar esses objetos GDI, substituir o [OnEndPrinting](../Topic/CView::OnEndPrinting.md) função de membro.  O framework chama essa função ao final de cada trabalho de impressão, oferecendo a oportunidade para desalocar objetos GDI de impressão específico antes do aplicativo retorna para outras tarefas.  
  
## Consulte também  
 [Imprimindo](../mfc/printing.md)   
 [Como a impressão padrão é feita](../Topic/How%20Default%20Printing%20Is%20Done.md)