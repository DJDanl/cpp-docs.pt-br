---
title: Classe cancellation_token_registration
ms.date: 11/04/2016
f1_keywords:
- cancellation_token_registration
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_registration
- PPLCANCELLATION_TOKEN/concurrency::cancellation_token_registration::cancellation_token_registration
helpviewer_keywords:
- cancellation_token_registration class
ms.assetid: 823d63f4-7233-4d65-8976-6152ccf12d0e
ms.openlocfilehash: ca664d78f80a0c335a8669454b1345955aaefcb2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50644659"
---
# <a name="cancellationtokenregistration-class"></a>Classe cancellation_token_registration

O `cancellation_token_registration` classe representa uma notificação de retorno de chamada de um `cancellation_token`. Quando o `register` método em um `cancellation_token` é usado para receber notificações de quando o cancelamento ocorre, um `cancellation_token_registration` objeto é retornado como um identificador para o retorno de chamada para que o chamador possa solicitar um retorno de chamada específico não precisa mais ser feitas por meio do uso da `deregister` método.

## <a name="syntax"></a>Sintaxe

```
class cancellation_token_registration;
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[cancellation_token_registration](#ctor)||
|[~ cancellation_token_registration destruidor](#dtor)||

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[operator!=](#operator_neq)||
|[operator=](#operator_eq)||
|[operator==](#operator_eq_eq)||

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`cancellation_token_registration`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** pplcancellation_token. h

**Namespace:** simultaneidade

##  <a name="dtor"></a> ~ cancellation_token_registration

```
~cancellation_token_registration();
```

##  <a name="ctor"></a> cancellation_token_registration

```
cancellation_token_registration();

cancellation_token_registration(const cancellation_token_registration& _Src);

cancellation_token_registration(cancellation_token_registration&& _Src);
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
O `cancellation_token_registration` para copiar ou mover.

##  <a name="operator_neq"></a> operador! =

```
bool operator!= (const cancellation_token_registration& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O `cancellation_token_registration` de comparação.

### <a name="return-value"></a>Valor de retorno

##  <a name="operator_eq"></a> operador =

```
cancellation_token_registration& operator= (const cancellation_token_registration& _Src);

cancellation_token_registration& operator= (cancellation_token_registration&& _Src);
```

### <a name="parameters"></a>Parâmetros

*_Src*<br/>
O `cancellation_token_registration` atribuir.

### <a name="return-value"></a>Valor de retorno

##  <a name="operator_eq_eq"></a> operador = =

```
bool operator== (const cancellation_token_registration& _Rhs) const;
```

### <a name="parameters"></a>Parâmetros

*_Rhs*<br/>
O `cancellation_token_registration` de comparação.

### <a name="return-value"></a>Valor de retorno

## <a name="see-also"></a>Consulte também

[Namespace de simultaneidade](concurrency-namespace.md)
