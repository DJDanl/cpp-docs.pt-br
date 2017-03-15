---
title: "Servi&#231;os CWinApp especiais | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "LoadStdProfileSettings"
  - "EnableShellOpen"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "objetos de aplicativo [C++], serviços"
  - "Classe CWinApp, arrastar e soltar do Gerenciador de Arquivos"
  - "Classe CWinApp, inicializando GDI+"
  - "Classe CWinApp, documentos usados recentemente"
  - "Classe CWinApp, serviços"
  - "Classe CWinApp, registro de shell"
  - "arrastar e soltar [C++], Arquivos "
  - "Método DragAcceptFiles"
  - "Método EnableShellOpen"
  - "Arquivos  [C++], arrastar e soltar"
  - "Arquivos  [C++], usado mais recentemente"
  - "GDI+, inicializando para MFC"
  - "GDI+, suprimindo thread em segundo plano [MFC]"
  - "Método LoadStdProfileSettings"
  - "MFC [C++], operações de arquivo"
  - "MFC [C++], lista de arquivos usados mais recentemente"
  - "MFC [C++], registro de shell"
  - "Listas MRU"
  - "registrando tipos de arquivo"
  - "Método RegisterShellFileTypes"
  - "registro [C++], shell"
  - "registro [C++], arquivos usados mais recentemente"
  - "serviços, fornecido por CWinApp"
  - "Shell, registrando tipos de arquivo"
ms.assetid: 0480cd01-f629-4249-b221-93432d95b431
caps.latest.revision: 10
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Servi&#231;os CWinApp especiais
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Além de executar a mensagem e fazendo um loop pela você uma oportunidade de inicializar o aplicativo e de limpá\-lo depois deles, [CWinApp](../mfc/reference/cwinapp-class.md) fornece vários outros serviços.  
  
##  <a name="_core_shell_registration"></a> Registro de Shell  
 Por padrão, o assistente de aplicativo MFC possibilita para que o usuário para abrir arquivos de dados que seu aplicativo criou clicando duas vezes no Explorador de Arquivos ou no gerenciador de arquivos.  Se seu aplicativo for um aplicativo MDI e especificar uma extensão para os arquivos que seu aplicativo cria, o assistente de aplicativo MFC adiciona chamadas a [RegisterShellFileTypes](../Topic/CWinApp::RegisterShellFileTypes.md) e as funções de membro de [EnableShellOpen](../Topic/CWinApp::EnableShellOpen.md) de [CWinApp](../mfc/reference/cwinapp-class.md) a `InitInstance` substituem que grava para você.  
  
 `RegisterShellFileTypes` registra tipos de documento do seu aplicativo com o Explorador de Arquivos ou o gerenciador de arquivos.  A função adiciona entradas a base de dados do registro que mantêm o windows.  As entradas anteriores cada tipo de documento, associam uma extensão de arquivo com o tipo de arquivo, especifique uma linha de comando para abrir o aplicativo, e especificam um comando de \(DDE\) de troca dinâmicas de dados abrir um documento desse tipo.  
  
 `EnableShellOpen` concluir o processo permitindo seu aplicativo receber comandos de DDE do Explorador de Arquivos ou o gerenciador de arquivos abra o arquivo escolhido pelo usuário.  
  
 Esse suporte automático de registro em `CWinApp` elimina a necessidade de enviar um arquivo .reg com o aplicativo ou de fazer o trabalho da instalação especial.  
  
 Se você deseja inicializar GDI\+ para seu aplicativo \(chamando [GdiplusStartup](_gdiplus_FUNC_GdiplusStartup_token_input_output_) na função de [InitInstance](../Topic/CWinApp::InitInstance.md) \), é necessário para suprimir o thread em segundo plano de GDI\+.  
  
 Você pode fazer isso definindo o membro de **SuppressBackgroundThread** da estrutura de [GdiplusStartupInput](_gdiplus_STRUC_GdiplusStartupInput) a **Verdadeiro**.  Para suprimir o thread em segundo plano de GDI\+, chamadas de **NotificationHook** e de **NotificationUnhook** \(consulte [GdiplusStartupOutput](_gdiplus_STRUC_GdiplusStartupOutput)\) deve ser feito apenas antes de inserir e saia do loop de mensagem do aplicativo.  Consequentemente, um bom local para chamar **GdiplusStartup** e as funções de notificação de gancho estariam em uma substituição da função virtual [CWinApp::Run](../Topic/CWinApp::Run.md), conforme mostrado abaixo:  
  
 [!code-cpp[NVC_MFCDocView#6](../mfc/codesnippet/CPP/special-cwinapp-services_1.cpp)]  
  
 Se você não suprime o thread em segundo plano de GDI\+, os comandos de prematuramente DDE podem ser emitidos para o aplicativo antes que a janela principal foi criada.  Os comandos de DDE geradas pelo shell prematuramente podem ser cancelada, resultando em mensagens de erro.  
  
##  <a name="_core_file_manager_drag_and_drop"></a> Arraste e solte do gerenciador de arquivos  
 Os arquivos podem ser arrastados da janela de exibição do arquivo no gerenciador de arquivos ou do gerenciador de Arquivos para uma janela em seu aplicativo.  Você pode, por exemplo, habilitar um ou mais arquivos a ser arrastados a janela principal de um aplicativo MDI, onde o aplicativo pode recuperar os nomes de arquivo e abrir janelas filho MDI para esses arquivos.  
  
 Para habilitar o arquivo arrastar e soltar em seu aplicativo, as gravações do assistente de aplicativo MFC uma chamada à função de membro [DragAcceptFiles](../Topic/CWnd::DragAcceptFiles.md) de [CWnd](../Topic/CWnd%20Class.md) da janela principal do quadro em seu `InitInstance`.  Você pode remover essa chamada se você não desejar implementar o recurso de arrastar e soltar.  
  
> [!NOTE]
>  Você também pode implementar um arrastar e soltar mais geral que arrasta dados entre ou no documento com OLE.  Para obter mais informações, consulte o artigo [Arraste e solte \(OLE\)](../mfc/drag-and-drop-ole.md).  
  
##  <a name="_core_keeping_track_of_the_most_recently_used_documents"></a> Mantendo o controle de documentos usados recentemente  
 Porque o usuário abrir e fechar arquivos, o objeto do aplicativo mantém acompanha dos quatro arquivos usados recentemente.  Os nomes desses arquivos são adicionados ao menu arquivo e atualizados quando são alterados.  A estrutura armazena esses nomes de arquivo no Registro ou no arquivo .ini, com o mesmo nome do projeto e lê\-los do arquivo quando o aplicativo inicia.  A substituição de `InitInstance` que o assistente de aplicativo MFC cria para incluir uma chamada à função de membro [LoadStdProfileSettings](../Topic/CWinApp::LoadStdProfileSettings.md)de [CWinApp](../mfc/reference/cwinapp-class.md) , que carrega as informações de Registro ou do arquivo .ini, incluindo os nomes de arquivo usados recentemente.  
  
 Essas entradas são armazenadas como segue:  
  
-   No Windows NT, Windows 2000, e em versões posteriores, o valor é armazenado para uma chave do Registro.  
  
-   Nas janelas 3.x, o valor é armazenado no arquivo de WIN.INI.  
  
-   No Windows 95 e versões posteriores, o valor é armazenado em uma versão armazenada em cachê de WIN.INI.  
  
## Consulte também  
 [CWinApp: a classe do aplicativo](../Topic/CWinApp:%20The%20Application%20Class.md)