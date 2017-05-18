---
title: _fdopen, _wfdopen | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _fdopen
- _wfdopen
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
apitype: DLLExport
f1_keywords:
- _tfdopen
- _fdopen
- _wfdopen
- wfdopen
- tfdopen
dev_langs:
- C++
helpviewer_keywords:
- wfdopen function
- _fdopen function
- _wfdopen function
- tfdopen function
- fdopen function
- _tfdopen function
- streams, associating with files
ms.assetid: 262757ff-1e09-4472-a5b6-4325fc28f971
caps.latest.revision: 23
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
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 3efc15f9d9fa6544ad7af2c3809ee6562b7f36e0
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="fdopen-wfdopen"></a>_fdopen, _wfdopen
Associa um fluxo com um arquivo que foi aberto anteriormente para E/S de nível inferior.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
FILE *_fdopen(    
   int fd,  
   const char *mode   
);  
FILE *_wfdopen(   
   int fd,  
   const wchar_t *mode   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `fd`  
 Descritor de arquivo do arquivo aberto.  
  
 `mode`  
 Tipo de acesso do arquivo.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para o fluxo aberto. Um valor de ponteiro nulo indica um erro. Quando ocorre um erro, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, `errno` será definido como `EBADF`, que indica um descritor de arquivo inválido ou `EINVAL`, que indica que `mode` é um ponteiro nulo.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `_fdopen` associa um fluxo de E/S com o arquivo que é identificado por `fd`e, portanto, permite que um arquivo seja aberto para a E/S de nível inferior que será armazenada em buffer e formatada. A função `_wfdopen` é uma versão de caractere largo da função `_fdopen`; o argumento `mode` para `_wfdopen` é uma cadeia de caracteres larga. Caso contrário, `_wfdopen` e `_fdopen` comportam-se de modo idêntico.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tfdopen`|`_fdopen`|`_fdopen`|`_wfdopen`|  
  
 A cadeia de caracteres `mode` especifica o tipo de arquivo e acesso de arquivo.  
  
 A cadeia de caracteres `mode` especifica o tipo de acesso solicitado para o arquivo, conforme mostrado na tabela a seguir.  
  
 `"r"`  
 Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, a chamada `fopen` falha.  
  
 `"w"`  
 Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.  
  
 `"a"`  
 Abre para gravação, no final do arquivo (em acréscimo). Cria o arquivo se ele não existir.  
  
 `"r+"`  
 Abre para leitura e gravação. (O arquivo deve existir.)  
  
 `"w+"`  
 Abre um arquivo vazio para leitura e gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.  
  
 `"a+"`  
 Abre para leitura e conexão. Cria o arquivo se ele não existir.  
  
 Quando um arquivo é aberto com o tipo de acesso `"a"` ou `"a+"`, todas as operações de gravação ocorrem no fim do arquivo. O ponteiro do arquivo pode ser reposicionado usando `fseek` ou `rewind`, mas é sempre movido de volta para o fim do arquivo antes de qualquer operação de gravação ser realizada. Sendo assim, dados existentes não podem ser substituídos. Quando o tipo de acesso `"r+"`, `"w+"` ou `"a+"` é especificado, são permitidas leitura e gravação (diz-se que o arquivo está aberto para "atualização"). No entanto, quando você muda entre leitura e gravação, deve haver uma operação `fflush`, `fsetpos`, `fseek` ou `rewind` intermediária. Você poderá especificar a posição atual para a operação `fsetpos` ou `fseek`, se desejar.  
  
 Além dos valores anteriores, os seguintes caracteres podem ser inclusos em `mode` para especificar o modo de conversão para os caracteres de nova linha.  
  
 `t`  
 Abra no modo de texto (convertido). Neste modo, combinações de CR-LF (retorno de carro – avanço de linha) são convertidas em LFs (avanços de uma linha) na entrada e caracteres de LF são convertidos em combinações de CR-LF na saída. Além disso, Ctrl+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura/gravação, `fopen` verifica se há um Ctrl+Z no fim do arquivo e o remove, se possível. Isso é feito porque usar as funções `fseek` e `ftell` para movimentação dentro de um arquivo que termina com Ctrl+Z pode fazer o `fseek` se comportar incorretamente perto do fim do arquivo.  
  
 `b`  
 Abre no modo binário (não convertido). Todas as conversões do modo `t` são suprimidas.  
  
 `c`  
 Habilite o sinalizador de confirmação para o `filename` associado de modo que os conteúdos do buffer de arquivo sejam gravados diretamente no disco, se `fflush` ou `_flushall` for chamado.  
  
 `n`  
 Redefina o sinalizador de confirmação para o `filename` associado a "no-commit." Esse é o padrão. Também substitui o sinalizador de confirmação global se você vincular o programa a Commode.obj. O padrão do sinalizador de confirmação global é "no-commit", a menos que você vincule explicitamente o programa a Commode.obj.  
  
 As opções `t`, `c` e `n` `mode` são extensões da Microsoft para `fopen` e `_fdopen`. Não as use se você quiser preservar a portabilidade ANSI.  
  
 Se `t` ou `b` não for fornecido em `mode`, o modo de conversão padrão será definido pela variável global [_fmode](../../c-runtime-library/fmode.md). Se `t` ou `b` for prefixado para o argumento, a função falha e retorna `NULL`. Para saber mais sobre os modos de texto e binário, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).  
  
 Caracteres válidos para a cadeia de caracteres `mode` usada em `fopen` e `_fdopen` correspondem a argumentos `oflag` usados em [_open](../../c-runtime-library/reference/open-wopen.md) e [_sopen](../../c-runtime-library/reference/sopen-wsopen.md), como segue.  
  
|Caracteres `mode` na cadeia de caracteres|Valor de `oflag` equivalente a `_open`/`_sopen`|  
|---------------------------------|---------------------------------------------------|  
|`a`|`_O_WRONLY &#124; _O_APPEND`(geralmente `_O_WRONLY &#124; _O_CREAT &#124; _O_APPEND`)|  
|`a+`|`_O_RDWR &#124; _O_APPEND` (geralmente `_O_RDWR &#124; _O_APPEND &#124; _O_CREAT`)|  
|`r`|`_O_RDONLY`|  
|`r+`|`_O_RDWR`|  
|`w`|`_O_WRONLY`(geralmente `_O_WRONLY &#124; _O_CREAT &#124; _O_TRUNC`)|  
|`w+`|`_O_RDWR`(geralmente `_O_RDWR &#124; _O_CREAT &#124; _O_TRUNC`)|  
|`b`|`_O_BINARY`|  
|`t`|`_O_TEXT`|  
|`c`|Nenhum|  
|`n`|Nenhum|  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_fdopen`|\<stdio.h>|  
|`_wfdopen`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_fdopen.c  
// This program opens a file by using low-level  
// I/O, then uses _fdopen to switch to stream  
// access. It counts the lines in the file.  
  
#include <stdlib.h>  
#include <stdio.h>  
#include <fcntl.h>  
#include <io.h>  
#include <share.h>  
  
int main( void )  
{  
   FILE *stream;  
   int  fd, count = 0;  
   char inbuf[128];  
  
   // Open a file.  
   if( _sopen_s( &fd, "crt_fdopen.txt", _O_RDONLY, _SH_DENYNO, 0 ) )  
      exit( 1 );  
  
   // Get stream from file descriptor.  
   if( (stream = _fdopen( fd, "r" )) == NULL )  
      exit( 1 );  
  
   while( fgets( inbuf, 128, stream ) != NULL )  
      count++;  
  
   // After _fdopen, close by using fclose, not _close.  
   fclose( stream );  
   printf( "Lines in file: %d\n", count );  
}  
```  
  
## <a name="input-crtfdopentxt"></a>Entrada: crt_fdopen.txt  
  
```  
Line one  
Line two  
```  
  
### <a name="output"></a>Saída  
  
```  
Lines in file: 2  
```  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [_dup, _dup2](../../c-runtime-library/reference/dup-dup2.md)   
 [fclose, _fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [fopen, _wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [freopen, _wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)
