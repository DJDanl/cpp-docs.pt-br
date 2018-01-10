---
title: CMyProviderSession (myprovidersess. H) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- cmyprovidersession
- myprovidersess.h
dev_langs: C++
helpviewer_keywords:
- CMyProviderSession class in MyProviderSess.H
- OLE DB providers, wizard-generated files
ms.assetid: d37ad471-cf05-49c5-aa47-cd10824d777f
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3cf8a75a416f03fed1ae7e0deb9118b3c40ea5fb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmyprovidersession-myprovidersessh"></a>CMyProviderSession (MyProviderSess.H)
Myprovidersess. H contém a declaração e a implementação para o objeto de sessão do OLE DB. O objeto de fonte de dados cria o objeto de sessão e representa uma conversa entre um provedor e consumidor. Várias sessões simultâneas podem ser abertas para uma fonte de dados. A lista de herança para `CMyProviderSession` segue:  
  
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
  
 O objeto de sessão herda de **IGetDataSource**, `IOpenRowset`, **ISessionProperties**, e **IDBCreateCommand**. O **IGetDataSource** interface permite que uma sessão recuperar a fonte de dados que o criou. Isso é útil se você precisar obter as propriedades da fonte de dados que você criou ou outras informações que a fonte de dados pode fornecer. O **ISessionProperties** interface trata todas as propriedades para a sessão. O `IOpenRowset` e **IDBCreateCommand** interfaces são usadas para fazer o trabalho de banco de dados. Se o provedor oferece suporte a comandos, ele implementa o **IDBCreateCommand** interface. Ele é usado para criar o objeto de comando que pode executar comandos. O provedor implementa sempre o `IOpenRowset` objeto. Ele é usado para gerar um conjunto de linhas simple de um provedor. É um conjunto de linhas padrão (por exemplo, `"select * from mytable"`) de um provedor.  
  
 O assistente também gera três classes de sessão: `CMyProviderSessionColSchema`, `CMyProviderSessionPTSchema`, e `CMyProviderSessionTRSchema`. Essas sessões são usadas para conjuntos de linhas de esquema. Conjuntos de linhas de esquema permitir que o provedor retornar os metadados para o consumidor sem o consumidor precisar executar uma consulta ou busca de dados. Busca de metadados pode ser muito mais rápido do que descobrir um recursos de provedores.  
  
 A especificação OLE DB requer que provedores de implementar o **IDBSchemaRowset** tipos de conjunto de linhas de esquema interface oferece suporte a três: **DBSCHEMA_COLUMNS**, **DBSCHEMA_PROVIDER_TYPES** , e `DBSCHEMA_TABLES`. O assistente gera implementações para cada conjunto de linhas de esquema. Cada classe gerada pelo assistente contém um `Execute` método. Neste `Execute` método, você pode retornar dados para o provedor sobre quais tabelas, colunas e tipos de dados que oferecem suporte. Esses dados normalmente são conhecidos no momento da compilação.  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)