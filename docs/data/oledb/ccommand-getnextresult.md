---
title: CCommand::GetNextResult | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CCommand::GetNextResult
- CCommand::GetNextResult
- GetNextResult
- CCommand.GetNextResult
- ATL.CCommand.GetNextResult
dev_langs:
- C++
helpviewer_keywords:
- GetNextResult method
ms.assetid: 63df9b55-9490-45c4-934a-879c5c2725d8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: fa77785373545b2c4efd2faef0a8c0a02ee26910
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ccommandgetnextresult"></a>CCommand::GetNextResult
Busca o próximo conjunto de resultados se estiver disponível.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetNextResult(DBROWCOUNT* pulRowsAffected,  
   bool bBind = true) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pulRowsAffected*  
 [entrada/saída] Um ponteiro de memória em que a contagem de linhas afetadas por um comando é retornada.  
  
 `bBind`  
 [in] Especifica se deve associar o comando automaticamente depois que está sendo executada. O padrão é **true**, que faz com que o comando a ser associado automaticamente. Configuração `bBind` para **false** impede que a associação automática do comando de modo que você pode vincular manualmente. (Associação manual é de especial interesse para os usuários OLAP).  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Se um conjunto de resultados foi buscado anteriormente, essa função libera o conjunto de resultados anterior e desvincula as colunas. Se `bBind` é **true**, ele associa as novas colunas.  
  
 Você deve chamar essa função somente se você tiver especificado vários resultados, definindo a `CCommand` parâmetro de modelo *TMultiple*=`CMultipleResults`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCommand](../../data/oledb/ccommand-class.md)