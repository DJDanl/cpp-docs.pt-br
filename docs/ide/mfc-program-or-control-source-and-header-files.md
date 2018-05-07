---
title: Programa MFC ou origem de controle e arquivos de cabeçalho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- file types [C++], MFC source and header
ms.assetid: f61419a8-bf69-4bbb-8f7c-1734be5e6db6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5ab1ed04b9890fbed8de8b59354ab36d7be063e7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="mfc-program-or-control-source-and-header-files"></a>Programa MFC ou origem de controle e arquivos de cabeçalho
Os seguintes arquivos são criados quando você cria um projeto no Visual Studio, dependendo das opções selecionadas para o projeto que você criar. Por exemplo, seu projeto contém *NomeDoProjeto*dlg.cpp e *NomeDoProjeto*dlg.h arquivos somente se você criar uma classe ou um projeto baseado na caixa de diálogo.  
  
 Todos esses arquivos estão localizados no *NomeDoProjeto* diretório e na pasta arquivos de cabeçalho (arquivos. h) ou pasta de arquivos de origem (arquivos. cpp) no Gerenciador de soluções.  
  
|Nome do arquivo|Descrição|  
|---------------|-----------------|  
|*NomeDoProjeto*. h|O arquivo de inclusão principal para o programa ou DLL. Ele contém todos os símbolos globais e `#include` diretivas para outros arquivos de cabeçalho. Deriva a `CPrjnameApp` classe `CWinApp` e declara um `InitInstance` função de membro. Para um controle, o `CPrjnameApp` classe é derivada de `COleControlModule`.|  
|*NomeDoProjeto*. cpp|O arquivo de origem do programa principal. Ele cria um objeto da classe `CPrjnameApp`, que é derivada de `CWinApp`e substitui o `InitInstance` função de membro.<br /><br /> Para executáveis, `CPrjnameApp::InitInstance` faz várias coisas. Registra os modelos de documento, que servem como uma conexão entre documentos e exibições; cria uma janela do quadro principal; e cria um documento vazio (ou abrir um documento, se um for especificado como um argumento de linha de comando para o aplicativo).<br /><br /> Para controles ActiveX (anteriormente OLE) e DLLs, `CProjNameApp::InitInstance` registra a fábrica do objeto do controle com OLE chamando `COleObjectFactory::RegisterAll` e faz uma chamada para `AfxOLEInit`. Além disso, a função de membro `CProjNameApp::ExitInstance` é usado para descarregar o controle da memória com uma chamada para **AfxOleTerm**.<br /><br /> Esse arquivo também registra e cancela o registro de controle do banco de dados de registro do Windows com a implementação de `DllRegisterServer` e `DllUnregisterServer` funções.|  
|*NomeDoProjeto*ctrl.h, *NomeDoProjeto*ctrl.cpp|Declare e implemente o `CProjnameCtrl` classe. `CProjnameCtrl` é derivado de `COleControl`, e implementações de esqueleto de algumas funções de membro são definidas que inicializar, desenhar e serializar (carregar e salvar) o controle. Mensagem de evento e mapas de expedição também são definidos.|  
|*NomeDoProjeto*dlg.cpp, *NomeDoProjeto*dlg.h|Criado se você escolher um aplicativo baseado na caixa de diálogo. Os arquivos de derivar e implementar a classe de caixa de diálogo, denominada `CProjnameDlg`e incluem funções de membro de esqueleto para inicializar uma caixa de diálogo e executar a troca de dados de caixa de diálogo (DDX). A classe de caixa de diálogo sobre também será colocado nesses arquivos em vez de usar *NomeDoProjeto*. cpp.|  
|Dlgproxy.cpp, Dlgproxy.h|Em um diálogo programa, a implementação e o cabeçalho de arquivo para a classe de proxy de automação do projeto para a caixa de diálogo principal. Isso é usado apenas se você tiver escolhido o suporte de automação.|  
|*NomeDoProjeto*doc.cpp, *NomeDoProjeto*doc.h|Derivar e implementar a classe de documento, denominada `CProjnameDoc`e incluem funções de membro de esqueleto para inicializar um documento, serializar (Salvar e carregar) um documento e implementar diagnóstico de depuração.|  
|*NomeDoProjeto*set.h/.cpp|Criado se você criar um programa que oferece suporte a um banco de dados e contém a classe do conjunto de registros.|  
|*NomeDoProjeto*view.cpp, *NomeDoProjeto*view.h|Derivar e implementar a classe de exibição, denominada `CProjnameView`, que é usada para exibir e imprimir os dados do documento. O `CProjnameView` classe é derivada de uma das seguintes classes MFC:<br /><br /> -   [CEditView](../mfc/reference/ceditview-class.md)<br />-   [CFormView](../mfc/reference/cformview-class.md)<br />-   [CRecordView](../mfc/reference/crecordview-class.md)<br />-   [COleDBRecordView](../mfc/reference/coledbrecordview-class.md)<br />-   [CTreeView](../mfc/reference/ctreeview-class.md)<br />-   [CListView](../mfc/reference/clistview-class.md)<br />-   [CRichEditView](../mfc/reference/cricheditview-class.md)<br />-   [CScrollView](../mfc/reference/cscrollview-class.md)<br />-   [CView](../mfc/reference/cview-class.md)<br />-   [CHTMLView](../mfc/reference/chtmlview-class.md)<br />-   [CHTMLEditView](../mfc/reference/chtmleditview-class.md)<br /><br /> Classe de exibição do projeto contém funções de membro de esqueleto para desenhar a exibição e implementar diagnóstico de depuração. Se você tiver habilitado o suporte para impressão, em seguida, entradas de mapa de mensagem são adicionadas para a instalação de impressão, imprimir e mensagens de comando de visualização de impressão. Essas entradas de chamam as funções de membro correspondente na classe base do modo de exibição.|  
|*NomeDoProjeto*PropPage.h, *NomeDoProjeto*PropPage.cpp|Declare e implemente o `CProjnamePropPage` classe. `CProjnamePropPage` é derivado de `COlePropertyPage` e uma função de membro de esqueleto, `DoDataExchange`, é fornecido para implementar a troca de dados e a validação.|  
|IPframe.cpp, IPframe.h|Criado se a opção miniservidor ou servidor completo for selecionada no Assistente do aplicativo **opções de automação** página (etapa 3 de 6). Os arquivos de derivar e implementar a classe de janela do quadro no local, denominada **CInPlaceFrame**, usado quando o servidor está em vigor ativado por um programa do contêiner.|  
|Mainfrm.cpp, Mainfrm.h|Derivar o **CMainFrame** classe do [CFrameWnd](../mfc/reference/cframewnd-class.md) (para aplicativos SDI) ou [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) (para aplicativos MDI). O **CMainFrame** classe manipula a criação de botões de barra de ferramentas e barra de status, se as opções correspondentes são selecionadas no Assistente do aplicativo **aplicativo opções** página (etapa 4 de 6). Para obter informações sobre como usar **CMainFrame**, consulte [a janela do quadro Classes criadas pelo Assistente de aplicativo](../mfc/frame-window-classes-created-by-the-application-wizard.md).|  
|Childfrm.cpp, Childfrm.h|Derivar o **CChildFrame** classe [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md). O **CChildFrame** classe é usada para janelas de quadro de documentos MDI. Esses arquivos são criados sempre se você selecionar a opção de MDI.|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)   
 [Programa ATL ou origem de controle e arquivos de cabeçalho](../ide/atl-program-or-control-source-and-header-files.md)   
 [Projetos CLR](../ide/files-created-for-clr-projects.md)