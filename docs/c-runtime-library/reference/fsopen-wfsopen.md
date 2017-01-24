---
title: "_fsopen, _wfsopen | Microsoft Docs"
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
  - "_wfsopen"
  - "_fsopen"
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
  - "wfsopen"
  - "fsopen"
  - "tfsopen"
  - "_tfsopen"
  - "_wfsopen"
  - "_fsopen"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fsopen"
  - "Função _tfsopen"
  - "Função _wfsopen"
  - "compartilhamento de arquivos [C++]"
  - "Arquivos  [C++], abertura"
  - "Função fsopen"
  - "abrindo arquivos, fluxos"
  - "Função tfsopen"
  - "Função wfsopen"
ms.assetid: 5e4502ab-48a9-4bee-a263-ebac8d638dec
caps.latest.revision: 20
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _fsopen, _wfsopen
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Abre um fluxo com o compartilhamento de arquivos.  
  
## Sintaxe  
  
```  
FILE *_fsopen(   
   const char *filename,  
   const char *mode,  
   int shflag   
);  
FILE *_wfsopen(   
   const wchar_t *filename,  
   const wchar_t *mode,  
   int shflag   
);  
```  
  
#### Parâmetros  
 `filename`  
 Nome do arquivo a ser aberto.  
  
 `mode`  
 Tipo de acesso permitido.  
  
 `shflag`  
 Tipo de compartilhamento permitido.  
  
## Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para o fluxo.  Um valor de ponteiro nulo indica um erro.  Se `filename` ou `mode` é `NULL` ou uma cadeia de caracteres vazia, essas funções invocar o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `NULL` e definirão `errno` para `EINVAL`.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [doserrno, errno, sys\_errlist e sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 O `_fsopen` função abre o arquivo especificado por `filename` como um fluxo e prepara o arquivo para subsequente leitura ou gravação compartilhada, conforme definido pelo modo e `shflag` argumentos.  `_wfsopen` é uma versão de caractere largo de `_fsopen`; o `filename` e `mode` argumentos `_wfsopen` são cadeias de caracteres largos.  Caso contrário, `_wfsopen` e `_fsopen` se comportam de forma idêntica.  
  
 A cadeia de caracteres `mode` Especifica o tipo de acesso solicitado para o arquivo, como mostrado na tabela a seguir.  
  
|Termo|Definição|  
|-----------|---------------|  
|`"r"`|Abre para leitura.  Se o arquivo não existir ou não puder ser encontrado, a chamada `_fsopen` falha.|  
|`"w"`|Abre um arquivo vazio para gravação.  Se o arquivo determinado existir, seus conteúdos são destruídos.|  
|`"a"`|Abre para gravação no final do arquivo \(conexão\); cria o arquivo primeiro se ele não existir.|  
|`"r+"`|Abre para leitura e gravação.  \(O arquivo deve existir\).|  
|`"w+"`|Abre um arquivo vazio para leitura e gravação.  Se o arquivo determinado existir, seus conteúdos são destruídos.|  
|`"a+"`|Abre para leitura e conexão; cria o arquivo primeiro se ele não existir.|  
  
 Use o `"w"` e `"w+"` tipos com cuidado, como eles podem destruir os arquivos existentes.  
  
 Quando um arquivo é aberto com a `"a"` ou `"a+"` acessar tipo, todas as operações de gravação ocorrem no final do arquivo.  O ponteiro do arquivo pode ser reposicionado usando `fseek` ou `rewind`, mas ele é sempre movido para o final do arquivo antes de qualquer gravação a operação é executada.  Assim, os dados existentes não podem ser substituídos.  Quando o `"r+"`, `"w+"`, ou `"a+"` tipo de acesso for especificado, leitura e gravação são permitidas \(o arquivo deve estar aberto para atualização\).  No entanto, ao alternar entre a leitura e gravação, deve haver uma intervenção [fsetpos](../Topic/fsetpos.md), [fseek](../../c-runtime-library/reference/fseek-fseeki64.md), ou [Retroceder](../../c-runtime-library/reference/rewind.md) operação.  A posição atual pode ser especificada para o `fsetpos` ou `fseek` operação, se desejado.  Além dos valores acima, um dos seguintes caracteres pode ser incluído em `mode` para especificar o modo de tradução para novas linhas e para gerenciamento de arquivos.  
  
|Termo|Definição|  
|-----------|---------------|  
|`t`|Abre um arquivo no modo de texto \(convertido\).  Nesse modo, combinações de feed \(CR\-LF\) carro de retorno – linha são convertidas em feeds de única linha \(LF\) na entrada e LF caracteres são convertidos para combinações CR\-LF na saída.  Além disso, CTRL \+ Z é interpretado como um caractere de final de arquivo na entrada.  Em arquivos abertos para leitura ou leitura\/gravação, `_fsopen` verifica se há um CTRL \+ Z no final do arquivo e remove, se possível.  Isso é feito porque usando `fseek` e `ftell` para movimentação dentro de um arquivo que termina com um CTRL \+ Z pode causar `fseek` se comportar incorretamente perto do fim do arquivo.|  
|`b`|Abre um arquivo no modo binário de \(não convertido\); as traduções acima são suprimidas.|  
|`S`|Especifica que o cache é otimizado para acesso sequencial do disco, mas não se restringe a isso.|  
|`R`|Especifica que o cache é otimizado para acesso aleatório do disco, mas não se restringe a isso.|  
|`T`|Especifica um arquivo como temporário.  Se possível, ele não é liberado no disco.|  
|`D`|Especifica um arquivo como temporário.  É excluído quando o último ponteiro de arquivo é fechado.|  
  
 Se `t` ou `b` não for fornecido em `mode`, o modo de tradução é definido pela variável de modo padrão `_fmode`.  Se `t` ou `b` for prefixado para o argumento, a função falha e retorna `NULL`.  Para uma discussão sobre modos de texto e binários, consulte [texto e binário e\/s de arquivo de modo](../../c-runtime-library/text-and-binary-mode-file-i-o.md).  
  
 O argumento `shflag` é uma expressão constante formada por uma das seguintes constantes de manifesto, definidas em Share.  
  
|Termo|Definição|  
|-----------|---------------|  
|`_SH_COMPAT`|Define o modo de compatibilidade para aplicativos de 16 bits.|  
|`_SH_DENYNO`|Permite acesso de leitura e gravação.|  
|`_SH_DENYRD`|Nega o acesso de leitura ao arquivo.|  
|`_SH_DENYRW`|Nega o acesso de leitura e gravação para o arquivo.|  
|`_SH_DENYWR`|Nega acesso de gravação ao arquivo.|  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tfsopen`|`_fsopen`|`_fsopen`|`_wfsopen`|  
  
## Requisitos  
  
|Função|Cabeçalho necessário|Cabeçalhos opcionais|  
|------------|--------------------------|--------------------------|  
|`_fsopen`|\<stdio.h\>|\< Share \><br /><br /> Constante de manifesto para `shflag` parâmetro.|  
|`_wfsopen`|\<stdio.h\> ou \<wchar.h\>|\< Share \><br /><br /> Constante de manifesto para `shflag` parâmetro.|  
  
## Exemplo  
  
```  
// crt_fsopen.c  
  
#include <stdio.h>  
#include <stdlib.h>  
#include <share.h>  
  
int main( void )  
{  
   FILE *stream;  
  
   // Open output file for writing. Using _fsopen allows us to  
   // ensure that no one else writes to the file while we are  
   // writing to it.  
    //  
   if( (stream = _fsopen( "outfile", "wt", _SH_DENYWR )) != NULL )  
   {  
      fprintf( stream, "No one else in the network can write "  
                       "to this file until we are done.\n" );  
      fclose( stream );  
   }  
   // Now others can write to the file while we read it.  
   system( "type outfile" );  
}  
```  
  
  **Ninguém na rede pode gravar esse arquivo até a conclusão.**   
## Equivalência do .NET Framework  
  
-   [System::IO::file::Open](https://msdn.microsoft.com/en-us/library/system.io.file.open.aspx)  
  
-   <xref:System.IO.FileStream.%23ctor%2A>  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fclose, \_fcloseall](../../c-runtime-library/reference/fclose-fcloseall.md)   
 [\_fdopen, \_wfdopen](../Topic/_fdopen,%20_wfdopen.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [\_fileno](../Topic/_fileno.md)   
 [fopen, \_wfopen](../../c-runtime-library/reference/fopen-wfopen.md)   
 [freopen, \_wfreopen](../../c-runtime-library/reference/freopen-wfreopen.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [\_setmode](../../c-runtime-library/reference/setmode.md)   
 [\_sopen, \_wsopen](../../c-runtime-library/reference/sopen-wsopen.md)