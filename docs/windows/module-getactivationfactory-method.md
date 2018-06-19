---
title: 'Método: getactivationfactory | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::GetActivationFactory
dev_langs:
- C++
helpviewer_keywords:
- GetActivationFactory method
ms.assetid: 59da8844-072e-414b-b89c-1db1cc4fd81d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 837cb68173ca1994de6bc560882d617bb3aa03e0
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33887007"
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
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
[Classe de módulo](../windows/module-class.md) [ActivatableClass Macros](../windows/activatableclass-macros.md)