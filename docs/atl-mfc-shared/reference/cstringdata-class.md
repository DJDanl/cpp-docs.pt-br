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
ms.openlocfilehash: 5915d9e25588e4e35538619662281ceaf1b35ff7
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81317606"
---
# <a name="cstringdata-class"></a>Classe CStringData

Esta classe representa os dados de um objeto de seqüência.

## <a name="syntax"></a>Sintaxe

```
struct CStringData
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[AddRef](#addref)|Incrementa a contagem de referência do objeto de dados de seqüência.|
|[dados](#data)|Recupera os dados de caracterede um objeto de seqüência.|
|[IsLocked](#islocked)|Determina se o buffer do objeto de seqüência associado está bloqueado.|
|[IsShared](#isshared)|Determina se o buffer do objeto de seqüência associado está atualmente compartilhado.|
|[Bloqueio](#lock)|Bloqueia o buffer do objeto de seqüência associado.|
|[Versão](#release)|Libera o objeto de string especificado.|
|[Desbloquear](#unlock)|Desbloqueia o buffer do objeto de seqüência associado.|

### <a name="data-members"></a>Membros de dados

|||
|-|-|
|[Nalloclength](#nalloclength)|Comprimento dos dados `XCHAR`alocados em s (sem incluir o término nulo)|
|[nDataLength](#ndatalength)|Comprimento dos dados usados atualmente em `XCHAR`s (sem incluir o término nulo)|
|[nRefs](#nrefs)|A contagem de referência atual do objeto.|
|[pStringMgr](#pstringmgr)|Um ponteiro para o gerenciador de strings deste objeto de seqüência.|

## <a name="remarks"></a>Comentários

Esta classe só deve ser usada por desenvolvedores que implementam gerentes de stringpersonalizados. Para obter mais informações sobre gerenciadores de strings personalizados, consulte [Memory Management e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md)

Esta classe encapsula vários tipos de informações e dados associados a um objeto de seqüência superior, como objetos [CStringT,](../../atl-mfc-shared/reference/cstringt-class.md) [CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)ou [CFixedStringT.](../../atl-mfc-shared/reference/cfixedstringt-class.md) Cada objeto de seqüência `CStringData` superior contém um ponteiro para seu objeto associado, permitindo que vários objetos de seqüência apontem para o mesmo objeto de dados de seqüência. Essa relação é representada pela`nRefs`contagem `CStringData` de referência ( ) do objeto.

> [!NOTE]
> Em certos casos, um tipo `CFixedString`de string (como ) não compartilhará um objeto de dados de seqüência com mais de um objeto de seqüência superior. Para obter mais informações sobre isso, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

Esses dados são compostos por:

- O gerenciador de memória (do tipo [IAtlStringMgr)](../../atl-mfc-shared/reference/iatlstringmgr-class.md)da string.

- O comprimento atual [(nDataLength)](#ndatalength)da string.

- O comprimento alocado [(nAllocLength)](#nalloclength)da string. Por razões de desempenho, isso pode diferir do comprimento atual da seqüência

- A contagem de referência atual `CStringData` [(nRefs)](#nrefs)do objeto. Esse valor é usado para determinar quantos `CStringData` objetos de seqüência estão compartilhando o mesmo objeto.

- O buffer de caracterereal [(dados)](#data)da seqüência.

   > [!NOTE]
   > O buffer de caracterereal do objeto de seqüência é `CStringData` alocado pelo gerenciador de strings e é anexado ao objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpstr.h

## <a name="cstringdataaddref"></a><a name="addref"></a>CStringData::AddRef

Incrementa a contagem de referência do objeto de seqüência.

```
void AddRef() throw();
```

### <a name="remarks"></a>Comentários

Incrementa a contagem de referência do objeto de seqüência.

> [!NOTE]
> Não chame esse método de string com uma contagem de referência negativa, uma vez que uma contagem negativa indica que o buffer de string está bloqueado.

## <a name="cstringdatadata"></a><a name="data"></a>CStringData::data

Retorna um ponteiro para o buffer de caracteres de um objeto de seqüência.

```
void* data() throw();
```

### <a name="return-value"></a>Valor retornado

Um ponteiro para o buffer de caracteres do objeto de seqüência.

### <a name="remarks"></a>Comentários

Chame esta função para retornar o buffer de caractereatual do objeto de seqüência de caracteres associado.

> [!NOTE]
> Este buffer não é `CStringData` alocado pelo objeto, mas pelo gerenciador de strings quando necessário. Quando alocado, o buffer é anexado ao objeto de dados de seqüência.

## <a name="cstringdataislocked"></a><a name="islocked"></a>CStringData::IsLocked

Determina se o buffer de caracteres está bloqueado.

```
bool IsLocked() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o buffer estiver bloqueado; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Chame esta função para determinar se o buffer de caracteres de um objeto de seqüência está bloqueado no momento.

## <a name="cstringdataisshared"></a><a name="isshared"></a>CStringData::IsShared

Determina se o buffer de caracteres é compartilhado.

```
bool IsShared() const throw();
```

### <a name="return-value"></a>Valor retornado

Retorna TRUE se o buffer for compartilhado; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

Chame esta função para determinar se o buffer de caracteres de um objeto de dados de seqüência é atualmente compartilhado entre vários objetos de seqüência.

## <a name="cstringdatalock"></a><a name="lock"></a>CStringData::Bloqueio

Bloqueia o buffer de caracteres do objeto de seqüência associado.

```
void Lock() throw();
```

### <a name="remarks"></a>Comentários

Chame esta função para bloquear o buffer de caracteres do objeto de dados de seqüência. O bloqueio e o desbloqueio são usados quando o acesso direto ao buffer de caracteres é exigido pelo desenvolvedor. Um bom exemplo de bloqueio é demonstrado pelos métodos [LockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [UnlockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) de `CSimpleStringT`.

> [!NOTE]
> Um buffer de caracteres só pode ser bloqueado se o buffer não for compartilhado entre objetos de seqüência superiores.

## <a name="cstringdatanalloclength"></a><a name="nalloclength"></a>CStringData::nAllocLength

Comprimento do buffer de caractere alocado.

```
int nAllocLength;
```

### <a name="remarks"></a>Comentários

Armazena o comprimento do buffer `XCHAR`de dados alocado em s (sem incluir o término nulo).

## <a name="cstringdatandatalength"></a><a name="ndatalength"></a>CStringData::nDataLength

Comprimento atual do objeto de corda.

```
int nDataLength;
```

### <a name="remarks"></a>Comentários

Armazena o comprimento dos dados `XCHAR`usados atualmente em s (sem incluir o término nulo).

## <a name="cstringdatanrefs"></a><a name="nrefs"></a>CStringData::nRefs

Contagem de referência do objeto de dados de seqüência.

```
long nRefs;
```

### <a name="remarks"></a>Comentários

Armazena a contagem de referência do objeto de dados de seqüência. Esta contagem indica o número de objetos de seqüência mais altos que estão associados ao objeto de dados de seqüência. Um valor negativo indica que o objeto de dados de seqüência está bloqueado no momento.

## <a name="cstringdatapstringmgr"></a><a name="pstringmgr"></a>CStringData::pString

O gerenciador de memória do objeto de seqüência associado.

```
IAtlStringMgr* pStringMgr;
```

### <a name="remarks"></a>Comentários

Armazena o gerenciador de memória para o objeto de string associado. Para obter mais informações sobre gerenciadores de memória e strings, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="cstringdatarelease"></a><a name="release"></a>CStringData::Lançamento

Decreta a contagem de referência do objeto de dados de seqüência.

```
void Release() throw();
```

### <a name="remarks"></a>Comentários

Chame esta função para diminuir a contagem `CStringData` de referência, liberando a estrutura se a contagem de referência atingir zero. Isso é comumente feito quando um objeto de seqüência é excluído e, portanto, não precisa mais fazer referência ao objeto de dados de seqüência.

Por exemplo, o código `CStringData::Release` a seguir exigiria `str1`o objeto de dados de seqüência associado a:

[!code-cpp[NVC_ATLMFC_Utilities#104](../../atl-mfc-shared/codesnippet/cpp/cstringdata-class_1.cpp)]

## <a name="cstringdataunlock"></a><a name="unlock"></a>CStringData::Desbloqueio

Desbloqueia o buffer de caracteres do objeto de seqüência de caracteres associado.

```
void Unlock() throw();
```

### <a name="remarks"></a>Comentários

Chame esta função para desbloquear o buffer de caracteres do objeto de dados de seqüência. Uma vez que um buffer é desbloqueado, ele é compartilhável e pode ser contado de referência.

> [!NOTE]
> Cada chamada `Lock` deve ser combinada com `Unlock`uma chamada correspondente a .

O bloqueio e o desbloqueio são usados quando o desenvolvedor deve garantir que os dados da seqüência não sejam compartilhados. Um bom exemplo de bloqueio é demonstrado pelos métodos [LockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [UnlockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) de `CSimpleStringT`.

## <a name="see-also"></a>Confira também

[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
