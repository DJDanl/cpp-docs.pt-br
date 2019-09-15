---
title: fopen_s, _wfopen_s
ms.date: 11/04/2016
api_name:
- _wfopen_s
- fopen_s
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
- fopen_s
- _tfopen_s
- _wfopen_s
helpviewer_keywords:
- _wfopen_s function
- opening files, for file I/O
- _tfopen_s function
- tfopen_s function
- wfopen_s function
- fopen_s function
- Unicode [C++], creating files
- Unicode [C++], writing files
- files [C++], opening
- Unicode [C++], files
ms.assetid: c534857e-39ee-4a3f-bd26-dfe551ac96c3
ms.openlocfilehash: 2a400918a171c0009e40be8a20b814e8ded336ce
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70957135"
---
# <a name="fopen_s-_wfopen_s"></a>fopen_s, _wfopen_s

Abre um arquivo. Estas versões de [fopen, _wfopen](fopen-wfopen.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).

## <a name="syntax"></a>Sintaxe

```C
errno_t fopen_s(
   FILE** pFile,
   const char *filename,
   const char *mode
);
errno_t _wfopen_s(
   FILE** pFile,
   const wchar_t *filename,
   const wchar_t *mode
);
```

### <a name="parameters"></a>Parâmetros

*pFile*<br/>
Um ponteiro para o ponteiro de arquivo que receberá o ponteiro para o arquivo aberto.

*filename*<br/>
Nome do arquivo.

*modo*<br/>
Tipo de acesso permitido.

## <a name="return-value"></a>Valor de retorno

Zero se for bem-sucedido; um código de erro em caso de falha. Consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses códigos de erro.

### <a name="error-conditions"></a>Condições de Erro

|*pFile*|*filename*|*modo*|Valor de retorno|Conteúdo de *pfile*|
|-------------|----------------|------------|------------------|------------------------|
|**NULL**|qualquer|qualquer|**EINVAL**|inalterado|
|qualquer|**NULL**|qualquer|**EINVAL**|inalterado|
|qualquer|qualquer|**NULL**|**EINVAL**|inalterado|

## <a name="remarks"></a>Comentários

Os arquivos que são abertos por **fopen_s** e **_wfopen_s** não são compartilháveis. Se você precisar que um arquivo seja compartilhável, use [_fsopen, _wfsopen](fsopen-wfsopen.md) com a constante de modo de compartilhamento apropriada — por exemplo, **_SH_DENYNO** para compartilhamento de leitura/gravação.

A função **fopen_s** abre o arquivo especificado por *filename*. **_wfopen_s** é uma versão de caractere largo do **fopen_s**; os argumentos para **_wfopen_s** são cadeias de caracteres largos. **_wfopen_s** e **fopen_s** se comportam de outra forma.

**fopen_s** aceita caminhos que são válidos no sistema de arquivos no ponto de execução; Caminhos e caminhos UNC que envolvem unidades de rede mapeadas são aceitos por **fopen_s** , desde que o sistema que está executando o código tenha acesso ao compartilhamento ou à unidade de rede mapeada no momento da execução. Quando você constrói caminhos para **fopen_s**, não faça suposições sobre a disponibilidade de unidades, caminhos ou compartilhamentos de rede no ambiente de execução. É possível usar barras (/) ou barras invertidas (\\) como separadores de diretório em um caminho.

Essas funções validam seus parâmetros. Se *pfile*, *filename*ou *Mode* for um ponteiro NULL, essas funções gerarão uma exceção de parâmetro inválida, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md).

Sempre verifique o valor retornado para ver se a função foi bem-sucedida antes de realizar qualquer outra operação no arquivo. Se ocorrer um erro, o código de erro será retornado e a variável global **errno** será definida. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="unicode-support"></a>Suporte para Unicode

o **fopen_s** dá suporte a fluxos de arquivos Unicode. Para abrir um arquivo Unicode novo ou existente, passe um sinalizador *CCS* que especifica a codificação desejada para **fopen_s**:

**fopen_s(&fp, "newfile.txt", "rw, ccs=** _encoding_ **");**

Os valores permitidos de *codificação* são **Unicode**, **UTF-8**e **UTF-16LE**. Se não houver nenhum valor especificado para *codificação*, **fopen_s** usará a codificação ANSI.

Se o arquivo já existir e for aberto para ler ou anexar, a BOM (Marca de ordem de byte), se presente no arquivo, determinará a codificação. A codificação de BOM tem precedência sobre a codificação especificada pelo sinalizador *CCS* . A codificação *CCS* é usada somente quando nenhuma bom está presente ou se o arquivo é um arquivo novo.

> [!NOTE]
> A detecção de BOM só se aplica a arquivos que são abertos no modo Unicode; ou seja, passando o sinalizador *CCS* .

A tabela a seguir resume os modos para vários sinalizadores de *CCS* que são fornecidos para **Fopen_s** e para marcas de ordem de byte no arquivo.

### <a name="encodings-used-based-on-ccs-flag-and-bom"></a>Codificações usadas com base em Sinalizador ccs e BOM

|sinalizador CCS|Nenhuma BOM (ou novo arquivo)|BOM UTF-8|BOM UTF-16|
|----------------|----------------------------|-----------------|------------------|
|**UNICODE**|**UTF-16LE**|**UTF-8**|**UTF-16LE**|
|**UTF-8**|**UTF-8**|**UTF-8**|**UTF-16LE**|
|**UTF-16LE**|**UTF-16LE**|**UTF-8**|**UTF-16LE**|

Arquivos abertos para gravação no modo Unicode têm uma BOM gravada neles automaticamente.

Se *Mode* for **"a, CCS =** _Encoding_ **"** , o **fopen_s** primeiro tentará abrir o arquivo com acesso de leitura e acesso de gravação. Se isso for bem-sucedido, a função lê a BOM para determinar a codificação para o arquivo; se não for bem-sucedido, a função usa a codificação padrão para o arquivo. Em ambos os casos, **fopen_s** , em seguida, reabre o arquivo com acesso somente gravação. (Isso se aplica apenas a **um** modo, e não **a +** .)

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tfopen_s**|**fopen_s**|**fopen_s**|**_wfopen_s**|

O *modo* de cadeia de caracteres especifica o tipo de acesso solicitado para o arquivo, como a seguir.

|*modo*|Access|
|-|-|
| **"r"** | Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, a chamada **fopen_s** falhará. |
| **"w"** | Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos. |
| **"a"** | Abre para gravação no fim do arquivo (conexão) sem remover o marcador de EOF (Fim de arquivo) antes de novos dados serem gravados no arquivo. Cria o arquivo se ele não existir. |
| **"r+"** | Abre para leitura e gravação. O arquivo deve existir. |
| **"w+"** | Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos. |
| **"a+"** | Abre para leitura e conexão. A operação de conexão inclui a remoção do marcador de EOF antes de os novos dados serem gravados no arquivo. O marcador de EOF não é restaurado após a gravação ser concluída. Cria o arquivo se ele não existir. |

Quando um arquivo é aberto usando o tipo de acesso **"a"** ou **"a +"** , todas as operações de gravação ocorrem no final do arquivo. O ponteiro do arquivo pode ser reposicionado usando [fseek](fseek-fseeki64.md) ou [retrocesso](rewind.md), mas sempre é movido de volta ao final do arquivo antes que qualquer operação de gravação seja executada para que os dados existentes não possam ser substituídos.

O modo **"a"** não remove o marcador EOF antes de acrescentar ao arquivo. Após o acréscimo ter ocorrido, o comando MS-DOS TYPE mostra dados somente até o marcador de EOF original e não qualquer dado acrescentado ao arquivo. O modo **"a +"** remove o marcador EOF antes de acrescentar ao arquivo. Depois de anexar, o comando MS-DOS TYPE mostra todos os dados no arquivo. O modo **"a +"** é necessário para anexar a um arquivo de fluxo que é encerrado usando o marcador de EOF CTRL + Z.

Quando o tipo de acesso **"r +"** , **"w +"** ou **"a +"** é especificado, a leitura e a gravação são permitidas. (Diz-se que o arquivo está aberto para "atualização".) Porém, ao trocar de leitura para gravação, a operação de entrada deve encontrar um marcador de EOF. Se não houver EOF, você deverá usar uma chamada intermediária para uma função de posicionamento de arquivo. As funções de posicionamento de arquivos são **fsetpos**, [fseek](fseek-fseeki64.md)e [retrocesso](rewind.md). Quando você muda de gravação para leitura, deve usar uma chamada intermediária para **fflush** ou para uma função de posicionamento de arquivo.

Além dos valores acima, os caracteres a seguir podem ser incluídos no *modo* para especificar o modo de tradução para caracteres de nova linha:

|modificador de *modo*|Modo de tradução|
|-|-|
| **t** | Abra no modo de texto (convertido). |
| **b** | Abrir no modo binário (não traduzido); as traduções que envolvem caracteres de retorno de carro e de alimentação de linha são suprimidas. |

No modo de texto (traduzido), CTRL + Z é interpretado como um caractere de final de arquivo na entrada. Em arquivos abertos para leitura/gravação com **"a +"** , o **fopen_s** verifica se há um CTRL + Z no final do arquivo e o Remove, se possível. Isso é feito porque o uso de [fseek](fseek-fseeki64.md) e **ftell** para mover dentro de um arquivo que termina com CTRL + Z pode fazer com que o [fseek](fseek-fseeki64.md) se comporte incorretamente próximo ao final do arquivo.

Além disso, no modo de texto, as combinações de alimentação de linha de retorno de carro são convertidas em feeds de linha única na entrada e os caracteres de alimentação de linha são convertidos em combinações de retorno de carro e alimentação de linha na saída. Quando uma função de E/S de fluxo Unicode opera no modo de texto (o padrão), presume-se que o fluxo de origem ou destino é uma sequência de caracteres multibyte. Portanto, as funções de entrada de fluxo Unicode convertem caracteres multibyte em caracteres largos (como por uma chamada à função **mbtowc**). Pelo mesmo motivo, as funções de saída de fluxo Unicode convertem caracteres largos em caracteres multibyte (como por uma chamada à função **wctomb**).

Se **t** ou **b** não for fornecido no *modo*, o modo de tradução padrão será definido pela variável global [_fmode](../../c-runtime-library/fmode.md). Se **t** ou **b** for prefixado para o argumento, a função falhará e retornará **NULL**.

Para obter mais informações sobre como usar os modos de texto e binário em Unicode e E/S de fluxo multibyte, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [E/S de fluxo Unicode em modos de texto e binários](../../c-runtime-library/unicode-stream-i-o-in-text-and-binary-modes.md).

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

Os caracteres válidos para a cadeia de caracteres de *modo* usada em **fopen_s** e [_fdopen](fdopen-wfdopen.md) correspondem aos argumentos *oflag* usados em [_open](open-wopen.md) e [_sopen](sopen-wsopen.md), da seguinte maneira.

|Caracteres no *modo* String|Valor equivalente de *oflag* para _open/_sopen|
|-------------------------------|----------------------------------------------------|
|**a**|**_O_WRONLY** &#124; **_O_APPEND** (geralmente **_O_WRONLY** &#124; **_O_CREAT** &#124;* * _O_APPEND * *)|
|**a +**|**_O_RDWR** &#124; **_O_APPEND** (geralmente **_O_RDWR** &#124; **_O_APPEND** &#124; **_O_CREAT** )|
|**r**|**_O_RDONLY**|
|**r+**|**_O_RDWR**|
|**w**|**_O_WRONLY** (geralmente **_O_WRONLY** &#124; **_O_CREAT** &#124;* * _O_TRUNC * *)|
|**w+**|**_O_RDWR** (geralmente **_O_RDWR** &#124; **_O_CREAT** &#124; **_O_TRUNC**)|
|**b**|**_O_BINARY**|
|**t**|**_O_TEXT**|
|**c**|Nenhum|
|**n**|Nenhum|
|**S**|**_O_SEQUENTIAL**|
|**R**|**_O_RANDOM**|
|**T**|**_O_SHORTLIVED**|
|**D**|**_O_TEMPORARY**|
|**ccs=UNICODE**|**_O_WTEXT**|
|**ccs=UTF-8**|**_O_UTF8**|
|**ccs=UTF-16LE**|**_O_UTF16**|

Se você estiver usando o modo **RB** , não precisará portar seu código e esperar ler muito do arquivo e/ou não se preocupar com o desempenho da rede, os arquivos Win32 mapeados na memória também podem ser uma opção.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fopen_s**|\<stdio.h>|
|**_wfopen_s**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

As opções de *modo* **c**, **n**e **t** são extensões da Microsoft para **fopen_s** e [_fdopen](fdopen-wfdopen.md) e não devem ser usadas onde a portabilidade ANSI é desejada.

## <a name="example"></a>Exemplo

```C
// crt_fopen_s.c
// This program opens two files. It uses
// fclose to close the first file and
// _fcloseall to close all remaining files.

#include <stdio.h>

FILE *stream, *stream2;

int main( void )
{
   errno_t err;

   // Open for read (will fail if file "crt_fopen_s.c" does not exist)
   err  = fopen_s( &stream, "crt_fopen_s.c", "r" );
   if( err == 0 )
   {
      printf( "The file 'crt_fopen_s.c' was opened\n" );
   }
   else
   {
      printf( "The file 'crt_fopen_s.c' was not opened\n" );
   }

   // Open for write
   err = fopen_s( &stream2, "data2", "w+" );
   if( err == 0 )
   {
      printf( "The file 'data2' was opened\n" );
   }
   else
   {
      printf( "The file 'data2' was not opened\n" );
   }

   // Close stream if it is not NULL
   if( stream )
   {
      err = fclose( stream );
      if ( err == 0 )
      {
         printf( "The file 'crt_fopen_s.c' was closed\n" );
      }
      else
      {
         printf( "The file 'crt_fopen_s.c' was not closed\n" );
      }
   }

   // All other files are closed:
   int numclosed = _fcloseall( );
   printf( "Number of files closed by _fcloseall: %u\n", numclosed );
}
```

```Output
The file 'crt_fopen_s.c' was opened
The file 'data2' was opened
Number of files closed by _fcloseall: 1
```

## <a name="see-also"></a>Consulte também

[E/S de fluxo](../../c-runtime-library/stream-i-o.md)<br/>
[fclose, _fcloseall](fclose-fcloseall.md)<br/>
[_fdopen, _wfdopen](fdopen-wfdopen.md)<br/>
[ferror](ferror.md)<br/>
[_fileno](fileno.md)<br/>
[freopen, _wfreopen](freopen-wfreopen.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_setmode](setmode.md)<br/>
