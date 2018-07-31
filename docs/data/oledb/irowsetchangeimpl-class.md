---
title: Classe IRowsetChangeImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
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
- SetData
- IRowsetChangeImpl::SetData
- ATL.IRowsetChangeImpl.SetData
- IRowsetChangeImpl.SetData
- ATL::IRowsetChangeImpl::SetData
- IRowsetChangeImpl::FlushData
- IRowsetChangeImpl.FlushData
- FlushData
dev_langs:
- C++
helpviewer_keywords:
- providers, updatable
- updatable providers, immediate update
- IRowsetChangeImpl class
- DeleteRows method
- InsertRow method
- SetData method
- FlushData method
ms.assetid: 1e9fee15-ed9e-4387-af8f-215569beca6c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 0f77f9a33b0cf51ea54d16f89e86ea914640f627
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39339592"
---
# <a name="irowsetchangeimpl-class"></a>Classe IRowsetChangeImpl
A implementação de modelos OLE DB do [IRowsetChange](https://msdn.microsoft.com/library/ms715790.aspx) interface na especificação do OLE DB.  
  
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
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Uma classe derivada de `IRowsetChangeImpl`.  
  
 *Armazenamento*  
 O registro do usuário.  
  
 *BaseInterface*  
 A classe base para a interface, tais como `IRowsetChange`.  
  
 *RowClass*  
 A unidade de armazenamento para o identificador de linha.  
  
 *MapClass*  
 A unidade de armazenamento para todos os identificadores de linha mantidos pelo provedor.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods-used-with-irowsetchange"></a>Métodos de interface (usados com IRowsetChange)  
  
|||  
|-|-|  
|[DeleteRows](#deleterows)|Exclui linhas do conjunto de linhas.|  
|[InsertRow](#insertrow)|Insere uma linha no conjunto de linhas.|  
|[SetData](#setdata)|Define valores de dados em uma ou mais colunas.|  
  
### <a name="implementation-method-callback"></a>Método de implementação (retorno de chamada)  
  
|||  
|-|-|  
|[FlushData](#flushdata)|Ponto pelo provedor para confirmar dados para seu repositório.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface é responsável por operações de gravação de imediato para um armazenamento de dados. "Imediatas" significa que quando o usuário final (a pessoa que usa o consumidor) faz qualquer alteração, essas alterações são transmitidas imediatamente para os dados armazena (e não pode ser desfeita).  
  
 `IRowsetChangeImpl` implementa o OLE DB `IRowsetChange` interface, que permite atualização dos valores das colunas em linhas existentes, a exclusão de linhas e inserindo novas linhas.  
  
 A implementação de modelos OLE DB dá suporte a todos os métodos de base (`SetData`, `InsertRow`, e `DeleteRows`).  
  
> [!IMPORTANT]
>  É altamente recomendável que você leia a documentação a seguir antes de tentar implementar seu provedor:  
  
-   [Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)  
  
-   Capítulo 6 a *referência do programador do OLE DB*  
  
-   Consulte também como o `RUpdateRowset` classe é usada no exemplo UpdatePV  
  
## <a name="deleterows"></a> Irowsetchangeimpl:: DeleteRows
Exclui linhas do conjunto de linhas.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD (DeleteRows )(HCHAPTER /* hReserved */,  
   DBCOUNTITEM cRows,  
   const HROW rghRows[],  
   DBROWSTATUS rgRowStatus[]);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IRowsetChange:: DeleteRows](https://msdn.microsoft.com/library/ms724362.aspx) na *referência do programador do OLE DB*. 

## <a name="insertrow"></a> Irowsetchangeimpl:: Insertrow
Cria e inicializa uma nova linha no conjunto de linhas.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD (InsertRow )(HCHAPTER /* hReserved */,  
   HACCESSOR hAccessor,  
   void* pData,  
   HROW* phRow);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IRowsetChange:: Insertrow](https://msdn.microsoft.com/library/ms716921.aspx) na *referência do programador do OLE DB*. 

## <a name="setdata"></a> Irowsetchangeimpl:: SetData
Define valores de dados em uma ou mais colunas.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD (SetData )(HROW hRow,  
   HACCESSOR hAccessor,  
   void* pSrcData);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IRowsetChange:: SetData](https://msdn.microsoft.com/library/ms721232.aspx) na *referência do programador do OLE DB*. 

## <a name="flushdata"></a> Irowsetchangeimpl:: Flushdata
Ponto pelo provedor para confirmar dados para seu repositório.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT FlushData(HROW hRowToFlush,  
   HACCESSOR hAccessorToFlush);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *hRowToFlush*  
 [in] Identificador para as linhas de dados. O tipo dessa linha é determinado a partir de *RowClass* argumento de modelo da `IRowsetImpl` classe (`CSimpleRow` por padrão).  
  
 *hAccessorToFlush*  
 [in] Identificador para o acessador, que contém informações de associação e informações de tipo em seu `PROVIDER_MAP` (consulte [IAccessorImpl](../../data/oledb/iaccessorimpl-class.md)).  
  
### <a name="return-value"></a>Valor de retorno  
 Um HRESULT padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)