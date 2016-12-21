---
title: "vscanf, vwscanf | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "vscanf"
  - "vwscanf"
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
apitype: "DLLExport"
f1_keywords: 
  - "vscanf"
  - "vwscanf"
  - "_vtscanf"
dev_langs: 
  - "C++"
ms.assetid: d1df595b-11bc-4682-9441-a92616301e3b
caps.latest.revision: 6
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# vscanf, vwscanf
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Lê dados formatados do fluxo de entrada padrão.  Versões mais seguras dessas funções estão disponíveis; consulte [vscanf\_s, vwscanf\_s](../../c-runtime-library/reference/vscanf-s-vwscanf-s.md).  
  
## Sintaxe  
  
```  
int vscanf(  
   const char *format,  
   va_list arglist  
);  
int vwscanf(  
   const wchar_t *format,  
   va_list arglist  
);  
  
```  
  
#### Parâmetros  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `arglist`  
 Lista de argumentos variável.  
  
## Valor de retorno  
 Retorna o número de campos que com êxito são convertidos e atribuídos; o valor de retorno não inclui os campos que foram lidos mas não atribuídos.  Um valor de retorno 0 indica que nenhum campo foi atribuído.  
  
 Se `format` é um ponteiro `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `EOF` e definirão `errno` para `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função `vscanf` lê os dados do fluxo de entrada padrão `stdin` e grava os dados nos locais fornecidos pela lista de argumentos `arglist` \(se houver\).  Cada argumento da lista deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo em `format`.  Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
> [!IMPORTANT]
>  Ao usar `vscanf` para ler uma cadeia de caracteres, especifique sempre uma largura para o formato de `%s` \(por exemplo, `"%32s"` em vez de `"%s"`\); caso contrário, a entrada formatada incorretamente pode causar um estouro de buffer.  Como alternativa, você pode usar [vscanf\_s, vwscanf\_s](../../c-runtime-library/reference/vscanf-s-vwscanf-s.md) ou [fgets](../../c-runtime-library/reference/fgets-fgetws.md).  
  
 `vwscanf` é uma versão de caractere longo de `vscanf`; o argumento `format` para `vwscanf` é uma cadeia de caractere longo.  `vwscanf` e `vscanf` se comportarão de forma idêntica se o fluxo for aberto no modo de ANSI.  O `vscanf` não oferece suporte a entrada de um fluxo de UNICODE.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_vtscanf`|`vscanf`|`vscanf`|`vwscanf`|  
  
 Para obter mais informações, consulte [Campos de especificação de formato: funções scanf e wscanf](../Topic/Format%20Specification%20Fields:%20scanf%20and%20wscanf%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`vscanf`|\<stdio.h\>|  
|`vwscanf`|\<stdio.h\> ou \<wchar.h\>|  
  
 O console não tem suporte em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Os manipuladores de fluxo padrão associados ao console — `stdin`, `stdout` e `stderr` — devem ser redirecionados antes que as funções de tempo de execução do C possam utilizá\-los em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_vscanf.c  
// compile with: /W3  
// This program uses the vscanf and vwscanf functions  
// to read formatted input.  
  
#include <stdio.h>  
#include <stdarg.h>  
  
int call_vscanf(char *format, ...)  
{  
    int result;  
    va_list arglist;  
    va_start(arglist, format);  
    result = vscanf(format, arglist);  
    va_end(arglist);  
    return result;  
}  
  
int call_vwscanf(wchar_t *format, ...)  
{  
    int result;  
    va_list arglist;  
    va_start(arglist, format);  
    result = vwscanf(format, arglist);  
    va_end(arglist);  
    return result;  
}  
  
int main( void )  
{  
    int   i, result;  
    float fp;  
    char  c, s[81];  
    wchar_t wc, ws[81];  
    result = call_vscanf( "%d %f %c %C %80s %80S", &i, &fp, &c, &wc, s, ws );  
    printf( "The number of fields input is %d\n", result );  
    printf( "The contents are: %d %f %c %C %s %S\n", i, fp, c, wc, s, ws);  
    result = call_vwscanf( L"%d %f %hc %lc %80S %80ls", &i, &fp, &c, &wc, s, ws );  
    wprintf( L"The number of fields input is %d\n", result );  
    wprintf( L"The contents are: %d %f %C %c %hs %s\n", i, fp, c, wc, s, ws);  
}  
  
```  
  
  **`caracteres de 71 98,6 h z bites caracteres amplos 36 92.3 y n`O número da entrada de campo é 6**  
**Os conteúdos são: 71 98.599998 caracteres de byte h z**  
**O número de entrada dos campos é 6**  
**Os conteúdos são: 36 a 92,300003 caracteres amplos y n**   
## Equivalência do .NET Framework  
  
-   [System::Console::Read](https://msdn.microsoft.com/en-us/library/system.console.read.aspx)  
  
-   [System::Console::ReadLine](https://msdn.microsoft.com/en-us/library/system.console.readline.aspx)  
  
-   Consulte também métodos de `Parse` , como [System::Double::Parse](https://msdn.microsoft.com/en-us/library/system.double.parse.aspx).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [fscanf, \_fscanf\_l, fwscanf, \_fwscanf\_l](../../c-runtime-library/reference/fscanf-fscanf-l-fwscanf-fwscanf-l.md)   
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [sscanf, \_sscanf\_l, swscanf, \_swscanf\_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)   
 [vscanf\_s, vwscanf\_s](../../c-runtime-library/reference/vscanf-s-vwscanf-s.md)