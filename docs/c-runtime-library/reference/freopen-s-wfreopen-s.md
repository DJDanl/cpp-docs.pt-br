---
title: freopen_s, _wfreopen_s
ms.date: 11/04/2016
apiname:
- _wfreopen_s
- freopen_s
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
ms.openlocfilehash: 2cdc16f21882c32933868000c6fd1d66accc74b8
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51326506"
---
# <a name="freopens-wfreopens"></a>freopen_s, _wfreopen_s

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

*pFile*<br/>
Um ponteiro para o ponteiro de arquivo a ser fornecido pela chamada.

*path*<br/>
Caminho do novo arquivo.

*modo*<br/>
Tipo de acesso permitido.

*fluxo*<br/>
Ponteiro para a estrutura **FILE**.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um código de erro. Se ocorrer um erro, o arquivo original será fechado.

## <a name="remarks"></a>Comentários

O **freopen_s** função fecha o arquivo atualmente associado *fluxo* e reatribui *fluxo* para o arquivo especificado por *caminho* . **wfreopen_s** é uma versão de caractere largo de **_freopen_s**; o *caminho* e *modo* argumentos a serem **wfreopen_s** são cadeias de caracteres largos. **wfreopen_s** e **_freopen_s** se comportam de forma idêntica caso contrário.

Se qualquer uma das *pFile*, *caminho*, *modo*, ou *fluxo* são **nulo**, ou se *caminho* é uma cadeia de caracteres vazia, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** à **EINVAL** e retornar **EINVAL**.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tfreopen_s**|**freopen_s**|**freopen_s**|**_wfreopen_s**|

**freopen_s** normalmente é usado para redirecionar os arquivos abertos previamente **stdin**, **stdout**, e **stderr** para arquivos especificados pelo usuário. O novo arquivo associado *stream* é aberto com *modo*, que é uma cadeia de caracteres que especifica o tipo de acesso solicitado para o arquivo, da seguinte maneira:

|*modo*|Acesso|
|-|-|
| **"r"** | Abre para leitura. Se o arquivo não existe ou não for encontrado, o **freopen_s** chamar falhar. |
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
|**freopen_s**|\<stdio.h>|
|**_wfreopen_s**|\<stdio.h> ou \<wchar.h>|

Não há suporte para o console em aplicativos da plataforma Universal do Windows (UWP). Os identificadores de fluxo padrão que estão associados com o console **stdin**, **stdout**, e **stderr**, deverá ser redirecionado para funções de tempo de execução C possam ser usados em aplicativos UWP . Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[freopen, _wfreopen](freopen-wfreopen.md)<br/>
[fclose, _fcloseall](fclose-fcloseall.md)<br/>
[_fdopen, _wfdopen](fdopen-wfdopen.md)<br/>
[_fileno](fileno.md)<br/>
[fopen, _wfopen](fopen-wfopen.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_setmode](setmode.md)<br/>
