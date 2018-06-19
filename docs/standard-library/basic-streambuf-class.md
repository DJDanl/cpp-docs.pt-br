---
title: Classe basic_streambuf | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- streambuf/std::basic_streambuf
- streambuf/std::basic_streambuf::char_type
- streambuf/std::basic_streambuf::int_type
- streambuf/std::basic_streambuf::off_type
- streambuf/std::basic_streambuf::pos_type
- streambuf/std::basic_streambuf::traits_type
- streambuf/std::basic_streambuf::eback
- streambuf/std::basic_streambuf::egptr
- streambuf/std::basic_streambuf::epptr
- streambuf/std::basic_streambuf::gbump
- streambuf/std::basic_streambuf::getloc
- streambuf/std::basic_streambuf::gptr
- streambuf/std::basic_streambuf::imbue
- streambuf/std::basic_streambuf::in_avail
- streambuf/std::basic_streambuf::overflow
- streambuf/std::basic_streambuf::pbackfail
- streambuf/std::basic_streambuf::pbase
- streambuf/std::basic_streambuf::pbump
- streambuf/std::basic_streambuf::pptr
- streambuf/std::basic_streambuf::pubimbue
- streambuf/std::basic_streambuf::pubseekoff
- streambuf/std::basic_streambuf::pubseekpos
- streambuf/std::basic_streambuf::pubsetbuf
- streambuf/std::basic_streambuf::pubsync
- streambuf/std::basic_streambuf::sbumpc
- streambuf/std::basic_streambuf::seekoff
- streambuf/std::basic_streambuf::seekpos
- streambuf/std::basic_streambuf::setbuf
- streambuf/std::basic_streambuf::setg
- streambuf/std::basic_streambuf::setp
- streambuf/std::basic_streambuf::sgetc
- streambuf/std::basic_streambuf::sgetn
- streambuf/std::basic_streambuf::showmanyc
- streambuf/std::basic_streambuf::snextc
- streambuf/std::basic_streambuf::sputbackc
- streambuf/std::basic_streambuf::sputc
- streambuf/std::basic_streambuf::sputn
- streambuf/std::basic_streambuf::stossc
- streambuf/std::basic_streambuf::sungetc
- streambuf/std::basic_streambuf::swap
- streambuf/std::basic_streambuf::sync
- streambuf/std::basic_streambuf::uflow
- streambuf/std::basic_streambuf::underflow
- streambuf/std::basic_streambuf::xsgetn
- streambuf/std::basic_streambuf::xsputn
dev_langs:
- C++
helpviewer_keywords:
- std::basic_streambuf [C++]
- std::basic_streambuf [C++], char_type
- std::basic_streambuf [C++], int_type
- std::basic_streambuf [C++], off_type
- std::basic_streambuf [C++], pos_type
- std::basic_streambuf [C++], traits_type
- std::basic_streambuf [C++], eback
- std::basic_streambuf [C++], egptr
- std::basic_streambuf [C++], epptr
- std::basic_streambuf [C++], gbump
- std::basic_streambuf [C++], getloc
- std::basic_streambuf [C++], gptr
- std::basic_streambuf [C++], imbue
- std::basic_streambuf [C++], in_avail
- std::basic_streambuf [C++], overflow
- std::basic_streambuf [C++], pbackfail
- std::basic_streambuf [C++], pbase
- std::basic_streambuf [C++], pbump
- std::basic_streambuf [C++], pptr
- std::basic_streambuf [C++], pubimbue
- std::basic_streambuf [C++], pubseekoff
- std::basic_streambuf [C++], pubseekpos
- std::basic_streambuf [C++], pubsetbuf
- std::basic_streambuf [C++], pubsync
- std::basic_streambuf [C++], sbumpc
- std::basic_streambuf [C++], seekoff
- std::basic_streambuf [C++], seekpos
- std::basic_streambuf [C++], setbuf
- std::basic_streambuf [C++], setg
- std::basic_streambuf [C++], setp
- std::basic_streambuf [C++], sgetc
- std::basic_streambuf [C++], sgetn
- std::basic_streambuf [C++], showmanyc
- std::basic_streambuf [C++], snextc
- std::basic_streambuf [C++], sputbackc
- std::basic_streambuf [C++], sputc
- std::basic_streambuf [C++], sputn
- std::basic_streambuf [C++], stossc
- std::basic_streambuf [C++], sungetc
- std::basic_streambuf [C++], swap
- std::basic_streambuf [C++], sync
- std::basic_streambuf [C++], uflow
- std::basic_streambuf [C++], underflow
- std::basic_streambuf [C++], xsgetn
- std::basic_streambuf [C++], xsputn
ms.assetid: 136af6c3-13bf-4501-9288-b93da26efac7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7453120d40efc05fd0dce919a7b85869710a9b18
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33848905"
---
# <a name="basicstreambuf-class"></a>Classe basic_streambuf

Descreve uma classe base abstrata para derivar um buffer de fluxo, que controla a transmissão de elementos de e para uma representação específica de um fluxo.

## <a name="syntax"></a>Sintaxe

```cpp
template <class Elem, class Tr = char_traits<Elem>>
class basic_streambuf;
```

### <a name="parameters"></a>Parâmetros

`Elem` Um [char_type](#char_type).

`Tr` O caractere [traits_type](#traits_type).

## <a name="remarks"></a>Comentários

A classe de modelo descreve uma classe base abstrata para derivar um buffer de fluxo, que controla a transmissão de elementos de e para uma representação específica de um fluxo. Um objeto da classe `basic_streambuf` ajuda a controlar um fluxo com elementos do tipo `Tr`, também conhecido como [char_type](#char_type), cujas características de caractere são determinadas pela classe [char_traits](../standard-library/char-traits-struct.md), também conhecida como [traits_type](#traits_type).

Todo buffer de fluxo controla conceitualmente dois fluxos independentes: um para extrações (entrada) e outro para inserções (saída). Uma representação específica pode, no entanto, tornar um ou ambos esses fluxos inacessíveis. Normalmente, mantém alguma relação entre os dois fluxos. O que você insere no fluxo de saída de um objeto [basic_stringbuf](../standard-library/basic-stringbuf-class.md)< `Elem`, `Tr`>, por exemplo, é o que você mais tarde extrai do fluxo de entrada. Ao posicionar um fluxo de um objeto [basic_filebuf](../standard-library/basic-filebuf-class.md)< `Elem`, `Tr`>, você posiciona o outro fluxo em tandem.

A interface pública para a classe de modelo `basic_streambuf` fornece as operações que são comuns a todos os buffers de fluxo, por mais especializados que sejam. A interface protegida fornece as operações necessárias para uma representação específica de um fluxo para fazer seu trabalho. As funções membro virtuais protegidas permitem personalizar o comportamento de um buffer de fluxo derivado para uma representação específica de um fluxo. Cada buffer de fluxo derivado nesta biblioteca descreve como especializa o comportamento de suas funções membro virtual protegidas. O comportamento padrão para a classe base, que costuma não fazer nada, é descrito neste tópico.

As funções membro protegidas restantes controla a cópia para e de qualquer armazenamento fornecido para transmissões de buffer para e de fluxos. Um buffer de entrada, por exemplo, é caracterizado por:

- [eback](#eback), um ponteiro para o início do buffer.

- [gptr](#gptr), um ponteiro para o próximo elemento a ler.

- [egptr](#egptr), um ponteiro logo após o fim do buffer.

Da mesma forma, um buffer de saída é caracterizado por:

- [pbase](#pbase), um ponteiro para o início do buffer.

- [pptr](#pptr), um ponteiro para o próximo elemento a gravar.

- [epptr](#epptr), um ponteiro logo após o fim do buffer.

Para qualquer buffer, o seguinte protocolo é usado:

- Se o próximo ponteiro for nulo, nenhum buffer existirá. Caso contrário, todos os três ponteiros apontam para a mesma sequência. Eles podem ser comparados com segurança para ordem.

- Para um buffer de saída, se o ponteiro seguinte comparar menos que o ponteiro final, você poderá armazenar um elemento na posição de gravação designada pelo ponteiro seguinte.

- Para um buffer de entrada, se o ponteiro seguinte comparar menos que o ponteiro final, você poderá ler um elemento na posição de leitura designada pelo ponteiro seguinte.

- Para um buffer de entrada, se o ponteiro inicial comparar menos que o ponteiro seguinte, você pode colocar um elemento de volta na posição putback designada pelo próximo ponteiro decrementado.

Quaisquer funções membro virtuais protegidas que você grave para uma classe derivada de `basic_streambuf`< `Elem`, `Tr`> deve cooperar para manter esse protocolo.

Um objeto da classe `basic_streambuf`< `Elem`, `Tr`> armazena os seis ponteiros descritos anteriormente. Ele também armazena um objeto de localidade em um objeto do tipo [localidade](../standard-library/locale-class.md) para uso potencial por um buffer de fluxo derivado.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[basic_streambuf](#basic_streambuf)|Constrói um objeto do tipo `basic_streambuf`.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[char_type](#char_type)|Associa um nome de tipo ao parâmetro de modelo `Elem`.|
|[int_type](#int_type)|Associa um nome de tipo dentro do escopo de `basic_streambuf` ao parâmetro do modelo `Elem`.|
|[off_type](#off_type)|Associa um nome de tipo dentro do escopo de `basic_streambuf` ao parâmetro do modelo `Elem`.|
|[pos_type](#pos_type)|Associa um nome de tipo dentro do escopo de `basic_streambuf` ao parâmetro do modelo `Elem`.|
|[traits_type](#traits_type)|Associa um nome de tipo ao parâmetro de modelo `Tr`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[eback](#eback)|Uma função protegida que retorna um ponteiro para o início do buffer de entrada.|
|[egptr](#egptr)|Uma função protegida que retorna um ponteiro logo após o final do buffer de entrada.|
|[epptr](#epptr)|Uma função protegida que retorna um ponteiro logo após o final do buffer de saída.|
|[gbump](#gbump)|Uma função protegida que adiciona `count` ao próximo ponteiro para o buffer de entrada.|
|[getloc](#getloc)|Obtém a localidade do objeto `basic_streambuf`.|
|[gptr](#gptr)|Uma função protegida que retorna um ponteiro para o próximo elemento do buffer de entrada.|
|[imbue](#imbue)|Uma função virtual protegida chamada por [pubimbue](#pubimbue).|
|[in_avail](#in_avail)|Retorna o número de elementos que estão prontos para serem lidos do buffer.|
|[overflow](#overflow)|Uma função virtual protegida que pode ser chamada quando um novo caractere é inserido em um buffer cheio.|
|[pbackfail](#pbackfail)|Uma função membro virtual protegida que tenta colocar um elemento de volta no fluxo de entrada, então torná-lo elemento atual (apontando para o ponteiro seguinte).|
|[pbase](#pbase)|Uma função protegida que retorna um ponteiro para o início do buffer de saída.|
|[pbump](#pbump)|Uma função protegida que adiciona `count` ao próximo ponteiro para o buffer de saída.|
|[pptr](#pptr)|Uma função protegida que retorna um ponteiro para o próximo elemento do buffer de saída.|
|[pubimbue](#pubimbue)|Define a localidade do objeto `basic_streambuf`.|
|[pubseekoff](#pubseekoff)|Chama [seekoff](#seekoff), uma função virtual protegida que é substituída em uma classe derivada.|
|[pubseekpos](#pubseekpos)|Chama [seekpos](#seekpos), uma função virtual protegida que é substituída em uma classe derivada e redefine a posição atual do ponteiro.|
|[pubsetbuf](#pubsetbuf)|Chama [setbuf](#setbuf), uma função virtual protegida que é substituída em uma classe derivada.|
|[pubsync](#pubsync)|Chama [sync](#sync), uma função virtual protegida que é substituída em uma classe derivada e atualiza o fluxo externo associado a esse buffer.|
|[sbumpc](#sbumpc)|Lê e retorna o elemento atual, movendo o ponteiro de fluxo.|
|[seekoff](#seekoff)|A função membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.|
|[seekpos](#seekpos)|A função membro virtual protegida tenta alterar as posições atuais para os fluxos controlados.|
|[setbuf](#setbuf)|A função membro virtual protegida executa uma operação que específica para cada buffer de fluxo derivado.|
|[setg](#setg)|Uma função protegida que armazena `_Gbeg` no ponteiro de início, `_Gnext` no próximo ponteiro e `_Gend` no ponteiro final para o buffer de entrada.|
|[setp](#setp)|Uma função protegida que armazena `_Pbeg` no ponteiro inicial e `_Pend` no ponteiro final para o buffer de saída.|
|[sgetc](#sgetc)|Retorna o elemento atual sem alterar a posição no fluxo.|
|[sgetn](#sgetn)|Retorna o número de elementos lidos.|
|[showmanyc](#showmanyc)|Função membro virtual protegida que retorna uma contagem do número de caracteres que pode ser extraído do fluxo de entrada e garante que o programa não esteja sujeito a uma espera indefinida.|
|[snextc](#snextc)|Lê o elemento atual e retorna o elemento seguinte.|
|[sputbackc](#sputbackc)|Coloca um `char_type` no fluxo.|
|[sputc](#sputc)|Coloca um caractere no fluxo.|
|[sputn](#sputn)|Coloca uma cadeia de caracteres no fluxo.|
|[stossc](#stossc)|Move-se além do elemento atual no fluxo.|
|[sungetc](#sungetc)|Obtém um caractere do fluxo.|
|[swap](#swap)|Troca os valores nesse objeto pelos valores do parâmetro do objeto `basic_streambuf` fornecido.|
|[sync](#sync)|Uma função virtual protegida que tenta sincronizar os fluxos controlados com quaisquer fluxos externos associados.|
|[uflow](#uflow)|Função virtual protegida que extrai o elemento atual do fluxo de entrada.|
|[underflow](#underflow)|Função virtual protegida que extrai o elemento atual do fluxo de entrada.|
|[xsgetn](#xsgetn)|Uma função virtual protegida que extrai elementos de fluxo de entrada.|
|[xsputn](#xsputn)|Uma função virtual protegida que insere elementos no fluxo de saída.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator=](#op_eq)|Atribui os valores deste objeto de outro objeto `basic_streambuf`.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<streambuf >

**Namespace:** std

## <a name="basic_streambuf"></a>  basic_streambuf::basic_streambuf

Constrói um objeto do tipo `basic_streambuf`.

```cpp
basic_streambuf();

basic_streambuf(const basic_streambuf& right);
```

### <a name="parameters"></a>Parâmetros

`right` Uma referência de lvalue para o `basic_streambuf` que é usado para definir os valores para este objeto `basic_streambuf` objeto.

### <a name="remarks"></a>Comentários

O primeiro construtor protegido armazena um ponteiro nulo em todos os ponteiros controlando o buffer de entrada e o buffer de saída. Ele também armazena `locale::classic` no objeto de localidade. Para obter mais informações, consulte [Locale::classic](../standard-library/locale-class.md#classic).

O segundo construtor protegido copia os ponteiros e a localidade de `right`.

## <a name="char_type"></a>  basic_streambuf::char_type

Associa um nome de tipo ao parâmetro do modelo **Elem**.

```cpp
typedef Elem char_type;
```

## <a name="eback"></a>  basic_streambuf::eback

Uma função protegida que retorna um ponteiro para o início do buffer de entrada.

```cpp
char_type *eback() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o início do buffer de entrada.

## <a name="egptr"></a>  basic_streambuf::egptr

Uma função protegida que retorna um ponteiro logo após o final do buffer de entrada.

```cpp
char_type *egptr() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro logo após o final do buffer de entrada.

## <a name="epptr"></a>  basic_streambuf::epptr

Uma função protegida que retorna um ponteiro logo após o final do buffer de saída.

```cpp
char_type *epptr() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro logo após o final do buffer de saída.

## <a name="gbump"></a>  basic_streambuf::gbump

Uma função protegida que adiciona `count` ao próximo ponteiro para o buffer de entrada.

```cpp
void gbump(int count);
```

### <a name="parameters"></a>Parâmetros

`count` O valor pelo qual Avançar o ponteiro.

## <a name="getloc"></a>  basic_streambuf::getloc

Obtém a localidade do objeto basic_streambuf.

```cpp
locale getloc() const;
```

### <a name="return-value"></a>Valor de retorno

O objeto de localidade armazenado.

### <a name="remarks"></a>Comentários

Para obter informações relacionadas, consulte [ios_base::getloc](../standard-library/ios-base-class.md#getloc).

### <a name="example"></a>Exemplo

```cpp
// basic_streambuf_getloc.cpp
// compile with: /EHsc
#include <iostream>

int main( )
{
   using namespace std;
   cout << cout.rdbuf( )->getloc( ).name( ).c_str( ) << endl;
}
```

```Output
C
```

## <a name="gptr"></a>  basic_streambuf::gptr

Uma função protegida que retorna um ponteiro para o próximo elemento do buffer de entrada.

```cpp
char_type *gptr() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o próximo elemento do buffer de entrada.

## <a name="imbue"></a>  basic_streambuf::imbue

Uma função virtual protegida chamada por [pubimbue](#pubimbue).

```cpp
virtual void imbue(const locale& _Loc);
```

### <a name="parameters"></a>Parâmetros

`_Loc` Uma referência a uma localidade.

### <a name="remarks"></a>Comentários

O comportamento padrão é não fazer nada.

## <a name="in_avail"></a>  basic_streambuf::in_avail

Retorna o número de elementos que estão prontos para serem lidos do buffer.

```cpp
streamsize in_avail();
```

### <a name="return-value"></a>Valor de retorno

O número de elementos que estão prontos para serem lidos do buffer.

### <a name="remarks"></a>Comentários

Se um [ler posição](../standard-library/basic-streambuf-class.md) estiver disponível, a função de membro retorna [egptr](#egptr) - [gptr](#gptr). Caso contrário, retorna [showmanyc](#showmanyc).

### <a name="example"></a>Exemplo

```cpp
// basic_streambuf_in_avail.cpp
// compile with: /EHsc
#include <iostream>

int main( )
{
   using namespace std;
   char c;
   // cin's buffer is empty, in_avail will return 0
   cout << cin.rdbuf( )->in_avail( ) << endl;
   cin >> c;
   cout << cin.rdbuf( )->in_avail( ) << endl;
}
```

## <a name="int_type"></a>  basic_streambuf::int_type

Associa um nome de tipo dentro do escopo de basic_streambuf a um dos tipos em um parâmetro de modelo.

```cpp
typedef typename traits_type::int_type int_type;
```

## <a name="off_type"></a>  basic_streambuf::off_type

Associa um nome de tipo dentro do escopo de basic_streambuf a um dos tipos em um parâmetro de modelo.

```cpp
typedef typename traits_type::off_type off_type;
```

## <a name="op_eq"></a>  basic_streambuf::operator=

Atribui os valores deste objeto de outro objeto `basic_streambuf`.

```cpp
basic_streambuf& operator=(const basic_streambuf& right);
```

### <a name="parameters"></a>Parâmetros

`right` Uma referência de lvalue para o `basic_streambuf` objeto que é usado para atribuir valores a este objeto.

### <a name="remarks"></a>Comentários

O operador membro protegido copia de `right` os ponteiros que controlam o buffer de entrada e o buffer de saída. Também armazena `right.`[getloc()](#getloc) no `locale object`. Ele retorna `*this`.

## <a name="overflow"></a>  basic_streambuf::overflow

Uma função virtual protegida que pode ser chamada quando um novo caractere é inserido em um buffer cheio.

```cpp
virtual int_type overflow(int_type _Meta = traits_type::eof());
```

### <a name="parameters"></a>Parâmetros

`_Meta` O caractere a ser inserido no buffer, ou **traits_type::**[eof](../standard-library/char-traits-struct.md#eof).

### <a name="return-value"></a>Valor de retorno

Se a função não conseguir obter sucesso, ela retornará **traits_type::eof** ou gerará uma exceção. Caso contrário, retornará **traits_type::**[not_eof](../standard-library/char-traits-struct.md#not_eof)(_ *Meta*). O comportamento padrão é retornar **traits_type::eof**.

### <a name="remarks"></a>Comentários

Se _ *Meta* não for equivalente a **traits_type::eof**, a função membro virtual protegida buscará inserir o elemento **traits_type::**[to_char_type](../standard-library/char-traits-struct.md#to_char_type)(\_ *Meta*) no fluxo de saída. Isso pode ser feito de várias maneiras:

- Se `write position` estiver disponível, ela poderá armazenar o elemento na posição de gravação e incrementar o próximo ponteiro para o buffer de saída.

- Ele pode disponibilizar uma posição de gravação alocando armazenamento novo ou adicional ao buffer de saída.

- Ele pode disponibilizar uma posição de gravação gravando, em algum destino externo, alguns ou todos os elementos entre os ponteiros inicial e seguinte para o buffer de saída.

A função de estouro virtual, junto com as funções [sync](#sync) e [underflow](#underflow), definem as características da classe derivada streambuf. Cada classe derivada pode implementar o estouro de forma diferente, mas a interface com a classe de fluxo de chamada é a mesma.

A função `overflow` frequentemente é chamada por funções `streambuf` públicas como `sputc` e `sputn` quando a área put está cheia, mas outras classes, incluindo as classes de fluxo, podem chamar `overflow` a qualquer momento.

A função consome os caracteres na área de put entre os ponteiros `pbase` e `pptr` e, em seguida, reinicializa a área put. A função `overflow` também deve consumir `nCh` (se `nCh` não for `EOF`) ou pode optar por colocar o caractere na nova área de put para que ele seja consumido na próxima chamada.

A definição de consumir varia entre as classes derivadas. Por exemplo, a classe `filebuf` grava seus caracteres em um arquivo, enquanto a classe `strstreambuf` os mantém em seu buffer e, se o buffer for designado como dinâmico, expande o buffer em resposta a uma chamada para estouro. Essa expansão é obtida liberando o buffer antigo e substituindo-o por um novo maior. Os ponteiros são ajustados conforme necessário.

## <a name="pbackfail"></a>  basic_streambuf::pbackfail

Uma função membro virtual protegida que tenta colocar um elemento de volta no fluxo de entrada, então torná-lo elemento atual (apontando para o ponteiro seguinte).

```cpp
virtual int_type pbackfail(int_type _Meta = traits_type::eof());
```

### <a name="parameters"></a>Parâmetros

`_Meta` O caractere a ser inserido no buffer, ou **traits_type::**[eof](../standard-library/char-traits-struct.md#eof).

### <a name="return-value"></a>Valor de retorno

Se a função não conseguir obter sucesso, ela retornará **traits_type::eof** ou gerará uma exceção. Caso contrário, retorna algum outro valor. O comportamento padrão é retornar **traits_type::eof**.

### <a name="remarks"></a>Comentários

Se _ *Meta* for comparável a **traits_type::eof**, o elemento a ser recuado será efetivamente aquele que já estava no fluxo antes do elemento atual. Caso contrário, esse elemento é substituído por **traits_type::**[to_char_type](../standard-library/char-traits-struct.md#to_char_type)(\_ *Meta*). A função pode colocar um elemento de volta de várias maneiras:

- Se uma posição putback estiver disponível, ela poderá armazenar o elemento na posição putback e diminuir o ponteiro seguinte para o buffer de entrada.

- Pode disponibilizar uma posição de putback alocando armazenamento novo ou adicional para o buffer de entrada.

- Para um buffer de fluxo com fluxos de entrada e saída comuns, ele pode disponibilizar uma posição de putback gravando, em algum destino externo, alguns ou todos os elementos entre os ponteiros inicial e seguintes para o buffer de saída.

## <a name="pbase"></a>  basic_streambuf::pbase

Uma função protegida que retorna um ponteiro para o início do buffer de saída.

```cpp
char_type *pbase() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o início do buffer de saída.

## <a name="pbump"></a>  basic_streambuf::pbump

Uma função protegida que adiciona `count` ao próximo ponteiro para o buffer de saída.

```cpp
void pbump(int count);
```

### <a name="parameters"></a>Parâmetros

`count` O número de caracteres pelo qual mover a posição de gravação para frente.

## <a name="pos_type"></a>  basic_streambuf::pos_type

Associa um nome de tipo dentro do escopo de basic_streambuf a um dos tipos em um parâmetro de modelo.

```cpp
typedef typename traits_type::pos_type pos_type;
```

## <a name="pptr"></a>  basic_streambuf::pptr

Uma função protegida que retorna um ponteiro para o próximo elemento do buffer de saída.

```cpp
char_type *pptr() const;
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o próximo elemento do buffer de saída.

## <a name="pubimbue"></a>  basic_streambuf::pubimbue

Define a localidade do objeto basic_streambuf.

```cpp
locale pubimbue(const locale& _Loc);
```

### <a name="parameters"></a>Parâmetros

`_Loc` Uma referência a uma localidade.

### <a name="return-value"></a>Valor de retorno

O valor anterior armazenado no objeto de localidade.

### <a name="remarks"></a>Comentários

A função membro armazena _ *Loc* no objeto de localidade e chama [imbue](#imbue).

### <a name="example"></a>Exemplo

Consulte [basic_ios::imbue](../standard-library/basic-ios-class.md#imbue) para obter um exemplo que usa `pubimbue`.

## <a name="pubseekoff"></a>  basic_streambuf::pubseekoff

Chama [seekoff](#seekoff), uma função virtual protegida que é substituída em uma classe derivada.

```cpp
pos_type pubseekoff(off_type _Off,
    ios_base::seekdir _Way,
    ios_base::openmode _Which = ios_base::in | ios_base::out);
```

### <a name="parameters"></a>Parâmetros

`_Off` A posição para buscar para relativo a `_Way`.

`_Way` O ponto de partida para operações de deslocamento. Consulte [seekdir](../standard-library/ios-base-class.md#seekdir) para valores possíveis.

`_Which` Especifica o modo para a posição do ponteiro. O padrão é permitir que você modifique as posições de leitura e gravação.

### <a name="return-value"></a>Valor de retorno

Retorna a nova posição ou uma posição de fluxo inválida ( [seekoff](#seekoff)(_ *Off*, `_Way`, `_Which`) ).

### <a name="remarks"></a>Comentários

Move o ponteiro com relação a `_Way`.

## <a name="pubseekpos"></a>  basic_streambuf::pubseekpos

Chama [seekpos](#seekpos), uma função virtual protegida que é substituída em uma classe derivada e redefine a posição atual do ponteiro.

```cpp
pos_type pubseekpos(pos_type _Sp, ios_base::openmode _Which = ios_base::in | ios_base::out);
```

### <a name="parameters"></a>Parâmetros

`_Sp` A posição de busca para.

`_Which` Especifica o modo para a posição do ponteiro. O padrão é permitir que você modifique as posições de leitura e gravação.

### <a name="return-value"></a>Valor de retorno

A nova posição ou uma posição de fluxo inválida. Para determinar se a posição de fluxo é inválida, compare o valor retornado com `pos_type(off_type(-1))`.

### <a name="remarks"></a>Comentários

A função membro retorna [seekpos](#seekpos)(_ *Sp*, `_Which`).

## <a name="pubsetbuf"></a>  basic_streambuf::pubsetbuf

Chama [setbuf](#setbuf), uma função virtual protegida que é substituída em uma classe derivada.

```cpp
basic_streambuf<Elem, Tr> *pubsetbuf(
    char_type* _Buffer,
    streamsize count);
```

### <a name="parameters"></a>Parâmetros

`_Buffer` Um ponteiro para `char_type` para essa instanciação.

`count` O tamanho do buffer.

### <a name="return-value"></a>Valor de retorno

Retorna [setbuf](#setbuf)( `_Buffer`, `count`).

## <a name="pubsync"></a>  basic_streambuf::pubsync

Chama [sync](#sync), uma função virtual protegida que é substituída em uma classe derivada e atualiza o fluxo externo associado a esse buffer.

```cpp
int pubsync();
```

### <a name="return-value"></a>Valor de retorno

Retorna [sincronização](#sync) ou -1 se falha.

## <a name="sbumpc"></a>  basic_streambuf::sbumpc

Lê e retorna o elemento atual, movendo o ponteiro de fluxo.

```cpp
int_type sbumpc();
```

### <a name="return-value"></a>Valor de retorno

O elemento atual.

### <a name="remarks"></a>Comentários

Se uma posição de leitura estiver disponível, a função membro retornará **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#to_int_type)( **\*** [gptr](#gptr)) e incrementará o ponteiro seguinte para o buffer de entrada. Caso contrário, retorna [uflow](#uflow).

### <a name="example"></a>Exemplo

```cpp
// basic_streambuf_sbumpc.cpp
// compile with: /EHsc
#include <iostream>

int main( )
{
   using namespace std;
   int i = 0;
   i = cin.rdbuf( )->sbumpc( );
   cout << i << endl;
}
```

```Output

3

```

```Output

      33
51
```

## <a name="seekoff"></a>  basic_streambuf::seekoff

Uma função de membro virtual protegida que tenta alterar as posições atuais para os fluxos controlados.

```cpp
virtual pos_type seekoff(
    off_type _Off,
    ios_base::seekdir _Way,
    ios_base::openmode _Which = ios_base::in | ios_base::out);
```

### <a name="parameters"></a>Parâmetros

`_Off` A posição para buscar para relativo a `_Way`.

`_Way` O ponto de partida para operações de deslocamento. Consulte [seekdir](../standard-library/ios-base-class.md#seekdir) para valores possíveis.

`_Which` Especifica o modo para a posição do ponteiro. O padrão é permitir que você modifique as posições de leitura e gravação.

### <a name="return-value"></a>Valor de retorno

Retorna a nova posição ou uma posição de fluxo inválida ( `seekoff` (_ *Off*, `_Way`, `_Which`) ).

### <a name="remarks"></a>Comentários

A nova posição é determinada da seguinte forma:

- Se `_Way`  ==  `ios_base::beg`, a nova posição é o início do fluxo mais _ *Off*.

- Se `_Way`  ==  `ios_base::cur`, a nova posição é a posição atual do fluxo mais _ *Off*.

- Se `_Way`  ==  `ios_base::end`, a nova posição é o final do fluxo mais _ *Off*.

Normalmente, se **which & ios_base::in** for diferente de zero, o fluxo de entrada será afetado; se **which & ios_base::out** for diferente de zero, o fluxo de saída será afetado. No entanto, o uso real desse parâmetro varia entre os buffers de fluxo derivados.

Se a função tiver êxito em alterar a posição ou as posições do fluxo, ela retornará a posição do fluxo resultante ou uma das posições do fluxo resultantes. Caso contrário, retorna uma posição de fluxo inválida. O comportamento padrão é retornar uma posição de fluxo inválida.

## <a name="seekpos"></a>  basic_streambuf::seekpos

Uma função de membro virtual protegida que tenta alterar as posições atuais para os fluxos controlados.

```cpp
virtual pos_type seekpos(pos_type _Sp, ios_base::openmode _Which = ios_base::in | ios_base::out);
```

### <a name="parameters"></a>Parâmetros

`_Sp` A posição de busca para.

`_Which` Especifica o modo para a posição do ponteiro. O padrão é permitir que você modifique as posições de leitura e gravação.

### <a name="return-value"></a>Valor de retorno

A nova posição ou uma posição de fluxo inválida. Para determinar se a posição de fluxo é inválida, compare o valor retornado com `pos_type(off_type(-1))`.

### <a name="remarks"></a>Comentários

A nova posição é _ *Sp*.

Normalmente, se **which & ios_base::in** for diferente de zero, o fluxo de entrada será afetado; se **which & ios_base::out** for diferente de zero, o fluxo de saída será afetado. No entanto, o uso real desse parâmetro varia entre os buffers de fluxo derivados.

Se a função tiver êxito em alterar a posição ou as posições do fluxo, ela retornará a posição do fluxo resultante ou uma das posições do fluxo resultantes. Caso contrário, retorna uma posição de fluxo inválida (-1). O comportamento padrão é retornar uma posição de fluxo inválida.

## <a name="setbuf"></a>  basic_streambuf::setbuf

A função membro virtual protegida que executa uma operação específica para cada buffer de fluxo derivado.

```cpp
virtual basic_streambuf<Elem, Tr> *setbuf(
    char_type* _Buffer,
    streamsize count);
```

### <a name="parameters"></a>Parâmetros

`_Buffer` Ponteiro para um buffer.

`count` Tamanho do buffer.

### <a name="return-value"></a>Valor de retorno

O comportamento padrão é retornar **this**.

### <a name="remarks"></a>Comentários

Consulte [basic_filebuf](../standard-library/basic-filebuf-class.md). `setbuf` fornece uma área de memória para o objeto `streambuf` usar. Como o buffer é usado é definido nas classes derivadas.

## <a name="setg"></a>  basic_streambuf::setg

Uma função protegida que armazena _ *Gbeg* no ponteiro de início, `_Gnext` no próximo ponteiro e `_Gend` no ponteiro final para o buffer de entrada.

```cpp
void setg(char_type* _Gbeg,
    char_type* _Gnext,
    char_type* _Gend);
```

### <a name="parameters"></a>Parâmetros

*_Gbeg* um ponteiro para o início do buffer.

`_Gnext` Um ponteiro para um local no meio do buffer.

`_Gend` Um ponteiro para o final do buffer.

## <a name="setp"></a>  basic_streambuf::setp

Uma função protegida que armazena `_Pbeg` no ponteiro inicial e `_Pend` no ponteiro final para o buffer de saída.

```cpp
void setp(char_type* _Pbeg, char_type* _Pend);
```

### <a name="parameters"></a>Parâmetros

`_Pbeg` Um ponteiro para o início do buffer.

`_Pend` Um ponteiro para o final do buffer.

## <a name="sgetc"></a>  basic_streambuf::sgetc

Retorna o elemento atual sem alterar a posição no fluxo.

```cpp
int_type sgetc();
```

### <a name="return-value"></a>Valor de retorno

O elemento atual.

### <a name="remarks"></a>Comentários

Se uma posição de leitura estiver disponível, a função membro retornará **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#to_int_type)( `*` [gptr](#gptr)). Caso contrário, retorna [underflow](#underflow).

### <a name="example"></a>Exemplo

```cpp
// basic_streambuf_sgetc.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

int main( )
{
   using namespace std;
   ifstream myfile( "basic_streambuf_sgetc.txt", ios::in );

   char i = myfile.rdbuf( )->sgetc( );
   cout << i << endl;
   i = myfile.rdbuf( )->sgetc( );
   cout << i << endl;
}
```

## <a name="sgetn"></a>  basic_streambuf::sgetn

Extrai até `count` caracteres do buffer de entrada e armazena-os no buffer `ptr` fornecido.

Esse método pode não ser seguro, pois depende do chamador para verificar se os valores passados estão corretos.

```cpp
streamsize sgetn(
    char_type* ptr,
    streamsize count);
```

### <a name="parameters"></a>Parâmetros

`ptr` O buffer para conter os caracteres extraídos.

`count` O número de elementos a serem lidos.

### <a name="return-value"></a>Valor de retorno

O número de elementos lidos. Consulte [streamsize](../standard-library/ios-typedefs.md#streamsize) para obter mais informações.

### <a name="remarks"></a>Comentários

A função membro retorna [xsgetn](#xsgetn)( `ptr`, `count`).

### <a name="example"></a>Exemplo

```cpp
// basic_streambuf_sgetn.cpp
// compile with: /EHsc /W3
#include <iostream>
#include <fstream>

int main()
{
    using namespace std;

    ifstream myfile("basic_streambuf_sgetn.txt", ios::in);
    char a[10];

    // Extract 3 characters from myfile and store them in a.
    streamsize i = myfile.rdbuf()->sgetn(&a[0], 3);  // C4996
    a[i] = myfile.widen('\0');

    // Display the size and contents of the buffer passed to sgetn.
    cout << i << " " << a << endl;

    // Display the contents of the original input buffer.
    cout << myfile.rdbuf() << endl;
}
```

## <a name="showmanyc"></a>  basic_streambuf::showmanyc

Uma função membro virtual protegida que retorna uma contagem do número de caracteres que pode ser extraído do fluxo de entrada e garante que o programa não esteja sujeito a uma espera indefinida.

```cpp
virtual streamsize showmanyc();
```

### <a name="return-value"></a>Valor de retorno

O comportamento padrão é retornar zero.

## <a name="snextc"></a>  basic_streambuf::snextc

Lê o elemento atual e retorna o elemento seguinte.

```cpp
int_type snextc();
```

### <a name="return-value"></a>Valor de retorno

O próximo elemento no fluxo.

### <a name="remarks"></a>Comentários

A função membro chama [sbumpc](#sbumpc) e, se essa função retornar **traits_type::**[eof](../standard-library/char-traits-struct.md#eof), retornará **traits_type::eof**. Caso contrário, retorna [sgetc](#sgetc).

### <a name="example"></a>Exemplo

```cpp
// basic_streambuf_snextc.cpp
// compile with: /EHsc
#include <iostream>
int main( )
{
   using namespace std;
   int i = 0;
   i = cin.rdbuf( )->snextc( );
   // cout << ( int )char_traits<char>::eof << endl;
   cout << i << endl;
}
```

```Output

aa

```

```Output

aa97
```

## <a name="sputbackc"></a>  basic_streambuf::sputbackc

Coloca um char_type no fluxo.

```cpp
int_type sputbackc(char_type _Ch);
```

### <a name="parameters"></a>Parâmetros

`_Ch` O caractere.

### <a name="return-value"></a>Valor de retorno

Retorna o caractere ou a falha.

### <a name="remarks"></a>Comentários

Se houver uma posição putback estiver disponível e `_Ch` for comparável ao caractere armazenado nessa posição, a função membro diminuirá o ponteiro seguinte para o buffer de entrada e retornará **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#to_int_type)( `_Ch`). Caso contrário, retorna [pbackfail](#pbackfail)( `_Ch`).

### <a name="example"></a>Exemplo

```cpp
// basic_streambuf_sputbackc.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

int main( )
{
    using namespace std;

    ifstream myfile("basic_streambuf_sputbackc.txt",
        ios::in);

    int i = myfile.rdbuf()->sbumpc();
    cout << (char)i << endl;
    int j = myfile.rdbuf()->sputbackc('z');
    if (j == 'z')
    {
        cout << "it worked" << endl;
    }
    i = myfile.rdbuf()->sgetc();
    cout << (char)i << endl;
}
```

## <a name="sputc"></a>  basic_streambuf::sputc

Coloca um caractere no fluxo.

```cpp
int_type sputc(char_type _Ch);
```

### <a name="parameters"></a>Parâmetros

`_Ch` O caractere.

### <a name="return-value"></a>Valor de retorno

Retorna o caractere, se for bem-sucedido.

### <a name="remarks"></a>Comentários

Se um `write position` estiver disponível, a função membro armazenará `_Ch` na posição de gravação, incrementará o ponteiro seguinte para o buffer de saída e retornará **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#to_int_type)( `_Ch`). Caso contrário, retorna [overflow](#overflow)( `_Ch`).

### <a name="example"></a>Exemplo

```cpp
// basic_streambuf_sputc.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

int main( )
{
   using namespace std;

   int i = cout.rdbuf( )->sputc( 'a' );
   cout << endl << ( char )i << endl;
}
```

```Output
a
a
```

## <a name="sputn"></a>  basic_streambuf::sputn

Coloca uma cadeia de caracteres no fluxo.

```cpp
streamsize sputn(const char_type* ptr, streamsize count);
```

### <a name="parameters"></a>Parâmetros

`ptr` A cadeia de caracteres.

`count` A contagem de caracteres.

### <a name="return-value"></a>Valor de retorno

O número de caracteres de fato inseridos no fluxo.

### <a name="remarks"></a>Comentários

A função membro retorna [xsputn](#xsputn)( `ptr`, `count`). Consulte a seção Comentários desse membro para obter mais informações.

### <a name="example"></a>Exemplo

```cpp
// basic_streambuf_sputn.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

int main()
{
    using namespace std;

    streamsize i = cout.rdbuf()->sputn("test", 4);
    cout << endl << i << endl;
}
```

```Output
test
4
```

## <a name="stossc"></a>  basic_streambuf::stossc

Move-se além do elemento atual no fluxo.

```cpp
void stossc();
```

### <a name="remarks"></a>Comentários

A função membro chama [sbumpc](#sbumpc). Observe que uma implementação não é necessária para fornecer essa função membro.

### <a name="example"></a>Exemplo

```cpp
// basic_streambuf_stossc.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

int main( )
{
   using namespace std;
   ifstream myfile( "basic_streambuf_stossc.txt", ios::in );

   myfile.rdbuf( )->stossc( );
   char i = myfile.rdbuf( )->sgetc( );
   cout << i << endl;
}
```

## <a name="sungetc"></a>  basic_streambuf::sungetc

Obtém um caractere do fluxo.

```cpp
int_type sungetc();
```

### <a name="return-value"></a>Valor de retorno

Retorna o caractere ou a falha.

### <a name="remarks"></a>Comentários

Se uma posição de putback estiver disponível, a função membro diminuirá o ponteiro seguinte para o buffer de entrada e retornará `traits_type::` [to_int_type](../standard-library/char-traits-struct.md#to_int_type)( `*` [gptr](#gptr)). No entanto, nem sempre é possível determinar o último caractere lido para que ele pode ser capturado no estado do buffer atual. Se isso for true, a função retornará [pbackfail](#pbackfail). Para evitar essa situação, acompanhe o caractere a colocado de volta e chame `sputbackc(ch)`, que não falhará, desde que você não o chame no início do fluxo e não tente colocar mais de um caractere de volta.

### <a name="example"></a>Exemplo

```cpp
// basic_streambuf_sungetc.cpp
// compile with: /EHsc
#include <iostream>
#include <fstream>

int main( )
{
   using namespace std;

   ifstream myfile( "basic_streambuf_sungetc.txt", ios::in );

   // Read and increment
   int i = myfile.rdbuf( )->sbumpc( );
   cout << ( char )i << endl;

   // Read and increment
   i = myfile.rdbuf( )->sbumpc( );
   cout << ( char )i << endl;

   // Decrement, read, and do not increment
   i = myfile.rdbuf( )->sungetc( );
   cout << ( char )i << endl;

   i = myfile.rdbuf( )->sungetc( );
   cout << ( char )i << endl;

   i = myfile.rdbuf( )->sbumpc( );
   cout << ( char )i << endl;
}
```

## <a name="swap"></a>  basic_streambuf::swap

Troca os valores nesse objeto pelos valores do objeto `basic_streambuf` fornecido.

```cpp
void swap(basic_streambuf& right);
```

### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`right`|Uma referência lvalue para o objeto `basic_streambuf` usada para trocar valores.|

### <a name="remarks"></a>Comentários

A função membro protegida troca com `right` todos os ponteiros controlando o `input buffer` e o `output buffer`. Também troca `right.`[getloc()](#getloc) com o objeto `locale`.

## <a name="sync"></a>  basic_streambuf::sync

Uma função virtual protegida que tenta sincronizar os fluxos controlados com quaisquer fluxos externos associados.

```cpp
virtual int sync();
```

### <a name="return-value"></a>Valor de retorno

Se a função não conseguir obter êxito, ela retornará -1. O comportamento padrão é retornar zero.

### <a name="remarks"></a>Comentários

`sync` envolve gravar quaisquer elementos entre os ponteiros inicial e seguinte para o buffer de saída. Não envolve colocar de volta nenhum elemento entre os ponteiros seguinte e final para o buffer de entrada.

## <a name="traits_type"></a>  basic_streambuf::traits_type

Associa um nome de tipo ao parâmetro de modelo **Tr**.

```cpp
typedef Tr traits_type;
```

## <a name="uflow"></a>  basic_streambuf::uflow

Função virtual protegida que extrai o elemento atual do fluxo de entrada.

```cpp
virtual int_type uflow();
```

### <a name="return-value"></a>Valor de retorno

O elemento atual.

### <a name="remarks"></a>Comentários

A função membro virtual protegida tenta extrair o elemento atual **ch** do fluxo de entrada, então avança a posição atual do fluxo e retorna o elemento como **traits_type::**[to_int_type](../standard-library/char-traits-struct.md#to_int_type)( **ch**). Isso pode ser feito de várias maneiras:

- Se houver uma posição de leitura estiver disponível, ela pegará **ch** como o elemento armazenado na posição leitura e avançará o próximo ponteiro para o buffer de entrada.

- Ele pode ler um elemento diretamente, de alguma fonte externa e entregá-lo como o valor **ch**.

- Para um buffer de fluxo com fluxos de entrada e saída comuns, ele pode disponibilizar uma posição de leitura gravando, em algum destino externo, alguns ou todos os elementos entre os ponteiros inicial e seguintes para o buffer de saída. Ou pode alocar armazenamento novo ou adicional para o buffer de entrada. A função então lê, de alguma fonte externa, um ou mais elementos.

Se a função não conseguir obter sucesso, ela retornará **traits_type::**[eof](../standard-library/char-traits-struct.md#eof) ou gerará uma exceção. Caso contrário, retornará o elemento `ch` atual no fluxo de entrada, convertido conforme descrito acima e avançará o ponteiro seguinte para o buffer de entrada. O comportamento padrão é chamar [underflow](#underflow) e, se essa função retornar **traits_type::eof**, retornar **traits_type::eof**. Caso contrário, a função retorna o elemento atual **ch** no fluxo de entrada, convertido conforme descrito anteriormente e avança o ponteiro seguinte para o buffer de entrada.

## <a name="underflow"></a>  basic_streambuf::underflow

Função virtual protegida para extrair o elemento atual do fluxo de entrada.

```cpp
virtual int_type underflow();
```

### <a name="return-value"></a>Valor de retorno

O elemento atual.

### <a name="remarks"></a>Comentários

A função membro virtual protegida busca extrair o elemento atual **ch** do fluxo de entrada, sem avançar a posição de fluxo atual e retorná-la como `traits_type::`[to_int_type](../standard-library/char-traits-struct.md#to_int_type)( **ch**). Isso pode ser feito de várias maneiras:

- Se uma posição de leitura estiver disponível, **ch** será o elemento armazenado na posição de leitura. Para obter mais informações sobre isso, consulte a seção Comentários da [Classe basic_streambuf](../standard-library/basic-streambuf-class.md).

- Pode disponibilizar uma posição de leitura alocando armazenamento novo ou adicional para o buffer de entrada, então lendo, de alguma fonte externa, um ou mais elementos. Para obter mais informações sobre isso, consulte a seção Comentários da [Classe basic_streambuf](../standard-library/basic-streambuf-class.md).

Se a função não conseguir obter sucesso, ela retornará `traits_type::`[eof](../standard-library/char-traits-struct.md#eof)`()` ou gerará uma exceção. Caso contrário, retornará o elemento atual no fluxo de entrada, convertido conforme descrito anteriormente. O comportamento padrão é retornar `traits_type::eof()`.

A função `underflow` virtual, com as funções [sync](#sync) e [overflow](#overflow), define as características da classe derivada de `streambuf`. Cada classe derivada pode implementar `underflow` de forma diferente, mas a interface com a classe de fluxo de chamada é a mesma.

A função `underflow` frequentemente é chamada por funções `streambuf` públicas como [sgetc](#sgetc) e [sgetn](#sgetn) quando a área get está vazia, mas outras classes, incluindo as classes de fluxo, podem chamar `underflow` a qualquer momento.

A função `underflow` fornece a área de get caracteres da fonte de entrada. Se a área get contiver caracteres, `underflow` retornará o primeiro caractere. Se a área get estiver vazia, ela preencherá a área get e retornará o caractere seguinte (que deixa na área get). Não se houver mais nenhum caractere disponível, `underflow` retornará `EOF` e deixará a área get vazia.

Na classe `strstreambuf`, `underflow` ajusta o ponteiro [egptr](#egptr) para acessar o armazenamento alocado dinamicamente por uma chamada para `overflow`.

## <a name="xsgetn"></a>  basic_streambuf::xsgetn

Função virtual protegida para extrair elementos do fluxo de entrada.

Esse método pode não ser seguro, pois depende do chamador para verificar se os valores passados estão corretos.

```cpp
virtual streamsize xsgetn(
    char_type* ptr,
    streamsize count);
```

### <a name="parameters"></a>Parâmetros

`ptr` O buffer para conter os caracteres extraídos.

`count` O número de elementos para extrair.

### <a name="return-value"></a>Valor de retorno

O número de elementos extraídos.

### <a name="remarks"></a>Comentários

A função de membro virtual protegida extrai até `count` elementos do fluxo de entrada, como por chamadas repetidas a [sbumpc](#sbumpc) e armazena-os na matriz que começa em `ptr`. Retorna o número de elementos realmente extraídos.

## <a name="xsputn"></a>  basic_streambuf::xsputn

Função virtual protegida para inserir elementos no fluxo de saída.

```cpp
virtual streamsize xsputn(const char_type* ptr, streamsize count);
```

### <a name="parameters"></a>Parâmetros

`ptr` Ponteiro para elementos para inserir.

`count` Número de elementos para inserir.

### <a name="return-value"></a>Valor de retorno

O número de elementos realmente inseridos no fluxo.

### <a name="remarks"></a>Comentários

A função de membro virtual protegida insere até `count` elementos no fluxo de saída, como se por chamadas repetidas a [sputc](#sputc), da matriz que começa em `ptr`. A inserção de caracteres no fluxo de saída para quando todos os caracteres `count` tiverem sido gravados ou se chamar `sputc( count)` retornaria `traits::eof()`. Retorna o número de elementos realmente inseridos.

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Programação de iostream](../standard-library/iostream-programming.md)<br/>
[Convenções de iostreams](../standard-library/iostreams-conventions.md)<br/>
