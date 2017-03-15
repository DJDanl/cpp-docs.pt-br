---
title: Classe CLinkCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CLinkCtrl
dev_langs:
- C++
helpviewer_keywords:
- CLinkCtrl class
- Web pages, link control
- controls [MFC], links
- links [C++], link control
- SysLink control
ms.assetid: d1cd876a-ecca-42db-8ac4-9cd327df0cd4
caps.latest.revision: 23
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
ms.openlocfilehash: 710fef79306c906e13e99beac15401835422ecbe
ms.lasthandoff: 02/25/2017

---
# <a name="clinkctrl-class"></a>Classe CLinkCtrl
Fornece a funcionalidade do controle de SysLink comuns do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CLinkCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CLinkCtrl::CLinkCtrl](#clinkctrl)|Constrói um objeto `CLinkCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CLinkCtrl::Create](#create)|Cria um controle de link e anexa a um `CLinkCtrl` objeto.|  
|[CLinkCtrl::CreateEx](#createex)|Cria um controle de link com estilos estendidos e anexa-o para um `CLinkCtrl` objeto.|  
|[CLinkCtrl::GetIdealHeight](#getidealheight)|Recupera a altura ideal do controle de link.|  
|[CLinkCtrl::GetIdealSize](#getidealsize)|Calcula a altura preferencial do texto do link para o controle atual do link, dependendo da largura especificada do link.|  
|[CLinkCtrl::GetItem](#getitem)|Recupera os estados e os atributos de um item de controle de link.|  
|[CLinkCtrl::GetItemID](#getitemid)|Recupera a ID de um item de controle de link.|  
|[CLinkCtrl::GetItemState](#getitemstate)|Recupera o estado do item de controle de link.|  
|[CLinkCtrl::GetItemUrl](#getitemurl)|Recupera a URL representada pelo item de controle de link.|  
|[CLinkCtrl::HitTest](#hittest)|Determina se o usuário clicou no link especificado.|  
|[CLinkCtrl::SetItem](#setitem)|Define os estados e os atributos de um item de controle de link.|  
|[CLinkCtrl::SetItemID](#setitemid)|Define a ID de um item de controle de link.|  
|[CLinkCtrl::SetItemState](#setitemstate)|Define o estado do item de controle de link.|  
|[CLinkCtrl::SetItemUrl](#setitemurl)|Define a URL representada pelo item de controle de link.|  
  
## <a name="remarks"></a>Comentários  
 "Controle de link" fornece uma forma cômoda de incorporar links de hipertexto em uma janela. O controle real é uma janela que processa o texto marcado e inicia os aplicativos apropriados quando o usuário clica em um link incorporado. Vários links têm suporte dentro de um controle e podem ser acessados por um índice baseado em zero.  
  
 Esse controle (e, portanto, a `CLinkCtrl` classe) está disponível apenas para programas em execução no Windows XP e versões posteriores.  
  
 Para obter mais informações, consulte [SysLink controle](http://msdn.microsoft.com/library/windows/desktop/bb760706) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CLinkCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="a-nameclinkctrla--clinkctrlclinkctrl"></a><a name="clinkctrl"></a>CLinkCtrl::CLinkCtrl  
 Constrói um objeto `CLinkCtrl`.  
  
```  
CLinkCtrl();
```  
  
##  <a name="a-namecreatea--clinkctrlcreate"></a><a name="create"></a>CLinkCtrl::Create  
 Cria um controle de link e anexa a um `CLinkCtrl` objeto.  
  
```  
virtual BOOL Create(
    LPCTSTR lpszLinkMarkup,   
    DWORD dwStyle,   
    const RECT& rect,   
    CWnd* pParentWnd,   
    UINT nID);

 
virtual BOOL Create(DWORD dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszLinkMarkup`  
 Ponteiro para uma cadeia de caracteres terminada em zero que contém a área marcada, o texto a ser exibido. Para obter mais informações, consulte a seção "Acesso de marcação e Link" no tópico [visão geral de controles SysLink](http://msdn.microsoft.com/library/windows/desktop/bb760706) no [biblioteca MSDN](http://go.microsoft.com/fwlink/linkid=556).  
  
 `dwStyle`  
 Especifica o estilo do controle de link. Aplique qualquer combinação de estilos de controle. Consulte [estilos de controle comum](http://msdn.microsoft.com/library/windows/desktop/bb775498) no `Windows SDK` para obter mais informações.  
  
 `rect`  
 Especifica o tamanho e a posição do controle de link. Ele pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [RECT](../../mfc/reference/rect-structure1.md) estrutura.  
  
 `pParentWnd`  
 Especifica a janela pai do controle de link. Ele não deve ser `NULL`.  
  
 `nID`  
 Especifica a identificação. do controle do link  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se a inicialização foi bem sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CLinkCtrl` objeto em duas etapas. Primeiro, chame o construtor e, em seguida, chame `Create`, que cria o controle de link e anexa-o para o `CLinkCtrl` objeto. Se você quiser usar estilos estendidos do windows com o controle, chame [CLinkCtrl::CreateEx](#createex) em vez de `Create`.  
  
 A segunda forma do `Create` método está obsoleto. Usar o primeiro formulário que especifica o `lpszLinkMarkup` parâmetro.  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir define duas variáveis, chamadas `m_Link1` e `m_Link2`, que são usadas para acessar dois controles de link.  
  
 [!code-cpp[NVC_MFC_CLinkCtrl_s1 n º&2;](../../mfc/reference/codesnippet/cpp/clinkctrl-class_1.h)]  
  
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir cria um controle de link com base na localização de outro controle do link. O carregador de recursos cria o primeiro controle de link quando seu aplicativo for iniciado. Quando seu aplicativo indica o método OnInitDialog, você pode criar o segundo controle de link em relação à posição do primeiro controle de link. Em seguida, você redimensionar o segundo controle de link para ajustar o texto que ele exibe.  
  
 [!code-cpp[NVC_MFC_CLinkCtrl_s1 n º&1;](../../mfc/reference/codesnippet/cpp/clinkctrl-class_2.cpp)]  
  
##  <a name="a-namecreateexa--clinkctrlcreateex"></a><a name="createex"></a>CLinkCtrl::CreateEx  
 Cria um controle de link com estilos estendidos e anexa-o para um `CLinkCtrl` objeto.  
  
```  
virtual BOOL CreateEx(
    LPCTSTR lpszLinkMarkup,   
    DWORD dwExStyle,  
    DWORD dwStyle,   
    const RECT& rect,   
    CWnd* pParentWnd,   
    UINT nID);

 
virtual BOOL CreateEx(DWORD  dwExStyle,
    DWORD  dwStyle,
    const RECT& rect,
    CWnd* pParentWnd,
    UINT  nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszLinkMarkup`  
 Ponteiro para uma cadeia de caracteres terminada em zero que contém a área marcada, o texto a ser exibido. Para obter mais informações, consulte a seção "Acesso de marcação e Link" no tópico [visão geral de controles SysLink](http://msdn.microsoft.com/library/windows/desktop/bb760706) no [biblioteca MSDN](http://go.microsoft.com/fwlink/linkid=556).  
  
 `dwExStyle`  
 Especifica o estilo estendido do controle de link. Para obter uma lista dos estilos estendidos do Windows, consulte o `dwExStyle` parâmetro [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwStyle`  
 Especifica o estilo do controle de link. Aplique qualquer combinação de estilos de controle. Para obter mais informações, consulte [estilos de controle comum](http://msdn.microsoft.com/library/windows/desktop/bb775498) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `rect`  
 Especifica o tamanho e a posição do controle de link. Ele pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [RECT](../../mfc/reference/rect-structure1.md) estrutura.  
  
 `pParentWnd`  
 Especifica a janela pai do controle de link. Ele não deve ser `NULL`.  
  
 `nID`  
 Especifica a identificação. do controle do link  
  
### <a name="return-value"></a>Valor de retorno  
 `true`Se a inicialização foi bem sucedida; Caso contrário, `false`.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de [criar](#create) aplicar constantes de estilo estendidos do Windows.  
  
 A segunda forma do `CreateEx` método está obsoleto. Usar o primeiro formulário que especifica o `lpszLinkMarkup` parâmetro.  
  
##  <a name="a-namegetidealheighta--clinkctrlgetidealheight"></a><a name="getidealheight"></a>CLinkCtrl::GetIdealHeight  
 Recupera a altura ideal do controle de link.  
  
```  
int GetIdealHeight() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 A altura ideal do controle, em pixels.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [LM_GETIDEALHEIGHT](http://msdn.microsoft.com/library/windows/desktop/bb760716), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetidealsizea--clinkctrlgetidealsize"></a><a name="getidealsize"></a>CLinkCtrl::GetIdealSize  
 Calcula a altura preferencial do texto do link para o controle atual do link, dependendo da largura especificada do link.  
  
```  
int GetIdealSize(
    int cxMaxWidth,   
    SIZE* pSize) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] `cxMaxWidth`|A largura máxima da conexão, em pixels.|  
|[out] *`pSize`|Um ponteiro para um Windows [tamanho](http://msdn.microsoft.com/library/windows/desktop/dd145106) estrutura. Quando este método retorna, o `cy` membro o `SIZE` estrutura contém a altura do texto de link ideal para a largura do texto de link que é especificada pelo `cxMaxWidth`. O `cx` membro da estrutura contém a largura do texto de link que é realmente necessária.|  
  
### <a name="return-value"></a>Valor de retorno  
 A altura preferencial do texto do link, em pixels. O valor de retorno é igual ao valor da `cy` membro o `SIZE` estrutura.  
  
### <a name="remarks"></a>Comentários  
 Para obter um exemplo de `GetIdealSize` método, consulte o exemplo na [CLinkCtrl::Create](#create).  
  
 Esse método envia o [LM_GETIDEALSIZE](http://msdn.microsoft.com/library/windows/desktop/bb760718) mensagem, que é descrita o [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetitema--clinkctrlgetitem"></a><a name="getitem"></a>CLinkCtrl::GetItem  
 Recupera os estados e os atributos de um item de controle de link.  
  
```  
BOOL GetItem(PLITEM pItem) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Um ponteiro para um [LITEM](http://msdn.microsoft.com/library/windows/desktop/bb760710) estrutura para receber informações sobre o item.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [LM_GETITEM](http://msdn.microsoft.com/library/windows/desktop/bb760720), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetitemida--clinkctrlgetitemid"></a><a name="getitemid"></a>CLinkCtrl::GetItemID  
 Recupera a ID de um item de controle de link.  
  
```  
BOOL GetItemID(
    int iLink,  
    CString& strID) const;  
  
BOOL GetItemID(
    int iLink,  
    LPWSTR szID,  
    UINT cchID) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `iLink`  
 O índice de um item de controle de link.  
  
 *strID*  
 A [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém a ID do item especificado.  
  
 *szID*  
 Uma cadeia terminada em nulo que contém a ID do item especificado.  
  
 *cchID*  
 O tamanho em caracteres do *szID* buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
> [!NOTE]
>  Essa função também retorna **FALSE** se o buffer de *szID ou strID* é menor do que **MAX_LINKID_TEXT**.  
  
### <a name="remarks"></a>Comentários  
 Recupera a ID de um item de controle de link específico. Para obter mais informações, consulte a mensagem do Win32 [LM_GETITEM](http://msdn.microsoft.com/library/windows/desktop/bb760720) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetitemstatea--clinkctrlgetitemstate"></a><a name="getitemstate"></a>CLinkCtrl::GetItemState  
 Recupera o estado do item de controle de link.  
  
```  
BOOL GetItemState(
    int iLink,  
    UINT* pnState,  
    UINT stateMask = LIS_FOCUSED | LIS_ENABLED | LIS_VISITED) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `iLink`  
 O índice de um item de controle de link.  
  
 `pnState`  
 O valor do item de estado especificado.  
  
 `stateMask`  
 Combinação de sinalizadores que descrevem quais itens de estado para obter. Para obter uma lista de valores, consulte a descrição do **estado** membro o [LITEM](http://msdn.microsoft.com/library/windows/desktop/bb760710) estrutura. Itens permitidos são idênticas àquelas permitidos em **estado**.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Recupera o valor do item especificado do estado de um item de controle de link específico. Para obter mais informações, consulte a mensagem do Win32 [LM_GETITEM](http://msdn.microsoft.com/library/windows/desktop/bb760720) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namegetitemurla--clinkctrlgetitemurl"></a><a name="getitemurl"></a>CLinkCtrl::GetItemUrl  
 Recupera a URL representada pelo item de controle de link.  
  
```  
BOOL GetItemUrl(
    int iLink,  
    CString& strUrl) const;  
  
BOOL GetItemUrl(
    int iLink,  
    LPWSTR szUrl,  
    UINT cchUrl) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 `iLink`  
 O índice de um item de controle de link.  
  
 `strUrl`  
 A [CStringT](../../atl-mfc-shared/reference/cstringt-class.md) objeto que contém a URL representada pelo item especificado  
  
 `szUrl`  
 Uma cadeia de caracteres terminada em nulo que contém a URL representada pelo item especificado  
  
 *cchUrl*  
 O tamanho em caracteres do *szURL* buffer.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
> [!NOTE]
>  Essa função também retorna **FALSE** se o buffer de *szUrl ou strUrl* é menor do que **MAX_LINKID_TEXT**.  
  
### <a name="remarks"></a>Comentários  
 Recupera a URL representada pelo item de controle de link especificado. Para obter mais informações, consulte a mensagem do Win32 [LM_GETITEM](http://msdn.microsoft.com/library/windows/desktop/bb760720) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namehittesta--clinkctrlhittest"></a><a name="hittest"></a>CLinkCtrl::HitTest  
 Determina se o usuário clicou no link especificado.  
  
```  
BOOL HitTest(PLHITTESTINFO phti) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
 *phti*  
 Ponteiro para uma **LHITTESTINFO** estrutura que contém todas as informações sobre o link o usuário clicou.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [LM_HITTEST](http://msdn.microsoft.com/library/windows/desktop/bb760722), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetitema--clinkctrlsetitem"></a><a name="setitem"></a>CLinkCtrl::SetItem  
 Define os estados e os atributos de um item de controle de link.  
  
```  
BOOL SetItem(PLITEM pItem);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pItem`  
 Um ponteiro para um [LITEM](http://msdn.microsoft.com/library/windows/desktop/bb760710) estrutura que contém as informações a serem definidas.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [LM_SETITEM](http://msdn.microsoft.com/library/windows/desktop/bb760724), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetitemida--clinkctrlsetitemid"></a><a name="setitemid"></a>CLinkCtrl::SetItemID  
 Recupera a ID de um item de controle de link.  
  
```  
BOOL SetItemID(
    int iLink,  
    LPCWSTR szID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iLink`  
 O índice de um item de controle de link.  
  
 *szID*  
 Uma cadeia terminada em nulo que contém a ID do item especificado.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Define a ID de um item de controle de link específico. Para obter mais informações, consulte a mensagem do Win32 [LM_SETITEM](http://msdn.microsoft.com/library/windows/desktop/bb760724) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetitemstatea--clinkctrlsetitemstate"></a><a name="setitemstate"></a>CLinkCtrl::SetItemState  
 Recupera o estado do item de controle de link.  
  
```  
BOOL SetItemState(
    int iLink,  
    UINT state,  
    UINT stateMask = LIS_FOCUSED | LIS_ENABLED | LIS_VISITED);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iLink`  
 O índice de um item de controle de link.  
  
 `pnState`  
 O valor do item de estado específico que está sendo definido.  
  
 `stateMask`  
 Combinação de sinalizadores que descrevem o item de estado que está sendo definido. Para obter uma lista de valores, consulte a descrição do **estado** membro o [LITEM](http://msdn.microsoft.com/library/windows/desktop/bb760710) estrutura. Itens permitidos são idênticas àquelas permitidos em **estado**.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Define o valor do item especificado do estado de um item de controle de link específico. Para obter mais informações, consulte a mensagem do Win32 [LM_SETITEM](http://msdn.microsoft.com/library/windows/desktop/bb760724) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="a-namesetitemurla--clinkctrlsetitemurl"></a><a name="setitemurl"></a>CLinkCtrl::SetItemUrl  
 Define a URL representada pelo item de controle de link.  
  
```  
BOOL SetItemUrl(
    int iLink,  
    LPCWSTR szUrl);
```  
  
### <a name="parameters"></a>Parâmetros  
 `iLink`  
 O índice de um item de controle de link.  
  
 `szUrl`  
 Uma cadeia de caracteres terminada em nulo que contém a URL representada pelo item especificado  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna **TRUE** com êxito, **FALSE** em caso de falha.  
  
### <a name="remarks"></a>Comentários  
 Define a URL representada pelo item de controle de link especificado. Para obter mais informações, consulte a mensagem do Win32 [LM_SETITEM](http://msdn.microsoft.com/library/windows/desktop/bb760724) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWnd](../../mfc/reference/cwnd-class.md)

