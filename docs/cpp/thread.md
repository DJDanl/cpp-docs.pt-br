---
title: thread
ms.date: 05/07/2019
f1_keywords:
- thread_cpp
helpviewer_keywords:
- thread local storage (TLS)
- thread __declspec keyword
- TLS (thread local storage), compiler implementation
- __declspec keyword [C++], thread
ms.assetid: 667f2a77-6d1f-4b41-bee8-05e67324fab8
ms.openlocfilehash: cc21602764a9a3c2584bdd7da62c75974ffdd5fb
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301282"
---
# <a name="thread"></a>thread

**Seção específica da Microsoft**

O modificador de classe de armazenamento estendido de **thread** é usado para declarar uma variável local de thread. Para o equivalente portátil no C++ 11 e posterior, use o especificador de classe de armazenamento [thread_local](../cpp/storage-classes-cpp.md#thread_local) para código portátil. No Windows **thread_local** é implementado com **__declspec (thread)** .

## <a name="syntax"></a>Sintaxe

*Declarador* **de __declspec (thread)**

## <a name="remarks"></a>Comentários

O TLS (armazenamento local de threads) é o mecanismo pelo qual cada thread em um processo multithread aloca armazenamento para dados específicos ao thread. Em programas multithread padrão, os dados são compartilhados entre todos os threads de um processo específico, enquanto o armazenamento local de threads é o mecanismo para alocar dados por thread. Para obter uma discussão completa sobre threads, consulte [multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).

As declarações de variáveis locais de thread devem usar a [sintaxe de atributo estendido](../cpp/declspec.md) e a palavra-chave **__declspec** com a palavra-chave **thread** . Por exemplo, o código a seguir declara uma variável local de thread de inteiro e a inicializa com um valor:

```cpp
__declspec( thread ) int tls_i = 1;
```

Ao usar variáveis de local de thread em bibliotecas carregadas dinamicamente, você precisa estar ciente dos fatores que podem fazer com que uma variável de local de thread não seja inicializada corretamente:

1. Se a variável for inicializada com uma chamada de função (incluindo construtores), essa função só será chamada para o thread que fez com que o binário/DLL fosse carregado no processo e para os threads iniciados depois que o binário/DLL foi carregado. As funções de inicialização não são chamadas para qualquer outro thread que já estava em execução quando a DLL foi carregada. A inicialização dinâmica ocorre na chamada DllMain para DLL_THREAD_ATTACH, mas a DLL nunca receberá essa mensagem se a DLL não estiver no processo quando o thread for iniciado.

1. Variáveis locais de thread que são inicializadas estaticamente com valores constantes geralmente são inicializadas corretamente em todos os threads. No entanto, a partir de dezembro de 2017, há um problema de C++ conformidade conhecido no compilador da Microsoft, no qual as variáveis **constexpr** recebem inicialização dinâmica em vez de estática.

   Observação: os dois problemas devem ser corrigidos em atualizações futuras do compilador.

Além disso, você deve observar essas diretrizes ao declarar variáveis e objetos locais de thread:

- Você pode aplicar o atributo **thread** somente às declarações e definições de classe e de dados; o **thread** não pode ser usado em declarações ou definições de função.

- Você pode especificar o atributo de **thread** somente em itens de dados com duração de armazenamento estático. Isso inclui objetos de dados globais ( **estáticos** e **extern**), objetos estáticos locais e membros de dados estáticos de classes. Você não pode declarar objetos de dados automáticos com o atributo **thread** .

- Você deve usar o atributo **thread** para a declaração e a definição de um objeto local de thread, se a declaração e a definição ocorrem no mesmo arquivo ou em arquivos separados.

- Você não pode usar o atributo **thread** como um modificador de tipo.

- Como a declaração de objetos que usam o atributo **thread** é permitida, esses dois exemplos são semanticamente equivalentes:

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

- O C padrão permite a inicialização de um objeto ou variável com uma expressão que envolve uma referência a si só, mas somente para objetos não estáticos. Embora C++ normalmente permita tal inicialização dinâmica de um objeto com uma expressão que envolva uma referência a si mesmo, esse tipo de inicialização não é permitido com objetos locais de thread. Por exemplo:

   ```cpp
   // declspec_thread_3.cpp
   // compile with: /LD
   #define Thread __declspec( thread )
   int j = j;   // Okay in C++; C error
   Thread int tls_i = sizeof( tls_i );   // Okay in C and C++
   ```

   Uma expressão **sizeof** que inclui o objeto que está sendo inicializado não constitui uma referência a si mesma e é permitida C++em C e.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Veja também

[__declspec](../cpp/declspec.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)<br/>
[TLS (armazenamento local de thread)](../parallel/thread-local-storage-tls.md)