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
- AddBindEntry
- CManualAccessor.AddBindEntry
- CManualAccessor::AddParameterEntry
- ATL.CManualAccessor.AddParameterEntry
- CManualAccessor.AddParameterEntry
- AddParameterEntry
- ATL::CManualAccessor::AddParameterEntry
- ATL::CManualAccessor::CreateAccessor
- CreateAccessor
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
ms.openlocfilehash: 526415f14172911b26462fab97d9e0a7513b8cad
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59027604"
---
# <a name="cmanualaccessor-class"></a>Classe CManualAccessor

Representa um tipo de acessador projetado para uso avançado.

## <a name="syntax"></a>Sintaxe

```cpp
class CManualAccessor : public CAccessorBase
```

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atldbcli.h

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[AddBindEntry](#addbindentry)|Adiciona uma entrada de associação para as colunas de saída.|
|[AddParameterEntry](#addparameterentry)|Adiciona uma entrada de parâmetro para o acessador de parâmetro.|
|[CreateAccessor](#createaccessor)|Aloca memória para a coluna de estruturas de associação e inicializa os membros de dados de coluna.|
|[CreateParameterAccessor](#createparameteraccessor)|Aloca memória para o parâmetro de estruturas de associação e inicializa os membros de dados do parâmetro.|

## <a name="remarks"></a>Comentários

Usando `CManualAccessor`, você pode especificar o parâmetro e associação de coluna de saída por chamadas de função de tempo de execução.

## <a name="addbindentry"></a> Cmanualaccessor:: Addbindentry

Adiciona uma entrada de associação para as colunas de saída.

### <a name="syntax"></a>Sintaxe

```cpp
void AddBindEntry(DBORDINAL nOrdinal,
   DBTYPE wType,  DBLENGTH nColumnSize,
   void* pData,
   void* pLength = NULL,
   void* pStatus = NULL) throw ();
```

#### <a name="parameters"></a>Parâmetros

Ver [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador do OLE DB*.

*nOrdinal*<br/>
[in] Número da coluna.

*wType*<br/>
[in] Tipo de dados.

*nColumnSize*<br/>
[in] Tamanho de coluna em bytes.

*pData*<br/>
[in] Um ponteiro para os dados da coluna armazenados no buffer.

*pLength*<br/>
[in] Um ponteiro para o tamanho do campo, se necessário.

*pStatus*<br/>
[in] Um ponteiro para a variável a ser associado para o status da coluna, se necessário.

### <a name="remarks"></a>Comentários

Para usar essa função, você deve primeiro chamar [CreateAccessor](../../data/oledb/cmanualaccessor-createaccessor.md). Não é possível adicionar mais entradas do que o número de colunas especificado em `CreateAccessor`.

## <a name="addparameterentry"></a> CManualAccessor::AddParameterEntry

Adiciona uma entrada de parâmetro para as estruturas de entrada de parâmetro.

### <a name="syntax"></a>Sintaxe

```cpp
void AddParameterEntry(DBORDINAL nOrdinal,
   DBTYPE wType,  DBLENGTH nColumnSize,
   void* pData,
   void* pLength = NULL,
   void* pStatus = NULL,
   DBPARAMIO eParamIO = DBPARAMIO_INPUT) throw ();
```

#### <a name="parameters"></a>Parâmetros

Ver [DBBINDING](/previous-versions/windows/desktop/ms716845(v=vs.85)) na *referência do programador do OLE DB*.

*nOrdinal*<br/>
[in] Número do parâmetro.

*wType*<br/>
[in] Tipo de dados.

*nColumnSize*<br/>
[in] Tamanho de coluna em bytes.

*pData*<br/>
[in] Um ponteiro para os dados da coluna armazenados no buffer.

*pLength*<br/>
[in] Um ponteiro para o tamanho do campo, se necessário.

*pStatus*<br/>
[in] Um ponteiro para a variável a ser associado para o status da coluna, se necessário.

*eParamIO*<br/>
[in] Especifica se o parâmetro ao qual a associação está associada é um parâmetro de entrada, entrada/saída ou saído.

### <a name="remarks"></a>Comentários

Para usar essa função, você deve primeiro chamar [CreateParameterAccessor](../../data/oledb/cmanualaccessor-createparameteraccessor.md).

## <a name="createaccessor"></a> Cmanualaccessor:: CreateAccessor

Aloca memória para a coluna de estruturas de associação e inicializa os membros de dados de coluna.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CreateAccessor(int nBindEntries,
  void* pBuffer,
   DBLENGTH nBufferSize) throw();
```

#### <a name="parameters"></a>Parâmetros

*nBindEntries*<br/>
[in] Número de colunas. Esse número deve corresponder ao número de chamadas para o [cmanualaccessor:: Addbindentry](../../data/oledb/cmanualaccessor-addbindentry.md) função.

*pBuffer*<br/>
[in] Um ponteiro para o buffer no qual as colunas de saída são armazenadas.

*nBufferSize*<br/>
[in] O tamanho do buffer em bytes.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Chame essa função antes de chamar o `CManualAccessor::AddBindEntry` função.

## <a name="createparameteraccessor"></a> Cmanualaccessor:: Createparameteraccessor

Aloca memória para o parâmetro de estruturas de associação e inicializa os membros de dados do parâmetro.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT CreateParameterAccessor(int nBindEntries,
   void* pBuffer,
   DBLENGTH nBufferSize) throw();
```

#### <a name="parameters"></a>Parâmetros

*nBindEntries*<br/>
[in] Número de colunas.

*pBuffer*<br/>
[in] Um ponteiro para o buffer no qual as colunas de entrada são armazenadas.

*nBufferSize*<br/>
[in] O tamanho do buffer em bytes.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Você deve chamar essa função antes de chamar [AddParameterEntry](../../data/oledb/cmanualaccessor-addparameterentry.md).

## <a name="see-also"></a>Consulte também

[DBViewer](../../overview/visual-cpp-samples.md)<br/>
[Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)<br/>
[Referência dos modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-reference.md)<br/>
[Classe CAccessor](../../data/oledb/caccessor-class.md)<br/>
[Classe CDynamicAccessor](../../data/oledb/cdynamicaccessor-class.md)<br/>
[Classe CDynamicParameterAccessor](../../data/oledb/cdynamicparameteraccessor-class.md)