---
title: getenv, _wgetenv | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- getenv
- _wgetenv
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
- _wgetenv
- getenv
- _tgetenv
dev_langs:
- C++
helpviewer_keywords:
- getenv function
- tgetenv function
- wgetenv function
- environment values
- environment variables
- _tgetenv function
- _wgetenv function
ms.assetid: 3b9cb9ab-a126-4e0e-a44f-6c5a7134daf4
caps.latest.revision: 31
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
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: 2838a1c79ad97bfd665a367b2a597cb20ac70097
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="getenv-wgetenv"></a>getenv, _wgetenv
Obtém um valor do ambiente atual. Versões mais seguras dessas funções estão disponíveis; consulte [getenv_s, _wgetenv_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [Funções de CRT sem suporte com /ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
char *getenv(   
   const char *varname   
);  
wchar_t *_wgetenv(   
   const wchar_t *varname   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `varname`  
 Nome da variável de ambiente.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para a entrada da tabela de ambiente que contém `varname`. Não é seguro modificar o valor da variável de ambiente usando o ponteiro retornado. Use a função `_putenv` para modificar o valor de uma variável de ambiente. O valor retornado será `NULL` se `varname` não for encontrado na tabela de ambiente.  
  
## <a name="remarks"></a>Comentários  
 A função `getenv` pesquisa `varname` na lista de variáveis de ambiente. `getenv` não diferencia maiúsculas de minúsculas no sistema operacional Windows. `getenv` e `_putenv` usam a cópia do ambiente apontado pela variável global `_environ` para acessar o ambiente. `getenv` funciona somente nas estruturas de dados acessíveis para a biblioteca em tempo de execução e não no "segmento" de ambiente criado para o processo pelo sistema operacional. Portanto, programas que usam o argumento `envp` para [main](../../cpp/main-program-startup.md) ou [wmain](../../cpp/main-program-startup.md) podem recuperar informações inválidas.  
  
 Se `varname` for `NULL`, a função invocará um manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essa função definirá `errno` para `EINVAL` e retornará `NULL`.  
  
 `_wgetenv` é uma versão de caractere largo de `getenv`; o argumento e o valor retornado de `_wgetenv` são cadeias de caracteres largos. A variável global `_wenviron` é uma versão de caractere largo de `_environ`.  
  
 Em um programa MBCS (por exemplo, em um programa ASCII SBCS), `_wenviron` é inicialmente `NULL` porque o ambiente é composto por cadeias de caracteres multibyte. Então, na primeira chamada para `_wputenv` ou na primeira chamada para `_wgetenv` se um ambiente (MBCS) já existir, um ambiente correspondente de cadeia de caracteres largos será criado e apontado por `_wenviron`.  
  
 De forma semelhante, em um programa Unicode (`_wmain`), `_environ` é inicialmente `NULL` porque o ambiente é composto por cadeias de caracteres largos. Então, na primeira chamada para `_putenv` ou na primeira chamada para `getenv` se um ambiente (Unicode) já existir, um ambiente MBCS correspondente será criado e apontado por `_environ`.  
  
 Quando duas cópias do ambiente (MBCS e Unicode) existirem simultaneamente em um programa, o sistema de tempo de execução deverá manter as duas cópias, fazendo com que o tempo de execução fique mais lento. Por exemplo, sempre que você chama `_putenv`, uma chamada para `_wputenv` também é executada automaticamente para que as duas cadeias de caracteres de ambiente correspondam.  
  
> [!CAUTION]
>  Em casos raros, quando o sistema de tempo de execução mantém uma versão Unicode e uma versão multibyte do ambiente, as duas versões de ambiente podem não corresponder exatamente. Isso acontece porque, embora qualquer cadeia de caracteres multibyte exclusiva seja mapeada para uma cadeia de caracteres Unicode exclusiva, o mapeamento de uma cadeia de caracteres Unicode exclusiva para uma cadeia de caracteres multibyte não é necessariamente exclusivo. Para obter mais informações, consulte [_environ, _wenviron](../../c-runtime-library/environ-wenviron.md).  
  
> [!NOTE]
>  As famílias de funções `_putenv` e `_getenv` não são thread-safe. `_getenv` poderia retornar um ponteiro de cadeia de caracteres enquanto `_putenv` está modificando a cadeia de caracteres, causando falhas aleatórias. As chamadas para essas funções devem estar sincronizadas.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_tgetenv`|`getenv`|`getenv`|`_wgetenv`|  
  
 Para verificar ou alterar o valor da variável de ambiente `TZ`, use `getenv`, `_putenv` e `_tzset`, conforme necessário. Para obter mais informações sobre `TZ`, consulte [_tzset](../../c-runtime-library/reference/tzset.md) e [_daylight, timezone e _tzname](../../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`getenv`|\<stdlib.h>|  
|`_wgetenv`|\<stdlib.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_getenv.c  
// compile with: /W3  
// This program uses getenv to retrieve  
// the LIB environment variable and then uses  
// _putenv to change it to a new value.  
  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char *libvar;  
  
   // Get the value of the LIB environment variable.  
   libvar = getenv( "LIB" ); // C4996  
   // Note: getenv is deprecated; consider using getenv_s instead  
  
   if( libvar != NULL )  
      printf( "Original LIB variable is: %s\n", libvar );  
  
   // Attempt to change path. Note that this only affects the environment  
   // variable of the current process. The command processor's  
   // environment is not changed.  
   _putenv( "LIB=c:\\mylib;c:\\yourlib" ); // C4996  
   // Note: _putenv is deprecated; consider using putenv_s instead  
  
   // Get new value.  
   libvar = getenv( "LIB" ); // C4996  
  
   if( libvar != NULL )  
      printf( "New LIB variable is: %s\n", libvar );  
}  
```  
  
```Output  
Original LIB variable is: C:\progra~1\devstu~1\vc\lib  
New LIB variable is: c:\mylib;c:\yourlib  
```  
  
## <a name="see-also"></a>Consulte também  
 [Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [_putenv, _wputenv](../../c-runtime-library/reference/putenv-wputenv.md)   
 [Constantes ambientais](../../c-runtime-library/environmental-constants.md)
