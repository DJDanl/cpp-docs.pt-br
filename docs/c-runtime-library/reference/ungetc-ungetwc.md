---
title: "ungetc, ungetwc | Microsoft Docs"
ms.custom: ""
ms.date: "11/04/2016"
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
helpviewer_keywords: 
  - "ungetwc function"
  - "ungettc function"
  - "characters, pushing back onto stream"
  - "_ungettc function"
  - "ungetc function"
ms.assetid: e0754f3a-b4c6-408f-90c7-e6387b830d84
caps.latest.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
translation.priority.ht: 
  - "cs-cz"
  - "de-de"
  - "es-es"
  - "fr-fr"
  - "it-it"
  - "ja-jp"
  - "ko-kr"
  - "pl-pl"
  - "pt-br"
  - "ru-ru"
  - "tr-tr"
  - "zh-cn"
  - "zh-tw"
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
 Se tiver sucesso, cada uma dessas funções retornará o argumento do caractere `c`*.* Se `c` não pode ser enviado de volta ou se nenhum caractere for lido, o fluxo de entrada não é alterado e `ungetc` retorna `EOF`; `ungetwc` retorna `WEOF`. Se `stream` for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se for permitido que a execução continue, `EOF` ou `WEOF` será definido como `errno` é definido como `EINVAL`.  
  
 Para obter informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `ungetc` envia o caractere `c` de volta para `stream` e limpa o indicador de final do arquivo. O fluxo deve estar aberto para leitura. Uma operação de leitura subsequente em `stream` começa com `c` *.* Uma tentativa de envio `EOF` para o fluxo usando `ungetc` será ignorada.  
  
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
  
 Não há suporte para o console em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Os identificadores de fluxo padrão associados ao console – `stdin`, `stdout` e `stderr` – devem ser redirecionados antes que as funções em tempo de execução C possam usá-los em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
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
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](http://msdn.microsoft.com/Library/15926806-f0b7-487e-93a6-4e9367ec689f).  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [getc, getwc](../../c-runtime-library/reference/getc-getwc.md)   
 [putc, putwc](../../c-runtime-library/reference/putc-putwc.md)