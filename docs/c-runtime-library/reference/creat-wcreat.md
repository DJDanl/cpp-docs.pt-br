---
title: "_creat, _wcreat | Microsoft Docs"
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
  - "_creat"
  - "_wcreat"
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
  - "wcreat"
  - "_wcreat"
  - "_creat"
  - "tcreat"
  - "_tcreat"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função wcreat"
  - "Função _wcreat"
  - "arquivos [C++], criando"
  - "Função _creat"
  - "Função tcreat"
  - "Função creat"
  - "Função _tcreat"
ms.assetid: 3b3b795d-1620-40ec-bd2b-a4bbb0d20fe5
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _creat, _wcreat
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um arquivo novo.  `_creat` e `_wcreat` foram preteridos; use [\_sopen\_s, \_wsopen\_s](../../c-runtime-library/reference/sopen-s-wsopen-s.md) em vez disso.  
  
## Sintaxe  
  
```  
int _creat(   
   const char *filename,  
   int pmode   
);  
int _wcreat(   
   const wchar_t *filename,  
   int pmode   
);  
```  
  
#### Parâmetros  
 `filename`  
 Nome do novo arquivo.  
  
 `pmode`  
 Configuração de permissão.  
  
## Valor de retorno  
 Essas funções, se tiver êxito, retornam um descritor de arquivo para o arquivo criado.  Caso contrário, as funções retornam – 1 e `errno` definido como mostra a tabela a seguir.  
  
|defina de`errno`|Descrição|  
|----------------------|---------------|  
|`EACCES`|`filename` especifica um arquivo somente leitura existente ou especifica um diretório em vez de um arquivo.|  
|`EMFILE`|Não mais descritor de arquivo está disponível.|  
|`ENOENT`|O arquivo especificado não pôde ser localizado.|  
  
 Se `filename` for NULL, essas funções invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções definirão `errno` para `EINVAL` e retornarão \-1.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de `_creat` cria um novo arquivo ou abre e trunca existente.  `_wcreat` é uma versão de caractere longo de `_creat`; o argumento `filename` para `_wcreat` é uma cadeia de caractere longo.  Caso contrário, `_wcreat` e `_creat`, ao contrário, se comportam de forma idêntica.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tcreat`|`_creat`|`_creat`|`_wcreat`|  
  
 Se o arquivo especificado por `filename` não existir, um novo arquivo será criado com a configuração de permissão especificada e aberto para gravação.  Se o arquivo já existir e a configuração de permissão permite escrever, `_creat` trunca o arquivo ao comprimento 0, destruindo os conteúdos anteriores, e abri\-lo para gravação.  A configuração de permissão, `pmode`, se aplica aos recém\-criados apenas arquivos.  O novo arquivo recebe a configuração de permissão especificada depois que é fechado pela primeira vez.  A expressão de inteiro `pmode` contém uma ou ambas as constantes manifestas `_S_IWRITE` e `_S_IREAD`, definido no sistema \\ Stat.h.  Quando ambas as constantes são fornecidas, são adicionadas com o operador bit a bit de `OR` \(  **&#124;**\).  O parâmetro de `pmode` é definido como um dos seguintes valores.  
  
|Valor|Definição|  
|-----------|---------------|  
|`_S_IWRITE`|Gravando permitida.|  
|`_S_IREAD`|Leitura permitidas.|  
|`_S_IREAD &#124; _S_IWRITE`|Leitura e gravação permitidas.|  
  
 Se a permissão de gravação não for especificado, o arquivo é somente leitura.  Todos os arquivos são sempre legíveis; é impossível atribuir a permissão somente gravação.  Os modos `_S_IWRITE` e `_S_IREAD``| _S_IWRITE` são equivalentes em.  Os arquivos abertos usando `_creat` são sempre abertos no modo de compatibilidade \(consulte [\_sopen](../../c-runtime-library/reference/sopen-wsopen.md)\) com `_SH_DENYNO`.  
  
 `_creat` aplica a máscara de arquivo atual permissão a `pmode` antes de definir as permissões [\_umask](../../c-runtime-library/reference/umask.md)\(consulte\).  `_creat` primeiro é fornecido para compatibilidade com as bibliotecas anteriores.  Uma chamada para `_open` com `_O_CREAT` e a `_O_TRUNC` no parâmetro de `oflag` é equivalente a `_creat` e é preferível para o novo código.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_creat`|\<io.h\>|\<o sistema\/types.h, o sistema\>\<\/stat.h, errno.h\>\<\>|  
|`_wcreat`|\<io.h ou\> wchar.h \<\>|\<o sistema\/types.h, o sistema\>\<\/stat.h, errno.h\>\<\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_creat.c  
// compile with: /W3  
// This program uses _creat to create  
// the file (or truncate the existing file)  
// named data and open it for writing.  
  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <io.h>  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   int fh;  
  
   fh = _creat( "data", _S_IREAD | _S_IWRITE ); // C4996  
   // Note: _creat is deprecated; use _sopen_s instead  
   if( fh == -1 )  
      perror( "Couldn't create data file" );  
   else  
   {  
      printf( "Created data file.\n" );  
      _close( fh );  
   }  
}  
```  
  
  **Arquivo de dados criado.**   
## Consulte também  
 [E\/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [\_chmod, \_wchmod](../../c-runtime-library/reference/chmod-wchmod.md)   
 [\_chsize](../../c-runtime-library/reference/chsize.md)   
 [\_close](../Topic/_close.md)   
 [\_dup, \_dup2](../../c-runtime-library/reference/dup-dup2.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [\_sopen, \_wsopen](../../c-runtime-library/reference/sopen-wsopen.md)   
 [\_umask](../../c-runtime-library/reference/umask.md)