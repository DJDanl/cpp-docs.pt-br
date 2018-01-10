---
title: ATL e livre de threads Marshaler | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- ATL, free threaded marshaler
- free threaded marshaler
- threading [C++], marshaler in ATL
- threading [ATL], free threaded marshaler
- FTM in ATL
ms.assetid: 2db88a13-2217-4ebc-aa7e-432d5da902eb
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 02b8586d7df5a521b48bfce61a097ed6ca450196
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="atl-and-the-free-threaded-marshaler"></a>ATL e marshaler livre de threads
Página de atributos do ATL simples objeto Assistente fornece uma opção que permite que a classe de agregação marshaler livre de threads (FTM).  
  
 O assistente gera código para criar uma instância do marshaler livre de threads no `FinalConstruct` e liberar a instância em `FinalRelease`. Um `COM_INTERFACE_ENTRY_AGGREGATE` macro é automaticamente adicionada ao mapa de COM para garantir que `QueryInterface` as solicitações de [IMarshal](http://msdn.microsoft.com/library/windows/desktop/dd542707) são manipuladas pelo marshaler livre de threads.  
  
 O marshaler de threads livres permite acesso direto a interfaces em seu objeto de qualquer thread no mesmo processo, acelerando a chamadas entre apartment. Essa opção destina-se de usar o modelo de threading ambas as classes.  
  
 Ao usar essa opção, classes devem assumir a responsabilidade para a thread de segurança de seus dados. Além disso, os objetos que o marshaler de threads livres de agregação e precisam usar ponteiros de interface obtidos a partir de outros objetos devem realizar etapas adicionais para garantir que as interfaces são empacotadas corretamente. Normalmente, isso envolve armazenar os ponteiros de interface na tabela de interface global (GIT) e obter o ponteiro do GIT cada vez que ele é usado. ATL fornece a classe [CComGITPtr](../atl/reference/ccomgitptr-class.md) para ajudá-lo a usar ponteiros de interface armazenados no GIT.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos](../atl/active-template-library-atl-concepts.md)   
 [CoCreateFreeThreadedMarshaler](http://msdn.microsoft.com/library/windows/desktop/ms694500)   
 [IMarshal](http://msdn.microsoft.com/library/windows/desktop/dd542707)   
 [Quando usar a tabela de Interface Global](http://msdn.microsoft.com/library/windows/desktop/ms693729)   
 [Problemas de Threading do servidor em processo](http://msdn.microsoft.com/library/windows/desktop/ms687205)

