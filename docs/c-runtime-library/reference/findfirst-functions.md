---
title: _findfirst, _findfirst32, _findfirst32i64, _findfirst64, _findfirst64i32, _findfirsti64, _wfindfirst, _wfindfirst32, _wfindfirst32i64, _wfindfirst64, _wfindfirst64i32, _wfindfirsti64
ms.date: 4/2/2020
api_name:
- _findfirst
- _wfindfirst
- _findfirst32
- _wfindfirst32
- _findfirst32i64
- _wfindfirst32i64
- _findfirst64
- _wfindfirst64
- _findfirst64i32
- _wfindfirst64i32
- _findfirsti64
- _wfindfirsti64
- _o__findfirst32
- _o__findfirst32i64
- _o__findfirst64
- _o__findfirst64i32
- _o__wfindfirst32
- _o__wfindfirst32i64
- _o__wfindfirst64
- _o__wfindfirst64i32
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- findfirst32i64
- wfindfirst32i64
- tfindfirst64
- _findfirst64i32
- _wfindfirst32i64
- _wfindfirsti64
- wfindfirst
- _tfindfirsti64
- findfirst32
- _tfindfirst32
- _findfirsti64
- findfirst
- wfindfirst64
- wfindfirst32
- tfindfirst32
- _wfindfirst64i32
- findfirst64i32
- tfindfirst64i32
- _wfindfirst
- findfirsti64
- _findfirst32i64
- wfindfirst64i32
- _wfindfirst32
- _findfirst32
- _tfindfirst32i64
- tfindfirst
- _tfindfirst64i32
- findfirst64
- _tfindfirst
- _findfirst64
- _tfindfirst64
- tfindfirst32i64
- _findfirst
- _wfindfirst64
helpviewer_keywords:
- _tfindfirst64 function
- _wfindfirst64i32 function
- _wfindfirst32i64 function
- wfindfirst32 function
- _findfirst function
- wfindfirst64 function
- _wfindfirst function
- _findfirst64i32 function
- wfindfirst function
- _findfirst64 function
- tfindfirst32 function
- _tfindfirst64i32 function
- findfirst function
- findfirst32i64 function
- tfindfirst64 function
- _tfindfirst32 function
- tfindfirst32i64 function
- tfindfirst64i32 function
- _wfindfirsti64 function
- _findfirst32i64 function
- findfirst32 function
- findfirsti64 function
- findfirst64i32 function
- tfindfirsti64 function
- tfindfirst function
- _wfindfirst32 function
- wfindfirsti64 function
- _tfindfirsti64 function
- _tfindfirst function
- _tfindfirst32i64 function
- findfirst64 function
- _findfirst32 function
- _findfirsti64 function
- wfindfirst32i64 function
- wfindfirst64i32 function
- _wfindfirst64 function
ms.assetid: 9bb46d1a-b946-47de-845a-a0b109a33ead
ms.openlocfilehash: 879a84b14f612992ae7ed3a96211637aaf5c4783
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82911733"
---
# <a name="_findfirst-_findfirst32-_findfirst32i64-_findfirst64-_findfirst64i32-_findfirsti64-_wfindfirst-_wfindfirst32-_wfindfirst32i64-_wfindfirst64-_wfindfirst64i32-_wfindfirsti64"></a>_findfirst, _findfirst32, _findfirst32i64, _findfirst64, _findfirst64i32, _findfirsti64, _wfindfirst, _wfindfirst32, _wfindfirst32i64, _wfindfirst64, _wfindfirst64i32, _wfindfirsti64

Forneça informações sobre a primeira instância de um nome de arquivo que corresponde ao arquivo especificado no argumento *filespec* .

## <a name="syntax"></a>Sintaxe

```C
intptr_t _findfirst(
   const char *filespec,
   struct _finddata_t *fileinfo
);
intptr_t _findfirst32(
   const char *filespec,
   struct _finddata32_t *fileinfo
);
intptr_t _findfirst64(
   const char *filespec,
   struct _finddata64_t *fileinfo
);
intptr_t _findfirsti64(
   const char *filespec,
   struct _finddatai64_t *fileinfo
);
intptr_t _findfirst32i64(
   const char *filespec,
   struct _finddata32i64_t *fileinfo
);
intptr_t _findfirst64i32(
   const char *filespec,
   struct _finddata64i32_t *fileinfo
);
intptr_t _wfindfirst(
   const wchar_t *filespec,
   struct _wfinddata_t *fileinfo
);
intptr_t _wfindfirst32(
   const wchar_t *filespec,
   struct _wfinddata32_t *fileinfo
);
intptr_t _wfindfirst64(
   const wchar_t *filespec,
   struct _wfinddata64_t *fileinfo
);
intptr_t _wfindfirsti64(
   const wchar_t *filespec,
   struct _wfinddatai64_t *fileinfo
);
intptr_t _wfindfirst32i64(
   const wchar_t *filespec,
   struct _wfinddata32i64_t *fileinfo
);
intptr_t _wfindfirst64i32(
   const wchar_t *filespec,
   struct _wfinddata64i32_t *fileinfo
);
```

### <a name="parameters"></a>Parâmetros

*filespec*<br/>
Especificação de arquivo de destino (pode incluir caracteres curinga).

*Method*<br/>
Buffer de informações do arquivo.

## <a name="return-value"></a>Valor retornado

Se for bem-sucedido, **_findfirst** retornará um identificador de pesquisa exclusivo que identifica o arquivo ou grupo de arquivos que correspondem à especificação de *filespec* , que pode ser usada em uma chamada subsequente para [_findnext](findnext-functions.md) ou para [_findclose](findclose.md). Caso contrário, **_findfirst** retornará-1 e definirá **errno** como um dos valores a seguir.

| Valor errno | Condição |
|-|-|
| **EINVAL** | Parâmetro inválido: *filespec* ou *FileInfo* era **nulo**. Ou o sistema operacional retornou um erro inesperado. |
| **ENOENT** | Especificação de arquivo que não pôde ser correspondida. |
| **ENOMEM** | Memória insuficiente. |
| **EINVAL** | Especificação de nome de arquivo inválida ou o nome de arquivo fornecido foi maior que **MAX_PATH**. |

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Se um parâmetro inválido for passado, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md).

## <a name="remarks"></a>Comentários

Você deve chamar [_findclose](findclose.md) depois de terminar com a função **_findfirst** ou [_findnext](findnext-functions.md) (ou qualquer variante). Isso libera recursos usados por essas funções em seu aplicativo.

As variações dessas funções que têm o prefixo **w** são versões de caractere largo; caso contrário, eles são idênticos às funções correspondentes de byte único.

Variações dessas funções dão suporte a tipos de hora de 32 ou de 64 bits e a tamanhos de arquivo de 32 ou de 64 bits. O primeiro sufixo numérico (**32** ou **64**) indica o tamanho do tipo de tempo; o segundo sufixo é **i32** ou **i64**e indica se o tamanho do arquivo é representado como um inteiro de 32 bits ou 64 bits. Para obter informações sobre quais versões dão suporte a tamanhos de arquivo e tipos de hora de 32 e de 64 bits, consulte a tabela a seguir. O sufixo **i32** ou **i64** é omitido se for igual ao tamanho do tipo de hora, portanto **_findfirst64** também dá suporte a comprimentos de arquivo de 64 bits e **_findfirst32** dá suporte apenas a comprimentos de arquivo de 32 bits.

Essas funções usam várias formas da estrutura de **_finddata_t** para o parâmetro *FileInfo* . Para obter mais informações sobre a estrutura, consulte [Funções de pesquisa de nome de arquivo](../../c-runtime-library/filename-search-functions.md).

As variações que usam um tipo de hora de 64 bits permitem que as datas de criação de arquivo sejam expressas até 23:59:59 de 31 de dezembro de 3000, no horário UTC. As que usam tipos de hora de 32 bits representam datas somente até 23:59:59 de 18 de janeiro de 2038, no horário UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para todas essas funções.

A menos que você tenha um motivo específico para usar as versões que especificam o tamanho de tempo explicitamente, use **_findfirst** ou **_wfindfirst** ou, se precisar dar suporte a tamanhos de arquivo maiores que 3 GB, use **_findfirsti64** ou **_wfindfirsti64**. Todas essas funções usam o tipo de hora de 64 bits. Em versões anteriores, elas usavam um tipo de hora de 32 bits. Se essa for uma alteração significativa para um aplicativo, você poderá definir **_USE_32BIT_TIME_T** para reverter ao comportamento antigo. Se **_USE_32BIT_TIME_T** for definido, **_findfirst**, **_finfirsti64**e suas versões Unicode correspondentes usarão um tempo de 32 bits.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="time-type-and-file-length-type-variations-of-_findfirst"></a>Variações de tipo de hora e tipo de tamanho de arquivo de _findfirst

|Funções|**_USE_32BIT_TIME_T** definido?|Tipo de hora|Tipo de tamanho de arquivo|
|---------------|----------------------------------|---------------|----------------------|
|**_findfirst**, **_wfindfirst**|Não definido|64 bits|32 bits|
|**_findfirst**, **_wfindfirst**|Definido|32 bits|32 bits|
|**_findfirst32**, **_wfindfirst32**|Não afetado pela definição de macro|32 bits|32 bits|
|**_findfirst64**, **_wfindfirst64**|Não afetado pela definição de macro|64 bits|64 bits|
|**_findfirsti64**, **_wfindfirsti64**|Não definido|64 bits|64 bits|
|**_findfirsti64**, **_wfindfirsti64**|Definido|32 bits|64 bits|
|**_findfirst32i64**, **_wfindfirst32i64**|Não afetado pela definição de macro|32 bits|64 bits|
|**_findfirst64i32**, **_wfindfirst64i32**|Não afetado pela definição de macro|64 bits|32 bits|

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tfindfirst**|**_findfirst**|**_findfirst**|**_wfindfirst**|
|**_tfindfirst32**|**_findfirst32**|**_findfirst32**|**_wfindfirst32**|
|**_tfindfirst64**|**_findfirst64**|**_findfirst64**|**_wfindfirst64**|
|**_tfindfirsti64**|**_findfirsti64**|**_findfirsti64**|**_wfindfirsti64**|
|**_tfindfirst32i64**|**_findfirst32i64**|**_findfirst32i64**|**_wfindfirst32i64**|
|**_tfindfirst64i32**|**_findfirst64i32**|**_findfirst64i32**|**_wfindfirst64i32**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_findfirst**|\<io.h>|
|**_findfirst32**|\<io.h>|
|**_findfirst64**|\<io.h>|
|**_findfirsti64**|\<io.h>|
|**_findfirst32i64**|\<io.h>|
|**_findfirst64i32**|\<io.h>|
|**_wfindfirst**|\<io.h> ou \<wchar.h>|
|**_wfindfirst32**|\<io.h> ou \<wchar.h>|
|**_wfindfirst64**|\<io.h> ou \<wchar.h>|
|**_wfindfirsti64**|\<io.h> ou \<wchar.h>|
|**_wfindfirst32i64**|\<io.h> ou \<wchar.h>|
|**_wfindfirst64i32**|\<io.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Chamadas do sistema](../../c-runtime-library/system-calls.md)<br/>
[Funções de pesquisa de nome de arquivo](../../c-runtime-library/filename-search-functions.md)<br/>
