---
title: const (C++)
ms.date: 11/04/2016
f1_keywords:
- const_cpp
helpviewer_keywords:
- const keyword [C++]
ms.assetid: b21c0271-1ad0-40a0-b21c-5e812bba0318
ms.openlocfilehash: db79e228f1fabc4b2da0a7778126a1b576a67768
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229032"
---
# <a name="const-c"></a>const (C++)

Ao modificar uma declaração de dados, a **`const`** palavra-chave especifica que o objeto ou a variável não é modificável.

## <a name="syntax"></a>Sintaxe

```
const declaration ;
member-function const ;
```

## <a name="const-values"></a>valores const

A **`const`** palavra-chave especifica que o valor de uma variável é constante e informa ao compilador para impedir que o programador o modifique.

```cpp
// constant_values1.cpp
int main() {
   const int i = 5;
   i = 10;   // C3892
   i++;   // C2105
}
```

Em C++, você pode usar a **`const`** palavra-chave em vez da diretiva de pré-processador de [#define](../preprocessor/hash-define-directive-c-cpp.md) para definir valores constantes. Os valores definidos com **`const`** estão sujeitos à verificação de tipo e podem ser usados no lugar de expressões constantes. Em C++, você pode especificar o tamanho de uma matriz com uma **`const`** variável da seguinte maneira:

```cpp
// constant_values2.cpp
// compile with: /c
const int maxarray = 255;
char store_char[maxarray];  // allowed in C++; not allowed in C
```

Em C, os valores constantes usam como padrão o vínculo externo, assim eles podem aparecer somente em arquivos de origem. Em C++, os valores constantes usam como padrão o vínculo interno, que permite que eles apareçam em arquivos de cabeçalho.

A **`const`** palavra-chave também pode ser usada em declarações de ponteiro.

```cpp
// constant_values3.cpp
int main() {
   char *mybuf = 0, *yourbuf;
   char *const aptr = mybuf;
   *aptr = 'a';   // OK
   aptr = yourbuf;   // C3892
}
```

Um ponteiro para uma variável declarada como **`const`** pode ser atribuído somente a um ponteiro que também é declarado como **`const`** .

```cpp
// constant_values4.cpp
#include <stdio.h>
int main() {
   const char *mybuf = "test";
   char *yourbuf = "test2";
   printf_s("%s\n", mybuf);

   const char *bptr = mybuf;   // Pointer to constant data
   printf_s("%s\n", bptr);

   // *bptr = 'a';   // Error
}
```

Você pode usar ponteiros para os dados constantes como parâmetros de função para evitar que a função modifique um parâmetro passado por um ponteiro.

Para objetos declarados como **`const`** , você só pode chamar funções de membro constantes. Isso assegura que o objeto constante nunca seja modificado.

```cpp
birthday.getMonth();    // Okay
birthday.setMonth( 4 ); // Error
```

Você pode chamar funções membro constantes ou não constantes para um objeto não constante. Você também pode sobrecarregar uma função de membro usando a **`const`** palavra-chave; isso permite que uma versão diferente da função seja chamada para objetos constantes e não constantes.

Você não pode declarar construtores ou destruidores com a **`const`** palavra-chave.

## <a name="const-member-functions"></a>funções de membro const

A declaração de uma função de membro com a **`const`** palavra-chave especifica que a função é uma função "somente leitura" que não modifica o objeto para o qual ela é chamada. Uma função de membro de constante não pode modificar nenhum membro de dados não estático nem chamar funções de membros que não sejam constantes. Para declarar uma função de membro constante, coloque a **`const`** palavra-chave após o parêntese de fechamento da lista de argumentos. A **`const`** palavra-chave é necessária tanto na declaração quanto na definição.

```cpp
// constant_member_function.cpp
class Date
{
public:
   Date( int mn, int dy, int yr );
   int getMonth() const;     // A read-only function
   void setMonth( int mn );   // A write function; can't be const
private:
   int month;
};

int Date::getMonth() const
{
   return month;        // Doesn't modify anything
}
void Date::setMonth( int mn )
{
   month = mn;          // Modifies data member
}
int main()
{
   Date MyDate( 7, 4, 1998 );
   const Date BirthDate( 1, 18, 1953 );
   MyDate.setMonth( 4 );    // Okay
   BirthDate.getMonth();    // Okay
   BirthDate.setMonth( 4 ); // C2662 Error
}
```

## <a name="c-and-c-const-differences"></a>Diferenças entre C e C++ const

Quando você declara uma variável como **`const`** em um arquivo de código-fonte C, você faz isso da seguinte maneira:

```cpp
const int i = 2;
```

Então, você pode usar essa variável em outro módulo como segue:

```cpp
extern const int i;
```

Mas para obter o mesmo comportamento em C++, você deve declarar sua **`const`** variável como:

```cpp
extern const int i = 2;
```

Se você quiser declarar uma **`extern`** variável em um arquivo de código-fonte C++ para uso em um arquivo de código-fonte C, use:

```cpp
extern "C" const int x=10;
```

para evitar a desconfiguração do nome pelo compilador C++.

## <a name="remarks"></a>Comentários

Ao seguir a lista de parâmetros de uma função de membro, a **`const`** palavra-chave especifica que a função não modifica o objeto para o qual ele é invocado.

Para obter mais informações sobre **`const`** o, consulte os seguintes tópicos:

- [Ponteiros const e voláteis](../cpp/const-and-volatile-pointers.md)

- [Qualificadores de tipo (Referência da linguagem C)](../c-language/type-qualifiers.md)

- [volatile](../cpp/volatile-cpp.md)

- [#define](../preprocessor/hash-define-directive-c-cpp.md)

## <a name="see-also"></a>Confira também

[Palavras-chave](../cpp/keywords-cpp.md)
