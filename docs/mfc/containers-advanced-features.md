---
title: 'Contêineres: funcionalidades avançadas'
ms.date: 11/04/2016
helpviewer_keywords:
- links [MFC], to embedded OLE objects
- containers [MFC], links to embedded OLE objects
- containers [MFC], advanced features
- container/server applications [MFC]
- embedded objects [MFC]
- OLE controls [MFC], containers
- OLE containers [MFC], advanced features
- server/container applications [MFC]
- containers [MFC], container applications
ms.assetid: 221fd99c-b138-40fa-ad6a-974e3b3ad1f8
ms.openlocfilehash: a68cc85062f9ca711c453ef98f69a7c5ea114d94
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80214351"
---
# <a name="containers-advanced-features"></a>Contêineres: funcionalidades avançadas

Este artigo descreve as etapas necessárias para incorporar recursos avançados opcionais em aplicativos de contêiner existentes. Esses recursos são:

- [Um aplicativo que é um contêiner e um servidor](#_core_creating_a_container_server_application)

- [Um link OLE para um objeto inserido](#_core_links_to_embedded_objects)

##  <a name="creating-a-containerserver-application"></a><a name="_core_creating_a_container_server_application"></a>Criando um aplicativo de contêiner/servidor

Um aplicativo de contêiner/servidor é um aplicativo que atua como um contêiner e um servidor. O Microsoft Word para Windows é um exemplo disso. Você pode inserir documentos do Word para Windows em outros aplicativos e também pode inserir itens em documentos do Word para Windows. O processo para modificar o aplicativo de contêiner para ser um contêiner e um servidor completo (você não pode criar um aplicativo de contêiner/miniserver de combinação) é semelhante ao processo de criação de um servidor completo.

O artigo [servidores: Implementando um servidor](../mfc/servers-implementing-a-server.md) lista várias tarefas necessárias para implementar um aplicativo de servidor. Se você converter um aplicativo de contêiner em um aplicativo de contêiner/servidor, precisará executar algumas dessas mesmas tarefas, adicionando o código ao contêiner. Veja a seguir uma lista das coisas importantes a considerar:

- O código de contêiner criado pelo assistente de aplicativo já Inicializa o subsistema OLE. Não será necessário alterar nem adicionar nada para esse suporte.

- Sempre que a classe base de uma classe de documento for `COleDocument`, altere a classe base para `COleServerDoc`.

- Substitua `COleClientItem::CanActivate` para evitar a edição de itens no local enquanto o próprio servidor está sendo usado para editar no local.

   Por exemplo, o exemplo OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) inseriu um item criado por seu aplicativo contêiner/servidor. Abra o aplicativo OCLIENT e no local edite o item criado pelo seu aplicativo de contêiner/servidor. Ao editar o item do aplicativo, você decide que deseja inserir um item criado pelo exemplo de OLE do MFC [HIERSVR](../overview/visual-cpp-samples.md). Para fazer isso, não é possível usar a ativação in-loco. Você deve abrir totalmente o HIERSVR para ativar este item. Como o biblioteca MFC não dá suporte a esse recurso OLE, a substituição de `COleClientItem::CanActivate` permite que você verifique essa situação e evite um possível erro em tempo de execução em seu aplicativo.

Se você estiver criando um novo aplicativo e quiser que ele funcione como um aplicativo de contêiner/servidor, escolha essa opção na caixa de diálogo opções de OLE no assistente de aplicativo e esse suporte será criado automaticamente. Para obter mais informações, consulte o artigo [visão geral: Criando um contêiner de controle ActiveX](../mfc/reference/creating-an-mfc-activex-control-container.md). Para obter informações sobre exemplos de MFC, consulte [exemplos de MFC](../overview/visual-cpp-samples.md#mfc-samples).

Observe que você não pode inserir um aplicativo MDI em si mesmo. Um aplicativo que é um contêiner/servidor não pode ser inserido em si, a menos que seja um aplicativo SDI.

##  <a name="links-to-embedded-objects"></a><a name="_core_links_to_embedded_objects"></a>Links para objetos inseridos

O recurso links para objetos inseridos permite que um usuário crie um documento com um link OLE para um objeto inserido dentro do aplicativo de contêiner. Por exemplo, crie um documento em um processador de texto que contenha uma planilha inserida. Se seu aplicativo oferecer suporte a links para objetos inseridos, ele poderá colar um link para a planilha contida no documento do processador de texto. Esse recurso permite que seu aplicativo use as informações contidas na planilha sem saber onde o processador de texto o recebeu originalmente.

#### <a name="to-link-to-embedded-objects-in-your-application"></a>Para vincular a objetos inseridos em seu aplicativo

1. Derive sua classe de documento de `COleLinkingDoc` em vez de `COleDocument`.

1. Crie uma ID de classe OLE (**CLSID**) para seu aplicativo usando o gerador de ID de classe incluído com as ferramentas de desenvolvimento de OLE.

1. Registre o aplicativo com OLE.

1. Crie um objeto `COleTemplateServer` como um membro de sua classe de aplicativo.

1. Na função de membro `InitInstance` da sua classe de aplicativo, faça o seguinte:

   - Conecte o objeto `COleTemplateServer` aos modelos de documento chamando a função de membro `ConnectTemplate` do objeto.

   - Chame a função de membro `COleTemplateServer::RegisterAll` para registrar todos os objetos de classe com o sistema OLE.

   - Chame `COleTemplateServer::UpdateRegistry`. O único parâmetro a `UpdateRegistry` deve ser *OAT_CONTAINER* se o aplicativo não for iniciado com a opção "/Embedded". Isso registra o aplicativo como um contêiner que pode dar suporte a links para objetos inseridos.

      Se o aplicativo for iniciado com a opção "/Embedded", ele não deverá mostrar sua janela principal, semelhante a um aplicativo de servidor.

O [OCLIENT](../overview/visual-cpp-samples.md) de exemplo OLE do MFC implementa esse recurso. Para obter um exemplo de como isso é feito, consulte a função `InitInstance` no *OCLIENT. Arquivo CPP* deste aplicativo de exemplo.

## <a name="see-also"></a>Confira também

[Contêineres](../mfc/containers.md)<br/>
[Servidores](../mfc/servers.md)
