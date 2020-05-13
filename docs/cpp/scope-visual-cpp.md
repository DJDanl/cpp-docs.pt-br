---
title: Escopo (C++)
ms.date: 11/19/2018
helpviewer_keywords:
- classes [C++], scope
- scope [C++]
- function prototypes [C++], scope
- class scope
- prototype scope
- functions [C++], scope
- scope, C++ names
ms.assetid: 81fecbb0-338b-4325-8332-49f33e716352
ms.openlocfilehash: a5b5601c89991fbe1a148ebaf781fe2ad6a9dfc4
ms.sourcegitcommit: c4cf8976939dd0e13e25b82930221323ba6f15d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/12/2020
ms.locfileid: "83204130"
---
# <a name="scope-c"></a>Escopo (C++)

Quando você declara um elemento Program, como uma classe, uma função ou uma variável, seu nome só pode ser "visto" e usado em determinadas partes do seu programa. O contexto no qual um nome é visível é chamado de seu *escopo*. Por exemplo, se você declarar uma variável `x` dentro de uma função, `x` só será visível dentro desse corpo de função. Ele tem *escopo local*. Você pode ter outras variáveis com o mesmo nome em seu programa; Contanto que estejam em escopos diferentes, eles não violam a regra de uma definição e nenhum erro é gerado.

Para variáveis não estáticas automáticas, o escopo também determina quando elas são criadas e destruídas na memória do programa.

Há seis tipos de escopo:

- **Escopo global** Um nome global é aquele declarado fora de qualquer classe, função ou namespace. No entanto, em C++ mesmo esses nomes existem com um namespace global implícito. O escopo de nomes globais se estende do ponto de declaração até o final do arquivo no qual eles são declarados. Para nomes globais, a visibilidade também é regida pelas regras de [ligação](program-and-linkage-cpp.md) que determinam se o nome está visível em outros arquivos no programa.

- **Escopo do namespace** Um nome que é declarado dentro de um [namespace](namespaces-cpp.md), fora de qualquer definição de classe ou de enumeração ou bloco de função, é visível de seu ponto de declaração até o final do namespace. Um namespace pode ser definido em vários blocos em arquivos diferentes.

- **Escopo local** Um nome declarado em uma função ou lambda, incluindo os nomes de parâmetro, tem escopo local. Eles são geralmente chamados de "locais". Eles só ficam visíveis do ponto de declaração até o fim da função ou do corpo lambda. Escopo local é um tipo de escopo de bloco, que é discutido posteriormente neste artigo.

- **Escopo de classe** Os nomes dos membros da classe têm escopo de classe, que se estende por toda a definição de classe, independentemente do ponto de declaração. A acessibilidade de membros de classe é mais controlada pelas palavras-chave **pública**, **privada**e **protegida** . Membros públicos ou protegidos só podem ser acessados usando os operadores de seleção de Membros (**.** or **->** ) ou operadores de ponteiro para membro (**.** <strong>\*</strong> ou **->** <strong>\*</strong> ).

- **Escopo da instrução** Nomes declarados em uma instrução **for**, **If**, **while**ou **switch** são visíveis até o final do bloco de instrução.

- **Escopo da função** Um [rótulo](labeled-statements.md) tem um escopo de função, o que significa que ele é visível em todo um corpo de função, mesmo antes de seu ponto de declaração. O escopo da função torna possível escrever instruções como `goto cleanup` antes de o `cleanup` rótulo ser declarado.

## <a name="hiding-names"></a>Ocultando nomes

Você pode ocultar um nome declarando-o em um bloco fechado. Na figura a seguir, `i` é redeclarado dentro do bloco interno, ocultando assim a variável associada a `i` no escopo do bloco externo.

![Ocultar nome do escopo de&#45;de bloco](../cpp/media/vc38sf1.png "Ocultar nome do escopo de&#45;de bloco") <br/>
Ocultar o escopo e o nome do bloco

O resultado do programa mostrado na figura é:

```cpp
i = 0
i = 7
j = 9
i = 0
```

> [!NOTE]
> O argumento `szWhat` é considerado como presente no escopo da função. Portanto, ele será tratado como se tivesse sido declarado no bloco externo da função.

## <a name="hiding-class-names"></a>Ocultando nomes de classe

É possível ocultar nomes de classe declarando uma função, um objeto, uma variável ou um enumerador no mesmo escopo. No entanto, o nome da classe ainda pode ser acessado quando prefixado pela **classe**Keyword.

```cpp
// hiding_class_names.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

// Declare class Account at global scope.
class Account
{
public:
    Account( double InitialBalance )
        { balance = InitialBalance; }
    double GetBalance()
        { return balance; }
private:
    double balance;
};

double Account = 15.37;            // Hides class name Account

int main()
{
    class Account Checking( Account ); // Qualifies Account as
                                       //  class name

    cout << "Opening account with a balance of: "
         << Checking.GetBalance() << "\n";
}
//Output: Opening account with a balance of: 15.37
```

> [!NOTE]
> Qualquer lugar ao qual o nome de classe ( `Account` ) é chamado, a classe keyword deve ser usada para diferenciá-lo da conta variável com escopo global. Essa regra não se aplica quando o nome de classe ocorre no lado esquerdo do operador de resolução de escopo (::). Os nomes no lado esquerdo do operador de resolução de escopo são sempre considerados nomes de classe.

O exemplo a seguir demonstra como declarar um ponteiro para um objeto do tipo `Account` usando a palavra-chave **Class** :

```cpp
class Account *Checking = new class Account( Account );
```

O `Account` no inicializador (entre parênteses) na instrução anterior tem escopo global; ele é do tipo **Double**.

> [!NOTE]
> A reutilização de nomes de identificadores como mostrada neste exemplo é considerada um estilo de programação ruim.

Para obter informações sobre a declaração e a inicialização de objetos de classe, consulte [classes, estruturas e uniões](../cpp/classes-and-structs-cpp.md). Para obter informações sobre como usar os operadores **novo** e **excluir** do armazenamento gratuito, consulte [operadores New e Delete](new-and-delete-operators.md).

## <a name="hiding-names-with-global-scope"></a>Ocultando nomes com escopo global

Você pode ocultar nomes com escopo global declarando explicitamente o mesmo nome no escopo do bloco. No entanto, os nomes de escopo global podem ser acessados usando o operador de resolução de escopo ( `::` ).

```cpp
#include <iostream>

int i = 7;   // i has global scope, outside all blocks
using namespace std;

int main( int argc, char *argv[] ) {
   int i = 5;   // i has block scope, hides i at global scope
   cout << "Block-scoped i has the value: " << i << "\n";
   cout << "Global-scoped i has the value: " << ::i << "\n";
}
```

```Output
Block-scoped i has the value: 5
Global-scoped i has the value: 7
```

## <a name="see-also"></a>Veja também

[Conceitos básicos](../cpp/basic-concepts-cpp.md)
