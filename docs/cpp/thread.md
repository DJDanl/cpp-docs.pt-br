---
title: thread | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: thread_cpp
dev_langs: C++
helpviewer_keywords:
- thread local storage (TLS)
- thread __declspec keyword
- TLS (thread local storage), compiler implementation
- __declspec keyword [C++], thread
ms.assetid: 667f2a77-6d1f-4b41-bee8-05e67324fab8
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: b26487e7f5f11bb32f418b438e9d0396b5854a91
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="thread"></a>thread

**Seção específica da Microsoft**  
O **thread** modificador de classe de armazenamento estendido é usada para declarar uma variável local de thread. Para o portátil equivalente em C++ 11 e posterior, use o [thread_local](../cpp/storage-classes-cpp.md#thread_local) especificador de classe de armazenamento para código portátil. No Windows **thread_local** é implementado com **__declspec(thread)**.

## <a name="syntax"></a>Sintaxe

```
__declspec( thread ) declarator
```

## <a name="remarks"></a>Comentários

O TLS (armazenamento local de threads) é o mecanismo pelo qual cada thread em um processo multithread aloca armazenamento para dados específicos ao thread. Em programas multithread padrão, os dados são compartilhados entre todos os threads de um processo específico, enquanto o armazenamento local de threads é o mecanismo para alocar dados por thread. Para obter uma discussão completa de threads, consulte [Multithreading](../parallel/multithreading-support-for-older-code-visual-cpp.md).

Declarações de variáveis locais de thread devem usar [estendido a sintaxe do atributo](../cpp/declspec.md) e o `__declspec` palavra-chave with a **thread** palavra-chave. Por exemplo, o código a seguir declara uma variável local de thread de inteiro e a inicializa com um valor:

```cpp
__declspec( thread ) int tls_i = 1;  
```

Ao usar variáveis locais de thread em bibliotecas carregadas dinamicamente, você precisa estar ciente dos fatores que podem causar uma variável local de thread não seja inicializada corretamente:

1) Se a variável é inicializada com uma chamada de função (incluindo construtores), essa função será chamada somente para o segmento que causou a binário/DLL carregar no processo de e para esses threads iniciadas depois que o binário/DLL foi carregado. As funções de inicialização não são chamadas por qualquer outro thread já estava em execução quando o DLL foi carregado. Inicialização dinâmica ocorre na chamada para DLL_THREAD_ATTACH DllMain, mas o DLL nunca obtém a mensagem se a DLL não está no processo de quando o thread é iniciado. 

2) Variáveis locais de thread que são inicializadas estaticamente com valores constantes geralmente são inicializadas corretamente em todos os threads. No entanto, a partir de dezembro de 2017 há um problema de conformidade conhecidos no compilador Microsoft C++ no qual as variáveis de constexpr recebem dinâmico em vez de inicialização estática.  
  
   Observação: Esses dois problemas devem ser corrigidos em futuras atualizações do compilador.


Além disso, você deve observar estas diretrizes ao declarar variáveis e objetos de thread local:

- Você pode aplicar o **thread** atributo somente para a classe e declarações de dados e as definições. **thread** não pode ser usado em definições ou declarações de função.

- Você pode especificar o **thread** atributo apenas em itens de dados com duração de armazenamento estático. Isso inclui objetos de dados globais (ambos **estático** e **extern**), locais objetos static e membros de dados estáticos de classes. Você não pode declarar objetos automática de dados com o **thread** atributo.

- Você deve usar o **thread** atributo para a declaração e a definição de um objeto de thread local, se a declaração e a definição de ocorrerem no mesmo arquivo ou arquivos separados.

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

     Observe que uma **sizeof** expressão que inclui o objeto que está sendo inicializado não constitui uma referência a mesmo e é permitido em C e C++.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[__declspec](../cpp/declspec.md)  
[Palavras-chave](../cpp/keywords-cpp.md)  
[TLS (armazenamento local de thread)](../parallel/thread-local-storage-tls.md)
