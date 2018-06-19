---
title: fopen_s, _wfopen_s | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: bef5587188cebe4ed7e91cbd95eb46cca7f05044
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32405621"
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

Os arquivos abertos por **fopen_s** e **wfopen_s** não são compartilhável. Se você precisar que um arquivo ser compartilhável, use [fsopen, wfsopen](fsopen-wfsopen.md) à constante apropriada de modo de compartilhamento — por exemplo, **sh_denyno** para o compartilhamento de leitura/gravação.

O **fopen_s** função abre o arquivo especificado por *filename*. **wfopen_s** é uma versão de caractere largo de **fopen_s**; os argumentos para **wfopen_s** são cadeias de caracteres do caractere largo. **wfopen_s** e **fopen_s** se comportam de forma idêntica caso contrário.

**fopen_s** aceita caminhos que são válidos no sistema de arquivos no ponto de execução; Caminhos UNC e que envolvem unidades de rede mapeadas são aceitos pelo **fopen_s** desde que o sistema que está executando o código tem acesso ao compartilhamento ou unidade de rede mapeada no momento da execução. Quando você cria caminhos para **fopen_s**, não faça suposições sobre a disponibilidade de unidades, caminhos ou compartilhamentos de rede no ambiente de execução. É possível usar barras (/) ou barras invertidas (\\) como separadores de diretório em um caminho.

Essas funções validam seus parâmetros. Se *pFile*, *filename*, ou *modo* é um ponteiro nulo, essas funções para gerar uma exceção de parâmetro inválido, conforme descrito em [validação de parâmetro ](../../c-runtime-library/parameter-validation.md).

Sempre verifique o valor retornado para ver se a função foi bem-sucedida antes de realizar qualquer outra operação no arquivo. Se ocorrer um erro, o código de erro será retornado e a variável global **errno** está definido. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="unicode-support"></a>Suporte para Unicode

**fopen_s** dá suporte a fluxos de arquivo Unicode. Para abrir um arquivo Unicode novo ou existente, passe um *ccs* sinalizador que especifica a codificação desejada para **fopen_s**:

**fopen_s (& fp, "newfile.txt", "rw, ccs =**_codificação_**");**

Permite valores de *codificação* são **UNICODE**, **UTF-8**, e **UTF-16LE**. Se há nenhum valor for especificado para *codificação*, **fopen_s** usa a codificação de ANSI.

Se o arquivo já existir e for aberto para ler ou anexar, a BOM (Marca de ordem de byte), se presente no arquivo, determinará a codificação. A codificação de BOM tem precedência sobre a codificação especificada pelo *ccs* sinalizador. O *ccs* codificação é usada somente quando nenhum BOM estiver presente ou se o arquivo é um novo arquivo.

> [!NOTE]
> Detecção de BOM só se aplica a arquivos que são abertos no modo de Unicode; ou seja, passe o *ccs* sinalizador.

A tabela a seguir resume os modos para várias *ccs* sinalizadores que recebem a **fopen_s** e marcas de ordem de bytes no arquivo.

### <a name="encodings-used-based-on-ccs-flag-and-bom"></a>Codificações usadas com base em Sinalizador ccs e BOM

|CCS sinalizador|Nenhuma BOM (ou novo arquivo)|BOM: UTF-8|BOM: UTF-16|
|----------------|----------------------------|-----------------|------------------|
|**UNICODE**|**UTF-16LE**|**UTF-8**|**UTF-16LE**|
|**UTF-8**|**UTF-8**|**UTF-8**|**UTF-16LE**|
|**UTF-16LE**|**UTF-16LE**|**UTF-8**|**UTF-16LE**|

Arquivos abertos para gravação no modo Unicode têm uma BOM gravada neles automaticamente.

Se *modo* é **", ccs =**_codificação_**"**, **fopen_s** primeiro tenta abrir o arquivo com leitura acesso e gravação. Se isso for bem-sucedido, a função lê a BOM para determinar a codificação para o arquivo; se não for bem-sucedido, a função usa a codificação padrão para o arquivo. Em ambos os casos, **fopen_s** abre o arquivo com acesso somente gravação novamente. (Isso se aplica a **um** modo, não **+**.)

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tfopen_s**|**fopen_s**|**fopen_s**|**_wfopen_s**|

A cadeia de caracteres *modo* Especifica o tipo de acesso é solicitado para o arquivo, da seguinte maneira.

|*modo*|Acesso|
|-|-|
**"r"**|Abre para leitura. Se o arquivo não existe ou não é possível encontrar o **fopen_s** chamada falhará.
**"w"**|Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.
**"a"**|Abre para gravação no fim do arquivo (conexão) sem remover o marcador de EOF (Fim de arquivo) antes de novos dados serem gravados no arquivo. Cria o arquivo se ele não existir.
**"r+"**|Abre para leitura e gravação. O arquivo deve existir.
**"w+"**|Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos.
**"a+"**|Abre para leitura e conexão. A operação de conexão inclui a remoção do marcador de EOF antes de os novos dados serem gravados no arquivo. O marcador de EOF não é restaurado após a gravação ser concluída. Cria o arquivo se ele não existir.

Quando um arquivo é aberto usando o **"a"** ou **"+"** acessar o tipo, todas as gravação operações ocorrem no final do arquivo. O ponteiro do arquivo pode ser reposicionado usando [fseek](fseek-fseeki64.md) ou [retroceder](rewind.md), mas ele é sempre movido de volta para o final do arquivo antes que qualquer gravar a operação é executada para que os dados existentes não podem ser substituídos.

O **"a"** não remove o marcador EOF antes de anexar o arquivo. Após o acréscimo ter ocorrido, o comando MS-DOS TYPE mostra dados somente até o marcador de EOF original e não qualquer dado acrescentado ao arquivo. O **"+"** modo remova o marcador EOF antes de anexar o arquivo. Depois de anexar, o comando MS-DOS TYPE mostra todos os dados no arquivo. O **"+"** modo é necessário para anexar a um arquivo de fluxo que é encerrado usando o marcador EOF CTRL + Z.

Quando o **"r +"**, **"w +"**, ou **"+"** tipo de acesso for especificado, leitura e gravação são permitidas. (Diz-se que o arquivo está aberto para "atualização".) Porém, ao trocar de leitura para gravação, a operação de entrada deve encontrar um marcador de EOF. Se não houver EOF, você deverá usar uma chamada intermediária para uma função de posicionamento de arquivo. As funções de posicionamento de arquivos são **fsetpos**, [fseek](fseek-fseeki64.md), e [retroceder](rewind.md). Quando você alternar de gravação de leitura, você deve usar uma chamada intermediária para **fflush** ou a uma função de posicionamento de arquivos.

Além dos valores acima, os seguintes caracteres podem ser incluídos em *modo* para especificar o modo de conversão de caracteres de nova linha:

|*modo* modificador|Modo de tradução|
|-|-|
**t**|Abra no modo de texto (convertido).
**b**|Abra em um modo binário (não convertido); as conversões envolvendo caracteres de retorno de carro e avanço de linha são suprimidas.

No modo de texto (traduzido), CTRL + Z é interpretado como um caractere de final de arquivo na entrada. Em arquivos abertos para leitura/gravação com **"+"**, **fopen_s** verifica um CTRL + Z no final do arquivo e remove-lo, se possível. Isso é feito porque usando [fseek](fseek-fseeki64.md) e **ftell** mover dentro de um arquivo que termina com um CTRL + Z, podem causar [fseek](fseek-fseeki64.md) se comporte incorretamente no final do arquivo.

Além disso, no modo de texto, combinações de avanço de linha de retorno de carro são convertidas em alimentações de linha únicas na entrada e caracteres de alimentação de linha são convertidos para combinações de avanço de linha de retorno de carro na saída. Quando uma função de E/S de fluxo Unicode opera no modo de texto (o padrão), presume-se que o fluxo de origem ou destino é uma sequência de caracteres multibyte. Portanto, as funções de entrada de fluxo Unicode convertem caracteres multibyte em caracteres largos (como por uma chamada à função **mbtowc**). Pelo mesmo motivo, as funções de saída de fluxo Unicode convertem caracteres largos em caracteres multibyte (como por uma chamada à função **wctomb**).

Se **t** ou **b** não é fornecido em *modo*, o modo de conversão padrão é definido pela variável global [fmode](../../c-runtime-library/fmode.md). Se **t** ou **b** é o prefixo para o argumento, a função falhará e retornará **nulo**.

Para obter mais informações sobre como usar os modos de texto e binário em Unicode e E/S de fluxo multibyte, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [E/S de fluxo Unicode em modos de texto e binários](../../c-runtime-library/unicode-stream-i-o-in-text-and-binary-modes.md).

|*modo* modificador|Comportamento|
|-|-|
**c**|Habilitar o sinalizador de confirmação associado *filename* para que o conteúdo do buffer de arquivo é gravado diretamente no disco se **fflush** ou **flushall** é chamado.
**n**|Redefinir o sinalizador de confirmação associado *filename* para "nenhuma confirmação." Esse é o padrão. Também substitui o sinalizador de confirmação global se você vincular o programa a COMMODE.OBJ. O padrão do sinalizador de confirmação global é "no-commit", a menos que você vincule explicitamente o programa a COMMODE.OBJ (consulte [Opções de vinculação](../../c-runtime-library/link-options.md)).
**N**|Especifica que o arquivo não é herdado por processos filhos.
**S**|Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso.
**R**|Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso.
**T**|Especifica um arquivo como temporário. Se possível, ele não é liberado no disco.
**D**|Especifica um arquivo como temporário. É excluído quando o último ponteiro de arquivo é fechado.
**CCS =**_codificação_|Especifica o caractere codificado definido para usar (um dos **UTF-8**, **UTF-16LE**, ou **UNICODE**) para esse arquivo. Deixe não especificado se desejar codificação ANSI.

Caracteres válidos para o *modo* cadeia de caracteres usada na **fopen_s** e [fdopen](fdopen-wfdopen.md) correspondem às *oflag* argumentos usados no [_ Abra](open-wopen.md) e [sopen](sopen-wsopen.md), da seguinte maneira.

|Caracteres de *modo* cadeia de caracteres|Equivalente *oflag* valor abrir/sopen|
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

Se você estiver usando **rb** modo, não precisará portar seu código e esperar muito do arquivo de leitura e/ou não se preocupar com o desempenho da rede, os arquivos de memória mapeada Win32 também podem ser uma opção.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**fopen_s**|\<stdio.h>|
|**_wfopen_s**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

O **c**, **n**, e **t** *modo* opções são extensões da Microsoft para **fopen_s** e [fdopen](fdopen-wfdopen.md) e não deve ser usada onde a portabilidade de ANSI é desejada.

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
