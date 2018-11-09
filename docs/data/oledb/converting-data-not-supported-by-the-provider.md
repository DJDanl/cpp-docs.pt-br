---
title: Dados de conversão não suportados pelo provedor
ms.date: 10/29/2018
helpviewer_keywords:
- OLE DB provider templates, unsupported data types
ms.assetid: f495e50f-530a-4fab-ab54-e0c359785845
ms.openlocfilehash: 44cdde2bad24d21adbc728c90ecd173717c02b04
ms.sourcegitcommit: 943c792fdabf01c98c31465f23949a829eab9aad
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/07/2018
ms.locfileid: "51265185"
---
# <a name="converting-data-not-supported-by-the-provider"></a>Dados de conversão não suportados pelo provedor

Quando o consumidor solicita um tipo de dados que não é suportado pelo provedor, o modelo de provedor do OLE DB de código para `IRowsetImpl::GetData` chama Msdadc.dll para converter o tipo de dados.

Se você implementar uma interface como `IRowsetChange` que requer conversão de dados, você pode chamar Msdaenum.dll para fazer a conversão. Use `GetData`, definida em Atldb.h, como um exemplo.

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)