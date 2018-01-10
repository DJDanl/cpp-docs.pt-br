---
title: "Método: GetClassObject | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::Module::GetClassObject
dev_langs: C++
helpviewer_keywords: GetClassObject method
ms.assetid: 95b0de1b-f728-4f96-9f44-f6ea71ce56e4
caps.latest.revision: "5"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 3f234b46da1a70ee0256a9a38ebb2ef7ae0bb5bb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="modulegetclassobject-method"></a>Método Module::GetClassObject
Recupera um cache de fábricas de classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
 HRESULT GetClassObject(  
   REFCLSID clsid,  
   REFIID riid,  
   _Deref_out_ void **ppv,  
   wchar_t* serverName = nullptr  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `clsid`  
 ID de classe.  
  
 `riid`  
 ID de interface que você solicitar.  
  
 `ppv`  
 Ponteiro para o objeto retornado.  
  
 `serverName`  
 O nome do servidor especificado no `ActivatableClassWithFactory`, `ActivatableClassWithFactoryEx`, ou `ActivatableClass` macro; ou `nullptr` para obter o nome do servidor padrão.  
  
## <a name="return-value"></a>Valor de retorno  
  
## <a name="remarks"></a>Comentários  
 Use este método somente para COM, não o tempo de execução do Windows. Esse método expõe métodos de IClassFactory somente.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl
 
 ## <a name="see-also"></a>Consulte também
 [Classe Module](../windows/module-class.md)