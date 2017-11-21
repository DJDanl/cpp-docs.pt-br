---
title: fopen_s, _wfopen_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
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
dev_langs: C++
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
caps.latest.revision: "41"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 49a884b8ae4ea34c02a0ca57563077add4d9d6fa
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="fopens-wfopens"></a>fopen_s, _wfopen_s
Abre um arquivo. Estas versões de [fopen, _wfopen](../../c-runtime-library/reference/fopen-wfopen.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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
  
#### <a name="parameters"></a>Parâmetros  
 [out] `pFile`  
 Um ponteiro para o ponteiro de arquivo que receberá o ponteiro para o arquivo aberto.  
  
 [in] `filename`  
 Nome do arquivo.  
  
 [in] `mode`  
 Tipo de acesso permitido.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido; um código de erro em caso de falha. Consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses códigos de erro.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`pFile`|`filename`|`mode`|Valor de retorno|Conteúdo de `pFile`|  
|-------------|----------------|------------|------------------|------------------------|  
|`NULL`|qualquer|qualquer|`EINVAL`|inalterado|  
|qualquer|`NULL`|qualquer|`EINVAL`|inalterado|  
|qualquer|qualquer|NULL|`EINVAL`|inalterado|  
  
## <a name="remarks"></a>Comentários  
 Os arquivos abertos por `fopen_s` e `_wfopen_s` não são compartilháveis. Se você precisar que um arquivo seja compartilhável, use [_fsopen, _wfsopen](../../c-runtime-library/reference/fsopen-wfsopen.md) com a constante de modo de compartilhamento apropriada — por exemplo, `_SH_DENYNO` para compartilhamento de leitura/gravação.  
  
 A função `fopen_s` abre o arquivo especificado por `filename`. `_wfopen_s` é uma versão de caractere largo de `fopen_s`; os argumentos para `_wfopen_s` são cadeias de caracteres largas. Caso contrário, `_wfopen_s` e `fopen_s` se comportam de forma idêntica.  
  
 `fopen_s` aceita caminhos válidos no sistema de arquivos no ponto de execução; caminhos UNC e caminhos que envolvem unidades de rede mapeadas são aceitas por `fopen_s` desde que o sistema que executa o código tenha acesso ao compartilhamento ou à unidade de rede mapeada no momento da execução. Quando construir caminhos para `fopen_s`, não faça pressuposições sobre a disponibilidade de unidades, caminhos ou compartilhamentos de rede no ambiente de execução. É possível usar barras (/) ou barras invertidas (\\) como separadores de diretório em um caminho.  
  
 Essas funções validam seus parâmetros. Se `pFile`, `filename` ou `mode` for um ponteiro nulo, essas funções gerarão uma exceção de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Sempre verifique o valor retornado para ver se a função foi bem-sucedida antes de realizar qualquer outra operação no arquivo. Se ocorrer um erro, o código de erro será retornado e a variável global `errno` será definida. Para obter mais informações, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="unicode-support"></a>Suporte para Unicode  
 O `fopen_s` oferece suporte a fluxos de arquivo Unicode. Para abrir um arquivo Unicode novo ou existente, passe um sinalizador `ccs` que especifique a codificação desejada para `fopen_s`:  
  
 `fopen_s(&fp, "newfile.txt", "rw, ccs=`*codificação*`");`  
  
 Permite valores de *codificação* são `UNICODE`, `UTF-8`, e `UTF-16LE`. Se há nenhum valor for especificado para *codificação*, `fopen_s` usa a codificação de ANSI.  
  
 Se o arquivo já existir e for aberto para ler ou anexar, a BOM (Marca de ordem de byte), se presente no arquivo, determinará a codificação. A codificação da BOM tem precedência sobre a codificação especificada pelo sinalizador `ccs`. A codificação `ccs` é usada apenas quando nenhuma BOM estiver presente ou se o arquivo for um novo arquivo.  
  
> [!NOTE]
>  A detecção da BOM só se aplica a arquivos abertos no modo Unicode, ou seja, passando o sinalizador `ccs`.  
  
 A tabela a seguir resume os modos para vários sinalizadores `ccs` fornecidos a `fopen_s` e Marcas de ordem de byte no arquivo.  
  
### <a name="encodings-used-based-on-ccs-flag-and-bom"></a>Codificações usadas com base em Sinalizador ccs e BOM  
  
|Sinalizador `ccs`|Nenhuma BOM (ou novo arquivo)|BOM: UTF-8|BOM: UTF-16|  
|----------------|----------------------------|-----------------|------------------|  
|`UNICODE`|`UTF-16LE`|`UTF-8`|`UTF-16LE`|  
|`UTF-8`|`UTF-8`|`UTF-8`|`UTF-16LE`|  
|`UTF-16LE`|`UTF-16LE`|`UTF-8`|`UTF-16LE`|  
  
 Arquivos abertos para gravação no modo Unicode têm uma BOM gravada neles automaticamente.  
  
 Se `mode` é ", ccs =*codificação*", `fopen_s` primeiro tenta abrir o arquivo com acesso de leitura e acesso de gravação. Se isso for bem-sucedido, a função lê a BOM para determinar a codificação para o arquivo; se não for bem-sucedido, a função usa a codificação padrão para o arquivo. Em todo caso, `fopen_s` reabrirá o arquivo com acesso somente gravação. (Isso se aplica ao modo `a` apenas, não a `a+`.)  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tfopen_s`|`fopen_s`|`fopen_s`|`_wfopen_s`|  
  
 A cadeia de caracteres `mode` especifica o tipo de acesso solicitado para o arquivo, da seguinte forma.  
  
 `"r"`  
 Abre para leitura. Se o arquivo não existir ou não puder ser encontrado, a chamada `fopen_s` falha.  
  
 `"w"`  
 Abre um arquivo vazio para gravação. Se o arquivo existir, seus conteúdos são destruídos.  
  
 `"a"`  
 Abre para gravação no fim do arquivo (acréscimo) sem remover o marcador de EOF antes de gravar novos dados no arquivo. Cria o arquivo se ele não existir.  
  
 `"r+"`  
 Abre para leitura e gravação. (O arquivo deve existir.)  
  
 `"w+"`  
 Abre um arquivo vazio para leitura e gravação. Se o arquivo existir, seus conteúdos são destruídos.  
  
 `"a+"`  
 Abre para leitura e conexão. A operação de acréscimo inclui a remoção do marcador de EOF antes que novos dados sejam gravados no arquivo e o marcador de EOF seja restaurado após a gravação ser concluída. Cria o arquivo se ele não existir.  
  
 Quando um arquivo é aberto usando o tipo de acesso `"a"` ou `"a+"`, todas as operações de gravação ocorrem no fim do arquivo. O ponteiro do arquivo pode ser reposicionado usando `fseek` ou `rewind`, mas é sempre movido de volta para o fim do arquivo antes de qualquer operação de gravação seja realizada, de modo que os dados existentes não possam ser substituídos.  
  
 O modo `"a"` não remove o marcador de EOF antes de ser acrescentado ao arquivo. Após o acréscimo ter ocorrido, o comando MS-DOS TYPE mostra dados somente até o marcador de EOF original e não qualquer dado acrescentado ao arquivo. O modo `"a+"` remove o marcador de EOF antes de ser acrescentado ao arquivo. Depois de anexar, o comando MS-DOS TYPE mostra todos os dados no arquivo. O modo `"a+"` é exigido para o acréscimo a um arquivo de fluxo terminado com o marcador de EOF CTRL+Z.  
  
 Quando o `"r+"`, `"w+",` ou `"a+"` tipo de acesso for especificado, leitura e gravação são permitidas. (Diz-se que o arquivo está aberto para "atualização".) Porém, ao trocar de leitura para gravação, a operação de entrada deve encontrar um marcador de EOF. Se não houver EOF, você deverá usar uma chamada intermediária para uma função de posicionamento de arquivo. As funções do posicionamento de arquivo são `fsetpos`, `fseek` e `rewind`. Ao trocar de gravação para leitura, você precisa usar uma chamada intermediária para `fflush` ou uma função de posicionamento de arquivo.  
  
 Além dos valores anteriores, os seguintes caracteres podem ser incluídos em `mode` para especificar o modo de conversão dos caracteres newline:  
  
 `t`  
 Abra no modo de texto (convertido). Neste modo, CTRL+Z é interpretado como um caractere de fim do arquivo na entrada. Em arquivos abertos para leitura/gravação com `"a+"`, `fopen_s` verifica se há um CTRL+Z no fim do arquivo e o remove, se possível. Isso é feito porque usar `fseek` e `ftell` para movimentação dentro de um arquivo que termina com CTRL+Z pode fazer o `fseek` se comportar incorretamente perto do fim do arquivo.  
  
 Além disso, no modo de texto, combinações de avanço de linha de retorno de carro são convertidas em alimentações de linha únicas na entrada e caracteres de alimentação de linha são convertidos para combinações de avanço de linha de retorno de carro na saída. Quando uma função de E/S de fluxo Unicode opera no modo de texto (o padrão), presume-se que o fluxo de origem ou destino é uma sequência de caracteres multibyte. Portanto, as funções de entrada de fluxo do Unicode convertem caracteres multibyte para caracteres largos (como por uma chamada à função `mbtowc`). Pelo mesmo motivo, as funções de saída de fluxo do Unicode convertem caracteres largos para caracteres multibyte (como por uma chamada à função `wctomb`).  
  
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
 Especifique o conjunto de caracteres codificado para usar (UTF-8, UTF-16LE e UNICODE) para esse arquivo. Deixe-o não especificado se desejar codificação ANSI.  
  
 Caracteres válidos para a cadeia de caracteres `mode` usada em `fopen_s` e `_fdopen` correspondem a argumentos `oflag` usados em [_open](../../c-runtime-library/reference/open-wopen.md) e [_sopen](../../c-runtime-library/reference/sopen-wsopen.md), como segue.  
  
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
  
 Se você estiver usando o modo `rb`, não for precisar portar seu código e for ler grande parte do arquivo e/ou não se preocupar com o desempenho da rede, arquivos Win32 mapeados na memória também poderão ser uma opção.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`fopen_s`|\<stdio.h>|  
|`_wfopen_s`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
 As opções `c`, `n` e `t` `mode` são extensões da Microsoft para `fopen_s` e `_fdopen` e não devem ser usadas quando se desejar portabilidade ANSI.  
  
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
 [E/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fclose, _fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [_fdopen, _wfdopen](../../c-runtime-library/reference/fdopen-wfdopen.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [_fileno](../../c-runtime-library/reference/fileno.md)   
 [freopen, _wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)   
 [_setmode](../../c-runtime-library/reference/setmode.md)