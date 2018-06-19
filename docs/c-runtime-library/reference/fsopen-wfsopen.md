---
title: _fsopen, _wfsopen | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _wfsopen
- _fsopen
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
- wfsopen
- fsopen
- tfsopen
- _tfsopen
- _wfsopen
- _fsopen
dev_langs:
- C++
helpviewer_keywords:
- opening files, streams
- fsopen function
- tfsopen function
- wfsopen function
- _fsopen function
- files [C++], opening
- _tfsopen function
- _wfsopen function
- file sharing [C++]
ms.assetid: 5e4502ab-48a9-4bee-a263-ebac8d638dec
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7ce69c6789ba65f61c54957dde3dfa6965bc32e2
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32405147"
---
# <a name="fsopen-wfsopen"></a>_fsopen, _wfsopen

Abre um fluxo com compartilhamento de arquivos.

## <a name="syntax"></a>Sintaxe

```C
FILE *_fsopen(
   const char *filename,
   const char *mode,
   int shflag
);
FILE *_wfsopen(
   const wchar_t *filename,
   const wchar_t *mode,
   int shflag
);
```

### <a name="parameters"></a>Parâmetros

*filename*<br/>
Nome do arquivo a ser aberto.

*modo*<br/>
Tipo de acesso permitido.

*shflag*<br/>
Tipo de compartilhamento permitido.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um ponteiro para o fluxo. Um valor de ponteiro nulo indica um erro. Se *filename* ou *modo* é **nulo** ou uma cadeia de caracteres vazia, essas funções invocam o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro ](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções retornam **nulo** e defina **errno** para **EINVAL**.

Para obter mais informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **fsopen** função abre o arquivo especificado por *filename* como um fluxo e prepara o arquivo para leitura compartilhada subsequente ou gravação, conforme definido pelo modo e *shflag*argumentos. **wfsopen** é uma versão de caractere largo de **fsopen**; o *filename* e *modo* argumentos para **wfsopen** são cadeias de caracteres largos. **wfsopen** e **fsopen** se comportam de forma idêntica caso contrário.

A cadeia de caracteres *modo* Especifica o tipo de acesso solicitado para o arquivo, como mostrado na tabela a seguir.

|Termo|Definição|
|----------|----------------|
|**"r"**|Abre para leitura. Se o arquivo não existe ou não é possível encontrar o **fsopen** chamada falhará.|
|**"w"**|Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.|
|**"a"**|Abre para gravação no final do arquivo (acréscimo); cria o arquivo primeiro se ele não existir.|
|**"r+"**|Abre para leitura e gravação. (O arquivo deve existir.)|
|**"w+"**|Abre um arquivo vazio para leitura e gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.|
|**"a+"**|Abre para gravação e acréscimo; cria o arquivo primeiro se ele não existir.|

Use o **"w"** e **"w +"** tipos com cuidado, pois eles podem destruir os arquivos existentes.

Quando um arquivo é aberto com o **"a"** ou **"+"** acessar o tipo, todas as gravação operações ocorrem no final do arquivo. O ponteiro do arquivo pode ser reposicionado usando [fseek](fseek-fseeki64.md) ou [retroceder](rewind.md), mas ele é sempre movido de volta para o final do arquivo antes que qualquer gravar a operação é executada. Sendo assim, dados existentes não podem ser substituídos. Quando o **"r +"**, **"w +"**, ou **"+"** tipo de acesso for especificado, leitura e gravação são permitidas (o arquivo deve estar aberto para atualização). No entanto, ao alternar entre leitura e gravação, deve haver uma operação [fsetpos](fsetpos.md), [fseek](fseek-fseeki64.md) ou [rewind](rewind.md) intermediária. A posição atual pode ser especificada para o [fsetpos](fsetpos.md) ou [fseek](fseek-fseeki64.md) operação, se desejado. Os valores acima, além de um dos seguintes caracteres pode ser incluído em *modo* para especificar o modo de tradução para novas linhas e para gerenciamento de arquivos.

|Termo|Definição|
|----------|----------------|
|**t**|Abre um arquivo no modo de texto (convertido). Nesse modo, combinações de carro linha de retorno de feed (CR LF) são transformadas em feeds de única linha (LF) na entrada e LF caracteres são convertidos para combinações de CR LF na saída. Além disso, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura ou leitura/gravação, **fsopen** verifica um CTRL + Z no final do arquivo e remove-lo, se possível. Isso é feito porque usando [fseek](fseek-fseeki64.md) e [ftell](ftell-ftelli64.md) mover dentro de um arquivo que termina com um CTRL + Z pode causar [fseek](fseek-fseeki64.md) se comporte incorretamente no final do arquivo.|
|**b**|Abre um arquivo no modo binário (não convertido); as conversões acima são suprimidas.|
|**S**|Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso.|
|**R**|Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso.|
|**T**|Especifica um arquivo como temporário. Se possível, ele não é liberado no disco.|
|**D**|Especifica um arquivo como temporário. É excluído quando o último ponteiro de arquivo é fechado.|

Se **t** ou **b** não for informado em *mode*, o modo de translação será definido pela variável de modo padrão **_fmode**. Se **t** ou **b** é o prefixo para o argumento, a função falhará e retornará **nulo**. Para saber mais sobre os modos de texto e binário, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).

O argumento *shflag* é uma expressão constante que consiste em uma das seguintes constantes de manifesto, definidas em Share.h.

|Termo|Definição|
|----------|----------------|
|**SH_COMPAT**|Define o modo de Compatibilidade para aplicativos de 16 bits.|
|**SH_DENYNO**|Permite acesso de leitura e gravação.|
|**SH_DENYRD**|Nega acesso de leitura ao arquivo.|
|**SH_DENYRW**|Nega acesso de leitura e gravação ao arquivo.|
|**SH_DENYWR**|Nega acesso de gravação ao arquivo.|

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**tfsopen**|**_fsopen**|**_fsopen**|**_wfsopen**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|Cabeçalhos opcionais|
|--------------|---------------------|----------------------|
|**_fsopen**|\<stdio.h>|\<share.h><br /><br /> Constante de manifesto para *shflag* parâmetro.|
|**_wfsopen**|\<stdio.h> ou \<wchar.h>|\<share.h><br /><br /> Constante de manifesto para *shflag* parâmetro.|

## <a name="example"></a>Exemplo

```C
// crt_fsopen.c

#include <stdio.h>
#include <stdlib.h>
#include <share.h>

int main( void )
{
   FILE *stream;

   // Open output file for writing. Using _fsopen allows us to
   // ensure that no one else writes to the file while we are
   // writing to it.
    //
   if( (stream = _fsopen( "outfile", "wt", _SH_DENYWR )) != NULL )
   {
      fprintf( stream, "No one else in the network can write "
                       "to this file until we are done.\n" );
      fclose( stream );
   }
   // Now others can write to the file while we read it.
   system( "type outfile" );
}
```

```Output
No one else in the network can write to this file until we are done.
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fclose, _fcloseall](fclose-fcloseall.md)<br/>
[_fdopen, _wfdopen](fdopen-wfdopen.md)<br/>
[ferror](ferror.md)<br/>
[_fileno](fileno.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[freopen, _wfreopen](freopen-wfreopen.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_setmode](setmode.md)<br/>
[_sopen, _wsopen](sopen-wsopen.md)<br/>
