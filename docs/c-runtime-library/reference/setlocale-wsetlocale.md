---
title: setlocale, _wsetlocale
description: Descreve as funções de biblioteca do Microsoft C Runtime (CRT) setlocale e _wsetlocale.
ms.date: 01/28/2020
api_name:
- _wsetlocale
- setlocale
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
- api-ms-win-crt-locale-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _wsetlocale
- _tsetlocale
- setlocale
helpviewer_keywords:
- wsetlocale function
- setlocale function
- tsetlocale function
- locales, defining
- _tsetlocale function
- defining locales
- _wsetlocale function
ms.assetid: 3ffb684e-5990-4202-9553-b5339af9520d
no-loc:
- setlocale
- _wsetlocale
ms.openlocfilehash: b1c7b739e671caebc51022945a369a632ecebb9e
ms.sourcegitcommit: f38f770bfda1c174d2b81fabda7c893b15bd83a1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/20/2020
ms.locfileid: "77473857"
---
# <a name="setlocale-_wsetlocale"></a>setlocale, _wsetlocale

Define ou recupera a localidade do tempo de execução.

## <a name="syntax"></a>Sintaxe

```C
char *setlocale(
   int category,
   const char *locale
);
wchar_t *_wsetlocale(
   int category,
   const wchar_t *locale
);
```

### <a name="parameters"></a>parâmetros

\ de *categoria*
Categoria afetada pela localidade.

\ de *localidade*
Especificador de localidade.

## <a name="return-value"></a>Valor retornado

Se uma *localidade* e *categoria* válidas forem fornecidas, o retornará um ponteiro para a cadeia de caracteres associada à *localidade* e à *categoria*especificadas. Se a *localidade* ou *categoria* não for válida, o retornará um ponteiro nulo e as configurações de localidade atuais do programa ficarão inalteradas.

Por exemplo, a chamada

```C
setlocale( LC_ALL, "en-US" );
```

define todas as categorias, retornando apenas a cadeia de caracteres

```Output
en-US
```

Você pode copiar a cadeia de caracteres retornada por **setlocale** para restaurar essa parte das informações de localidade do programa. O armazenamento local global ou de thread é usado para a cadeia de caracteres retornada por **setlocale**. As chamadas posteriores para **setlocaling** substituem a cadeia de caracteres, que invalida os ponteiros de cadeia de caracteres retornados por chamadas anteriores.

## <a name="remarks"></a>Comentários

Use a função **setlocalize** para definir, alterar ou consultar algumas ou todas as informações de localidade do programa atual especificadas por *localidade* e *categoria*. *locale* refere-se à localidade (país/região e idioma) para a qual você pode personalizar determinados aspectos do seu programa. Algumas categorias de localidade dependentes incluem a formatação de datas e o formato de exibição de valores monetários. Se você definir a *localidade* como a cadeia de caracteres padrão para um idioma que tenha vários formulários com suporte no seu computador, deverá verificar o valor de retorno de **setlocalize** para ver qual idioma está em vigor. Por exemplo, se você definir *locale* como "chinês", o valor de retorno poderá ser "chinês simplificado" ou "chinês-tradicional".

**_wsetlocale** é uma versão de caractere largo do **setlocale**; o argumento de *localidade* e o valor de retorno de **_wsetlocale** são cadeias de caracteres largos. o **_wsetlocale** e o **setlocaling** se comportam de forma idêntica.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tsetlocale**|**setlocale**|**setlocale**|**_wsetlocale**|

O argumento *Category* especifica as partes das informações de localidade de um programa que são afetadas. As macros usadas para a *categoria* e as partes do programa que elas afetam são as seguintes:

|sinalizador de *categoria*|Afeta|
|-|-|
| **LC_ALL** | Todas as categorias, conforme listado abaixo. |
| **LC_COLLATE** | As funções **strcoll**, **_stricoll**, **wcscoll**, **_wcsicoll**, **strxfrm**, **_strncoll**, **_strnicoll**, **_wcsncoll**, **_wcsnicoll**e **wcsxfrm** . |
| **LC_CTYPE** | As funções de manipulação de caracteres (exceto **IsDigit**, **isxdigit**, **mbstowcs**e **mbtowc**, que não são afetadas). |
| **LC_MONETARY** | Informações de formatação monetária retornadas pela função **localeconv** . |
| **LC_NUMERIC** | Caractere de ponto decimal para as rotinas de saída formatadas (como **printf**), para as rotinas de conversão de dados e para as informações de formatação não monetária retornadas por **localeconv**. Além do caractere de ponto decimal, **LC_NUMERIC** define o separador de milhar e a cadeia de caracteres de controle de agrupamento retornada por [localeconv](localeconv.md). |
| **LC_TIME** | As funções **strftime** e **wcsftime** . |

Essa função valida o parâmetro category. Se o parâmetro Category não for um dos valores fornecidos na tabela anterior, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função definirá **errno** como **EINVAL** e retornará **NULL**.

O argumento de *localidade* é um ponteiro para uma cadeia de caracteres que especifica a localidade. Para obter informações sobre o formato do argumento de *localidade* , consulte [nomes de localidade, idiomas e cadeias de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md). Se *locale* apontar para uma cadeia de caracteres vazia, a localidade será o ambiente nativo definido pela implementação. Um valor de **C** especifica o ambiente de conformidade ANSI mínimo para conversão de C. A localidade **C** pressupõe que todos os tipos de dados **Char** sejam 1 byte e que seu valor seja sempre menor que 256.

Na inicialização do programa, o equivalente da instrução a seguir é executado:

`setlocale( LC_ALL, "C" );`

O argumento de *localidade* pode usar um nome de localidade, uma cadeia de caracteres de idioma, uma cadeia de caracteres de idioma e um código de país/região, uma página de código ou uma cadeia de caracteres de idioma, código de país/região e página de código. O conjunto de nomes de localidade disponíveis, idiomas, códigos de país/região e páginas de código inclui todos aqueles com suporte da API NLS do Windows. O conjunto de nomes de localidade com suporte do **setlocaling** é descrito em [nomes de localidade, linguagens e cadeias de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md). O conjunto de cadeias de caracteres de idioma e país/região com suporte no **setlocale** são listados em cadeias de caracteres de [idioma](../../c-runtime-library/language-strings.md) e de [país/região](../../c-runtime-library/country-region-strings.md). Recomendamos o formato do nome da localidade para o desempenho e a capacidade de manutenção de cadeias de caracteres de localidade inseridas no código ou serializadas para armazenamento. As cadeias de caracteres de nome da localidade são menos prováveis de ser alteradas por uma atualização do sistema operacional do que o formato de idioma e país/região.

Um ponteiro nulo que é passado como o argumento *locale* informa **setlocalize** para consultar em vez de para definir o ambiente internacional. Se o argumento de *localidade* for um ponteiro nulo, a configuração de localidade atual do programa não será alterada. Em vez disso, **setlocalize** retorna um ponteiro para a cadeia de caracteres associada à *categoria* da localidade atual do thread. Se o argumento *Category* for **LC_ALL**, a função retornará uma cadeia de caracteres que indica a configuração atual de cada categoria, separada por ponto e vírgula. Por exemplo, a sequência de chamadas

```C
// Set all categories and return "en-US"
setlocale(LC_ALL, "en-US");
// Set only the LC_MONETARY category and return "fr-FR"
setlocale(LC_MONETARY, "fr-FR");
printf("%s\n", setlocale(LC_ALL, NULL));
```

retorna

```Output
LC_COLLATE=en-US;LC_CTYPE=en-US;LC_MONETARY=fr-FR;LC_NUMERIC=en-US;LC_TIME=en-US
```

que é a cadeia de caracteres associada à categoria de **LC_ALL** .

Os exemplos a seguir pertencem à categoria de **LC_ALL** . Qualquer uma das cadeias de caracteres ". OCP "e". ACP "pode ser usado em vez de um número de página de código para especificar o uso da página de código OEM padrão do usuário e da página de código ANSI padrão do usuário para esse nome de localidade, respectivamente.

- `setlocale( LC_ALL, "" );`

   Define a localidade para o padrão, que é a página de código ANSI padrão do usuário obtida do sistema operacional. O nome da localidade é definido como o valor retornado por [GetUserDefaultLocaleName](/windows/win32/api/winnls/nf-winnls-getuserdefaultlocalename). A página de código é definida com o valor retornado por [GetACP](/windows/win32/api/winnls/nf-winnls-getacp).

- `setlocale( LC_ALL, ".OCP" );`

   Define a localidade para a página de código OEM atual obtida do sistema operacional. O nome da localidade é definido como o valor retornado por [GetUserDefaultLocaleName](/windows/win32/api/winnls/nf-winnls-getuserdefaultlocalename). A página de código é definida como o valor [LOCALE_IDEFAULTCODEPAGE](/windows/win32/intl/locale-idefault-constants) para o nome de localidade padrão do usuário por [GetLocaleInfoEx](/windows/win32/api/winnls/nf-winnls-getlocaleinfoex).

- `setlocale( LC_ALL, ".ACP" );`

   Define a localidade para a página de código ANSI obtida do sistema operacional. O nome da localidade é definido como o valor retornado por [GetUserDefaultLocaleName](/windows/win32/api/winnls/nf-winnls-getuserdefaultlocalename). A página de código é definida como o valor [LOCALE_IDEFAULTANSICODEPAGE](/windows/win32/intl/locale-idefault-constants) para o nome de localidade padrão do usuário por [GetLocaleInfoEx](/windows/win32/api/winnls/nf-winnls-getlocaleinfoex).

- `setlocale( LC_ALL, "<localename>" );`

   Define a localidade para o nome da localidade que é indicado por *\<localename>* . A página de código é definida como o valor de [LOCALE_IDEFAULTANSICODEPAGE](/windows/win32/intl/locale-idefault-constants) para o nome de localidade especificado por [GetLocaleInfoEx](/windows/win32/api/winnls/nf-winnls-getlocaleinfoex).

- `setlocale( LC_ALL, "<language>_<country>" );`

   Define a localidade para o idioma e o país/região indicados por *\<language>* e *\<country>* , juntamente com a página de código padrão obtida do sistema operacional do host. A página de código é definida como o valor de [LOCALE_IDEFAULTANSICODEPAGE](/windows/win32/intl/locale-idefault-constants) para o nome de localidade especificado por [GetLocaleInfoEx](/windows/win32/api/winnls/nf-winnls-getlocaleinfoex).

- `setlocale( LC_ALL, "<language>_<country>.<code_page>" );`

   Define a localidade para o idioma, o país/região e a página de código indicados pelo *> de idiomas\<* , *\<país >* e *\<* code_page > cadeias de caracteres. Você pode usar várias combinações de idioma, país/região e página de código. Por exemplo, esta chamada define a localidade para francês canadense com a página de código 1252:

   `setlocale( LC_ALL, "French_Canada.1252" );`

   Esta chamada define a localidade para francês canadense com a página de código ANSI padrão:

   `setlocale( LC_ALL, "French_Canada.ACP" );`

   Esta chamada define a localidade para francês canadense com a página de código OEM padrão:

   `setlocale( LC_ALL, "French_Canada.OCP" );`

- `setlocale( LC_ALL, "<language>" );`

   Define a localidade para o idioma que é indicado por *\<language>* e usa o país/região padrão para o idioma especificado e a página de código ANSI padrão do usuário para esse país/região conforme obtidos do sistema operacional do host. Por exemplo, as seguintes chamadas para **setlocaling** são funcionalmente equivalentes:

   `setlocale( LC_ALL, "en-US" );`

   `setlocale( LC_ALL, "English" );`

   `setlocale( LC_ALL, "English_United States.1252" );`

   Recomendamos o primeiro formato para o desempenho e a capacidade de manutenção.

- `setlocale( LC_ALL, ".<code_page>" );`

   Define a página de código para o valor indicado por *<code_page>* , juntamente com o país/região e o idioma padrão (conforme definidos pelo sistema operacional do host) para a página de código especificada.

A categoria deve ser **LC_ALL** ou **LC_CTYPE** para afetar uma alteração de página de código. Por exemplo, se o país/região padrão e idioma do sistema operacional do host forem "Estados Unidos" e "inglês", as duas chamadas a seguir para **setlocaling** serão funcionalmente equivalentes:

`setlocale( LC_ALL, ".1252" );`

`setlocale( LC_ALL, "English_United States.1252");`

Para obter mais informações, consulte a diretiva de pragma [setlocale](../../preprocessor/setlocale.md) na [Referência de pré-processador C/C++](../../preprocessor/c-cpp-preprocessor-reference.md).

A função [_configthreadlocale](configthreadlocale.md) é usada para controlar se **setlocaling** afeta a localidade de todos os threads em um programa ou apenas a localidade do thread de chamada.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**setlocale**|\<locale.h>|
|**_wsetlocale**|\<locale.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_setlocale.c
//
// This program demonstrates the use of setlocale when
// using two independent threads.
//

#include <locale.h>
#include <process.h>
#include <windows.h>
#include <stdio.h>
#include <time.h>

#define BUFF_SIZE 100

// Retrieve the date in the current
// locale's format.
int get_date(unsigned char* str)
{
    __time64_t ltime;
    struct tm  thetime;

    // Retrieve the current time
    _time64(&ltime);
    _gmtime64_s(&thetime, &ltime);

    // Format the current time structure into a string
    // "%#x" is the long date representation in the
    // current locale
    if (!strftime((char *)str, BUFF_SIZE, "%#x",
                  (const struct tm *)&thetime))
    {
        printf("strftime failed!\n");
        return -1;
    }
    return 0;
}

// This thread sets its locale to the argument
// and prints the date.
uintptr_t __stdcall SecondThreadFunc( void* pArguments )
{
    unsigned char str[BUFF_SIZE];
    char * locale = (char *)pArguments;

    // Set the thread locale
    printf("The thread locale is now set to %s.\n",
           setlocale(LC_ALL, locale));

    // Retrieve the date string from the helper function
    if (get_date(str) == 0)
    {
        printf("The date in %s locale is: '%s'\n", locale, str);
    }

    _endthreadex( 0 );
    return 0;
}

// The main thread sets the locale to English
// and then spawns a second thread (above) and prints the date.
int main()
{
    HANDLE          hThread;
    unsigned        threadID;
    unsigned char   str[BUFF_SIZE];

    // Enable per-thread locale causes all subsequent locale
    // setting changes in this thread to only affect this thread.
    _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);

    // Set the locale of the main thread to US English.
    printf("The thread locale is now set to %s.\n",
           setlocale(LC_ALL, "en-US"));

    // Create the second thread with a German locale.
    // Our thread function takes an argument of the locale to use.
    hThread = (HANDLE)_beginthreadex( NULL, 0, &SecondThreadFunc,
                                      "de-DE", 0, &threadID );

    if (get_date(str) == 0)
    {
        // Retrieve the date string from the helper function
        printf("The date in en-US locale is: '%s'\n\n", str);
    }

    // Wait for the created thread to finish.
    WaitForSingleObject( hThread, INFINITE );

    // Destroy the thread object.
    CloseHandle( hThread );
}
```

```Output
The thread locale is now set to en-US.
The time in en-US locale is: 'Wednesday, May 12, 2004'

The thread locale is now set to de-DE.
The time in de-DE locale is: 'Mittwoch, 12. Mai 2004'
```

## <a name="see-also"></a>Confira também

[Nomes de localidade, idiomas e cadeias de caracteres de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md)\
[_configthreadlocale](configthreadlocale.md)\
[_create_locale, _wcreate_locale](create-locale-wcreate-locale.md)\
[Localidade](../../c-runtime-library/locale.md)\
[localeconv](localeconv.md)\
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)\
[strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md)\
[mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md)\
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)\
[_setmbcp](setmbcp.md)\
[Funções strcoll](../../c-runtime-library/strcoll-functions.md)\
[strftime, wcsftime, _strftime_l, _wcsftime_l](strftime-wcsftime-strftime-l-wcsftime-l.md)\
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)\
[wcstombs, _wcstombs_l](wcstombs-wcstombs-l.md)\
[wctomb, _wctomb_l](wctomb-wctomb-l.md)
