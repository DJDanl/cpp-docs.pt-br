---
title: Procurar dependentes em demarcadores
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, dependents
- dependents, NMAKE
ms.assetid: bf998e47-da74-48b5-891d-d3d8ce57264b
ms.openlocfilehash: 8856d845d51072d205c84278978c7fbb447aed9b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50448796"
---
# <a name="search-paths-for-dependents"></a>Procurar dependentes em demarcadores

Cada dependente tem um caminho de pesquisa opcional especificado da seguinte maneira:

## <a name="syntax"></a>Sintaxe

```
{directory[;directory...]}dependent
```

## <a name="remarks"></a>Comentários

NMAKE procura um dependente primeiro no diretório atual e, em seguida, nos diretórios na ordem especificada. Uma macro pode especificar parte ou todo um caminho de pesquisa. Coloque os nomes de diretório entre chaves ({}); Separe vários diretórios com um ponto e vírgula (;). Não há espaços ou tabulações são permitidas.

## <a name="see-also"></a>Consulte também

[Dependentes](../build/dependents.md)