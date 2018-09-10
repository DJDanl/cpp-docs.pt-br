---
title: _strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _wcsnicmp
- _strnicmp_l
- _wcsnicmp_l
- _strnicmp
- _mbsnicmp
- _mbsnicmp_l
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
- ntoskrnl.exe
apitype: DLLExport
f1_keywords:
- wcsnicmp_l
- _strnicmp
- _ftcsnicmp
- mbsnicmp_l
- _ftcsncicmp
- mbsnicmp
- _tcsncicmp
- _mbsnicmp
- _tcsnicmp
- strnicmp_l
- _wcsnicmp
- _wcsnicmp_l
- CORECRT_WSTRING/_wcsnicmp
- CORECRT_WSTRING/_wcsnicmp_l
- string/_strnicmp
- string/_strnicmp_l
dev_langs:
- C++
helpviewer_keywords:
- tcsnicmp function
- _tcsncicmp function
- _mbsnicmp_l function
- mbsnicmp_l function
- wcsnicmp_l function
- wcsnicmp function
- string comparison [C++], lowercase
- ftcsnicmp function
- strnicmp_l function
- strncmp function
- _strnicmp function
- strings [C++], comparing characters of
- _wcsnicmp_l function
- tcsncicmp function
- string comparison [C++], strncmp function
- _mbsnicmp function
- ftcsncicmp function
- _tcsnicmp function
- _ftcsncicmp function
- _strnicmp_l function
- _ftcsnicmp function
- characters [C++], comparing
- mbsnicmp function
- _wcsnicmp function
ms.assetid: df6e5037-4039-4c85-a0a6-21d4ef513966
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0da454b2b980be3565ee27fde4ee14d7eadd42fb
ms.sourcegitcommit: f0c90000125a9497bf61e41624de189a043703c0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/10/2018
ms.locfileid: "44313618"
---
# <a name="strnicmp-wcsnicmp-mbsnicmp-strnicmpl-wcsnicmpl-mbsnicmpl"></a>_strnicmp, _wcsnicmp, _mbsnicmp, _strnicmp_l, _wcsnicmp_l, _mbsnicmp_l
Compara o número especificado de caracteres de duas cadeias de caracteres sem considerar o caso.

> [!IMPORTANT]
> **mbsnicmp** e **mbsnicmp_l** não pode ser usado em aplicativos executados no tempo de execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int _strnicmp(
   const char *string1,
   const char *string2,
   size_t count
);
int _wcsnicmp(
   const wchar_t *string1,
   const wchar_t *string2,
   size_t count
);
int _mbsnicmp(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count
);
int _strnicmp_l(
   const char *string1,
   const char *string2,
   size_t count,
   _locale_t locale
);
int _wcsnicmp_l(
   const wchar_t *string1,
   const wchar_t *string2,
   size_t count,
   _locale_t locale
);
int _mbsnicmp_l(
   const unsigned char *string1,
   const unsigned char *string2,
   size_t count,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*string1*, *string2*<br/>
Cadeias de caracteres com terminação nula.

*count*<br/>
O número de caracteres a serem comparados.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Indica a relação entre as subcadeias de caracteres, da seguinte maneira.

|Valor retornado|Descrição|
|------------------|-----------------|
|< 0|*string1* subcadeia de caracteres é menor que *string2* subcadeia de caracteres.|
|0|*string1* subcadeia de caracteres é idêntica à *string2* subcadeia de caracteres.|
|> 0|*string1* subcadeia de caracteres é maior que *string2* subcadeia de caracteres.|

Em um erro de validação de parâmetro, essas funções retornarão **_NLSCMPERROR**, que é definida no \<String. h > e \<mbstring >.

## <a name="remarks"></a>Comentários

O **strnicmp** função compara ordinariamente, no máximo, a primeira *contagem* caracteres da *string1* e *string2*. A comparação é executada independentemente do caso, convertendo cada caractere em minúsculas. **strnicmp** é uma versão sem diferenciação de **strncmp**. A comparação termina se um caractere nulo de terminação for atingido na cadeia de caracteres antes de *contagem* caracteres serem comparados. Se as cadeias de caracteres são iguais quando um caractere nulo de terminação for atingido na cadeia de caracteres antes de *contagem* caracteres são comparados, a cadeia de caracteres mais curta será menor.

Os caracteres de 91 a 96 na tabela ASCII ('[','\\', ']', ' ^', '_' e '\`') avaliam como menor do que qualquer caractere alfabético. Essa classificação é idêntico da **stricmp**.

**wcsnicmp** e **mbsnicmp** são versões de caractere largo e caracteres multibyte **strnicmp**. Os argumentos de **wcsnicmp** são largos cadeias de caracteres; aqueles de **mbsnicmp** são cadeias de caracteres multibyte. **mbsnicmp** reconhece sequências de caracteres multibyte de acordo com a página de código multibyte atual e retorna **_NLSCMPERROR** em um erro. Para obter mais informações, consulte [Páginas de Código](../../c-runtime-library/code-pages.md). Caso contrário, essas três funções se comportam de forma idêntica. Essas funções são afetadas pela configuração de localidade – as versões que não têm o **l** sufixo usam a localidade atual para seu comportamento dependente da localidade; as versões que têm o **l** sufixo em vez disso, use o *localidade* que é passado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

Todas essas funções validam seus parâmetros. Se qualquer um dos *string1* ou *string2* é um ponteiro nulo, o manipulador de parâmetro inválido será invocado, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão **_NLSCMPERROR** e defina **errno** para **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcsncicmp**|**_strnicmp**|**_mbsnicmp**|**_wcsnicmp**|
|**tcsnicmp**|**_strnicmp**|**_mbsnbicmp**|**_wcsnicmp**|
|**_tcsncicmp_l**|**_strnicmp_l**|**_mbsnicmp_l**|**_wcsnicmp_l**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strnicmp**, **strnicmp_l**|\<string.h>|
|**wcsnicmp**, **wcsnicmp_l**|\<string.h> ou \<wchar.h>|
|**mbsnicmp**, **mbsnicmp_l**|\<mbstring.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo para [strncmp](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md).

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[strcat, wcscat, _mbscat](strcat-wcscat-mbscat.md)<br/>
[strcmp, wcscmp, _mbscmp](strcmp-wcscmp-mbscmp.md)<br/>
[strcpy, wcscpy, _mbscpy](strcpy-wcscpy-mbscpy.md)<br/>
[strncat, _strncat_l, wcsncat, _wcsncat_l, _mbsncat, _mbsncat_l](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[strncpy, _strncpy_l, wcsncpy, _wcsncpy_l, _mbsncpy, _mbsncpy_l](strncpy-strncpy-l-wcsncpy-wcsncpy-l-mbsncpy-mbsncpy-l.md)<br/>
[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)<br/>
[_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l](strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
