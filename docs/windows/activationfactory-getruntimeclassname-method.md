---
title: 'Método activationfactory:: Getruntimeclassname | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::ActivationFactory::GetRuntimeClassName
dev_langs:
- C++
helpviewer_keywords:
- GetRuntimeClassName method
ms.assetid: 74e34f0a-9c51-4b40-89f5-45c6c5886ece
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: edc4658ebf0519ef9d1792d62b303f423e658835
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39643063"
---
# <a name="activationfactorygetruntimeclassname-method"></a>Método ActivationFactory::GetRuntimeClassName
Obtém o nome de classe de tempo de execução do objeto que o atual **ActivationFactory** cria uma instância.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
STDMETHOD(  
   GetRuntimeClassName  
)(_Out_ HSTRING* runtimeName);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *runtimeName*  
 Quando essa operação for concluída, um identificador para uma cadeia de caracteres que contém o nome de classe de tempo de execução do objeto que o atual **ActivationFactory** cria uma instância.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, um HRESULT que descreve a falha.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe ActivationFactory](../windows/activationfactory-class.md)