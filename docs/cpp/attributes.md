---
title: Atributos em C++
ms.date: 05/06/2019
ms.assetid: 748340d9-8abf-4940-b0a0-91b6156a3ff8
ms.openlocfilehash: efdc62e2343135aee483520f633bac99519455b4
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229201"
---
# <a name="attributes-in-c"></a>Atributos em C++

O padrão C++ define um conjunto de atributos e também permite que os fornecedores de compilador definam seus próprios atributos (dentro de um namespace específico do fornecedor), mas os compiladores são necessários para reconhecer apenas os atributos definidos no padrão.

Em alguns casos, os atributos padrão se sobrepõem com parâmetros declspec específicos do compilador. No Visual C++, você pode usar o `[[deprecated]]` atributo em vez de usar `declspec(deprecated)` e o atributo será reconhecido por qualquer compilador em conformidade. Para todos os outros parâmetros de declspec, como DllImport e dllexport, ainda não há nenhum equivalente de atributo, portanto, você deve continuar a usar a sintaxe declspec. Os atributos não afetam o sistema de tipos e não alteram o significado de um programa. Os compiladores ignoram valores de atributo que não reconhecem.

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)): no escopo de uma lista de atributos, você pode especificar o namespace para todos os nomes com um único **`using`** apresentador:

```cpp
void g() {
    [[using rpr: kernel, target(cpu,gpu)]] // equivalent to [[ rpr::kernel, rpr::target(cpu,gpu) ]]
    do task();
}
```

## <a name="c-standard-attributes"></a>Atributos padrão do C++

No C++ 11, os atributos fornecem uma maneira padronizada para anotar construções do C++ (incluindo, mas não se limitando a classes, funções, variáveis e blocos) com informações adicionais que podem ou não ser específicas do fornecedor. Um compilador pode usar essas informações para gerar mensagens informativas ou para aplicar uma lógica especial ao compilar o código atribuído. O compilador ignora todos os atributos que ele não reconhece, o que significa que você não pode definir seus próprios atributos personalizados usando essa sintaxe. Os atributos são colocados entre colchetes duplos:

```cpp
[[deprecated]]
void Foo(int);
```

Os atributos representam uma alternativa padronizada para extensões específicas de fornecedor, como #pragma diretivas, __declspec () (Visual C++) ou GNU ( &#95;&#95;de atributo&#95;&#95; ). No entanto, ainda será necessário usar as construções específicas do fornecedor para a maioria das finalidades. O padrão atualmente especifica os seguintes atributos que um compilador de conformidade deve reconhecer:

- `[[noreturn]]`Especifica que uma função nunca retorna; em outras palavras, ele sempre gera uma exceção. O compilador pode ajustar suas regras de compilação para `[[noreturn]]` entidades.

- `[[carries_dependency]]`Especifica que a função propaga a ordem de dependência de dados em relação à sincronização de threads. O atributo pode ser aplicado a um ou mais parâmetros, para especificar que o argumento passado transporta uma dependência no corpo da função. O atributo pode ser aplicado à própria função, para especificar que o valor de retorno transporta uma dependência da função. O compilador pode usar essas informações para gerar um código mais eficiente.

- `[[deprecated]]`**Visual Studio 2015 e posterior:** Especifica que uma função não deve ser usada e pode não existir em versões futuras de uma interface de biblioteca. O compilador pode usar isso para gerar uma mensagem informativa quando o código do cliente tenta chamar a função. Pode ser aplicado à declaração de uma classe, um nome de typedef, uma variável, um membro de dados não estático, uma função, um namespace, uma enumeração, um enumerador ou uma especialização de modelo.

- `[[fallthrough]]`**Visual Studio 2017 e posterior:** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)) o `[[fallthrough]]` atributo pode ser usado no contexto de instruções [switch](switch-statement-cpp.md) como uma dica para o compilador (ou qualquer pessoa que lê o código) que o comportamento de fallthrough é pretendido. No momento, o compilador do Microsoft C++ não avisa sobre o comportamento do fallthrough, portanto, esse atributo não tem efeito sobre o comportamento do compilador.

- `[[nodiscard]]`**Visual Studio 2017 versão 15,3 e posterior:** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)) especifica que o valor de retorno de uma função não deve ser Descartado. Gera C4834 de aviso, conforme mostrado neste exemplo:

    ```cpp
    [[nodiscard]]
    int foo(int i) { return i * i; }

    int main()
    {
        foo(42); //warning C4834: discarding return value of function with 'nodiscard' attribute
        return 0;
    }
    ```

- `[[maybe_unused]]`**Visual Studio 2017 versão 15,3 e posteriores:** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)) especifica que uma especialização de variável, função, classe, typedef, membro de dados não estático, enumeração ou modelo pode não ser usada intencionalmente. O compilador não avisa quando uma entidade marcada `[[maybe_unused]]` não é usada. Uma entidade que é declarada sem o atributo pode ser redeclarada posteriormente com o atributo e vice-versa. Uma entidade é considerada marcada depois que sua primeira declaração marcada é analisada e para o restante da tradução da unidade de tradução atual.

## <a name="microsoft-specific-attributes"></a>Atributos específicos da Microsoft

- `[[gsl::suppress(rules)]]`Este atributo específico da Microsoft é usado para suprimir avisos de verificadores que impõem regras de [GSL (biblioteca de suporte de diretrizes)](https://github.com/Microsoft/GSL) no código. Por exemplo, considere este trecho de código:

    ```cpp
    int main()
    {
        int arr[10]; // GSL warning C26494 will be fired
        int* p = arr; // GSL warning C26485 will be fired
        [[gsl::suppress(bounds.1)]] // This attribute suppresses Bounds rule #1
        {
            int* q = p + 1; // GSL warning C26481 suppressed
            p = q--; // GSL warning C26481 suppressed
        }
    }
    ```

  O exemplo gera estes avisos:

  - 26494 (tipo de regra 5: sempre inicializar um objeto.)

  - 26485 (Associação regra 3: nenhuma matriz para ponteiro decaimento.)

  - 26481 (regra de limites 1: não use aritmética de ponteiro. Use span em vez disso.)

  Os dois primeiros avisos são acionados quando você compila esse código com a ferramenta de análise de código do CppCoreCheck instalada e ativada. Mas o terceiro aviso não é acionado devido ao atributo. Você pode suprimir o perfil de limites inteiro escrevendo [[GSL:: suprimir (limites)]] sem incluir um número de regra específico. As Diretrizes Principais do C++ são projetadas para ajudá-lo a escrever um código melhor e mais seguro. O atributo suprimir facilita a desativação dos avisos quando eles não são desejados.
  