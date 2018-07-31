---
title: Classe IConvertTypeImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ATL.IConvertTypeImpl<T>
- IConvertTypeImpl
- ATL.IConvertTypeImpl
- ATL::IConvertTypeImpl
- ATL::IConvertTypeImpl<T>
- IConvertTypeImpl.CanConvert
- CanConvert
- IConvertTypeImpl::CanConvert
dev_langs:
- C++
helpviewer_keywords:
- IConvertTypeImpl class
- CanConvert method
ms.assetid: 7f81e79e-7d3f-4cbe-b93c-d632a94b15f6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 57ad4c5e9f119a7c9904376db4f77c35de4290f2
ms.sourcegitcommit: 889a75be1232817150be1e0e8d4d7f48f5993af2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/30/2018
ms.locfileid: "39337122"
---
# <a name="iconverttypeimpl-class"></a>Classe IConvertTypeImpl
Fornece uma implementação de [IConvertType](https://msdn.microsoft.com/library/ms715926.aspx) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T>  
class ATL_NO_VTABLE IConvertTypeImpl   
   : public IConvertType, public CConvertHelper  
```  
  
### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de `IConvertTypeImpl`.  

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="members"></a>Membros  
  
### <a name="interface-methods"></a>Métodos de interface  
  
|||  
|-|-|  
|[CanConvert](#canconvert)|Fornece informações sobre a disponibilidade de conversões de tipo em um comando ou em um conjunto de linhas.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface é obrigatória em comandos, conjuntos de linhas e conjuntos de linhas do índice. `IConvertTypeImpl` implementa a interface delegando para o objeto de conversão fornecido pelo OLE DB.  

## <a name="canconvert"></a> Iconverttypeimpl:: Canconvert
Fornece informações sobre a disponibilidade de conversões de tipo em um comando ou em um conjunto de linhas.  
  
### <a name="syntax"></a>Sintaxe  
  
```cpp
STDMETHOD(CanConvert)(DBTYPE wFromType,   
   DBTYPE wToType,   
   DBCONVERTFLAGS dwConvertFlags);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Ver [IConvertType::CanConvert](https://msdn.microsoft.com/library/ms711224.aspx) na *referência do programador do OLE DB*.  
  
### <a name="remarks"></a>Comentários  
 Usa a conversão de dados OLE DB em `MSADC.DLL`.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)   
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)