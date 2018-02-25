---
title: CRowset::Update | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CRowset.Update
- ATL.CRowset.Update
- ATL.CRowset<TAccessor>.Update
- ATL::CRowset<TAccessor>::Update
- CRowset<TAccessor>::Update
- CRowset::Update
- CRowset<TAccessor>.Update
- ATL::CRowset::Update
dev_langs:
- C++
helpviewer_keywords:
- Update method
ms.assetid: cd5fedc8-2b85-4cb8-8c40-c79576316903
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 5b9acbe5df9d0ccf1a1798f19e41ea9fd1cc0ada
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="crowsetupdate"></a>CRowset::Update
Transmite todas as alterações feitas na linha atual desde a última busca pendentes ou **atualização** chamar nela.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT Update(DBCOUNTITEM* pcRows = NULL,   
   HROW* phRow = NULL,   
   DBROWSTATUS* pStatus = NULL) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pcRows`  
 [out] Um ponteiro para o local onde **atualizar** retorna o número de linhas que ele tentou atualizar, se necessário.  
  
 `phRow`  
 [out] Um ponteiro para o local onde **atualizar** retorna o identificador da linha tentou atualizar. Nenhum identificador é retornado se `phRow` é nulo.  
  
 `pStatus`  
 [out] Um ponteiro para o local onde **atualização** retorna o valor de status de linha. Nenhum status será retornado se `pStatus` é nulo.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Transmite todas as alterações feitas na linha atual desde que a linha última foi buscada ou atualizada pendentes (usando **atualização** ou [UpdateAll](../../data/oledb/crowset-updateall.md)). Normalmente você chama [SetData](../../data/oledb/crowset-setdata.md) para definir valores de dados em colunas em uma linha e, em seguida, chamar **atualização** para transmitir as alterações.  
  
 Esse método requer que a interface opcional `IRowsetUpdate`, que talvez não tenha suporte em todos os provedores; se esse for o caso, o método retornará **E_NOINTERFACE**. Você também deve definir **DBPROP_IRowsetUpdate** para `VARIANT_TRUE` antes de chamar **abrir** na tabela ou que contém o conjunto de linhas de comando.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowset](../../data/oledb/crowset-class.md)   
 [IRowsetUpdate::Update](https://msdn.microsoft.com/en-us/library/ms719709.aspx)   
 [CRowset::UpdateAll](../../data/oledb/crowset-updateall.md)   
 [CRowset::SetData](../../data/oledb/crowset-setdata.md)