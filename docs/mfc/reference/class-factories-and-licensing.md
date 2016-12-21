---
title: "Alocadores de classe e licenciamento | Microsoft Docs"
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
  - "vc.mfc.macros.classes"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "fábricas de classe, e licenciamento"
ms.assetid: 53c4856a-4062-46db-9f69-dd4339f746b3
caps.latest.revision: 13
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Alocadores de classe e licenciamento
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para criar uma instância do controlador OLE, um aplicativo de contêiner chama uma função de membro de fábrica da classe do controle.  Como o controle é um objeto OLE real, a fábrica da classe é responsável por criar instâncias do controle.  Cada classe do controlador OLE deve ter uma fábrica da classe.  
  
 Outro recurso importante de controladores OLE é a possibilidade de aplicar uma licença.  ControlWizard permite que você insira de licenciamento durante a criação do projeto de controle.  Para obter mais informações sobre o controle de licença, consulte o artigo [Controles ActiveX: Licenciamento um controle ActiveX](../../mfc/mfc-activex-controls-licensing-an-activex-control.md).  
  
 A tabela a seguir lista várias funções e macros usados para declarar e implementar a fábrica da classe do controle e a licença do controle.  
  
### Fábricas e licenciamento da classe  
  
|||  
|-|-|  
|[DECLARE\_OLECREATE\_EX](../Topic/DECLARE_OLECREATE_EX.md)|Declara a fábrica da classe para um controlador OLE ou uma página de propriedades.|  
|[IMPLEMENT\_OLECREATE\_EX](../Topic/IMPLEMENT_OLECREATE_EX.md)|Implementa a função de `GetClassID` de controle e declara uma instância de fábrica da classe.|  
|[BEGIN\_OLEFACTORY](../Topic/BEGIN_OLEFACTORY.md)|Inicia a declaração de todas as funções de licenciamento.|  
|[END\_OLEFACTORY](../Topic/END_OLEFACTORY.md)|Termina a declaração de todas as funções de licenciamento.|  
|[AfxVerifyLicFile](../Topic/AfxVerifyLicFile.md)|Verifica se um controle ser licenciado para uso em um computador específico.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)