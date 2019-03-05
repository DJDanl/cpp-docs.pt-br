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
ms.openlocfilehash: 910660253c9d306b13294a710021a6bbd36c1952
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57258080"
---
# <a name="special-cwinapp-services"></a>Serviços CWinApp especiais

Além de executar o loop de mensagem e dando a você uma oportunidade de inicializar o aplicativo e a limpeza posteriormente, [CWinApp](../mfc/reference/cwinapp-class.md) fornece vários outros serviços.

##  <a name="_core_shell_registration"></a> Registro de shell

Por padrão, o Assistente de aplicativo do MFC torna possível para o usuário abrir arquivos de dados que seu aplicativo criou, clique duas vezes no Explorador de arquivos ou no Gerenciador de arquivos. Se seu aplicativo é um aplicativo MDI e você especificar uma extensão para os arquivos de seu aplicativo cria, o Assistente de aplicativo MFC adiciona chamadas para o [RegisterShellFileTypes](../mfc/reference/cwinapp-class.md#registershellfiletypes) e [EnableShellOpen](../mfc/reference/cwinapp-class.md#enableshellopen)funções de membro [CWinApp](../mfc/reference/cwinapp-class.md) para o `InitInstance` substituição que ele grava para você.

`RegisterShellFileTypes` registra os tipos de documento do seu aplicativo com o Explorador de arquivos ou o Gerenciador de arquivos. A função adiciona entradas para o banco de dados de registro que o Windows mantém. As entradas de registrar cada tipo de documento, associar uma extensão de arquivo com o tipo de arquivo, especificam uma linha de comando para abrir o aplicativo e especificam um comando de DDE (troca) de dados dinâmicos para abrir um documento desse tipo.

`EnableShellOpen` conclui o processo, permitindo que seu aplicativo receber comandos DDE do Explorador de arquivos ou o Gerenciador de arquivos para abrir o arquivo escolhido pelo usuário.

Esse suporte de registro automático no `CWinApp` elimina a necessidade de enviar um arquivo. reg com seu aplicativo ou para fazer o trabalho de instalação especial.

Se você deseja inicializar o GDI+ para seu aplicativo (chamando [GdiplusStartup](/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup) no seu [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) função), você tem que suprimir o thread em segundo plano GDI+.

Você pode fazer isso definindo a `SuppressBackgroundThread` membro do [GdiplusStartupInput](/windows/desktop/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupinput) estrutura ao **TRUE**. Quando suprimir o GDI+ thread de segundo plano, o `NotificationHook` e `NotificationUnhook` chamadas devem ser feitas apenas anteriores entrando e saindo do loop de mensagem do aplicativo. Para obter mais informações sobre essas chamadas, consulte [GdiplusStartupOutput](/windows/desktop/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupoutput). Portanto, um bom lugar para chamar `GdiplusStartup` e as funções de gancho de notificação seria em uma substituição da função virtual [CWinApp:: Run](../mfc/reference/cwinapp-class.md#run), conforme mostrado abaixo:

[!code-cpp[NVC_MFCDocView#6](../mfc/codesnippet/cpp/special-cwinapp-services_1.cpp)]

Se você não suprime o plano de fundo GDI+ thread, DDE comandos podem ser emitidos prematuramente no aplicativo antes que a janela principal foi criada. Os comandos DDE emitidos pelo shell podem ser prematuramente interrompidos, resultando em mensagens de erro.

##  <a name="_core_file_manager_drag_and_drop"></a> Gerenciador de arquivos de arrastar e soltar

Arquivos podem ser arrastados da janela de exibição de arquivo no Gerenciador de arquivos ou o Explorador de arquivos para uma janela em seu aplicativo. Você pode, por exemplo, habilitar um ou mais arquivos sejam arrastados para a janela principal do aplicativo MDI, onde o aplicativo pode recuperar os nomes de arquivo e abrir janelas MDI filhas para esses arquivos.

Para permitir o arquivo arrastar e soltar em seu aplicativo, o Assistente de aplicativo MFC grava uma chamada para o [CWnd](../mfc/reference/cwnd-class.md) função de membro [DragAcceptFiles](../mfc/reference/cwnd-class.md#dragacceptfiles) para sua janela de quadro principal no seu `InitInstance`. Se você não quiser implementar o recurso de arrastar e soltar, você pode remover essa chamada.

> [!NOTE]
>  Você também pode implementar os recursos de arrastar e soltar mais gerais — arrastando dados entre ou dentro de documentos — com OLE. Para obter informações, consulte o artigo [arrastar e soltar (OLE)](../mfc/drag-and-drop-ole.md).

##  <a name="_core_keeping_track_of_the_most_recently_used_documents"></a> Manter o controle de mais documentos usados recentemente

O usuário abre e fecha os arquivos, o objeto de aplicativo controla de quatro arquivos usados mais recentemente. Os nomes desses arquivos são adicionados ao menu Arquivo e atualizados quando elas forem alteradas. O framework armazena esses nomes de arquivo no registro ou no arquivo. ini, com o mesmo nome que o seu projeto e lê-los a partir do arquivo quando seu aplicativo é iniciado. O `InitInstance` substituir que o Assistente de aplicativo do MFC cria para você inclui uma chamada para o [CWinApp](../mfc/reference/cwinapp-class.md) função de membro [LoadStdProfileSettings](../mfc/reference/cwinapp-class.md#loadstdprofilesettings), que carrega informações de registro ou. ini o arquivo, incluindo mais recentemente usado nomes de arquivo.

Essas entradas são armazenadas da seguinte maneira:

- No Windows NT, Windows 2000 e posterior, o valor é armazenado para uma chave do registro.

- No Windows 3. x, o valor é armazenado no arquivo o WIN. Arquivo INI.

- No Windows 95 e posterior, o valor é armazenado em uma versão em cache do WIN. INI.

## <a name="see-also"></a>Consulte também

[CWinApp: A classe do aplicativo](../mfc/cwinapp-the-application-class.md)
