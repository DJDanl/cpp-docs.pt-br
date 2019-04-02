---
title: 'Contêineres: Recursos avançados'
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
ms.openlocfilehash: 350431975a4335fc06e436237b7e0d3388faab64
ms.sourcegitcommit: 5cecccba0a96c1b4ccea1f7a1cfd91f259cc5bde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/01/2019
ms.locfileid: "58769557"
---
# <a name="containers-advanced-features"></a>Contêineres: Recursos avançados

Este artigo descreve as etapas necessárias para incorporar recursos avançados opcionais em aplicativos de contêiner existentes. Esses recursos estão:

- [Um aplicativo que é um contêiner e um servidor](#_core_creating_a_container_server_application)

- [Um vínculo OLE com um objeto inserido](#_core_links_to_embedded_objects)

##  <a name="_core_creating_a_container_server_application"></a> Criando um aplicativo de contêiner/servidor

Um aplicativo de contêiner/servidor é um aplicativo que atua como um contêiner e um servidor. Microsoft Word para Windows é um exemplo disso. Você pode inserir documentos do Word para Windows em outros aplicativos, e você também pode inserir itens em documentos do Word para Windows. O processo para modificar o aplicativo de contêiner seja um contêiner e um servidor completo (não é possível criar um aplicativo de contêiner/miniserver combinação) é semelhante ao processo de criação de um servidor completo.

O artigo [servidores: Implementação de um servidor](../mfc/servers-implementing-a-server.md) lista um número de tarefas necessárias para implementar um aplicativo de servidor. Se você converter um aplicativo de contêiner para um aplicativo de contêiner/servidor, em seguida, você precisa executar algumas dessas mesmas tarefas, adicionar código para o contêiner. O exemplo a seguir lista os pontos importantes a considerar:

- O código do contêiner criado pelo Assistente de aplicativo já inicializa o subsistema OLE. Você não precisará alterar ou adicionar qualquer coisa para que o suporte.

- Onde quer que seja a classe base de uma classe de documento `COleDocument`, altere a classe base para `COleServerDoc`.

- Substituir `COleClientItem::CanActivate` para evitar a edição de itens em vigor enquanto o próprio servidor está sendo usado para editar no local.

   Por exemplo, a OLE do MFC amostra [OCLIENT](../overview/visual-cpp-samples.md) incorporou um item criado pelo seu aplicativo de contêiner/servidor. Abrir o aplicativo OCLIENT e in-loco editar o item criado pelo seu aplicativo de contêiner/servidor. Ao editar o item do seu aplicativo, você decide que deseja inserir um item criado por este exemplo OLE do MFC [HIERSVR](../overview/visual-cpp-samples.md). Para fazer isso, você não pode usar a ativação in-loco. Totalmente, você deve abrir HIERSVR para ativar esse item. Porque a biblioteca Microsoft Foundation Class não oferece suporte a esse recurso OLE, substituindo `COleClientItem::CanActivate` permite que você verificar essa situação e evitar um possível erro de tempo de execução em seu aplicativo.

Se você estiver criando um novo aplicativo e deseja que ele funcione como um aplicativo de contêiner/servidor, escolha a que a opção na caixa de diálogo OLE opções no Assistente de aplicativo e esse suporte será criada automaticamente. Para obter mais informações, consulte o artigo [visão geral: Criando um contêiner de controle ActiveX](../mfc/reference/creating-an-mfc-activex-control-container.md). Para obter informações sobre exemplos de MFC, consulte exemplos de MFC.

Observe que você não é possível inserir um aplicativo MDI em si. Um aplicativo que é um contêiner/servidor não pode ser inserido no próprio, a menos que ele é um aplicativo SDI.

##  <a name="_core_links_to_embedded_objects"></a> Links para os objetos inseridos

Os Links para recursos de objetos inseridos permite que um usuário criar um documento com um vínculo OLE com um objeto inserido dentro de seu aplicativo de contêiner. Por exemplo, crie um documento em um processador de texto que contém uma planilha incorporada. Se seu aplicativo dá suporte a links para objetos incorporados, ela pôde colar um link para a planilha contida no documento do word do processador. Esse recurso permite que seu aplicativo para usar as informações contidas na planilha sem saber em que o processador de texto originalmente entendi.

#### <a name="to-link-to-embedded-objects-in-your-application"></a>Para vincular a objetos incorporados em seu aplicativo

1. Derive sua classe de documento da `COleLinkingDoc` em vez de `COleDocument`.

1. Criar uma ID de classe OLE (**CLSID**) para seu aplicativo usando o gerador de ID de classe incluído com as ferramentas de desenvolvimento OLE.

1. Registre o aplicativo com OLE.

1. Criar um `COleTemplateServer` objeto como um membro de sua classe de aplicativo.

1. Em sua classe de aplicativo `InitInstance` membro de função, faça o seguinte:

   - Conectar seu `COleTemplateServer` objeto aos seus modelos de documento ao chamar o objeto `ConnectTemplate` função de membro.

   - Chamar o `COleTemplateServer::RegisterAll` a função de membro para registrar todos os objetos de classe com o sistema OLE.

   - Chamar `COleTemplateServer::UpdateRegistry`. O único parâmetro para `UpdateRegistry` deve ser *OAT_CONTAINER* que o aplicativo não seja iniciado com a opção "/ inserido". Isso registra o aplicativo como um contêiner que pode dar suporte a links para os objetos inseridos.

         If the application is launched with the "/Embedded" switch, it should not show its main window, similar to a server application.

O exemplo OLE do MFC [OCLIENT](../overview/visual-cpp-samples.md) implementa esse recurso. Para obter um exemplo de como isso é feito, consulte o `InitInstance` funcionar a *OCLIENT. CPP* arquivo deste aplicativo de exemplo.

## <a name="see-also"></a>Consulte também

[Contêineres](../mfc/containers.md)<br/>
[Servidores](../mfc/servers.md)
