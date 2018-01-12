---
title: Classe IRowsetInfoImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.IRowsetInfoImpl
- IRowsetInfoImpl
- ATL::IRowsetInfoImpl
dev_langs: C++
helpviewer_keywords: IRowsetInfoImpl class
ms.assetid: 9c654155-7727-464e-bd31-143e68391a47
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: cba03cfdda0b7a55c8f4719d5340566ee5dc6050
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="irowsetinfoimpl-class"></a>Classe IRowsetInfoImpl
Fornece uma implementação para o [IRowsetInfo](https://msdn.microsoft.com/en-us/library/ms724541.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
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