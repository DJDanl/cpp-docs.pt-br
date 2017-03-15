---
title: "Constantes de permissão de arquivo | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _S_IWRITE
- _S_IREAD
dev_langs:
- C++
helpviewer_keywords:
- S_IWRITE constant
- constants [C++], file attributes
- S_IREAD constant
- file permissions [C++]
- _S_IWRITE constant
- _S_IREAD constant
ms.assetid: 593cad33-31d1-44d2-8941-8af7d210c88c
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
ms.openlocfilehash: a54b34ed093e5fc13461df58725d79a53aa31134
ms.lasthandoff: 02/25/2017

---
# <a name="file-permission-constants"></a>Constantes de permissão de arquivo
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <sys/stat.h>  
  
```  
  
## <a name="remarks"></a>Comentários  
 Uma dessas constantes é necessária quando `_O_CREAT` (`_open`, `_sopen`) for especificado.  
  
 O argumento `pmode` especifica configurações de permissão do arquivo da seguinte maneira.  
  
|Constante|Significado|  
|--------------|-------------|  
|`_S_IREAD`|Leitura permitida|  
|`_S_IWRITE`|Gravação permitida|  
|`_S_IREAD` &#124; `_S_IWRITE`|Leitura e gravação permitidas|  
  
 Quando usado como o argumento `pmode` para `_umask`, a constante de manifesto define a configuração de permissão, da seguinte maneira.  
  
|Constante|Significado|  
|--------------|-------------|  
|`_S_IREAD`|Gravação não permitida (o arquivo é somente leitura)|  
|`_S_IWRITE`|Leitura não permitida (o arquivo é somente gravação)|  
|`_S_IREAD` &#124; `_S_IWRITE`|Leitura ou gravação não são permitidas|  
  
## <a name="see-also"></a>Consulte também  
 [_open, _wopen](../c-runtime-library/reference/open-wopen.md)   
 [_sopen, _wsopen](../c-runtime-library/reference/sopen-wsopen.md)   
 [_umask](../c-runtime-library/reference/umask.md)   
 [Tipos padrão](../c-runtime-library/standard-types.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)
