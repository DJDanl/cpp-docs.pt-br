---
title: Interface IAxWinHostWindow | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IAxWinHostWindow
dev_langs:
- C++
helpviewer_keywords:
- IAxWinHostWindow interface
ms.assetid: 9821c035-cd52-4c46-b58a-9278064f09b4
caps.latest.revision: 21
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 6e366e7e30e7b4080462fbc21c29b4ecdf0214ae
ms.lasthandoff: 02/25/2017

---
# <a name="iaxwinhostwindow-interface"></a>Interface IAxWinHostWindow
Essa interface fornece métodos para manipular um controle e seu objeto de host.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
interface IAxWinHostWindow : IUnknown
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[AttachControl](#attachcontrol)|Anexa um controle existente ao objeto de host.|  
|[CreateControl](#createcontrol)|Cria um controle e anexa-o ao objeto de host.|  
|[CreateControlEx](#createcontrolex)|Cria um controle, anexa-o ao objeto de host e, opcionalmente, configura um manipulador de eventos.|  
|[QueryControl](#querycontrol)|Retorna um ponteiro de interface para o controle hospedado.|  
|[SetExternalDispatch](#setexternaldispatch)|Define o external `IDispatch` interface.|  
|[SetExternalUIHandler](#setexternaluihandler)|Define o external `IDocHostUIHandlerDispatch` interface.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface é exposta pelo controle ActiveX do ATL que objetos de hospedagem. Chame os métodos nessa interface para criar e/ou anexar um controle para o objeto de host, para obter uma interface de um controle hospedado ou definir a dispinterface externo ou o manipulador da IU para uso quando o navegador da Web de hospedagem.  
  
## <a name="requirements"></a>Requisitos  
 A definição desta interface está disponível como IDL ou C++, conforme mostrado abaixo.  
  
|Tipo de definição|Arquivo|  
|---------------------|----------|  
|IDL|ATLIFace.idl|  
|C++|Atliface (também incluído no atlbase. H)|  
  
##  <a name="a-nameattachcontrola--iaxwinhostwindowattachcontrol"></a><a name="attachcontrol"></a>IAxWinHostWindow::AttachControl  
 Anexa um controle existente (e inicializado anteriormente) para o objeto de host usando a janela identificada por `hWnd`.  
  
```
STDMETHOD(AttachControl)(IUnknown* pUnkControl, HWND hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnkControl*  
 [in] Um ponteiro para o **IUnknown** interface do controle a ser anexado ao objeto de host.  
  
 `hWnd`  
 [in] Um identificador para a janela a ser usado para hospedar.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="a-namecreatecontrola--iaxwinhostwindowcreatecontrol"></a><a name="createcontrol"></a>IAxWinHostWindow::CreateControl  
 Cria um controle, inicializa e hospeda-o na janela identificada por `hWnd`.  
  
```
STDMETHOD(CreateControl)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpTricsData`  
 [in] Uma cadeia de caracteres que identifica o controle a ser criado. Pode ser um CLSID (deve incluir as chaves), ProgID, URL ou HTML bruto (prefixo **MSHTML:**).  
  
 `hWnd`  
 [in] Um identificador para a janela a ser usado para hospedar.  
  
 `pStream`  
 [in] Um ponteiro de interface para um fluxo contendo dados de inicialização para o controle. Pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Esta janela será ter subclasses pelo objeto de host expor essa interface para que as mensagens podem ser refletidas no controle e outros recursos de contêiner funcionará.  
  
 Chamar esse método é equivalente a chamar [IAxWinHostWindow::CreateControlEx](#createcontrolex).  
  
 Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLic](../../atl/reference/iaxwinhostwindowlic-interface.md#createcontrollicex).  
  
##  <a name="a-namecreatecontrolexa--iaxwinhostwindowcreatecontrolex"></a><a name="createcontrolex"></a>IAxWinHostWindow::CreateControlEx  
 Cria um controle ActiveX, inicializa e hospeda-o na janela especificada, semelhante ao [IAxWinHostWindow::CreateControl](#createcontrol).  
  
```
STDMETHOD(CreateControlEx)(
    LPCOLESTR lpszTricsData,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnk,
    REFIID riidAdvise,
    IUnknown* punkAdvise);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpTricsData`  
 [in] Uma cadeia de caracteres que identifica o controle a ser criado. Pode ser um CLSID (deve incluir as chaves), ProgID, URL ou HTML bruto (prefixados com **MSHTML:**).  
  
 `hWnd`  
 [in] Um identificador para a janela a ser usado para hospedar.  
  
 `pStream`  
 [in] Um ponteiro de interface para um fluxo contendo dados de inicialização para o controle. Pode ser **nulo**.  
  
 `ppUnk`  
 [out] O endereço de um ponteiro que receberá o **IUnknown** interface do controle criado. Pode ser **nulo**.  
  
 *riidAdvise*  
 [in] O identificador de interface de uma interface externa do objeto contido. Pode ser **IID_NULL**.  
  
 *punkAdvise*  
 [in] Um ponteiro para o **IUnknown** interface do objeto coletor a ser conectado ao ponto de conexão no objeto independente especificado pelo `iidSink`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário do `CreateControl` método `CreateControlEx` também permite que você receber um ponteiro de interface para o controle recém-criado e configurar um coletor de eventos para receber eventos disparados pelo controle.  
  
 Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLicEx](../../atl/reference/iaxwinhostwindowlic-interface.md#createcontrollicex).  
  
##  <a name="a-namequerycontrola--iaxwinhostwindowquerycontrol"></a><a name="querycontrol"></a>IAxWinHostWindow::QueryControl  
 Retorna o ponteiro de interface especificado fornecido pelo controle hospedado.  
  
```
STDMETHOD(QueryControl)(
    REFIID riid,
    void** ppvObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `riid`  
 [in] A ID de uma interface no controle que está sendo solicitado.  
  
 `ppvObject`  
 [out] O endereço de um ponteiro que receberá a interface especificada do controle criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="a-namesetexternaldispatcha--iaxwinhostwindowsetexternaldispatch"></a><a name="setexternaldispatch"></a>IAxWinHostWindow::SetExternalDispatch  
 Define a dispinterface externa, que está disponível para controles contidos por meio de [IDocHostUIHandlerDispatch::GetExternal](../../atl/reference/idochostuihandlerdispatch-interface.md) método.  
  
```
STDMETHOD(SetExternalDispatch)(IDispatch* pDisp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDisp`  
 [in] Um ponteiro para um `IDispatch` interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="a-namesetexternaluihandlera--iaxwinhostwindowsetexternaluihandler"></a><a name="setexternaluihandler"></a>IAxWinHostWindow::SetExternalUIHandler  
 Chame essa função para definir o external [IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md) de interface para o `CAxWindow` objeto.  
  
```
STDMETHOD(SetExternalUIHandler)(IDocHostUIHandlerDispatch* pDisp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDisp`  
 [in] Um ponteiro para um **IDocHostUIHandlerDispatch** interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Essa função é usada pelos controles (como o controle de navegador da Web) que consultar o site do host para o `IDocHostUIHandlerDispatch` interface.  
  
## <a name="see-also"></a>Consulte também  
 [Interface IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)   
 [CAxWindow::QueryHost](../../atl/reference/caxwindow-class.md#queryhost)   
 [AtlAxGetHost](http://msdn.microsoft.com/library/ad1f4f16-608d-4e96-8d30-04d4ca906a7b)










