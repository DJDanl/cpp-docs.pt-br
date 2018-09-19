---
title: Classe IAtlMemMgr | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- IAtlMemMgr
- ATLMEM/ATL::IAtlMemMgr
- ATLMEM/ATL::Allocate
- ATLMEM/ATL::Free
- ATLMEM/ATL::GetSize
- ATLMEM/ATL::Reallocate
dev_langs:
- C++
helpviewer_keywords:
- IAtlMemMgr class
- memory, managing
- memory, memory manager
ms.assetid: 18b2c569-25fe-4464-bdb6-3b1abef7154a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b772a548054cd9d829356436afe53748c215c193
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46078914"
---
# <a name="iatlmemmgr-class"></a>Classe IAtlMemMgr

Essa classe representa a interface para um Gerenciador de memória.

## <a name="syntax"></a>Sintaxe

```
__interface __declspec(uuid("654F7EF5-CFDF-4df9-A450-6C6A13C622C0")) IAtlMemMgr
```

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[alocar](#allocate)|Chame esse método para alocar um bloco de memória.|
|[livre](#free)|Chame esse método para liberar um bloco de memória.|
|[GetSize](#getsize)|Chame esse método para recuperar o tamanho de um bloco de memória alocada.|
|[Realocar](#reallocate)|Chame esse método para realocar um bloco de memória.|

## <a name="remarks"></a>Comentários

Essa interface é implementada pelo [CComHeap](../../atl/reference/ccomheap-class.md), [CCRTHeap](../../atl/reference/ccrtheap-class.md), [CLocalHeap](../../atl/reference/clocalheap-class.md), [CGlobalHeap](../../atl/reference/cglobalheap-class.md), ou [CWin32Heap](../../atl/reference/cwin32heap-class.md).

> [!NOTE]
>  As funções de heap local e global mais lentas do que outras funções de gerenciamento de memória e não fornecem o máximo de recursos. Portanto, os novos aplicativos devem usar o [funções de heap](/windows/desktop/Memory/heap-functions). Eles estão disponíveis na [CWin32Heap](../../atl/reference/cwin32heap-class.md) classe.

## <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#94](../../atl/codesnippet/cpp/iatlmemmgr-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlmem. h

##  <a name="allocate"></a>  IAtlMemMgr::Allocate

Chame esse método para alocar um bloco de memória.

```
void* Allocate(size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*nBytes*<br/>
O número solicitado de bytes no novo bloco de memória.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o início do bloco de memória recém-alocada.

### <a name="remarks"></a>Comentários

Chame [IAtlMemMgr::Free](#free) ou [IAtlMemMgr::Reallocate](#reallocate) para liberar a memória alocada por esse método.

### <a name="example"></a>Exemplo

Por exemplo, consulte o [visão geral de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

##  <a name="free"></a>  IAtlMemMgr::Free

Chame esse método para liberar um bloco de memória.

```
void Free(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro de memória alocado anteriormente por este Gerenciador de memória.

### <a name="remarks"></a>Comentários

Use esse método para liberar memória obtida por [IAtlMemMgr::Allocate](#allocate) ou [IAtlMemMgr::Reallocate](#reallocate).

### <a name="example"></a>Exemplo

Por exemplo, consulte o [visão geral de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

##  <a name="getsize"></a>  IAtlMemMgr::GetSize

Chame esse método para recuperar o tamanho de um bloco de memória alocada.

```
size_t GetSize(void* p) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro de memória alocado anteriormente por este Gerenciador de memória.

### <a name="return-value"></a>Valor de retorno

Retorna o tamanho do bloco de memória em bytes.

### <a name="example"></a>Exemplo

Por exemplo, consulte o [visão geral de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

##  <a name="reallocate"></a>  IAtlMemMgr::Reallocate

Chame esse método para realocar a memória alocada por este Gerenciador de memória.

```
void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>Parâmetros

*p*<br/>
Ponteiro de memória alocado anteriormente por este Gerenciador de memória.

*nBytes*<br/>
O número solicitado de bytes no novo bloco de memória.

### <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o início do bloco de memória recém-alocada.

### <a name="remarks"></a>Comentários

Chame [IAtlMemMgr::Free](#free) ou [IAtlMemMgr::Reallocate](#reallocate) para liberar a memória alocada por esse método.

Conceitualmente, esse método libera a memória existente e aloca um novo bloco de memória. Na realidade, a memória existente pode ser estendida ou caso contrário, reutilizada.

### <a name="example"></a>Exemplo

Por exemplo, consulte o [visão geral de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

##  <a name="get_allowcontextmenu"></a>  IAxWinAmbientDispatch::get_AllowContextMenu

O `AllowContextMenu` propriedade especifica se o controle hospedado tem permissão para exibir seu próprio menu de contexto.

```
STDMETHOD(get_AllowContextMenu)(VARIANT_BOOL* pbAllowContextMenu);
```

### <a name="parameters"></a>Parâmetros

*pbAllowContextMenu*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="get_allowshowui"></a>  IAxWinAmbientDispatch::get_AllowShowUI

O `AllowShowUI` propriedade especifica se o controle hospedado tem permissão para exibir sua própria interface do usuário.

```
STDMETHOD(get_AllowShowUI)(VARIANT_BOOL* pbAllowShowUI);
```

### <a name="parameters"></a>Parâmetros

*pbAllowShowUI*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_FALSE como o valor padrão dessa propriedade.

##  <a name="get_allowwindowlessactivation"></a>  IAxWinAmbientDispatch::get_AllowWindowlessActivation

O `AllowWindowlessActivation` propriedade especifica se o contêiner permite a ativação sem janelas.

```
STDMETHOD(get_AllowWindowlessActivation)(VARIANT_BOOL* pbAllowWindowless);
```

### <a name="parameters"></a>Parâmetros

*pbAllowWindowless*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="get_backcolor"></a>  IAxWinAmbientDispatch::get_BackColor

O `BackColor` propriedade especifica a cor da tela de fundo ambiente do contêiner.

```
STDMETHOD(get_BackColor)(OLE_COLOR* pclrBackground);
```

### <a name="parameters"></a>Parâmetros

*pclrBackground*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa COLOR_BTNFACE ou COLOR_WINDOW como o valor padrão dessa propriedade (dependendo se o pai da janela de host é uma caixa de diálogo ou não).

##  <a name="get_displayasdefault"></a>  IAxWinAmbientDispatch::get_DisplayAsDefault

`DisplayAsDefault` é uma propriedade de ambiente que permite que um controle para descobrir se ele é o padrão de controle.

```
STDMETHOD(get_DisplayAsDefault)(VARIANT_BOOL* pbDisplayAsDefault);
```

### <a name="parameters"></a>Parâmetros

*pbDisplayAsDefault*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_FALSE como o valor padrão dessa propriedade.

##  <a name="get_dochostdoubleclickflags"></a>  IAxWinAmbientDispatch::get_DocHostDoubleClickFlags

O `DocHostDoubleClickFlags` propriedade especifica a operação que deve ocorrer em resposta a um clique duplo.

```
STDMETHOD(get_DocHostDoubleClickFlags)(DWORD* pdwDocHostDoubleClickFlags);
```

### <a name="parameters"></a>Parâmetros

*pdwDocHostDoubleClickFlags*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa DOCHOSTUIDBLCLK_DEFAULT como o valor padrão dessa propriedade.

##  <a name="get_dochostflags"></a>  IAxWinAmbientDispatch::get_DocHostFlags

O `DocHostFlags` propriedade especifica os recursos de interface do usuário do objeto de host.

```
STDMETHOD(get_DocHostFlags)(DWORD* pdwDocHostFlags);
```

### <a name="parameters"></a>Parâmetros

*pdwDocHostFlags*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa DOCHOSTUIFLAG_NO3DBORDER como o valor padrão dessa propriedade.

##  <a name="get_font"></a>  IAxWinAmbientDispatch::get_Font

O `Font` propriedade especifica a fonte do ambiente do contêiner.

```
STDMETHOD(get_Font)(IFontDisp** pFont);
```

### <a name="parameters"></a>Parâmetros

*pFont*<br/>
[out] O endereço de um `IFontDisp` ponteiro de interface usado para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto ATL host usa a fonte de GUI padrão ou a fonte do sistema como o valor padrão dessa propriedade.

##  <a name="get_forecolor"></a>  IAxWinAmbientDispatch::get_ForeColor

O `ForeColor` propriedade especifica a cor de primeiro plano de ambiente do contêiner.

```
STDMETHOD(get_ForeColor)(OLE_COLOR* pclrForeground);
```

### <a name="parameters"></a>Parâmetros

*pclrForeground*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto ATL host usa a cor de texto da janela de sistema como o valor padrão dessa propriedade.

##  <a name="get_localeid"></a>  IAxWinAmbientDispatch::get_LocaleID

O `LocaleID` propriedade especifica a ID de localidade de ambiente do contêiner.

```
STDMETHOD(get_LocaleID)(LCID* plcidLocaleID);
```

### <a name="parameters"></a>Parâmetros

*plcidLocaleID*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto ATL host usa a localidade do usuário padrão como o valor padrão dessa propriedade.

Com esse método, você pode descobrir o ambiente LocalID, ou seja, o LocaleID do programa de seu controle está sendo usado no. Quando você souber o LocaleID, você pode chamar o código para carregar legendas específica de localidade, texto da mensagem de erro, e assim por diante de um arquivo de recurso ou uma DLL satélite.

##  <a name="get_messagereflect"></a>  IAxWinAmbientDispatch::get_MessageReflect

O `MessageReflect` propriedade de ambiente que especifica se o contêiner refletirá as mensagens para o controle hospedado.

```
STDMETHOD(get_MessageReflect)(VARIANT_BOOL* pbMessageReflect);
```

### <a name="parameters"></a>Parâmetros

*pbMessageReflect*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="get_optionkeypath"></a>  IAxWinAmbientDispatch::get_OptionKeyPath

O `OptionKeyPath` propriedade especifica o caminho da chave do registro nas configurações de usuário.

```
STDMETHOD(get_OptionKeyPath)(BSTR* pbstrOptionKeyPath);
```

### <a name="parameters"></a>Parâmetros

*pbstrOptionKeyPath*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="get_showgrabhandles"></a>  IAxWinAmbientDispatch::get_ShowGrabHandles

O `ShowGrabHandles` propriedade de ambiente permite que o controle descobrir se ele deve desenhar a próprio com as alças de captura.

```
STDMETHOD(get_ShowGrabHandles)(VARIANT_BOOL* pbShowGrabHandles);
```

### <a name="parameters"></a>Parâmetros

*pbShowGrabHandles*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação de objeto de host do ATL sempre retorna VARIANT_FALSE como o valor dessa propriedade.

##  <a name="get_showhatching"></a>  IAxWinAmbientDispatch::get_ShowHatching

O `ShowHatching` propriedade de ambiente permite que o controle descobrir se ele deve ser desenhado em si hatched.

```
STDMETHOD(get_ShowHatching)(VARIANT_BOOL* pbShowHatching);
```

### <a name="parameters"></a>Parâmetros

*pbShowHatching*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação de objeto de host do ATL sempre retorna VARIANT_FALSE como o valor dessa propriedade.

##  <a name="get_usermode"></a>  IAxWinAmbientDispatch::get_UserMode

O `UserMode` propriedade especifica o modo de usuário do ambiente do contêiner.

```
STDMETHOD(get_UserMode)(VARIANT_BOOL* pbUserMode);
```

### <a name="parameters"></a>Parâmetros

*pbUserMode*<br/>
[out] O endereço de uma variável para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="put_allowcontextmenu"></a>  IAxWinAmbientDispatch::put_AllowContextMenu

O `AllowContextMenu` propriedade especifica se o controle hospedado tem permissão para exibir seu próprio menu de contexto.

```
STDMETHOD(put_AllowContextMenu)(VARIANT_BOOL bAllowContextMenu);
```

### <a name="parameters"></a>Parâmetros

*bAllowContextMenu*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="put_allowshowui"></a>  IAxWinAmbientDispatch::put_AllowShowUI

O `AllowShowUI` propriedade especifica se o controle hospedado tem permissão para exibir sua própria interface do usuário.

```
STDMETHOD(put_AllowShowUI)(VARIANT_BOOL bAllowShowUI);
```

### <a name="parameters"></a>Parâmetros

*bAllowShowUI*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_FALSE como o valor padrão dessa propriedade.

##  <a name="put_allowwindowlessactivation"></a>  IAxWinAmbientDispatch::put_AllowWindowlessActivation

O `AllowWindowlessActivation` propriedade especifica se o contêiner permite a ativação sem janelas.

```
STDMETHOD(put_AllowWindowlessActivation)(VARIANT_BOOL bAllowWindowless);
```

### <a name="parameters"></a>Parâmetros

*bAllowWindowless*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="put_backcolor"></a>  IAxWinAmbientDispatch::put_BackColor

O `BackColor` propriedade especifica a cor da tela de fundo ambiente do contêiner.

```
STDMETHOD(put_BackColor)(OLE_COLOR clrBackground);
```

### <a name="parameters"></a>Parâmetros

*clrBackground*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa COLOR_BTNFACE ou COLOR_WINDOW como o valor padrão dessa propriedade (dependendo se o pai da janela de host é uma caixa de diálogo ou não).

##  <a name="put_displayasdefault"></a>  IAxWinAmbientDispatch::put_DisplayAsDefault

`DisplayAsDefault` é uma propriedade de ambiente que permite que um controle para descobrir se ele é o padrão de controle.

```
STDMETHOD(put_DisplayAsDefault)(VARIANT_BOOL bDisplayAsDefault);
```

### <a name="parameters"></a>Parâmetros

*bDisplayAsDefault*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_FALSE como o valor padrão dessa propriedade.

##  <a name="put_dochostdoubleclickflags"></a>  IAxWinAmbientDispatch::put_DocHostDoubleClickFlags

O `DocHostDoubleClickFlags` propriedade especifica a operação que deve ocorrer em resposta a um clique duplo.

```
STDMETHOD(put_DocHostDoubleClickFlags)(DWORD dwDocHostDoubleClickFlags);
```

### <a name="parameters"></a>Parâmetros

*dwDocHostDoubleClickFlags*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa DOCHOSTUIDBLCLK_DEFAULT como o valor padrão dessa propriedade.

##  <a name="put_dochostflags"></a>  IAxWinAmbientDispatch::put_DocHostFlags

O `DocHostFlags` propriedade especifica os recursos de interface do usuário do objeto de host.

```
STDMETHOD(put_DocHostFlags)(DWORD dwDocHostFlags);
```

### <a name="parameters"></a>Parâmetros

*dwDocHostFlags*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa DOCHOSTUIFLAG_NO3DBORDER como o valor padrão dessa propriedade.

##  <a name="put_font"></a>  IAxWinAmbientDispatch::put_Font

O `Font` propriedade especifica a fonte do ambiente do contêiner.

```
STDMETHOD(put_Font)(IFontDisp* pFont);
```

### <a name="parameters"></a>Parâmetros

*pFont*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto ATL host usa a fonte de GUI padrão ou a fonte do sistema como o valor padrão dessa propriedade.

##  <a name="put_forecolor"></a>  IAxWinAmbientDispatch::put_ForeColor

O `ForeColor` propriedade especifica a cor de primeiro plano de ambiente do contêiner.

```
STDMETHOD(put_ForeColor)(OLE_COLOR clrForeground);
```

### <a name="parameters"></a>Parâmetros

*clrForeground*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto ATL host usa a cor de texto da janela de sistema como o valor padrão dessa propriedade.

##  <a name="put_localeid"></a>  IAxWinAmbientDispatch::put_LocaleID

O `LocaleID` propriedade especifica a ID de localidade de ambiente do contêiner.

```
STDMETHOD(put_LocaleID)(LCID lcidLocaleID);
```

### <a name="parameters"></a>Parâmetros

*lcidLocaleID*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto ATL host usa a localidade do usuário padrão como o valor padrão dessa propriedade.

##  <a name="put_messagereflect"></a>  IAxWinAmbientDispatch::put_MessageReflect

O `MessageReflect` propriedade de ambiente que especifica se o contêiner refletirá as mensagens para o controle hospedado.

```
STDMETHOD(put_MessageReflect)(VARIANT_BOOL bMessageReflect);
```

### <a name="parameters"></a>Parâmetros

*bMessageReflect*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="put_optionkeypath"></a>  IAxWinAmbientDispatch::put_OptionKeyPath

O `OptionKeyPath` propriedade especifica o caminho da chave do registro nas configurações de usuário.

```
STDMETHOD(put_OptionKeyPath)(BSTR bstrOptionKeyPath);
```

### <a name="parameters"></a>Parâmetros

*bstrOptionKeyPath*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="put_usermode"></a>  IAxWinAmbientDispatch::put_UserMode

O `UserMode` propriedade especifica o modo de usuário do ambiente do contêiner.

```
STDMETHOD(put_UserMode)(VARIANT_BOOL bUserMode);
```

### <a name="parameters"></a>Parâmetros

*bUserMode*<br/>
[in] O novo valor dessa propriedade.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="setambientdispatch"></a>  IAxWinAmbientDispatchEx::SetAmbientDispatch

Esse método é chamado para complementar a interface de propriedade de ambiente padrão com uma interface definida pelo usuário.

```
virtual HRESULT STDMETHODCALLTYPE SetAmbientDispatch(IDispatch* pDispatch) = 0;
```

### <a name="parameters"></a>Parâmetros

*pDispatch*<br/>
Ponteiro para a nova interface.

### <a name="return-value"></a>Valor de retorno

Retorna S_OK no êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Quando `SetAmbientDispatch` é chamado com um ponteiro para uma nova interface, essa nova interface será usado para invocar quaisquer propriedades ou métodos solicitados pelo controle hospedado — se essas propriedades já não são fornecidas pela [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md).

##  <a name="attachcontrol"></a>  IAxWinHostWindow::AttachControl

Anexa um controle existente (e inicializado anteriormente) para o objeto de host usando a janela identificada pelo *hWnd*.

```
STDMETHOD(AttachControl)(IUnknown* pUnkControl, HWND hWnd);
```

### <a name="parameters"></a>Parâmetros

*pUnkControl*<br/>
[in] Um ponteiro para o `IUnknown` interface do controle a ser anexado ao objeto de host.

*hWnd*<br/>
[in] Um identificador para a janela a ser usado para a hospedagem.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="createcontrol"></a>  IAxWinHostWindow::CreateControl

Cria um controle, inicializa-o e hospeda-o na janela identificada pelo *hWnd*.

```
STDMETHOD(CreateControl)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream);
```

### <a name="parameters"></a>Parâmetros

*lpTricsData*<br/>
[in] Uma cadeia de caracteres que identifica o controle para criar. Pode ser um (deve incluir as chaves) de CLSID, ProgID, URL ou HTML bruto (antecedidos **MSHTML:**).

*hWnd*<br/>
[in] Um identificador para a janela a ser usado para a hospedagem.

*pStream*<br/>
[in] Um ponteiro de interface para um fluxo que contém dados de inicialização para o controle. Pode ser NULL.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Esta janela será ser uma subclasse pelo objeto de host expondo essa interface para que as mensagens podem ser refletidas ao controle e outros recursos de contêiner funcionará.

Chamar esse método é equivalente a chamar [IAxWinHostWindow::CreateControlEx](#createcontrolex).

Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLic](#createcontrollicex).

##  <a name="createcontrolex"></a>  IAxWinHostWindow::CreateControlEx

Cria um controle ActiveX, inicializa-o e hospeda-o na janela especificada, semelhante à [IAxWinHostWindow::CreateControl](#createcontrol).

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
[in] Uma cadeia de caracteres que identifica o controle para criar. Pode ser um (deve incluir as chaves) de CLSID, ProgID, URL ou HTML bruto (prefixados com **MSHTML:**).

*hWnd*<br/>
[in] Um identificador para a janela a ser usado para a hospedagem.

*pStream*<br/>
[in] Um ponteiro de interface para um fluxo que contém dados de inicialização para o controle. Pode ser NULL.

*ppUnk*<br/>
[out] O endereço de um ponteiro que receberá o `IUnknown` interface do controle criado. Pode ser NULL.

*riidAdvise*<br/>
[in] O identificador de interface de uma interface de saída o objeto contido. Pode ser IID_NULL.

*punkAdvise*<br/>
[in] Um ponteiro para o `IUnknown` interface do objeto coletor a ser conectado ao ponto de conexão no objeto independente especificado pelo `iidSink`.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Ao contrário do `CreateControl` método, `CreateControlEx` também permite que você receber um ponteiro de interface para o controle criado recentemente e configurar um coletor de eventos para receber eventos acionados pelo controle.

Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLicEx](#createcontrollicex).

##  <a name="querycontrol"></a>  IAxWinHostWindow::QueryControl

Retorna o ponteiro de interface especificado fornecido pelo controle hospedado.

```
STDMETHOD(QueryControl)(REFIID riid, void** ppvObject);
```

### <a name="parameters"></a>Parâmetros

*riid*<br/>
[in] A ID de uma interface no controle que está sendo solicitado.

*ppvObject*<br/>
[out] O endereço de um ponteiro que receberá a interface especificada do controle criado.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="setexternaldispatch"></a>  IAxWinHostWindow::SetExternalDispatch

Define a dispinterface externa, que está disponível para os controles contidos por meio de [IDocHostUIHandlerDispatch::GetExternal](../../atl/reference/idochostuihandlerdispatch-interface.md) método.

```
STDMETHOD(SetExternalDispatch)(IDispatch* pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
[in] Um ponteiro para um `IDispatch` interface.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

##  <a name="setexternaluihandler"></a>  IAxWinHostWindow::SetExternalUIHandler

Chame essa função para definir o externo [IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md) interface para o `CAxWindow` objeto.

```
STDMETHOD(SetExternalUIHandler)(IDocHostUIHandlerDispatch* pDisp);
```

### <a name="parameters"></a>Parâmetros

*pDisp*<br/>
[in] Um ponteiro para um `IDocHostUIHandlerDispatch` interface.

### <a name="return-value"></a>Valor de retorno

Um valor padrão de HRESULT.

### <a name="remarks"></a>Comentários

Essa função é usada por controles (como o controle de navegador da Web) que consultar o site do host para o `IDocHostUIHandlerDispatch` interface.

##  <a name="createcontrollic"></a>  IAxWinHostWindowLic::CreateControlLic

Cria um controle licenciado, inicializa-o e hospeda-o na janela identificada pelo `hWnd`.

```
STDMETHOD(CreateControlLic)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream,
    BSTR bstrLic);
```

### <a name="parameters"></a>Parâmetros

*bstrLic*<br/>
[in] O BSTR que contém a chave de licença para o controle.

### <a name="remarks"></a>Comentários

Ver [IAxWinHostWindow::CreateControl](#createcontrol) para obter uma descrição do valor de retorno e parâmetros restantes.

Chamar esse método é equivalente a chamar [IAxWinHostWindowLic::CreateControlLicEx](#createcontrollicex)

### <a name="example"></a>Exemplo

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `IAxWinHostWindowLic::CreateControlLic`.

##  <a name="createcontrollicex"></a>  IAxWinHostWindowLic::CreateControlLicEx

Cria um controle ActiveX licenciado, inicializa-o e hospeda-o na janela especificada, semelhante à [IAxWinHostWindow::CreateControl](#createcontrol).

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

*bstrLic*<br/>
[in] O BSTR que contém a chave de licença para o controle.

### <a name="remarks"></a>Comentários

Ver [IAxWinHostWindow::CreateControlEx](#createcontrolex) para obter uma descrição do valor de retorno e parâmetros restantes.

### <a name="example"></a>Exemplo

Ver [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `IAxWinHostWindowLic::CreateControlLicEx`.

## <a name="see-also"></a>Consulte também

[Visão geral da classe](../../atl/atl-class-overview.md)
