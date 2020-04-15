---
title: Classe basic_iostream
ms.date: 11/04/2016
f1_keywords:
- istream/std::basic_iostream
- istream/std::basic_iostream::swap
helpviewer_keywords:
- basic_iostream class
ms.assetid: 294b680b-eb49-4066-8db2-6d52dac9d6e3
ms.openlocfilehash: e2a892525afbbad6d5b42d0b836fee096a70c297
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376814"
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

O modelo de classe descreve um objeto que controla `Tr` inserções, através de sua classe `Tr` base [basic_ostream,](../standard-library/basic-ostream-class.md)< `Elem`> e extrações, através de sua classe base [basic_istream](../standard-library/basic-istream-class.md)< `Elem`,>. Os dois objetos compartilham uma `Tr` classe de base virtual comum [basic_ios](../standard-library/basic-ios-class.md)< `Elem`,>. Eles também gerenciam um buffer de fluxo comum, com elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`. O construtor inicializa suas classes base por meio de `basic_istream`( **strbuf**) e `basic_ostream`( **strbuf**).

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_iostream](#basic_iostream)|Crie um objeto `basic_iostream`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Trocar](#swap)|Troca o conteúdo do objeto `basic_iostream` fornecido pelo conteúdo deste objeto.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador=](#op_eq)|Atribui o valor de um objeto `basic_iostream` especificado a esse objeto. Essa é uma atribuição de movimentação que envolve um `rvalue` que não deixa uma cópia.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<istream>

**Namespace:** std

## <a name="basic_iostreambasic_iostream"></a><a name="basic_iostream"></a>basic_iostream::basic_iostream

Crie um objeto `basic_iostream`.

```cpp
explicit basic_iostream(basic_streambuf<Elem, Tr>* strbuf);

basic_iostream(basic_iostream&& right);

basic_iostream();
```

### <a name="parameters"></a>Parâmetros

*strbuf*\
Um objeto `basic_streambuf` existente.

*Certo*\
Um objeto `basic_iostream` Existente usado para construir um novo `basic_iostream`.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa os objetos base por meio de `basic_istream(strbuf)` e `basic_ostream(strbuf)`.

O segundo construtor inicializa os objetos base chamando `move(right)`.

## <a name="basic_iostreamoperator"></a><a name="op_eq"></a>basic_iostream::operador=

Atribua o valor do objeto `basic_iostream` especificado a esse objeto. Essa é uma atribuição de movimentação que envolve um rvalue que não deixa uma cópia.

```cpp
basic_iostream& operator=(basic_iostream&& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
Uma referência `rvalue` a um objeto `basic_iostream` do qual atribuir.

### <a name="remarks"></a>Comentários

O operador `swap(right)`membro chama .

## <a name="basic_iostreamswap"></a><a name="swap"></a>basic_iostream::swap

Troca o conteúdo do objeto `basic_iostream` fornecido pelo conteúdo deste objeto.

```cpp
void swap(basic_iostream& right);
```

### <a name="parameters"></a>Parâmetros

*Certo*\
O objeto `basic_iostream` a trocar.

### <a name="remarks"></a>Comentários

A função `swap(right)`membro chama .

## <a name="see-also"></a>Confira também

[Segurança do segmento na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Programação iostream](../standard-library/iostream-programming.md)\
[Convenções iostreams](../standard-library/iostreams-conventions.md)
