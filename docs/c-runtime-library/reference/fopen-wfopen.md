---
title: fopen, _wfopen
ms.date: 11/04/2016
api_name:
- _wfopen
- fopen
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
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- fopen
- _wfopen
- _tfopen
- corecrt_wstdio/_wfopen
- stdio/fopen
helpviewer_keywords:
- opening files, for file I/O
- wfopen function
- tfopen function
- _tfopen function
- _wfopen function
- files [C++], opening
- fopen function
ms.assetid: e868993f-738c-4920-b5e4-d8f2f41f933d
ms.openlocfilehash: 0e50854cf35dd58f7f59f67ed861247b51fd4541
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957046"
---
# <a name="fopen-_wfopen"></a>fopen, _wfopen

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

Cada uma dessas funções retorna um ponteiro para o arquivo aberto. Um valor de ponteiro nulo indica um erro. Se o *nome do arquivo* ou o *modo* for **nulo** ou uma cadeia de caracteres vazia, essas funções dispararão o manipulador de parâmetro inválido, que é descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão **NULL** e definirá **errno** como **EINVAL**.

Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **fopen** abre o arquivo especificado por *filename*. Por padrão, uma cadeia de caracteres de *nome de arquivo* estreita é interpretada usando a página de código ANSI (CP_ACP). Em aplicativos de área de trabalho do Windows, isso pode ser alterado para a página de código OEM (CP_OEMCP) usando a função [SetFileApisToOEM](/windows/win32/api/fileapi/nf-fileapi-setfileapistooem). Você pode usar a função [AreFileApisANSI](/windows/win32/api/fileapi/nf-fileapi-arefileapisansi) para determinar se o *nome do arquivo* é interpretado usando o ANSI ou a página de código OEM padrão do sistema. **_wfopen** é uma versão de caractere largo do **fopen**; os argumentos para **_wfopen** são cadeias de caracteres largos. Caso contrário, **_wfopen** e **fopen** se comportam de forma idêntica. Apenas usar **_wfopen** não afeta o conjunto de caracteres codificado usado no fluxo de arquivos.

**fopen** aceita caminhos que são válidos no sistema de arquivos no ponto de execução; o **fopen** aceita caminhos UNC e caminhos que envolvem unidades de rede mapeadas, desde que o sistema que executa o código tenha acesso ao compartilhamento ou à unidade mapeada no momento da execução. Ao construir caminhos para **fopen**, verifique se as unidades, os caminhos ou os compartilhamentos de rede estarão disponíveis no ambiente de execução. É possível usar barras (/) ou barras invertidas (\\) como separadores de diretório em um caminho.

Sempre verifique o valor retornado para ver se o ponteiro é NULL antes de realizar qualquer operação adicional no arquivo. Se ocorrer um erro, a variável global **errno** será definida e poderá ser usada para obter informações de erro específicas. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="unicode-support"></a>Suporte para Unicode

o **fopen** dá suporte a fluxos de arquivos Unicode. Para abrir um arquivo Unicode, passe um sinalizador **CCS** que especifica a codificação desejada para **fopen**, da seguinte maneira.

> **FILE \*fp = fopen("newfile.txt", "rt+, ccs=** _encoding_ **");**

Os valores permitidos de *codificação* são **Unicode**, **UTF-8**e **UTF-16LE**.

Quando um arquivo é aberto no modo Unicode, as funções de entrada convertem os dados lidos do arquivo em dados UTF-16 armazenados como tipo **wchar_t**. As funções que gravam em um arquivo aberto no modo Unicode esperam buffers que contêm dados UTF-16 armazenados como tipo **wchar_t**. Se o arquivo estiver codificado como UTF-8, os dados em UTF-16 serão convertidos em UTF-8 no momento da gravação. O conteúdo do arquivo codificado como UTF-8 será convertido em UTF-16 no momento da leitura. Tentar ler ou gravar um número ímpar de bytes no modo Unicode gera um erro de [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Para ler ou gravar dados armazenados em seu programa como UTF-8, use um modo de arquivo de texto ou binário em vez do modo Unicode. Você é responsável por toda a conversão de codificação necessária.

Se o arquivo já existir e for aberto para ler ou anexar, o BOM (Marca de ordem de byte), se presente no arquivo, determina a codificação. A codificação de BOM tem precedência sobre a codificação especificada pelo sinalizador **CCS** . A codificação **CCS** é usada somente quando nenhuma bom está presente ou o arquivo é um arquivo novo.

> [!NOTE]
> A detecção de BOM só se aplica a arquivos que são abertos no modo Unicode (isto é, passando o sinalizador **CCS** ).

A tabela a seguir resume os modos que são usados para vários sinalizadores de **CCS** fornecidos para **fopen** e marcas de ordem de byte no arquivo.

### <a name="encodings-used-based-on-ccs-flag-and-bom"></a>Codificações usadas com base em Sinalizador ccs e BOM

|sinalizador CCS|Nenhuma BOM (ou novo arquivo)|BOM UTF-8|BOM UTF-16|
|----------------|----------------------------|-----------------|------------------|
|**UNICODE**|**UTF-16LE**|**UTF-8**|**UTF-16LE**|
|**UTF-8**|**UTF-8**|**UTF-8**|**UTF-16LE**|
|**UTF-16LE**|**UTF-16LE**|**UTF-8**|**UTF-16LE**|

Arquivos abertos para gravação no modo Unicode têm uma BOM gravada neles automaticamente.

Se *Mode* for **"a, CCS =** _Encoding_ **"** , o **fopen** primeiro tentará abrir o arquivo usando o acesso de leitura e gravação. Se isso for bem-sucedido, a função lê a BOM para determinar a codificação para o arquivo; se falhar, a função usa a codificação padrão para o arquivo. Em ambos os casos, o **fopen** abrirá o arquivo novamente usando o acesso somente gravação. (Isso se aplica apenas ao modo **"a"** , não ao modo **"a +"** .)

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tfopen**|**fopen**|**fopen**|**_wfopen**|

O *modo* de cadeia de caracteres especifica o tipo de acesso solicitado para o arquivo, como a seguir.

|*modo*|Access|
|-|-|
| **"r"** | Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, a chamada **fopen** falhará. |
| **"w"** | Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos. |
| **"a"** | Abre para gravação no fim do arquivo (conexão) sem remover o marcador de EOF (Fim de arquivo) antes de novos dados serem gravados no arquivo. Cria o arquivo se ele não existir. |
| **"r+"** | Abre para leitura e gravação. O arquivo deve existir. |
| **"w+"** | Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos. |
| **"a+"** | Abre para leitura e conexão. A operação de conexão inclui a remoção do marcador de EOF antes de os novos dados serem gravados no arquivo. O marcador de EOF não é restaurado após a gravação ser concluída. Cria o arquivo se ele não existir. |

Quando um arquivo é aberto usando o tipo de acesso **"a"** ou o tipo de acesso **"a +"** , todas as operações de gravação ocorrem no final do arquivo. O ponteiro do arquivo pode ser reposicionado usando [fseek](fseek-fseeki64.md) ou [retrocesso](rewind.md), mas sempre é movido de volta para o final do arquivo antes de qualquer operação de gravação ser executada. Portanto, dados existentes não podem ser substituídos.

O modo **"a"** não remove o marcador EOF antes que ele seja anexado ao arquivo. Depois de a conexão ter ocorrido, o comando MS-DOS TYPE só mostra dados até o marcador de EOF original, e não qualquer dado anexado ao arquivo. Antes de acrescentar ao arquivo, o modo **"a +"** remove o marcador EOF. Depois de anexar, o comando MS-DOS TYPE mostra todos os dados no arquivo. O modo **"a +"** é necessário para anexar a um arquivo de fluxo que é encerrado com o marcador EOF CTRL + Z.

Quando o tipo de acesso **"r +"** , **"w +"** ou **"a +"** é especificado, a leitura e a gravação são habilitadas (o arquivo é considerado aberto para "atualização"). Porém, ao trocar de leitura para gravação, a operação de entrada deve encontrar um marcador de EOF. Se não houver EOF, você deve usar uma chamada intermediária para uma função de posicionamento de arquivo. As funções de posicionamento de arquivo são **fsetpos**, [fseek](fseek-fseeki64.md)e [retrocesso](rewind.md). Quando você muda de gravação para leitura, deve usar uma chamada intermediária para **fflush** ou para uma função de posicionamento de arquivo.

Além dos valores anteriores, os caracteres a seguir podem ser anexados ao *modo* para especificar o modo de tradução para caracteres de nova linha.

|modificador de *modo*|Modo de tradução|
|-|-|
| **t** | Abra no modo de texto (convertido). |
| **b** | Abrir no modo binário (não traduzido); as traduções que envolvem caracteres de retorno de carro e de alimentação de linha são suprimidas. |

No modo de texto, CTRL + Z é interpretado como um caractere EOF na entrada. Em arquivos abertos para leitura/gravação usando **"a +"** , o **FOPEN** verifica um CTRL + Z no final do arquivo e o Remove, se possível. Isso é feito porque usar [fseek](fseek-fseeki64.md) e **ftell** para mover dentro de um arquivo que termina com CTRL + Z pode fazer com que o [fseek](fseek-fseeki64.md) se comporte incorretamente perto do final do arquivo.

No modo de texto, as combinações de retorno de carro-alimentação de linha são convertidas em feeds de linha única na entrada e os caracteres de alimentação de linha são convertidos em combinações de retorno de carro-alimentação de linha na saída. Quando uma função de E/S de fluxo Unicode opera no modo de texto (o padrão), presume-se que o fluxo de origem ou destino é uma sequência de caracteres multibyte. Portanto, as funções de entrada de fluxo Unicode convertem caracteres multibyte em caracteres largos (como por uma chamada à função **mbtowc**). Pelo mesmo motivo, as funções de saída de fluxo Unicode convertem caracteres largos em caracteres multibyte (como por uma chamada à função **wctomb**).

Se **t** ou **b** não for fornecido no *modo*, o modo de tradução padrão será definido pela variável global [_fmode](../../c-runtime-library/fmode.md). Se **t** ou **b** for prefixado para o argumento, a função falhará e retornará **NULL**.

Para obter mais informações sobre como usar os modos de texto e binário em Unicode e E/S de fluxo multibyte, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [E/S de fluxo Unicode em modos de texto e binários](../../c-runtime-library/unicode-stream-i-o-in-text-and-binary-modes.md).

As opções a seguir podem ser acrescentadas ao *modo* para especificar comportamentos adicionais.

|modificador de *modo*|Comportamento|
|-|-|
| **c** | Habilite o sinalizador de confirmação para o *nome de arquivo* associado para que o conteúdo do buffer de arquivo seja gravado diretamente no disco se o **fflush** ou **_flushall** for chamado. |
| **n** | Redefina o sinalizador de confirmação para o *nome de arquivo* associado como "sem confirmação". Esse é o padrão. Também substitui o sinalizador de confirmação global se você vincular o programa a COMMODE.OBJ. O padrão do sinalizador de confirmação global é "no-commit", a menos que você vincule explicitamente o programa a COMMODE.OBJ (consulte [Opções de vinculação](../../c-runtime-library/link-options.md)). |
| **N** | Especifica que o arquivo não é herdado por processos filhos. |
| **S** | Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso. |
| **R** | Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso. |
| **T** | Especifica um arquivo como temporário. Se possível, ele não é liberado no disco. |
| **D** | Especifica um arquivo como temporário. É excluído quando o último ponteiro de arquivo é fechado. |
| **ccs=** _encoding_ | Especifica o conjunto de caracteres codificado a ser usado (um de **UTF-8**, **UTF-16LE**ou **Unicode**) para esse arquivo. Deixe não especificado se desejar codificação ANSI. |

Os caracteres válidos para a cadeia de caracteres de *modo* usada em **fopen** e **_fdopen** correspondem aos argumentos *oflag* usados em [_open](open-wopen.md) e [_sopen](sopen-wsopen.md), da seguinte maneira.

|Caracteres no *modo* String|Valor equivalente de oflag \_para Open\_/sopen|
|-------------------------------|----------------------------------------------------|
|**a**|**\_O\_WRONLY** &#124; &#124; **oAppend\_(geralmente o WRONLY o CRI \_**  **\_\_** &#124;  **\_\_**  **\_ O\_Append**)|
|**a +**|**\_O\_RDWR** &#124; &#124; **oAppend\_(geralmente o RDWR o Append \_**  **\_\_** &#124;  **\_\_**  **\_ O\_cri** )|
|**r**|**\_O\_RDONLY**|
|**r+**|**\_O\_RDWR**|
|**w**|**\_O\_WRONLY** (geralmente  **\_oWRONLY\_** &#124; **ocri\_o trunc) \_** &#124;  **\_\_**|
|**w+**|**\_O\_RDWR** (geralmente  **\_oRDWR\_** &#124; **ocri\_o trunc) \_** &#124;  **\_\_**|
|**b**|**\_O\_BINARY**|
|**t**|**\_O\_TEXT**|
|**c**|Nenhum|
|**n**|Nenhum|
|**S**|**\_O\_SEQUENCIAL**|
|**R**|**\_O\_ALEATÓRIO**|
|**T**|**\_O\_SHORTLIVED**|
|**D**|**\_O\_TEMPORÁRIO**|
|**ccs=UNICODE**|**\_O\_WTEXT**|
|**ccs=UTF-8**|**\_O\_UTF8**|
|**ccs=UTF-16LE**|**\_O\_UTF16**|

Se você estiver usando o modo **RB** , não precisará portar seu código e, se você pretende ler a maior parte de um arquivo grande ou se não estiver preocupado com o desempenho da rede, também poderá considerar se deseja usar os arquivos do Win32 mapeados na memória como uma opção.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fopen**|\<stdio.h>|
|**_wfopen**|\<stdio.h> ou \<wchar.h>|

**_wfopen** é uma extensão da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

As opções de *modo* **c**, **n**, **t**, **S**, **R**, **t**e **D** são extensões da Microsoft para **fopen** e **_fdopen** e não devem ser usadas onde a portabilidade ANSI é desejada.

## <a name="example-1"></a>Exemplo 1

O seguinte programa abre dois arquivos.  Ele usa **fclose** para fechar o primeiro arquivo e **_fcloseall** para fechar todos os arquivos restantes.

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
