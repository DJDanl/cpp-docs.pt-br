---
title: Atributos de C++ padrão | Microsoft Docs
ms.custom: ''
ms.date: 03/28/2017
ms.topic: language-reference
ms.assetid: 748340d9-8abf-4940-b0a0-91b6156a3ff8
ms.openlocfilehash: 7bd7fd4e01fb210069f4dbae42a671e4dd9c64c9
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32416191"
---
# <a name="attributes-in-c"></a>Atributos em C++

O padrão C++ define um conjunto de atributos e também permite que fornecedores de compilador definir seus próprios atributos (dentro de um namespace específico do fornecedor), mas compiladores são necessárias para reconhecer apenas os atributos definidos no padrão.

Em alguns casos, os atributos padrão se sobrepõem com parâmetros específicos de compilador declspec. No Visual C++, você pode usar o `[[deprecated]]` atributo em vez de usar `declspec(deprecated)` e o atributo será reconhecido pelo compilador qualquer compatível. Para todos os outros parâmetros de declspec como dllimport e dllexport, há como ainda nenhum atributo equivalente para que você deve continuar a usar a sintaxe declspec. Atributos não afetam o sistema de tipos e não alterar o significado de um programa. Compiladores ignoram valores de atributo que não reconhecem.

**Visual Studio 2017 versão posterior e 15,3** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)): no escopo de uma lista de atributos, você pode especificar o namespace para todos os nomes com um único `using` Introdutor:

```cpp
void g() {
    [[using rpr: kernel, target(cpu,gpu)]] // equivalent to [[ rpr::kernel, rpr::target(cpu,gpu) ]]
    do task();
}
```

## <a name="c-standard-attributes"></a>Atributos de C++ padrão

No C++ 11, atributos fornecem uma maneira padronizada para anotar construções C++ (incluindo, mas não limitado a classes, funções, variáveis e blocos) com informações adicionais que podem ou não ser específico do fornecedor. Um compilador pode usar essas informações para gerar mensagens informativas ou aplicar uma lógica especial ao compilar o código atribuído. O compilador ignora todos os atributos que não reconhece, o que significa que você não pode definir seus próprios atributos personalizados com essa sintaxe. Atributos são delimitados por colchetes duplos:

```cpp
[[deprecated]]
void Foo(int);
```

Atributos que representam uma alternativa padronizada para extensões específicas do fornecedor como #pragma diretivas, atribuir (Visual C++), ou &#95; &#95;atributo&#95; &#95; (GNU). No entanto, você ainda precisará usar as construções específicas do fornecedor para a maioria das finalidades. Atualmente, o padrão especifica os seguintes atributos que um compilador com conformidade deve reconhecer:

- `[[noreturn]]` Especifica que uma função nunca retorna; em outras palavras, ele sempre gerará uma exceção. O compilador pode ajustar suas regras de compilação para `[[noreturn]]` entidades.

- `[[carries_dependency]]` Especifica que a função propaga ordenação em relação à sincronização de threads de dependência de dados. O atributo pode ser aplicado a um ou mais parâmetros para especificar que o argumento transmitido apresenta uma dependência no corpo da função. O atributo pode ser aplicado à função em si, para especificar o valor de retorno executa uma dependência sairá da função. O compilador pode usar essas informações para gerar um código mais eficiente.

- `[[deprecated]]` **Visual Studio 2015 e posterior:** Especifica que uma função não se destina a ser usada e pode não existir em versões futuras de uma interface de biblioteca. O compilador pode usar isso para gerar uma mensagem informativa ao código do cliente tenta chamar a função. Pode ser aplicado a declaração de uma classe, um nome de typedef, uma variável, um membro de dados não estático, uma função, um namespace, uma enumeração, um enumerador ou uma especialização de modelo.  

- `[[fallthrough]]` **Visual Studio 2017 e posterior:** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)) o `[[fallthrough]]` atributo pode ser usado no contexto de [alternar](switch-statement-cpp.md) instruções como uma dica para o compilador (ou qualquer pessoa que ler o código) que se destina o comportamento de fallthrough. O compilador do Visual C++ no momento não avisa sobre o comportamento de fallthrough para que este atributo não tem nenhum comportamento de compilador efeito.

- `[[nodiscard]]` **Visual Studio 2017 versão 15,3 e posterior:** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)) Especifica que o valor de retorno da função não é destinado a ser descartado. Gerar aviso C4834, conforme mostrado neste exemplo:

   ```cpp
   [[nodiscard]]
   int foo(int i) { return i * i; }

   int main()
   {
       foo(42); //warning C4834: discarding return value of function with 'nodiscard' attribute
       return 0;
   }
   ```

- `[[maybe_unused]]` **Visual Studio 2017 versão 15,3 e posterior:** (disponível com [/std:c + + 17](../build/reference/std-specify-language-standard-version.md)) Especifica que uma variável, função, classe, typedef, membro de dados não estático, enum ou especialização de modelo intencionalmente não pode ser usada. O compilador não avisa quando uma entidade marcado `[[maybe_unused]]` não é usado. Uma entidade que está declarada sem o atributo mais tarde pode ser redeclarada com o atributo e vice-versa. Uma entidade é considerada marcadas após sua primeira declaração marcado é analisada e para o restante da conversão da unidade de tradução atual.

## <a name="microsoft-specific-attributes"></a>Atributos específicos da Microsoft

- `[[gsl::suppress(rules)]]` Este atributo específico da Microsoft é usado para suprimir avisos de verificadores que impõem [biblioteca de suporte de diretrizes (GSL)](https://github.com/Microsoft/GSL) regras no código. Por exemplo, considere este trecho de código:

    ```cpp
    void main()
    {
        int arr[10]; // GSL warning 26494 will be fired
        int* p = arr; // GSL warning 26485 will be fired
        [[gsl::suppress(bounds.1)]] // This attribute suppresses Bounds rule #1
        {
            int* q = p + 1; // GSL warning 26481 suppressed
            p = q--; // GSL warning 26481 suppressed
        }
    }
    ```

   O exemplo gera esses avisos:

   - 26494 (tipo de regra 5: sempre inicializar um objeto.)

   - 26485 (limites regra 3: Nenhuma matriz de decay do ponteiro.)

   - 26481 (limites regra 1: não usar aritmética de ponteiro. Use período.)

   Os dois primeiros avisos disparados quando você compila seu código com a ferramenta de análise de código CppCoreCheck instalado e ativado. Mas o terceiro aviso não é acionado por causa do atributo. Você pode suprimir todo o perfil de limites, escrevendo [[gsl::suppress(bounds)]] sem a inclusão de um número específico de regra. As diretrizes de núcleos de C++ são projetadas para ajudá-lo a escrever código melhor e mais seguro. O atributo suprimir facilita desativar os avisos quando eles não são desejáveis.
