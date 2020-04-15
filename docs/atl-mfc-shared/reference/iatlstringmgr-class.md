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
ms.openlocfilehash: 49ef7850edb18cd51092f282644973376abd4c7c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317490"
---
# <a name="iatlstringmgr-class"></a>Classe IAtlStringMgr

Esta classe representa a `CStringT` interface para um gerenciador de memória.

## <a name="syntax"></a>Sintaxe

```
__interface IAtlStringMgr
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Alocar](#allocate)|Chame este método para alocar uma nova estrutura de dados de string.|
|[Clonar](#clone)|Chame este método para retornar um ponteiro a um `CSimpleStringT`novo gerenciador de strings para uso com outra instância de .|
|[Livre](#free)|Chame este método para liberar uma estrutura de dados de cadeia.|
|[GetNilString](#getnilstring)|Retorna um ponteiro `CStringData` para o objeto usado por objetos de seqüência vazios.|
|[Realocar](#reallocate)|Chame este método para realocar uma estrutura de dados de cadeia.|

## <a name="remarks"></a>Comentários

Esta interface gerencia a memória usada pelas classes de string independentes do MFC; como [CSimpleStringT,](../../atl-mfc-shared/reference/csimplestringt-class.md) [CStringT](../../atl-mfc-shared/reference/cstringt-class.md)e [CFixedStringT](../../atl-mfc-shared/reference/cfixedstringt-class.md).

Você também pode usar esta classe para implementar um gerenciador de memória personalizado para sua classe de strings personalizada. Para obter mais informações, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpstr.h

## <a name="iatlstringmgrallocate"></a><a name="allocate"></a>IAtlStringMgr::Alocar

Aloca uma nova estrutura de dados de string.

```
CStringData* Allocate(int nAllocLength,int nCharSize) throw();
```

### <a name="parameters"></a>Parâmetros

*Nalloclength*<br/>
O número de caracteres no novo bloco de memória.

*nCharSize*<br/>
O tamanho (em bytes) do tipo de caractere usado pelo gerenciador de strings.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o bloco de memória recém-alocado.

> [!NOTE]
> Não sinalize uma alocação falha, lançando uma exceção. Em vez disso, uma alocação falha deve ser sinalizada retornando NULL.

### <a name="remarks"></a>Comentários

Ligue para [IAtlStringMgr:::Free](#free) ou [IAtlStringMgr::ReAllocate](#reallocate) para liberar a memória alocada por este método.

> [!NOTE]
> Para exemplos de uso, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="iatlstringmgrclone"></a><a name="clone"></a>IAtlStringMgr::Clone

Retorna um ponteiro a um novo gerenciador `CSimpleStringT`de strings para uso com outra instância de .

```
IAtlStringMgr* Clone() throw();
```

### <a name="return-value"></a>Valor retornado

Retorna uma cópia do objeto `IAtlStringMgr`.

### <a name="remarks"></a>Comentários

Comumente chamado pela framework quando um gerenciador de strings é necessário para uma nova seqüência. Na maioria dos casos, o ponteiro **é** devolvido.

No entanto, se o gerenciador de `CSimpleStringT`memória não suportar o uso por várias instâncias de , um ponteiro para um gerenciador de strings sharable deve ser devolvido.

> [!NOTE]
> Para exemplos de uso, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="iatlstringmgrfree"></a><a name="free"></a>IAtlStringMgr::Grátis

Libera uma estrutura de dados de cordas.

```
void Free(CStringData* pData) throw();
```

### <a name="parameters"></a>Parâmetros

*Pdata*<br/>
Um ponteiro para o bloco de memória a ser liberado.

### <a name="remarks"></a>Comentários

Libera o bloco de memória especificado anteriormente alocado por [Alocar](#allocate) ou [Realocar](../../atl/reference/iatlmemmgr-class.md#reallocate).

> [!NOTE]
> Para exemplos de uso, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="iatlstringmgrgetnilstring"></a><a name="getnilstring"></a>IAtlStringMgr::GetNilString

Retorna um ponteiro para uma estrutura de dados de seqüência de strings para uma seqüência de string vazia.

```
CStringData* GetNilString() throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro `CStringData` para o objeto usado para representar uma seqüência de string vazia.

### <a name="remarks"></a>Comentários

Chame esta função para retornar uma representação de uma seqüência de string vazia.

> [!NOTE]
> Ao implementar um gerenciador de strings personalizado, essa função nunca deve falhar. Você pode garantir isso incorporando `CNilStringData` uma instância na classe gerenciador de strings e retornar um ponteiro para essa instância.

> [!NOTE]
> Para exemplos de uso, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="iatlstringmgrreallocate"></a><a name="reallocate"></a>IAtlStringMgr::Realocação

Realoca uma estrutura de dados de string.

```
CStringData* Reallocate(
    CStringData* pData,
    int nAllocLength,
    int nCharSize) throw();
```

### <a name="parameters"></a>Parâmetros

*Pdata*<br/>
Ponteiro para a memória anteriormente alocada por este gerenciador de memória.

*Nalloclength*<br/>
O número de caracteres no novo bloco de memória.

*nCharSize*<br/>
O tamanho (em bytes) do tipo de caractere usado pelo gerenciador de strings.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o início do bloco de memória recém-alocado.

### <a name="remarks"></a>Comentários

Chame esta função para redimensionar o bloco de memória existente especificado por *pData*.

Ligue para [IAtlStringMgr:::Livre](#free) para liberar a memória alocada por este método.

> [!NOTE]
> Para exemplos de uso, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
