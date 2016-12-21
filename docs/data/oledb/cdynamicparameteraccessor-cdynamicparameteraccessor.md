---
title: "CDynamicParameterAccessor::CDynamicParameterAccessor | Microsoft Docs"
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
  - "CDynamicParameterAccessor::CDynamicParameterAccessor"
  - "CDynamicParameterAccessor.CDynamicParameterAccessor"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CDynamicParameterAccessor, construtor"
  - "Método CDynamicParameterAccessor"
ms.assetid: a1cce5e4-dfb9-43a2-bfb8-0435c653674a
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicParameterAccessor::CDynamicParameterAccessor
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O construtor.  
  
## Sintaxe  
  
```  
  
      typedef CDynamicParameterAccessor _ParamClass;  
CDynamicParameterAccessor(   
   DBBLOBHANDLINGENUM eBlobHandling = DBBLOBHANDLING_DEFAULT,   
   DBLENGTH nBlobSize = 8000 )   
   : CDynamicAccessor( eBlobHandling, nBlobSize )  
```  
  
#### Parâmetros  
 `eBlobHandling`  
 Especifica como os dados BLOB devem ser tratados.  O valor padrão é **DBBLOBHANDLING\_DEFAULT**.  Consulte [CDynamicAccessor::SetBlobHandling](../../data/oledb/cdynamicaccessor-setblobhandling.md) para obter uma descrição dos valores de **DBBLOBHANDLINGENUM** .  
  
 `nBlobSize`  
 O tamanho máximo do BLOB em bytes; os dados de coluna sobre esse valor é tratado como um BLOB.  O valor padrão é 8,000.  Consulte [CDynamicAccessor::SetBlobSizeLimit](../../data/oledb/cdynamicaccessor-setblobsizelimit.md) para obter detalhes.  
  
## Comentários  
 Consulte o construtor de [CDynamicAccessor::CDynamicAccessor](../Topic/CDynamicAccessor::CDynamicAccessor.md) para obter mais informações sobre a manipulação de BLOB.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)