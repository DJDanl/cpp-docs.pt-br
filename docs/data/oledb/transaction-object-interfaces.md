---
title: Interfaces de objeto da transação
ms.date: 10/24/2018
helpviewer_keywords:
- interfaces, OLE DB
- transaction object interfaces
- OLE DB, interfaces
- OLE DB providers, transaction support
- OLE DB provider templates, object interfaces
- interfaces, list of
ms.assetid: d2ce99ce-6f7a-4ff9-bc6e-acda3633d5c8
ms.openlocfilehash: 177f66222a054c3305418ffcd0acdda5c82ccf43
ms.sourcegitcommit: c40469825b6101baac87d43e5f4aed6df6b078f5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/12/2018
ms.locfileid: "51556173"
---
# <a name="transaction-object-interfaces"></a>Interfaces de objeto da transação

O objeto de transação define uma unidade atômica de trabalho em uma fonte de dados e determina como as unidades de trabalho se relacionam entre si. Esse objeto não é compatível diretamente pelos modelos de provedor do OLE DB (ou seja, você deverá criar seu próprio objeto).

A tabela a seguir mostra as interfaces obrigatórias e opcionais definidas por OLE DB para um objeto de transação.

|Interface|Necessário?|Implementado por modelos OLE DB?|
|---------------|---------------|--------------------------------------|
|[IConnectionPointContainer](/windows/desktop/api/ocidl/nn-ocidl-iconnectionpointcontainer)|Obrigatório|Não|
|[ITransaction](https://docs.microsoft.com/previous-versions/windows/desktop/ms723053(v=vs.85))|Obrigatório|Não|
|[ISupportErrorInfo](https://docs.microsoft.com/previous-versions/windows/desktop/ms715816(v=vs.85))|Opcional|Não|

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
