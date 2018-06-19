---
title: Classes de seções críticas (ATL) e modelos de Threading | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
f1_keywords:
- vc.atl.threads.models
dev_langs:
- C++
helpviewer_keywords:
- ATL, critical sections
- ATL, multithreading
- threading [ATL], models
- critical sections
ms.assetid: 759f05ef-6285-4be6-a2cc-78572dd75146
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 37172c0080664f496bdf5d5c7c0ebecbd8f77898
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32359912"
---
# <a name="threading-models-and-critical-sections-classes"></a>Classes de seções críticas e modelos de Threading
As seguintes classes que definem um threading modelo e seção crítica:  
  
-   [CAtlAutoThreadModule](../atl/reference/catlautothreadmodule-class.md) implementa um servidor de pool de thread, o modelo de apartment COM.  
  
-   [CAtlAutoThreadModuleT](../atl/reference/catlautothreadmodulet-class.md) fornece métodos para a implementação de um servidor de pool de thread, o modelo de apartment COM.  
  
-   [CComMultiThreadModel](../atl/reference/ccommultithreadmodel-class.md) fornece métodos de thread-safe para incrementar e decrementar uma variável. Fornece uma seção crítica.  
  
-   [CComMultiThreadModelNoCS](../atl/reference/ccommultithreadmodelnocs-class.md) fornece métodos de thread-safe para incrementar e decrementar uma variável. Não fornece uma seção crítica.  
  
-   [CComSingleThreadModel](../atl/reference/ccomsinglethreadmodel-class.md) fornece métodos para incrementar e decrementar uma variável. Não fornece uma seção crítica.  
  
-   [CComObjectThreadModel](../atl/reference/atl-typedefs.md#ccomobjectthreadmodel) determina a classe de modelo de threading apropriada para uma classe de objeto único.  
  
-   [CComGlobalsThreadModel](../atl/reference/atl-typedefs.md#ccomglobalsthreadmodel) determina a classe de modelo de threading apropriada para um objeto que está disponível globalmente.  
  
-   [CComAutoCriticalSection](../atl/reference/ccomautocriticalsection-class.md) contém métodos para a obtenção e liberar uma seção crítica. Seção crítica é inicializada automaticamente.  
  
-   [CComCriticalSection](../atl/reference/ccomcriticalsection-class.md) contém métodos para a obtenção e liberar uma seção crítica. Seção crítica deve ser explicitamente inicializada.  
  
-   [CComFakeCriticalSection](../atl/reference/ccomfakecriticalsection-class.md) espelha os métodos em `CComCriticalSection` sem fornecer uma seção crítica. Os métodos em `CComFakeCriticalSection` não fazer nada.  
  
-   [CRTThreadTraits](../atl/reference/crtthreadtraits-class.md) fornece a função de criação de um thread do CRT. Use essa classe se o thread de usar funções de CRT.  
  
-   [Win32ThreadTraits](../atl/reference/win32threadtraits-class.md) fornece a função de criação de um thread do Windows. Use essa classe se o thread não usará as funções de CRT.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../atl/atl-class-overview.md)

