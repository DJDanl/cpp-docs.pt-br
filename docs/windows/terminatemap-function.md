---
title: Função TerminateMap | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Details::TerminateMap
dev_langs:
- C++
helpviewer_keywords:
- TerminateMap function
ms.assetid: 1c314a61-da5d-49bb-ac44-c34ee3c23b66
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b4787fec0a6b4b9f55c500b66786372945d9a523
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33890343"
---
# <a name="terminatemap-function"></a>Função TerminateMap
Oferece suporte à infraestrutura WRL e não se destina a ser usado diretamente no seu código.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
inline bool TerminateMap(  
   _In_ ModuleBase *module,   
   _In_opt_z_ const wchar_t *serverName,   
    bool forceTerminate) throw()  
```  
  
## <a name="parameters"></a>Parâmetros  
 `module`  
 Um [módulo](../windows/module-class.md).  
  
 `serverName`  
 O nome de um subconjunto de fábricas de classe no módulo especificado pelo parâmetro `module`.  
  
 `forceTerminate`  
 `true` Para encerrar a classe fábricas independentemente de eles estão ativas; `false` não encerrar as fábricas de classe se qualquer fábrica estiver ativa.  
  
## <a name="return-value"></a>Valor de retorno  
 `true` Se todas as fábricas de classe foram finalizadas. Caso contrário, `false`.  
  
## <a name="remarks"></a>Comentários  
 Desliga as fábricas de classe no módulo especificado.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## <a name="see-also"></a>Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)