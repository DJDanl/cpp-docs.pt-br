---
title: "Especificando p&#225;ginas de propriedades | Microsoft Docs"
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
  - "ISpecifyPropertyPages"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método de ISpecifyPropertyPages"
  - "páginas de propriedades, especificando"
ms.assetid: ee8678cf-c708-49ab-b0ad-fc2db31f1ac3
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especificando p&#225;ginas de propriedades
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você cria um controle ActiveX, você freqüentemente desejará associá\-lo com páginas de propriedades que podem ser usadas para definir as propriedades do controle.  Contêiners do controle usando a interface de **ISpecifyPropertyPages** para descobrir que as páginas de propriedades podem ser usadas para definir as propriedades do controle.  Você precisará implementar essa interface no controle.  
  
 Para implementar **ISpecifyPropertyPages** usando ATL, siga as seguintes etapas:  
  
1.  Derivado da classe de [ISpecifyPropertyPagesImpl](../Topic/ISpecifyPropertyPagesImpl%20Class.md).  
  
2.  Adicione uma entrada para **ISpecifyPropertyPages** ao mapa COM de sua classe.  
  
3.  Adicione uma entrada de [PROP\_PAGE](../Topic/PROP_PAGE.md) no mapa da propriedade para cada página associada com o controle.  
  
> [!NOTE]
>  Para gerar um controle padrão usando [Assistente de controle de ATL](../atl/reference/atl-control-wizard.md), você terá que adicionar apenas as entradas de `PROP_PAGE` no mapa da propriedade.  O assistente gera código necessário para as outras etapas.  
  
 Os bons contêiner exibirão as páginas de propriedades especificadas na mesma ordem que as entradas de `PROP_PAGE` na propriedade aponta.  Em geral, você deve colocar entradas padrão da página de propriedades após as entradas para suas páginas personalizadas no mapa da propriedade, para que os usuários vejam as páginas específicas para seu primeiro controle.  
  
## Exemplo  
 A seguinte classe para um controle de calendário usa a interface de **ISpecifyPropertyPages** para instruir o contêiner que suas propriedades podem ser definidas usando uma página personalizado de data e a página conservada em estoque de cor.  
  
 [!code-cpp[NVC_ATL_Windowing#72](../atl/codesnippet/CPP/specifying-property-pages_1.h)]  
  
## Consulte também  
 [Páginas de propriedade](../atl/atl-com-property-pages.md)   
 [exemplo de ATLPages](../top/visual-cpp-samples.md)