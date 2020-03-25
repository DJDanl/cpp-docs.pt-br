---
title: Dados de conversão não suportados pelo provedor
ms.date: 10/29/2018
helpviewer_keywords:
- OLE DB provider templates, unsupported data types
ms.assetid: f495e50f-530a-4fab-ab54-e0c359785845
ms.openlocfilehash: e87aebc4d6f23343af9a2f966d2c522e95b304ea
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211491"
---
# <a name="converting-data-not-supported-by-the-provider"></a>Dados de conversão não suportados pelo provedor

Quando o consumidor solicita um tipo de dados que não é suportado pelo provedor, o código de modelo do provedor de OLE DB para `IRowsetImpl::GetData` chama Msdadc. dll para converter o tipo de dados.

Se você implementar uma interface como `IRowsetChange` que requer conversão de dados, poderá chamar Msdaenum. dll para fazer a conversão. Use `GetData`, definido em ATLDB. h, como um exemplo.

## <a name="see-also"></a>Confira também

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)
