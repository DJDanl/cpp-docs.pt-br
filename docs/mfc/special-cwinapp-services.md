---
title: Serviços CWinApp especiais | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- LoadStdProfileSettings
- EnableShellOpen
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cd6af2ab524711c591772c28ed47742e6aa406ad
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36955866"
---
# <a name="special-cwinapp-services"></a>Serviços CWinApp especiais
Além de executar o loop de mensagem e fornecendo uma oportunidade para inicializar o aplicativo e limpar depois dele, [CWinApp](../mfc/reference/cwinapp-class.md) fornece vários outros serviços.  
  
##  <a name="_core_shell_registration"></a> Registro de shell  
 Por padrão, o Assistente de aplicativo MFC torna possível para o usuário abrir arquivos de dados que seu aplicativo foi criado, clique duas vezes no Explorador de arquivos ou no Gerenciador de arquivos. Se seu aplicativo é um aplicativo MDI e você especificar uma extensão para os arquivos de seu aplicativo cria, o Assistente de aplicativo MFC adiciona chamadas para o [RegisterShellFileTypes](../mfc/reference/cwinapp-class.md#registershellfiletypes) e [EnableShellOpen](../mfc/reference/cwinapp-class.md#enableshellopen)funções membro de [CWinApp](../mfc/reference/cwinapp-class.md) para o `InitInstance` substituição que ele grava para você.  
  
 `RegisterShellFileTypes` Registra tipos de documento do aplicativo com o Explorador de arquivos ou no Gerenciador de arquivos. A função adiciona entradas para o banco de dados de registro que o Windows mantém. As entradas de registrar cada tipo de documento, associar uma extensão de arquivo com o tipo de arquivo, especifique uma linha de comando para abrir o aplicativo e especificar um comando de intercâmbio (DDE) de dados dinâmicos para abrir um documento desse tipo.  
  
 `EnableShellOpen` conclui o processo, permitindo que o seu aplicativo receber comandos DDE do Explorador de arquivos ou o Gerenciador de arquivos para abrir o arquivo escolhido pelo usuário.  
  
 Esse suporte de registro automático em `CWinApp` elimina a necessidade de enviar um arquivo. reg com o seu aplicativo ou para fazer o trabalho de instalação especial.  
  
 Se você deseja inicializar GDI+ para seu aplicativo (chamando [GdiplusStartup](https://msdn.microsoft.com/library/ms534077) no seu [InitInstance](../mfc/reference/cwinapp-class.md#initinstance) função), você tem que suprimir o thread de plano de fundo GDI+.  
  
 Você pode fazer isso definindo o `SuppressBackgroundThread` membro o [GdiplusStartupInput](https://msdn.microsoft.com/library/ms534067) estrutura para **TRUE**. Quando suprimindo o GDI+ em segundo plano thread, o `NotificationHook` e `NotificationUnhook` chamadas devem ser feitas apenas anteriores entrando e saindo do loop de mensagens do aplicativo. Para obter mais informações sobre essas chamadas, consulte [GdiplusStartupOutput](https://msdn.microsoft.com/library/ms534068). Portanto, um bom lugar para chamar `GdiplusStartup` e as funções de gancho de notificação está em uma substituição da função virtual [CWinApp:: Run](../mfc/reference/cwinapp-class.md#run), conforme mostrado abaixo:  
  
 [!code-cpp[NVC_MFCDocView#6](../mfc/codesnippet/cpp/special-cwinapp-services_1.cpp)]  
  
 Se você não suprima o plano de fundo GDI+ thread, DDE comandos podem ser emitidos prematuramente ao aplicativo antes de criar a janela principal. Os comandos DDE emitidos pelo shell podem ser prematuramente anulados, resultando em mensagens de erro.  
  
##  <a name="_core_file_manager_drag_and_drop"></a> Gerenciador de arquivos de arrastar e soltar  
 Arquivos podem ser arrastados da janela de exibição de arquivo no Gerenciador de arquivos ou no Explorador de arquivos em uma janela no seu aplicativo. Você pode, por exemplo, permitir que um ou mais arquivos para ser arrastado para a janela principal do aplicativo MDI, onde o aplicativo pode recuperar os nomes de arquivo e abra janelas de filho MDI para esses arquivos.  
  
 Para permitir arquivo arrastar e soltar em seu aplicativo, o Assistente de aplicativo MFC grava uma chamada para o [CWnd](../mfc/reference/cwnd-class.md) função de membro [DragAcceptFiles](../mfc/reference/cwnd-class.md#dragacceptfiles) da janela do quadro principal no seu `InitInstance`. Se você não quiser implementar o recurso de arrastar e soltar, você pode remover essa chamada.  
  
> [!NOTE]
>  Você também pode implementar os recursos de arrastar e soltar mais gerais, arrastando os dados entre ou dentro de documentos — com OLE. Para obter informações, consulte o artigo [arrastar e soltar (OLE)](../mfc/drag-and-drop-ole.md).  
  
##  <a name="_core_keeping_track_of_the_most_recently_used_documents"></a> Controlando o máximo de documentos usados recentemente  
 Como o usuário abre e fecha os arquivos, o objeto de aplicativo controla de quatro arquivos usados mais recentemente. Os nomes desses arquivos são adicionados ao menu Arquivo e atualizados quando elas forem alteradas. O framework armazena esses nomes de arquivo no registro ou no arquivo. ini, com o mesmo nome do seu projeto e lê-los a partir do arquivo quando o aplicativo é iniciado. O `InitInstance` substituir que o Assistente de aplicativo MFC cria para você inclui uma chamada para o [CWinApp](../mfc/reference/cwinapp-class.md) função de membro [LoadStdProfileSettings](../mfc/reference/cwinapp-class.md#loadstdprofilesettings), que carrega as informações do registro ou. ini arquivo, incluindo mais recentemente usados nomes de arquivo.  
  
 Essas entradas são armazenadas da seguinte maneira:  
  
-   No Windows NT, Windows 2000 e posterior, o valor é armazenado em uma chave do registro.  
  
-   No Windows 3. x, o valor é armazenado em arquivos WIN. Arquivo INI.  
  
-   No Windows 95 e posterior, o valor é armazenado em uma versão em cache do WIN. INI.  
  
## <a name="see-also"></a>Consulte também  
 [CWinApp: a classe do aplicativo](../mfc/cwinapp-the-application-class.md)