---
title: Constantes de arquivo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- _O_EXCL
- _O_RDWR
- _O_APPEND
- _O_RDONLY
- _O_TRUNC
- _O_CREAT
- _O_WRONLY
dev_langs:
- C++
helpviewer_keywords:
- _O_RDWR constant
- O_EXCL constant
- O_RDWR constant
- O_WRONLY constant
- O_APPEND constant
- O_CREAT constant
- _O_CREAT constant
- _O_APPEND constant
- _O_EXCL constant
- O_TRUNC constant
- _O_RDONLY constant
- _O_TRUNC constant
- O_RDONLY constant
- _O_WRONLY constant
ms.assetid: c8fa5548-9ac2-4217-801d-eb45e86f2fa4
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 59e108f8674b002cdbc5e7ab0b9c1868eea632df
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="file-constants"></a>Constantes de arquivo
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <fcntl.h>  
  
```  
  
## <a name="remarks"></a>Comentários  
 A expressão de inteiro formada por uma ou mais dessas constantes determina o tipo de operações de leitura ou gravação permitidas. Ela é formada pela combinação de uma ou mais constantes com uma constante de modo de translação.  
  
 As constantes de arquivo são as seguintes:  
  
 `_O_APPEND`  
 Reposiciona o ponteiro de arquivo no final do arquivo, antes de cada operação de gravação.  
  
 `_O_CREAT`  
 Cria e abre um novo arquivo para gravação; não terá nenhum efeito se o arquivo especificado por *nome do arquivo* existir.  
  
 `_O_EXCL`  
 Retorna um valor de erro se o arquivo especificado por *nome do arquivo* existir. Aplica-se apenas quando usado com `_O_CREAT`.  
  
 `_O_RDONLY`  
 Abre o arquivo somente para leitura; se este sinalizador for fornecido, nem `_O_RDWR` nem `_O_WRONLY` pode ser determinado.  
  
 `_O_RDWR`  
 Abre o arquivo para leitura e gravação; se este sinalizador for fornecido, nem `_O_RDONLY` nem `_O_WRONLY` pode ser determinado.  
  
 `_O_TRUNC`  
 Abre um arquivo existente e o trunca para que ele fique com comprimento zero; o arquivo deve ter permissão de gravação. O conteúdo do arquivo é destruído. Se esse sinalizador for especificado, não é possível especificar `_O_RDONLY`.  
  
 `_O_WRONLY`  
 Abre o arquivo somente para gravação; se este sinalizador for fornecido, nem `_O_RDONLY` nem `_O_RDWR` pode ser determinado.  
  
## <a name="see-also"></a>Consulte também  
 [_open, _wopen](../c-runtime-library/reference/open-wopen.md)   
 [_sopen, _wsopen](../c-runtime-library/reference/sopen-wsopen.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)