---
title: "_searchenv, _wsearchenv | Microsoft Docs"
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
  - "_searchenv"
  - "_wsearchenv"
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
  - "api-ms-win-crt-environment-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_wsearchenv"
  - "_tsearchenv"
  - "wsearchenv"
  - "_searchenv"
  - "searchenv"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _searchenv"
  - "Função _tsearchenv"
  - "Função _wsearchenv"
  - "caminhos de ambiente"
  - "caminhos de ambiente, procurando arquivos"
  - "Arquivos  [C++], localizando"
  - "Função searchenv"
  - "Função tsearchenv"
  - "Função wsearchenv"
ms.assetid: 9c944a27-d326-409b-aee6-410e8762d9d3
caps.latest.revision: 33
caps.handback.revision: 31
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _searchenv, _wsearchenv
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usa caminhos de ambiente para procurar um arquivo.  Versões mais seguras dessas funções estão disponíveis; consulte [\_searchenv\_s, \_wsearchenv\_s](../Topic/_searchenv_s,%20_wsearchenv_s.md).  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
void _searchenv(  
   const char *filename,  
   const char *varname,  
   char *pathname   
);  
void _wsearchenv(  
   const wchar_t *filename,  
   const wchar_t *varname,  
   wchar_t *pathname   
);  
template <size_t size>  
void _searchenv(  
   const char *filename,  
   const char *varname,  
   char (&pathname)[size]  
); // C++ only  
template <size_t size>  
void _wsearchenv(  
   const wchar_t *filename,  
   const wchar_t *varname,  
   wchar_t (&pathname)[size]  
); // C++ only  
```  
  
#### Parâmetros  
 `filename`  
 Nome do arquivo a ser pesquisado.  
  
 `varname`  
 Ambiente de pesquisa.  
  
 `pathname`  
 Buffer para armazenar o caminho completo.  
  
## Comentários  
 O `_searchenv` rotina procurará o arquivo de destino no domínio especificado.  O `varname` variável pode ser qualquer ambiente ou variável definida pelo usuário — por exemplo, `PATH`, `LIB`, ou `INCLUDE`que especifica uma lista de caminhos de diretório.  Porque `_searchenv` diferencia maiúsculas de minúsculas, `varname` deve corresponder ao uso da variável de ambiente.  
  
 A rotina primeiro procura o arquivo no diretório de trabalho atual.  Se não encontrar o arquivo, ele procura os diretórios especificados pela variável de ambiente.  Se o arquivo de destino estiver em um desses diretórios, o caminho recém\-criado será copiado para `pathname`.  Se o `filename` arquivo não for encontrado, `pathname` contém uma cadeia de caracteres vazia terminada em nulo.  
  
 O `pathname` buffer deve ser pelo menos `_MAX_PATH` caracteres para acomodar o comprimento total do nome do caminho construído.  Caso contrário, `_searchenv` poderia saturar o `pathname` buffer e causar um comportamento inesperado.  
  
 `_wsearchenv` é uma versão de caractere largo de `_searchenv`, e os argumentos para `_wsearchenv` são cadeias de caracteres largos.  Caso contrário, `_wsearchenv` e `_searchenv` se comportam de forma idêntica.  
  
 Se `filename` é uma cadeia de caracteres vazia, essas funções retornam `ENOENT`.  
  
 Se `filename` ou `pathname` é um `NULL` ponteiro, o manipulador de parâmetro inválido é invocado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão \-1 e definirão `errno` como `EINVAL`.  
  
 Para obter mais informações sobre `errno` e códigos de erro, consulte [Constantes errno](../../c-runtime-library/errno-constants.md).  
  
 Em C\+\+, essas funções têm sobrecargas de modelo que invocam os mais recentes correspondentes mais seguras dessas funções.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tsearchenv`|`_searchenv`|`_searchenv`|`_wsearchenv`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_searchenv`|\<stdlib.h\>|  
|`_wsearchenv`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_searchenv.c  
// compile with: /W3  
// This program searches for a file in  
// a directory that's specified by an environment variable.  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char pathbuffer[_MAX_PATH];  
   char searchfile[] = "CL.EXE";  
   char envvar[] = "PATH";  
  
   // Search for file in PATH environment variable:  
   _searchenv( searchfile, envvar, pathbuffer ); // C4996  
   // Note: _searchenv is deprecated; consider using _searchenv_s  
   if( *pathbuffer != '\0' )  
      printf( "Path for %s:\n%s\n", searchfile, pathbuffer );  
   else  
      printf( "%s not found\n", searchfile );  
}  
```  
  
  **Caminho para CL. EXE:**  
**C:\\Program Files\\Microsoft Visual Studio 8\\VC\\BIN\\CL. EXE**   
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função C padrão, use `PInvoke`. Para obter mais informações, consulte [Exemplos de invocação de plataforma](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Controle de diretório](../../c-runtime-library/directory-control.md)   
 [getenv, \_wgetenv](../../c-runtime-library/reference/getenv-wgetenv.md)   
 [\_putenv, \_wputenv](../../c-runtime-library/reference/putenv-wputenv.md)   
 [\_searchenv\_s, \_wsearchenv\_s](../Topic/_searchenv_s,%20_wsearchenv_s.md)