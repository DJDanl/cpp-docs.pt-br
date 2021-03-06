---
title: Interfaces de objeto da sessão
ms.date: 11/19/2018
helpviewer_keywords:
- session objects [OLE DB]
- session objects [OLE DB], interfaces
- OLE DB provider templates, object interfaces
- interfaces, session object
- interfaces, list of
ms.assetid: ac01a958-6dde-4bd7-8b63-94459e488335
ms.openlocfilehash: 2fb91365fec0709e1bb2a26afa519e6565862681
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62404567"
---
# <a name="session-object-interfaces"></a>Interfaces de objeto da sessão

A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de sessão.

|Interface|Necessário?|Implementado por modelos OLE DB?|
|---------------|---------------|--------------------------------------|
|[IGetDataSource](/previous-versions/windows/desktop/ms709721(v=vs.85))|Obrigatório|Sim|
|[IOpenRowset](/previous-versions/windows/desktop/ms716946(v=vs.85))|Obrigatório|Sim|
|[ISessionProperties](/previous-versions/windows/desktop/ms713721(v=vs.85))|Obrigatório|Sim|
|[IAlterIndex](/previous-versions/windows/desktop/ms714943(v=vs.85))|Opcional|Não|
|[IAlterTable](/previous-versions/windows/desktop/ms719764(v=vs.85))|Opcional|Não|
|[IBindResource](/previous-versions/windows/desktop/ms714936(v=vs.85))|Opcional|Não|
|[ICreateRow](/previous-versions/windows/desktop/ms716832(v=vs.85))|Opcional|Não|
|[IDBCreateCommand](/previous-versions/windows/desktop/ms711625(v=vs.85))|Opcional|Sim|
|[IDBSchemaRowset](/previous-versions/windows/desktop/ms713686(v=vs.85))|Opcional|Sim|
|[IIndexDefinition](/previous-versions/windows/desktop/ms711593(v=vs.85))|Opcional|Não|
|[ISupportErrorInfo](/previous-versions/windows/desktop/ms715816(v=vs.85))|Opcional|Sim|
|[ITableCreation](/previous-versions/windows/desktop/ms713639(v=vs.85))|Opcional|Não|
|[ITableDefinition](/previous-versions/windows/desktop/ms714277(v=vs.85))|Opcional|Não|
|[ITableDefinitionWithConstraints](/previous-versions/windows/desktop/ms720947(v=vs.85))|Opcional|Não|
|[ITransaction](/previous-versions/windows/desktop/ms723053(v=vs.85))|Opcional|Não|
|[ITransactionJoin](/previous-versions/windows/desktop/ms718071(v=vs.85))|Opcional|Não|
|[ITransactionLocal](/previous-versions/windows/desktop/ms714893(v=vs.85))|Opcional|Não|
|[ITransactionObject](/previous-versions/windows/desktop/ms713659(v=vs.85))|Opcional|Não|

O objeto de sessão cria um objeto de conjunto de linhas. Se o provedor oferece suporte a comandos, a sessão também cria um objeto de comando (`CCommand`, a implementação do OLE DB `TCommand`). O objeto de comando implementa a `ICommand` interface e usa o `ICommand::Execute` método para executar comandos no conjunto de linhas, conforme mostrado na figura a seguir.

![Diagrama conceitual do provedor](../../data/oledb/media/vc4u551.gif "diagrama conceitual do provedor")

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
