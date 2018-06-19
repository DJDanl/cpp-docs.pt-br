---
title: Constantes do modo de translação | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- _O_BINARY
- _O_TEXT
- _O_RAW
dev_langs:
- C++
helpviewer_keywords:
- O_BINARY constant
- O_TEXT constant
- O_RAW constant
- _O_TEXT constant
- _O_RAW constant
- translation constants
- _O_BINARY constant
- translation, constants
- translation, modes
- translation modes (file I/O)
ms.assetid: a5993bf4-7e7a-47f9-83c3-e46332b85579
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: eabf83c8388819b074ad553dc2b29b1902f2f1b5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32410938"
---
# <a name="translation-mode-constants"></a>Constantes do modo de translação
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <fcntl.h>  
  
```  
  
## <a name="remarks"></a>Comentários  
 As constantes de manifesto `_O_BINARY` e `_O_TEXT` determinam o modo de translação para os arquivos (`_open` e `_sopen`) ou o modo de translação para os fluxos (`_setmode`).  
  
 Os valores permitidos são:  
  
 `_O_TEXT`  
 Abre um arquivo no modo de texto (movido). Combinações CR-LF (Retorno de carro –alimentação de linha) são convertidas em uma única alimentação de linha (LF) na entrada. Os caracteres de alimentação de linha são movidos para combinações CR-LF na saída. Além disso, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura e leitura/gravação, `fopen` verifica se há um CTRL+Z no fim do arquivo e o remove, se possível. Isso é feito porque usar as funções `fseek` e `ftell` para movimentação dentro de um arquivo que termina com CTRL+Z poderá fazer o `fseek` se comportar incorretamente perto do fim do arquivo.  
  
 `_O_BINARY`  
 Abre um arquivo no modo binário (não convertido). As translações acima são suprimidas.  
  
 `_O_RAW`  
 Mesmo que `_O_BINARY`. Suporte para compatibilidade com C 2.0.  
  
 Para obter mais informações, consulte [E/S de arquivo nos modos de texto e binário](../c-runtime-library/text-and-binary-mode-file-i-o.md) e [Translação de arquivo](../c-runtime-library/file-translation-constants.md).  
  
## <a name="see-also"></a>Consulte também  
 [_open, _wopen](../c-runtime-library/reference/open-wopen.md)   
 [_pipe](../c-runtime-library/reference/pipe.md)   
 [_sopen, _wsopen](../c-runtime-library/reference/sopen-wsopen.md)   
 [_setmode](../c-runtime-library/reference/setmode.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)