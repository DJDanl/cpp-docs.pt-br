---
title: "Multithread e localidades | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "localidades [C++], multithreading"
  - "multithreading [C++], localidades"
  - "de acordo com a localidade do thread"
  - "threading [C++], localidades"
ms.assetid: d6fb159a-eaca-4130-a51a-f95d62f71485
caps.latest.revision: 8
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Multithread e localidades
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

A biblioteca de tempo de execução C e a biblioteca padrão C\+\+ fornecem suporte para alterar a localidade do programa.  Este tópico aborda problemas que ocorrem ao usar a funcionalidade de localidade de ambas as bibliotecas em um aplicativo multi\-threaded.  
  
## Comentários  
 Com a biblioteca de tempo de execução C, você pode criar aplicativos multi\-threaded usando as funções de `_beginthread` e de `_beginthreadex` .  Este tópico abrange apenas os aplicativos multi\-threaded criados usando estas funções.  Para obter mais informações, consulte [\_beginthread, \_beginthreadex](../Topic/_beginthread,%20_beginthreadex.md).  
  
 Para alterar a localidade usando a biblioteca de tempo de execução C, use a função de [setlocale](../../preprocessor/setlocale.md) .  Em versões anteriores de [!INCLUDE[vcprvc](../../build/includes/vcprvc_md.md)], essa função deve alterar sempre a localidade durante qualquer aplicativo inteiro.  Agora existe suporte para definir a localidade em uma base por thread.  Isso é feito usando a função de [\_configthreadlocale](../../c-runtime-library/reference/configthreadlocale.md) .  Para especificar que [setlocale](../../preprocessor/setlocale.md) deve alterar apenas a localidade do thread atual, chame `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)` nesse thread.  Por outro lado, chame `_configthreadlocale(_DISABLE_PER_THREAD_LOCALE)` fará com que o thread use a localidade global, e qualquer chamada para [setlocale](../../preprocessor/setlocale.md) nesse thread alterará a localidade em todos os threads que não habilitado explicitamente a localidade do thread.  
  
 Para alterar a localidade usando a biblioteca de tempo de execução C\+\+, use [Classe locale](../../standard-library/locale-class.md).  Chamando o método de [locale::global](../Topic/locale::global.md) , modifique a localidade em cada thread que não tenha habilitado explicitamente a localidade do thread.  Para alterar a localidade em um único thread ou parte de um aplicativo, crie apenas uma instância de um objeto de `locale` nessa thread ou parte do código.  
  
> [!NOTE]
>  A chamada [locale::global](../Topic/locale::global.md) altera a localidade da biblioteca padrão C\+\+ e a biblioteca de tempo de execução C.  No entanto, chame [setlocale](../../preprocessor/setlocale.md) altera somente a localidade da biblioteca de tempo de execução C; a biblioteca padrão do C\+\+ não é afetada.  
  
 Os exemplos a seguir mostram como usar a função de [setlocale](../../preprocessor/setlocale.md) , o [Classe locale](../../standard-library/locale-class.md), e a função de [\_configthreadlocale](../../c-runtime-library/reference/configthreadlocale.md) para alterar a localidade de um aplicativo em vários cenários diferentes.  
  
## Exemplo  
 Neste exemplo, o thread principal gerencie dois threads filhos.  O primeiro thread, A threads, habilita a localidade do thread chamando `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)`.  O segundo thread, o thread B, bem como o thread principal, não habilitam a localidade do thread.  Executável continuar A seguir para alterar a localidade usando a função de [setlocale](../../preprocessor/setlocale.md) da biblioteca de tempo de execução C.  
  
 Desde que o thread A tem localidade do thread habilitada, somente as funções da biblioteca de tempo de execução C threads no início da usando a localidade francesa “”.  Funções da biblioteca de tempo de execução C no thread B e o thread principal continuam a usar a localidade de C “2.0”.  Além disso, desde que [setlocale](../../preprocessor/setlocale.md) não afeta a localidade da biblioteca padrão C\+\+, todos os objetos de biblioteca padrão do C\+\+ continuam a usar a localidade de C “2.0”.  
  
```  
// multithread_locale_1.cpp  
// compile with: /EHsc /MD  
#include <clocale>  
#include <cstdio>  
#include <locale>  
#include <process.h>  
#include <windows.h>  
  
#define NUM_THREADS 2  
using namespace std;  
  
unsigned __stdcall RunThreadA(void *params);  
unsigned __stdcall RunThreadB(void *params);  
  
BOOL localeSet = FALSE;  
HANDLE printMutex = CreateMutex(NULL, FALSE, NULL);  
  
int main()  
{  
    HANDLE threads[NUM_THREADS];  
  
    unsigned aID;  
    threads[0] = (HANDLE)_beginthreadex(  
        NULL, 0, RunThreadA, NULL, 0, &aID);  
  
    unsigned bID;  
    threads[1] = (HANDLE)_beginthreadex(  
        NULL, 0, RunThreadB, NULL, 0, &bID);  
  
    WaitForMultipleObjects(2, threads, TRUE, INFINITE);  
  
    printf_s("[Thread main] Per-thread locale is NOT enabled.\n");  
    printf_s("[Thread main] CRT locale is set to \"%s\"\n",  
        setlocale(LC_ALL, NULL));  
    printf_s("[Thread main] locale::global is set to \"%s\"\n",  
        locale().name().c_str());  
  
    CloseHandle(threads[0]);  
    CloseHandle(threads[1]);  
    CloseHandle(printMutex);  
  
    return 0;  
}  
  
unsigned __stdcall RunThreadA(void *params)  
{  
    _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);  
    setlocale(LC_ALL, "french");  
    localeSet = TRUE;  
  
    WaitForSingleObject(printMutex, INFINITE);  
    printf_s("[Thread A] Per-thread locale is enabled.\n");  
    printf_s("[Thread A] CRT locale is set to \"%s\"\n",  
        setlocale(LC_ALL, NULL));  
    printf_s("[Thread A] locale::global is set to \"%s\"\n\n",  
        locale().name().c_str());  
    ReleaseMutex(printMutex);  
  
    return 1;  
}  
  
unsigned __stdcall RunThreadB(void *params)  
{  
    while (!localeSet)  
        Sleep(100);  
  
    WaitForSingleObject(printMutex, INFINITE);  
    printf_s("[Thread B] Per-thread locale is NOT enabled.\n");  
    printf_s("[Thread B] CRT locale is set to \"%s\"\n",  
        setlocale(LC_ALL, NULL));  
    printf_s("[Thread B] locale::global is set to \"%s\"\n\n",  
        locale().name().c_str());  
    ReleaseMutex(printMutex);  
  
    return 1;  
}  
```  
  
  **\[\] Executável à localidade do thread está habilitada.**  
**\[\] Executável à localidade de CRT é definida como “French\_France.1252”**  
**\[\] Executável A locale::global é definido como “2.0” C**  
**\[\] Thread B a localidade do thread não é habilitada.**  
**\[\] Thread B a localidade de CRT é definida como “2.0” C**  
**\[\] Thread B locale::global é definido como “2.0” C**  
**\[A localidade do thread de main de thread\] não é habilitada.**  
**\[Main de thread\] a localidade de CRT é definida como “2.0” C**  
**\[Main de thread\] locale::global é definido como “2.0” C**   
## Exemplo  
 Neste exemplo, o thread principal gerencie dois threads filhos.  O primeiro thread, A threads, habilita a localidade do thread chamando `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)`.  O segundo thread, o thread B, bem como o thread principal, não habilitam a localidade do thread.  Executável continuar A seguir para alterar a localidade usando o método de [locale::global](../Topic/locale::global.md) de biblioteca padrão do C\+\+.  
  
 Desde que o thread A tem localidade do thread habilitada, somente as funções da biblioteca de tempo de execução C threads no início da usando a localidade francesa “”.  Funções da biblioteca de tempo de execução C no thread B e o thread principal continuam a usar a localidade de C “2.0”.  Entretanto, como o método de [locale::global](../Topic/locale::global.md) altera a localidade “globais”, todos os objetos da biblioteca padrão do C\+\+ em qualquer início dos threads usando a localidade francesa “”.  
  
```  
// multithread_locale_2.cpp  
// compile with: /EHsc /MD  
#include <clocale>  
#include <cstdio>  
#include <locale>  
#include <process.h>  
#include <windows.h>  
  
#define NUM_THREADS 2  
using namespace std;  
  
unsigned __stdcall RunThreadA(void *params);  
unsigned __stdcall RunThreadB(void *params);  
  
BOOL localeSet = FALSE;  
HANDLE printMutex = CreateMutex(NULL, FALSE, NULL);  
  
int main()  
{  
    HANDLE threads[NUM_THREADS];  
  
    unsigned aID;  
    threads[0] = (HANDLE)_beginthreadex(  
        NULL, 0, RunThreadA, NULL, 0, &aID);  
  
    unsigned bID;  
    threads[1] = (HANDLE)_beginthreadex(  
        NULL, 0, RunThreadB, NULL, 0, &bID);  
  
    WaitForMultipleObjects(2, threads, TRUE, INFINITE);  
  
    printf_s("[Thread main] Per-thread locale is NOT enabled.\n");  
    printf_s("[Thread main] CRT locale is set to \"%s\"\n",  
        setlocale(LC_ALL, NULL));  
    printf_s("[Thread main] locale::global is set to \"%s\"\n",  
        locale().name().c_str());  
  
    CloseHandle(threads[0]);  
    CloseHandle(threads[1]);  
    CloseHandle(printMutex);  
  
    return 0;  
}  
  
unsigned __stdcall RunThreadA(void *params)  
{  
    _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);  
    locale::global(locale("french"));  
    localeSet = TRUE;  
  
    WaitForSingleObject(printMutex, INFINITE);  
    printf_s("[Thread A] Per-thread locale is enabled.\n");  
    printf_s("[Thread A] CRT locale is set to \"%s\"\n",  
        setlocale(LC_ALL, NULL));  
    printf_s("[Thread A] locale::global is set to \"%s\"\n\n",  
        locale().name().c_str());  
    ReleaseMutex(printMutex);  
  
    return 1;  
}  
  
unsigned __stdcall RunThreadB(void *params)  
{  
    while (!localeSet)  
        Sleep(100);  
  
    WaitForSingleObject(printMutex, INFINITE);  
    printf_s("[Thread B] Per-thread locale is NOT enabled.\n");  
    printf_s("[Thread B] CRT locale is set to \"%s\"\n",  
        setlocale(LC_ALL, NULL));  
    printf_s("[Thread B] locale::global is set to \"%s\"\n\n",  
        locale().name().c_str());  
    ReleaseMutex(printMutex);  
  
    return 1;  
}  
```  
  
  **\[\] Executável à localidade do thread está habilitada.**  
**\[\] Executável à localidade de CRT é definida como “French\_France.1252”**  
**\[\] Executável A locale::global é definido como “French\_France.1252”**  
**\[\] Thread B a localidade do thread não é habilitada.**  
**\[\] Thread B a localidade de CRT é definida como “2.0” C**  
**\[\] Thread B locale::global é definido como “French\_France.1252”**  
**\[A localidade do thread de main de thread\] não é habilitada.**  
**\[Main de thread\] a localidade de CRT é definida como “2.0” C**  
**\[Main de thread\] locale::global é definido como “French\_France.1252”**   
## Exemplo  
 Neste exemplo, o thread principal gerencie dois threads filhos.  O primeiro thread, A threads, habilita a localidade do thread chamando `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)`.  O segundo thread, o thread B, bem como o thread principal, não habilitam a localidade do thread.  O thread B continue para alterar a localidade usando a função de [setlocale](../../preprocessor/setlocale.md) da biblioteca de tempo de execução C.  
  
 Desde que o thread B não tem localidade do thread habilitada, as funções da biblioteca de tempo de execução C no thread B e o thread principal começa usando a localidade francesa “”.  Funções da biblioteca de tempo de execução C threads em uma acompanhamento usar a localidade de C “2.0” porque o thread A tem localidade do thread habilitada.  Além disso, desde que [setlocale](../../preprocessor/setlocale.md) não afeta a localidade da biblioteca padrão C\+\+, todos os objetos de biblioteca padrão do C\+\+ continuam a usar a localidade de C “2.0”.  
  
```  
// multithread_locale_3.cpp  
// compile with: /EHsc /MD  
#include <clocale>  
#include <cstdio>  
#include <locale>  
#include <process.h>  
#include <windows.h>  
  
#define NUM_THREADS 2  
using namespace std;  
  
unsigned __stdcall RunThreadA(void *params);  
unsigned __stdcall RunThreadB(void *params);  
  
BOOL localeSet = FALSE;  
BOOL configThreadLocaleCalled = FALSE;  
HANDLE printMutex = CreateMutex(NULL, FALSE, NULL);  
  
int main()  
{  
    HANDLE threads[NUM_THREADS];  
  
    unsigned aID;  
    threads[0] = (HANDLE)_beginthreadex(  
        NULL, 0, RunThreadA, NULL, 0, &aID);  
  
    unsigned bID;  
    threads[1] = (HANDLE)_beginthreadex(  
        NULL, 0, RunThreadB, NULL, 0, &bID);  
  
    WaitForMultipleObjects(2, threads, TRUE, INFINITE);  
  
    printf_s("[Thread main] Per-thread locale is NOT enabled.\n");  
    printf_s("[Thread main] CRT locale is set to \"%s\"\n",  
        setlocale(LC_ALL, NULL));  
    printf_s("[Thread main] locale::global is set to \"%s\"\n",  
        locale().name().c_str());  
  
    CloseHandle(threads[0]);  
    CloseHandle(threads[1]);  
    CloseHandle(printMutex);  
  
    return 0;  
}  
  
unsigned __stdcall RunThreadA(void *params)  
{  
    _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);  
    configThreadLocaleCalled = TRUE;  
    while (!localeSet)  
        Sleep(100);  
  
    WaitForSingleObject(printMutex, INFINITE);  
    printf_s("[Thread A] Per-thread locale is enabled.\n");  
    printf_s("[Thread A] CRT locale is set to \"%s\"\n",  
        setlocale(LC_ALL, NULL));  
    printf_s("[Thread A] locale::global is set to \"%s\"\n\n",  
        locale().name().c_str());  
    ReleaseMutex(printMutex);  
  
    return 1;  
}  
  
unsigned __stdcall RunThreadB(void *params)  
{  
    while (!configThreadLocaleCalled)  
        Sleep(100);  
    setlocale(LC_ALL, "french");  
    localeSet = TRUE;  
  
    WaitForSingleObject(printMutex, INFINITE);  
    printf_s("[Thread B] Per-thread locale is NOT enabled.\n");  
    printf_s("[Thread B] CRT locale is set to \"%s\"\n",  
        setlocale(LC_ALL, NULL));  
    printf_s("[Thread B] locale::global is set to \"%s\"\n\n",  
        locale().name().c_str());  
    ReleaseMutex(printMutex);  
  
    return 1;  
}  
```  
  
  **\[\] Thread B a localidade do thread não é habilitada.**  
**\[\] Thread B a localidade de CRT é definida como “French\_France.1252”**  
**\[\] Thread B locale::global é definido como “2.0” C**  
**\[\] Executável à localidade do thread está habilitada.**  
**\[\] Executável à localidade de CRT é definida como “2.0” C**  
**\[\] Executável A locale::global é definido como “2.0” C**  
**\[A localidade do thread de main de thread\] não é habilitada.**  
**\[Main de thread\] a localidade de CRT é definida como “French\_France.1252”**  
**\[Main de thread\] locale::global é definido como “2.0” C**   
## Exemplo  
 Neste exemplo, o thread principal gerencie dois threads filhos.  O primeiro thread, A threads, habilita a localidade do thread chamando `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)`.  O segundo thread, o thread B, bem como o thread principal, não habilitam a localidade do thread.  O thread B continue para alterar a localidade usando o método de [locale::global](../Topic/locale::global.md) de biblioteca padrão do C\+\+.  
  
 Desde que o thread B não tem localidade do thread habilitada, as funções da biblioteca de tempo de execução C no thread B e o thread principal começa usando a localidade francesa “”.  Funções da biblioteca de tempo de execução C threads em uma acompanhamento usar a localidade de C “2.0” porque o thread A tem localidade do thread habilitada.  Entretanto, como o método de [locale::global](../Topic/locale::global.md) altera a localidade “globais”, todos os objetos da biblioteca padrão do C\+\+ em qualquer início dos threads usando a localidade francesa “”.  
  
```  
// multithread_locale_4.cpp  
// compile with: /EHsc /MD  
#include <clocale>  
#include <cstdio>  
#include <locale>  
#include <process.h>  
#include <windows.h>  
  
#define NUM_THREADS 2  
using namespace std;  
  
unsigned __stdcall RunThreadA(void *params);  
unsigned __stdcall RunThreadB(void *params);  
  
BOOL localeSet = FALSE;  
BOOL configThreadLocaleCalled = FALSE;  
HANDLE printMutex = CreateMutex(NULL, FALSE, NULL);  
  
int main()  
{  
    HANDLE threads[NUM_THREADS];  
  
    unsigned aID;  
    threads[0] = (HANDLE)_beginthreadex(  
        NULL, 0, RunThreadA, NULL, 0, &aID);  
  
    unsigned bID;  
    threads[1] = (HANDLE)_beginthreadex(  
        NULL, 0, RunThreadB, NULL, 0, &bID);  
  
    WaitForMultipleObjects(2, threads, TRUE, INFINITE);  
  
    printf_s("[Thread main] Per-thread locale is NOT enabled.\n");  
    printf_s("[Thread main] CRT locale is set to \"%s\"\n",  
        setlocale(LC_ALL, NULL));  
    printf_s("[Thread main] locale::global is set to \"%s\"\n",  
        locale().name().c_str());  
  
    CloseHandle(threads[0]);  
    CloseHandle(threads[1]);  
    CloseHandle(printMutex);  
  
    return 0;  
}  
  
unsigned __stdcall RunThreadA(void *params)  
{  
    _configthreadlocale(_ENABLE_PER_THREAD_LOCALE);  
    configThreadLocaleCalled = TRUE;  
    while (!localeSet)  
        Sleep(100);  
  
    WaitForSingleObject(printMutex, INFINITE);  
    printf_s("[Thread A] Per-thread locale is enabled.\n");  
    printf_s("[Thread A] CRT locale is set to \"%s\"\n",  
        setlocale(LC_ALL, NULL));  
    printf_s("[Thread A] locale::global is set to \"%s\"\n\n",  
        locale().name().c_str());  
    ReleaseMutex(printMutex);  
  
    return 1;  
}  
  
unsigned __stdcall RunThreadB(void *params)  
{  
    while (!configThreadLocaleCalled)  
        Sleep(100);  
    locale::global(locale("french"));  
    localeSet = TRUE;  
  
    WaitForSingleObject(printMutex, INFINITE);  
    printf_s("[Thread B] Per-thread locale is NOT enabled.\n");  
    printf_s("[Thread B] CRT locale is set to \"%s\"\n",  
        setlocale(LC_ALL, NULL));  
    printf_s("[Thread B] locale::global is set to \"%s\"\n\n",  
        locale().name().c_str());  
    ReleaseMutex(printMutex);  
  
    return 1;  
}  
```  
  
  **\[\] Thread B a localidade do thread não é habilitada.**  
**\[\] Thread B a localidade de CRT é definida como “French\_France.1252”**  
**\[\] Thread B locale::global é definido como “French\_France.1252”**  
**\[\] Executável à localidade do thread está habilitada.**  
**\[\] Executável à localidade de CRT é definida como “2.0” C**  
**\[\] Executável A locale::global é definido como “French\_France.1252”**  
**\[A localidade do thread de main de thread\] não é habilitada.**  
**\[Main de thread\] a localidade de CRT é definida como “French\_France.1252”**  
**\[Main de thread\] locale::global é definido como “French\_France.1252”**   
## Consulte também  
 [Suporte multithread para código anterior \(Visual C\+\+\)](../../parallel/multithreading-support-for-older-code-visual-cpp.md)   
 [\_beginthread, \_beginthreadex](../Topic/_beginthread,%20_beginthreadex.md)   
 [\_configthreadlocale](../../c-runtime-library/reference/configthreadlocale.md)   
 [setlocale](../../preprocessor/setlocale.md)   
 [Internacionalização](../../c-runtime-library/internationalization.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [\<clocale\>](../../standard-library/clocale.md)   
 [\<locale\>](../../standard-library/locale.md)   
 [Classe locale](../../standard-library/locale-class.md)