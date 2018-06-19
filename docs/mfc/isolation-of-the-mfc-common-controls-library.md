---
title: Biblioteca de controles de isolamento de comuns MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MFC, Common Controls library
ms.assetid: 7471e6f0-49b0-47f7-86e7-8d6bc3541694
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 193a0ea527cda3819a585f5b7149c823a7eb8ef7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33346809"
---
# <a name="isolation-of-the-mfc-common-controls-library"></a>Isolamento da biblioteca de controles comuns MFC
A biblioteca de controles comuns agora é isolada em MFC, permitindo que diferentes módulos (por exemplo, o usuário DLLs) para usar diferentes versões da biblioteca de controles comuns, especificando a versão em seus manifestos.  
  
 Um aplicativo MFC (ou código de usuário chamado pelo MFC) faz chamadas a biblioteca de controles comuns APIs por meio de funções de invólucro denominado `Afx` *FunctionName*, onde *FunctionName* é o nome de um comum Controles de API. Essas funções de wrapper são definidas em afxcomctl32.h e afxcomctl32.inl.  
  
 Você pode usar o [AFX_COMCTL32_IF_EXISTS](reference/run-time-object-model-services.md#afx_comctl32_if_exists) e [AFX_COMCTL32_IF_EXISTS2](reference/run-time-object-model-services.md#afx_comctl32_if_exists2) macros (definidos no afxcomctl32.h) para determinar se a biblioteca de controles comuns implementa uma API determinada em vez de chamar [GetProcAddress](../build/getprocaddress.md).  
  
 Tecnicamente, você pode fazer chamadas a APIs de biblioteca de controles comuns por meio de uma classe wrapper, `CComCtlWrapper` (definido em afxcomctl32.h). `CComCtlWrapper` também é responsável pelo carregamento e descarregamento de comctl32.dll. O estado do módulo MFC contém um ponteiro para uma instância de `CComCtlWrapper`. Você pode acessar a classe de invólucro usando o `afxComCtlWrapper` macro.  
  
 Observe que a chamada API controles comuns diretamente (sem usar as funções de invólucro do MFC) de um MFC aplicativo ou usuário DLL funcionará na maioria dos casos, porque o aplicativo do MFC ou usuário DLL está associado à biblioteca de controles comuns solicitada em seu manifesto). No entanto, o próprio código MFC precisa usar os wrappers, porque o código MFC pode ser chamado a partir de DLLs de usuário com diferentes versões de biblioteca de controles comuns.

