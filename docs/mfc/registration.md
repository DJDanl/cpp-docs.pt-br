---
title: Registro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e115edc4a7a276e04e886a0d7d324308dbe1c8ed
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46399572"
---
# <a name="registration"></a>Registro

Quando um usuário deseja inserir um item OLE em um aplicativo, o OLE apresenta uma lista de tipos de objeto para sua escolha. OLE obtém essa lista do banco de dados de registro do sistema, que contém as informações fornecidas por todos os aplicativos de servidor. Quando um servidor se registra, as entradas que ele coloca o banco de dados de registro de sistema (registro) descrevem cada tipo de objeto, que ele fornece, extensões de arquivo e o caminho para si mesmo, entre outras informações.

A estrutura e as bibliotecas de vínculo dinâmico do sistema OLE (DLL) usam esse registro para determinar quais tipos de itens OLE estão disponíveis no sistema. O sistema OLE DLLs também usam esse registro para determinar como iniciar um aplicativo de servidor quando um objeto vinculado ou inserido é ativado.

Este artigo descreve o que cada aplicativo de servidor precisa fazer quando ele é instalado, e cada vez que ele é executado.

Para obter informações detalhadas sobre o banco de dados de registro do sistema e o formato dos arquivos. reg usados para atualizá-lo, consulte o *referência do programador OLE*.

##  <a name="_core_server_installation"></a> Instalação do servidor

Quando você instala o aplicativo de servidor, ele deve registrar todos os tipos de itens OLE que ele suporta. Você também pode ter o servidor de atualizar o banco de dados de registro do sistema sempre que ele é executado como um aplicativo autônomo. Isso mantém o banco de dados de registro atualizado se o arquivo executável do servidor é movido.

> [!NOTE]
>  Aplicativos do MFC gerados automaticamente pelo Assistente de aplicativo se registrarão quando eles são executados como aplicativos autônomos.

Se você quiser registrar seu aplicativo durante a instalação, use o programa de RegEdit.exe. Se você incluir um programa de instalação com o seu aplicativo, com que o programa de instalação execute "RegEdit /S *appname*. reg". (O sinalizador /S indica a operação silenciosa, ou seja, ele não exibe a caixa de diálogo relatar a conclusão bem-sucedida do comando.) Caso contrário, instrua o usuário para executar o RegEdit manualmente.

> [!NOTE]
>  O arquivo. reg criado pelo Assistente de aplicativo não inclui o caminho completo para o executável. O programa de instalação deverá modificar o arquivo. reg para incluir o caminho completo para o executável ou modificar a variável de ambiente PATH para incluir o diretório de instalação.

RegEdit mescla o conteúdo do arquivo de texto. reg para o banco de dados de registro. Para verificar se o banco de dados ou para repará-lo, use o editor do registro. Tome cuidado para evitar a exclusão de entradas OLE essenciais.

##  <a name="_core_server_initialization"></a> Inicialização do servidor

Quando você cria um aplicativo de servidor com o Assistente de aplicativo, o assistente for concluído todas as tarefas de inicialização para você automaticamente. Esta seção descreve o que você deve fazer se você escrever um aplicativo de servidor manualmente.

Quando um aplicativo de servidor é iniciado por um aplicativo de contêiner, as DLLs do sistema OLE adicionar a opção "/ incorporação" à linha de comando do servidor. Comportamento de um aplicativo de servidor difere dependendo se ele foi iniciado por um contêiner, portanto, a primeira coisa que um aplicativo deve fazer quando ele inicia a execução é a seleção para a "/ incorporação" ou "-incorporação" opção na linha de comando. Se houver essa opção, carregar um conjunto diferente de recursos que mostram o servidor como sendo o ativo no local ou software totalmente livre. Para obter mais informações, consulte [Menus e recursos: adições de servidor](../mfc/menus-and-resources-server-additions.md).

O aplicativo de servidor também deve chamar seu `CWinApp::RunEmbedded` função analisar a linha de comando. Se ela retorna um valor diferente de zero, o aplicativo não deve mostrar sua janela porque ele foi executado de um aplicativo de contêiner, não como um aplicativo autônomo. Essa função atualiza a entrada do servidor no banco de dados de registro de sistema e chama o `RegisterAll` a função de membro para você, executando o registro da instância.

Quando o aplicativo de servidor é iniciado, você deve garantir que ele pode realizar o registro da instância. Registro da instância informa as DLLs do sistema OLE que o servidor está ativo e pronto para receber solicitações de contêineres. Ela adiciona uma entrada para o banco de dados de registro. Executar o registro de instância do servidor chamando o `ConnectTemplate` função de membro definida pelo `COleTemplateServer`. Isso conecta o `CDocTemplate` do objeto para o `COleTemplateServer` objeto.

O `ConnectTemplate` função usa três parâmetros: o servidor *CLSID*, um ponteiro para o `CDocTemplate` objeto e um sinalizador que indica se o servidor dá suporte a várias instâncias. Um miniserver deve ser capaz de dar suporte a várias instâncias, ou seja, ele deve ser possível que várias instâncias do servidor a ser executadas simultaneamente, uma para cada contêiner. Consequentemente, passe **verdadeira** para esse sinalizador ao iniciar um miniserver.

Se você estiver escrevendo um miniserver, por definição, que ele sempre será iniciado por um contêiner. Você ainda deve analisar a linha de comando para verificar se há a opção "/ inserção". A ausência dessa opção na linha de comando significa que o usuário tentou iniciar o miniserver como um aplicativo autônomo. Se isso ocorrer, registrar o servidor com o banco de dados de registro do sistema e, em seguida, exibir uma caixa de mensagem informando ao usuário para iniciar o miniserver de um aplicativo de contêiner.

## <a name="see-also"></a>Consulte também

[OLE](../mfc/ole-in-mfc.md)<br/>
[Servidores](../mfc/servers.md)<br/>
[CWinApp::RunAutomated](../mfc/reference/cwinapp-class.md#runautomated)<br/>
[CWinApp::RunEmbedded](../mfc/reference/cwinapp-class.md#runembedded)<br/>
[Classe COleTemplateServer](../mfc/reference/coletemplateserver-class.md)
