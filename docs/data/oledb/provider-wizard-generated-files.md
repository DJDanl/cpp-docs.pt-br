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
ms.openlocfilehash: a9bc7c85dccdfe095412450d5020fc8a6b42d516
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50076965"
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