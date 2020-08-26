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
ms.openlocfilehash: 140836f45ed2f4088bc0baed67676f93cb268d01
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832107"
---
# <a name="cstringdata-class"></a>Classe CStringData

Essa classe representa os dados de um objeto de cadeia de caracteres.

## <a name="syntax"></a>Sintaxe

```
struct CStringData
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|Nome|Descrição|
|-|-|
|[AddRef](#addref)|Incrementa a contagem de referência do objeto de dados de cadeia de caracteres.|
|[data](#data)|Recupera os dados de caractere de um objeto de cadeia de caracteres.|
|[IsLocked](#islocked)|Determina se o buffer do objeto de cadeia de caracteres associado está bloqueado.|
|[IsShared](#isshared)|Determina se o buffer do objeto de cadeia de caracteres associado está compartilhado no momento.|
|[Bloqueio](#lock)|Bloqueia o buffer do objeto de cadeia de caracteres associado.|
|[Versão](#release)|Libera o objeto de cadeia de caracteres especificado.|
|[Automático](#unlock)|Desbloqueia o buffer do objeto de cadeia de caracteres associado.|

### <a name="data-members"></a>Membros de dados

|Nome|Descrição|
|-|-|
|[nAllocLength](#nalloclength)|Comprimento dos dados alocados em `XCHAR` s (sem incluir a terminação nula)|
|[nDataLength](#ndatalength)|Comprimento dos dados atualmente usados em `XCHAR` s (sem incluir o encerramento nulo)|
|[nRefs](#nrefs)|A contagem de referência atual do objeto.|
|[pStringMgr](#pstringmgr)|Um ponteiro para o Gerenciador de cadeia de caracteres desse objeto de cadeia de caracteres.|

## <a name="remarks"></a>Comentários

Essa classe só deve ser usada por desenvolvedores que implementam gerenciadores de cadeias de caracteres personalizadas. Para obter mais informações sobre gerenciadores de cadeias de caracteres personalizadas, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md)

Essa classe encapsula vários tipos de informações e dados associados a um objeto String mais alto, como objetos [CStringT](../../atl-mfc-shared/reference/cstringt-class.md), [CSimpleStringT](../../atl-mfc-shared/reference/csimplestringt-class.md)ou [CFixedStringT](../../atl-mfc-shared/reference/cfixedstringt-class.md) . Cada objeto de cadeia de caracteres superior contém um ponteiro para seu `CStringData` objeto associado, permitindo que vários objetos de cadeia de caracteres apontem para o mesmo objeto de dados de cadeia de caracteres. Essa relação é representada pela contagem de referência ( `nRefs` ) do `CStringData` objeto.

> [!NOTE]
> Em determinados casos, um tipo de cadeia de caracteres (como `CFixedString` ) não compartilhará um objeto de dados de cadeia de caracteres com mais de um objeto de cadeia de caracteres mais alto. Para obter mais informações sobre isso, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

Esses dados são compostos de:

- O Gerenciador de memória (do tipo [IAtlStringMgr](../../atl-mfc-shared/reference/iatlstringmgr-class.md)) da cadeia de caracteres.

- O comprimento atual ( [nDataLength](#ndatalength)) da cadeia de caracteres.

- O comprimento alocado ( [nAllocLength](#nalloclength)) da cadeia de caracteres. Por motivos de desempenho, isso pode diferir do comprimento da cadeia de caracteres atual

- A contagem de referência atual ( [nRefs](#nrefs)) do `CStringData` objeto. Esse valor é usado para determinar quantos objetos de cadeia de caracteres estão compartilhando o mesmo `CStringData` objeto.

- O buffer de caracteres real ( [dados](#data)) da cadeia de caracteres.

   > [!NOTE]
   > O buffer de caracteres real do objeto de cadeia de caracteres é alocado pelo Gerenciador de cadeia de caracteres e é anexado ao `CStringData` objeto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlsimpstr. h

## <a name="cstringdataaddref"></a><a name="addref"></a> CStringData:: AddRef

Incrementa a contagem de referência do objeto de cadeia de caracteres.

```cpp
void AddRef() throw();
```

### <a name="remarks"></a>Comentários

Incrementa a contagem de referência do objeto de cadeia de caracteres.

> [!NOTE]
> Não chame esse método em uma cadeia de caracteres com uma contagem de referência negativa, uma vez que uma contagem negativa indica que o buffer da cadeia de caracteres está bloqueado.

## <a name="cstringdatadata"></a><a name="data"></a> CStringData::d ATA

Retorna um ponteiro para o buffer de caracteres de um objeto de cadeia de caracteres.

```cpp
void* data() throw();
```

### <a name="return-value"></a>Valor Retornado

Um ponteiro para o buffer de caracteres do objeto de cadeia de caracteres.

### <a name="remarks"></a>Comentários

Chame essa função para retornar o buffer de caracteres atual do objeto de cadeia de caracteres associado.

> [!NOTE]
> Esse buffer não é alocado pelo `CStringData` objeto, mas pelo Gerenciador de cadeia de caracteres quando necessário. Quando alocado, o buffer é anexado ao objeto de dados de cadeia de caracteres.

## <a name="cstringdataislocked"></a><a name="islocked"></a> CStringData:: IsLocked

Determina se o buffer de caracteres está bloqueado.

```
bool IsLocked() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retornará TRUE se o buffer estiver bloqueado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame essa função para determinar se o buffer de caracteres de um objeto de cadeia de caracteres está bloqueado no momento.

## <a name="cstringdataisshared"></a><a name="isshared"></a> CStringData:: IsShared

Determina se o buffer de caracteres é compartilhado.

```
bool IsShared() const throw();
```

### <a name="return-value"></a>Valor Retornado

Retornará TRUE se o buffer for compartilhado; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Chame essa função para determinar se o buffer de caracteres de um objeto de dados de cadeia de caracteres está compartilhado atualmente entre vários objetos de cadeia de caracteres.

## <a name="cstringdatalock"></a><a name="lock"></a> CStringData:: Lock

Bloqueia o buffer de caracteres do objeto de cadeia de caracteres associado.

```cpp
void Lock() throw();
```

### <a name="remarks"></a>Comentários

Chame essa função para bloquear o buffer de caracteres do objeto de dados de cadeia de caracteres. O bloqueio e o desbloqueio são usados quando o acesso direto ao buffer de caracteres é exigido pelo desenvolvedor. Um bom exemplo de bloqueio é demonstrado pelos métodos [LockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [UnlockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) de `CSimpleStringT` .

> [!NOTE]
> Um buffer de caracteres só poderá ser bloqueado se o buffer não for compartilhado entre objetos de cadeia de caracteres superiores.

## <a name="cstringdatanalloclength"></a><a name="nalloclength"></a> CStringData::nAllocLength

Comprimento do buffer de caracteres alocado.

```
int nAllocLength;
```

### <a name="remarks"></a>Comentários

Armazena o comprimento do buffer de dados alocado em `XCHAR` s (sem incluir a terminação nula).

## <a name="cstringdatandatalength"></a><a name="ndatalength"></a> CStringData::nDataLength

Comprimento atual do objeto de cadeia de caracteres.

```
int nDataLength;
```

### <a name="remarks"></a>Comentários

Armazena o comprimento dos dados atualmente usados em `XCHAR` s (sem incluir a terminação nula).

## <a name="cstringdatanrefs"></a><a name="nrefs"></a> CStringData::nRefs

Contagem de referência do objeto de dados de cadeia de caracteres.

```
long nRefs;
```

### <a name="remarks"></a>Comentários

Armazena a contagem de referência do objeto de dados de cadeia de caracteres. Essa contagem indica o número de objetos de cadeia de caracteres mais altos associados ao objeto de dados de cadeia de caracteres. Um valor negativo indica que o objeto de dados de cadeia de caracteres está bloqueado no momento.

## <a name="cstringdatapstringmgr"></a><a name="pstringmgr"></a> CStringData::p StringMgr

O Gerenciador de memória do objeto de cadeia de caracteres associado.

```
IAtlStringMgr* pStringMgr;
```

### <a name="remarks"></a>Comentários

Armazena o Gerenciador de memória para o objeto de cadeia de caracteres associado. Para obter mais informações sobre cadeias de caracteres e gerenciadores de memória, consulte [Gerenciamento de memória e CStringT](../../atl-mfc-shared/memory-management-with-cstringt.md).

## <a name="cstringdatarelease"></a><a name="release"></a> CStringData:: versão

Decrementa a contagem de referência do objeto de dados de cadeia de caracteres.

```cpp
void Release() throw();
```

### <a name="remarks"></a>Comentários

Chame essa função para diminuir a contagem de referência, liberando a `CStringData` estrutura se a contagem de referência chegar a zero. Isso normalmente é feito quando um objeto de cadeia de caracteres é excluído e, portanto, não precisa mais fazer referência ao objeto de dados de cadeia de caracteres.

Por exemplo, o código a seguir chamaria `CStringData::Release` o objeto de dados de cadeia de caracteres associado a `str1` :

[!code-cpp[NVC_ATLMFC_Utilities#104](../../atl-mfc-shared/codesnippet/cpp/cstringdata-class_1.cpp)]

## <a name="cstringdataunlock"></a><a name="unlock"></a> CStringData:: desbloquear

Desbloqueia o buffer de caracteres do objeto de cadeia de caracteres associado.

```cpp
void Unlock() throw();
```

### <a name="remarks"></a>Comentários

Chame essa função para desbloquear o buffer de caracteres do objeto de dados de cadeia de caracteres. Depois que um buffer é desbloqueado, ele é compartilhável e pode ter referência contada.

> [!NOTE]
> Cada chamada para `Lock` deve ser correspondida por uma chamada correspondente para `Unlock` .

O bloqueio e o desbloqueio são usados quando o desenvolvedor deve garantir que os dados da cadeia de caracteres não sejam compartilhados. Um bom exemplo de bloqueio é demonstrado pelos métodos [LockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#lockbuffer) e [UnlockBuffer](../../atl-mfc-shared/reference/csimplestringt-class.md#unlockbuffer) de `CSimpleStringT` .

## <a name="see-also"></a>Confira também

[Gráfico de hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classes compartilhadas ATL/MFC](../../atl-mfc-shared/atl-mfc-shared-classes.md)
