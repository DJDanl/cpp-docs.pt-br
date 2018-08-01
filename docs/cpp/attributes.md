---
title: Atributos padrão do C++ | Microsoft Docs
ms.custom: ''
ms.date: 03/28/2017
ms.topic: language-reference
ms.assetid: 748340d9-8abf-4940-b0a0-91b6156a3ff8
ms.openlocfilehash: 89da1bbfc89496f54c829093c2c0ccf17d2f9123
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39401968"
---
# <a name="attributes-in-c"></a>Atributos em C++

O padrão C++ define um conjunto de atributos e também permite que fornecedores de compilador definir seus próprios atributos (dentro de um namespace específico do fornecedor), mas os compiladores são necessárias para reconhecer apenas os atributos definidos no padrão.

Em alguns casos, os atributos padrão se sobrepõem com parâmetros específicos do compilador declspec. No Visual C++, você pode usar o `[[deprecated]]` atributo em vez de usar `declspec(deprecated)` e o atributo será reconhecido pelo compilador qualquer compatível com. Para todos os outros parâmetros de declspec como dllimport e dllexport, há que ainda não há equivalente do atributo para que você deve continuar a usar a sintaxe de declspec. Atributos não afetam o sistema de tipos, e não alterar o significado de um programa. Compiladores ignoram os valores de atributo que eles não reconhecem.

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)): no escopo de uma lista de atributos, você pode especificar o namespace para todos os nomes com um único **usando** Introdutor:

```cpp
void g() {
    [[using rpr: kernel, target(cpu,gpu)]] // equivalent to [[ rpr::kernel, rpr::target(cpu,gpu) ]]
    do task();
}
```

## <a name="c-standard-attributes"></a>Atributos padrão do C++

No C++ 11, os atributos fornecem uma maneira padronizada para anotar as construções C++ (incluindo mas não limitado a classes, funções, variáveis e blocos) com informações adicionais que podem ou não ser específicas do fornecedor. Um compilador pode usar essas informações para gerar mensagens informativas ou aplicar uma lógica especial ao compilar o código atribuído. O compilador ignora todos os atributos que ele não reconhece, o que significa que você não pode definir seus próprios atributos personalizados usando essa sintaxe. Os atributos são colocados por colchetes duplos:

```cpp
[[deprecated]]
void Foo(int);
```

Atributos que representam uma alternativa padronizada para extensões específicas do fornecedor, como diretivas de #pragma atribuir (Visual C++), ou &#95; &#95;atributo&#95; &#95; (GNU). No entanto, você ainda precisará usar as construções específicas do fornecedor para a maioria das finalidades. Atualmente, o padrão especifica os seguintes atributos que um compilador em conformidade deve reconhecer:

- `[[noreturn]]` Especifica que uma função nunca retorna; em outras palavras, ele sempre lança uma exceção. O compilador pode ajustar suas regras de compilação para `[[noreturn]]` entidades.

- `[[carries_dependency]]` Especifica que a função propaga ordenação em relação à sincronização de threads de dependência de dados. O atributo pode ser aplicado a um ou mais parâmetros para especificar que o argumento transmitido carrega uma dependência no corpo da função. O atributo pode ser aplicado à função em si, para especificar que o valor de retorno apresenta uma dependência da função. O compilador pode usar essas informações para gerar um código mais eficiente.

- `[[deprecated]]` **Visual Studio 2015 e posterior:** Especifica que uma função não se destina a ser usada e podem não existir em futuras versões de uma interface de biblioteca. O compilador pode usar isso para gerar uma mensagem informativa ao detectar tentativas de código do cliente chamar a função. Pode ser aplicado a declaração de uma classe, um nome de typedef, uma variável, um membro de dados não estático, uma função, um namespace, uma enumeração, um enumerador ou uma especialização de modelo.  

- `[[fallthrough]]` **Visual Studio 2017 e posterior:** (disponível com [/std:c++17 + + 17](../build/reference/std-specify-language-standard-version.md)) a `[[fallthrough]]` atributo pode ser usado no contexto do [alternar](switch-statement-cpp.md) instruções como uma dica para o compilador (ou qualquer pessoa que leia o código) que se destina o comportamento de fallthrough. O compilador do Visual C++ no momento não avisa sobre o comportamento de fallthrough, para que esse atributo não tem nenhum comportamento do compilador em vigor.

- `[[nodiscard]]` **Visual Studio 2017 versão 15.3 e posterior:** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)) Especifica que o valor de retorno da função não foi projetado para ser descartada. Gera o aviso de C4834, conforme mostrado neste exemplo:

   ```cpp
   [[nodiscard]]
   int foo(int i) { return i * i; }

   int main()
   {
       foo(42); //warning C4834: discarding return value of function with 'nodiscard' attribute
       return 0;
   }
   ```

- `[[maybe_unused]]` **Visual Studio 2017 versão 15.3 e posterior:** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)) Especifica que uma variável, função, classe, typedef, membro de dados não estáticos, enum ou especialização de modelo intencionalmente não pode ser usada. O compilador não avisa quando uma entidade marcada `[[maybe_unused]]` não é usado. Uma entidade que é declarada sem o atributo pode posteriormente ser declarado novamente com o atributo e vice-versa. Uma entidade é considerada marcado após sua primeira declaração que está marcado como análise e para o restante da tradução da unidade de tradução atual.

## <a name="microsoft-specific-attributes"></a>Atributos específicos da Microsoft

- `[[gsl::suppress(rules)]]` Esse atributo de específico da Microsoft é usado para suprimir avisos do verificadores que impõem [biblioteca de suporte de diretrizes (GSL)](https://github.com/Microsoft/GSL) regras no código. Por exemplo, considere o trecho de código:

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

   - 26494 (tipo de regra 5: sempre inicialize um objeto.)

   - 26485 (limites a regra 3: sem matriz para ponteiro de decaimento.)

   - 26481 (limites regra 1: não use aritmética de ponteiro. Usar o span em vez disso.)

   Os dois primeiros avisos são acionados quando você compilar esse código com a ferramenta de análise de código CppCoreCheck instalado e ativado. Mas o terceiro aviso não dispara devido ao atributo. Você pode suprimir todo o perfil limites escrevendo [[gsl::suppress(bounds)]] sem incluir um número específico de regra. Diretrizes principais do C++ são projetadas para ajudar você a escrever código melhor e mais seguro. O atributo de suprimir torna fácil desativar avisos quando eles não são desejáveis.