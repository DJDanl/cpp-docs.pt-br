---
title: Armazenamento de thread Local (TLS) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- multithreading [C++], Thread Local Storage
- TLS [C++]
- threading [C++], Thread Local Storage
- storing thread-specific data
- thread attribute
- Thread Local Storage [C++]
ms.assetid: 80801907-d792-45ca-b776-df0cf2e9f197
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a71ed98e550d9db43a42289cfb26e3daaaf68027
ms.sourcegitcommit: b92ca0b74f0b00372709e81333885750ba91f90e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/16/2018
ms.locfileid: "42538595"
---
# <a name="thread-local-storage-tls"></a>Armazenamento local de thread (TLS)
Armazenamento Local do thread (TLS) é o método pelo qual cada thread em um processo multithread determinado pode alocar locais para armazenar dados específicos de segmento. Dinamicamente dados específicos de segmento de limite (tempo de execução) são suportados por meio da API de TLS ([TlsAlloc](/windows/desktop/api/processthreadsapi/nf-processthreadsapi-tlsalloc).  Win32 e o compilador do Visual C++ agora dão suporte a dados associados estaticamente (tempo de carregamento) por thread, além da implementação da API existente.  
  
##  <a name="_core_compiler_implementation_for_tls"></a> Implementação do compilador para TLS  
 
**C++11:** o `thread_local` especificador de classe de armazenamento é a maneira recomendada para especificar o armazenamento local de thread para objetos e membros de classe. Para obter mais informações, consulte [classes de armazenamento (C++)](../cpp/storage-classes-cpp.md).  
  
O Visual C++ também fornece um atributo específico da Microsoft, [thread](../cpp/thread.md), como o modificador de classe de armazenamento estendido. Use o **declspec** palavra-chave para declarar uma **thread** variável. Por exemplo, o código a seguir declara uma variável local de thread de inteiro e a inicializa com um valor:  
  
```  
__declspec( thread ) int tls_i = 1;  
```  
  
## <a name="rules-and-limitations"></a>Regras e limitações  
 
As diretrizes a seguir devem ser observadas quando declarar estaticamente vinculado variáveis e objetos de thread local. Essas diretrizes se aplicam a ambos [thread](../cpp/thread.md)e, na maior parte também [thread_local](../cpp/storage-classes-cpp.md):  
  
- O **thread** atributo pode ser aplicado somente a definições e declarações de classe e de dados. Ele não pode ser usado em declarações ou definições de função. Por exemplo, o código a seguir gera um erro de compilador:  
  
    ```  
    __declspec( thread )void func();     // This will generate an error.  
    ```  
  
- O **thread** modificador pode ser especificado somente em itens de dados com **estático** extensão. Isso inclui objetos de dados globais (ambos **estáticos** e **extern**), objetos estáticos locais e os membros de dados estáticos de classes do C++. Objetos de dados automática não podem ser declarados com o **thread** atributo. O código a seguir gera erros de compilador:  
  
    ```  
    void func1()  
    {  
        __declspec( thread )int tls_i;            // This will generate an error.  
    }  
  
    int func2(__declspec( thread )int tls_i )    // This will generate an error.  
    {  
        return tls_i;  
    }  
    ```  
  
- As declarações e a definição de um thread de objeto local deve especificar o **thread** atributo. Por exemplo, o código a seguir gera um erro:  
  
    ```  
    #define Thread  __declspec( thread )  
    extern int tls_i;        // This will generate an error, since the  
    int __declspec( thread )tls_i;        // declaration and definition differ.  
    ```  
  
- O **thread** atributo não pode ser usado como um modificador de tipo. Por exemplo, o código a seguir gera um erro de compilador:  
  
    ```  
    char __declspec( thread ) *ch;        // Error  
    ```  
  
- Porque a declaração do C++ objetos que usam o **thread** o atributo é permitido, os dois exemplos a seguir são semanticamente equivalentes:  
  
    ```  
    __declspec( thread ) class B  
    {  
    // Code  
    } BObject;  // OK--BObject is declared thread local.  
  
    class B  
    {  
    // Code  
    };  
    __declspec( thread ) B BObject;  // OK--BObject is declared thread local.  
    ```  
  
- O endereço de um objeto de local de thread não é considerado constante, e qualquer expressão que envolva esse endereço não é considerada uma expressão constante. No C padrão, o efeito disso é proibir o uso do endereço de uma variável local de thread como um inicializador para um objeto ou ponteiro. Por exemplo, o código a seguir é sinalizado como um erro pelo compilador C:  
  
    ```  
    __declspec( thread )int tls_i;  
    int *p = &tls_i;       //This will generate an error in C.  
    ```  
  
     Essa restrição não se aplica em C++. Como C++ permite para inicialização dinâmica de todos os objetos, você pode inicializar um objeto usando uma expressão que usa o endereço de uma variável local de thread. Isso é feito exatamente como a construção de objetos de thread local. Por exemplo, o código mostrado anteriormente não gera um erro quando ele é compilado como um arquivo de origem do C++. Observe que o endereço de uma variável local de thread é válido somente quando o thread em que o endereço foi feito ainda existe.  
  
- C padrão permite a inicialização de um objeto ou variável com uma expressão que envolva uma referência a mesma, mas apenas para objetos de extensão não estática. Embora o C++ geralmente permita essa inicialização dinâmica de objetos com uma expressão que envolva uma referência a mesmo, esse tipo de inicialização não é permitido com objetos locais de thread. Por exemplo:  
  
    ```  
    __declspec( thread )int tls_i = tls_i;                // Error in C and C++   
    int j = j;                               // OK in C++, error in C  
    __declspec( thread )int tls_i = sizeof( tls_i )       // Legal in C and C++  
    ```  
  
     Observe que um `sizeof` expressão que inclui o objeto que está sendo inicializado não representa uma referência a mesma e é habilitado em C e C++.  
  
     O C++ não permite essa inicialização dinâmica de dados de thread devido a possíveis aprimoramentos futuros para o recurso de armazenamento local de thread.  
  
- Em sistemas de operacionais Windows anteriores ao Windows Vista, `__declspec`(thread) tem algumas limitações. Se uma DLL declara quaisquer dados ou objeto como `__declspec`(thread), isso pode causar uma falha de proteção se carregado dinamicamente. Depois que a DLL é carregada com [LoadLibrary](http://msdn.microsoft.com/library/windows/desktop/ms684175), ele causa falha do sistema sempre que o código faz referência a `__declspec`dados (thread). Como o espaço de variável global para um thread é alocado em tempo de execução, o tamanho desse espaço se baseia em um cálculo de requisitos do aplicativo mais os requisitos de todas as DLLs vinculadas estaticamente. Quando você usa `LoadLibrary`, você não pode estender esse espaço para permitir que as variáveis locais de thread declaradas com `__declspec`(thread). Use as APIs de TLS, tais como [TlsAlloc](http://msdn.microsoft.com/library/windows/desktop/ms686801), em sua DLL para alocar TLS, se a DLL pode ser carregada com `LoadLibrary`.  
  
## <a name="see-also"></a>Consulte também  
 
[Multithreading com C e Win32](../parallel/multithreading-with-c-and-win32.md)   