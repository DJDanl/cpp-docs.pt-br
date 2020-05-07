---
title: Armazenamento local de thread
ms.date: 11/04/2016
helpviewer_keywords:
- thread-local variables
- TLS (thread local storage)
- thread storage-class attribute
- thread-local storage
- storage, thread local storage
ms.assetid: a0f1b109-c953-4079-aa10-e47f5483173d
ms.openlocfilehash: a1099228e072a772ee7d8e7e93253b674d0cd24b
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69500282"
---
# <a name="thread-local-storage"></a>Armazenamento local de thread

**Específico da Microsoft**

O armazenamento local de thread (TLS) é o mecanismo pelo qual cada thread em um processo multithread determinado aloca o armazenamento para dados específicos de threads. Em programas multithread padrão, os dados são compartilhados entre todos os threads de um processo específico, enquanto o armazenamento local de threads é o mecanismo para alocar dados por thread. Para obter uma discussão completa sobre threads, confira [Processos e threads](/windows/win32/ProcThread/processes-and-threads) no SDK do Windows.

A linguagem Microsoft C inclui o atributo de classe de armazenamento estendida, thread, que é usado com a palavra-chave __declspec para declarar uma variável local de thread. Por exemplo, o código a seguir declara uma variável local de thread de inteiro e a inicializa com um valor:

```
__declspec( thread ) int tls_i = 1;
```

As seguintes diretrizes devem ser observadas ao declarar variáveis locais de threads associados estaticamente:

- Variáveis locais de thread com inicialização dinâmica são inicializadas somente no thread que faz com que a DLL seja carregada e nos threads que já estão em execução no processo. Para obter mais informações, veja [thread](../cpp/thread.md).

- Você pode aplicar o atributo thread somente a declarações e definições de dados. Ele não pode ser usado em declarações ou definições de função. Por exemplo, o código a seguir gera um erro de compilador:

    ```C
    #define Thread   __declspec( thread )
    Thread void func();      /* Error */
    ```

- Você pode especificar o atributo thread apenas em itens de dados com duração de armazenamento estática. Isso inclui dados globais (estáticos e externos) e dados estáticos locais. Você não pode declarar dados automáticos com o atributo thread. Por exemplo, o código a seguir gera erros de compilador:

    ```C
    #define Thread   __declspec( thread )
    void func1()
    {
        Thread int tls_i;            /* Error */
    }

    int func2( Thread int tls_i )    /* Error */
    {
       return tls_i;
    }
    ```

- Você deve usar o atributo thread para a declaração e a definição de dados locais de thread, independentemente da declaração e a definição ocorrem no mesmo arquivo ou em arquivos separados. Por exemplo, o código a seguir gera um erro:

    ```C
    #define Thread   __declspec( thread )
    extern int tls_i;     /* This generates an error, because the   */
    int Thread tls_i;     /* declaration and the definition differ. */
    ```

- Você não pode usar o atributo thread como um modificador de tipo. Por exemplo, o código a seguir gera um erro de compilador:

    ```C
    char *ch __declspec( thread );      /* Error */
    ```

- O endereço de uma variável local de thread não é considerado constante, e nenhuma expressão que envolva esse endereço é considerada uma expressão constante. Isso significa que você não pode usar o endereço de uma variável local de thread como um inicializador para um ponteiro. Por exemplo, o compilador sinaliza o código a seguir como um erro:

    ```C
    #define Thread   __declspec( thread )
    Thread int tls_i;
    int *p = &tls_i;      /* Error */
    ```

- O C permite a inicialização de uma variável com uma expressão que envolva uma referência a si mesma, mas apenas para objetos de extensão não estática. Por exemplo: 

    ```C
    #define Thread   __declspec( thread )
    Thread int tls_i = tls_i;             /* Error */
    int j = j;                            /* Error */
    Thread int tls_i = sizeof( tls_i )    /* Okay  */
    ```

   Observe que uma expressão sizeof que inclua a variável que está sendo inicializada não constitui uma referência a si mesma e é permitida.

- O uso de ** \_ \_declspec (thread)** pode interferir no [carregamento do atraso](../build/reference/linker-support-for-delay-loaded-dlls.md) de importações de dll.

Para obter mais informações sobre como usar o atributo thread, consulte [Tópicos de multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Atributos de classe de armazenamento estendido C](../c-language/c-extended-storage-class-attributes.md)
