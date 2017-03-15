---
title: fgetc, fgetwc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- fgetwc
- fgetc
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
- _fgettc
- fgetwc
- fgetc
dev_langs:
- C++
helpviewer_keywords:
- fgettc function
- characters, reading
- _fgettc function
- fgetc function
- streams, reading characters from
- reading characters from streams
- fgetwc function
ms.assetid: 13348b7b-dc86-421c-9d6c-611ca79c8338
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: c27ab371e240e47b20faacf0af678b1d24fe84b5
ms.lasthandoff: 02/25/2017

---
# <a name="fgetc-fgetwc"></a>fgetc, fgetwc
Lê um caractere de um fluxo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int fgetc(   
   FILE *stream   
);  
wint_t fgetwc(   
   FILE *stream   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
## <a name="return-value"></a>Valor de retorno  
 `fgetc` retorna o caractere lido como um `int` ou retorna `EOF` para indicar um erro ou o fim do arquivo. `fgetwc` retorna, como um [wint_t](../../c-runtime-library/standard-types.md), o caractere largo que corresponde ao caractere lido ou retorna `WEOF` para indicar um erro ou o fim do arquivo. Para ambas as funções, use `feof` ou `ferror` para distinguir entre um erro e uma condição de fim de arquivo. Se ocorrer um erro de leitura, o indicador de erro para o fluxo será definido. Se `stream` for `NULL`, `fgetc` e `fgetwc` invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definirão `errno` como `EINVAL` e retornarão `EOF`.  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas funções lê um único caractere da posição atual do arquivo associado a `stream`. A função, em seguida, incrementa o ponteiro de arquivo associado (se definido) para apontar para o próximo caractere. Se o fluxo estiver no fim do arquivo, o indicador de fim de arquivo para o fluxo será definido.  
  
 `fgetc` é equivalente a `getc`, mas implementado somente como uma função, em vez de uma função e uma macro.  
  
 `fgetwc` é a versão de caractere largo do `fgetc`. Ele lê `c` como um caractere multibyte ou um caractere largo se `stream` estiver aberto no modo de texto ou no modo binário.  
  
 As versões com o sufixo `_nolock` são idênticas, exceto pelo fato de não serem protegidas contra interferência de outros threads.  
  
 Para obter mais informações sobre como processar caracteres largos e caracteres multibyte em modos de texto e binários, consulte [E/S de fluxo de Unicode em modos de texto e binário](../../c-runtime-library/unicode-stream-i-o-in-text-and-binary-modes.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_fgettc`|`fgetc`|`fgetc`|`fgetwc`|  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`fgetc`|\<stdio.h>|  
|`fgetwc`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_fgetc.c  
// This program uses getc to read the first  
// 80 input characters (or until the end of input)  
// and place them into a string named buffer.  
  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   FILE *stream;  
   char buffer[81];  
   int  i, ch;  
  
   // Open file to read line from:  
   fopen_s( &stream, "crt_fgetc.txt", "r" );  
   if( stream == NULL )  
      exit( 0 );  
  
   // Read in first 80 characters and place them in "buffer":   
   ch = fgetc( stream );  
   for( i=0; (i < 80 ) && ( feof( stream ) == 0 ); i++ )  
   {  
      buffer[i] = (char)ch;  
      ch = fgetc( stream );  
   }  
  
   // Add null to end string   
   buffer[i] = '\0';  
   printf( "%s\n", buffer );  
   fclose( stream );  
}  
```  
  
## <a name="input-crtfgetctxt"></a>Entrada: crt_fgetc.txt  
  
```  
Line one.  
Line two.  
```  
  
### <a name="output"></a>Saída  
  
```  
Line one.  
Line two.  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
  
-   [System::IO::StreamReader::Read](https://msdn.microsoft.com/en-us/library/system.io.streamreader.read.aspx)  
  
-   [System::Console::Read](https://msdn.microsoft.com/en-us/library/system.console.read.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fputc, fputwc](../../c-runtime-library/reference/fputc-fputwc.md)   
 [getc, getwc](../../c-runtime-library/reference/getc-getwc.md)
