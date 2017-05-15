---
title: setlocale, _wsetlocale | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wsetlocale
- setlocale
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
- api-ms-win-crt-locale-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _wsetlocale
- _tsetlocale
- setlocale
dev_langs:
- C++
helpviewer_keywords:
- wsetlocale function
- setlocale function
- tsetlocale function
- locales, defining
- _tsetlocale function
- defining locales
- _wsetlocale function
ms.assetid: 3ffb684e-5990-4202-9553-b5339af9520d
caps.latest.revision: 31
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 5a83ef5640a72dcd2ff8f7f35c587789dff35d61
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="setlocale-wsetlocale"></a>setlocale, _wsetlocale
Define ou recupera a localidade do tempo de execução.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *setlocale(  
   int category,  
   const char *locale   
);  
wchar_t *_wsetlocale(  
   int category,  
   const wchar_t *locale   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `category`  
 Categoria afetada pela localidade.  
  
 `locale`  
 Especificador de localidade.  
  
## <a name="return-value"></a>Valor de retorno  
 Se `locale` e `category` válidos forem fornecidos, retornará um ponteiro para a cadeia de caracteres associada a `locale` e `category` especificados. Se `locale` ou `category` for inválido, retornará um ponteiro nulo e as configurações de localidade atuais do programa não serão modificadas.  
  
 Por exemplo, a chamada  
  
 `setlocale( LC_ALL, "en-US" );`  
  
 define todas as categorias, retornando apenas a cadeia de caracteres  
  
 `en-US`  
  
 Você pode copiar a cadeia de caracteres retornada por `setlocale` para restaurar essa parte das informações de localidade do programa. O armazenamento de thread local ou global é usado para a cadeia de caracteres retornada por `setlocale`. As chamadas posteriores para `setlocale` substituirão a cadeia de caracteres, o que invalida os ponteiros de cadeia de caracteres retornados pelas chamadas anteriores.  
  
## <a name="remarks"></a>Comentários  
 Use a função `setlocale` para definir, modificar ou consultar algumas ou todas as informações de localidade do programa atual especificadas por `locale` e `category`. `locale` refere-se à localidade (país/região e idioma) para a qual você pode personalizar alguns aspectos do programa. Algumas categorias de localidade dependentes incluem a formatação de datas e o formato de exibição de valores monetários. Se você definir `locale` como a cadeia de caracteres padrão para um idioma que tenha várias formas com suporte em seu computador, verifique o valor de retorno de `setlocale` para ver que idioma é aplicado. Por exemplo, se você definir `locale` como “chinês”, o valor de retorno poderá ser “chinês simplificado” ou “chinês tradicional”.  
  
 `_wsetlocale` é uma versão caracteres largos de `setlocale`; o argumento `locale` e o valor de retorno de `_wsetlocale` são cadeias de caracteres largos. Caso contrário, `_wsetlocale` e `setlocale` se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tsetlocale`|`setlocale`|`setlocale`|`_wsetlocale`|  
  
 O argumento `category` especifica as partes das informações de localidade de um programa que são afetadas. As macros usadas para `category` e as partes de programa que afetam são:  
  
 `LC_ALL`  
 Todas as categorias na lista a seguir.  
  
 `LC_COLLATE`  
 As funções `strcoll`, `_stricoll`, `wcscoll`, `_wcsicoll`, `strxfrm`, `_strncoll`, `_strnicoll`, `_wcsncoll`, `_wcsnicoll` e `wcsxfrm`.  
  
 `LC_CTYPE`  
 As funções de manipulação de caracteres (exceto `isdigit`, `isxdigit`, `mbstowcs` e `mbtowc`, que não são afetadas).  
  
 `LC_MONETARY`  
 Informações de formatação monetária retornadas pela função `localeconv`.  
  
 `LC_NUMERIC`  
 Caractere de ponto decimal para rotinas de saída formatadas (como `printf`), para rotinas de conversão de dados, e para informações não monetárias de formatação retornadas por `localeconv`. Além do caractere de ponto decimal, `LC_NUMERIC` também define o separador de milhares e a cadeia de caracteres de controle de agrupamento retornada por [localeconv](../../c-runtime-library/reference/localeconv.md).  
  
 `LC_TIME`  
 As funções `strftime` e `wcsftime`.  
  
 Essa função valida o parâmetro category. Se o parâmetro category não for um dos valores fornecidos na tabela anterior, o manipulador de parâmetro inválido será chamado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função definirá `errno` como `EINVAL` e retornará `NULL`.  
  
 O argumento `locale` é um ponteiro para uma cadeia de caracteres que especifica a localidade. Para obter informações sobre o formato do argumento `locale`, consulte [Nomes de localidades, idiomas e cadeias de caracteres de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md). Se `locale` apontar para uma cadeia de caracteres vazia, a localidade será o ambiente nativo definido pela implementação. Um valor de `C` especifica o ambiente em conformidade mínima com ANSI para a conversão em C. A localidade `C` pressupõe que todos os tipos de dados `char` tenham 1 byte e seu valor seja sempre menor que 256.  
  
 Na inicialização do programa, o equivalente da instrução a seguir é executado:  
  
 `setlocale( LC_ALL, "C" );`  
  
 O argumento `locale` pode ter um nome de localidade, uma cadeia de caracteres de idioma, uma cadeia de caracteres de idioma e código de país/região, uma página de código ou uma cadeia de caracteres de idioma, código de país/região e página de código. O conjunto disponível de nomes de localidade, idiomas, códigos de país/região e páginas de código inclui tudo o que é suportado pela API NLS do Windows, exceto as páginas de código que exigem mais de dois bytes por caractere, como UTF-7 e UTF-8. Se você fornecer um valor de página de código de UTF-7 ou UTF-8, `setlocale` falhará e retornará NULL. O conjunto de nomes de localidades com suporte no `setlocale` é descrito em [Nomes de localidades, idiomas e cadeias de caracteres de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md). O conjunto de idiomas e cadeias de caracteres de país/região com suporte no `setlocale` é listado em [Cadeias de caracteres de idiomas](../../c-runtime-library/language-strings.md) e [Cadeias de caracteres de país/região](../../c-runtime-library/country-region-strings.md). Recomendamos o formato do nome da localidade para o desempenho e a capacidade de manutenção de cadeias de caracteres de localidade inseridas no código ou serializadas para armazenamento. As cadeias de caracteres de nome da localidade são menos prováveis de ser alteradas por uma atualização do sistema operacional do que o formato de idioma e país/região.  
  
 Um ponteiro nulo que é passado quando o argumento `locale` diz para `setlocale` consultar em vez de para definir o ambiente internacional. Se o argumento `locale` for um ponteiro nulo, a configuração de localidade atual do programa não será alterada. Em vez disso, `setlocale` retorna um ponteiro para a cadeia de caracteres associada a `category` de localidade do thread atual. Se o argumento `category` for `LC_ALL`, a função retornará uma cadeia de caracteres que indica a configuração atual de cada categoria, separada por ponto-e-vírgula. Por exemplo, a sequência de chamadas  
  
 `// Set all categories and return "en-US"`  
  
 `setlocale(LC_ALL, "en-US");`  
  
 `// Set only the LC_MONETARY category and return "fr-FR"`  
  
 `setlocale(LC_MONETARY, "fr-FR");`  
  
 `printf("%s\n", setlocale(LC_ALL, NULL));`  
  
 retorna  
  
 `LC_COLLATE=en-US;LC_CTYPE=en-US;LC_MONETARY=fr-FR;LC_NUMERIC=en-US;LC_TIME=en-US`  
  
 qual é a cadeia de caracteres associada à categoria `LC_ALL`.  
  
 Os exemplos a seguir pertencem à categoria `LC_ALL`. Qualquer uma das cadeias de caracteres “.OCP” e “.ACP” pode ser usada em vez de um número de página de código para especificar o uso da página de código OEM do usuário padrão e da página de código ANSI padrão do usuário, respectivamente.  
  
 `setlocale( LC_ALL, "" );`  
 Define a localidade para o padrão, que é a página de código ANSI padrão do usuário obtida do sistema operacional.  
  
 `setlocale( LC_ALL, ".OCP" );`  
 Define explicitamente a localidade para a página de código OEM obtida do sistema operacional.  
  
 `setlocale( LC_ALL, ".ACP" );`  
 Define a localidade para a página de código ANSI obtida do sistema operacional.  
  
 `setlocale( LC_ALL, "<localename>" );`  
 Define a localidade para o nome da localidade que é indicado por *\<localename>*.  
  
 `setlocale( LC_ALL, "<language>_<country>" );`  
 Define a localidade para o idioma e o país/região indicados por *\<language>* e *\<country>*, juntamente com a página de código padrão obtida do sistema operacional do host.  
  
 `setlocale( LC_ALL, "<language>_<country>.<code_page>" );`  
 Define a localidade para o idioma, o país/região e a página de código indicados pelas cadeias de caracteres *\<language>*, *\<country>* e *<code_page>*. Você pode usar várias combinações de idioma, país/região e página de código. Por exemplo, esta chamada define a localidade para francês canadense com a página de código 1252:  
  
 `setlocale( LC_ALL, "French_Canada.1252" );`  
  
 Esta chamada define a localidade para francês canadense com a página de código ANSI padrão:  
  
 `setlocale( LC_ALL, "French_Canada.ACP" );`  
  
 Esta chamada define a localidade para francês canadense com a página de código OEM padrão:  
  
 `setlocale( LC_ALL, "French_Canada.OCP" );`  
  
 `setlocale( LC_ALL, "<language>" );`  
 Define a localidade para o idioma que é indicado por *\<language>* e usa o país/região padrão para o idioma especificado e a página de código ANSI padrão do usuário para esse país/região conforme obtidos do sistema operacional do host. Por exemplo, as seguintes chamadas para `setlocale` são funcionalmente equivalentes:  
  
 `setlocale( LC_ALL, "en-US" );`  
  
 `setlocale( LC_ALL, "English" );`  
  
 `setlocale( LC_ALL, "English_United States.1252" );`  
  
 Recomendamos o primeiro formato para o desempenho e a capacidade de manutenção.  
  
 `setlocale( LC_ALL, ".<code_page>" );`  
 Define a página de código para o valor indicado por *<code_page>*, juntamente com o país/região e o idioma padrão (conforme definidos pelo sistema operacional do host) para a página de código especificada.  
  
 A categoria deve ser `LC_ALL` ou `LC_CTYPE` para efetivar uma alteração de página de código. Por exemplo, se o país/região e o idioma padrão do sistema operacional do host forem “Estados Unidos” e “inglês”, estas duas chamadas para `setlocale` serão funcionalmente equivalentes:  
  
 `setlocale( LC_ALL, ".1252" );`  
  
 `setlocale( LC_ALL, "English_United States.1252");`  
  
 Para obter mais informações, consulte a diretiva de pragma [setlocale](../../preprocessor/setlocale.md) na [Referência de pré-processador C/C++](../../preprocessor/c-cpp-preprocessor-reference.md).  
  
 A função [_configthreadlocale](../../c-runtime-library/reference/configthreadlocale.md) é usada para controlar se `setlocale` afeta a localidade de todos os threads em um programa ou somente a localidade do thread da chamada.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`setlocale`|\<locale.h>|  
|`_wsetlocale`|\<locale.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
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
  
    // Configure per-thread locale to cause all subsequently created   
    // threads to have their own locale.  
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
  
## <a name="see-also"></a>Consulte também  
 [Nomes de localidade, idiomas e cadeias de caracteres de país/região](../../c-runtime-library/locale-names-languages-and-country-region-strings.md)   
 [_configthreadlocale](../../c-runtime-library/reference/configthreadlocale.md)   
 [_create_locale, _wcreate_locale](../../c-runtime-library/reference/create-locale-wcreate-locale.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [localeconv](../../c-runtime-library/reference/localeconv.md)   
 [_mbclen, mblen, _mblen_l](../../c-runtime-library/reference/mbclen-mblen-mblen-l.md)   
 [strlen, wcslen, _mbslen, _mbslen_l, _mbstrlen, _mbstrlen_l](../../c-runtime-library/reference/strlen-wcslen-mbslen-mbslen-l-mbstrlen-mbstrlen-l.md)   
 [mbstowcs, _mbstowcs_l](../../c-runtime-library/reference/mbstowcs-mbstowcs-l.md)   
 [mbtowc, _mbtowc_l](../../c-runtime-library/reference/mbtowc-mbtowc-l.md)   
 [_setmbcp](../../c-runtime-library/reference/setmbcp.md)   
 [Funções strcoll](../../c-runtime-library/strcoll-functions.md)   
 [strftime, wcsftime, _strftime_l, _wcsftime_l](../../c-runtime-library/reference/strftime-wcsftime-strftime-l-wcsftime-l.md)   
 [strxfrm, wcsxfrm, _strxfrm_l, _wcsxfrm_l](../../c-runtime-library/reference/strxfrm-wcsxfrm-strxfrm-l-wcsxfrm-l.md)   
 [wcstombs, _wcstombs_l](../../c-runtime-library/reference/wcstombs-wcstombs-l.md)   
 [wctomb, _wctomb_l](../../c-runtime-library/reference/wctomb-wctomb-l.md)
