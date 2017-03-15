---
title: fopen, _wfopen | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 56
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: 34682e11247bc0680f0d3dfce2c3d3b73fb74aea
ms.lasthandoff: 02/25/2017

---
# <a name="fopen-wfopen"></a>fopen, _wfopen
Abre um arquivo. Versões mais seguras dessas funções que executam validação de parâmetro adicional e retornam códigos de erro estão disponíveis; consulte [fopen_s, wfopen_s](../../c-runtime-library/reference/fopen-s-wfopen-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
FILE *fopen(   
   const char *filename,  
   const char *mode   
);  
FILE *_wfopen(   
   const wchar_t *filename,  
   const wchar_t *mode   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `filename`  
 Nome do arquivo.  
  
 `mode`  
 Tipo de acesso habilitado.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para o arquivo aberto. Um valor de ponteiro nulo indica um erro. Se `filename` ou `mode` for `NULL` ou uma cadeia de caracteres vazia, essas funções disparam o manipulador de parâmetro inválido, que é descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `NULL` e definirão `errno` para `EINVAL`.  
  
 Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `fopen` abre o arquivo especificado por `filename`. Por padrão, uma cadeia de caracteres `filename` vazia é interpretada usando a página de código ANSI (CP_ACP). Em aplicativos de área de trabalho do Windows, isso pode ser alterado para a página de código OEM (CP_OEMCP) usando a função [SetFileApisToOEM](https://msdn.microsoft.com/library/windows/desktop/aa365534\(v=vs.85\).aspx). Você pode usar a função [AreFileApisANSI](https://msdn.microsoft.com/library/windows/desktop/aa363781\(v=vs.85\).aspx) para determinar se `filename` é interpretado usando o ANSI ou a página de código OEM padrão do sistema. `_wfopen` é uma versão de caractere largo de `fopen`; os argumentos para `_wfopen` são cadeias de caracteres largas. Caso contrário, `_wfopen` e `fopen` comportam-se de modo idêntico. Apenas usar `_wfopen` não afeta o conjunto de caracteres codificado usado no fluxo de arquivos.  
  
 O `fopen` aceita caminhos válidos no sistema de arquivos no ponto de execução; o `fopen` aceita caminhos UNC e caminhos que envolvem unidades de rede mapeadas desde que o sistema que executa o código tenha acesso ao compartilhamento ou à unidade mapeada no momento da execução. Quando você constrói caminhos para `fopen`, certifique-se de que unidades, caminhos ou compartilhamentos de rede estejam disponíveis no ambiente de execução. É possível usar barras (/) ou barras invertidas (\\) como separadores de diretório em um caminho.  
  
 Sempre verifique o valor retornado para ver se o ponteiro é NULL antes de realizar qualquer operação adicional no arquivo. Se ocorrer um erro, a variável global `errno` será definida e poderá ser usada para obter informações específicas sobre o erro. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="unicode-support"></a>Suporte para Unicode  
 O `fopen` oferece suporte a fluxos de arquivo Unicode. Para abrir um arquivo Unicode, passe um sinalizador `ccs`que especifique a codificação desejada para `fopen`, da seguinte maneira.  
  
 `FILE *fp = fopen("newfile.txt", "rt+, ccs=encoding");`  
  
 Os valores possíveis de `encoding` são `UNICODE`, `UTF-8` e `UTF-16LE`.  
  
 Quando um arquivo é aberto no modo Unicode, as funções de entrada convertem os dados lidos do arquivo em dados UTF-16 armazenados como tipo `wchar_t`. Funções que gravam em arquivos abertos no modo Unicode esperam buffers que contenham dados UTF-16 armazenados como tipo `wchar_t`. Se o arquivo estiver codificado como UTF-8, os dados em UTF-16 serão convertidos em UTF-8 no momento da gravação. O conteúdo do arquivo codificado como UTF-8 será convertido em UTF-16 no momento da leitura. Tentar ler ou gravar um número ímpar de bytes no modo Unicode gera um erro de [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Para ler ou gravar dados armazenados em seu programa como UTF-8, use um modo de arquivo de texto ou binário em vez do modo Unicode. Você é responsável por toda a conversão de codificação necessária.  
  
 Se o arquivo já existir e for aberto para ler ou anexar, o BOM (Marca de ordem de byte), se presente no arquivo, determina a codificação. A codificação BOM tem precedência sobre a codificação especificada pelo sinalizador `ccs`. A codificação `ccs` é usada apenas quando nenhuma BOM estiver presente ou o arquivo for um novo arquivo.  
  
> [!NOTE]
>  A detecção de BOM só se aplica a arquivos abertos no modo Unicode (ou seja, enviando o sinalizador `ccs`).  
  
 A tabela a seguir resume os modos usados para vários sinalizadores `ccs` dados a `fopen` e Marcas de Ordem de Byte no arquivo.  
  
### <a name="encodings-used-based-on-ccs-flag-and-bom"></a>Codificações usadas com base em Sinalizador ccs e BOM  
  
|Sinalizador `ccs`|Nenhuma BOM (ou novo arquivo)|BOM: UTF-8|BOM: UTF-16|  
|----------------|----------------------------|-----------------|------------------|  
|`UNICODE`|`UTF-16LE`|`UTF-8`|`UTF-16LE`|  
|`UTF-8`|`UTF-8`|`UTF-8`|`UTF-16LE`|  
|`UTF-16LE`|`UTF-16LE`|`UTF-8`|`UTF-16LE`|  
  
 Arquivos abertos para gravação no modo Unicode têm uma BOM gravada neles automaticamente.  
  
 Se `mode` for "`a, ccs=<encoding>`", o `fopen` tenta primeiro abrir o arquivo usando acesso de leitura e gravação. Se isso for bem-sucedido, a função lê a BOM para determinar a codificação para o arquivo; se falhar, a função usa a codificação padrão para o arquivo. Em qualquer caso, `fopen` reabrirá o arquivo usando acesso somente gravação. (Isso se aplica ao modo `a` apenas, não ao modo `a+`.)  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tfopen`|`fopen`|`fopen`|`_wfopen`|  
  
 A cadeia de caracteres `mode` especifica o tipo de acesso solicitado para o arquivo como a seguir.  
  
 `"r"`  
 Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, a chamada `fopen` falha.  
  
 `"w"`  
 Abre um arquivo vazio para gravação. Se o arquivo determinado existir, seus conteúdos são destruídos.  
  
 `"a"`  
 Abre para gravação no fim do arquivo (conexão) sem remover o marcador de EOF (Fim de arquivo) antes de novos dados serem gravados no arquivo. Cria o arquivo se ele não existir.  
  
 `"r+"`  
 Abre para leitura e gravação. O arquivo deve existir.  
  
 `"w+"`  
 Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos.  
  
 `"a+"`  
 Abre para leitura e conexão. A operação de conexão inclui a remoção do marcador de EOF antes de os novos dados serem gravados no arquivo. O marcador de EOF não é restaurado após a gravação ser concluída. Cria o arquivo se ele não existir.  
  
 Quando um arquivo é aberto usando o tipo de acesso `"a"` ou o tipo de acesso `"a+"`, todas as operações de gravação ocorrem no fim do arquivo. O ponteiro do arquivo pode ser reposicionado usando `fseek` ou `rewind`, mas sempre é movido de volta para o final do arquivo antes que qualquer operação de gravação seja realizada. Portanto, dados existentes não podem ser substituídos.  
  
 O modo `"a"` não remove o marcador de EOF antes que ele seja anexado ao arquivo. Depois de a conexão ter ocorrido, o comando MS-DOS TYPE só mostra dados até o marcador de EOF original, e não qualquer dado anexado ao arquivo. Antes de anexar ao arquivo, o modo `"a+"` remove o marcador de EOF. Depois de anexar, o comando MS-DOS TYPE mostra todos os dados no arquivo. O modo `"a+"` é exigido para conexão com um arquivo de fluxo terminado com o marcador de EOF CTRL+Z.  
  
 Quando o tipo de acesso `"r+"`, `"w+"` ou `"a+"` é especificado, a leitura e a gravação são habilitadas (diz-se que o arquivo está aberto para "atualização"). Porém, ao trocar de leitura para gravação, a operação de entrada deve encontrar um marcador de EOF. Se não houver EOF, você deve usar uma chamada intermediária para uma função de posicionamento de arquivo. As funções do posicionamento do arquivo são `fsetpos`, `fseek` e `rewind`. Ao trocar de gravação para leitura, você deve usar uma chamada intermediária para `fflush` ou uma função de posicionamento de arquivo.  
  
 Além dos valores anteriores, os seguintes caracteres podem ser anexados ao `mode` para especificar o modo de conversão para os caracteres newline.  
  
 `t`  
 Abra no modo de texto (convertido). Nesse modo, CTRL+Z é interpretado como um caractere de EOF na entrada. Nos arquivos que são abertos para leitura/gravação usando `"a+"`, o `fopen` verifica se há um CTRL+Z no fim do arquivo e o remove, se possível. Isso é feito porque usar `fseek` e `ftell` para movimentação dentro de um arquivo que termine com CTRL+Z pode fazer o `fseek` se comportar incorretamente perto do fim do arquivo.  
  
 No modo de texto, combinações de retorno de carro de avanço de linha são convertidas em avanços de linha simples na entrada, e caracteres de avanço de linha são convertidos em combinações de retorno de carro de avanço de linha na saída. Quando uma função de E/S de fluxo Unicode opera no modo de texto (o padrão), presume-se que o fluxo de origem ou destino é uma sequência de caracteres multibyte. Portanto, as funções de entrada de fluxo do Unicode convertem caracteres multibyte para caracteres largos (como por uma chamada à função `mbtowc`). Pelo mesmo motivo, as funções de saída de fluxo do Unicode convertem caracteres largos para caracteres multibyte (como por uma chamada à função `wctomb`).  
  
 `b`  
 Abra em um modo binário (não convertido); as conversões envolvendo caracteres de retorno de carro e avanço de linha são suprimidas.  
  
 Se `t` ou `b` não for fornecido em `mode`, o modo de conversão padrão será definido pela variável global [_fmode](../../c-runtime-library/fmode.md). Se `t` ou `b` for prefixado para o argumento, a função falha e retorna `NULL`.  
  
 Para obter mais informações sobre como usar os modos de texto e binário em Unicode e E/S de fluxo multibyte, consulte [E/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [E/S de fluxo Unicode em modos de texto e binários](../../c-runtime-library/unicode-stream-i-o-in-text-and-binary-modes.md).  
  
 `c`  
 Habilite o sinalizador de confirmação para o `filename` associado de modo que os conteúdos do buffer de arquivo sejam gravados diretamente no disco, se `fflush` ou `_flushall` for chamado.  
  
 `n`  
 Redefina o sinalizador de confirmação para o `filename` associado a "no-commit." Esse é o padrão. Também substitui o sinalizador de confirmação global se você vincular o programa a COMMODE.OBJ. O padrão do sinalizador de confirmação global é "no-commit", a menos que você vincule explicitamente o programa a COMMODE.OBJ (consulte [Opções de vinculação](../../c-runtime-library/link-options.md)).  
  
 `N`  
 Especifica que o arquivo não é herdado por processos filhos.  
  
 `S`  
 Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso.  
  
 `R`  
 Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso.  
  
 `T`  
 Especifica um arquivo como temporário. Se possível, ele não é liberado no disco.  
  
 `D`  
 Especifica um arquivo como temporário. É excluído quando o último ponteiro de arquivo é fechado.  
  
 `ccs=ENCODING`  
 Especifica o conjunto de caracteres codificado a ser usado (`UTF-8`, `UTF-16LE` ou `UNICODE`) para esse arquivo. Deixe não especificado se desejar codificação ANSI.  
  
 Caracteres válidos para a cadeia de caracteres `mode` usada em `fopen` e `_fdopen` correspondem a argumentos `oflag` usados em [_open](../../c-runtime-library/reference/open-wopen.md) e [_sopen](../../c-runtime-library/reference/sopen-wsopen.md), como segue.  
  
|Caracteres na cadeia de caracteres de modo|Valor de `oflag` equivalente a `_open`/`_sopen`|  
|-------------------------------|----------------------------------------------------|  
|`a`|`_O_WRONLY &#124; _O_APPEND`(geralmente `_O_WRONLY &#124; _O_CREAT &#124; _O_APPEND`)|  
|`a+`|`_O_RDWR &#124; _O_APPEND` (geralmente `_O_RDWR &#124; _O_APPEND &#124; _O_CREAT`)|  
|`r`|`_O_RDONLY`|  
|`r+`|`_O_RDWR`|  
|`w`|`_O_WRONLY`(geralmente `_O_WRONLY &#124; _O_CREAT &#124; _O_TRUNC`)|  
|`w+`|`_O_RDWR`(geralmente `_O_RDWR &#124; _O_CREAT &#124; _O_TRUNC`)|  
|`b`|`_O_BINARY`|  
|`t`|`_O_TEXT`|  
|`c`|Nenhum|  
|`n`|Nenhum|  
|`S`|`_O_SEQUENTIAL`|  
|`R`|`_O_RANDOM`|  
|`T`|`_O_SHORTLIVED`|  
|`D`|`_O_TEMPORARY`|  
|`ccs=UNICODE`|`_O_WTEXT`|  
|`ccs=UTF-8`|`_O_UTF8`|  
|`ccs=UTF-16LE`|`_O_UTF16`|  
  
 Se você estiver usando o modo `rb`, não precisa codificar a porta e esperar ler a maior parte de um arquivo grande ou estar preocupado com o desempenho de rede, você também pode considerar usar arquivos Win32 mapeados em memória como uma opção.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`fopen`|\<stdio.h>|  
|`_wfopen`|\<stdio.h> ou \<wchar.h>|  
  
 `_wfopen` é uma extensão da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
 As opções de `mode` `c`, `n`, `t`, `S`, `R`, `T` e `D` são extensões da Microsoft para `fopen` e `_fdopen` e não devem ser usadas quando portabilidade ANSI é desejada.  
  
## <a name="example"></a>Exemplo  
 O seguinte programa abre dois arquivos.  Ele usa `fclose` para fechar o primeiro arquivo e `_fcloseall` para fechar todos os arquivos restantes.  
  
```  
  
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
  
## <a name="example"></a>Exemplo  
 O programa a seguir cria um arquivo (ou substitui um, se existir) no modo de texto que usa codificação Unicode.  Em seguida, ele grava duas cadeias de caracteres no arquivo e o fecha. A saída é um arquivo chamado _wfopen_test.xml, que contém os dados da seção de saída.  
  
```  
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
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
  
-   [System::IO::File::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [fclose, _fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [_fdopen, _wfdopen](../../c-runtime-library/reference/fdopen-wfdopen.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [_fileno](../../c-runtime-library/reference/fileno.md)   
 [freopen, _wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)   
 [_setmode](../../c-runtime-library/reference/setmode.md)   
 [_sopen, _wsopen](../../c-runtime-library/reference/sopen-wsopen.md)
