---
title: Interfaces de objeto de fonte de dados | Microsoft Docs
ms.custom: ''
ms.date: 10/24/2018
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
ms.openlocfilehash: d6b76dd8423abd18359081a8fc30050c23e0b161
ms.sourcegitcommit: 840033ddcfab51543072604ccd5656fc6d4a5d3a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2018
ms.locfileid: "50216273"
---
# <a name="data-source-object-interfaces"></a>Interfaces de objeto da fonte de dados

A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de fonte de dados.

|Interface|Necessário?|Implementado por modelos OLE DB?|
|---------------|---------------|--------------------------------------|
|`IDBCreateSession`|Obrigatório|Sim|
|`IDBInitialize`|Obrigatório|Sim|
|`IDBProperties`|Obrigatório|Sim|
|[IPersist](/windows/desktop/api/objidl/nn-objidl-ipersist)|Obrigatório|Sim|
|[IConnectionPointContainer](/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer)|Opcional|Não|
|`IDBDataSourceAdmin`|Opcional|Não|
|`IDBInfo`|Opcional|Não|
|[IPersistFile](/windows/desktop/api/objidl/nn-objidl-ipersistfile)|Opcional|Não|
|`ISupportErrorInfo`|Opcional|Não|

A fonte de dados objeto implementa a `IDBProperties`, `IDBInitialize`, e `IDBCreateSession` interfaces por meio da herança. Você pode escolher dar suporte à funcionalidade adicional por herdar ou não herdar de uma dessas classes de implementação. Se você quiser dar suporte a `IDBDataSourceAdmin` interface, você deve herdar o `IDBDataSourceAdminImpl` classe.

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
