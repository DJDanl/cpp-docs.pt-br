---
title: "Como: adicionar suporte ao Gerenciador de reinicialização | Microsoft Docs"
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
- Restart manager [MFC]
- C++, application crash support
ms.assetid: 7f3f5867-d4bc-4ba8-b3c9-dc1e7be93642
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a413f28909a52e3bc82e9d8f2694d559bf8a885c
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-add-restart-manager-support"></a>Como adicionar suporte ao gerenciador de reinicialização
O Gerenciador de reinicialização é um recurso adicionado para [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] para [!INCLUDE[wiprlhext](../c-runtime-library/reference/includes/wiprlhext_md.md)]. O Gerenciador de reinicialização adiciona suporte para o seu aplicativo se fecha ou for reiniciado inesperadamente. O comportamento do Gerenciador de reinicialização depende do tipo de seu aplicativo. Se seu aplicativo for um editor de documento, o Gerenciador de reinicialização habilitado automaticamente salvar o estado do seu aplicativo e o conteúdo de qualquer abra documentos e reinicia o aplicativo depois de um encerramento inesperado. Se seu aplicativo não é um editor de documento, o Gerenciador de reinicialização reiniciará o aplicativo, mas ele não é possível salvar o estado do aplicativo por padrão.  
  
 Após a reinicialização, o aplicativo exibe uma caixa de diálogo de tarefa se o aplicativo é Unicode. Se for um aplicativo ANSI, o aplicativo exibe uma caixa de mensagem do Windows. Neste ponto, o usuário escolhe se deseja restaurar os documentos salvos automaticamente. Se o usuário não restaura os documentos salvos automaticamente, o Gerenciador de reinicialização descartará os arquivos temporários.  
  
> [!NOTE]
>  Você pode substituir o comportamento padrão do Gerenciador de reinicialização para salvar dados e reiniciar o aplicativo.  
  
 Por padrão, os aplicativos MFC criado usando o Assistente de projeto em [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] suporte o Gerenciador de reinicialização quando os aplicativos são executados em um computador que tenha [!INCLUDE[wiprlhext](../c-runtime-library/reference/includes/wiprlhext_md.md)]. Se você não deseja que seu aplicativo para suportar o Gerenciador de reinicialização, você pode desabilitar o Gerenciador de reinicialização no Assistente do novo projeto.  
  
### <a name="to-add-support-for-the-restart-manager-to-an-existing-application"></a>Para adicionar suporte para o Gerenciador de reinicialização para um aplicativo existente  
  
1.  Abrir um aplicativo MFC existente em [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)].  
  
2.  Abra o arquivo de origem para o seu aplicativo principal. Por padrão, esse é o arquivo. cpp que tem o mesmo nome de seu aplicativo. Por exemplo, o arquivo de origem do aplicativo principal para MyProject é MyProject.cpp.  
  
3.  Encontre construtor para o aplicativo principal. Por exemplo, se seu projeto for MyProject, o construtor é `CMyProjectApp::CMyProjectApp()`.  
  
4.  Adicione a seguinte linha de código para o construtor.  
  
 ```  
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;  
 ```  
  
5.  Verifique se o `InitInstance` chamadas de método do seu aplicativo de seu pai `InitInstance` método: [CWinApp::InitInstance](../mfc/reference/cwinapp-class.md#initinstance) ou `CWinAppEx::InitInstance`. O `InitInstance` método é responsável por verificar a `m_dwRestartManagerSupportFlags` parâmetro.  
  
6.  Compile e execute seu aplicativo.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDataRecoveryHandler](../mfc/reference/cdatarecoveryhandler-class.md)   
 [CWinApp::m_dwRestartManagerSupportFlags](../mfc/reference/cwinapp-class.md#m_dwrestartmanagersupportflags)   
 [Classe CWinApp](../mfc/reference/cwinapp-class.md)   
 [CWinApp::m_nAutosaveInterval](../mfc/reference/cwinapp-class.md#m_nautosaveinterval)   
 [CDocument::OnDocumentEvent](../mfc/reference/cdocument-class.md#ondocumentevent)

