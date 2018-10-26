---
title: Classe CTypedPtrArray | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CTypedPtrArray
- AFXTEMPL/CTypedPtrArray
- AFXTEMPL/CTypedPtrArray::Add
- AFXTEMPL/CTypedPtrArray::Append
- AFXTEMPL/CTypedPtrArray::Copy
- AFXTEMPL/CTypedPtrArray::ElementAt
- AFXTEMPL/CTypedPtrArray::GetAt
- AFXTEMPL/CTypedPtrArray::InsertAt
- AFXTEMPL/CTypedPtrArray::SetAt
- AFXTEMPL/CTypedPtrArray::SetAtGrow
dev_langs:
- C++
helpviewer_keywords:
- CTypedPtrArray [MFC], Add
- CTypedPtrArray [MFC], Append
- CTypedPtrArray [MFC], Copy
- CTypedPtrArray [MFC], ElementAt
- CTypedPtrArray [MFC], GetAt
- CTypedPtrArray [MFC], InsertAt
- CTypedPtrArray [MFC], SetAt
- CTypedPtrArray [MFC], SetAtGrow
ms.assetid: e3ecdf1a-a889-4156-92dd-ddbd36ccd919
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8f8cb8da3eaae08eeb694deaad6c3f4f6a71e7dc
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50054976"
---
# <a name="ctypedptrarray-class"></a>Classe CTypedPtrArray

Fornece um "wrapper" de tipo seguro para objetos da classe `CPtrArray` ou `CObArray`.

## <a name="syntax"></a>Sintaxe

```
template<class BASE_CLASS, class TYPE>
class CTypedPtrArray : public BASE_CLASS
```

#### <a name="parameters"></a>Parâmetros

*BASE_CLASS*<br/>
Classe base da classe de matriz com tipo de ponteiro; deve ser uma classe de matriz ( `CObArray` ou `CPtrArray`).

*TIPO*<br/>
Tipo dos elementos armazenados na matriz de classe base.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CTypedPtrArray::Add](#add)|Adiciona um novo elemento ao final de uma matriz. Aumenta a matriz quando necessário|
|[CTypedPtrArray::Append](#append)|Adiciona o conteúdo de uma matriz ao final do outro. Aumenta a matriz quando necessário|
|[CTypedPtrArray::Copy](#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[CTypedPtrArray::ElementAt](#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|
|[CTypedPtrArray::GetAt](#getat)|Retorna o valor a um determinado índice.|
|[CTypedPtrArray::InsertAt](#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CTypedPtrArray::SetAt](#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[CTypedPtrArray::SetAtGrow](#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[[CTypedPtrArray::operator]](#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

Quando você usa `CTypedPtrArray` em vez de `CPtrArray` ou `CObArray`, o recurso de verificação de tipo C++ ajuda a eliminar erros causados por tipos de ponteiro incompatíveis.

Além disso, o `CTypedPtrArray` wrapper executa muito da conversão que seria necessária se você usou `CObArray` ou `CPtrArray`.

Porque todos os `CTypedPtrArray` funções são embutidos, uso deste modelo não afeta significativamente o tamanho ou velocidade do seu código.

Para obter mais informações sobre como usar `CTypedPtrArray`, consulte os artigos [coleções](../../mfc/collections.md) e [Classes com base no modelo](../../mfc/template-based-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`BASE_CLASS`

`CTypedPtrArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl.h

##  <a name="add"></a>  CTypedPtrArray::Add

Essa função membro chama `BASE_CLASS` **:: Add**.

```
INT_PTR Add(TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Especifica o tipo de elemento a ser adicionado à matriz de parâmetro de modelo.

*newElement*<br/>
O elemento a ser adicionado a essa matriz.

### <a name="return-value"></a>Valor de retorno

O índice do elemento adicionado.

### <a name="remarks"></a>Comentários

Para obter comentários mais detalhadas, consulte [CObArray::Add](../../mfc/reference/cobarray-class.md#add).

##  <a name="append"></a>  CTypedPtrArray::Append

Essa função membro chama `BASE_CLASS`:: Append * *.

```
INT_PTR Append(const CTypedPtrArray<BASE_CLASS, TYPE>& src);
```

### <a name="parameters"></a>Parâmetros

*BASE_CLASS*<br/>
Classe base da classe de matriz com tipo de ponteiro; deve ser uma classe de matriz ( [CObArray](../../mfc/reference/cobarray-class.md) ou [CPtrArray](../../mfc/reference/cptrarray-class.md)).

*TIPO*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*src*<br/>
Origem dos elementos a ser anexado a uma matriz.

### <a name="return-value"></a>Valor de retorno

O índice do primeiro elemento acrescentado.

### <a name="remarks"></a>Comentários

Para obter comentários mais detalhadas, consulte [CObArray::Append](../../mfc/reference/cobarray-class.md#append).

##  <a name="copy"></a>  CTypedPtrArray::Copy

Essa função membro chama `BASE_CLASS` **:: Copy**.

```
void Copy(const CTypedPtrArray<BASE_CLASS, TYPE>& src);
```

### <a name="parameters"></a>Parâmetros

*BASE_CLASS*<br/>
Classe base da classe de matriz com tipo de ponteiro; deve ser uma classe de matriz ( [CObArray](../../mfc/reference/cobarray-class.md) ou [CPtrArray](../../mfc/reference/cptrarray-class.md)).

*TIPO*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*src*<br/>
Origem dos elementos a serem copiados para uma matriz.

### <a name="remarks"></a>Comentários

Para obter comentários mais detalhadas, consulte [CObArray::Copy](../../mfc/reference/cobarray-class.md#copy).

##  <a name="elementat"></a>  CTypedPtrArray::ElementAt

Essa função embutida chama `BASE_CLASS` **:: ElementAt**.

```
TYPE& ElementAt(INT_PTR nIndex);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo que especifica o tipo de elementos armazenados nesta matriz.

*nIndex*<br/>
Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por `BASE_CLASS` **:: GetUpperBound**.

### <a name="return-value"></a>Valor de retorno

Uma referência temporária para o elemento no local especificado por *nIndex*. Esse elemento é do tipo especificado pelo parâmetro de modelo *tipo*.

### <a name="remarks"></a>Comentários

Para obter comentários mais detalhadas, consulte [CObArray::ElementAt](../../mfc/reference/cobarray-class.md#elementat).

##  <a name="getat"></a>  CTypedPtrArray::GetAt

Essa função embutida chama `BASE_CLASS` **:: GetAt**.

```
TYPE GetAt(INT_PTR nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Especifica o tipo de elementos armazenados na matriz de parâmetro de modelo.

*nIndex*<br/>
Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por `BASE_CLASS` **:: GetUpperBound**.

### <a name="return-value"></a>Valor de retorno

Uma cópia do elemento no local especificado por *nIndex*. Esse elemento é do tipo especificado pelo parâmetro de modelo *tipo*.

### <a name="remarks"></a>Comentários

Para obter comentários mais detalhadas, consulte [CObArray::GetAt](../../mfc/reference/cobarray-class.md#getat)

##  <a name="insertat"></a>  CTypedPtrArray::InsertAt

Essa função membro chama `BASE_CLASS` **:: InsertAt**.

```
void InsertAt(
    INT_PTR nIndex,
    TYPE newElement,
    INT_PTR nCount = 1);

void InsertAt(
    INT_PTR nStartIndex,
    CTypedPtrArray<BASE_CLASS, TYPE>* pNewArray);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice de inteiro que pode ser maior que o valor retornado por [CObArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound).

*TIPO*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*newElement*<br/>
O ponteiro de objeto a ser colocado nesta matriz. Um *newElement* do valor de **nulo** é permitido.

*nCount*<br/>
O número de vezes que esse elemento deve ser inserido (o padrão é 1).

*nStartIndex*<br/>
Um índice de inteiro que pode ser maior que o valor retornado por `CObArray::GetUpperBound`.

*BASE_CLASS*<br/>
Classe base da classe de matriz com tipo de ponteiro; deve ser uma classe de matriz ( [CObArray](../../mfc/reference/cobarray-class.md) ou [CPtrArray](../../mfc/reference/cptrarray-class.md)).

*pNewArray*<br/>
Outra matriz que contém elementos a serem adicionados a essa matriz.

### <a name="remarks"></a>Comentários

Para obter comentários mais detalhadas, consulte [CObArray::InsertAt](../../mfc/reference/cobarray-class.md#insertat).

##  <a name="operator_at"></a>  [CTypedPtrArray::operator]

Chamar esses operadores embutidos `BASE_CLASS` **:: [] de operador**.

```
TYPE& operator[ ](int_ptr nindex);
TYPE operator[ ](int_ptr nindex) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Especifica o tipo de elementos armazenados na matriz de parâmetro de modelo.

*nIndex*<br/>
Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por `BASE_CLASS` **:: GetUpperBound**.

### <a name="remarks"></a>Comentários

O primeiro operador, chamado para matrizes que não sejam **const**, pode ser usado na direita (r-Value) ou à esquerda (l-value) de uma instrução de atribuição. A segunda chamada para **const** matrizes, pode ser usado apenas no lado direito.

A versão de depuração da biblioteca declara se o subscrito (tanto no lado esquerdo ou direito de uma instrução de atribuição) está fora dos limites.

##  <a name="setat"></a>  CTypedPtrArray::SetAt

Essa função membro chama `BASE_CLASS` **:: SetAt**.

```
void SetAt(
    INT_PTR nIndex,
    TYPE ptr);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice de inteiro que é maior que ou igual a 0 e menor ou igual ao valor retornado por [CObArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound).

*TIPO*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*ptr*<br/>
Um ponteiro para o elemento a ser inserido na matriz no nIndex. Um valor NULL é permitido.

### <a name="remarks"></a>Comentários

Para obter comentários mais detalhadas, consulte [CObArray::SetAt](../../mfc/reference/cobarray-class.md#setat).

##  <a name="setatgrow"></a>  CTypedPtrArray::SetAtGrow

Essa função membro chama `BASE_CLASS` **:: SetAtGrow**.

```
void SetAtGrow(
    INT_PTR nIndex,
    TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice de inteiro que é maior que ou igual a 0.

*TIPO*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*newElement*<br/>
O ponteiro de objeto a ser adicionado a essa matriz. Um **nulo** valor é permitido.

### <a name="remarks"></a>Comentários

Para obter comentários mais detalhadas, consulte [CObArray::SetAtGrow](../../mfc/reference/cobarray-class.md#setatgrow).

## <a name="see-also"></a>Consulte também

[Exemplo MFC COLETAR](../../visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CPtrArray](../../mfc/reference/cptrarray-class.md)<br/>
[Classe CObArray](../../mfc/reference/cobarray-class.md)
