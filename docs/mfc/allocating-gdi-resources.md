---
title: Alocando recursos GDI | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- resources [MFC], printing
- GDI objects [MFC], allocating during printing
- printing [MFC], allocating GDI resources
ms.assetid: cef7e94d-5a27-4aea-a9ee-8369fc895d3a
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 976852b11101a608a47f37ec1c796ef1363ec648
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="allocating-gdi-resources"></a>Alocando recursos GDI
Este artigo explica como aloque e desaloque os objetos GDI (interface) do Windows gráficos dispositivo necessários para impressão.  
  
> [!NOTE]
>  GDI+ está incluído no Windows XP e está disponível como um redistribuível para Windows NT 4.0 SP6, Windows 2000, Windows 98 e Windows Me. Para baixar o redistribuível mais recente, consulte [http://www.microsoft.com/msdownload/platformsdk/sdkupdate/psdkredist.htm](http://www.microsoft.com/msdownload/platformsdk/sdkupdate/psdkredist.htm). Para obter mais informações, consulte a documentação do SDK GDI+ em: [http://msdn.microsoft.com/library/default.aspurl=/library/gdicpp/GDIPlus/GDIPlus.asp](http://msdn.microsoft.com/library/default.aspurl=/library/gdicpp/gdiplus/gdiplus.asp).  
  
 Suponha que você precisa usar certas fontes, canetas ou outros objetos GDI para impressão, mas não para exibição na tela. Devido a memória que eles precisam, é ineficiente para alocar esses objetos quando o aplicativo é iniciado. Quando o aplicativo não imprimir um documento, que a memória poderá ser necessária para outras finalidades. É melhor alocá-los quando começa a impressão e, em seguida, excluí-los ao imprimir termina.  
  
 Para alocar esses objetos GDI, substituir o [OnBeginPrinting](../mfc/reference/cview-class.md#onbeginprinting) função de membro. Essa função é adequada para essa finalidade por dois motivos: o framework chama esta função uma vez no início de cada trabalho de impressão e, ao contrário de [OnPreparePrinting](../mfc/reference/cview-class.md#onprepareprinting), essa função tem acesso a [CDC](../mfc/reference/cdc-class.md) objeto que representa o driver de dispositivo de impressora. Você pode armazenar esses objetos para uso durante o trabalho de impressão, definindo variáveis de membro em sua classe de modo que aponte para objetos GDI (por exemplo, **CFont \***  membros e assim por diante).  
  
 Para usar os objetos GDI que você criou, selecione-as no contexto de dispositivo de impressora no [OnPrint](../mfc/reference/cview-class.md#onprint) função de membro. Se você precisar de objetos GDI diferentes para diferentes páginas do documento, você pode examinar o `m_nCurPage` membro o [CPrintInfo](../mfc/reference/cprintinfo-structure.md) estrutura e selecione o objeto GDI adequadamente. Se você precisar de um objeto GDI para várias páginas consecutivas, Windows exige que você selecioná-lo no contexto do dispositivo sempre `OnPrint` é chamado.  
  
 Para desalocar a esses objetos GDI, substituir o [OnEndPrinting](../mfc/reference/cview-class.md#onendprinting) função de membro. O framework chama esta função no final de cada trabalho de impressão, dando-lhe a oportunidade para desalocar objetos GDI de impressão específicos antes do aplicativo retorna para outras tarefas.  
  
## <a name="see-also"></a>Consulte também  
 [Impressão](../mfc/printing.md)   
 [Como a impressão padrão é feita](../mfc/how-default-printing-is-done.md)

