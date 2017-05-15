---
title: _searchenv_s, _wsearchenv_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _wsearchenv_s
- _searchenv_s
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
- api-ms-win-crt-environment-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _searchenv_s
- _wsearchenv_s
- wsearchenv_s
- searchenv_s
dev_langs:
- C++
helpviewer_keywords:
- tsearchenv_s function
- files [C++], finding
- buffers [C++], buffer overruns
- environment paths, searching for files
- wsearchenv_s function
- searchenv_s function
- _tsearchenv_s function
- buffer overruns
- buffers [C++], avoiding overruns
- _wsearchenv_s function
- _searchenv_s function
- environment paths
ms.assetid: 47f9fc29-250e-4c09-b52e-9e9f0ef395ca
caps.latest.revision: 32
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
ms.openlocfilehash: 3b7b1d4165edb3a7e34cda665de195759784eedc
ms.contentlocale: pt-br
ms.lasthandoff: 04/04/2017

---
# <a name="searchenvs-wsearchenvs"></a>_searchenv_s, _wsearchenv_s
Pesquisa por um arquivo usando caminhos de ambiente. Estas versões de [_searchenv, _wsearchenv](../../c-runtime-library/reference/searchenv-wsearchenv.md) têm aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t _searchenv_s(  
   const char *filename,  
   const char *varname,  
   char *pathname,  
   size_t numberOfElements  
);  
errno_t _wsearchenv_s(  
   const wchar_t *filename,  
   const wchar_t *varname,  
   wchar_t *pathname,  
   size_t numberOfElements  
);  
template <size_t size>  
errno_t _searchenv_s(  
   const char *filename,  
   const char *varname,  
   char (&pathname)[size]  
); // C++ only  
template <size_t size>  
errno_t _wsearchenv_s(  
   const wchar_t *filename,  
   const wchar_t *varname,  
   wchar_t (&pathname)[size]  
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 [in] `filename`  
 O nome de arquivo a ser pesquisado.  
  
 [in] `varname`  
 O ambiente a pesquisar.  
  
 [out] `pathname`  
 O buffer para armazenar o caminho completo.  
  
 [in] `numberOfElements`  
 Tamanho do `pathname` buffer.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido; um código de erro em caso de falha.  
  
 Se `filename` for uma cadeia de caracteres vazia, o valor retornado será `ENOENT`.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`filename`|`varname`|`pathname`|`numberOfElements`|Valor retornado|Conteúdo de `pathname`|  
|----------------|---------------|----------------|------------------------|------------------|----------------------------|  
|qualquer|qualquer|`NULL`|qualquer|`EINVAL`|N/D|  
|`NULL`|qualquer|qualquer|qualquer|`EINVAL`|não alterado|  
|qualquer|qualquer|qualquer|<= 0|`EINVAL`|não alterado|  
  
 Se qualquer uma dessas condições de erro ocorrer, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 A rotina `_searchenv_s` pesquisará pelo arquivo de destino no domínio especificado. A variável `varname` pode ser qualquer ambiente ou variável definida pelo usuário que especifica uma lista de caminhos de diretório, por exemplo, `PATH`, `LIB` e `INCLUDE`. Já que `_searchenv_s` diferencia maiúsculas de minúsculas, o uso de maiúsculas e minúsculas em `varname` deve corresponder àquele encontrado na variável de ambiente. Se `varname` não corresponder ao nome de uma variável de ambiente definida no ambiente do processo, a função retornará zero e a variável `pathname` permanecerá inalterada.  
  
 A rotina pesquisa pelo arquivo primeiramente no diretório de trabalho atual. Se não encontrar o arquivo, ela procurará em seguida nos diretórios especificados pela variável de ambiente. Se o arquivo de destino estiver em um desses diretórios, o caminho criado recentemente será copiado para `pathname`. Se o arquivo `filename` não for encontrado, `pathname` conterá uma cadeia de caracteres vazia terminada em nulo.  
  
 O buffer `pathname` deve ter pelo menos `_MAX_PATH` caracteres para acomodar o comprimento total do nome do caminho criado. Caso contrário, `_searchenv_s` poderia causar um estouro de buffer `pathname`, resultando em um comportamento inesperado.  
  
 `_wsearchenv_s` é uma versão de caractere largo de `_searchenv_s`; os argumentos para `_wsearchenv_s` são cadeias de caracteres largas. Caso contrário, `_wsearchenv_s` e `_searchenv_s` se comportam de forma idêntica.  
  
 Em C++, o uso dessas funções é simplificado pelas sobrecargas de modelo; as sobrecargas podem inferir o tamanho do buffer automaticamente (eliminando a necessidade de especificar um argumento de tamanho) e podem substituir automaticamente funções mais antigas e não seguras por suas equivalentes mais recentes e seguras. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|--------------------------------------|--------------------|-----------------------|  
|`_tsearchenv_s`|`_searchenv_s`|`_searchenv_s`|`_wsearchenv_s`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_searchenv_s`|\<stdlib.h>|  
|`_wsearchenv_s`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_searchenv_s.c  
/* This program searches for a file in  
 * a directory specified by an environment variable.  
 */  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char pathbuffer[_MAX_PATH];  
   char searchfile[] = "CL.EXE";  
   char envvar[] = "PATH";  
   errno_t err;  
  
   /* Search for file in PATH environment variable: */  
   err = _searchenv_s( searchfile, envvar, pathbuffer, _MAX_PATH );  
   if (err != 0)  
   {  
      printf("Error searching the path. Error code: %d\n", err);  
   }  
   if( *pathbuffer != '\0' )  
      printf( "Path for %s:\n%s\n", searchfile, pathbuffer );  
   else  
      printf( "%s not found\n", searchfile );  
}  
```  
  
```Output  
Path for CL.EXE:  
C:\Program Files\Microsoft Visual Studio 2010\VC\BIN\CL.EXE  
```  
  
## <a name="see-also"></a>Consulte também  
 [Controle de diretório](../../c-runtime-library/directory-control.md)   
 [_searchenv, _wsearchenv](../../c-runtime-library/reference/searchenv-wsearchenv.md)   
 [getenv, _wgetenv](../../c-runtime-library/reference/getenv-wgetenv.md)   
 [_putenv, _wputenv](../../c-runtime-library/reference/putenv-wputenv.md)
