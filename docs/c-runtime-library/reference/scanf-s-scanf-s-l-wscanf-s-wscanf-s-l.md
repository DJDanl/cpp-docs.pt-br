---
title: "scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l | Microsoft Docs"
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
  - "wscanf_s"
  - "_wscanf_s_l"
  - "scanf_s"
  - "_scanf_s_l"
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
  - "wscanf_s"
  - "_tscanf_s_l"
  - "_wscanf_s_l"
  - "scanf_s"
  - "_tscanf_s"
  - "_scanf_s_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Lendo dados [C++], fluxos de entrada"
  - "buffers [C++], saturações de buffer"
  - "Função _scanf_s_l"
  - "Função _wscanf_s_l"
  - "Função tscanf_s_l"
  - "Função tscanf_s"
  - "Função scanf_s"
  - "dados [C++], lendo de fluxo de entrada"
  - "Função wscanf_s"
  - "Função _tscanf_s_l"
  - "Função _tscanf_s"
  - "Função scanf_s_l"
  - "dados formatados [C++], fluxos de entrada"
  - "Função wscanf_s_l"
  - "buffers [C++], evitando saturações"
ms.assetid: 42cafcf7-52d6-404a-80e4-b056a7faf2e5
caps.latest.revision: 33
caps.handback.revision: 33
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# scanf_s, _scanf_s_l, wscanf_s, _wscanf_s_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Lê dados formatados de fluxo de entrada padrão. Essas versões do [scanf, \_scanf\_l, wscanf, \_wscanf\_l](../../c-runtime-library/reference/scanf-scanf-l-wscanf-wscanf-l.md) tem aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
int scanf_s(  
   const char *format [,  
   argument]...   
);  
int _scanf_s_l(  
   const char *format,  
   locale_t locale [,  
   argument]...   
);  
int wscanf_s(  
   const wchar_t *format [,  
   argument]...   
);  
int _wscanf_s_l(  
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
 Retorna o número de campos convertido com êxito e atribuídos; o valor de retorno não inclui campos que foram lidos, mas não atribuídos. Um valor de retorno 0 indica que nenhum campo foi atribuído. O valor de retorno é `EOF` para um erro, ou se o caractere de final de arquivo ou o caractere de fim de cadeia de caracteres for encontrado na primeira tentativa de ler um caractere. Se `format` é um `NULL` ponteiro, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, `scanf_s` e `wscanf_s` retornar `EOF` e defina `errno` para `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 O `scanf_s` função lê dados do fluxo de entrada padrão `stdin` e grava os dados no local que é determinado por `argument`. Cada `argument` deve ser um ponteiro para uma variável de um tipo que corresponde a um especificador de tipo em `format`. Se ocorrer cópia entre cadeias de caracteres que se sobrepõem, o comportamento será indefinido.  
  
 `wscanf_s` é uma versão de caractere largo de `scanf_s`; o `format` argumento `wscanf_s` é uma cadeia de caracteres largos.`wscanf_s` e `scanf_s` tenham comportamento idêntico quando o fluxo é aberto no modo ANSI.`scanf_s` no momento não oferece suporte a entrada de um fluxo UNICODE.  
  
 As versões dessas funções que têm o `_l` sufixo são idênticas, exceto que elas usam o parâmetro de localidade que é passado em vez da localidade do thread atual.  
  
 Ao contrário de `scanf` e `wscanf`, `scanf_s` e `wscanf_s` exigem o tamanho do buffer a ser especificado para todos os parâmetros de tipo de entrada `c`, `C`, `s`, `S`, ou conjuntos de controles que são incluídos na cadeia de caracteres `[]`. O tamanho do buffer em caracteres é passado como um parâmetro adicional imediatamente seguindo o ponteiro para o buffer ou variável. Por exemplo, se você estiver lendo uma cadeia de caracteres, o tamanho do buffer para essa cadeia de caracteres é passado como a seguir:  
  
 `char s[10];`  
  
 `scanf_s("%9s", s, (unsigned)_countof(s)); // buffer size is 10, width specification is 9`  
  
 O tamanho do buffer inclui a terminação nula. Você pode usar um campo de especificação de largura para garantir que o token que é lido em caiba no buffer. Se nenhum campo de especificação de largura for usado, e o token lido é muito grande para caber no buffer, nada é gravado em buffer.  
  
> [!NOTE]
>  O parâmetro de tamanho é do tipo `unsigned`, e não `size_t`. Use uma conversão estática para converter um `size_t` valor `unsigned` configurações de compilação para 64 bits.  
  
 O exemplo a seguir mostra que o parâmetro de tamanho de buffer descreve o número máximo de caracteres, não em bytes. Na chamada para `wscanf_s`, a largura de caractere que é indicada pelo tipo de buffer não coincide com a largura de caractere que é indicada pelo especificador de formato.  
  
```  
wchar_t ws[10];  
wscanf_s(L"%9S", ws, (unsigned)_countof(ws));  
```  
  
 O `S` especificador de formato indica o uso da largura de caractere que é "a largura padrão que é compatível com a função oposto". A largura do caractere é um byte, mas a função oferece suporte a caracteres de byte duplo. Este exemplo lê uma cadeia de caracteres de até 9 caracteres de largura de byte simples e coloca\-os em um buffer de caracteres de byte duplo\-todo. Os caracteres são tratados como valores de byte único; os dois primeiros caracteres são armazenados em `ws[0]`, os dois são armazenados em `ws[1]`, e assim por diante.  
  
 No caso de caracteres, um único caractere pode ser lida como segue:  
  
 `char c;`  
  
 `scanf_s("%c", &c, 1);`  
  
 Quando vários caracteres para cadeias de caracteres terminadas nulos são lidos, inteiros são usados como a especificação de largura e o tamanho do buffer.  
  
 `char c[4];`  
  
 `scanf_s("%4c", &c, (unsigned)_countof(c)); // not null terminated`  
  
 Para obter mais informações, consulte [Especificação de largura scanf Width](../../c-runtime-library/scanf-width-specification.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_tscanf_s`|`scanf_s`|`scanf_s`|`wscanf_s`|  
|`_tscanf_s_l`|`_scanf_s_l`|`_scanf_s_l`|`_wscanf_s_l`|  
  
 Para obter mais informações, consulte [Campos de especificação de formato: funções scanf e wscanf](../Topic/Format%20Specification%20Fields:%20scanf%20and%20wscanf%20Functions.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`scanf_s`, `_scanf_s_l`|\< stdio \>|  
|`wscanf_s`, `_wscanf_s_l`|\< stdio \> ou \< WCHAR \>|  
  
 Não há suporte para o console no [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos. Os identificadores de fluxo padrão que estão associados com o console —`stdin`, `stdout`, e `stderr`— devem ser redirecionados para funções de tempo de execução C podem usá\-los em [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_scanf_s.c  
// This program uses the scanf_s and wscanf_s functions  
// to read formatted input.  
  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   int      i,  
            result;  
   float    fp;  
   char     c,  
            s[80];  
   wchar_t  wc,  
            ws[80];  
  
   result = scanf_s( "%d %f %c %C %s %S", &i, &fp, &c, 1,  
                     &wc, 1, s, (unsigned)_countof(s), ws, (unsigned)_countof(ws) );  
   printf( "The number of fields input is %d\n", result );  
   printf( "The contents are: %d %f %c %C %s %S\n", i, fp, c,  
           wc, s, ws);  
   result = wscanf_s( L"%d %f %hc %lc %S %ls", &i, &fp, &c, 2,  
                      &wc, 1, s, (unsigned)_countof(s), ws, (unsigned)_countof(ws) );  
   wprintf( L"The number of fields input is %d\n", result );  
   wprintf( L"The contents are: %d %f %C %c %hs %s\n", i, fp,  
            c, wc, s, ws);  
}  
```  
  
 Este programa produz a seguinte saída quando recebe esta entrada:  
  
 `71 98.6 h z Byte characters`  
  
 `36 92.3 y n Wide characters`  
  
```Output  
O número de campos de entrada é o conteúdo é de 6: 71 z h 98.599998 o número de campos de entrada de caracteres de Byte é o conteúdo é de 6: 36 92.300003 y n caracteres largos  
```  
  
## Equivalência do .NET Framework  
  
-   [System::console::Read](https://msdn.microsoft.com/en-us/library/system.console.read.aspx)  
  
-   [System::console::ReadLine](https://msdn.microsoft.com/en-us/library/system.console.readline.aspx)  
  
-   Consulte também `Parse` métodos, tais como [System::Double::Parse](https://msdn.microsoft.com/en-us/library/system.double.parse.aspx).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [fscanf, \_fscanf\_l, fwscanf, \_fwscanf\_l](../../c-runtime-library/reference/fscanf-fscanf-l-fwscanf-fwscanf-l.md)   
 [printf, \_printf\_l, wprintf, \_wprintf\_l](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md)   
 [sprintf, \_sprintf\_l, swprintf, \_swprintf\_l, \_\_swprintf\_l](../../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md)   
 [sscanf, \_sscanf\_l, swscanf, \_swscanf\_l](../../c-runtime-library/reference/sscanf-sscanf-l-swscanf-swscanf-l.md)