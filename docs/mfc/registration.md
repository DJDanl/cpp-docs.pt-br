---
title: Registro
ms.date: 11/04/2016
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
ms.openlocfilehash: 82411e53620e92eff3484f7d3f7955030fd439ac
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372835"
---
# <a name="registration"></a>Registro

Quando um usuário deseja inserir um item OLE em um aplicativo, o OLE apresenta uma lista de tipos de objetos para escolher. O LE Recebe essa lista do banco de dados de registro do sistema, que contém informações fornecidas por todos os aplicativos do servidor. Quando um servidor se registra, as entradas que ele coloca no banco de dados de registro do sistema (o Registro) descrevem cada tipo de objeto que fornece, extensões de arquivo e o caminho para si mesmo, entre outras informações.

A estrutura e as bibliotecas de link dinâmico do sistema OLE (DLL) usam este registro para determinar quais tipos de itens OLE estão disponíveis no sistema. Os DLLs do sistema OLE também usam esse registro para determinar como iniciar um aplicativo de servidor quando um objeto vinculado ou incorporado é ativado.

Este artigo descreve o que cada aplicativo de servidor precisa fazer quando é instalado e cada vez que é executado.

Para obter informações detalhadas sobre o banco de dados de registro do sistema e o formato dos arquivos .reg usados para atualizá-lo, consulte o *Programador OLE*.

## <a name="server-installation"></a><a name="_core_server_installation"></a>Instalação do servidor

Quando você instala seu aplicativo de servidor pela primeira vez, ele deve registrar todos os tipos de itens OLE que ele suporta. Você também pode fazer com que o servidor atualize o banco de dados de registro do sistema toda vez que ele for executado como um aplicativo autônomo. Isso mantém o banco de dados de registro atualizado se o arquivo executável do servidor for movido.

> [!NOTE]
> Os aplicativos MFC gerados pelo assistente de aplicativo registram-se automaticamente quando são executados como aplicativos autônomos.

Se você quiser registrar seu aplicativo durante a instalação, use o programa RegEdit.exe. Se você incluir um programa de configuração com seu aplicativo, faça com que o programa de configuração execute "RegEdit /S *appname*.reg". (O sinalizador /S indica operação silenciosa, ou seja, não exibe a caixa de diálogo que informa a conclusão bem sucedida do comando.) Caso contrário, instrua o usuário a executar o RegEdit manualmente.

> [!NOTE]
> O arquivo .reg criado pelo assistente do aplicativo não inclui o caminho completo para o executável. Seu programa de instalação deve modificar o arquivo .reg para incluir o caminho completo para o executável ou modificar a variável de ambiente PATH para incluir o diretório de instalação.

O RegEdit mescla o conteúdo do arquivo de texto .reg no banco de dados de registro. Para verificar o banco de dados ou repará-lo, use o editor do registro. Tome cuidado para evitar a exclusão de entradas OLE essenciais.

## <a name="server-initialization"></a><a name="_core_server_initialization"></a>Inicialização do servidor

Quando você cria um aplicativo de servidor com o assistente do aplicativo, o assistente completa todas as tarefas de inicialização para você automaticamente. Esta seção descreve o que você deve fazer se você escrever um aplicativo de servidor manualmente.

Quando um aplicativo de servidor é iniciado por um aplicativo de contêiner, os DLLs do sistema OLE adicionam a opção "/Incorporação" à linha de comando do servidor. O comportamento de um aplicativo de servidor difere dependendo se ele foi lançado por um contêiner, então a primeira coisa que um aplicativo deve fazer quando começa a execução é verificar a opção "/Incorporação" ou "Incorporação" na linha de comando. Se esse switch existir, carregue um conjunto diferente de recursos que mostram o servidor como sendo ativo ou totalmente aberto. Para obter mais informações, consulte [Menus e Recursos: Adições de servidor](../mfc/menus-and-resources-server-additions.md).

Seu aplicativo de servidor `CWinApp::RunEmbedded` também deve chamar sua função para analisar a linha de comando. Se ele retornar um valor não zero, o aplicativo não deve mostrar sua janela porque foi executado a partir de um aplicativo de contêiner, não como um aplicativo autônomo. Esta função atualiza a entrada do servidor no banco `RegisterAll` de dados de registro do sistema e chama a função de membro para você, realizando o registro de instâncias.

Quando o aplicativo do servidor está sendo iniciado, você deve garantir que ele possa realizar o registro de instâncias. O registro de instâncias informa os DLLs do sistema OLE que o servidor está ativo e pronto para receber solicitações de contêineres. Ele não adiciona uma entrada ao banco de dados de registro. Realize o registro de instância `ConnectTemplate` do servidor `COleTemplateServer`ligando para a função membro definida por . Isso conecta `CDocTemplate` o objeto `COleTemplateServer` ao objeto.

A `ConnectTemplate` função tem três parâmetros: *CLSID*do `CDocTemplate` servidor, um ponteiro para o objeto e um sinalizador indicando se o servidor suporta várias instâncias. Um miniservidor deve ser capaz de suportar várias instâncias, ou seja, deve ser possível que várias instâncias do servidor sejam executadas simultaneamente, uma para cada contêiner. Consequentemente, passe **TRUE** para este sinalizador ao lançar um miniservidor.

Se você estiver escrevendo um miniservidor, por definição ele sempre será lançado por um contêiner. Você ainda deve analisar a linha de comando para verificar a opção "/Incorporação". A ausência desta opção na linha de comando significa que o usuário tentou lançar o miniservidor como um aplicativo autônomo. Se isso ocorrer, registre o servidor no banco de dados de registro do sistema e, em seguida, exiba uma caixa de mensagem informando o usuário para iniciar o miniservidor a partir de um aplicativo de contêiner.

## <a name="see-also"></a>Confira também

[OLE](../mfc/ole-in-mfc.md)<br/>
[Servidores](../mfc/servers.md)<br/>
[CWinApp::RunAutomated](../mfc/reference/cwinapp-class.md#runautomated)<br/>
[CWinApp::RunEmbedded](../mfc/reference/cwinapp-class.md#runembedded)<br/>
[Classe COleTemplateServer](../mfc/reference/coletemplateserver-class.md)
