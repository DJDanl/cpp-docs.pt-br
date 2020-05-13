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
ms.openlocfilehash: cbea3e032932477006820c5a71fbbf3e40123bdf
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81322078"
---
# <a name="active-documents"></a>Documentos ativos

Documentos ativos ampliam a tecnologia de documento composto do OLE. Essas extensões são fornecidas sob a forma de interfaces adicionais que gerenciam visualizações, para que os objetos possam funcionar dentro de contêineres e ainda manter o controle sobre suas funções de exibição e impressão. Esse processo permite exibir documentos tanto em quadros estrangeiros (como o Microsoft Office Binder ou o Microsoft Internet Explorer) quanto em quadros nativos (como as portas de exibição do próprio produto).

Esta seção descreve os [requisitos](#requirements_for_active_documents)funcionais para documentos ativos . O documento ativo possui um conjunto de dados e tem acesso ao armazenamento onde os dados podem ser salvos e recuperados. Ele pode criar e gerenciar uma ou mais visualizações em seus dados. Além de suportar as interfaces habituais de incorporação e ativação in loco de documentos `IOleDocument`OLE, o documento ativo comunica sua capacidade de criar visualizações através de . Através desta interface, o contêiner pode pedir para criar (e possivelmente enumerar) as visualizações que o documento ativo pode exibir. Através dessa interface, o documento ativo também pode fornecer informações diversas sobre si mesmo, como se suporta múltiplas visões ou retângulos complexos.

A seguir `IOleDocument` está a interface. Observe que `IEnumOleDocumentViews` a interface é um enumerador OLE padrão para `IOleDocumentView*` tipos.

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

Cada documento ativo deve ter um provedor de quadros de exibição com esta interface. Se o documento não estiver incorporado dentro de um contêiner, o próprio servidor de documentos ativo deve fornecer o quadro de exibição. No entanto, quando o documento ativo é incorporado em um recipiente de documento ativo, o contêiner fornece o quadro de exibição.

Um documento ativo pode criar um ou mais tipos de [visualizações](#requirements_for_view_objects) de seus dados (por exemplo, normal, contorno, layout da página e assim por diante). As visualizações agem como filtros através dos quais os dados podem ser vistos. Mesmo que o documento tenha apenas um tipo de exibição, você ainda pode querer suportar várias visualizações como um meio de suportar a nova funcionalidade da janela (por exemplo, o item **Nova janela** no menu **Janela** em aplicativos do Office).

## <a name="requirements-for-active-documents"></a><a name="requirements_for_active_documents"></a>Requisitos para documentos ativos

Um documento ativo que pode ser exibido em um recipiente de documento ativo deve:

- Use os Arquivos Compostos do OLE `IPersistStorage`como mecanismo de armazenamento implementando .

- Suporte aos recursos básicos de incorporação de documentos OLE, incluindo **Criar a partir de arquivo**. Isso requer as interfaces, `IPersistFile` `IOleObject` `IDataObject`e .

- Suporte a uma ou mais visualizações, cada uma das quais é capaz de ativação no local. Ou seja, as visualizações `IOleDocumentView` devem suportar a `IOleInPlaceObject` `IOleInPlaceActiveObject` interface, bem como `IOleInPlaceSite` `IOleInPlaceFrame` as interfaces e (usando o contêiner e interfaces).

- Suporte às interfaces `IOleDocument`de `IOleCommandTarget`documentos `IPrint`ativas padrão, e .

O conhecimento de quando e como usar as interfaces lado contêiner está implícito nesses requisitos.

## <a name="requirements-for-view-objects"></a><a name="requirements_for_view_objects"></a>Requisitos para exibir objetos

Um documento ativo pode criar uma ou mais visualizações de seus dados. Funcionalmente, essas visualizações são como portas em um método específico para exibir os dados. Se um documento ativo suportar apenas uma exibição única, o documento ativo e essa exibição única podem ser implementados usando uma única classe. `IOleDocument::CreateView`retorna o ponteiro `IOleDocumentView` de interface do mesmo objeto.

Para ser representado dentro de um contêiner `IOleInPlaceObject` de `IOleInPlaceActiveObject` documento `IOleDocumentView`ativo, um componente de exibição deve suportar e, além de:

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

Cada visualização tem um local de exibição associado, que encapsula o quadro de exibição e a porta de exibição (HWND e uma área retangular nessa janela). O site expõe essa funcionalidade `IOleInPlaceSite` através da interface padrão. Observe que é possível ter mais de uma porta de exibição em um único HWND.

Normalmente, cada tipo de visualização tem uma representação impressa diferente. Portanto, as visualizações e os locais `IPrint` de `IContinueCallback`exibição correspondentes devem implementar as interfaces de impressão se e , respectivamente. O quadro de exibição deve `IPrint` negociar com o provedor de visualização durante o início da impressão, para que os cabeçalhos, rodapés, margens e elementos relacionados sejam impressos corretamente. O provedor de visualização notifica o `IContinueCallback`quadro de eventos relacionados à impressão através de . Para obter mais informações sobre o uso dessas interfaces, consulte [Programmatic Printing](../mfc/programmatic-printing.md).

Observe que se um documento ativo apenas suporta uma exibição única, então o documento ativo e essa exibição única podem ser implementados usando uma única classe de concreto. `IOleDocument::CreateView`simplesmente retorna o ponteiro `IOleDocumentView` de interface do mesmo objeto. Em suma, não é necessário que haja duas instâncias de objeto separadas quando apenas uma exibição é necessária.

Um objeto de exibição também pode ser um alvo de comando. Ao implementar `IOleCommandTarget` uma visualização pode receber comandos que se originam na interface do usuário do contêiner (como **Novo**, **Abrir**, **Salvar Como**, **Imprimir** no menu **Arquivo;** e **Copiar**, **Colar**, **Desfazer** no menu **Editar).** Para obter mais informações, consulte [O manuseio de mensagens e os alvos de comando](../mfc/message-handling-and-command-targets.md).

## <a name="see-also"></a>Confira também

[Contenção de documentos ativos](../mfc/active-document-containment.md)
