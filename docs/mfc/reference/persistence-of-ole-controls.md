---
title: "Persist&#234;ncia de controles OLE | Microsoft Docs"
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
  - "vc.mfc.macros.ole"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Controles OLE, persistência"
  - "persistência, Controles OLE"
ms.assetid: 64f8dc80-f110-41af-b3ea-14948f6bfdf7
caps.latest.revision: 17
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Persist&#234;ncia de controles OLE
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Um recurso dos controladores OLE é a persistência da propriedade \(ou a serialização\), o que permite que o controlador OLE ler ou gravar valores de propriedade para e de um arquivo ou transmita.  Um aplicativo de contêiner pode usar serialização para armazenar os valores de propriedade de um controle mesmo depois que o aplicativo destruído o controle.  Os valores de propriedade do controlador OLE podem ser lidos do arquivo ou de fluxo quando uma nova instância do controle é criada posteriormente.  
  
### Persistência de controladores OLE  
  
|||  
|-|-|  
|[PX\_Blob](../Topic/PX_Blob.md)|Troca uma propriedade de controle que armazena dados \(BLOB\) de objeto binário grande.|  
|[PX\_Bool](../Topic/PX_Bool.md)|Troca uma propriedade do controle do tipo **BOOL**.|  
|[PX\_Color](../Topic/PX_Color.md)|Troca uma propriedade cor de um controle.|  
|[PX\_Currency](../Topic/PX_Currency.md)|Troca uma propriedade do controle do tipo **CY**.|  
|[PX\_DataPath](../Topic/PX_DataPath.md)|Troca uma propriedade do controle do tipo `CDataPathProperty`.|  
|[PX\_Double](../Topic/PX_Double.md)|Troca uma propriedade do controle do tipo **double**.|  
|[PX\_Font](../Topic/PX_Font.md)|Troca uma propriedade de fonte de um controle.|  
|[PX\_Float](../Topic/PX_Float.md)|Troca uma propriedade do controle do tipo **float**.|  
|[PX\_IUnknown](../Topic/PX_IUnknown.md)|Troca uma propriedade do controle de tipo indefinido.|  
|[PX\_Long](../Topic/PX_Long.md)|Troca uma propriedade do controle do tipo **long**.|  
|[PX\_Picture](../Topic/PX_Picture.md)|Troca uma propriedade de imagem de um controle.|  
|[PX\_Short](../Topic/PX_Short.md)|Troca uma propriedade do controle do tipo **short**.|  
|[PX\_ULong](../Topic/PX_ULong.md)|Troca uma propriedade do controle do tipo **ULONG**.|  
|[PX\_UShort](../Topic/PX_UShort.md)|Troca uma propriedade do controle do tipo **USHORT**.|  
|[PX\_String](../Topic/PX_String.md)|Troca uma propriedade do controle de cadeia de caracteres.|  
|[PX\_VBXFontConvert](../Topic/PX_VBXFontConvert.md)|Troca as propriedades relativas de um controle de VBX em uma propriedade de fonte do controlador OLE.|  
  
 Além disso, a função global de `AfxOleTypeMatchGuid` é fornecida para testar uma correspondência entre `TYPEDESC` e o GUID especificado.  
  
## Consulte também  
 [Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)