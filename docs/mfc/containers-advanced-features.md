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
ms.openlocfilehash: cf130bf8dead5c59548821658b979785c4d54726
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376490"
---
# <a name="containers-advanced-features"></a>Contêineres: funcionalidades avançadas

Este artigo descreve as etapas necessárias para incorporar recursos avançados opcionais em aplicações de contêineres existentes. Essas características são:

- [Um aplicativo que é tanto um contêiner quanto um servidor](#_core_creating_a_container_server_application)

- [Um link OLE para um objeto incorporado](#_core_links_to_embedded_objects)

## <a name="creating-a-containerserver-application"></a><a name="_core_creating_a_container_server_application"></a>Criando um aplicativo de contêiner/servidor

Um aplicativo de contêiner/servidor é um aplicativo que atua como um contêiner e um servidor. O Microsoft Word for Windows é um exemplo disso. Você pode incorporar documentos do Word for Windows em outros aplicativos, e também pode incorporar itens em documentos do Word for Windows. O processo para modificar seu aplicativo de contêiner para ser um contêiner e um servidor completo (você não pode criar uma combinação de aplicativo de contêiner/miniservidor) é semelhante ao processo de criação de um servidor completo.

O artigo [Servidores: Implementar um servidor](../mfc/servers-implementing-a-server.md) lista uma série de tarefas necessárias para implementar um aplicativo de servidor. Se você converter um aplicativo de contêiner em um aplicativo de contêiner/servidor, então você precisará executar algumas dessas mesmas tarefas, adicionando código ao contêiner. A seguir lista as coisas importantes a considerar:

- O código de contêiner criado pelo assistente de aplicativo já inicia o subsistema OLE. Você não precisará mudar ou adicionar nada para esse suporte.

- Onde quer que a classe `COleDocument`base de uma `COleServerDoc`classe de documento esteja, mude a classe base para .

- Substituir `COleClientItem::CanActivate` para evitar editar itens no lugar enquanto o servidor em si está sendo usado para editar no lugar.

   Por exemplo, a amostra [MFC](../overview/visual-cpp-samples.md) OLE OCLIENT incorporou um item criado pelo aplicativo container/server. Você abre o aplicativo OCLIENT e edita o item criado pelo aplicativo contêiner/servidor. Ao editar o item do seu aplicativo, você decide incorporar um item criado pela amostra [DeRO HIERSVR](../overview/visual-cpp-samples.md). Para fazer isso, você não pode usar ativação no local. Você deve abrir totalmente o HIERSVR para ativar este item. Como a Biblioteca de Classes da Microsoft Foundation `COleClientItem::CanActivate` não suporta esse recurso OLE, a substituição permite que você verifique essa situação e evite um possível erro de tempo de execução em seu aplicativo.

Se você estiver criando um novo aplicativo e quiser que ele funcione como um aplicativo de contêiner/servidor, escolha essa opção na caixa de diálogo Opções OLE no assistente do aplicativo e esse suporte será criado automaticamente. Para obter mais informações, consulte a visão geral do [artigo: Criando um contêiner de controle ActiveX](../mfc/reference/creating-an-mfc-activex-control-container.md). Para obter informações sobre amostras de MFC, consulte [MFC Samples](../overview/visual-cpp-samples.md#mfc-samples).

Observe que você não pode inserir um aplicativo MDI em si mesmo. Um aplicativo que é um contêiner/servidor não pode ser inserido em si mesmo a menos que seja um aplicativo SDI.

## <a name="links-to-embedded-objects"></a><a name="_core_links_to_embedded_objects"></a>Links para objetos incorporados

O recurso Links to Embedded Objects permite que um usuário crie um documento com um link OLE para um objeto incorporado dentro do aplicativo do contêiner. Por exemplo, crie um documento em um processador de texto contendo uma planilha incorporada. Se o aplicativo suportar links para objetos incorporados, ele poderá colar um link para a planilha contida no documento do processador de texto. Esse recurso permite que seu aplicativo use as informações contidas na planilha sem saber onde o processador de texto originalmente conseguiu.

#### <a name="to-link-to-embedded-objects-in-your-application"></a>Para vincular a objetos incorporados em sua aplicação

1. Obtenha sua classe `COleLinkingDoc` de `COleDocument`documentos em vez de .

1. Crie um ID de classe OLE **(CLSID)** para sua aplicação usando o Gerador de ID de classe incluído nas Ferramentas de Desenvolvimento OLE.

1. Registre o aplicativo no OLE.

1. Crie `COleTemplateServer` um objeto como membro da sua classe de aplicação.

1. Na função de `InitInstance` membro da sua classe de aplicação, faça o seguinte:

   - Conecte `COleTemplateServer` seu objeto aos modelos de `ConnectTemplate` documento chamando a função de membro do objeto.

   - Ligue `COleTemplateServer::RegisterAll` para a função membro para registrar todos os objetos de classe com o sistema OLE.

   - Chame `COleTemplateServer::UpdateRegistry`. O único parâmetro `UpdateRegistry` a ser *OAT_CONTAINER* se o aplicativo não for lançado com o interruptor "/Embedded". Isso registra o aplicativo como um contêiner que pode suportar links para objetos incorporados.

      Se o aplicativo for lançado com o switch "/Embedded", ele não deve mostrar sua janela principal, semelhante a um aplicativo de servidor.

A amostra [OLE Do](../overview/visual-cpp-samples.md) MFC Implementa esse recurso. Para um exemplo de como isso `InitInstance` é feito, consulte a função no *OCLIENT. Arquivo CPP* deste aplicativo de amostra.

## <a name="see-also"></a>Confira também

[Contêineres](../mfc/containers.md)<br/>
[Servidores](../mfc/servers.md)
