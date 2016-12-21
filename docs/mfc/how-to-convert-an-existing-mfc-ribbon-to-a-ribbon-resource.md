---
title: "Como converter uma faixa de op&#231;&#245;es MFC existente em um recurso da faixa de op&#231;&#245;es | Microsoft Docs"
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
  - "Faixa de opções do MFC, convertendo um recurso de faixa de opções"
  - "recurso de faixa de opções, convertendo de uma faixa de opções do MFC"
ms.assetid: 324b7ff6-58f9-4691-96a9-9836a79d0fb6
caps.latest.revision: 8
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como converter uma faixa de op&#231;&#245;es MFC existente em um recurso da faixa de op&#231;&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os recursos da Faixa De Opções são mais fáceis de exibir, modificar e, lembre\-se de que as fitas manualmente valores.  Este tópico descreve como converter uma fita manualmente codificado em um projeto de MFC em um recurso de fita.  
  
 Você deve ter um projeto existente de MFC que tem o código que usa as classes de fita MFC, por exemplo, [Classe de CMFCRibbonBar](../mfc/reference/cmfcribbonbar-class.md).  
  
### Para converter uma fita MFC a um recurso de fita  
  
1.  No Visual Studio, em um projeto existente de MFC, abra o arquivo de origem em que o objeto de CMFCRibbonBar é inicializado.  Normalmente, o arquivo é mainfrm.cpp.  Adicione o seguinte código após o código de inicialização da fita.  
  
    ```  
    m_wndRibbonBar.SaveToXMLFile("RibbonOutput.xml");  
    ```  
  
     Salve e feche o arquivo.  
  
2.  Criar e executar o aplicativo MFC e, no Bloco De Notas, copie RibbonOutput.txt aberto e seu conteúdo.  
  
3.  No Visual Studio, no menu de **Projeto** , clique **Adicionar Recurso**.  Na caixa de diálogo de **Adicionar Recurso** , **Faixa de Opções** selecione e clique em **Novo**.  
  
     Visual Studio cria um recurso de fita e abri\-lo no Modo Design.  A ID do recurso de fita é IDR\_RIBBON1, que é exibido em **Modo de Exibição de Recurso**.  A fita é definida no arquivo XML de ribbon1.mfcribbon\-ms.  
  
4.  No Visual Studio, ribbon1.mfcribbon\-ms abertos, excluir seu conteúdo, e colar o conteúdo do RibbonOutput.txt, que você copiou anterior.  Salvar e fechar ribbon1.mfcribbon\-ms.  
  
5.  Novamente abrir o arquivo de origem em que o objeto de CMFCRibbonBar é inicializada \(normalmente, mainfrm.cpp\) e faça comentários do código existente de fita.  Adicione o seguinte código após o código que você comentou out.  
  
    ```  
    m_wndRibbonBar.LoadFromResource(IDR_RIBBON1);  
    ```  
  
6.  Crie o projeto e execute o programa.  
  
## Consulte também  
 [Designer da faixa de opções \(MFC\)](../mfc/ribbon-designer-mfc.md)