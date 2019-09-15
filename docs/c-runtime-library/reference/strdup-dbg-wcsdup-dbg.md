---
title: _strdup_dbg, _wcsdup_dbg
ms.date: 11/04/2016
api_name:
- _strdup_dbg
- _wcsdup_dbg
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _wcsdup_dbg
- strdup_dbg
- _strdup_dbg
- wcsdup_dbg
helpviewer_keywords:
- _wcsdup_dbg function
- stdup_dbg function
- copying strings
- duplicating strings
- strings [C++], copying
- strings [C++], duplicating
- _strdup_dbg function
- wcsdup_dbg function
ms.assetid: 681db70c-d124-43ab-b83e-5eeea9035097
ms.openlocfilehash: 9f7d4fd8781269ee37f7515fdcab72e5195fdf00
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70958194"
---
# <a name="_strdup_dbg-_wcsdup_dbg"></a>_strdup_dbg, _wcsdup_dbg

Versões de [_strdup e _wcsdup](strdup-wcsdup-mbsdup.md) que usam a versão de depuração de **malloc**.

## <a name="syntax"></a>Sintaxe

```C
char *_strdup_dbg(
   const char *strSource,
   int blockType,
   const char *filename,
   int linenumber
);
wchar_t *_wcsdup_dbg(
   const wchar_t *strSource,
   int blockType,
   const char *filename,
   int linenumber
);
```

### <a name="parameters"></a>Parâmetros

*strSource*<br/>
Cadeia de caracteres de origem com terminação nula.

*blockType*<br/>
Tipo de bloco de memória solicitado: **_CLIENT_BLOCK** ou **_NORMAL_BLOCK**.

*filename*<br/>
Ponteiro para o nome do arquivo de origem que solicitou a operação de alocação ou **nulo**.

*linenumber*<br/>
Número de linha no arquivo de origem em que a operação de alocação foi solicitada ou **nula**.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um ponteiro para o local de armazenamento da cadeia de caracteres copiada ou **nula** se o armazenamento não puder ser alocado.

## <a name="remarks"></a>Comentários

As funções **_strdup_dbg** e **_wcsdup_dbg** são idênticas a **_strdup** e **_wcsdup** , exceto que, quando **_DEBUG** é definido, essas funções usam a versão de depuração de **malloc**, **_malloc_dbg**, para alocar memória para a cadeia de caracteres duplicada. Para obter informações sobre os recursos de depuração do **_malloc_dbg**, consulte [_malloc_dbg](malloc-dbg.md).

Na maioria dos casos, não é necessário chamar essas funções explicitamente. Em vez disso, você pode definir o sinalizador **_CRTDBG_MAP_ALLOC**. Quando **_CRTDBG_MAP_ALLOC** é definido, as chamadas para **_strdup** e **_wcsdup** são remapeadas para **_strdup_dbg** e **_wcsdup_dbg**, respectivamente, com o *blockType* definido como **_NORMAL_BLOCK**. Portanto, você não precisa chamar essas funções explicitamente, a menos que queira marcar os blocos de heap como **_CLIENT_BLOCK**. Para obter mais informações sobre os tipos de bloco, consulte [Tipos de blocos no heap de depuração](/visualstudio/debugger/crt-debug-heap-details).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcsdup_dbg**|**_strdup_dbg**|**_mbsdup**|**_wcsdup_dbg**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_strdup_dbg**, **_wcsdup_dbg**|\<crtdbg.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões de depuração das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[_strdup, _wcsdup, _mbsdup](strdup-wcsdup-mbsdup.md)<br/>
[Versões de depuração de funções de alocação de heap](/visualstudio/debugger/debug-versions-of-heap-allocation-functions)<br/>
