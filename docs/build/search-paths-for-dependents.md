---
title: Pesquisar caminhos dependentes | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, dependents
- dependents, NMAKE
ms.assetid: bf998e47-da74-48b5-891d-d3d8ce57264b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: f6093db4ac8e0c88dfe6e4b5a5463e5ee8d24349
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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