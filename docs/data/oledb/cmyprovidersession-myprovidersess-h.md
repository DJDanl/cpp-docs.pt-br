---
title: "CMyProviderSession (MyProviderSess.H) | Microsoft Docs"
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
  - "cmyprovidersession"
  - ""myprovidersess.h""
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe CMyProviderSession em MyProviderSess.H"
  - "Provedores OLE DB, arquivos gerados por assistente"
ms.assetid: d37ad471-cf05-49c5-aa47-cd10824d777f
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# CMyProviderSession (MyProviderSess.H)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

MyProviderSess.H contém a declaração e a implementação do objeto de sessão OLE DB.  O objeto de fonte de dados cria o objeto de sessão e representa uma conversa entre um consumidor e um provedor.  Várias sessões simultâneas podem ser abertas para uma fonte de dados.  A lista de herança para `CMyProviderSession` segue:  
  
```  
/////////////////////////////////////////////////////////////////////////  
// CMyProviderSession  
class ATL_NO_VTABLE CMyProviderSession :   
   public CComObjectRootEx<CComSingleThreadModel>,  
   public IGetDataSourceImpl<CMyProviderSession>,  
   public IOpenRowsetImpl<CMyProviderSession>,  
   public ISessionPropertiesImpl<CMyProviderSession>,  
   public IObjectWithSiteSessionImpl<CMyProviderSession>,  
   public IDBSchemaRowsetImpl<CMyProviderSession>,  
   public IDBCreateCommandImpl<CMyProviderSession, CMyProviderCommand>  
```  
  
 O objeto de sessão herda de **IGetDataSource**, de `IOpenRowset`, de **ISessionProperties**, e de **IDBCreateCommand**.  A interface de **IGetDataSource** permite que uma sessão recuperar a fonte de dados que a criou.  Isso será útil se você precisar obter as propriedades da fonte de dados que você criou ou de outras informações que a fonte de dados pode fornecer.  A interface de **ISessionProperties** trata todas as propriedades da sessão.  `IOpenRowset` e interfaces de **IDBCreateCommand** são usados para fazer o trabalho da base de dados.  Se o provedor oferecer suporte a comandos, implementa a interface de **IDBCreateCommand** .  É usado para criar o objeto de comando que pode executar comandos.  O provedor do implementa sempre o objeto de `IOpenRowset` .  É usado para gerar um conjunto de linhas simples de um provedor.  É um conjunto de linhas padrão \(por exemplo, `"select * from mytable"`\) de um provedor.  
  
 O assistente também gerencia três classes de sessão: `CMyProviderSessionColSchema`, `CMyProviderSessionPTSchema`, e `CMyProviderSessionTRSchema`.  Essas sessões são usadas para conjuntos de linhas de esquema.  Os conjuntos de linhas de esquema permitem que o provedor retorna metadados para o consumidor sem o consumidor que tiver que executar uma consulta ou buscar dados.  Buscar metadados pode ser muito mais rápido do que a descoberta de recursos provedores.  
  
 A especificação OLE DB requer que os provedores que implementam os tipos de conjunto de linhas de esquema da suporte a três da interface de **IDBSchemaRowset** : **DBSCHEMA\_COLUMNS**, **DBSCHEMA\_PROVIDER\_TYPES**, e `DBSCHEMA_TABLES`.  O assistente gerencia implementações para cada conjunto de linhas de esquema.  Cada classe gerada pelo assistente contém um método de `Execute` .  Neste método de `Execute` , você pode retornar dados ao provedor sobre quais tabelas, colunas, e tipos de dados que você tem suporte.  Esses dados são conhecidos normalmente em tempo de compilação.  
  
## Consulte também  
 [Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)