---
title: strnlen, strnlen_s, wcsnlen, wcsnlen_s, _mbsnlen, _mbsnlen_l, _mbstrnlen, _mbstrnlen_l | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- wcsnlen
- strnlen_s
- _mbstrnlen
- _mbsnlen_l
- _mbstrnlen_l
- strnlen
- wcsnlen_s
- _mbsnlen
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
- wcsnlen
- strnlen_s
- _mbsnlen
- _mbsnlen_l
- _tcsnlen
- _tcscnlen
- _mbstrnlen_l
- wcsnlen_s
- _mbstrnlen
- strnlen
- _tcscnlen_l
dev_langs:
- C++
helpviewer_keywords:
- _tcscnlen function
- _mbstrnlen function
- _mbsnlen_l function
- lengths, strings
- mbstrnlen function
- mbsnlen_l function
- _mbstrnlen_l function
- _tcscnlen_l function
- wcsnlen_l function
- _tcsnlen function
- _mbsnlen function
- strnlen function
- mbsnlen function
- wcsnlen_s function
- strnlen_s function
- mbstrnlen_l function
- wcsnlen function
- string length
- strnlen_l function
ms.assetid: cc05ce1c-72ea-4ae4-a7e7-4464e56e5f80
caps.latest.revision: 35
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 64ff971ad80259854fafbd367d83f099c08ed33b
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="strnlen-strnlens-wcsnlen-wcsnlens-mbsnlen-mbsnlenl-mbstrnlen-mbstrnlenl"></a>strnlen, strnlen_s, wcsnlen, wcsnlen_s, _mbsnlen, _mbsnlen_l, _mbstrnlen, _mbstrnlen_l

Obtém o tamanho de uma cadeia de caracteres usando a localidade atual ou uma que foi enviada. Essas são versões mais seguras do [strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md).

> [!IMPORTANT]
> **mbsnlen**, **mbsnlen_l**, **mbstrnlen**, e **mbstrnlen_l** não pode ser usado em aplicativos que são executados o tempo de execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
size_t strnlen(
   const char *str,
   size_t numberOfElements
);
size_t strnlen_s(
   const char *str,
   size_t numberOfElements
);
size_t wcsnlen(
   const wchar_t *str,
   size_t numberOfElements
);
size_t wcsnlen_s(
   const wchar_t *str,
   size_t numberOfElements
);
size_t _mbsnlen(
   const unsigned char *str,
   size_t numberOfElements
);
size_t _mbsnlen_l(
   const unsigned char *str,
   size_t numberOfElements,
   _locale_t locale
);
size_t _mbstrnlen(
   const char *str,
   size_t numberOfElements
);
size_t _mbstrnlen_l(
   const char *str,
   size_t numberOfElements,
   _locale_t locale
);
```

### <a name="parameters"></a>Parâmetros

*str*<br/>
Cadeia de caracteres terminada em nulo.

*numberOfElements*<br/>
O tamanho do buffer da cadeia de caracteres.

*locale*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor de retorno

Essas funções retornam o número de caracteres na cadeia de caracteres, sem incluir o caractere de terminação nula. Se houver um terminador nulo no primeiro *numberOfElements* bytes da cadeia de caracteres (ou caracteres largos para **wcsnlen**), em seguida, *numberOfElements* é retornado para indica a condição de erro; cadeias de caracteres terminada em nulo têm comprimentos são estritamente menor que *numberOfElements*.

**mbstrnlen** e **mbstrnlen_l** retornará -1 se a cadeia de caracteres contém um caractere de multibyte inválido.

## <a name="remarks"></a>Comentários

> [!NOTE]
> **strnlen** não é uma substituição para **strlen**; **strnlen** se destina a ser usado apenas para calcular o tamanho dos dados de entrada não confiáveis em um buffer de tamanho conhecido — por exemplo, um pacote de rede. **strnlen** calcula o comprimento, mas não mostram após o final do buffer se a cadeia de caracteres não finalizada. Em outras situações, use **strlen**. (O mesmo se aplica a **wcsnlen**, **mbsnlen**, e **mbstrnlen**.)

Cada uma dessas funções retorna o número de caracteres em *str*, não incluindo o caractere null de terminação. No entanto, **strnlen** e **strnlen_s** interpretar a cadeia de caracteres como uma cadeia de caracteres de byte único e, portanto, o valor de retorno sempre é igual ao número de bytes, mesmo que não contenha a cadeia de caracteres multibyte caracteres. **wcsnlen** e **wcsnlen_s** são versões de caractere largo de **strnlen** e **strnlen_s** respectivamente; os argumentos para **wcsnlen**  e **wcsnlen_s** são cadeias de caracteres largos e a contagem de caracteres estão em unidades de caractere largo. Caso contrário, **wcsnlen** e **strnlen** se comportam de forma idêntica, assim como **strnlen_s** e **wcsnlen_s**.

**strnlen**, **wcsnlen**, e **mbsnlen** não validar seus parâmetros. Se *str* é **nulo**, ocorre uma violação de acesso.

**strnlen_s** e **wcsnlen_s** validar seus parâmetros. Se *str* é **nulo**, as funções retornam 0.

**mbstrnlen** também valida seus parâmetros. Se *str* é **nulo**, ou se *numberOfElements* é maior do que **INT_MAX**, **mbstrnlen** gera uma exceção de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, **mbstrnlen** define **errno** para **EINVAL** e retorna -1.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tcsnlen**|**strnlen**|**strnlen**|**wcsnlen**|
|**tcscnlen**|**strnlen**|**_mbsnlen**|**wcsnlen**|
|**tcscnlen_l**|**strnlen**|**_mbsnlen_l**|**wcsnlen**|

**mbsnlen** e **mbstrnlen** retornar o número de caracteres multibyte em uma cadeia de caracteres multibyte. **mbsnlen** reconhece sequências de caracteres multibyte de acordo com a página de código multibyte que está atualmente em uso ou de acordo com a localidade que é transmitida; ele não de teste de validade de caracteres multibyte. **mbstrnlen** testa a validade de caracteres multibyte e reconhece as sequências de caracteres multibyte. Se a cadeia de caracteres que é passada para **mbstrnlen** contém um caractere inválido de vários bytes, **errno** é definido como **EILSEQ**.

O valor de saída é afetado pela configuração do **LC_CTYPE** configuração de categoria da localidade, consulte [setlocale, wsetlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções são idênticas, exceto que os que não têm o **_l** sufixo usam a localidade atual para este comportamento dependente de localidade e as versões que têm o **_l** sufixo em vez disso, use o parâmetro de localidade que é transmitido. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strnlen**, **strnlen_s**|\<string.h>|
|**wcsnlen**, **wcsnlen_s**|\<string.h> ou \<wchar.h>|
|**mbsnlen**, **mbsnlen_l**|\<mbstring.h>|
|**mbstrnlen**, **mbstrnlen_l**|\<stdlib.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_strnlen.c

#include <string.h>

int main()
{
   // str1 is 82 characters long. str2 is 159 characters long

   char* str1 = "The length of a string is the number of characters\n"
               "excluding the terminating null.";
   char* str2 = "strnlen takes a maximum size. If the string is longer\n"
                "than the maximum size specified, the maximum size is\n"
                "returned rather than the actual size of the string.";
   size_t len;
   size_t maxsize = 100;

   len = strnlen(str1, maxsize);
   printf("%s\n Length: %d \n\n", str1, len);

   len = strnlen(str2, maxsize);
   printf("%s\n Length: %d \n", str2, len);
}
```

```Output
The length of a string is the number of characters
excluding the terminating null.
Length: 82

strnlen takes a maximum size. If the string is longer
than the maximum size specified, the maximum size is
returned rather than the actual size of the string.
Length: 100
```

## <a name="see-also"></a>Consulte também

[Manipulação de cadeias de caracteres](../../c-runtime-library/string-manipulation-crt.md)<br/>
[Localidade](../../c-runtime-library/locale.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[setlocale, _wsetlocale](setlocale-wsetlocale.md)<br/>
[strncat, _strncat_l, wcsncat, _wcsncat_l, _mbsncat, _mbsncat_l](strncat-strncat-l-wcsncat-wcsncat-l-mbsncat-mbsncat-l.md)<br/>
[strncmp, wcsncmp, _mbsncmp, _mbsncmp_l](strncmp-wcsncmp-mbsncmp-mbsncmp-l.md)<br/>
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)<br/>
[strncpy_s, _strncpy_s_l, wcsncpy_s, _wcsncpy_s_l, _mbsncpy_s, _mbsncpy_s_l](strncpy-s-strncpy-s-l-wcsncpy-s-wcsncpy-s-l-mbsncpy-s-mbsncpy-s-l.md)<br/>
[strrchr, wcsrchr, _mbsrchr, _mbsrchr_l](strrchr-wcsrchr-mbsrchr-mbsrchr-l.md)<br/>
[_strset, _strset_l, _wcsset, _wcsset_l, _mbsset, _mbsset_l](strset-strset-l-wcsset-wcsset-l-mbsset-mbsset-l.md)<br/>
[strspn, wcsspn, _mbsspn, _mbsspn_l](strspn-wcsspn-mbsspn-mbsspn-l.md)<br/>
