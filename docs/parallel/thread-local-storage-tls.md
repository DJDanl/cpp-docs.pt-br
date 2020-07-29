---
title: Armazenamento local de thread (TLS)
ms.date: 08/09/2019
helpviewer_keywords:
- multithreading [C++], Thread Local Storage
- TLS [C++]
- threading [C++], Thread Local Storage
- storing thread-specific data
- thread attribute
- Thread Local Storage [C++]
ms.assetid: 80801907-d792-45ca-b776-df0cf2e9f197
ms.openlocfilehash: f677d7382a9747df63023bd83b104a6bb3b74c1f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222648"
---
# <a name="thread-local-storage-tls"></a>Armazenamento local de thread (TLS)

O armazenamento local de threads (TLS) é o método pelo qual cada thread em um determinado processo multithread pode alocar locais para armazenar dados específicos de thread. Dados específicos de thread (tempo de execução) vinculados dinamicamente têm suporte por meio da API TLS ([TlsAlloc](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc)). O Win32 e o compilador do Microsoft C++ agora dão suporte a dados vinculados estaticamente (tempo de carregamento) por thread, além da implementação da API existente.

## <a name="compiler-implementation-for-tls"></a><a name="_core_compiler_implementation_for_tls"></a>Implementação do compilador para TLS

**C++ 11:**  O **`thread_local`** especificador de classe de armazenamento é a maneira recomendada para especificar o armazenamento local de thread para objetos e membros de classe. Para obter mais informações, consulte [classes de armazenamento (C++)](../cpp/storage-classes-cpp.md).

O MSVC também fornece um atributo específico da Microsoft, [thread](../cpp/thread.md), como modificador de classe de armazenamento estendido. Use a **`__declspec`** palavra-chave para declarar uma **`thread`** variável. Por exemplo, o código a seguir declara uma variável local de thread de inteiro e a inicializa com um valor:

```C
__declspec( thread ) int tls_i = 1;
```

## <a name="rules-and-limitations"></a>Regras e limitações

As diretrizes a seguir devem ser observadas ao declarar variáveis e objetos locais de thread vinculados estaticamente. Essas diretrizes se aplicam ao [thread](../cpp/thread.md) e ao [thread_local](../cpp/storage-classes-cpp.md):

- O **`thread`** atributo só pode ser aplicado a declarações e definições de classe e de dados. Ele não pode ser usado em declarações ou definições de função. Por exemplo, o código a seguir gera um erro de compilador:

    ```C
    __declspec( thread )void func();     // This will generate an error.
    ```

- O **`thread`** modificador só pode ser especificado em itens de dados com **`static`** extensão. Isso inclui objetos de dados globais ( **`static`** e **`extern`** ), objetos estáticos locais e membros de dados estáticos de classes C++. Os objetos de dados automáticos não podem ser declarados com o **`thread`** atributo. O código a seguir gera erros do compilador:

    ```C
    void func1()
    {
        __declspec( thread )int tls_i;            // This will generate an error.
    }

    int func2(__declspec( thread )int tls_i )     // This will generate an error.
    {
        return tls_i;
    }
    ```

- As declarações e a definição de um objeto local de thread devem especificar o **`thread`** atributo. Por exemplo, o código a seguir gera um erro:

    ```C
    #define Thread  __declspec( thread )
    extern int tls_i;        // This will generate an error, since the
    int __declspec( thread )tls_i;        // declaration and definition differ.
    ```

- O **`thread`** atributo não pode ser usado como um modificador de tipo. Por exemplo, o código a seguir gera um erro de compilador:

    ```C
    char __declspec( thread ) *ch;        // Error
    ```

- Como a declaração de objetos C++ que usam o **`thread`** atributo é permitida, os dois exemplos a seguir são semanticamente equivalentes:

    ```cpp
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

- O endereço de um objeto local de thread não é considerado constante e qualquer expressão que envolva tal endereço não é considerada uma expressão constante. No padrão C, o efeito é impedir o uso do endereço de uma variável local de thread como um inicializador para um objeto ou ponteiro. Por exemplo, o código a seguir é sinalizado como um erro pelo compilador C:

    ```C
    __declspec( thread ) int tls_i;
    int *p = &tls_i;       //This will generate an error in C.
    ```

   Essa restrição não se aplica em C++. Como o C++ permite a inicialização dinâmica de todos os objetos, você pode inicializar um objeto usando uma expressão que usa o endereço de uma variável local de thread. Isso é feito da mesma forma que a construção de objetos locais de thread. Por exemplo, o código mostrado anteriormente não gera um erro quando ele é compilado como um arquivo de origem C++. O endereço de uma variável local de thread é válido somente contanto que o thread no qual o endereço foi obtido ainda exista.

- O C padrão permite a inicialização de um objeto ou variável com uma expressão que envolve uma referência a si só, mas somente para objetos de extensão não estática. Embora o C++ geralmente permita a inicialização dinâmica de objetos com uma expressão que envolve uma referência a si mesmo, esse tipo de inicialização não é permitido com objetos locais de thread. Por exemplo:

    ```C
    __declspec( thread )int tls_i = tls_i;                // Error in C and C++
    int j = j;                               // OK in C++, error in C
    __declspec( thread )int tls_i = sizeof( tls_i )       // Legal in C and C++
    ```

   Uma **`sizeof`** expressão que inclui o objeto que está sendo inicializado não representa uma referência a si mesma e é habilitada em C e C++.

   O C++ não permite a inicialização dinâmica de dados de thread devido a possíveis aprimoramentos futuros para o recurso de armazenamento local de thread.

- Em sistemas operacionais Windows anteriores ao Windows Vista, o `__declspec( thread )` tem algumas limitações. Se uma DLL declarar qualquer dado ou objeto como `__declspec( thread )` , isso poderá causar uma falha de proteção se carregado dinamicamente. Depois que a DLL é carregada com [LoadLibrary](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw), ela causa falha do sistema sempre que o código faz referência aos `__declspec( thread )` dados. Como o espaço de variável global para um thread é alocado em tempo de execução, o tamanho desse espaço é baseado em um cálculo dos requisitos do aplicativo mais os requisitos de todas as DLLs que são vinculadas estaticamente. Ao usar `LoadLibrary` o, você não pode estender esse espaço para permitir as variáveis locais de thread declaradas com `__declspec( thread )` . Use as APIs de TLS, como [TlsAlloc](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc), em sua dll para alocar TLS se a dll puder ser carregada com `LoadLibrary` .

## <a name="see-also"></a>Confira também

[Multithread com C e Win32](multithreading-with-c-and-win32.md)
