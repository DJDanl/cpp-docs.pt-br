---
title: Dados de conversão não suportados pelo provedor
ms.date: 11/04/2016
helpviewer_keywords:
- OLE DB provider templates, unsupported data types
ms.assetid: f495e50f-530a-4fab-ab54-e0c359785845
ms.openlocfilehash: a53781f71a55dfb07dc996e5e25644d9337e4c63
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50473431"
---
# <a name="converting-data-not-supported-by-the-provider"></a>Dados de conversão não suportados pelo provedor

Quando o consumidor solicita um tipo de dados que não é suportado pelo provedor, o modelo de provedor do OLE DB de código para `IRowsetImpl::GetData` chama Msdadc.dll para converter o tipo de dados.

Se você implementar uma interface como `IRowsetChange` que requer conversão de dados, você pode chamar Msdaenum.dll para fazer a conversão. Use `GetData`, definida em Atldb.h, como um exemplo.

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)