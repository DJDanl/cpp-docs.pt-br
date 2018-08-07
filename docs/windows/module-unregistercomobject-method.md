---
title: 'Método Module:: unregistercomobject | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::UnregisterCOMObject
dev_langs:
- C++
helpviewer_keywords:
- UnregisterCOMObject method
ms.assetid: 5d377525-0385-482a-a215-6e8a1f032861
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: c19e7b5388438b8c3c2359672360e4a2ee3001a3
ms.sourcegitcommit: 4586bfc32d8bc37ab08b24816d7fad5df709bfa3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/07/2018
ms.locfileid: "39602624"
---
# <a name="moduleunregistercomobject-method"></a>Método Module::UnregisterCOMObject
Cancela o registro de um ou mais objetos COM, que impede que outros aplicativos se conectem a eles.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
virtual HRESULT UnregisterCOMObject(  
   const wchar_t* serverName,  
   DWORD* cookies,  
   unsigned int count  
```  
  
### <a name="parameters"></a>Parâmetros  
 *ServerName*  
 (Não usado)  
  
 *Cookies*  
 Uma matriz de ponteiros para valores que identificam os objetos de classe para cancelar o registro. A matriz foi criada por meio de [RegisterCOMObject](../windows/module-registercomobject-method.md) método.  
  
 *count*  
 O número de classes para cancelar o registro.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se essa operação for bem-sucedida; Caso contrário, um erro HRESULT que indica o motivo pelo qual a operação falhou.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL
 
 ## <a name="see-also"></a>Consulte também
 [Classe Module](../windows/module-class.md)