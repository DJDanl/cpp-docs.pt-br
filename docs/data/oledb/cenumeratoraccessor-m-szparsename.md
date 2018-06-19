---
title: CEnumeratorAccessor::m_szParseName | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CEnumeratorAccessor::m_szParseName
- ATL::CEnumeratorAccessor::m_szParseName
- m_szParseName
- CEnumeratorAccessor.m_szParseName
- ATL.CEnumeratorAccessor.m_szParseName
dev_langs:
- C++
helpviewer_keywords:
- m_szParseName
ms.assetid: 32e826b6-0890-4db4-aa92-fc1ea3f528b2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 9b10c5b3dcc09cba0d0e424c962f02fefe12a633
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33096240"
---
# <a name="cenumeratoraccessormszparsename"></a>CEnumeratorAccessor::m_szParseName
Cadeia de caracteres para passar para [IParseDisplayName](http://msdn.microsoft.com/library/windows/desktop/ms680604) para obter um identificador de origem para a fonte de dados ou o enumerador.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
WCHAR m_szParseName[129];  
  
```  
  
## <a name="remarks"></a>Comentários  
 Consulte [ISourcesRowset:: Getsourcesrowset](https://msdn.microsoft.com/en-us/library/ms711200.aspx) no *referência do programador de DB OLE* para obter mais informações.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CEnumeratorAccessor](../../data/oledb/cenumeratoraccessor-class.md)