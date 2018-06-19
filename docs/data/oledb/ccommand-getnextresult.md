---
title: 'Ccommand:: Getnextresult | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: d833c3e644ac6ed44216542ce4fc6d995cc22efa
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33094189"
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