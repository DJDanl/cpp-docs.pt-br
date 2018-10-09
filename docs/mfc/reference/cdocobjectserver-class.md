---
title: Classe CDocObjectServer | Microsoft Docs
ms.custom: ''
ms.date: 09/12/2018
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CDocObjectServer
- AFXDOCOB/CDocObjectServer
- AFXDOCOB/CDocObjectServer::CDocObjectServer
- AFXDOCOB/CDocObjectServer::ActivateDocObject
- AFXDOCOB/CDocObjectServer::OnActivateView
- AFXDOCOB/CDocObjectServer::OnApplyViewState
- AFXDOCOB/CDocObjectServer::OnSaveViewState
dev_langs:
- C++
helpviewer_keywords:
- CDocObjectServer [MFC], CDocObjectServer
- CDocObjectServer [MFC], ActivateDocObject
- CDocObjectServer [MFC], OnActivateView
- CDocObjectServer [MFC], OnApplyViewState
- CDocObjectServer [MFC], OnSaveViewState
ms.assetid: 18cd0dff-0616-4472-b8d9-66c081bc383a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 552252c8826e167b4aaa21aa41e489bbc8179ec3
ms.sourcegitcommit: d3c41b16bf05af2149090e996d8e71cd6cd55c7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/09/2018
ms.locfileid: "48890369"
---
# <a name="cdocobjectserver-class"></a>Classe CDocObjectServer

Implementa as interfaces OLE adicionais necessárias para tomar um normal `COleDocument` server em um servidor DocObject completo: `IOleDocument`, `IOleDocumentView`, `IOleCommandTarget`, e `IPrint`.

## <a name="syntax"></a>Sintaxe

```
class CDocObjectServer : public CCmdTarget
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocObjectServer::CDocObjectServer](#cdocobjectserver)|Constrói um objeto `CDocObjectServer`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CDocObjectServer::ActivateDocObject](#activatedocobject)|Ativa o servidor de objeto do documento, mas não exibi-la.|

### <a name="protected-methods"></a>Métodos Protegidos

|Nome|Descrição|
|----------|-----------------|
|[CDocObjectServer::OnActivateView](#onactivateview)|Exibe a exibição DocObject.|
|[CDocObjectServer::OnApplyViewState](#onapplyviewstate)|Restaura o estado da exibição DocObject.|
|[CDocObjectServer::OnSaveViewState](#onsaveviewstate)|Salva o estado da exibição DocObject.|

## <a name="remarks"></a>Comentários

`CDocObjectServer` é derivado de `CCmdTarget` e trabalha em conjunto com `COleServerDoc` para expor as interfaces.

Um documento do servidor DocObject pode conter [CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md) objetos que representam a interface de servidor DocObject itens.

Para personalizar seu servidor DocObject, derive sua própria classe de `CDocObjectServer` e substituir suas funções de instalação do modo de exibição, [OnActivateView](#onactivateview), [OnApplyViewState](#onapplyviewstate), e [OnSaveViewState ](#onsaveviewstate). Você precisará fornecer uma nova instância da sua classe em resposta a chamadas do framework.

Para obter mais informações sobre DocObjects, consulte [CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md) e [COleCmdUI](../../mfc/reference/colecmdui-class.md) no *referência da MFC*.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

`CDocObjectServer`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdocob.h

##  <a name="activatedocobject"></a>  CDocObjectServer::ActivateDocObject

Chame essa função para ativar o servidor de objeto do documento (mas não mostrar uma).

```
void ActivateDocObject();
```

### <a name="remarks"></a>Comentários

`ActivateDocObject` chamadas `IOleDocumentSite`do `ActivateMe` método, mas não mostra o modo de exibição porque ele aguarda para obter instruções específicas sobre como configurar e exibir o modo de exibição fornecido na chamada para [CDocObjectServer::OnActivateView](#onactivateview).

Juntos, `ActivateDocObject` e `OnActivateView` ativar e mostrar a exibição DocObject. Ativação DocObject difere de outros tipos de ativação no local OLE. Ativação DocObject ignora a exibição de bordas de hachura de no local e os adornos de objeto (por exemplo, alças de dimensionamento), ignora as funções de extensão do objeto e desenha as barras de rolagem dentro do retângulo de exibição em vez de desenhá-los fora do retângulo (como em normal ativação in-loco).

##  <a name="cdocobjectserver"></a>  CDocObjectServer::CDocObjectServer

Constrói e inicializa um objeto `CDocObjectServer`.

```
explicit CDocObjectServer(
    COleServerDoc* pOwner,
    LPOLEDOCUMENTSITE pDocSite = NULL);
```

### <a name="parameters"></a>Parâmetros

*pOwner*<br/>
Um ponteiro para o documento de site do cliente que é o cliente para o servidor DocObject.

*pDocSite*<br/>
Um ponteiro para o `IOleDocumentSite` interface implementada pelo contêiner.

### <a name="remarks"></a>Comentários

Quando DocObject está ativa, o cliente do site interface OLE ( `IOleDocumentSite`) é o que permite que o servidor DocObject para se comunicar com seu cliente (o contêiner). Quando um servidor DocObject é ativado, ele primeiro verifica se o contêiner implementa o `IOleDocumentSite` interface. Nesse caso, [COleServerDoc::GetDocObjectServer](../../mfc/reference/coleserverdoc-class.md#getdocobjectserver) é chamado se o contêiner dá suporte a DocObjects. Por padrão, `GetDocObjectServer` retorna NULL. Você deve substituir `COleServerDoc::GetDocObjectServer` para construir uma nova `CDocObjectServer` objeto ou um objeto derivado de suas preferência, com ponteiros para o `COleServerDoc` contêiner e seu `IOleDocumentSite` interface como argumentos para o construtor.

##  <a name="onactivateview"></a>  CDocObjectServer::OnActivateView

Chame essa função para mostrar a exibição DocObject.

```
virtual HRESULT OnActivateView();
```

### <a name="return-value"></a>Valor de retorno

Retorna um valor de aviso ou erro. Por padrão, retorna NOERROR se bem-sucedido; Caso contrário, E_FAIL.

### <a name="remarks"></a>Comentários

Essa função cria uma janela de quadro in-loco, desenha as barras de rolagem no modo de exibição, configura os menus, o servidor compartilha com seu contêiner, adiciona controles frame, define o objeto do Active Directory, e finalmente mostra a janela de quadro in-loco e define o foco.

##  <a name="onapplyviewstate"></a>  CDocObjectServer::OnApplyViewState

Substitua essa função para restaurar o estado da exibição DocObject.

```
virtual void OnApplyViewState(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
Um `CArchive` objeto do qual serializar o estado de exibição.

### <a name="remarks"></a>Comentários

Essa função é chamada quando o modo de exibição está sendo exibido pela primeira vez após sua instanciação. `OnApplyViewState` instrui para se reinicializar de acordo com os dados em um modo de exibição de `CArchive` objeto salvo anteriormente com [OnSaveViewState](#onsaveviewstate). O modo de exibição deve validar os dados a `CArchive` objeto porque o contêiner não tenta interpretar os dados de estado de exibição de qualquer forma.

Você pode usar `OnSaveViewState` para armazenar informações persistentes específicas para o estado do seu modo de exibição. Se você substituir `OnSaveViewState` para armazenar informações, você desejará substituir `OnApplyViewState` para ler as informações e aplicá-lo ao modo de exibição quando ele for ativado recentemente.

##  <a name="onsaveviewstate"></a>  CDocObjectServer::OnSaveViewState

Substitua essa função para salvar informações de estado adicionais sobre o modo de exibição DocObject.

```
virtual void OnSaveViewState(CArchive& ar);
```

### <a name="parameters"></a>Parâmetros

*ar*<br/>
Um `CArchive` do objeto para o qual o estado de exibição é serializado.

### <a name="remarks"></a>Comentários

Seu estado pode incluir propriedades, como o tipo de exibição, fator de zoom, inserção e ponto de seleção e assim por diante. Normalmente, o contêiner chama esta função antes de desativar o modo de exibição. O estado salvo pode ser restaurado posteriormente por meio [OnApplyViewState](#onapplyviewstate).

Você pode usar `OnSaveViewState` para armazenar informações persistentes específicas para o estado do seu modo de exibição. Se você substituir `OnSaveViewState` para armazenar informações, você desejará substituir `OnApplyViewState` para ler as informações e aplicá-lo ao modo de exibição quando ele for ativado recentemente.

## <a name="see-also"></a>Consulte também

[Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe de CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md)
