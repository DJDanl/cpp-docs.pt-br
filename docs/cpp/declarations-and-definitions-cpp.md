---
title: Declarações e definições (C++)
ms.date: 12/12/2019
ms.assetid: 678f1424-e12f-45e0-a957-8169e5fef6cb
ms.openlocfilehash: d52294b635e05f42a4c48620214a90cad609f575
ms.sourcegitcommit: a5fa9c6f4f0c239ac23be7de116066a978511de7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75301542"
---
# <a name="declarations-and-definitions-c"></a>Declarações e definições (C++)

Um C++ programa consiste em várias entidades, como variáveis, funções, tipos e namespaces. Cada uma dessas entidades deve ser *declarada* antes que possa ser usada. Uma declaração especifica um nome exclusivo para a entidade, juntamente com informações sobre seu tipo e outras características. No C++ ponto em que um nome é declarado é o ponto em que ele se torna visível para o compilador. Não é possível fazer referência a uma função ou classe declarada em algum momento posterior na unidade de compilação. As variáveis devem ser declaradas o mais próximo possível antes do ponto em que são usadas.

O exemplo a seguir mostra algumas declarações:

```cpp
#include <string>

void f(); // forward declaration

int main()
{
    const double pi = 3.14; //OK
    int i = f(2); //OK. f is forward-declared
    std::string str; // OK std::string is declared in <string> header
    C obj; // error! C not yet declared.
    j = 0; // error! No type specified.
    auto k = 0; // OK. type inferred as int by compiler.
}

int f(int i)
{
    return i + 42;
}

namespace N {
   class C{/*...*/};
}
```

Na linha 5, a função `main` é declarada. Na linha 7, uma variável **const** chamada `pi` é declarada e *inicializada*. Na linha 8, um inteiro `i` é declarado e inicializado com o valor produzido pela função `f`. O nome `f` é visível para o compilador devido à *declaração de encaminhamento* na linha 3. 

Na linha 9, uma variável chamada `obj` do tipo `C` é declarada. No entanto, essa declaração gera um erro porque `C` não é declarada até mais tarde no programa e não é declarada de encaminhamento. Para corrigir o erro, você pode mover toda a *definição* de `C` antes de `main` ou adicionar uma declaração de encaminhamento para ele. Esse comportamento é diferente de outras linguagens, C#como, em que funções e classes podem ser usadas antes de seu ponto de declaração em um arquivo de origem. 

Na linha 10, uma variável chamada `str` do tipo `std::string` é declarada. O nome `std::string` é visível porque é introduzido no [arquivo de cabeçalho](header-files-cpp.md) `string` que é mesclado no arquivo de origem na linha 1. `std` é o namespace no qual a classe `string` é declarada.

Na linha 11, um erro é gerado porque o nome `j` não foi declarado. Uma declaração deve fornecer um tipo, diferente de outras linguagens, como javaScript. Na linha 12, a palavra-chave `auto` é usada, o que informa ao compilador para inferir o tipo de `k` com base no valor com o qual ele foi inicializado. Nesse caso, o compilador escolhe `int` para o tipo.  

## <a name="declaration-scope"></a>Escopo de declaração

O nome que é introduzido por uma declaração é válido dentro do *escopo* onde a declaração ocorre. No exemplo anterior, as variáveis que são declaradas dentro da função `main` são *variáveis locais*. Você pode declarar outra variável chamada `i` fora do principal, no *escopo global*, e seria uma entidade completamente separada. No entanto, essa duplicação de nomes pode levar à confusão e aos erros do programador e deve ser evitada. Na linha 21, a classe `C` é declarada no escopo do namespace `N`. O uso de namespaces ajuda a evitar *colisões de nomes*. A C++ maioria dos nomes de biblioteca padrão é declarada dentro do namespace `std`. Para obter mais informações sobre como as regras de escopo interagem com declarações, consulte [escopo](../cpp/scope-visual-cpp.md).

## <a name="definitions"></a>Definições

Algumas entidades, incluindo funções, classes, enums e variáveis constantes, devem ser definidas além de serem declaradas. Uma *definição* fornece ao compilador todas as informações necessárias para gerar o código do computador quando a entidade é usada posteriormente no programa. No exemplo anterior, a linha 3 contém uma declaração para a função `f`, mas a *definição* da função é fornecida nas linhas de 15 a 18. Na linha 21, a classe `C` é declarada e definida (embora conforme definido, a classe não faz nada). Uma variável Constant deve ser definida, em outras palavras, um valor atribuído, na mesma instrução em que é declarada. Uma declaração de um tipo interno como `int` é automaticamente uma definição porque o compilador sabe quanto espaço alocar para ele.

O exemplo a seguir mostra declarações que também são definições:

```cpp
// Declare and define int variables i and j.
int i;
int j = 10;

// Declare enumeration suits.
enum suits { Spades = 1, Clubs, Hearts, Diamonds };

// Declare class CheckBox.
class CheckBox : public Control
{
public:
    Boolean IsChecked();
    virtual int     ChangeState() = 0;
};
```

Aqui estão algumas declarações que não são definições:

```cpp
extern int i;
char *strchr( const char *Str, const char Target );
```

## <a name="typedefs-and-using-statements"></a>TYPEDEFs e instruções using

Em versões mais antigas C++do, a palavra-chave [typedef](aliases-and-typedefs-cpp.md) é usada para declarar um novo nome que é um *alias* para outro nome. Por exemplo, o tipo `std::string` é outro nome para `std::basic_string<char>`. Deve ser óbvio por que os programadores usam o nome do typedef e não o nome real. No moderno C++, a palavra-chave [using](aliases-and-typedefs-cpp.md) é preferida sobre typedef, mas a ideia é a mesma: um novo nome é declarado para uma entidade que já está declarada e definida.

## <a name="static-class-members"></a>Membros de classe estática

Como os membros de dados de classe estática são variáveis discretas compartilhadas por todos os objetos da classe, eles devem ser definidos e inicializados fora da definição de classe. (Para obter mais informações, consulte [classes](../cpp/classes-and-structs-cpp.md).)

## <a name="extern-declarations"></a>declarações extern

Um C++ programa pode conter mais de uma [unidade de compilação](header-files-cpp.md). Para declarar uma entidade que é definida em uma unidade de compilação separada, use a palavra-chave [extern](extern-cpp.md) . As informações na declaração são suficientes para o compilador, mas se a definição da entidade não puder ser encontrada na etapa de vinculação, o vinculador gerará um erro.

## <a name="in-this-section"></a>Nesta seção

[Classes de armazenamento](storage-classes-cpp.md)<br/>
[const](const-cpp.md)<br/>
[constexpr](constexpr-cpp.md)<br/>
[extern](extern-cpp.md)<br/>
[Inicializadores](initializers.md)<br/>
[Aliases e typedefs](aliases-and-typedefs-cpp.md)<br/>
[usando declaração](using-declaration.md)<br/>
[volatile](volatile-cpp.md)<br/>
[decltype](decltype-cpp.md)<br/>
[Atributos emC++](attributes.md)<br/>

## <a name="see-also"></a>Veja também

[Conceitos básicos](../cpp/basic-concepts-cpp.md)<br/>
