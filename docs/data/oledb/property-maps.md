---
title: Mapas de propriedade
ms.date: 10/24/2018
helpviewer_keywords:
- OLE DB providers, properties
- maps, property
- property maps
ms.assetid: 44abde56-90ad-4612-854e-d2fa5426fa80
ms.openlocfilehash: 79a65290c24ab016d9f81b54b9b7720d5c4ff352
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "70311781"
---
# <a name="property-maps"></a>Mapas de propriedade

Com a sessão, o conjunto de linhas e o objeto de comando opcional, cada provedor dá suporte a uma ou mais propriedades. Essas propriedades são definidas em mapas de propriedades armazenados nos arquivos de cabeçalho criados pelo **Assistente de provedor de OLE DB**. Cada arquivo de cabeçalho contém um mapa para as propriedades no grupo de propriedades OLE DB definido para o objeto ou objetos definidos nesse arquivo. O arquivo de cabeçalho que contém o objeto de fonte de dados também contém o mapa de propriedades para as [propriedades DataSource](/previous-versions/windows/desktop/ms724188(v=vs.85)). `Session.h`contém o mapa de propriedades para as [Propriedades da sessão](/previous-versions/windows/desktop/ms714221(v=vs.85)). O conjunto de linhas e os objetos de comando estão em um único arquivo de cabeçalho, chamado *ProjectName*RS. h. Essas propriedades são membros do grupo de [Propriedades do conjunto de linhas](/previous-versions/windows/desktop/ms711252(v=vs.85)) .

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
