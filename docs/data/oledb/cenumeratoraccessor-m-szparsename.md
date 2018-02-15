---
title: CEnumeratorAccessor::m_szParseName | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5089ff7531c349afc8a8f7991cfcb0ff97c4bd52
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
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