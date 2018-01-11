---
title: Classe IDBSchemaRowsetImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: IDBSchemaRowsetImpl
dev_langs: C++
helpviewer_keywords: IDBSchemaRowsetImpl class
ms.assetid: bd7bf0d7-a1c6-4afa-88e3-cfdbdf560703
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6b4f451fa408f2f6470281206e5de3670d069b6c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="idbschemarowsetimpl-class"></a>Classe IDBSchemaRowsetImpl
Fornece a implementação para conjuntos de linhas de esquema.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <class SessionClass>  
class ATL_NO_VTABLE IDBSchemaRowsetImpl : public IDBSchemaRowset  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `SessionClass`  
 A classe pelo qual `IDBSchemaRowsetImpl` é herdada. Normalmente, essa classe será classe da sessão do usuário.  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[CheckRestrictions](../../data/oledb/idbschemarowsetimpl-checkrestrictions.md)|Verifica a validade de restrições em relação a um conjunto de linhas de esquema.|  
|[CreateSchemaRowset](../../data/oledb/idbschemarowsetimpl-createschemarowset.md)|Implementa uma função de criador do objeto COM para o objeto especificado pelo parâmetro de modelo.|  
|[SetRestrictions](../../data/oledb/idbschemarowsetimpl-setrestrictions.md)|Especifica as restrições de suporte em um conjunto de linhas de esquema específico.|  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetRowset](../../data/oledb/idbschemarowsetimpl-getrowset.md)|Retorna um conjunto de linhas de esquema.|  
|[GetSchemas](../../data/oledb/idbschemarowsetimpl-getschemas.md)|Retorna uma lista de conjuntos de linhas de esquema acessível por [idbschemarowsetimpl:: Getrowset](../../data/oledb/idbschemarowsetimpl-getrowset.md).|  
  
## <a name="remarks"></a>Comentários  
 Essa classe implementa o [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) interface e a função de modelo criador [CreateSchemaRowset](../../data/oledb/idbschemarowsetimpl-createschemarowset.md).  
  
 OLE DB usa conjuntos de linhas de esquema para retornar dados sobre os dados em um provedor. Esses dados é geralmente chamados de "metadados". Por padrão, um provedor deve oferecer suporte sempre `DBSCHEMA_TABLES`, **DBSCHEMA_COLUMNS**, e **DBSCHEMA_PROVIDER_TYPES**, conforme descrito em [IDBSchemaRowset](https://msdn.microsoft.com/en-us/library/ms713686.aspx) no  *Referência do programador de OLE DB*. Conjuntos de linhas de esquema são designados em um mapa de esquema. Para obter informações sobre as entradas de mapa de esquema, consulte [SCHEMA_ENTRY](../../data/oledb/schema-entry.md).  
  
 O OLE DB Provider assistente, no Assistente de objeto ATL, gera automaticamente código para os conjuntos de linhas de esquema em seu projeto. (Por padrão, o assistente dá suporte a conjuntos de linhas de esquema obrigatório mencionados anteriormente.) Quando você cria um consumidor usando o Assistente de objeto ATL, o assistente usa conjuntos de linhas de esquema para associar os dados corretos para um provedor. Se você não implementar seus conjuntos de linhas de esquema para fornecer os metadados corretos, o assistente não associará os dados corretos.  
  
 Para obter informações sobre como dar suporte a conjuntos de linhas de esquema no provedor, consulte [dando suporte a conjuntos de linhas de esquema](../../data/oledb/supporting-schema-rowsets.md).  
  
 Para obter mais informações sobre conjuntos de linhas de esquema, consulte [conjuntos de linhas de esquema](https://msdn.microsoft.com/en-us/library/ms712921.aspx) no *referência do programador de DB OLE*.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Membros de classe IDBSchemaRowsetImpl](http://msdn.microsoft.com/en-us/e74f6f82-541c-42e7-b4c6-e2d4656a0649)   
 [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)   
 [Dando suporte a conjuntos de linhas do esquema](../../data/oledb/supporting-schema-rowsets.md)