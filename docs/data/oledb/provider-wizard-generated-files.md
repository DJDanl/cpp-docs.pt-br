---
title: Arquivos gerados pelo Assistente do Provedor
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB providers, wizard-generated files
ms.assetid: 6e1ac94b-eb90-4abf-82b3-06944b947ebc
ms.openlocfilehash: de5c9056402cb1db25240772eb3c592523daafae
ms.sourcegitcommit: 00e26915924869cd7eb3c971a7d0604388abd316
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2019
ms.locfileid: "65525331"
---
# <a name="provider-wizard-generated-files"></a>Arquivos gerados pelo Assistente do Provedor

::: moniker range="vs-2019"

O assistente de Provedor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores.

::: moniker-end

::: moniker range="vs-2017"

O **Assistente de Provedor ATL OLE DB** gera os arquivos a seguir. Os tópicos a seguir usam o nome curto *Personalizado*, mas os nomes de arquivo exatos dependem da escolha feita ao criar o provedor.

|Nome do arquivo|Descrição|
|---------------|-----------------|
|*Personalizado*RS.cpp|Contém o método `Execute` do auxiliar de comando e o mapa de coluna do provedor.|
|*Personalizado*DS.h|Implementa o objeto da fonte de dados. Esse arquivo de cabeçalho contém o mapa de propriedade para as propriedades da fonte de dados.|
|*Personalizado*RS.h|Implementa os objetos de comando e conjunto de linhas. Esse arquivo de cabeçalho contém o mapa de propriedade para as propriedades do conjunto de linhas e de comando.|
|*Personalizado*Sess.h|Implementa o objeto de sessão. Esse arquivo de cabeçalho contém o mapa de propriedade para as propriedades da sessão.|
|*Personalizado*.rgs|Contém os objetos registrados gerados pelo **Assistente de Provedor OLE DB**.|

::: moniker-end

## <a name="see-also"></a>Consulte também

[Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)<br/>
