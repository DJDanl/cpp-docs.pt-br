---
title: Precedência em definições de Macro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, precedence in macro definitions
- macros, precedence
ms.assetid: 0c13182d-83cb-4cbd-af2d-f4c916b62aeb
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6ce6f0acc898dc719d2252d5cc59dff92bda4a98
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32368607"
---
# <a name="precedence-in-macro-definitions"></a>Precedência em definições de macro
Se uma macro tem várias definições, NMAKE usa a definição de precedência mais alta. A lista a seguir mostra a ordem de precedência, em ordem decrescente:  
  
1.  Uma macro definida na linha de comando  
  
2.  Uma macro definida em um makefile ou arquivo de inclusão  
  
3.  Uma macro de variável de ambiente herdada  
  
4.  Uma macro definida no arquivo Tools.ini  
  
5.  Uma macro predefinida, como [CC](../build/command-macros-and-options-macros.md) e [AS](../build/command-macros-and-options-macros.md)  
  
 Use /E para macros herdadas de variáveis de ambiente para substituir macros makefile com o mesmo nome. Use **! UNDEF** para substituir uma linha de comando.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)