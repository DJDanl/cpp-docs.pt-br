---
title: Interfaces de objeto de sessão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- session objects [OLE DB]
- session objects [OLE DB], interfaces
- OLE DB provider templates, object interfaces
- interfaces, session object
- interfaces, list of
ms.assetid: ac01a958-6dde-4bd7-8b63-94459e488335
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0b88a2b04862743839b3cd438b31506c8aea0883
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50079905"
---
# <a name="session-object-interfaces"></a>Interfaces de objeto da sessão

A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de sessão.

|Interface|Necessário?|Implementado por modelos OLE DB?|
|---------------|---------------|--------------------------------------|
|[IGetDataSource](/previous-versions/windows/desktop/ms709721)|Obrigatório|Sim|
|[IOpenRowset](/previous-versions/windows/desktop/ms716946)|Obrigatório|Sim|
|[ISessionProperties](/previous-versions/windows/desktop/ms713721)|Obrigatório|Sim|
|[IAlterIndex](/previous-versions/windows/desktop/ms714943)|Opcional|Não|
|[IAlterTable](/previous-versions/windows/desktop/ms719764)|Opcional|Não|
|[IBindResource](/previous-versions/windows/desktop/ms714936)|Opcional|Não|
|[ICreateRow](/previous-versions/windows/desktop/ms716832)|Opcional|Não|
|[IDBCreateCommand](/previous-versions/windows/desktop/ms711625)|Opcional|Sim|
|[IDBSchemaRowset](/previous-versions/windows/desktop/ms713686)|Opcional|Sim|
|[IIndexDefinition](/previous-versions/windows/desktop/ms711593)|Opcional|Não|
|[ISupportErrorInfo](/previous-versions/windows/desktop/ms715816)|Opcional|Sim|
|[ITableCreation](/previous-versions/windows/desktop/ms713639)|Opcional|Não|
|[ITableDefinition](/previous-versions/windows/desktop/ms714277)|Opcional|Não|
|[ITableDefinitionWithConstraints](/previous-versions/windows/desktop/ms720947)|Opcional|Não|
|[ITransaction](/previous-versions/windows/desktop/ms723053)|Opcional|Não|
|[ITransactionJoin](/previous-versions/windows/desktop/ms718071)|Opcional|Não|
|[ITransactionLocal](/previous-versions/windows/desktop/ms714893)|Opcional|Não|
|[ITransactionObject](/previous-versions/windows/desktop/ms713659)|Opcional|Não|

O objeto de sessão cria um objeto de conjunto de linhas. Se o provedor oferece suporte a comandos, a sessão também cria um objeto de comando (`CCommand`, a implementação do OLE DB `TCommand`). O objeto de comando implementa a `ICommand` interface e usa o `ICommand::Execute` método para executar comandos no conjunto de linhas, conforme mostrado na figura a seguir.

![Diagrama conceitual do provedor](../../data/oledb/media/vc4u551.gif "vc4u551")

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)