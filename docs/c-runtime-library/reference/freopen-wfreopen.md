---
title: freopen, _wfreopen
ms.date: 11/04/2016
apiname:
- freopen
- _wfreopen
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
- _wfreopen
- _tfreopen
- freopen
helpviewer_keywords:
- _wfreopen function
- file pointers [C++], reassigning
- _tfreopen function
- freopen function
- tfreopen function
- wfreopen function
ms.assetid: de4b73f8-1043-4d62-98ee-30d2022da885
ms.openlocfilehash: 4c570837bddea1f5e986ae5f767279ab2637ea21
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51332498"
---
# <a name="freopen-wfreopen"></a>freopen, _wfreopen

Reatribui um ponteiro de arquivo. Versões mais seguras dessas funções estão disponíveis; consulte [freopen_s, _wfreopen_s](freopen-s-wfreopen-s.md).

## <a name="syntax"></a>Sintaxe

```C
FILE *freopen(
   const char *path,
   const char *mode,
   FILE *stream
);
FILE *_wfreopen(
   const wchar_t *path,
   const wchar_t *mode,
   FILE *stream
);
```

### <a name="parameters"></a>Parâmetros

*path*<br/>
Caminho do novo arquivo.

*modo*<br/>
Tipo de acesso permitido.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um ponteiro para o arquivo recém-aberto. Se ocorrer um erro, o arquivo original será fechado e a função retorna um **nulo** valor do ponteiro. Se *caminho*, *modo*, ou *fluxo* é um ponteiro nulo, ou se *filename* é uma cadeia de caracteres vazia, essas funções invocarão o parâmetro inválido manipulador, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** à **EINVAL** e retornar **nulo**.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de erro.

## <a name="remarks"></a>Comentários

Existem versões mais seguras dessas funções; consulte [freopen_s, _wfreopen_s](freopen-s-wfreopen-s.md).

O **freopen** função fecha o arquivo atualmente associado *fluxo* e reatribui *fluxo* para o arquivo especificado por *caminho*. **wfreopen** é uma versão de caractere largo de **_freopen**; o *caminho* e *modo* argumentos a serem **wfreopen** são cadeias de caracteres largos. **wfreopen** e **_freopen** se comportam de forma idêntica caso contrário.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tfreopen**|**freopen**|**freopen**|**_wfreopen**|

**freopen** normalmente é usado para redirecionar os arquivos abertos previamente **stdin**, **stdout**, e **stderr** para arquivos especificados pelo usuário. O novo arquivo associado *stream* é aberto com *modo*, que é uma cadeia de caracteres que especifica o tipo de acesso solicitado para o arquivo, da seguinte maneira:

|*modo*|Acesso|
|-|-|
| **"r"** | Abre para leitura. Se o arquivo não existe ou não for encontrado, o **freopen** chamar falhar. |
| **"w"** | Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos. |
| **"a"** | Abre para gravação no fim do arquivo (conexão) sem remover o marcador de EOF (Fim de arquivo) antes de novos dados serem gravados no arquivo. Cria o arquivo se ele não existir. |
| **"r+"** | Abre para leitura e gravação. O arquivo deve existir. |
| **"w+"** | Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos. |
| **"a+"** | Abre para leitura e conexão. A operação de conexão inclui a remoção do marcador de EOF antes de os novos dados serem gravados no arquivo. O marcador de EOF não é restaurado após a gravação ser concluída. Cria o arquivo se ele não existir. |

Use o **"w"** e **"w +"** tipos com cuidado, pois eles podem destruir arquivos existentes.

Quando um arquivo é aberto com o **"a"** ou **"+"** acessar o tipo, todas as operações ocorrem no final do arquivo de gravação. Embora o ponteiro do arquivo pode ser reposicionado usando [fseek](fseek-fseeki64.md) ou [rewind](rewind.md), o ponteiro do arquivo é sempre movido de volta para o final do arquivo antes de qualquer operação de gravação é realizada. Sendo assim, dados existentes não podem ser substituídos.

O **"a"** não remove o marcador de EOF antes de ser acrescentado ao arquivo. Depois de a conexão ter ocorrido, o comando MS-DOS TYPE só mostra dados até o marcador de EOF original, e não qualquer dado anexado ao arquivo. O **"+"** modo remove o marcador de EOF antes de ser acrescentado ao arquivo. Depois de anexar, o comando MS-DOS TYPE mostra todos os dados no arquivo. O **"+"** modo é exigido para conexão com um arquivo de fluxo terminado com o marcador de EOF CTRL + Z.

Quando o **"r +"**, **"w +"**, ou **"+"** tipo de acesso for especificado, são permitidas leitura e gravação (o arquivo deve ser aberto para "atualização"). No entanto, quando você muda entre leitura e gravação, deve haver uma operação [fsetpos](fsetpos.md), [fseek](fseek-fseeki64.md) ou [rewind](rewind.md) intermediária. A posição atual pode ser especificada para o [fsetpos](fsetpos.md) ou [fseek](fseek-fseeki64.md) operação, se desejado. Além dos valores acima, um dos seguintes caracteres pode ser incluído na *modo* cadeia de caracteres para especificar o modo de conversão para novas linhas.

|*modo* modificador|Modo de conversão|
|-|-|
| **t** | Abra no modo de texto (convertido). |
| **b** | Abra em um modo binário (não convertido); as conversões envolvendo caracteres de retorno de carro e avanço de linha são suprimidas. |

No modo de texto (convertido), as combinações de retorno-linha (CR-LF) do carro são convertidas em caracteres de única linha (LF) na entrada; Caracteres de LF são convertidos em combinações de CR-LF na saída. Além disso, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura ou de leitura e gravação com **"+"**, a biblioteca de tempo de execução verifica se há um CTRL + Z no final do arquivo e o remove, se possível. Isso é feito porque usar [fseek](fseek-fseeki64.md) e [ftell](ftell-ftelli64.md) para movimentação dentro de um arquivo pode causar [fseek](fseek-fseeki64.md) se comportar incorretamente perto do fim do arquivo. O **t** opção é uma extensão da Microsoft que não deve ser usada quando se desejar portabilidade ANSI.

Se **t** ou **b** não é fornecido na *modo*, o modo de translação padrão é definido pela variável global [fmode](../../c-runtime-library/fmode.md). Se **t** ou **b** é o prefixo para o argumento, a função falhará e retornará **nulo**.

Para saber mais sobre os modos de texto e binário, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**freopen**|\<stdio.h>|
|**_wfreopen**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos da plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão que estão associados com o console **stdin**, **stdout**, e **stderr**, deverá ser redirecionado para funções de tempo de execução C possam ser usados em aplicativos UWP . Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_freopen.c
// compile with: /W3
// This program reassigns stderr to the file
// named FREOPEN.OUT and writes a line to that file.
#include <stdio.h>
#include <stdlib.h>

FILE *stream;

int main( void )
{
   // Reassign "stderr" to "freopen.out":
   stream = freopen( "freopen.out", "w", stderr ); // C4996
   // Note: freopen is deprecated; consider using freopen_s instead

   if( stream == NULL )
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

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fclose, _fcloseall](fclose-fcloseall.md)<br/>
[_fdopen, _wfdopen](fdopen-wfdopen.md)<br/>
[_fileno](fileno.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_setmode](setmode.md)<br/>
