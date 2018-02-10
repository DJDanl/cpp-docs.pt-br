---
title: Registro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- servers [MFC], initializing
- initializing servers [MFC]
- OLE, registration
- installing servers [MFC]
- registry [MFC], OLE item database
- registration databases [MFC]
- servers [MFC], installing
- OLE server applications [MFC], registering servers
ms.assetid: 991d5684-72c1-4f9e-a09a-9184ed12bbb9
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 636a0c2ff254957724511a067fa64533cb4837aa
ms.sourcegitcommit: a5916b48541f804a79891ff04e246628b5f9a24a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/09/2018
---
# <a name="registration"></a>Registro
Quando um usuário quiser inserir um item OLE em um aplicativo, o OLE apresenta uma lista de tipos de objeto para escolher. OLE obtém essa lista do banco de dados de registro do sistema, que contém as informações fornecidas por todos os aplicativos de servidor. Quando um servidor registrado, as entradas que ele coloca o banco de dados do sistema registration (registro) descrevem cada tipo de objeto que fornece, extensões de arquivo e o caminho para si mesmo, entre outras informações.  
  
 A estrutura e as bibliotecas de vínculo dinâmico do sistema OLE (DLL) usam esse registro para determinar quais tipos de itens OLE estão disponíveis no sistema. O sistema OLE DLLs também usam esse registro para determinar como iniciar um aplicativo de servidor quando um objeto vinculado ou incorporado é ativado.  
  
 Este artigo descreve o que cada aplicativo de servidor precisa fazer quando ele está instalado e a cada vez que ele é executado.  
  
 Para obter informações detalhadas sobre o banco de dados de registro do sistema e o formato dos arquivos. reg usados para atualizá-lo, consulte o *referência do programador de OLE*.  
  
##  <a name="_core_server_installation"></a>Instalação do servidor  
 Quando você instala o aplicativo de servidor, ele deve registrar todos os tipos de itens OLE que ele suporta. Você também pode ter o servidor de atualizar o banco de dados de registro do sistema toda vez que ele é executado como um aplicativo autônomo. Isso mantém o banco de dados de registro atualizado se o arquivo executável do servidor é movido.  
  
> [!NOTE]
>  Aplicativos MFC gerados automaticamente pelo Assistente de aplicativo se registram quando eles são executados como aplicativos autônomos.  
  
 Se você quiser registrar seu aplicativo durante a instalação, use o programa RegEdit.exe. Se você incluir um programa de instalação com o seu aplicativo, ter o programa de instalação executar "RegEdit /S *appname*. reg". (O sinalizador /S indica a operação silenciosa, ou seja, ele não exibe a caixa de diálogo reporting conclusão bem-sucedida do comando.) Caso contrário, instrua o usuário para executar manualmente o RegEdit.  
  
> [!NOTE]
>  O arquivo. reg criado pelo Assistente de aplicativo não inclui o caminho completo para o executável. O programa de instalação deve modificar o arquivo. reg para incluir o caminho completo para o executável ou modificar a variável de ambiente PATH para incluir o diretório de instalação.  
  
 RegEdit mescla o conteúdo do arquivo de texto. reg o banco de dados de registro. Para verificar se o banco de dados ou para repará-lo, use o editor do registro. Tome cuidado para evitar a exclusão de entradas OLE essenciais.  
  
##  <a name="_core_server_initialization"></a>Inicialização do servidor  
 Quando você cria um aplicativo de servidor com o Assistente de aplicativo, o assistente for concluído todas as tarefas de inicialização para você automaticamente. Esta seção descreve o que você deve fazer se você escrever um aplicativo de servidor manualmente.  
  
 Quando um aplicativo de servidor é iniciado por um aplicativo de contêiner, as DLLs do sistema OLE adicionar a opção "/ incorporação" à linha de comando do servidor. O comportamento de um aplicativo servidor difere dependendo se foi iniciado por um contêiner, portanto, a primeira coisa que um aplicativo deve fazer quando ele inicia a execução é verificar o "/ incorporação" ou "-incorporando" opção na linha de comando. Se essa opção existir, carregar um conjunto diferente de recursos que mostram o servidor como um ativo no local ou totalmente abrir. Para obter mais informações, consulte [Menus e recursos: adições de servidor](../mfc/menus-and-resources-server-additions.md).  
  
 O aplicativo de servidor também deve chamar seu `CWinApp::RunEmbedded` função analisar a linha de comando. Se ele retorna um valor diferente de zero, o aplicativo não deve exibir a janela porque ele foi executado em um aplicativo de contêiner, não como um aplicativo autônomo. Esta função atualiza a entrada do servidor no banco de dados de registro de sistema e chama o `RegisterAll` a função de membro para você realizar o registro da instância.  
  
 Quando o aplicativo de servidor é iniciado, certifique-se de que ele pode realizar o registro da instância. Registro de instância informa a DLLs do sistema OLE que o servidor está ativo e pronto para receber solicitações de contêineres. Ele não adicione uma entrada para o banco de dados de registro. Executar o registro de instância do servidor chamando o `ConnectTemplate` função de membro definida pelo `COleTemplateServer`. Isso conecta o `CDocTemplate` o objeto para o `COleTemplateServer` objeto.  
  
 O `ConnectTemplate` função usa três parâmetros: o servidor **CLSID**, um ponteiro para o `CDocTemplate` objeto e um sinalizador que indica se o servidor oferece suporte a várias instâncias. Um miniserver deve ser capaz de dar suporte a várias instâncias, ou seja, deve ser possível que várias instâncias do servidor a ser executadas simultaneamente, uma para cada contêiner. Consequentemente, passar **TRUE** para esse sinalizador ao iniciar um miniserver.  
  
 Se você estiver escrevendo um miniserver, por definição, que ele sempre será iniciado por um contêiner. Você ainda deve analisar a linha de comando para verificar se há a opção "/ incorporação". A ausência dessa opção na linha de comando significa que o usuário tentou iniciar o miniserver como um aplicativo autônomo. Se isso ocorrer, registrar o servidor com o banco de dados de registro do sistema e, em seguida, exibir uma caixa de mensagem informando ao usuário para iniciar o miniserver de um aplicativo de contêiner.  
  
## <a name="see-also"></a>Consulte também  
 [OLE](../mfc/ole-in-mfc.md)   
 [Servidores](../mfc/servers.md)   
 [CWinApp::RunAutomated](../mfc/reference/cwinapp-class.md#runautomated)   
 [CWinApp::RunEmbedded](../mfc/reference/cwinapp-class.md#runembedded)   
 [Classe COleTemplateServer](../mfc/reference/coletemplateserver-class.md)
