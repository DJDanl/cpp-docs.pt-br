---
title: "freopen, _wfreopen | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "freopen"
  - "_wfreopen"
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
  - "_wfreopen"
  - "_tfreopen"
  - "freopen"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tfreopen"
  - "Função _wfreopen"
  - "ponteiros de arquivo [C++], reatribuindo"
  - "Função freopen"
  - "Função tfreopen"
  - "Função wfreopen"
ms.assetid: de4b73f8-1043-4d62-98ee-30d2022da885
caps.latest.revision: 27
caps.handback.revision: 25
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# freopen, _wfreopen
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Reatribui um ponteiro de arquivo.  Versões mais seguras dessas funções estão disponíveis; consulte [freopen\_s, \_wfreopen\_s](../../c-runtime-library/reference/freopen-s-wfreopen-s.md).  
  
## Sintaxe  
  
```  
FILE *freopen(   
   const char *path,  
   const char *mode,  
   FILE *stream   
);  
FILE *_wfreopen(   
   const wchar_t *path,  
   const wchar_t *mode,  
   FILE *stream   
);  
```  
  
#### Parâmetros  
 `path`  
 Caminho do novo arquivo.  
  
 `mode`  
 Tipo de acesso permitido.  
  
 `stream`  
 Ponteiro para a estrutura `FILE`.  
  
## Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para o arquivo aberto recentemente.  Se ocorrer um erro, o arquivo original é fechado e a função retorna um `NULL` valor do ponteiro.  Se `path`, `mode`, ou `stream` é um ponteiro nulo, ou se `filename` é uma seqüência vazia, essas funções para invocar o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` para `EINVAL` e retornar `NULL`.  
  
 Consulte [doserrno, errno, sys\_errlist e sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) para obter mais informações sobre esses e outros códigos de erro.  
  
## Comentários  
 Versões mais seguras dessas funções existe, consulte [freopen\_s, wfreopen\_s](../../c-runtime-library/reference/freopen-s-wfreopen-s.md).  
  
 O `freopen` função fecha o arquivo atualmente associado `stream` e reatribui `stream` para o arquivo especificado por `path`*.* `_wfreopen` é uma versão de caractere largo de `_freopen`; o `path` e `mode` argumentos `_wfreopen` são cadeias de caracteres largos.  Caso contrário, `_wfreopen` e `_freopen` se comportam de forma idêntica.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tfreopen`|`freopen`|`freopen`|`_wfreopen`|  
  
 `freopen` normalmente é usado para redirecionar os arquivos abertos previamente `stdin`, `stdout`, e `stderr` para os arquivos especificados pelo usuário.  O novo arquivo associado `stream` é aberto com `mode`*,* que é uma cadeia de caracteres que especifica o tipo de acesso solicitado para o arquivo, da seguinte maneira:  
  
 `"r"`  
 Abre para leitura.  Se o arquivo não existir ou não puder ser encontrado, a chamada `freopen` falha.  
  
 `"w"`  
 Abre um arquivo vazio para gravação.  Se o arquivo determinado existir, seus conteúdos são destruídos.  
  
 `"a"`  
 Abre para gravação no final do arquivo \(conexão\) sem remover o marcador de EOF antes de gravar novos dados para o arquivo; cria o arquivo primeiro se ele não existir.  
  
 `"r+"`  
 Abre para leitura e gravação.  \(O arquivo deve existir\).  
  
 `"w+"`  
 Abre um arquivo vazio para leitura e gravação.  Se o arquivo determinado existir, seus conteúdos são destruídos.  
  
 `"a+"`  
 Abre para leitura e conexão; a operação de conexão inclui a remoção do marcador de EOF antes que novos dados são gravados no arquivo e o marcador de EOF é restaurado após a gravação ser concluída; cria o arquivo primeiro se ele não existir.  
  
 Use o `"w"` e `"w+"` tipos com cuidado, como eles podem destruir os arquivos existentes.  
  
 Quando um arquivo é aberto com a `"a"` ou `"a+"` acessar o tipo, todas as operações ocorrem no final do arquivo de gravação.  Embora o ponteiro do arquivo pode ser reposicionado usando `fseek` ou `rewind`, o ponteiro do arquivo é sempre movido para o final do arquivo antes de qualquer gravação a operação é executada.  Assim, os dados existentes não podem ser substituídos.  
  
 O `"a"` não remove o marcador de EOF antes de anexar ao arquivo.  Depois de a conexão ter ocorrido, o comando MS\-DOS TYPE só mostra dados até o marcador de EOF original, e não qualquer dado anexado ao arquivo.  O `"a+"` modo remover o marcador de EOF antes de anexar ao arquivo.  Depois de anexar, o comando MS\-DOS TYPE mostra todos os dados no arquivo.  O modo `"a+"` é exigido para conexão com um arquivo de fluxo terminado com o marcador de EOF CTRL\+Z.  
  
 Quando o tipo de acesso `"r+"`, `"w+"` ou `"a+"` é especificado, são permitidas leitura e gravação \(diz\-se que o arquivo está aberto para "atualização"\).  No entanto, quando você alternar entre a leitura e gravação, deve haver uma intervenção [fsetpos](../Topic/fsetpos.md), [fseek](../../c-runtime-library/reference/fseek-fseeki64.md), ou [Retroceder](../../c-runtime-library/reference/rewind.md) operação.  A posição atual pode ser especificada para o `fsetpos` ou `fseek` operação, se desejado.  Além dos valores acima, um dos seguintes caracteres pode ser incluído na `mode` cadeia de caracteres para especificar o modo de tradução para novas linhas.  
  
 `t`  
 Abrir em texto \(convertido\) modo; combinações de retorno – avanço de linha \(CR\-LF\) de carro são convertidas em caracteres de avanço de linha \(LF\) único na entrada; LF caracteres são convertidos para combinações CR\-LF na saída.  Além disso, CTRL \+ Z é interpretado como um caractere de final de arquivo na entrada.  Em arquivos abertos para leitura ou para gravação e leitura com `"a+"`, a biblioteca de tempo de execução procura um CTRL \+ Z no final do arquivo e remove, se possível.  Isso é feito porque usando `fseek` e `ftell` para movimentação dentro de um arquivo pode causar `fseek` se comportar incorretamente perto do fim do arquivo.  O `t` opção é uma extensão da Microsoft que não deve ser usada onde se desejar portabilidade ANSI.  
  
 `b`  
 Abra o modo binário \(não convertido\); as traduções acima são suprimidas.  
  
 Se `t` ou `b` não for informado no `mode`, o modo de tradução padrão é definido pela variável global [\_fmode](../../c-runtime-library/fmode.md).  Se `t` ou `b` for prefixado para o argumento, a função falha e retorna `NULL`.  
  
 Para uma discussão sobre modos de texto e binários, consulte [texto e binário e\/s de arquivo de modo](../../c-runtime-library/text-and-binary-mode-file-i-o.md).  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`freopen`|\<stdio.h\>|  
|`_wfreopen`|\<stdio.h\> ou \<wchar.h\>|  
  
 Não há suporte para o console em [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos.  Os identificadores de fluxo padrão que estão associados com o console —`stdin`, `stdout`, e `stderr`— deverá ser redirecionado para funções de tempo de execução C podem usá\-los em [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos.  Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_freopen.c  
// compile with: /W3  
// This program reassigns stderr to the file  
// named FREOPEN.OUT and writes a line to that file.  
#include <stdio.h>  
#include <stdlib.h>  
  
FILE *stream;  
  
int main( void )  
{  
   // Reassign "stderr" to "freopen.out":   
   stream = freopen( "freopen.out", "w", stderr ); // C4996  
   // Note: freopen is deprecated; consider using freopen_s instead  
  
   if( stream == NULL )  
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
  
  **reatribuídos com êxito**  
**Isso irá para o arquivo 'freopen.out'**   
## Equivalência do .NET Framework  
  
-   <xref:System.IO.File.Open%2A>  
  
-   <xref:System.IO.FileStream.%23ctor%2A>  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fclose, \_fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [\_fdopen, \_wfdopen](../Topic/_fdopen,%20_wfdopen.md)   
 [\_fileno](../Topic/_fileno.md)   
 [fopen, \_wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [\_setmode](../../c-runtime-library/reference/setmode.md)