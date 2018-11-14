---
title: Interfaces de objeto da sessão
ms.date: 10/24/2018
helpviewer_keywords:
- session objects [OLE DB]
- session objects [OLE DB], interfaces
- OLE DB provider templates, object interfaces
- interfaces, session object
- interfaces, list of
ms.assetid: ac01a958-6dde-4bd7-8b63-94459e488335
ms.openlocfilehash: 6b4748b804572c72b75f63b8ea2473818bdac989
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556615"
---
# <a name="session-object-interfaces"></a>Interfaces de objeto da sessão

A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de sessão.

|Interface|Necessário?|Implementado por modelos OLE DB?|
|---------------|---------------|--------------------------------------|
|[IGetDataSource](https://docs.microsoft.com/previous-versions/windows/desktop/ms709721(v=vs.85))|Obrigatório|Sim|
|[IOpenRowset](https://docs.microsoft.com/previous-versions/windows/desktop/ms716946(v=vs.85))|Obrigatório|Sim|
|[ISessionProperties](https://docs.microsoft.com/previous-versions/windows/desktop/ms713721(v=vs.85))|Obrigatório|Sim|
|[IAlterIndex](https://docs.microsoft.com/previous-versions/windows/desktop/ms714943(v=vs.85))|Opcional|Não|
|[IAlterTable](https://docs.microsoft.com/previous-versions/windows/desktop/ms719764(v=vs.85))|Opcional|Não|
|[IBindResource](https://docs.microsoft.com/previous-versions/windows/desktop/ms714936(v=vs.85))|Opcional|Não|
|[ICreateRow](https://docs.microsoft.com/previous-versions/windows/desktop/ms716832(v=vs.85))|Opcional|Não|
|[IDBCreateCommand](https://docs.microsoft.com/previous-versions/windows/desktop/ms711625(v=vs.85))|Opcional|Sim|
|[IDBSchemaRowset](https://docs.microsoft.com/previous-versions/windows/desktop/ms713686(v=vs.85))|Opcional|Sim|
|[IIndexDefinition](https://docs.microsoft.com/previous-versions/windows/desktop/ms711593(v=vs.85))|Opcional|Não|
|[ISupportErrorInfo](https://docs.microsoft.com/previous-versions/windows/desktop/ms715816(v=vs.85))|Opcional|Sim|
|[ITableCreation](https://docs.microsoft.com/previous-versions/windows/desktop/ms713639(v=vs.85))|Opcional|Não|
|[ITableDefinition](https://docs.microsoft.com/previous-versions/windows/desktop/ms714277(v=vs.85))|Opcional|Não|
|[ITableDefinitionWithConstraints](https://docs.microsoft.com/previous-versions/windows/desktop/ms720947(v=vs.85))|Opcional|Não|
|[ITransaction](https://docs.microsoft.com/previous-versions/windows/desktop/ms723053(v=vs.85))|Opcional|Não|
|[ITransactionJoin](https://docs.microsoft.com/previous-versions/windows/desktop/ms718071(v=vs.85))|Opcional|Não|
|[ITransactionLocal](https://docs.microsoft.com/previous-versions/windows/desktop/ms714893(v=vs.85))|Opcional|Não|
|[ITransactionObject](https://docs.microsoft.com/previous-versions/windows/desktop/ms713659(v=vs.85))|Opcional|Não|

O objeto de sessão cria um objeto de conjunto de linhas. Se o provedor oferece suporte a comandos, a sessão também cria um objeto de comando (`CCommand`, a implementação do OLE DB `TCommand`). O objeto de comando implementa a `ICommand` interface e usa o `ICommand::Execute` método para executar comandos no conjunto de linhas, conforme mostrado na figura a seguir.

![Diagrama conceitual do provedor](../../data/oledb/media/vc4u551.gif "vc4u551")

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
