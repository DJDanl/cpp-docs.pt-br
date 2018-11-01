---
title: Mapas de propriedade
ms.date: 10/24/2018
helpviewer_keywords:
- OLE DB providers, properties
- maps, property
- property maps
ms.assetid: 44abde56-90ad-4612-854e-d2fa5426fa80
ms.openlocfilehash: 174108cac9982e46a62a90f8cb60662527812e47
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50575494"
---
# <a name="property-maps"></a>Mapas de propriedade

Com a sessão, o conjunto de linhas e o objeto de comando opcionais, cada provedor dá suporte a uma ou mais propriedades. Essas propriedades são definidas em mapas de propriedade armazenados nos arquivos de cabeçalho criados pela **OLE DB Provider Wizard**. Cada arquivo de cabeçalho contém um mapa para as propriedades no grupo de propriedades OLE DB definidos para o objeto ou objetos definidos no arquivo. O arquivo de cabeçalho que contém o objeto de fonte de dados também contém o mapa de propriedade para o [propriedades de fonte de dados](https://msdn.microsoft.com/library/ms724188). `Session.h` contém o mapa de propriedade para o [propriedades da sessão](/previous-versions/windows/desktop/ms714221). Os objetos de conjunto de linhas e de comando estão em um arquivo de cabeçalho único, chamado *projectname*RS.h. Essas propriedades são os membros de [propriedades do conjunto de linhas](/previous-versions/windows/desktop/ms711252) grupo.

## <a name="see-also"></a>Consulte também

[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)<br/>
