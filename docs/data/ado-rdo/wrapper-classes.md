---
title: "Classes wrapper | Microsoft Docs"
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
  - "Controles ActiveX [C++], classes wrapper"
  - "associação de dados [C++], Controles ActiveX"
  - "Classes wrapper [C++], Controles ActiveX"
ms.assetid: ebbc17b9-cc1b-4c29-afa9-da7f9511876e
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes wrapper
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Quando você [inserir um controle](../../data/ado-rdo/inserting-the-control-into-a-visual-cpp-application.md) em um projeto do Visual C\+\+, classes wrapper para o controle não é incluído por padrão.  No entanto, se desejar que a [alterar o comportamento de controle](../../data/ado-rdo/modifying-a-control-s-run-time-behavior.md), você pode escrever uma classe wrapper para o controle.  Dependendo de como você pretende manipular programaticamente o controle, você precisa gravar uma ou mais das classes wrapper do controle.  
  
 Uma classe wrapper está disponível para cada um dos coclasses no arquivo de biblioteca de tipos de controle \(.tlb\).  A classe de invólucro de controle deve ser o nome do controle prefixado pela letra C.  
  
 Para obter mais informações sobre a funcionalidade das classes wrapper, consulte o modelo de objeto da tecnologia de base do controle.  
  
 Usar [CWnd::GetDlgItem](../Topic/CWnd::GetDlgItem.md) também requer classes wrapper porque o valor de retorno deve ser convertido para a classe do controle.  Por exemplo:  
  
```  
CDBList* pDBList = 0;  
pDBList = static_cast<CDBList*>(GetDlgItem(IDC_DBLIST));  
```  
  
 Lê o arquivo gerado de .idl, você pode determinar quais propriedades, métodos, e eventos são expostas por um controle, bem como consulte declarações do método e de função do acessador diretamente.  Informações adicionais podem ser obtidas de controle usando [Visualizador de objetos OLE\/COM](../Topic/Using%20the%20OLE-COM%20Object%20Viewer.md).  
  
## Consulte também  
 [Usando controles ActiveX](../Topic/Using%20ActiveX%20Controls.md)   
 [Modificando o comportamento de tempo de execução de um controle](../../data/ado-rdo/modifying-a-control-s-run-time-behavior.md)