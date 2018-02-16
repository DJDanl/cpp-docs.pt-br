---
title: ungetc, ungetwc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- ungetwc
- ungetc
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _ungettc
- ungetwc
- ungetc
dev_langs:
- C++
helpviewer_keywords:
- ungetwc function
- ungettc function
- characters, pushing back onto stream
- _ungettc function
- ungetc function
ms.assetid: e0754f3a-b4c6-408f-90c7-e6387b830d84
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d65453f1254e4c42658ef6f27d7c90d2ad0022b9
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ungetc-ungetwc"></a>ungetc, ungetwc
Envia um caractere de volta para o fluxo.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 O caractere a ser enviado.  
  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
## <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedida, cada uma dessas funções retornará o argumento de caractere `c`. Se `c` não pode ser enviado de volta ou se nenhum caractere for lido, o fluxo de entrada não é alterado e `ungetc` retorna `EOF`; `ungetwc` retorna `WEOF`. Se `stream` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se for permitido que a execução continue, `EOF` ou `WEOF` será definido como `errno` é definido como `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `ungetc` envia o caractere `c` de volta para `stream` e limpa o indicador de final do arquivo. O fluxo deve estar aberto para leitura. Uma operação de leitura em `stream` começa com `c`. Uma tentativa de envio `EOF` para o fluxo usando `ungetc` será ignorada.  
  
 Caracteres colocados no fluxo por `ungetc` podem ser apagados se `fflush`, `fseek`, `fsetpos` ou `rewind` é chamado antes que o caractere é lido do fluxo. O indicador de posição do arquivo terá o valor que tinha antes que os caracteres foram enviados de volta. O armazenamento externo correspondente para o fluxo não é alterado. Em uma chamada de `ungetc` bem-sucedida em um fluxo de texto, o indicador de posição do arquivo não é especificado até que todos os caracteres de retorno enviado sejam lidos ou descartados. Em cada chamada de `ungetc` bem-sucedida em um fluxo binário, o indicador de posição do arquivo será reduzido; se o valor for 0 antes de uma chamada, o valor será indefinido após a chamada.  
  
 Resultados serão imprevisíveis se `ungetc` for chamado duas vezes sem uma operação de leitura ou posicionamento de arquivo entre as duas chamadas. Após uma chamada para `fscanf`, uma chamada para `ungetc` pode falhar, a menos que outra operação de leitura (como `getc`) tenha sido executada. Isso ocorre porque `fscanf` chama `ungetc`.  
  
 `ungetwc` é uma versão de caractere largo de `ungetc`. No entanto, em cada chamada de `ungetwc` bem-sucedida em um fluxo de texto ou binário, o valor do indicador de posição do arquivo não é especificado até que todos os caracteres de retorno enviado sejam lidos ou descartados.  
  
 Essas funções são thread-safe e bloqueiam dados confidenciais durante a execução. Para ver uma versão sem bloqueio, consulte [_ungetc_nolock, _ungetwc_nolock](../../c-runtime-library/reference/ungetc-nolock-ungetwc-nolock.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_ungettc`|`ungetc`|`ungetc`|`ungetwc`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`ungetc`|\<stdio.h>|  
|`ungetwc`|\<stdio.h> ou \<wchar.h>|  
  
Não há suporte para o console em aplicativos do Windows UWP (plataforma Universal). Os identificadores de fluxo padrão que estão associados com o console, `stdin`, `stdout`, e `stderr`, deverá ser redirecionado para funções de tempo de execução C podem usá-los em aplicativos UWP. Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
  
      521aNumber = 521  
Next character in stream = 'a'  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [getc, getwc](../../c-runtime-library/reference/getc-getwc.md)   
 [putc, putwc](../../c-runtime-library/reference/putc-putwc.md)