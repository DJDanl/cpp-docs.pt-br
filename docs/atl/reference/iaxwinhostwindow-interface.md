---
title: Interface IAxWinHostWindow | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- IAxWinHostWindow
- ATLIFACE/ATL::IAxWinHostWindow
- ATLIFACE/ATL::AttachControl
- ATLIFACE/ATL::CreateControl
- ATLIFACE/ATL::CreateControlEx
- ATLIFACE/ATL::QueryControl
- ATLIFACE/ATL::SetExternalDispatch
- ATLIFACE/ATL::SetExternalUIHandler
dev_langs:
- C++
helpviewer_keywords:
- IAxWinHostWindow interface
ms.assetid: 9821c035-cd52-4c46-b58a-9278064f09b4
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 791ef9de69646efc82361f8afbed3e17dbe56453
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="iaxwinhostwindow-interface"></a>Interface IAxWinHostWindow
Essa interface fornece métodos para manipular um controle e seu objeto de host.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
interface IAxWinHostWindow : IUnknown
```  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[AttachControl](#attachcontrol)|Anexa um controle existente para o objeto de host.|  
|[CreateControl](#createcontrol)|Cria um controle e a anexa ao objeto de host.|  
|[CreateControlEx](#createcontrolex)|Cria um controle, conecta-o para o objeto de host e, opcionalmente, configura um manipulador de eventos.|  
|[QueryControl](#querycontrol)|Retorna um ponteiro de interface para o controle hospedado.|  
|[SetExternalDispatch](#setexternaldispatch)|Define o external `IDispatch` interface.|  
|[SetExternalUIHandler](#setexternaluihandler)|Define o external `IDocHostUIHandlerDispatch` interface.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface é exposta pelo controle ActiveX do ATL objetos de hospedagem. Chame os métodos nessa interface para criar e/ou anexar um controle para o objeto de host, para obter uma interface de um controle hospedado, ou para definir o dispinterface externo ou um manipulador de interface do usuário para uso quando o navegador da Web de hospedagem.  
  
## <a name="requirements"></a>Requisitos  
 A definição desta interface está disponível como IDL ou C++, conforme mostrado abaixo.  
  
|Tipo de definição|Arquivo|  
|---------------------|----------|  
|IDL|ATLIFace.idl|  
|C++|Atliface (também é incluído no atlbase)|  
  
##  <a name="attachcontrol"></a>IAxWinHostWindow::AttachControl  
 Anexa um controle existente (e inicializado anteriormente) para o objeto de host usando a janela identificada por `hWnd`.  
  
```
STDMETHOD(AttachControl)(IUnknown* pUnkControl, HWND hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pUnkControl*  
 [in] Um ponteiro para o **IUnknown** interface do controle a ser anexado ao objeto de host.  
  
 `hWnd`  
 [in] Um identificador para a janela a ser usado para hospedagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="createcontrol"></a>IAxWinHostWindow::CreateControl  
 Cria um controle, inicializa e hospeda na janela identificada por `hWnd`.  
  
```
STDMETHOD(CreateControl)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpTricsData`  
 [in] Uma cadeia de caracteres que identifica o controle a ser criado. Pode ser um CLSID (deve incluir as chaves), ProgID, URL ou HTML bruto (antecedidos **MSHTML:**).  
  
 `hWnd`  
 [in] Um identificador para a janela a ser usado para hospedagem.  
  
 `pStream`  
 [in] Um ponteiro de interface para um fluxo que contém dados de inicialização para o controle. Pode ser **nulo**.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Esta janela será ter subclasses pelo objeto de host expondo essa interface para que as mensagens podem ser refletidas ao controle e outros recursos de contêiner funcionará.  
  
 Chamar esse método é equivalente a chamar [IAxWinHostWindow::CreateControlEx](#createcontrolex).  
  
 Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLic](../../atl/reference/iaxwinhostwindowlic-interface.md#createcontrollicex).  
  
##  <a name="createcontrolex"></a>IAxWinHostWindow::CreateControlEx  
 Cria um controle ActiveX, inicializa e hospeda na janela especificada, semelhante ao [IAxWinHostWindow::CreateControl](#createcontrol).  
  
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
 [in] Uma cadeia de caracteres que identifica o controle a ser criado. Pode ser um CLSID (deve incluir as chaves), ProgID, URL ou HTML bruto (prefixado com **MSHTML:**).  
  
 `hWnd`  
 [in] Um identificador para a janela a ser usado para hospedagem.  
  
 `pStream`  
 [in] Um ponteiro de interface para um fluxo que contém dados de inicialização para o controle. Pode ser **nulo**.  
  
 `ppUnk`  
 [out] O endereço de um ponteiro que receberá o **IUnknown** interface do controle criado. Pode ser **nulo**.  
  
 *riidAdvise*  
 [in] O identificador de interface de uma interface saída o objeto contido. Pode ser **IID_NULL**.  
  
 *punkAdvise*  
 [in] Um ponteiro para o **IUnknown** interface do objeto coletor a ser conectado ao ponto de conexão no objeto contido especificado pelo `iidSink`.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Ao contrário de `CreateControl` método `CreateControlEx` também permite que você receber um ponteiro de interface para o controle recém-criado e configurar um coletor de eventos para receber eventos disparados pelo controle.  
  
 Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLicEx](../../atl/reference/iaxwinhostwindowlic-interface.md#createcontrollicex).  
  
##  <a name="querycontrol"></a>IAxWinHostWindow::QueryControl  
 Retorna o ponteiro de interface especificado fornecido pelo controle hospedado.  
  
```
STDMETHOD(QueryControl)(
    REFIID riid,
    void** ppvObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `riid`  
 [in] A ID de uma interface do controle que está sendo solicitado.  
  
 `ppvObject`  
 [out] O endereço de um ponteiro que receberá a interface especificada do controle criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="setexternaldispatch"></a>IAxWinHostWindow::SetExternalDispatch  
 Define a dispinterface externa, que está disponível para controles contidos por meio de [IDocHostUIHandlerDispatch::GetExternal](../../atl/reference/idochostuihandlerdispatch-interface.md) método.  
  
```
STDMETHOD(SetExternalDispatch)(IDispatch* pDisp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDisp`  
 [in] Um ponteiro para um `IDispatch` interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="setexternaluihandler"></a>IAxWinHostWindow::SetExternalUIHandler  
 Chamar essa função para definir o external [IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md) a interface para o `CAxWindow` objeto.  
  
```
STDMETHOD(SetExternalUIHandler)(IDocHostUIHandlerDispatch* pDisp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDisp`  
 [in] Um ponteiro para um **IDocHostUIHandlerDispatch** interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Essa função é usada pelos controles (como o controle de navegador da Web) que consulta o site do host para o `IDocHostUIHandlerDispatch` interface.  
  
## <a name="see-also"></a>Consulte também  
 [Interface IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md)   
 [CAxWindow::QueryHost](../../atl/reference/caxwindow-class.md#queryhost)   
 [AtlAxGetHost](composite-control-global-functions.md#atlaxgethost)









