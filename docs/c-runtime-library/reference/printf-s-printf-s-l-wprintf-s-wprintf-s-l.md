---
title: "printf_s, _printf_s_l, wprintf_s, _wprintf_s_l | Microsoft Docs"
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
  - "_printf_s_l"
  - "wprintf_s"
  - "_wprintf_s_l"
  - "printf_s"
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
  - "wprintf_s"
  - "printf_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _printf_s_l"
  - "Função _tprintf_s"
  - "Função _tprintf_s_l"
  - "Função _wprintf_s_l"
  - "texto formatado [C++]"
  - "printf - função, campos de especificação de formato"
  - "printf - função, usando"
  - "Função printf_s"
  - "Função printf_s_l"
  - "Função tprintf_s"
  - "Função tprintf_s_l"
  - "Função wprintf_s"
  - "Função wprintf_s_l"
ms.assetid: 044ebb2e-5cc1-445d-bb4c-f084b405615b
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# printf_s, _printf_s_l, wprintf_s, _wprintf_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Imprime saída formatada para o fluxo de saída padrão.  Essas versões de [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md) têm aprimoramentos de segurança, como descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
int printf_s(  
   const char *format [,  
   argument]...   
);  
int _printf_s_l(  
   const char *format,  
   locale_t locale [,  
   argument]...   
);  
int wprintf_s(  
   const wchar_t *format [,  
   argument]...   
);  
int _wprintf_s_l(  
   const wchar_t *format,  
   locale_t locale [,  
   argument]...   
);  
```  
  
#### Parâmetros  
 `format`  
 Controle de formato.  
  
 `argument`  
 Argumentos opcionais.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Retorna o número de caracteres impressos ou um valor negativo caso tenha ocorrido um erro.  
  
## Comentários  
 A função `printf_s` formata e imprime uma série de caracteres e de valores para o fluxo de saída padrão, `stdout`.  Se os argumentos seguem *a cadeia de caracteres de formato* , a cadeia de caracteres de `format` deve conter as especificações que determinam o formato de saída para os argumentos.  
  
 A principal diferença entre `printf_s` e `printf` é que `printf_s` verifica a cadeia de caracteres de caracteres de formatação válidos, enquanto que `printf` só verifica se a cadeia de caracteres de formato é um ponteiro nulo.  Se qualquer verificação falhará, um manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, a função retornará \-1 e definirá `errno` a `EINVAL`.  
  
 Para obter informações sobre `errno` e códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 `printf_s` e`fprintf_s` se comportam da mesma forma que a saída das gravações de `printf_s` a `stdout` em vez de em um destino do tipo `FILE`.  Para obter mais informações, consulte [fprintf\_s, \_fprintf\_s\_l, fwprintf\_s, \_fwprintf\_s\_l](../../c-runtime-library/reference/fprintf-s-fprintf-s-l-fwprintf-s-fwprintf-s-l.md).  
  
 `wprintf_s` é uma versão de caractere largo do `printf_s`; `format` é uma cadeia de caracteres largos.  `wprintf_s` e `printf_s` se comportarão de forma idêntica se o fluxo for aberto no modo de ANSI.  No momento, `printf_s` não tem suporte para saída em fluxo UNICODE.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto que usam o parâmetro de localidade passado em vez da localidade de thread atual.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_unicode definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tprintf_s`|`printf_s`|`printf_s`|`wprintf_s`|  
|`_tprintf_s_l`|`_printf_s_l`|`_printf_s_l`|`_wprintf_s_l`|  
  
 O argumento `format` consiste em caracteres comuns, sequências de escape e \(se argumentos seguirem `format`\) especificações de formato.  Os caracteres e sequências de escape comuns são copiados para `stdout` na ordem de sua aparição.  Por exemplo, a linha  
  
```  
printf_s("Line one\n\t\tLine two\n");   
```  
  
 gerenciar as saídas  
  
```  
Line one  
        Line two  
```  
  
 [Especificações de formato](../Topic/Format%20Specification%20Syntax:%20printf%20and%20wprintf%20Functions.md) sempre começam com um sinal de porcentagem \(`%`\) e são lidos da esquerda para a direita.  Quando `printf_s` localizar a primeira especificação de formato \(se houver\), ele converterá o valor do primeiro argumento após `format` e o gerará corretamente.  A segunda especificação de formato faz com que o segundo argumento seja convertido e enviado para a saída e assim por diante.  Se houver mais argumentos do que especificações de formato, os argumentos adicionais são ignorados.  Os resultados serão indefinidos se não houver argumentos suficientes para todas as especificações de formato.  
  
> [!IMPORTANT]
>  Verifique se `format` não é uma cadeia de caracteres definida pelo usuário.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`printf_s`, `_printf_s_l`|\<stdio.h\>|  
|`wprintf_s`, `_wprintf_s_l`|\<stdio.h\> ou \<wchar.h\>|  
  
 O console não tem suporte em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Os manipuladores de fluxo padrão associados ao console — `stdin`, `stdout` e `stderr` — devem ser redirecionados antes que as funções de tempo de execução do C possam utilizá\-los em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_printf_s.c  
/* This program uses the printf_s and wprintf_s functions  
 * to produce formatted output.  
 */  
  
#include <stdio.h>  
  
int main( void )  
{  
   char   ch = 'h', *string = "computer";  
   int    count = -9234;  
   double fp = 251.7366;  
   wchar_t wch = L'w', *wstring = L"Unicode";  
  
   /* Display integers. */  
   printf_s( "Integer formats:\n"  
           "   Decimal: %d  Justified: %.6d  Unsigned: %u\n",  
           count, count, count );  
  
   printf_s( "Decimal %d as:\n   Hex: %Xh  C hex: 0x%x  Octal: %o\n",  
            count, count, count, count );  
  
   /* Display in different radixes. */  
   printf_s( "Digits 10 equal:\n   Hex: %i  Octal: %i  Decimal: %i\n",  
            0x10, 010, 10 );  
  
   /* Display characters. */  
  
   printf_s("Characters in field (1):\n%10c%5hc%5C%5lc\n", ch, ch, wch, wch);  
   wprintf_s(L"Characters in field (2):\n%10C%5hc%5c%5lc\n", ch, ch, wch, wch);  
  
   /* Display strings. */  
  
   printf_s("Strings in field (1):\n%25s\n%25.4hs\n   %S%25.3ls\n",  
   string, string, wstring, wstring);  
   wprintf_s(L"Strings in field (2):\n%25S\n%25.4hs\n   %s%25.3ls\n",  
       string, string, wstring, wstring);  
  
   /* Display real numbers. */  
   printf_s( "Real numbers:\n   %f %.2f %e %E\n", fp, fp, fp, fp );  
  
   /* Display pointer. */  
   printf_s( "\nAddress as:   %p\n", &count);  
  
}  
```  
  
## Saída de Exemplo  
  
```  
Integer formats:  
   Decimal: -9234  Justified: -009234  Unsigned: 4294958062  
Decimal -9234 as:  
   Hex: FFFFDBEEh  C hex: 0xffffdbee  Octal: 37777755756  
Digits 10 equal:  
   Hex: 16  Octal: 8  Decimal: 10  
Characters in field (1):  
         h    h    w    w  
Characters in field (2):  
         h    h    w    w  
Strings in field (1):  
                 computer  
                     comp  
   Unicode                      Uni  
Strings in field (2):  
                 computer  
                     comp  
   Unicode                      Uni  
Real numbers:  
   251.736600 251.74 2.517366e+002 2.517366E+002  
  
Address as:   0012FF78  
  
```  
  
## Equivalência do .NET Framework  
  
-   [System::Console::Write](https://msdn.microsoft.com/en-us/library/system.console.write.aspx)  
  
-   [System::Console::WriteLine](https://msdn.microsoft.com/en-us/library/system.console.writeline.aspx)  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [fopen, \_wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [fprintf, \_fprintf\_l, fwprintf, \_fwprintf\_l](../../c-runtime-library/reference/fprintf-fprintf-l-fwprintf-fwprintf-l.md)   
 [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md)   
 [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [Funções vprintf](../../c-runtime-library/vprintf-functions.md)