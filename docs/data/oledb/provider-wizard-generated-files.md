---
title: Arquivos gerados pelo Assistente do provedor | Microsoft Docs
ms.custom: ''
ms.date: 10/18/2018
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
ms.openlocfilehash: f22c5e21d1f648a8235207713391306b24e0a6cf
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49807284"
---
# <a name="provider-wizard-generated-files"></a>Arquivos gerados pelo Assistente do Provedor

O ATL OLE DB Provider assistente gera os seguintes arquivos. Os tópicos a seguir usam o nome curto *personalizado*, mas os nomes de arquivo exatos dependem da escolha feita ao criar o provedor.  
  
|Nome do arquivo|Descrição|  
|---------------|-----------------|  
|*Personalizado*RS.cpp|Contém o auxiliar de comando `Execute` método e o mapa de coluna do provedor.|  
|*Personalizado*DS.h|Implementa o objeto de fonte de dados. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades da fonte de dados.|  
|*Personalizado*RS.h|Implementa os objetos de comando e o conjunto de linhas. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades de conjunto de linhas e de comando.|  
|*Personalizado*Sess.h|Implementa o objeto de sessão. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades de sessão.|  
|*Personalizado*. rgs|Contém os objetos registrados gerados pelo Assistente do provedor de banco de dados OLE.|  
  
## <a name="see-also"></a>Consulte também  

[Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)