---
title: 'Método: registercomobject | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::RegisterCOMObject
dev_langs:
- C++
helpviewer_keywords:
- RegisterCOMObject method
ms.assetid: 59f223dc-03c6-429d-95da-b74b3f73b702
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c002dd64049006c8ee74c709c585a3a9d0f253a5
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33873973"
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
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe Module](../windows/module-class.md)