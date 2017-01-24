---
title: "CDynamicAccessor::SetBlobSizeLimit | Microsoft Docs"
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
  - "CDynamicAccessor::SetBlobSizeLimit"
  - "SetBlobSizeLimit"
  - "CDynamicAccessor.SetBlobSizeLimit"
  - "ATL.CDynamicAccessor.SetBlobSizeLimit"
  - "ATL::CDynamicAccessor::SetBlobSizeLimit"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Método SetBlobSizeLimit"
ms.assetid: fb8cb85d-f841-408e-a344-37895b10993f
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CDynamicAccessor::SetBlobSizeLimit
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define o tamanho máximo do BLOB em bytes.  
  
## Sintaxe  
  
```  
  
      void SetBlobSizeLimit(  
   DBLENGTH nBlobSize   
);  
```  
  
#### Parâmetros  
 `nBlobSize`  
 Especifica o limite de tamanho de BLOB.  
  
## Comentários  
 Define o tamanho máximo do BLOB em bytes; os dados de coluna maiores que esse valor é tratado como um BLOB.  Alguns provedores dão tamanhos muito grandes para colunas \(como 2 GB\).  Em vez de tentando alocar memória para uma coluna esse tamanho, você normalmente tentará associar essas colunas como blobs.  Dessa forma você não precisa alocar toda a memória, mas você ainda pode ler todos os dados sem medo de truncamento.  No entanto, há alguns casos em que talvez você queira forçar `CDynamicAccessor` para associar colunas em seus tipos de dados nativos.  Para fazer isso, chame `SetBlobSizeLimit` antes de chamar **Abrir**.  
  
 O método [CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md) de construtor define o tamanho máximo de BLOB para um valor padrão de 8.000 bytes.  
  
## Requisitos  
 **Header:** atldbcli.h  
  
## Consulte também  
 [Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)