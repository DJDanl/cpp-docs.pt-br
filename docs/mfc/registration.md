---
title: "Registro | Microsoft Docs"
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
  - "inicializando servidores"
  - "instalando servidores"
  - "aplicativos de servidor OLE, registrando servidores"
  - "OLE, registro"
  - "bancos de dados de registro"
  - "registro, Banco de dados de itens OLE"
  - "servidores, inicializando"
  - "servidores, instalando"
ms.assetid: 991d5684-72c1-4f9e-a09a-9184ed12bbb9
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Registro
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando um usuário deseja inserir um item OLE em um aplicativo OLE, apresenta uma lista de tipos de objeto para a escolha do.  OLE obtém a lista de base de dados do registro do sistema, que contém as informações fornecidas por todos os aplicativos de servidor.  Quando um servidor se registra, as entradas que coloca na base de dados do registro do sistema \(o Registro\) descreve cada tipo de objeto fornece, de extensões de arquivo, e o caminho para se, entre outras informações.  
  
 A estrutura e bibliotecas DE vínculo dinâmico\) \(DLL\) do link do sistema usam esse Registro para determinar quais tipos de itens com OLE DB estão disponíveis no sistema.  Dlls OLE DB do sistema também usam esse Registro para determinar como iniciar um aplicativo de servidor quando um objeto vinculado ou inserida é ativado.  
  
 Este artigo descreve o que cada aplicativo do servidor precisa fazer quando o é instalado e será executado toda vez.  
  
 Para obter informações detalhadas sobre a base de dados do registro do sistema e o formato de arquivo .reg usados para sua atualização, consulte *a referência do programador OLE*.  
  
##  <a name="_core_server_installation"></a> Instalação do servidor  
 Quando você instala o seu aplicativo de servidor, deve registrar todos os tipos de itens do que oferece suporte.  Você também pode fazer com que o servidor atualizar o base de dados de registro do sistema cada vez que é executado como um aplicativo autônomo.  Isso mantém o base de dados de registro atualizado se o arquivo executável do será movido.  
  
> [!NOTE]
>  Os aplicativos MFC gerados pelo assistente de aplicativo registram automaticamente quando são executados como aplicativos autônomos.  
  
 Se você deseja registrar seu aplicativo durante a instalação, use o programa de RegEdit.exe. \(No Windows 95, Windows 98, e no Windows, ME RegEdit está no diretório do Windows.  No Windows NT e no Windows 2000, RegEdit está no diretório System32 do windows\). Se você incluir um programa de instalação com seu aplicativo, tem o “RegEdit executado programa de instalação *appname.reg*\/S”. \(O sinalizador de \/S indica a operação silenciosa, ou seja, não exibe a caixa de diálogo que se reporta a conclusão bem\-sucedida do comando.\) Caso contrário, instrui o usuário para executar manualmente RegEdit.  
  
> [!NOTE]
>  O arquivo .reg criado pelo assistente de aplicativo não inclui o caminho completo para o executável.  O programa de instalação necessário modificar o arquivo .reg para incluir o caminho completo para o executável ou para alterar a variável de ambiente PATH para incluir o diretório de instalação.  
  
 RegEdit mescla os conteúdos do arquivo de texto .reg na base de dados do registro.  Para verificar o base de dados ou repara, use o Editor do Registro.  Procure evitar excluir entradas com OLE DB essenciais. \(No Windows 95, Windows 98, e no Windows, ME o Editor do Registro é RegEdit.exe.  No Windows NT e no Windows 2000, é RegEdit32.exe.\)  
  
##  <a name="_core_server_initialization"></a> Inicialização do servidor  
 Quando você cria um aplicativo de servidor com o assistente de aplicativo, o assistente concluir todas as tarefas de inicialização para você automaticamente.  Esta seção descreve o que você deve fazer se você escrever um aplicativo de servidor manualmente.  
  
 Quando um aplicativo de servidor é iniciado por um aplicativo de contêineres, as dlls OLE DB do sistema adicionam a opção de “\/Embedding” na linha de comando do servidor.  Comportamento de um aplicativo de servidor difere dependendo se esteve iniciada por um contêiner, assim que a primeira coisa aplicativo deve fazer quando inicia a execução é verificação para o “\/Embedding” ou “\- opção de inserção” na linha de comando.  Essa opção se existir, carregar um conjunto diferente de recursos que mostram o servidor como estando ativas ou completamente abertos no local.  Para obter mais informações, consulte [Menus e recursos: Adições de servidor](../mfc/menus-and-resources-server-additions.md).  
  
 Seu aplicativo de servidor também deve chamar a função de `CWinApp::RunEmbedded` para analisar a linha de comando.  Se retornar um valor diferente de zero, o aplicativo não deve exibir a janela porque foi executado de um aplicativo de contêiner, não como um aplicativo autônomo.  Essa função atualiza a entrada de servidor na base de dados do registro do sistema e chama a função de membro de `RegisterAll` para você, executando o registro da instância.  
  
 Quando seu aplicativo de servidor estiver iniciando, você deve assegurar que pode executar o registro da instância.  O registro da instância informa as dlls OLE DB do sistema que o servidor está ativo e pronto para receber solicitações de contêiner.  Não adiciona uma entrada para a base de dados do registro.  Execute o registro da instância do servidor chamando a função de membro de `ConnectTemplate` definida por `COleTemplateServer`.  Isso conecta o objeto de `CDocTemplate` ao objeto de `COleTemplateServer` .  
  
 A função de `ConnectTemplate` usa três parâmetros: **CLSID**de servidor, um ponteiro para o objeto de `CDocTemplate` , e um sinalizador que indica se o servidor oferecer suporte a várias instâncias.  Um miniserver deve poder dar suporte a várias instâncias, ou seja, deve ser possível para várias instâncias do servidor ser executados simultaneamente, um para cada contêiner.  Consequentemente, passagem **Verdadeiro** desse sinalizador para iniciar um miniserver.  
  
 Se você estiver escrevendo um miniserver, por definição sempre será iniciada por um contêiner.  Você ainda deve analisar a linha de comando para verificar a opção de “\/Embedding”.  A ausência dessa opção na linha de comando significa que o usuário tentou iniciar o miniserver como um aplicativo autônomo.  Se isso ocorrer, registrar o servidor com o base de dados de registro do sistema e exibir em uma caixa de mensagem que informa ao usuário para iniciar o miniserver de um aplicativo de contêiner.  
  
## Consulte também  
 [OLE](../mfc/ole-in-mfc.md)   
 [Servidores](../mfc/servers.md)   
 [CWinApp::RunAutomated](../Topic/CWinApp::RunAutomated.md)   
 [CWinApp::RunEmbedded](../Topic/CWinApp::RunEmbedded.md)   
 [Classe de COleTemplateServer](../mfc/reference/coletemplateserver-class.md)