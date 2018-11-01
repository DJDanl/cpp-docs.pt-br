---
title: _strdup, _wcsdup, _mbsdup
ms.date: 11/04/2016
apiname:
- _strdup
- _mbsdup
- _wcsdup
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
- api-ms-win-crt-multibyte-l1-1-0.dll
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
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
ms.openlocfilehash: 094843fdb1432aa58ec04b3b4e39ac8861b928ec
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50461510"
---
# <a name="strdup-wcsdup-mbsdup"></a>_strdup, _wcsdup, _mbsdup

Duplica cadeias de caracteres.

> [!IMPORTANT]
> **mbsdup** não pode ser usado em aplicativos executados no tempo de execução do Windows. Para obter mais informações, consulte [funções de CRT sem suporte em aplicativos da plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*strSource*<br/>
Cadeia de caracteres de origem com terminação nula.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um ponteiro para o local de armazenamento para a cadeia de caracteres copiada ou **nulo** se o armazenamento não pode ser alocado.

## <a name="remarks"></a>Comentários

O **strdup** chamadas de função [malloc](malloc.md) alocar espaço de armazenamento para uma cópia do *strSource* e, em seguida, copia *strSource* para o espaço alocado.

**wcsdup** e **mbsdup** são versões de caractere largo e caracteres multibyte **strdup**. Os argumentos e o valor de retorno **wcsdup** são largos cadeias de caracteres; aqueles de **mbsdup** são cadeias de caracteres multibyte. Caso contrário, essas três funções se comportam de forma idêntica.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcsdup**|**_strdup**|**_mbsdup**|**_wcsdup**|

Porque **strdup** chamadas **malloc** alocar espaço de armazenamento para a cópia do *strSource*, é recomendável sempre liberar essa memória chamando o [livre](free.md) rotina no ponteiro retornado pela chamada para **strdup**.

Se **Debug** e **crtdbg_map_alloc** estiverem definidos, **strdup** e **wcsdup** são substituídos por chamadas para **strdup_dbg**  e **wcsdup_dbg** para permitir a depuração de alocações de memória. Para obter mais informações, consulte [_strdup_dbg, _wcsdup_dbg](strdup-dbg-wcsdup-dbg.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_strdup**|\<string.h>|
|**_wcsdup**|\<string.h> ou \<wchar.h>|
|**_mbsdup**|\<mbstring.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[memset, wmemset](memset-wmemset.md)<br/>
[strcat, wcscat, _mbscat](strcat-wcscat-mbscat.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[strncat, _strncat_l, wcsncat, _wcsncat_l, _mbsncat, _mbsncat_l](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[strncpy, _strncpy_l, wcsncpy, _wcsncpy_l, _mbsncpy, _mbsncpy_l](strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)<br/>
[_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l](strnicmp-wcsnicmp-mbsnicmp-strnicmp-l-wcsnicmp-l-mbsnicmp-l.md)<br/>
[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
