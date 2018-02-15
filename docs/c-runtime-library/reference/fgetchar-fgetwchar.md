---
title: _fgetchar, _fgetwchar | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _fgetchar
- _fgetwchar
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
- fgetwchar
- _fgettchar
- _fgetchar
- _fgetwchar
- fgettchar
dev_langs:
- C++
helpviewer_keywords:
- fgetwchar function
- _fgetchar function
- fgettchar function
- _fgetwchar function
- _fgettchar function
- standard input, reading from
- fgetchar function
ms.assetid: 8bce874c-701a-41a3-b1b2-feff266fb5b9
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0eabf9bd54764aaa37bd860eb5bdb7d1ac5232ab
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="fgetchar-fgetwchar"></a>_fgetchar, _fgetwchar
Lê um caractere de `stdin`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _fgetchar( void );  
wint_t _fgetwchar( void );  
```  
  
## <a name="return-value"></a>Valor de retorno  
 `_fgetchar` retorna o caractere lido como um `int` ou retorna `EOF` para indicar um erro ou o fim do arquivo. **_**`fgetwchar` retorna, como um [wint_t](../../c-runtime-library/standard-types.md), o caractere largo que corresponde ao caractere lido ou retorna `WEOF` para indicar um erro ou o fim do arquivo. Para ambas as funções, use `feof` ou `ferror` para distinguir entre um erro e uma condição de fim de arquivo.  
  
## <a name="remarks"></a>Comentários  
 Essas funções leem um único caractere de `stdin`. A função, em seguida, incrementa o ponteiro de arquivo associado (se definido) para apontar para o próximo caractere. Se o fluxo estiver no fim do arquivo, o indicador de fim de arquivo para o fluxo será definido.  
  
 `_fgetchar` equivale a `fgetc( stdin )`. Também é equivalente a `getchar`, mas implementado somente como uma função, em vez de uma função e uma macro. `_fgetwchar` é a versão de caracteres largos do `_fgetchar`.  
  
 Essas funções não são compatíveis com o padrão ANSI.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_fgettchar`|`_fgetchar`|`_fgetchar`|`_fgetwchar`|  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_fgetchar`|\<stdio.h>|  
|`_fgetwchar`|\<stdio.h> ou \<wchar.h>|  
  
 Não há suporte para o console em aplicativos do Windows UWP (plataforma Universal). Os identificadores de fluxo padrão que estão associados com o console —`stdin`, `stdout`, e `stderr`— deverá ser redirecionado para funções de tempo de execução C podem usá-los em [! Aplicativos INCLUDEUWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_fgetchar.c  
// This program uses _fgetchar to read the first  
// 80 input characters (or until the end of input)  
// and place them into a string named buffer.  
//  
  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   char buffer[81];  
   int  i, ch;  
  
   // Read in first 80 characters and place them in "buffer":  
   ch = _fgetchar();  
   for( i=0; (i < 80 ) && ( feof( stdin ) == 0 ); i++ )  
   {  
      buffer[i] = (char)ch;  
      ch = _fgetchar();  
   }  
  
   // Add null to end string   
   buffer[i] = '\0';  
   printf( "%s\n", buffer );  
}  
```  
  
```Output  
  
      Line one.  
Line two.Line one.  
Line two.  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fputc, fputwc](../../c-runtime-library/reference/fputc-fputwc.md)   
 [getc, getwc](../../c-runtime-library/reference/getc-getwc.md)