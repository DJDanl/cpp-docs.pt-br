---
title: Classe CDocObjectServer | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: f89812fbc0e1b6a3df80cd7c99879d8d630179de
ms.sourcegitcommit: c6b095c5f3de7533fd535d679bfee0503e5a1d91
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/26/2018
ms.locfileid: "36956447"
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
|[CDocObjectServer::ActivateDocObject](#activatedocobject)|Ativa o servidor de objeto de documento, mas não mostrá-lo.|  
  
### <a name="protected-methods"></a>Métodos Protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CDocObjectServer::OnActivateView](#onactivateview)|Exibe a exibição DocObject.|  
|[CDocObjectServer::OnApplyViewState](#onapplyviewstate)|Restaura o estado da exibição DocObject.|  
|[CDocObjectServer::OnSaveViewState](#onsaveviewstate)|Salva o estado da exibição DocObject.|  
  
## <a name="remarks"></a>Comentários  
 `CDocObjectServer` é derivado de `CCmdTarget` e trabalha em conjunto com `COleServerDoc` para expor as interfaces.  
  
 Pode conter um documento do servidor DocObject [CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md) objetos que representam a interface de servidor DocObject itens.  
  
 Para personalizar seu servidor DocObject, derive sua própria classe de `CDocObjectServer` e substituir suas funções de instalação do modo de exibição, [OnActivateView](#onactivateview), [OnApplyViewState](#onapplyviewstate), e [OnSaveViewState ](#onsaveviewstate). Você precisará fornecer uma nova instância da sua classe em resposta a chamadas de estrutura.  
  
 Para obter mais informações sobre DocObjects, consulte [CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md) e [COleCmdUI](../../mfc/reference/colecmdui-class.md) no *referência MFC*. Consulte também [Internet primeiras etapas: documentos ativos](../../mfc/active-documents-on-the-internet.md) e [documentos ativos](../../mfc/active-documents-on-the-internet.md).  
  
 Consulte também o seguinte artigo da Base de dados de Conhecimento:  
  
-   Q247382: PRB: dicas de ferramentas para controles no servidor de documento ActiveX são ocultos por contêiner do documento do ActiveX  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 `CDocObjectServer`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdocob.h  
  
##  <a name="activatedocobject"></a>  CDocObjectServer::ActivateDocObject  
 Chame essa função para ativar o servidor de objeto de documento (mas não mostrar,).  
  
```  
void ActivateDocObject();
```  
  
### <a name="remarks"></a>Comentários  
 `ActivateDocObject` chamadas `IOleDocumentSite`do `ActivateMe` método, mas não mostra o modo de exibição porque ele espera para obter instruções específicas sobre como configurar e exibir o modo de exibição fornecido na chamada para [CDocObjectServer::OnActivateView](#onactivateview).  
  
 Juntas, `ActivateDocObject` e `OnActivateView` ativar e mostrar a exibição DocObject. Ativação DocObject difere de outros tipos de ativação no local OLE. Ativação DocObject ignora a exibição in-loco hachura bordas e adornos de objeto (por exemplo, alças de dimensionamento), ignora as funções de extensão de objeto e desenha barras de rolagem dentro do retângulo de exibição em vez de desenho fora do retângulo (como normal ativação no local).  
  
##  <a name="cdocobjectserver"></a>  CDocObjectServer::CDocObjectServer  
 Constrói e inicializa um objeto `CDocObjectServer`.  
  
```  
explicit CDocObjectServer(
    COleServerDoc* pOwner,  
    LPOLEDOCUMENTSITE pDocSite = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pOwner*  
 Um ponteiro para o documento de site do cliente que é o cliente para o servidor DocObject.  
  
 *pDocSite*  
 Um ponteiro para o `IOleDocumentSite` interface implementada pelo contêiner.  
  
### <a name="remarks"></a>Comentários  
 Quando um DocObject está ativa, o cliente site interface OLE ( `IOleDocumentSite`) é o que permite que o servidor DocObject para se comunicar com seu cliente (o contêiner). Quando um servidor DocObject está ativado, ele primeiro verifica se o contêiner implementa o `IOleDocumentSite` interface. Nesse caso, [COleServerDoc::GetDocObjectServer](../../mfc/reference/coleserverdoc-class.md#getdocobjectserver) é chamado para ver se o contêiner suporta DocObjects. Por padrão, `GetDocObjectServer` retorna **nulo**. Você deve substituir `COleServerDoc::GetDocObjectServer` para construir uma nova `CDocObjectServer` objeto ou um objeto derivado de seus próprios com ponteiros para o `COleServerDoc` contêiner e seu `IOleDocumentSite` interface como argumentos para o construtor.  
  
##  <a name="onactivateview"></a>  CDocObjectServer::OnActivateView  
 Chame essa função para mostrar a exibição DocObject.  
  
```  
virtual HRESULT OnActivateView();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um valor de aviso ou erro. Por padrão, retorna **NOERROR** se bem-sucedido; caso contrário, **E_FAIL**.  
  
### <a name="remarks"></a>Comentários  
 Esta função cria uma janela do quadro no local, desenha barras de rolagem no modo de exibição, configura os menus no servidor compartilha com seu contêiner, adiciona os controles do quadro, define o objeto ativo, e finalmente mostra a janela do quadro no local e define o foco.  
  
##  <a name="onapplyviewstate"></a>  CDocObjectServer::OnApplyViewState  
 Substitua essa função para restaurar o estado da exibição DocObject.  
  
```  
virtual void OnApplyViewState(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 *ar*  
 Um `CArchive` objeto do qual serializar o estado de exibição.  
  
### <a name="remarks"></a>Comentários  
 Esta função é chamada quando o modo de exibição está sendo exibido pela primeira vez após sua instanciação. `OnApplyViewState` Instrui a sua reinicialização de acordo com os dados em um modo de exibição de `CArchive` objeto salvo anteriormente com [OnSaveViewState](#onsaveviewstate). O modo de exibição deve validar os dados de `CArchive` o objeto, pois o contêiner não tenta interpretar os dados de estado de exibição de qualquer forma.  
  
 Você pode usar `OnSaveViewState` para armazenar informações persistentes específicas para o estado da exibição. Se você substituir `OnSaveViewState` para armazenar informações, você desejará substituir `OnApplyViewState` para ler as informações e aplicá-lo ao modo de exibição quando ela é ativada recentemente.  
  
##  <a name="onsaveviewstate"></a>  CDocObjectServer::OnSaveViewState  
 Substitua essa função para salvar informações de estado adicionais sobre o modo de exibição DocObject.  
  
```  
virtual void OnSaveViewState(CArchive& ar);
```  
  
### <a name="parameters"></a>Parâmetros  
 *ar*  
 Um `CArchive` do objeto para o qual o estado de exibição é serializado.  
  
### <a name="remarks"></a>Comentários  
 O estado pode incluir propriedades, como o tipo de exibição, fator de zoom, inserção e ponto de seleção e assim por diante. Normalmente, o contêiner chama esta função antes de desativar o modo de exibição. O estado salvo pode ser restaurado posteriormente por meio de [OnApplyViewState](#onapplyviewstate).  
  
 Você pode usar `OnSaveViewState` para armazenar informações persistentes específicas para o estado da exibição. Se você substituir `OnSaveViewState` para armazenar informações, você desejará substituir `OnApplyViewState` para ler as informações e aplicá-lo ao modo de exibição quando ela é ativada recentemente.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdTarget](../../mfc/reference/ccmdtarget-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe de CDocObjectServerItem](../../mfc/reference/cdocobjectserveritem-class.md)
