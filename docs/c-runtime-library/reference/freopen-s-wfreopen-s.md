---
title: "freopen_s, _wfreopen_s | Microsoft Docs"
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
  - "_wfreopen_s"
  - "freopen_s"
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
  - "freopen_s"
  - "_tfreopen_s"
  - "_wfreopen_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tfreopen_s"
  - "Função _wfreopen_s"
  - "ponteiros de arquivo [C++], reatribuindo"
  - "Função freopen_s"
  - "Função tfreopen_s"
  - "Função wfreopen_s"
ms.assetid: ad25a4da-6ad4-476b-a86d-660b221ca84d
caps.latest.revision: 27
caps.handback.revision: 25
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# freopen_s, _wfreopen_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Reatribui um ponteiro de arquivo.  Essas versões do [freopen, wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md) tem aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t freopen(   
   FILE** pFile,  
   const char *path,  
   const char *mode,  
   FILE *stream   
);  
errno_t _wfreopen(   
   FILE** pFile,  
   const wchar_t *path,  
   const wchar_t *mode,  
   FILE *stream   
);  
```  
  
#### Parâmetros  
 \[out\] `pFile`  
 Um ponteiro para o ponteiro do arquivo a ser fornecido pela chamada.  
  
 \[in\] `path`  
 Caminho do novo arquivo.  
  
 \[in\] `mode`  
 Tipo de acesso permitido.  
  
 \[in\] `stream`  
 Ponteiro para a estrutura `FILE`.  
  
## Valor de retorno  
 Cada uma dessas funções retorna um código de erro.  Se ocorrer um erro, o arquivo original é fechado.  
  
## Comentários  
 O `freopen_s` função fecha o arquivo atualmente associado `stream` e reatribui `stream` para o arquivo especificado por `path.` `_wfreopen_s` é uma versão de caractere largo de `_freopen_s`; o `path` e `mode` argumentos `_wfreopen_s` são cadeias de caracteres largos.  Caso contrário, `_wfreopen_s` e `_freopen_s` se comportam de forma idêntica.  
  
 Se qualquer um dos `pFile`, `path`, `mode`, ou `stream` são `NULL`, ou se `path` é uma seqüência vazia, essas funções para invocar o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` para `EINVAL` e retornar `EINVAL`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tfreopen_s`|`freopen_s`|`freopen_s`|`_wfreopen_s`|  
  
 `freopen_s` normalmente é usado para redirecionar os arquivos abertos previamente `stdin`, `stdout`, e `stderr` para os arquivos especificados pelo usuário.  O novo arquivo associado `stream` é aberto com `mode`*,* que é uma cadeia de caracteres que especifica o tipo de acesso solicitado para o arquivo, da seguinte maneira:  
  
 `"r"`  
 Abre para leitura.  Se o arquivo não existir ou não puder ser encontrado, a chamada `freopen_s` falha.  
  
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
  
 Quando o `"r+",` `"w+",` ou `"a+"` tipo de acesso for especificado, leitura e gravação são permitidas \(o arquivo deve estar aberto para "atualização"\).  No entanto, quando você alternar entre a leitura e gravação, deve haver uma intervenção [fsetpos](../Topic/fsetpos.md), [fseek](../../c-runtime-library/reference/fseek-fseeki64.md), ou [Retroceder](../../c-runtime-library/reference/rewind.md) operação.  A posição atual pode ser especificada para o `fsetpos` ou `fseek` operação, se desejado.  Além dos valores acima, um dos seguintes caracteres pode ser incluído na `mode` cadeia de caracteres para especificar o modo de tradução para novas linhas.  
  
 `t`  
 Abrir em texto \(convertido\) modo; combinações de retorno – avanço de linha \(CR\-LF\) de carro são convertidas em caracteres de avanço de linha \(LF\) único na entrada; LF caracteres são convertidos para combinações CR\-LF na saída.  Além disso, CTRL \+ Z é interpretado como um caractere de final de arquivo na entrada.  Em arquivos abertos para leitura ou para gravação e leitura com `"a+"`, a biblioteca de tempo de execução procura um CTRL \+ Z no final do arquivo e remove, se possível.  Isso é feito porque usando `fseek` e `ftell` para movimentação dentro de um arquivo pode causar `fseek` se comportar incorretamente perto do fim do arquivo.  O `t` opção é uma extensão da Microsoft que não deve ser usada onde se desejar portabilidade ANSI.  
  
 `b`  
 Abra o modo binário \(não convertido\); as traduções acima são suprimidas.  
  
 Se `t` ou `b` não for informado no `mode`, o modo de tradução padrão é definido pela variável global [\_fmode](../../c-runtime-library/fmode.md).  Se `t` ou `b` for prefixado para o argumento, a função falha e retorna `NULL`.  
  
 Para uma discussão sobre modos de texto e binários, consulte [texto e binário e\/s de arquivo de modo](../../c-runtime-library/text-and-binary-mode-file-i-o.md).  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`freopen_s`|\<stdio.h\>|  
|`_wfreopen_s`|\<stdio.h\> ou \<wchar.h\>|  
  
 Não há suporte para o console em [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos.  Os identificadores de fluxo padrão que estão associados com o console —`stdin`, `stdout`, e `stderr`— deverá ser redirecionado para funções de tempo de execução C podem usá\-los em [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos.  Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_freopen_s.c  
// This program reassigns stderr to the file  
// named FREOPEN.OUT and writes a line to that file.  
  
#include <stdio.h>  
#include <stdlib.h>  
  
FILE *stream;  
  
int main( void )  
{  
   errno_t err;  
   // Reassign "stderr" to "freopen.out":   
   err = freopen_s( &stream, "freopen.out", "w", stderr );  
  
   if( err != 0 )  
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
  
-   [System::IO::file::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx)  
  
-   <xref:System.IO.FileStream.%23ctor%2A>  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [freopen, \_wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md)   
 [fclose, \_fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [\_fdopen, \_wfdopen](../Topic/_fdopen,%20_wfdopen.md)   
 [\_fileno](../Topic/_fileno.md)   
 [fopen, \_wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [\_setmode](../../c-runtime-library/reference/setmode.md)