---
title: Interfaces de objeto de fonte de dados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- data source objects [C++], interfaces
- data source objects [C++]
- interfaces [C++], OLE DB
- interfaces [C++], list of
- OLE DB provider templates [C++], object interfaces
- OLE DB [C++], interfaces
ms.assetid: 929e100c-c08c-4b64-8437-d8d1357226f6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 1c8aaed0a9f50e20dba5938b9b37425f4caa2bb1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="data-source-object-interfaces"></a>Interfaces de objeto da fonte de dados
A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de fonte de dados.  
  
|Interface|Necessário?|Implementado por modelos OLE DB?|  
|---------------|---------------|--------------------------------------|  
|`IDBCreateSession`|Obrigatório|Sim|  
|`IDBInitialize`|Obrigatório|Sim|  
|`IDBProperties`|Obrigatório|Sim|  
|[IPersist](http://msdn.microsoft.com/library/windows/desktop/ms688695)|Obrigatório|Sim|  
|[IConnectionPointContainer](http://msdn.microsoft.com/library/windows/desktop/ms683857)|Opcional|Não|  
|`IDBDataSourceAdmin`|Opcional|Não|  
|`IDBInfo`|Opcional|Não|  
|[IPersistFile](http://msdn.microsoft.com/library/windows/desktop/ms687223)|Opcional|Não|  
|`ISupportErrorInfo`|Opcional|Não|  
  
 A fonte de dados objeto implementa a `IDBProperties`, `IDBInitialize`, e `IDBCreateSession` interfaces por meio da herança. Você pode escolher dar suporte a funcionalidade adicional ao herdar ou não herdar de uma dessas classes de implementação. Se você desejar oferecer suporte a `IDBDataSourceAdmin` interface, você deve herdar do `IDBDataSourceAdminImpl` classe.  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)