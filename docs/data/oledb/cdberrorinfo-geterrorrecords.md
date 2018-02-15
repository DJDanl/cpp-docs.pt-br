---
title: CDBErrorInfo::GetErrorRecords | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- CDBErrorInfo.GetErrorRecords
- ATL.CDBErrorInfo.GetErrorRecords
- ATL::CDBErrorInfo::GetErrorRecords
- GetErrorRecords
- CDBErrorInfo::GetErrorRecords
dev_langs:
- C++
helpviewer_keywords:
- GetErrorRecords method
ms.assetid: 07746774-bcca-4833-8f55-a619e9777c17
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a904eba0ae45186715fd8f7071d06db309c0a24c
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="cdberrorinfogeterrorrecords"></a>CDBErrorInfo::GetErrorRecords
Obtém os registros de erro para o objeto especificado.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp
HRESULT GetErrorRecords(IUnknown* pUnk,   
   const IID& iid,   
   ULONG* pcRecords) throw();  


HRESULT GetErrorRecords(ULONG* pcRecords) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *pUnk*  
 [in] Interface para o objeto para o qual obter os registros de erro.  
  
 `iid`  
 [in] O IID da interface associada ao erro.  
  
 *pcRecords*  
 [out] Um ponteiro para a contagem (base um) dos registros de erro.  
  
## <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT`.  
  
## <a name="remarks"></a>Comentários  
 Use o primeiro formulário da função se você deseja verificar qual interface para obter as informações de erro. Caso contrário, use o segundo formulário.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDBErrorInfo](../../data/oledb/cdberrorinfo-class.md)