---
title: Classe CComSafeARRAYBound
ms.date: 05/06/2019
f1_keywords:
- CComSafeArrayBound
- ATLSAFE/ATL::CComSafeArrayBound
- ATLSAFE/ATL::GetCount
- ATLSAFE/ATL::GetLowerBound
- ATLSAFE/ATL::GetUpperBound
- ATLSAFE/ATL::SetCount
- ATLSAFE/ATL::SetLowerBound
helpviewer_keywords:
- CComSafeArrayBound class
ms.assetid: dd6299db-5f84-4630-bbf0-f5add5318437
ms.openlocfilehash: 2c2f8b787e5366ec893538a88049f6f53dc35caf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81327376"
---
# <a name="ccomsafearraybound-class"></a>Classe CComSafeARRAYBound

Esta classe é um invólucro para uma estrutura [SAFEARRAYBOUND.](/windows/win32/api/oaidl/ns-oaidl-safearraybound)

## <a name="syntax"></a>Sintaxe

```
class CComSafeArrayBound : public SAFEARRAYBOUND
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Ccomsafearraybound](#ccomsafearraybound)|O construtor.|
|[GetCount](#getcount)|Chame este método para retornar o número de elementos.|
|[Getlowerbound](#getlowerbound)|Chame este método para retornar o limite inferior.|
|[Getupperbound](#getupperbound)|Chame este método para retornar o limite superior.|
|[Setcount](#setcount)|Chame este método para definir o número de elementos.|
|[SetLowerBound](#setlowerbound)|Chame este método para definir o limite inferior.|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operador =](#operator_eq)|Define `CComSafeArrayBound` o valor para um novo valor.|

## <a name="remarks"></a>Comentários

Esta classe é um `SAFEARRAYBOUND` invólucro para a estrutura usada pelo [CComSafeArray](../../atl/reference/ccomsafearray-class.md). Ele fornece métodos para consultar e definir os limites superior e `CComSafeArray` inferior de uma única dimensão de um objeto e o número de elementos que ele contém. Um objeto `CComSafeArray` multidimensional usa `CComSafeArrayBound` uma matriz de objetos, um para cada dimensão. Portanto, ao usar métodos como [GetCount,](#getcount)esteja ciente de que este método não retornará o número total de elementos em uma matriz multidimensional.

**Cabeçalho:** atlsafe.h

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsafe.h

## <a name="ccomsafearrayboundccomsafearraybound"></a><a name="ccomsafearraybound"></a>CComSafeArrayBound::CComSafeArrayBound

O construtor.

```
CComSafeArrayBound(ULONG ulCount = 0, LONG lLowerBound = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*ulCount*<br/>
O número de elementos na matriz.

*lLowerBound*<br/>
O limite inferior a partir do qual a matriz está numerada.

### <a name="remarks"></a>Comentários

Se a matriz for acessada a partir de um programa C++, recomenda-se que o limite inferior seja definido como 0. Pode ser preferível usar um valor de limite inferior diferente se a matriz for usada com outros idiomas, como o Visual Basic.

## <a name="ccomsafearrayboundgetcount"></a><a name="getcount"></a>CComSafeArrayBound::contagem de pessoas

Chame este método para retornar o número de elementos.

```
ULONG GetCount() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o número de elementos.

### <a name="remarks"></a>Comentários

Se o `CComSafeArray` objeto associado representar uma matriz multidimensional, este método só retornará o número total de elementos na dimensão mais correta. Use [CComSafeArray::GetCount](../../atl/reference/ccomsafearray-class.md#getcount) para obter o número total de elementos.

## <a name="ccomsafearrayboundgetlowerbound"></a><a name="getlowerbound"></a>CcomSafeArrayBound::getLowerBound

Chame este método para retornar o limite inferior.

```
LONG GetLowerBound() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o limite `CComSafeArrayBound` inferior do objeto.

## <a name="ccomsafearrayboundgetupperbound"></a><a name="getupperbound"></a>CcomsafearrayBound::getupperbound

Chame este método para retornar o limite superior.

```
LONG GetUpperBound() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna o limite `CComSafeArrayBound` superior do objeto.

### <a name="remarks"></a>Comentários

O limite superior depende do número de elementos e do valor de limite inferior. Por exemplo, se o limite inferior for 0 e o número de elementos for 10, o limite superior será automaticamente definido como 9.

## <a name="ccomsafearrayboundoperator-"></a><a name="operator_eq"></a>CComSafeArrayBound::operador =

Define `CComSafeArrayBound` o valor para um novo valor.

```
CComSafeArrayBound& operator= (const CComSafeArrayBound& bound) throw();
CComSafeArrayBound& operator= (ULONG ulCount) throw();
```

### <a name="parameters"></a>Parâmetros

*Limite*<br/>
Um objeto `CComSafeArrayBound` .

*ulCount*<br/>
O número de elementos.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro `CComSafeArrayBound` para o objeto.

### <a name="remarks"></a>Comentários

O `CComSafeArrayBound` objeto pode ser atribuído `CComSafeArrayBound`usando um existente , ou fornecendo o número de elementos, nesse caso o limite inferior é definido como 0 por padrão.

## <a name="ccomsafearrayboundsetcount"></a><a name="setcount"></a>CComSafeArrayBound::setCount

Chame este método para definir o número de elementos.

```
ULONG SetCount(ULONG ulCount) throw();
```

### <a name="parameters"></a>Parâmetros

*ulCount*<br/>
O número de elementos.

### <a name="return-value"></a>Valor retornado

Retorna o número de `CComSafeArrayBound` elementos no objeto.

## <a name="ccomsafearrayboundsetlowerbound"></a><a name="setlowerbound"></a>CComSafeArrayBound::SetLowerBound

Chame este método para definir o limite inferior.

```
LONG SetLowerBound(LONG lLowerBound) throw();
```

### <a name="parameters"></a>Parâmetros

*lLowerBound*<br/>
O limite inferior.

### <a name="return-value"></a>Valor retornado

Retorna o novo limite `CComSafeArrayBound` inferior do objeto.

### <a name="remarks"></a>Comentários

Se a matriz for acessada a partir de um programa Visual C++, recomenda-se que o limite inferior seja definido como 0. Pode ser preferível usar um valor de limite inferior diferente se a matriz for usada com outros idiomas, como o Visual Basic.

O limite superior depende do número de elementos e do valor de limite inferior. Por exemplo, se o limite inferior for 0 e o número de elementos for 10, o limite superior será automaticamente definido como 9.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
