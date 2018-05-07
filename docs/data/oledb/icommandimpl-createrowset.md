---
title: 'Icommandimpl:: Createrowset | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
f1_keywords:
- ICommandImpl::CreateRowset
- ICommandImpl.CreateRowset
- CreateRowset
dev_langs:
- C++
helpviewer_keywords:
- CreateRowset method
ms.assetid: a0890009-205e-4970-879f-01ed9d6a93f1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6909f8f6825aacf55c000bfd87e0282365180559
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="icommandimplcreaterowset"></a>ICommandImpl::CreateRowset
Chamado pelo [Execute](../../data/oledb/icommandimpl-execute.md) para criar um único conjunto de linhas.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
      template template <class RowsetClass  
      >  
HRESULT CreateRowset(IUnknown* pUnkOuter,  
   REFIID riid,  
   DBPARAMS* pParams,  
   DBROWCOUNT* pcRowsAffected,  
   IUnknown** ppRowset,  
   RowsetClass*& pRowsetObj);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `RowsetClass`  
 Um membro de classe de modelo que representa a classe do usuário. Geralmente, gerado pelo assistente.  
  
 `pUnkOuter`  
 [in] Um ponteiro para o controle **IUnknown** interface se o conjunto de linhas estiver sendo criado como parte de uma agregação; caso contrário, será nulo.  
  
 `riid`  
 [in] Corresponde à `riid` em `ICommand::Execute`.  
  
 `pParams`  
 [entrada/saída] Corresponde à `pParams` em `ICommand::Execute`.  
  
 `pcRowsAffected`  
 Corresponde à `pcRowsAffected` em `ICommand::Execute`.  
  
 `ppRowset`  
 [entrada/saída] Corresponde à `ppRowset` em `ICommand::Execute`.  
  
 `pRowsetObj`  
 [out] Um ponteiro para um objeto de conjunto de linhas. Normalmente, esse parâmetro não for usado, mas ele pode ser usado se você deve executar o trabalho mais no conjunto de linhas antes de passá-lo para um objeto COM. O tempo de vida de `pRowsetObj` estiver associado ao `ppRowset`.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor. Consulte `ICommand::Execute` para obter uma lista de valores típicos.  
  
## <a name="remarks"></a>Comentários  
 Para criar mais de um conjunto de linhas, ou para fornecer suas próprias condições para a criação de diferentes conjuntos de linhas, fazer chamadas diferentes para `CreateRowset` na **Execute**.  
  
 Consulte [ICommand:: execute](https://msdn.microsoft.com/en-us/library/ms718095.aspx) no *referência do programador de OLE DB.*  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldb.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe ICommandImpl](../../data/oledb/icommandimpl-class.md)