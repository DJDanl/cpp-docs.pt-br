---
title: fopen_s, _wfopen_s
ms.date: 11/04/2016
apiname:
- _wfopen_s
- fopen_s
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
ms.openlocfilehash: 1309f991b8251bde7d614aa274d8d2e9da7a8ed3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62333320"
---
# <a name="fopens-wfopens"></a>fopen_s, _wfopen_s

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

|*pFile*|*filename*|*modo*|Valor de retorno|Conteúdo de *pFile*|
|-------------|----------------|------------|------------------|------------------------|
|**NULL**|qualquer|qualquer|**EINVAL**|inalterado|
|qualquer|**NULL**|qualquer|**EINVAL**|inalterado|
|qualquer|qualquer|**NULL**|**EINVAL**|inalterado|

## <a name="remarks"></a>Comentários

Os arquivos abertos por **fopen_s** e **wfopen_s** não são compartilháveis. Se você precisar que um arquivo seja compartilhável, use [fsopen, wfsopen](fsopen-wfsopen.md) com a constante de modo de compartilhamento apropriada — por exemplo, **sh_denyno** para o compartilhamento de leitura/gravação.

O **fopen_s** função abre o arquivo especificado por *filename*. **wfopen_s** é uma versão de caractere largo de **fopen_s**; os argumentos a serem **wfopen_s** são cadeias de caracteres largos. **wfopen_s** e **fopen_s** se comportam de forma idêntica caso contrário.

**fopen_s** aceita caminhos válidos no sistema de arquivos no ponto de execução; Caminhos UNC e caminhos que envolvem unidades de rede mapeadas são aceitas por **fopen_s** desde que o sistema que está executando o código tem acesso ao compartilhamento ou unidade de rede mapeada no momento da execução. Quando você constrói caminhos para **fopen_s**, não faça suposições sobre a disponibilidade de unidades, caminhos ou compartilhamentos de rede no ambiente de execução. É possível usar barras (/) ou barras invertidas (\\) como separadores de diretório em um caminho.

Essas funções validam seus parâmetros. Se *pFile*, *filename*, ou *modo* é um ponteiro nulo, essas funções gerarão uma exceção de parâmetro inválido, conforme descrito em [validação de parâmetro ](../../c-runtime-library/parameter-validation.md).

Sempre verifique o valor retornado para ver se a função foi bem-sucedida antes de realizar qualquer outra operação no arquivo. Se ocorrer um erro, o código de erro é retornado e a variável global **errno** está definido. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="unicode-support"></a>Suporte para Unicode

**fopen_s** dá suporte a fluxos de arquivo Unicode. Para abrir um arquivo Unicode novo ou existente, passe uma *ccs* sinalizador que especifica a codificação desejada para **fopen_s**:

**fopen_s(&fp, "newfile.txt", "rw, ccs=**_encoding_**");**

Valores de permitidos *codificação* são **UNICODE**, **UTF-8**, e **UTF-16LE**. Se há nenhum valor for especificado para *codificação*, **fopen_s** usa a codificação ANSI.

Se o arquivo já existir e for aberto para ler ou anexar, a BOM (Marca de ordem de byte), se presente no arquivo, determinará a codificação. A codificação BOM tem precedência sobre a codificação especificada pelo *ccs* sinalizador. O *ccs* codificação é usada apenas quando nenhuma BOM estiver presente ou se o arquivo é um novo arquivo.

> [!NOTE]
> Detecção da BOM só se aplica a arquivos que são abertos no modo Unicode; ou seja, passando o *ccs* sinalizador.

A tabela a seguir resume os modos para vários *ccs* sinalizadores que foram fornecidas à **fopen_s** e marcas de ordem de Byte no arquivo de.

### <a name="encodings-used-based-on-ccs-flag-and-bom"></a>Codificações usadas com base em Sinalizador ccs e BOM

|CCS sinalizador|Nenhuma BOM (ou novo arquivo)|BOM: UTF-8|BOM: UTF-16|
|----------------|----------------------------|-----------------|------------------|
|**UNICODE**|**UTF-16LE**|**UTF-8**|**UTF-16LE**|
|**UTF-8**|**UTF-8**|**UTF-8**|**UTF-16LE**|
|**UTF-16LE**|**UTF-16LE**|**UTF-8**|**UTF-16LE**|

Arquivos abertos para gravação no modo Unicode têm uma BOM gravada neles automaticamente.

Se *modo* é **", ccs =**_codificação_**"**, **fopen_s** primeiro tenta abrir o arquivo com a leitura acesso e gravação. Se isso for bem-sucedido, a função lê a BOM para determinar a codificação para o arquivo; se não for bem-sucedido, a função usa a codificação padrão para o arquivo. Em ambos os casos **fopen_s** reabrirá o arquivo com acesso somente gravação. (Isso se aplica ao **uma** apenas, não do modo **+**.)

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tfopen_s**|**fopen_s**|**fopen_s**|**_wfopen_s**|

A cadeia de caracteres *modo* Especifica o tipo de acesso solicitado para o arquivo, da seguinte maneira.

|*modo*|Acesso|
|-|-|
| **"r"** | Abre para leitura. Se o arquivo não existe ou não for encontrado, o **fopen_s** chamar falhar. |
| **"w"** | Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos. |
| **"a"** | Abre para gravação no fim do arquivo (conexão) sem remover o marcador de EOF (Fim de arquivo) antes de novos dados serem gravados no arquivo. Cria o arquivo se ele não existir. |
| **"r+"** | Abre para leitura e gravação. O arquivo deve existir. |
| **"w+"** | Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos. |
| **"a+"** | Abre para leitura e conexão. A operação de conexão inclui a remoção do marcador de EOF antes de os novos dados serem gravados no arquivo. O marcador de EOF não é restaurado após a gravação ser concluída. Cria o arquivo se ele não existir. |

Quando um arquivo é aberto usando o **"a"** ou **"+"** acessar o tipo, todas as operações de gravação ocorrem no final do arquivo. O ponteiro do arquivo pode ser reposicionado usando [fseek](fseek-fseeki64.md) ou [rewind](rewind.md), mas é sempre movido de volta até o final do arquivo antes de qualquer operação de gravação é realizada para que os dados existentes não podem ser substituídos.

O **"a"** não remove o marcador de EOF antes de ser acrescentado ao arquivo. Após o acréscimo ter ocorrido, o comando MS-DOS TYPE mostra dados somente até o marcador de EOF original e não qualquer dado acrescentado ao arquivo. O **"+"** modo remove o marcador de EOF antes de ser acrescentado ao arquivo. Depois de anexar, o comando MS-DOS TYPE mostra todos os dados no arquivo. O **"+"** modo é exigido para conexão com um arquivo de fluxo terminado com o marcador de EOF CTRL + Z.

Quando o **"r +"**, **"w +"**, ou **"+"** tipo de acesso for especificado, leitura e gravação são permitidas. (Diz-se que o arquivo está aberto para "atualização".) Porém, ao trocar de leitura para gravação, a operação de entrada deve encontrar um marcador de EOF. Se não houver EOF, você deverá usar uma chamada intermediária para uma função de posicionamento de arquivo. As funções de posicionamento de arquivo são **fsetpos**, [fseek](fseek-fseeki64.md), e [rewind](rewind.md). Quando você alternar de gravação para leitura, você deve usar uma chamada intermediária para **fflush** ou a uma função de posicionamento de arquivo.

Além dos valores acima, os caracteres a seguir podem ser incluídos no *modo* para especificar o modo de conversão de caracteres de nova linha:

|*modo* modificador|Modo de conversão|
|-|-|
| **t** | Abra no modo de texto (convertido). |
| **b** | Abra em um modo binário (não convertido); as conversões envolvendo caracteres de retorno de carro e avanço de linha são suprimidas. |

No modo de texto (convertido), CTRL + Z é interpretado como um caractere de final de arquivo na entrada. Em arquivos abertos para leitura/gravação com **"+"**, **fopen_s** verifica se há um CTRL + Z no final do arquivo e o remove, se possível. Isso é feito porque usar [fseek](fseek-fseeki64.md) e **ftell** para movimentação dentro de um arquivo que termina com CTRL + Z, podem causar [fseek](fseek-fseeki64.md) se comportar incorretamente perto do fim do arquivo.

Além disso, no modo de texto, combinações de avanço de linha de retorno de carro são convertidas em avanços de linha simples na entrada e caracteres de avanço de linha são convertidos em combinações de avanço de linha de retorno de carro na saída. Quando uma função de E/S de fluxo Unicode opera no modo de texto (o padrão), presume-se que o fluxo de origem ou destino é uma sequência de caracteres multibyte. Portanto, as funções de entrada de fluxo Unicode convertem caracteres multibyte em caracteres largos (como por uma chamada à função **mbtowc**). Pelo mesmo motivo, as funções de saída de fluxo Unicode convertem caracteres largos em caracteres multibyte (como por uma chamada à função **wctomb**).

Se **t** ou **b** não é fornecido na *modo*, o modo de translação padrão é definido pela variável global [fmode](../../c-runtime-library/fmode.md). Se **t** ou **b** é o prefixo para o argumento, a função falhará e retornará **nulo**.

Para obter mais informações sobre como usar os modos de texto e binário em Unicode e E/S de fluxo multibyte, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [E/S de fluxo Unicode em modos de texto e binários](../../c-runtime-library/unicode-stream-i-o-in-text-and-binary-modes.md).

|*modo* modificador|Comportamento|
|-|-|
| **c** | Habilitar o sinalizador de confirmação associado *filename* para que o conteúdo do buffer de arquivo sejam gravado diretamente no disco, se **fflush** ou **flushall** é chamado. |
| **n** | Redefinir o sinalizador de confirmação associado *filename* para "no-commit". Esse é o padrão. Também substitui o sinalizador de confirmação global se você vincular o programa a COMMODE.OBJ. O padrão do sinalizador de confirmação global é "no-commit", a menos que você vincule explicitamente o programa a COMMODE.OBJ (consulte [Opções de vinculação](../../c-runtime-library/link-options.md)). |
| **N** | Especifica que o arquivo não é herdado por processos filhos. |
| **S** | Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso. |
| **R** | Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso. |
| **T** | Especifica um arquivo como temporário. Se possível, ele não é liberado no disco. |
| **D** | Especifica um arquivo como temporário. É excluído quando o último ponteiro de arquivo é fechado. |
| **ccs=**_encoding_ | Especifica o caractere codificado definido para usar (um dos **UTF-8**, **UTF-16LE**, ou **UNICODE**) para esse arquivo. Deixe não especificado se desejar codificação ANSI. |

Caracteres válidos para o *modo* cadeia de caracteres usada na **fopen_s** e [fdopen](fdopen-wfdopen.md) correspondem às *oflag* argumentos usados no [_ Abra](open-wopen.md) e [sopen](sopen-wsopen.md), da seguinte maneira.

|Caracteres em *modo* cadeia de caracteres|Equivalente *oflag* valor para sopen|
|-------------------------------|----------------------------------------------------|
|**a**|**_O_WRONLY** &#124; **_O_APPEND** (usually **_O_WRONLY** &#124; **_O_CREAT** &#124;** _O_APPEND**)|
|**a+**|**O_rdwr** &#124; **o_append** (geralmente **o_rdwr** &#124; **o_append** &#124; **o_creat** )|
|**r**|**_O_RDONLY**|
|**r+**|**_O_RDWR**|
|**w**|**_O_WRONLY** (usually **_O_WRONLY** &#124; **_O_CREAT** &#124;** _O_TRUNC**)|
|**w+**|**_O_RDWR** (usually **_O_RDWR** &#124; **_O_CREAT** &#124; **_O_TRUNC**)|
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

Se você estiver usando **rb** modo, não será necessário portar seu código e esperar ler uma grande parte do arquivo e/ou não se preocupa com o desempenho da rede, arquivos do Win32 mapeados na memória também podem ser uma opção.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fopen_s**|\<stdio.h>|
|**_wfopen_s**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

O **c**, **n**, e **t** *modo* opções são extensões da Microsoft para **fopen_s** e [fdopen](fdopen-wfdopen.md) e não deve ser usado quando se desejar portabilidade ANSI.

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
