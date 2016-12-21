---
title: "_fullpath, _wfullpath | Microsoft Docs"
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
  - "_fullpath"
  - "_wfullpath"
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
  - "wfullpath"
  - "fullpath"
  - "_wfullpath"
  - "_fullpath"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fullpath"
  - "Função _wfullpath"
  - "caminhos absolutos"
  - "Função fullpath"
  - "caminhos de arquivo relativos"
  - "Função wfullpath"
ms.assetid: 4161ec17-0d22-45dd-b07d-0222553afae9
caps.latest.revision: 18
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _fullpath, _wfullpath
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um absoluta ou um nome de caminho completo para o nome do caminho relativo especificado.  
  
## Sintaxe  
  
```  
char *_fullpath(   
   char *absPath,  
   const char *relPath,  
   size_t maxLength   
);  
wchar_t *_wfullpath(   
   wchar_t *absPath,  
   const wchar_t *relPath,  
   size_t maxLength   
);  
```  
  
#### Parâmetros  
 `absPath`  
 Ponteiro para um buffer que contém o absoluta ou o nome do caminho completo, ou NULL.  
  
 `relPath`  
 Nome do caminho relativo.  
  
 `maxLength`  
 Comprimento máximo do buffer do nome de caminho absoluto \(`absPath`\).  Esse comprimento é em bytes para `_fullpath` mas em caracteres amplos`wchar_t`\(\) para `_wfullpath`.  
  
## Valor de retorno  
 Cada uma dessas funções retorna um ponteiro para um buffer que contém o nome do caminho absoluto \(`absPath`\).  Se houver um erro \(por exemplo, se o valor transmitido em `relPath` inclui uma letra de unidade que não é válido ou não pode ser localizada, ou se o comprimento do nome de caminho absoluta criado \(`absPath`\) é maior do que `maxLength`\), a função retornará `NULL`.  
  
## Comentários  
 A função de `_fullpath` expande o nome de caminho relativa em `relPath` a seu totalmente qualificado ou caminho absoluta e armazena esse nome em `absPath`*.* Se `absPath` for NULL, `malloc` é usada para atribuir um buffer de comprimento suficiente para conter o nome de caminho.  É responsabilidade do chamador liberar esse buffer.  Um nome de caminho especifica um caminho relativo para outro local atual \(como o diretório de trabalho atual: “."\).  Um nome de caminho absoluto é a expansão de um nome de caminho relativo que indica o caminho inteiro exigida para alcançar o local desejado da raiz do sistema de arquivos.  Ao contrário de `_makepath`, `_fullpath` pode ser usado para obter o nome de caminho absoluto para os caminhos relativos`relPath`\(\) que incluem “. \/” ou “. \/” em seus nomes.  
  
 Por exemplo, para usar rotinas de tempo de execução C, o aplicativo deve incluir os arquivos de cabeçalho que contêm as declarações para as rotinas.  Cada arquivo de cabeçalho inclui referências de instrução o local do arquivo em um modo relativo \(o diretório de trabalho de aplicativo\):  
  
```  
#include <stdlib.h>  
```  
  
 quando o caminho absoluto \(local real do sistema de arquivos\) do arquivo poderia ser:  
  
```  
\\machine\shareName\msvcSrc\crt\headerFiles\stdlib.h  
```  
  
 `_fullpath` controla automaticamente argumentos de cadeia de caracteres de multibyte\- caracteres conforme apropriado, confirmando sequências de multibyte\- caractere de acordo com a página de código de multibyte atualmente em uso.  `_wfullpath` é uma versão de ampla caractere de `_fullpath`; os argumentos de cadeia de caracteres a `_wfullpath` são cadeias de caracteres de ampla caractere.  `_wfullpath` e `_fullpath` se comportam idêntica exceto que `_wfullpath` não trata as cadeias de caracteres de multibyte\- caractere.  
  
 Se `_DEBUG` e `_CRTDBG_MAP_ALLOC` ambos são definidas, as chamadas para `_fullpath` e `_wfullpath` são substituídos por chamadas a `_fullpath_dbg` e a `_wfullpath_dbg` para permitir depuração alocações de memória.  Para obter mais informações, consulte [\_fullpath\_dbg, \_wfullpath\_dbg](../../c-runtime-library/reference/fullpath-dbg-wfullpath-dbg.md).  
  
 Essa função invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md), se `maxlen` é menor ou igual a 0.  Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará `NULL`.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tfullpath`|`_fullpath`|`_fullpath`|`_wfullpath`|  
  
 Se o buffer de `absPath` é `NULL`, `_fullpath` chama [malloc](../../c-runtime-library/reference/malloc.md) para alocar um buffer e ignora o argumento de `maxLength` .  É responsabilidade do chamador desaloque esse buffer \(usando [livre](../../c-runtime-library/reference/free.md)\) conforme apropriado.  Se o argumento de `relPath` especifica uma unidade de disco, o diretório atual dessa unidade é combinado com o caminho.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`_fullpath`|\<stdlib.h\>|  
|`_wfullpath`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_fullpath.c  
// This program demonstrates how _fullpath  
// creates a full path from a partial path.  
  
#include <stdio.h>  
#include <conio.h>  
#include <stdlib.h>  
#include <direct.h>  
  
void PrintFullPath( char * partialPath )  
{  
   char full[_MAX_PATH];  
   if( _fullpath( full, partialPath, _MAX_PATH ) != NULL )  
      printf( "Full path is: %s\n", full );  
   else  
      printf( "Invalid path\n" );  
}  
  
int main( void )  
{  
   PrintFullPath( "test" );  
   PrintFullPath( "\\test" );  
   PrintFullPath( "..\\test" );  
}  
```  
  
  **O caminho completo é: C:\\Documents and settings \\ usuário \\ meus documentos \\ teste**  
**O caminho completo é: C:\\test**  
**O caminho completo é: C:\\Documents and Settings\\user\\test**   
## Equivalência do .NET Framework  
 [System::IO::File::Create](https://msdn.microsoft.com/en-us/library/system.io.file.create.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_getcwd, \_wgetcwd](../../c-runtime-library/reference/getcwd-wgetcwd.md)   
 [\_getdcwd, \_wgetdcwd](../../c-runtime-library/reference/getdcwd-wgetdcwd.md)   
 [\_makepath, \_wmakepath](../../c-runtime-library/reference/makepath-wmakepath.md)   
 [\_splitpath, \_wsplitpath](../Topic/_splitpath,%20_wsplitpath.md)