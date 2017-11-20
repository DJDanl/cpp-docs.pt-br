---
title: "Interfaces de objeto de sessão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- session objects [OLE DB]
- session objects [OLE DB], interfaces
- OLE DB provider templates, object interfaces
- interfaces, session object
- interfaces, list of
ms.assetid: ac01a958-6dde-4bd7-8b63-94459e488335
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 2748756a4355b8f0befcf1287f8f30f6ece8ef84
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="session-object-interfaces"></a>Interfaces de objeto da sessão
A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de sessão.  
  
|Interface|Necessário?|Implementado por modelos OLE DB?|  
|---------------|---------------|--------------------------------------|  
|[IGetDataSource](https://msdn.microsoft.com/en-us/library/ms709721.aspx)|Obrigatório|Sim|  
|[IOpenRowset](https://msdn.microsoft.com/en-us/library/ms716946.aspx)|Obrigatório|Sim|  
|[ISessionProperties](https://msdn.microsoft.com/en-us/library/ms713721.aspx)|Obrigatório|Sim|  
|[IAlterIndex](https://msdn.microsoft.com/en-us/library/ms714943.aspx)|Opcional|Não|  
|[IAlterTable](https://msdn.microsoft.com/en-us/library/ms719764.aspx)|Opcional|Não|  
|[IBindResource](https://msdn.microsoft.com/en-us/library/ms714936.aspx)|Opcional|Não|  
|[ICreateRow](https://msdn.microsoft.com/en-us/library/ms716832.aspx)|Opcional|Não|  
|[IDBCreateCommand](https://msdn.microsoft.com/en-us/library/ms711625.aspx)|Opcional|Sim|  
|[IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx)|Opcional|Sim|  
|[IIndexDefinition](https://msdn.microsoft.com/en-us/library/ms711593.aspx)|Opcional|Não|  
|[ISupportErrorInfo](https://msdn.microsoft.com/en-us/library/ms715816.aspx)|Opcional|Sim|  
|[ITableCreation](https://msdn.microsoft.com/en-us/library/ms713639.aspx)|Opcional|Não|  
|[ITableDefinition](https://msdn.microsoft.com/en-us/library/ms714277.aspx)|Opcional|Não|  
|[ITableDefinitionWithConstraints](https://msdn.microsoft.com/en-us/library/ms720947.aspx)|Opcional|Não|  
|[ITransaction](https://msdn.microsoft.com/en-us/library/ms723053.aspx)|Opcional|Não|  
|[ITransactionJoin](https://msdn.microsoft.com/en-us/library/ms718071.aspx)|Opcional|Não|  
|[ITransactionLocal](https://msdn.microsoft.com/en-us/library/ms714893.aspx)|Opcional|Não|  
|[ITransactionObject](https://msdn.microsoft.com/en-us/library/ms713659.aspx)|Opcional|Não|  
  
 O objeto de sessão cria um objeto de conjunto de linhas. Se o provedor oferece suporte a comandos, a sessão também cria um objeto de comando (`CCommand`, Implementando OLE DB **TCommand**). O objeto de comando implementa o `ICommand` interface e usa o `ICommand::Execute` método para executar comandos no conjunto de linhas, conforme mostrado na figura a seguir.  
  
 ![Diagrama conceitual do provedor](../../data/oledb/media/vc4u551.gif "vc4u551")  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)