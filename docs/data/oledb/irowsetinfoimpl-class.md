---
title: Classe IRowsetInfoImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.IRowsetInfoImpl
- IRowsetInfoImpl
- ATL::IRowsetInfoImpl
dev_langs:
- C++
helpviewer_keywords:
- IRowsetInfoImpl class
ms.assetid: 9c654155-7727-464e-bd31-143e68391a47
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f9b784dbb13ff39be21ccd353d514dd244d5ae41
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33106213"
---
# <a name="irowsetinfoimpl-class"></a>Classe IRowsetInfoImpl
Fornece uma implementação para o [IRowsetInfo](https://msdn.microsoft.com/en-us/library/ms724541.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T, class PropClass = T>  
class ATL_NO_VTABLE IRowsetInfoImpl :   
   public IRowsetInfo,    
   public CUtlProps<PropClass>  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `IRowsetInfoImpl`.  
  
 `PropClass`  
 Uma classe de propriedade definidos pelo usuário cujo padrão é `T`.  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[GetProperties](../../data/oledb/irowsetinfoimpl-getproperties.md)|Retorna as configurações atuais de todas as propriedades compatíveis com o conjunto de linhas.|  
|[GetReferencedRowset](../../data/oledb/irowsetinfoimpl-getreferencedrowset.md)|Retorna um ponteiro de interface para o conjunto de linhas ao qual se aplica a um indicador.|  
|[GetSpecification](../../data/oledb/irowsetinfoimpl-getspecification.md)|Retorna um ponteiro de interface no objeto (comando ou sessão) que criou esse conjunto de linhas.|  
  
## <a name="remarks"></a>Comentários  
 Uma interface obrigatória em conjuntos de linhas. Essa classe implementa as propriedades do conjunto de linhas usando o [mapa de conjunto de propriedade](../../data/oledb/begin-propset-map.md) definido em sua classe de comando. Embora a classe de conjunto de linhas é exibida usando a propriedade de classe do comando define, o conjunto de linhas é fornecido com sua própria cópia das propriedades do tempo de execução, quando ele é criado por um objeto de comando ou sessão.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** altdb.h  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)