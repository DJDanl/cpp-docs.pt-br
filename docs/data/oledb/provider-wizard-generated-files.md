---
title: Arquivos gerados pelo Assistente do provedor | Microsoft Docs
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
ms.openlocfilehash: 26e20e0417e2253158930a8d3d055171fe767001
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46108398"
---
# <a name="provider-wizard-generated-files"></a>Arquivos gerados pelo Assistente do Provedor

O ATL OLE DB Provider assistente gera os seguintes arquivos. Os tópicos a seguir usam o nome curto "MyProvider", mas os nomes de arquivo exatos dependem da escolha feita ao criar o provedor.  
  
|Nome do arquivo|Descrição|  
|---------------|-----------------|  
|MyProviderRS.cpp|Contém o auxiliar de comando `Execute` método e o mapa de coluna do provedor.|  
|MyProviderDS.h|Implementa o objeto de fonte de dados. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades da fonte de dados.|  
|MyProviderRS.h|Implementa os objetos de comando e o conjunto de linhas. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades de conjunto de linhas e de comando.|  
|MyProviderSess.h|Implementa o objeto de sessão. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades de sessão.|  
|MyProvider.rgs|Contém os objetos registrados gerados pelo Assistente do provedor de banco de dados OLE.|  
  
## <a name="see-also"></a>Consulte também  

[Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)