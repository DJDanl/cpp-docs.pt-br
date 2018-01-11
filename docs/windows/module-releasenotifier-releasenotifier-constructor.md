---
title: Construtor Module::ReleaseNotifier::ReleaseNotifier | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords: module/Microsoft::WRL::Module::ReleaseNotifier::ReleaseNotifier
dev_langs: C++
helpviewer_keywords: ReleaseNotifier, constructor
ms.assetid: 889a3c9a-2366-44a1-ba7d-a59c1885e7f3
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 81d4f136fc9982b7260ce08d3fca4e9037f60c22
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="modulereleasenotifierreleasenotifier-constructor"></a>Construtor Module::ReleaseNotifier::ReleaseNotifier
Inicializa uma nova instância da classe releasenotifier.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
ReleaseNotifier(bool release) throw();  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `release`  
 `true`Excluir esta instância quando o método Release é chamado; `false` não excluir esta instância.  
  
## <a name="exceptions"></a>Exceções  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** module.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe Module::ReleaseNotifier](../windows/module-releasenotifier-class.md)