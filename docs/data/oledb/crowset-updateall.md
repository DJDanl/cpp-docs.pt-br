---
title: CRowset::UpdateAll | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- CRowset::UpdateAll
- ATL.CRowset.UpdateAll
- CRowset<TAccessor>.UpdateAll
- ATL.CRowset<TAccessor>.UpdateAll
- UpdateAll
- CRowset.UpdateAll
- ATL::CRowset<TAccessor>::UpdateAll
- CRowset<TAccessor>::UpdateAll
- ATL::CRowset::UpdateAll
dev_langs:
- C++
helpviewer_keywords:
- UpdateAll method
ms.assetid: e5b26c0a-40fc-4c91-a293-5084951788e6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: d9e21cd34a4d758becb12b529fe858e96d18f187
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33092185"
---
# <a name="crowsetupdateall"></a>CRowset::UpdateAll
Transmite todas as alterações feitas a todas as linhas desde a última busca pendentes ou **atualização** chamar nela.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT UpdateAll(DBCOUNTITEM* pcRows = NULL,   
   HROW** pphRow = NULL,   
   DBROWSTATUS** ppStatus = NULL) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pcRows`  
 [out] Um ponteiro para o local onde `UpdateAll` retorna o número de linhas que ele tentou atualizar, se necessário.  
  
 `pphRow`  
 [out] Um ponteiro de memória no qual `UpdateAll` retorna o identificador da linha tentou atualizar. Nenhum identificador é retornado se `pphRow` é nulo.  
  
 `ppStatus`  
 [out] Um ponteiro para o local onde **atualização** retorna o valor de status de linha. Nenhum status será retornado se `ppStatus` é nulo.  
  
## <a name="remarks"></a>Comentários  
 Transmite todas as alterações feitas a todas as linhas, desde que essas linhas buscadas última ou atualizados usando pendentes [atualização](../../data/oledb/crowset-update.md) ou `UpdateAll`. `UpdateAll` atualizará todas as linhas que foram modificadas, independentemente se você ainda tem o identificador para eles (consulte `pphRow`) ou não.  
  
 Por exemplo, se você usou **inserir** para inserir cinco linhas em um conjunto de linhas, você poderia chamar **atualizar** cinco vezes ou chamada `UpdateAll` uma vez para atualizar todos eles.  
  
 Esse método requer que a interface opcional `IRowsetUpdate`, que talvez não tenha suporte em todos os provedores; se esse for o caso, o método retornará **E_NOINTERFACE**. Você também deve definir **DBPROP_IRowsetUpdate** para `VARIANT_TRUE` antes de chamar **abrir** na tabela ou que contém o conjunto de linhas de comando.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CRowset](../../data/oledb/crowset-class.md)   
 [IRowsetUpdate::Update](https://msdn.microsoft.com/en-us/library/ms719709.aspx)   
 [CRowset::SetData](../../data/oledb/crowset-setdata.md)   
 [CRowset::Update](../../data/oledb/crowset-update.md)