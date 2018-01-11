---
title: 'Crowsetimpl:: Getcolumninfo | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- GetColumnInfo
- CRowsetImpl.GetColumnInfo
- CRowsetImpl::GetColumnInfo
dev_langs: C++
helpviewer_keywords: GetColumnInfo method
ms.assetid: 9ef76525-f996-4c6f-81b9-68eb260350ef
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: acfc7e4afa0036c6f6e66aaef65305fc05ef6d14
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="crowsetimplgetcolumninfo"></a>CRowsetImpl::GetColumnInfo
Recupera informações de coluna para uma solicitação de cliente específico.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      static ATLCOLUMNINFO* CRowsetBaseImpl::GetColumnInfo(  
   T* pv,  
   ULONG* pcCols   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pv`  
 [in] Um ponteiro para o usuário `CRowsetImpl` classe derivada.  
  
 `pcCols`  
 [in] Um ponteiro (saída) para o número de colunas retornadas.  
  
## <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um static **ATLCOLUMNINFO** estrutura.  
  
## <a name="remarks"></a>Comentários  
 Esse método é uma substituição avançada.  
  
 Este método é chamado por várias classes de implementação de base para recuperar informações de coluna para uma solicitação de cliente específico. Normalmente, esse método será chamado `IColumnsInfoImpl`. Se você substituir esse método, você deve colocar uma versão do método na sua `CRowsetImpl`-classe derivada. Como o método pode ser colocado em uma classe não-transformado em modelo, você deve alterar `pv` ao apropriado `CRowsetImpl`-classe derivada.  
  
 O exemplo a seguir demonstra **do GetColumnInfo** uso. Neste exemplo, **CMyRowset** é um `CRowsetImpl`-classe derivada. Para substituir `GetColumnInfo` para todas as instâncias dessa classe, coloque o seguinte método no **CMyRowset** definição da classe:  
  
 [!code-cpp[NVC_OLEDB_Provider#1](../../data/oledb/codesnippet/cpp/crowsetimpl-getcolumninfo_1.h)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowsetImpl](../../data/oledb/crowsetimpl-class.md)