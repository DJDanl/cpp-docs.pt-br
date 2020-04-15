---
title: freopen_s, _wfreopen_s
ms.date: 4/2/2020
api_name:
- _wfreopen_s
- freopen_s
- _o__wfreopen_s
- _o_freopen_s
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
- freopen_s
- _tfreopen_s
- _wfreopen_s
helpviewer_keywords:
- _tfreopen_s function
- _wfreopen_s function
- file pointers [C++], reassigning
- tfreopen_s function
- wfreopen_s function
- freopen_s function
ms.assetid: ad25a4da-6ad4-476b-a86d-660b221ca84d
ms.openlocfilehash: a24e34ead905d2f704bfbf4d829064c656272e97
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345912"
---
# <a name="freopen_s-_wfreopen_s"></a>freopen_s, _wfreopen_s

Reatribui um ponteiro de arquivo. Estas versões de [freopen, _wfreopen](freopen-wfreopen.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t freopen(
   FILE** pFile,
   const char *path,
   const char *mode,
   FILE *stream
);
errno_t _wfreopen(
   FILE** pFile,
   const wchar_t *path,
   const wchar_t *mode,
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*Pfile*<br/>
Um ponteiro para o ponteiro de arquivo a ser fornecido pela chamada.

*path*<br/>
Caminho do novo arquivo.

*Modo*<br/>
Tipo de acesso permitido.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retorna um código de erro. Se ocorrer um erro, o arquivo original será fechado.

## <a name="remarks"></a>Comentários

A função **freopen_s** fecha o arquivo atualmente associado ao *fluxo* e reatribui o *fluxo* ao arquivo especificado por *caminho*. **_wfreopen_s** é uma versão ampla de **_freopen_s;** os argumentos *de caminho* e *modo* para **_wfreopen_s** são strings de caracteres amplos. **_wfreopen_s** e **_freopen_s** se comportam de forma idêntica.

Se qualquer um dos *pFile,* *path,* *mode*ou *stream* **forNULL,** ou se *o caminho* for uma seqüência de string vazia, essas funções invocam o manipulador de parâmetros inválido, conforme descrito na Validação [de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EINVAL** e retornam **EINVAL**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tfreopen_s**|**freopen_s**|**freopen_s**|**_wfreopen_s**|

**freopen_s** é normalmente usado para redirecionar os arquivos pré-abertos **stdin**, **stdout**e **stderr** para arquivos especificados pelo usuário. O novo arquivo associado ao *fluxo* é aberto com *o modo*, que é uma seqüência de caracteres especificando o tipo de acesso solicitado para o arquivo, da seguinte forma:

|*Modo*|Acesso|
|-|-|
| **"R"** | Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, a **chamada freopen_s** falhará. |
| **"W"** | Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos. |
| **"A"** | Abre para gravação no fim do arquivo (conexão) sem remover o marcador de EOF (Fim de arquivo) antes de novos dados serem gravados no arquivo. Cria o arquivo se ele não existir. |
| **"r+"** | Abre para leitura e gravação. O arquivo deve existir. |
| **"W+"** | Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos. |
| **"a+"** | Abre para leitura e conexão. A operação de conexão inclui a remoção do marcador de EOF antes de os novos dados serem gravados no arquivo. O marcador de EOF não é restaurado após a gravação ser concluída. Cria o arquivo se ele não existir. |

Use os tipos **"w"** e **"w+"** com cuidado, pois eles podem destruir arquivos existentes.

Quando um arquivo é aberto com o tipo de acesso **"a"** ou **"a+",** todas as operações de gravação ocorrem no final do arquivo. Embora o ponteiro do arquivo possa ser reposicionado usando [fseek](fseek-fseeki64.md) ou [rebobinar,](rewind.md)o ponteiro do arquivo é sempre movido de volta para o final do arquivo antes que qualquer operação de gravação seja realizada. Assim, os dados existentes não podem ser substituídos.

O modo **"a"** não remove o marcador EOF antes de anexar ao arquivo. Depois de a conexão ter ocorrido, o comando MS-DOS TYPE só mostra dados até o marcador de EOF original, e não qualquer dado anexado ao arquivo. O modo **"a+"** remove o marcador EOF antes de anexar ao arquivo. Depois de anexar, o comando MS-DOS TYPE mostra todos os dados no arquivo. O modo **"a+"** é necessário para anexar a um arquivo de fluxo que é encerrado com o marcador CTRL+Z EOF.

Quando o tipo de acesso **"r+",** **"w+"** ou **"a+"** é especificado, tanto a leitura quanto a escrita são permitidas (o arquivo está aberto para "atualização"). No entanto, quando você muda entre leitura e gravação, deve haver uma operação [fsetpos](fsetpos.md), [fseek](fseek-fseeki64.md) ou [rewind](rewind.md) intermediária. A posição atual pode ser especificada para a operação [fsetpos](fsetpos.md) ou [fseek,](fseek-fseeki64.md) se desejar. Além dos valores acima, um dos seguintes caracteres pode ser incluído na seqüência de *modos* para especificar o modo de tradução para novas linhas.

|modificador *de modo*|Modo de tradução|
|-|-|
| **t** | Abra no modo de texto (convertido). |
| **B** | Abrir no modo binário (não traduzido); traduções envolvendo caracteres de retorno de transporte e alimentação de linha são suprimidas. |

No modo texto (traduzido), as combinações de alimentação de linha de retorno de transporte (CR-LF) são traduzidas em caracteres de alimentação de linha única (LF) na entrada; LF os caracteres são traduzidos para combinações CR-LF na saída. Além disso, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura ou para escrita e leitura com **"a+",** a biblioteca de tempo de execução verifica um CTRL+Z no final do arquivo e remove-o, se possível. Isso é feito porque o uso [de fseek](fseek-fseeki64.md) e [ftell](ftell-ftelli64.md) para mover dentro de um arquivo pode fazer com [que fseek](fseek-fseeki64.md) se comporte incorretamente perto do final do arquivo. A opção **t** é uma extensão da Microsoft que não deve ser usada onde a portabilidade ANSI é desejada.

Se **t** ou **b** não for dado no *modo,* o modo de tradução padrão é definido pela variável global [_fmode](../../c-runtime-library/fmode.md). Se **t** ou **b forprefixado** ao argumento, a função falha e retorna **NULA**.

Para saber mais sobre os modos de texto e binário, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**freopen_s**|\<stdio.h>|
|**_wfreopen_s**|\<stdio.h> ou \<wchar.h>|

O console não é suportado em aplicativos Universal Windows Platform (UWP). As alças de fluxo padrão associadas ao console, **stdin**, **stdout**e **stderr,** devem ser redirecionadas antes que as funções de tempo de execução C possam usá-las em aplicativos UWP. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_freopen_s.c
// This program reassigns stderr to the file
// named FREOPEN.OUT and writes a line to that file.

#include <stdio.h>
#include <stdlib.h>

FILE *stream;

int main( void )
{
   errno_t err;
   // Reassign "stderr" to "freopen.out":
   err = freopen_s( &stream, "freopen.out", "w", stderr );

   if( err != 0 )
      fprintf( stdout, "error on freopen\n" );
   else
   {
      fprintf( stdout, "successfully reassigned\n" ); fflush( stdout );
      fprintf( stream, "This will go to the file 'freopen.out'\n" );
      fclose( stream );
   }
   system( "type freopen.out" );
}
```

```Output
successfully reassigned
This will go to the file 'freopen.out'
```

## <a name="see-also"></a>Confira também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[freopen, _wfreopen](freopen-wfreopen.md)<br/>
[fclose, _fcloseall](fclose-fcloseall.md)<br/>
[_fdopen, _wfdopen](fdopen-wfdopen.md)<br/>
[_fileno](fileno.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_setmode](setmode.md)<br/>
