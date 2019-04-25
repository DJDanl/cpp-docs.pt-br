---
title: Classe Platform::Array
ms.date: 12/30/2016
ms.topic: reference
f1_keywords:
- VCCORLIB/Namespace not found::Platform
- VCCORLIB/Namespace not found::Platform::Array Constructors
- VCCORLIB/Namespace not found::Platform::Array::Value
helpviewer_keywords:
- Platform::Array Class
ms.assetid: 7815ab40-88c5-42b0-83b8-081cef0cda31
ms.openlocfilehash: 597f8e32e2da95370169cdbfe2ccd209296322cc
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62161649"
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
|[Array::Value](#value)|Recupera um identificador para a matriz atual.|

### <a name="remarks"></a>Comentários

A classe da matriz é fechada e não pode ser herdada.

O sistema de tipo de tempo de execução do Windows não suporta o conceito de matrizes denteadas e, portanto, você não pode passar um IVector < Platform:: array\<T >> como um parâmetro de método ou valor de retorno. Para passar uma matriz denteada ou uma sequência de sequências através da ABI, use `IVector<IVector<T>^>`.

Para obter mais informações sobre quando e como usar Platform:: array, consulte [matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).

O sistema de tipo de tempo de execução do Windows não suporta o conceito de matrizes denteadas e, portanto, você não pode passar um IVector < Platform:: array\<T >> como um parâmetro de método ou valor de retorno. Para passar uma matriz denteada ou uma sequência de sequências através da ABI, use `IVector<IVector<T>^>`.

Essa classe é definida no cabeçalho vccorlib.h, que é incluído automaticamente pelo compilador. Ele é visível no IntelliSense mas não no Pesquisador de objetos porque ele não é um tipo público definido em Platform. winmd.

### <a name="requirements"></a>Requisitos

Opção do compilador: **/ZW**

## <a name="ctor"></a>  Construtores de matriz

Inicializa uma matriz unidimensional e modificável de tipos especificados pelo parâmetro do modelo de classe, *T*.

## <a name="syntax"></a>Sintaxe

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

Para obter mais informações sobre como criar instâncias de Platform:: array, consulte [matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).

## <a name="get"></a>  Método Array:: Get

Recupera uma referência ao elemento de matriz no local do índice especificado.

## <a name="syntax"></a>Sintaxe

```cpp
T& get(unsigned int index)  const;
```

#### <a name="parameters"></a>Parâmetros

*index*<br/>
Um índice com base zero que identifica um elemento na matriz. O índice mínimo é 0 e o índice máximo é o valor especificado pela `size` parâmetro na [construtor Array](#ctor).

### <a name="return-value"></a>Valor de retorno

O elemento de matriz especificado pelo parâmetro `index`.

## <a name="value"></a>  Propriedade array:: Value

Recupera um identificador para a matriz atual.

## <a name="syntax"></a>Sintaxe

```cpp
property Array^ Value;
```

### <a name="return-value"></a>Valor de retorno

Um identificador para a matriz atual.

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)<br/>
[Matriz e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md)
