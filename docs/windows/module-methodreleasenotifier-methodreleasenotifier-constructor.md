---
title: Construtor Module::MethodReleaseNotifier::MethodReleaseNotifier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::MethodReleaseNotifier::MethodReleaseNotifier
dev_langs:
- C++
helpviewer_keywords:
- MethodReleaseNotifier, constructor
ms.assetid: 762e2ca4-0a92-49de-9ff5-d3efa0f067c0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 91540ca3fff03f1f0a449413c2d1ca72781c70f1
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33875221"
---
# <a name="modulemethodreleasenotifiermethodreleasenotifier-constructor"></a>Construtor Module::MethodReleaseNotifier::MethodReleaseNotifier
Inicializa uma nova instância da classe methodreleasenotifier.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
MethodReleaseNotifier(  
   _In_ T* object,   
   _In_ void (T::* method)(),   
   bool release) throw() :  
            ReleaseNotifier(release), object_(object),   
            method_(method);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `object`  
 Um objeto cuja função de membro é um manipulador de eventos.  
  
 `method`  
 A função de membro do parâmetro `object` que é o manipulador de eventos.  
  
 `release`  
 Especifique `true` para habilitar a chamada subjacente [Module:: ReleaseNotifier::Release()](../windows/module-releasenotifier-release.md) método; caso contrário, especifique `false`.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe Module::MethodReleaseNotifier](../windows/module-methodreleasenotifier-class.md)