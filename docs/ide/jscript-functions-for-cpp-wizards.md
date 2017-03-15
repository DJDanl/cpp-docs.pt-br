---
title: "Fun&#231;&#245;es JScript para assistentes do C++ | Microsoft Docs"
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
  - "métodos JScript de assistente"
  - "métodos JScript de assistente, criando assistentes C++"
ms.assetid: f3046c56-cf67-4aaa-919e-8c066bfb6760
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#245;es JScript para assistentes do C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

|||  
|-|-|  
|[AddATLSupportToProject](../ide/addatlsupporttoproject.md)|Adiciona o suporte ATL para um projeto MFC.|  
|[AddCoclassFromFile](../Topic/AddCoclassFromFile.md)|Processa e insere o arquivo do projeto. idl um arquivo de modelo que contém um coclass.|  
|[AddCommonConfig](../ide/addcommonconfig.md)|Adiciona as configurações padrão para o projeto.|  
|[AddFilesToProject](../Topic/AddFilesToProject.md)|Adiciona todos os arquivos para o projeto de acordo com a lista no arquivo Templates.inf.|  
|[AddInterfaceFromFile](../ide/addinterfacefromfile.md)|Processa e insere o arquivo do projeto IDL um arquivo de modelo que contém uma interface.|  
|[CanAddATLClass](../ide/canaddatlclass.md)|Chamado pelo Assistente para verificar se o projeto é compatível com o Assistente de código que está prestes a ser executado \(em outras palavras, ele pode aceitar uma classe ATL\).<br /><br /> O assistente chama esta função quando o parâmetro PREPROCESS\_FUNCTION é na  [arquivo de vsz do controle do projeto](../ide/dot-vsz-file-project-control.md) e verifica se o [Visual C\+\+ Code Model](http://msdn.microsoft.com/pt-br/dd6452c2-1054-44a1-b0eb-639a94a1216b) está disponível.  Se o modelo de código não estiver disponível, a função reporta um erro e retorna  **false**.|  
|[CanAddClass](../ide/canaddclass.md)|O assistente chama esta função quando o parâmetro PREPROCESS\_FUNCTION é no arquivo vsz do controle projeto.<br /><br /> Ele verifica se o objeto de modelo de código do Visual C\+\+ está disponível.  Se o modelo de código não estiver disponível, a função reporta um erro e retorna  **false**.|  
|[CanAddMFCClass](../ide/canaddmfcclass.md)|Chamado pelo Assistente para verificar se o projeto é compatível com o Assistente de código que está prestes a ser executado \(em outras palavras, ele pode aceitar uma classe do MFC\).<br /><br /> O assistente chama esta função quando o parâmetro PREPROCESS\_FUNCTION no arquivo vsz do controle projeto e verifica se o objeto de modelo de código do Visual C\+\+ está disponível.  Se o modelo de código não estiver disponível, a função reporta um erro e retorna  **false**.|  
|[CanAddNonAttributed](../ide/canaddnonattributed.md)|Indica se o projeto oferece suporte a objetos ATL atribuídos e nonattributed.|  
|[CanUseFileName](../ide/canusefilename.md)|Verifica se existe um arquivo.  Nesse caso, o assistente solicita ao usuário para mesclar o código a ser adicionado ao arquivo existente.|  
|[ConvertProjectToAttributed](../Topic/ConvertProjectToAttributed.md)|Converte um projeto do ATL para atribuída.|  
|[CreateInfFile](../Topic/CreateInfFile.md)|Cria o arquivo Templates.inf.|  
|[CreateProject](../ide/createproject.md)|Cria um projeto de C\+\+.|  
|[CreateSafeName](../ide/createsafename.md)|Gera um nome amigável do C\+\+.|  
|[DeleteFile](../ide/deletefile.md)|Exclui o arquivo especificado.|  
|[DoesIncludeExist](../ide/doesincludeexist.md)|Indica se um `#include` instrução existe em um arquivo.|  
|[GetCodeForDllCanUnloadNow](../Topic/GetCodeForDllCanUnloadNow.md)|Recupera o código necessário para descarregar a DLL.|  
|[GetCodeForDllGetClassObject](../ide/getcodefordllgetclassobject.md)|Recupera o código para o objeto de classe DLL.|  
|[GetCodeForDllRegisterServer](../ide/getcodefordllregisterserver.md)|Recupera o código para registrar um servidor.|  
|[GetCodeForDllUnregisterServer](../ide/getcodefordllunregisterserver.md)|Recupera o código para cancelar o registro de um servidor.|  
|[GetCodeForExitInstance](../Topic/GetCodeForExitInstance.md)|Função auxiliar para obter o texto para `ExitInstance`.|  
|[GetCodeForInitInstance](../ide/getcodeforinitinstance.md)|Função auxiliar para obter o texto para  [InitInstance](../Topic/CWinApp::InitInstance.md).|  
|[GetExportPragmas](../Topic/GetExportPragmas.md)|Recupera os pragmas de funções de exportação.|  
|[GetInterfaceClasses](../Topic/GetInterfaceClasses.md)|Retorna o `VCCodeClass` objeto associado com uma interface.|  
|[GetInterfaceType](../ide/getinterfacetype.md)|Retorna o tipo de interface \(por exemplo, personalizado, dual, dispinterface, oleautomation\).|  
|[GetMaxID](../ide/getmaxid.md)|Retorna o maior `dispid` de membros nesta interface e todas as suas bases.|  
|[GetMemberfunction](../Topic/GetMemberfunction.md)|Retorna um objeto de função com base no nome fornecido.|  
|[GetProjectFile](../Topic/GetProjectFile.md)|Retorna o nome do arquivo do tipo por projeto de arquivos \(. rc. idl e assim por diante\).|  
|[GetProjectPath](../ide/getprojectpath.md)|Retorna o caminho do diretório do projeto.|  
|[GetRuntimeErrorDesc](../ide/getruntimeerrordesc.md)|Retorna uma descrição para o tipo de exceção.|  
|[GetUniqueFileName](../Topic/GetUniqueFileName.md)|Retorna um nome de arquivo exclusivo.|  
|[IncludeCodeElementDeclaration](../ide/includecodeelementdeclaration.md)|Adiciona a instrução include para `strInFile`, incluindo o cabeçalho onde `strCodeElemName` é implementado, se tal um cabeçalho encontrado está no projeto.|  
|[InsertIntoFunction](../ide/insertintofunction.md)|Função auxiliar chamada `AddATLSupportToProject` para inserir o código em `InitInstance`.|  
|[IsATLProject](../ide/isatlproject.md)|Indica se o projeto é ATL com base.|  
|[IsAttributedProject](../Topic/IsAttributedProject.md)|Indica se um projeto é atribuído.|  
|[IsMFCProject](../Topic/IsMFCProject.md)|Verifica se um projeto é baseado de MFC.|  
|[LineBeginsWith](../ide/linebeginswith.md)|Função auxiliar chamada `InsertIntoFunction` para determinar se uma linha começar com uma determinada seqüência de caracteres|  
|[OffsetToLineNumber](../ide/offsettolinenumber.md)|Localiza o número da linha para uma determinada posição no corpo da função.|  
|[OnWizFinish](../Topic/OnWizFinish.md)|Chamado a partir do script HTML do assistente quando o usuário clica  **Concluir**.  Chama do controle wizard  **Concluir** método.|  
|[RenderAddTemplate](../Topic/RenderAddTemplate.md)|Processa um arquivo de modelo e, opcionalmente, o adiciona ao projeto.|  
|[SetCommonPchSettings](../ide/setcommonpchsettings.md)|Define o cabeçalho pré\-compilado para o projeto.|  
|[SetErrorInfo](../ide/seterrorinfo.md)|Fornece informações de erro.|  
|[SetFilters](../ide/setfilters.md)|Adiciona origem, e incluir e filtros de recurso para pastas de projeto.|  
|[SetMergeProxySymbol](../ide/setmergeproxysymbol.md)|Chamado pelo Assistente para adicionar o símbolo \_MERGE\_PROXYSTUB, se necessário.|  
|[SetNoPchSettings](../ide/setnopchsettings.md)|Configura as propriedades de configuração do projeto quando não há cabeçalho pré\-compilado é usado.|  
  
## Consulte também  
 [Personalizando assistentes do C\+\+ com funções JScript comuns](../ide/customizing-cpp-wizards-with-common-jscript-functions.md)   
 [Criando um assistente personalizado](../ide/creating-a-custom-wizard.md)   
 [Projetando um assistente](../ide/designing-a-wizard.md)