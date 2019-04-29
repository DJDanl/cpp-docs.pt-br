---
title: Isolamento da biblioteca de controles comuns MFC
ms.date: 11/04/2016
helpviewer_keywords:
- MFC, Common Controls library
ms.assetid: 7471e6f0-49b0-47f7-86e7-8d6bc3541694
ms.openlocfilehash: 94700f850be62404f22974a1d5e76acad711555c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62310858"
---
# <a name="isolation-of-the-mfc-common-controls-library"></a>Isolamento da biblioteca de controles comuns MFC

A biblioteca de controles comuns agora é isolada dentro do MFC, permitindo que módulos diferentes (por exemplo, o usuário DLLs) para usar versões diferentes da biblioteca de controles comuns, especificando a versão em seus manifestos.

Um aplicativo MFC (ou código de usuário chamado pelo MFC) faz chamadas para APIs por meio de funções de wrapper de chamada de biblioteca de controles comuns `Afx` *FunctionName*, onde *FunctionName* é o nome de um comum Controles de API. Essas funções de wrapper são definidas em afxcomctl32.h e afxcomctl32.inl.

Você pode usar o [AFX_COMCTL32_IF_EXISTS](reference/run-time-object-model-services.md#afx_comctl32_if_exists) e [AFX_COMCTL32_IF_EXISTS2](reference/run-time-object-model-services.md#afx_comctl32_if_exists2) macros (definidos em afxcomctl32.h) para determinar se a biblioteca de controles comuns implementa uma API certa em vez de chamar [GetProcAddress](../build/getprocaddress.md).

Tecnicamente, você pode fazer chamadas para APIs da biblioteca de controles comuns através de uma classe wrapper, `CComCtlWrapper` (definidos em afxcomctl32.h). `CComCtlWrapper` também é responsável pelo carregamento e descarregamento do comctl32.dll. O estado do módulo MFC contém um ponteiro para uma instância de `CComCtlWrapper`. Você pode acessar a classe de wrapper usando o `afxComCtlWrapper` macro.

Observe que a chamada API controles comuns diretamente (não usando as funções de wrapper do MFC) de um MFC DLL do usuário ou aplicativo funcionará na maioria dos casos, porque o aplicativo do MFC ou usuário DLL está associado à biblioteca de controles comuns solicitadas no seu manifesto). No entanto, o próprio código do MFC tem usar wrappers, porque o código MFC pode ser chamado a partir de DLLs de usuário com diferentes versões de biblioteca de controles comuns.
