---
title: 'Cenumerator:: Find | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CEnumerator::Find
- ATL::CEnumerator::Find
- ATL.CEnumerator.Find
- CEnumerator.Find
dev_langs:
- C++
helpviewer_keywords:
- Find method
ms.assetid: 69a153af-d6c3-40fd-9018-27c7d2f344c6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 2466127dab53fa6646a4f149400e4318aed59970
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33094476"
---
# <a name="cenumeratorfind"></a>CEnumerator::Find
Procura um nome especificado entre os provedores disponíveis.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      bool Find(TCHAR* szSearchName) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *szSearchName*  
 [in] O nome a ser pesquisado.  
  
## <a name="return-value"></a>Valor de retorno  
 **True** se o nome foi encontrado. Caso contrário, **false**.  
  
## <a name="remarks"></a>Comentários  
 Esse nome é mapeado para o **SOURCES_NAME** membro o [ISourcesRowset da](https://msdn.microsoft.com/en-us/library/ms715969.aspx) interface.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CEnumerator](../../data/oledb/cenumerator-class.md)