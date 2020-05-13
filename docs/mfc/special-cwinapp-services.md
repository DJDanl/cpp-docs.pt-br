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
ms.openlocfilehash: 1f5abcdab3eda1304879b122acc8072951a0e6c3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81363913"
---
# <a name="special-cwinapp-services"></a>Serviços CWinApp especiais

Além de executar o loop de mensagem e dar-lhe a oportunidade de inicializar o aplicativo e limpar depois dele, [o CWinApp](../mfc/reference/cwinapp-class.md) fornece vários outros serviços.

## <a name="shell-registration"></a><a name="_core_shell_registration"></a>Registro de Conchas

Por padrão, o MFC Application Wizard torna possível que o usuário abra arquivos de dados que seu aplicativo criou clicando duas vezes neles no File Explorer ou File Manager. Se o aplicativo for um aplicativo MDI e você especificar uma extensão para os arquivos que seu aplicativo cria, o Assistente `InitInstance` de Aplicativo do MFC adiciona chamadas às funções de membro [RegisterShellFileTypes](../mfc/reference/cwinapp-class.md#registershellfiletypes) e [EnableShellOpen](../mfc/reference/cwinapp-class.md#enableshellopen) do [CWinApp](../mfc/reference/cwinapp-class.md) à substituição que ele grava para você.

`RegisterShellFileTypes`registra os tipos de documentos do aplicativo com o File Explorer ou o File Manager. A função adiciona entradas ao banco de dados de registro que o Windows mantém. As entradas registram cada tipo de documento, associam uma extensão de arquivo ao tipo de arquivo, especificam uma linha de comando para abrir o aplicativo e especificam um comando DDE (Dynamic Data Exchange, troca de dados dinâmico) para abrir um documento desse tipo.

`EnableShellOpen`completa o processo permitindo que seu aplicativo receba comandos DDE do File Explorer ou do File Manager para abrir o arquivo escolhido pelo usuário.

Este suporte de `CWinApp` registro automático elimina a necessidade de enviar um arquivo .reg com seu aplicativo ou para fazer um trabalho especial de instalação.

Se você quiser inicializar o GDI+ para o seu aplicativo (chamando [GdiplusStartup](/windows/win32/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup) em sua função [InitInstance),](../mfc/reference/cwinapp-class.md#initinstance) você terá que suprimir o segmento de fundo GDI+.

Você pode fazer isso `SuppressBackgroundThread` definindo o membro da estrutura [GdiplusStartupInput](/windows/win32/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupinput) como **TRUE**. Ao suprimir o segmento de fundo `NotificationHook` `NotificationUnhook` GDI+, as chamadas devem ser feitas pouco antes de entrar e sair do loop de mensagem do aplicativo. Para obter mais informações sobre essas chamadas, consulte [GdiplusStartupOutput](/windows/win32/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupoutput). Portanto, um bom lugar `GdiplusStartup` para ligar e as funções de notificação de gancho estariam em uma substituição da função virtual [CWinApp::Run](../mfc/reference/cwinapp-class.md#run), como mostrado abaixo:

[!code-cpp[NVC_MFCDocView#6](../mfc/codesnippet/cpp/special-cwinapp-services_1.cpp)]

Se você não suprimir o segmento GDI+ de fundo, os comandos DDE podem ser emitidos prematuramente para o aplicativo antes de sua janela principal ter sido criada. Os comandos DDE emitidos pelo shell podem ser prematuramente abortados, resultando em mensagens de erro.

## <a name="file-manager-drag-and-drop"></a><a name="_core_file_manager_drag_and_drop"></a>Arrastar e soltar o gerenciador de arquivos

Os arquivos podem ser arrastados da janela de exibição de arquivos no Gerenciador de arquivos ou no Explorador de arquivos para uma janela em seu aplicativo. Você pode, por exemplo, habilitar que um ou mais arquivos sejam arrastados para a janela principal de um aplicativo MDI, onde o aplicativo poderia recuperar os nomes dos arquivos e abrir janelas de crianças MDI para esses arquivos.

Para habilitar arrastar e soltar o arquivo no aplicativo, o Assistente de Aplicativo do MFC grava `InitInstance`uma chamada para a função de membro [CWnd](../mfc/reference/cwnd-class.md) [DragAcceptFiles](../mfc/reference/cwnd-class.md#dragacceptfiles) para a janela principal do quadro em seu . Você pode remover essa chamada se não quiser implementar o recurso arrastar e soltar.

> [!NOTE]
> Você também pode implementar recursos mais gerais de arrastar e soltar — arrastando dados entre ou dentro de documentos — com o OLE. Para obter informações, consulte o artigo [OLE arrastar e soltar](../mfc/drag-and-drop-ole.md).

## <a name="keeping-track-of-the-most-recently-used-documents"></a><a name="_core_keeping_track_of_the_most_recently_used_documents"></a>Mantendo o controle dos documentos usados mais recentemente

À medida que o usuário abre e fecha arquivos, o objeto do aplicativo mantém o controle dos quatro arquivos mais usados recentemente. Os nomes desses arquivos são adicionados ao menu Arquivo e atualizados quando eles mudam. O framework armazena esses nomes de arquivo no registro ou no arquivo .ini, com o mesmo nome do seu projeto e os lê do arquivo quando o aplicativo é iniciado. A `InitInstance` substituição que o MFC Application Wizard cria para você inclui uma chamada para a função de membro [do CWinApp](../mfc/reference/cwinapp-class.md) [LoadStdProfileSettings](../mfc/reference/cwinapp-class.md#loadstdprofilesettings), que carrega informações do arquivo registry ou .ini, incluindo os nomes de arquivo mais recentemente usados.

Estas entradas são armazenadas da seguinte forma:

- No Windows NT, Windows 2000 e, posteriormente, o valor é armazenado em uma chave de registro.

- No Windows 3.x, o valor é armazenado no WIN. Arquivo INI.

- No Windows 95 e posterior, o valor é armazenado em uma versão em cache do WIN. Ini.

## <a name="see-also"></a>Confira também

[CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)
