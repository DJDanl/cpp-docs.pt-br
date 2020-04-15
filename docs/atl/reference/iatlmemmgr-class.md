---
title: Classe IAtlMemMgr
ms.date: 11/04/2016
f1_keywords:
- IAtlMemMgr
- ATLMEM/ATL::IAtlMemMgr
- ATLMEM/ATL::Allocate
- ATLMEM/ATL::Free
- ATLMEM/ATL::GetSize
- ATLMEM/ATL::Reallocate
helpviewer_keywords:
- IAtlMemMgr class
- memory, managing
- memory, memory manager
ms.assetid: 18b2c569-25fe-4464-bdb6-3b1abef7154a
ms.openlocfilehash: c296c9de79c305d0f7d2f135f250d181d3cd667a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81330066"
---
# <a name="iatlmemmgr-class"></a>Classe IAtlMemMgr

Esta classe representa a interface para um gerenciador de memória.

## <a name="syntax"></a>Sintaxe

```
__interface __declspec(uuid("654F7EF5-CFDF-4df9-A450-6C6A13C622C0")) IAtlMemMgr
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[Alocar](#allocate)|Chame este método para alocar um bloco de memória.|
|[Livre](#free)|Chame este método para liberar um bloco de memória.|
|[GetSize](#getsize)|Chame este método para recuperar o tamanho de um bloco de memória alocado.|
|[Realocar](#reallocate)|Chame este método para realocar um bloco de memória.|

## <a name="remarks"></a>Comentários

Esta interface é implementada por [CComHeap,](../../atl/reference/ccomheap-class.md) [CCRTHeap,](../../atl/reference/ccrtheap-class.md) [CLocalHeap,](../../atl/reference/clocalheap-class.md) [CGlobalHeap](../../atl/reference/cglobalheap-class.md)ou [CWin32Heap](../../atl/reference/cwin32heap-class.md).

> [!NOTE]
> As funções de pilha local e global são mais lentas do que outras funções de gerenciamento de memória, e não fornecem tantos recursos. Portanto, novas aplicações devem usar as [funções de pilha.](/windows/win32/Memory/heap-functions) Estes estão disponíveis na classe [CWin32Heap.](../../atl/reference/cwin32heap-class.md)

## <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#94](../../atl/codesnippet/cpp/iatlmemmgr-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlmem.h

## <a name="iatlmemmgrallocate"></a><a name="allocate"></a>IAtlMemMgr::Alocar

Chame este método para alocar um bloco de memória.

```
void* Allocate(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*Nbytes*<br/>
O número solicitado de bytes no novo bloco de memória.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o início do bloco de memória recém-alocado.

### <a name="remarks"></a>Comentários

Ligue para [IAtlMemMgr:::Free](#free) ou [IAtlMemMgr::Reallocate](#reallocate) para liberar a memória alocada por este método.

### <a name="example"></a>Exemplo

Por exemplo, consulte a [visão geral do IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

## <a name="iatlmemmgrfree"></a><a name="free"></a>IAtlMemMgr::Grátis

Chame este método para liberar um bloco de memória.

```
void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para memória previamente alocado por este gerenciador de memória.

### <a name="remarks"></a>Comentários

Use este método para liberar a memória obtida por [IAtlMemMgr::Alocar](#allocate) ou [IAtlMemMgr:::Reallocate](#reallocate).

### <a name="example"></a>Exemplo

Por exemplo, consulte a [visão geral do IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

## <a name="iatlmemmgrgetsize"></a><a name="getsize"></a>IAtlMemMgr::GetSize

Chame este método para recuperar o tamanho de um bloco de memória alocado.

```
size_t GetSize(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para memória previamente alocado por este gerenciador de memória.

### <a name="return-value"></a>Valor retornado

Retorna o tamanho do bloco de memória em bytes.

### <a name="example"></a>Exemplo

Por exemplo, consulte a [visão geral do IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

## <a name="iatlmemmgrreallocate"></a><a name="reallocate"></a>IAtlMemMgr::Realocação

Chame este método para realocar a memória alocada por este gerenciador de memória.

```
void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*P*<br/>
Ponteiro para memória previamente alocado por este gerenciador de memória.

*Nbytes*<br/>
O número solicitado de bytes no novo bloco de memória.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o início do bloco de memória recém-alocado.

### <a name="remarks"></a>Comentários

Ligue para [IAtlMemMgr:::Free](#free) ou [IAtlMemMgr::Reallocate](#reallocate) para liberar a memória alocada por este método.

Conceitualmente, este método libera a memória existente e aloca um novo bloco de memória. Na realidade, a memória existente pode ser estendida ou reutilizada de outra forma.

### <a name="example"></a>Exemplo

Por exemplo, consulte a [visão geral do IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

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

## <a name="iaxwinambientdispatchexsetambientdispatch"></a><a name="setambientdispatch"></a>IAxWinAmbientDispatchEx::SetAmbientDispatch

Este método é chamado para complementar a interface de propriedade ambiente padrão com uma interface definida pelo usuário.

```
virtual HRESULT STDMETHODCALLTYPE SetAmbientDispatch(IDispatch* pDispatch) = 0;
```

### <a name="parameters"></a>Parâmetros

*pDispatch*<br/>
Ponteiro para a nova interface.

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

### <a name="remarks"></a>Comentários

Quando `SetAmbientDispatch` é chamado com um ponteiro para uma nova interface, esta nova interface será usada para invocar quaisquer propriedades ou métodos solicitados pelo controle hospedado — se essas propriedades ainda não estiverem fornecidas pelo [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md).

## <a name="iaxwinhostwindowattachcontrol"></a><a name="attachcontrol"></a>IAxWinHostWindow::AttachControl

Anexa um controle existente (e previamente inicializado) ao objeto host usando a janela identificada por *hWnd*.

```
STDMETHOD(AttachControl)(IUnknown* pUnkControl, HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*pUnkControl*<br/>
[em] Um ponteiro `IUnknown` para a interface do controle a ser anexado ao objeto host.

*hWnd*<br/>
[em] Uma alça para a janela a ser usada para hospedagem.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="iaxwinhostwindowcreatecontrol"></a><a name="createcontrol"></a>IAxWinHostWindow::CreateControl

Cria um controle, inicializa-o e hospeda-o na janela identificada por *hWnd*.

```
STDMETHOD(CreateControl)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream);
```

### <a name="parameters"></a>Parâmetros

*lpTricsData*<br/>
[em] Uma seqüência identificando o controle para criar. Pode ser um CLSID (deve incluir os aparelhos), ProgID, URL ou HTML bruto (prefixado por **MSHTML:**).

*hWnd*<br/>
[em] Uma alça para a janela a ser usada para hospedagem.

*pStream*<br/>
[em] Um ponteiro de interface para um fluxo contendo dados de inicialização para o controle. Pode ser NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Esta janela será subclassificada pelo objeto host expondo esta interface para que as mensagens possam ser refletidas no controle e outros recursos do contêiner funcionarão.

Chamar esse método é equivalente a chamar [IAxWinHostWindow::CreateControlEx](#createcontrolex).

Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLic](#createcontrollicex).

## <a name="iaxwinhostwindowcreatecontrolex"></a><a name="createcontrolex"></a>IAxWinHostWindow::CreateControlEx

Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada, semelhante ao [IAxWinHostWindow::CreateControl](#createcontrol).

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

*lpTricsData*<br/>
[em] Uma seqüência identificando o controle para criar. Pode ser um CLSID (deve incluir os aparelhos), ProgID, URL ou HTML bruto (prefixado com **MSHTML:**).

*hWnd*<br/>
[em] Uma alça para a janela a ser usada para hospedagem.

*pStream*<br/>
[em] Um ponteiro de interface para um fluxo contendo dados de inicialização para o controle. Pode ser NULL.

*ppUnk*<br/>
[fora] O endereço de um ponteiro `IUnknown` que receberá a interface do controle criado. Pode ser NULL.

*riidAdvise*<br/>
[em] O identificador de interface de uma interface de saída no objeto contido. Pode ser IID_NULL.

*punkAdvise*<br/>
[em] Um ponteiro `IUnknown` para a interface do objeto da pia a ser conectado `iidSink`ao ponto de conexão no objeto contido especificado por .

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Ao `CreateControl` contrário `CreateControlEx` do método, também permite que você receba um ponteiro de interface para o controle recém-criado e configure um dissipador de eventos para receber eventos disparados pelo controle.

Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLicEx](#createcontrollicex).

## <a name="iaxwinhostwindowquerycontrol"></a><a name="querycontrol"></a>IAxWinHostWindow::QueryControl

Retorna o ponteiro de interface especificado fornecido pelo controle hospedado.

```
STDMETHOD(QueryControl)(REFIID riid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
[em] O ID de uma interface no controle que está sendo solicitado.

*Ppvobject*<br/>
[fora] O endereço de um ponteiro que receberá a interface especificada do controle criado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="iaxwinhostwindowsetexternaldispatch"></a><a name="setexternaldispatch"></a>IAxWinHostWindow::SetExternalDispatch

Define a dispinterface externa, disponível para controles contidos através do [método IDocHostUIHandlerDispatch::GetExternal.](../../atl/reference/idochostuihandlerdispatch-interface.md)

```
STDMETHOD(SetExternalDispatch)(IDispatch* pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
[em] Um ponteiro `IDispatch` para uma interface.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

## <a name="iaxwinhostwindowsetexternaluihandler"></a><a name="setexternaluihandler"></a>IAxWinHostWindow::SetExternalUIHandler

Chame esta função para definir a interface externa [IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md) para o `CAxWindow` objeto.

```
STDMETHOD(SetExternalUIHandler)(IDocHostUIHandlerDispatch* pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
[em] Um ponteiro `IDocHostUIHandlerDispatch` para uma interface.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Esta função é usada por controles (como o controle do navegador da `IDocHostUIHandlerDispatch` Web) que consultam o site do host para a interface.

## <a name="iaxwinhostwindowliccreatecontrollic"></a><a name="createcontrollic"></a>IAxWinHostWindowlic::CreateControlLic

Cria um controle licenciado, inicializa-o e hospeda-o na janela identificada por `hWnd`.

```
STDMETHOD(CreateControlLic)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream,
    BSTR bstrLic);
```

### <a name="parameters"></a>Parâmetros

*bstrlic*<br/>
[em] O BSTR que contém a chave de licença para o controle.

### <a name="remarks"></a>Comentários

Consulte [IAxWinHostWindow::CreateControl](#createcontrol) para obter uma descrição dos parâmetros restantes e do valor de retorno.

Chamar esse método é equivalente a chamar [IAxWinHostWindowLic::CreateControlLicEx](#createcontrollicex)

### <a name="example"></a>Exemplo

Consulte [Host ActiveX Controls Usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter uma amostra que usa `IAxWinHostWindowLic::CreateControlLic`.

## <a name="iaxwinhostwindowliccreatecontrollicex"></a><a name="createcontrollicex"></a>IAxWinHostWindowliclic::CreateControlLicEx

Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada, semelhante ao [IAxWinHostWindow::CreateControl](#createcontrol).

```
STDMETHOD(CreateControlLicEx)(
    LPCOLESTR lpszTricsData,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnk,
    REFIID riidAdvise,
    IUnknown* punkAdvise,
    BSTR bstrLic);
```

### <a name="parameters"></a>Parâmetros

*bstrlic*<br/>
[em] O BSTR que contém a chave de licença para o controle.

### <a name="remarks"></a>Comentários

Consulte [IAxWinHostWindow::CreateControlEx](#createcontrolex) para obter uma descrição dos parâmetros restantes e do valor de retorno.

### <a name="example"></a>Exemplo

Consulte [Host ActiveX Controls Usando ATL AXHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter uma amostra que usa `IAxWinHostWindowLic::CreateControlLicEx`.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
