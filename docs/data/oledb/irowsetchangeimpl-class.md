---
title: Classe IRowsetChangeImpl
ms.date: 11/04/2016
f1_keywords:
- ATL::IRowsetChangeImpl
- IRowsetChangeImpl
- ATL.IRowsetChangeImpl
- ATL.IRowsetChangeImpl.DeleteRows
- ATL::IRowsetChangeImpl::DeleteRows
- IRowsetChangeImpl.DeleteRows
- DeleteRows
- IRowsetChangeImpl::DeleteRows
- ATL.IRowsetChangeImpl.InsertRow
- InsertRow
- IRowsetChangeImpl.InsertRow
- ATL::IRowsetChangeImpl::InsertRow
- IRowsetChangeImpl::InsertRow
- IRowsetChangeImpl::SetData
- ATL.IRowsetChangeImpl.SetData
- IRowsetChangeImpl.SetData
- ATL::IRowsetChangeImpl::SetData
- IRowsetChangeImpl::FlushData
- IRowsetChangeImpl.FlushData
- FlushData
helpviewer_keywords:
- providers, updatable
- updatable providers, immediate update
- IRowsetChangeImpl class
- DeleteRows method
- InsertRow method
- SetData method
- FlushData method
ms.assetid: 1e9fee15-ed9e-4387-af8f-215569beca6c
ms.openlocfilehash: 66e7b758752a46fffff177323fe83eecc0b2fa55
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832773"
---
# <a name="irowsetchangeimpl-class"></a>Classe IRowsetChangeImpl

A implementação de modelos de OLE DB da interface [IRowsetChange](/previous-versions/windows/desktop/ms715790(v=vs.85)) na especificação OLE DB.

## <a name="syntax"></a>Sintaxe

```cpp
template <
   class T,
   class Storage,
   class BaseInterface = IRowsetChange,
   class RowClass = CSimpleRow,
   class MapClass = CAtlMap <RowClass::KeyType, RowClass*>>
class ATL_NO_VTABLE IRowsetChangeImpl : public BaseInterface
```

### <a name="parameters"></a>parâmetros

*T*<br/>
Uma classe derivada de `IRowsetChangeImpl` .

*Storage*<br/>
O registro do usuário.

*BaseInterface*<br/>
A classe base para a interface, como `IRowsetChange` .

*Classe de categoria*<br/>
A unidade de armazenamento para o identificador de linha.

*MapClass*<br/>
A unidade de armazenamento para todos os identificadores de linha mantidos pelo provedor.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** Atldb. h

## <a name="members"></a>Membros

### <a name="interface-methods-used-with-irowsetchange"></a>Métodos de interface (usados com IRowsetChange)

| Nome | Descrição |
|-|-|
|[DeleteRows](#deleterows)|Exclui linhas do conjunto de linhas.|
|[InsertRow](#insertrow)|Insere uma linha no conjunto de linhas.|
|[SetData](#setdata)|Define valores de dados em uma ou mais colunas.|

### <a name="implementation-method-callback"></a>Método de implementação (retorno de chamada)

| Nome | Descrição |
|-|-|
|[FlushData](#flushdata)|Substituído pelo provedor para confirmar dados para seu armazenamento.|

## <a name="remarks"></a>Comentários

Essa interface é responsável por operações de gravação imediata em um armazenamento de dados. "Immediate" significa que, quando o usuário final (a pessoa que usa o consumidor) faz alterações, essas alterações são transmitidas imediatamente para o armazenamento de dados (e não podem ser desfeitas).

`IRowsetChangeImpl` implementa a `IRowsetChange` interface OLE DB, que permite a atualização de valores de colunas em linhas existentes, exclusão de linhas e inserção de novas linhas.

A implementação de modelos de OLE DB dá suporte a todos os métodos base ( `SetData` , `InsertRow` e `DeleteRows` ).

> [!IMPORTANT]
> É altamente recomendável que você leia a seguinte documentação antes de tentar implementar seu provedor:

- [Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)

- Capítulo 6 da *referência do programador de OLE DB*

- Veja também como a `RUpdateRowset` classe é usada no exemplo [UpdatePV](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Provider/UPDATEPV) .

## <a name="irowsetchangeimpldeleterows"></a><a name="deleterows"></a> IRowsetChangeImpl::D eleteRows

Exclui linhas do conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (DeleteRows )(HCHAPTER /* hReserved */,
   DBCOUNTITEM cRows,
   const HROW rghRows[],
   DBROWSTATUS rgRowStatus[]);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetChange::D eleterows](/previous-versions/windows/desktop/ms724362(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetchangeimplinsertrow"></a><a name="insertrow"></a> IRowsetChangeImpl:: InsertRow

Cria e Inicializa uma nova linha no conjunto de linhas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (InsertRow )(HCHAPTER /* hReserved */,
   HACCESSOR hAccessor,
   void* pData,
   HROW* phRow);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetChange:: InsertRow](/previous-versions/windows/desktop/ms716921(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetchangeimplsetdata"></a><a name="setdata"></a> IRowsetChangeImpl:: SetData

Define valores de dados em uma ou mais colunas.

### <a name="syntax"></a>Sintaxe

```cpp
STDMETHOD (SetData )(HROW hRow,
   HACCESSOR hAccessor,
   void* pSrcData);
```

#### <a name="parameters"></a>parâmetros

Consulte [IRowsetChange:: SetData](/previous-versions/windows/desktop/ms721232(v=vs.85)) na *referência do programador de OLE DB*.

## <a name="irowsetchangeimplflushdata"></a><a name="flushdata"></a> IRowsetChangeImpl:: FlushData

Substituído pelo provedor para confirmar dados para seu armazenamento.

### <a name="syntax"></a>Sintaxe

```cpp
HRESULT FlushData(HROW hRowToFlush,
   HACCESSOR hAccessorToFlush);
```

#### <a name="parameters"></a>parâmetros

*hRowToFlush*<br/>
no Identificador para as linhas dos dados. O tipo dessa linha é determinado a partir do argumento de modelo da *classe* rowgroup da `IRowsetImpl` classe ( `CSimpleRow` por padrão).

*hAccessorToFlush*<br/>
no Identificador para o acessador, que contém informações de associação e informações de tipo em seu `PROVIDER_MAP` (consulte [IAccessorImpl](../../data/oledb/iaccessorimpl-class.md)).

### <a name="return-value"></a>Valor Retornado

Um HRESULT padrão.

## <a name="see-also"></a>Confira também

[Modelos de Provedor OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo de provedor de OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)
