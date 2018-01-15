---
title: Multithread e localidades | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- locales [C++], multithreading
- multithreading [C++], locales
- threading [C++], locales
- per-thread locale
ms.assetid: d6fb159a-eaca-4130-a51a-f95d62f71485
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e60235bb011cb130b06a51a498cd8b5b88a56232
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="multithreading-and-locales"></a>Multithread e localidades
A biblioteca de tempo de execução do C e a biblioteca padrão C++ oferecem suporte para alterar a localidade do seu programa. Este tópico aborda problemas que surgem ao usar a funcionalidade de localidade de ambas as bibliotecas em um aplicativo multithread.  
  
## <a name="remarks"></a>Comentários  
 Com a biblioteca de tempo de execução do C, você pode criar aplicativos multithread usando o `_beginthread` e `_beginthreadex` funções. Este tópico aborda apenas aplicativos multithread criados usando estas funções. Para obter mais informações, consulte [beginthread, beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md).  
  
 Para alterar a localidade usando a biblioteca de tempo de execução C, use o [setlocale](../preprocessor/setlocale.md) função. Nas versões anteriores do Visual C++, essa função sempre deve modificar a localidade em todo o aplicativo. Agora há suporte para definir a localidade em uma base por thread. Isso é feito usando o [configthreadlocale](../c-runtime-library/reference/configthreadlocale.md) função. Para especificar que [setlocale](../preprocessor/setlocale.md) só deve alterar a localidade do thread atual, chamada `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)` nesse thread. Por outro lado, chamar `_configthreadlocale(_DISABLE_PER_THREAD_LOCALE)` fará com que esse thread para usar a localidade global e todas as chamadas de [setlocale](../preprocessor/setlocale.md) nesse thread irá alterar a localidade em todos os threads que não tenha habilitado explicitamente localidade por thread.  
  
 Para alterar a localidade usando a biblioteca de tempo de execução C++, use o [classe locale](../standard-library/locale-class.md). Chamando o [Locale:: global](../standard-library/locale-class.md#global) método, você alterar a localidade em cada thread que não tenha habilitado explicitamente localidade por thread. Para alterar a localidade em um único thread ou parte de um aplicativo, basta criar uma instância de um `locale` objeto no thread ou parte do código.  
  
> [!NOTE]
>  Chamando [Locale:: global](../standard-library/locale-class.md#global) altera a localidade para a biblioteca padrão C++ e a biblioteca de tempo de execução C. No entanto, chamar [setlocale](../preprocessor/setlocale.md) altera apenas a localidade para a biblioteca de tempo de execução C; a biblioteca padrão C++ não é afetado.  
  
 Os exemplos a seguir mostram como usar o [setlocale](../preprocessor/setlocale.md) função, o [classe locale](../standard-library/locale-class.md)e o [configthreadlocale](../c-runtime-library/reference/configthreadlocale.md) função para alterar a localidade de um aplicativo vários cenários diferentes.  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, o thread principal gera dois threads de filho. O primeiro thread, A, permite que a localidade por thread chamando `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)`. O thread de segundo, o Thread B, bem como o thread principal, não habilite a localidade por thread. Thread de um, em seguida, prossegue para alterar a localidade usando o [setlocale](../preprocessor/setlocale.md) função da biblioteca de tempo de execução do C.  
  
 Desde que o Thread A tem localidade por thread habilitada, somente as funções de biblioteca de tempo de execução C no início de Thread A usando a localidade "França". As funções de biblioteca de tempo de execução C no Thread B e no thread principal continuam a usar a localidade "C". Além disso, como [setlocale](../preprocessor/setlocale.md) não afeta a localidade de biblioteca padrão C++, todos os biblioteca padrão C++ objetos continuam a usar a localidade "C".  
  
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
  
```Output  
[Thread A] Per-thread locale is enabled.  
[Thread A] CRT locale is set to "French_France.1252"  
[Thread A] locale::global is set to "C"  
  
[Thread B] Per-thread locale is NOT enabled.  
[Thread B] CRT locale is set to "C"  
[Thread B] locale::global is set to "C"  
  
[Thread main] Per-thread locale is NOT enabled.  
[Thread main] CRT locale is set to "C"  
[Thread main] locale::global is set to "C"  
```  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, o thread principal gera dois threads de filho. O primeiro thread, A, permite que a localidade por thread chamando `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)`. O thread de segundo, o Thread B, bem como o thread principal, não habilite a localidade por thread. Thread de um, em seguida, prossegue para alterar a localidade usando o [Locale:: global](../standard-library/locale-class.md#global) método da biblioteca C++ padrão.  
  
 Desde que o Thread A tem localidade por thread habilitada, somente as funções de biblioteca de tempo de execução C no início de Thread A usando a localidade "França". As funções de biblioteca de tempo de execução C no Thread B e no thread principal continuam a usar a localidade "C". No entanto, como o [Locale:: global](../standard-library/locale-class.md#global) método altera a localidade "global", todos os objetos de biblioteca padrão C++ em todos os threads iniciar usando a localidade "França".  
  
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
  
```Output  
[Thread A] Per-thread locale is enabled.  
[Thread A] CRT locale is set to "French_France.1252"  
[Thread A] locale::global is set to "French_France.1252"  
  
[Thread B] Per-thread locale is NOT enabled.  
[Thread B] CRT locale is set to "C"  
[Thread B] locale::global is set to "French_France.1252"  
  
[Thread main] Per-thread locale is NOT enabled.  
[Thread main] CRT locale is set to "C"  
[Thread main] locale::global is set to "French_France.1252"  
```  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, o thread principal gera dois threads de filho. O primeiro thread, A, permite que a localidade por thread chamando `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)`. O thread de segundo, o Thread B, bem como o thread principal, não habilite a localidade por thread. O thread B, em seguida, prossegue para alterar a localidade usando o [setlocale](../preprocessor/setlocale.md) função da biblioteca de tempo de execução do C.  
  
 Desde que o Thread B não tiver habilitada a localidade por thread, as funções de biblioteca de tempo de execução C no Thread B e no thread principal iniciar usando a localidade "França". As funções de biblioteca de tempo de execução do C em continuar Thread A usar a localidade "C", porque o Thread A tem localidade por thread habilitada. Além disso, como [setlocale](../preprocessor/setlocale.md) não afeta a localidade de biblioteca padrão C++, todos os biblioteca padrão C++ objetos continuam a usar a localidade "C".  
  
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
  
```Output  
[Thread B] Per-thread locale is NOT enabled.  
[Thread B] CRT locale is set to "French_France.1252"  
[Thread B] locale::global is set to "C"  
  
[Thread A] Per-thread locale is enabled.  
[Thread A] CRT locale is set to "C"  
[Thread A] locale::global is set to "C"  
  
[Thread main] Per-thread locale is NOT enabled.  
[Thread main] CRT locale is set to "French_France.1252"  
[Thread main] locale::global is set to "C"  
```  
  
## <a name="example"></a>Exemplo  
 Neste exemplo, o thread principal gera dois threads de filho. O primeiro thread, A, permite que a localidade por thread chamando `_configthreadlocale(_ENABLE_PER_THREAD_LOCALE)`. O thread de segundo, o Thread B, bem como o thread principal, não habilite a localidade por thread. O thread B, em seguida, prossegue para alterar a localidade usando o [Locale:: global](../standard-library/locale-class.md#global) método da biblioteca C++ padrão.  
  
 Desde que o Thread B não tiver habilitada a localidade por thread, as funções de biblioteca de tempo de execução C no Thread B e no thread principal iniciar usando a localidade "França". As funções de biblioteca de tempo de execução do C em continuar Thread A usar a localidade "C", porque o Thread A tem localidade por thread habilitada. No entanto, como o [Locale:: global](../standard-library/locale-class.md#global) método altera a localidade "global", todos os objetos de biblioteca padrão C++ em todos os threads iniciar usando a localidade "França".  
  
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
  
```Output  
[Thread B] Per-thread locale is NOT enabled.  
[Thread B] CRT locale is set to "French_France.1252"  
[Thread B] locale::global is set to "French_France.1252"  
  
[Thread A] Per-thread locale is enabled.  
[Thread A] CRT locale is set to "C"  
[Thread A] locale::global is set to "French_France.1252"  
  
[Thread main] Per-thread locale is NOT enabled.  
[Thread main] CRT locale is set to "French_France.1252"  
[Thread main] locale::global is set to "French_France.1252"  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte multithread para código anterior (Visual C++)](../parallel/multithreading-support-for-older-code-visual-cpp.md)   
 [_beginthread, _beginthreadex](../c-runtime-library/reference/beginthread-beginthreadex.md)   
 [_configthreadlocale](../c-runtime-library/reference/configthreadlocale.md)   
 [setlocale](../preprocessor/setlocale.md)   
 [Internacionalização](../c-runtime-library/internationalization.md)   
 [Localidade](../c-runtime-library/locale.md)   
 [\<clocale >](../standard-library/clocale.md)   
 [\<locale>](../standard-library/locale.md)   
 [Classe locale](../standard-library/locale-class.md)