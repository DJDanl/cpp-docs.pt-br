---
title: 'Classe Platform:: delegate | Microsoft Docs'
ms.custom: 
ms.date: 12/30/2016
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: VCCORLIB/Platform::Delegate
dev_langs: C++
helpviewer_keywords: Platform::Delegate Class
ms.assetid: 82b21271-768f-4193-9ca2-be68ddfd546e
caps.latest.revision: "5"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 661e96cd2455610e6a7f669928d49c915b7d7575
ms.sourcegitcommit: 6f40bba1772a09ff0e3843d5f70b553e1a15ab50
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2018
---
# <a name="platformdelegate-class"></a>Classe Platform::Delegate
Representa um objeto de função.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
public delegate void delegate_name();  
```  
  
### <a name="members"></a>Membros  
 A classe Delegate possui os métodos Equals(), GetHashCode() e ToString() derivados do [Platform::Object Class](../cppcx/platform-object-class.md).  
  
### <a name="remarks"></a>Comentários  
 Use a palavra-chave [delegate](../windows/delegate-cpp-component-extensions.md) para criar delegados; não use Platform::Delegate explicitamente. Para obter mais informações, consulte [Delegados](../cppcx/delegates-c-cx.md). Para obter um exemplo de como criar e consumir um delegado, consulte [Criando componentes do tempo de execução do Windows em C++](/windows/uwp/winrt-components/creating-windows-runtime-components-in-cpp).  
  
### <a name="requirements"></a>Requisitos  
 **Suporte mínimo de cliente:** Windows 8  
  
 **Suporte mínimo de servidor:** Windows Server 2012  
  
 **Namespace:** Platform  
  
 **Metadados:** platform.winmd  
  
## <a name="see-also"></a>Consulte também  
 [Namespace de plataforma](../cppcx/platform-namespace-c-cx.md)