---
title: "Como: converter uma faixa de opções do MFC existente em um recurso de faixa de opções | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- ribbon resource, converting from an MFC ribbon
- MFC ribbon, converting to a ribbon resource
ms.assetid: 324b7ff6-58f9-4691-96a9-9836a79d0fb6
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 97097618ee3f166866daad68190b7c22cca3c16d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-convert-an-existing-mfc-ribbon-to-a-ribbon-resource"></a>Como converter uma faixa de opções MFC existente em um recurso da faixa de opções
Recursos de faixa de opções são mais fáceis de visualizar, modificar e manter que faixas de opções codificadas manualmente. Este tópico descreve como converter uma faixa de opções manualmente codificada em um projeto MFC em um recurso de faixa de opções.  
  
 Você deve ter um projeto MFC existente que tem o código que usa as classes de faixa de opções do MFC, por exemplo, [classe CMFCRibbonBar](../mfc/reference/cmfcribbonbar-class.md).  
  
### <a name="to-convert-an-mfc-ribbon-to-a-ribbon-resource"></a>Para converter uma faixa de opções do MFC para um recurso de faixa de opções  
  
1.  No Visual Studio, em um projeto MFC existente, abra o arquivo de origem em que o objeto de CMFCRibbonBar é inicializado. Normalmente, o arquivo é mainfrm.cpp. Adicione o seguinte código após o código de inicialização para a faixa de opções.  
  
 ```  
    m_wndRibbonBar.SaveToXMLFile("RibbonOutput.xml");

 ```  
  
     Salve e feche o arquivo.  
  
2.  Compilar e executar o aplicativo do MFC e, em seguida, no bloco de notas, abra RibbonOutput.txt e copiar o conteúdo.  
  
3.  No Visual Studio, no **projeto** menu, clique em **adicionar recurso**. No **adicionar recurso** caixa de diálogo, selecione **faixa de opções** e, em seguida, clique em **novo**.  
  
     Visual Studio cria um recurso de faixa de opções e abre no modo de design. A ID de recurso da faixa de opções é IDR_RIBBON1, que é exibido em **exibição recursos**. A faixa de opções é definida no arquivo XML ribbon1.mfcribbon ms.  
  
4.  No Visual Studio, abra ribbon1.mfcribbon ms, exclua seu conteúdo e, em seguida, cole o conteúdo de RibbonOutput.txt, que você copiou anteriormente. Salve e feche ribbon1.mfcribbon ms.  
  
5.  Abra novamente o arquivo de origem em que o objeto de CMFCRibbonBar é inicializado (normalmente, mainfrm.cpp) e comente existente código da faixa de opções. Adicione o seguinte código após o código que você comentadas.  
  
 ```  
    m_wndRibbonBar.LoadFromResource(IDR_RIBBON1);

 ```  
  
6.  Compilar o projeto e execute o programa.  
  
## <a name="see-also"></a>Consulte também  
 [Designer da faixa de opções (MFC)](../mfc/ribbon-designer-mfc.md)

