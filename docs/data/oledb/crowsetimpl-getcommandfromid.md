---
title: 'Crowsetimpl:: Getcommandfromid | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CRowsetImpl::GetCommandFromID
- GetCommandFromID
- CRowsetImpl.GetCommandFromID
dev_langs:
- C++
helpviewer_keywords:
- GetCommandFromID method
ms.assetid: 9f39cb07-1c40-486f-ba5b-cb4a65fab8a7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: f79e9287bf8d546ba5007257899a6b6ddc27ad40
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33091288"
---
# <a name="crowsetimplgetcommandfromid"></a>CRowsetImpl::GetCommandFromID
Verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres e, em caso afirmativo, copia os valores de cadeia de caracteres para os membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT CRowsetBaseImpl::GetCommandFromID(DBID* pTableID,  
   DBID* pIndexID);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pTableID`  
 [in] Um ponteiro para o **DBID** que representa a ID da tabela.  
  
 `pIndexID`  
 [in] Um ponteiro para o **DBID** que representa a ID de índice.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Este método é chamado por meio de uma elevação estática por `CRowsetImpl` para preencher os membros de dados [m_strCommandText](../../data/oledb/crowsetimpl-m-strcommandtext.md) e [m_strIndexText](../../data/oledb/crowsetimpl-m-strindextext.md). Por padrão, esse método verifica se um ou ambos os parâmetros contêm valores de cadeia de caracteres. Se eles contêm valores de cadeia de caracteres, esse método copia os valores de cadeia de caracteres para os membros de dados. Colocando um método com essa assinatura em seu `CRowsetImpl`-derivado da classe, o método será chamado em vez da implementação base.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowsetImpl](../../data/oledb/crowsetimpl-class.md)   
 [CRowsetImpl::SetCommandText](../../data/oledb/crowsetimpl-setcommandtext.md)