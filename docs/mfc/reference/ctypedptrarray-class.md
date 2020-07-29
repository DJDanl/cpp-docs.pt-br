---
title: Classe CTypedPtrArray
ms.date: 11/04/2016
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
ms.openlocfilehash: db24e3992e5db70895ccc2908dba108de843bcdc
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215940"
---
# <a name="ctypedptrarray-class"></a>Classe CTypedPtrArray

Fornece um "wrapper" de tipo seguro para objetos da classe `CPtrArray` ou `CObArray` .

## <a name="syntax"></a>Sintaxe

```
template<class BASE_CLASS, class TYPE>
class CTypedPtrArray : public BASE_CLASS
```

#### <a name="parameters"></a>parâmetros

*BASE_CLASS*<br/>
Classe base da classe de matriz de ponteiro tipado; deve ser uma classe de matriz ( `CObArray` ou `CPtrArray` ).

*TYPE*<br/>
Tipo dos elementos armazenados na matriz de classe base.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTypedPtrArray:: Adicionar](#add)|Adiciona um novo elemento ao final de uma matriz. Aumenta a matriz, se necessário|
|[CTypedPtrArray:: Append](#append)|Adiciona o conteúdo de uma matriz ao final de outra. Aumenta a matriz, se necessário|
|[CTypedPtrArray:: copiar](#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[CTypedPtrArray::ElementAt](#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|
|[CTypedPtrArray::GetAt](#getat)|Retorna o valor a um determinado índice.|
|[CTypedPtrArray::InsertAt](#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CTypedPtrArray::SetAt](#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[CTypedPtrArray::SetAtGrow](#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador \[ CTypedPtrArray::\]](#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

Quando você usa `CTypedPtrArray` em vez de `CPtrArray` ou `CObArray` , o recurso de verificação de tipo C++ ajuda a eliminar erros causados por tipos de ponteiros incompatíveis.

Além disso, o `CTypedPtrArray` wrapper executa grande parte da conversão que seria necessária se você usava `CObArray` ou `CPtrArray` .

Como todas as `CTypedPtrArray` funções são embutidas, o uso desse modelo não afeta significativamente o tamanho ou a velocidade do seu código.

Para obter mais informações sobre como usar `CTypedPtrArray` o, consulte as [coleções](../../mfc/collections.md) de artigos e [classes baseadas em modelo](../../mfc/template-based-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`BASE_CLASS`

`CTypedPtrArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl. h

## <a name="ctypedptrarrayadd"></a><a name="add"></a>CTypedPtrArray:: Adicionar

Essa função de membro chama `BASE_CLASS` **:: Add**.

```
INT_PTR Add(TYPE newElement);
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo de elemento a ser adicionado à matriz.

*newElement*<br/>
O elemento a ser adicionado a esta matriz.

### <a name="return-value"></a>Valor retornado

O índice do elemento adicionado.

### <a name="remarks"></a>Comentários

Para ver comentários mais detalhados, consulte [CObArray:: Add](../../mfc/reference/cobarray-class.md#add).

## <a name="ctypedptrarrayappend"></a><a name="append"></a>CTypedPtrArray:: Append

Essa função de membro chama `BASE_CLASS` :: Append * *.

```
INT_PTR Append(const CTypedPtrArray<BASE_CLASS, TYPE>& src);
```

### <a name="parameters"></a>parâmetros

*BASE_CLASS*<br/>
Classe base da classe de matriz de ponteiro tipado; deve ser uma classe de matriz ( [CObArray](../../mfc/reference/cobarray-class.md) ou [CPtrArray](../../mfc/reference/cptrarray-class.md)).

*TYPE*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*src*<br/>
Origem dos elementos a serem acrescentados a uma matriz.

### <a name="return-value"></a>Valor retornado

O índice do primeiro elemento acrescentado.

### <a name="remarks"></a>Comentários

Para comentários mais detalhados, consulte [CObArray:: Append](../../mfc/reference/cobarray-class.md#append).

## <a name="ctypedptrarraycopy"></a><a name="copy"></a>CTypedPtrArray:: copiar

Essa função de membro chama `BASE_CLASS` **:: Copy**.

```cpp
void Copy(const CTypedPtrArray<BASE_CLASS, TYPE>& src);
```

### <a name="parameters"></a>parâmetros

*BASE_CLASS*<br/>
Classe base da classe de matriz de ponteiro tipado; deve ser uma classe de matriz ( [CObArray](../../mfc/reference/cobarray-class.md) ou [CPtrArray](../../mfc/reference/cptrarray-class.md)).

*TYPE*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*src*<br/>
Origem dos elementos a serem copiados para uma matriz.

### <a name="remarks"></a>Comentários

Para ver comentários mais detalhados, consulte [CObArray:: Copy](../../mfc/reference/cobarray-class.md#copy).

## <a name="ctypedptrarrayelementat"></a><a name="elementat"></a>CTypedPtrArray::ElementAt

Essa função embutida chama `BASE_CLASS` **:: ElementAt**.

```
TYPE& ElementAt(INT_PTR nIndex);
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo de elementos armazenados nessa matriz.

*nIndex*<br/>
Um índice inteiro que é maior ou igual a 0 e menor ou igual ao valor retornado por `BASE_CLASS` **:: GetUpperBound**.

### <a name="return-value"></a>Valor retornado

Uma referência temporária para o elemento no local especificado por *nIndex*. Esse elemento é do tipo especificado pelo *tipo*de parâmetro de modelo.

### <a name="remarks"></a>Comentários

Para ver comentários mais detalhados, consulte [CObArray:: ElementAt](../../mfc/reference/cobarray-class.md#elementat).

## <a name="ctypedptrarraygetat"></a><a name="getat"></a>CTypedPtrArray::GetAt

Essa função embutida chama `BASE_CLASS` **:: GetAt**.

```
TYPE GetAt(INT_PTR nIndex) const;
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo de elementos armazenados na matriz.

*nIndex*<br/>
Um índice inteiro que é maior ou igual a 0 e menor ou igual ao valor retornado por `BASE_CLASS` **:: GetUpperBound**.

### <a name="return-value"></a>Valor retornado

Uma cópia do elemento no local especificado por *nIndex*. Esse elemento é do tipo especificado pelo *tipo*de parâmetro de modelo.

### <a name="remarks"></a>Comentários

Para ver comentários mais detalhados, consulte [CObArray:: GetAt](../../mfc/reference/cobarray-class.md#getat)

## <a name="ctypedptrarrayinsertat"></a><a name="insertat"></a>CTypedPtrArray::InsertAt

Essa função de membro chama `BASE_CLASS` **:: InsertAt**.

```cpp
void InsertAt(
    INT_PTR nIndex,
    TYPE newElement,
    INT_PTR nCount = 1);

void InsertAt(
    INT_PTR nStartIndex,
    CTypedPtrArray<BASE_CLASS, TYPE>* pNewArray);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Um índice de inteiro que pode ser maior que o valor retornado por [CObArray:: GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound).

*TYPE*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*newElement*<br/>
O ponteiro de objeto a ser colocado nesta matriz. Um *newElement* de valor **NULL** é permitido.

*nCount*<br/>
O número de vezes que esse elemento deve ser inserido (o padrão é 1).

*nStartIndex*<br/>
Um índice de inteiro que pode ser maior que o valor retornado por `CObArray::GetUpperBound` .

*BASE_CLASS*<br/>
Classe base da classe de matriz de ponteiro tipado; deve ser uma classe de matriz ( [CObArray](../../mfc/reference/cobarray-class.md) ou [CPtrArray](../../mfc/reference/cptrarray-class.md)).

*pNewArray*<br/>
Outra matriz que contém elementos a serem adicionados a esta matriz.

### <a name="remarks"></a>Comentários

Para ver comentários mais detalhados, consulte [CObArray:: InsertAt](../../mfc/reference/cobarray-class.md#insertat).

## <a name="ctypedptrarrayoperator--"></a><a name="operator_at"></a>CTypedPtrArray:: operator []

Estes operadores embutidos chamam `BASE_CLASS` **:: operator []**.

```
TYPE& operator[ ](int_ptr nindex);
TYPE operator[ ](int_ptr nindex) const;
```

### <a name="parameters"></a>parâmetros

*TYPE*<br/>
Parâmetro de modelo que especifica o tipo de elementos armazenados na matriz.

*nIndex*<br/>
Um índice inteiro que é maior ou igual a 0 e menor ou igual ao valor retornado por `BASE_CLASS` **:: GetUpperBound**.

### <a name="remarks"></a>Comentários

O primeiro operador, chamado para matrizes que não são **`const`** , pode ser usado na direita (r-value) ou na esquerda (l-Value) de uma instrução de atribuição. O segundo, invocado para **`const`** matrizes, pode ser usado somente à direita.

A versão de depuração da biblioteca é declarada se o subscrito (no lado esquerdo ou direito de uma instrução de atribuição) está fora dos limites.

## <a name="ctypedptrarraysetat"></a><a name="setat"></a>CTypedPtrArray::SetAt

Essa função de membro chama `BASE_CLASS` **:: SetAt**.

```cpp
void SetAt(
    INT_PTR nIndex,
    TYPE ptr);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Um índice inteiro que é maior ou igual a 0 e menor ou igual ao valor retornado por [CObArray:: GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound).

*TYPE*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*ptr*<br/>
Um ponteiro para o elemento a ser inserido na matriz no nIndex. Um valor nulo é permitido.

### <a name="remarks"></a>Comentários

Para ver comentários mais detalhados, consulte [CObArray:: SetAt](../../mfc/reference/cobarray-class.md#setat).

## <a name="ctypedptrarraysetatgrow"></a><a name="setatgrow"></a>CTypedPtrArray::SetAtGrow

Essa função de membro chama `BASE_CLASS` **:: SetAtGrow**.

```cpp
void SetAtGrow(
    INT_PTR nIndex,
    TYPE newElement);
```

### <a name="parameters"></a>parâmetros

*nIndex*<br/>
Um índice de inteiro maior ou igual a 0.

*TYPE*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*newElement*<br/>
O ponteiro de objeto a ser adicionado a esta matriz. Um valor **nulo** é permitido.

### <a name="remarks"></a>Comentários

Para ver comentários mais detalhados, consulte [CObArray:: SetAtGrow](../../mfc/reference/cobarray-class.md#setatgrow).

## <a name="see-also"></a>Confira também

[COLETA de amostra do MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CPtrArray](../../mfc/reference/cptrarray-class.md)<br/>
[Classe CObArray](../../mfc/reference/cobarray-class.md)
