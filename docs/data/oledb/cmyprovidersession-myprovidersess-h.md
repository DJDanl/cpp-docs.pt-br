---
title: CCustomSession (CustomSess.H)
ms.date: 10/22/2018
f1_keywords:
- cmyprovidersession
- myprovidersess.h
- ccustomsession
- customsess.h
helpviewer_keywords:
- CMyProviderSession class in MyProviderSess.H
- OLE DB providers, wizard-generated files
- CCustomSession class in CustomSess.H
ms.assetid: d37ad471-cf05-49c5-aa47-cd10824d777f
ms.openlocfilehash: 4775f21c1e0fa7666d24b4d6a55e099bc6ae55a2
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80079752"
---
# <a name="ccustomsession-customsessh"></a>CCustomSession (CustomSess.H)

*Personalizado* Sess. H contém a declaração e a implementação para o objeto de sessão OLE DB. O objeto de fonte de dados cria o objeto de sessão e representa uma conversa entre um consumidor e um provedor. Várias sessões simultâneas podem ser abertas para uma fonte de dados. A lista de herança para `CCustomSession` segue:

```cpp
/////////////////////////////////////////////////////////////////////////
// CCustomSession
class ATL_NO_VTABLE CCustomSession :
   public CComObjectRootEx<CComSingleThreadModel>,
   public IGetDataSourceImpl<CCustomSession>,
   public IOpenRowsetImpl<CCustomSession>,
   public ISessionPropertiesImpl<CCustomSession>,
   public IObjectWithSiteSessionImpl<CCustomSession>,
   public IDBSchemaRowsetImpl<CCustomSession>,
   public IDBCreateCommandImpl<CCustomSession, CCustomCommand>
```

O objeto de sessão é herdado de `IGetDataSource`, `IOpenRowset`, `ISessionProperties`e `IDBCreateCommand`. A interface `IGetDataSource` permite que uma sessão recupere a fonte de dados que a criou. Isso será útil se você precisar obter propriedades da fonte de dados que você criou ou outras informações que a fonte de dados pode fornecer. A interface `ISessionProperties` manipula todas as propriedades da sessão. As interfaces `IOpenRowset` e `IDBCreateCommand` são usadas para o trabalho do banco de dados. Se o provedor oferecer suporte a comandos, ele implementará a interface `IDBCreateCommand`. Ele é usado para criar o objeto de comando que pode executar comandos. O provedor sempre implementa o objeto `IOpenRowset`. Ele é usado para gerar um conjunto de linhas de um provedor. É um conjunto de linhas padrão (por exemplo, `"select * from mytable"`) de um provedor.

O assistente também gera três classes de sessão: `CCustomSessionColSchema`, `CCustomSessionPTSchema`e `CCustomSessionTRSchema`. Essas sessões são usadas para conjuntos de linhas de esquema. Os conjuntos de linhas de esquema permitem que o provedor retorne metadados para o consumidor sem que o consumidor precise executar uma consulta ou buscar dados. A busca de metadados pode ser muito mais rápida do que encontrar os recursos de um provedor.

A especificação de OLE DB requer que os provedores que implementam a interface `IDBSchemaRowset` ofereçam suporte a três tipos de conjunto de linhas de esquema: DBSCHEMA_COLUMNS, DBSCHEMA_PROVIDER_TYPES e DBSCHEMA_TABLES. O assistente gera implementações para cada conjunto de linhas de esquema. Cada classe gerada pelo assistente contém um método `Execute`. Nesse `Execute` método, você pode retornar dados para o provedor sobre a quais tipos de dados, colunas e tabelas são compatíveis. Esses dados são conhecidos no momento da compilação.

## <a name="see-also"></a>Confira também

[Arquivos gerados pelo Assistente do Provedor](../../data/oledb/provider-wizard-generated-files.md)<br/>
