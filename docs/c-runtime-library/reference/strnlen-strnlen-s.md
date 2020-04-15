---
title: strnlen, strnlen_s, wcsnlen, wcsnlen_s, _mbsnlen, _mbsnlen_l, _mbstrnlen, _mbstrnlen_l
ms.date: 4/2/2020
api_name:
- wcsnlen
- strnlen_s
- _mbstrnlen
- _mbsnlen_l
- _mbstrnlen_l
- strnlen
- wcsnlen_s
- _mbsnlen
- _o__mbsnlen
- _o__mbsnlen_l
- _o__mbstrnlen
- _o__mbstrnlen_l
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
- ntoskrnl.exe
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: db4fa65fa47dfe11d7ab56ffc5feee06f2634e2a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364464"
---
# <a name="strnlen-strnlen_s-wcsnlen-wcsnlen_s-_mbsnlen-_mbsnlen_l-_mbstrnlen-_mbstrnlen_l"></a>strnlen, strnlen_s, wcsnlen, wcsnlen_s, _mbsnlen, _mbsnlen_l, _mbstrnlen, _mbstrnlen_l

Obtém o tamanho de uma cadeia de caracteres usando a localidade atual ou uma que foi enviada. Essas são versões mais seguras do [strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md).

> [!IMPORTANT]
> **_mbsnlen**, **_mbsnlen_l**, **_mbstrnlen**e **_mbstrnlen_l** não podem ser usados em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*Str*<br/>
Cadeia de caracteres terminada em nulo.

*Numberofelements*<br/>
O tamanho do buffer da cadeia de caracteres.

*Localidade*<br/>
Localidade a usar.

## <a name="return-value"></a>Valor retornado

Essas funções retornam o número de caracteres na cadeia de caracteres, sem incluir o caractere de terminação nula. Se não houver exterminador nulo dentro dos primeiros *bytes numberOfElements* da string (ou caracteres largos para **wcsnlen),** então *numberOfElements* é devolvido para indicar a condição de erro; as seqüências terminadas por nulo têm comprimentos estritamente inferiores *ao númeroOfElements*.

**_mbstrnlen** e **_mbstrnlen_l** retorno -1 se a seqüência contiver um caractere multibyte inválido.

## <a name="remarks"></a>Comentários

> [!NOTE]
> **strnlen** não é um substituto para **strlen;** **strnlen** destina-se a ser usado apenas para calcular o tamanho dos dados não confiáveis de entrada em um buffer de tamanho conhecido — por exemplo, um pacote de rede. **strnlen** calcula o comprimento, mas não passa do fim do buffer se a seqüência não for terminada. Para outras situações, use **strlen**. (O mesmo se aplica a **wcsnlen,** **_mbsnlen**e **_mbstrnlen**.)

Cada uma dessas funções retorna o número de caracteres em *str*, sem incluir o caractere nulo final. No entanto, **strnlen** e **strnlen_s** interpretam a seqüência como uma seqüência de caracteres de byte único e, portanto, o valor de retorno é sempre igual ao número de bytes, mesmo que a seqüência contenha caracteres multibyte. **wcsnlen** e **wcsnlen_s** são versões de amplo caráter de **strnlen** e **strnlen_s** respectivamente; os argumentos para **wcsnlen** e **wcsnlen_s** são cordas de caracteres amplos e a contagem de caracteres estão em unidades de amplo caráter. Caso contrário, **wcsnlen** e **strnlen** se comportam de forma idêntica, assim como **strnlen_s** e **wcsnlen_s**.

**strnlen,** **wcsnlen**e **_mbsnlen** não validam seus parâmetros. Se *str* for **NULL,** uma violação de acesso ocorre.

**strnlen_s** e **wcsnlen_s** validam seus parâmetros. Se *str* for **NULL,** as funções retornam 0.

**_mbstrnlen** também valida seus parâmetros. Se *str* for **NULL**, ou se *numberOfElements* for maior que **INT_MAX,** **_mbstrnlen** gerar uma exceção de parâmetro inválido, conforme descrito na Validação [de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **_mbstrnlen** define **errno** para **EINVAL** e retorna -1.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tcsnlen**|**strnlen**|**strnlen**|**wcsnlen**|
|**_tcscnlen**|**strnlen**|**_mbsnlen**|**wcsnlen**|
|**_tcscnlen_l**|**strnlen**|**_mbsnlen_l**|**wcsnlen**|

**_mbsnlen** e **_mbstrnlen** retornar o número de caracteres multibytes em uma seqüência de caracteres multibytes. **_mbsnlen** reconhece seqüências de caracteres multibytes de acordo com a página de código multibyte que está atualmente em uso ou de acordo com o local que foi passado; não testa a validade de caracteres multibytes. **_mbstrnlen** testa a validade de caracteres multibytes e reconhece seqüências de caracteres multibytes. Se a seqüência de caracteres que for passada para **_mbstrnlen** contiver um caractere multibyte inválido, **errno** será definido **como EILSEQ**.

O valor de saída é afetado pela configuração da configuração da categoria **LC_CTYPE** do local; consulte [setlocale, _wsetlocale](setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções são idênticas, exceto que as que não têm o **sufixo _l** usam o local atual para este comportamento dependente da localidade e as versões que têm o **sufixo _l** em vez disso usam o parâmetro local que é passado. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**strnlen,** **strnlen_s**|\<string.h>|
|**wcsnlen**, **wcsnlen_s**|\<string.h> ou \<wchar.h>|
|**_mbsnlen**_mbsnlen **_mbsnlen_l**|\<mbstring.h>|
|**_mbstrnlen** **_mbstrnlen_l**|\<stdlib.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Confira também

[Manipulação de cordas](../../c-runtime-library/string-manipulation-crt.md)<br/>
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
