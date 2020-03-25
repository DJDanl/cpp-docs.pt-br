---
title: Classe CManualAccessor
ms.date: 11/04/2016
f1_keywords:
- ATL::CManualAccessor
- ATL.CManualAccessor
- CManualAccessor
- ATL::CManualAccessor::AddBindEntry
- ATL.CManualAccessor.AddBindEntry
- CManualAccessor::AddBindEntry
- CManualAccessor.AddBindEntry
- CManualAccessor::AddParameterEntry
- ATL.CManualAccessor.AddParameterEntry
- CManualAccessor.AddParameterEntry
- AddParameterEntry
- ATL::CManualAccessor::AddParameterEntry
- ATL::CManualAccessor::CreateAccessor
- ATL.CManualAccessor.CreateAccessor
- CManualAccessor.CreateAccessor
- CManualAccessor::CreateAccessor
- ATL::CManualAccessor::CreateParameterAccessor
- ATL.CManualAccessor.CreateParameterAccessor
- CManualAccessor.CreateParameterAccessor
- CreateParameterAccessor
- CManualAccessor::CreateParameterAccessor
helpviewer_keywords:
- CManualAccessor class
- AddBindEntry method
- AddParameterEntry method
- CreateAccessor method
- CreateParameterAccessor method
ms.assetid: a0088074-7135-465c-b228-69097a50b8cc
ms.openlocfilehash: 4d9fb79bbf5203fa959672faec8c3b076c17f1ca
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80211842"
---
# <a name="cmanualaccessor-class"></a>Classe CManualAccessor

Representa um tipo de acessador projetado para uso avançado.

## <a name="syntax"></a>Sintaxe

```cpp
class CManualAccessor : public CAccessorBase
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli. h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[AddBindEntry](#addbindentry)|Adiciona uma entrada de associação às colunas de saída.|
|[AddParameterEntry](#addparameterentry)|Adiciona uma entrada de parâmetro ao acessador de parâmetro.|
|[Createaccesser](#createaccessor)|Aloca memória para as estruturas de associação de coluna e inicializa os membros de dados de coluna.|
|[CreateParameterAccessor](#createparameteraccessor)|Aloca memória para as estruturas de ligação de parâmetro e inicializa os membros de dados de parâmetro.|

## <a name="remarks"></a>Comentários

Usando `CManualAccessor`, você pode especificar o parâmetro e a associação de coluna de saída por chamadas de função em tempo de execução.

## <a name="cmanualaccessoraddbindentry"></a><a name="addbindentry"></a>CManualAccessor::AddBindEntry

Adiciona uma entrada de associação às colunas de saída.

### <a name="syntax"></a>Sintaxe

```cpp
void AddBindEntry(DBORDINAL nOrdinal,
   DBTYPE wType,  DBLENGTH nColumnSize,
   void* pData,
   void* pLength = NULL,
   void* pStatus = NULL) throw ();
```

#### <a name="parameters"></a>parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador de OLE DB*.

*nOrdinal*<br/>
no Número da coluna.

*wType*<br/>
no Tipo de dados.

*nColumnSize*<br/>
no Tamanho da coluna em bytes.

*pData*<br/>
no Um ponteiro para os dados de coluna armazenados no buffer.

*pLength*<br/>
no Um ponteiro para o tamanho do campo, se necessário.

*pStatus*<br/>
no Um ponteiro para a variável a ser associada ao status da coluna, se necessário.

### <a name="remarks"></a>Comentários

Para usar essa função, você deve primeiro chamar [Createaccesser](../../data/oledb/cmanualaccessor-createaccessor.md). Não é possível adicionar mais entradas do que o número de colunas especificado em `CreateAccessor`.

## <a name="cmanualaccessoraddparameterentry"></a><a name="addparameterentry"></a>CManualAccessor::AddParameterEntry

Adiciona uma entrada de parâmetro às estruturas de entrada de parâmetro.

### <a name="syntax"></a>Sintaxe

```cpp
void AddParameterEntry(DBORDINAL nOrdinal,
   DBTYPE wType,  DBLENGTH nColumnSize,
   void* pData,
   void* pLength = NULL,
   void* pStatus = NULL,
   DBPARAMIO eParamIO = DBPARAMIO_INPUT) throw ();
```

#### <a name="parameters"></a>parâmetros

Consulte [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador de OLE DB*.

*nOrdinal*<br/>
no Número do parâmetro.

*wType*<br/>
no Tipo de dados.

*nColumnSize*<br/>
no Tamanho da coluna em bytes.

*pData*<br/>
no Um ponteiro para os dados de coluna armazenados no buffer.

*pLength*<br/>
no Um ponteiro para o tamanho do campo, se necessário.

*pStatus*<br/>
no Um ponteiro para a variável a ser associada ao status da coluna, se necessário.

*eParamIO*<br/>
no Especifica se o parâmetro com o qual a associação está associada é um parâmetro de entrada, entrada/saída ou saída.

### <a name="remarks"></a>Comentários

Para usar essa função, primeiro você deve chamar [CreateParameterAccessor](../../data/oledb/cmanualaccessor-createparameteraccessor.md).

## <a name="cmanualaccessorcreateaccessor"></a><a name="createaccessor"></a>CManualAccessor:: createaccesser

Aloca memória para as estruturas de associação de coluna e inicializa os membros de dados de coluna.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CreateAccessor(int nBindEntries,
  void* pBuffer,
   DBLENGTH nBufferSize) throw();
```

#### <a name="parameters"></a>parâmetros

*nBindEntries*<br/>
no Número de colunas. Esse número deve corresponder ao número de chamadas para a função [CManualAccessor:: AddBindEntry](../../data/oledb/cmanualaccessor-addbindentry.md) .

*pBuffer*<br/>
no Um ponteiro para o buffer onde as colunas de saída são armazenadas.

*nBufferSize*<br/>
no O tamanho do buffer em bytes.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Chame essa função antes de chamar a função `CManualAccessor::AddBindEntry`.

## <a name="cmanualaccessorcreateparameteraccessor"></a><a name="createparameteraccessor"></a>CManualAccessor::CreateParameterAccessor

Aloca memória para as estruturas de ligação de parâmetro e inicializa os membros de dados de parâmetro.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CreateParameterAccessor(int nBindEntries,
   void* pBuffer,
   DBLENGTH nBufferSize) throw();
```

#### <a name="parameters"></a>parâmetros

*nBindEntries*<br/>
no Número de colunas.

*pBuffer*<br/>
no Um ponteiro para o buffer em que as colunas de entrada são armazenadas.

*nBufferSize*<br/>
no O tamanho do buffer em bytes.

### <a name="return-value"></a>Valor retornado

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Você deve chamar essa função antes de chamar [AddParameterEntry](../../data/oledb/cmanualaccessor-addparameterentry.md).

## <a name="see-also"></a>Confira também

[DBViewer](../../overview/visual-cpp-samples.md)<br/>
[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência de modelos de consumidor do OLE DB](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessor](../../data/oledb/caccessor-class.md)<br/>
[Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)<br/>
[Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)
