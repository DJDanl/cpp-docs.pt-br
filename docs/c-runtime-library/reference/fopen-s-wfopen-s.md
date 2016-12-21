---
title: "fopen_s, _wfopen_s | Microsoft Docs"
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
  - "_wfopen_s"
  - "fopen_s"
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
  - "fopen_s"
  - "_tfopen_s"
  - "_wfopen_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tfopen_s"
  - "Função _wfopen_s"
  - "Arquivos  [C++], abertura"
  - "Função fopen_s"
  - "abrindo arquivos, para E/S de arquivo"
  - "Função tfopen_s"
  - "Unicode [C++], criando arquivos"
  - "Unicode [C++], Arquivos "
  - "Unicode [C++], gravando arquivos"
  - "Função wfopen_s"
ms.assetid: c534857e-39ee-4a3f-bd26-dfe551ac96c3
caps.latest.revision: 41
caps.handback.revision: 39
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fopen_s, _wfopen_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Abre um arquivo.  Essas versões do [fopen, wfopen](../../c-runtime-library/reference/fopen-wfopen.md) tem aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 \[out\] `pFile`  
 Um ponteiro para o ponteiro do arquivo que receberá o ponteiro para o arquivo aberto.  
  
 \[in\] `filename`  
 Nome do arquivo.  
  
 \[in\] `mode`  
 Tipo de acesso permitido.  
  
## Valor de retorno  
 Zero se tiver êxito; um código de erro em caso de falha.  Consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) para obter mais informações sobre esses códigos de erro.  
  
### Condições de erro  
  
|`pFile`|`filename`|`mode`|Valor de Retorno|Conteúdo do`pFile`|  
|-------------|----------------|------------|----------------------|------------------------|  
|`NULL`|qualquer|qualquer|`EINVAL`|inalterado|  
|qualquer|`NULL`|qualquer|`EINVAL`|inalterado|  
|qualquer|qualquer|NULL|`EINVAL`|inalterado|  
  
## Comentários  
 Os arquivos abertos por `fopen_s` e `_wfopen_s` não são compartilhável.  Se você precisar que um arquivo seja compartilhável, use [\_fsopen, \_wfsopen](../../c-runtime-library/reference/fsopen-wfsopen.md) com a constante de modo de compartilhamento apropriado — por exemplo, `_SH_DENYNO` para compartilhamento de leitura\/gravação.  
  
 O `fopen_s` função abre o arquivo especificado por `filename`.  `_wfopen_s` é uma versão de caractere largo de `fopen_s`; os argumentos para `_wfopen_s` são cadeias de caracteres largas.  Caso contrário, `_wfopen_s` e `fopen_s` se comportam de forma idêntica.  
  
 `fopen_s` aceita caminhos válidos no sistema de arquivos no ponto de execução; Caminhos UNC e caminhos que envolvem unidades de rede mapeadas são aceitos pelo `fopen_s` desde que o sistema que está executando o código tem acesso ao compartilhamento ou unidade de rede mapeada no momento da execução.  Quando você constrói caminhos para `fopen_s`, não faça suposições sobre a disponibilidade de unidades, caminhos ou compartilhamentos de rede no ambiente de execução.  É possível usar barras \(\/\) ou contrabarras \(\\\) como separadores de diretório em um caminho.  
  
 Essas funções validam seus parâmetros.  Se `pFile`, `filename`, ou `mode` é um ponteiro nulo, essas funções para gerar uma exceção de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Sempre verifique o valor de retorno para ver se a função foi bem\-sucedida antes de executar qualquer outra operação no arquivo.  Se ocorrer um erro, o código de erro será retornado e a variável global `errno` está definido.  Para obter mais informações, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Suporte a Unicode  
 O `fopen_s` oferece suporte a fluxos de arquivo Unicode.  Para abrir um arquivo novo ou existente do Unicode, passe um `ccs` Sinalizador que especifica a codificação desejada para `fopen_s`:  
  
 `fopen_s(&fp, "newfile.txt", "rw,`   `ccs=`  `encoding` `");`  
  
 Os valores possíveis de `encoding` são `UNICODE`, `UTF-8` e `UTF-16LE`.  Se há nenhum valor for especificado para `encoding`, `fopen_s` usa a codificação ANSI.  
  
 Se o arquivo já existe e está aberto para ler ou anexar, o Byte de ordem BOM \(marca\), se estiver presente no arquivo, determina a codificação.  A codificação BOM tem precedência sobre a codificação especificada pelo `ccs` sinalizador.  O `ccs` codificação é usado somente quando nenhuma BOM estiver presente ou se o arquivo é um novo arquivo.  
  
> [!NOTE]
>  Detecção de BOM só se aplica a arquivos que são abertos no modo Unicode; ou seja, enviando o `ccs` sinalizador.  
  
 A tabela a seguir resume os modos para vários `ccs` sinalizadores que recebem a `fopen_s` e marcas de ordem de Byte no arquivo.  
  
### Codificações usadas com base em Sinalizador ccs e BOM  
  
|Sinalizador `ccs`|Nenhuma BOM \(ou novo arquivo\)|BOM: UTF\-8|BOM: UTF\-16|  
|-----------------------|-------------------------------------|-----------------|------------------|  
|`UNICODE`|`UTF-16LE`|`UTF-8`|`UTF-16LE`|  
|`UTF-8`|`UTF-8`|`UTF-8`|`UTF-16LE`|  
|`UTF-16LE`|`UTF-16LE`|`UTF-8`|`UTF-16LE`|  
  
 Os arquivos abertos para gravação no modo Unicode têm uma BOM gravada neles automaticamente.  
  
 Se `mode` é "`a, ccs=<encoding>`", `fopen_s` primeiro tenta abrir o arquivo com acesso de leitura e acesso de gravação.  Se for bem\-sucedido, a função lê a BOM para determinar a codificação do arquivo; Se não for bem\-sucedida, a função usa a codificação padrão para o arquivo.  Em ambos os casos, `fopen_s` reabre o arquivo com acesso somente gravação.  \(Isso se aplica a `a` modo, não `a+`.\)  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tfopen_s`|`fopen_s`|`fopen_s`|`_wfopen_s`|  
  
 A cadeia de caracteres `mode` Especifica o tipo de acesso solicitado para o arquivo, da seguinte maneira.  
  
 `"r"`  
 Abre para leitura.  Se o arquivo não existir ou não puder ser encontrado, a chamada `fopen_s` falha.  
  
 `"w"`  
 Abre um arquivo vazio para gravação.  Se o arquivo existir, seus conteúdos são destruídos.  
  
 `"a"`  
 Abre para gravação no final do arquivo \(conexão\) sem remover o marcador de EOF antes de gravar novos dados para o arquivo.  Cria o arquivo se ele não existir.  
  
 `"r+"`  
 Abre para leitura e gravação.  \(O arquivo deve existir\).  
  
 `"w+"`  
 Abre um arquivo vazio para leitura e gravação.  Se o arquivo existir, seus conteúdos são destruídos.  
  
 `"a+"`  
 Abre para leitura e conexão.  A operação de conexão inclui a remoção do marcador de EOF antes que novos dados são gravados no arquivo e o marcador de EOF é restaurado após a conclusão da gravação.  Cria o arquivo se ele não existir.  
  
 Quando um arquivo é aberto usando o `"a"` ou `"a+"` acessar tipo, todas as operações de gravação ocorrem no final do arquivo.  O ponteiro do arquivo pode ser reposicionado usando `fseek` ou `rewind`, mas ele é sempre movido para o final do arquivo antes de qualquer gravação a operação é executada para que os dados existentes não podem ser substituídos.  
  
 O `"a"` não remove o marcador de EOF antes de anexar ao arquivo.  Após a conexão ter ocorrido, o comando MS\-DOS TYPE só mostra dados até o marcador de EOF original e não os dados que são acrescentados ao arquivo.  O `"a+"` modo remover o marcador de EOF antes de anexar ao arquivo.  Depois de anexar, o comando MS\-DOS TYPE mostra todos os dados no arquivo.  O `"a+"` modo é exigido para conexão com um arquivo de fluxo é encerrado usando o marcador de EOF CTRL \+ Z.  
  
 Quando o `"r+",` `"w+",` ou `"a+"` tipo de acesso for especificado, leitura e gravação são permitidas.  \(O arquivo deve estar aberto para "atualização".\) Porém, ao trocar de leitura para gravação, a operação de entrada deve encontrar um marcador de EOF.  Se não houver EOF, você deve usar uma chamada intermediária para uma função de posicionamento de arquivos.  As funções de posicionamento de arquivo são `fsetpos`, `fseek`, e `rewind`.  Quando você alternar de gravação para leitura, você deve usar uma chamada intermediária para `fflush` ou a uma função de posicionamento de arquivos.  
  
 Além dos valores acima, os seguintes caracteres podem ser incluídos em `mode` para especificar o modo de conversão de caracteres de nova linha:  
  
 `t`  
 Abra no modo de texto \(convertido\).  Nesse modo, CTRL \+ Z é interpretado como um caractere de final de arquivo na entrada.  Em arquivos abertos para leitura\/gravação com `"a+"`, `fopen_s` verifica se há um CTRL \+ Z no final do arquivo e remove, se possível.  Isso é feito porque usando `fseek` e `ftell` para movimentação dentro de um arquivo que termine com CTRL \+ Z, podem causar `fseek` se comportar incorretamente perto do fim do arquivo.  
  
 Além disso, no modo de texto, combinações de avanço de linha – retorno de carro são convertidas em avanços de linha simples na entrada e caracteres de avanço de linha são convertidos para combinações de avanço de linha – retorno de carro na saída.  Quando uma função de E\/S de fluxo Unicode opera no modo de texto \(o padrão\), presume\-se que o fluxo de origem ou destino é uma sequência de caracteres multibyte.  Portanto, as funções de entrada de fluxo do Unicode convertem caracteres multibyte para caracteres largos \(como por uma chamada à função `mbtowc`\).  Pelo mesmo motivo, as funções de saída de fluxo do Unicode convertem caracteres largos para caracteres multibyte \(como por uma chamada à função `wctomb`\).  
  
 `b`  
 Abra em um modo binário \(não convertido\); as conversões envolvendo caracteres de retorno de carro e avanço de linha são suprimidas.  
  
 Se `t` ou `b` não for informado no `mode`, o modo de tradução padrão é definido pela variável global [\_fmode](../../c-runtime-library/fmode.md).  Se `t` ou `b` for prefixado para o argumento, a função falha e retorna `NULL`.  
  
 Para obter mais informações sobre como usar modos de texto e binários em Unicode e multibyte fluxo de e\/S, consulte [texto e binário e\/s de arquivo de modo](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [e\/s de fluxo de Unicode em modos de texto e binário](../../c-runtime-library/unicode-stream-i-o-in-text-and-binary-modes.md).  
  
 `c`  
 Habilite o sinalizador de confirmação para o `filename` associado de modo que os conteúdos do buffer de arquivo sejam gravados diretamente no disco, se `fflush` ou `_flushall` for chamado.  
  
 `n`  
 Redefina o sinalizador de confirmação para o `filename` associado a "no\-commit." Esse é o padrão.  Também substitui o sinalizador de confirmação global se você vincular o programa a COMMODE.OBJ.  O padrão de sinalizador de confirmação global é "no\-commit", a menos que você explicitamente vincula o programa a COMMODE. OBJ \(consulte [Opções de link](../Topic/Link%20Options.md)\).  
  
 `N`  
 Especifica que o arquivo não é herdado por processos filhos.  
  
 `S`  
 Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso.  
  
 `R`  
 Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso.  
  
 `T`  
 Especifica um arquivo como temporário.  Se possível, ele não é liberado no disco.  
  
 `D`  
 Especifica um arquivo como temporário.  É excluído quando o último ponteiro de arquivo é fechado.  
  
 `ccs=ENCODING`  
 Especifique o caractere codificado definido para usar \(UTF\-8, UTF\-16LE e UNICODE\) para esse arquivo.  Deixe isso não especificado se desejar codificação ANSI.  
  
 Os caracteres válidos para o `mode` cadeia de caracteres usada na `fopen_s` e `_fdopen` correspondem a `oflag` argumentos usados na [Open](../../c-runtime-library/reference/open-wopen.md) e [sopen](../../c-runtime-library/reference/sopen-wsopen.md), da seguinte maneira.  
  
|Caracteres na cadeia de caracteres de modo|Valor de `oflag` equivalente a `_open`\/`_sopen`|  
|------------------------------------------------|------------------------------------------------------|  
|`a`|`_O_WRONLY &#124; _O_APPEND` \(geralmente `_O_WRONLY &#124; _O_CREAT &#124;``_O_APPEND`\)|  
|`a+`|`_O_RDWR &#124; _O_APPEND` \(geralmente `_O_RDWR &#124; _O_APPEND &#124; _O_CREAT` \)|  
|`r`|`_O_RDONLY`|  
|`r+`|`_O_RDWR`|  
|`w`|`_O_WRONLY` \(geralmente `_O_WRONLY &#124;``_O_CREAT &#124; _O_TRUNC`\)|  
|`w+`|`_O_RDWR`\(geralmente `_O_RDWR &#124; _O_CREAT &#124; _O_TRUNC`\)|  
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
  
 Se você estiver usando `rb` modo, não precisará portar seu código e esperar ler o arquivo muitas e\/ou não se preocupa com o desempenho da rede, arquivos Win32 de memória mapeada também podem ser uma opção.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`fopen_s`|\<stdio.h\>|  
|`_wfopen_s`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões de [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
 O `c`, `n`, e `t` `mode` Opções são extensões da Microsoft para `fopen_s` e `_fdopen` e não deve ser usada onde se desejar portabilidade ANSI.  
  
## Exemplo  
  
```  
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
  
  **O arquivo 'crt\_fopen\_s.c' foi aberto**  
**O arquivo 'data2' foi aberto**  
**Número de arquivos fechados por \_fcloseall: 1**   
## Equivalência do .NET Framework  
  
-   [System::IO::file::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx)  
  
-   <xref:System.IO.FileStream.%23ctor%2A>  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fclose, \_fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [\_fdopen, \_wfdopen](../Topic/_fdopen,%20_wfdopen.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [\_fileno](../Topic/_fileno.md)   
 [freopen, \_wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [\_setmode](../../c-runtime-library/reference/setmode.md)