---
title: Suporte para contextos de ativação no estado do módulo MFC
ms.date: 11/04/2016
helpviewer_keywords:
- activation contexts [MFC]
- activation contexts [MFC], MFC support
ms.assetid: 1e49eea9-3620-46dd-bc5f-d664749567c7
ms.openlocfilehash: 296df3d2ecec74c5c9a7deef1617298d40243724
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69511439"
---
# <a name="support-for-activation-contexts-in-the-mfc-module-state"></a>Suporte para contextos de ativação no estado do módulo MFC

O MFC cria um contexto de ativação usando um recurso de manifesto fornecido pelo módulo do usuário. Para obter mais informações sobre como os contextos de ativação são criados, consulte os seguintes tópicos:

- [Contextos de ativação](/windows/win32/SbsCs/activation-contexts)

- [Manifestos do aplicativo](/windows/win32/SbsCs/application-manifests)

- [Manifestos de assembly](/windows/win32/SbsCs/assembly-manifests)

## <a name="remarks"></a>Comentários

Ao ler esses tópicos de SDK do Windows, observe que o mecanismo de contexto de ativação do MFC é semelhante ao contexto de ativação SDK do Windows, exceto pelo fato de que o MFC não usa a API de contexto de ativação do SDK do Windows.

O contexto de ativação funciona em aplicativos MFC, DLLs de usuário e DLLs de extensão MFC das seguintes maneiras:

- Os aplicativos MFC usam a ID de recurso 1 para o recurso de manifesto. Nesse caso, o MFC não cria seu próprio contexto de ativação, mas usa o contexto do aplicativo padrão.

- As DLLs de usuário do MFC usam a ID de recurso 2 para o recurso de manifesto. Aqui, o MFC cria um contexto de ativação para cada DLL de usuário, para que diferentes DLLs de usuário possam usar versões diferentes das mesmas bibliotecas (por exemplo, a biblioteca de controles comuns).

- As DLLs de extensão do MFC dependem de seus aplicativos de hospedagem ou DLLs de usuário para estabelecer seu contexto de ativação.

Embora o estado do contexto de ativação possa ser modificado usando os processos descritos em [usando a API de contexto de ativação](/windows/win32/SbsCs/using-the-activation-context-api), o uso do mecanismo de contexto de ativação do MFC pode ser útil ao desenvolver arquiteturas de plug-ins baseadas em dll, onde não é fácil (ou Não é possível) para alternar manualmente o estado de ativação antes e depois de chamadas individuais para plug-ins externos.

O contexto de ativação é criado em [AfxWinInit](../mfc/reference/application-information-and-management.md#afxwininit). Ele é destruído no `AFX_MODULE_STATE` destruidor. Um identificador de contexto de ativação é `AFX_MODULE_STATE`mantido no. (`AFX_MODULE_STATE` é descrito em [AfxGetStaticModuleState](reference/extension-dll-macros.md#afxgetstaticmodulestate).)

A macro [AFX_MANAGE_STATE](reference/extension-dll-macros.md#afx_manage_state) ativa e desativa o contexto de ativação. `AFX_MANAGE_STATE`está habilitado para bibliotecas do MFC estáticos, bem como DLLs do MFC, para permitir que o código MFC seja executado no contexto de ativação apropriado selecionado pela DLL do usuário.

## <a name="see-also"></a>Consulte também

[Contextos de ativação](/windows/win32/SbsCs/activation-contexts)<br/>
[Manifestos do aplicativo](/windows/win32/SbsCs/application-manifests)<br/>
[Manifestos de assembly](/windows/win32/SbsCs/assembly-manifests)<br/>
[AfxWinInit](../mfc/reference/application-information-and-management.md#afxwininit)<br/>
[AfxGetStaticModuleState](reference/extension-dll-macros.md#afxgetstaticmodulestate)<br/>
[AFX_MANAGE_STATE](reference/extension-dll-macros.md#afx_manage_state)
