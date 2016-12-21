---
title: "Interfaces de objeto da sess&#227;o | Microsoft Docs"
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
  - "interfaces, objeto de sessão"
  - "modelos de provedor do OLE DB, Interfaces de objeto"
  - "objetos de sessão [OLE DB]"
  - "objetos de sessão [OLE DB], interfaces"
ms.assetid: ac01a958-6dde-4bd7-8b63-94459e488335
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Interfaces de objeto da sess&#227;o
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas pelo OLE DB para um objeto de sessão.  
  
|Interface|Obrigatório?|Implementado por modelos OLE DB?|  
|---------------|------------------|--------------------------------------|  
|[\<caps:sentence id\="tgt5" sentenceid\="84bd345ed51e4b9228da4eebd9ca3bd6" class\="tgtSentence"\>IGetDataSource\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms709721.aspx)|Obrigatório|Sim|  
|[\<caps:sentence id\="tgt8" sentenceid\="1857d9ee3f90b714f7d456a2712c0041" class\="tgtSentence"\>IOpenRowset\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms716946.aspx)|Obrigatório|Sim|  
|[\<caps:sentence id\="tgt11" sentenceid\="5a404cb65e2c2338db2e80978a9e67a2" class\="tgtSentence"\>ISessionProperties\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms713721.aspx)|Obrigatório|Sim|  
|[\<caps:sentence id\="tgt14" sentenceid\="713bcc50c078a14a6fb0a671b416510b" class\="tgtSentence"\>IAlterIndex\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms714943.aspx)|Opcional|Não|  
|[\<caps:sentence id\="tgt17" sentenceid\="24fbee76531423a4d09802565cd11362" class\="tgtSentence"\>IAlterTable\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms719764.aspx)|Opcional|Não|  
|[\<caps:sentence id\="tgt20" sentenceid\="b692103b1e1bfc19e7c5b54e42ba6f33" class\="tgtSentence"\>IBindResource\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms714936.aspx)|Opcional|Não|  
|[\<caps:sentence id\="tgt23" sentenceid\="437b598116cf64157b7c6f6d0ebe8095" class\="tgtSentence"\>ICreateRow\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms716832.aspx)|Opcional|Não|  
|[\<caps:sentence id\="tgt26" sentenceid\="336cdaf38e70da667eae9ab8a6d3c9ff" class\="tgtSentence"\>IDBCreateCommand\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms711625.aspx)|Opcional|Sim|  
|[\<caps:sentence id\="tgt29" sentenceid\="7cffd2da39279c8fb46f585db4ebcc91" class\="tgtSentence"\>IDBSchemaRowset\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms713686.aspx)|Opcional|Sim|  
|[\<caps:sentence id\="tgt32" sentenceid\="b8d3ac9198a7bc6dca13799dec75e132" class\="tgtSentence"\>IIndexDefinition\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms711593.aspx)|Opcional|Não|  
|[\<caps:sentence id\="tgt35" sentenceid\="130702210bcc45e1afd88b1f2aae1a0b" class\="tgtSentence"\>ISupportErrorInfo\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms715816.aspx)|Opcional|Sim|  
|[\<caps:sentence id\="tgt38" sentenceid\="9335c6109fea1ca1e5e74ee87ff58c45" class\="tgtSentence"\>ITableCreation\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms713639.aspx)|Opcional|Não|  
|[\<caps:sentence id\="tgt41" sentenceid\="568789fddb5a6849d3b1f59b42254292" class\="tgtSentence"\>ITableDefinition\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms714277.aspx)|Opcional|Não|  
|[\<caps:sentence id\="tgt44" sentenceid\="9a9807a7d8d31a6c0de805a5f28111d4" class\="tgtSentence"\>ITableDefinitionWithConstraints\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms720947.aspx)|Opcional|Não|  
|[\<caps:sentence id\="tgt47" sentenceid\="f5097e646bb93cceb560c38e13953a89" class\="tgtSentence"\>ITransaction\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms723053.aspx)|Opcional|Não|  
|[\<caps:sentence id\="tgt50" sentenceid\="160d543e4608ffb947e7e98bc94d2dd6" class\="tgtSentence"\>ITransactionJoin\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms718071.aspx)|Opcional|Não|  
|[\<caps:sentence id\="tgt53" sentenceid\="06c2b3c9bbd28371734b84bf68130381" class\="tgtSentence"\>ITransactionLocal\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms714893.aspx)|Opcional|Não|  
|[\<caps:sentence id\="tgt56" sentenceid\="3cf0b0ed75f511b15ab0f34f30e50a04" class\="tgtSentence"\>ITransactionObject\<\/caps:sentence\>](https://msdn.microsoft.com/en-us/library/ms713659.aspx)|Opcional|Não|  
  
 O objeto de sessão cria um objeto de conjunto de linhas.  Se o provedor oferecer suporte a comandos, a sessão também cria um objeto de comando \(`CCommand`, implementando OLE DB **TCommand**\).  O objeto de comando implementa a interface de `ICommand` e usa o método de `ICommand::Execute` para executar comandos no conjunto de linhas, conforme mostrado na figura a seguir.  
  
 ![Gráfico conceitual do provedor](../Image/vc4U551.gif "vc4U551")  
  
## Consulte também  
 [Arquitetura de modelo do provedor de banco de dados OLE](../../data/oledb/ole-db-provider-template-architecture.md)