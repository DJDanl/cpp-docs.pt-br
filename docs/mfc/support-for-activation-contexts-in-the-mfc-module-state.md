---
title: "Suporte para contextos de ativação no estado do módulo MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- activation contexts [MFC]
- activation contexts [MFC], MFC support
ms.assetid: 1e49eea9-3620-46dd-bc5f-d664749567c7
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 41aa0987a6fad48e57544ebbdd708d60c000382e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="support-for-activation-contexts-in-the-mfc-module-state"></a>Suporte para contextos de ativação no estado do módulo MFC
MFC cria um contexto de ativação usando um recurso de manifesto fornecido pelo módulo de usuário. Para obter mais informações sobre como os contextos de ativação são criados, consulte os tópicos a seguir:  
  
-   [Contextos de ativação](http://msdn.microsoft.com/library/aa374153)  
  
-   [Manifestos de aplicativo](http://msdn.microsoft.com/library/aa374191)  
  
-   [Manifestos de assembly](http://msdn.microsoft.com/library/aa374219)  
  
## <a name="remarks"></a>Comentários  
 Ao ler estes tópicos do SDK do Windows, observe que o mecanismo de contexto de ativação do MFC semelhante o contexto de ativação do SDK do Windows, exceto que MFC não usa a API de contexto de ativação do Windows SDK.  
  
 Contexto de ativação funciona em aplicativos MFC DLLs de usuário e DLLs de extensão do MFC das seguintes maneiras:  
  
-   Aplicativos MFC usam identificação de recurso 1 para o recurso de manifesto. Nesse caso, o MFC não cria seu próprio contexto de ativação, mas usa o contexto de aplicativo padrão.  
  
-   Usuário MFC DLLs usar recursos ID 2 para o recurso de manifesto. Aqui, o MFC cria um contexto de ativação para cada DLL de usuário, para que DLLs de outro usuário possa usar versões diferentes da mesmo bibliotecas (por exemplo, a biblioteca de controles comuns).  
  
-   DLLs de extensão do MFC dependem de seus aplicativos ou um usuário DLLs de hospedagem para estabelecer o contexto de ativação.  
  
 Embora o estado de contexto de ativação pode ser modificado usando os processos descritos em [usando a API de contexto de ativação](http://msdn.microsoft.com/library/aa376620), usando o mecanismo de contexto de ativação do MFC pode ser útil ao desenvolvimento de arquiteturas de plug-in baseado em DLL onde não é fácil (ou não é possível) para alternar o estado de ativação manualmente antes e depois chamadas individuais para plug-ins externos.  
  
 O contexto de ativação é criado no [AfxWinInit](../mfc/reference/application-information-and-management.md#afxwininit). Ele é destruído no `AFX_MODULE_STATE` destruidor. Um identificador de contexto de ativação é mantido em `AFX_MODULE_STATE`. (`AFX_MODULE_STATE` descrito [AfxGetStaticModuleState](reference/extension-dll-macros.md#afxgetstaticmodulestate).)  
  
 O [AFX_MANAGE_STATE](reference/extension-dll-macros.md#afx_manage_state) macro ativa e desativa o contexto de ativação. `AFX_MANAGE_STATE`está habilitado para bibliotecas estáticas do MFC, bem como o MFC DLLs, para permitir que o código do MFC executar no contexto de ativação adequada selecionado pelo usuário DLL.  
  
## <a name="see-also"></a>Consulte também  
 [Contextos de ativação](http://msdn.microsoft.com/library/aa374153)   
 [Manifestos de aplicativo](http://msdn.microsoft.com/library/aa374191)   
 [Manifestos de assembly](http://msdn.microsoft.com/library/aa374219)   
 [AfxWinInit](../mfc/reference/application-information-and-management.md#afxwininit)   
 [AfxGetStaticModuleState](reference/extension-dll-macros.md#afxgetstaticmodulestate)   
 [AFX_MANAGE_STATE](reference/extension-dll-macros.md#afx_manage_state)

