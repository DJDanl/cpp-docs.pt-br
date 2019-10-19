---
title: Classe Platform::ArrayReference
ms.date: 10/16/2019
ms.topic: reference
f1_keywords:
- VCCORLIB/Platform::ArrayReference::ArrayReference
helpviewer_keywords:
- Platform::ArrayReference Class
ms.assetid: 9ab3b15e-8a60-4600-8fcb-7d6c86284f4b
ms.openlocfilehash: f7e587902f1c99b294ed79255397aeffccee26b5
ms.sourcegitcommit: 8178d22701047d24f69f10d01ba37490e3d67241
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/18/2019
ms.locfileid: "72587923"
---
# <a name="platformarrayreference-class"></a>Classe Platform::ArrayReference

`ArrayReference` é um tipo de otimização que você pode substituir por [Platform::Array^](../cppcx/platform-array-class.md) em parâmetros de entrada quando você deseja preencher uma matriz de estilo C com os dados de entrada.

## <a name="syntax"></a>Sintaxe

```cpp
class ArrayReference
```

### <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Name|Descrição|
|----------|-----------------|
|[ArrayReference::ArrayReference](#ctor)|Inicializa uma nova instância da classe `ArrayReference` .|

### <a name="public-operators"></a>Operadores públicos

|Name|Descrição|
|----------|-----------------|
|[Operador ArrayReference::operator()](#operator-call)|Converte essa `ArrayReference` em uma `Platform::Array<T>^*`.|
|[Operador ArrayReference::operator=](#operator-assign)|Atribui o conteúdo de outra `ArrayReference` a essa instância.|

## <a name="exceptions"></a>Exceções

### <a name="remarks"></a>Comentários

Usando `ArrayReference` para preencher uma matriz de estilo C, você evita a operação de cópia adicional que estaria envolvida ao copiar primeiramente em uma variável `Platform::Array` e, em seguida, na matriz de estilo C. Quando você usa `ArrayReference`, há apenas uma operação de cópia. Para obter um exemplo de código, consulte [array e WriteOnlyArray](../cppcx/array-and-writeonlyarray-c-cx.md).

### <a name="requirements"></a>Requisitos

**Mínimo de cliente com suporte:** Windows 8

**Mínimo de servidor com suporte:** Windows Server 2012

**Namespace:** Platform

**Cabeçalho:** vccorlib.h

## <a name="ctor"></a>Construtor ArrayReference:: ArrayReference

Inicializa uma nova instância da classe [Platform:: ArrayReference](../cppcx/platform-arrayreference-class.md) .

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

## <a name="operator-assign"></a>Operador ArrayReference:: Operator =

Atribui o objeto especificado ao objeto [Platform:: ArrayReference](../cppcx/platform-arrayreference-class.md) atual usando a semântica de movimentação.

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

## <a name="operator-call"></a>Operador ArrayReference:: Operator ()

Converte o objeto [Platform:: ArrayReference](../cppcx/platform-arrayreference-class.md) atual de volta para uma classe [Platform:: array](../cppcx/platform-array-class.md) .

### <a name="syntax"></a>Sintaxe

```cpp
Array<TArg>^ operator ();
```

### <a name="return-value"></a>Valor retornado

Um identificador para um objeto do tipo `Array<TArg>^`

### <a name="remarks"></a>Comentários

[Platform:: ArrayReference](../cppcx/platform-arrayreference-class.md) é um modelo C++ de classe padrão, e [Platform:: array](../cppcx/platform-array-class.md) é uma classe ref.

## <a name="see-also"></a>Consulte também

[Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)
