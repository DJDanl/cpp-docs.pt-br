---
title: "fopen, _wfopen | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_wfopen"
  - "fopen"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "fopen"
  - "_wfopen"
  - "_tfopen"
  - "corecrt_wstdio/_wfopen"
  - "stdio/fopen"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "abrir arquivos, de e/s de arquivo"
  - "Função wfopen"
  - "Função tfopen"
  - "Função _tfopen"
  - "Função _wfopen"
  - "arquivos [C++], abrindo"
  - "Função fopen"
ms.assetid: e868993f-738c-4920-b5e4-d8f2f41f933d
caps.latest.revision: 56
caps.handback.revision: 56
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fopen, _wfopen
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Abre um arquivo. Versões mais seguras dessas funções que executam códigos de erro de validação e retornar parâmetros adicionais estão disponíveis; consulte [fopen\_s, \_wfopen\_s](../../c-runtime-library/reference/fopen-s-wfopen-s.md).  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `filename`  
 Nome do arquivo.  
  
 `mode`  
 Tipo de acesso que está habilitado.  
  
## Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para o arquivo aberto. Um valor de ponteiro nulo indica um erro. Se `filename` ou `mode` é `NULL` ou uma cadeia de caracteres vazia, essas funções acionam o manipulador de parâmetro inválido, que é descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornam `NULL` e defina `errno` para `EINVAL`.  
  
 Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 O `fopen` função abre o arquivo especificado por `filename`. Por padrão, um estreito `filename` cadeia de caracteres é interpretada usando a página de código ANSI \(CP\_ACP\). Em aplicativos de área de trabalho do Windows isso pode ser alterado para a página de código do OEM \(CP\_OEMCP\) usando o [SetFileApisToOEM](https://msdn.microsoft.com/library/windows/desktop/aa365534\(v=vs.85\).aspx) função. Você pode usar o [AreFileApisANSI](https://msdn.microsoft.com/library/windows/desktop/aa363781\(v=vs.85\).aspx) função para determinar se `filename` é interpretado usando o ANSI ou a página de código de OEM do sistema padrão.`_wfopen` é uma versão de caractere largo de `fopen`; os argumentos `_wfopen` são cadeias de caracteres largos. Caso contrário, `_wfopen` e `fopen` se comportam de forma idêntica. Usando apenas `_wfopen` não afeta o conjunto de caracteres codificado que é usado no fluxo de arquivos.  
  
 `fopen` aceita caminhos válidos no sistema de arquivos no ponto de execução; `fopen` aceita caminhos UNC e caminhos que envolvem unidades de rede mapeadas, contanto que o sistema que executa o código tenha acesso ao compartilhamento ou unidade mapeada no momento da execução. Quando você constrói caminhos para `fopen`, certifique\-se de que as unidades, caminhos ou compartilhamentos de rede estará disponíveis no ambiente de execução. Você pode usar barras \(\/\) ou barras invertidas \(\\\) como separadores de diretório em um caminho.  
  
 Sempre verifique o valor de retorno para ver se o ponteiro é NULL antes de executar quaisquer operações adicionais no arquivo. Se ocorrer um erro, a variável global `errno` é definido e podem ser usadas para obter informações sobre erros específicos. Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Suporte para Unicode  
 `fopen` oferece suporte a fluxos de arquivo Unicode. Para abrir um arquivo Unicode, passe um `ccs` Sinalizador que especifica a codificação desejada para `fopen`, da seguinte maneira.  
  
 `FILE *fp = fopen("newfile.txt", "rt+, ccs=encoding");`  
  
 Permite valores de `encoding` são `UNICODE`, `UTF-8`, e `UTF-16LE`.  
  
 Quando um arquivo é aberto no modo Unicode, funções de entrada convertem os dados lidos do arquivo de dados UTF\-16 armazenados como tipo `wchar_t`. Funções que gravam em um arquivo aberto no modo Unicode esperam buffers que contenham dados UTF\-16 armazenados como tipo `wchar_t`. Se o arquivo é codificado como UTF\-8, UTF\-16 dados são convertidos em UTF\-8 quando ele foi criado e o conteúdo do arquivo codificado em UTF\-8 é convertido em UTF\-16, quando ela é lida. Uma tentativa de ler ou gravar um número ímpar de bytes no causas de modo Unicode um [validação de parâmetro](../../c-runtime-library/parameter-validation.md) erro. Para ler ou gravar dados armazenados em seu programa como UTF\-8, use um modo de arquivo de texto ou binário em vez de um modo Unicode. Você é responsável por qualquer conversão de codificação necessária.  
  
 Se o arquivo já existe e está aberto para leitura ou o acréscimo, a ordem de BOM \(marca bytes\), se presente no arquivo, determina a codificação. A codificação BOM tem precedência sobre a codificação especificada pelo `ccs` sinalizador. O `ccs` codificação é usada apenas quando nenhuma BOM estiver presente ou o arquivo é um novo arquivo.  
  
> [!NOTE]
>  Detecção de BOM só se aplica a arquivos que são abertos no modo Unicode \(isto é, passe o `ccs` sinalizador\).  
  
 A tabela a seguir resume os modos são usados para várias `ccs` sinalizadores fornecidos ao `fopen` e marcas de ordem de Byte no arquivo.  
  
### Codificações usadas com base em sinalizador ccs e BOM  
  
|`ccs` sinalizador|Nenhuma BOM \(ou um novo arquivo\)|BOM: UTF\-8|BOM: UTF\-16|  
|-----------------------|----------------------------------------|-----------------|------------------|  
|`UNICODE`|`UTF-16LE`|`UTF-8`|`UTF-16LE`|  
|`UTF-8`|`UTF-8`|`UTF-8`|`UTF-16LE`|  
|`UTF-16LE`|`UTF-16LE`|`UTF-8`|`UTF-16LE`|  
  
 Arquivos abertos para gravação no modo Unicode têm uma BOM gravada neles automaticamente.  
  
 Se `mode` é "`a, ccs=<encoding>`", `fopen` primeiro tenta abrir o arquivo usando o acesso de leitura e gravação. Se for bem\-sucedida, a função lê a BOM para determinar a codificação do arquivo; Se isso falhar, a função usa a codificação padrão para o arquivo. Em ambos os casos, `fopen` será, em seguida, abrir o arquivo novamente usando o acesso somente gravação. \(Isso se aplica a `a` modo apenas, não `a+` modo.\)  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_tfopen`|`fopen`|`fopen`|`_wfopen`|  
  
 A cadeia de caracteres `mode` Especifica o tipo de acesso solicitado para o arquivo, da seguinte maneira.  
  
 `"r"`  
 É aberto para leitura. Se o arquivo não existe ou não pode ser encontrado, o `fopen` chamada falhará.  
  
 `"w"`  
 Abre um arquivo vazio para gravação. Se o arquivo especificado já existir, seus conteúdos são destruídos.  
  
 `"a"`  
 Abre para gravação no final do arquivo \(conexão\) sem remover o marcador de fim de arquivo \(EOF\) antes que novos dados são gravados no arquivo. Cria o arquivo se ele não existir.  
  
 `"r+"`  
 Abre para leitura e gravação. O arquivo deve existir.  
  
 `"w+"`  
 Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos.  
  
 `"a+"`  
 Abre para leitura e conexão. A operação de anexação inclui a remoção do marcador EOF antes que novos dados são gravados no arquivo. O marcador de EOF não é restaurado após a gravação. Cria o arquivo se ele não existir.  
  
 Quando um arquivo é aberto usando o `"a"` tipo de acesso ou o `"a+"` acessar o tipo, todas as operações de gravação ocorrem no final do arquivo. O ponteiro do arquivo pode ser reposicionado usando `fseek` ou `rewind`, mas é sempre movido para o final do arquivo antes de qualquer gravação a operação é executada. Portanto, os dados existentes não podem ser substituídos.  
  
 O `"a"` modo não remove o marcador de EOF antes de anexar o arquivo. Após a conexão ter ocorrido, o comando MS\-DOS TYPE só mostra dados até o marcador de EOF original e não qualquer dado anexado ao arquivo. Antes de anexar o arquivo, o `"a+"` modo remove o marcador de EOF. Depois de anexar, o comando MS\-DOS TYPE mostra todos os dados no arquivo. O `"a+"` modo é exigido para conexão com um arquivo de fluxo é encerrado com o marcador de EOF CTRL \+ Z.  
  
 Quando o `"r+"`, `"w+"`, ou `"a+"` o tipo de acesso é especificado, leitura e gravação estão habilitados \(o arquivo deve ser aberto para "atualização"\). No entanto, quando você alternar de leitura para gravação, a operação de entrada deve encontrar um marcador EOF. Se não houver nenhum EOF, você deve usar uma chamada intermediária para uma função de posicionamento de arquivo. As funções de posicionamento de arquivo são `fsetpos`, `fseek`, e `rewind`. Quando você alternar de gravação para leitura, você deve usar uma chamada intermediária para `fflush` ou em um arquivo de função de posicionamento.  
  
 Além dos valores anteriores, os seguintes caracteres podem ser anexados a `mode` para especificar o modo de conversão de caracteres de nova linha.  
  
 `t`  
 Abrir no texto \(convertido\) modo. Nesse modo, CTRL \+ Z é interpretado como um caractere EOF na entrada. Em arquivos abertos para leitura\/gravação usando `"a+"`, `fopen` verifica se há um CTRL \+ Z no final do arquivo e remove, se possível. Isso é feito porque usando `fseek` e `ftell` para movimentação dentro de um arquivo que termine com CTRL \+ Z pode causar `fseek` se comportar incorretamente perto do final do arquivo.  
  
 No modo de texto, combinações de retorno de avanço de linha de carro são convertidas em avanços de linha únicos na entrada e caracteres de avanço de linha são convertidos para combinações de retorno de avanço de linha de carro na saída. Quando uma função de e\/S de fluxo Unicode opera no modo de texto \(o padrão\), a fonte ou fluxo de destino deve para ser uma seqüência de caracteres multibyte. Portanto, as funções de entrada de fluxo Unicode convertem caracteres multibyte para caracteres largos \(como por uma chamada para o `mbtowc` função\). Pelo mesmo motivo, as funções de saída de fluxo do Unicode convertem caracteres largos para caracteres multibyte \(como por uma chamada para o `wctomb` função\).  
  
 `b`  
 Abrir no modo binário de \(não convertido\); as conversões envolvendo caracteres de retorno de carro e avanço de linha são suprimidas.  
  
 Se `t` ou `b` não for fornecido em `mode`, o modo de tradução padrão é definido pela variável global [fmode](../../c-runtime-library/fmode.md). Se `t` ou `b` é prefixado para o argumento, a função falhará e retornará `NULL`.  
  
 Para obter mais informações sobre como usar modos de texto e binários em Unicode e multibyte fluxo de e\/S, consulte [E\/S de texto e arquivo de modo binário](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [E\/S de fluxo Unicode em modos de texto e binários](../../c-runtime-library/unicode-stream-i-o-in-text-and-binary-modes.md).  
  
 `c`  
 Habilitar o sinalizador de confirmação associado `filename` para que o conteúdo do buffer de arquivo é gravado diretamente no disco, se `fflush` ou `_flushall` é chamado.  
  
 `n`  
 Redefinir o sinalizador de confirmação associado `filename` para "no\-commit." Esse é o padrão. Ele também substitui o sinalizador de confirmação global se você vincular o programa a commode. O padrão de sinalizador de confirmação global é "no\-commit", a menos que você vincule explicitamente o programa a COMMODE. OBJ \(consulte [Opções de link](../Topic/Link%20Options.md)\).  
  
 `N`  
 Especifica que o arquivo não é herdado por processos filhos.  
  
 `S`  
 Especifica que o cache é otimizado para, mas não se restringe a acesso sequencial do disco.  
  
 `R`  
 Especifica que o cache é otimizado para, mas não se restringe a acesso aleatório do disco.  
  
 `T`  
 Especifica um arquivo temporário. Se possível, ele não é liberado no disco.  
  
 `D`  
 Especifica um arquivo temporário. Ele é excluído quando o último ponteiro de arquivo é fechado.  
  
 `ccs=ENCODING`  
 Especifica o caractere codificado definido para usar \(`UTF-8`, `UTF-16LE`, ou `UNICODE`\) para esse arquivo. Deixe não especificado se desejar codificação ANSI.  
  
 Caracteres válidos para o `mode` cadeia de caracteres que é usada em `fopen` e `_fdopen` correspondem a `oflag` argumentos que são usados em [Open](../../c-runtime-library/reference/open-wopen.md) e [sopen](../../c-runtime-library/reference/sopen-wsopen.md), da seguinte maneira.  
  
|Caracteres na cadeia de modo|Equivalente `oflag` valor `_open`\/`_sopen`|  
|----------------------------------|-------------------------------------------------|  
|`a`|`_O_WRONLY &#124; _O_APPEND` \(geralmente `_O_WRONLY &#124; _O_CREAT &#124; _O_APPEND`\)|  
|`a+`|`_O_RDWR &#124; _O_APPEND` \(geralmente `_O_RDWR &#124; _O_APPEND &#124; _O_CREAT` \)|  
|`r`|`_O_RDONLY`|  
|`r+`|`_O_RDWR`|  
|`w`|`_O_WRONLY` \(geralmente `_O_WRONLY &#124; _O_CREAT &#124; _O_TRUNC`\)|  
|`w+`|`_O_RDWR` \(geralmente `_O_RDWR &#124; _O_CREAT &#124; _O_TRUNC`\)|  
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
  
 Se você estiver usando `rb` modo, não é necessário código de porta e esperar ler a maior parte de um arquivo grande ou não estiver preocupado sobre o desempenho da rede, você também pode considerar se usar memória mapeada arquivos Win32 como uma opção.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`fopen`|\< stdio \>|  
|`_wfopen`|\< stdio \> ou \< WCHAR \>|  
  
 `_wfopen` é uma extensão da Microsoft. Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
 O `c`, `n`, `t`, `S`, `R`, `T`, e `D` `mode` Opções são extensões da Microsoft para `fopen` e `_fdopen` e não deve ser usado onde se desejar portabilidade ANSI.  
  
## Exemplo  
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
O arquivo 'crt_fopen C' foi aberto o arquivo 'data2' foi aberto número de arquivos fechado por fcloseall: 1  
```  
  
## Exemplo  
 O programa a seguir cria um arquivo \(ou substitui um, se ele existir\), no modo de texto que usa codificação Unicode.  Em seguida, ele grava duas cadeias de caracteres no arquivo e fecha o arquivo. A saída é um arquivo chamado wfopen\_test, que contém os dados da seção de saída.  
  
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
  
## Equivalência do .NET Framework  
  
-   [System::IO::file::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [fclose, \_fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [\_fdopen, \_wfdopen](../Topic/_fdopen,%20_wfdopen.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [\_fileno](../Topic/_fileno.md)   
 [freopen, \_wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [\_setmode](../../c-runtime-library/reference/setmode.md)   
 [\_sopen, \_wsopen](../../c-runtime-library/reference/sopen-wsopen.md)