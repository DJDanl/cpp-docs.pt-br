---
title: Escopo (C++) | Microsoft Docs
ms.custom: ''
ms.date: 04/08/2018
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- classes [C++], scope
- scope [C++]
- function prototypes [C++], scope
- class scope
- prototype scope
- functions [C++], scope
- scope, C++ names
ms.assetid: 81fecbb0-338b-4325-8332-49f33e716352
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: eb9d21eee8e561e2caa8a7c4088774435d3ce273
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46080435"
---
# <a name="scope-c"></a>Escopo (C++)

Quando você declara um elemento de programa, como uma classe, função ou variável, seu nome só pode "Vista" e usado em certas partes do seu programa. O contexto no qual um nome é visível é chamado seu *escopo*. Por exemplo, se você declarar uma variável `x` dentro de uma função, `x` só é visível dentro do corpo da função. Ele tem *escopo local*. Você pode ter outras variáveis com o mesmo nome em seu programa; desde que eles estão em escopos diferentes, eles não violem uma regra de definição e nenhum erro será gerado.

Para as variáveis automáticas não-estático, o escopo também determina quando eles são criados e destruídos na memória de programa.

Há seis tipos de escopo:

- **Escopo global** um nome global é aquele que é declarado fora de qualquer classe, função ou namespace. No entanto, em C++, mesmo que esses nomes existem com um namespace global implícito. Estende o escopo de nomes globais do ponto de declaração até o final do arquivo no qual elas são declaradas. Para nomes globais, visibilidade também é regida pelas regras da [vinculação](program-and-linkage-cpp.md) que determinam se o nome é visível em outros arquivos no programa.

- **Escopo de Namespace** um nome que é declarado dentro de um [namespace](namespaces-cpp.md), fora de qualquer definição de classe ou enumeração ou bloco de função é visível do ponto de declaração até o final do namespace. Um namespace pode ser definido em vários blocos em arquivos diferentes.

- **Escopo local** um nome declarado em uma função ou lambda, incluindo os nomes de parâmetro, têm escopo local. Eles são geralmente denominados "locais". Eles são visíveis apenas de seu ponto de declaração até o final do corpo da função ou lambda. Escopo local é um tipo de escopo de bloco, que é abordado neste artigo.

- **Escopo de classe** nomes de membros de classe têm escopo de classe, que se estende em toda a definição de classe, independentemente do ponto de declaração. Acessibilidade de membro de classe é mais controlada pela **pública**, **privada**, e **protegido** palavras-chave. Membros públicos ou protegidos podem ser acessados usando os operadores de seleção de membro (**.** ou **->**) ou operadores de ponteiro para membro (**.** <strong>\*</strong> ou **->** <strong>\*</strong>).

- **Escopo da instrução** nomes declarados em uma **para**, **se**, **enquanto**, ou **alternar** instrução são visíveis até o final das bloco de instrução.

- **Escopo de função** um [rótulo](labeled-statements.md) tem escopo de função, o que significa que ela é visível durante um corpo de função mesmo antes de ponto de declaração. Escopo da função torna possível escrever instruções, como `goto cleanup` antes do `cleanup` rótulo é declarado.

## <a name="hiding-names"></a>Ocultando nomes

Você pode ocultar um nome declarando-o em um bloco fechado. Na figura a seguir, `i` é redeclarado dentro do bloco interno, ocultando assim a variável associada a `i` no escopo do bloco externo.

![Bloco&#45;definir o escopo de ocultação de nome](../cpp/media/vc38sf1.png "vc38SF1") escopo de bloco e ocultação de nome

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

É possível ocultar nomes de classe declarando uma função, um objeto, uma variável ou um enumerador no mesmo escopo. No entanto, o nome de classe pode ainda ser acessado quando precedido da palavra-chave **classe**.

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

    cout << "Opening account with balance of: "
         << Checking.GetBalance() << "\n";
}
//Output: Opening account with balance of: 15.37
```

> [!NOTE]
> Qualquer lugar que o nome de classe (`Account`) for chamado, a palavra-chave class deve ser usada para diferenciá-lo de que a conta de variável no escopo global. Essa regra não se aplica quando o nome de classe ocorre no lado esquerdo do operador de resolução de escopo (::). Os nomes no lado esquerdo do operador de resolução de escopo são sempre considerados nomes de classe.

O exemplo a seguir demonstra como declarar um ponteiro para um objeto do tipo `Account` usando o **classe** palavra-chave:

```cpp
class Account *Checking = new class Account( Account );
```

O `Account` no inicializador (entre parênteses) na instrução anterior tem escopo global; ela é do tipo **duplo**.

> [!NOTE]
> A reutilização de nomes de identificadores como mostrada neste exemplo é considerada um estilo de programação ruim.

Para obter informações sobre declaração e inicialização de objetos de classe, consulte [Classes, estruturas e uniões](../cpp/classes-and-structs-cpp.md). Para obter informações sobre como usar o **novos** e **excluir** operadores de armazenamento livre, consulte [novo e excluir operadores](new-and-delete-operators.md).

## <a name="hiding-names-with-global-scope"></a>Ocultando nomes com escopo global

Você pode ocultar nomes com escopo global, declarando explicitamente o mesmo nome no escopo de bloco. No entanto, os nomes de escopo global podem ser acessados usando o operador de resolução de escopo (`::`).

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

## <a name="see-also"></a>Consulte também

[Conceitos básicos](../cpp/basic-concepts-cpp.md)