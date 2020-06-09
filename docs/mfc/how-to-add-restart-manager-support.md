---
title: Como adicionar suporte ao gerenciador de reinicialização
ms.date: 11/04/2016
helpviewer_keywords:
- Restart manager [MFC]
- C++, application crash support
ms.assetid: 7f3f5867-d4bc-4ba8-b3c9-dc1e7be93642
ms.openlocfilehash: 848cb3bb52ae13eb1b7798126becd13384fddeb6
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625662"
---
# <a name="how-to-add-restart-manager-support"></a>Como adicionar suporte ao gerenciador de reinicialização

O Gerenciador de reinicialização é um recurso adicionado ao Visual Studio para Windows Vista ou sistemas operacionais posteriores. O Gerenciador de reinicialização adicionará suporte para seu aplicativo se ele fechar ou reiniciar inesperadamente. O comportamento do Gerenciador de reinicialização depende do tipo de seu aplicativo. Se seu aplicativo for um editor de documento, o Gerenciador de reinicialização habilitou seu aplicativo para salvar automaticamente o estado e o conteúdo de qualquer documento aberto e reinicia seu aplicativo após um fechamento inesperado. Se seu aplicativo não for um editor de documento, o Gerenciador de reinicialização reiniciará o aplicativo, mas não poderá salvar o estado do aplicativo por padrão.

Após a reinicialização, o aplicativo exibirá uma caixa de diálogo de tarefa se o aplicativo for Unicode. Se for um aplicativo ANSI, o aplicativo exibirá uma caixa de mensagem do Windows. Neste ponto, o usuário escolhe se deseja restaurar os documentos salvos automaticamente. Se o usuário não restaurar os documentos salvos automaticamente, o Gerenciador de reinicialização descartará os arquivos temporários.

> [!NOTE]
> Você pode substituir o comportamento padrão do Gerenciador de reinicialização para salvar dados e reiniciar o aplicativo.

Por padrão, os aplicativos MFC criados usando o assistente de projeto no Visual Studio dão suporte ao Gerenciador de reinicialização quando os aplicativos são executados em um computador que tem um sistema operacional Windows Vista ou posterior. Se não quiser que seu aplicativo dê suporte ao Gerenciador de reinicialização, você poderá desabilitar o Gerenciador de reinicialização no assistente de novo projeto.

### <a name="to-add-support-for-the-restart-manager-to-an-existing-application"></a>Para adicionar suporte para o Gerenciador de reinicialização a um aplicativo existente

1. Abra um aplicativo MFC existente no Visual Studio.

1. Abra o arquivo de origem para seu aplicativo principal. Por padrão, esse é o arquivo. cpp que tem o mesmo nome que o seu aplicativo. Por exemplo, o arquivo de origem do aplicativo principal para MyProject é MyProject. cpp.

1. Localize o construtor para seu aplicativo principal. Por exemplo, se o seu projeto for MyProject, o Construtor será `CMyProjectApp::CMyProjectApp()` .

1. Adicione a seguinte linha de código ao seu construtor.

```
    m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
```

1. Verifique se o `InitInstance` método do seu aplicativo chama seu `InitInstance` método pai: [CWinApp:: InitInstance](reference/cwinapp-class.md#initinstance) ou `CWinAppEx::InitInstance` . O `InitInstance` método é responsável por verificar o parâmetro *m_dwRestartManagerSupportFlags* .

1. Compile e execute seu aplicativo.

## <a name="see-also"></a>Consulte também

[Classe CDataRecoveryHandler](reference/cdatarecoveryhandler-class.md)<br/>
[CWinApp:: m_dwRestartManagerSupportFlags](reference/cwinapp-class.md#m_dwrestartmanagersupportflags)<br/>
[Classe CWinApp](reference/cwinapp-class.md)<br/>
[CWinApp:: m_nAutosaveInterval](reference/cwinapp-class.md#m_nautosaveinterval)<br/>
[CDocument:: OnDocumentEvent](reference/cdocument-class.md#ondocumentevent)
