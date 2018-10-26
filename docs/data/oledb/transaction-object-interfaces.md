---
title: Interfaces de objeto de transação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- interfaces, OLE DB
- transaction object interfaces
- OLE DB, interfaces
- OLE DB providers, transaction support
- OLE DB provider templates, object interfaces
- interfaces, list of
ms.assetid: d2ce99ce-6f7a-4ff9-bc6e-acda3633d5c8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b8f03516aedcaf231f14943079eb9be40adf5be4
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50073117"
---
# <a name="transaction-object-interfaces"></a>Interfaces de objeto da transação

O objeto de transação define uma unidade atômica de trabalho em uma fonte de dados e determina como as unidades de trabalho se relacionam entre si. Esse objeto não é compatível diretamente pelos modelos de provedor do OLE DB (ou seja, você deverá criar seu próprio objeto).

A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de transação.

|Interface|Necessário?|Implementado por modelos OLE DB?|
|---------------|---------------|--------------------------------------|
|[IConnectionPointContainer](/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer)|Obrigatório|Não|
|[ITransaction](/previous-versions/windows/desktop/ms723053)|Obrigatório|Não|
|[ISupportErrorInfo](/previous-versions/windows/desktop/ms715816)|Opcional|Não|

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)