---
title: Classe basic_stringbuf
ms.date: 11/04/2016
f1_keywords:
- sstream/std::basic_stringbuf
- sstream/std::basic_stringbuf::allocator_type
- sstream/std::basic_stringbuf::char_type
- sstream/std::basic_stringbuf::int_type
- sstream/std::basic_stringbuf::off_type
- sstream/std::basic_stringbuf::pos_type
- sstream/std::basic_stringbuf::traits_type
- sstream/std::basic_stringbuf::overflow
- sstream/std::basic_stringbuf::pbackfail
- sstream/std::basic_stringbuf::seekoff
- sstream/std::basic_stringbuf::seekpos
- sstream/std::basic_stringbuf::str
- sstream/std::basic_stringbuf::underflow
helpviewer_keywords:
- std::basic_stringbuf [C++]
- std::basic_stringbuf [C++], allocator_type
- std::basic_stringbuf [C++], char_type
- std::basic_stringbuf [C++], int_type
- std::basic_stringbuf [C++], off_type
- std::basic_stringbuf [C++], pos_type
- std::basic_stringbuf [C++], traits_type
- std::basic_stringbuf [C++], overflow
- std::basic_stringbuf [C++], pbackfail
- std::basic_stringbuf [C++], seekoff
- std::basic_stringbuf [C++], seekpos
- std::basic_stringbuf [C++], str
- std::basic_stringbuf [C++], underflow
ms.assetid: 40c85f9e-42a5-4a65-af5c-23c8e3bf8113
ms.openlocfilehash: 1ed9deee46f7c99750ee3260a6b2a8de1f0f3397
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51329638"
---
# <a name="basicstringbuf-class"></a>Classe basic_stringbuf

Descreve um buffer de fluxo que controla a transmissão de elementos do tipo `Elem`, cujas características de caractere são determinadas pela classe `Tr`, para e de uma sequência de elementos armazenados em um objeto de matriz.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>,
    class Alloc = allocator<Elem>>
class basic_stringbuf : public basic_streambuf<Elem, Tr>
```

### <a name="parameters"></a>Parâmetros

*ALLOC*<br/>
A classe do alocador.

*Elem*<br/>
O tipo do elemento básico da cadeia de caracteres.

*Tr*<br/>
As características de caractere especializadas no elemento básico da cadeia de caracteres.

## <a name="remarks"></a>Comentários

O objeto é alocado, estendido e liberado, conforme o necessário, para acomodar as alterações na sequência.

Um objeto da classe basic_stringbuf< `Elem`, `Tr`, `Alloc`> armazena uma cópia do argumento `ios_base::`[openmode](../standard-library/ios-base-class.md#openmode) de seu construtor como seu modo de `stringbuf` **mode**:

- Se `mode & ios_base::in` é diferente de zero, o buffer de entrada está acessível. Para obter mais informações, consulte a [Classe basic_streambuf](../standard-library/basic-streambuf-class.md).

- Se `mode & ios_base::out` é diferente de zero, o buffer de saída está acessível.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_stringbuf](#basic_stringbuf)|Constrói um objeto do tipo `basic_stringbuf`.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[allocator_type](#allocator_type)|O tipo é um sinônimo do parâmetro de modelo *Alloc*.|
|[char_type](#char_type)|Associa um nome de tipo ao parâmetro do modelo *Elem*.|
|[int_type](#int_type)|Torna esse tipo dentro `basic_filebuf`do escopo equivalente ao tipo de mesmo nome na *Tr* escopo.|
|[off_type](#off_type)|Torna esse tipo dentro `basic_filebuf`do escopo equivalente ao tipo de mesmo nome na *Tr* escopo.|
|[pos_type](#pos_type)|Torna esse tipo dentro `basic_filebuf`do escopo equivalente ao tipo de mesmo nome na *Tr* escopo.|
|[traits_type](#traits_type)|Associa um nome de tipo ao parâmetro de modelo *Tr*.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[overflow](#overflow)|Uma função protegida e virtual que pode ser chamada quando um novo caractere é inserido em um buffer cheio.|
|[pbackfail](#pbackfail)|A função membro virtual protegida tenta colocar um elemento de volta no buffer de entrada, em seguida, faz com que ele se torne o elemento atual (apontado pelo próximo ponteiro).|
|[seekoff](#seekoff)|A função membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.|
|[seekpos](#seekpos)|A função membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.|
|[str](#str)|Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.|
|swap||
|[underflow](#underflow)|A função membro virtual protegida para extrair o elemento atual do fluxo de entrada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<sstream>

**Namespace:** std

## <a name="allocator_type"></a>  basic_stringbuf::allocator_type

O tipo é um sinônimo do parâmetro de modelo *Alloc*.

```cpp
typedef Alloc allocator_type;
```

## <a name="basic_stringbuf"></a>  basic_stringbuf::basic_stringbuf

Constrói um objeto do tipo `basic_stringbuf`.

```cpp
basic_stringbuf(
    ios_base::openmode _Mode = ios_base::in | ios_base::out);

basic_stringbuf(
    const basic_string<Elem, Tr, Alloc>& str,
    ios_base::openmode _Mode = ios_base::in | ios_base::out);
```

### <a name="parameters"></a>Parâmetros

*Modo*<br/>
Uma das enumerações em [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

*str*<br/>
Um objeto do tipo [basic_string](../standard-library/basic-string-class.md).

### <a name="remarks"></a>Comentários

O primeiro construtor armazena um ponteiro nulo em todos os ponteiros que controlam o buffer de entrada e o buffer de saída. Para obter mais informações, consulte a seção Comentários da [Classe basic_streambuf](../standard-library/basic-streambuf-class.md). Ele também armazena *modo* como o modo de stringbuf. Para obter mais informações, consulte a seção Comentários da [Classe basic_stringbuf](../standard-library/basic-stringbuf-class.md).

O segundo construtor aloca uma cópia da sequência controlada pelo objeto de cadeia de caracteres *str*. Se `_Mode & ios_base::in` é diferente de zero, ele define o buffer de entrada para começar a ler no início da sequência. Se `_Mode & ios_base::out` é diferente de zero, ele define o buffer de saída para começar a escrever no início da sequência. Ele também armazena *modo* como o modo de stringbuf. Para obter mais informações, consulte a seção Comentários da [Classe basic_stringbuf](../standard-library/basic-stringbuf-class.md).

## <a name="char_type"></a>  basic_stringbuf::char_type

Associa um nome de tipo ao parâmetro do modelo *Elem*.

```cpp
typedef Elem char_type;
```

## <a name="int_type"></a>  basic_stringbuf::int_type

Torna esse tipo no escopo de basic_filebuf equivalente ao tipo de mesmo nome no `Tr` escopo.

```cpp
typedef typename traits_type::int_type int_type;
```

## <a name="off_type"></a>  basic_stringbuf::off_type

Torna esse tipo no escopo de basic_filebuf equivalente ao tipo de mesmo nome no `Tr` escopo.

```cpp
typedef typename traits_type::off_type off_type;
```

## <a name="overflow"></a>  basic_stringbuf::overflow

Uma função virtual protegida que pode ser chamada quando um novo caractere é inserido em um buffer cheio.

```cpp
virtual int_type overflow(int_type _Meta = traits_type::eof());
```

### <a name="parameters"></a>Parâmetros

*_Meta*<br/>
O caractere a ser inserido no buffer ou `traits_type::eof`.

### <a name="return-value"></a>Valor de retorno

Se a função não conseguir obter êxito, ela retornará `traits_type::eof`. Caso contrário, retornará **traits_type::**[not_eof](../standard-library/char-traits-struct.md#not_eof)(_ *Meta*).

### <a name="remarks"></a>Comentários

Se  *\_Meta* comparar como igual a **traits_type::**[eof](../standard-library/char-traits-struct.md#eof), a função de membro virtual protegida tenta inserir o elemento  **traits_type::**[to_char_type](../standard-library/char-traits-struct.md#to_char_type)(*\_Meta*) no buffer de saída. Isso pode ser feito de várias maneiras:

- Se houver uma posição de gravação disponível, ela poderá armazenar o elemento na posição de gravação e incrementar o próximo ponteiro para o buffer de saída.

- Ele pode disponibilizar uma posição de gravação alocando armazenamento novo ou adicional ao buffer de saída. Estender o buffer de saída dessa forma também estende qualquer buffer de entrada associado.

## <a name="pbackfail"></a>  basic_stringbuf::pbackfail

A função membro virtual protegida tenta colocar um elemento de volta no buffer de entrada e, em seguida, faz com que ele seja o elemento atual (apontado pelo próximo ponteiro).

```cpp
virtual int_type pbackfail(int_type _Meta = traits_type::eof());
```

### <a name="parameters"></a>Parâmetros

*_Meta*<br/>
O caractere a ser inserido no buffer ou `traits_type::eof`.

### <a name="return-value"></a>Valor de retorno

Se a função não conseguir obter êxito, ela retornará `traits_type::eof`. Caso contrário, retornará **traits_type::**[not_eof](../standard-library/char-traits-struct.md#not_eof)(_ *Meta*).

### <a name="remarks"></a>Comentários

Se *_Meta* comparado como igual a **traits_type::**[eof](../standard-library/char-traits-struct.md#eof), elemento a ser recuado será efetivamente aquele que já está no fluxo antes do elemento atual. Caso contrário, esse elemento será substituído por **byte** = **traits_type::**[to_char_type](../standard-library/char-traits-struct.md#to_char_type)(_ *Meta*). A função pode colocar um elemento de volta de várias maneiras:

- Se uma posição para colocar de volta estiver disponível e o elemento armazenado lá for comparado como igual a byte, ela poderá decrementar o próximo ponteiro para o buffer de entrada.

- Se uma posição para colocar de volta estiver disponível e se o modo de stringbuf permitir que a sequência seja alterada (**mode & ios_base::out** é diferente de zero), ela poderá armazenar byte na posição para colocar de volta e decrementar o próximo ponteiro para o buffer de entrada.

## <a name="pos_type"></a>  basic_stringbuf::pos_type

Torna esse tipo no escopo de basic_filebuf equivalente ao tipo de mesmo nome no `Tr` escopo.

```cpp
typedef typename traits_type::pos_type pos_type;
```

## <a name="seekoff"></a>  basic_stringbuf::seekoff

A função membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.

```cpp
virtual pos_type seekoff(
    off_type _Off,
    ios_base::seekdir _Way,
    ios_base::openmode _Mode = ios_base::in | ios_base::out);
```

### <a name="parameters"></a>Parâmetros

*Off*<br/>
A posição para buscar com relação a *Way*. Para obter mais informações, consulte [basic_stringbuf::off_type](#off_type).

*Way*<br/>
O ponto de partida para operações de deslocamento. Consulte [ios_base::seekdir](../standard-library/ios-base-class.md#seekdir) para obter os valores possíveis.

*Modo*<br/>
Especifica o modo para a posição do ponteiro. O padrão é permitir que você modifique as posições de leitura e gravação. Para obter mais informações, consulte [ios_base::openmode](../standard-library/ios-base-class.md#openmode).

### <a name="return-value"></a>Valor de retorno

Retorna a nova posição ou uma posição de fluxo inválida.

### <a name="remarks"></a>Comentários

Para um objeto da classe `basic_stringbuf<Elem, Tr, Alloc>`, uma posição de fluxo consiste exclusivamente em um deslocamento de fluxo. O deslocamento zero designa o primeiro elemento da sequência controlada.

A nova posição é determinada da seguinte forma:

- Se `_Way`  ==  `ios_base::beg`, a nova posição é o início do fluxo mais *off*.

- Se `_Way`  ==  `ios_base::cur`, a nova posição é a posição do fluxo atual mais *off*.

- Se `_Way`  ==  `ios_base::end`, a nova posição é o final do fluxo mais *off*.

Se `_Mode & ios_base::in` é diferente de zero, a função altera a próxima posição a ser lida no buffer de entrada. Se `_Mode & ios_base::out` é diferente de zero, a função altera a próxima posição a ser gravada no buffer de saída. Para que um fluxo seja afetado, o buffer deve existir. Para que uma operação de posicionamento seja bem-sucedida, a posição do fluxo resultante deve estar dentro da sequência controlada. Se a função afetar as duas posições de fluxo *Way* deve ser `ios_base::beg` ou `ios_base::end` e ambos os fluxos serão posicionados no mesmo elemento. Caso contrário (ou se nenhuma posição for afetada), a operação de posicionamento falhará.

Se a função tiver êxito na alteração de uma ou de ambas as posições de fluxo, ela retornará a posição de fluxo resultante. Caso contrário, ela falhará e retornará uma posição de fluxo inválida.

## <a name="seekpos"></a>  basic_stringbuf::seekpos

A função membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.

```cpp
virtual pos_type seekpos(pos_type _Sp, ios_base::openmode _Mode = ios_base::in | ios_base::out);
```

### <a name="parameters"></a>Parâmetros

*_Sp*<br/>
A posição pela qual buscar.

*Modo*<br/>
Especifica o modo para a posição do ponteiro. O padrão é permitir que você modifique as posições de leitura e gravação.

### <a name="return-value"></a>Valor de retorno

Se a função tiver êxito na alteração de uma ou de ambas as posições de fluxo, ela retornará a posição de fluxo resultante. Caso contrário, ela falhará e retornará uma posição de fluxo inválida. Para determinar se a posição de fluxo é inválida, compare o valor retornado com `pos_type(off_type(-1))`.

### <a name="remarks"></a>Comentários

Para um objeto da classe basic_stringbuf< **Elem**, **Tr**, `Alloc`>, uma posição de fluxo consiste exclusivamente em um deslocamento de fluxo. O deslocamento zero designa o primeiro elemento da sequência controlada. A nova posição é determinada por _ *Sp*.

Se **mode & ios_base::in** é diferente de zero, a função altera a próxima posição a ser lida no buffer de entrada. Se **mode & ios_base::out** é diferente de zero, a função altera a próxima posição a ser gravada no buffer de saída. Para que um fluxo seja afetado, o buffer deve existir. Para que uma operação de posicionamento seja bem-sucedida, a posição do fluxo resultante deve estar dentro da sequência controlada. Caso contrário (ou se nenhuma posição for afetada), a operação de posicionamento falhará.

## <a name="str"></a>  basic_stringbuf::str

Define ou obtém o texto em um buffer de cadeia de caracteres sem alterar a posição de gravação.

```cpp
basic_string<Elem, Tr, Alloc> str() const;
void str(
    const basic_string<Elem, Tr, Alloc>& _Newstr);
```

### <a name="parameters"></a>Parâmetros

*_Newstr*<br/>
A nova cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Retorna um objeto da classe [basic_string](../standard-library/basic-string-class.md)\< **Elem**, **Tr**, Alloc **>,**, cuja sequência controlada é uma cópia da sequência controlada por **\*this**.

### <a name="remarks"></a>Comentários

A primeira função membro retorna um objeto da classe basic_string< **Elem**, **Tr**, `Alloc`>, cuja sequência controlada é uma cópia da sequência controlada por **\*this**. A sequência copiada depende do modo de stringbuf armazenado:

- Se **mode & ios_base::out** é diferente de zero e existe um buffer de saída, a sequência é o buffer de saída inteiro (elementos [epptr](../standard-library/basic-streambuf-class.md#epptr) - [pbase](../standard-library/basic-streambuf-class.md#pbase) que começam com `pbase`).

- Se **mode & ios_base::in** é diferente de zero e existe um buffer de entrada, a sequência é todo o buffer de entrada (elementos [egptr](../standard-library/basic-streambuf-class.md#egptr) - [eback](../standard-library/basic-streambuf-class.md#eback) que começam com `eback`).

- Caso contrário, a sequência copiada fica vazia.

A segunda função membro desaloca qualquer sequência controlada atualmente por **\*this**. Em seguida, aloca uma cópia da sequência controlada por *_Newstr*. Se **mode & ios_base::in** é diferente de zero, ela define o buffer de entrada para começar a ler no início da sequência. Se **mode & ios_base::out** é diferente de zero, ela define o buffer de saída para começar a gravar no início da sequência.

### <a name="example"></a>Exemplo

```cpp
// basic_stringbuf_str.cpp
// compile with: /EHsc
#include <iostream>
#include <sstream>

using namespace std;

int main( )
{
   basic_string<char> i( "test" );
   stringstream ss;

   ss.rdbuf( )->str( i );
   cout << ss.str( ) << endl;

   ss << "z";
   cout << ss.str( ) << endl;

   ss.rdbuf( )->str( "be" );
   cout << ss.str( ) << endl;
}
```

```Output
test
zest
be
```

## <a name="traits_type"></a>  basic_stringbuf::traits_type

Associa um nome de tipo ao parâmetro de modelo *Tr*.

```cpp
typedef Tr traits_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo *Tr*.

## <a name="underflow"></a>  basic_stringbuf::underflow

Função virtual protegida para extrair o elemento atual do fluxo de entrada.

```cpp
virtual int_type underflow();
```

### <a name="return-value"></a>Valor de retorno

Se a função não conseguir obter êxito, ela retornará **traits_type::**[eof](../standard-library/char-traits-struct.md#eof). Caso contrário, retornará o elemento atual no fluxo de entrada, que é convertido.

### <a name="remarks"></a>Comentários

A função de membro virtual protegida tenta extrair o elemento atual `byte` do buffer de entrada, avança a posição do fluxo atual e retorna o elemento como **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#to_int_type)( **bytes**). Ele pode fazer isso de uma maneira: se uma posição de leitura estiver disponível, ela terá `byte` como o elemento armazenado na posição de leitura e avançará o próximo ponteiro para o buffer de entrada.

## <a name="swap"></a>  basic_streambuf::swap

Troca o conteúdo desse buffer de cadeia de caracteres com outro buffer de cadeia de caracteres.

```cpp
void basic_stringbuf<T>::swap(basic_stringbuf& other)
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
O basic_stringbuf cujo conteúdo será trocado com este basic_stringbuf.

### <a name="remarks"></a>Comentários

## <a name="op_eq"></a>  basic_stringbuf::operator=

Atribui o conteúdo do basic_stringbuf no lado direito do operador para o basic_stringbuf no lado esquerdo.

```cpp
basic_stringbuf& basic_stringbuf:: operator=(const basic_stringbuf& other)
```

### <a name="parameters"></a>Parâmetros

*other*<br/>
Um basic_stringbuf cujo conteúdo, incluindo as características de localidade, será atribuído a stringbuf no lado esquerdo do operador.

### <a name="remarks"></a>Comentários

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Programação de iostream](../standard-library/iostream-programming.md)<br/>
[Convenções de iostreams](../standard-library/iostreams-conventions.md)<br/>
