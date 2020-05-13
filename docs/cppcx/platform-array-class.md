---
title: Classe Platform::Array
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::Array
- VCCORLIB/Platform::Array::Value
helpviewer_keywords:
- Platform::Array Class
ms.assetid: 7815ab40-88c5-42b0-83b8-081cef0cda31
ms.openlocfilehash: d625d80df67a3c8207467ad629afd4c2bf88db18
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81318664"
---
# <a name="platformarray-class"></a>Classe Platform::Array

Representa uma matriz unidimensional modificável, que pode ser recebida e transmitida pela interface binária de aplicativo (ABI).

## <a name="syntax"></a>Sintaxe

```cpp
template <typename T>
private ref class Array<TArg, 1> :
    public WriteOnlyArray<TArg, 1>,
    public IBoxArray<TArg>
```

### <a name="members"></a>Membros

Platform::Array herda todos os métodos de [Platform::WriteOnlyArray Class](../cppcx/platform-writeonlyarray-class.md) e implementa a propriedade `Value` da [Platform::IBoxArray Interface](../cppcx/platform-iboxarray-interface.md).

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[Construtores de matriz](#ctor)|Inicializa uma matriz unidimensional e modificável de tipos especificados pelo parâmetro do modelo de classe, *T*.|

### <a name="methods"></a>Métodos

Consulte [Platform::WriteOnlyArray Class](../cppcx/platform-writeonlyarray-class.md).

### <a name="properties"></a>Propriedades

|||
|-|-|
|[Matriz::Valor](#value)|Recupera um identificador para a matriz atual.|

### <a name="remarks"></a>Comentários

A classe da matriz é fechada e não pode ser herdada.

O sistema de tipo Executar o Windows não suporta o conceito de matrizes irregulares\<e, portanto, você não pode passar um IVector<Plataforma::Array T>> como um valor de retorno ou parâmetro de método. Para passar uma matriz denteada ou uma sequência de sequências através da ABI, use `IVector<IVector<T>^>`.

Para obter mais informações sobre quando e como usar a Plataforma::Array, consulte [Array e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).

Essa classe é definida no cabeçalho vccorlib.h, que é incluído automaticamente pelo compilador. Ele é visível no IntelliSense, mas não no Object Browser porque não é um tipo público definido em platform.winmd.

### <a name="requirements"></a>Requisitos

Opção compilador: **/ZW**

## <a name="array-constructors"></a><a name="ctor"></a>Construtores de matrizes

Inicializa uma matriz unidimensional e modificável de tipos especificados pelo parâmetro do modelo de classe, *T*.

## <a name="syntax"></a>Sintaxe

```cpp
Array(unsigned int size);
Array(T* data, unsigned int size);
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Parâmetro de modelo de classe.

*Tamanho*<br/>
O número de elementos na matriz.

*dados*<br/>
Um ponteiro para uma matriz do tipo de dados `T` que é usado para inicializar esse objeto Array.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre como criar instâncias de Plataforma::Array, consulte [Array e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).

## <a name="arrayget-method"></a><a name="get"></a>Matriz::obter método

Recupera uma referência ao elemento de matriz no local do índice especificado.

## <a name="syntax"></a>Sintaxe

```cpp
T& get(unsigned int index)  const;
```

#### <a name="parameters"></a>Parâmetros

*Índice*<br/>
Um índice com base zero que identifica um elemento na matriz. O índice mínimo é 0 e o índice `size` máximo é o valor especificado pelo parâmetro no [construtor Array](#ctor).

### <a name="return-value"></a>Valor retornado

O elemento de matriz especificado pelo parâmetro `index`.

## <a name="arrayvalue-property"></a><a name="value"></a>Matriz::Propriedade de valor

Recupera um identificador para a matriz atual.

## <a name="syntax"></a>Sintaxe

```cpp
property Array^ Value;
```

### <a name="return-value"></a>Valor retornado

Um identificador para a matriz atual.

## <a name="see-also"></a>Confira também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)<br/>
[Matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md)
