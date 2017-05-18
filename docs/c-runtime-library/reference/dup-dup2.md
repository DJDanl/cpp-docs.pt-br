---
title: _dup, _dup2 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _dup
- _dup2
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
- _dup2
- _dup
dev_langs:
- C++
helpviewer_keywords:
- _dup2 function
- dup function
- file handles [C++], duplicating
- file handles [C++], reassigning
- dup2 function
- _dup function
ms.assetid: 4d07e92c-0d76-4832-a770-dfec0e7a0cfa
caps.latest.revision: 19
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3f91eafaf3b5d5c1b8f96b010206d699f666e224
ms.openlocfilehash: a85a26fbe7ab8417ea9ecd3c43745789117ac856
ms.contentlocale: pt-br
ms.lasthandoff: 04/01/2017

---
# <a name="dup-dup2"></a>_dup, _dup2
Cria um segundo descritor de arquivo para um arquivo aberto (`_dup`) ou reatribui um descritor de arquivo (`_dup2`).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _dup(   
   int fd   
);  
int _dup2(   
   int fd1,  
   int fd2   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `fd`, `fd1`  
 Descritores de arquivo que fazem referência ao arquivo aberto.  
  
 `fd2`  
 Qualquer descritor de arquivo.  
  
## <a name="return-value"></a>Valor de retorno  
 `_dup` retorna um novo descritor de arquivo. `_dup2` retorna 0 para indicar êxito. Se ocorrer um erro, cada função retorna -1 e conjuntos de `errno` para `EBADF` se o descritor de arquivo é inválido ou a `EMFILE` se não há mais descritores de arquivo estão disponíveis. No caso de um descritor de arquivo inválido, a função também invoca o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 As funções `_dup` e `_dup2` associam um segundo descritor de arquivo com um arquivo aberto. Essas funções podem ser usadas para associar um descritor de arquivo predefinido, como `stdout`, com um arquivo diferente. As operações no arquivo podem ser realizadas usando um descritor de arquivo. O tipo de acesso permitido para o arquivo não é afetado pela criação de um novo descritor. `_dup` retorna o próximo descritor de arquivo disponível para o arquivo. `_dup2` força `fd2` para se referir ao mesmo arquivo como `fd1`. Se `fd2` está associado com um arquivo aberto no momento da chamada, esse arquivo é fechado.  
  
 `_dup` e `_dup2` aceitam descritores de arquivo como parâmetros. Para passar um fluxo `(FILE *)` para uma dessas funções, use [_fileno](../../c-runtime-library/reference/fileno.md). A rotina `fileno` retorna o descritor de arquivo associado no momento a determinado fluxo. O exemplo a seguir mostra como associar `stderr` (definido como `FILE` `*` no Stdio.h) com um descritor de arquivo:  
  
```  
int cstderr = _dup( _fileno( stderr ));  
```  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_dup`|\<io.h>|  
|`_dup2`|\<io.h>|  
  
 Não há suporte para o console em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Os identificadores de fluxo padrão associados ao console – `stdin`, `stdout` e `stderr` – devem ser redirecionados antes que as funções em tempo de execução C possam usá-los em aplicativos [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)]. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_dup.c  
// This program uses the variable old to save  
// the original stdout. It then opens a new file named  
// DataFile and forces stdout to refer to it. Finally, it  
// restores stdout to its original state.  
//  
  
#include <io.h>  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   int old;  
   FILE *DataFile;  
  
   old = _dup( 1 );   // "old" now refers to "stdout"   
                      // Note:  file descriptor 1 == "stdout"   
   if( old == -1 )  
   {  
      perror( "_dup( 1 ) failure" );  
      exit( 1 );  
   }  
   _write( old, "This goes to stdout first\n", 26 );  
   if( fopen_s( &DataFile, "data", "w" ) != 0 )  
   {  
      puts( "Can't open file 'data'\n" );  
      exit( 1 );  
   }  
  
   // stdout now refers to file "data"   
   if( -1 == _dup2( _fileno( DataFile ), 1 ) )  
   {  
      perror( "Can't _dup2 stdout" );  
      exit( 1 );  
   }  
   puts( "This goes to file 'data'\n" );  
  
   // Flush stdout stream buffer so it goes to correct file   
   fflush( stdout );  
   fclose( DataFile );  
  
   // Restore original stdout   
   _dup2( old, 1 );  
   puts( "This goes to stdout\n" );  
   puts( "The file 'data' contains:" );  
   _flushall();  
   system( "type data" );  
}  
```  
  
```Output  
This goes to stdout first  
This goes to stdout  
  
The file 'data' contains:  
This goes to file 'data'  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [_close](../../c-runtime-library/reference/close.md)   
 [_creat, _wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)
