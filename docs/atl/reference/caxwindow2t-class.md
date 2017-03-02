---
title: Classe CAxWindow2T | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ATL::CAxWindow2T<TBase>
- ATL::CAxWindow2T
- CAxWindow2T
- ATL.CAxWindow2T<TBase>
- ATL.CAxWindow2T
- CAxWindow2
dev_langs:
- C++
helpviewer_keywords:
- CAxWindow2 class
ms.assetid: b87bc943-7991-4537-b902-2138d7f4d837
caps.latest.revision: 22
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
ms.openlocfilehash: deed13f7e44246eca1e9d3d138f73d0f540dc0b1
ms.lasthandoff: 02/25/2017

---
# <a name="caxwindow2t-class"></a>Classe CAxWindow2T
Essa classe fornece métodos para manipular uma janela que hospeda um controle ActiveX e também tem suporte para hospedar controles ActiveX licenciados.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class TBase = CWindow>
    class CAxWindow2T :
    public CAxWindowT<TBase>
```  
  
#### <a name="parameters"></a>Parâmetros  
 *TBase*  
 A classe da qual `CAxWindowT` deriva.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAxWindow2T::CAxWindow2T](#caxwindow2t)|Constrói um objeto `CAxWindow2T`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAxWindow2T::Create](#create)|Cria uma janela do host.|  
|[CAxWindow2T::CreateControlLic](#createcontrollic)|Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada.|  
|[CAxWindow2T::CreateControlLicEx](#createcontrollicex)|Cria um controle ActiveX licenciado, inicializa, hospeda-o na janela especificada e recupera um ponteiro de interface (ou ponteiros) do controle.|  
|[CAxWindow2T::GetWndClassName](#getwndclassname)|Método estático que recupera o nome da classe de janela.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAxWindow2T::operator =](#operator_eq)|Atribui um `HWND` um existente `CAxWindow2T` objeto.|  
  
## <a name="remarks"></a>Comentários  
 `CAxWindow2T`fornece métodos para manipular uma janela que hospeda um controle ActiveX. `CAxWindow2T`também tem suporte para hospedar controles ActiveX licenciados. A hospedagem é fornecida por " **AtlAxWinLic80**", que é encapsulado por `CAxWindow2T`.  
  
 Classe `CAxWindow2` é implementado como uma especialização da `CAxWindow2T` classe. Essa especialização é declarada como:  
  
 `typedef CAxWindow2T <CWindow> CAxWindow2;`  
  
> [!NOTE]
> `CAxWindowT`membros estão documentados em [CAxWindow](../../atl/reference/caxwindow-class.md).  
  
 Consulte [de hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa os membros dessa classe.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `TBase`  
  
 `CAxWindowT`  
  
 `CAxWindow2T`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="a-namecaxwindow2ta--caxwindow2tcaxwindow2t"></a><a name="caxwindow2t"></a>CAxWindow2T::CAxWindow2T  
 Constrói um objeto `CAxWindow2T`.  
  
```
CAxWindow2T(HWND  hWnd = NULL) : CAxWindowT<TBase>(hWnd)
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 Um identificador de uma janela existente.  
  
##  <a name="a-namecreatea--caxwindow2tcreate"></a><a name="create"></a>CAxWindow2T::Create  
 Cria uma janela do host.  
  
```
HWND Create(
    HWND hWndParent,
    _U_RECT rect = NULL,
    LPCTSTR szWindowName = NULL,
    DWORD dwStyle = 0,
    DWORD dwExStyle = 0,
    _U_MENUorID MenuOrID = 0U,
    LPVOID lpCreateParam = NULL);
```  
  
### <a name="remarks"></a>Comentários  
 `CAxWindow2T::Create`chamadas [CWindow::Create](../../atl/reference/cwindow-class.md#create) com o `LPCTSTR``lpstrWndClass` parâmetro definido para a classe de janela que fornece hospedagem de controles ( **AtlAxWinLic80**).  
  
 Consulte `CWindow::Create` para obter uma descrição dos parâmetros e valor de retorno.  
  
 **Observação** se 0 for usado como o valor para o `MenuOrID` parâmetro, ele deverá ser especificado como 0U (o valor padrão) para evitar um erro do compilador.  
  
### <a name="example"></a>Exemplo  
 Consulte [de hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CAxWindow2T::Create`.  
  
##  <a name="a-namecreatecontrollica--caxwindow2tcreatecontrollic"></a><a name="createcontrollic"></a>CAxWindow2T::CreateControlLic  
 Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada.  
  
```
HRESULT CreateControlLic(
    DWORD dwResID,
    IStream* pStream = NULL,
    IUnknown** ppUnkContainer = NULL,
    BSTR bstrLicKey = NULL);

HRESULT CreateControlLic(
    LPCOLESTR lpszName,
    IStream* pStream = NULL,
    IUnknown** ppUnkContainer = NULL,
    BSTR bstrLicKey = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bstrLicKey`  
 A chave de licença para o controle; NULL se criar um controle nonlicensed.  
  
### <a name="remarks"></a>Comentários  
 Consulte [CAxWindow::CreateControl](../../atl/reference/caxwindow-class.md#createcontrol) para obter uma descrição do valor de retorno e parâmetros restantes.  
  
### <a name="example"></a>Exemplo  
 Consulte [de hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CAxWindow2T::CreateControlLic`.  
  
##  <a name="a-namecreatecontrollicexa--caxwindow2tcreatecontrollicex"></a><a name="createcontrollicex"></a>CAxWindow2T::CreateControlLicEx  
 Cria um controle ActiveX licenciado, inicializa, hospeda-o na janela especificada e recupera um ponteiro de interface (ou ponteiros) do controle.  
  
```
HRESULT CreateControlLicEx(
    LPCOLESTR lpszName,
    IStream* pStream = NULL,
    IUnknown** ppUnkContainer = NULL,
    IUnknown** ppUnkControl = NULL,
    REFIID iidSink = IID_NULL,
    IUnknown* punkSink = NULL,
    BSTR bstrLicKey = NULL);

    HRESULT CreateControlLicEx(
    DWORD dwResID,
    IStream* pStream = NULL,
    IUnknown** ppUnkContainer = NULL,
    IUnknown** ppUnkControl = NULL,
    REFIID iidSink = IID_NULL,
    IUnknown* punkSink = NULL,
    BSTR bstrLickey = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bstrLicKey`  
 A chave de licença para o controle; NULL se criar um controle nonlicensed.  
  
### <a name="remarks"></a>Comentários  
 Consulte [CAxWindow::CreateControlEx](../../atl/reference/caxwindow-class.md#createcontrolex) para obter uma descrição do valor de retorno e parâmetros restantes.  
  
### <a name="example"></a>Exemplo  
 Consulte [de hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `CAxWindow2T::CreateControlLicEx`.  
  
##  <a name="a-namegetwndclassnamea--caxwindow2tgetwndclassname"></a><a name="getwndclassname"></a>CAxWindow2T::GetWndClassName  
 Recupera o nome da classe de janela.  
  
```
static LPCTSTR GetWndClassName();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para uma cadeia de caracteres que contém o nome da classe de janela ( **AtlAxWinLic80**) que pode hospedar os controles ActiveX licenciados e nonlicensed.  
  
##  <a name="a-nameoperatoreqa--caxwindow2toperator-"></a><a name="operator_eq"></a>CAxWindow2T::operator =  
 Atribui um `HWND` um existente `CAxWindow2T` objeto.  
  
```
CAxWindow2T<TBase>& operator= (HWND hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 Um identificador de uma janela existente.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)   
 [Perguntas frequentes sobre contenção de controle](../../atl/atl-control-containment-faq.md)

