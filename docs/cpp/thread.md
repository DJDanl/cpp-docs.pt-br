---
title: thread
ms.date: 11/04/2016
f1_keywords:
- thread_cpp
helpviewer_keywords:
- thread local storage (TLS)
- thread __declspec keyword
- TLS (thread local storage), compiler implementation
- __declspec keyword [C++], thread
ms.assetid: 667f2a77-6d1f-4b41-bee8-05e67324fab8
ms.openlocfilehash: 089f339e5d203fe44789a7df1607f73ab13b8a24
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50440073"
---
# <a name="thread"></a>thread

**Seção específica da Microsoft**

O **thread** modificador de classe de armazenamento estendido é usado para declarar uma variável local de thread. Para o portable equivalente no C++ 11 e posterior, use o [thread_local](../cpp/storage-classes-cpp.md#thread_local) especificador de classe de armazenamento para código portátil. No Windows `thread_local` é implementado com **__declspec(thread)**.

## <a name="syntax"></a>Sintaxe

> **__declspec( thread )** *declarator*

## <a name="remarks"></a>Comentários

O TLS (armazenamento local de threads) é o mecanismo pelo qual cada thread em um processo multithread aloca armazenamento para dados específicos ao thread. Em programas multithread padrão, os dados são compartilhados entre todos os threads de um processo específico, enquanto o armazenamento local de threads é o mecanismo para alocar dados por thread. Para obter uma discussão completa sobre threads, consulte [Multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).

Declarações de variáveis locais de thread devem usar [sintaxe de atributo estendida](../cpp/declspec.md) e o **declspec** palavra-chave com o **thread** palavra-chave. Por exemplo, o código a seguir declara uma variável local de thread de inteiro e a inicializa com um valor:

```cpp
__declspec( thread ) int tls_i = 1;
```

Ao usar variáveis locais de thread nas bibliotecas carregado dinamicamente, você precisa estar ciente de fatores que podem fazer com que uma variável local de thread não sejam inicializados corretamente:

1. Se a variável é inicializada com uma chamada de função (incluindo construtores), essa função será chamada somente para o thread que causou a binário/DLL carregar no processo de e para esses threads iniciadas depois que o binário/DLL foi carregado. As funções de inicialização não são chamadas para qualquer outro thread que já estava executando quando a DLL foi carregada. Inicialização dinâmica ocorre na chamada para DLL_THREAD_ATTACH DllMain, mas a DLL nunca obtém a mensagem se a DLL não está no processo de quando o thread é iniciado.

1. Variáveis locais de thread que são inicializadas estaticamente com valores constantes geralmente são inicializadas corretamente em todos os threads. No entanto, a partir de dezembro de 2017 há um problema de compatibilidade conhecidos no compilador do Microsoft Visual C++ no qual variáveis constexpr recebem dinâmica em vez de inicialização estática.

   Observação: Esses dois problemas devem ser corrigidos em futuras atualizações do compilador.

Além disso, você deve observar estas diretrizes ao declarar variáveis e objetos locais de thread:

- Você pode aplicar a **thread** atributo somente a classe e declarações de dados e as definições. **thread** não pode ser usado em definições ou declarações de função.

- Você pode especificar o **thread** atributo apenas em itens de dados com duração de armazenamento estático. Isso inclui objetos de dados globais (ambos **estáticos** e **extern**), objetos estáticos locais e membros de dados estáticos de classes. Você não pode declarar objetos de dados automáticos com o **thread** atributo.

- Você deve usar o **thread** de atributo para a declaração e a definição de um objeto de thread local, se a declaração e a definição ocorrem no mesmo arquivo ou arquivos separados.

- Não é possível usar o **thread** atributo como um modificador de tipo.

- Como a declaração de objetos que usam o **thread** atributo é permitido, estes dois exemplos são semanticamente equivalentes:

    ```cpp
    // declspec_thread_2.cpp
    // compile with: /LD
    __declspec( thread ) class B {
    public:
       int data;
    } BObject;   // BObject declared thread local.

    class B2 {
    public:
       int data;
    };
    __declspec( thread ) B2 BObject2;   // BObject2 declared thread local.
    ```

- O C padrão permite a inicialização de um objeto ou uma variável com uma expressão que envolva uma referência a si mesma, mas apenas para objetos de extensão não estática. Embora normalmente o C++ permita essa inicialização dinâmica de um objeto com uma expressão que envolva uma referência a si mesma, esse tipo de inicialização não é permitido com objetos locais de thread. Por exemplo:

   ```cpp
   // declspec_thread_3.cpp
   // compile with: /LD
   #define Thread __declspec( thread )
   int j = j;   // Okay in C++; C error
   Thread int tls_i = sizeof( tls_i );   // Okay in C and C++
   ```

   Observe que um **sizeof** expressão que inclui o objeto que está sendo inicializado não constitui uma referência a mesma e é permitido em C e C++.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[TLS (armazenamento local de thread)](../parallel/thread-local-storage-tls.md)