---
title: Constantes fseek, _lseek | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- SEEK_END
- SEEK_SET
- SEEK_CUR
dev_langs:
- C++
helpviewer_keywords:
- SEEK_SET constant
- SEEK_END constant
- SEEK_CUR constant
ms.assetid: 9deeb13e-5aa3-4c33-80d8-721c80a4de9d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fbcf0a1106610740a585b7e4f8b68e3fc9b6a8f7
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="fseek-lseek-constants"></a>Constantes fseek, _lseek
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <stdio.h>  
  
```  
  
## <a name="remarks"></a>Comentários  
 O argumento *origem* especifica a posição inicial e pode ser uma das seguintes constantes de manifesto:  
  
|Constante|Significado|  
|--------------|-------------|  
|`SEEK_END`|Final do arquivo|  
|`SEEK_CUR`|Posição atual do ponteiro de arquivo|  
|`SEEK_SET`|Início do arquivo|  
  
## <a name="see-also"></a>Consulte também  
 [fseek, _fseeki64](../c-runtime-library/reference/fseek-fseeki64.md)   
 [_lseek, _lseeki64](../c-runtime-library/reference/lseek-lseeki64.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)