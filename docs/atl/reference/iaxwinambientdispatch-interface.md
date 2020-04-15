---
title: IAxWinAmbientDispatch Interface
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
ms.openlocfilehash: 6a4f5322d957b1e978bd123db3b4796be6b300da
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330002"
---
# <a name="iaxwinambientdispatch-interface"></a>IAxWinAmbientDispatch Interface

Esta interface fornece métodos para especificar características do controle ou contêiner hospedado.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
interface IAxWinAmbientDispatch : IDispatch
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[get_AllowContextMenu](#get_allowcontextmenu)|A `AllowContextMenu` propriedade especifica se o controle hospedado pode exibir seu próprio menu de contexto.|
|[get_AllowShowUI](#get_allowshowui)|A `AllowShowUI` propriedade especifica se o controle hospedado pode exibir sua própria interface de usuário.|
|[get_AllowWindowlessActivation](#get_allowwindowlessactivation)|A `AllowWindowlessActivation` propriedade especifica se o contêiner permitirá a ativação sem janelas.|
|[get_BackColor](#get_backcolor)|A `BackColor` propriedade especifica a cor de fundo ambiente do recipiente.|
|[get_DisplayAsDefault](#get_displayasdefault)|`DisplayAsDefault`é uma propriedade ambiente que permite um controle para descobrir se é o controle padrão.|
|[get_DocHostDoubleClickFlags](#get_dochostdoubleclickflags)|A `DocHostDoubleClickFlags` propriedade especifica a operação que deve ocorrer em resposta a um duplo clique.|
|[get_DocHostFlags](#get_dochostflags)|A `DocHostFlags` propriedade especifica os recursos de interface de usuário do objeto host.|
|[get_Font](#get_font)|A `Font` propriedade especifica a fonte ambiente do recipiente.|
|[get_ForeColor](#get_forecolor)|A `ForeColor` propriedade especifica a cor do primeiro plano ambiente do recipiente.|
|[get_LocaleID](#get_localeid)|A `LocaleID` propriedade especifica o ID de localização ambiente do contêiner.|
|[get_MessageReflect](#get_messagereflect)|A `MessageReflect` propriedade ambiente especifica se o contêiner refletirá mensagens para o controle hospedado.|
|[get_OptionKeyPath](#get_optionkeypath)|A `OptionKeyPath` propriedade especifica o caminho-chave do registro para as configurações do usuário.|
|[get_ShowGrabHandles](#get_showgrabhandles)|A `ShowGrabHandles` propriedade ambiente permite que o controle descubra se ele deve desenhar-se com alças de agarramento.|
|[get_ShowHatching](#get_showhatching)|A `ShowHatching` propriedade ambiente permite que o controle descubra se ele deve desenhar-se eclodido.|
|[get_UserMode](#get_usermode)|A `UserMode` propriedade especifica o modo de usuário ambiente do recipiente.|
|[put_AllowContextMenu](#put_allowcontextmenu)|A `AllowContextMenu` propriedade especifica se o controle hospedado pode exibir seu próprio menu de contexto.|
|[put_AllowShowUI](#put_allowshowui)|A `AllowShowUI` propriedade especifica se o controle hospedado pode exibir sua própria interface de usuário.|
|[put_AllowWindowlessActivation](#put_allowwindowlessactivation)|A `AllowWindowlessActivation` propriedade especifica se o contêiner permitirá a ativação sem janelas.|
|[put_BackColor](#put_backcolor)|A `BackColor` propriedade especifica a cor de fundo ambiente do recipiente.|
|[put_DisplayAsDefault](#put_displayasdefault)|`DisplayAsDefault`é uma propriedade ambiente que permite um controle para descobrir se é o controle padrão.|
|[put_DocHostDoubleClickFlags](#put_dochostdoubleclickflags)|A `DocHostDoubleClickFlags` propriedade especifica a operação que deve ocorrer em resposta a um duplo clique.|
|[put_DocHostFlags](#put_dochostflags)|A `DocHostFlags` propriedade especifica os recursos de interface de usuário do objeto host.|
|[put_Font](#put_font)|A `Font` propriedade especifica a fonte ambiente do recipiente.|
|[put_ForeColor](#put_forecolor)|A `ForeColor` propriedade especifica a cor do primeiro plano ambiente do recipiente.|
|[put_LocaleID](#put_localeid)|A `LocaleID` propriedade especifica o ID de localização ambiente do contêiner.|
|[put_MessageReflect](#put_messagereflect)|A `MessageReflect` propriedade ambiente especifica se o contêiner refletirá mensagens para o controle hospedado.|
|[put_OptionKeyPath](#put_optionkeypath)|A `OptionKeyPath` propriedade especifica o caminho-chave do registro para as configurações do usuário.|
|[put_UserMode](#put_usermode)|A `UserMode` propriedade especifica o modo de usuário ambiente do recipiente.|

## <a name="remarks"></a>Comentários

Esta interface é exposta pelos objetos de hospedagem de controle ActiveX da ATL. Chame os métodos nesta interface para definir as propriedades ambientais disponíveis para o controle hospedado ou para especificar outros aspectos do comportamento do contêiner. Para complementar as propriedades `IAxWinAmbientDispatch`fornecidas por , use [IAxWinAmbientDispatchEx](../../atl/reference/iaxwinambientdispatchex-interface.md).

<xref:System.Windows.Forms.AxHost>tentará carregar informações `IAxWinAmbientDispatch` de `IAxWinAmbientDispatchEx` tipo sobre e a partir do typelib que contém o código.

Se você estiver vinculando ao ATL90.dll, **o AXHost** carregará as informações do tipo do typelib na DLL.

Consulte [Host ActiveX Controls Usando atl AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter mais detalhes.

## <a name="requirements"></a>Requisitos

A definição desta interface está disponível em uma série de formulários, como mostrado na tabela abaixo.

|Tipo de definição|Arquivo|
|---------------------|----------|
|Idl|atliface.idl|
|Biblioteca de tipos|ATL.dll|
|C++|atliface.h (também incluído no ATLBase.h)|

## <a name="iaxwinambientdispatchget_allowcontextmenu"></a><a name="get_allowcontextmenu"></a>IAxWinAmbientDispatch::get_AllowContextMenu

A `AllowContextMenu` propriedade especifica se o controle hospedado pode exibir seu próprio menu de contexto.

```
STDMETHOD(get_AllowContextMenu)(VARIANT_BOOL* pbAllowContextMenu);
```

### <a name="parameters"></a>Parâmetros

*pbAllowContextMenu*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa VARIANT_TRUE como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchget_allowshowui"></a><a name="get_allowshowui"></a>IAxWinAmbientDispatch::get_AllowShowUI

A `AllowShowUI` propriedade especifica se o controle hospedado pode exibir sua própria interface de usuário.

```
STDMETHOD(get_AllowShowUI)(VARIANT_BOOL* pbAllowShowUI);
```

### <a name="parameters"></a>Parâmetros

*pbAllowShowUI*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa VARIANT_FALSE como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchget_allowwindowlessactivation"></a><a name="get_allowwindowlessactivation"></a>IAxWinAmbientDispatch::get_AllowWindowlessActivation

A `AllowWindowlessActivation` propriedade especifica se o contêiner permitirá a ativação sem janelas.

```
STDMETHOD(get_AllowWindowlessActivation)(VARIANT_BOOL* pbAllowWindowless);
```

### <a name="parameters"></a>Parâmetros

*pbAllowWindowless*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa VARIANT_TRUE como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchget_backcolor"></a><a name="get_backcolor"></a>IAxWinAmbientDispatch::get_BackColor

A `BackColor` propriedade especifica a cor de fundo ambiente do recipiente.

```
STDMETHOD(get_BackColor)(OLE_COLOR* pclrBackground);
```

### <a name="parameters"></a>Parâmetros

*pclrBackground*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa COLOR_BTNFACE ou COLOR_WINDOW como o valor padrão desta propriedade (dependendo se o pai da janela host é uma caixa de diálogo ou não).

## <a name="iaxwinambientdispatchget_displayasdefault"></a><a name="get_displayasdefault"></a>IAxWinAmbientDispatch::get_DisplayAsDefault

`DisplayAsDefault`é uma propriedade ambiente que permite um controle para descobrir se é o controle padrão.

```
STDMETHOD(get_DisplayAsDefault)(VARIANT_BOOL* pbDisplayAsDefault);
```

### <a name="parameters"></a>Parâmetros

*pbDisplayAsDefault*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa VARIANT_FALSE como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchget_dochostdoubleclickflags"></a><a name="get_dochostdoubleclickflags"></a>IAxWinAmbientDispatch::get_DocHostDoubleClickFlags

A `DocHostDoubleClickFlags` propriedade especifica a operação que deve ocorrer em resposta a um duplo clique.

```
STDMETHOD(get_DocHostDoubleClickFlags)(DWORD* pdwDocHostDoubleClickFlags);
```

### <a name="parameters"></a>Parâmetros

*pdwDocHostDoubleClickFlags*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa DOCHOSTUIDBLCLK_DEFAULT como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchget_dochostflags"></a><a name="get_dochostflags"></a>IAxWinAmbientDispatch::get_DocHostFlags

A `DocHostFlags` propriedade especifica os recursos de interface de usuário do objeto host.

```
STDMETHOD(get_DocHostFlags)(DWORD* pdwDocHostFlags);
```

### <a name="parameters"></a>Parâmetros

*pdwDocHostFlags*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa DOCHOSTUIFLAG_NO3DBORDER como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchget_font"></a><a name="get_font"></a>IAxWinAmbientDispatch::get_Font

A `Font` propriedade especifica a fonte ambiente do recipiente.

```
STDMETHOD(get_Font)(IFontDisp** pFont);
```

### <a name="parameters"></a>Parâmetros

*fonte p*<br/>
[fora] O endereço `IFontDisp` de um ponteiro de interface usado para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa a fonte GUI padrão ou a fonte do sistema como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchget_forecolor"></a><a name="get_forecolor"></a>IAxWinAmbientDispatch::get_ForeColor

A `ForeColor` propriedade especifica a cor do primeiro plano ambiente do recipiente.

```
STDMETHOD(get_ForeColor)(OLE_COLOR* pclrForeground);
```

### <a name="parameters"></a>Parâmetros

*pclrForeground*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa a cor do texto da janela do sistema como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchget_localeid"></a><a name="get_localeid"></a>IAxWinAmbientDispatch::get_LocaleID

A `LocaleID` propriedade especifica o ID de localização ambiente do contêiner.

```
STDMETHOD(get_LocaleID)(LCID* plcidLocaleID);
```

### <a name="parameters"></a>Parâmetros

*plcidLocaleID*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa a localização padrão do usuário como o valor padrão desta propriedade.

Com este método você pode descobrir o Ambient LocalID, ou seja, o LocaleID do programa em que seu controle está sendo usado. Uma vez que você conhece o LocaleID, você pode chamar o código para carregar legendas específicas do local, texto de mensagem de erro e assim por diante a partir de um arquivo de recurso ou DLL de satélite.

## <a name="iaxwinambientdispatchget_messagereflect"></a><a name="get_messagereflect"></a>IAxWinAmbientDispatch::get_MessageReflect

A `MessageReflect` propriedade ambiente especifica se o contêiner refletirá mensagens para o controle hospedado.

```
STDMETHOD(get_MessageReflect)(VARIANT_BOOL* pbMessageReflect);
```

### <a name="parameters"></a>Parâmetros

*pbMessageReflect*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa VARIANT_TRUE como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchget_optionkeypath"></a><a name="get_optionkeypath"></a>IAxWinAmbientDispatch::get_OptionKeyPath

A `OptionKeyPath` propriedade especifica o caminho-chave do registro para as configurações do usuário.

```
STDMETHOD(get_OptionKeyPath)(BSTR* pbstrOptionKeyPath);
```

### <a name="parameters"></a>Parâmetros

*pbstrOptionKeyPath*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="iaxwinambientdispatchget_showgrabhandles"></a><a name="get_showgrabhandles"></a>IAxWinAmbientDispatch::get_ShowGrabHandles

A `ShowGrabHandles` propriedade ambiente permite que o controle descubra se ele deve desenhar-se com alças de agarramento.

```
STDMETHOD(get_ShowGrabHandles)(VARIANT_BOOL* pbShowGrabHandles);
```

### <a name="parameters"></a>Parâmetros

*pbShowGrabHandles*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL sempre retorna VARIANT_FALSE como o valor desta propriedade.

## <a name="iaxwinambientdispatchget_showhatching"></a><a name="get_showhatching"></a>IAxWinAmbientDispatch::get_ShowHatching

A `ShowHatching` propriedade ambiente permite que o controle descubra se ele deve desenhar-se eclodido.

```
STDMETHOD(get_ShowHatching)(VARIANT_BOOL* pbShowHatching);
```

### <a name="parameters"></a>Parâmetros

*pbShowHatching*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL sempre retorna VARIANT_FALSE como o valor desta propriedade.

## <a name="iaxwinambientdispatchget_usermode"></a><a name="get_usermode"></a>IAxWinAmbientDispatch::get_UserMode

A `UserMode` propriedade especifica o modo de usuário ambiente do recipiente.

```
STDMETHOD(get_UserMode)(VARIANT_BOOL* pbUserMode);
```

### <a name="parameters"></a>Parâmetros

*pbUserMode*<br/>
[fora] O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa VARIANT_TRUE como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchput_allowcontextmenu"></a><a name="put_allowcontextmenu"></a>IAxWinAmbientDispatch::put_AllowContextMenu

A `AllowContextMenu` propriedade especifica se o controle hospedado pode exibir seu próprio menu de contexto.

```
STDMETHOD(put_AllowContextMenu)(VARIANT_BOOL bAllowContextMenu);
```

### <a name="parameters"></a>Parâmetros

*bAllowContextMenu*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa VARIANT_TRUE como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchput_allowshowui"></a><a name="put_allowshowui"></a>IAxWinAmbientDispatch::put_AllowShowUI

A `AllowShowUI` propriedade especifica se o controle hospedado pode exibir sua própria interface de usuário.

```
STDMETHOD(put_AllowShowUI)(VARIANT_BOOL bAllowShowUI);
```

### <a name="parameters"></a>Parâmetros

*ballowShowUI*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa VARIANT_FALSE como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchput_allowwindowlessactivation"></a><a name="put_allowwindowlessactivation"></a>IAxWinAmbientDispatch::put_AllowSActivation

A `AllowWindowlessActivation` propriedade especifica se o contêiner permitirá a ativação sem janelas.

```
STDMETHOD(put_AllowWindowlessActivation)(VARIANT_BOOL bAllowWindowless);
```

### <a name="parameters"></a>Parâmetros

*bAllowWindowless*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa VARIANT_TRUE como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchput_backcolor"></a><a name="put_backcolor"></a>IAxWinAmbientDispatch::put_BackColor

A `BackColor` propriedade especifica a cor de fundo ambiente do recipiente.

```
STDMETHOD(put_BackColor)(OLE_COLOR clrBackground);
```

### <a name="parameters"></a>Parâmetros

*clrBackground*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa COLOR_BTNFACE ou COLOR_WINDOW como o valor padrão desta propriedade (dependendo se o pai da janela host é uma caixa de diálogo ou não).

## <a name="iaxwinambientdispatchput_displayasdefault"></a><a name="put_displayasdefault"></a>IAxWinAmbientDispatch::put_DisplayAsDefault

`DisplayAsDefault`é uma propriedade ambiente que permite um controle para descobrir se é o controle padrão.

```
STDMETHOD(put_DisplayAsDefault)(VARIANT_BOOL bDisplayAsDefault);
```

### <a name="parameters"></a>Parâmetros

*bDisplayAsDefault*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa VARIANT_FALSE como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchput_dochostdoubleclickflags"></a><a name="put_dochostdoubleclickflags"></a>IAxWinAmbientDispatch::put_DocHostDoubleClickFlags

A `DocHostDoubleClickFlags` propriedade especifica a operação que deve ocorrer em resposta a um duplo clique.

```
STDMETHOD(put_DocHostDoubleClickFlags)(DWORD dwDocHostDoubleClickFlags);
```

### <a name="parameters"></a>Parâmetros

*dwDocHostDoubleClickFlags*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa DOCHOSTUIDBLCLK_DEFAULT como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchput_dochostflags"></a><a name="put_dochostflags"></a>IAxWinAmbientDispatch::put_DocHostFlags

A `DocHostFlags` propriedade especifica os recursos de interface de usuário do objeto host.

```
STDMETHOD(put_DocHostFlags)(DWORD dwDocHostFlags);
```

### <a name="parameters"></a>Parâmetros

*dwDocHostFlags*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa DOCHOSTUIFLAG_NO3DBORDER como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchput_font"></a><a name="put_font"></a>IAxWinAmbientDispatch::put_Font

A `Font` propriedade especifica a fonte ambiente do recipiente.

```
STDMETHOD(put_Font)(IFontDisp* pFont);
```

### <a name="parameters"></a>Parâmetros

*fonte p*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa a fonte GUI padrão ou a fonte do sistema como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchput_forecolor"></a><a name="put_forecolor"></a>IAxWinAmbientDispatch::put_ForeColor

A `ForeColor` propriedade especifica a cor do primeiro plano ambiente do recipiente.

```
STDMETHOD(put_ForeColor)(OLE_COLOR clrForeground);
```

### <a name="parameters"></a>Parâmetros

*clrForeground*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa a cor do texto da janela do sistema como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchput_localeid"></a><a name="put_localeid"></a>IAxWinAmbientDispatch::put_LocaleID

A `LocaleID` propriedade especifica o ID de localização ambiente do contêiner.

```
STDMETHOD(put_LocaleID)(LCID lcidLocaleID);
```

### <a name="parameters"></a>Parâmetros

*icidLocaleID*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa a localização padrão do usuário como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchput_messagereflect"></a><a name="put_messagereflect"></a>IAxWinAmbientDispatch::put_MessageReflect

A `MessageReflect` propriedade ambiente especifica se o contêiner refletirá mensagens para o controle hospedado.

```
STDMETHOD(put_MessageReflect)(VARIANT_BOOL bMessageReflect);
```

### <a name="parameters"></a>Parâmetros

*bMessageReflect*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa VARIANT_TRUE como o valor padrão desta propriedade.

## <a name="iaxwinambientdispatchput_optionkeypath"></a><a name="put_optionkeypath"></a>IAxWinAmbientDispatch::put_OptionKeyPath

A `OptionKeyPath` propriedade especifica o caminho-chave do registro para as configurações do usuário.

```
STDMETHOD(put_OptionKeyPath)(BSTR bstrOptionKeyPath);
```

### <a name="parameters"></a>Parâmetros

*bstrOptionKeyPath*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="iaxwinambientdispatchput_usermode"></a><a name="put_usermode"></a>IAxWinAmbientDispatch::put_UserMode

A `UserMode` propriedade especifica o modo de usuário ambiente do recipiente.

```
STDMETHOD(put_UserMode)(VARIANT_BOOL bUserMode);
```

### <a name="parameters"></a>Parâmetros

*bUserMode*<br/>
[em] O novo valor desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto host ATL usa VARIANT_TRUE como o valor padrão desta propriedade.

## <a name="see-also"></a>Confira também

[IAxWinAmbientDispatchEx Interface](../../atl/reference/iaxwinambientdispatchex-interface.md)<br/>
[IAxWinHostWindow Interface](../../atl/reference/iaxwinhostwindow-interface.md)<br/>
[CAxWindow::ConsultaHost](../../atl/reference/caxwindow-class.md#queryhost)<br/>
[AtlAxGetHost](composite-control-global-functions.md#atlaxgethost)
