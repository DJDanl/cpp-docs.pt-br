---
title: 'Como: Adicionar suporte ao Gerenciador de reinicialização'
ms.date: 11/04/2016
helpviewer_keywords:
- Restart manager [MFC]
- C++, application crash support
ms.assetid: 7f3f5867-d4bc-4ba8-b3c9-dc1e7be93642
ms.openlocfilehash: 23f860c43c63e3153f4b87f8eaf05d61709af82f
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57279777"
---
# <a name="how-to-add-restart-manager-support"></a>Como: Adicionar suporte ao Gerenciador de reinicialização

O Gerenciador de reinicialização é um recurso adicionado ao Visual Studio para Windows Vista ou sistemas operacionais posteriores. O Gerenciador de reinicialização adiciona suporte para seu aplicativo se ele fecha ou reinicia inesperadamente. O comportamento do Gerenciador de reinicialização depende do tipo de seu aplicativo. Se seu aplicativo for um editor de documentos, seu aplicativo para salvar automaticamente o estado habilitado para o Gerenciador de reinicialização e conteúdo de qualquer abrir documentos e reinicia o aplicativo após um encerramento inesperado. Se seu aplicativo não é um editor de documentos, o Gerenciador de reinicialização será reiniciar o aplicativo, mas ele não é possível salvar o estado do aplicativo por padrão.

Após a reinicialização, o aplicativo exibe uma caixa de diálogo de tarefa se o aplicativo for Unicode. Se for um aplicativo ANSI, o aplicativo exibe uma caixa de mensagem do Windows. Neste ponto, o usuário escolhe se deseja restaurar os documentos salvos automaticamente. Se o usuário não restaura os documentos salvos automaticamente, o Gerenciador de reinicialização descarta os arquivos temporários.

> [!NOTE]
>  Você pode substituir o comportamento padrão do Gerenciador de reinicialização para salvar os dados e reiniciar o aplicativo.

Por padrão, os aplicativos MFC criados usando o Assistente de projeto no Visual Studio suportam o Gerenciador de reinicialização quando os aplicativos são executados em um computador que tenha um Windows Vista ou o sistema operacional posterior. Se você não deseja que seu aplicativo para dar suporte ao Gerenciador de reinicialização, você pode desabilitar o Gerenciador de reinicialização no Assistente do novo projeto.

### <a name="to-add-support-for-the-restart-manager-to-an-existing-application"></a>Para adicionar suporte para o Gerenciador de reinicialização para um aplicativo existente

1. Abra um aplicativo MFC existente no Visual Studio.

1. Abra o arquivo de origem para o seu aplicativo principal. Por padrão, esse é o arquivo. cpp que tem o mesmo nome que seu aplicativo. Por exemplo, o arquivo de origem do aplicativo principal para MyProject é MyProject.cpp.

1. Localize o construtor para seu aplicativo principal. Por exemplo, se seu projeto for MyProject, o construtor é `CMyProjectApp::CMyProjectApp()`.

1. Adicione a seguinte linha de código para seu construtor.

```
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
```

1. Verifique se o `InitInstance` método de seu aplicativo chama seu pai `InitInstance` método: [CWinApp::InitInstance](../mfc/reference/cwinapp-class.md#initinstance) ou `CWinAppEx::InitInstance`. O `InitInstance` método é responsável por verificar as *m_dwRestartManagerSupportFlags* parâmetro.

1. Compile e execute seu aplicativo.

## <a name="see-also"></a>Consulte também

[Classe CDataRecoveryHandler](../mfc/reference/cdatarecoveryhandler-class.md)<br/>
[CWinApp::m_dwRestartManagerSupportFlags](../mfc/reference/cwinapp-class.md#m_dwrestartmanagersupportflags)<br/>
[Classe CWinApp](../mfc/reference/cwinapp-class.md)<br/>
[CWinApp::m_nAutosaveInterval](../mfc/reference/cwinapp-class.md#m_nautosaveinterval)<br/>
[CDocument::OnDocumentEvent](../mfc/reference/cdocument-class.md#ondocumentevent)
