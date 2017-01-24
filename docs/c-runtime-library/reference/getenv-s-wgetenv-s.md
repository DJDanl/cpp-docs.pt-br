---
title: "getenv_s, _wgetenv_s | Microsoft Docs"
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
  - "getenv_s"
  - "_wgetenv_s"
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
  - "getenv_s"
  - "_tgetenv_s"
  - "_wgetenv_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tgetenv_s"
  - "Função _wgetenv_s"
  - "variáveis de ambiente"
  - "Função getenv_s"
  - "Função tgetenv_s"
  - "Função wgetenv_s"
ms.assetid: c3ae1ffe-d4cd-4bae-bcb1-3afa754c613a
caps.latest.revision: 42
caps.handback.revision: 40
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# getenv_s, _wgetenv_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém um valor do ambiente atual.  Essas versões do [getenv, \_wgetenv](../../c-runtime-library/reference/getenv-wgetenv.md) tem aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
> [!IMPORTANT]
>  Essa API não pode ser usada em aplicativos executados no [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  Para obter mais informações, consulte [Funções de CRT sem suporte com \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
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
  
#### Parâmetros  
 `pReturnValue`  
 O tamanho do buffer necessário, ou 0 se a variável não for encontrada.  
  
 `buffer`  
 Buffer para armazenar o valor da variável de ambiente.  
  
 `numberOfElements`  
 Tamanho de `buffer`.  
  
 `varname`  
 Nome da variável de ambiente.  
  
## Valor de retorno  
 Zero se tiver êxito; Caso contrário, um código de erro em caso de falha.  
  
### Condições de erro  
  
|`pReturnValue`|`buffer`|`numberOfElements`|`varname`|Valor de Retorno|  
|--------------------|--------------|------------------------|---------------|----------------------|  
|`NULL`|qualquer|qualquer|qualquer|`EINVAL`|  
|qualquer|`NULL`|\>0|qualquer|`EINVAL`|  
|qualquer|qualquer|qualquer|`NULL`|`EINVAL`|  
  
 Alguma dessas condições de erro invoca um manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, as funções definirão `errno` como `EINVAL` e retornarão `EINVAL`.  
  
 Além disso, se o buffer é muito pequeno, essas funções retornarão `ERANGE`.  Eles não chamam um manipulador de parâmetro inválido.  Gravar o tamanho do buffer necessário em `pReturnValue`, e assim habilitar programas chamar a função novamente com um buffer maior.  
  
## Comentários  
 A função `getenv_s` pesquisa `varname` na lista de variáveis de ambiente.  `getenv_s` não diferencia maiúsculas de minúsculas no sistema operacional Windows.  `getenv_s` e `_putenv_s` usar a cópia do ambiente que é apontado pela variável global `_environ` acessem o ambiente.  `getenv_s` opera somente as estruturas de dados que são acessíveis para a biblioteca de tempo de execução e não o ambiente "segmento" é criado para o processo pelo sistema operacional.  Portanto, programas que usam o `envp` argumento [principal](../Topic/main:%20Program%20Startup.md) ou [wmain](../Topic/main:%20Program%20Startup.md) pode recuperar informações inválidas.  
  
 `_wgetenv_s` é uma versão de caractere largo de `getenv_s`; o argumento e retornar o valor de `_wgetenv_s` são cadeias de caracteres largos.  A variável global `_wenviron` é uma versão de caractere largo de `_environ`.  
  
 Em um programa MBCS \(por exemplo, em um programa de ASCII SBCS\) `_wenviron` é inicialmente `NULL` porque o ambiente é composto de cadeias de caracteres multibyte.  Em seguida, na primeira chamada para `_wputenv`, ou na primeira chamada para `_wgetenv_s`, se já existir um ambiente \(MBCS\), um ambiente de cadeia de caracteres largos correspondente é criado e, em seguida, é apontado pelo `_wenviron`.  
  
 Da mesma forma em Unicode `(_wmain`\) programa, `_environ` é inicialmente `NULL` porque o ambiente é composto de cadeias de caracteres largos.  Em seguida, na primeira chamada para `_putenv`, ou na primeira chamada para `getenv_s` se já existir um ambiente \(Unicode\), um ambiente MBCS correspondente é criado e, em seguida, é apontado pelo `_environ`.  
  
 Quando duas cópias do ambiente \(MBCS e Unicode\) existem simultaneamente em um programa, o sistema de tempo de execução deve manter as duas cópias, e isso faz com que o tempo de execução mais lento.  Por exemplo, quando você chama `_putenv`, uma chamada para `_wputenv` também é executado automaticamente para que as cadeias de caracteres de dois ambiente correspondem.  
  
> [!CAUTION]
>  Em casos raros, quando o sistema de tempo de execução é manter uma versão Unicode e uma multibyte versão do ambiente, as versões de dois ambiente podem não corresponder exatamente.  Isso acontece porque, embora qualquer cadeia de caracteres multibyte exclusiva é mapeado para uma cadeia de caracteres Unicode exclusiva, o mapeamento de uma cadeia de caracteres Unicode exclusivo para uma cadeia de caracteres multibyte não é necessariamente exclusivo.  Para obter mais informações, consulte [\_environ, \_wenviron](../../c-runtime-library/environ-wenviron.md).  
  
> [!NOTE]
>  O `_putenv_s` e `_getenv_s` famílias de funções não são thread\-safe.  `_getenv_s` pode retornar um ponteiro de cadeia de caracteres ao `_putenv_s` é modificar a cadeia de caracteres e, portanto, causar falhas aleatórias.  Certifique\-se de que as chamadas para essas funções estão sincronizadas.  
  
 Em C\+\+, uso dessas funções é simplificado pela sobrecargas de modelo; as sobrecargas podem inferir automaticamente o tamanho do buffer e eliminando a necessidade de especificar um argumento de tamanho.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_tgetenv_s`|`getenv_s`|`getenv_s`|`_wgetenv_s`|  
  
 Para verificar ou alterar o valor de `TZ` uso de variável de ambiente `getenv_s`, `_putenv`, e `_tzset`, conforme necessário.  Para obter mais informações sobre `TZ`, consulte [\_tzset](../Topic/_tzset.md) e [\_daylight, \_dstbias, \_timezone e \_tzname](../../c-runtime-library/daylight-dstbias-timezone-and-tzname.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`getenv_s`|\<stdlib.h\>|  
|`_wgetenv_s`|\<stdlib.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
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
  
  **Variável LIB original é: c:\\vctools\\lib;c:\\vctools\\atlmfc\\lib;c:\\vctools\\PlatformSDK\\lib;c:\\vctools\\Visual Studio SDKs\\DIA Sdk\\lib; c:\\vctools\\Visual Studio SDKs\\BSC Sdk\\lib**  
**Nova variável LIB é: c:\\mylib;c:\\yourlib**   
## Equivalência do .NET Framework  
 [System::Environment::GetEnvironmentVariable](https://msdn.microsoft.com/en-us/library/system.environment.getenvironmentvariable.aspx)  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [Constantes ambientais](../../c-runtime-library/environmental-constants.md)   
 [\_putenv, \_wputenv](../../c-runtime-library/reference/putenv-wputenv.md)   
 [\_dupenv\_s, \_wdupenv\_s](../../c-runtime-library/reference/dupenv-s-wdupenv-s.md)