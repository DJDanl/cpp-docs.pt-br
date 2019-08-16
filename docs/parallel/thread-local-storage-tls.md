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
ms.openlocfilehash: 7e308f7ba23503879f8ebbcacde481cf72055229
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69510396"
---
# <a name="thread-local-storage-tls"></a>Armazenamento local de thread (TLS)

O armazenamento local de threads (TLS) é o método pelo qual cada thread em um determinado processo multithread pode alocar locais para armazenar dados específicos de thread. Dados específicos de thread (tempo de execução) vinculados dinamicamente têm suporte por meio da API TLS ([TlsAlloc](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc). O Win32 e o C++ compilador da Microsoft agora dão suporte a dados vinculados estaticamente (tempo de carregamento) por thread, além da implementação de API existente.

## <a name="_core_compiler_implementation_for_tls"></a>Implementação do compilador para TLS

**C++11:**  O `thread_local` especificador de classe de armazenamento é a maneira recomendada para especificar o armazenamento local de thread para objetos e membros de classe. Para obter mais informações, consulte [classes deC++armazenamento ()](../cpp/storage-classes-cpp.md).

O MSVC também fornece um atributo específico da Microsoft, [thread](../cpp/thread.md), como modificador de classe de armazenamento estendido. Use a palavra-chave **_ declspec** para declarar uma variável de **thread** . Por exemplo, o código a seguir declara uma variável local de thread de inteiro e a inicializa com um valor:

```C
__declspec( thread ) int tls_i = 1;
```

## <a name="rules-and-limitations"></a>Regras e limitações

As diretrizes a seguir devem ser observadas ao declarar variáveis e objetos locais de thread vinculados estaticamente. Essas diretrizes se aplicam ao [thread](../cpp/thread.md) e ao [thread_local](../cpp/storage-classes-cpp.md):

- O atributo **thread** só pode ser aplicado a declarações e definições de classe e de dados. Ele não pode ser usado em declarações ou definições de função. Por exemplo, o código a seguir gera um erro de compilador:

    ```C
    __declspec( thread )void func();     // This will generate an error.
    ```

- O modificador de **thread** só pode ser especificado em itens de dados com extensão **estática** . Isso inclui objetos de dados globais ( estáticose extern), objetos estáticos locais e membros de C++ dados estáticos de classes. Os objetos de dados automáticos não podem ser declarados com o atributo **thread** . O código a seguir gera erros do compilador:

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

- As declarações e a definição de um objeto local de thread devem especificar o atributo **thread** . Por exemplo, o código a seguir gera um erro:

    ```C
    #define Thread  __declspec( thread )
    extern int tls_i;        // This will generate an error, since the
    int __declspec( thread )tls_i;        // declaration and definition differ.
    ```

- O atributo **thread** não pode ser usado como um modificador de tipo. Por exemplo, o código a seguir gera um erro de compilador:

    ```C
    char __declspec( thread ) *ch;        // Error
    ```

- Como a declaração de C++ objetos que usam o atributo **thread** é permitida, os dois exemplos a seguir são semanticamente equivalentes:

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

   Essa restrição não se aplica C++ao. Como C++ o permite a inicialização dinâmica de todos os objetos, você pode inicializar um objeto usando uma expressão que usa o endereço de uma variável local de thread. Isso é feito da mesma forma que a construção de objetos locais de thread. Por exemplo, o código mostrado anteriormente não gera um erro quando ele é compilado como um C++ arquivo de origem. O endereço de uma variável local de thread é válido somente contanto que o thread no qual o endereço foi obtido ainda exista.

- O C padrão permite a inicialização de um objeto ou variável com uma expressão que envolve uma referência a si só, mas somente para objetos de extensão não estática. Embora C++ o geralmente permita a inicialização dinâmica de objetos com uma expressão que envolve uma referência a si mesmo, esse tipo de inicialização não é permitido com objetos locais de thread. Por exemplo:

    ```C
    __declspec( thread )int tls_i = tls_i;                // Error in C and C++
    int j = j;                               // OK in C++, error in C
    __declspec( thread )int tls_i = sizeof( tls_i )       // Legal in C and C++
    ```

   Uma `sizeof` expressão que inclui o objeto que está sendo inicializado não representa uma referência a si mesma e é habilitada C++em C e.

   C++Não permite essa inicialização dinâmica de dados de thread devido a possíveis aprimoramentos futuros para o recurso de armazenamento local de thread.

- Em sistemas operacionais Windows anteriores ao Windows Vista `__declspec( thread )` , o tem algumas limitações. Se uma DLL declarar qualquer dado ou objeto como `__declspec( thread )`, isso poderá causar uma falha de proteção se carregado dinamicamente. Depois que a dll é carregada com [LoadLibrary](/windows/win32/api/libloaderapi/nf-libloaderapi-loadlibraryw), ela causa falha do sistema sempre que o `__declspec( thread )` código faz referência aos dados. Como o espaço de variável global para um thread é alocado em tempo de execução, o tamanho desse espaço é baseado em um cálculo dos requisitos do aplicativo mais os requisitos de todas as DLLs que são vinculadas estaticamente. Ao usar `LoadLibrary`o, você não pode estender esse espaço para permitir as variáveis locais de thread declaradas com `__declspec( thread )`. Use as APIs de TLS, como [TlsAlloc](/windows/win32/api/processthreadsapi/nf-processthreadsapi-tlsalloc), em sua dll para alocar TLS se a dll puder ser carregada `LoadLibrary`com.

## <a name="see-also"></a>Consulte também

[Multithreading com C e Win32](multithreading-with-c-and-win32.md)
