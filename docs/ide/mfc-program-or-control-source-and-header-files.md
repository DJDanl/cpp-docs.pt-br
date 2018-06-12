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
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33340223"
---
# <a name="mfc-program-or-control-source-and-header-files"></a>Programa MFC ou origem de controle e arquivos de cabeçalho
Os arquivos a seguir são criados quando você cria um projeto MFC no Visual Studio, dependendo das opções selecionadas para o projeto criado. Por exemplo, o projeto contém os arquivos *Nome_do_projeto*dlg.cpp e *Nome_do_projeto*dlg.h somente se você cria uma classe ou um projeto baseado em caixa de diálogo.  
  
 Todos esses arquivos estão localizados no diretório *Nome_do_projeto* e na pasta Arquivos de Cabeçalho (arquivos .h) ou na pasta Arquivos de Origem (arquivos .cpp) do Gerenciador de Soluções.  
  
|Nome do arquivo|Descrição|  
|---------------|-----------------|  
|*Nome_do_projeto*.h|O arquivo de inclusão principal do programa ou da DLL. Contém todos os símbolos globais e diretivas `#include` para outros arquivos de cabeçalho. Deriva a classe `CPrjnameApp` de `CWinApp` e declara uma função de membro `InitInstance`. Para um controle, a classe `CPrjnameApp` é derivada de `COleControlModule`.|  
|*Nome_do_projeto*.cpp|O arquivo de origem do programa principal. Cria um objeto da classe `CPrjnameApp`, que é derivada de `CWinApp`, e substitui a função de membro `InitInstance`.<br /><br /> Para executáveis, `CPrjnameApp::InitInstance` executa várias operações. Registra modelos de documento, que servem como uma conexão entre documentos e exibições; cria uma janela com moldura principal; e cria um documento vazio (ou abre um documento, caso um seja especificado como um argumento de linha de comando para o aplicativo).<br /><br /> Para DLLs e controles ActiveX (anteriormente OLE), `CProjNameApp::InitInstance` registra o alocador de objeto do controle no OLE chamando `COleObjectFactory::RegisterAll` e faz uma chamada a `AfxOLEInit`. Além disso, a função de membro `CProjNameApp::ExitInstance` é usada para descarregar o controle da memória com uma chamada a **AfxOleTerm**.<br /><br /> Esse arquivo também registra e cancela o registro do controle no banco de dados de registro do Windows com a implementação das funções `DllRegisterServer` e `DllUnregisterServer`.|  
|*Nome_do_projeto*ctrl.h, *Nome_do_projeto*ctrl.cpp|Declaram e implementam a classe `CProjnameCtrl`. `CProjnameCtrl` é derivado de `COleControl`, e são definidas as implementações de esqueleto de algumas funções de membro que inicializam, desenham e serializam (carregam e salvam) o controle. Os mapas de mensagens, eventos e expedição também são definidos.|  
|*Nome_do_projeto*dlg.cpp, *Nome_do_projeto*dlg.h|Criados se um aplicativo baseado em caixa de diálogo é escolhido. Os arquivos derivam e implementam a classe de caixa de diálogo, chamada `CProjnameDlg`, e incluem funções de membro de esqueleto para inicializar uma caixa de diálogo e executar a DDX (troca de dados da caixa de diálogo). A classe de caixa de diálogo Sobre também é colocada nesses arquivos, em vez de em *Nome_do_projeto*.cpp.|  
|Dlgproxy.cpp, Dlgproxy.h|Em um diálogo baseado em programa, a implementação e o arquivo de cabeçalho para a classe proxy de Automação do projeto da caixa de diálogo principal. Isso é usado somente se você escolheu o suporte de Automação.|  
|*Nome_do_projeto*doc.cpp, *Nome_do_projeto*doc.h|Derivam e implementam a classe de documento, chamada `CProjnameDoc`, e incluem funções de membro de esqueleto para inicializar um documento, serializar (salvar e carregar) um documento, bem como implementar o diagnóstico de depuração.|  
|*Nome_do_projeto*set.h/.cpp|Criado se você criar um programa que dá suporte a um banco de dados e que contém a classe do conjunto de registros.|  
|*Nome_do_projeto*view.cpp, *Nome_do_projeto*view.h|Derivam e implementam a classe de exibição, chamada `CProjnameView`, que é usada para exibir e imprimir os dados do documento. A classe `CProjnameView` é derivada de uma das seguintes classes MFC:<br /><br /> -   [CEditView](../mfc/reference/ceditview-class.md)<br />-   [CFormView](../mfc/reference/cformview-class.md)<br />-   [CRecordView](../mfc/reference/crecordview-class.md)<br />-   [COleDBRecordView](../mfc/reference/coledbrecordview-class.md)<br />-   [CTreeView](../mfc/reference/ctreeview-class.md)<br />-   [CListView](../mfc/reference/clistview-class.md)<br />-   [CRichEditView](../mfc/reference/cricheditview-class.md)<br />-   [CScrollView](../mfc/reference/cscrollview-class.md)<br />-   [CView](../mfc/reference/cview-class.md)<br />-   [CHTMLView](../mfc/reference/chtmlview-class.md)<br />-   [CHTMLEditView](../mfc/reference/chtmleditview-class.md)<br /><br /> A classe de exibição do projeto contém funções de membro de esqueleto para desenhar a exibição e implementar o diagnóstico de depuração. Se você habilitou o suporte para impressão, as entradas do mapa de mensagens são adicionadas às mensagens de comando de impressão, configuração de impressão e visualização de impressão. Essas entradas chamam as funções de membro correspondentes na classe base de exibição.|  
|*Nome_do_projeto*PropPage.h, *Nome_do_projeto*PropPage.cpp|Declaram e implementam a classe `CProjnamePropPage`. `CProjnamePropPage` é derivado de `COlePropertyPage` e uma função de membro de esqueleto, `DoDataExchange`, é fornecida para implementar a troca e a validação de dados.|  
|IPframe.cpp, IPframe.h|Criado se a opção Minisservidor ou Servidor Completo estiver selecionada na página **Opções de Automação** do assistente de aplicativo (etapa 3 de 6). Os arquivos derivam e implementam a classe de janela com moldura in-loco, chamada **CInPlaceFrame**, usada quando o servidor está em vigor, ativado por um programa de contêiner.|  
|Mainfrm.cpp, Mainfrm.h|Derivam a classe **CMainFrame** de [CFrameWnd](../mfc/reference/cframewnd-class.md) (para aplicativos SDI) ou [CMDIFrameWnd](../mfc/reference/cmdiframewnd-class.md) (para aplicativos MDI). A classe **CMainFrame** manipula a criação de botões de barra de ferramentas e da barra de status se as opções correspondentes estão selecionadas na página **Opções do Aplicativo** do assistente de aplicativo (etapa 4 de 6). Para obter informações sobre como usar **CMainFrame**, confira [As classes de janela com moldura criadas pelo Assistente de Aplicativo](../mfc/frame-window-classes-created-by-the-application-wizard.md).|  
|Childfrm.cpp, Childfrm.h|Derivam a classe **CChildFrame** de [CMDIChildWnd](../mfc/reference/cmdichildwnd-class.md). A classe **CChildFrame** é usada para janelas com moldura de documentos MDI. Esses arquivos são sempre criados se você seleciona a opção MDI.|  
  
## <a name="see-also"></a>Consulte também  
 [Tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md)   
 [Programa ATL ou origem de controle e arquivos de cabeçalho](../ide/atl-program-or-control-source-and-header-files.md)   
 [Projetos CLR](../ide/files-created-for-clr-projects.md)