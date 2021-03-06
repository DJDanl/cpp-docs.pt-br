---
title: Classe combinable
ms.date: 11/04/2016
f1_keywords:
- combinable
- PPL/concurrency::combinable
- PPL/concurrency::combinable::combinable
- PPL/concurrency::combinable::clear
- PPL/concurrency::combinable::combine
- PPL/concurrency::combinable::combine_each
- PPL/concurrency::combinable::local
helpviewer_keywords:
- combinable class
ms.assetid: fe0bfbf6-6250-47da-b8d0-f75369f0b5be
ms.openlocfilehash: d445b8ac1d2a8487e9e1ec4f21f63cf5ef071e91
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87224962"
---
# <a name="combinable-class"></a>Classe combinable

O `combinable<T>` objeto destina-se a fornecer cópias de dados de thread privado para executar subcoleções locais de thread sem bloqueio durante algoritmos paralelos. No final da operação paralela, os subcoleções thread-Private podem ser mesclados em um resultado final. Essa classe pode ser usada em vez de uma variável compartilhada e pode resultar em uma melhoria no desempenho se, de outra forma, houvesse muita contenção nessa variável compartilhada.

## <a name="syntax"></a>Sintaxe

```cpp
template<typename T>
class combinable;
```

### <a name="parameters"></a>parâmetros

*T*<br/>
O tipo de dados do resultado mesclado final. O tipo deve ter um construtor de cópia e um construtor padrão.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[combinable](#ctor)|Sobrecarregado. Constrói um novo objeto `combinable`.|
|[~ Destruidor combinável](#dtor)|Destrói um objeto `combinable`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[formatação](#clear)|Limpa os resultados computacionais intermediários de um uso anterior.|
|[Combine](#combine)|Computa um valor final do conjunto de subcoleções locais de thread chamando o functor de combinação fornecido.|
|[combine_each](#combine_each)|Computa um valor final do conjunto de subcoleções locais de thread chamando o functor de combinação fornecido uma vez por subcálculo local de thread. O resultado final é acumulado pelo objeto de função.|
|[local](#local)|Sobrecarregado. Retorna uma referência para o sub-cálculo thread-Private.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operador =](#operator_eq)|Atribui a um `combinable` objeto de outro `combinable` objeto.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [contêineres e objetos paralelos](../../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`combinable`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppl. h

**Namespace:** simultaneidade

## <a name="clear"></a><a name="clear"></a>formatação

Limpa os resultados computacionais intermediários de um uso anterior.

```cpp
void clear();
```

## <a name="combinable"></a><a name="ctor"></a>combináveis

Constrói um novo objeto `combinable`.

```cpp
combinable();

template <typename _Function>
explicit combinable(_Function _FnInitialize);

combinable(const combinable& _Copy);
```

### <a name="parameters"></a>parâmetros

*_Function*<br/>
O tipo do objeto de inicialização functor.

*_FnInitialize*<br/>
Uma função que será chamada para inicializar cada novo valor de thread privado do tipo `T` . Ele deve dar suporte a um operador de chamada de função com a assinatura `T ()` .

*_Copy*<br/>
Um `combinable` objeto existente a ser copiado para este.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa novos elementos com o construtor padrão para o tipo `T` .

O segundo construtor inicializa novos elementos usando o functor de inicialização fornecido como o `_FnInitialize` parâmetro.

O terceiro construtor é o construtor de cópia.

## <a name="combinable"></a><a name="dtor"></a>~ combinável

Destrói um objeto `combinable`.

```cpp
~combinable();
```

## <a name="combine"></a><a name="combine"></a>Combine

Computa um valor final do conjunto de subcoleções locais de thread chamando o functor de combinação fornecido.

```cpp
template<typename _Function>
T combine(_Function _FnCombine) const;
```

### <a name="parameters"></a>parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para combinar dois subcoleções de local de thread.

*_FnCombine*<br/>
O functor que é usado para combinar os subcálculos. Sua assinatura é `T (T, T)` ou `T (const T&, const T&)` , e deve ser associativa e comutador.

### <a name="return-value"></a>Valor retornado

O resultado final da combinação de todos os subcoleções de thread-Private.

## <a name="combine_each"></a><a name="combine_each"></a>combine_each

Computa um valor final do conjunto de subcoleções locais de thread chamando o functor de combinação fornecido uma vez por subcálculo local de thread. O resultado final é acumulado pelo objeto de função.

```cpp
template<typename _Function>
void combine_each(_Function _FnCombine) const;
```

### <a name="parameters"></a>parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para combinar uma única subcomputação de local de thread.

*_FnCombine*<br/>
O functor que é usado para combinar um subcálculo. Sua assinatura é `void (T)` ou `void (const T&)` , e deve ser associativa e comutador.

## <a name="local"></a><a name="local"></a>local

Retorna uma referência para o sub-cálculo thread-Private.

```cpp
T& local();

T& local(bool& _Exists);
```

### <a name="parameters"></a>parâmetros

*_Exists*<br/>
Uma referência a um booliano. O valor booliano referenciado por esse argumento será definido como **`true`** se a sub-rotina já existir nesse thread e definida como **`false`** se esta fosse a primeira subcomputação neste thread.

### <a name="return-value"></a>Valor retornado

Uma referência à subcomputação thread-Private.

## <a name="operator"></a><a name="operator_eq"></a>operador =

Atribui a um `combinable` objeto de outro `combinable` objeto.

```cpp
combinable& operator= (const combinable& _Copy);
```

### <a name="parameters"></a>parâmetros

*_Copy*<br/>
Um `combinable` objeto existente a ser copiado para este.

### <a name="return-value"></a>Valor retornado

Uma referência a este `combinable` objeto.

## <a name="see-also"></a>Confira também

[Namespace de simultaneidade](concurrency-namespace.md)
