---
title: "Método: registercomobject | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::Module::RegisterCOMObject
dev_langs: C++
helpviewer_keywords: RegisterCOMObject method
ms.assetid: 59f223dc-03c6-429d-95da-b74b3f73b702
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: a2984d5950464385ea47301db356b7364707e667
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="moduleregistercomobject-method"></a>Método Module::RegisterCOMObject
Registra um ou mais objetos para que outros aplicativos possam se conectar a eles.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW virtual HRESULT RegisterCOMObject(  
   const wchar_t* serverName,  
   IID* clsids,  
   IClassFactory** factories,  
   DWORD* cookies,  
   unsigned int count);  
  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `serverName`  
 Nome totalmente qualificado de um servidor.  
  
 `clsids`  
 Uma matriz de CLSIDs para registrar.  
  
 `factories`  
 Uma matriz de interfaces de IUnknown dos objetos de classe cuja disponibilidade está sendo publicada.  
  
 `cookies`  
 Quando a operação for concluída, uma matriz de ponteiros para valores que identificam a classe de objetos que foram registrados. Esses valores são usados mais tarde revogar o registro.  
  
 `count`  
 O número de CLSIDs para registrar.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT como CO_E_OBJISREG que indica o motivo da falha da operação.  
  
## <a name="remarks"></a>Comentários  
 Os objetos COM estão registrados com o enumerador CLSCTX_LOCAL_SERVER da enumeração CLSCTX.  
  
 O tipo de conexão para os objetos registrados é especificado por uma combinação de atual `comflag` parâmetro do modelo e o enumerador REGCLS_SUSPENDED da enumeração REGCLS.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe Module](../windows/module-class.md)