---
title: "_makepath, _wmakepath | Microsoft Docs"
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
  - "_makepath"
  - "_wmakepath"
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
  - "_wmakepath"
  - "_tmakepath"
  - "makepath"
  - "tmakepath"
  - "wmakepath"
  - "_makepath"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _makepath"
  - "Função _tmakepath"
  - "Função _wmakepath"
  - "Função makepath"
  - "caminhos"
  - "Função tmakepath"
  - "Função wmakepath"
ms.assetid: 5930b197-a7b8-46eb-8519-2841a58cd026
caps.latest.revision: 22
caps.handback.revision: 20
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _makepath, _wmakepath
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Crie um nome de caminho dos componentes.  Versões mais seguras dessas funções estão disponíveis; consulte [\_makepath\_s, \_wmakepath\_s](../../c-runtime-library/reference/makepath-s-wmakepath-s.md).  
  
## Sintaxe  
  
```  
void _makepath(  
   char *path,  
   const char *drive,  
   const char *dir,  
   const char *fname,  
   const char *ext   
);  
void _wmakepath(  
   wchar_t *path,  
   const wchar_t *drive,  
   const wchar_t *dir,  
   const wchar_t *fname,  
   const wchar_t *ext   
);  
```  
  
#### Parâmetros  
 `path`  
 Buffer de caminho completo.  
  
 `drive`  
 Contém uma letra \(A, B, e assim por diante\) correspondentes à unidade desejada e a dois\-pontos à direita opcional.  `_makepath` insere os dois\-pontos automaticamente no caminho composto se está ausente.  Se `drive` é `NULL` ou aponta para uma cadeia de caracteres vazia, nenhuma letra de unidade aparece na cadeia de caracteres composta de `path` .  
  
 `dir`  
 Contém o caminho dos diretórios, não incluindo o designador de unidade ou o nome do arquivo real.  A barra à direita é opcional, e uma barra \(\/\) ou uma barra invertida \(\\\) ou ambos podem ser usados em um único argumento de `dir` .  Se nenhuma barra à direita \(\/ou\/\/\\\) for especificada, será inserida automaticamente.  Se `dir` é `NULL` ou aponta para uma cadeia de caracteres vazia, nenhum caminho de diretório é inserido na cadeia de caracteres composta de `path` .  
  
 `fname`  
 Contém o nome de arquivo base sem nenhuma extensões de nome de arquivo.  Se `fname` é `NULL` ou aponta para uma cadeia de caracteres vazia, nenhum nome de arquivo é inserido na cadeia de caracteres composta de `path` .  
  
 `ext`  
 Contém a extensão de nome de arquivo real, com ou sem um período principal \(.\).  `_makepath` insere o período automaticamente se não aparecer em `ext`.  Se `ext` é `NULL` ou aponta para uma cadeia de caracteres vazia, nenhuma extensão é inserida na cadeia de caracteres composta de `path` .  
  
## Comentários  
 A função de `_makepath` cria uma cadeia de caracteres composta de caminho dos componentes individuais, para armazenar o resultado em `path`.  `path` pode incluir uma letra de unidade, um caminho de diretório, um nome de arquivo, e uma extensão de nome de arquivo.  `_wmakepath` é uma versão de caractere largo de `_makepath`; os argumentos para `_wmakepath` são cadeias de caractere amplo.  Caso contrário, `_wmakepath` e `_makepath`, ao contrário, se comportam de forma idêntica.  
  
 **Observação sobre segurança** Use uma cadeia de caracteres com terminação nula.  Para evitar a excesso de buffer, a cadeia de caracteres com terminação nula não deve exceder o tamanho do buffer de `path` .  `_makepath` não assegura que o comprimento da cadeia de caracteres composta de caminho não exceda `_MAX_PATH`.  Para obter mais informações, consulte [Evitando saturações de buffer](http://msdn.microsoft.com/library/windows/desktop/ms717795).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tmakepath`|`_makepath`|`_makepath`|`_wmakepath`|  
  
 O argumento de `path` deve apontar para um buffer vazio grande o suficiente para manter o caminho completo.  `path` composto não deve ser maior que a constante de `_MAX_PATH` , definida em Stdlib.h.  
  
 Se o caminho for `NULL`, o manipulador inválido do parâmetro será chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Além disso, `errno` é definido como `EINVAL`.  os valores de`NULL` são permitidos todos os outros parâmetros.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_makepath`|\<stdlib.h\>|  
|`_wmakepath`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_makepath.c  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char path_buffer[_MAX_PATH];  
   char drive[_MAX_DRIVE];  
   char dir[_MAX_DIR];  
   char fname[_MAX_FNAME];  
   char ext[_MAX_EXT];  
  
   _makepath( path_buffer, "c", "\\sample\\crt\\", "makepath", "c" ); // C4996  
   // Note: _makepath is deprecated; consider using _makepath_s instead  
   printf( "Path created with _makepath: %s\n\n", path_buffer );  
   _splitpath( path_buffer, drive, dir, fname, ext ); // C4996  
   // Note: _splitpath is deprecated; consider using _splitpath_s instead  
   printf( "Path extracted with _splitpath:\n" );  
   printf( "  Drive: %s\n", drive );  
   printf( "  Dir: %s\n", dir );  
   printf( "  Filename: %s\n", fname );  
   printf( "  Ext: %s\n", ext );  
}  
```  
  
  **Caminho criado com o \_makepath: c:\\sample\\crt\\makepath.c**  
**Caminho extraído com \_splitpath:**  
 **Unidade: c:**  
 **Dir: \\sample\\crt\\**  
 **Nome de arquivo: makepath**  
 **Ext: .c**   
## Equivalência do .NET Framework  
 [System::IO::File::Create](https://msdn.microsoft.com/en-us/library/system.io.file.create.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_fullpath, \_wfullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)   
 [\_splitpath, \_wsplitpath](../Topic/_splitpath,%20_wsplitpath.md)   
 [\_makepath\_s, \_wmakepath\_s](../../c-runtime-library/reference/makepath-s-wmakepath-s.md)