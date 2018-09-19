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
ms.openlocfilehash: fa9fed1f7c779efc7104ec8138d618b85aeb2a33
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46081735"
---
# <a name="converting-data-not-supported-by-the-provider"></a>Dados de conversão não suportados pelo provedor

Quando o consumidor solicita um tipo de dados que não é suportado pelo provedor, o modelo de provedor do OLE DB de código para `IRowsetImpl::GetData` chama Msdadc.dll para converter o tipo de dados.  
  
Se você implementar uma interface como `IRowsetChange` que requer conversão de dados, você pode chamar Msdaenum.dll para fazer a conversão. Use `GetData`, definida em Atldb.h, como um exemplo.  
  
## <a name="see-also"></a>Consulte também  

[Trabalhando com modelos de provedor do OLE DB](../../data/oledb/working-with-ole-db-provider-templates.md)