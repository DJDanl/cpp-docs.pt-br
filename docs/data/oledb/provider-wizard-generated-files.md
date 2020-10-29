---
title: Arquivos gerados pelo Assistente do Provedor
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB providers, wizard-generated files
ms.assetid: 6e1ac94b-eb90-4abf-82b3-06944b947ebc
ms.openlocfilehash: 3bc680e5999c077dda384823ec4f67d2456af284
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924318"
---
# <a name="provider-wizard-generated-files"></a>Arquivos gerados pelo Assistente do Provedor

::: moniker range="msvc-160"

O assistente de Provedor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores.

::: moniker-end

::: moniker range="<=msvc-150"

O **Assistente de Provedor ATL OLE DB** gera os arquivos a seguir. Os tópicos a seguir usam o nome curto *Personalizado* , mas os nomes de arquivo exatos dependem da escolha feita ao criar o provedor.

|Nome do arquivo|Descrição|
|---------------|-----------------|
|*Personalizado* RS.cpp|Contém o método `Execute` do auxiliar de comando e o mapa de coluna do provedor.|
|*Personalizado* DS.h|Implementa o objeto da fonte de dados. Esse arquivo de cabeçalho contém o mapa de propriedade para as propriedades da fonte de dados.|
|*Personalizado* RS.h|Implementa os objetos de comando e conjunto de linhas. Esse arquivo de cabeçalho contém o mapa de propriedade para as propriedades do conjunto de linhas e de comando.|
|*Personalizado* Sess.h|Implementa o objeto de sessão. Esse arquivo de cabeçalho contém o mapa de propriedade para as propriedades da sessão.|
|*Personalizado* .rgs|Contém os objetos registrados gerados pelo **Assistente de Provedor OLE DB** .|

::: moniker-end

## <a name="see-also"></a>Veja também

[Criando um provedor de OLE DB](../../data/oledb/creating-an-ole-db-provider.md)<br/>
