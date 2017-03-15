---
title: "Interfaces de objeto da transa&#231;&#227;o | Microsoft Docs"
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
  - "interfaces, lista de"
  - "interfaces, OLE DB"
  - "modelos de provedor do OLE DB, Interfaces de objeto"
  - "Provedores OLE DB, suporte a transações"
  - "OLE DB, interfaces"
  - "interfaces de objeto da transação"
ms.assetid: d2ce99ce-6f7a-4ff9-bc6e-acda3633d5c8
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interfaces de objeto da transa&#231;&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O objeto de transação define uma unidade atômica de trabalho em uma fonte de dados e determina como as unidades de trabalho relacionam\-se entre si.  Esse objeto não tem suporte diretamente pelos modelos do provedor OLE DB \(isto é, você deve criar seu próprio objeto\).  
  
 A tabela a seguir mostra o obrigatório e as interfaces opcionais definidas pelo OLE DB para uma transação objeto.  
  
|Interface|Obrigatório?|Implementado por modelos OLE DB?|  
|---------------|------------------|--------------------------------------|  
|[\<caps:sentence id\="tgt7" sentenceid\="63e99e63156fc90f114fa402662387ef" class\="tgtSentence"\>IConnectionPointContainer\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/ms683857)|Obrigatório|Não|  
|[\<caps:sentence id\="tgt10" sentenceid\="f5097e646bb93cceb560c38e13953a89" class\="tgtSentence"\>ITransaction\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms723053.aspx)|Obrigatório|Não|  
|[\<caps:sentence id\="tgt13" sentenceid\="130702210bcc45e1afd88b1f2aae1a0b" class\="tgtSentence"\>ISupportErrorInfo\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms715816.aspx)|Opcional|Não|  
  
## Consulte também  
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)