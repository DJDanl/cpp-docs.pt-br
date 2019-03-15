---
title: Procurar dependentes em caminhos
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, dependents
- dependents, NMAKE
ms.assetid: bf998e47-da74-48b5-891d-d3d8ce57264b
ms.openlocfilehash: bc2c430c43f408065234c9df50977003eafd3cb1
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824281"
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

[Dependentes](dependents.md)
