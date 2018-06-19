---
title: IConvertTypeImpl::CanConvert | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- IConvertTypeImpl.CanConvert
- CanConvert
- IConvertTypeImpl::CanConvert
dev_langs:
- C++
helpviewer_keywords:
- CanConvert method
ms.assetid: bdad6e95-bc0b-4427-9b5e-eea51f09f392
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a2f7e32fd01c932f24b617951d601ddcfe7fb5af
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33099882"
---
# <a name="iconverttypeimplcanconvert"></a>IConvertTypeImpl::CanConvert
Fornece informações sobre a disponibilidade de conversões de tipo em um comando ou em um conjunto de linhas.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      STDMETHOD(CanConvert)(DBTYPE wFromType,   
   DBTYPE wToType,   
   DBCONVERTFLAGS dwConvertFlags);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 Consulte [IConvertType::CanConvert](https://msdn.microsoft.com/en-us/library/ms711224.aspx) no *referência do programador de OLE DB*.  
  
## <a name="remarks"></a>Comentários  
 Usa a conversão de dados OLE DB em `MSADC.DLL`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe IConvertTypeImpl](../../data/oledb/iconverttypeimpl-class.md)