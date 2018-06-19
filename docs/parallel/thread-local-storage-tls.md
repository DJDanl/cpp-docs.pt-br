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
ms.openlocfilehash: c4cd0897a04ec2e07f1f8f3b660d092e0075ac0b
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33694544"
---
# <a name="thread-local-storage-tls"></a>Armazenamento local de thread (TLS)
Armazenamento Local da thread (TLS) é o método pelo qual cada thread em um determinado processo multithread pode alocar locais para armazenar dados específicos de segmento. Dinamicamente os dados específicos de segmento de limite (tempo de execução) são suportados por meio da API de TLS ([TlsAlloc](https://msdn.microsoft.com/en-us/library/windows/desktop/ms686801), [TlsGetValue](https://msdn.microsoft.com/en-us/library/windows/desktop/ms686812), [TlsSetValue](https://msdn.microsoft.com/en-us/library/windows/desktop/ms686818), e [TlsFree](https://msdn.microsoft.com/en-us/library/windows/desktop/ms686804)). Para obter mais informações sobre como o armazenamento local de thread é implementado no Windows, consulte [armazenamento Local de Thread (Windows)](https://msdn.microsoft.com/en-us/library/windows/desktop/ms686749\(v=vs.85\).aspx).  Win32 e do compilador Visual C++ agora dão suporte a dados estaticamente vinculado (tempo de carregamento) por thread além de implementação da API existente.  
  
##  <a name="_core_compiler_implementation_for_tls"></a> Implementação do compilador para TLS  
 **C++ 11:** o `thread_local` especificador de classe de armazenamento é a maneira recomendada para especificar o armazenamento local de thread para objetos e membros de classe. Para obter mais informações, consulte [classes de armazenamento (C++)](../cpp/storage-classes-cpp.md).  
  
 O Visual C++ também fornece um atributo específico da Microsoft, [thread](../cpp/thread.md), como o modificador de classe de armazenamento estendido. Use o `__declspec` palavra-chave para declarar um **thread** variável. Por exemplo, o código a seguir declara uma variável local de thread de inteiro e a inicializa com um valor:  
  
```  
__declspec( thread ) int tls_i = 1;  
```  
  
## <a name="rules-and-limitations"></a>Regras e limitações  
 As diretrizes a seguir devem ser observadas declarando estaticamente quando associado a objetos locais de thread e variáveis. Essas diretrizes se aplicam tanto ao [thread](../cpp/thread.md)e a maior parte também [thread_local](../cpp/storage-classes-cpp.md):  
  
-   O `thread` atributo pode ser aplicado somente a definições e declarações de classe e de dados. Ele não pode ser usado em declarações ou definições de função. Por exemplo, o código a seguir gera um erro de compilador:  
  
    ```  
  
    __declspec( thread )void func();     // This will generate an error.  
    ```  
  
-   O `thread` modificador pode ser especificado somente em itens de dados com `static` extensão. Isso inclui objetos de dados globais (ambos `static` e `extern`), locais objetos static e membros de dados estáticos de classes C++. Objetos de dados automática não podem ser declarados com o `thread` atributo. O código a seguir gera erros do compilador:  
  
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
  
-   As declarações e a definição de um thread de objeto local deve especificar o `thread` atributo. Por exemplo, o código a seguir gera um erro:  
  
    ```  
    #define Thread  __declspec( thread )  
    extern int tls_i;        // This will generate an error, since the  
    int __declspec( thread )tls_i;        // declaration and definition differ.  
    ```  
  
-   O `thread` atributo não pode ser usado como um modificador de tipo. Por exemplo, o código a seguir gera um erro de compilador:  
  
    ```  
    char __declspec( thread ) *ch;        // Error  
    ```  
  
-   Porque a declaração do C++ objetos que usam o `thread` atributo é permitido, os dois exemplos a seguir são semanticamente equivalentes:  
  
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
  
-   O endereço de um objeto de local de thread não é constante e qualquer expressão que envolvem um endereço não é considerada uma expressão constante. No padrão C, o efeito disso é proíba o uso do endereço de uma variável local de thread como um inicializador para um objeto ou ponteiro. Por exemplo, o código a seguir é sinalizado como um erro pelo compilador C:  
  
    ```  
  
    __declspec( thread )int tls_i;  
    int *p = &tls_i;       //This will generate an error in C.  
    ```  
  
     Essa restrição não se aplica em C++. Como o C++ permite para inicialização dinâmica de todos os objetos, você pode inicializar um objeto usando uma expressão que usa o endereço de uma variável local de thread. Isso é feito como a construção de objetos de local de thread. Por exemplo, o código mostrado anteriormente não gera um erro quando ele é compilado como um arquivo de origem C++. Observe que o endereço de uma variável local de thread é válido somente quando o thread no qual foi feito o endereço ainda existe.  
  
-   C padrão permite a inicialização de um objeto ou variável com uma expressão que envolve uma referência a mesma, mas apenas para objetos de extensão não estático. Embora geralmente o C++ permite para tal inicialização dinâmica de objetos com uma expressão que envolve uma referência a mesmo, esse tipo de inicialização não é permitido com objetos locais de thread. Por exemplo:  
  
    ```  
    __declspec( thread )int tls_i = tls_i;                // Error in C and C++   
    int j = j;                               // OK in C++, error in C  
    __declspec( thread )int tls_i = sizeof( tls_i )       // Legal in C and C++  
    ```  
  
     Observe que um `sizeof` expressão que inclui o objeto que está sendo inicializado não representa uma referência a mesmo e está habilitada em C e C++.  
  
     C++ não permite essa inicialização dinâmica de dados de thread devido a possíveis aperfeiçoamentos futuros para o recurso de armazenamento local de thread.  
  
-   Em sistemas operacionais antes do Windows Vista, `__declspec`(thread) tem algumas limitações. Se uma DLL declara os dados ou objeto como `__declspec`(thread), isso pode causar uma falha de proteção se carregada dinamicamente. Depois que a DLL é carregada com [LoadLibrary](http://msdn.microsoft.com/library/windows/desktop/ms684175), causar falha do sistema sempre que o código faz referência a `__declspec`dados (thread). Como o espaço de variável global para um thread é alocado em tempo de execução, o tamanho desse espaço se baseia em um cálculo dos requisitos do aplicativo e os requisitos de todas as DLLs vinculadas estaticamente. Quando você usa `LoadLibrary`, você não pode estender esse espaço para permitir que as variáveis locais de thread declaradas com `__declspec`(thread). Use as APIs do TLS, como [TlsAlloc](http://msdn.microsoft.com/library/windows/desktop/ms686801), em sua DLL alocar TLS se a DLL pode ser carregada com `LoadLibrary`.  
  
## <a name="see-also"></a>Consulte também  
 [Multithreading com C e Win32](../parallel/multithreading-with-c-and-win32.md)   
