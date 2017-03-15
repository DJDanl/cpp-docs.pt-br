---
title: "CDynamicAccessor::SetBlobHandling | Microsoft Docs"
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
  - "CDynamicAccessor::SetBlobHandling"
  - "CDynamicAccessor.SetBlobHandling"
  - "ATL::CDynamicAccessor::SetBlobHandling"
  - "SetBlobHandling"
  - "ATL.CDynamicAccessor.SetBlobHandling"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetBlobHandling"
ms.assetid: fa8b0bb3-a21b-4d64-aeef-e79bf61d079c
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicAccessor::SetBlobHandling
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o valor de manipulação de BLOB para a linha atual.  
  
## Sintaxe  
  
```  
  
      bool SetBlobHandling(  
   DBBLOBHANDLINGENUM eBlobHandling   
);  
```  
  
#### Parâmetros  
 `eBlobHandling`  
 Especifica como os dados BLOB devem ser tratados.  Pode ter os seguintes valores:  
  
-   **DBBLOBHANDLING\_DEFAULT**: Controlar os dados de coluna maiores que `nBlobSize` \(conforme definido por `SetBlobSizeLimit`\) como fazer com dados BLOB e por meio de um objeto de `ISequentialStream` ou de `IStream` .  Essa opção tentará associar cada coluna que contém os dados maiores que `nBlobSize` ou listados como **DBTYPE\_IUNKNOWN** como dados BLOB.  
  
-   **DBBLOBHANDLING\_NOSTREAMS**: Controlar os dados de coluna maiores que `nBlobSize` \(conforme definido por `SetBlobSizeLimit`\) como dados BLOB e fazer com a referência na memória alocada, provedor de propriedade do consumidor.  Essa opção é útil para tabelas com mais de uma coluna de BLOB, e o provedor oferecer suporte apenas a um objeto de `ISequentialStream` pelo acessador.  
  
-   **DBBLOBHANDLING\_SKIP**: Ignore \(não\) faz o associar as colunas qualificada como contendo de blobs \(o acessador não associará nem recupera o valor da coluna mas ainda recupera o status e o comprimento da coluna\).  
  
## Comentários  
 Você deve chamar `SetBlobHandling` antes de chamar **Abrir**.  
  
 O método [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) de construtor define o valor de manipulação de BLOB a **DBBLOBHANDLING\_DEFAULT**.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)