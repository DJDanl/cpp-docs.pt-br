---
title: Construtor Module::GenericReleaseNotifier::GenericReleaseNotifier | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- module/Microsoft::WRL::Module::GenericReleaseNotifier::GenericReleaseNotifier
dev_langs:
- C++
helpviewer_keywords:
- GenericReleaseNotifier, constructor
ms.assetid: feb5b687-a4b0-4809-9022-8f292181b7a1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5aa78562c934c41b2ff2ab7b381f6b2612426651
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40014582"
---
# <a name="modulegenericreleasenotifiergenericreleasenotifier-constructor"></a>Construtor Module::GenericReleaseNotifier::GenericReleaseNotifier
Inicializa uma nova instância dos **genericreleasenotifier** classe.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
GenericReleaseNotifier(  
   T callback,   
   bool release  
) throw() : ReleaseNotifier(release), callback_(callback);  
```  
  
### <a name="parameters"></a>Parâmetros  
 *retorno de chamada*  
 Um lambda, functor ou manipulador de eventos de ponteiro para função que pode ser chamado com o operador de parênteses (`()`).  
  
 *release*  
 Especificar **verdadeira** para habilitar a chamada subjacente [Module:: ReleaseNotifier::Release()](../windows/module-releasenotifier-release.md) método; caso contrário, especifique **false**.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe Module::GenericReleaseNotifier](../windows/module-genericreleasenotifier-class.md)