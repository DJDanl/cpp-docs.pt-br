---
title: Suporte para contextos de ativação no estado do módulo MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- activation contexts [MFC]
- activation contexts [MFC], MFC support
ms.assetid: 1e49eea9-3620-46dd-bc5f-d664749567c7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0e162ae0540157209733d9cf4833ad922d69949a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46378352"
---
# <a name="support-for-activation-contexts-in-the-mfc-module-state"></a>Suporte para contextos de ativação no estado do módulo MFC

MFC cria um contexto de ativação usando um recurso de manifesto fornecido pelo módulo do usuário. Para obter mais informações sobre como os contextos de ativação são criados, consulte os tópicos a seguir:

- [Contextos de ativação](/windows/desktop/SbsCs/activation-contexts)

- [Manifestos de aplicativo](/windows/desktop/SbsCs/application-manifests)

- [Manifestos de assembly](/windows/desktop/SbsCs/assembly-manifests)

## <a name="remarks"></a>Comentários

Durante a leitura destes tópicos de SDK do Windows, observe que o mecanismo de contexto de ativação de MFC se parece com o contexto de ativação do Windows SDK, exceto que o MFC não usa a API de contexto de ativação do Windows SDK.

Contexto de ativação funciona em aplicativos MFC, as DLLs de usuário e DLLs de extensão do MFC das seguintes maneiras:

- Aplicativos MFC usam identificação de recurso 1 para seu recurso de manifesto. Nesse caso, o MFC não cria seu próprio contexto de ativação, mas usa o contexto de aplicativo padrão.

- Usuário MFC DLLs usar resource ID 2 para seu recurso de manifesto. Aqui, o MFC cria um contexto de ativação para cada DLL de usuário, portanto, DLLs de usuário diferente pode usar diferentes versões da mesma biblioteca (por exemplo, a biblioteca de controles comuns).

- DLLs de extensão MFC dependem de seus aplicativos ou um usuário DLLs de hospedagem para estabelecer seu contexto de ativação.

Embora o estado de contexto de ativação pode ser modificado usando os processos descritos em [usando a API de contexto de ativação](/windows/desktop/SbsCs/using-the-activation-context-api), usar o mecanismo de contexto de ativação do MFC pode ser útil ao desenvolvimento de arquiteturas de plug-in baseado em DLL onde não é fácil (ou não é possível) para alternar o estado de ativação manualmente antes e depois chamadas individuais para plug-ins externos.

O contexto de ativação é criado no [AfxWinInit](../mfc/reference/application-information-and-management.md#afxwininit). Ele é destruído no `AFX_MODULE_STATE` destruidor. Um identificador de contexto de ativação é mantido em `AFX_MODULE_STATE`. (`AFX_MODULE_STATE` descrito [AfxGetStaticModuleState](reference/extension-dll-macros.md#afxgetstaticmodulestate).)

O [AFX_MANAGE_STATE](reference/extension-dll-macros.md#afx_manage_state) macro ativa e desativa o contexto de ativação. `AFX_MANAGE_STATE` está habilitado para bibliotecas estáticas do MFC, bem como DLLs do MFC, para permitir que o código do MFC para ser executado no contexto de ativação adequada selecionado pelo usuário DLL.

## <a name="see-also"></a>Consulte também

[Contextos de ativação](/windows/desktop/SbsCs/activation-contexts)<br/>
[Manifestos de aplicativo](/windows/desktop/SbsCs/application-manifests)<br/>
[Manifestos de assembly](/windows/desktop/SbsCs/assembly-manifests)<br/>
[AfxWinInit](../mfc/reference/application-information-and-management.md#afxwininit)<br/>
[AfxGetStaticModuleState](reference/extension-dll-macros.md#afxgetstaticmodulestate)<br/>
[AFX_MANAGE_STATE](reference/extension-dll-macros.md#afx_manage_state)

