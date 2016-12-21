---
title: "_umask | Microsoft Docs"
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
  - "_umask"
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
  - "api-ms-win-crt-filesystem-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_umask"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _umask"
  - "permissões de arquivo [C++]"
  - "Arquivos  [C++], configurações de permissão para"
  - "máscaras"
  - "máscaras, configuração de permissão de arquivo"
  - "Função umask"
ms.assetid: 5e9a13ba-5321-4536-8721-6afb6f4c8483
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _umask
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Define a máscara de arquivo padrão permissão.  Uma versão mais segura dessa função está disponível; consulte [\_umask\_s](../Topic/_umask_s.md).  
  
## Sintaxe  
  
```  
int _umask(  
   int pmode   
);  
```  
  
#### Parâmetros  
 `pmode`  
 Usar como padrão a configuração de permissão.  
  
## Valor de retorno  
 `_umask` retorna o valor anterior de `pmode`.  Não há nenhum retorno de erro.  
  
## Comentários  
 A função de `_umask` define a máscara de arquivo permissão do processo atual para o modo especificado por `pmode`*.* A máscara de arquivo permissão altera a configuração de permissão dos novos arquivos criados por `_creat`, por `_open`, ou por `_sopen`.  Se um bit na máscara é 1, o bit correspondente no valor solicitado de permissões do arquivo é definido como 0 \(não permitido\).  Se um bit na máscara é 0, o bit correspondente está inalterado.  A configuração de permissão para um novo arquivo não estiver definida até que o arquivo seja fechado pela primeira vez.  
  
 A expressão de inteiro `pmode` contém uma ou ambas as seguintes constantes manifestas, definido no sistema \\ STAT.H:  
  
 `_S_IWRITE`  
 Gravando permitida.  
  
 `_S_IREAD`  
 Leitura permitidas.  
  
 `_S_IREAD | _S_IWRITE`  
 Leitura e gravação permitidas.  
  
 Quando ambas as constantes são fornecidas, são adicionadas com bit a bit OR \(o operador          `|`  \).  Se o argumento de `pmode` é `_S_IREAD`, leia não é permitido \(o arquivo é somente gravação.\)  Se o argumento de `pmode` é `_S_IWRITE`, escrever não é permitida \(o arquivo é somente leitura\).  Por exemplo, se o bit de gravação é definido na máscara, todos os novos arquivos serão somente leitura.  Observe que o MS\-DOS e com os sistemas operacionais Windows, todos os arquivos são legíveis; não é possível atribuir a permissão somente gravação.  Consequentemente, definir o bit de leitura com `_umask` não tem nenhum efeito nos modos de arquivo.  
  
 Se `pmode` não é uma combinação de uma das constantes manifestas nem inserir um conjunto de substituição de constantes, a função ignorará somente as.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_umask`|\<io.h, o sistema\>\<\/stat.h, o sistema\/\>types.h \<\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_umask.c  
// compile with: /W3  
// This program uses _umask to set  
// the file-permission mask so that all future  
// files will be created as read-only files.  
// It also displays the old mask.  
#include <sys/stat.h>  
#include <sys/types.h>  
#include <io.h>  
#include <stdio.h>  
  
int main( void )  
{  
   int oldmask;  
  
   /* Create read-only files: */  
   oldmask = _umask( _S_IWRITE ); // C4996  
   // Note: _umask is deprecated; consider using _umask_s instead  
   printf( "Oldmask = 0x%.4x\n", oldmask );  
}  
```  
  
  **Oldmask \= 0x0000**   
## Equivalência do .NET Framework  
 [System::IO::File::SetAttributes](https://msdn.microsoft.com/en-us/library/system.io.file.setattributes.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [E\/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [\_chmod, \_wchmod](../../c-runtime-library/reference/chmod-wchmod.md)   
 [\_creat, \_wcreat](../../c-runtime-library/reference/creat-wcreat.md)   
 [\_mkdir, \_wmkdir](../Topic/_mkdir,%20_wmkdir.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)