---
title: Nomes de arquivo longos em um Makefile | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, long filenames
- long filenames
ms.assetid: 626d56fc-8879-46ba-9c2d-dd386c78cccc
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dc199289f80e6ce2f9dbc5317ee439af528a055b
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32367622"
---
# <a name="long-filenames-in-a-makefile"></a>Nomes de arquivo longos em um makefile
Coloque nomes de arquivo longos entre aspas duplas, da seguinte maneira:  
  
```  
all : "VeryLongFileName.exe"  
```  
  
## <a name="see-also"></a>Consulte também  
 [Conteúdo de um makefile](../build/contents-of-a-makefile.md)