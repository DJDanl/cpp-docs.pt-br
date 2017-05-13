---
title: _putc_nolock, _putwc_nolock | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _putc_nolock
- _putwc_nolock
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
- _puttc_nolock
- puttc_nolock
- putwc_nolock
- _putwc_nolock
- _putc_nolock
- putc_nolock
dev_langs:
- C++
helpviewer_keywords:
- puttc_nolock function
- putc_nolock function
- _putc_nolock function
- streams, writing characters to
- characters, writing
- putwc_nolock function
- _puttc_nolock function
- _putwc_nolock function
ms.assetid: 3cfc7f21-c9e8-4b7f-b0fb-af0d4d85e7e1
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: a92fc2fe740d52c2040c8dc479e2ffaa8607989a
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="putcnolock-putwcnolock"></a>_putc_nolock, _putwc_nolock
Grava um caractere em um fluxo sem bloquear o thread.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      int _putc_nolock(  
   int c,  
   FILE *stream   
);  
wint_t _putwc_nolock(  
   wchar_t c,  
   FILE *stream   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 O caractere a ser gravado.  
  
 `stream`  
 Ponteiro para a estrutura **FILE**.  
  
## <a name="return-value"></a>Valor de retorno  
 Consulte **putc, putwc**.  
  
## <a name="remarks"></a>Comentários  
 `_putc_nolock` e `_putwc_nolock` são idênticas às versões sem o sufixo **_nolock**, exceto pelo fato de não serem protegidas contra interferência de outros threads. Elas podem ser mais rápidas, porque não incorrem na sobrecarga de bloquear outros threads. Use estas funções apenas em contextos thread-safe, como aplicativos de thread único ou em que o escopo de chamada já trata do isolamento de threads.  
  
 `_putwc_nolock` é a versão de caractere largo de `_putc_nolock`; as duas funções se comportam de forma idêntica quando o fluxo é aberto no modo ANSI. Atualmente, `_putc_nolock` não dá suporte para a saída em um fluxo UNICODE.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_puttc_nolock`|`_putc_nolock`|`_putc_nolock`|**_putwc_nolock**|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_putc_nolock`|\<stdio.h>|  
|`_putwc_nolock`|\<stdio.h> ou \<wchar.h>|  
  
 Não há suporte para o console em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Os identificadores de fluxo padrão associados ao console – `stdin`, `stdout` e `stderr` – devem ser redirecionados antes que as funções em tempo de execução C possam usá-los em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_putc_nolock.c  
/* This program uses putc to write buffer  
 * to a stream. If an error occurs, the program  
 * stops before writing the entire buffer.  
 */  
  
#include <stdio.h>  
  
int main( void )  
{  
   FILE *stream;  
   char *p, buffer[] = "This is the line of output\n";  
   int  ch;  
  
   ch = 0;  
   /* Make standard out the stream and write to it. */  
   stream = stdout;  
   for( p = buffer; (ch != EOF) && (*p != '\0'); p++ )  
      ch = _putc_nolock( *p, stream );  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
This is the line of output  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fputc, fputwc](../../c-runtime-library/reference/fputc-fputwc.md)   
 [getc, getwc](../../c-runtime-library/reference/getc-getwc.md)
