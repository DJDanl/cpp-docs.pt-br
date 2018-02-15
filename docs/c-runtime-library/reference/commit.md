---
title: _commit | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _commit
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
- _commit
- commit
dev_langs:
- C++
helpviewer_keywords:
- files [C++], flushing
- flushing files to disk
- commit function
- _commit function
- committing files to disk
ms.assetid: d0c74d3a-4f2d-4fb0-b140-2d687db3d233
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ed5a3f1e8d1f4a122ecf5a66393fa5c1f5c65f1b
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="commit"></a>_commit
Libera um arquivo diretamente no disco.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _commit(   
   int fd   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `fd`  
 Descritor de arquivo que se refere ao arquivo aberto.  
  
## <a name="return-value"></a>Valor de retorno  
 `_commit` retorna 0 se o arquivo tiver sido liberado com sucesso no disco. Um valor de retorno de -1 indica um erro.  
  
## <a name="remarks"></a>Comentários  
 A função `_commit` força o sistema operacional a gravar o arquivo associado a `fd` no disco. Essa chamada garante que o arquivo especificado seja liberado imediatamente, não a critério do sistema operacional.  
  
 Se `fd` for um descritor do arquivo inválido, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função retornará -1 e `errno` será definido como `EBADF`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalhos opcionais|  
|-------------|---------------------|----------------------|  
|`_commit`|\<io.h>|\<errno.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [_creat, _wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)   
 [_read](../../c-runtime-library/reference/read.md)   
 [_write](../../c-runtime-library/reference/write.md)