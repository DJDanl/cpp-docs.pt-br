---
title: "Cont&#234;ineres de documento ativos | Microsoft Docs"
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
  - "contêineres de documentos ativos [C++]"
  - "documentos ativos [C++], contêineres"
  - "contêineres [C++], documento ativo"
  - "COM MFC [C++], contenção de documentos ativos"
ms.assetid: ba20183a-8b4c-440f-9031-e5fcc41d391b
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres de documento ativos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um contêiner ativa do documento, como a pasta do Microsoft Office ou o Internet Explorer, permite que você trabalhe com vários documentos de tipos de aplicativos diferentes dentro de um único quadro \(em vez de forçar para criar e usar várias peças de aplicativo para cada tipo de documento\).  
  
 MFC O oferece suporte completo para contêineres ativas do documento na classe de `COleDocObjectItem` .  Você pode usar o assistente de aplicativo MFC para criar um contêiner ativa do documento selecionando a caixa de seleção de **Active document container** na página de **Compound Document Support** do assistente de aplicativo MFC.  Para obter mais informações, consulte [Criando um aplicativo de contêineres do documento ativo](../mfc/creating-an-active-document-container-application.md).  
  
 Para obter mais informações sobre os contêineres ativas do documento, consulte:  
  
-   [Requisitos do contêiner](#container_requirements)  
  
-   [Objetos do site do documento](#document_site_objects)  
  
-   [Objetos do site da exibição](#view_site_objects)  
  
-   [Objeto de quadro](#frame_object)  
  
-   [A mesclagem do menu ajuda](../Topic/Help%20Menu%20Merging.md)  
  
-   [Impressão programático](../mfc/programmatic-printing.md)  
  
-   [Destinos de comando](../mfc/message-handling-and-command-targets.md)  
  
##  <a name="container_requirements"></a> Requisitos do contêiner  
 O suporte ativa do documento em um contêiner do documento ativo implica mais do que simplesmente implementações da interface: também requer o conhecimento de usar as interfaces de um objeto contido.  O mesmo se aplica às extensões ativas do documento, em que o contêiner também deve saber como usar essas interfaces em documentos ativas próprias de extensão.  
  
 Um contêiner ativa do documento que integra documentos ativas deve:  
  
-   É capaz de armazenamento do objeto de manipulação por meio da interface de **IPersistStorage** , ou seja, deve fornecer uma instância de `IStorage` a cada documento ativo.  
  
-   Oferecer suporte aos recursos básicos de inserção de documentos OLE, necessitando a “site” objects \(uma pelo documento ou inserir\) que implementam **IOleClientSite** e **IAdviseSink**.  
  
-   Oferecer suporte à ativação in\-loco de objetos inseridos ou de documentos ativas.  Os objetos do site do contêiner deve implementar `IOleInPlaceSite` e o objeto do quadro do contêiner deve fornecer **IOleInPlaceFrame**.  
  
-   Oferecer suporte às extensões ativas de documentos implementando `IOleDocumentSite` para fornecer um mecanismo para que o contêiner fale ao documento.  Opcionalmente, o contêiner pode implementar as interfaces ativas `IOleCommandTarget` e `IContinueCallback` do documento para obter comandos simples como a impressão ou salvamento.  
  
 O objeto do quadro, os objetos de exibição, e o objeto de contêiner podem se desejar implementar **IOleCommandTarget** para dar suporte a expedição de certos comandos, como discutido em [Destinos de comando](../mfc/message-handling-and-command-targets.md).  A exibição e os objetos de contêiner também podem implementar `IPrint` e `IContinueCallback`opcionalmente, para dar suporte à impressão programática, conforme discutido em [Impressão programático](../mfc/programmatic-printing.md).  
  
 A figura a seguir mostra as relações entre conceituais um contêiner e seus componentes \(à esquerda\), e o documento ativo e suas exibições \(no lado direito\).  O documento ativo gerencia o armazenamento e os dados, e a exibição exibe ou opcionalmente as cópias de dados.  As interfaces em negrito são as necessárias para participação do documento ativo; aqueles em negrito e itálico são opcionais.  Todas as interfaces forem necessárias.  
  
 ![Interfaces de contêiner do documento ativo](../mfc/media/vc37gj1.png "vc37gj1")  
  
 Um documento que da suporte a apenas uma única exibição pode implementar os componentes de exibição e do documento \(ou seja, as interfaces correspondentes\) em uma única classe concreta.  Além disso, um site do contêiner que da suporte a apenas uma exibição de cada vez pode combinar o site do documento e o site de exibição em uma única classe concreta do site.  O objeto do quadro do contêiner, porém, deve permanecer distintos, e o componente do documento contêiner é incluído aqui apenas para fornecer uma imagem completa da arquitetura; não é afetada pela arquitetura ativa de retenção de documentos.  
  
##  <a name="document_site_objects"></a> Objetos do site do documento  
 Ativa na arquitetura de retenção de documentos, em um site do documento é igual a um objeto de site do cliente em documentos com OLE DB com a adição da interface de `IOleDocument` :  
  
 `interface IOleDocumentSite : IUnknown`  
  
 `{`  
  
 `HRESULT ActivateMe(IOleDocumentView *pViewToActivate);`  
  
 `}`  
  
 O site do documento é conceitualmente o contêiner para um ou mais objetos de “do site exibição”.  Cada objeto de site da exibição é associado aos objetos de exibição individuais do documento gerenciado por site do documento.  Se o contêiner da suporte apenas a uma única exibição por site do documento, você poderá implementar o site do documento e o site da exibição com uma única classe concreta.  
  
##  <a name="view_site_objects"></a> Objetos do site da exibição  
 O objeto de site de exibição de um contêiner gerencia o espaço de exibição para uma exibição específica de um documento.  Além de oferecer suporte à interface padrão de `IOleInPlaceSite` , um site exibição também implementa geralmente `IContinueCallback` para o controle de impressão programática. \(Observe que o objeto de exibição nunca consulta para `IContinueCallback` para que possam ser realmente implementadas em qualquer objeto que o contêiner desejada.\)  
  
 Um contêiner que da suporte a várias exibições deve ser capaz de criar vários objetos do site da exibição no site de documento.  Isso fornece cada exibição com serviços separados de ativação e a desativação da forma esperada com `IOleInPlaceSite`.  
  
##  <a name="frame_object"></a> Objeto de quadro  
 O objeto do quadro do contêiner é, em geral, o mesmo tableau que é usado para ativação o local em documentos OLE, isto é, o que trata a negociação no menu e a barra de ferramentas.  Um objeto de exibição tem acesso a esse objeto do quadro com **IOleInPlaceSite::GetWindowContext**, que também fornece acesso ao objeto contêiner que representa o documento contêiner \(que pode controlar a negociação da barra de ferramentas do painel nível e a enumeração contida do objeto\).  
  
 Um contêiner ativa do documento pode aumentar o quadro adicionando `IOleCommandTarget`.  Isso permite receber os comandos que se originam na interface de usuário ativa do documento da mesma forma que essa interface pode permitir que um contêiner envie os mesmos comandos \(como **File New**, **Abrir**, **Salvar como**, **Imprimir**; **Edit Copy**, **Colar**, **Desfazer**, entre outros\) a um documento ativo.  Para obter mais informações, consulte [Destinos de comando](../mfc/message-handling-and-command-targets.md).  
  
## Consulte também  
 [Contenção de documento ativa](../mfc/active-document-containment.md)