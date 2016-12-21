---
title: "P&#225;ginas de propriedade (MFC) | Microsoft Docs"
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
  - "vc.mfc.macros"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "funções de transferência de dados de página de propriedades em MFC"
  - "páginas de propriedade, funções de MFC globais"
ms.assetid: 734f88bc-c776-4136-9b0e-f45c761a45c1
caps.latest.revision: 14
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# P&#225;ginas de propriedade (MFC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

As páginas de propriedades exibem os valores atuais de propriedades específicas do controlador OLE em um personalizável, de interface gráfica para exibir e editar dando suporte a um mecanismo de mapeamento de dados baseado na caixa de diálogo de troca de dados \(DDX\).  
  
 Esse mecanismo de projeção de dados mapeia controles da página de propriedades para as propriedades individuais do controlador OLE.  O valor da propriedade do controle reflete o status ou o conteúdo do controle da página de propriedades.  O mapeamento entre controles da página de propriedades e propriedades é especificado por chamadas de função de **DDP\_** na função de membro de `DoDataExchange` da página de propriedades.  O seguinte é uma lista de funções que **DDP\_** trocar dados inserido usando a página de propriedades do controle:  
  
### Transferência de dados da página de propriedades  
  
|||  
|-|-|  
|[DDP\_CBIndex](../Topic/DDP_CBIndex.md)|Vincula o índice de cadeia de caracteres selecionada em uma caixa de combinação com a propriedade de um controle.|  
|[DDP\_CBString](../Topic/DDP_CBString.md)|Vincula a cadeia de caracteres selecionada em uma caixa de combinação com a propriedade de um controle.  A cadeia de caracteres selecionada pode começar com as mesmas letras que o valor da propriedade mas não precisa corresponde completamente.|  
|[DDP\_CBStringExact](../Topic/DDP_CBStringExact.md)|Vincula a cadeia de caracteres selecionada em uma caixa de combinação com a propriedade de um controle.  A cadeia de caracteres selecionada e o valor da cadeia de caracteres de propriedade devem corresponder exatamente.|  
|[DDP\_Check](../Topic/DDP_Check.md)|Vincula uma caixa de seleção na página de propriedades de controle com a propriedade de um controle.|  
|[DDP\_LBIndex](../Topic/DDP_LBIndex.md)|Vincula o índice de cadeia de caracteres selecionada em uma caixa de listagem a propriedade de um controle.|  
|[DDP\_LBString](../Topic/DDP_LBString.md)|Vincula a cadeia de caracteres selecionada em uma caixa de listagem a propriedade de um controle.  A cadeia de caracteres selecionada pode começar com as mesmas letras que o valor da propriedade mas não precisa corresponde completamente.|  
|[DDP\_LBStringExact](../Topic/DDP_LBStringExact.md)|Vincula a cadeia de caracteres selecionada em uma caixa de listagem a propriedade de um controle.  A cadeia de caracteres selecionada e o valor da cadeia de caracteres de propriedade devem corresponder exatamente.|  
|[DDP\_PostProcessing](../Topic/DDP_PostProcessing.md)|Conclui a transferência dos valores de propriedade do controle.|  
|[DDP\_Radio](../Topic/DDP_Radio.md)|Vincula um grupo do botão de opção na página de propriedades de controle com a propriedade de um controle.|  
|[DDP\_Text](../Topic/DDP_Text.md)|Vincula um controle na página de propriedades de controle com a propriedade de um controle.  Esta função tratará vários tipos diferentes de propriedades, como **double**, **short**, `BSTR`, e **long**.|  
  
 Para obter mais informações sobre a função e as páginas de propriedades de `DoDataExchange` , consulte o artigo [Controles ActiveX: Páginas de propriedades](../../mfc/mfc-activex-controls-property-pages.md).  
  
 O seguinte é uma lista de macros usados para criar e gerenciar páginas de propriedades para um controlador OLE:  
  
### Páginas de Propriedades  
  
|||  
|-|-|  
|[BEGIN\_PROPPAGEIDS](../Topic/BEGIN_PROPPAGEIDS.md)|Inicia a lista de IDs de página de propriedades.|  
|[END\_PROPPAGEIDS](../Topic/END_PROPPAGEIDS.md)|Termina a lista de IDs de página de propriedades.|  
|[PROPPAGEID](../Topic/PROPPAGEID.md)|Declara uma página de propriedades da classe do controle.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)