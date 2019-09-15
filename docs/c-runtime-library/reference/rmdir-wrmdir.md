---
title: _rmdir, _wrmdir
ms.date: 11/04/2016
api_name:
- _wrmdir
- _rmdir
api_location:
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
- api-ms-win-crt-filesystem-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- trmdir
- _trmdir
- wrmdir
- _rmdir
- _wrmdir
helpviewer_keywords:
- _rmdir function
- directories [C++], deleting
- rmdir function
- directories [C++], removing
- trmdir function
- _trmdir function
- _wrmdir function
- wrmdir function
ms.assetid: 652c2a5a-b0ac-4493-864e-1edf484333c5
ms.openlocfilehash: 396e620bfabe240638dc070ff87582b16287ff60
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70949213"
---
# <a name="_rmdir-_wrmdir"></a>_rmdir, _wrmdir

Exclui um diretório.

## <a name="syntax"></a>Sintaxe

```C
int _rmdir(
   const char *dirname
);
int _wrmdir(
   const wchar_t *dirname
);
```

### <a name="parameters"></a>Parâmetros

*dirname*<br/>
O caminho do diretório a ser removido.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retornará 0 se o diretório for excluído com êxito. Um valor de retorno de-1 indica um erro e **errno** é definido como um dos seguintes valores:

|Valor errno|Condição|
|-|-|
| **ENOTEMPTY** | O caminho especificado não é um diretório, o diretório não está vazio ou o diretório é o diretório de trabalho atual ou o diretório raiz. |
| **ENOENT** | Caminho inválido. |
| **EACCES** | Um programa tem um identificador aberto para o diretório. |

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_rmdir** exclui o diretório especificado por *dirname*. O diretório deve estar vazio e não deve ser o diretório de trabalho atual ou o diretório raiz.

**_wrmdir** é uma versão de caractere largo do **_rmdir**; o argumento *dirname* para **_wrmdir** é uma cadeia de caracteres largos. **_wrmdir** e **_rmdir** se comportam de outra forma.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_trmdir**|**_rmdir**|**_rmdir**|**_wrmdir**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_rmdir**|\<direct.h>|
|**_wrmdir**|\<direct.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

Consulte o exemplo de [_mkdir](mkdir-wmkdir.md).

## <a name="see-also"></a>Consulte também

[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[_chdir, _wchdir](chdir-wchdir.md)<br/>
[_mkdir, _wmkdir](mkdir-wmkdir.md)<br/>
