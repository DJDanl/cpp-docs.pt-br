---
title: Classe CComSafeArrayBound
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
ms.openlocfilehash: 9adee1e8b6a46c239aaf6a3c404277b34efd00e2
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88834746"
---
# <a name="ccomsafearraybound-class"></a>Classe CComSafeArrayBound

Essa classe é um wrapper para uma estrutura [SAFEARRAYBOUND](/windows/win32/api/oaidl/ns-oaidl-safearraybound) .

## <a name="syntax"></a>Sintaxe

```
class CComSafeArrayBound : public SAFEARRAYBOUND
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|Função|Descrição|
|-|-|
|[CComSafeArrayBound](#ccomsafearraybound)|O construtor.|
|[GetCount](#getcount)|Chame esse método para retornar o número de elementos.|
|[GetLowerBound](#getlowerbound)|Chame esse método para retornar o limite inferior.|
|[GetUpperBound](#getupperbound)|Chame esse método para retornar o limite superior.|
|[Total](#setcount)|Chame esse método para definir o número de elementos.|
|[SetLowerBound](#setlowerbound)|Chame esse método para definir o limite inferior.|

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operador =](#operator_eq)|Define o `CComSafeArrayBound` para um novo valor.|

## <a name="remarks"></a>Comentários

Essa classe é um wrapper para a `SAFEARRAYBOUND` estrutura usada pelo [CComSafeArray](../../atl/reference/ccomsafearray-class.md). Ele fornece métodos para consultar e definir os limites superior e inferior de uma única dimensão de um `CComSafeArray` objeto e o número de elementos que ele contém. Um objeto multidimensional `CComSafeArray` usa uma matriz de `CComSafeArrayBound` objetos, um para cada dimensão. Portanto, ao usar métodos como [GetCount](#getcount), lembre-se de que esse método não retornará o número total de elementos em uma matriz multidimensional.

**Cabeçalho:** atlsafe. h

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsafe. h

## <a name="ccomsafearrayboundccomsafearraybound"></a><a name="ccomsafearraybound"></a> CComSafeArrayBound::CComSafeArrayBound

O construtor.

```
CComSafeArrayBound(ULONG ulCount = 0, LONG lLowerBound = 0) throw();
```

### <a name="parameters"></a>Parâmetros

*ulCount*<br/>
O número de elementos na matriz.

*lLowerBound*<br/>
O limite inferior do qual a matriz é numerada.

### <a name="remarks"></a>Comentários

Se a matriz for ser acessada em um programa C++, é recomendável que o limite inferior seja definido como 0. Pode ser preferível usar um valor de limite inferior diferente se a matriz for usada com outras linguagens, como Visual Basic.

## <a name="ccomsafearrayboundgetcount"></a><a name="getcount"></a> CComSafeArrayBound:: GetCount

Chame esse método para retornar o número de elementos.

```
ULONG GetCount() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o número de elementos.

### <a name="remarks"></a>Comentários

Se o `CComSafeArray` objeto associado representar uma matriz multidimensional, esse método retornará apenas o número total de elementos na dimensão mais à direita. Use [CComSafeArray:: GetCount](../../atl/reference/ccomsafearray-class.md#getcount) para obter o número total de elementos.

## <a name="ccomsafearrayboundgetlowerbound"></a><a name="getlowerbound"></a> CComSafeArrayBound::GetLowerBound

Chame esse método para retornar o limite inferior.

```
LONG GetLowerBound() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o limite inferior do `CComSafeArrayBound` objeto.

## <a name="ccomsafearrayboundgetupperbound"></a><a name="getupperbound"></a> CComSafeArrayBound::GetUpperBound

Chame esse método para retornar o limite superior.

```
LONG GetUpperBound() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retorna o limite superior do `CComSafeArrayBound` objeto.

### <a name="remarks"></a>Comentários

O limite superior depende do número de elementos e do valor limite inferior. Por exemplo, se o limite inferior for 0 e o número de elementos for 10, o limite superior será definido automaticamente como 9.

## <a name="ccomsafearrayboundoperator-"></a><a name="operator_eq"></a> CComSafeArrayBound:: Operator =

Define o `CComSafeArrayBound` para um novo valor.

```
CComSafeArrayBound& operator= (const CComSafeArrayBound& bound) throw();
CComSafeArrayBound& operator= (ULONG ulCount) throw();
```

### <a name="parameters"></a>Parâmetros

*limita*<br/>
Um objeto `CComSafeArrayBound`.

*ulCount*<br/>
O número de elementos.

### <a name="return-value"></a>Valor Retornado

Retorna um ponteiro para o `CComSafeArrayBound` objeto.

### <a name="remarks"></a>Comentários

O `CComSafeArrayBound` objeto pode ser atribuído usando um existente `CComSafeArrayBound` ou fornecendo o número de elementos; nesse caso, o limite inferior é definido como 0 por padrão.

## <a name="ccomsafearrayboundsetcount"></a><a name="setcount"></a> CComSafeArrayBound:: SetCount

Chame esse método para definir o número de elementos.

```
ULONG SetCount(ULONG ulCount) throw();
```

### <a name="parameters"></a>Parâmetros

*ulCount*<br/>
O número de elementos.

### <a name="return-value"></a>Valor Retornado

Retorna o número de elementos no `CComSafeArrayBound` objeto.

## <a name="ccomsafearrayboundsetlowerbound"></a><a name="setlowerbound"></a> CComSafeArrayBound::SetLowerBound

Chame esse método para definir o limite inferior.

```
LONG SetLowerBound(LONG lLowerBound) throw();
```

### <a name="parameters"></a>Parâmetros

*lLowerBound*<br/>
O limite inferior.

### <a name="return-value"></a>Valor Retornado

Retorna o novo limite inferior do `CComSafeArrayBound` objeto.

### <a name="remarks"></a>Comentários

Se a matriz for acessada de um programa Visual C++, é recomendável que o limite inferior seja definido como 0. Pode ser preferível usar um valor de limite inferior diferente se a matriz for usada com outras linguagens, como Visual Basic.

O limite superior depende do número de elementos e do valor limite inferior. Por exemplo, se o limite inferior for 0 e o número de elementos for 10, o limite superior será definido automaticamente como 9.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
