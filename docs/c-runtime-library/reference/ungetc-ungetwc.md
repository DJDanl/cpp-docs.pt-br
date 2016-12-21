---
title: "ungetc, ungetwc | Microsoft Docs"
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
  - "ungetwc"
  - "ungetc"
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
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_ungettc"
  - "ungetwc"
  - "ungetc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _ungettc"
  - "caracteres, retornando para o fluxo"
  - "Função ungetc"
  - "Função ungettc"
  - "Função ungetwc"
ms.assetid: e0754f3a-b4c6-408f-90c7-e6387b830d84
caps.latest.revision: 16
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# ungetc, ungetwc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Envia um caractere de volta para o fluxo.  
  
## Sintaxe  
  
```  
int ungetc(  
   int c,  
   FILE *stream   
);  
wint_t ungetwc(  
   wint_t c,  
   FILE *stream   
);  
```  
  
#### Parâmetros  
 `c`  
 Caractere a ser armazenado.  
  
 `stream`  
 Ponteiro a estrutura de `FILE` .  
  
## Valor de retorno  
 Se for bem\-sucedido, cada uma dessas funções retornará o argumento de caractere `c`*.* Se `c` não puder ser empurrado novamente ou se nenhum caractere tiver sido lido, a alteração no fluxo de entrada é desfeita e `EOF` retorna `ungetc`; retorna `WEOF` `ungetwc`.  Se `stream` é `NULL`, o parâmetro de manipulador inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, `EOF` ou `WEOF` será retornado e `errno` definido como `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função `ungetc` empurra o caractere `c` de volta ao `stream` e limpa o indicador de fim do arquivo.  O fluxo deve estar aberto para leitura.  Uma operação de leitura subsequente em `stream` começa com `c`*.* Será ignorada uma tentativa de empurrar `EOF` no fluxo que usa `ungetc`.  
  
 Os caracteres colocados no fluxo por `ungetc` podem ser apagados se `fflush`, `fseek`, `fsetpos` ou `rewind` for chamado antes que o caractere seja lido do fluxo.  O indicador de posição de arquivo terá o valor que tinha antes de os caracteres serem enviados de volta por push.  O armazenamento externo que corresponde ao fluxo é inalterado.  Em cada chamada bem\-sucedida do `ungetc` em um fluxo de texto, o indicador de posição do arquivo não é especificado até que todos os caracteres enviados por push sejam lidos ou descartados.  Em cada chamada `ungetc` bem\-sucedida em um fluxo binário, o indicador de posição de arquivo é diminuído; se o seu valor era 0 antes de uma chamada, o valor será indefinido após a chamada.  
  
 Os resultados serão imprevisíveis se `ungetc` for chamada duas vezes sem uma operação de leitura ou de posicionamento de arquivo entre as duas chamadas.  Após uma chamada a `fscanf`, uma chamada a `ungetc` pode falhar, a menos que outra operação de leitura \(como `getc`\) seja executada.  Isso ocorre porque o próprio `fscanf` chama `ungetc`.  
  
 `ungetwc` é uma versão de caracteres largos de `ungetc`.  No entanto, em cada chamada bem\-sucedida do `ungetwc` em um texto ou fluxo binário, o valor do indicador de posição do arquivo não é especificado até que todos os caracteres enviados por push sejam lidos ou descartados.  
  
 Essas funções são safe\-thread e bloqueiam dados confidenciais durante a execução.  Para uma versão sem bloqueio, consulte [\_ungetc\_nolock, \_ungetwc\_nolock](../Topic/_ungetc_nolock,%20_ungetwc_nolock.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_ungettc`|`ungetc`|`ungetc`|`ungetwc`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`ungetc`|\<stdio.h\>|  
|`ungetwc`|\<stdio.h\> ou \<wchar.h\>|  
  
 O console não tem suporte em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Os manipuladores de fluxo padrão associados ao console — `stdin`, `stdout` e `stderr` — devem ser redirecionados antes que as funções de tempo de execução do C possam utilizá\-los em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_ungetc.c  
// This program first converts a character  
// representation of an unsigned integer to an integer. If  
// the program encounters a character that is not a digit,  
// the program uses ungetc to replace it in the  stream.  
//  
  
#include <stdio.h>  
#include <ctype.h>  
  
int main( void )  
{  
   int ch;  
   int result = 0;  
  
   // Read in and convert number:  
   while( ((ch = getchar()) != EOF) && isdigit( ch ) )  
      result = result * 10 + ch - '0';    // Use digit.  
   if( ch != EOF )  
      ungetc( ch, stdin );                // Put nondigit back.  
   printf( "Number = %d\nNext character in stream = '%c'",   
            result, getchar() );  
}  
```  
  
  **Número `521a` \= 521**  
**Próximo caractere no fluxo \= “a”**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [getc, getwc](../../c-runtime-library/reference/getc-getwc.md)   
 [putc, putwc](../../c-runtime-library/reference/putc-putwc.md)