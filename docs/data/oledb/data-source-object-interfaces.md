---
title: "Interfaces de objeto da fonte de dados | Microsoft Docs"
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
  - "objetos de fonte de dados [C++]"
  - "objetos de fonte de dados [C++], interfaces"
  - "interfaces [C++], lista de"
  - "interfaces [C++], OLE DB"
  - "OLE DB [C++], interfaces"
  - "Modelos de provedor OLE DB [C++], Interfaces de objeto"
ms.assetid: 929e100c-c08c-4b64-8437-d8d1357226f6
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interfaces de objeto da fonte de dados
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir mostra o obrigatório e as interfaces opcionais definidas pelo OLE DB para uma fonte de dados publicado.  
  
|Interface|Obrigatório?|Implementado por modelos OLE DB?|  
|---------------|------------------|--------------------------------------|  
|`IDBCreateSession`|Obrigatório|Sim|  
|`IDBInitialize`|Obrigatório|Sim|  
|`IDBProperties`|Obrigatório|Sim|  
|[\<caps:sentence id\="tgt14" sentenceid\="731a3344bc1c6b5f8f54d9de3524f18a" class\="tgtSentence"\>IPersist\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/ms688695)|Obrigatório|Sim|  
|[\<caps:sentence id\="tgt17" sentenceid\="63e99e63156fc90f114fa402662387ef" class\="tgtSentence"\>IConnectionPointContainer\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/ms683857)|Opcional|Não|  
|`IDBDataSourceAdmin`|Opcional|Não|  
|`IDBInfo`|Opcional|Não|  
|[\<caps:sentence id\="tgt26" sentenceid\="7e6a12ecd4cb3b1bd45dccf9421ed567" class\="tgtSentence"\>IPersistFile\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/ms687223)|Opcional|Não|  
|`ISupportErrorInfo`|Opcional|Não|  
  
 O objeto de fonte de dados implementa `IDBProperties`, `IDBInitialize`, e interfaces de `IDBCreateSession` com a herança.  Você pode escolher para dar suporte à funcionalidade adicional ou herdando não herdando de uma dessas classes de implementação.  Se você quiser oferecer suporte à interface de `IDBDataSourceAdmin` , você deve herdar da classe de `IDBDataSourceAdminImpl` .  
  
## Consulte também  
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)