---
title: "Vincula&#231;&#227;o de dados com controles ActiveX no Visual C++ | Microsoft Docs"
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
  - "Controles ActiveX [C++], associação de dados"
  - "controles associados [C++], ActiveX"
  - "controles [C++], associação de dados"
  - "associação de dados [C++], Controles ActiveX"
  - "controles de dados associados [C++], ActiveX"
ms.assetid: afe11d2b-eefe-43ce-958d-82d3d4dee158
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Vincula&#231;&#227;o de dados com controles ActiveX no Visual C++
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A associação de dados é implementada através de dois tipos de controles ActiveX: controles de dados e controles associados a dados.  
  
 **Controles de dados**  
 Um controle de dados é responsável por encapsular uma consulta do banco de dados e o conjunto de linhas recuperado.  Os controles de dados da Microsoft fornecem uma interface de usuário que consiste em uma série de botões para iteração pelos dados.  Visual C\+\+ oferece duas tecnologias de acesso a dados para controles de dados: [ADO e RDO](../../data/ado-rdo/data-access-ado-and-rdo.md).  
  
> [!IMPORTANT]
>  Os controles de dados de ADO e RDO são uma tecnologia mais antiga lançada em uma versão anterior do Visual Studio e não estão disponíveis na versão atual.  Para usar as informações desta seção, talvez você precise obter uma versão anterior para adquirir o controle apropriado.  
  
 **Controles associados a dados**  
 Um controle associado a dados é responsável para apresentar os dados.  Os controles associados a dados se conectam aos controles de dados para receber e apresentar dados através de várias interfaces de usuário.  Um aplicativo Visual C\+\+ também pode associar variáveis a valores de dados definidos em controles associados a dados; consulte [CWnd::BindProperty](../Topic/CWnd::BindProperty.md).  
  
 Para obter mais informações sobre associação de dados, consulte:  
  
-   [Controles ActiveX MFC: Usando associação de dados em um controle ActiveX](../../mfc/mfc-activex-controls-using-data-binding-in-an-activex-control.md)  
  
-   [Acesso aos dados: ADO e RDO](../../data/ado-rdo/data-access-ado-and-rdo.md)  
  
-   [Associação de dados ADO](../../data/ado-rdo/ado-databinding.md)  
  
-   [Associação de dados RDO](../../data/ado-rdo/rdo-databinding.md)  
  
-   [Classes wrapper](../../data/ado-rdo/wrapper-classes.md)  
  
-   [Configuração de manipuladores de eventos em controles ActiveX](../../data/ado-rdo/setting-event-handlers-on-activex-controls.md)  
  
-   [Interceptação de erro](../../data/ado-rdo/error-trapping.md)  
  
-   [Restrições da associação de dados](../../data/ado-rdo/limitations-of-databinding.md)  
  
## Consulte também  
 [Controles de dados associados \(ADO e RDO\)](../Topic/Data-Bound%20Controls%20\(ADO%20and%20RDO\).md)