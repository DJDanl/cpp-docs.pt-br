---
title: "Plano de fundo OLE | Microsoft Docs"
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
  - "OLE, sobre OLE"
ms.assetid: 5f654eb5-66b1-40c9-9215-bb85356a67f8
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Plano de fundo OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

OLE é um mecanismo que permite que os usuários criem e editar documentos que contêm os itens” ou “os objetos criados por vários aplicativos.  
  
> [!NOTE]
>  OLE era originalmente um acrônimo do objeto que vincula e que insere.  No entanto, agora é conhecido como OLE.  As partes de OLE não relacionadas ao qual vincular\-se e inserir agora fazem parte da tecnologia ativa.  
  
 Os documentos OLE, historicamente documentos compostos, chamados são integrados de forma direta vários tipos de dados, ou dos componentes do.  Os trechos sadios, as planilhas, e os bitmaps são exemplos comuns dos componentes localizados em documentos com OLE DB.  Ofereça suporte a OLE em seu aplicativo permite que os usuários usem documentos com OLE DB sem se preocupar sobre como trocar entre os aplicativos diferentes; OLE faz a alternância para você.  
  
 Você usa um aplicativo de contêiner criar documentos compostos e um aplicativo de aplicativo de servidor ou do componente criar os itens dentro do documento contêiner.  Qualquer aplicativo que escreva pode ser um contêiner, um servidor, ou ambos.  
  
 OLE inserir muitos conceitos diferentes que todo o trabalho para a meta da interação transparente entre aplicativos.  Essas áreas incluem o seguinte:  
  
 Vincular e inserir  
 Vincular e inserir são os dois métodos para armazenar os itens criados em um documento OLE que foram criados em outro aplicativo.  Para obter informações gerais sobre as diferenças entre os dois, consulte o artigo [Plano de fundo OLE: Vincular e inserir](../mfc/ole-background-linking-and-embedding.md).  Para obter mais informações detalhadas, consulte os artigos [Contêiner](../mfc/containers.md) e [Servidores](../mfc/servers.md).  
  
 Ativação local \(edição visual\)  
 Alternando um item inserido no contexto do documento contêiner é chamado de ativação é uma edição visual.  A interface de aplicativo de contêiner muda para inserir os recursos de aplicativo componente que criou o item inserido.  Os itens vinculados são ativados nunca no lugar porque os dados reais para o item são contidos em um arquivo separado, fora do contexto do aplicativo que contém o link.  Para obter mais informações sobre de ativação no local, consulte o artigo [Ativação](../mfc/activation-cpp.md).  
  
> [!NOTE]
>  Vincular e inserir e ativação in\-loco fornecem os recursos principais de edição visual OLE.  
  
 Automação  
 A automação permite que um aplicativo resultar em outro aplicativo.  O aplicativo à esquerda é conhecido como um cliente de automação, e o aplicativo que está sendo controlado por é conhecido como um servidor de automação ou componente de automação.  Para obter mais informações sobre a automação, consulte os artigos [Clientes de automação](../mfc/automation-clients.md) e [Servidores de automação](../mfc/automation-servers.md).  
  
> [!NOTE]
>  A automação funciona em contextos OLE e ativas de tecnologia.  Você pode automatizar qualquer objeto baseado em COM.  
  
 Arquivos compostos  
 Os arquivos compostos fornecem um formato de arquivo padrão que simplifica o armazenamento estruturado de documentos compostos para aplicativos OLE.  Dentro de um arquivo composto, os armazenamentos têm muitos recursos de diretórios e os fluxos têm muitos recursos de arquivos.  Essa tecnologia também é chamada de armazenamento estruturado.  Para obter mais informações sobre arquivos compostos, consulte o artigo [Contêiner: Arquivos compostos](../mfc/containers-compound-files.md).  
  
 Transferência de dados\)  
 A transferência de dados uniforme \(UDT\) é um conjunto de interfaces que permitem que os dados sejam enviados e recebidos em uma forma padrão, independentemente do método escolhido real para transferir os dados.  O UDT é a base para transferências de dados por arrastar e soltar pela.  O UDT agora atua como a base para a transferência de dados existente do windows, como a área de transferência e troca dinâmicas de dados \(DDE\).  Para obter mais informações sobre o UDT, consulte o artigo [Objetos de dados e fontes de dados \(OLE\)](../mfc/data-objects-and-data-sources-ole.md).  
  
 Drag and Drop \(Arrastar e Soltar\)  
 Arraste e remoção é uma técnica fácil de usar anexado, a manipulação transferir dados entre aplicativos, entre o windows em um aplicativo, ou mesmo dentro de uma única janela em um aplicativo.  Os dados a serem transferidos são selecionados e arrastados ao destino desejado.  O arrastar e soltar são baseados na transferência de dados\).  Para obter mais informações sobre o arraste e solte, consulte o artigo [Arraste e solte](../mfc/drag-and-drop-ole.md).  
  
 Component Object Model  
 O Component Object Model \(COM\) fornece a infraestrutura usada quando os objetos OLE se comunicam entre si.  As classes DE MFC simplificam COM para o programador.  COM faz parte da tecnologia ativa, como os objetos COM são a base da tecnologia OLE e ativa.  Para obter mais informações sobre como COM o, consulte os tópicos de [Biblioteca ativa \(ATL\) do modelo](../atl/active-template-library-atl-concepts.md) .  
  
 Alguns dos tópicos com OLE DB mais importantes são abordados nos artigos a seguir:  
  
-   [Plano de fundo OLE: Vincular e inserir](../mfc/ole-background-linking-and-embedding.md)  
  
-   [Plano de fundo OLE: Contêineres e servidores](../mfc/ole-background-containers-and-servers.md)  
  
-   [Plano de fundo OLE: Estratégias de implementação](../mfc/ole-background-implementation-strategies.md)  
  
-   [Plano de fundo OLE: Implementação de MFC](../mfc/ole-background-mfc-implementation.md)  
  
 Para obter informações OLE em geral não encontrada nos artigos acima, pesquisa para OLE no MSDN.  
  
## Consulte também  
 [OLE](../mfc/ole-in-mfc.md)