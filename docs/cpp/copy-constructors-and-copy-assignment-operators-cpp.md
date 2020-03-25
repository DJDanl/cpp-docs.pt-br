---
title: Operadores de construtores de cópia e de atribuição de cópia (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- = operator [C++], copying objects
- assignment statements [C++], copying objects
- assignment operators [C++], for copying objects
- objects [C++], copying
- initializing objects, by copying objects
- copying objects
- assigning values to copy objects
ms.assetid: a94fe1f9-0289-4fb9-8633-77c654002c0d
ms.openlocfilehash: beabe4c6219975d33c7af98a94498188c9abfa55
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80189515"
---
# <a name="copy-constructors-and-copy-assignment-operators-c"></a>Operadores de construtores de cópia e de atribuição de cópia (C++)

> [!NOTE]
> A partir do C++ 11, há suporte para dois tipos de atribuição no idioma: *copiar atribuição* e *mover atribuição*. Neste artigo, "atribuição" significa a atribuição de cópia, a menos que explicitamente declarado de outra forma. Para obter informações sobre como mover a atribuição, consulte [mover construtores e mover operadoresC++de atribuição ()](move-constructors-and-move-assignment-operators-cpp.md).
>
> Tanto a operação de atribuição como a operação de inicialização fazem com que os objetos sejam copiados.

- **Atribuição**: quando o valor de um objeto é atribuído a outro objeto, o primeiro objeto é copiado para o segundo objeto. Portanto:

    ```cpp
    Point a, b;
    ...
    a = b;
    ```

   faz com que o valor de `b` seja copiado para `a`.

- **Inicialização**: a inicialização ocorre quando um novo objeto é declarado, quando argumentos são passados para funções por valor ou quando valores são retornados de funções por valor.

Você pode definir a semântica de “cópia” para objetos do tipo classe. Por exemplo, considere este código:

```cpp
TextFile a, b;
a.Open( "FILE1.DAT" );
b.Open( "FILE2.DAT" );
b = a;
```

O código anterior poderia significar “copiar o conteúdo de FILE1.DAT para FILE2.DAT” ou “ignore FILE2.DAT e faça de `b` um segundo manipulador para FILE1.DAT”. Você deve anexar a semântica de cópia apropriada a cada classe, da seguinte maneira.

- Usando o operador de atribuição **Operator =** junto com uma referência ao tipo de classe como o tipo de retorno e o parâmetro que é passado pela referência **const** — por exemplo `ClassName& operator=(const ClassName& x);`.

- Usando o construtor de cópia.

Se você não declarar um construtor de cópia, o compilador gerará um construtor de cópia por membro para você.  Se você não declarar um operador de atribuição de cópia, o compilador gerará um operador de atribuição de cópia de membro para você. A declaração de um construtor de cópia não suprime o operador de atribuição de cópia gerado pelo compilador, e vice-versa. Se você implementar um deles, recomendamos que você também implemente o outro para que o significado do código seja claro.

O construtor de cópia usa um argumento do tipo <em>class-name</em> <strong>&</strong>, em que *Class-Name* é o nome da classe para a qual o Construtor está definido. Por exemplo:

```cpp
// spec1_copying_class_objects.cpp
class Window
{
public:
    Window( const Window& ); // Declare copy constructor.
    // ...
};

int main()
{
}
```

> [!NOTE]
> Torne o tipo do argumento **const** do construtor de cópia <em>-nome</em> <strong>&</strong> sempre que possível. Isso evita que o construtor de cópia altere acidentalmente o objeto que está copiando. Ele também permite copiar de objetos **const** .

## <a name="compiler-generated-copy-constructors"></a>Construtores de cópia gerados pelo compilador

Os construtores de cópia gerados pelo compilador, como construtores de cópia definidos pelo usuário, têm um único argumento do tipo "Reference to *Class-Name*". Uma exceção é quando todas as classes base e classes de membro têm construtores de cópia declarados como tendo um único argumento do tipo **const** <em>-Name</em> <strong>&</strong>. Nesse caso, o argumento do construtor de cópia gerado pelo compilador também é **const**.

Quando o tipo de argumento para o construtor de cópia não é **const**, a inicialização copiando um objeto **const** gera um erro. O inverso não é verdadeiro: se o argumento for **const**, você poderá inicializar copiando um objeto que não seja **const**.

Os operadores de atribuição gerados pelo compilador seguem o mesmo padrão em relação à **const.** Eles usam um único argumento do tipo <em>class-name</em> <strong>&</strong> , a menos que os operadores de atribuição em todas as classes base e de membro tomem argumentos do tipo **const** <em>Class-Name</em> <strong>&</strong>. Nesse caso, o operador de atribuição gerado pela classe usa um argumento **const** .

> [!NOTE]
> Quando classes básicas virtuais são inicializadas por construtores de cópia, geradas pelo compilador ou definidas pelo usuário, elas são inicializadas somente uma vez: no ponto em que são construídas.

As implicações são semelhantes às do construtor de cópia. Quando o tipo de argumento não é **const**, a atribuição de um objeto **const** gera um erro. O inverso não é verdadeiro: se um valor **const** for atribuído a um valor que não seja **const**, a atribuição terá sucesso.

Para obter mais informações sobre operadores de atribuição sobrecarregados, consulte [atribuição](../cpp/assignment.md).
