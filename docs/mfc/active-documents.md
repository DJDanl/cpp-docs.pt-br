---
title: Documentos ativos
ms.date: 11/04/2016
helpviewer_keywords:
- active documents [MFC]
- active documents [MFC], requirements
- view objects [MFC], requirements
- OLE [MFC], active documents
- views [MFC], active documents
- active documents [MFC], views
ms.assetid: 1378f18e-aaa6-420b-8501-4b974905baa0
ms.openlocfilehash: bfe91dcb42b97ddfbb0bf0be36a54b45e6dc0809
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625167"
---
# <a name="active-documents"></a>Documentos ativos

Os documentos ativos estendem a tecnologia de documentos compostos do OLE. Essas extensões são fornecidas na forma de interfaces adicionais que gerenciam exibições, para que os objetos possam funcionar dentro de contêineres e ainda manter o controle sobre suas funções de exibição e impressão. Esse processo possibilita a exibição de documentos em quadros estrangeiros (como o Microsoft Office Binder ou o Microsoft Internet Explorer) e em quadros nativos (como as próprias portas de exibição do produto).

Esta seção descreve os [requisitos funcionais para documentos ativos](#requirements_for_active_documents). O documento ativo possui um conjunto de dados e tem acesso ao armazenamento onde os dados podem ser salvos e recuperados. Ele pode criar e gerenciar uma ou mais exibições em seus dados. Além de dar suporte à incorporação usual e às interfaces de ativação in-loco de documentos OLE, o documento ativo comunica sua capacidade de criar exibições por meio do `IOleDocument` . Por meio dessa interface, o contêiner pode pedir para criar (e possivelmente enumerar) as exibições que o documento ativo pode exibir. Por meio dessa interface, o documento ativo também pode fornecer informações diversas sobre si mesmo, como se ele dá suporte a vários modos de exibição ou retângulos complexos.

A seguir está a `IOleDocument` interface. Observe que a `IEnumOleDocumentViews` interface é um enumerador OLE padrão para `IOleDocumentView*` tipos.

```
interface IOleDocument : IUnknown
    {
    HRESULT CreateView(
        [in] IOleInPlaceSite *pIPSite,
        [in] IStream *pstm,
        [in] DWORD dwReserved,
        [out] IOleDocumentView **ppView);

    HRESULT GetDocMiscStatus([out] DWORD *pdwStatus);

    HRESULT EnumViews(
        [out] IEnumOleDocumentViews **ppEnum,
        [out] IOleDocumentView **ppView);
    }
```

Cada documento ativo deve ter um provedor de quadro de exibição com esta interface. Se o documento não estiver inserido em um contêiner, o próprio servidor de documentos ativo deverá fornecer o quadro de exibição. No entanto, quando o documento ativo é inserido em um contêiner de documento ativo, o contêiner fornece o quadro de exibição.

Um documento ativo pode criar um ou mais tipos de [exibições](#requirements_for_view_objects) de seus dados (por exemplo, normal, estrutura de tópicos, layout de página e assim por diante). As exibições atuam como filtros por meio dos quais os dados podem ser vistos. Mesmo que o documento tenha apenas um tipo de exibição, talvez você ainda queira dar suporte a várias exibições como meio de dar suporte à nova funcionalidade de janela (por exemplo, o novo item de **janela** no menu **janela** em aplicativos do Office).

## <a name="requirements-for-active-documents"></a><a name="requirements_for_active_documents"></a>Requisitos para documentos ativos

Um documento ativo que pode ser exibido em um contêiner de documento ativo deve:

- Use os arquivos compostos do OLE como seu mecanismo de armazenamento implementando `IPersistStorage` .

- Suporte aos recursos básicos de incorporação de documentos OLE, incluindo **criar do arquivo**. Isso exige as interfaces `IPersistFile` , `IOleObject` e `IDataObject` .

- Suporte a uma ou mais exibições, cada uma delas capaz de ativação in-loco. Ou seja, as exibições devem dar suporte à interface, `IOleDocumentView` bem como às interfaces `IOleInPlaceObject` e `IOleInPlaceActiveObject` (usando as `IOleInPlaceSite` interfaces e do contêiner `IOleInPlaceFrame` ).

- Dê suporte às interfaces de documento ativo padrão `IOleDocument` , `IOleCommandTarget` e `IPrint` .

O conhecimento de quando e como usar as interfaces do lado do contêiner é implícito nesses requisitos.

## <a name="requirements-for-view-objects"></a><a name="requirements_for_view_objects"></a>Requisitos para objetos de exibição

Um documento ativo pode criar uma ou mais exibições de seus dados. Funcionalmente, essas exibições são como portas em um método específico para exibir os dados. Se um documento ativo der suporte apenas a uma única exibição, o documento ativo e esse modo de exibição único poderão ser implementados usando uma única classe. `IOleDocument::CreateView`Retorna o ponteiro de interface do mesmo objeto `IOleDocumentView` .

Para ser representado em um contêiner de documento ativo, um componente de exibição deve oferecer suporte `IOleInPlaceObject` e, `IOleInPlaceActiveObject` além de `IOleDocumentView` :

```
interface IOleDocumentView : IUnknown
    {
    HRESULT SetInPlaceSite([in] IOleInPlaceSite *pIPSite);
    HRESULT GetInPlaceSite([out] IOleInPlaceSite **ppIPSite);
    HRESULT GetDocument([out] IUnknown **ppunk);
    [input_sync] HRESULT SetRect([in] LPRECT prcView);
    HRESULT GetRect([in] LPRECT prcView);
    [input_sync] HRESULT SetRectComplex(
        [in] LPRECT prcView,
        [in] LPRECT prcHScroll,
        [in] LPRECT prcVScroll,
        [in] LPRECT prcSizeBox);
    HRESULT Show([in] BOOL fShow);
    HRESULT UIActivate([in] BOOL fUIActivate);
    HRESULT Open(void);
    HRESULT CloseView([in] DWORD dwReserved);
    HRESULT SaveViewState([in] IStream *pstm);
    HRESULT ApplyViewState([in] IStream *pstm);
    HRESULT Clone(
        [in] IOleInPlaceSite *pIPSiteNew,
        [out] IOleDocumentView **ppViewNew);
    }
```

Cada exibição tem um site de exibição associado, que encapsula o quadro de exibição e a porta de exibição (HWND e uma área retangular nessa janela). O site expõe essa funcionalidade por meio da `IOleInPlaceSite` interface padrão. Observe que é possível ter mais de uma porta de exibição em um único HWND.

Normalmente, cada tipo de exibição tem uma representação impressa diferente. Portanto, as exibições e os sites de exibição correspondentes devem implementar as interfaces de impressão se `IPrint` e `IContinueCallback` , respectivamente. O quadro de exibição deve negociar com o provedor de exibição durante o `IPrint` início da impressão, de modo que os cabeçalhos, rodapés, margens e elementos relacionados sejam impressos corretamente. O provedor de exibição notifica o quadro de eventos relacionados à impressão por meio do `IContinueCallback` . Para obter mais informações sobre o uso dessas interfaces, consulte [impressão programática](programmatic-printing.md).

Observe que, se um documento ativo der suporte apenas a uma única exibição, o documento ativo e esse modo de exibição único poderão ser implementados usando uma única classe concreta. `IOleDocument::CreateView`simplesmente retorna o ponteiro de interface do mesmo objeto `IOleDocumentView` . Em suma, não é necessário que haja duas instâncias de objeto separadas quando apenas uma exibição é necessária.

Um objeto View também pode ser um destino de comando. A implementação `IOleCommandTarget` de uma exibição pode receber comandos originados na interface do usuário do contêiner (como **novo**, **abrir**, **salvar como**, **Imprimir** no menu **arquivo** e **copiar**, **colar**, **desfazer** no menu **Editar** ). Para obter mais informações, consulte [tratamento de mensagens e destinos de comando](message-handling-and-command-targets.md).

## <a name="see-also"></a>Consulte também

[Contenção de documentos ativos](active-document-containment.md)
