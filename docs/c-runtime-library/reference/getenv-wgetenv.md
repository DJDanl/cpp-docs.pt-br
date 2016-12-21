---
title: "getenv, _wgetenv | Microsoft Docs"
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
  - "getenv"
  - "_wgetenv"
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
  - "_wgetenv"
  - "getenv"
  - "_tgetenv"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tgetenv"
  - "Função _wgetenv"
  - "valores de ambiente"
  - "variáveis de ambiente"
  - "Função getenv"
  - "Função tgetenv"
  - "Função wgetenv"
ms.assetid: 3b9cb9ab-a126-4e0e-a44f-6c5a7134daf4
caps.latest.revision: 31
caps.handback.revision: 29
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# getenv, _wgetenv
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém um valor do ambiente atual.  Versões mais seguras dessas funções estão disponíveis; consulte [getenv\_s, \_wgetenv\_s](../../c-runtime-library/reference/getenv-s-wgetenv-s.md).  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
char *getenv(   
   const char *varname   
);  
wchar_t *_wgetenv(   
   const wchar_t *varname   
);  
```  
  
#### Parâmetros  
 `varname`  
 Nome de variável de ambiente.  
  
## Valor de retorno  
 Retorna um ponteiro para a entrada da tabela do ambiente que contém `varname`.  Não é seguro altere o valor da variável de ambiente usando o ponteiro retornado.  Use a função `_putenv` para alterar o valor de uma variável de ambiente.  O valor de retorno é `NULL` se `varname` não for localizado na tabela de ambiente.  
  
## Comentários  
 A função `getenv` procura `varname` na lista de variáveis de ambiente.  `getenv` não diferencia maiúsculas de minúsculas no sistema operacional Windows.  `getenv` e `_putenv` usam a cópia do ambiente apontado pela variável global `_environ` para acessar o ambiente.  `getenv` funciona apenas nas estruturas de dados que podem ser acessados pela biblioteca de tempo de execução e não no ambiente “bucket” projetado para o processo pelo sistema operacional.  Consequentemente, os programas que usam o argumento de `envp` a [principal](../Topic/main:%20Program%20Startup.md) ou a [wmain](../Topic/main:%20Program%20Startup.md) podem recuperar informações inválidas.  
  
 Se `varname` é `NULL`, essa função invoca um manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará `NULL`.  
  
 `_wgetenv` é uma versão de ampla caractere de `getenv`; o argumento e o valor de retorno de `_wgetenv` são cadeias de caracteres de ampla caractere.  A variável global `_wenviron` é uma versão de caractere largo de `_environ`.  
  
 Em um programa de MBCS \(por exemplo, em um programa de SBCS ASCII\), `_wenviron` é inicialmente `NULL` porque o ambiente é composto de cadeias de caracteres de multibyte\- caractere.  Em seguida, na primeira chamada a `_wputenv`, ou na primeira chamada a `_wgetenv` se um ambiente de MBCS \(\) já existir, um ambiente correspondente da cadeia de caracteres de ampla caractere é criado e apontado por `_wenviron`.  
  
 De maneira semelhante em um programa Unicode \(`_wmain`\), `_environ` é inicialmente `NULL` porque o ambiente é composto de cadeias de caracteres de ampla caractere.  Em seguida, na primeira chamada a `_putenv`, ou na primeira chamada a `getenv` se o ambiente de \(Unicode\) já existir, um ambiente correspondente de MBCS é criado e apontado por `_environ`.  
  
 Quando duas cópias de ambiente \(MBCS e Unicode\) existem simultaneamente em um programa, o sistema de tempo de execução deve manter as duas cópias, resultando em tempos de execução mais lentos.  Por exemplo, sempre que chama `_putenv`, uma chamada a `_wputenv` também é executado automaticamente, de modo que as duas cadeias de caracteres de ambiente correspondam.  
  
> [!CAUTION]
>  Em poucas instâncias, quando o sistema de tempo de execução está mantendo uma versão Unicode e uma versão multibyte de ambiente, essas versões de dois ambientes podem não corresponder exatamente.  Isso ocorre porque, embora nenhum mapas exclusivos da cadeia de caracteres de multibyte\- caracteres em uma cadeia de caracteres exclusiva Unicode, o mapeamento de uma cadeia de caracteres Unicode exclusivo em uma cadeia de caracteres de multibyte\- caractere não são necessariamente exclusivos.  Para obter mais informações, consulte [\_environ, \_wenviron](../../c-runtime-library/environ-wenviron.md).  
  
> [!NOTE]
>  As famílias de funções `_putenv` e `_getenv` não são thread\-safe.  `_getenv` pode retornar um ponteiro de cadeia de caracteres quando `_putenv` está modificando a cadeia de caracteres, causando falhas aleatórios.  Certifique\-se de que as chamadas para essas funções sejam sincronizadas.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tgetenv`|`getenv`|`getenv`|`_wgetenv`|  
  
 Para verificar como REQUIRED ou altere o valor da variável de ambiente de `TZ` , use `getenv`, de `_putenv` e de `_tzset` .  Para obter mais informações sobre como `TZ`, consulte [\_tzset](../Topic/_tzset.md) e [\_daylight, fuso horário, e \_tzname](../../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`getenv`|\<stdlib.h\>|  
|`_wgetenv`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
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
  
  **A variável original de LIBERAL é: C:\\progra~1\\devstu~1\\vc\\lib**  
**A nova variável de LIBERAL é: c:\\mylib;c:\\yourlib**   
## Equivalência do .NET Framework  
 [System::Environment::GetEnvironmentVariable](https://msdn.microsoft.com/en-us/library/system.environment.getenvironmentvariable.aspx)  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [\_putenv, \_wputenv](../../c-runtime-library/reference/putenv-wputenv.md)   
 [Constantes ambientais](../../c-runtime-library/environmental-constants.md)