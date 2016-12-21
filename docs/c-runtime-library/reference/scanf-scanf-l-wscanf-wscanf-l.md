---
title: "scanf, _scanf_l, wscanf, _wscanf_l | Microsoft Docs"
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
  - "_wscanf_l"
  - "scanf"
  - "_scanf_l"
  - "wscanf"
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
  - "_tscanf"
  - "_scanf_l"
  - "wscanf"
  - "_wscanf_l"
  - "scanf"
  - "_tscanf_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _scanf_l"
  - "Função _tscanf"
  - "Função _tscanf_l"
  - "Função _wscanf_l"
  - "dados [C++], lendo de fluxo de entrada"
  - "dados formatados [C++], de fluxos de entrada"
  - "lendo dados [C++], de fluxos de entrada"
  - "Função scanf"
  - "Função scanf_l"
  - "Função tscanf"
  - "Função tscanf_l"
  - "Função wscanf"
  - "Função wscanf_l"
ms.assetid: 73eac607-117f-4be4-9ff0-4afd9cf3c848
caps.latest.revision: 25
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# scanf, _scanf_l, wscanf, _wscanf_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Lê dados formatados do fluxo de entrada padrão.  Versões mais seguras dessas funções estão disponíveis; consulte [scanf\_s, \_scanf\_s\_l, wscanf\_s, \_wscanf\_s\_l](../../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md).  
  
## Sintaxe  
  
```  
int scanf(  
   const char *format [,  
   argument]...   
);  
int _scanf_l(  
   const char *format,  
   locale_t locale [,  
   argument]...   
);  
int wscanf(  
   const wchar_t *format [,  
   argument]...   
);  
int _wscanf_l(  
   const wchar_t *format,  
   locale_t locale [,  
   argument]...   
);  
```  
  
#### Parâmetros  
 `format`  
 Cadeia de caracteres de controle de formato.  
  
 `argument`  
 Argumentos opcionais.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Retorna o número de campos que com êxito são convertidos e atribuídos; o valor de retorno não inclui os campos que foram lidos mas não atribuídos.  Um valor de retorno 0 indica que nenhum campo foi atribuído.  
  
 Se `format` é um ponteiro `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `EOF` e definirão `errno` para `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de `scanf` ler dados do fluxo de entrada padrão `stdin` e grava os dados no local especificado por `argument`.  Cada `argument` deve ser um ponteiro para uma variável de tipo que corresponde a um especificador do tipo em `format`.  Se a cópia for feita entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
> [!IMPORTANT]
>  Ao ler uma cadeia de caracteres com `scanf`, sempre especifique uma largura para o formato de `%s` \(por exemplo, `"%32s"` em vez de `"%s"`\); caso contrário, a entrada de forma incorreta formatado pode fazer facilmente uma excesso de buffer.  Como alternativa, considere usar [scanf\_s, \_scanf\_s\_l, wscanf\_s, \_wscanf\_s\_l](../../c-runtime-library/reference/scanf-s-scanf-s-l-wscanf-s-wscanf-s-l.md) ou [fgets](../../c-runtime-library/reference/fgets-fgetws.md).  
  
 `wscanf` é uma versão de caractere longo de `scanf`; o argumento `format` para `wscanf` é uma cadeia de caractere longo.  `wscanf` e `scanf` se comportarão de forma idêntica se o fluxo for aberto no modo de ANSI.  `scanf` não oferece suporte a entrada de um fluxo de UNICODE.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que usam o parâmetro de localidade passado em vez da localidade de thread atual.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tscanf`|`scanf`|`scanf`|`wscanf`|  
|`_tscanf_l`|`_scanf_l`|`_scanf_l`|`_wscanf_l`|  
  
 Para obter mais informações, consulte [Formatar campos da especificação — funções de scanf e funções de wscanf](../Topic/Format%20Specification%20Fields:%20scanf%20and%20wscanf%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`scanf`, `_scanf_l`|\<stdio.h\>|  
|`wscanf`, `_wscanf_l`|\<stdio.h\> ou \<wchar.h\>|  
  
 O console não tem suporte em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Os manipuladores de fluxo padrão associados ao console — `stdin`, `stdout` e `stderr` — devem ser redirecionados antes que as funções de tempo de execução do C possam utilizá\-los em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_scanf.c  
// compile with: /W3  
 /* This program uses the scanf and wscanf functions  
  * to read formatted input.  
  */  
  
#include <stdio.h>  
  
int main( void )  
{  
   int   i, result;  
   float fp;  
   char  c, s[81];  
   wchar_t wc, ws[81];  
   result = scanf( "%d %f %c %C %80s %80S", &i, &fp, &c, &wc, s, ws ); // C4996  
   // Note: scanf and wscanf are deprecated; consider using scanf_s and wscanf_s  
   printf( "The number of fields input is %d\n", result );  
   printf( "The contents are: %d %f %c %C %s %S\n", i, fp, c, wc, s, ws);  
   result = wscanf( L"%d %f %hc %lc %80S %80ls", &i, &fp, &c, &wc, s, ws ); // C4996  
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