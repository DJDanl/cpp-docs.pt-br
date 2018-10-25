---
title: Convertendo dados sem suporte pelo provedor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB provider templates, unsupported data types
ms.assetid: f495e50f-530a-4fab-ab54-e0c359785845
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 79889125675a3e544802eb700718dee0829457c5
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50066117"
---
# <a name="converting-data-not-supported-by-the-provider"></a>Dados de conversão não suportados pelo provedor

Quando o consumidor solicita um tipo de dados que não é suportado pelo provedor, o modelo de provedor do OLE DB de código para `IRowsetImpl::GetData` chama Msdadc.dll para converter o tipo de dados.

Se você implementar uma interface como `IRowsetChange` que requer conversão de dados, você pode chamar Msdaenum.dll para fazer a conversão. Use `GetData`, definida em Atldb.h, como um exemplo.

## <a name="see-also"></a>Consulte também

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)