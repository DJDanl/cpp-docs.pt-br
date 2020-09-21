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
ms.openlocfilehash: 4903c18f981c87c418a6ab08595816ce22a7413c
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90742938"
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

| Nome | Descrição |
|--|--|
| [Matriz:: valor](#value) | Recupera um identificador para a matriz atual. |

### <a name="remarks"></a>Comentários

A classe da matriz é fechada e não pode ser herdada.

O sistema do tipo Windows Runtime não oferece suporte ao conceito de matrizes denteadas e, portanto, você não pode passar um `IVector<Platform::Array<T>>` como um valor de retorno ou um parâmetro de método. Para passar uma matriz denteada ou uma sequência de sequências através da ABI, use `IVector<IVector<T>^>`.

Para obter mais informações sobre quando e como usar o platform:: Array, consulte [array e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).

Essa classe é definida no cabeçalho vccorlib.h, que é incluído automaticamente pelo compilador. Ele é visível no IntelliSense, mas não no Pesquisador de objetos porque não é um tipo público definido em Platform. winmd.

### <a name="requirements"></a>Requisitos

Opção do compilador: **/zw**

## <a name="array-constructors"></a><a name="ctor"></a> Construtores de matriz

Inicializa uma matriz unidimensional e modificável de tipos especificados pelo parâmetro do modelo de classe, *T*.

### <a name="syntax"></a>Sintaxe

```cpp
Array(unsigned int size);
Array(T* data, unsigned int size);
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Parâmetro de modelo de classe.

*size*<br/>
O número de elementos na matriz.

*data*<br/>
Um ponteiro para uma matriz do tipo de dados `T` que é usado para inicializar esse objeto Array.

### <a name="remarks"></a>Comentários

Para obter mais informações sobre como criar instâncias de Platform:: Array, consulte [array e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).

## <a name="arrayget-method"></a><a name="get"></a> Método Array:: Get

Recupera uma referência ao elemento de matriz no local do índice especificado.

### <a name="syntax"></a>Sintaxe

```cpp
T& get(unsigned int index)  const;
```

#### <a name="parameters"></a>Parâmetros

*index*<br/>
Um índice com base zero que identifica um elemento na matriz. O índice mínimo é 0 e o índice máximo é o valor especificado pelo `size` parâmetro no construtor de [matriz](#ctor).

### <a name="return-value"></a>Valor Retornado

O elemento de matriz especificado pelo parâmetro `index`.

## <a name="arrayvalue-property"></a><a name="value"></a> Propriedade Array:: Value

Recupera um identificador para a matriz atual.

### <a name="syntax"></a>Sintaxe

```cpp
property Array^ Value;
```

### <a name="return-value"></a>Valor retornado

Um identificador para a matriz atual.

## <a name="see-also"></a>Confira também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)<br/>
[Matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md)
