---
title: Procurar dependentes em caminhos
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, dependents
- dependents, NMAKE
ms.assetid: bf998e47-da74-48b5-891d-d3d8ce57264b
ms.openlocfilehash: 9f2251a5fff9d708a783797d04606572e5ebce62
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57426453"
---
# <a name="search-paths-for-dependents"></a>Procurar dependentes em caminhos

Cada dependente tem um caminho de pesquisa opcional especificado da seguinte maneira:

## <a name="syntax"></a>Sintaxe

```
{directory[;directory...]}dependent
```

## <a name="remarks"></a>Comentários

NMAKE procura um dependente primeiro no diretório atual e, em seguida, nos diretórios na ordem especificada. Uma macro pode especificar parte ou todo um caminho de pesquisa. Coloque os nomes de diretório entre chaves ({}); Separe vários diretórios com um ponto e vírgula (;). Não há espaços ou tabulações são permitidas.

## <a name="see-also"></a>Consulte também

[Dependentes](../build/dependents.md)
