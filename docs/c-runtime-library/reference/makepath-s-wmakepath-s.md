---
title: _makepath_s, _wmakepath_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wmakepath_s
- _makepath_s
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
- _wmakepath_s
- makepath_s
- _makepath_s
- wmakepath_s
dev_langs:
- C++
helpviewer_keywords:
- _makepath_s function
- wmakepath_s function
- paths
- _wmakepath_s function
- makepath_s function
ms.assetid: 4405e43c-3d63-4697-bb80-9b8dcd21d027
caps.latest.revision: 29
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: 0d3ac02a0ac8dfa7f681c8585be7e1b6f41f0f82
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="makepaths-wmakepaths"></a>_makepath_s, _wmakepath_s
Cria um nome de caminho com base nos componentes. Estas são versões de [_makepath, _wmakepath](../../c-runtime-library/reference/makepath-wmakepath.md) com melhorias de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 [out] `path`  
 Buffer de caminho completo.  
  
 [in] `sizeInWords`  
 O tamanho do buffer em palavras.  
  
 [in] `sizeInBytes`  
 O tamanho do buffer em bytes.  
  
 [in] `drive`  
 Contém uma letra (A, B e assim por diante) correspondente à unidade desejada e um sinal de dois pontos opcional à direita. `_makepath_s` insere automaticamente os dois pontos no caminho de composição se ele estiver ausente. Se `drive` for `NULL` ou apontar para uma cadeia de caracteres vazia, nenhuma letra da unidade aparecerá na cadeia de caracteres de composição `path`.  
  
 [in] `dir`  
 Contém o caminho de diretórios, excluindo o designador da unidade ou o nome de arquivo real. A barra à direita é opcional e uma barra (/), uma barra invertida (\\) ou ambas podem ser usadas em um único argumento `dir`. Se nenhuma barra à direita (/ ou \\) for especificada, ela será inserida automaticamente. Se `dir` for `NULL` ou apontar para uma cadeia de caracteres vazia, nenhum caminho de diretório será inserido na cadeia de caracteres de composição `path`.  
  
 [in] `fname`  
 Contém o nome de arquivo base sem qualquer extensão de nome de arquivo. Se `fname` for `NULL` ou apontar para uma cadeia de caracteres vazia, nenhum nome de arquivo será inserido na cadeia de caracteres de composição `path`.  
  
 [in] `ext`  
 Contém a extensão de nome de arquivo real, com ou sem um ponto à esquerda (.). `_makepath_s` insere o período automaticamente se ele não aparecer em `ext`. Se `ext` for `NULL` ou apontar para uma cadeia de caracteres vazia, nenhuma extensão será inserida na cadeia de caracteres de composição `path`.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido; um código de erro em caso de falha.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`path`|`sizeInWords` / `sizeInBytes`|Valor de|Conteúdo de `path`|  
|------------|------------------------------------|------------|------------------------|  
|`NULL`|qualquer|`EINVAL`|não modificado|  
|qualquer|<= 0|`EINVAL`|não modificado|  
  
 Se qualquer uma das condições de erro acima ocorrer, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, `errno` será definido como `EINVAL` e as funções retornarão `EINVAL`. `NULL` tem permissão para os parâmetros `drive`, `fname` e `ext`. Para obter informações sobre o comportamento quando esses parâmetros são ponteiros nulos ou cadeias de caracteres vazias, consulte a seção de Comentários.  
  
## <a name="remarks"></a>Comentários  
 A função `_makepath_s` cria uma cadeia de caracteres de caminho de composição com base em componentes individuais e armazena o resultado em `path`. O `path` pode incluir uma letra da unidade, caminho de diretório, nome de arquivo e extensão de nome de arquivo. `_wmakepath_s` é uma versão de caractere largo de `_makepath_s`; os argumentos para `_wmakepath_s` são cadeias de caracteres largas. Caso contrário, `_wmakepath_s` e `_makepath_s` se comportam de forma idêntica.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tmakepath_s`|`_makepath_s`|`_makepath_s`|`_wmakepath_s`|  
  
 O argumento `path` deve apontar para um buffer vazio grande o suficiente para conter o caminho completo. A composição `path` não deve ser maior do que a constante `_MAX_PATH`, definida em Stdlib.h.  
  
 Se o caminho for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Além disso, `errno` é definido como `EINVAL`. Valores `NULL` são permitidos para todos os outros parâmetros.  
  
 Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
 As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_makepath_s`|\<stdlib.h>|  
|`_wmakepath_s`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="output"></a>Saída  
  
```  
Path created with _makepath_s: c:\sample\crt\crt_makepath_s.c  
  
Path extracted with _splitpath_s:  
  Drive: c:  
  Dir: \sample\crt\  
  Filename: crt_makepath_s  
  Ext: .c  
```  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de Arquivos](../../c-runtime-library/file-handling.md)   
 [_fullpath, _wfullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)   
 [_splitpath_s, _wsplitpath_s](../../c-runtime-library/reference/splitpath-s-wsplitpath-s.md)   
 [_makepath, _wmakepath](../../c-runtime-library/reference/makepath-wmakepath.md)
