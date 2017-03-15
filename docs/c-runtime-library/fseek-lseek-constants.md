---
title: Constantes fseek, _lseek | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 2814fe41478b323c117aedea47d3b3c993f26d2c
ms.lasthandoff: 02/25/2017

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
