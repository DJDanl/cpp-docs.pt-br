---
title: 'Método Module:: registercomobject | Microsoft Docs'
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
ms.openlocfilehash: 8c997b4221dee913a6eaad55f6f114b0ad9d820e
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39606534"
---
# <a name="moduleregistercomobject-method"></a>Método Module::RegisterCOMObject
Registra os objetos COM um ou mais para que outros aplicativos podem se conectar a eles.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW virtual HRESULT RegisterCOMObject(  
   const wchar_t* serverName,  
   IID* clsids,  
   IClassFactory** factories,  
   DWORD* cookies,  
   unsigned int count);  
  
```  
  
### <a name="parameters"></a>Parâmetros  
 *ServerName*  
 Nome totalmente qualificado de um servidor.  
  
 *CLSIDs*  
 Uma matriz de CLSIDs para registrar.  
  
 *fábricas*  
 Uma matriz de interfaces IUnknown dos objetos de classe cuja disponibilidade está sendo publicada.  
  
 *Cookies*  
 Quando a operação for concluída, uma matriz de ponteiros para valores que identificam a classe de objetos que foram registrados. Esses valores são usados mais tarde revoga o registro.  
  
 *count*  
 O número de CLSIDs para registrar.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT como CO_E_OBJISREG que indica o motivo pelo qual a operação falhou.  
  
## <a name="remarks"></a>Comentários  
 Os objetos COM são registrados com o enumerador CLSCTX_LOCAL_SERVER da enumeração CLSCTX.  
  
 O tipo de conexão para os objetos registrados é especificado por uma combinação do atual *comflag* parâmetro de modelo e o enumerador REGCLS_SUSPENDED da enumeração REGCLS.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe Module](../windows/module-class.md)