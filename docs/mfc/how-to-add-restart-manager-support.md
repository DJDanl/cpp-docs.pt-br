---
title: Como adicionar suporte ao gerenciador de reinicialização
ms.date: 11/04/2016
helpviewer_keywords:
- Restart manager [MFC]
- C++, application crash support
ms.assetid: 7f3f5867-d4bc-4ba8-b3c9-dc1e7be93642
ms.openlocfilehash: 7cf3fede663a7c4bc85573e17dd9c2f8bf3622b4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373323"
---
# <a name="how-to-add-restart-manager-support"></a>Como adicionar suporte ao gerenciador de reinicialização

O gerenciador de reinicialização é um recurso adicionado ao Visual Studio para Windows Vista ou sistemas operacionais posteriores. O gerenciador de reinicialização adiciona suporte ao aplicativo se ele fechar ou reiniciar inesperadamente. O comportamento do gerenciador de reinicialização depende do tipo de sua aplicação. Se o aplicativo for um editor de documentos, o gerenciador de reinicialização permitiu que seu aplicativo salvasse automaticamente o estado e o conteúdo de quaisquer documentos abertos e reiniciasse seu aplicativo após um encerramento inesperado. Se o aplicativo não for um editor de documentos, o gerenciador de reinicialização reiniciará o aplicativo, mas não poderá salvar o estado do aplicativo por padrão.

Após a reinicialização, o aplicativo exibe uma caixa de diálogo de tarefas se o aplicativo for Unicode. Se for um aplicativo ANSI, o aplicativo exibirá uma caixa de mensagens do Windows. Neste ponto, o usuário escolhe se quer restaurar os documentos salvos automaticamente. Se o usuário não restaurar os documentos salvos automaticamente, o gerenciador de reinicialização descartará os arquivos temporários.

> [!NOTE]
> Você pode substituir o comportamento padrão do gerenciador de reinicialização para salvar dados e reiniciar o aplicativo.

Por padrão, os aplicativos MFC criados usando o assistente de projeto no Visual Studio suportam o gerenciador de reinicialização quando os aplicativos são executados em um computador que tem um Windows Vista ou um sistema operacional posterior. Se você não quiser que seu aplicativo suporte o gerenciador de reinicialização, você pode desativar o gerenciador de reinicialização no novo assistente de projeto.

### <a name="to-add-support-for-the-restart-manager-to-an-existing-application"></a>Para adicionar suporte ao gerenciador de reinicialização a um aplicativo existente

1. Abra um aplicativo MFC existente no Visual Studio.

1. Abra o arquivo de código para sua aplicação principal. Por padrão, este é o arquivo .cpp que tem o mesmo nome do seu aplicativo. Por exemplo, o principal arquivo de origem do aplicativo para myProject é MyProject.cpp.

1. Encontre o construtor para sua aplicação principal. Por exemplo, se o seu projeto é `CMyProjectApp::CMyProjectApp()`MyProject, o construtor é .

1. Adicione a seguinte linha de código ao seu construtor.

```
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
```

1. Certifique-se `InitInstance` de que o `InitInstance` método do aplicativo ligue para o `CWinAppEx::InitInstance`método pai: [CWinApp::InitInstance](../mfc/reference/cwinapp-class.md#initinstance) ou . O `InitInstance` método é responsável por verificar o parâmetro *m_dwRestartManagerSupportFlags.*

1. Compile e execute sua aplicação.

## <a name="see-also"></a>Confira também

[Classe CDataRecoveryHandler](../mfc/reference/cdatarecoveryhandler-class.md)<br/>
[CwinApp::m_dwRestartManagerSupportFlags](../mfc/reference/cwinapp-class.md#m_dwrestartmanagersupportflags)<br/>
[Classe CWinApp](../mfc/reference/cwinapp-class.md)<br/>
[CWinApp::m_nAutosaveInterval](../mfc/reference/cwinapp-class.md#m_nautosaveinterval)<br/>
[CDocument::OnDocumentEvent](../mfc/reference/cdocument-class.md#ondocumentevent)
