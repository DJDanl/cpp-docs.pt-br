---
title: Classe IRowsetChangeImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL::IRowsetChangeImpl
- IRowsetChangeImpl
- ATL.IRowsetChangeImpl
dev_langs: C++
helpviewer_keywords:
- providers, updatable
- updatable providers, immediate update
- IRowsetChangeImpl class
ms.assetid: 1e9fee15-ed9e-4387-af8f-215569beca6c
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4ff5057bed4f6f74511355f4675dd2bc69ad5262
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="irowsetchangeimpl-class"></a>Classe IRowsetChangeImpl
A implementação de modelos OLE DB do [IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715790.aspx) interface na especificação do OLE DB.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <  
   class T,   
   class Storage,   
   class BaseInterface = IRowsetChange,   
   class RowClass = CSimpleRow,   
   class MapClass = CAtlMap < RowClass::KeyType, RowClass* >   
>  
class ATL_NO_VTABLE IRowsetChangeImpl : public BaseInterface  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Uma classe derivada de `IRowsetChangeImpl`.  
  
 `Storage`  
 O registro do usuário.  
  
 `BaseInterface`  
 A classe base para a interface, como `IRowsetChange`.  
  
 `RowClass`  
 A unidade de armazenamento para o identificador de linha.  
  
 `MapClass`  
 A unidade de armazenamento para todos os identificadores de linha mantidos pelo provedor.  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods-used-with-irowsetchange"></a>Métodos de interface (usados com IRowsetChange)  
  
|||  
|-|-|  
|[DeleteRows](../../data/oledb/irowsetchangeimpl-deleterows.md)|Exclui linhas do conjunto de linhas.|  
|[InsertRow](../../data/oledb/irowsetchangeimpl-insertrow.md)|Insere uma linha no conjunto de linhas.|  
|[SetData](../../data/oledb/irowsetchangeimpl-setdata.md)|Define valores de dados em uma ou mais colunas.|  
  
### <a name="implementation-method-callback"></a>Método de implementação (retorno de chamada)  
  
|||  
|-|-|  
|[FlushData](../../data/oledb/irowsetchangeimpl-flushdata.md)|Overidden pelo provedor para confirmar seu repositório de dados.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface é responsável pelas operações de gravação imediata para um repositório de dados. "Imediata" significa que quando o usuário final (pessoa usando o consumidor) faz as alterações, essas alterações são transmitidas imediatamente para os dados armazena (e não pode ser desfeita).  
  
 `IRowsetChangeImpl`implementa o OLE DB `IRowsetChange` interface, que permite atualização de valores de colunas em linhas existentes, excluindo linhas e inserir novas linhas.  
  
 A implementação de modelos OLE DB dá suporte a todos os métodos de base (`SetData`, `InsertRow`, e `DeleteRows`).  
  
> [!IMPORTANT]
>  É altamente recomendável que você leia a documentação a seguir antes de tentar implementar seu provedor:  
  
-   [Criando um provedor atualizável](../../data/oledb/creating-an-updatable-provider.md)  
  
-   Capítulo 6 a *referência do programador de OLE DB*  
  
-   Consulte também como o `RUpdateRowset` classe é usada no exemplo UpdatePV  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)