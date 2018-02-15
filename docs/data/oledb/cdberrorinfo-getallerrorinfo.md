---
title: CDBErrorInfo::GetAllErrorInfo | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- ATL.CDBErrorInfo.GetAllErrorInfo
- CDBErrorInfo::GetAllErrorInfo
- ATL::CDBErrorInfo::GetAllErrorInfo
- GetAllErrorInfo
- CDBErrorInfo.GetAllErrorInfo
dev_langs:
- C++
helpviewer_keywords:
- GetAllErrorInfo method
ms.assetid: 630049fa-d296-497a-bbf6-f5d3d71d271d
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 90086d0760e477ef41c4d6b59505ff90115f964b
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="cdberrorinfogetallerrorinfo"></a>CDBErrorInfo::GetAllErrorInfo
Retorna todos os tipos de informações de erro contidas em um registro de erro.  
  
## <a name="syntax"></a>Sintaxe  
  
```
HRESULT GetAllErrorInfo(ULONG ulRecordNum,  
   LCID lcid,  BSTR* pbstrDescription,  
   BSTR* pbstrSource = NULL,  
   GUID* pguid = NULL,  
   DWORD* pdwHelpContext = NULL,  
   BSTR* pbstrHelpFile = NULL) const throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *ulRecordNum*  
 [in] O número com base em zero do registro para o qual retornar informações de erro.  
  
 `lcid`  
 [in] A ID de localidade para as informações de erro a ser retornado.  
  
 `pbstrDescription`  
 [out] Um ponteiro para uma descrição de texto do erro ou nulo se não há suporte para a localidade. Consulte Observações.  
  
 `pbstrSource`  
 [out] Um ponteiro para uma cadeia de caracteres que contém o nome do componente que gerou o erro.  
  
 `pguid`  
 [out] Um ponteiro para o GUID da interface que definiu o erro.  
  
 *pdwHelpContext*  
 [out] Um ponteiro para a ID do contexto de ajuda para o erro.  
  
 *pbstrHelpFile*  
 [out] Um ponteiro para uma cadeia de caracteres que contém o caminho para o arquivo de Ajuda que descreve o erro.  
  
## <a name="return-value"></a>Valor de retorno  
 `S_OK` se bem-sucedido. Consulte [IErrorRecords::GetErrorInfo](https://msdn.microsoft.com/en-us/library/ms711230.aspx) no *referência do programador de DB OLE* para outros valores de retorno.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="remarks"></a>Comentários  
 O valor de saída `pbstrDescription` obtido internamente pela chamada IErrorInfo:: GetDescription, que define o valor como NULL se não há suporte para a localidade, ou se ambas as seguintes condições forem verdadeiras:  
  
1.  o valor de `lcid` não é dos EUA Inglês e  
  
2.  o valor de `lcid` é não é igual ao valor retornado por GetUserDefaultLCID.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDBErrorInfo](../../data/oledb/cdberrorinfo-class.md)