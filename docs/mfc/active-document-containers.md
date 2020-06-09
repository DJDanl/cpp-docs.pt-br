---
title: Contêineres de documento ativos
ms.date: 11/19/2018
helpviewer_keywords:
- active documents [MFC], containers
- active document containers [MFC]
- containers [MFC], active document
- MFC COM, active document containment
ms.assetid: ba20183a-8b4c-440f-9031-e5fcc41d391b
ms.openlocfilehash: dc7017a205bedd716e5c87aa23ac96b257af2e16
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626029"
---
# <a name="active-document-containers"></a>Contêineres de documento ativos

Um contêiner de documento ativo, como o Microsoft Office Binder ou o Internet Explorer, permite que você trabalhe com vários documentos de diferentes tipos de aplicativo dentro de um único quadro (em vez de forçá-lo a criar e usar vários quadros de aplicativo para cada tipo de documento).

O MFC fornece suporte completo para contêineres de documento ativos na `COleDocObjectItem` classe. Você pode usar o assistente de aplicativo do MFC para criar um contêiner de documento ativo marcando a caixa de seleção **contêiner do documento ativo** na página de **suporte do documento composto** do assistente do aplicativo do MFC. Para obter mais informações, consulte [criando um aplicativo de contêiner de documento ativo](creating-an-active-document-container-application.md).

Para obter mais informações sobre contêineres de documento ativos, consulte:

- [Requisitos de contêiner](#container_requirements)

- [Documentar objetos do site](#document_site_objects)

- [Exibir objetos do site](#view_site_objects)

- [Objeto de Quadro](#frame_object)

- [Mesclagem do menu Ajuda](help-menu-merging.md)

- [Impressão programática](programmatic-printing.md)

- [Destinos de comando](message-handling-and-command-targets.md)

## <a name="container-requirements"></a><a name="container_requirements"></a>Requisitos de contêiner

O suporte a documentos ativos em um contêiner de documento ativo implica mais do que apenas implementações de interface: ele também requer o conhecimento do uso das interfaces de um objeto contido. O mesmo se aplica às extensões de documento ativas, em que o contêiner também deve saber como usar essas interfaces de extensão nos próprios documentos ativos.

Um contêiner de documento ativo que integra documentos ativos deve:

- Ser capaz de lidar com o armazenamento de objetos por meio da `IPersistStorage` interface, ou seja, deve fornecer uma `IStorage` instância para cada documento ativo.

- Dê suporte aos recursos básicos de incorporação de documentos OLE, que necessitam de objetos de "site" (um por documento ou incorporação) que implementam `IOleClientSite` e `IAdviseSink` .

- Suporte à ativação in-loco de objetos inseridos ou de documentos ativos. Os objetos do site do contêiner devem ser implementados `IOleInPlaceSite` e o objeto de quadro do contêiner deve fornecer `IOleInPlaceFrame` .

- Dê suporte às extensões de documentos ativos implementando `IOleDocumentSite` o para fornecer o mecanismo para o contêiner se comunicar com o documento. Opcionalmente, o contêiner pode implementar as interfaces de documento ativas `IOleCommandTarget` e `IContinueCallback` escolher comandos simples, como impressão ou salvamento.

O objeto frame, os objetos View e o objeto Container podem, opcionalmente, `IOleCommandTarget` ser implementados para dar suporte ao despacho de certos comandos, conforme discutido em [targets de comando](message-handling-and-command-targets.md). Os objetos View e Container também podem implementar opcionalmente `IPrint` e `IContinueCallback` , para dar suporte à impressão programática, conforme discutido na [impressão programática](programmatic-printing.md).

A figura a seguir mostra as relações conceituais entre um contêiner e seus componentes (à esquerda) e o documento ativo e suas exibições (à direita). O documento ativo gerencia o armazenamento e os dados, e a exibição exibe ou, opcionalmente, imprime esses dados. As interfaces em negrito são as necessárias para a participação do documento ativo; Esses negrito e itálico são opcionais. Todas as outras interfaces são necessárias.

![Interfaces de contêiner de documento ativo](../mfc/media/vc37gj1.gif "Interfaces de contêiner de documento ativo")

Um documento que dá suporte apenas a uma única exibição pode implementar os componentes de exibição e de documento (ou seja, suas interfaces correspondentes) em uma única classe concreta. Além disso, um site de contêiner que dá suporte apenas a uma exibição por vez pode combinar o site do documento e o site de exibição em uma única classe de site concreto. No entanto, o objeto de quadro do contêiner deve permanecer distinto e o componente do documento do contêiner é incluído aqui para dar uma visão completa da arquitetura; Ele não é afetado pela arquitetura de confinamento do documento ativo.

## <a name="document-site-objects"></a><a name="document_site_objects"></a>Documentar objetos do site

Na arquitetura de contenção do documento ativo, um site de documento é o mesmo que um objeto de site do cliente em documentos OLE com a adição da `IOleDocument` interface:

```cpp
interface IOleDocumentSite : IUnknown
{
    HRESULT ActivateMe(IOleDocumentView *pViewToActivate);
}
```

O site do documento é conceitualmente o contêiner de um ou mais objetos "Exibir site". Cada objeto de site de exibição é associado a objetos de exibição individuais do documento gerenciado pelo site do documento. Se o contêiner oferecer suporte apenas a uma única exibição por site de documento, ele poderá implementar o site do documento e o site de exibição com uma única classe concreta.

## <a name="view-site-objects"></a><a name="view_site_objects"></a>Exibir objetos do site

O objeto de site de exibição de um contêiner gerencia o espaço de exibição para uma exibição específica de um documento. Além de dar suporte à `IOleInPlaceSite` interface padrão, um site de exibição geralmente também implementa `IContinueCallback` para o controle de impressão programático. (Observe que o objeto View nunca consulta para que `IContinueCallback` possa realmente ser implementado em qualquer objeto que o contêiner desejar.)

Um contêiner que dá suporte a várias exibições deve ser capaz de criar vários objetos de site de exibição no site do documento. Isso fornece cada exibição com serviços separados de ativação e desativação, conforme fornecido por meio do `IOleInPlaceSite` .

## <a name="frame-object"></a><a name="frame_object"></a>Objeto de quadro

O objeto de quadro do contêiner é, na maior parte, o mesmo quadro usado para ativação in-loco em documentos OLE, ou seja, aquele que manipula a negociação de menus e barras de ferramentas. Um objeto View tem acesso a esse objeto frame por meio de `IOleInPlaceSite::GetWindowContext` , que também fornece acesso ao objeto contêiner que representa o documento de contêiner (que pode manipular a negociação de barra de ferramentas no nível do painel e a enumeração de objeto contida).

Um contêiner de documento ativo pode aumentar o quadro adicionando `IOleCommandTarget` . Isso permite que ele receba comandos originados na interface do usuário do documento ativo da mesma forma que essa interface pode permitir que um contêiner envie os mesmos comandos (como **arquivo novo**, **abrir**, **salvar como**, **Imprimir**; **Editar copiar**, **colar**, **desfazer**e outros) em um documento ativo. Para obter mais informações, consulte [destinos de comando](message-handling-and-command-targets.md).

## <a name="see-also"></a>Consulte também

[Contenção de documentos ativos](active-document-containment.md)
