---
title: Interface IAxWinAmbientDispatch
ms.date: 11/04/2016
f1_keywords:
- IAxWinAmbientDispatch
- ATLIFACE/ATL::IAxWinAmbientDispatch
- ATLIFACE/ATL::get_AllowContextMenu
- ATLIFACE/ATL::get_AllowShowUI
- ATLIFACE/ATL::get_AllowWindowlessActivation
- ATLIFACE/ATL::get_BackColor
- ATLIFACE/ATL::get_DisplayAsDefault
- ATLIFACE/ATL::get_DocHostDoubleClickFlags
- ATLIFACE/ATL::get_DocHostFlags
- ATLIFACE/ATL::get_Font
- ATLIFACE/ATL::get_ForeColor
- ATLIFACE/ATL::get_LocaleID
- ATLIFACE/ATL::get_MessageReflect
- ATLIFACE/ATL::get_OptionKeyPath
- ATLIFACE/ATL::get_ShowGrabHandles
- ATLIFACE/ATL::get_ShowHatching
- ATLIFACE/ATL::get_UserMode
- ATLIFACE/ATL::put_AllowContextMenu
- ATLIFACE/ATL::put_AllowShowUI
- ATLIFACE/ATL::put_AllowWindowlessActivation
- ATLIFACE/ATL::put_BackColor
- ATLIFACE/ATL::put_DisplayAsDefault
- ATLIFACE/ATL::put_DocHostDoubleClickFlags
- ATLIFACE/ATL::put_DocHostFlags
- ATLIFACE/ATL::put_Font
- ATLIFACE/ATL::put_ForeColor
- ATLIFACE/ATL::put_LocaleID
- ATLIFACE/ATL::put_MessageReflect
- ATLIFACE/ATL::put_OptionKeyPath
- ATLIFACE/ATL::put_UserMode
helpviewer_keywords:
- IAxWinAmbientDispatch interface
ms.assetid: 55ba6f7b-7a3c-4792-ae47-c8a84b683ca9
ms.openlocfilehash: a53481a57676b5b4a253a3501d3536e5115907a7
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88833407"
---
# <a name="iaxwinambientdispatch-interface"></a>Interface IAxWinAmbientDispatch

Essa interface fornece métodos para especificar características do controle ou contêiner hospedado.

> [!IMPORTANT]
> Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
interface IAxWinAmbientDispatch : IDispatch
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|Nome|Descrição|
|-|-|
|[get_AllowContextMenu](#get_allowcontextmenu)|A `AllowContextMenu` propriedade especifica se o controle hospedado tem permissão para exibir seu próprio menu de contexto.|
|[get_AllowShowUI](#get_allowshowui)|A `AllowShowUI` propriedade especifica se o controle hospedado tem permissão para exibir sua própria interface do usuário.|
|[get_AllowWindowlessActivation](#get_allowwindowlessactivation)|A `AllowWindowlessActivation` propriedade especifica se o contêiner permitirá a ativação sem janela.|
|[get_BackColor](#get_backcolor)|A `BackColor` propriedade especifica a cor do plano de fundo ambiente do contêiner.|
|[get_DisplayAsDefault](#get_displayasdefault)|`DisplayAsDefault` é uma propriedade de ambiente que permite que um controle descubra se ele é o controle padrão.|
|[get_DocHostDoubleClickFlags](#get_dochostdoubleclickflags)|A `DocHostDoubleClickFlags` propriedade especifica a operação que deve ocorrer em resposta a um clique duplo.|
|[get_DocHostFlags](#get_dochostflags)|A `DocHostFlags` propriedade especifica os recursos de interface do usuário do objeto de host.|
|[get_Font](#get_font)|A `Font` propriedade especifica a fonte de ambiente do contêiner.|
|[get_ForeColor](#get_forecolor)|A `ForeColor` propriedade especifica a cor de primeiro plano de ambiente do contêiner.|
|[get_LocaleID](#get_localeid)|A `LocaleID` propriedade especifica a ID de localidade ambiente do contêiner.|
|[get_MessageReflect](#get_messagereflect)|A `MessageReflect` propriedade ambiente especifica se o contêiner refletirá as mensagens para o controle hospedado.|
|[get_OptionKeyPath](#get_optionkeypath)|A `OptionKeyPath` propriedade especifica o caminho da chave do registro para as configurações do usuário.|
|[get_ShowGrabHandles](#get_showgrabhandles)|A `ShowGrabHandles` propriedade ambiente permite que o controle descubra se ele deve se desenhar com alças de captura.|
|[get_ShowHatching](#get_showhatching)|A `ShowHatching` propriedade ambiente permite que o controle descubra se ele deve ser desenhado em um hachura.|
|[get_UserMode](#get_usermode)|A `UserMode` propriedade especifica o modo de usuário ambiente do contêiner.|
|[put_AllowContextMenu](#put_allowcontextmenu)|A `AllowContextMenu` propriedade especifica se o controle hospedado tem permissão para exibir seu próprio menu de contexto.|
|[put_AllowShowUI](#put_allowshowui)|A `AllowShowUI` propriedade especifica se o controle hospedado tem permissão para exibir sua própria interface do usuário.|
|[put_AllowWindowlessActivation](#put_allowwindowlessactivation)|A `AllowWindowlessActivation` propriedade especifica se o contêiner permitirá a ativação sem janela.|
|[put_BackColor](#put_backcolor)|A `BackColor` propriedade especifica a cor do plano de fundo ambiente do contêiner.|
|[put_DisplayAsDefault](#put_displayasdefault)|`DisplayAsDefault` é uma propriedade de ambiente que permite que um controle descubra se ele é o controle padrão.|
|[put_DocHostDoubleClickFlags](#put_dochostdoubleclickflags)|A `DocHostDoubleClickFlags` propriedade especifica a operação que deve ocorrer em resposta a um clique duplo.|
|[put_DocHostFlags](#put_dochostflags)|A `DocHostFlags` propriedade especifica os recursos de interface do usuário do objeto de host.|
|[put_Font](#put_font)|A `Font` propriedade especifica a fonte de ambiente do contêiner.|
|[put_ForeColor](#put_forecolor)|A `ForeColor` propriedade especifica a cor de primeiro plano de ambiente do contêiner.|
|[put_LocaleID](#put_localeid)|A `LocaleID` propriedade especifica a ID de localidade ambiente do contêiner.|
|[put_MessageReflect](#put_messagereflect)|A `MessageReflect` propriedade ambiente especifica se o contêiner refletirá as mensagens para o controle hospedado.|
|[put_OptionKeyPath](#put_optionkeypath)|A `OptionKeyPath` propriedade especifica o caminho da chave do registro para as configurações do usuário.|
|[put_UserMode](#put_usermode)|A `UserMode` propriedade especifica o modo de usuário ambiente do contêiner.|

## <a name="remarks"></a>Comentários

Essa interface é exposta pelos objetos de hospedagem do controle ActiveX da ATL. Chame os métodos nessa interface para definir as propriedades de ambiente disponíveis para o controle hospedado ou para especificar outros aspectos do comportamento do contêiner. Para complementar as propriedades fornecidas pelo `IAxWinAmbientDispatch` , use [IAxWinAmbientDispatchEx](../../atl/reference/iaxwinambientdispatchex-interface.md).

<xref:System.Windows.Forms.AxHost> tentará carregar informações de tipo sobre `IAxWinAmbientDispatch` e `IAxWinAmbientDispatchEx` a partir do typelib que contém o código.

Se você estiver vinculando a ATL90.dll, **AxHost** carregará as informações de tipo do TypeLib na dll.

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter mais detalhes.

## <a name="requirements"></a>Requisitos

A definição dessa interface está disponível em vários formatos, conforme mostrado na tabela a seguir.

|Tipo de definição|Arquivo|
|---------------------|----------|
|INSERI|atliface. idl|
|Biblioteca de tipos|ATL.dll|
|C++|atliface. h (também incluído em ATLBase. h)|

## <a name="iaxwinambientdispatchget_allowcontextmenu"></a><a name="get_allowcontextmenu"></a> IAxWinAmbientDispatch:: get_AllowContextMenu

A `AllowContextMenu` propriedade especifica se o controle hospedado tem permissão para exibir seu próprio menu de contexto.

```
STDMETHOD(get_AllowContextMenu)(VARIANT_BOOL* pbAllowContextMenu);
```

### <a name="parameters"></a>parâmetros

*pbAllowContextMenu*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchget_allowshowui"></a><a name="get_allowshowui"></a> IAxWinAmbientDispatch:: get_AllowShowUI

A `AllowShowUI` propriedade especifica se o controle hospedado tem permissão para exibir sua própria interface do usuário.

```
STDMETHOD(get_AllowShowUI)(VARIANT_BOOL* pbAllowShowUI);
```

### <a name="parameters"></a>parâmetros

*pbAllowShowUI*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_FALSE como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchget_allowwindowlessactivation"></a><a name="get_allowwindowlessactivation"></a> IAxWinAmbientDispatch:: get_AllowWindowlessActivation

A `AllowWindowlessActivation` propriedade especifica se o contêiner permitirá a ativação sem janela.

```
STDMETHOD(get_AllowWindowlessActivation)(VARIANT_BOOL* pbAllowWindowless);
```

### <a name="parameters"></a>parâmetros

*pbAllowWindowless*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchget_backcolor"></a><a name="get_backcolor"></a> IAxWinAmbientDispatch:: get_BackColor

A `BackColor` propriedade especifica a cor do plano de fundo ambiente do contêiner.

```
STDMETHOD(get_BackColor)(OLE_COLOR* pclrBackground);
```

### <a name="parameters"></a>parâmetros

*pclrBackground*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa COLOR_BTNFACE ou COLOR_WINDOW como o valor padrão dessa propriedade (dependendo se o pai da janela do host é uma caixa de diálogo ou não).

## <a name="iaxwinambientdispatchget_displayasdefault"></a><a name="get_displayasdefault"></a> IAxWinAmbientDispatch:: get_DisplayAsDefault

`DisplayAsDefault` é uma propriedade de ambiente que permite que um controle descubra se ele é o controle padrão.

```
STDMETHOD(get_DisplayAsDefault)(VARIANT_BOOL* pbDisplayAsDefault);
```

### <a name="parameters"></a>parâmetros

*pbDisplayAsDefault*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_FALSE como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchget_dochostdoubleclickflags"></a><a name="get_dochostdoubleclickflags"></a> IAxWinAmbientDispatch:: get_DocHostDoubleClickFlags

A `DocHostDoubleClickFlags` propriedade especifica a operação que deve ocorrer em resposta a um clique duplo.

```
STDMETHOD(get_DocHostDoubleClickFlags)(DWORD* pdwDocHostDoubleClickFlags);
```

### <a name="parameters"></a>parâmetros

*pdwDocHostDoubleClickFlags*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa DOCHOSTUIDBLCLK_DEFAULT como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchget_dochostflags"></a><a name="get_dochostflags"></a> IAxWinAmbientDispatch:: get_DocHostFlags

A `DocHostFlags` propriedade especifica os recursos de interface do usuário do objeto de host.

```
STDMETHOD(get_DocHostFlags)(DWORD* pdwDocHostFlags);
```

### <a name="parameters"></a>parâmetros

*pdwDocHostFlags*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa DOCHOSTUIFLAG_NO3DBORDER como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchget_font"></a><a name="get_font"></a> IAxWinAmbientDispatch:: get_Font

A `Font` propriedade especifica a fonte de ambiente do contêiner.

```
STDMETHOD(get_Font)(IFontDisp** pFont);
```

### <a name="parameters"></a>parâmetros

*pFont*<br/>
fora O endereço de um `IFontDisp` ponteiro de interface usado para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa a fonte GUI padrão ou a fonte do sistema como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchget_forecolor"></a><a name="get_forecolor"></a> IAxWinAmbientDispatch:: get_ForeColor

A `ForeColor` propriedade especifica a cor de primeiro plano de ambiente do contêiner.

```
STDMETHOD(get_ForeColor)(OLE_COLOR* pclrForeground);
```

### <a name="parameters"></a>parâmetros

*pclrForeground*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa a cor de texto da janela do sistema como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchget_localeid"></a><a name="get_localeid"></a> IAxWinAmbientDispatch:: get_LocaleID

A `LocaleID` propriedade especifica a ID de localidade ambiente do contêiner.

```
STDMETHOD(get_LocaleID)(LCID* plcidLocaleID);
```

### <a name="parameters"></a>parâmetros

*plcidLocaleID*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa a localidade padrão do usuário como o valor padrão dessa propriedade.

Com esse método, você pode descobrir o ambiente LocalId, ou seja, o LocaleID do programa em que seu controle está sendo usado. Depois de saber a LocaleID, você pode chamar o código para carregar legendas específicas de localidade, texto de mensagem de erro e assim por diante de um arquivo de recurso ou DLL satélite.

## <a name="iaxwinambientdispatchget_messagereflect"></a><a name="get_messagereflect"></a> IAxWinAmbientDispatch:: get_MessageReflect

A `MessageReflect` propriedade ambiente especifica se o contêiner refletirá as mensagens para o controle hospedado.

```
STDMETHOD(get_MessageReflect)(VARIANT_BOOL* pbMessageReflect);
```

### <a name="parameters"></a>parâmetros

*pbMessageReflect*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchget_optionkeypath"></a><a name="get_optionkeypath"></a> IAxWinAmbientDispatch:: get_OptionKeyPath

A `OptionKeyPath` propriedade especifica o caminho da chave do registro para as configurações do usuário.

```
STDMETHOD(get_OptionKeyPath)(BSTR* pbstrOptionKeyPath);
```

### <a name="parameters"></a>parâmetros

*pbstrOptionKeyPath*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

## <a name="iaxwinambientdispatchget_showgrabhandles"></a><a name="get_showgrabhandles"></a> IAxWinAmbientDispatch:: get_ShowGrabHandles

A `ShowGrabHandles` propriedade ambiente permite que o controle descubra se ele deve se desenhar com alças de captura.

```
STDMETHOD(get_ShowGrabHandles)(VARIANT_BOOL* pbShowGrabHandles);
```

### <a name="parameters"></a>parâmetros

*pbShowGrabHandles*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL sempre retorna VARIANT_FALSE como o valor dessa propriedade.

## <a name="iaxwinambientdispatchget_showhatching"></a><a name="get_showhatching"></a> IAxWinAmbientDispatch:: get_ShowHatching

A `ShowHatching` propriedade ambiente permite que o controle descubra se ele deve ser desenhado em um hachura.

```
STDMETHOD(get_ShowHatching)(VARIANT_BOOL* pbShowHatching);
```

### <a name="parameters"></a>parâmetros

*pbShowHatching*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL sempre retorna VARIANT_FALSE como o valor dessa propriedade.

## <a name="iaxwinambientdispatchget_usermode"></a><a name="get_usermode"></a> IAxWinAmbientDispatch:: get_UserMode

A `UserMode` propriedade especifica o modo de usuário ambiente do contêiner.

```
STDMETHOD(get_UserMode)(VARIANT_BOOL* pbUserMode);
```

### <a name="parameters"></a>parâmetros

*pbUserMode*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchput_allowcontextmenu"></a><a name="put_allowcontextmenu"></a> IAxWinAmbientDispatch::p ut_AllowContextMenu

A `AllowContextMenu` propriedade especifica se o controle hospedado tem permissão para exibir seu próprio menu de contexto.

```
STDMETHOD(put_AllowContextMenu)(VARIANT_BOOL bAllowContextMenu);
```

### <a name="parameters"></a>parâmetros

*bAllowContextMenu*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchput_allowshowui"></a><a name="put_allowshowui"></a> IAxWinAmbientDispatch::p ut_AllowShowUI

A `AllowShowUI` propriedade especifica se o controle hospedado tem permissão para exibir sua própria interface do usuário.

```
STDMETHOD(put_AllowShowUI)(VARIANT_BOOL bAllowShowUI);
```

### <a name="parameters"></a>parâmetros

*bAllowShowUI*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_FALSE como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchput_allowwindowlessactivation"></a><a name="put_allowwindowlessactivation"></a> IAxWinAmbientDispatch::p ut_AllowWindowlessActivation

A `AllowWindowlessActivation` propriedade especifica se o contêiner permitirá a ativação sem janela.

```
STDMETHOD(put_AllowWindowlessActivation)(VARIANT_BOOL bAllowWindowless);
```

### <a name="parameters"></a>parâmetros

*bAllowWindowless*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchput_backcolor"></a><a name="put_backcolor"></a> IAxWinAmbientDispatch::p ut_BackColor

A `BackColor` propriedade especifica a cor do plano de fundo ambiente do contêiner.

```
STDMETHOD(put_BackColor)(OLE_COLOR clrBackground);
```

### <a name="parameters"></a>parâmetros

*clrBackground*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa COLOR_BTNFACE ou COLOR_WINDOW como o valor padrão dessa propriedade (dependendo se o pai da janela do host é uma caixa de diálogo ou não).

## <a name="iaxwinambientdispatchput_displayasdefault"></a><a name="put_displayasdefault"></a> IAxWinAmbientDispatch::p ut_DisplayAsDefault

`DisplayAsDefault` é uma propriedade de ambiente que permite que um controle descubra se ele é o controle padrão.

```
STDMETHOD(put_DisplayAsDefault)(VARIANT_BOOL bDisplayAsDefault);
```

### <a name="parameters"></a>parâmetros

*bDisplayAsDefault*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_FALSE como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchput_dochostdoubleclickflags"></a><a name="put_dochostdoubleclickflags"></a> IAxWinAmbientDispatch::p ut_DocHostDoubleClickFlags

A `DocHostDoubleClickFlags` propriedade especifica a operação que deve ocorrer em resposta a um clique duplo.

```
STDMETHOD(put_DocHostDoubleClickFlags)(DWORD dwDocHostDoubleClickFlags);
```

### <a name="parameters"></a>parâmetros

*dwDocHostDoubleClickFlags*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa DOCHOSTUIDBLCLK_DEFAULT como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchput_dochostflags"></a><a name="put_dochostflags"></a> IAxWinAmbientDispatch::p ut_DocHostFlags

A `DocHostFlags` propriedade especifica os recursos de interface do usuário do objeto de host.

```
STDMETHOD(put_DocHostFlags)(DWORD dwDocHostFlags);
```

### <a name="parameters"></a>parâmetros

*dwDocHostFlags*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa DOCHOSTUIFLAG_NO3DBORDER como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchput_font"></a><a name="put_font"></a> IAxWinAmbientDispatch::p ut_Font

A `Font` propriedade especifica a fonte de ambiente do contêiner.

```
STDMETHOD(put_Font)(IFontDisp* pFont);
```

### <a name="parameters"></a>parâmetros

*pFont*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa a fonte GUI padrão ou a fonte do sistema como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchput_forecolor"></a><a name="put_forecolor"></a> IAxWinAmbientDispatch::p ut_ForeColor

A `ForeColor` propriedade especifica a cor de primeiro plano de ambiente do contêiner.

```
STDMETHOD(put_ForeColor)(OLE_COLOR clrForeground);
```

### <a name="parameters"></a>parâmetros

*clrForeground*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa a cor de texto da janela do sistema como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchput_localeid"></a><a name="put_localeid"></a> IAxWinAmbientDispatch::p ut_LocaleID

A `LocaleID` propriedade especifica a ID de localidade ambiente do contêiner.

```
STDMETHOD(put_LocaleID)(LCID lcidLocaleID);
```

### <a name="parameters"></a>parâmetros

*lcidLocaleID*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa a localidade padrão do usuário como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchput_messagereflect"></a><a name="put_messagereflect"></a> IAxWinAmbientDispatch::p ut_MessageReflect

A `MessageReflect` propriedade ambiente especifica se o contêiner refletirá as mensagens para o controle hospedado.

```
STDMETHOD(put_MessageReflect)(VARIANT_BOOL bMessageReflect);
```

### <a name="parameters"></a>parâmetros

*bMessageReflect*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

## <a name="iaxwinambientdispatchput_optionkeypath"></a><a name="put_optionkeypath"></a> IAxWinAmbientDispatch::p ut_OptionKeyPath

A `OptionKeyPath` propriedade especifica o caminho da chave do registro para as configurações do usuário.

```
STDMETHOD(put_OptionKeyPath)(BSTR bstrOptionKeyPath);
```

### <a name="parameters"></a>parâmetros

*bstrOptionKeyPath*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

## <a name="iaxwinambientdispatchput_usermode"></a><a name="put_usermode"></a> IAxWinAmbientDispatch::p ut_UserMode

A `UserMode` propriedade especifica o modo de usuário ambiente do contêiner.

```
STDMETHOD(put_UserMode)(VARIANT_BOOL bUserMode);
```

### <a name="parameters"></a>parâmetros

*bUserMode*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor Retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

## <a name="see-also"></a>Confira também

[Interface IAxWinAmbientDispatchEx](../../atl/reference/iaxwinambientdispatchex-interface.md)<br/>
[Interface IAxWinHostWindow](../../atl/reference/iaxwinhostwindow-interface.md)<br/>
[CAxWindow::QueryHost](../../atl/reference/caxwindow-class.md#queryhost)<br/>
[AtlAxGetHost](composite-control-global-functions.md#atlaxgethost)
