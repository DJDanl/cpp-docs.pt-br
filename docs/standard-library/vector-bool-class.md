---
title: Classe vector&lt;bool&gt;
ms.date: 11/04/2016
f1_keywords:
- vector<bool>
- vector/std::vector::flip
helpviewer_keywords:
- std::vector [C++], const_pointer
- std::vector [C++], const_reference
- std::vector [C++], pointer
- std::vector [C++], flip
- std::vector [C++], swap
ms.assetid: 8028c8ed-ac9c-4f06-aba1-5de45c00aafb
ms.openlocfilehash: 7819c8c2ebe8a07a76e242ea2ef3c19206ab69be
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211990"
---
# <a name="vectorltboolgt-class"></a>Classe vector&lt;bool&gt;

A `vector<bool>` classe é uma especialização parcial do [vetor](../standard-library/vector-class.md) para elementos do tipo **`bool`** . Ele tem um alocador para o tipo subjacente usado pela especialização, que fornece otimização de espaço armazenando um **`bool`** valor por bit.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Allocator = allocator<bool>>
class vector<bool, Allocator>
```

## <a name="remarks"></a>Comentários

Essa especialização de modelo de classe se comporta como vector, exceto pelas diferenças explicadas neste artigo.

As operações que lidam com o **`bool`** tipo correspondem aos valores no armazenamento de contêiner. `allocator_traits::construct` não é usado para construir esses valores.

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[const_pointer](#const_pointer)|Um typedef para um `const_iterator` que pode funcionar como um ponteiro de constante para um elemento booliano do `vector<bool>`.|
|[const_reference](#const_reference)|Um typedef para **`bool`** . Depois da inicialização, ele não observa atualizações no valor original.|
|[refere](#pointer)|Um typedef para um `iterator` que pode funcionar como um ponteiro para um elemento booliano do `vector<bool>`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[flip](#flip)|Inverte todos os bits no `vector<bool>`.|
|[permuta](#swap)|Troca os elementos de dois `vector<bool>`s.|
|[operator&#91;&#93;](#op_at)|Retorna uma referência simulada para o elemento `vector<bool>` em uma posição especificada.|
|`at`|O funciona da mesma forma que a função [vetor](../standard-library/vector-class.md):: at não especializada, exceto pelo fato de que ele usa a classe proxy [vector \<bool> :: Reference](#reference_class). Consulte também [operator&#91;&#93;](#op_at).|
|`front`|O funciona da mesma forma que a função [vector](../standard-library/vector-class.md):: Front não especializada, exceto pelo fato de que ela usa a classe proxy [vector \<bool> :: Reference](#reference_class). Consulte também [operator&#91;&#93;](#op_at).|
|`back`|O funciona da mesma forma que a função [vector](../standard-library/vector-class.md):: back não especializada, exceto pelo fato de que ela usa a classe proxy [vector \<bool> :: Reference](#reference_class). Consulte também [operator&#91;&#93;](#op_at).|

### <a name="proxy-class"></a>Classe proxy

|||
|-|-|
|[Classe de referência de vetor \<bool>](#reference_class)|Uma classe que atua como um proxy para simular o comportamento de `bool&` e cujos objetos podem fornecer referências a elementos (bits únicos) em um objeto `vector<bool>`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho**:\<vector>

**Namespace:** std

## <a name="vectorboolconst_pointer"></a><a name="const_pointer"></a>vetor \<bool> :: const_pointer

Um tipo que descreve um objeto que pode servir como um ponteiro de constante para um elemento booliano da sequência contida pelo objeto `vector<bool>`.

```cpp
typedef const_iterator const_pointer;
```

## <a name="vectorboolconst_reference"></a><a name="const_reference"></a>vetor \<bool> :: const_reference

Um tipo que descreve um objeto que pode servir como uma referência de constante para um elemento booliano da sequência contida pelo objeto `vector<bool>`.

```cpp
typedef bool const_reference;
```

### <a name="remarks"></a>Comentários

Para obter mais informações e exemplos de código, consulte [vector&lt;bool&gt;::reference::operator=](#reference_operator_eq).

## <a name="vectorboolflip"></a><a name="flip"></a>vetor \<bool> :: Flip

Inverte todos os bits em um `vector<bool>`.

```cpp
void flip();
```

### <a name="example"></a>Exemplo

```cpp
// vector_bool_flip.cpp
// compile with: /EHsc /W4
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    cout << boolalpha; // format output for subsequent code

    vector<bool> vb = { true, false, false, true, true };
    cout << "The vector is:" << endl << "    ";
    for (const auto& b : vb) {
        cout << b << " ";
    }
    cout << endl;

    vb.flip();

    cout << "The flipped vector is:" << endl << "    ";
    for (const auto& b : vb) {
        cout << b << " ";
    }
    cout << endl;
}
```

## <a name="vectorbooloperator"></a><a name="op_at"></a>vector \<bool> :: operator []

Retorna uma referência simulada para o elemento `vector<bool>` em uma posição especificada.

```cpp
vector<bool>::reference operator[](size_type Pos);

vector&<bool&>::const_reference operator[](size_type Pos) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|DESCRIÇÃO|
|-|-|
|*Pos*|A posição do elemento `vector<bool>`.|

### <a name="return-value"></a>Valor retornado

Um objeto [vector \<bool> :: Reference](#reference_class) ou [vector \<bool> :: const_reference](#const_reference) que contém o valor do elemento indexado.

Se a posição especificada for maior ou igual ao tamanho do contêiner, o resultado será indefinido.

### <a name="remarks"></a>Comentários

Se você compilar com _ITERATOR_DEBUG_LEVEL definido, ocorrerá um erro em tempo de execução se você tentar acessar um elemento fora dos limites do vetor.  Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

Este exemplo de código mostra o uso correto de `vector<bool>::operator[]` e dois erros comuns de codificação, que são comentados. Esses erros causam erros porque o endereço do `vector<bool>::reference` objeto que `vector<bool>::operator[]` retorna não pode ser obtido.

```cpp
// cl.exe /EHsc /nologo /W4 /MTd
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    cout << boolalpha;
    vector<bool> vb;

    vb.push_back(true);
    vb.push_back(false);

    //    bool* pb = &vb[1]; // conversion error - do not use
    //    bool& refb = vb[1];   // conversion error - do not use
    bool hold = vb[1];
    cout << "The second element of vb is " << vb[1] << endl;
    cout << "The held value from the second element of vb is " << hold << endl;

    // Note this doesn't modify hold.
    vb[1] = true;
    cout << "The second element of vb is " << vb[1] << endl;
    cout << "The held value from the second element of vb is " << hold << endl;
}
```

## <a name="vectorboolpointer"></a><a name="pointer"></a>vetor \<bool> ::p ointer

Um tipo que descreve um objeto que pode servir como um ponteiro para um elemento booliano da sequência contida pelo objeto `vector<bool>`.

```cpp
typedef iterator pointer;
```

## <a name="vectorboolreference-class"></a><a name="reference_class"></a>\<bool>classe vector:: Reference

A `vector<bool>::reference` classe é uma classe de proxy fornecida pela [ \<bool> classe vector](../standard-library/vector-bool-class.md) para simular `bool&` .

### <a name="remarks"></a>Comentários

Uma referência simulada é necessária porque o C++ não permite nativamente referências diretas aos bits. `vector<bool>` usa apenas um bit por elemento, que pode ser referenciado usando essa classe proxy. No entanto, a simulação de referência não é concluída porque determinadas atribuições não são válidas. Por exemplo, como o endereço do `vector<bool>::reference` objeto não pode ser obtido, o código a seguir que usa [vector \<bool> :: Operator&#91;&#93;](#op_at) não está correto:

```cpp
vector<bool> vb;
//...
bool* pb = &vb[1]; // conversion error - do not use
bool& refb = vb[1];   // conversion error - do not use
```

### <a name="vectorboolreferenceflip"></a><a name="reference_flip"></a>vector \<bool> :: Reference:: Flip

Inverte o valor booliano de um elemento [de \<bool> vetor](../standard-library/vector-bool-class.md) referenciado.

```cpp
void flip();
```

#### <a name="example"></a>Exemplo

```cpp
// vector_bool_ref_flip.cpp
// compile with: /EHsc /W4
#include <vector>
#include <iostream>

int main()
{
    using namespace std;
    cout << boolalpha;

    vector<bool> vb = { true, false, false, true, true };

    cout << "The vector is: " << endl << "    ";
    for (const auto& b : vb) {
        cout << b << " ";
    }
    cout << endl;

    vector<bool>::reference vbref = vb.front();
    vbref.flip();

    cout << "The vector with first element flipped is: " << endl << "    ";
    for (const auto& b : vb) {
        cout << b << " ";
    }
    cout << endl;
}
```

```Output
The vector is:
    true false false true true
The vector with first element flipped is:
    false false false true true
```

### <a name="vectorboolreferenceoperator-bool"></a><a name="reference_operator_bool"></a>vector \<bool> :: Reference:: Operator bool

Fornece uma conversão implícita de `vector<bool>::reference` para **`bool`** .

```cpp
operator bool() const;
```

#### <a name="return-value"></a>Valor retornado

O valor booliano do elemento do objeto de vetor \<bool> .

#### <a name="remarks"></a>Comentários

O objeto `vector<bool>` não pode ser modificado por esse operador.

### <a name="vectorboolreferenceoperator"></a><a name="reference_operator_eq"></a>vector \<bool> :: Reference:: Operator =

Atribui um valor booliano a um bit ou o valor mantido por um elemento referenciado para um bit.

```cpp
reference& operator=(const reference& Right);
reference& operator=(bool Val);
```

### <a name="parameters"></a>parâmetros

*Certo*\
A referência de elemento cujo valor deve ser atribuído ao bit.

*Val*\
O valor booliano a ser atribuído ao bit.

#### <a name="example"></a>Exemplo

```cpp
// vector_bool_ref_op_assign.cpp
// compile with: /EHsc
#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <typename C> void print(const string& s, const C& c) {
    cout << s;

    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

int main()
{
    cout << boolalpha;

    vector<bool> vb = { true, false, false, true, true };

    print("The vector is: ", vb);

    // Invoke vector<bool>::reference::operator=()
    vector<bool>::reference refelem1 = vb[0];
    vector<bool>::reference refelem2 = vb[1];
    vector<bool>::reference refelem3 = vb[2];

    bool b1 = refelem1;
    bool b2 = refelem2;
    bool b3 = refelem3;
    cout << "The original value of the 1st element stored in a bool: " << b1 << endl;
    cout << "The original value of the 2nd element stored in a bool: " << b2 << endl;
    cout << "The original value of the 3rd element stored in a bool: " << b3 << endl;
    cout << endl;

    refelem2 = refelem1;

    print("The vector after assigning refelem1 to refelem2 is now: ", vb);

    refelem3 = true;

    print("The vector after assigning false to refelem1 is now: ", vb);

    // The initial values are still stored in the bool variables and remained unchanged
    cout << "The original value of the 1st element still stored in a bool: " << b1 << endl;
    cout << "The original value of the 2nd element still stored in a bool: " << b2 << endl;
    cout << "The original value of the 3rd element still stored in a bool: " << b3 << endl;
    cout << endl;
}
```

```Output
The vector is: true false false true true
The original value of the 1st element stored in a bool: true
The original value of the 2nd element stored in a bool: false
The original value of the 3rd element stored in a bool: false

The vector after assigning refelem1 to refelem2 is now: true true false true true
The vector after assigning false to refelem1 is now: true true true true true
The original value of the 1st element still stored in a bool: true
The original value of the 2nd element still stored in a bool: false
The original value of the 3rd element still stored in a bool: false
```

## <a name="vectorboolswap"></a><a name="swap"></a>vetor \<bool> :: swap

Função de membro estático que troca dois elementos de vetores Boolianos ( `vector<bool>` ) usando a classe proxy [vector \<bool> :: Reference](#reference_class).

```cpp
static void swap(
    reference Left,
    reference Right);
```

### <a name="parameters"></a>parâmetros

*Mantida*\
O elemento a ser trocado pelo elemento *à direita* .

*Certo*\
O elemento a ser trocado pelo elemento *à esquerda* .

### <a name="remarks"></a>Comentários

Essa sobrecarga oferece suporte aos requisitos especiais de proxy do `vector<bool>`. [vector](../standard-library/vector-class.md)::swap tem a mesma funcionalidade que a sobrecarga de argumento único de `vector<bool>::swap()`.

## <a name="see-also"></a>Confira também

[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
