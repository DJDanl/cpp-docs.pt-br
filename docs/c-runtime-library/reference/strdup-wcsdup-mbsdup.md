---
title: _strdup, _wcsdup, _mbsdup
ms.date: 4/2/2020
api_name:
- _strdup
- _mbsdup
- _wcsdup
- _o__strdup
- _o__wcsdup
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
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _tcsdup
- mbsdup
- _mbsdup
- _strdup
- _ftcsdup
- _wcsdup
helpviewer_keywords:
- wcsdup function
- ftcsdup function
- _ftcsdup function
- mbsdup function
- strdup function
- _strdup function
- _wcsdup function
- copying strings
- duplicating strings
- strings [C++], copying
- _mbsdup function
- strings [C++], duplicating
- tcsdup function
- _tcsdup function
ms.assetid: 8604f8bb-95e9-45d3-93ef-20397ebf247a
ms.openlocfilehash: 7ad28633844c49ce5b86c8f71f4502c62eba1216
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81359699"
---
# <a name="_strdup-_wcsdup-_mbsdup"></a>_strdup, _wcsdup, _mbsdup

Duplica cadeias de caracteres.

> [!IMPORTANT]
> **_mbsdup** não podem ser usados em aplicativos executados no Tempo de execução do Windows. Para obter mais informações, consulte [funções CRT não suportadas em aplicativos universal windows platform](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
char *_strdup(
   const char *strSource
);
wchar_t *_wcsdup(
   const wchar_t *strSource
);
unsigned char *_mbsdup(
   const unsigned char *strSource
);
```

### <a name="parameters"></a>Parâmetros

*Strsource*<br/>
Cadeia de caracteres de origem com terminação nula.

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retorna um ponteiro ao local de armazenamento para a seqüência copiada ou **NULL** se o armazenamento não puder ser alocado.

## <a name="remarks"></a>Comentários

A função **_strdup** chama [malloc](malloc.md) para alocar espaço de armazenamento para uma cópia do *strSource* e, em seguida, copia *strSource* para o espaço alocado.

**_wcsdup** e **_mbsdup** são versões de amplo caráter e multibytes de **_strdup**. Os argumentos e o valor de retorno do **_wcsdup** são strings de caracteres amplos; os de **_mbsdup** são cordas de caracteres multibyte. Caso contrário, essas três funções se comportam de forma idêntica.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcsdup**|**_strdup**|**_mbsdup**|**_wcsdup**|

Como **_strdup** chama **malloc** para alocar espaço de armazenamento para a cópia do *strSource,* é uma boa prática sempre liberar essa memória chamando a rotina [gratuita](free.md) no ponteiro que é devolvido pela chamada para **_strdup**.

Se **_DEBUG** e **_CRTDBG_MAP_ALLOC** forem definidos, **_strdup** e **_wcsdup** serão substituídos por chamadas para **_strdup_dbg** e **_wcsdup_dbg** para permitir a depuração de alocações de memória. Para obter mais informações, consulte [_strdup_dbg, _wcsdup_dbg](strdup-dbg-wcsdup-dbg.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_strdup**|\<string.h>|
|**_wcsdup**|\<string.h> ou \<wchar.h>|
|**_mbsdup**|\<mbstring.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_strdup.c

#include <string.h>
#include <stdio.h>

int main( void )
{
   char buffer[] = "This is the buffer text";
   char *newstring;
   printf( "Original: %s\n", buffer );
   newstring = _strdup( buffer );
   printf( "Copy:     %s\n", newstring );
   free( newstring );
}
```

```Output
Original: This is the buffer text
Copy:     This is the buffer text
```

## <a name="see-also"></a>Confira também

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
[memset, wmemset](memset-wmemset.md)<br/>
[strcat, wcscat, _mbscat](strcat-wcscat-mbscat.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[strncat, _strncat_l, wcsncat, _wcsncat_l, _mbsncat, _mbsncat_l](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[strncpy, _strncpy_l, wcsncpy, _wcsncpy_l, _mbsncpy, _mbsncpy_l](strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
