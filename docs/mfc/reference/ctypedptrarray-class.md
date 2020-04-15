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
ms.openlocfilehash: a996bca471ce82a7c2adaaad67670ddef417eda1
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373275"
---
# <a name="ctypedptrarray-class"></a>Classe CTypedPtrArray

Fornece um "invólucro" seguro `CPtrArray` para `CObArray`objetos de classe ou .

## <a name="syntax"></a>Sintaxe

```
template<class BASE_CLASS, class TYPE>
class CTypedPtrArray : public BASE_CLASS
```

#### <a name="parameters"></a>Parâmetros

*Base_class*<br/>
Classe base da classe de matriz de ponteiro digitada; deve ser uma `CObArray` classe `CPtrArray`de matriz (ou ).

*TIPO*<br/>
Tipo dos elementos armazenados na matriz de classe base.

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CTypedPtrArray::Adicionar](#add)|Adiciona um novo elemento ao fim de uma matriz. Cresce a matriz, se necessário|
|[CTypedPtrArray::Apêndice](#append)|Adiciona o conteúdo de uma matriz ao final de outra. Cresce a matriz, se necessário|
|[CTypedPtrArray::Copiar](#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[CTypedPtrArray::ElementAt](#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|
|[CTypedPtrArray::GetAt](#getat)|Retorna o valor a um determinado índice.|
|[CTypedPtrArray::InsertAt](#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CTypedPtrArray::SetAt](#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[CTypedPtrArray::SetAtGrow](#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[CTypedPtrArray::operador \[\]](#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

Quando você `CTypedPtrArray` usa `CPtrArray` `CObArray`em vez de ou , o recurso de verificação de tipo C++ ajuda a eliminar erros causados por tipos de ponteiros incompatíveis.

Além disso, `CTypedPtrArray` o invólucro executa grande parte `CObArray` `CPtrArray`do casting que seria necessário se você usou ou .

Como `CTypedPtrArray` todas as funções são inline, o uso deste modelo não afeta significativamente o tamanho ou a velocidade do seu código.

Para obter mais `CTypedPtrArray`informações sobre o uso, consulte os artigos Coleções e Classes [Baseadas](../../mfc/collections.md) [em Modelos](../../mfc/template-based-classes.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`BASE_CLASS`

`CTypedPtrArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxtempl.h

## <a name="ctypedptrarrayadd"></a><a name="add"></a>CTypedPtrArray::Adicionar

Esta função `BASE_CLASS`de membro chama **::Adicionar**.

```
INT_PTR Add(TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elemento a ser adicionado à matriz.

*Newelement*<br/>
O elemento a ser adicionado a esta matriz.

### <a name="return-value"></a>Valor retornado

O índice do elemento adicionado.

### <a name="remarks"></a>Comentários

Para obter observações mais detalhadas, consulte [CObArray::Add](../../mfc/reference/cobarray-class.md#add).

## <a name="ctypedptrarrayappend"></a><a name="append"></a>CTypedPtrArray::Apêndice

Esta função `BASE_CLASS`de membro chama ::Apêndice**.

```
INT_PTR Append(const CTypedPtrArray<BASE_CLASS, TYPE>& src);
```

### <a name="parameters"></a>Parâmetros

*Base_class*<br/>
Classe base da classe de matriz de ponteiro digitada; deve ser uma classe de matriz [(CObArray](../../mfc/reference/cobarray-class.md) ou [CPtrArray).](../../mfc/reference/cptrarray-class.md)

*TIPO*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*src*<br/>
Fonte dos elementos a serem anexados a uma matriz.

### <a name="return-value"></a>Valor retornado

O índice do primeiro elemento anexado.

### <a name="remarks"></a>Comentários

Para obter observações mais detalhadas, consulte [CObArray::Apêndice](../../mfc/reference/cobarray-class.md#append).

## <a name="ctypedptrarraycopy"></a><a name="copy"></a>CTypedPtrArray::Copiar

Esta função `BASE_CLASS`de membro chama **::Copiar**.

```
void Copy(const CTypedPtrArray<BASE_CLASS, TYPE>& src);
```

### <a name="parameters"></a>Parâmetros

*Base_class*<br/>
Classe base da classe de matriz de ponteiro digitada; deve ser uma classe de matriz [(CObArray](../../mfc/reference/cobarray-class.md) ou [CPtrArray).](../../mfc/reference/cptrarray-class.md)

*TIPO*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*src*<br/>
Fonte dos elementos a serem copiados para uma matriz.

### <a name="remarks"></a>Comentários

Para obter observações mais detalhadas, consulte [CObArray::Copy](../../mfc/reference/cobarray-class.md#copy).

## <a name="ctypedptrarrayelementat"></a><a name="elementat"></a>CTypedPtrArray::ElementAt

Esta função inline `BASE_CLASS` **chama::ElementAt**.

```
TYPE& ElementAt(INT_PTR nIndex);
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos armazenados nesta matriz.

*nIndex*<br/>
Um índice inteiro maior ou igual a 0 e menor ou igual `BASE_CLASS`ao valor devolvido por **::GetUpperBound**.

### <a name="return-value"></a>Valor retornado

Uma referência temporária ao elemento no local especificado pelo *nIndex*. Este elemento é do tipo especificado pelo parâmetro modelo *TYPE*.

### <a name="remarks"></a>Comentários

Para obter observações mais detalhadas, consulte [CObArray::ElementAt](../../mfc/reference/cobarray-class.md#elementat).

## <a name="ctypedptrarraygetat"></a><a name="getat"></a>CTypedPtrArray::GetAt

Esta função inline `BASE_CLASS` **chama::GetAt**.

```
TYPE GetAt(INT_PTR nIndex) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos armazenados na matriz.

*nIndex*<br/>
Um índice inteiro maior ou igual a 0 e menor ou igual `BASE_CLASS`ao valor devolvido por **::GetUpperBound**.

### <a name="return-value"></a>Valor retornado

Uma cópia do elemento no local especificado pelo *nIndex*. Este elemento é do tipo especificado pelo parâmetro modelo *TYPE*.

### <a name="remarks"></a>Comentários

Para obter observações mais detalhadas, consulte [CObArray::GetAt](../../mfc/reference/cobarray-class.md#getat)

## <a name="ctypedptrarrayinsertat"></a><a name="insertat"></a>CTypedPtrArray::InsertAt

Esta função `BASE_CLASS`de membro **chama::InsertAt**.

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
Um índice inteiro que pode ser maior do que o valor retornado por [CObArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound).

*TIPO*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*Newelement*<br/>
O ponteiro do objeto a ser colocado nesta matriz. Um *novoElemento* de valor **NULL** é permitido.

*Ncount*<br/>
O número de vezes que este elemento deve ser inserido (padrão para 1).

*Nstartindex*<br/>
Um índice inteiro que pode ser maior do `CObArray::GetUpperBound`que o valor devolvido por .

*Base_class*<br/>
Classe base da classe de matriz de ponteiro digitada; deve ser uma classe de matriz [(CObArray](../../mfc/reference/cobarray-class.md) ou [CPtrArray).](../../mfc/reference/cptrarray-class.md)

*pNewArray*<br/>
Outra matriz que contém elementos a serem adicionados a esta matriz.

### <a name="remarks"></a>Comentários

Para obter observações mais detalhadas, consulte [CObArray::InsertAt](../../mfc/reference/cobarray-class.md#insertat).

## <a name="ctypedptrarrayoperator--"></a><a name="operator_at"></a>CTypedPtrArray::operador [ ]

Estes operadores `BASE_CLASS`inline chamam **::operador [ ]**

```
TYPE& operator[ ](int_ptr nindex);
TYPE operator[ ](int_ptr nindex) const;
```

### <a name="parameters"></a>Parâmetros

*TIPO*<br/>
Parâmetro de modelo especificando o tipo de elementos armazenados na matriz.

*nIndex*<br/>
Um índice inteiro maior ou igual a 0 e menor ou igual `BASE_CLASS`ao valor devolvido por **::GetUpperBound**.

### <a name="remarks"></a>Comentários

O primeiro operador, chamado para matrizes que não são **const,** pode ser usado tanto à direita (r-valor) quanto à esquerda (l-valor) de uma declaração de atribuição. O segundo, invocado para **matrizes const,** só pode ser usado à direita.

A versão Debug da biblioteca afirma se o subscrito (no lado esquerdo ou direito de uma declaração de atribuição) estiver fora dos limites.

## <a name="ctypedptrarraysetat"></a><a name="setat"></a>CTypedPtrArray::SetAt

Esta função `BASE_CLASS`de membro chama **::SetAt**.

```
void SetAt(
    INT_PTR nIndex,
    TYPE ptr);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice inteiro maior ou igual a 0 e menor ou igual ao valor devolvido por [CObArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound).

*TIPO*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*Ptr*<br/>
Um ponteiro para o elemento a ser inserido na matriz no nIndex. Um valor NULA é permitido.

### <a name="remarks"></a>Comentários

Para obter observações mais detalhadas, consulte [CObArray::SetAt](../../mfc/reference/cobarray-class.md#setat).

## <a name="ctypedptrarraysetatgrow"></a><a name="setatgrow"></a>CTypedPtrArray::SetAtGrow

Esta função `BASE_CLASS`de membro **chama::SetAtGrow**.

```
void SetAtGrow(
    INT_PTR nIndex,
    TYPE newElement);
```

### <a name="parameters"></a>Parâmetros

*nIndex*<br/>
Um índice inteiro maior ou igual a 0.

*TIPO*<br/>
Tipo dos elementos armazenados na matriz de classe base.

*Newelement*<br/>
O ponteiro do objeto a ser adicionado a esta matriz. Um valor **NULA** é permitido.

### <a name="remarks"></a>Comentários

Para obter observações mais detalhadas, consulte [CObArray::SetAtGrow](../../mfc/reference/cobarray-class.md#setatgrow).

## <a name="see-also"></a>Confira também

[Coleta de amostras de MFC](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe CPtrArray](../../mfc/reference/cptrarray-class.md)<br/>
[Classe CObArray](../../mfc/reference/cobarray-class.md)
