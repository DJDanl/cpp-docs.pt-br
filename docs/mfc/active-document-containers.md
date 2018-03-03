---
title: "Contêineres de documentos ativos | Microsoft Docs"
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
- active documents [MFC], containers
- active document containers [MFC]
- containers [MFC], active document
- MFC COM, active document containment
ms.assetid: ba20183a-8b4c-440f-9031-e5fcc41d391b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 87546f3c02025438b3e60cd2038fdc885dfedf9f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="active-document-containers"></a>Contêineres de documento ativos
Um contêiner de documento ativo, como o Microsoft Office Binder ou Internet Explorer, permite que você trabalhe com vários documentos de diferentes tipos de aplicativos em uma única estrutura (em vez de forçá-lo a criar e usar várias estruturas de aplicativo para cada tipo de documento).  
  
 MFC fornece suporte completo para contêineres de documento ativo no `COleDocObjectItem` classe. Você pode usar o Assistente de aplicativo MFC para criar um contêiner de documento ativo selecionando o **contêiner de documento ativo** caixa de seleção de **suporte a documentos compostos** página do Assistente de aplicativo MFC. Para obter mais informações, consulte [criando um aplicativo de contêiner de documento ativo](../mfc/creating-an-active-document-container-application.md).  
  
 Para obter mais informações sobre contêineres de documentos ativos, consulte:  
  
-   [Requisitos do contêiner](#container_requirements)  
  
-   [Objetos de Site do documento](#document_site_objects)  
  
-   [Exibir objetos do Site](#view_site_objects)  
  
-   [Objeto de Quadro](#frame_object)  
  
-   [Mesclagem do menu Ajuda](../mfc/help-menu-merging.md)  
  
-   [Impressão programática](../mfc/programmatic-printing.md)  
  
-   [Destinos de comando](../mfc/message-handling-and-command-targets.md)  
  
##  <a name="container_requirements"></a>Requisitos do contêiner  
 Suporte do documento ativo em um contêiner de documento ativo implica mais do que apenas as implementações de interface: também requer conhecimento de como usar as interfaces de um objeto contido. O mesmo se aplica a extensões do documento ativo, em que o contêiner também deve saber como usar essas interfaces de extensão nos próprios documentos ativos.  
  
 Um contêiner de documento ativo que integra documentos ativos deve:  
  
-   Ser capaz de manipular o armazenamento de objeto por meio de **IPersistStorage** interface, ou seja, ele deve fornecer um `IStorage` instância para cada documento ativo.  
  
-   Suporte os recursos básicos de incorporação de documentos OLE, necessidade nos objetos de "site" (uma por documento ou inserindo) que implementam **IOleClientSite** e **IAdviseSink**.  
  
-   Suporte a ativação no local de objetos inseridos ou documentos ativos. Objetos do site do contêiner devem implementar `IOleInPlaceSite` e objeto de quadro do contêiner deve fornecer **IOleInPlaceFrame**.  
  
-   Suporte a extensões dos documentos ativos implementando `IOleDocumentSite` para fornecer um mecanismo para o contêiner para se comunicar com o documento. Opcionalmente, o contêiner pode implementar as interfaces do documento ativo `IOleCommandTarget` e `IContinueCallback` para acompanhar comandos simples como imprimir ou salvar.  
  
 O objeto de quadro, os objetos de exibição e o objeto de contêiner podem implementar **IOleCommandTarget** para dar suporte a expedição de certos comandos, conforme discutido em [destinos de comando](../mfc/message-handling-and-command-targets.md). Objetos de exibição e contêiner também podem implementar `IPrint` e `IContinueCallback`, para dar suporte a impressão programática, conforme discutido em [impressão programática](../mfc/programmatic-printing.md).  
  
 A figura a seguir mostra as relações conceituais entre um contêiner e seus componentes (à esquerda) e o documento ativo e seus modos de exibição (à direita). O documento ativo gerencia o armazenamento e os dados e o modo de exibição exibe ou imprime opcionalmente que os dados. Interfaces em negrito são aqueles necessários para a participação do documento ativo; Esses negrito e itálico são opcionais. Todas as outras interfaces são necessárias.  
  
 ![Interfaces do contêiner de documento ativo](../mfc/media/vc37gj1.gif "vc37gj1")  
  
 Um documento que oferece suporte a apenas um modo de exibição pode implementar a exibição e o documento de componentes (ou seja, suas interfaces correspondentes) em uma única classe concreta. Além disso, um site de contêiner que dá suporte apenas a uma visualização por vez pode combinar o site de documentos e o site de modo de exibição em uma classe concreta de site único. Objeto de quadro do contêiner, porém, deve permanecer distinto e componente de documento do contêiner simplesmente está incluído aqui para fornecer uma visão completa da arquitetura; não é afetada por arquitetura de confinamento do documento ativo.  
  
##  <a name="document_site_objects"></a>Objetos de Site do documento  
 Na arquitetura de confinamento do documento ativo, um site de documento é o mesmo que um objeto de site do cliente em documentos OLE com a adição do `IOleDocument` interface:  
  
 `interface IOleDocumentSite : IUnknown`  
  
 `{`  
  
 `HRESULT ActivateMe(IOleDocumentView *pViewToActivate);`  
  
 `}`  
  
 Conceitualmente, o site de documento é o contêiner para um ou mais objetos de "Exibir site". Cada objeto de exibição de site está associado a objetos individuais do modo de exibição do documento gerenciados pelo site de documentos. Se o contêiner só oferece suporte a uma única exibição por site de documentos, ela pode implementar o site de documentos e o site de modo de exibição com uma única classe concreta.  
  
##  <a name="view_site_objects"></a>Exibir objetos do Site  
 Objeto de site do modo de exibição do contêiner gerencia o espaço de exibição de uma exibição específica de um documento. Além de oferecer suporte ao padrão `IOleInPlaceSite` interface, um site de modo de exibição geralmente também implementa `IContinueCallback` para controle programático de impressão. (Observe que o objeto de exibição nunca consulta `IContinueCallback` para realmente podem ser implementada em qualquer objeto os desejos de contêiner.)  
  
 Um contêiner que dá suporte a vários modos de exibição deve ser capaz de criar a exibição de vários objetos de site no site de documentos. Isso fornece cada modo de exibição com os serviços de ativação e desativação separados, conforme fornecido por meio de `IOleInPlaceSite`.  
  
##  <a name="frame_object"></a>Objeto de quadro  
 Objeto de quadro do contêiner é, a maior parte do tempo, mesmo quadro que é usado para ativação no local em documentos OLE, ou seja, aquele que lida com a negociação de menu e barra de ferramentas. Um objeto de exibição tem acesso a esse objeto de quadro por meio de **IOleInPlaceSite::GetWindowContext**, que também fornece acesso ao objeto de contêiner que representa o documento de contêiner (que pode lidar com a negociação de nível de painel de ferramentas e enumeração de objeto contido).  
  
 Um contêiner de documento ativo pode aumentar o quadro adicionando `IOleCommandTarget`. Isso permite que ele receber comandos que se originam na interface do usuário do documento ativo da mesma forma que essa interface pode permitir que um contêiner enviar os mesmos comandos (como **arquivo novo**, **abrir**,  **Salvar como**, **impressão**; **Editar cópia**, **colar**, **desfazer**e outros) para um documento ativo. Para obter mais informações, consulte [destinos de comando](../mfc/message-handling-and-command-targets.md).  
  
## <a name="see-also"></a>Consulte também  
 [Contenção de documentos ativos](../mfc/active-document-containment.md)

