---
title: "_makepath_s, _wmakepath_s | Microsoft Docs"
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
  - "_wmakepath_s"
  - "_makepath_s"
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
  - "_wmakepath_s"
  - "makepath_s"
  - "_makepath_s"
  - "wmakepath_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _makepath_s"
  - "Função wmakepath_s"
  - "caminhos"
  - "Função _wmakepath_s"
  - "Função makepath_s"
ms.assetid: 4405e43c-3d63-4697-bb80-9b8dcd21d027
caps.latest.revision: 29
caps.handback.revision: 29
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _makepath_s, _wmakepath_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Cria um nome de caminho dos componentes.  Essas são versões de [\_makepath, \_wmakepath](../../c-runtime-library/reference/makepath-wmakepath.md) com aprimoramentos de segurança conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
errno_t _makepath_s(  
   char *path,  
   size_t sizeInBytes,  
   const char *drive,  
   const char *dir,  
   const char *fname,  
   const char *ext   
);  
errno_t _wmakepath_s(  
   wchar_t *path,  
   size_t sizeInWords,  
   const wchar_t *drive,  
   const wchar_t *dir,  
   const wchar_t *fname,  
   const wchar_t *ext   
);  
template <size_t size>  
errno_t _makepath_s(  
   char (&path)[size],  
   const char *drive,  
   const char *dir,  
   const char *fname,  
   const char *ext   
); // C++ only  
template <size_t size>  
errno_t _wmakepath_s(  
   wchar_t (&path)[size],  
   const wchar_t *drive,  
   const wchar_t *dir,  
   const wchar_t *fname,  
   const wchar_t *ext   
); // C++ only  
```  
  
#### Parâmetros  
 \[saída\] `path`  
 Buffer de caminho completo.  
  
 \[entrada\] `sizeInWords`  
 Tamanho do buffer no word.  
  
 \[entrada\] `sizeInBytes`  
 Tamanho do buffer em bytes.  
  
 \[entrada\] `drive`  
 Contém uma letra \(A, B, e assim por diante\) correspondentes à unidade desejada e a dois\-pontos à direita opcional.  `_makepath_s` insere os dois\-pontos automaticamente no caminho composto se está ausente.  Se `drive` é `NULL` ou aponta para uma cadeia de caracteres vazia, nenhuma letra de unidade aparece na cadeia de caracteres composta de `path` .  
  
 \[entrada\] `dir`  
 Contém o caminho dos diretórios, não incluindo o designador de unidade ou o nome do arquivo real.  A barra à direita é opcional, e uma barra \(\/\) ou uma barra invertida \(\\\) ou ambos podem ser usados em um único argumento de `dir` .  Se nenhuma barra à direita \(\/ou\/\/\\\) for especificada, será inserida automaticamente.  Se `dir` é `NULL` ou aponta para uma cadeia de caracteres vazia, nenhum caminho de diretório é inserido na cadeia de caracteres composta de `path` .  
  
 \[entrada\] `fname`  
 Contém o nome de arquivo base sem nenhuma extensões de nome de arquivo.  Se `fname` é `NULL` ou aponta para uma cadeia de caracteres vazia, nenhum nome de arquivo é inserido na cadeia de caracteres composta de `path` .  
  
 \[entrada\] `ext`  
 Contém a extensão de nome de arquivo real, com ou sem um período principal \(.\).  `_makepath_s` insere o período automaticamente se não aparecer em `ext`.  Se `ext` é `NULL` ou aponta para uma cadeia de caracteres vazia, nenhuma extensão é inserida na cadeia de caracteres composta de `path` .  
  
## Valor de retorno  
 Zero se tiver êxito; um código de erro em falha.  
  
### Condições de erro  
  
|`path`|`sizeInWords` \/ `sizeInBytes`|Return|Conteúdo de `path`|  
|------------|------------------------------------|------------|------------------------|  
|`NULL`|any|`EINVAL`|não modificado|  
|any|\<\= 0|`EINVAL`|não modificado|  
  
 Se qualquer uma das condições de erro acima ocorrerem, essas funções invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, `errno` estádefinido como`EINVAL` e retorna`EINVAL`**.** `NULL` de funções são permitidos os parâmetros `drive`, `fname`, e `ext`.  Para obter informações sobre o comportamento quando esses parâmetros são ponteiros nulos ou cadeias de caracteres vazias, consulte a seção comentários.  
  
## Comentários  
 A função de `_makepath_s` cria uma cadeia de caracteres composta de caminho dos componentes individuais, para armazenar o resultado em `path`.  `path` pode incluir uma letra de unidade, um caminho de diretório, um nome de arquivo, e uma extensão de nome de arquivo.  `_wmakepath_s` é uma versão de caractere largo de `_makepath_s`; os argumentos para `_wmakepath_s` são cadeias de caractere amplo.  Caso contrário, `_wmakepath_s` e `_makepath_s`, ao contrário, se comportam de forma idêntica.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tmakepath_s`|`_makepath_s`|`_makepath_s`|`_wmakepath_s`|  
  
 O argumento de `path` deve apontar para um buffer vazio grande o suficiente para manter o caminho completo.  `path` composto não deve ser maior que a constante de `_MAX_PATH` , definida em Stdlib.h.  
  
 Se o caminho for `NULL`, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Além disso, `errno` é definido como `EINVAL`.  os valores de`NULL` são permitidos todos os outros parâmetros.  
  
 No C\+\+, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e podem substituir automaticamente as funções menos seguras mais antigas por correspondentes mais seguras e mais recentes.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
 As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD.  Para desabilitar esse comportamento, use [\_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_makepath_s`|\<stdlib.h\>|  
|`_wmakepath_s`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_makepath_s.c  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char path_buffer[_MAX_PATH];  
   char drive[_MAX_DRIVE];  
   char dir[_MAX_DIR];  
   char fname[_MAX_FNAME];  
   char ext[_MAX_EXT];  
   errno_t err;  
  
   err = _makepath_s( path_buffer, _MAX_PATH, "c", "\\sample\\crt\\",  
                      "crt_makepath_s", "c" );  
   if (err != 0)  
   {  
      printf("Error creating path. Error code %d.\n", err);  
      exit(1);  
   }  
   printf( "Path created with _makepath_s: %s\n\n", path_buffer );  
   err = _splitpath_s( path_buffer, drive, _MAX_DRIVE, dir, _MAX_DIR, fname,  
                       _MAX_FNAME, ext, _MAX_EXT );  
   if (err != 0)  
   {  
      printf("Error splitting the path. Error code %d.\n", err);  
      exit(1);  
   }  
   printf( "Path extracted with _splitpath_s:\n" );  
   printf( "  Drive: %s\n", drive );  
   printf( "  Dir: %s\n", dir );  
   printf( "  Filename: %s\n", fname );  
   printf( "  Ext: %s\n", ext );  
}  
```  
  
## Saída  
  
```  
Path created with _makepath_s: c:\sample\crt\crt_makepath_s.c  
  
Path extracted with _splitpath_s:  
  Drive: c:  
  Dir: \sample\crt\  
  Filename: crt_makepath_s  
  Ext: .c  
```  
  
## Equivalência do .NET Framework  
 [System::IO::File::Create](https://msdn.microsoft.com/en-us/library/system.io.file.create.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_fullpath, \_wfullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)   
 [\_splitpath\_s, \_wsplitpath\_s](../../c-runtime-library/reference/splitpath-s-wsplitpath-s.md)   
 [\_makepath, \_wmakepath](../../c-runtime-library/reference/makepath-wmakepath.md)