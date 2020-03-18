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
ms.openlocfilehash: a0d79ae95a0604ca75f03673873e99394a1bc295
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79417652"
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
|[Aloca](#allocate)|Chame esse método para alocar um bloco de memória.|
|[Gratuito](#free)|Chame esse método para liberar um bloco de memória.|
|[GetSize](#getsize)|Chame esse método para recuperar o tamanho de um bloco de memória alocado.|
|[Realocar](#reallocate)|Chame esse método para realocar um bloco de memória.|

## <a name="remarks"></a>Comentários

Essa interface é implementada por [CComHeap](../../atl/reference/ccomheap-class.md), [CCRTHeap](../../atl/reference/ccrtheap-class.md), [CLocalHeap](../../atl/reference/clocalheap-class.md), [CGlobalHeap](../../atl/reference/cglobalheap-class.md)ou [CWin32Heap](../../atl/reference/cwin32heap-class.md).

> [!NOTE]
>  As funções de heap local e global são mais lentas do que outras funções de gerenciamento de memória e não fornecem quantos recursos. Portanto, novos aplicativos devem usar as [funções de heap](/windows/win32/Memory/heap-functions). Eles estão disponíveis na classe [CWin32Heap](../../atl/reference/cwin32heap-class.md) .

## <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_Utilities#94](../../atl/codesnippet/cpp/iatlmemmgr-class_1.cpp)]

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlmem. h

##  <a name="allocate"></a>IAtlMemMgr:: Allocate

Chame esse método para alocar um bloco de memória.

```
void* Allocate(size_t nBytes) throw();
```

### <a name="parameters"></a>parâmetros

*nBytes*<br/>
O número de bytes solicitado no novo bloco de memória.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o início do bloco de memória alocado recentemente.

### <a name="remarks"></a>Comentários

Chame [IAtlMemMgr:: Free](#free) ou [IAtlMemMgr:: realoque](#reallocate) para liberar a memória alocada por esse método.

### <a name="example"></a>Exemplo

Para obter um exemplo, consulte a [visão geral do IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

##  <a name="free"></a>IAtlMemMgr:: Free

Chame esse método para liberar um bloco de memória.

```
void Free(void* p) throw();
```

### <a name="parameters"></a>parâmetros

*p*<br/>
Ponteiro para a memória alocada anteriormente por esse Gerenciador de memória.

### <a name="remarks"></a>Comentários

Use este método para liberar memória obtida por [IAtlMemMgr:: Allocate](#allocate) ou [IAtlMemMgr:: realoque](#reallocate).

### <a name="example"></a>Exemplo

Para obter um exemplo, consulte a [visão geral do IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

##  <a name="getsize"></a>IAtlMemMgr::GetSize

Chame esse método para recuperar o tamanho de um bloco de memória alocado.

```
size_t GetSize(void* p) throw();
```

### <a name="parameters"></a>parâmetros

*p*<br/>
Ponteiro para a memória alocada anteriormente por esse Gerenciador de memória.

### <a name="return-value"></a>Valor retornado

Retorna o tamanho do bloco de memória em bytes.

### <a name="example"></a>Exemplo

Para obter um exemplo, consulte a [visão geral do IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

##  <a name="reallocate"></a>IAtlMemMgr:: realocar

Chame esse método para realocar memória alocada por esse Gerenciador de memória.

```
void* Reallocate(void* p, size_t nBytes) throw();
```

### <a name="parameters"></a>parâmetros

*p*<br/>
Ponteiro para a memória alocada anteriormente por esse Gerenciador de memória.

*nBytes*<br/>
O número de bytes solicitado no novo bloco de memória.

### <a name="return-value"></a>Valor retornado

Retorna um ponteiro para o início do bloco de memória alocado recentemente.

### <a name="remarks"></a>Comentários

Chame [IAtlMemMgr:: Free](#free) ou [IAtlMemMgr:: realoque](#reallocate) para liberar a memória alocada por esse método.

Conceitualmente, esse método libera a memória existente e aloca um novo bloco de memória. Na realidade, a memória existente pode ser estendida ou reutilizada de outra forma.

### <a name="example"></a>Exemplo

Para obter um exemplo, consulte a [visão geral do IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).

##  <a name="get_allowcontextmenu"></a>IAxWinAmbientDispatch:: get_AllowContextMenu

A propriedade `AllowContextMenu` especifica se o controle hospedado tem permissão para exibir seu próprio menu de contexto.

```
STDMETHOD(get_AllowContextMenu)(VARIANT_BOOL* pbAllowContextMenu);
```

### <a name="parameters"></a>parâmetros

*pbAllowContextMenu*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="get_allowshowui"></a>IAxWinAmbientDispatch:: get_AllowShowUI

A propriedade `AllowShowUI` especifica se o controle hospedado tem permissão para exibir sua própria interface do usuário.

```
STDMETHOD(get_AllowShowUI)(VARIANT_BOOL* pbAllowShowUI);
```

### <a name="parameters"></a>parâmetros

*pbAllowShowUI*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_FALSE como o valor padrão dessa propriedade.

##  <a name="get_allowwindowlessactivation"></a>IAxWinAmbientDispatch:: get_AllowWindowlessActivation

A propriedade `AllowWindowlessActivation` especifica se o contêiner permitirá a ativação sem janela.

```
STDMETHOD(get_AllowWindowlessActivation)(VARIANT_BOOL* pbAllowWindowless);
```

### <a name="parameters"></a>parâmetros

*pbAllowWindowless*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="get_backcolor"></a>IAxWinAmbientDispatch:: get_BackColor

A propriedade `BackColor` especifica a cor do plano de fundo ambiente do contêiner.

```
STDMETHOD(get_BackColor)(OLE_COLOR* pclrBackground);
```

### <a name="parameters"></a>parâmetros

*pclrBackground*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa COLOR_BTNFACE ou COLOR_WINDOW como o valor padrão dessa propriedade (dependendo se o pai da janela do host é uma caixa de diálogo ou não).

##  <a name="get_displayasdefault"></a>IAxWinAmbientDispatch:: get_DisplayAsDefault

`DisplayAsDefault` é uma propriedade de ambiente que permite que um controle descubra se ele é o controle padrão.

```
STDMETHOD(get_DisplayAsDefault)(VARIANT_BOOL* pbDisplayAsDefault);
```

### <a name="parameters"></a>parâmetros

*pbDisplayAsDefault*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_FALSE como o valor padrão dessa propriedade.

##  <a name="get_dochostdoubleclickflags"></a>IAxWinAmbientDispatch:: get_DocHostDoubleClickFlags

A propriedade `DocHostDoubleClickFlags` especifica a operação que deve ocorrer em resposta a um clique duplo.

```
STDMETHOD(get_DocHostDoubleClickFlags)(DWORD* pdwDocHostDoubleClickFlags);
```

### <a name="parameters"></a>parâmetros

*pdwDocHostDoubleClickFlags*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa DOCHOSTUIDBLCLK_DEFAULT como o valor padrão dessa propriedade.

##  <a name="get_dochostflags"></a>IAxWinAmbientDispatch:: get_DocHostFlags

A propriedade `DocHostFlags` especifica os recursos de interface do usuário do objeto de host.

```
STDMETHOD(get_DocHostFlags)(DWORD* pdwDocHostFlags);
```

### <a name="parameters"></a>parâmetros

*pdwDocHostFlags*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa DOCHOSTUIFLAG_NO3DBORDER como o valor padrão dessa propriedade.

##  <a name="get_font"></a>IAxWinAmbientDispatch:: get_Font

A propriedade `Font` especifica a fonte de ambiente do contêiner.

```
STDMETHOD(get_Font)(IFontDisp** pFont);
```

### <a name="parameters"></a>parâmetros

*pFont*<br/>
fora O endereço de um ponteiro de interface `IFontDisp` usado para receber o valor atual dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa a fonte GUI padrão ou a fonte do sistema como o valor padrão dessa propriedade.

##  <a name="get_forecolor"></a>IAxWinAmbientDispatch:: get_ForeColor

A propriedade `ForeColor` especifica a cor de primeiro plano de ambiente do contêiner.

```
STDMETHOD(get_ForeColor)(OLE_COLOR* pclrForeground);
```

### <a name="parameters"></a>parâmetros

*pclrForeground*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa a cor de texto da janela do sistema como o valor padrão dessa propriedade.

##  <a name="get_localeid"></a>IAxWinAmbientDispatch:: get_LocaleID

A propriedade `LocaleID` especifica a ID de localidade ambiente do contêiner.

```
STDMETHOD(get_LocaleID)(LCID* plcidLocaleID);
```

### <a name="parameters"></a>parâmetros

*plcidLocaleID*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa a localidade padrão do usuário como o valor padrão dessa propriedade.

Com esse método, você pode descobrir o ambiente LocalId, ou seja, o LocaleID do programa em que seu controle está sendo usado. Depois de saber a LocaleID, você pode chamar o código para carregar legendas específicas de localidade, texto de mensagem de erro e assim por diante de um arquivo de recurso ou DLL satélite.

##  <a name="get_messagereflect"></a>IAxWinAmbientDispatch:: get_MessageReflect

A propriedade de ambiente `MessageReflect` especifica se o contêiner refletirá as mensagens para o controle hospedado.

```
STDMETHOD(get_MessageReflect)(VARIANT_BOOL* pbMessageReflect);
```

### <a name="parameters"></a>parâmetros

*pbMessageReflect*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="get_optionkeypath"></a>IAxWinAmbientDispatch:: get_OptionKeyPath

A propriedade `OptionKeyPath` especifica o caminho da chave do registro para as configurações do usuário.

```
STDMETHOD(get_OptionKeyPath)(BSTR* pbstrOptionKeyPath);
```

### <a name="parameters"></a>parâmetros

*pbstrOptionKeyPath*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

##  <a name="get_showgrabhandles"></a>IAxWinAmbientDispatch:: get_ShowGrabHandles

A propriedade de ambiente `ShowGrabHandles` permite que o controle descubra se ele deve se desenhar com alças de captura.

```
STDMETHOD(get_ShowGrabHandles)(VARIANT_BOOL* pbShowGrabHandles);
```

### <a name="parameters"></a>parâmetros

*pbShowGrabHandles*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL sempre retorna VARIANT_FALSE como o valor dessa propriedade.

##  <a name="get_showhatching"></a>IAxWinAmbientDispatch:: get_ShowHatching

O `ShowHatching` propriedade de ambiente permite que o controle descubra se ele deve ser desenhado em um hachura.

```
STDMETHOD(get_ShowHatching)(VARIANT_BOOL* pbShowHatching);
```

### <a name="parameters"></a>parâmetros

*pbShowHatching*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL sempre retorna VARIANT_FALSE como o valor dessa propriedade.

##  <a name="get_usermode"></a>IAxWinAmbientDispatch:: get_UserMode

A propriedade `UserMode` especifica o modo de usuário ambiente do contêiner.

```
STDMETHOD(get_UserMode)(VARIANT_BOOL* pbUserMode);
```

### <a name="parameters"></a>parâmetros

*pbUserMode*<br/>
fora O endereço de uma variável para receber o valor atual desta propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="put_allowcontextmenu"></a>IAxWinAmbientDispatch::p ut_AllowContextMenu

A propriedade `AllowContextMenu` especifica se o controle hospedado tem permissão para exibir seu próprio menu de contexto.

```
STDMETHOD(put_AllowContextMenu)(VARIANT_BOOL bAllowContextMenu);
```

### <a name="parameters"></a>parâmetros

*bAllowContextMenu*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="put_allowshowui"></a>IAxWinAmbientDispatch::p ut_AllowShowUI

A propriedade `AllowShowUI` especifica se o controle hospedado tem permissão para exibir sua própria interface do usuário.

```
STDMETHOD(put_AllowShowUI)(VARIANT_BOOL bAllowShowUI);
```

### <a name="parameters"></a>parâmetros

*bAllowShowUI*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_FALSE como o valor padrão dessa propriedade.

##  <a name="put_allowwindowlessactivation"></a>IAxWinAmbientDispatch::p ut_AllowWindowlessActivation

A propriedade `AllowWindowlessActivation` especifica se o contêiner permitirá a ativação sem janela.

```
STDMETHOD(put_AllowWindowlessActivation)(VARIANT_BOOL bAllowWindowless);
```

### <a name="parameters"></a>parâmetros

*bAllowWindowless*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="put_backcolor"></a>IAxWinAmbientDispatch::p ut_BackColor

A propriedade `BackColor` especifica a cor do plano de fundo ambiente do contêiner.

```
STDMETHOD(put_BackColor)(OLE_COLOR clrBackground);
```

### <a name="parameters"></a>parâmetros

*clrBackground*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa COLOR_BTNFACE ou COLOR_WINDOW como o valor padrão dessa propriedade (dependendo se o pai da janela do host é uma caixa de diálogo ou não).

##  <a name="put_displayasdefault"></a>IAxWinAmbientDispatch::p ut_DisplayAsDefault

`DisplayAsDefault` é uma propriedade de ambiente que permite que um controle descubra se ele é o controle padrão.

```
STDMETHOD(put_DisplayAsDefault)(VARIANT_BOOL bDisplayAsDefault);
```

### <a name="parameters"></a>parâmetros

*bDisplayAsDefault*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_FALSE como o valor padrão dessa propriedade.

##  <a name="put_dochostdoubleclickflags"></a>IAxWinAmbientDispatch::p ut_DocHostDoubleClickFlags

A propriedade `DocHostDoubleClickFlags` especifica a operação que deve ocorrer em resposta a um clique duplo.

```
STDMETHOD(put_DocHostDoubleClickFlags)(DWORD dwDocHostDoubleClickFlags);
```

### <a name="parameters"></a>parâmetros

*dwDocHostDoubleClickFlags*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa DOCHOSTUIDBLCLK_DEFAULT como o valor padrão dessa propriedade.

##  <a name="put_dochostflags"></a>IAxWinAmbientDispatch::p ut_DocHostFlags

A propriedade `DocHostFlags` especifica os recursos de interface do usuário do objeto de host.

```
STDMETHOD(put_DocHostFlags)(DWORD dwDocHostFlags);
```

### <a name="parameters"></a>parâmetros

*dwDocHostFlags*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa DOCHOSTUIFLAG_NO3DBORDER como o valor padrão dessa propriedade.

##  <a name="put_font"></a>IAxWinAmbientDispatch::p ut_Font

A propriedade `Font` especifica a fonte de ambiente do contêiner.

```
STDMETHOD(put_Font)(IFontDisp* pFont);
```

### <a name="parameters"></a>parâmetros

*pFont*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa a fonte GUI padrão ou a fonte do sistema como o valor padrão dessa propriedade.

##  <a name="put_forecolor"></a>IAxWinAmbientDispatch::p ut_ForeColor

A propriedade `ForeColor` especifica a cor de primeiro plano de ambiente do contêiner.

```
STDMETHOD(put_ForeColor)(OLE_COLOR clrForeground);
```

### <a name="parameters"></a>parâmetros

*clrForeground*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa a cor de texto da janela do sistema como o valor padrão dessa propriedade.

##  <a name="put_localeid"></a>IAxWinAmbientDispatch::p ut_LocaleID

A propriedade `LocaleID` especifica a ID de localidade ambiente do contêiner.

```
STDMETHOD(put_LocaleID)(LCID lcidLocaleID);
```

### <a name="parameters"></a>parâmetros

*lcidLocaleID*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa a localidade padrão do usuário como o valor padrão dessa propriedade.

##  <a name="put_messagereflect"></a>IAxWinAmbientDispatch::p ut_MessageReflect

A propriedade de ambiente `MessageReflect` especifica se o contêiner refletirá as mensagens para o controle hospedado.

```
STDMETHOD(put_MessageReflect)(VARIANT_BOOL bMessageReflect);
```

### <a name="parameters"></a>parâmetros

*bMessageReflect*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="put_optionkeypath"></a>IAxWinAmbientDispatch::p ut_OptionKeyPath

A propriedade `OptionKeyPath` especifica o caminho da chave do registro para as configurações do usuário.

```
STDMETHOD(put_OptionKeyPath)(BSTR bstrOptionKeyPath);
```

### <a name="parameters"></a>parâmetros

*bstrOptionKeyPath*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

##  <a name="put_usermode"></a>IAxWinAmbientDispatch::p ut_UserMode

A propriedade `UserMode` especifica o modo de usuário ambiente do contêiner.

```
STDMETHOD(put_UserMode)(VARIANT_BOOL bUserMode);
```

### <a name="parameters"></a>parâmetros

*bUserMode*<br/>
no O novo valor dessa propriedade.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

A implementação do objeto de host ATL usa VARIANT_TRUE como o valor padrão dessa propriedade.

##  <a name="setambientdispatch"></a>IAxWinAmbientDispatchEx::SetAmbientDispatch

Esse método é chamado para complementar a interface de propriedade de ambiente padrão com uma interface definida pelo usuário.

```
virtual HRESULT STDMETHODCALLTYPE SetAmbientDispatch(IDispatch* pDispatch) = 0;
```

### <a name="parameters"></a>parâmetros

*pDispatch*<br/>
Ponteiro para a nova interface.

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

### <a name="remarks"></a>Comentários

Quando `SetAmbientDispatch` é chamado com um ponteiro para uma nova interface, essa nova interface será usada para invocar quaisquer propriedades ou métodos solicitados pelo controle hospedado — se essas propriedades ainda não forem fornecidas pelo [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md).

##  <a name="attachcontrol"></a>IAxWinHostWindow::AttachControl

Anexa um controle existente (e inicializado anteriormente) ao objeto de host usando a janela identificada por *HWND*.

```
STDMETHOD(AttachControl)(IUnknown* pUnkControl, HWND hWnd);
```

### <a name="parameters"></a>parâmetros

*pUnkControl*<br/>
no Um ponteiro para a interface de `IUnknown` do controle a ser anexado ao objeto de host.

*hWnd*<br/>
no Um identificador para a janela a ser usada para hospedagem.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

##  <a name="createcontrol"></a>IAxWinHostWindow:: CreateControl

Cria um controle, inicializa-o e o hospeda na janela identificada por *HWND*.

```
STDMETHOD(CreateControl)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream);
```

### <a name="parameters"></a>parâmetros

*lpTricsData*<br/>
no Uma cadeia de caracteres que identifica o controle a ser criado. Pode ser um CLSID (deve incluir chaves), ProgID, URL ou HTML bruto (prefixado por **Mshtml:** ).

*hWnd*<br/>
no Um identificador para a janela a ser usada para hospedagem.

*pStream*<br/>
no Um ponteiro de interface para um fluxo que contém dados de inicialização para o controle. Pode ser NULL.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Essa janela será subclasseda pelo objeto de host expondo essa interface para que as mensagens possam ser refletidas no controle e outros recursos do contêiner funcionarão.

Chamar esse método é equivalente a chamar [IAxWinHostWindow:: CreateControlEx](#createcontrolex).

Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic:: CreateControlLic](#createcontrollicex).

##  <a name="createcontrolex"></a>IAxWinHostWindow::CreateControlEx

Cria um controle ActiveX, inicializa-o e o hospeda na janela especificada, semelhante a [IAxWinHostWindow:: CreateControl](#createcontrol).

```
STDMETHOD(CreateControlEx)(
    LPCOLESTR lpszTricsData,
    HWND hWnd,
    IStream* pStream,
    IUnknown** ppUnk,
    REFIID riidAdvise,
    IUnknown* punkAdvise);
```

### <a name="parameters"></a>parâmetros

*lpTricsData*<br/>
no Uma cadeia de caracteres que identifica o controle a ser criado. Pode ser um CLSID (deve incluir chaves), ProgID, URL ou HTML bruto (prefixado com **Mshtml:** ).

*hWnd*<br/>
no Um identificador para a janela a ser usada para hospedagem.

*pStream*<br/>
no Um ponteiro de interface para um fluxo que contém dados de inicialização para o controle. Pode ser NULL.

*ppUnk*<br/>
fora O endereço de um ponteiro que receberá a interface de `IUnknown` do controle criado. Pode ser NULL.

*riidAdvise*<br/>
no O identificador de interface de uma interface de saída no objeto contido. Pode ser IID_NULL.

*punkAdvise*<br/>
no Um ponteiro para a interface de `IUnknown` do objeto de coletor a ser conectado ao ponto de conexão no objeto contido especificado por `iidSink`.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Ao contrário do método `CreateControl`, `CreateControlEx` também permite que você receba um ponteiro de interface para o controle recém-criado e configure um coletor de eventos para receber eventos acionados pelo controle.

Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic:: CreateControlLicEx](#createcontrollicex).

##  <a name="querycontrol"></a>IAxWinHostWindow::QueryControl

Retorna o ponteiro de interface especificado fornecido pelo controle hospedado.

```
STDMETHOD(QueryControl)(REFIID riid, void** ppvObject);
```

### <a name="parameters"></a>parâmetros

*riid*<br/>
no A ID de uma interface no controle que está sendo solicitado.

*ppvObject*<br/>
fora O endereço de um ponteiro que receberá a interface especificada do controle criado.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

##  <a name="setexternaldispatch"></a>IAxWinHostWindow::SetExternalDispatch

Define o dispinterface externo, que está disponível para controles contidos por meio do método [IDocHostUIHandlerDispatch:: GetExternal](../../atl/reference/idochostuihandlerdispatch-interface.md) .

```
STDMETHOD(SetExternalDispatch)(IDispatch* pDisp);
```

### <a name="parameters"></a>parâmetros

*pDisp*<br/>
no Um ponteiro para uma interface `IDispatch`.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

##  <a name="setexternaluihandler"></a>IAxWinHostWindow::SetExternalUIHandler

Chame essa função para definir a interface [IDocHostUIHandlerDispatch](../../atl/reference/idochostuihandlerdispatch-interface.md) externa para o objeto `CAxWindow`.

```
STDMETHOD(SetExternalUIHandler)(IDocHostUIHandlerDispatch* pDisp);
```

### <a name="parameters"></a>parâmetros

*pDisp*<br/>
no Um ponteiro para uma interface `IDocHostUIHandlerDispatch`.

### <a name="return-value"></a>Valor retornado

Um valor HRESULT padrão.

### <a name="remarks"></a>Comentários

Essa função é usada por controles (como o controle de navegador da Web) que consultam o site do host para a interface de `IDocHostUIHandlerDispatch`.

##  <a name="createcontrollic"></a>IAxWinHostWindowLic::CreateControlLic

Cria um controle licenciado, inicializa-o e o hospeda na janela identificada por `hWnd`.

```
STDMETHOD(CreateControlLic)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream,
    BSTR bstrLic);
```

### <a name="parameters"></a>parâmetros

*bstrLic*<br/>
no O BSTR que contém a chave de licença para o controle.

### <a name="remarks"></a>Comentários

Consulte [IAxWinHostWindow:: CreateControl](#createcontrol) para obter uma descrição dos parâmetros e do valor de retorno restantes.

Chamar esse método é equivalente a chamar [IAxWinHostWindowLic:: CreateControlLicEx](#createcontrollicex)

### <a name="example"></a>Exemplo

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `IAxWinHostWindowLic::CreateControlLic`.

##  <a name="createcontrollicex"></a>IAxWinHostWindowLic::CreateControlLicEx

Cria um controle ActiveX licenciado, inicializa-o e o hospeda na janela especificada, semelhante a [IAxWinHostWindow:: CreateControl](#createcontrol).

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

### <a name="parameters"></a>parâmetros

*bstrLic*<br/>
no O BSTR que contém a chave de licença para o controle.

### <a name="remarks"></a>Comentários

Consulte [IAxWinHostWindow:: CreateControlEx](#createcontrolex) para obter uma descrição dos parâmetros e do valor de retorno restantes.

### <a name="example"></a>Exemplo

Consulte [hospedando controles ActiveX usando o ATL AxHost](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `IAxWinHostWindowLic::CreateControlLicEx`.

## <a name="see-also"></a>Confira também

[Visão geral da classe](../../atl/atl-class-overview.md)
