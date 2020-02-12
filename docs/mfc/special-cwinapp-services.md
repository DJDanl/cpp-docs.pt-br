---
title: Serviços CWinApp especiais
ms.date: 11/04/2016
f1_keywords:
- LoadStdProfileSettings
- EnableShellOpen
helpviewer_keywords:
- files [MFC], most recently used
- DragAcceptFiles method [MFC]
- MRU lists
- GDI+, initializing for MFC
- GDI+, suppressing background thread [MFC]
- CWinApp class [MFC], shell registration
- application objects [MFC], services
- CWinApp class [MFC], initializing GDI+
- MFC, shell registration
- CWinApp class [MFC], File Manager drag and drop
- LoadStdProfileSettings method [MFC]
- MFC, most-recently-used file list
- RegisterShellFileTypes method [MFC]
- drag and drop [MFC], files
- registering file types
- Shell, registering file types
- services, provided by CWinApp
- CWinApp class [MFC], recently used documents
- CWinApp class [MFC], services
- files [MFC], drag and drop
- EnableShellOpen method [MFC]
- registry [MFC], most recently used files
- MFC, file operations
- registration [MFC], shell
ms.assetid: 0480cd01-f629-4249-b221-93432d95b431
ms.openlocfilehash: 04c7357d67dc1a5daee4b8b8135c9a54eda8504a
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127823"
---
# <a name="special-cwinapp-services"></a>Serviços CWinApp especiais

Além de executar o loop de mensagem e dar a você uma oportunidade de inicializar o aplicativo e limpá-lo depois dele, o [CWinApp](../mfc/reference/cwinapp-class.md) fornece vários outros serviços.

##  <a name="_core_shell_registration"></a>Registro do Shell

Por padrão, o assistente de aplicativo do MFC possibilita que o usuário abra arquivos de dados que seu aplicativo criou clicando duas vezes neles no explorador de arquivos ou no Gerenciador de arquivos. Se seu aplicativo for um aplicativo MDI e você especificar uma extensão para os arquivos que seu aplicativo cria, o assistente de aplicativo do MFC adicionará chamadas às funções membro [RegisterShellFileTypes](../mfc/reference/cwinapp-class.md#registershellfiletypes) e [EnableShellOpen](../mfc/reference/cwinapp-class.md#enableshellopen) de [CWinApp](../mfc/reference/cwinapp-class.md) para a substituição de `InitInstance` que grava para você.

`RegisterShellFileTypes` registra os tipos de documento do aplicativo com o explorador de arquivos ou o Gerenciador de arquivos. A função adiciona entradas ao banco de dados de registro que o Windows mantém. As entradas registram cada tipo de documento, associam uma extensão de arquivo ao tipo de arquivo, especificam uma linha de comando para abrir o aplicativo e especificam um comando DDE (troca de dados dinâmicos) para abrir um documento desse tipo.

`EnableShellOpen` conclui o processo permitindo que seu aplicativo receba comandos DDE do explorador de arquivos ou do Gerenciador de arquivos para abrir o arquivo escolhido pelo usuário.

Esse suporte de registro automático no `CWinApp` elimina a necessidade de enviar um arquivo. reg com seu aplicativo ou para realizar um trabalho de instalação especial.

Se você quiser inicializar o GDI+ para seu aplicativo (chamando [GdiplusStartup](/windows/win32/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup) em sua função [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) ), será necessário suprimir o thread em segundo plano GDI+.

Você pode fazer isso definindo o membro `SuppressBackgroundThread` da estrutura [GdiplusStartupInput](/windows/win32/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupinput) como **true**. Ao suprimir o thread em segundo plano GDI+, as chamadas `NotificationHook` e `NotificationUnhook` devem ser feitas antes de entrar e sair do loop de mensagem do aplicativo. Para obter mais informações sobre essas chamadas, consulte [GdiplusStartupOutput](/windows/win32/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupoutput). Portanto, um bom lugar para chamar `GdiplusStartup` e as funções de notificação de Hook estaria em uma substituição da função virtual [CWinApp:: Run](../mfc/reference/cwinapp-class.md#run), conforme mostrado abaixo:

[!code-cpp[NVC_MFCDocView#6](../mfc/codesnippet/cpp/special-cwinapp-services_1.cpp)]

Se você não suprimir o thread GDI+ em segundo plano, os comandos DDE poderão ser emitidos prematuramente para o aplicativo antes que sua janela principal tenha sido criada. Os comandos DDE emitidos pelo shell podem ser anulados prematuramente, resultando em mensagens de erro.

##  <a name="_core_file_manager_drag_and_drop"></a>Arrastar e soltar do Gerenciador de arquivos

Os arquivos podem ser arrastados da janela de exibição de arquivo no Gerenciador de arquivos ou do explorador de arquivos para uma janela em seu aplicativo. Você pode, por exemplo, permitir que um ou mais arquivos sejam arrastados para uma janela principal do aplicativo MDI, onde o aplicativo poderia recuperar os nomes de arquivo e abrir janelas filhas MDI para esses arquivos.

Para habilitar o recurso arrastar e soltar em seu aplicativo, o assistente de aplicativo MFC grava uma chamada para a função de membro [CWnd](../mfc/reference/cwnd-class.md) [DragAcceptFiles](../mfc/reference/cwnd-class.md#dragacceptfiles) para sua janela de quadro principal em seu `InitInstance`. Você pode remover essa chamada se não quiser implementar o recurso de arrastar e soltar.

> [!NOTE]
>  Você também pode implementar recursos mais gerais de arrastar e soltar, arrastando dados entre o ou dentro de documentos — com OLE. Para obter informações, consulte o artigo [arrastar e soltar de OLE](../mfc/drag-and-drop-ole.md).

##  <a name="_core_keeping_track_of_the_most_recently_used_documents"></a>Controlando os documentos usados mais recentemente

À medida que o usuário abre e fecha os arquivos, o objeto de aplicativo mantém o controle dos quatro arquivos usados mais recentemente. Os nomes desses arquivos são adicionados ao menu arquivo e atualizados quando eles são alterados. A estrutura armazena esses nomes de arquivo no registro ou no arquivo. ini, com o mesmo nome que o seu projeto e os lê do arquivo quando o aplicativo é iniciado. O `InitInstance` substituição que o assistente de aplicativo do MFC cria para você inclui uma chamada para a função membro [CWinApp](../mfc/reference/cwinapp-class.md) [LoadStdProfileSettings](../mfc/reference/cwinapp-class.md#loadstdprofilesettings), que carrega informações do registro ou do arquivo. ini, incluindo os nomes de arquivo usados mais recentemente.

Essas entradas são armazenadas da seguinte maneira:

- No Windows NT, Windows 2000 e posterior, o valor é armazenado em uma chave do registro.

- No Windows 3. x, o valor é armazenado no WIN. Arquivo INI.

- No Windows 95 e posterior, o valor é armazenado em uma versão armazenada em cache do WIN. Personalizado.

## <a name="see-also"></a>Consulte também

[CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
