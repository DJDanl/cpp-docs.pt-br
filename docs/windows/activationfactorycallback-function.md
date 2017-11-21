---
title: "Função ActivationFactoryCallback | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::Details::ActivationFactoryCallback
dev_langs: C++
helpviewer_keywords: ActivationFactoryCallback function
ms.assetid: dd40c79b-1273-4f2a-8c24-ae9926fb4fd9
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: adf41c8a518b0ca57326da1dd71c1a8ddd6f0a27
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="activationfactorycallback-function"></a>Função ActivationFactoryCallback
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
inline HRESULT STDAPICALLTYPE ActivationFactoryCallback(  
   HSTRING activationId,  
   IActivationFactory **ppFactory  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `activationId`  
 Identificador para uma cadeia de caracteres que especifica um nome de classe de tempo de execução.  
  
 `ppFactory`  
 Quando essa operação for concluída, um alocador de ativação que corresponde ao parâmetro `activationId`.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT que descreve a falha. Falha provável HRESULTs são CLASS_E_CLASSNOTAVAILABLE e E_INVALIDARG.  
  
## <a name="remarks"></a>Comentários  
 Obtém o alocador de ativação para a ID de ativação especificado.  
  
 O tempo de execução do Windows chama essa função de retorno de chamada para solicitar um objeto especificado por seu nome de classe de tempo de execução.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)