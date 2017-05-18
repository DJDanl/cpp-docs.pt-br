---
title: Constantes de atributo do arquivo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- A_HIDDEN
- _A_NORMAL
- _A_SUBDIR
- _A_RDONLY
- A_NORMAL
- A_SUBDIR
- _A_SYSTEM
- c.constants.file
- _A_HIDDEN
- A_RDONLY
- _A_ARCH
- A_ARCH
dev_langs:
- C++
helpviewer_keywords:
- constants [C++], file attributes
- file attribute constants [C++]
- _A_SYSTEM constant
- files [C++], file attribute constants
- _A_SUBDIR constant
- _A_ARCH constant
- _A_NORMAL constant
- _A_HIDDEN constant
- _A_RDONLY constant
ms.assetid: 8dc8ccb9-99f5-446b-876c-7ebecc2f764f
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
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 3025a88d0ff824b9e3f26b461664b91c255704e4
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="file-attribute-constants"></a>Constantes de atributo do arquivo
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <io.h>  
```  
  
## <a name="remarks"></a>Comentários  
 Essas constantes especificam os atributos atuais do arquivo ou diretório especificado pela função.  
  
 Os atributos são representados pelas constantes de manifesto a seguir:  
  
 `_A_ARCH`  
 Arquivo morto. Definido sempre que o arquivo é alterado e limpo com o comando BACKUP. Valor: 0x20  
  
 `_A_HIDDEN`  
 Arquivo oculto. Normalmente não visto com o comando DIR, a menos que a opção /AH seja usada. Retorna informações sobre arquivos normais, como também arquivos com esse atributo. Valor: 0x02  
  
 `_A_NORMAL`  
 Normal. O arquivo pode ser lido ou gravado sem restrição. Valor: 0x00  
  
 `_A_RDONLY`  
 Somente leitura. O arquivo não pode ser aberto para gravação e não é possível criar um arquivo com o mesmo nome. Valor: 0x01  
  
 `_A_SUBDIR`  
 Subdiretório. Valor: 0x10  
  
 `_A_SYSTEM`  
 Arquivo do sistema. Normalmente não visto com o comando DIR, a menos que a opção /AS seja usada. Valor: 0x04  
  
 Várias constantes podem ser combinadas com o operador OR (&#124;).  
  
## <a name="see-also"></a>Consulte também  
 [Funções de pesquisa de nome de arquivo](../c-runtime-library/filename-search-functions.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)
