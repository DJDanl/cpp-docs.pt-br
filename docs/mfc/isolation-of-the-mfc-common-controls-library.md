---
title: Biblioteca de controles de isolamento de comuns MFC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- MFC, Common Controls library
ms.assetid: 7471e6f0-49b0-47f7-86e7-8d6bc3541694
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 04ed1be46d4c3d7f36bfa501bfc933fbba41e8d1
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="isolation-of-the-mfc-common-controls-library"></a>Isolamento da biblioteca de controles comuns MFC
A biblioteca de controles comuns agora é isolada em MFC, permitindo que diferentes módulos (por exemplo, o usuário DLLs) para usar diferentes versões da biblioteca de controles comuns, especificando a versão em seus manifestos.  
  
 Um aplicativo MFC (ou código de usuário chamado pelo MFC) faz chamadas a biblioteca de controles comuns APIs por meio de funções de invólucro denominado `Afx` *FunctionName*, onde *FunctionName* é o nome de um comum Controles de API. Essas funções de wrapper são definidas em afxcomctl32.h e afxcomctl32.inl.  
  
 Você pode usar o [AFX_COMCTL32_IF_EXISTS](reference/run-time-object-model-services.md#afx_comctl32_if_exists) e [AFX_COMCTL32_IF_EXISTS2](reference/run-time-object-model-services.md#afx_comctl32_if_exists2) macros (definidos no afxcomctl32.h) para determinar se a biblioteca de controles comuns implementa uma API determinada em vez de chamar [GetProcAddress](../build/getprocaddress.md).  
  
 Tecnicamente, você pode fazer chamadas a APIs de biblioteca de controles comuns por meio de uma classe wrapper, `CComCtlWrapper` (definido em afxcomctl32.h). `CComCtlWrapper`também é responsável pelo carregamento e descarregamento de comctl32.dll. O estado do módulo MFC contém um ponteiro para uma instância de `CComCtlWrapper`. Você pode acessar a classe de invólucro usando o `afxComCtlWrapper` macro.  
  
 Observe que a chamada API controles comuns diretamente (sem usar as funções de invólucro do MFC) de um MFC aplicativo ou usuário DLL funcionará na maioria dos casos, porque o aplicativo do MFC ou usuário DLL está associado à biblioteca de controles comuns solicitada em seu manifesto). No entanto, o próprio código MFC precisa usar os wrappers, porque o código MFC pode ser chamado a partir de DLLs de usuário com diferentes versões de biblioteca de controles comuns.

