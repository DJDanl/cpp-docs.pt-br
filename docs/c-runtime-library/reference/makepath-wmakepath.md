---
title: _makepath, _wmakepath | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _makepath
- _wmakepath
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-filesystem-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _wmakepath
- _tmakepath
- makepath
- tmakepath
- wmakepath
- _makepath
dev_langs:
- C++
helpviewer_keywords:
- _makepath function
- wmakepath function
- makepath function
- _tmakepath function
- paths
- _wmakepath function
- tmakepath function
ms.assetid: 5930b197-a7b8-46eb-8519-2841a58cd026
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: e207ec2a158bbc311ae181e71b9170cf2e48e76d
ms.lasthandoff: 02/25/2017

---
# <a name="makepath-wmakepath"></a>_makepath, _wmakepath
Crie um nome de caminho com base em componentes. Versões mais seguras dessas funções estão disponíveis; consulte [_makepath_s, _wmakepath_s](../../c-runtime-library/reference/makepath-s-wmakepath-s.md).  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `path`  
 Buffer de caminho completo.  
  
 `drive`  
 Contém uma letra (A, B e assim por diante) correspondente à unidade desejada e um sinal de dois pontos opcional à direita. `_makepath` insere automaticamente os dois pontos no caminho de composição se ele estiver ausente. Se `drive` for `NULL` ou apontar para uma cadeia de caracteres vazia, nenhuma letra da unidade aparecerá na cadeia de caracteres de composição `path`.  
  
 `dir`  
 Contém o caminho de diretórios, excluindo o designador da unidade ou o nome de arquivo real. A barra à direita é opcional e uma barra (/), uma barra invertida (\\) ou ambas podem ser usadas em um único argumento `dir`. Se nenhuma barra à direita (/ ou \\) for especificada, ela será inserida automaticamente. Se `dir` for `NULL` ou apontar para uma cadeia de caracteres vazia, nenhum caminho de diretório será inserido na cadeia de caracteres de composição `path`.  
  
 `fname`  
 Contém o nome de arquivo base sem qualquer extensão de nome de arquivo. Se `fname` for `NULL` ou apontar para uma cadeia de caracteres vazia, nenhum nome de arquivo será inserido na cadeia de caracteres de composição `path`.  
  
 `ext`  
 Contém a extensão de nome de arquivo real, com ou sem um ponto à esquerda (.). `_makepath` insere o período automaticamente se ele não aparecer em `ext`. Se `ext` for `NULL` ou apontar para uma cadeia de caracteres vazia, nenhuma extensão será inserida na cadeia de caracteres de composição `path`.  
  
## <a name="remarks"></a>Comentários  
 A função `_makepath` cria uma cadeia de caracteres de caminho de composição com base em componentes individuais e armazena o resultado em `path`. O `path` pode incluir uma letra da unidade, caminho de diretório, nome de arquivo e extensão de nome de arquivo. `_wmakepath` é uma versão de caractere largo de `_makepath`; os argumentos para `_wmakepath` são cadeias de caracteres largas. Caso contrário, `_wmakepath` e `_makepath` se comportam de forma idêntica.  
  
 **Observação de Segurança** Use uma cadeia de caracteres terminada em nulo. Para evitar o estouro de buffer, a cadeia de caracteres terminada em nulo não deve exceder o tamanho do buffer `path`. `_makepath` não garante que o comprimento da cadeia de caracteres de caminho de composição não exceda `_MAX_PATH`. Para obter mais informações, consulte [Avoiding Buffer Overruns](http://msdn.microsoft.com/library/windows/desktop/ms717795) (Evitando estouros de buffer).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tmakepath`|`_makepath`|`_makepath`|`_wmakepath`|  
  
 O argumento `path` deve apontar para um buffer vazio grande o suficiente para conter o caminho completo. A composição `path` não deve ser maior do que a constante `_MAX_PATH`, definida em Stdlib.h.  
  
 Se o caminho for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Além disso, `errno` é definido como `EINVAL`. Valores `NULL` são permitidos para todos os outros parâmetros.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_makepath`|\<stdlib.h>|  
|`_wmakepath`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
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
  
```Output  
Path created with _makepath: c:\sample\crt\makepath.c  
  
Path extracted with _splitpath:  
  Drive: c:  
  Dir: \sample\crt\  
  Filename: makepath  
  Ext: .c  
```  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::IO::File::Create](https://msdn.microsoft.com/en-us/library/system.io.file.create.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de Arquivos](../../c-runtime-library/file-handling.md)   
 [_fullpath, _wfullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)   
 [_splitpath, _wsplitpath](../../c-runtime-library/reference/splitpath-wsplitpath.md)   
 [_makepath_s, _wmakepath_s](../../c-runtime-library/reference/makepath-s-wmakepath-s.md)
