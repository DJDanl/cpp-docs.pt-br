---
title: "Cont&#234;ineres: recursos avan&#231;ados | Microsoft Docs"
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
  - "aplicativos de contêiner/servidor [C++]"
  - "contêineres [C++], recursos avançados"
  - "contêineres [C++], aplicativos de contêiner"
  - "contêineres [C++], links para objetos OLE inseridos"
  - "objetos inseridos [C++]"
  - "links [C++], para objetos OLE inseridos"
  - "Contêineres OLE, recursos avançados"
  - "Controles OLE, contêineres"
  - "aplicativos de servidor/contêiner"
ms.assetid: 221fd99c-b138-40fa-ad6a-974e3b3ad1f8
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres: recursos avan&#231;ados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este artigo descreve as etapas necessárias para inserir recursos avançados opcionais em aplicativos de contêiner existentes.  Esses recursos são:  
  
-   [Um aplicativo que é um contêiner e um servidor](#_core_creating_a_container.2f.server_application)  
  
-   [Um link OLE como um objeto inserido](#_core_links_to_embedded_objects)  
  
##  <a name="_core_creating_a_container.2f.server_application"></a> Criando um contêiner\/aplicativo de servidor  
 Um contêiner\/aplicativo de servidor é um aplicativo que atue como um contêiner e um servidor.  O Microsoft Word para o windows é um exemplo desse.  Você pode inserir palavras para documentos do windows em outros aplicativos, e você também pode inserir itens no word para documentos do windows.  O processo para alterar o aplicativo de contêiner ser um contêiner e um servidor completo \(não é possível criar um aplicativo do contêiner\/miniserver de combinação\) é semelhante ao processo para criar um servidor completo.  
  
 O artigo [Servidores: Implementando um servidor](../mfc/servers-implementing-a-server.md) lista um número de tarefas necessárias para implementar um aplicativo de servidor.  Se você converter um aplicativo de contêineres ao contêiner\/aplicativo de servidor, você precisa executar algumas das mesmas tarefas, adicionando código ao contêiner.  O a seguir lista as coisas importantes para serem consideradas:  
  
-   O código do contêiner criado pelo assistente de aplicativo já inicializa o subsistema OLE.  Você não precisará alterar ou adicionar nada para esse suporte.  
  
-   Onde a classe base de uma classe do documento é `COleDocument`, altera a classe base na `COleServerDoc`.  
  
-   Substituir `COleClientItem::CanActivate` para evitar editar itens em vigor quando o próprio servidor é usado para editar no lugar.  
  
     Por exemplo, o exemplo [OCLIENT](../top/visual-cpp-samples.md) MFC OLE inseriu um item criado por seus contêineres\/aplicativo de servidor.  Você abre o aplicativo de OCLIENT e edição em que o item criado por seus contêineres\/aplicativo de servidor.  Ao editar o item do seu aplicativo, você decide que você deseja inserir um item criado por exemplo [HIERSVR](../top/visual-cpp-samples.md)MFC OLE.  Para fazer isso, você não pode usar a ativação local.  Você deve abrir totalmente HIERSVR para ativar esse item.  Como a biblioteca de classes do Microsoft não oferece suporte a esse recurso OLE, substitua `COleClientItem::CanActivate` permite verificar a existência dessa situação e evitar um erro em tempo de execução possível em seu aplicativo.  
  
 Se você estiver criando um novo aplicativo e quiser funcionar como um contêiner\/aplicativo de servidor, escolher a opção na caixa de diálogo OLE as opções no assistente de aplicativo e neste suporte será criada automaticamente.  Para obter mais informações, consulte o artigo [Visão geral: Criando um contêiner do controle ActiveX](../mfc/reference/creating-an-mfc-activex-control-container.md).  Para obter informações sobre exemplos, consulte MFC MFC Exemplos.  
  
 Observe que você não pode inserir um aplicativo MDI no outro.  Um aplicativo que é um contêiner\/servidor não pode ser inserido em se a menos que seja um aplicativo de SDI.  
  
##  <a name="_core_links_to_embedded_objects"></a> Links para objetos inseridos  
 Links para o recurso inserido de objetos permite que um usuário para criar um documento com um link OLE como um objeto inserido dentro de seu aplicativo do contêiner.  Por exemplo, crie um documento em um processador de textos que contém uma planilha inserido.  Se os links da suporte a objetos de aplicativos inseridos, ele pode colar um link para a planilha contida no documento de tratamento de textos.  Esse recurso permite seu aplicativo usar as informações contidas na planilha não saiba onde o tratamento de textos a obteve originalmente.  
  
#### Para vincular a objetos incorporados em seu aplicativo  
  
1.  Derivar a sua classe de documento de `COleLinkingDoc` em vez de `COleDocument`.  
  
2.  Crie uma ID OLE da classe**CLSID**\(\) para o seu aplicativo usando o gerador de ID da classe incluído com as ferramentas de desenvolvimento do.  
  
3.  Registrar o aplicativo com OLE.  
  
4.  Crie um objeto de `COleTemplateServer` como um membro da classe do aplicativo.  
  
5.  Na função de membro de `InitInstance` da sua classe de aplicativo, faça o seguinte:  
  
    -   Se conectar ao objeto de `COleTemplateServer` com os modelos do documento chamando a função de membro de `ConnectTemplate` do objeto.  
  
    -   Chame a função de membro de **COleTemplateServer::RegisterAll** para registrar todos os objetos da classe com o sistema OLE.  
  
    -   Chame `COleTemplateServer::UpdateRegistry`.  O único parâmetro a `UpdateRegistry` deve ser `OAT_CONTAINER` se o aplicativo não é iniciado com a opção de “\/Embedded”.  Isso registra o aplicativo como um contêiner que pode links de suporte a objetos inseridos.  
  
         Se o aplicativo é iniciado com a opção de “\/Embedded”, não deve exibir a janela principal, semelhante a um aplicativo de servidor.  
  
 O exemplo [OCLIENT](../top/visual-cpp-samples.md) MFC OLE implementa esse recurso.  Para obter um exemplo de como isso é feito, consulte a função de `InitInstance` no arquivo de OCLIENT.CPP desse aplicativo de exemplo.  
  
## Consulte também  
 [Contêineres](../mfc/containers.md)   
 [Servidores](../mfc/servers.md)