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
ms.openlocfilehash: bee9c3d27ea05a40d6835d69079fc3e0a56efb86
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219047"
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
|[Aloca](#allocate)|Chame esse método para alocar uma nova estrutura de dados de cadeia de caracteres.|
|[Clone](#clone)|Chame esse método para retornar um ponteiro para um novo Gerenciador de cadeia de caracteres para uso com outra instância do `CSimpleStringT` .|
|[Gratuito](#free)|Chame esse método para liberar uma estrutura de dados de cadeia de caracteres.|
|[GetNilString](#getnilstring)|Retorna um ponteiro para o `CStringData` objeto usado por objetos de cadeia de caracteres vazios.|
|[Realocar](#reallocate)|Chame esse método para realocar uma estrutura de dados de cadeia de caracteres.|

## <a name="remarks"></a>Comentários

Essa interface gerencia a memória usada pelas classes de cadeia de caracteres independentes do MFC; como [CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md), [CStringT](../../atl-mfc-shared/reference/cstringt-class.md)e [CFixedStringT](../../atl-mfc-shared/reference/cfixedstringt-class.md).

Você também pode usar essa classe para implementar um Gerenciador de memória personalizado para sua classe de cadeia de caracteres personalizada. Para obter mais informações, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpstr. h

## <a name="iatlstringmgrallocate"></a><a name="allocate"></a>IAtlStringMgr:: Allocate

Aloca uma nova estrutura de dados de cadeia de caracteres.

```
CStringData* Allocate(int nAllocLength,int nCharSize) throw();
```

### <a name="parameters"></a>parâmetros

*nAllocLength*<br/>
O número de caracteres no novo bloco de memória.

*nCharSize*<br/>
O tamanho (em bytes) do tipo de caractere usado pelo Gerenciador de cadeia de caracteres.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o bloco de memória alocado recentemente.

> [!NOTE]
> Não sinalize uma alocação com falha lançando uma exceção. Em vez disso, uma alocação com falha deve ser sinalizada retornando NULL.

### <a name="remarks"></a>Comentários

Chame [IAtlStringMgr:: Free](#free) ou [IAtlStringMgr:: realoque](#reallocate) para liberar a memória alocada por esse método.

> [!NOTE]
> Para obter exemplos de uso, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="iatlstringmgrclone"></a><a name="clone"></a>IAtlStringMgr:: clone

Retorna um ponteiro para um novo Gerenciador de cadeia de caracteres para uso com outra instância do `CSimpleStringT` .

```
IAtlStringMgr* Clone() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma cópia do objeto `IAtlStringMgr`.

### <a name="remarks"></a>Comentários

Normalmente chamado pelo Framework quando um Gerenciador de cadeia de caracteres é necessário para uma nova cadeia de caracteres. Na maioria dos casos, o **`this`** ponteiro é retornado.

No entanto, se o Gerenciador de memória não oferecer suporte para uso por várias instâncias do `CSimpleStringT` , um ponteiro para um Gerenciador de cadeia de caracteres compartilhável deverá ser retornado.

> [!NOTE]
> Para obter exemplos de uso, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="iatlstringmgrfree"></a><a name="free"></a>IAtlStringMgr:: Free

Libera uma estrutura de dados de cadeia de caracteres.

```cpp
void Free(CStringData* pData) throw();
```

### <a name="parameters"></a>parâmetros

*pData*<br/>
Um ponteiro para o bloco de memória a ser liberado.

### <a name="remarks"></a>Comentários

Libera o bloco de memória especificado anteriormente alocado por [alocar](#allocate) ou [realocar](../../atl/reference/iatlmemmgr-class.md#reallocate).

> [!NOTE]
> Para obter exemplos de uso, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="iatlstringmgrgetnilstring"></a><a name="getnilstring"></a>IAtlStringMgr::GetNilString

Retorna um ponteiro para uma estrutura de dados de cadeia de caracteres para uma cadeia de caracteres vazia.

```
CStringData* GetNilString() throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o `CStringData` objeto usado para representar uma cadeia de caracteres vazia.

### <a name="remarks"></a>Comentários

Chame essa função para retornar uma representação de uma cadeia de caracteres vazia.

> [!NOTE]
> Ao implementar um Gerenciador de cadeia de caracteres personalizado, essa função nunca deve falhar. Você pode garantir isso inserindo uma instância do `CNilStringData` na classe do Gerenciador de cadeia de caracteres e retornar um ponteiro para essa instância.

> [!NOTE]
> Para obter exemplos de uso, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="iatlstringmgrreallocate"></a><a name="reallocate"></a>IAtlStringMgr:: realocar

Realoca uma estrutura de dados de cadeia de caracteres.

```
CStringData* Reallocate(
    CStringData* pData,
    int nAllocLength,
    int nCharSize) throw();
```

### <a name="parameters"></a>parâmetros

*pData*<br/>
Ponteiro para a memória alocada anteriormente por esse Gerenciador de memória.

*nAllocLength*<br/>
O número de caracteres no novo bloco de memória.

*nCharSize*<br/>
O tamanho (em bytes) do tipo de caractere usado pelo Gerenciador de cadeia de caracteres.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o início do bloco de memória alocado recentemente.

### <a name="remarks"></a>Comentários

Chame essa função para redimensionar o bloco de memória existente especificado por *pData*.

Chame [IAtlStringMgr:: Free](#free) para liberar a memória alocada por este método.

> [!NOTE]
> Para obter exemplos de uso, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
