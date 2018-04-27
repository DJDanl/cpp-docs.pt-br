---
title: Classe messages | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
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
caps.latest.revision: 18
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a66da5bc1b1352f4506e6294447a0610a3e1be4e
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
---
# <a name="messages-class"></a>Classe messages

A classe de modelo descreve um objeto que pode servir como uma faceta de localidade para recuperar mensagens localizadas em um catálogo de mensagens internacionalizadas de uma determinada localidade.

Atualmente, enquanto a classe de mensagens é implementada, não há mensagens.

## <a name="syntax"></a>Sintaxe

```cpp
template <class CharType>
class messages : public messages_base;
```

### <a name="parameters"></a>Parâmetros

`CharType` O tipo usado dentro de um programa para codificar caracteres em uma localidade.

## <a name="remarks"></a>Comentários

Como qualquer faceta de localidade, a ID de objeto estático tem um valor armazenado inicial de zero. A primeira tentativa de acessar seu valor armazenado armazena um valor positivo exclusivo na **id.**

Essa faceta, basicamente, abre um catálogo de mensagens definido na classe base messages_base, recupera as informações necessárias e fecha o catálogo.

### <a name="constructors"></a>Construtores

|Construtor|Descrição|
|-|-|
|[messages](#messages)|A função de construtor de faceta de mensagem.|

### <a name="typedefs"></a>Typedefs

|Nome de tipo|Descrição|
|-|-|
|[char_type](#char_type)|Um tipo de caractere usado para exibir mensagens.|
|[string_type](#string_type)|Um tipo que descreve uma cadeia de caracteres do tipo `basic_string` que contém caracteres do tipo `CharType`.|

### <a name="member-functions"></a>Funções de membro

|Função de membro|Descrição|
|-|-|
|[close](#close)|Fecha o catálogo de mensagens.|
|[do_close](#do_close)|Uma função virtual chamada para perder o catálogo de mensagens.|
|[do_get](#do_get)|Uma função virtual chamada para recuperar o catálogo de mensagens.|
|[do_open](#do_open)|Uma função virtual chamada para abrir o catálogo de mensagens.|
|[get](#get)|Recupera o catálogo de mensagens.|
|[open](#open)|Abre o catálogo de mensagens.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="char_type"></a>  messages::char_type

Um tipo de caractere usado para exibir mensagens.

```cpp
typedef CharType char_type;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo do parâmetro de modelo **CharType**.

## <a name="close"></a>  messages::close

Fecha o catálogo de mensagens.

```cpp
void close(catalog _Catval) const;
```

### <a name="parameters"></a>Parâmetros

`_Catval` O catálogo a ser fechado.

### <a name="remarks"></a>Comentários

A função membro chama [do_close](#do_close)(_ *Catval*).

## <a name="do_close"></a>  messages::do_close

Uma função virtual chamada para perder o catálogo de mensagens.

```cpp
virtual void do_close(catalog _Catval) const;
```

### <a name="parameters"></a>Parâmetros

`_Catval` O catálogo a ser fechado.

### <a name="remarks"></a>Comentários

A função membro protegido fecha o catálogo de mensagens `_Catval`, que deve ter sido aberto por uma chamada anterior para [do_open](#do_open).

*_Catval* deve ser obtido de um catálogo aberto anteriormente que não está fechado.

### <a name="example"></a>Exemplo

Consulte o exemplo de [close](#close), que chama `do_close`.

## <a name="do_get"></a>  messages::do_get

Uma função virtual chamada para recuperar o catálogo de mensagens.

```cpp
virtual string_type do_get(
    catalog _Catval,
    int _Set,
    int _Message,
    const string_type& _Dfault) const;
```

### <a name="parameters"></a>Parâmetros

`_Catval` O valor de identificação que especifica o catálogo de mensagem a ser pesquisada.

`_Set` O primeiro identificado usado para localizar uma mensagem em um catálogo de mensagem.

`_Message` O segundo identificado usado para localizar uma mensagem em um catálogo de mensagem.

`_Dfault` A cadeia de caracteres a ser retornado em caso de falha.

### <a name="return-value"></a>Valor de retorno

Ele retorna uma cópia do `_Dfault` em caso de falha. Caso contrário, ela retorna uma cópia da sequência de mensagem especificada.

### <a name="remarks"></a>Comentários

A função membro protegida tenta obter uma sequência de mensagens do catálogo de mensagens `_Catval`. Ela pode fazer uso de `_Set`, `_Message` e `_Dfault` dessa forma.

### <a name="example"></a>Exemplo

Consulte o exemplo de [get](#get), que chama `do_get`.

## <a name="do_open"></a>  messages::do_open

Uma função virtual chamada para abrir o catálogo de mensagens.

```cpp
virtual catalog do_open(
    const string& _Catname,
    const locale& _Loc) const;
```

### <a name="parameters"></a>Parâmetros

`_Catname` O nome do catálogo a ser pesquisada.

`_Loc` A localidade que está sendo procurada no catálogo.

### <a name="return-value"></a>Valor de retorno

Ele retorna um valor que compara menor que zero na falha. Caso contrário, o valor retornado pode ser usado como o primeiro argumento em uma chamada posterior para [get](#get).

### <a name="remarks"></a>Comentários

A função membro protegida tenta abrir um catálogo de mensagens cujo nome é `_Catname`. Ela pode fazer uso da localidade `_Loc` dessa forma

O valor retornado deve ser usado como o argumento em uma chamada posterior para [close](#close).

### <a name="example"></a>Exemplo

Consulte o exemplo de [open](#open), que chama `do_open`.

## <a name="get"></a>  messages::get

Recupera o catálogo de mensagens.

```cpp
string_type get(
    catalog _CatVal,
    int _Set,
    int _Message,
    const string_type& _Dfault) const;
```

### <a name="parameters"></a>Parâmetros

`_Catval` O valor de identificação que especifica o catálogo de mensagem a ser pesquisada.

`_Set` O primeiro identificado usado para localizar uma mensagem em um catálogo de mensagem.

`_Message` O segundo identificado usado para localizar uma mensagem em um catálogo de mensagem.

`_Dfault` A cadeia de caracteres a ser retornado em caso de falha.

### <a name="return-value"></a>Valor de retorno

Ele retorna uma cópia do `_Dfault` em caso de falha. Caso contrário, ela retorna uma cópia da sequência de mensagem especificada.

### <a name="remarks"></a>Comentários

A função membro retorna [do_get](#do_get)( `_Catval`, `_Set`, `_Message`, `_Dfault`).

## <a name="messages"></a>  messages::messages

A função de construtor de faceta de mensagem.

```cpp
explicit messages(
    size_t _Refs = 0);

protected: messages(
    const char* _Locname,
    size_t _Refs = 0);
```

### <a name="parameters"></a>Parâmetros

`_Refs` Valor inteiro usado para especificar o tipo de gerenciamento de memória para o objeto.

`_Locname` O nome da localidade.

### <a name="remarks"></a>Comentários

Os valores possíveis para o parâmetro `_Refs` e sua significância são:

- 0: o tempo de vida do objeto é gerenciado pelas localidades que o contêm.

- 1: o tempo de vida do objeto deve ser gerenciado manualmente.

- \> 1: esses valores não são definidos.

Nenhum exemplo direto é possível, pois o destruidor está protegido.

O construtor inicializa seu objeto base com **locale::**[facet](../standard-library/locale-class.md#facet_class)( `_Refs`).

## <a name="open"></a>  messages::open

Abre o catálogo de mensagens.

```cpp
catalog open(
    const string& _Catname,
    const locale& _Loc) const;
```

### <a name="parameters"></a>Parâmetros

`_Catname` O nome do catálogo a ser pesquisada.

`_Loc` A localidade que está sendo procurada no catálogo.

### <a name="return-value"></a>Valor de retorno

Ele retorna um valor que compara menor que zero na falha. Caso contrário, o valor retornado pode ser usado como o primeiro argumento em uma chamada posterior para [get](#get).

### <a name="remarks"></a>Comentários

A função membro retorna [do_open](#do_open)( `_Catname`, `_Loc`).

## <a name="string_type"></a>  messages::string_type

Um tipo que descreve uma cadeia de caracteres do tipo `basic_string` que contém caracteres do tipo **CharType**.

```cpp
typedef basic_string<CharType, Traits, Allocator> string_type;
```

### <a name="remarks"></a>Comentários

O tipo descreve uma especialização da classe de modelo [basic_string](../standard-library/basic-string-class.md) cujos objetos podem armazenar cópias das sequências de mensagens.

## <a name="see-also"></a>Consulte também

[\<locale>](../standard-library/locale.md)<br/>
[Classe messages_base](../standard-library/messages-base-class.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
