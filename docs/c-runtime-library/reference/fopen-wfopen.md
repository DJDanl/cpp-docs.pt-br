---
title: fopen, _wfopen | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _wfopen
- fopen
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
- fopen
- _wfopen
- _tfopen
- corecrt_wstdio/_wfopen
- stdio/fopen
dev_langs:
- C++
helpviewer_keywords:
- opening files, for file I/O
- wfopen function
- tfopen function
- _tfopen function
- _wfopen function
- files [C++], opening
- fopen function
ms.assetid: e868993f-738c-4920-b5e4-d8f2f41f933d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1633f846d1e3b6300463ef1cd3b9a6dd8c1446a7
ms.sourcegitcommit: b92ca0b74f0b00372709e81333885750ba91f90e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/16/2018
ms.locfileid: "42573208"
---
# <a name="fopen-wfopen"></a>fopen, _wfopen

Abre um arquivo. Versões mais seguras dessas funções que executam validação de parâmetro adicional e retornam códigos de erro estão disponíveis; consulte [fopen_s, wfopen_s](fopen-s-wfopen-s.md).

## <a name="syntax"></a>Sintaxe

```C
FILE *fopen(
   const char *filename,
   const char *mode
);
FILE *_wfopen(
   const wchar_t *filename,
   const wchar_t *mode
);
```

### <a name="parameters"></a>Parâmetros

*filename*<br/>
Nome do arquivo.

*modo*<br/>
Tipo de acesso habilitado.

## <a name="return-value"></a>Valor de retorno

Cada uma dessas funções retorna um ponteiro para o arquivo aberto. Um valor de ponteiro nulo indica um erro. Se *filename* ou *modo* está **nulo** ou uma cadeia de caracteres vazia, essas funções disparam o manipulador de parâmetro inválido, que é descrito em [parâmetro Validação](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão **nulo** e defina **errno** para **EINVAL**.

Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **fopen** função abre o arquivo especificado por *filename*. Por padrão, uma *filename* cadeia de caracteres é interpretada usando a página de código ANSI (CP_ACP). Em aplicativos de área de trabalho do Windows, isso pode ser alterado para a página de código OEM (CP_OEMCP) usando a função [SetFileApisToOEM](/windows/desktop/api/fileapi/nf-fileapi-setfileapistooem). Você pode usar o [AreFileApisANSI](/windows/desktop/api/fileapi/nf-fileapi-arefileapisansi) função para determinar se *filename* é interpretado usando o ANSI ou a página de código de OEM do sistema padrão. **wfopen** é uma versão de caractere largo de **fopen**; os argumentos a serem **wfopen** são cadeias de caracteres largos. Caso contrário, **wfopen** e **fopen** se comportam de forma idêntica. Usando apenas **wfopen** não afeta o conjunto de caracteres codificado usado no fluxo de arquivos.

**fopen** aceita caminhos válidos no sistema de arquivos no ponto de execução; **fopen** aceita caminhos UNC e caminhos que envolvem unidades de rede mapeadas desde que o sistema que executa o código tenha acesso ao compartilhamento ou unidade mapeada no momento da execução. Quando você constrói caminhos para **fopen**, certifique-se de que unidades, caminhos ou compartilhamentos de rede estará disponíveis no ambiente de execução. É possível usar barras (/) ou barras invertidas (\\) como separadores de diretório em um caminho.

Sempre verifique o valor retornado para ver se o ponteiro é NULL antes de realizar qualquer operação adicional no arquivo. Se ocorrer um erro, a variável global **errno** é definido e pode ser usado para obter informações de erro específicas. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="unicode-support"></a>Suporte para Unicode

**fopen** dá suporte a fluxos de arquivo Unicode. Para abrir um arquivo Unicode, passe uma **ccs** sinalizador que especifica a codificação desejada para **fopen**, da seguinte maneira.

> **ARQUIVO *fp = fopen ("NewFile", "rt + ccs =**_codificação_**");**

Valores de permitidos *codificação* são **UNICODE**, **UTF-8**, e **UTF-16LE**.

Quando um arquivo é aberto no modo Unicode, funções de entrada convertem os dados lidos do arquivo em dados UTF-16 armazenados como tipo **wchar_t**. Funções que gravam em um arquivo aberto no modo Unicode esperam buffers que contenham dados UTF-16 armazenados como tipo **wchar_t**. Se o arquivo estiver codificado como UTF-8, os dados em UTF-16 serão convertidos em UTF-8 no momento da gravação. O conteúdo do arquivo codificado como UTF-8 será convertido em UTF-16 no momento da leitura. Tentar ler ou gravar um número ímpar de bytes no modo Unicode gera um erro de [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Para ler ou gravar dados armazenados em seu programa como UTF-8, use um modo de arquivo de texto ou binário em vez do modo Unicode. Você é responsável por toda a conversão de codificação necessária.

Se o arquivo já existir e for aberto para ler ou anexar, o BOM (Marca de ordem de byte), se presente no arquivo, determina a codificação. A codificação BOM tem precedência sobre a codificação especificada pelo **ccs** sinalizador. O **ccs** codificação é usada apenas quando nenhuma BOM estiver presente ou o arquivo é um novo arquivo.

> [!NOTE]
> Detecção da BOM só se aplica a arquivos que são abertos no modo Unicode (ou seja, passando o **ccs** sinalizador).

A tabela a seguir resume os modos que são usados para várias **ccs** sinalizadores dados ao **fopen** e marcas de ordem de Byte no arquivo.

### <a name="encodings-used-based-on-ccs-flag-and-bom"></a>Codificações usadas com base em Sinalizador ccs e BOM

|CCS sinalizador|Nenhuma BOM (ou novo arquivo)|BOM: UTF-8|BOM: UTF-16|
|----------------|----------------------------|-----------------|------------------|
|**UNICODE**|**UTF-16LE**|**UTF-8**|**UTF-16LE**|
|**UTF-8**|**UTF-8**|**UTF-8**|**UTF-16LE**|
|**UTF-16LE**|**UTF-16LE**|**UTF-8**|**UTF-16LE**|

Arquivos abertos para gravação no modo Unicode têm uma BOM gravada neles automaticamente.

Se *modo* é **", ccs =**_codificação_**"**, **fopen** primeiro tenta abrir o arquivo por meio de leitura e acesso de gravação. Se isso for bem-sucedido, a função lê a BOM para determinar a codificação para o arquivo; se falhar, a função usa a codificação padrão para o arquivo. Em ambos os casos **fopen** reabrirá o arquivo usando acesso somente gravação. (Isso se aplica ao **"a"** modo apenas, não ao **"+"** modo.)

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tfopen**|**fopen**|**fopen**|**_wfopen**|

A cadeia de caracteres *modo* Especifica o tipo de acesso solicitado para o arquivo, da seguinte maneira.

|*modo*|Acesso|
|-|-|
**"r"**|Abre para leitura. Se o arquivo não existe ou não for encontrado, o **fopen** chamar falhar.
**"w"**|Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.
**"a"**|Abre para gravação no fim do arquivo (conexão) sem remover o marcador de EOF (Fim de arquivo) antes de novos dados serem gravados no arquivo. Cria o arquivo se ele não existir.
**"r+"**|Abre para leitura e gravação. O arquivo deve existir.
**"w+"**|Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos.
**"a+"**|Abre para leitura e conexão. A operação de conexão inclui a remoção do marcador de EOF antes de os novos dados serem gravados no arquivo. O marcador de EOF não é restaurado após a gravação ser concluída. Cria o arquivo se ele não existir.

Quando um arquivo é aberto usando o **"a"** tipo de acesso ou o **"+"** acessar o tipo, todas as operações de gravação ocorrem no final do arquivo. O ponteiro do arquivo pode ser reposicionado usando [fseek](fseek-fseeki64.md) ou [rewind](rewind.md), mas é sempre movido de volta para o final do arquivo antes de qualquer gravação a operação é executada. Portanto, dados existentes não podem ser substituídos.

O **"a"** modo não remove o marcador de EOF antes de ser anexado ao arquivo. Depois de a conexão ter ocorrido, o comando MS-DOS TYPE só mostra dados até o marcador de EOF original, e não qualquer dado anexado ao arquivo. Antes de anexar ao arquivo, o **"+"** modo remove o marcador de EOF. Depois de anexar, o comando MS-DOS TYPE mostra todos os dados no arquivo. O **"+"** modo é exigido para conexão com um arquivo de fluxo terminado com o marcador de EOF CTRL + Z.

Quando o **"r +"**, **"w +"**, ou **"+"** tipo de acesso for especificado, a leitura e gravação estão habilitados (o arquivo deve ser aberto para "atualização"). Porém, ao trocar de leitura para gravação, a operação de entrada deve encontrar um marcador de EOF. Se não houver EOF, você deve usar uma chamada intermediária para uma função de posicionamento de arquivo. As funções de posicionamento de arquivo são **fsetpos**, [fseek](fseek-fseeki64.md), e [rewind](rewind.md). Quando você alternar de gravação para leitura, você deve usar uma chamada intermediária para **fflush** ou para uma função de posicionamento de arquivo.

Além dos valores anteriores, os caracteres a seguir podem ser anexados à *modo* para especificar o modo de conversão de caracteres de nova linha.

|*modo* modificador|Modo de conversão|
|-|-|
**t**|Abra no modo de texto (convertido).
**b**|Abra em um modo binário (não convertido); as conversões envolvendo caracteres de retorno de carro e avanço de linha são suprimidas.

No modo de texto, CTRL + Z é interpretado como um caractere EOF na entrada. Em arquivos que são abertos para leitura/gravação usando **"+"**, **fopen** verifica se há um CTRL + Z no final do arquivo e o remove, se for possível. Isso é feito porque usar [fseek](fseek-fseeki64.md) e **ftell** para movimentação dentro de um arquivo que termina com CTRL + Z pode fazer [fseek](fseek-fseeki64.md) se comportar incorretamente perto do fim do arquivo.

No modo de texto, combinações de avanço de linha de retorno de carro são convertidas em avanços de linha simples na entrada e caracteres de avanço de linha são convertidos em combinações de avanço de linha de retorno de carro na saída. Quando uma função de E/S de fluxo Unicode opera no modo de texto (o padrão), presume-se que o fluxo de origem ou destino é uma sequência de caracteres multibyte. Portanto, as funções de entrada de fluxo Unicode convertem caracteres multibyte em caracteres largos (como por uma chamada à função **mbtowc**). Pelo mesmo motivo, as funções de saída de fluxo Unicode convertem caracteres largos em caracteres multibyte (como por uma chamada à função **wctomb**).

Se **t** ou **b** não é fornecido na *modo*, o modo de translação padrão é definido pela variável global [fmode](../../c-runtime-library/fmode.md). Se **t** ou **b** é o prefixo para o argumento, a função falhará e retornará **nulo**.

Para obter mais informações sobre como usar os modos de texto e binário em Unicode e E/S de fluxo multibyte, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [E/S de fluxo Unicode em modos de texto e binários](../../c-runtime-library/unicode-stream-i-o-in-text-and-binary-modes.md).

As opções a seguir podem ser anexadas à *modo* para especificar comportamentos adicionais.

|*modo* modificador|Comportamento|
|-|-|
**c**|Habilitar o sinalizador de confirmação associado *filename* para que o conteúdo do buffer de arquivo sejam gravado diretamente no disco, se **fflush** ou **flushall** é chamado.
**n**|Redefinir o sinalizador de confirmação associado *filename* para "no-commit". Esse é o padrão. Também substitui o sinalizador de confirmação global se você vincular o programa a COMMODE.OBJ. O padrão do sinalizador de confirmação global é "no-commit", a menos que você vincule explicitamente o programa a COMMODE.OBJ (consulte [Opções de vinculação](../../c-runtime-library/link-options.md)).
**N**|Especifica que o arquivo não é herdado por processos filhos.
**S**|Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso.
**R**|Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso.
**T**|Especifica um arquivo como temporário. Se possível, ele não é liberado no disco.
**D**|Especifica um arquivo como temporário. É excluído quando o último ponteiro de arquivo é fechado.
**CCS =**_codificação_|Especifica o caractere codificado definido para usar (um dos **UTF-8**, **UTF-16LE**, ou **UNICODE**) para esse arquivo. Deixe não especificado se desejar codificação ANSI.

Caracteres válidos para o *modo* cadeia de caracteres que é usada na **fopen** e **fdopen** correspondem às *oflag* argumentos que são usados no [Open](open-wopen.md) e [sopen](sopen-wsopen.md), da seguinte maneira.

|Caracteres em *modo* cadeia de caracteres|Equivalente *oflag* valor para sopen|
|-------------------------------|----------------------------------------------------|
|**a**|**O_wronly** &#124; **o_append** (geralmente **o_wronly** &#124; **o_creat** &#124;* * o_append * *)|
|**+**|**O_rdwr** &#124; **o_append** (geralmente **o_rdwr** &#124; **o_append** &#124; **o_creat** )|
|**r**|**_O_RDONLY**|
|**r +**|**O_RDWR**|
|**w**|**O_wronly** (geralmente **o_wronly** &#124; **o_creat** &#124;* * o_trunc * *)|
|**w +**|**O_rdwr** (geralmente **o_rdwr** &#124; **o_creat** &#124; **o_trunc**)|
|**b**|**O_BINARY**|
|**t**|**_O_TEXT**|
|**c**|Nenhum|
|**n**|Nenhum|
|**S**|**_O_SEQUENTIAL**|
|**R**|**_O_RANDOM**|
|**T**|**_O_SHORTLIVED**|
|**D**|**_O_TEMPORARY**|
|**CCS = UNICODE**|**_O_WTEXT**|
|**CCS = UTF-8**|**_O_UTF8**|
|**CCS = UTF-16LE**|**_O_UTF16**|

Se você estiver usando **rb** modo, você não precisa portar seu código e se você pretende ler a maior parte de um arquivo grande ou não estiver preocupado sobre o desempenho da rede, você também pode considerar se usar memória arquivos Win32 mapeados como uma opção.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fopen**|\<stdio.h>|
|**_wfopen**|\<stdio.h> ou \<wchar.h>|

**wfopen** é uma extensão da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

O **c**, **n**, **t**, **S**, **R**, **T**, e **1!d**  *modo* opções são extensões da Microsoft para **fopen** e **fdopen** e não deve ser usado quando se desejar portabilidade ANSI.

## <a name="example-1"></a>Exemplo 1

O seguinte programa abre dois arquivos.  Ele usa **fclose** para fechar o primeiro arquivo e **fcloseall** para fechar todos os arquivos restantes.

```C
// crt_fopen.c
// compile with: /W3
// This program opens two files. It uses
// fclose to close the first file and
// _fcloseall to close all remaining files.

#include <stdio.h>

FILE *stream, *stream2;

int main( void )
{
   int numclosed;

   // Open for read (will fail if file "crt_fopen.c" does not exist)
   if( (stream  = fopen( "crt_fopen.c", "r" )) == NULL ) // C4996
   // Note: fopen is deprecated; consider using fopen_s instead
      printf( "The file 'crt_fopen.c' was not opened\n" );
   else
      printf( "The file 'crt_fopen.c' was opened\n" );

   // Open for write
   if( (stream2 = fopen( "data2", "w+" )) == NULL ) // C4996
      printf( "The file 'data2' was not opened\n" );
   else
      printf( "The file 'data2' was opened\n" );

   // Close stream if it is not NULL
   if( stream)
   {
      if ( fclose( stream ) )
      {
         printf( "The file 'crt_fopen.c' was not closed\n" );
      }
   }

   // All other files are closed:
   numclosed = _fcloseall( );
   printf( "Number of files closed by _fcloseall: %u\n", numclosed );
}
```

```Output
The file 'crt_fopen.c' was opened
The file 'data2' was opened
Number of files closed by _fcloseall: 1
```

## <a name="example-2"></a>Exemplo 2

O programa a seguir cria um arquivo (ou substitui um, se existir) no modo de texto que usa codificação Unicode.  Em seguida, ele grava duas cadeias de caracteres no arquivo e o fecha. A saída é um arquivo chamado _wfopen_test.xml, que contém os dados da seção de saída.

```C
// crt__wfopen.c
// compile with: /W3
// This program creates a file (or overwrites one if
// it exists), in text mode using Unicode encoding.
// It then writes two strings into the file
// and then closes the file.

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <wchar.h>

#define BUFFER_SIZE 50

int main(int argc, char** argv)
{
    wchar_t str[BUFFER_SIZE];
    size_t  strSize;
    FILE*   fileHandle;

    // Create an the xml file in text and Unicode encoding mode.
    if ((fileHandle = _wfopen( L"_wfopen_test.xml",L"wt+,ccs=UNICODE")) == NULL) // C4996
    // Note: _wfopen is deprecated; consider using _wfopen_s instead
    {
        wprintf(L"_wfopen failed!\n");
        return(0);
    }

    // Write a string into the file.
    wcscpy_s(str, sizeof(str)/sizeof(wchar_t), L"<xmlTag>\n");
    strSize = wcslen(str);
    if (fwrite(str, sizeof(wchar_t), strSize, fileHandle) != strSize)
    {
        wprintf(L"fwrite failed!\n");
    }

    // Write a string into the file.
    wcscpy_s(str, sizeof(str)/sizeof(wchar_t), L"</xmlTag>");
    strSize = wcslen(str);
    if (fwrite(str, sizeof(wchar_t), strSize, fileHandle) != strSize)
    {
        wprintf(L"fwrite failed!\n");
    }

    // Close the file.
    if (fclose(fileHandle))
    {
        wprintf(L"fclose failed!\n");
    }
    return 0;
}
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)<br/>
[fclose, _fcloseall](fclose-fcloseall.md)<br/>
[_fdopen, _wfdopen](fdopen-wfdopen.md)<br/>
[ferror](ferror.md)<br/>
[_fileno](fileno.md)<br/>
[freopen, _wfreopen](freopen-wfreopen.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_setmode](setmode.md)<br/>
[_sopen, _wsopen](sopen-wsopen.md)<br/>
