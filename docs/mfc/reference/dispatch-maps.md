---
title: "Mapas de expedi&#231;&#227;o | Microsoft Docs"
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
  - "vc.mfc.macros.maps"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "macros de mapa de distribuição"
  - "mapas de envios"
  - "macros de mapas de distribuição"
ms.assetid: bef9d08b-ad35-4c3a-99d8-04150c7c04e2
caps.latest.revision: 14
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Mapas de expedi&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A Automação OLE fornece modos de chamar métodos e acessar propriedades pelos aplicativos.  O mecanismo fornecido pela biblioteca de classes do Microsoft para expedir essas solicitações do mapa é “distribuição”, que designa os nomes internos e externos de funções e as propriedades do objeto, bem como os tipos de dados das propriedades em si mesmos e de argumentos de função.  
  
### Mapas de distribuição  
  
|||  
|-|-|  
|[DECLARE\_DISPATCH\_MAP](../Topic/DECLARE_DISPATCH_MAP.md)|Declara que um mapa de distribuição será usado para expor os métodos e as propriedades de uma classe \(deve ser usado na declaração de classe\).|  
|[BEGIN\_DISPATCH\_MAP](../Topic/BEGIN_DISPATCH_MAP.md)|Inicia a definição de um mapa de distribuição.|  
|[END\_DISPATCH\_MAP](../Topic/END_DISPATCH_MAP.md)|Termina a definição de um mapa de distribuição.|  
|[DISP\_FUNCTION](../Topic/DISP_FUNCTION.md)|Usado em um mapa de distribuição para definir uma função de automação OLE.|  
|[DISP\_PROPERTY](../Topic/DISP_PROPERTY.md)|Define uma propriedade de automação OLE.|  
|[DISP\_PROPERTY\_EX](../Topic/DISP_PROPERTY_EX.md)|Define uma propriedade de automação OLE e obter os nomes e as funções de conjunto.|  
|[DISP\_PROPERTY\_NOTIFY](../Topic/DISP_PROPERTY_NOTIFY.md)|Define uma propriedade de automação OLE com notificação.|  
|[DISP\_PROPERTY\_PARAM](../Topic/DISP_PROPERTY_PARAM.md)|Define uma propriedade de automação OLE que usa parâmetros e nomeie obter e as funções de conjunto.|  
|[DISP\_DEFVALUE](../Topic/DISP_DEFVALUE.md)|Torna uma propriedade existente o valor padrão de um objeto.|  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)