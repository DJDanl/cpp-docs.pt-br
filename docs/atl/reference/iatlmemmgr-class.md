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
ms.openlocfilehash: 35cc685c06eaa3992ec8444cfc5d99f2191145a0
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32366202"
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
|[Alocar](#allocate)|Chame esse método para alocar um bloco de memória.|  
|[Livre](#free)|Chame este método para liberar um bloco de memória.|  
|[GetSize](#getsize)|Chame esse método para recuperar o tamanho de um bloco de memória alocada.|  
|[Realocar](#reallocate)|Chame este método para realocar um bloco de memória.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface é implementada por [CComHeap](../../atl/reference/ccomheap-class.md), [CCRTHeap](../../atl/reference/ccrtheap-class.md), [CLocalHeap](../../atl/reference/clocalheap-class.md), [CGlobalHeap](../../atl/reference/cglobalheap-class.md), ou [CWin32Heap](../../atl/reference/cwin32heap-class.md).  
  
> [!NOTE]
>  As funções de heap local e global mais lentas do que outras funções de gerenciamento de memória e não fornecem como muitos recursos. Portanto, os novos aplicativos devem usar o [heap funções](http://msdn.microsoft.com/library/windows/desktop/aa366711). Eles estão disponíveis no [CWin32Heap](../../atl/reference/cwin32heap-class.md) classe.  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_Utilities#94](../../atl/codesnippet/cpp/iatlmemmgr-class_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlmem.h  
  
##  <a name="allocate"></a>  IAtlMemMgr::Allocate  
 Chame esse método para alocar um bloco de memória.  
  
```
void* Allocate(size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `nBytes`  
 O número solicitado de bytes no novo bloco de memória.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o início do bloco de memória alocadas recentemente.  
  
### <a name="remarks"></a>Comentários  
 Chamar [IAtlMemMgr::Free](#free) ou [IAtlMemMgr::Reallocate](#reallocate) para liberar a memória alocada por esse método.  
  
### <a name="example"></a>Exemplo  
 Para obter um exemplo, consulte o [visão geral de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
##  <a name="free"></a>  IAtlMemMgr::Free  
 Chame este método para liberar um bloco de memória.  
  
```
void Free(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para a memória alocada anteriormente por este Gerenciador de memória.  
  
### <a name="remarks"></a>Comentários  
 Use esse método para liberar memória obtida por [IAtlMemMgr::Allocate](#allocate) ou [IAtlMemMgr::Reallocate](#reallocate).  
  
### <a name="example"></a>Exemplo  
 Para obter um exemplo, consulte o [visão geral de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
##  <a name="getsize"></a>  IAtlMemMgr::GetSize  
 Chame esse método para recuperar o tamanho de um bloco de memória alocada.  
  
```
size_t GetSize(void* p) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para a memória alocada anteriormente por este Gerenciador de memória.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna o tamanho do bloco de memória em bytes.  
  
### <a name="example"></a>Exemplo  
 Para obter um exemplo, consulte o [visão geral de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
##  <a name="reallocate"></a>  IAtlMemMgr::Reallocate  
 Chame este método para realocar a memória alocada por esse gerenciador de memória.  
  
```
void* Reallocate(void* p, size_t nBytes) throw();
```  
  
### <a name="parameters"></a>Parâmetros  
 `p`  
 Ponteiro para a memória alocada anteriormente por este Gerenciador de memória.  
  
 `nBytes`  
 O número solicitado de bytes no novo bloco de memória.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o início do bloco de memória alocadas recentemente.  
  
### <a name="remarks"></a>Comentários  
 Chamar [IAtlMemMgr::Free](#free) ou [IAtlMemMgr::Reallocate](#reallocate) para liberar a memória alocada por esse método.  
  
 Conceitualmente, esse método libera a memória existente e aloca um novo bloco de memória. Na realidade, a memória existente pode ser estendida ou reutilizada caso contrário.  
  
### <a name="example"></a>Exemplo  
 Para obter um exemplo, consulte o [visão geral de IAtlMemMgr](../../atl/reference/iatlmemmgr-class.md).  
  
##  <a name="get_allowcontextmenu"></a>  IAxWinAmbientDispatch::get_AllowContextMenu  
 O **AllowContextMenu** propriedade especifica se o controle hospedado tem permissão para exibir seu próprio menu de contexto.  
  
```
STDMETHOD(get_AllowContextMenu)(VARIANT_BOOL* pbAllowContextMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbAllowContextMenu*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto de host ATL usa `VARIANT_TRUE` como o valor padrão dessa propriedade.  
  
##  <a name="get_allowshowui"></a>  IAxWinAmbientDispatch::get_AllowShowUI  
 O **AllowShowUI** propriedade especifica se o controle hospedado tem permissão para exibir sua própria interface do usuário.  
  
```
STDMETHOD(get_AllowShowUI)(VARIANT_BOOL* pbAllowShowUI);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbAllowShowUI*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Usa a implementação do objeto de host ATL **VARIANT_FALSE** como o valor padrão dessa propriedade.  
  
##  <a name="get_allowwindowlessactivation"></a>  IAxWinAmbientDispatch::get_AllowWindowlessActivation  
 O **AllowWindowlessActivation** propriedade especifica se o contêiner permite a ativação sem janelas.  
  
```
STDMETHOD(get_AllowWindowlessActivation)(VARIANT_BOOL* pbAllowWindowless);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbAllowWindowless*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto de host ATL usa `VARIANT_TRUE` como o valor padrão dessa propriedade.  
  
##  <a name="get_backcolor"></a>  IAxWinAmbientDispatch::get_BackColor  
 O `BackColor` propriedade especifica a cor de plano de fundo de ambiente do contêiner.  
  
```
STDMETHOD(get_BackColor)(OLE_COLOR* pclrBackground);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pclrBackground*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Usa a implementação do objeto de host ATL **COLOR_BTNFACE** ou **COLOR_WINDOW** como o valor padrão dessa propriedade (dependendo se o pai da janela do host é uma caixa de diálogo ou não).  
  
##  <a name="get_displayasdefault"></a>  IAxWinAmbientDispatch::get_DisplayAsDefault  
 **Exibircomopadrão** é uma propriedade de ambiente que permite um controle para saber se ele é o padrão de controle.  
  
```
STDMETHOD(get_DisplayAsDefault)(VARIANT_BOOL* pbDisplayAsDefault);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbDisplayAsDefault*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Usa a implementação do objeto de host ATL **VARIANT_FALSE** como o valor padrão dessa propriedade.  
  
##  <a name="get_dochostdoubleclickflags"></a>  IAxWinAmbientDispatch::get_DocHostDoubleClickFlags  
 O **DocHostDoubleClickFlags** propriedade especifica a operação que deve ocorrer em resposta a um clique duplo.  
  
```
STDMETHOD(get_DocHostDoubleClickFlags)(DWORD* pdwDocHostDoubleClickFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pdwDocHostDoubleClickFlags*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Usa a implementação do objeto de host ATL **DOCHOSTUIDBLCLK_DEFAULT** como o valor padrão dessa propriedade.  
  
##  <a name="get_dochostflags"></a>  IAxWinAmbientDispatch::get_DocHostFlags  
 O **DocHostFlags** propriedade especifica os recursos de interface de usuário do objeto de host.  
  
```
STDMETHOD(get_DocHostFlags)(DWORD* pdwDocHostFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pdwDocHostFlags*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Usa a implementação do objeto de host ATL **DOCHOSTUIFLAG_NO3DBORDER** como o valor padrão dessa propriedade.  
  
##  <a name="get_font"></a>  IAxWinAmbientDispatch::get_Font  
 O **fonte** propriedade especifica a fonte de ambiente do contêiner.  
  
```
STDMETHOD(get_Font)(IFontDisp** pFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFont`  
 [out] O endereço de um **IFontDisp** ponteiro da interface usado para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto ATL host usa a fonte de GUI padrão ou a fonte do sistema como o valor padrão dessa propriedade.  
  
##  <a name="get_forecolor"></a>  IAxWinAmbientDispatch::get_ForeColor  
 O `ForeColor` propriedade especifica a cor de primeiro plano de ambiente do contêiner.  
  
```
STDMETHOD(get_ForeColor)(OLE_COLOR* pclrForeground);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pclrForeground*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto ATL host usa a cor de texto da janela de sistema como o valor padrão dessa propriedade.  
  
##  <a name="get_localeid"></a>  IAxWinAmbientDispatch::get_LocaleID  
 O **LocaleID** propriedade especifica a ID de localidade do ambiente do contêiner.  
  
```
STDMETHOD(get_LocaleID)(LCID* plcidLocaleID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *plcidLocaleID*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto ATL host usa a localidade do usuário padrão como o valor padrão dessa propriedade.  
  
 Com esse método, você pode descobrir o ambiente LocalID, ou seja, o LocaleID do programa de seu controle está sendo usado no. Quando você souber o LocaleID, você pode chamar código para carregar legendas específicas da localidade, texto de mensagem de erro, e assim por diante de um arquivo de recurso ou uma DLL satélite.  
  
##  <a name="get_messagereflect"></a>  IAxWinAmbientDispatch::get_MessageReflect  
 O **MessageReflect** propriedade de ambiente que especifica se o contêiner refletirá as mensagens para o controle hospedado.  
  
```
STDMETHOD(get_MessageReflect)(VARIANT_BOOL* pbMessageReflect);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbMessageReflect*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto de host ATL usa `VARIANT_TRUE` como o valor padrão dessa propriedade.  
  
##  <a name="get_optionkeypath"></a>  IAxWinAmbientDispatch::get_OptionKeyPath  
 O **OptionKeyPath** propriedade especifica o caminho da chave do registro para as configurações do usuário.  
  
```
STDMETHOD(get_OptionKeyPath)(BSTR* pbstrOptionKeyPath);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbstrOptionKeyPath*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="get_showgrabhandles"></a>  IAxWinAmbientDispatch::get_ShowGrabHandles  
 O **ShowGrabHandles** propriedade de ambiente permite que o controle descobrir se ele deve ser desenhado em si com identificadores de captura.  
  
```
STDMETHOD(get_ShowGrabHandles)(VARIANT_BOOL* pbShowGrabHandles);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbShowGrabHandles*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação de objeto de host do ATL sempre retorna **VARIANT_FALSE** como o valor dessa propriedade.  
  
##  <a name="get_showhatching"></a>  IAxWinAmbientDispatch::get_ShowHatching  
 O **ShowHatching** propriedade de ambiente permite que o controle descobrir se ele deve ser desenhado em si hatched.  
  
```
STDMETHOD(get_ShowHatching)(VARIANT_BOOL* pbShowHatching);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbShowHatching*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação de objeto de host do ATL sempre retorna **VARIANT_FALSE** como o valor dessa propriedade.  
  
##  <a name="get_usermode"></a>  IAxWinAmbientDispatch::get_UserMode  
 O **UserMode** propriedade especifica o modo de usuário do ambiente do contêiner.  
  
```
STDMETHOD(get_UserMode)(VARIANT_BOOL* pbUserMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 *pbUserMode*  
 [out] O endereço de uma variável para receber o valor atual dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto de host ATL usa `VARIANT_TRUE` como o valor padrão dessa propriedade.  
  
##  <a name="put_allowcontextmenu"></a>  IAxWinAmbientDispatch::put_AllowContextMenu  
 O **AllowContextMenu** propriedade especifica se o controle hospedado tem permissão para exibir seu próprio menu de contexto.  
  
```
STDMETHOD(put_AllowContextMenu)(VARIANT_BOOL bAllowContextMenu);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bAllowContextMenu*  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto de host ATL usa `VARIANT_TRUE` como o valor padrão dessa propriedade.  
  
##  <a name="put_allowshowui"></a>  IAxWinAmbientDispatch::put_AllowShowUI  
 O **AllowShowUI** propriedade especifica se o controle hospedado tem permissão para exibir sua própria interface do usuário.  
  
```
STDMETHOD(put_AllowShowUI)(VARIANT_BOOL bAllowShowUI);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bAllowShowUI*  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Usa a implementação do objeto de host ATL **VARIANT_FALSE** como o valor padrão dessa propriedade.  
  
##  <a name="put_allowwindowlessactivation"></a>  IAxWinAmbientDispatch::put_AllowWindowlessActivation  
 O **AllowWindowlessActivation** propriedade especifica se o contêiner permite a ativação sem janelas.  
  
```
STDMETHOD(put_AllowWindowlessActivation)(VARIANT_BOOL bAllowWindowless);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bAllowWindowless*  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto de host ATL usa `VARIANT_TRUE` como o valor padrão dessa propriedade.  
  
##  <a name="put_backcolor"></a>  IAxWinAmbientDispatch::put_BackColor  
 O `BackColor` propriedade especifica a cor de plano de fundo de ambiente do contêiner.  
  
```
STDMETHOD(put_BackColor)(OLE_COLOR clrBackground);
```  
  
### <a name="parameters"></a>Parâmetros  
 *clrBackground*  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Usa a implementação do objeto de host ATL **COLOR_BTNFACE** ou **COLOR_WINDOW** como o valor padrão dessa propriedade (dependendo se o pai da janela do host é uma caixa de diálogo ou não).  
  
##  <a name="put_displayasdefault"></a>  IAxWinAmbientDispatch::put_DisplayAsDefault  
 **Exibircomopadrão** é uma propriedade de ambiente que permite um controle para saber se ele é o padrão de controle.  
  
```
STDMETHOD(put_DisplayAsDefault)(VARIANT_BOOL bDisplayAsDefault);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bDisplayAsDefault`  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Usa a implementação do objeto de host ATL **VARIANT_FALSE** como o valor padrão dessa propriedade.  
  
##  <a name="put_dochostdoubleclickflags"></a>  IAxWinAmbientDispatch::put_DocHostDoubleClickFlags  
 O **DocHostDoubleClickFlags** propriedade especifica a operação que deve ocorrer em resposta a um clique duplo.  
  
```
STDMETHOD(put_DocHostDoubleClickFlags)(DWORD dwDocHostDoubleClickFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwDocHostDoubleClickFlags*  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Usa a implementação do objeto de host ATL **DOCHOSTUIDBLCLK_DEFAULT** como o valor padrão dessa propriedade.  
  
##  <a name="put_dochostflags"></a>  IAxWinAmbientDispatch::put_DocHostFlags  
 O **DocHostFlags** propriedade especifica os recursos de interface de usuário do objeto de host.  
  
```
STDMETHOD(put_DocHostFlags)(DWORD dwDocHostFlags);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwDocHostFlags*  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 Usa a implementação do objeto de host ATL **DOCHOSTUIFLAG_NO3DBORDER** como o valor padrão dessa propriedade.  
  
##  <a name="put_font"></a>  IAxWinAmbientDispatch::put_Font  
 O **fonte** propriedade especifica a fonte de ambiente do contêiner.  
  
```
STDMETHOD(put_Font)(IFontDisp* pFont);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pFont`  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto ATL host usa a fonte de GUI padrão ou a fonte do sistema como o valor padrão dessa propriedade.  
  
##  <a name="put_forecolor"></a>  IAxWinAmbientDispatch::put_ForeColor  
 O `ForeColor` propriedade especifica a cor de primeiro plano de ambiente do contêiner.  
  
```
STDMETHOD(put_ForeColor)(OLE_COLOR clrForeground);
```  
  
### <a name="parameters"></a>Parâmetros  
 *clrForeground*  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto ATL host usa a cor de texto da janela de sistema como o valor padrão dessa propriedade.  
  
##  <a name="put_localeid"></a>  IAxWinAmbientDispatch::put_LocaleID  
 O **LocaleID** propriedade especifica a ID de localidade do ambiente do contêiner.  
  
```
STDMETHOD(put_LocaleID)(LCID lcidLocaleID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *lcidLocaleID*  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto ATL host usa a localidade do usuário padrão como o valor padrão dessa propriedade.  
  
##  <a name="put_messagereflect"></a>  IAxWinAmbientDispatch::put_MessageReflect  
 O **MessageReflect** propriedade de ambiente que especifica se o contêiner refletirá as mensagens para o controle hospedado.  
  
```
STDMETHOD(put_MessageReflect)(VARIANT_BOOL bMessageReflect);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bMessageReflect`  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto de host ATL usa `VARIANT_TRUE` como o valor padrão dessa propriedade.  
  
##  <a name="put_optionkeypath"></a>  IAxWinAmbientDispatch::put_OptionKeyPath  
 O **OptionKeyPath** propriedade especifica o caminho da chave do registro para as configurações do usuário.  
  
```
STDMETHOD(put_OptionKeyPath)(BSTR bstrOptionKeyPath);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bstrOptionKeyPath*  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="put_usermode"></a>  IAxWinAmbientDispatch::put_UserMode  
 O **UserMode** propriedade especifica o modo de usuário do ambiente do contêiner.  
  
```
STDMETHOD(put_UserMode)(VARIANT_BOOL bUserMode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bUserMode`  
 [in] O novo valor dessa propriedade.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
### <a name="remarks"></a>Comentários  
 A implementação do objeto de host ATL usa `VARIANT_TRUE` como o valor padrão dessa propriedade.  
  
##  <a name="setambientdispatch"></a>  IAxWinAmbientDispatchEx::SetAmbientDispatch  
 Esse método é chamado para complementar a interface de propriedade de ambiente padrão com uma interface definida pelo usuário.  
  
```
virtual HRESULT STDMETHODCALLTYPE SetAmbientDispatch(IDispatch* pDispatch) = 0;
```  
  
### <a name="parameters"></a>Parâmetros  
 *pDispatch*  
 Ponteiro para a nova interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Quando `SetAmbientDispatch` é chamado com um ponteiro para uma nova interface, essa nova interface será usado para invocar qualquer propriedades ou métodos solicitados pelo controle hospedado, se essas propriedades já não são fornecidas pela [IAxWinAmbientDispatch](../../atl/reference/iaxwinambientdispatch-interface.md).  
  
##  <a name="attachcontrol"></a>  IAxWinHostWindow::AttachControl  
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
  
##  <a name="createcontrol"></a>  IAxWinHostWindow::CreateControl  
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
  
 Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLic](#createcontrollicex).  
  
##  <a name="createcontrolex"></a>  IAxWinHostWindow::CreateControlEx  
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
  
 Para criar um controle ActiveX licenciado, consulte [IAxWinHostWindowLic::CreateControlLicEx](#createcontrollicex).  
  
##  <a name="querycontrol"></a>  IAxWinHostWindow::QueryControl  
 Retorna o ponteiro de interface especificado fornecido pelo controle hospedado.  
  
```
STDMETHOD(QueryControl)(REFIID riid, void** ppvObject);
```  
  
### <a name="parameters"></a>Parâmetros  
 `riid`  
 [in] A ID de uma interface do controle que está sendo solicitado.  
  
 `ppvObject`  
 [out] O endereço de um ponteiro que receberá a interface especificada do controle criado.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="setexternaldispatch"></a>  IAxWinHostWindow::SetExternalDispatch  
 Define a dispinterface externa, que está disponível para controles contidos por meio de [IDocHostUIHandlerDispatch::GetExternal](../../atl/reference/idochostuihandlerdispatch-interface.md) método.  
  
```
STDMETHOD(SetExternalDispatch)(IDispatch* pDisp);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pDisp`  
 [in] Um ponteiro para um `IDispatch` interface.  
  
### <a name="return-value"></a>Valor de retorno  
 Um padrão `HRESULT` valor.  
  
##  <a name="setexternaluihandler"></a>  IAxWinHostWindow::SetExternalUIHandler  
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
  
##  <a name="createcontrollic"></a>  IAxWinHostWindowLic::CreateControlLic  
 Cria um controle licenciado, inicializa e hospeda na janela identificada por `hWnd`.  
  
```
STDMETHOD(CreateControlLic)(
    LPCOLESTR lpTricsData,
    HWND hWnd,
    IStream* pStream,
    BSTR bstrLic);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bstrLic`  
 [in] BSTR que contém a chave de licença para o controle.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IAxWinHostWindow::CreateControl](#createcontrol) para obter uma descrição do valor de retorno e parâmetros restantes.  
  
 Chamar esse método é equivalente a chamar [IAxWinHostWindowLic::CreateControlLicEx](#createcontrollicex)  
  
### <a name="example"></a>Exemplo  
 Consulte [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `IAxWinHostWindowLic::CreateControlLic`.  
  
##  <a name="createcontrollicex"></a>  IAxWinHostWindowLic::CreateControlLicEx  
 Cria um controle ActiveX licenciado, inicializa e hospeda na janela especificada, semelhante ao [IAxWinHostWindow::CreateControl](#createcontrol).  
  
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
 `bstrLic`  
 [in] BSTR que contém a chave de licença para o controle.  
  
### <a name="remarks"></a>Comentários  
 Consulte [IAxWinHostWindow::CreateControlEx](#createcontrolex) para obter uma descrição do valor de retorno e parâmetros restantes.  
  
### <a name="example"></a>Exemplo  
 Consulte [hospedagem de AXHost de ATL usando do ActiveX controles](../../atl/hosting-activex-controls-using-atl-axhost.md) para obter um exemplo que usa `IAxWinHostWindowLic::CreateControlLicEx`.  
  
## <a name="see-also"></a>Consulte também  
 [Visão geral da classe](../../atl/atl-class-overview.md)
