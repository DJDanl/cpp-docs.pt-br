---
title: Classe basic_iostream
ms.date: 11/04/2016
f1_keywords:
- istream/std::basic_iostream
- istream/std::basic_iostream::swap
helpviewer_keywords:
- basic_iostream class
ms.assetid: 294b680b-eb49-4066-8db2-6d52dac9d6e3
ms.openlocfilehash: 190c9aa23493cea67bae44be93fd3fdbdecc4447
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72690005"
---
# <a name="basic_iostream-class"></a>Classe basic_iostream

Uma classe de fluxo que pode fazer tanto entrada quanto saída.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>>
class basic_iostream : public basic_istream<Elem, Tr>,
    public basic_ostream<Elem, Tr>
{
public:
    explicit basic_iostream(basic_streambuf<Elem, Tr>* strbuf);

    virtual ~basic_iostream();

};
```

## <a name="remarks"></a>Comentários

O modelo de classe descreve um objeto que controla as inserções, por meio de sua classe base [basic_ostream](../standard-library/basic-ostream-class.md) <  `Elem`, `Tr` > e extrações, por meio de sua classe base [basic_istream](../standard-library/basic-istream-class.md) <  `Elem`, `Tr` >. Os dois objetos compartilham uma classe base virtual comum [basic_ios](../standard-library/basic-ios-class.md)< `Elem`, `Tr`>. Eles também gerenciam um buffer de fluxo comum, com elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`. O construtor inicializa suas classes base por meio de `basic_istream`( **strbuf**) e `basic_ostream`( **strbuf**).

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_iostream](#basic_iostream)|Crie um objeto `basic_iostream`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[swap](#swap)|Troca o conteúdo do objeto `basic_iostream` fornecido pelo conteúdo deste objeto.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_eq)|Atribui o valor de um objeto `basic_iostream` especificado a esse objeto. Essa é uma atribuição de movimentação que envolve um `rvalue` que não deixa uma cópia.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<istream>

**Namespace:** std

## <a name="basic_iostream"></a>  basic_iostream::basic_iostream

Crie um objeto `basic_iostream`.

```cpp
explicit basic_iostream(basic_streambuf<Elem, Tr>* strbuf);

basic_iostream(basic_iostream&& right);

basic_iostream();
```

### <a name="parameters"></a>Parâmetros

\ *strbuf*
Um objeto `basic_streambuf` existente.

\ *à direita*
Um objeto `basic_iostream` Existente usado para construir um novo `basic_iostream`.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa os objetos base por meio de `basic_istream(strbuf)` e `basic_ostream(strbuf)`.

O segundo construtor inicializa os objetos base chamando `move(right)`.

## <a name="op_eq"></a>  basic_iostream::operator=

Atribua o valor do objeto `basic_iostream` especificado a esse objeto. Essa é uma atribuição de movimentação que envolve um rvalue que não deixa uma cópia.

```cpp
basic_iostream& operator=(basic_iostream&& right);
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
Uma referência `rvalue` a um objeto `basic_iostream` do qual atribuir.

### <a name="remarks"></a>Comentários

O operador membro chama `swap(right)`.

## <a name="swap"></a>  basic_iostream::swap

Troca o conteúdo do objeto `basic_iostream` fornecido pelo conteúdo deste objeto.

```cpp
void swap(basic_iostream& right);
```

### <a name="parameters"></a>Parâmetros

\ *à direita*
O objeto `basic_iostream` a trocar.

### <a name="remarks"></a>Comentários

A função de membro chama `swap(right)`.

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação de iostream](../standard-library/iostream-programming.md)\
[Convenções de iostreams](../standard-library/iostreams-conventions.md)
