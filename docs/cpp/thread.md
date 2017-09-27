---
title: thread | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- thread
- thread_cpp
dev_langs:
- C++
helpviewer_keywords:
- thread local storage (TLS)
- thread __declspec keyword
- TLS (thread local storage), compiler implementation
- __declspec keyword [C++], thread
ms.assetid: 667f2a77-6d1f-4b41-bee8-05e67324fab8
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: HT
ms.sourcegitcommit: f460497071445cff87308fa9bf6e0d43c6f13a3e
ms.openlocfilehash: 7261dc1d6d76eeac8a6b2959bc9bb6fc3c98a66e
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="thread"></a>thread

**Seção específica da Microsoft**  
O **thread** modificador de classe de armazenamento estendido é usada para declarar uma variável local de thread. Para o portátil equivalente em C++ 11 e posterior, use o [thread_local](../cpp/storage-classes-cpp.md#thread_local) especificador de classe de armazenamento.

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

Você deve observar estas diretrizes ao declarar objetos e variáveis locais de thread:

- Você pode aplicar o **thread** atributo somente para a classe e declarações de dados e as definições. **thread** não pode ser usado em definições ou declarações de função.

- O uso do **thread** atributo pode interferir com [carregamento de atraso](../build/reference/linker-support-for-delay-loaded-dlls.md) da DLL importa.

- Em sistemas XP, **thread** pode não funcionar corretamente se uma DLL usa dados __declspec(thread) e ele é carregado dinamicamente por meio de LoadLibrary.

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

