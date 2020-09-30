---
title: struct (C++)
ms.date: 11/04/2016
f1_keywords:
- struct_cpp
helpviewer_keywords:
- struct constructors
ms.assetid: 3c6ba273-e248-4ff1-8c69-d2abcf1263c6
ms.openlocfilehash: d0092cf107159f4c84b431f5eeae130df64dc835
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91507464"
---
# <a name="struct-c"></a>struct (C++)

A **`struct`** palavra-chave define um tipo de estrutura e/ou uma variável de um tipo de estrutura.

## <a name="syntax"></a>Sintaxe

```
[template-spec] struct [ms-decl-spec] [tag [: base-list ]]
{
   member-list
} [declarators];
[struct] tag declarators;
```

#### <a name="parameters"></a>Parâmetros

*modelo-especificação*<br/>
Especificações de modelo opcionais. Para obter mais informações, consulte [especificações de modelo](templates-cpp.md).

*struct*<br/>
A **`struct`** palavra-chave.

*MS-decl-spec*<br/>
Especificação de classe de armazenamento opcional. Para obter mais informações, consulte a palavra-chave [__declspec](../cpp/declspec.md) .

*marcação*<br/>
O nome do tipo dado à estrutura. A marca se torna uma palavra reservada no escopo da estrutura. A marca é opcional. Se omitida, uma estrutura anônima será definida. Para obter mais informações, consulte [tipos de classe anônima](../cpp/anonymous-class-types.md).

*base-list*<br/>
A lista opcional de classes ou estruturas de que esta estrutura derivará seus membros. Consulte [classes base](../cpp/base-classes.md) para obter mais informações. Cada classe base ou nome de estrutura pode ser precedido por um especificador de acesso ([público](../cpp/public-cpp.md), [privado](../cpp/private-cpp.md), [protegido](../cpp/protected-cpp.md)) e a palavra-chave [virtual](../cpp/virtual-cpp.md) . Consulte a tabela de acesso de membro em [controlando o acesso a membros de classe](member-access-control-cpp.md) para obter mais informações.

*lista de membros*<br/>
Lista de membros da estrutura. Consulte [visão geral de membro de classe](../cpp/class-member-overview.md) para obter mais informações. A única diferença aqui é que **`struct`** é usada no lugar de **`class`** .

*declarators*<br/>
Lista de declaradores especificando os nomes da estrutura. As listas de declaradores declaram uma ou mais instâncias do tipo de estrutura. Os declaradores podem incluir listas de inicializador se todos os membros de dados da estrutura forem **`public`** . As listas de inicializadores são comuns em estruturas porque os membros de dados são **`public`** por padrão.  Consulte [visão geral dos declaradores](./declarations-and-definitions-cpp.md) para obter mais informações.

## <a name="remarks"></a>Comentários

Um tipo de estrutura é um tipo composto definido pelo usuário. É composto de campos ou membros que podem ter tipos diferentes.

Em C++, uma estrutura é igual a uma classe, exceto que seus membros são **`public`** por padrão.

Para obter informações sobre classes e estruturas gerenciadas em C++/CLI, consulte [classes e estruturas](../extensions/classes-and-structs-cpp-component-extensions.md).

## <a name="using-a-structure"></a>Usando uma estrutura

Em C, você deve usar explicitamente a **`struct`** palavra-chave para declarar uma estrutura. Em C++, você não precisa usar a **`struct`** palavra-chave após a definição do tipo.

Há também a opção de declarar variáveis quando o tipo de estrutura é definido colocando um ou vários nomes de variável separados por vírgulas entre a chave de fechamento e o ponto-e-vírgula.

As variáveis de estrutura podem ser inicializadas. A inicialização de cada variável deve ser incluída entre chaves.

Para obter informações relacionadas, consulte [Class](../cpp/class-cpp.md), [Union](../cpp/unions.md)e [enum](../cpp/enumerations-cpp.md).

## <a name="example"></a>Exemplo

```cpp
#include <iostream>
using namespace std;

struct PERSON {   // Declare PERSON struct type
    int age;   // Declare member types
    long ss;
    float weight;
    char name[25];
} family_member;   // Define object of type PERSON

struct CELL {   // Declare CELL bit field
    unsigned short character  : 8;  // 00000000 ????????
    unsigned short foreground : 3;  // 00000??? 00000000
    unsigned short intensity  : 1;  // 0000?000 00000000
    unsigned short background : 3;  // 0???0000 00000000
    unsigned short blink      : 1;  // ?0000000 00000000
} screen[25][80];       // Array of bit fields

int main() {
    struct PERSON sister;   // C style structure declaration
    PERSON brother;   // C++ style structure declaration
    sister.age = 13;   // assign values to members
    brother.age = 7;
    cout << "sister.age = " << sister.age << '\n';
    cout << "brother.age = " << brother.age << '\n';

    CELL my_cell;
    my_cell.character = 1;
    cout << "my_cell.character = " << my_cell.character;
}
// Output:
// sister.age = 13
// brother.age = 7
// my_cell.character = 1
```
