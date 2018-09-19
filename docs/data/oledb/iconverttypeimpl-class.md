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
ms.openlocfilehash: ed4eefe8c05e2b5b027ba1d7c1fec022c9e44409
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46104914"
---
# <a name="iconverttypeimpl-class"></a>Classe IConvertTypeImpl

Fornece uma implementação de [IConvertType](/previous-versions/windows/desktop/ms715926\(v=vs.85\)) interface.  
  
## <a name="syntax"></a>Sintaxe

```cpp
template <class T>  
class ATL_NO_VTABLE IConvertTypeImpl   
   : public IConvertType, public CConvertHelper  
```  
  
### <a name="parameters"></a>Parâmetros  

*T*<br/>
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

Ver [IConvertType::CanConvert](/previous-versions/windows/desktop/ms711224\(v=vs.85\)) na *referência do programador do OLE DB*.  
  
### <a name="remarks"></a>Comentários  

Usa a conversão de dados OLE DB em `MSADC.DLL`.  
  
## <a name="see-also"></a>Consulte também  

[Modelos de provedor do OLE DB](../../data/oledb/ole-db-provider-templates-cpp.md)<br/>
[Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)