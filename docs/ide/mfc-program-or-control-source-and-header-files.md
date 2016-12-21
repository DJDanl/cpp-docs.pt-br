---
title: "Programa MFC ou origem de controle e arquivos de cabe&#231;alho | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tipos de arquivo [C++], Origem e cabeçalho MFC"
ms.assetid: f61419a8-bf69-4bbb-8f7c-1734be5e6db6
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Programa MFC ou origem de controle e arquivos de cabe&#231;alho
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os seguintes arquivos são criados quando você cria um projeto MFC em Visual Studio, dependendo das opções selecionadas para o projeto que você cria.  Por exemplo, o seu projeto contém  *nomedoprojeto*dlg.cpp e  *nomedoprojeto*dlg.h arquivos somente se você criar uma classe ou um projeto baseado em diálogo.  
  
 Todos esses arquivos estão localizados na  *nomedoprojeto* e diretório, na pasta arquivos de cabeçalho \(arquivos. h\) ou a pasta arquivos de origem \(arquivos. cpp\) no Solution Explorer.  
  
|File name|Descrição|  
|---------------|---------------|  
|*Nomedoprojeto*. h|O arquivo de inclusão principal do programa ou DLL.  Ele contém todos os símbolos globais e `#include` diretivas para outros arquivos de cabeçalho.  Ele deriva de `CPrjnameApp` de classe de `CWinApp` e declara um `InitInstance` a função de membro.  Para um controle, o `CPrjnameApp` classe é derivada de `COleControlModule`.|  
|*Nomedoprojeto*. cpp|O arquivo de origem do programa principal.  Ele cria um objeto da classe `CPrjnameApp`, que é derivada de `CWinApp`e substitui o `InitInstance` a função de membro.<br /><br /> Para executáveis, `CPrjnameApp::InitInstance` faz várias coisas.  Ele registra os modelos de documento, que servem como uma conexão entre documentos e modos de exibição; cria uma janela de quadro principal; e cria um documento vazio \(ou abre um documento se alguma for especificada como um argumento de linha de comando para o aplicativo\).<br /><br /> Para controles de DLLs e ActiveX \(anteriormente conhecido como OLE\), `CProjNameApp::InitInstance` registra a fábrica de objeto do controle com OLE chamando `COleObjectFactory::RegisterAll` e faz uma chamada para `AfxOLEInit`.  Além disso, a função de membro `CProjNameApp::ExitInstance` é usado para descarregar o controle da memória com uma chamada para  **AfxOleTerm**.<br /><br /> Este arquivo também registra e cancela o registro de controle do banco de dados de registro do Windows, Implementando o `DllRegisterServer` e `DllUnregisterServer` funções.|  
|*Nomedoprojeto*ctrl.h,  *nomedoprojeto*ctrl.cpp|Declarar e implementar a `CProjnameCtrl` classe.  `CProjnameCtrl`é derivada de `COleControl`, e implementações de esqueleto de algumas funções de membro são definidas que inicializar, desenhar e serializar \(carregar e salvar\) o controle.  Mensagem de evento e mapas de despacho também são definidos.|  
|*Nomedoprojeto*dlg.cpp,  *nomedoprojeto*dlg.h|Se você escolher um aplicativo baseado em diálogo criado.  Os arquivos de derivar e implementar a classe de diálogo, chamada `CProjnameDlg`e incluem as funções de membro de esqueleto para inicializar uma caixa de diálogo e realizar a troca de dados de caixa de diálogo \(DDX\).  Sua classe de diálogo sobre também é colocada nesses arquivos, em vez de em  *nomedoprojeto*. cpp.|  
|Dlgproxy.cpp, Dlgproxy.h|Em um diálogo programa, a implementação e o cabeçalho de arquivo para a classe de proxy de automação do projeto para a caixa de diálogo principal.  Isso é usado apenas se você tiver escolhido o suporte de automação.|  
|*Nomedoprojeto*doc.cpp,  *nomedoprojeto*doc.h|Derivar e implementar a classe de documento, chamada `CProjnameDoc`e incluem funções de membro de esqueleto para inicializar um documento, serializar \(Salvar e carregar\) um documento e implementar o diagnóstico de depuração.|  
|*Nomedoprojeto*set.h\/.cpp|Se você criar um programa que oferece suporte a um banco de dados e contém a classe do conjunto de registros criado.|  
|*Nomedoprojeto*view.cpp,  *nomedoprojeto*view.h|Derivar e implementar a classe de modo de exibição, chamada `CProjnameView`, que é usado para exibir e imprimir os dados do documento.  O `CProjnameView` classe é derivada de uma das seguintes classes MFC:<br /><br /> -   [CEditView](../Topic/CEditView%20Class.md)<br />-   [CFormView](../mfc/reference/cformview-class.md)<br />-   [CRecordView](../mfc/reference/crecordview-class.md)<br />-   [COleDBRecordView](../mfc/reference/coledbrecordview-class.md)<br />-   [CTreeView](../mfc/reference/ctreeview-class.md)<br />-   [CListView](../mfc/reference/clistview-class.md)<br />-   [CRichEditView](../mfc/reference/cricheditview-class.md)<br />-   [CScrollView](../mfc/reference/cscrollview-class.md)<br />-   [CView](../Topic/CView%20Class.md)<br />-   [CHTMLView](../mfc/reference/chtmlview-class.md)<br />-   [CHTMLEditView](../mfc/reference/chtmleditview-class.md)<br /><br /> Classe de modo de exibição do projeto contém funções de membro de esqueleto para desenhar o modo de exibição e implementar o diagnóstico de depuração.  Se você tiver habilitado o suporte para impressão, em seguida, entradas de mapa da mensagem são adicionadas para a configuração de impressão, impressão e imprimam mensagens de comando de visualização.  Essas entradas chamam as funções de membro correspondente na classe base do modo de exibição.|  
|*Nomedoprojeto*PropPage.h,  *nomedoprojeto*PropPage.cpp|Declarar e implementar a `CProjnamePropPage` classe.  `CProjnamePropPage`é derivada de `COlePropertyPage` e uma função de membro de esqueleto, `DoDataExchange`, é fornecido para implementar a troca de dados e validação.|  
|IPframe.cpp, IPframe.h|Se a opção Mini\-Server ou Full\-servidor está selecionada no Assistente do aplicativo criado  **Opções de automação** página \(etapa 3 de 6\).  Os arquivos de derivar e implementar a classe de janela de quadro no local, denominada  **CInPlaceFrame**, usado quando o servidor esteja in\-loco ativado por um programa do recipiente.|  
|Mainfrm.cpp, Mainfrm.h|Derivar o  **CMainFrame** classe a partir de um  [CFrameWnd](../mfc/reference/cframewnd-class.md) \(para aplicativos SDI\) ou  [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) \(para aplicativos MDI\).  O  **CMainFrame** classe controla a criação de botões da barra de ferramentas e a barra de status, se as opções correspondentes são selecionadas no Assistente do aplicativo  **Opções de aplicativos** página \(etapa 4 de 6\).  Para obter informações sobre o uso de  **CMainFrame**, consulte  [A janela de quadro Classes criadas pelo Assistente de aplicativo](../mfc/frame-window-classes-created-by-the-application-wizard.md).|  
|Childfrm.cpp, Childfrm.h|Derivar o  **CChildFrame** de classe de  [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md).  O  **CChildFrame** classe é usada para janelas de quadro do documento MDI.  Esses arquivos são criados sempre se você selecionar a opção MDI.|  
  
## Consulte também  
 [Tipos de arquivo criados para projetos do Visual C\+\+](../ide/file-types-created-for-visual-cpp-projects.md)   
 [Programa ATL ou origem de controle e arquivos de cabeçalho](../ide/atl-program-or-control-source-and-header-files.md)   
 [Projetos CLR](../ide/files-created-for-clr-projects.md)