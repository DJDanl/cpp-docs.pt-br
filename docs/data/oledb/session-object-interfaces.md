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
ms.openlocfilehash: 8208a372989fac5fa7c7b0c13b83eb27a4d1444b
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42572028"
---
# <a name="session-object-interfaces"></a>Interfaces de objeto da sessão
A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de sessão.  
  
|Interface|Necessário?|Implementado por modelos OLE DB?|  
|---------------|---------------|--------------------------------------|  
|[IGetDataSource](/previous-versions/windows/desktop/ms709721\(v=vs.85\))|Obrigatório|Sim|  
|[IOpenRowset](/previous-versions/windows/desktop/ms716946\(v=vs.85\))|Obrigatório|Sim|  
|[ISessionProperties](/previous-versions/windows/desktop/ms713721\(v=vs.85\))|Obrigatório|Sim|  
|[IAlterIndex](/previous-versions/windows/desktop/ms714943\(v=vs.85\))|Opcional|Não|  
|[IAlterTable](/previous-versions/windows/desktop/ms719764\(v=vs.85\))|Opcional|Não|  
|[IBindResource](/previous-versions/windows/desktop/ms714936\(v=vs.85\))|Opcional|Não|  
|[ICreateRow](/previous-versions/windows/desktop/ms716832\(v=vs.85\))|Opcional|Não|  
|[IDBCreateCommand](/previous-versions/windows/desktop/ms711625\(v=vs.85\))|Opcional|Sim|  
|[IDBSchemaRowset](/previous-versions/windows/desktop/ms713686\(v=vs.85\))|Opcional|Sim|  
|[IIndexDefinition](/previous-versions/windows/desktop/ms711593\(v=vs.85\))|Opcional|Não|  
|[ISupportErrorInfo](/previous-versions/windows/desktop/ms715816\(v=vs.85\))|Opcional|Sim|  
|[ITableCreation](/previous-versions/windows/desktop/ms713639\(v=vs.85\))|Opcional|Não|  
|[ITableDefinition](/previous-versions/windows/desktop/ms714277\(v=vs.85\))|Opcional|Não|  
|[ITableDefinitionWithConstraints](/previous-versions/windows/desktop/ms720947\(v=vs.85\))|Opcional|Não|  
|[ITransaction](/previous-versions/windows/desktop/ms723053\(v=vs.85\))|Opcional|Não|  
|[ITransactionJoin](/previous-versions/windows/desktop/ms718071\(v=vs.85\))|Opcional|Não|  
|[ITransactionLocal](/previous-versions/windows/desktop/ms714893\(v=vs.85\))|Opcional|Não|  
|[ITransactionObject](/previous-versions/windows/desktop/ms713659\(v=vs.85\))|Opcional|Não|  
  
 O objeto de sessão cria um objeto de conjunto de linhas. Se o provedor oferece suporte a comandos, a sessão também cria um objeto de comando (`CCommand`, a implementação do OLE DB `TCommand`). O objeto de comando implementa a `ICommand` interface e usa o `ICommand::Execute` método para executar comandos no conjunto de linhas, conforme mostrado na figura a seguir.  
  
 ![Diagrama conceitual do provedor](../../data/oledb/media/vc4u551.gif "vc4u551")  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)