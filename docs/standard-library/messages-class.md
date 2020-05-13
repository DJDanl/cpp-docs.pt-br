---
title: Classe messages
ms.date: 11/04/2016
f1_keywords:
- xlocmes/std::messages
- xlocmes/std::messages::char_type
- xlocmes/std::messages::string_type
- xlocmes/std::messages::close
- xlocmes/std::messages::do_close
- xlocmes/std::messages::do_get
- xlocmes/std::messages::do_open
- xlocmes/std::messages::get
- xlocmes/std::messages::open
helpviewer_keywords:
- std::messages [C++]
- std::messages [C++], char_type
- std::messages [C++], string_type
- std::messages [C++], close
- std::messages [C++], do_close
- std::messages [C++], do_get
- std::messages [C++], do_open
- std::messages [C++], get
- std::messages [C++], open
ms.assetid: c4c71f40-4f24-48ab-9f7c-daccd8d5bd83
ms.openlocfilehash: deb9eaedba3c99bb2fcb8399ac412ccedb11545f
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375917"
---
# <a name="messages-class"></a>Classe messages

O modelo de classe descreve um objeto que pode servir como uma faceta local para recuperar mensagens localizadas de um catálogo de mensagens internacionalizadas para um determinado local.

Atualmente, enquanto a classe de mensagens é implementada, não há mensagens.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType>
class messages : public messages_base;
```

### <a name="parameters"></a>Parâmetros

*CharType*\
O tipo usado em um programa para codificar caracteres em uma localidade.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**

Essa faceta, basicamente, abre um catálogo de mensagens definido na classe base messages_base, recupera as informações necessárias e fecha o catálogo.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[Mensagens](#messages)|A função de construtor de faceta de mensagem.|

### <a name="typedefs"></a>Typedefs

|Nome do tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo de caractere usado para exibir mensagens.|
|[string_type](#string_type)|Um tipo que descreve uma cadeia de caracteres do tipo `basic_string` que contém caracteres do tipo `CharType`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[Perto](#close)|Fecha o catálogo de mensagens.|
|[do_close](#do_close)|Uma função virtual chamada para perder o catálogo de mensagens.|
|[do_get](#do_get)|Uma função virtual chamada para recuperar o catálogo de mensagens.|
|[do_open](#do_open)|Uma função virtual chamada para abrir o catálogo de mensagens.|
|[get](#get)|Recupera o catálogo de mensagens.|
|[open](#open)|Abre o catálogo de mensagens.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="messageschar_type"></a><a name="char_type"></a>mensagens::char_type

Um tipo de caractere usado para exibir mensagens.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o parâmetro de modelo **CharType**.

## <a name="messagesclose"></a><a name="close"></a>mensagens::fechar

Fecha o catálogo de mensagens.

```cpp
void close(catalog _Catval) const;
```

### <a name="parameters"></a>Parâmetros

*_Catval*\
O catálogo a ser fechado.

### <a name="remarks"></a>Comentários

A função membro chama [do_close](#do_close)(_ *Catval*).

## <a name="messagesdo_close"></a><a name="do_close"></a>mensagens::do_close

Uma função virtual chamada para perder o catálogo de mensagens.

```cpp
virtual void do_close(catalog _Catval) const;
```

### <a name="parameters"></a>Parâmetros

*_Catval*\
O catálogo a ser fechado.

### <a name="remarks"></a>Comentários

A função membro protegido fecha o catálogo de mensagens *_Catval*, que deve ter sido aberta por uma chamada anterior para [do_open](#do_open).

*_Catval* deve ser obtido de um catálogo aberto anteriormente que não está fechado.

### <a name="example"></a>Exemplo

Consulte o exemplo de [close](#close), que chama `do_close`.

## <a name="messagesdo_get"></a><a name="do_get"></a>mensagens::do_get

Uma função virtual chamada para recuperar o catálogo de mensagens.

```cpp
virtual string_type do_get(
    catalog _Catval,
    int _Set,
    int _Message,
    const string_type& _Dfault) const;
```

### <a name="parameters"></a>Parâmetros

*_Catval*\
O valor de identificação que especifica o catálogo de mensagens a ser pesquisado.

*_Set*\
O primeiro identificado usado para localizar uma mensagem em um catálogo de mensagens.

*_Message*\
O segundo identificado usado para localizar uma mensagem em um catálogo de mensagens.

*_Dfault*\
A cadeia de caracteres a ser retornada em caso de falha.

### <a name="return-value"></a>Valor retornado

Ele retorna uma cópia de *_Dfault* sobre o fracasso. Caso contrário, ela retorna uma cópia da sequência de mensagem especificada.

### <a name="remarks"></a>Comentários

A função membro protegido tenta obter uma seqüência de mensagens do catálogo de mensagens *_Catval*. Pode fazer uso de *_Set,* *_Message*e *_Dfault* ao fazê-lo.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get](#get), que chama `do_get`.

## <a name="messagesdo_open"></a><a name="do_open"></a>mensagens::do_open

Uma função virtual chamada para abrir o catálogo de mensagens.

```cpp
virtual catalog do_open(
    const string& _Catname,
    const locale& _Loc) const;
```

### <a name="parameters"></a>Parâmetros

*_Catname*\
O nome do catálogo a ser pesquisado.

*_Loc*\
A localidade que está sendo pesquisada no catálogo.

### <a name="return-value"></a>Valor retornado

Ele retorna um valor que compara menor que zero na falha. Caso contrário, o valor retornado pode ser usado como o primeiro argumento em uma chamada posterior para [get](#get).

### <a name="remarks"></a>Comentários

A função de membro protegido tenta abrir um catálogo de mensagens cujo nome é *_Catname*. Ele pode fazer uso do *local _Loc* em fazê-lo

O valor retornado deve ser usado como o argumento em uma chamada posterior para [close](#close).

### <a name="example"></a>Exemplo

Consulte o exemplo de [open](#open), que chama `do_open`.

## <a name="messagesget"></a><a name="get"></a>mensagens::get

Recupera o catálogo de mensagens.

```cpp
string_type get(
    catalog _CatVal,
    int _Set,
    int _Message,
    const string_type& _Dfault) const;
```

### <a name="parameters"></a>Parâmetros

*_Catval*\
O valor de identificação que especifica o catálogo de mensagens a ser pesquisado.

*_Set*\
O primeiro identificado usado para localizar uma mensagem em um catálogo de mensagens.

*_Message*\
O segundo identificado usado para localizar uma mensagem em um catálogo de mensagens.

*_Dfault*\
A cadeia de caracteres a ser retornada em caso de falha.

### <a name="return-value"></a>Valor retornado

Ele retorna uma cópia de *_Dfault* sobre o fracasso. Caso contrário, ela retorna uma cópia da sequência de mensagem especificada.

### <a name="remarks"></a>Comentários

A função do `_Catval`membro `_Set` `_Message`retorna `_Dfault` [do_get](#do_get)( , , ).

## <a name="messagesmessages"></a><a name="messages"></a>mensagens::mensagens

A função de construtor de faceta de mensagem.

```cpp
explicit messages(
    size_t _Refs = 0);

protected: messages(
    const char* _Locname,
    size_t _Refs = 0);
```

### <a name="parameters"></a>Parâmetros

*_Refs*\
Valor inteiro usado para especificar o tipo de gerenciamento de memória do objeto.

*_Locname*\
O nome da localidade.

### <a name="remarks"></a>Comentários

Os valores possíveis para o *parâmetro _Refs* e sua significância são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \>1: Esses valores não estão definidos.

Nenhum exemplo direto é possível, pois o destruidor está protegido.

O construtor inicializa seu objeto base com **locale::**[facet](../standard-library/locale-class.md#facet_class)( `_Refs`).

## <a name="messagesopen"></a><a name="open"></a>mensagens::abrir

Abre o catálogo de mensagens.

```cpp
catalog open(
    const string& _Catname,
    const locale& _Loc) const;
```

### <a name="parameters"></a>Parâmetros

*_Catname*\
O nome do catálogo a ser pesquisado.

*_Loc*\
A localidade que está sendo pesquisada no catálogo.

### <a name="return-value"></a>Valor retornado

Ele retorna um valor que compara menor que zero na falha. Caso contrário, o valor retornado pode ser usado como o primeiro argumento em uma chamada posterior para [get](#get).

### <a name="remarks"></a>Comentários

A função do `_Catname`membro `_Loc`retorna [do_open](#do_open)( , ).

## <a name="messagesstring_type"></a><a name="string_type"></a>mensagens::string_type

Um tipo que descreve uma cadeia de caracteres do tipo `basic_string` que contém caracteres do tipo `CharType`.

```cpp
typedef basic_string<CharType, Traits, Allocator> string_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização do modelo de classe [basic_string](../standard-library/basic-string-class.md) cujos objetos podem armazenar cópias das seqüências de mensagens.

## <a name="see-also"></a>Confira também

[\<local>](../standard-library/locale.md)\
[Classe messages_base](../standard-library/messages-base-class.md)\
[Segurança de threads na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
