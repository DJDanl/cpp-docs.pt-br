---
title: setlocale, _wsetlocale
description: Descreve as funções de biblioteca de tempo setlocale _wsetlocalede execução do Microsoft C (CRT) e .
ms.date: 4/2/2020
api_name:
- _wsetlocale
- setlocale
- _o__wsetlocale
- _o_setlocale
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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 2834229839153c3154caadf71e5fb30d84ed2f1a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81353716"
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

### <a name="parameters"></a>Parâmetros

*Categoria*\
Categoria afetada pela localidade.

*Localidade*\
Especificador de localidade.

## <a name="return-value"></a>Valor retornado

Se for dado um *local e* *categoria* válidos, retorne um ponteiro para a seqüência associada à *localidade* e *categoria*especificadas . Se a *localidade* ou *categoria* não for válida, retorne um ponteiro nulo e as configurações de localização atuais do programa serão inalteradas.

Por exemplo, a chamada

```C
setlocale( LC_ALL, "en-US" );
```

define todas as categorias, retornando apenas a cadeia de caracteres

```Output
en-US
```

Você pode copiar a seqüência devolvida por **setlocale** para restaurar essa parte das informações locais do programa. O armazenamento local global ou de rosca é usado para a seqüência retornada pelo **setlocale**. Chamadas posteriores para **definir setlocale** sobreescrevem a seqüência, o que invalida ponteiros de seqüência retornados por chamadas anteriores.

## <a name="remarks"></a>Comentários

Use a função **setlocale** para definir, alterar ou consultar algumas ou todas as informações atuais do local do programa especificadas por *localidade* e *categoria*. *local refere-se* à localidade (país/região e idioma) para a qual você pode personalizar certos aspectos do seu programa. Algumas categorias de localidade dependentes incluem a formatação de datas e o formato de exibição de valores monetários. Se você definir a *localização* da seqüência padrão para um idioma que tenha vários formulários suportados no computador, você deverá verificar o valor de retorno **definido para** ver qual idioma está em vigor. Por exemplo, se você definir *local para* "chinês" o valor de retorno pode ser "simplificado chinês" ou "chinês-tradicional".

**_wsetlocale** é uma versão de amplo caráter do **setlocale;** o argumento *local e* o valor de retorno de **_wsetlocale** são strings de caracteres amplos. **_wsetlocale** e **setlocale** se comportem de forma idêntica de outra forma.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tsetlocale**|**Setlocale**|**Setlocale**|**_wsetlocale**|

O argumento *da categoria* especifica as partes das informações locais de um programa que são afetadas. As macros utilizadas para *a categoria* e as partes do programa que afetam são as seguintes:

|*bandeira categoria*|Afeta|
|-|-|
| **Lc_all** | Todas as categorias, conforme listado abaixo. |
| **LC_COLLATE** | O **strcoll**, **_stricoll**, **wcscoll**, **_wcsicoll**, **strxfrm**, **_strncoll**, **_strnicoll**, **_wcsncoll**, **_wcsnicoll**, e **wcsxfrm.** |
| **LC_CTYPE** | As funções de manuseio de caracteres (exceto **isdigit**, **isxdigit,** **mbstowcs**e **mbtowc**, que não são afetadas). |
| **LC_MONETARY** | Informações de formatação monetária retornadas pela função **localeconv.** |
| **LC_NUMERIC** | Caractere de ponto decimal para as rotinas de saída formatadas (como **printf),** para as rotinas de conversão de dados e para as informações de formatação não monetárias retornadas pela **localeconv**. Além do caractere de ponto decimal, **LC_NUMERIC** define o separador de milhares e a seqüência de controle de agrupamento retornada por [localeconv](localeconv.md). |
| **LC_TIME** | As funções **strftime** e **wcsftime.** |

Essa função valida o parâmetro category. Se o parâmetro de categoria não for um dos valores dados na tabela anterior, o manipulador de parâmetros inválidos será invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, a função define **errno** para **EINVAL** e retorna **NULL**.

O *argumento local é* um ponteiro para uma string que especifica o local. Para obter informações sobre o formato do argumento *local,* consulte [Nomes locais, idiomas e strings de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md). Se *locale* apontar para uma cadeia de caracteres vazia, a localidade será o ambiente nativo definido pela implementação. Um valor de **C** especifica o ambiente mínimo de conformidade ANSI para tradução C. O **local C** assume que todos os tipos de dados **char** são 1 byte e que seu valor é sempre menor que 256.

Na inicialização do programa, o equivalente da instrução a seguir é executado:

`setlocale( LC_ALL, "C" );`

O argumento *local* pode ter um nome local, uma seqüência de idiomas, uma seqüência de idiomas e código de país/região, uma página de código ou uma seqüência de idiomas, código de país/região e página de código. O conjunto de nomes locais disponíveis, idiomas, códigos de país/região e páginas de código inclui todos aqueles suportados pela API do Windows NLS. O conjunto de nomes locais suportados por **setlocale** são descritos em [Nomes locais, idiomas e strings país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md). O conjunto de strings de idioma e país/região suportados pelo **setlocale** estão listados em [Strings de idioma](../../c-runtime-library/language-strings.md) e [strings país/região](../../c-runtime-library/country-region-strings.md). Recomendamos o formato do nome da localidade para o desempenho e a capacidade de manutenção de cadeias de caracteres de localidade inseridas no código ou serializadas para armazenamento. As cadeias de caracteres de nome da localidade são menos prováveis de ser alteradas por uma atualização do sistema operacional do que o formato de idioma e país/região.

Um ponteiro nulo que é passado como o argumento *local* diz **setlocale** para consultar em vez de definir o ambiente internacional. Se o argumento *local for* um ponteiro nulo, a configuração atual do local do programa não será alterada. Em vez disso, **setlocale** retorna um ponteiro para a string que está associada à *categoria* da localização atual do segmento. Se o argumento de *categoria* for **LC_ALL,** a função reameda uma string que indique a configuração atual de cada categoria, separada por ponto e vírgula. Por exemplo, a sequência de chamadas

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

que é a string que está associada com a categoria **LC_ALL.**

Os exemplos a seguir dizem respeito à categoria **LC_ALL.** Qualquer uma das cordas". OCP" e ". ACP" pode ser usado em vez de um número de página de código para especificar o uso da página de código OEM padrão do usuário e da página de código ANSI padrão do usuário para esse nome local, respectivamente.

- `setlocale( LC_ALL, "" );`

   Define a localidade para o padrão, que é a página de código ANSI padrão do usuário obtida do sistema operacional. O nome local está definido como o valor retornado por [GetUserDefaultLocaleName](/windows/win32/api/winnls/nf-winnls-getuserdefaultlocalename). A página de código é definida como o valor retornado pelo [GetACP](/windows/win32/api/winnls/nf-winnls-getacp).

- `setlocale( LC_ALL, ".OCP" );`

   Define a localização para a página de código OEM atual obtida no sistema operacional. O nome local está definido como o valor retornado por [GetUserDefaultLocaleName](/windows/win32/api/winnls/nf-winnls-getuserdefaultlocalename). A página de código é definida como o valor [LOCALE_IDEFAULTCODEPAGE](/windows/win32/intl/locale-idefault-constants) para o nome local padrão do usuário por [GetLocaleInfoEx](/windows/win32/api/winnls/nf-winnls-getlocaleinfoex).

- `setlocale( LC_ALL, ".ACP" );`

   Define a localidade para a página de código ANSI obtida do sistema operacional. O nome local está definido como o valor retornado por [GetUserDefaultLocaleName](/windows/win32/api/winnls/nf-winnls-getuserdefaultlocalename). A página de código é definida como o valor [LOCALE_IDEFAULTANSICODEPAGE](/windows/win32/intl/locale-idefault-constants) para o nome local padrão do usuário por [GetLocaleInfoEx](/windows/win32/api/winnls/nf-winnls-getlocaleinfoex).

- `setlocale( LC_ALL, "<localename>" );`

   Define o local para o nome local indicado * \< *pelo nome local>. A página de código é definida como o valor [LOCALE_IDEFAULTANSICODEPAGE](/windows/win32/intl/locale-idefault-constants) para o nome local especificado por [GetLocaleInfoEx](/windows/win32/api/winnls/nf-winnls-getlocaleinfoex).

- `setlocale( LC_ALL, "<language>_<country>" );`

   Define o local para o idioma e * \<* país/região indicados pelo idioma>e * \<país>, *juntamente com a página de código padrão obtida no sistema operacional host. A página de código é definida como o valor [LOCALE_IDEFAULTANSICODEPAGE](/windows/win32/intl/locale-idefault-constants) para o nome local especificado por [GetLocaleInfoEx](/windows/win32/api/winnls/nf-winnls-getlocaleinfoex).

- `setlocale( LC_ALL, "<language>_<country>.<code_page>" );`

   Define o local para a página de idioma, país/região e código indicada pelo * \<idioma>, * * \<>de país *e * \<code_page>* strings. Você pode usar várias combinações de idioma, país/região e página de código. Por exemplo, esta chamada define a localidade para francês canadense com a página de código 1252:

   `setlocale( LC_ALL, "French_Canada.1252" );`

   Esta chamada define a localidade para francês canadense com a página de código ANSI padrão:

   `setlocale( LC_ALL, "French_Canada.ACP" );`

   Esta chamada define a localidade para francês canadense com a página de código OEM padrão:

   `setlocale( LC_ALL, "French_Canada.OCP" );`

- `setlocale( LC_ALL, "<language>" );`

   Define o local para o idioma indicado * \< *pelo idioma>, e usa o país/região padrão para o idioma especificado e a página de código ANSI padrão do usuário para esse país/região, conforme obtido no sistema operacional host. Por exemplo, as seguintes chamadas para **setlocale** são funcionalmente equivalentes:

   `setlocale( LC_ALL, "en-US" );`

   `setlocale( LC_ALL, "English" );`

   `setlocale( LC_ALL, "English_United States.1252" );`

   Recomendamos o primeiro formato para o desempenho e a capacidade de manutenção.

- `setlocale( LC_ALL, ".<code_page>" );`

   Define a página de código para o valor indicado por *<code_page>*, juntamente com o país/região e o idioma padrão (conforme definidos pelo sistema operacional do host) para a página de código especificada.

A categoria deve ser **LC_ALL** ou **LC_CTYPE** para efetuar uma alteração da página de código. Por exemplo, se o país/região padrão e o idioma do sistema operacional host forem "Estados Unidos" e "Inglês", as duas chamadas para **setlocale** são funcionalmente equivalentes:

`setlocale( LC_ALL, ".1252" );`

`setlocale( LC_ALL, "English_United States.1252");`

Para obter mais informações, consulte a diretiva de pragma [setlocale](../../preprocessor/setlocale.md) na [Referência de pré-processador C/C++](../../preprocessor/c-cpp-preprocessor-reference.md).

A função [_configthreadlocale](configthreadlocale.md) é usada para controlar se o **setlocale** afeta a localização de todos os segmentos em um programa ou apenas a localização do segmento de chamada.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**setlocale**|\<locale.h>|
|**_wsetlocale**|\<locale.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

[Nomes locais, idiomas e strings país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md)\
[_configthreadlocale](configthreadlocale.md)\
[_create_locale _wcreate_locale.](create-locale-wcreate-locale.md)\
[Localidade](../../c-runtime-library/locale.md)\
[Localeconv](localeconv.md)\
[_mbclen, mblen, _mblen_l](mbclen-mblen-mblen-l.md)\
[strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md)\
[mbstowcs, _mbstowcs_l](mbstowcs-mbstowcs-l.md)\
[mbtowc, _mbtowc_l](mbtowc-mbtowc-l.md)\
[_setmbcp](setmbcp.md)\
[strcoll Funções](../../c-runtime-library/strcoll-functions.md)\
[strftime, wcsftime, _strftime_l, _wcsftime_l](strftime-wcsftime-strftime-l-wcsftime-l.md)\
[strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)\
[wcssetos, _wcstombs_l](wcstombs-wcstombs-l.md)\
[wctomb, _wctomb_l](wctomb-wctomb-l.md)
