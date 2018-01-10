---
title: "Método: getactivationfactory | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::Module::GetActivationFactory
dev_langs: C++
helpviewer_keywords: GetActivationFactory method
ms.assetid: 59da8844-072e-414b-b89c-1db1cc4fd81d
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5d5c5ca4d470f52ff9dde862cc99b10a3459cd0c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="modulegetactivationfactory-method"></a>Método Module::GetActivationFactory
Obtém um alocador de ativação para o módulo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
WRL_NOTHROW HRESULT GetActivationFactory(  
   _In_ HSTRING pActivatibleClassId,  
   _Deref_out_ IActivationFactory **ppIFactory,  
   wchar_t* serverName = nullptr  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pActivatibleClassId`  
 IID de uma classe de tempo de execução.  
  
 `ppIFactory`  
 IActivationFactory para a classe de tempo de execução especificado.  
  
 `serverName`  
 O nome de um subconjunto de fábricas de classe no módulo atual. Especifique o nome do servidor usado no [ActivatableClassWithFactoryEx](../windows/activatableclass-macros.md) macro, ou especificar `nullptr` para obter o nome do servidor padrão.  
  
## <a name="return-value"></a>Valor de retorno  
 S_OK se bem-sucedido; Caso contrário, o HRESULT retornado pelo GetActivationFactory.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
[Classe de módulo](../windows/module-class.md) [ActivatableClass Macros](../windows/activatableclass-macros.md)