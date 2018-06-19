---
title: Pesquisar caminhos dependentes | Microsoft Docs
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
ms.openlocfilehash: 577fc7e44bfff35cf7efdcff20dc4cdca1c7001e
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32380479"
---
# <a name="search-paths-for-dependents"></a>Procurar dependentes em demarcadores
Cada dependente tem um caminho de pesquisa opcional especificado da seguinte maneira:  
  
## <a name="syntax"></a>Sintaxe  
  
```  
{directory[;directory...]}dependent  
```  
  
## <a name="remarks"></a>Comentários  
 NMAKE procura um dependente primeiro no diretório atual e, em seguida, nos diretórios na ordem especificada. Uma macro pode especificar parte ou todo um caminho de pesquisa. Coloque nomes de diretórios entre chaves ({}); Separe vários diretórios com um ponto e vírgula (;). Nenhum tabulações ou espaços são permitidas.  
  
## <a name="see-also"></a>Consulte também  
 [Dependentes](../build/dependents.md)