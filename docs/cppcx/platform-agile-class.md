---
title: Classe Platform::Agile
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- AGILE/Platform::Platform
- AGILE/Platform::Platform::Agile::Agile
- AGILE/Platform::Platform::Agile::Get
- AGILE/Platform::Platform::Agile::GetAddressOf
- AGILE/Platform::Platform::Agile::GetAddressOfForInOut
- AGILE/Platform::Platform::Agile::Release
helpviewer_keywords:
- Platform::Agile
ms.assetid: e34459a9-c429-4c79-97fd-030c43ca4155
ms.openlocfilehash: 0822cef10b199a5bc3b33f116065816e380bf8a8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376510"
---
# <a name="platformagile-class"></a>Classe Platform::Agile

Representa um objeto que tem um MashalingBehavior=Standard como um objeto Agile, que reduz a possibilidade de exceções de threading do runtime. O `Agile<T>` permite que o objeto não Agile chame ou seja chamado do mesmo thread ou de um thread diferente. Para obter mais informações, consulte [Threading and Marshaling](../cppcx/threading-and-marshaling-c-cx.md).

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
class Agile;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O typename para a classe não Agile.

### <a name="remarks"></a>Comentários

A maioria das classes no Windows Runtime são ágeis. Um objeto Agile pode chamar ou ser chamado por um objeto em processo ou fora de processo no mesmo thread ou em um thread diferente. Se um objeto não for Agile, encapsule o objeto não Agile em um objeto `Agile<T>` , que seja Agile. Em seguida, pode-se realizar marshaling do objeto `Agile<T>` e o objeto não Agile subjacente pode ser usado.

A classe `Agile<T>` é uma classe do C++ nativa e padrão e requer o `agile.h`. Representa o *contexto*do objeto não Agile e do objeto Agile. O contexto especifica um modelo de threading e comportamento de marshaling de um objeto Agile. O sistema operacional usa o contexto para determinar como realizar marshaling de um objeto.

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Ágil::Ágil](#ctor)|Inicializa uma nova instância da classe Agile.|
|[Destruidor Agile::~Agile](#dtor)|Destrói a instância atual da classe Agile.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[Agile::Get](#get)|Retorna um identificador para o objeto representado pelo objeto Agile atual.|
|[Agile::GetAddressOf](#getaddressof)|Reinicializa o objeto Agile atual e retorna o endereço de um identificador para um objeto do tipo `T`.|
|[Agile::GetAddressOfForInOut](#getaddressofforinout)|Retorna o endereço de um identificador para o objeto representado pelo objeto Agile atual.|
|[Agile::Release](#release)|Descarta o objeto e o contexto subjacentes do objeto Agile atual.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Ágil::>de operador](#operator-arrow)|Recupera um endereço de um identificador para o objeto representado pelo objeto Agile atual.|
|[Agile::operator=](#operator-assign)|Atribui o objeto especificado ao objeto Agile atual.|

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`Object`

`Agile`

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Platform

**Cabeçalho:** agile.h

## <a name="agileagile-constructor"></a><a name="ctor"></a>Ágil::Construtor Ágil

Inicializa uma nova instância da classe Agile.

## <a name="syntax"></a>Sintaxe

```cpp
Agile();
Agile(T^ object);
Agile(const Agile<T>& object);
Agile(Agile<T>&& object);
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Um tipo especificado pelo parâmetro typename do modelo.

*Objeto*<br/>
Na segunda versão desse construtor, um objeto usado para inicializar uma nova instância de Agile. Na terceira versão, o objeto que é copiado para a nova instância de Agile. Na quarta versão, o objeto que é movido para a nova instância de Agile.

### <a name="remarks"></a>Comentários

A primeira versão desse construtor é o construtor padrão. A segunda versão inicializa a nova classe da instância de Agile do objeto especificado pelo parâmetro `object`. A terceira versão é o construtor de cópia. A quarta versão é o construtor de movimento. Esse construtor não pode gerar exceções.

## <a name="agileagile-destructor"></a><a name="dtor"></a>Ágil::~Destruidor ágil

Destrói a instância atual da classe Agile.

## <a name="syntax"></a>Sintaxe

```cpp
~Agile();
```

### <a name="remarks"></a>Comentários

Este destruidor também libera o objeto representado pelo objeto Agile atual.

## <a name="agileget-method"></a><a name="get"></a>Ágil::Obter método

Retorna um identificador para o objeto representado pelo objeto Agile atual.

## <a name="syntax"></a>Sintaxe

```cpp
T^ Get() const;
```

### <a name="return-value"></a>Valor retornado

Um identificador para o objeto representado pelo objeto Agile atual.

O tipo do valor retornado é, de fato, um tipo interno não revelado. Uma maneira conveniente de segurar o valor de retorno é atribuí-lo a uma variável que é declarada com a palavra-chave de dedução do tipo **automático.** Por exemplo, `auto x = myAgileTvariable->Get();`.

## <a name="agilegetaddressof-method"></a><a name="getaddressof"></a>Ágil::getAddressOf Method

Reinicializa o objeto Agile atual e retorna o endereço de um identificador para um objeto do tipo `T`.

## <a name="syntax"></a>Sintaxe

```cpp
T^* GetAddressOf() throw();
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Um tipo especificado pelo parâmetro typename do modelo.

### <a name="return-value"></a>Valor retornado

O endereço de um identificador para um objeto do tipo `T`.

### <a name="remarks"></a>Comentários

Esta operação libera a representação atual de um objeto do tipo `T`, se houver; reinicializa membros de dados do objeto Agile; adquire o contexto atual de threading; e retorna o endereço de uma variável de identificador para objeto que pode representar um objeto não Agile. Para fazer com que uma instância de classe Ágil represente um objeto, use o operador de atribuição[(Ágil::operador=](#operator-assign)) para atribuir o objeto à instância de classe Ágil.

## <a name="agilegetaddressofforinout-method"></a><a name="getaddressofforinout"></a>Ágil::getaddressofforinout method

Retorna o endereço de um identificador para o objeto representado pelo objeto Agile atual.

## <a name="syntax"></a>Sintaxe

```cpp
T^* GetAddressOfForInOut()  throw();
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Um tipo especificado pelo parâmetro typename do modelo.

### <a name="return-value"></a>Valor retornado

O endereço de um identificador para o objeto representado pelo objeto Agile atual.

### <a name="remarks"></a>Comentários

Esta operação adquire o contexto de threading atual e retorna o endereço de um identificador para o objeto subjacente.

## <a name="agilerelease-method"></a><a name="release"></a>Ágil::Método de lançamento

Descarta o objeto e o contexto subjacentes do objeto Agile atual.

## <a name="syntax"></a>Sintaxe

```cpp
void Release() throw();
```

### <a name="remarks"></a>Comentários

O objeto e o contexto subjacentes do objeto Agile atual serão descartados, caso existam, e o valor do objeto Agile será definido como nulo.

## <a name="agileoperator-gt-operator"></a><a name="operator-arrow"></a>Ágil::operador&gt; - Operador

Recupera um endereço de um identificador para o objeto representado pelo objeto Agile atual.

## <a name="syntax"></a>Sintaxe

```cpp
T^ operator->() const throw();
```

### <a name="return-value"></a>Valor retornado

Um identificador para o objeto representado pelo objeto Agile atual.

Esse operador retorna, na verdade, um tipo interno não revelado. Uma maneira conveniente de segurar o valor de retorno é atribuí-lo a uma variável que é declarada com a palavra-chave de dedução do tipo **automático.**

## <a name="agileoperator-operator"></a><a name="operator-assign"></a>Ágil::operador= Operador

Atribui o objeto especificado ao objeto Agile atual.

## <a name="syntax"></a>Sintaxe

```cpp
Agile<T> operator=( T^ object ) throw();
Agile<T> operator=( const Agile<T>& object ) throw();
Agile<T> operator=( Agile<T>&& object ) throw();
T^ operator=( IUnknown* lp ) throw();
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo especificado pelo typename do modelo.

*Objeto*<br/>
O objeto ou o identificador de um objeto que é copiado ou movido para o objeto Agile atual.

*Lp*<br/>
O ponteiro de interface de IUnknown de um objeto.

### <a name="return-value"></a>Valor retornado

Um identificador para um objeto do tipo `T`

### <a name="remarks"></a>Comentários

A primeira versão do operador de atribuição copia um identificador para um tipo de referência para o objeto Agile atual. A segunda versão copia uma referência a um tipo Agile para o objeto Agile atual. A terceira versão move um tipo Agile para o objeto Agile atual. A quarta versão move um ponteiro para um objeto COM para o objeto Agile atual.

A operação de atribuição persiste automaticamente o contexto do objeto Agile atual.

## <a name="see-also"></a>Confira também

[Espaço de nome da plataforma](platform-namespace-c-cx.md)
