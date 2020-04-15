---
title: Classe CDocObjectServer
ms.date: 09/12/2018
f1_keywords:
- CDocObjectServer
- AFXDOCOB/CDocObjectServer
- AFXDOCOB/CDocObjectServer::CDocObjectServer
- AFXDOCOB/CDocObjectServer::ActivateDocObject
- AFXDOCOB/CDocObjectServer::OnActivateView
- AFXDOCOB/CDocObjectServer::OnApplyViewState
- AFXDOCOB/CDocObjectServer::OnSaveViewState
helpviewer_keywords:
- CDocObjectServer [MFC], CDocObjectServer
- CDocObjectServer [MFC], ActivateDocObject
- CDocObjectServer [MFC], OnActivateView
- CDocObjectServer [MFC], OnApplyViewState
- CDocObjectServer [MFC], OnSaveViewState
ms.assetid: 18cd0dff-0616-4472-b8d9-66c081bc383a
ms.openlocfilehash: ccd8ddc9f4981b3d9f7f4e1decdf6790cd05b98b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375488"
---
# <a name="cdocobjectserver-class"></a>Classe CDocObjectServer

Implementa as interfaces OLE adicionais `COleDocument` necessárias para transformar um `IOleDocument` `IOleDocumentView`servidor `IOleCommandTarget`normal `IPrint`em um servidor DocObject completo: , , e .

## <a name="syntax"></a>Sintaxe

```
class CDocObjectServer : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocObjectServer::CDocObjectServer](#cdocobjectserver)|Constrói um objeto `CDocObjectServer`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocObjectServer::AtivarDocObject](#activatedocobject)|Ativa o servidor de objeto de documento, mas não o mostra.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CDocObjectServer::Ativação ativado](#onactivateview)|Exibe a exibição DocObject.|
|[CDocObjectServer::OnApplyViewState](#onapplyviewstate)|Restaura o estado da exibição DocObject.|
|[CDocObjectServer::OnSaveViewState](#onsaveviewstate)|Salva o estado da exibição DocObject.|

## <a name="remarks"></a>Comentários

`CDocObjectServer`é derivado `CCmdTarget` e trabalha em `COleServerDoc` estreita colaboração para expor as interfaces.

Um documento de servidor DocObject pode conter objetos [CDocObjectServerItem,](../../mfc/reference/cdocobjectserveritem-class.md) que representam a interface do servidor aos itens do DocObject.

Para personalizar seu servidor DocObject, `CDocObjectServer` obtenha sua própria classe e anule suas funções de configuração de exibição, [OnActivateView,](#onactivateview) [OnApplyViewState](#onapplyviewstate)e [OnSaveViewState](#onsaveviewstate). Você precisará fornecer uma nova instância de sua classe em resposta a chamadas-quadro.

Para obter mais informações sobre docObjects, consulte [CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md) e [COleCmdUI](../../mfc/reference/colecmdui-class.md) na *referência MFC*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

`CDocObjectServer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdocob.h

## <a name="cdocobjectserveractivatedocobject"></a><a name="activatedocobject"></a>CDocObjectServer::AtivarDocObject

Chame esta função para ativar (mas não mostrar) o servidor de objeto do documento.

```
void ActivateDocObject();
```

### <a name="remarks"></a>Comentários

`ActivateDocObject`o `IOleDocumentSite`método `ActivateMe` de chamadas, mas não mostra a exibição porque aguarda instruções específicas sobre como configurar e exibir a exibição, dada na chamada para [CDocObjectServer::OnActivateView](#onactivateview).

Juntos `ActivateDocObject` e `OnActivateView` ativar e exibir a exibição DocObject. A ativação do DocObject difere de outros tipos de ativação no local do OLE. A ativação do DocObject contorna a exibição de bordas e adornos de objetono hatch no local (como alças de dimensionamento), ignora as funções de extensão do objeto e desenha barras de rolagem dentro do retângulo de visão em vez de desenhá-las fora desse retângulo (como na ativação normal no local).

## <a name="cdocobjectservercdocobjectserver"></a><a name="cdocobjectserver"></a>CDocObjectServer::CDocObjectServer

Constrói e inicializa um objeto `CDocObjectServer`.

```
explicit CDocObjectServer(
    COleServerDoc* pOwner,
    LPOLEDOCUMENTSITE pDocSite = NULL);
```

### <a name="parameters"></a>Parâmetros

*pOwner*<br/>
Um ponteiro para o documento do site do cliente que é o cliente do servidor DocObject.

*pDocSite*<br/>
Um ponteiro `IOleDocumentSite` para a interface implementada pelo contêiner.

### <a name="remarks"></a>Comentários

Quando um DocObject está ativo, a `IOleDocumentSite`interface do site cliente OLE ( ) é o que permite que o servidor DocObject se comunique com seu cliente (o contêiner). Quando um servidor DocObject é ativado, primeiro verifica `IOleDocumentSite` se o contêiner implementa a interface. Se assim for, [COleServerDoc::GetDocObjectServer](../../mfc/reference/coleserverdoc-class.md#getdocobjectserver) é chamado para ver se o contêiner suporta DocObjects. Por padrão, `GetDocObjectServer` retorna NULL. Você deve `COleServerDoc::GetDocObjectServer` substituir para `CDocObjectServer` construir um novo objeto ou um objeto derivado `COleServerDoc` de `IOleDocumentSite` sua autoria, com ponteiros para o contêiner e sua interface como argumentos para o construtor.

## <a name="cdocobjectserveronactivateview"></a><a name="onactivateview"></a>CDocObjectServer::Ativação ativado

Chame esta função para exibir a exibição DocObject.

```
virtual HRESULT OnActivateView();
```

### <a name="return-value"></a>Valor retornado

Retorna um erro ou valor de aviso. Por padrão, retorna NOERROR se for bem sucedido; caso contrário, E_FAIL.

### <a name="remarks"></a>Comentários

Essa função cria uma janela de quadro no lugar, desenha barras de rolagem dentro da exibição, configura os menus que o servidor compartilha com seu contêiner, adiciona controles de quadro, define o objeto ativo e, finalmente, mostra a janela do quadro no lugar e define o foco.

## <a name="cdocobjectserveronapplyviewstate"></a><a name="onapplyviewstate"></a>CDocObjectServer::OnApplyViewState

Anular esta função para restaurar o estado da exibição DocObject.

```
virtual void OnApplyViewState(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
Um `CArchive` objeto a partir do qual serializar o estado de exibição.

### <a name="remarks"></a>Comentários

Esta função é chamada quando a exibição é exibida pela primeira vez após sua instanciação. `OnApplyViewState`instrui uma exibição para se reinicializar `CArchive` de acordo com os dados do objeto anteriormente salvo com [o OnSaveViewState](#onsaveviewstate). A exibição deve validar os dados no `CArchive` objeto porque o contêiner não tenta interpretar os dados do estado de exibição de forma alguma.

Você pode `OnSaveViewState` usar para armazenar informações persistentes específicas do estado da sua opinião. Se você `OnSaveViewState` substituir para armazenar informações, você `OnApplyViewState` vai querer substituir para ler essas informações e aplicá-la à sua visão quando ela for recém-ativada.

## <a name="cdocobjectserveronsaveviewstate"></a><a name="onsaveviewstate"></a>CDocObjectServer::OnSaveViewState

Anular essa função para salvar informações extras de estado sobre sua exibição DocObject.

```
virtual void OnSaveViewState(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
Um `CArchive` objeto para o qual o estado de exibição é serializado.

### <a name="remarks"></a>Comentários

Seu estado pode incluir propriedades como o tipo de exibição, fator de zoom, ponto de inserção e seleção, e assim por diante. O contêiner normalmente chama essa função antes de desativar a exibição. O estado salvo pode ser restaurado posteriormente através do [OnApplyViewState](#onapplyviewstate).

Você pode `OnSaveViewState` usar para armazenar informações persistentes específicas do estado da sua opinião. Se você `OnSaveViewState` substituir para armazenar informações, você `OnApplyViewState` vai querer substituir para ler essas informações e aplicá-la à sua visão quando ela for recém-ativada.

## <a name="see-also"></a>Confira também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe de CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md)
