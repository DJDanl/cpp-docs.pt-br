---
title: "strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_wcstok_s_l"
  - "_mbstok_s_l"
  - "_mbstok_s"
  - "strtok_s"
  - "wcstok_s"
  - "_strtok_s_l"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-multibyte-l1-1-0.dll"
  - "api-ms-win-crt-string-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_tcstok_s_l"
  - "_wcstok_s_l"
  - "_tcstok_s"
  - "_mbstok_s_l"
  - "strtok_s"
  - "wcstok_s"
  - "_mbstok_s"
  - "_strtok_s_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _mbstok_s"
  - "Função _mbstok_s_l"
  - "Função _strtok_s_l"
  - "Função _tcstok_s"
  - "Função _tcstok_s_l"
  - "Função _wcstok_s_l"
  - "Função mbstok_s"
  - "Função mbstok_s_l"
  - "cadeias de caracteres [C++], procurando"
  - "Função strtok_s"
  - "Função strtok_s_l"
  - "tokens, localizando em cadeias de caracteres"
  - "Função wcstok_s"
  - "Função wcstok_s_l"
ms.assetid: 7696c972-f83b-4617-8c82-95973e9fdb46
caps.latest.revision: 28
caps.handback.revision: 26
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# strtok_s, _strtok_s_l, wcstok_s, _wcstok_s_l, _mbstok_s, _mbstok_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Localiza o próximo token em uma cadeia de caracteres, usando a localidade atual ou uma localidade que é transmitida.  Essas versões de [strtok, \_strtok\_l, wcstok, \_wcstok\_l, \_mbstok, \_mbstok\_l](../Topic/strtok,%20_strtok_l,%20wcstok,%20_wcstok_l,%20_mbstok,%20_mbstok_l.md) têm aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
> [!IMPORTANT]
>  `_mbstok_s` e `_mbstok_s_l` não podem ser usados em aplicativos executados no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
  
      char *strtok_s(  
char *strToken,  
const char *strDelimit,  
   char **context  
);  
char *_strtok_s_l(  
char *strToken,  
const char *strDelimit,  
   char **context,  
_locale_tlocale  
);  
wchar_t *wcstok_s(  
wchar_t *strToken,  
const wchar_t *strDelimit,   
   wchar_t**context  
);  
wchar_t *_wcstok_s_l(  
wchar_t *strToken,  
const wchar_t *strDelimit,   
   wchar_t**context,  
_locale_tlocale  
);  
unsigned char *_mbstok_s(  
unsigned char*strToken,  
const unsigned char *strDelimit,   
   char **context  
);  
unsigned char *_mbstok_s(  
unsigned char*strToken,  
const unsigned char *strDelimit,   
   char **context,  
_locale_tlocale  
);  
```  
  
#### Parâmetros  
 `strToken`  
 Cadeia de caracteres que contém o token ou os tokens.  
  
 `strDelimit`  
 Conjunto de caracteres do delimitador.  
  
 `context`  
 Usado para armazenar informações da posição entre as chamadas para `strtok_s`  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Retorna um ponteiro para o próximo token localizado em `strToken`.  Retornam `NULL` quando não mais token é encontrado.  Cada chamada para alterar `strToken` substituindo um caractere de `NULL` para o primeiro delimitador que ocorre após o token retornado.  
  
### Condições de erro  
  
|`strToken`|`strDelimit`|`context`|Valor de retorno|`errno`|  
|----------------|------------------|---------------|----------------------|-------------|  
|`NULL`|any|ponteiro para um ponteiro nulo|`NULL`|`EINVAL`|  
|any|`NULL`|any|`NULL`|`EINVAL`|  
|any|any|`NULL`|`NULL`|`EINVAL`|  
  
 Se `strToken` é `NULL` mas o contexto é um ponteiro para um ponteiro válido de contexto, não há nenhum erro.  
  
## Comentários  
 A função de `strtok_s` localiza o próximo token em `strToken`.  O conjunto de caracteres em `strDelimit` especifica possíveis delimitadores de token a ser localizado em `strToken` na chamada atual.  `wcstok_s` e `_mbstok_s`são versões de ampla caractere e de multibyte\- caractere de `strtok_s`.  Os argumentos e os valores de retorno de `wcstok_s` e `_wcstok_s_l` são cadeias de caracteres de ampla caractere; essas de `_mbstok_s` e `_mbstok_s_l` são cadeias de caracteres de multibyte\- caractere.  Essas três funções se comportam de forma idêntica.  
  
 Essa função valida seus parâmetros.  Se uma condição de erro ocorrer, como na tabela de condições de erro, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` como `EINVAL` e retornarão `NULL`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tcstok_s`|`strtok_s`|`_mbstok_s`|`wcstok_s`|  
|`_tcstok_s_l`|`_strtok_s_l`|`_mbstok_s_l`|`_wcstok_s_l`|  
  
 Na primeira chamada a `strtok_s` a função ignora delimitadores principais e retorna um ponteiro para o primeiro token em `strToken`, encerrando o token com um caractere nulo.  Mais tokens podem ser incluídos do restante de `strToken` por uma série de chamadas a `strtok_s`.  Cada chamada para `strtok_s` altera `strToken` inserindo um caractere nulo após o token retornado por essa chamada.  O ponteiro de `context` controlam a cadeia de caracteres está sendo lido e onde na cadeia de caracteres o próximo token deve ser lido.  Para ler o próximo token de `strToken`, chame `strtok_s` com um valor de `NULL` para o argumento de `strToken` , e passe o mesmo parâmetro de `context` .  O argumento de `NULL``strToken` faz com que `strtok_s` pesquise pelo próximo token em `strToken`alterado.  O argumento de `strDelimit` pode aceitar qualquer valor de uma chamada a seguir de modo que o conjunto de delimitadores pode variar.  
  
 Desde que o parâmetro de `context` substitui os buffers estáticos usados em `strtok` e em `_strtok_l`, é possível analisar simultaneamente duas cadeias de caracteres no mesmo thread.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` de localidade. Para obter mais informações, consulte [setlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções sem o sufixo `_l` usam a localidade atual para esse comportamento dependente da localidade; as versões com o sufixo `_l` são idênticas, exceto que elas usam o parâmetro de localidade informado.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`strtok_s`|\<string.h\>|  
|`_strtok_s_l`|\<string.h\>|  
|`wcstok_s,`<br /><br /> `_wcstok_s_l`|\<string.h\> ou \<wchar.h\>|  
|`_mbstok_s,`<br /><br /> `_mbstok_s_l`|\<mbstring.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_strtok_s.c  
// In this program, a loop uses strtok_s  
// to print all the tokens (separated by commas  
// or blanks) in two strings at the same time.  
//  
  
#include <string.h>  
#include <stdio.h>  
  
char string1[] =  
    "A string\tof ,,tokens\nand some  more tokens";  
char string2[] =  
    "Another string\n\tparsed at the same time.";  
char seps[]   = " ,\t\n";  
char *token1 = NULL;  
char *token2 = NULL;  
char *next_token1 = NULL;  
char *next_token2 = NULL;  
  
int main( void )  
{  
    printf( "Tokens:\n" );  
  
    // Establish string and get the first token:  
    token1 = strtok_s( string1, seps, &next_token1);  
    token2 = strtok_s ( string2, seps, &next_token2);  
  
    // While there are tokens in "string1" or "string2"  
    while ((token1 != NULL) || (token2 != NULL))  
    {  
        // Get next token:  
        if (token1 != NULL)  
        {  
            printf( " %s\n", token1 );  
            token1 = strtok_s( NULL, seps, &next_token1);  
        }  
        if (token2 != NULL)  
        {  
            printf("        %s\n", token2 );  
            token2 = strtok_s (NULL, seps, &next_token2);  
        }  
    }  
}  
```  
  
  **Tokens:**  
 **A**  
 **Outros**  
 **cadeia de caracteres**  
 **cadeia de caracteres**  
 **de**  
 **analisado**  
 **tokens**  
 **em**  
 **e**  
 **the**  
 **alguns**  
 **mesmos**  
 **mais**  
 **tempo.**  
 **tokens**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Manipulação da cadeia de caracteres](../../c-runtime-library/string-manipulation-crt.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [strcspn, wcscspn, \_mbscspn, \_mbscspn\_l](../Topic/strcspn,%20wcscspn,%20_mbscspn,%20_mbscspn_l.md)   
 [strspn, wcsspn, \_mbsspn, \_mbsspn\_l](../../c-runtime-library/reference/strspn-wcsspn-mbsspn-mbsspn-l.md)