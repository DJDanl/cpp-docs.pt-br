---
title: "Contêineres: Recursos avançados | Microsoft Docs"
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
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4e79b1c88996e835a907129fa5810d4c4dca0770
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="containers-advanced-features"></a>Contêineres: funcionalidades avançadas
Este artigo descreve as etapas necessárias para incorporar recursos avançados opcionais em aplicativos de contêiner existente. Esses recursos são:  
  
-   [Um aplicativo que é um recipiente e um servidor](#_core_creating_a_container_server_application)  
  
-   [Um vínculo OLE com um objeto inserido](#_core_links_to_embedded_objects)  
  
##  <a name="_core_creating_a_container_server_application"></a>Criando um aplicativo de contêiner/servidor  
 Um aplicativo de contêiner/servidor é um aplicativo que atua como um recipiente e um servidor. Microsoft Word para Windows é um exemplo disso. Você pode inserir documentos do Word para Windows em outros aplicativos, e você também pode inserir itens em documentos do Word para Windows. O processo para modificar seu aplicativo de contêiner para um contêiner e um servidor completo (você não pode criar um aplicativo de contêiner/miniserver combinação) é semelhante ao processo de criação de um servidor completo.  
  
 O artigo [servidores: Implementando um servidor](../mfc/servers-implementing-a-server.md) relaciona um número de tarefas necessárias para implementar um aplicativo de servidor. Se você converter um aplicativo de contêiner para um aplicativo de contêiner/servidor, em seguida, você precisa executar algumas dessas mesmas tarefas, adicionando o código para o contêiner. O exemplo a seguir lista as coisas importantes a considerar:  
  
-   O código de contêiner criado pelo Assistente de aplicativo já inicializa o subsistema OLE. Você não precisa alterar ou adicionar qualquer coisa para esse suporte.  
  
-   Sempre que a classe base de uma classe de documento é `COleDocument`, alterar a classe base para `COleServerDoc`.  
  
-   Substituir `COleClientItem::CanActivate` para evitar a edição de itens em vigor enquanto o servidor estiver sendo usado para editar no local.  
  
     Por exemplo, o OLE do MFC exemplo [OCLIENT](../visual-cpp-samples.md) incorporou um item criado por seu aplicativo de contêiner/servidor. Abra o aplicativo OCLIENT e in-loco editar o item criado por seu aplicativo de contêiner/servidor. Ao editar o item do seu aplicativo, você decidir que deseja inserir um item criado pelo OLE do MFC exemplo [HIERSVR](../visual-cpp-samples.md). Para fazer isso, você não pode usar a ativação no local. Abra totalmente HIERSVR para ativar esse item. Porque a biblioteca Microsoft Foundation Class não oferece suporte a esse recurso OLE, substituindo `COleClientItem::CanActivate` permite verificar essa situação e evitar um possível erro de tempo de execução em seu aplicativo.  
  
 Se você estiver criando um novo aplicativo e deseja que ele funcione como um aplicativo de contêiner/servidor, escolha a que a opção na caixa de diálogo OLE opções no Assistente de aplicativo e esse suporte será criada automaticamente. Para obter mais informações, consulte o artigo [visão geral: Criando um contêiner de controle ActiveX](../mfc/reference/creating-an-mfc-activex-control-container.md). Para obter informações sobre exemplos MFC, consulte exemplos do MFC.  
  
 Observe que você não pode inserir um aplicativo MDI em si. Um aplicativo que é um contêiner/servidor não pode ser inserido em si mesmo, a menos que ele é um aplicativo SDI.  
  
##  <a name="_core_links_to_embedded_objects"></a>Links para objetos inseridos  
 Os Links para recursos de objetos inseridos permite que um usuário criar um documento com um vínculo OLE com um objeto inserido dentro de seu aplicativo de contêiner. Por exemplo, crie um documento em um processador de texto que contém uma planilha incorporada. Se seu aplicativo dá suporte a links para objetos incorporados, ele pode colar um link para a planilha contida no documento do word do processador. Esse recurso permite que seu aplicativo para usar as informações contidas na planilha sem saber em que o processador de textos originalmente acertou.  
  
#### <a name="to-link-to-embedded-objects-in-your-application"></a>Para vincular a objetos inseridos em seu aplicativo  
  
1.  Derive sua classe de documento da `COleLinkingDoc` em vez de `COleDocument`.  
  
2.  Crie uma ID de classe OLE (**CLSID**) para seu aplicativo usando o gerador de ID de classe incluído com as ferramentas de desenvolvimento OLE.  
  
3.  Registre o aplicativo com OLE.  
  
4.  Criar uma `COleTemplateServer` objeto como um membro da classe do aplicativo.  
  
5.  Em sua classe de aplicativo `InitInstance` membro de função, faça o seguinte:  
  
    -   Conecte-se a `COleTemplateServer` objeto para os modelos de documento chamando o objeto `ConnectTemplate` função de membro.  
  
    -   Chamar o **COleTemplateServer::RegisterAll** a função de membro para registrar todos os objetos de classe com o sistema OLE.  
  
    -   Call `COleTemplateServer::UpdateRegistry`. O único parâmetro para `UpdateRegistry` devem ser `OAT_CONTAINER` se o aplicativo não é iniciado com a opção "/ incorporado". Isso registra o aplicativo como um contêiner que pode dar suporte a links para objetos inseridos.  
  
         Se o aplicativo é iniciado com a opção "/ inserido", ele não deve exibir a janela principal, semelhante a um aplicativo de servidor.  
  
 O exemplo OLE do MFC [OCLIENT](../visual-cpp-samples.md) implementa esse recurso. Para obter um exemplo de como fazer isso, consulte o `InitInstance` função o OCLIENT. Arquivo CPP desse aplicativo de exemplo.  
  
## <a name="see-also"></a>Consulte também  
 [Contêineres](../mfc/containers.md)   
 [Servidores](../mfc/servers.md)

