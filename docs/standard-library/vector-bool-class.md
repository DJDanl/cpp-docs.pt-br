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
ms.openlocfilehash: 6c67e3d9ba1b33cb99a7d3afb2522f443003fa38
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376091"
---
# <a name="vectorltboolgt-class"></a>Classe vector&lt;bool&gt;

A `vector<bool>` classe é uma especialização parcial do [vetor](../standard-library/vector-class.md) para elementos do tipo **bool**. Ele tem um alocador para o tipo subjacente que é usado pela especialização, que fornece otimização de espaço armazenando um valor **bool** por bit.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Allocator = allocator<bool>>
class vector<bool, Allocator>
```

## <a name="remarks"></a>Comentários

Essa especialização de modelo de classe se comporta como vector, exceto pelas diferenças explicadas neste artigo.

As operações que lidam com o tipo **bool** correspondem a valores no armazenamento do contêiner. `allocator_traits::construct` não é usado para construir esses valores.

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[const_pointer](#const_pointer)|Um typedef para um `const_iterator` que pode funcionar como um ponteiro de constante para um elemento booliano do `vector<bool>`.|
|[const_reference](#const_reference)|Um typedef para **bool.** Depois da inicialização, ele não observa atualizações no valor original.|
|[ponteiro](#pointer)|Um typedef para um `iterator` que pode funcionar como um ponteiro para um elemento booliano do `vector<bool>`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[flip](#flip)|Inverte todos os bits no `vector<bool>`.|
|[Trocar](#swap)|Troca os elementos de dois `vector<bool>`s.|
|[operator&#91;&#93;](#op_at)|Retorna uma referência simulada para o elemento `vector<bool>` em uma posição especificada.|
|`at`|Funciona da mesma forma que a função não especializada [vector](../standard-library/vector-class.md)::at, exceto pelo fato de que usa a classe proxy [vector\<bool>::reference](#reference_class). Consulte também [operator&#91;&#93;](#op_at).|
|`front`|Funciona da mesma forma que a função não especializada [vector](../standard-library/vector-class.md)::front, exceto pelo fato de que usa a classe proxy [vector\<bool>::reference](#reference_class). Consulte também [operator&#91;&#93;](#op_at).|
|`back`|Funciona da mesma forma que a função não especializada [vector](../standard-library/vector-class.md)::back, exceto pelo fato de que usa a classe proxy [vector\<bool>::reference](#reference_class). Consulte também [operator&#91;&#93;](#op_at).|

### <a name="proxy-class"></a>Classe proxy

|||
|-|-|
|[Classe vector\<bool> reference](#reference_class)|Uma classe que atua como um proxy para simular o comportamento de `bool&` e cujos objetos podem fornecer referências a elementos (bits únicos) em um objeto `vector<bool>`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho**: \<> vetorial

**Namespace:** std

## <a name="vectorboolconst_pointer"></a><a name="const_pointer"></a>vetor\<bool>::const_pointer

Um tipo que descreve um objeto que pode servir como um ponteiro de constante para um elemento booliano da sequência contida pelo objeto `vector<bool>`.

```cpp
typedef const_iterator const_pointer;
```

## <a name="vectorboolconst_reference"></a><a name="const_reference"></a>vetor\<bool>::const_reference

Um tipo que descreve um objeto que pode servir como uma referência de constante para um elemento booliano da sequência contida pelo objeto `vector<bool>`.

```cpp
typedef bool const_reference;
```

### <a name="remarks"></a>Comentários

Para obter mais informações e exemplos de código, consulte [vector&lt;bool&gt;::reference::operator=](#reference_operator_eq).

## <a name="vectorboolflip"></a><a name="flip"></a>vetor\<bool>::flip

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

## <a name="vectorbooloperator"></a><a name="op_at"></a>vetor\<bool>::operador[]

Retorna uma referência simulada para o elemento `vector<bool>` em uma posição especificada.

```cpp
vector<bool>::reference operator[](size_type Pos);

vector&<bool&>::const_reference operator[](size_type Pos) const;
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|-|-|
|*Pos*|A posição do elemento `vector<bool>`.|

### <a name="return-value"></a>Valor retornado

Um objeto [vector\<bool>::reference](#reference_class) ou [vector\<bool>::const_reference](#const_reference) que contém o valor do elemento indexado.

Se a posição especificada for maior ou igual ao tamanho do contêiner, o resultado será indefinido.

### <a name="remarks"></a>Comentários

Se você compilar com _ITERATOR_DEBUG_LEVEL definido, um erro de tempo de execução ocorrerá se você tentar acessar um elemento fora dos limites do vetor.  Para obter mais informações, consulte [Iteradores verificados](../standard-library/checked-iterators.md).

### <a name="example"></a>Exemplo

Este exemplo de código `vector<bool>::operator[]` mostra o uso correto e dois erros de codificação comuns, que são comentados. Esses erros causam erros porque `vector<bool>::reference` o `vector<bool>::operator[]` endereço do objeto que retorna não pode ser tomado.

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

## <a name="vectorboolpointer"></a><a name="pointer"></a>vetor\<bool>::pointer

Um tipo que descreve um objeto que pode servir como um ponteiro para um elemento booliano da sequência contida pelo objeto `vector<bool>`.

```cpp
typedef iterator pointer;
```

## <a name="vectorboolreference-class"></a><a name="reference_class"></a>vetor\<bool>::classe de referência

A classe `vector<bool>::reference` é uma classe proxy fornecida pela Classe [vector\<bool>](../standard-library/vector-bool-class.md) para simular `bool&`.

### <a name="remarks"></a>Comentários

Uma referência simulada é necessária porque o C++ não permite nativamente referências diretas aos bits. `vector<bool>` usa apenas um bit por elemento, que pode ser referenciado usando essa classe proxy. No entanto, a simulação de referência não é concluída porque determinadas atribuições não são válidas. Por exemplo, como o endereço do objeto `vector<bool>::reference` não pode ser usado, o código a seguir que usa [vector\<bool>::operator&#91;&#93;](#op_at) não está correto:

```cpp
vector<bool> vb;
//...
bool* pb = &vb[1]; // conversion error - do not use
bool& refb = vb[1];   // conversion error - do not use
```

### <a name="vectorboolreferenceflip"></a><a name="reference_flip"></a>vetor\<bool>::referência::flip

Inverte o valor booliano de um elemento [vector\<bool>](../standard-library/vector-bool-class.md) referenciado.

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

### <a name="vectorboolreferenceoperator-bool"></a><a name="reference_operator_bool"></a>vetor\<bool>::referência::operador bool

Fornece uma conversão `vector<bool>::reference` implícita de **bool**.

```cpp
operator bool() const;
```

#### <a name="return-value"></a>Valor retornado

O valor booliano do elemento do objeto vector\<bool>.

#### <a name="remarks"></a>Comentários

O objeto `vector<bool>` não pode ser modificado por esse operador.

### <a name="vectorboolreferenceoperator"></a><a name="reference_operator_eq"></a>vetor\<bool>::referência::operador=

Atribui um valor booliano a um bit ou o valor mantido por um elemento referenciado para um bit.

```cpp
reference& operator=(const reference& Right);
reference& operator=(bool Val);
```

### <a name="parameters"></a>Parâmetros

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

## <a name="vectorboolswap"></a><a name="swap"></a>vetor\<bool>::swap

A função membro estática que troca dois elementos de vetores boolianos (`vector<bool>`) usando a classe de proxy [vector\<bool>::reference](#reference_class).

```cpp
static void swap(
    reference Left,
    reference Right);
```

### <a name="parameters"></a>Parâmetros

*Deixou*\
O elemento a ser trocado com o elemento *certo.*

*Certo*\
O elemento a ser trocado com o elemento *esquerda.*

### <a name="remarks"></a>Comentários

Essa sobrecarga oferece suporte aos requisitos especiais de proxy do `vector<bool>`. [vector](../standard-library/vector-class.md)::swap tem a mesma funcionalidade que a sobrecarga de argumento único de `vector<bool>::swap()`.

## <a name="see-also"></a>Confira também

[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
