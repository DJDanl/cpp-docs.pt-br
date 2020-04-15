---
title: Contêineres de documento ativos
ms.date: 11/19/2018
helpviewer_keywords:
- active documents [MFC], containers
- active document containers [MFC]
- containers [MFC], active document
- MFC COM, active document containment
ms.assetid: ba20183a-8b4c-440f-9031-e5fcc41d391b
ms.openlocfilehash: e2005ffed592fa1de278e0f6339d94687a20fd06
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81377392"
---
# <a name="active-document-containers"></a>Contêineres de documento ativos

Um contêiner de documentos ativo, como o Microsoft Office Binder ou o Internet Explorer, permite que você trabalhe com vários documentos de diferentes tipos de aplicativos dentro de um único quadro (em vez de forçá-lo a criar e usar vários quadros de aplicativos para cada tipo de documento).

O MFC fornece suporte total para `COleDocObjectItem` contêineres de documentos ativos na classe. Você pode usar o Assistente de Aplicativo Do MFC para criar um contêiner de documento ativo selecionando a caixa de seleção **de contêiner de documento ativo** na página de suporte a documentos **compostos** do Assistente de Aplicativo Do MFC. Para obter mais informações, consulte [Criando um aplicativo de contêiner de documento ativo](../mfc/creating-an-active-document-container-application.md).

Para obter mais informações sobre contêineres de documentos ativos, consulte:

- [Requisitos do contêiner](#container_requirements)

- [Objetos do site do documento](#document_site_objects)

- [Exibir objetos do site](#view_site_objects)

- [Objeto de Quadro](#frame_object)

- [Mesclagem do menu Ajuda](../mfc/help-menu-merging.md)

- [Impressão Programática](../mfc/programmatic-printing.md)

- [Destinos de comando](../mfc/message-handling-and-command-targets.md)

## <a name="container-requirements"></a><a name="container_requirements"></a>Requisitos do contêiner

O suporte ativo a documentos em um contêiner de documento ativo implica mais do que apenas implementações de interface: ele também requer conhecimento do uso das interfaces de um objeto contido. O mesmo se aplica às extensões ativas de documentos, onde o contêiner também deve saber como usar essas interfaces de extensão nos próprios documentos ativos.

Um contêiner de documentos ativo que integra documentos ativos deve:

- Seja capaz de lidar com `IPersistStorage` o armazenamento de objetos `IStorage` através da interface, ou seja, ele deve fornecer uma instância para cada documento ativo.

- Suporte aos recursos básicos de incorporação de documentos OLE, necessitando de objetos `IOleClientSite` "site" (um por documento ou incorporação) que implementem e `IAdviseSink`.

- Suporte à ativação in loac de objetos incorporados ou documentos ativos. Os objetos do local `IOleInPlaceSite` do contêiner devem ser `IOleInPlaceFrame`implementados e o objeto de armação do recipiente deve fornecer .

- Apoie as extensões dos documentos `IOleDocumentSite` ativos implementando o mecanismo para que o contêiner converse com o documento. Opcionalmente, o contêiner pode implementar `IOleCommandTarget` as `IContinueCallback` interfaces ativas de documentos e pegar comandos simples, como impressão ou economia.

O objeto de quadro, os objetos de `IOleCommandTarget` exibição e o objeto de contêiner podem ser implementados opcionalmente para suportar o envio de determinados comandos, conforme discutido em ['Command Targets '.](../mfc/message-handling-and-command-targets.md) A visualização e os `IPrint` objetos de contêiner também podem implementar e, `IContinueCallback`opcionalmente, apoiar a impressão programática, conforme discutido na [Impressão Programática.](../mfc/programmatic-printing.md)

A figura a seguir mostra as relações conceituais entre um contêiner e seus componentes (à esquerda), e o documento ativo e suas opiniões (à direita). O documento ativo gerencia o armazenamento e os dados, e a exibição exibe ou imprime opcionalmente esses dados. Interfaces em negrito são aquelas necessárias para a participação ativa de documentos; aqueles em negrito e itálico são opcionais. Todas as outras interfaces são necessárias.

![Interfaces ativas de contêineres de documentos](../mfc/media/vc37gj1.gif "Interfaces ativas de contêineres de documentos")

Um documento que suporta apenas uma única visualização pode implementar os componentes de exibição e documento (ou seja, suas interfaces correspondentes) em uma única classe de concreto. Além disso, um site de contêineres que suporta apenas uma visualização por vez pode combinar o local do documento e o local de exibição em uma única classe de local de concreto. O objeto de quadro do contêiner, no entanto, deve permanecer distinto, e o componente do documento do contêiner é meramente incluído aqui para dar uma imagem completa da arquitetura; não é afetada pela arquitetura ativa de contenção de documentos.

## <a name="document-site-objects"></a><a name="document_site_objects"></a>Objetos do site do documento

Na arquitetura ativa de contenção de documentos, um site de documento é o `IOleDocument` mesmo que um objeto de site cliente em Documentos OLE com a adição da interface:

```cpp
interface IOleDocumentSite : IUnknown
{
    HRESULT ActivateMe(IOleDocumentView *pViewToActivate);
}
```

O site do documento é conceitualmente o contêiner para um ou mais objetos "view site". Cada objeto do site de exibição está associado a objetos de exibição individuais do documento gerenciados pelo site do documento. Se o contêiner suportar apenas uma única visualização por site do documento, ele poderá implementar o site do documento e o local de exibição com uma única classe de concreto.

## <a name="view-site-objects"></a><a name="view_site_objects"></a>Exibir objetos do site

O objeto do site de visualização de um contêiner gerencia o espaço de exibição para uma exibição específica de um documento. Além de suportar `IOleInPlaceSite` a interface padrão, um site `IContinueCallback` de visualização também geralmente implementa para controle de impressão programática. (Observe que o objeto de `IContinueCallback` exibição nunca consulta para que ele possa realmente ser implementado em qualquer objeto que o contêiner deseja.)

Um contêiner que suporta várias visualizações deve ser capaz de criar vários objetos de site de visualização dentro do site do documento. Isso fornece a cada visualização serviços separados de ativação e desativação, conforme fornecido por meio `IOleInPlaceSite`.

## <a name="frame-object"></a><a name="frame_object"></a>Objeto de quadro

O objeto de quadro do contêiner é, na maioria das vezes, o mesmo quadro que é usado para ativação no local em Documentos OLE, ou seja, aquele que lida com menu e negociação de barra de ferramentas. Um objeto de exibição tem `IOleInPlaceSite::GetWindowContext`acesso a este objeto de quadro através de , que também fornece acesso ao objeto de contêiner representando o documento do contêiner (que pode lidar com a negociação da barra de ferramentas em nível de painel e continha enumeração do objeto).

Um recipiente de documento ativo `IOleCommandTarget`pode aumentar o quadro adicionando . Isso permite que ele receba comandos que se originam na interface de usuário do documento ativo da mesma forma que esta interface pode permitir que um contêiner envie os mesmos comandos (como **File New**, **Open,** **Save As,** **Print;** **Editar Copiar,** **Colar,** **Desfazer**e outros) para um documento ativo. Para obter mais informações, consulte ['Alvos de comando'.](../mfc/message-handling-and-command-targets.md)

## <a name="see-also"></a>Confira também

[Contenção de documentos ativos](../mfc/active-document-containment.md)
