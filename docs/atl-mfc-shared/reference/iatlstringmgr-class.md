---
title: Classe IAtlStringMgr
ms.date: 10/18/2018
f1_keywords:
- IAtlStringMgr
- ATLSIMPSTR/ATL::IAtlStringMgr
- ATLSIMPSTR/ATL::Allocate
- ATLSIMPSTR/ATL::Clone
- ATLSIMPSTR/ATL::Free
- ATLSIMPSTR/ATL::GetNilString
- ATLSIMPSTR/ATL::Reallocate
helpviewer_keywords:
- shared classes, IAtlStringMgr
- memory, managing
- IAtlStringMgr class
ms.assetid: 722f0346-a770-4aa7-8f94-177be8dba823
ms.openlocfilehash: 978d33c719b9cb8c2708dc97fa78874534dfd748
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57749952"
---
# <a name="iatlstringmgr-class"></a>Classe IAtlStringMgr

Essa classe representa a interface para um `CStringT` Gerenciador de memória.

## <a name="syntax"></a>Sintaxe

```
__interface IAtlStringMgr
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[alocar](#allocate)|Chame esse método para alocar uma nova estrutura de dados de cadeia de caracteres.|
|[Clonar](#clone)|Chame esse método para retornar um ponteiro para um novo Gerenciador de cadeia de caracteres para uso com outra instância do `CSimpleStringT`.|
|[livre](#free)|Chame esse método para liberar uma estrutura de dados de cadeia de caracteres.|
|[GetNilString](#getnilstring)|Retorna um ponteiro para o `CStringData` objeto usado por objetos de cadeia de caracteres vazia.|
|[Realocar](#reallocate)|Chame esse método para realocar uma estrutura de dados de cadeia de caracteres.|

## <a name="remarks"></a>Comentários

Essa interface gerencia a memória usada pelas classes de cadeia de caracteres MFC independente; como [CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md), [CStringT](../../atl-mfc-shared/reference/cstringt-class.md), e [CFixedStringT](../../atl-mfc-shared/reference/cfixedstringt-class.md).

Você também pode usar essa classe para implementar um Gerenciador de memória personalizado para a sua classe de cadeia de caracteres personalizada. Para obter mais informações, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpstr.h

##  <a name="allocate"></a>  IAtlStringMgr::Allocate

Aloca uma nova estrutura de dados de cadeia de caracteres.

```
CStringData* Allocate(int nAllocLength,int nCharSize) throw();
```

### <a name="parameters"></a>Parâmetros

*nAllocLength*<br/>
O número de caracteres no novo bloco de memória.

*nCharSize*<br/>
O tamanho (em bytes) do tipo de caractere usado pelo Gerenciador de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o bloco de memória recém-alocada.

> [!NOTE]
>  Não sinalizar uma alocação com falha, lançando uma exceção. Em vez disso, uma falha na alocação deve ser sinalizado, retornando nulo.

### <a name="remarks"></a>Comentários

Chame [IAtlStringMgr::Free](#free) ou [IAtlStringMgr::ReAllocate](#reallocate) para liberar a memória alocada por esse método.

> [!NOTE]
>  Para obter exemplos de uso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

##  <a name="clone"></a>  IAtlStringMgr::Clone

Retorna um ponteiro para um novo Gerenciador de cadeia de caracteres para uso com outra instância do `CSimpleStringT`.

```
IAtlStringMgr* Clone() throw();
```

### <a name="return-value"></a>Valor de retorno

Retorna uma cópia do `IAtlStringMgr` objeto.

### <a name="remarks"></a>Comentários

Geralmente, chamado pelo framework quando um Gerenciador de cadeia de caracteres é necessária para uma nova cadeia de caracteres. Na maioria dos casos, o **isso** ponteiro é retornado.

No entanto, se o Gerenciador de memória não oferece suporte a que está sendo usado por várias instâncias do `CSimpleStringT`, um ponteiro para um Gerenciador de cadeia de caracteres compartilháveis deve ser retornado.

> [!NOTE]
>  Para obter exemplos de uso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

##  <a name="free"></a>  IAtlStringMgr::Free

Libera uma estrutura de dados de cadeia de caracteres.

```
void Free(CStringData* pData) throw();
```

### <a name="parameters"></a>Parâmetros

*pData*<br/>
Um ponteiro para o bloco de memória a ser liberado.

### <a name="remarks"></a>Comentários

Libera o bloco de memória especificado anteriormente alocado pela [Allocate](#allocate) ou [realocar](../../atl/reference/iatlmemmgr-class.md#reallocate).

> [!NOTE]
>  Para obter exemplos de uso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

##  <a name="getnilstring"></a>  IAtlStringMgr::GetNilString

Retorna um ponteiro para uma estrutura de dados de cadeia de caracteres para uma cadeia de caracteres vazia.

```
CStringData* GetNilString() throw();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o `CStringData` objeto usado para representar uma cadeia de caracteres vazia.

### <a name="remarks"></a>Comentários

Chame essa função para retornar uma representação de cadeia de caracteres vazia.

> [!NOTE]
> Ao implementar um Gerenciador de cadeia de caracteres personalizada, essa função nunca deve falhar. Você pode garantir isso incorporando uma instância de `CNilStringData` na classe de Gerenciador de cadeia de caracteres e retornam um ponteiro para essa instância.

> [!NOTE]
> Para obter exemplos de uso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="reallocate"></a>  IAtlStringMgr::Reallocate

Realoca uma estrutura de dados de cadeia de caracteres.

```
CStringData* Reallocate(
    CStringData* pData,
    int nAllocLength,
    int nCharSize) throw();
```

### <a name="parameters"></a>Parâmetros

*pData*<br/>
Ponteiro para a memória alocada anteriormente por este Gerenciador de memória.

*nAllocLength*<br/>
O número de caracteres no novo bloco de memória.

*nCharSize*<br/>
O tamanho (em bytes) do tipo de caractere usado pelo Gerenciador de cadeia de caracteres.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o início do bloco de memória recém-alocada.

### <a name="remarks"></a>Comentários

Chame essa função para redimensionar o bloco de memória existente, especificado por *pData*.

Chame [IAtlStringMgr::Free](#free) para liberar a memória alocada por esse método.

> [!NOTE]
> Para obter exemplos de uso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
