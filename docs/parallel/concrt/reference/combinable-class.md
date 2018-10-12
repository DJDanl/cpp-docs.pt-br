---
title: Classe combinable | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-concrt
ms.topic: reference
f1_keywords:
- combinable
- PPL/concurrency::combinable
- PPL/concurrency::combinable::combinable
- PPL/concurrency::combinable::clear
- PPL/concurrency::combinable::combine
- PPL/concurrency::combinable::combine_each
- PPL/concurrency::combinable::local
dev_langs:
- C++
helpviewer_keywords:
- combinable class
ms.assetid: fe0bfbf6-6250-47da-b8d0-f75369f0b5be
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d544ac392e2eb227d7e1c37412110d09272f10d5
ms.sourcegitcommit: 8480f16893f09911f08a58caf684405404f7ac8e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49162497"
---
# <a name="combinable-class"></a>Classe combinable

O `combinable<T>` objeto destina-se a fornecer cópias de thread privada dos dados, executar cálculos de subpropriedades de local de thread livre de bloqueio durante algoritmos paralelos. No final da operação em paralelo, os cálculos de subpropriedades de thread / privada, em seguida, podem ser mesclados em um resultado final. Essa classe pode ser usado em vez de uma variável compartilhada e pode resultar em uma melhoria de desempenho em caso de outra forma muita contenção naquela variável compartilhada.

## <a name="syntax"></a>Sintaxe

```
template<typename T>
class combinable;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
O tipo de dados do resultado final mesclado. O tipo deve ter um construtor de cópia e um construtor padrão.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[combinable](#ctor)|Sobrecarregado. Constrói um novo objeto `combinable`.|
|[~ Destruidor combinable](#dtor)|Destrói um objeto `combinable`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[clear](#clear)|Limpa qualquer resultados intermediários de computação com um uso anterior.|
|[combine](#combine)|Calcula um valor final do conjunto de computações de subpropriedades de locais de thread chamando o functor combinar fornecido.|
|[combine_each](#combine_each)|Calcula um valor final do conjunto de computações de subpropriedades de locais de thread chamando o functor combinar fornecido, uma vez a cada cálculo de subpropriedades de thread local. O resultado final é acumulado pelo objeto de função.|
|[local](#local)|Sobrecarregado. Retorna uma referência para a computação de thread-private sub.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator=](#operator_eq)|Atribui a um `combinable` objeto de outro `combinable` objeto.|

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [paralela contêineres e objetos](../../../parallel/concrt/parallel-containers-and-objects.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`combinable`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** ppl.h

**Namespace:** simultaneidade

##  <a name="clear"></a> Limpar

Limpa qualquer resultados intermediários de computação com um uso anterior.

```
void clear();
```

##  <a name="ctor"></a> combinable

Constrói um novo objeto `combinable`.

```
combinable();

template <typename _Function>
explicit combinable(_Function _FnInitialize);

combinable(const combinable& _Copy);
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo de objeto de inicialização de functor.

*_FnInitialize*<br/>
Uma função que será chamada para inicializar cada novo valor de thread e privada do tipo `T`. Ele deve oferecer suporte a um operador de chamada de função com a assinatura `T ()`.

*Copiar*<br/>
Um existente `combinable` objeto a ser copiado para esse outro.

### <a name="remarks"></a>Comentários

O primeiro construtor inicializa novos elementos com o construtor padrão para o tipo `T`.

O segundo construtor inicializa novos elementos usando o functor de inicialização fornecido como o `_FnInitialize` parâmetro.

O terceiro construtor é o construtor de cópia.

##  <a name="dtor"></a> ~ combinable

Destrói um objeto `combinable`.

```
~combinable();
```

##  <a name="combine"></a> combinar

Calcula um valor final do conjunto de computações de subpropriedades de locais de thread chamando o functor combinar fornecido.

```
template<typename _Function>
T combine(_Function _FnCombine) const;
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para combinar dois cálculos de subpropriedades de thread local.

*_FnCombine*<br/>
O functor que é usado para combinar os cálculos de subpropriedades. Sua assinatura é `T (T, T)` ou `T (const T&, const T&)`, e ele deve ser associativa e comutativa.

### <a name="return-value"></a>Valor de retorno

O resultado final da combinação de todos os os cálculos do thread-private sub.

##  <a name="combine_each"></a> combine_each

Calcula um valor final do conjunto de computações de subpropriedades de locais de thread chamando o functor combinar fornecido, uma vez a cada cálculo de subpropriedades de thread local. O resultado final é acumulado pelo objeto de função.

```
template<typename _Function>
void combine_each(_Function _FnCombine) const;
```

### <a name="parameters"></a>Parâmetros

*_Function*<br/>
O tipo do objeto de função que será invocado para combinar uma computação de subpropriedades de locais de thread única.

*_FnCombine*<br/>
O functor que é usado para combinar um cálculo de subpropriedades. Sua assinatura é `void (T)` ou `void (const T&)`e deve ser associativa e comutativa.

##  <a name="local"></a> local

Retorna uma referência para a computação de thread-private sub.

```
T& local();

T& local(bool& _Exists);
```

### <a name="parameters"></a>Parâmetros

*_Exists*<br/>
Uma referência a um valor booliano. O valor booliano referenciado por esse argumento será definido como **verdadeira** se o cálculo de subpropriedades já existiam nesse thread e definido como **falso** se esse foi o primeiro cálculo de subpropriedades nesse thread.

### <a name="return-value"></a>Valor de retorno

Uma referência para a computação de thread-private sub.

##  <a name="operator_eq"></a> operador =

Atribui a um `combinable` objeto de outro `combinable` objeto.

```
combinable& operator= (const combinable& _Copy);
```

### <a name="parameters"></a>Parâmetros

*Copiar*<br/>
Um existente `combinable` objeto a ser copiado para esse outro.

### <a name="return-value"></a>Valor de retorno

Uma referência a este `combinable` objeto.

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
