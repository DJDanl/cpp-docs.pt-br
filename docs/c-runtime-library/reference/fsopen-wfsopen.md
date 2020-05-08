---
title: _fsopen, _wfsopen
ms.date: 4/2/2020
api_name:
- _wfsopen
- _fsopen
- _o__fsopen
- _o__wfsopen
api_location:
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- wfsopen
- fsopen
- tfsopen
- _tfsopen
- _wfsopen
- _fsopen
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
ms.openlocfilehash: 7c7f079d8867416ab4f091d7c95a01ab9e40c0e8
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82910152"
---
# <a name="_fsopen-_wfsopen"></a>_fsopen, _wfsopen

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

*nome do arquivo*<br/>
Nome do arquivo a ser aberto.

*mode*<br/>
Tipo de acesso permitido.

*shflag*<br/>
Tipo de compartilhamento permitido.

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retorna um ponteiro para o fluxo. Um valor de ponteiro nulo indica um erro. Se o *nome do arquivo* ou o *modo* for **nulo** ou uma cadeia de caracteres vazia, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão **NULL** e definirá **errno** como **EINVAL**.

Para obter mais informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_fsopen** abre o arquivo especificado por *filename* como um fluxo e prepara o arquivo para leitura ou gravação compartilhada subsequente, conforme definido pelos argumentos Mode e *shflag* . **_wfsopen** é uma versão de caractere largo do **_fsopen**; os argumentos *filename* e *Mode* para **_wfsopen** são cadeias de caracteres largos. **_wfsopen** e **_fsopen** se comportar de forma idêntica.

O *modo* de cadeia de caracteres especifica o tipo de acesso solicitado para o arquivo, conforme mostrado na tabela a seguir.

|Termo|Definição|
|----------|----------------|
|**d**|Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, a chamada de **_fsopen** falhará.|
|**Mostrar**|Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.|
|**um**|Abre para gravação no final do arquivo (acréscimo); cria o arquivo primeiro se ele não existir.|
|**"r +"**|Abre para leitura e gravação. (O arquivo deve existir.)|
|**"w +"**|Abre um arquivo vazio para leitura e gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.|
|**"a +"**|Abre para gravação e acréscimo; cria o arquivo primeiro se ele não existir.|

Use os tipos **"w"** e **"w +"** com cuidado, pois eles podem destruir arquivos existentes.

Quando um arquivo é aberto com o tipo de acesso **"a"** ou **"a +"** , todas as operações de gravação ocorrem no final do arquivo. O ponteiro do arquivo pode ser reposicionado usando [fseek](fseek-fseeki64.md) ou [retrocesso](rewind.md), mas sempre é movido de volta para o final do arquivo antes de qualquer operação de gravação ser executada. Portanto, os dados existentes não podem ser substituídos. Quando o tipo de acesso **"r +"**, **"w +"** ou **"a +"** é especificado, a leitura e a gravação são permitidas (o arquivo é considerado aberto para atualização). No entanto, ao alternar entre leitura e gravação, deve haver uma operação [fsetpos](fsetpos.md), [fseek](fseek-fseeki64.md) ou [rewind](rewind.md) intermediária. A posição atual pode ser especificada para a operação [fsetpos](fsetpos.md) ou [fseek](fseek-fseeki64.md) , se desejado. Além dos valores acima, um dos caracteres a seguir pode ser incluído no *modo* para especificar o modo de tradução para novas linhas e para o gerenciamento de arquivos.

|Termo|Definição|
|----------|----------------|
|**t**|Abre um arquivo no modo de texto (convertido). Nesse modo, as combinações de CR-LF (retorno de carro-alimentação de linha) são convertidas em LF (single line feeds) em caracteres de entrada e LF são convertidas em combinações de CR-LF na saída. Além disso, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura ou leitura/gravação, o **_fsopen** verifica se há um CTRL + Z no final do arquivo e o Remove, se possível. Isso é feito porque o uso de [fseek](fseek-fseeki64.md) e [ftell](ftell-ftelli64.md) para mover dentro de um arquivo que termina com CTRL + Z pode fazer com que o [fseek](fseek-fseeki64.md) se comporte incorretamente próximo ao final do arquivo.|
|**b**|Abre um arquivo no modo binário (não convertido); as conversões acima são suprimidas.|
|**&**|Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso.|
|**R**|Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso.|
|**T**|Especifica um arquivo como temporário. Se possível, ele não é liberado no disco.|
|**D**|Especifica um arquivo como temporário. É excluído quando o último ponteiro de arquivo é fechado.|

Se **t** ou **b** não for informado em *mode*, o modo de translação será definido pela variável de modo padrão **_fmode**. Se **t** ou **b** for prefixado para o argumento, a função falhará e retornará **NULL**. Para saber mais sobre os modos de texto e binário, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).

O argumento *shflag* é uma expressão constante que consiste em uma das constantes de manifesto a seguir, definidas em share. h.

|Termo|Definição|
|----------|----------------|
|**_SH_COMPAT**|Define o modo de Compatibilidade para aplicativos de 16 bits.|
|**_SH_DENYNO**|Permite acesso de leitura e gravação.|
|**_SH_DENYRD**|Nega acesso de leitura ao arquivo.|
|**_SH_DENYRW**|Nega acesso de leitura e gravação ao arquivo.|
|**_SH_DENYWR**|Nega acesso de gravação ao arquivo.|

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tfsopen**|**_fsopen**|**_fsopen**|**_wfsopen**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|Cabeçalhos opcionais|
|--------------|---------------------|----------------------|
|**_fsopen**|\<stdio.h>|\<share.h><br /><br /> Para constante de manifesto para o parâmetro *shflag* .|
|**_wfsopen**|\<stdio.h> ou \<wchar.h>|\<share.h><br /><br /> Para constante de manifesto para o parâmetro *shflag* .|

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

## <a name="see-also"></a>Confira também

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
