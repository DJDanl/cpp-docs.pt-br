---
title: getenv_s, _wgetenv_s | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- getenv_s
- _wgetenv_s
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
- getenv_s
- _tgetenv_s
- _wgetenv_s
dev_langs:
- C++
helpviewer_keywords:
- _tgetenv_s function
- wgetenv_s function
- _wgetenv_s function
- getenv_s function
- environment variables
- tgetenv_s function
ms.assetid: c3ae1ffe-d4cd-4bae-bcb1-3afa754c613a
caps.latest.revision: 42
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
ms.sourcegitcommit: 1a00023e4d3e31ddb6381e90a50231449b1de18d
ms.openlocfilehash: de79cb66e33564f321dd3277528d67a8d7e0ddc0
ms.contentlocale: pt-br
ms.lasthandoff: 02/28/2017

---
# <a name="getenvs-wgetenvs"></a>getenv_s, _wgetenv_s
Obtém um valor do ambiente atual. Estas versões de [getenv, _wgetenv](../../c-runtime-library/reference/getenv-wgetenv.md) têm melhorias de segurança, conforme descrito em [Recursos de segurança no CRT](../../c-runtime-library/security-features-in-the-crt.md).  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)]. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
errno_t getenv_s(   
   size_t *pReturnValue,  
   char* buffer,  
   size_t numberOfElements,  
   const char *varname   
);  
errno_t _wgetenv_s(   
   size_t *pReturnValue,  
   wchar_t *buffer,  
   size_t numberOfElements,  
   const wchar_t *varname   
);  
template <size_t size>  
errno_t getenv_s(   
   size_t *pReturnValue,  
   char (&buffer)[size],  
   const char *varname   
); // C++ only  
template <size_t size>  
errno_t _wgetenv_s(   
   size_t *pReturnValue,  
   wchar_t (&buffer)[size],  
   const wchar_t *varname   
); // C++ only  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pReturnValue`  
 O tamanho do buffer necessário ou 0 se a variável não for encontrada.  
  
 `buffer`  
 Buffer para armazenar o valor da variável de ambiente.  
  
 `numberOfElements`  
 Tamanho de `buffer`.  
  
 `varname`  
 Nome da variável de ambiente.  
  
## <a name="return-value"></a>Valor de retorno  
 Zero se for bem-sucedido; caso contrário, um código de erro em caso de falha.  
  
### <a name="error-conditions"></a>Condições de Erro  
  
|`pReturnValue`|`buffer`|`numberOfElements`|`varname`|Valor de retorno|  
|--------------------|--------------|------------------------|---------------|------------------|  
|`NULL`|qualquer|qualquer|qualquer|`EINVAL`|  
|qualquer|`NULL`|>0|qualquer|`EINVAL`|  
|qualquer|qualquer|qualquer|`NULL`|`EINVAL`|  
  
 Qualquer uma dessas condições de erro invoca um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, as funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.  
  
 Além disso, se o buffer for muito pequeno, essas funções retornarão `ERANGE`. Elas não invocam um manipulador de parâmetro inválido. Elas gravam o tamanho do buffer necessário em `pReturnValue` e, portanto, habilitam programas a chamarem a função novamente com um buffer maior.  
  
## <a name="remarks"></a>Comentários  
 A função `getenv_s` pesquisa `varname` na lista de variáveis de ambiente. `getenv_s` não diferencia maiúsculas de minúsculas no sistema operacional Windows. `getenv_s` e `_putenv_s` usam a cópia do ambiente apontado pela variável global `_environ` para acessar o ambiente. `getenv_s` funciona somente nas estruturas de dados que são acessíveis para a biblioteca em tempo de execução e não no "segmento" de ambiente que é criado para o processo pelo sistema operacional. Portanto, programas que usam o argumento `envp` para [main](../../cpp/main-program-startup.md) ou [wmain](../../cpp/main-program-startup.md) podem recuperar informações inválidas.  
  
 `_wgetenv_s` é uma versão de caractere largo de `getenv_s`; o argumento e o valor retornado de `_wgetenv_s` são cadeias de caracteres largos. A variável global `_wenviron` é uma versão de caractere largo de `_environ`.  
  
 Em um programa MBCS (por exemplo, em um programa ASCII SBCS), `_wenviron` é inicialmente `NULL` porque o ambiente é composto por cadeias de caracteres multibyte. Então, na primeira chamada para `_wputenv` ou na primeira chamada para `_wgetenv_s` se um ambiente (MBCS) já existir, um ambiente correspondente de cadeia de caracteres largos será criado e apontado por `_wenviron`.  
  
 De forma semelhante, em um programa Unicode (`(_wmain`), `_environ` é inicialmente `NULL` porque o ambiente é composto por cadeias de caracteres largos. Então, na primeira chamada para `_putenv` ou na primeira chamada para `getenv_s` se um ambiente (Unicode) já existir, um ambiente MBCS correspondente será criado e apontado por `_environ`.  
  
 Quando duas cópias do ambiente (MBCS e Unicode) existirem simultaneamente em um programa, o sistema de tempo de execução deverá manter as duas cópias e isso faz com que o tempo de execução fique mais lento. Por exemplo, quando você chama `_putenv`, uma chamada para `_wputenv` também é executada automaticamente para que as duas cadeias de caracteres de ambiente correspondam.  
  
> [!CAUTION]
>  Em casos raros, quando o sistema de tempo de execução mantém uma versão Unicode e uma versão multibyte do ambiente, as duas versões de ambiente podem não corresponder exatamente. Isso acontece porque, embora qualquer cadeia de caracteres multibyte exclusiva seja mapeada para uma cadeia de caracteres Unicode exclusiva, o mapeamento de uma cadeia de caracteres Unicode exclusiva para uma cadeia de caracteres multibyte não é necessariamente exclusivo. Para obter mais informações, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).  
  
> [!NOTE]
>  As famílias de funções `_putenv_s` e `_getenv_s` não são thread-safe. `_getenv_s` poderia retornar um ponteiro de cadeia de caracteres enquanto `_putenv_s` está modificando a cadeia de caracteres e, portanto, causar falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.  
  
 No C++, o uso dessas funções é simplificado por sobrecargas de modelo. As sobrecargas podem inferir o tamanho do buffer automaticamente, eliminando a necessidade de especificar um argumento de tamanho. Para obter mais informações, consulte [Sobrecargas de modelo seguro](../../c-runtime-library/secure-template-overloads.md).  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tgetenv_s`|`getenv_s`|`getenv_s`|`_wgetenv_s`|  
  
 Para verificar ou alterar o valor da variável de ambiente `TZ`, use `getenv_s`, `_putenv` e `_tzset`, conforme necessário. Para obter mais informações sobre `TZ`, consulte [tzset](../../c-runtime-library/reference/tzset.md) e [_daylight, _dstbias, _timezone e _tzname](../../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`getenv_s`|\<stdlib.h>|  
|`_wgetenv_s`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```C  
// crt_getenv_s.c  
// This program uses getenv_s to retrieve  
// the LIB environment variable and then uses  
// _putenv to change it to a new value.  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char* libvar;  
   size_t requiredSize;  
  
   getenv_s( &requiredSize, NULL, 0, "LIB");  
   if (requiredSize == 0)  
   {  
      printf("LIB doesn't exist!\n");  
      exit(1);  
   }  
  
   libvar = (char*) malloc(requiredSize * sizeof(char));  
   if (!libvar)  
   {  
      printf("Failed to allocate memory!\n");  
      exit(1);  
   }  
  
   // Get the value of the LIB environment variable.  
   getenv_s( &requiredSize, libvar, requiredSize, "LIB" );  
  
   printf( "Original LIB variable is: %s\n", libvar );  
  
   // Attempt to change path. Note that this only affects  
   // the environment variable of the current process. The command  
   // processor's environment is not changed.  
   _putenv_s( "LIB", "c:\\mylib;c:\\yourlib" );  
  
   getenv_s( &requiredSize, NULL, 0, "LIB");  
  
   libvar = (char*) realloc(libvar, requiredSize * sizeof(char));  
   if (!libvar)  
   {  
      printf("Failed to allocate memory!\n");  
      exit(1);  
   }  
  
   // Get the new value of the LIB environment variable.   
   getenv_s( &requiredSize, libvar, requiredSize, "LIB" );  
  
   printf( "New LIB variable is: %s\n", libvar );  
  
   free(libvar);  
}  
```  
  
```Output  
Original LIB variable is: c:\vctools\lib;c:\vctools\atlmfc\lib;c:\vctools\PlatformSDK\lib;c:\vctools\Visual Studio SDKs\DIA Sdk\lib;c:\vctools\Visual Studio SDKs\BSC Sdk\lib  
New LIB variable is: c:\mylib;c:\yourlib  
```  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [Constantes ambientais](../../c-runtime-library/environmental-constants.md)   
 [_putenv, _wputenv](../../c-runtime-library/reference/putenv-wputenv.md)   
 [_dupenv_s, _wdupenv_s](../../c-runtime-library/reference/dupenv-s-wdupenv-s.md)
