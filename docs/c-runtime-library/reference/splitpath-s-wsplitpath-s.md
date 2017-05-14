---
title: _splitpath_s, _wsplitpath_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wsplitpath_s
- _splitpath_s
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
- _wsplitpath_s
- splitpath_s
- _splitpath_s
- wsplitpath_s
dev_langs:
- C++
helpviewer_keywords:
- splitpath_s function
- pathnames
- _splitpath_s function
- _wsplitpath_s function
- path names
- wsplitpath_s function
ms.assetid: 30fff3e2-cd00-4eb6-b5a2-65db79cb688b
caps.latest.revision: 29
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: a82768750e6a7837bb81edd8a51847f83c294c20
ms.openlocfilehash: c4c6803731deba188a4f4dba118b04f626f58564
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="splitpaths-wsplitpaths"></a>_splitpath_s, _wsplitpath_s
Divide um nome de caminho em componentes. Estas são versões de [_splitpath, _wsplitpath](../../c-runtime-library/reference/splitpath-wsplitpath.md) com aprimoramentos de segurança, conforme descrito em [Recursos de Segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _splitpath_s(  
   const char * path,  
   char * drive,  
   size_t driveNumberOfElements,  
   char * dir,  
   size_t dirNumberOfElements,  
   char * fname,  
   size_t nameNumberOfElements,  
   char * ext,   
   size_t extNumberOfElements  
);  
errno_t _wsplitpath_s(  
   const wchar_t * path,  
   wchar_t * drive,  
   size_t driveNumberOfElements,  
   wchar_t *dir,  
   size_t dirNumberOfElements,  
   wchar_t * fname,  
   size_t nameNumberOfElements,  
   wchar_t * ext,  
   size_t extNumberOfElements  
);  
template <size_t drivesize, size_t dirsize, size_t fnamesize, size_t extsize>  
errno_t _splitpath_s(  
   const char *path,  
   char (&drive)[drivesize],  
   char (&dir)[dirsize],  
   char (&fname)[fnamesize],  
   char (&ext)[extsize]  
); // C++ only  
template <size_t drivesize, size_t dirsize, size_t fnamesize, size_t extsize>  
errno_t _wsplitpath_s(  
   const wchar_t *path,  
   wchar_t (&drive)[drivesize],  
   wchar_t (&dir)[dirsize],  
   wchar_t (&fname)[fnamesize],  
   wchar_t (&ext)[extsize]  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `path`  
 Caminho completo.  
  
 [out] `drive`  
 Letra da unidade, seguida por dois pontos (`:`). Você pode passar `NULL` para esse parâmetro se a letra da unidade não é necessária.  
  
 [in] `driveNumberOfElements`  
 O tamanho do buffer `drive` em caracteres de byte único ou largos. Se `drive` é `NULL`, esse valor deve ser 0.  
  
 [out] `dir`  
 Caminho do diretório, incluindo barra à direita. Barras duplas (`/`), barras invertidas (`\`) ou ambas podem ser usadas. Você pode passar `NULL` para esse parâmetro se o caminho do diretório não é necessário.  
  
 [in] `dirNumberOfElements`  
 O tamanho do buffer `dir` em caracteres de byte único ou largos. Se `dir` é `NULL`, esse valor deve ser 0.  
  
 [out] `fname`  
 Nome de arquivo base (sem extensão). Você pode passar `NULL` para esse parâmetro se o nome de arquivo não é necessário.  
  
 [in] `nameNumberOfElements`  
 O tamanho do buffer `fname` em caracteres de byte único ou largos. Se `fname` é `NULL`, esse valor deve ser 0.  
  
 [out] `ext`  
 Extensão de nome de arquivo, incluindo ponto à esquerda (**.**). Você pode passar `NULL` para esse parâmetro se a extensão do nome do arquivo não é necessária.  
  
 [in] `extNumberOfElements`  
 O tamanho do buffer `ext` em caracteres de byte único ou largos. Se `ext` é `NULL`, esse valor deve ser 0.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido; um código de erro em caso de falha.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|Condição|Valor de retorno|  
|---------------|------------------|  
|`path` é `NULL`|`EINVAL`|  
|`drive` é `NULL`, `driveNumberOfElements` é diferente de zero|`EINVAL`|  
|`drive` é diferente de `NULL`, `driveNumberOfElements` é zero|`EINVAL`|  
|`dir` é `NULL`, `dirNumberOfElements` é diferente de zero|`EINVAL`|  
|`dir` é diferente de `NULL`, `dirNumberOfElements` é zero|`EINVAL`|  
|`fname` é `NULL`, `nameNumberOfElements` é diferente de zero|`EINVAL`|  
|`fname` é diferente de `NULL`, `nameNumberOfElements` é zero|`EINVAL`|  
|`ext` é `NULL`, `extNumberOfElements` é diferente de zero|`EINVAL`|  
|`ext` é diferente de `NULL`, `extNumberOfElements` é zero|`EINVAL`|  
  
 Se qualquer uma das condições acima ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.  
  
 Se qualquer um dos buffers é curto demais para conter o resultado, essas funções limpam todos os buffers para cadeias de caracteres vazias, definem `errno` como `ERANGE` e retornam `ERANGE`.  
  
## <a name="remarks"></a>Comentários  
 A função `_splitpath_s` divide um caminho em seus quatro componentes. `_splitpath_s` manipula automaticamente argumentos de cadeia de caracteres multibyte conforme apropriado, reconhecendo sequências de caracteres multibyte de acordo com a página de código multibyte que está sendo usada no momento. `_wsplitpath_s` é uma versão de caractere largo de `_splitpath_s`; os argumentos para `_``wsplitpath_s` são cadeias de caracteres largas. Caso contrário, essas funções se comportam de forma idêntica  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tsplitpath_s`|`_splitpath_s`|`_splitpath_s`|`_wsplitpath_s`|  
  
 Cada componente do caminho completo é armazenado em um buffer separado; as constantes de manifesto `_MAX_DRIVE`, `_MAX_DIR`, `_MAX_FNAME` e `_MAX_EXT` (definidas em STDLIB.H) especificam o tamanho máximo permitido para cada componente de arquivo. Componentes de arquivo maiores do que as constantes de manifesto correspondentes causam corrupção de heap.  
  
 A tabela a seguir lista os valores das constantes do manifesto.  
  
|Nome|Valor|  
|----------|-----------|  
|_MAX_DRIVE|3|  
|_MAX_DIR|256|  
|_MAX_FNAME|256|  
|_MAX_EXT|256|  
  
 Se o caminho completo não contém um componente (por exemplo, um nome de arquivo), `_splitpath_s` atribui uma cadeia de caracteres vazia ao buffer correspondente.  
  
 No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir automaticamente o tamanho do buffer, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
 As versões de depuração dessas funções preenchem primeiro o buffer com 0xFD. Para desabilitar esse comportamento, use [_CrtSetDebugFillThreshold](../../c-runtime-library/reference/crtsetdebugfillthreshold.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_splitpath_s`|\<stdlib.h>|  
|`_wsplitpath_s`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Veja o exemplo de [_makepath_s, _wmakepath_s](../../c-runtime-library/reference/makepath-s-wmakepath-s.md).  
  
## <a name="see-also"></a>Consulte também  
 [Manipulação de Arquivos](../../c-runtime-library/file-handling.md)   
 [_splitpath, _wsplitpath](../../c-runtime-library/reference/splitpath-wsplitpath.md)   
 [_fullpath, _wfullpath](../../c-runtime-library/reference/fullpath-wfullpath.md)   
 [_getmbcp](../../c-runtime-library/reference/getmbcp.md)   
 [_makepath, _wmakepath](../../c-runtime-library/reference/makepath-wmakepath.md)   
 [_setmbcp](../../c-runtime-library/reference/setmbcp.md)
