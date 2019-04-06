---
title: Arquivos gerados pelo Assistente do Provedor
ms.date: 10/18/2018
helpviewer_keywords:
- OLE DB providers, wizard-generated files
ms.assetid: 6e1ac94b-eb90-4abf-82b3-06944b947ebc
ms.openlocfilehash: a9a706463326249135a55bc907cb8a664a3ca808
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59037085"
---
# <a name="provider-wizard-generated-files"></a>Arquivos gerados pelo Assistente do Provedor

O **ATL OLE DB Provider Wizard** gera os seguintes arquivos. Os tópicos a seguir usam o nome curto *personalizado*, mas os nomes de arquivo exatos dependem da escolha feita ao criar o provedor.

|Nome do arquivo|Descrição|
|---------------|-----------------|
|*Custom*RS.cpp|Contém o auxiliar de comando `Execute` método e o mapa de coluna do provedor.|
|*Custom*DS.h|Implementa o objeto de fonte de dados. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades da fonte de dados.|
|*Personalizado*RS.h|Implementa os objetos de comando e o conjunto de linhas. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades de conjunto de linhas e de comando.|
|*Personalizado*Sess.h|Implementa o objeto de sessão. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades de sessão.|
|*Personalizado*. rgs|Contém os objetos registrados gerados pelo **OLE DB Provider Wizard**.|

## <a name="see-also"></a>Consulte também

[Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)<br/>
