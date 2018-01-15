---
title: _get_osfhandle | Microsoft Docs
ms.custom: 
ms.date: 12/12/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _get_osfhandle
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- get_osfhandle
- _get_osfhandle
dev_langs: C++
helpviewer_keywords:
- operating systems, getting file handles
- get_osfhandle function
- _get_osfhandle function
- file handles [C++], operating system
ms.assetid: 0bdd728a-4fd8-410b-8c9f-01a121135196
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 2b810edac60b08ccc31d6767cb11b7176fb981b1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="getosfhandle"></a>_get_osfhandle

Recupera o identificador de arquivo do sistema operacional associado ao descritor do arquivo especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
intptr_t _get_osfhandle(   
   int fd   
);  
```  
  
### <a name="parameters"></a>Parâmetros

*FD*  
Um descritor de arquivo existente.  
  
## <a name="return-value"></a>Valor de retorno

Retorna um identificador de arquivo do sistema operacional se *fd* é válido. Caso contrário, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essa função retorna `INVALID_HANDLE_VALUE` (-1) e define `errno` para `EBADF`, que indica o identificador de arquivo inválido.  
  
## <a name="remarks"></a>Comentários

Para fechar um arquivo cujo identificador de arquivo do sistema operacional (SO) é obtido por `_get_osfhandle`, chame [ \_fechar](../../c-runtime-library/reference/close.md) no descritor de arquivo *fd*. Não chame `CloseHandle` no valor de retorno dessa função. O identificador de arquivo do sistema operacional subjacente é de propriedade de *fd* descritor de arquivo e é fechado quando `_close` é chamado em *fd*. Se o descritor de arquivo pertence a um `FILE *` fluxo, em seguida, chamar [fclose](../../c-runtime-library/reference/fclose-fcloseall.md) naquele `FILE *` fluxo fecha o descritor de arquivo e o identificador de arquivo do sistema operacional subjacente. Nesse caso, não chame `_close` no descritor de arquivo.
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_get_osfhandle`|\<io.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)   
[_close](../../c-runtime-library/reference/close.md)   
[_creat, _wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
[_dup, _dup2](../../c-runtime-library/reference/dup-dup2.md)   
[_open, _wopen](../../c-runtime-library/reference/open-wopen.md)
