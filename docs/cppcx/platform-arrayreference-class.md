---
title: Classe Platform::ArrayReference
ms.date: 10/16/2019
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::ArrayReference::ArrayReference
helpviewer_keywords:
- Platform::ArrayReference Class
ms.assetid: 9ab3b15e-8a60-4600-8fcb-7d6c86284f4b
ms.openlocfilehash: e9dd16ad6c3f53c5562b0419197a582c06fbc642
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81354795"
---
# <a name="platformarrayreference-class"></a>Classe Platform::ArrayReference

`ArrayReference` é um tipo de otimização que você pode substituir por [Platform::Array^](../cppcx/platform-array-class.md) em parâmetros de entrada quando você deseja preencher uma matriz de estilo C com os dados de entrada.

## <a name="syntax"></a>Sintaxe

```cpp
class ArrayReference
```

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[arrayReference::ArrayReference](#ctor)|Inicia uma nova instância da classe `ArrayReference`.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[ArrayReference::operador() Operador](#operator-call)|Converte essa `ArrayReference` em uma `Platform::Array<T>^*`.|
|[Operador ArrayReference::operator=](#operator-assign)|Atribui o conteúdo de outra `ArrayReference` a essa instância.|

## <a name="exceptions"></a>Exceções

### <a name="remarks"></a>Comentários

Usando `ArrayReference` para preencher uma matriz de estilo C, você evita a operação de cópia adicional que estaria envolvida ao copiar primeiramente em uma variável `Platform::Array` e, em seguida, na matriz de estilo C. Quando você usa `ArrayReference`, há apenas uma operação de cópia. Para um exemplo de código, consulte [Array e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).

### <a name="requirements"></a>Requisitos

**Cliente com suporte mínimo:** Windows 8

**Servidor com suporte mínimo:** Windows Server 2012

**Namespace:** Platform

**Cabeçalho:** vccorlib.h

## <a name="arrayreferencearrayreference-constructor"></a><a name="ctor"></a>Referência de array::ArrayReference Constructor

Inicializa uma nova instância da [classe Plataforma::ArrayReference.](../cppcx/platform-arrayreference-class.md)

### <a name="syntax"></a>Sintaxe

```cpp
ArrayReference(TArg* ataArg, unsigned int sizeArg, bool needsInitArg = false);
ArrayReference(ArrayReference&& otherArg)
```

### <a name="parameters"></a>Parâmetros

*dataArg*<br/>
Ponteiro para os dados de matriz.

*sizeArg*<br/>
O número de elementos na matriz de origem.

*otherArg*<br/>
Objeto `ArrayReference` cujos dados serão movidos para inicializar a nova instância.

### <a name="remarks"></a>Comentários

## <a name="arrayreferenceoperator-operator"></a><a name="operator-assign"></a>ArrayReference::operator= Operador

Atribui o objeto especificado à [plataforma atual::ArrayObjeto de referência](../cppcx/platform-arrayreference-class.md) usando semântica de movimento.

### <a name="syntax"></a>Sintaxe

```cpp
ArrayReference& operator=(ArrayReference&& otherArg);
```

### <a name="parameters"></a>Parâmetros

*otherArg*<br/>
O objeto que é movido para o objeto `ArrayReference` atual.

### <a name="return-value"></a>Valor retornado

Referência a um objeto do tipo `ArrayReference`.

### <a name="remarks"></a>Comentários

`Platform::ArrayReference` é um modelo de classe C++ padrão, não uma classe de referência.

## <a name="arrayreferenceoperator-operator"></a><a name="operator-call"></a>ArrayReference::operador() Operador

Converte o objeto [Plataforma atual::ArrayReference](../cppcx/platform-arrayreference-class.md) de volta para uma [classe Plataforma::Array.](../cppcx/platform-array-class.md)

### <a name="syntax"></a>Sintaxe

```cpp
Array<TArg>^ operator ();
```

### <a name="return-value"></a>Valor retornado

Um identificador para um objeto do tipo `Array<TArg>^`

### <a name="remarks"></a>Comentários

[Plataforma::ArrayReference](../cppcx/platform-arrayreference-class.md) é um modelo de classe C++ padrão e [Plataforma::Array](../cppcx/platform-array-class.md) é uma classe ref.

## <a name="see-also"></a>Confira também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
