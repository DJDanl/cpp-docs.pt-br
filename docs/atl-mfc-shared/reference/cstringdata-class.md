---
title: Classe CStringData
ms.date: 11/04/2016
f1_keywords:
- CStringData
- ATLSIMPSTR/ATL::CStringData
- ATLSIMPSTR/ATL::AddRef
- ATLSIMPSTR/ATL::data
- ATLSIMPSTR/ATL::IsLocked
- ATLSIMPSTR/ATL::IsShared
- ATLSIMPSTR/ATL::Lock
- ATLSIMPSTR/ATL::Release
- ATLSIMPSTR/ATL::Unlock
- ATLSIMPSTR/ATL::nAllocLength
- ATLSIMPSTR/ATL::nDataLength
- ATLSIMPSTR/ATL::nRefs
- ATLSIMPSTR/ATL::pStringMgr
helpviewer_keywords:
- CStringData class
- shared classes, CStringData
ms.assetid: 4e31b5ca-3dbe-4fd5-b692-8211fbfb2593
ms.openlocfilehash: 5977d26cade89f2e70453d5184323958e99e54c4
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57748509"
---
# <a name="cstringdata-class"></a>Classe CStringData

Essa classe representa os dados de um objeto de cadeia de caracteres.

## <a name="syntax"></a>Sintaxe

```
struct CStringData
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[AddRef](#addref)|Incrementa a contagem de referência do objeto de dados de cadeia de caracteres.|
|[data](#data)|Recupera os dados de caractere de um objeto de cadeia de caracteres.|
|[IsLocked](#islocked)|Determina se o buffer do objeto de cadeia de caracteres associada está bloqueado.|
|[IsShared](#isshared)|Determina se o buffer do objeto de cadeia de caracteres associado no momento é compartilhado.|
|[Bloqueio](#lock)|Bloqueia o buffer do objeto de cadeia de caracteres associada.|
|[Versão](#release)|Libera o objeto de cadeia de caracteres especificada.|
|[Unlock](#unlock)|Libera o buffer do objeto de cadeia de caracteres associada.|

### <a name="data-members"></a>Membros de Dados

|||
|-|-|
|[nAllocLength](#nalloclength)|Comprimento dos dados alocados em `XCHAR`s (não incluindo o nulo de terminação)|
|[nDataLength](#ndatalength)|Comprimento dos dados atualmente usados em `XCHAR`s (não incluindo o nulo de terminação)|
|[nRefs](#nrefs)|A contagem de referência atual do objeto.|
|[pStringMgr](#pstringmgr)|Um ponteiro para o Gerenciador de cadeia de caracteres desse objeto de cadeia de caracteres.|

## <a name="remarks"></a>Comentários

Essa classe deve ser usada somente por desenvolvedores implementar gerenciadores de cadeia de caracteres personalizada. Para obter mais informações sobre gerenciadores de cadeia de caracteres personalizada, consulte [CStringT e gerenciamento de memória](../../atl-mfc-shared/memory-management-with-cstringt.md)

Essa classe encapsula vários tipos de informações e dados associados a um objeto de cadeia de caracteres superior, como [CStringT](../../atl-mfc-shared/reference/cstringt-class.md), [CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md), ou [CFixedStringT](../../atl-mfc-shared/reference/cfixedstringt-class.md) objetos. Cada objeto de cadeia de caracteres superior contém um ponteiro para seus associados `CStringData` objeto, permitindo que vários objetos de cadeia de caracteres apontar para o mesmo objeto de dados de cadeia de caracteres. Essa relação é representada pela contagem de referência (`nRefs`) do `CStringData` objeto.

> [!NOTE]
>  Em alguns casos, um tipo de cadeia de caracteres (como `CFixedString`) não compartilhará um objeto de dados de cadeia de caracteres com mais de um objeto de cadeia de caracteres maior. Para obter mais informações sobre isso, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

Esses dados são compostos de:

- O Gerenciador de memória (do tipo [IAtlStringMgr](../../atl-mfc-shared/reference/iatlstringmgr-class.md)) da cadeia de caracteres.

- O comprimento atual ( [nDataLength](#ndatalength)) da cadeia de caracteres.

- O tamanho alocado ( [nAllocLength](#nalloclength)) da cadeia de caracteres. Por motivos de desempenho, isso pode ser diferente do comprimento atual da cadeia de caracteres

- A contagem de referência atual ( [nRefs](#nrefs)) do `CStringData` objeto. Esse valor é usado para determinar quantos objetos de cadeia de caracteres estão compartilhando o mesmo `CStringData` objeto.

- O buffer de caracteres real ( [dados](#data)) da cadeia de caracteres.

   > [!NOTE]
   > O buffer de caracteres real do objeto de cadeia de caracteres é alocado pelo Gerenciador de cadeia de caracteres e é anexado ao `CStringData` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpstr.h

##  <a name="addref"></a>  CStringData::AddRef

Incrementa a contagem de referência do objeto de cadeia de caracteres.

```
void AddRef() throw();
```

### <a name="remarks"></a>Comentários

Incrementa a contagem de referência do objeto de cadeia de caracteres.

> [!NOTE]
>  Não chame este método em uma cadeia de caracteres com uma contagem de referência negativo, como uma contagem negativa indica que o buffer de cadeia de caracteres está bloqueado.

##  <a name="data"></a>  CStringData::data

Retorna um ponteiro para o buffer de caracteres de um objeto de cadeia de caracteres.

```
void* data() throw();
```

### <a name="return-value"></a>Valor de retorno

Um ponteiro para o buffer de caracteres do objeto de cadeia de caracteres.

### <a name="remarks"></a>Comentários

Chame essa função para retornar o buffer de caracteres atual do objeto de cadeia de caracteres associada.

> [!NOTE]
>  Esse buffer não está alocado pelo `CStringData` objeto, mas pelo Gerenciador de cadeia de caracteres quando necessário. Quando alocados, o buffer é anexado ao objeto de dados de cadeia de caracteres.

##  <a name="islocked"></a>  CStringData::IsLocked

Determina se o buffer de caracteres está bloqueado.

```
bool IsLocked() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o buffer está bloqueado; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame essa função para determinar se o buffer de caracteres de um objeto de cadeia de caracteres está bloqueado no momento.

##  <a name="isshared"></a>  CStringData::IsShared

Determina se o buffer de caracteres é compartilhado.

```
bool IsShared() const throw();
```

### <a name="return-value"></a>Valor de retorno

Retornará TRUE se o buffer é compartilhado; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame essa função para determinar se o buffer de caracteres de um objeto de dados de cadeia de caracteres no momento é compartilhado entre vários objetos de cadeia de caracteres.

##  <a name="lock"></a>  CStringData::Lock

Bloqueia o buffer de caracteres do objeto de cadeia de caracteres associada.

```
void Lock() throw();
```

### <a name="remarks"></a>Comentários

Chame essa função para bloquear o buffer de caracteres do objeto de dados de cadeia de caracteres. Bloqueando e desbloqueando é usado quando o acesso direto ao buffer de caracteres é exigido pelo desenvolvedor. Um bom exemplo de bloqueio é demonstrado pelo [LockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [UnlockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) métodos de `CSimpleStringT`.

> [!NOTE]
>  Um buffer de caracteres só pode ser bloqueado se o buffer não é compartilhado entre os objetos de cadeia de caracteres maior.

##  <a name="nalloclength"></a>  CStringData::nAllocLength

Tamanho do buffer alocado de caractere.

```
int nAllocLength;
```

### <a name="remarks"></a>Comentários

Armazena o comprimento do buffer de dados alocados em `XCHAR`s (não incluindo o nulo de terminação).

##  <a name="ndatalength"></a>  CStringData::nDataLength

Tamanho atual do objeto de cadeia de caracteres.

```
int nDataLength;
```

### <a name="remarks"></a>Comentários

Armazena o comprimento de dados atualmente em uso no `XCHAR`s (não incluindo o nulo de terminação).

##  <a name="nrefs"></a>  CStringData::nRefs

Contagem de referência do objeto de dados de cadeia de caracteres.

```
long nRefs;
```

### <a name="remarks"></a>Comentários

Armazena a contagem de referência do objeto de dados de cadeia de caracteres. Essa contagem indica o número de objetos de cadeia de caracteres mais alto que estão associados com o objeto de dados de cadeia de caracteres. Um valor negativo indica que o objeto de dados de cadeia de caracteres está bloqueado no momento.

##  <a name="pstringmgr"></a>  CStringData::pStringMgr

O Gerenciador de memória do objeto de cadeia de caracteres associada.

```
IAtlStringMgr* pStringMgr;
```

### <a name="remarks"></a>Comentários

Armazena o Gerenciador de memória para o objeto de cadeia de caracteres associada. Para obter mais informações sobre gerenciadores de memória e cadeias de caracteres, consulte [gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

##  <a name="release"></a>  CStringData::Release

Diminui a contagem de referência do objeto de dados de cadeia de caracteres.

```
void Release() throw();
```

### <a name="remarks"></a>Comentários

Chame essa função para reduzir a contagem de referência, liberando o `CStringData` estrutura se a contagem de referência atingir zero. Normalmente, isso é feito quando um objeto de cadeia de caracteres é excluído e, portanto, não precisa mais fazer referência ao objeto de dados de cadeia de caracteres.

Por exemplo, o código a seguir chamaria `CStringData::Release` para o objeto de dados de cadeia de caracteres associado `str1`:

[!code-cpp[NVC_ATLMFC_Utilities#104](../../atl-mfc-shared/codesnippet/cpp/cstringdata-class_1.cpp)]

##  <a name="unlock"></a>  CStringData::Unlock

Libera o buffer de caracteres do objeto de cadeia de caracteres associada.

```
void Unlock() throw();
```

### <a name="remarks"></a>Comentários

Chame essa função para desbloquear o buffer de caracteres do objeto de dados de cadeia de caracteres. Depois que um buffer é desbloqueado, pode ser compartilhada e pode ser referência contada.

> [!NOTE]
>  Cada chamada para `Lock` deve ser correspondida por uma chamada correspondente para `Unlock`.

Bloqueando e desbloqueando é usado quando o desenvolvedor deve assegurar que os dados de cadeia de caracteres não seja compartilhada. Um bom exemplo de bloqueio é demonstrado pelo [LockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [UnlockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) métodos de `CSimpleStringT`.

## <a name="see-also"></a>Consulte também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
