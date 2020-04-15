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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 49907808729375e3bea18a5f4bbf204852e0072a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345698"
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

*Filename*<br/>
Nome do arquivo a ser aberto.

*Modo*<br/>
Tipo de acesso permitido.

*Shflag*<br/>
Tipo de compartilhamento permitido.

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retorna um ponteiro para o fluxo. Um valor de ponteiro nulo indica um erro. Se o nome ou *modo* *de arquivo* for **NULL** ou uma seqüência vazia, essas funções invocarão o manipulador de parâmetros inválido, conforme descrito na Validação [de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções retornam **NULL** e definem **errno** para **EINVAL**.

Para obter mais informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_fsopen** abre o arquivo especificado pelo *nome do arquivo* como um fluxo e prepara o arquivo para leitura ou escrita compartilhada subseqüentes, conforme definido pelo modo e argumentos *shflag.* **_wfsopen** é uma versão ampla de **_fsopen;** os argumentos *de nome de arquivo* e *modo* para **_wfsopen** são strings de caracteres amplos. **_wfsopen** e **_fsopen** se comportam de forma idêntica.

O *modo* string de caractereespecifica o tipo de acesso solicitado para o arquivo, conforme mostrado na tabela a seguir.

|Termo|Definição|
|----------|----------------|
|**"R"**|Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, a **chamada _fsopen** falhará.|
|**"W"**|Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.|
|**"A"**|Abre para gravação no final do arquivo (acréscimo); cria o arquivo primeiro se ele não existir.|
|**"r+"**|Abre para leitura e gravação. (O arquivo deve existir.)|
|**"W+"**|Abre um arquivo vazio para leitura e gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.|
|**"a+"**|Abre para gravação e acréscimo; cria o arquivo primeiro se ele não existir.|

Use os tipos **"w"** e **"w+"** com cuidado, pois eles podem destruir arquivos existentes.

Quando um arquivo é aberto com o tipo de acesso **"a"** ou **"a+",** todas as operações de gravação ocorrem no final do arquivo. O ponteiro do arquivo pode ser reposicionado usando [fseek](fseek-fseeki64.md) ou [rebobinar,](rewind.md)mas é sempre movido de volta para o final do arquivo antes que qualquer operação de gravação seja realizada. Assim, os dados existentes não podem ser substituídos. Quando o tipo de acesso **"r+",** **"w+"** ou **"a+"** é especificado, tanto a leitura quanto a escrita são permitidas (o arquivo está aberto para atualização). No entanto, ao alternar entre leitura e gravação, deve haver uma operação [fsetpos](fsetpos.md), [fseek](fseek-fseeki64.md) ou [rewind](rewind.md) intermediária. A posição atual pode ser especificada para a operação [fsetpos](fsetpos.md) ou [fseek,](fseek-fseeki64.md) se desejar. Além dos valores acima, um dos seguintes caracteres pode ser incluído no *modo* para especificar o modo de tradução para novas linhas e para o gerenciamento de arquivos.

|Termo|Definição|
|----------|----------------|
|**t**|Abre um arquivo no modo de texto (convertido). Neste modo, as combinações de feed de linha de retorno de transporte (CR-LF) são traduzidas em feeds de linha única (LF) na entrada e os caracteres LF são traduzidos para combinações CR-LF na saída. Além disso, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura ou leitura/escrita, **_fsopen** verifica um CTRL+Z no final do arquivo e o remove, se possível. Isso é feito porque o uso [de fseek](fseek-fseeki64.md) e [ftell](ftell-ftelli64.md) para mover dentro de um arquivo que termina com um CTRL+Z pode fazer com [que fseek](fseek-fseeki64.md) se comporte incorretamente perto do final do arquivo.|
|**B**|Abre um arquivo no modo binário (não convertido); as conversões acima são suprimidas.|
|**S**|Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso.|
|**R**|Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso.|
|**T**|Especifica um arquivo como temporário. Se possível, ele não é liberado no disco.|
|**D**|Especifica um arquivo como temporário. É excluído quando o último ponteiro de arquivo é fechado.|

Se **t** ou **b** não for informado em *mode*, o modo de translação será definido pela variável de modo padrão **_fmode**. Se **t** ou **b forprefixado** ao argumento, a função falha e retorna **NULA**. Para saber mais sobre os modos de texto e binário, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).

O argumento *shflag* é uma expressão constante que consiste em uma das seguintes constantes manifestas, definidas em Share.h.

|Termo|Definição|
|----------|----------------|
|**_SH_COMPAT**|Define o modo de Compatibilidade para aplicativos de 16 bits.|
|**_SH_DENYNO**|Permite acesso de leitura e gravação.|
|**_SH_DENYRD**|Nega acesso de leitura ao arquivo.|
|**_SH_DENYRW**|Nega acesso de leitura e gravação ao arquivo.|
|**_SH_DENYWR**|Nega acesso de gravação ao arquivo.|

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tfsopen**|**_fsopen**|**_fsopen**|**_wfsopen**|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|Cabeçalhos opcionais|
|--------------|---------------------|----------------------|
|**_fsopen**|\<stdio.h>|\<share.h><br /><br /> Para manifestação constante para parâmetro *de shflag.*|
|**_wfsopen**|\<stdio.h> ou \<wchar.h>|\<share.h><br /><br /> Para manifestação constante para parâmetro *de shflag.*|

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
