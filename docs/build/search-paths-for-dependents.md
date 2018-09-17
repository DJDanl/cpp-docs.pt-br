---
title: Caminhos de pesquisa para dependentes | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, dependents
- dependents, NMAKE
ms.assetid: bf998e47-da74-48b5-891d-d3d8ce57264b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d1fd407f99abb98fb949b6d5bcc45b10c6ff9121
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45706284"
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