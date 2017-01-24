---
title: "_configthreadlocale | Microsoft Docs"
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
  - "_configthreadlocale"
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
  - "api-ms-win-crt-locale-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_configthreadlocale"
  - "configthreadlocale"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _configthreadlocale"
  - "Função configthreadlocale"
  - "localidades, por thread"
  - "de acordo com a localidade do thread"
  - "localidade do thread"
ms.assetid: 10e4050e-b587-4f30-80bc-6c76b35fc770
caps.latest.revision: 24
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _configthreadlocale
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Configura as opções de localidade por thread.  
  
## Sintaxe  
  
```  
int _configthreadlocale(  
   int type  
);  
```  
  
#### Parâmetros  
 `type`  
 A opção a ser definida.  Uma das opções listadas na tabela a seguir.  
  
## Valor de retorno  
 O status anterior da localidade por thread \(`_DISABLE_PER_THREAD_LOCALE` ou `_ENABLE_PER_THREAD_LOCALE`\), ou \-1 em caso de falha.  
  
## Comentários  
 A função `_configurethreadlocale` é usada para controlar o uso de locais específicos do thread.  Use uma dessas opções para especificar ou determinar o status de localidade por thread:  
  
 `_ENABLE_PER_THREAD_LOCALE`  
 Faça o segmento atual usar uma localidade específica de segmento.  As chamadas subsequentes para `setlocale` nesse thread afetam somente o próprio local do thread.  
  
 `_DISABLE_PER_THREAD_LOCALE`  
 Faça o segmento atual usar a localidade global.  As chamadas subsequentes para `setlocale` nesse thread afetam outros threads que usam o local global.  
  
 `0`  
 Recupera a configuração atual para este thread específico.  
  
 Essas funções afetam o comportamento de `setlocale`, `_tsetlocale`, `_wsetlocale`, `_beginthread` e `_beginthreadex`.  Se outro método for usado para criar segmentos, as configurações de localidade não terão efeito nos segmentos.  
  
 Quando a localidade por thread é desativada, todas as chamadas subsequentes para `setlocale` ou para `_wsetlocale` alteram a localidade de todos os threads.  Quando a localidade por thread é ativada, `setlocale` ou `_wsetlocale` afeta somente a localidade do thread atual.  
  
 Se você usar `_configurethreadlocale` para ativar uma localidade por segmento, recomendamos que você chame `setlocale` ou `_wsetlocale` para definir o local preferido nesse segmento imediatamente depois.  
  
 Se `type` não for um dos valores listados na tabela, essa função chama o manipulador de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essa função definirá `errno` como `EINVAL` e retornará \-1.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_configthreadlocale`|\<locale.h\>|  
  
## Exemplo  
  
```  
// crt_configthreadlocale.cpp  
//   
// This program demonstrates the use of _configthreadlocale when  
// using is two independent threads.  
//  
  
#include <locale.h>  
#include <process.h>  
#include <windows.h>  
#include <stdio.h>  
#include <time.h>  
  
#define BUFF_SIZE 100  
  
// Retrieve the date and time in the current  
// locale's format.  
int get_time(unsigned char* str)  
{  
    __time64_t  ltime;  
    struct tm   thetime;  
  
    // Retieve the time  
    _time64(&ltime);  
    _gmtime64_s(&thetime, &ltime);  
  
    // Format the current time structure into a string  
    // using %#x is the long date representation,  
    // appropriate to the current locale  
    if (!strftime((char *)str, BUFF_SIZE, "%#x",   
                  (const struct tm*)&thetime))  
    {  
        printf("strftime failed!\n");  
        return -1;  
    }  
    return 0;  
}  
  
// This thread sets its locale to German  
// and prints the time.  
unsigned __stdcall SecondThreadFunc( void* pArguments )  
{  
    unsigned char str[BUFF_SIZE];  
  
    // Set the thread code page  
    _setmbcp(_MB_CP_ANSI)  
  
    // Set the thread locale  
    printf("The thread locale is now set to %s.\n",  
           setlocale(LC_ALL, "German"));  
  
    // Retrieve the time string from the helper function  
    if (get_time(str) == 0)  
    {  
        printf("The time in German locale is: '%s'\n", str);  
    }  
  
    _endthreadex( 0 );  
    return 0;  
}   
  
// The main thread spawns a second thread (above) and then  
// sets the locale to English and prints the time.  
int main()  
{   
    HANDLE          hThread;  
    unsigned        threadID;  
    unsigned char   str[BUFF_SIZE];  
  
    // Configure per-thread locale to cause all subsequently created   
    // threads to have their own locale.  
    _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);  
  
    // Retrieve the time string from the helper function  
    printf("The thread locale is now set to %s.\n",  
           setlocale(LC_ALL, "English"));  
  
    // Create the second thread.  
    hThread = (HANDLE)_beginthreadex( NULL, 0, &SecondThreadFunc,  
                                      NULL, 0, &threadID );  
  
    if (get_time(str) == 0)  
    {  
        // Retrieve the time string from the helper function  
        printf("The time in English locale is: '%s'\n\n", str);  
    }  
  
    // Wait for the created thread to finish.  
    WaitForSingleObject( hThread, INFINITE );  
  
    // Destroy the thread object.  
    CloseHandle( hThread );  
}  
```  
  
  **A localidade do thread agora está definida para Inglês\_Estados Unidos.1252.**  
**O tempo na localidade Inglês é: 'Wednesday, May 12, 2004'**  
**A localidade do thread agora está definida para Alemão\_Alemanha.1252.**  
**O tempo na localidade Alemão é 'Mittwock, 12.  Maio de 2004 '**    
## Equivalência do .NET Framework  
 Não aplicável. No entanto, consulte [Usando a propriedade CurrentCulture](http://msdn.microsoft.com/pt-br/3156042d-6082-4205-90b4-c917ae6a3ba6).  
  
## Consulte também  
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)   
 [\_beginthread, \_beginthreadex](../Topic/_beginthread,%20_beginthreadex.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Multithread e localidades](../../parallel/multithreading-and-locales.md)