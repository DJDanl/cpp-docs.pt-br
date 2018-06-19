---
title: Constantes de acesso de leitura/gravação de arquivo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: conceptual
f1_keywords:
- c.constants.file
dev_langs:
- C++
helpviewer_keywords:
- read/write access constants
- write access constants
- access constants for file read/write
- constants [C++], file attributes
- file read/write access constants
ms.assetid: 56cd1d22-39a5-4fcf-bea2-7046d249e8ee
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f57ac6ffc3c13c640d7bdf6a2ec64912148bfbc3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32391136"
---
# <a name="file-readwrite-access-constants"></a>Constantes de acesso de leitura/gravação de arquivo
## <a name="syntax"></a>Sintaxe  
  
```  
  
#include <stdio.h>  
```  
  
## <a name="remarks"></a>Comentários  
 Essas constantes especificam o tipo de acesso ("a", "r" ou "w") solicitado para o arquivo. O [modo de translação](../c-runtime-library/file-translation-constants.md) ("b" ou "t") e o [modo commit-to-disk](../c-runtime-library/commit-to-disk-constants.md) ("c" ou "n") podem ser especificados com o tipo de acesso.  
  
 Os tipos de acesso são descritos abaixo.  
  
 **"a"**  
 Abre para gravação no final do arquivo (acréscimo); cria o arquivo primeiro se ele não existir. Todas as operações de gravação ocorrem no final do arquivo. Embora o ponteiro do arquivo possa ser reposicionado usando `fseek` ou **rewind**, ele é sempre movido de volta para o final do arquivo antes que qualquer operação de gravação seja realizada.  
  
 **"a+"**  
 Idem acima, mas também permite a leitura.  
  
 **"r"**  
 Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, ocorrerá uma falha na chamada para abrir o arquivo.  
  
 **"r+"**  
 Abre para leitura e gravação. Se o arquivo não existir ou não puder ser encontrado, ocorrerá uma falha na chamada para abrir o arquivo.  
  
 **"w"**  
 Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.  
  
 **"w+"**  
 Abre um arquivo vazio para leitura e gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.  
  
 Quando o tipo "r+", "w+" ou "a+" é especificado, são permitidas leitura e gravação (diz-se que o arquivo está aberto para "atualização"). No entanto, quando você muda entre leitura e gravação, deve haver uma operação `fflush`, `fsetpos`, `fseek` ou **rewind** intermediária. A posição atual pode ser especificada para a operação `fsetpos` ou `fseek`.  
  
## <a name="see-also"></a>Consulte também  
 [_fdopen, _wfdopen](../c-runtime-library/reference/fdopen-wfdopen.md)   
 [fopen, _wfopen](../c-runtime-library/reference/fopen-wfopen.md)   
 [freopen, _wfreopen](../c-runtime-library/reference/freopen-wfreopen.md)   
 [_fsopen, _wfsopen](../c-runtime-library/reference/fsopen-wfsopen.md)   
 [_popen, _wpopen](../c-runtime-library/reference/popen-wpopen.md)   
 [Constantes globais](../c-runtime-library/global-constants.md)