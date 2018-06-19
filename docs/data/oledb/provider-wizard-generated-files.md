---
title: Arquivos gerados pelo assistente provedor | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, wizard-generated files
ms.assetid: 6e1ac94b-eb90-4abf-82b3-06944b947ebc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: ac23f06bf1ae697ecd627d493aa5902219488138
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33106002"
---
# <a name="provider-wizard-generated-files"></a>Arquivos gerados pelo Assistente do Provedor
O OLE DB Provider assistente ATL gera os seguintes arquivos. Os tópicos a seguir usam o nome curto "MyProvider", mas os nomes de arquivo exatos dependem da escolha feita ao criar o provedor.  
  
|Nome do arquivo|Descrição|  
|---------------|-----------------|  
|MyProviderRS.cpp|Contém o auxiliar do comando `Execute` método e o mapa de coluna do provedor.|  
|MyProviderDS.h|Implementa o objeto de fonte de dados. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades de fonte de dados.|  
|MyProviderRS.h|Implementa os objetos de comando e o conjunto de linhas. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades de conjunto de linhas e comando.|  
|MyProviderSess.h|Implementa o objeto de sessão. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades de sessão.|  
|MyProvider.rgs|Contém os objetos registrados gerados pelo Assistente do provedor de banco de dados OLE.|  
  
## <a name="see-also"></a>Consulte também  
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)