---
title: Classe CWindowImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CWindowImpl
- ATLWIN/ATL::CWindowImpl
- ATLWIN/ATL::CWindowImpl::Create
- ATLWIN/ATL::DefWindowProc
- ATLWIN/ATL::GetCurrentMessage
- ATLWIN/ATL::GetWindowProc
- ATLWIN/ATL::OnFinalMessage
- ATLWIN/ATL::SubclassWindow
- ATLWIN/ATL::UnsubclassWindow
- ATLWIN/ATL::GetWndClassInfo
- ATLWIN/ATL::WindowProc
- ATLWIN/ATL::m_pfnSuperWindowProc
dev_langs:
- C++
helpviewer_keywords:
- CWindowImpl class
- subclassing windows, ATL
ms.assetid: 02eefd45-a0a6-4d1b-99f6-dbf627e2cc2f
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
ms.sourcegitcommit: 604a4bf49490ad2599c857eb3afd527d67e1e25b
ms.openlocfilehash: 76827682e96d2aea80880fa7d70c267abe02ee1c
ms.lasthandoff: 02/25/2017

---
# <a name="cwindowimpl-class"></a>Classe CWindowImpl
Fornece métodos para criar ou uma janela de subclasses.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados a [!INCLUDE[wrt](../../atl/reference/includes/wrt_md.md)].  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, class TBase = CWindow, class TWinTraits = CControlWinTraits>  
class ATL_NO_VTABLE CWindowImpl : public CWindowImplBaseT<TBase, TWinTraits>
```    
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A nova classe, derivado de `CWindowImpl`.  
  
 *TBase*  
 A classe base de sua classe. Por padrão, a classe base é [CWindow](../../atl/reference/cwindow-class.md).  
  
 `TWinTraits`  
 A [classe de características](../../atl/understanding-window-traits.md) que define estilos para a sua janela. O padrão é `CControlWinTraits`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWindowImpl::Create](#create)|Cria uma janela.|  
  
### <a name="cwindowimplbaset-methods"></a>Métodos de CWindowImplBaseT  
  
|||  
|-|-|  
|[DefWindowProc](#defwindowproc)|Fornece o processamento da mensagem padrão.|  
|[GetCurrentMessage](#getcurrentmessage)|Retorna a mensagem atual.|  
|[GetWindowProc](#getwindowproc)|Retorna o procedimento da janela atual.|  
|[OnFinalMessage](#onfinalmessage)|Chamado após a última mensagem é recebida (geralmente `WM_NCDESTROY`).|  
|[SubclassWindow](#subclasswindow)|Subclasses de uma janela.|  
|[UnsubclassWindow](#unsubclasswindow)|Restaura uma janela subclasse anteriormente.|  
  
### <a name="static-methods"></a>Métodos estáticos  
  
|||  
|-|-|  
|[GetWndClassInfo](#getwndclassinfo)|Retorna uma instância estática de [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md), que gerencia as informações de classe de janela.|  
|[WindowProc](#windowproc)|Processa as mensagens enviadas para a janela.|  
  
### <a name="data-members"></a>Membros de Dados  
  
|||  
|-|-|  
|[m_pfnSuperWindowProc](#m_pfnsuperwindowproc)|Aponta para o procedimento de janela original da classe de janela.|  
  
## <a name="remarks"></a>Comentários  
 Você pode usar `CWindowImpl` para criar uma janela ou uma subclasse de uma janela existente. o `CWindowImpl` procedimento de janela usa um mapa da mensagem para direcionar mensagens para manipuladores adequados.  
  
 `CWindowImpl::Create`cria uma janela com base nas informações de classe de janela que são gerenciadas pelo [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md). `CWindowImpl`contém o [DECLARE_WND_CLASS](http://msdn.microsoft.com/library/55247a72-fb9e-4bde-87f3-747c08076971) macro, o que significa `CWndClassInfo` registra uma nova classe de janela. Se você quiser superclasse uma classe de janela existente, derive sua classe de `CWindowImpl` e incluem o [DECLARE_WND_SUPERCLASS](http://msdn.microsoft.com/library/650337b6-4973-41e5-8c36-55f90327bdcd) macro. Nesse caso, `CWndClassInfo` registra uma classe de janela que se baseia em uma classe existente, mas usa `CWindowImpl::WindowProc`. Por exemplo:  
  
 [!code-cpp[NVC_ATL_Windowing&#43;](../../atl/codesnippet/cpp/cwindowimpl-class_1.h)]  
  
> [!NOTE]
>  Porque `CWndClassInfo` gerencia as informações para apenas uma classe de janela, cada janela criada por meio de uma instância de `CWindowImpl` baseia-se na mesma classe de janela.  
  
 `CWindowImpl`também oferece suporte a criação de classes de janela. O `SubclassWindow` método anexa uma janela existente para o `CWindowImpl` de objeto e altera o procedimento de janela para `CWindowImpl::WindowProc`. Cada instância de `CWindowImpl` pode criar uma subclasse uma janela diferente.  
  
> [!NOTE]
>  Para qualquer dado `CWindowImpl` de objeto, chame o **criar** ou `SubclassWindow`. Não chama os dois métodos no mesmo objeto.  
  
 Além `CWindowImpl`, a ATL fornece [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) para criar uma janela que está contida em outro objeto.  
  
 O destruidor de classe base (~ **CWindowImplRoot**) garante que a janela desapareceu antes que o objeto seja destruído.  
  
 `CWindowImpl`deriva de **CWindowImplBaseT**, que deriva de **CWindowImplRoot**, que deriva de **TBase** e [CMessageMap](../../atl/reference/cmessagemap-class.md).  
  
|Para obter mais informações sobre|Consulte|  
|--------------------------------|---------|  
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|  
|Usando o windows em ATL|[Classes de janela ATL](../../atl/atl-window-classes.md)|  
|Assistente de Projeto da ATL|[Criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CMessageMap](../../atl/reference/cmessagemap-class.md)  
  
 `TBase`  
  
 `CWindowImplRoot`  
  
 `CWindowImplBaseT`  
  
 `CWindowImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="create"></a>CWindowImpl::Create  
 Cria uma janela com base em uma nova classe de janela.  
  
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
  
### <a name="parameters"></a>Parâmetros  
 `hWndParent`  
 [in] O identificador para a janela pai ou proprietário.  
  
 `rect`  
 [in] A [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura especificando a posição da janela. O `RECT` pode ser passado por ponteiro ou referência.  
  
 `szWindowName`  
 [in] Especifica o nome da janela. O valor padrão é **nulo**.  
  
 `dwStyle`  
 [in] O estilo da janela. Esse valor é combinado com o estilo fornecido pela classe de características da janela. O valor padrão fornece as características de controle de classe completo sobre o estilo. Para obter uma lista dos valores possíveis, consulte [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwExStyle`  
 [in] O estilo de janela estendidos. Esse valor é combinado com o estilo fornecido pela classe de características da janela. O valor padrão fornece as características de controle de classe completo sobre o estilo. Para obter uma lista dos valores possíveis, consulte [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `MenuOrID`  
 [in] Para uma janela filho, o identificador de janela. Para uma janela de nível superior, um identificador de menu da janela. O valor padrão é **0U**.  
  
 `lpCreateParam`  
 [in] Um ponteiro para dados de criação de janela. Para obter uma descrição completa, consulte a descrição para o parâmetro final para [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680).  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o identificador para a janela recém-criado. Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 **Criar** registra pela primeira vez a classe da janela se ele ainda não foi registrado. A janela recém-criado é anexada automaticamente para o `CWindowImpl` objeto.  
  
> [!NOTE]
>  Não chame **criar** se você já tiver chamado [SubclassWindow](#subclasswindow).  
  
 Para usar uma classe de janela com base em uma classe de janela existente, derive a classe de `CWindowImpl` e incluem o [DECLARE_WND_SUPERCLASS](http://msdn.microsoft.com/library/650337b6-4973-41e5-8c36-55f90327bdcd) macro. O procedimento de janela da classe de janela existente é salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc). Para obter mais informações, consulte o [CWindowImpl](../../atl/reference/cwindowimpl-class.md) visão geral.  
  
> [!NOTE]
>  Se 0 for usado como o valor para o `MenuOrID` parâmetro, ele deverá ser especificado como 0U (o valor padrão) para evitar um erro do compilador.  
  
##  <a name="defwindowproc"></a>CWindowImpl::DefWindowProc  
 Chamado por [WindowProc](#windowproc) para processar mensagens não tratadas pelo mapa de mensagens.  
  
```
LRESULT DefWindowProc(
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);

LRESULT DefWindowProc();
```  
  
### <a name="parameters"></a>Parâmetros  
 `uMsg`  
 [in] A mensagem enviada para a janela.  
  
 `wParam`  
 [in] Informações adicionais de mensagem específica.  
  
 `lParam`  
 [in] Informações adicionais de mensagem específica.  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado do processamento da mensagem.  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `DefWindowProc` chama o [CallWindowProc](http://msdn.microsoft.com/library/windows/desktop/ms633571) função do Win32 para enviar as informações de mensagem para o procedimento de janela especificado no [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).  
  
 A função sem parâmetros recupera automaticamente os parâmetros necessários a mensagem atual.  
  
##  <a name="getcurrentmessage"></a>CWindowImpl::GetCurrentMessage  
 Retorna a mensagem atual, empacotada no `MSG` estrutura.  
  
```
const MSG* GetCurrentMessage();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A mensagem atual.  
  
##  <a name="getwindowproc"></a>CWindowImpl::GetWindowProc  
 Retorna `WindowProc`, o procedimento de janela atual.  
  
```
virtual WNDPROC GetWindowProc();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O procedimento de janela atual.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para substituir o procedimento de janela com seus próprios.  
  
##  <a name="getwndclassinfo"></a>CWindowImpl::GetWndClassInfo  
 Chamado por [criar](#create) para acessar as informações de classe de janela.  
  
```
static CWndClassInfo& GetWndClassInfo();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma instância estática de [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md).  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `CWindowImpl` obtém esse método por meio de [DECLARE_WND_CLASS](http://msdn.microsoft.com/library/55247a72-fb9e-4bde-87f3-747c08076971) macro, que especifica uma nova classe de janela.  
  
 Para uma classe de janela existente da superclasse, derivar a classe de `CWindowImpl` e incluem o [DECLARE_WND_SUPERCLASS](http://msdn.microsoft.com/library/650337b6-4973-41e5-8c36-55f90327bdcd) macro substituir `GetWndClassInfo`. Para obter mais informações, consulte o [CWindowImpl](../../atl/reference/cwindowimpl-class.md) visão geral.  
  
 Além de usar o `DECLARE_WND_CLASS` e `DECLARE_WND_SUPERCLASS` macros, você pode substituir `GetWndClassInfo` por sua própria implementação.  
  
##  <a name="m_pfnsuperwindowproc"></a>CWindowImpl::m_pfnSuperWindowProc  
 Dependendo da janela, aponta para um dos seguintes procedimentos de janela.  
  
```
WNDPROC m_pfnSuperWindowProc;
```  
  
### <a name="remarks"></a>Comentários  
  
|Tipo de janela|Procedimento de janela|  
|--------------------|----------------------|  
|Uma janela com base em uma nova classe de janela, especificada por meio de [DECLARE_WND_CLASS](http://msdn.microsoft.com/library/55247a72-fb9e-4bde-87f3-747c08076971) macro.|O [DefWindowProc](http://msdn.microsoft.com/library/windows/desktop/ms633572) função do Win32.|  
|Uma janela com base em uma classe de janela que modifica uma classe existente, especificada por meio de [DECLARE_WND_SUPERCLASS](http://msdn.microsoft.com/library/650337b6-4973-41e5-8c36-55f90327bdcd) macro.|Procedimento de janela da classe de janela existente.|  
|Uma janela de subclasse.|Procedimento de janela original da janela subclasse.|  
  
 [CWindowImpl::DefWindowProc](#defwindowproc) envia a mensagem informações para o procedimento de janela salva em `m_pfnSuperWindowProc`.  
  
##  <a name="onfinalmessage"></a>CWindowImpl::OnFinalMessage  
 Chamado após o recebimento da última mensagem (geralmente `WM_NCDESTROY`).  
  
```
virtual void OnFinalMessage(HWND hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 [in] Um identificador para a janela que está sendo destruído.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão de `OnFinalMessage` não faz nada, mas você pode substituir essa função para lidar com limpeza antes de destruir uma janela. Se você quiser excluir automaticamente seu objeto após a destruição de janela, você pode chamar `delete this;` nessa função.  
  
##  <a name="subclasswindow"></a>CWindowImpl::SubclassWindow  
 Subclasses de janela identificada por `hWnd` e anexa-o para o `CWindowImpl` objeto.  
  
```
BOOL SubclassWindow(HWND hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 [in] O identificador para a janela que está sendo uma subclasse.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a janela estiver com êxito subclasse; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 A subclasse janela agora usa [CWindowImpl::WindowProc](#windowproc). O procedimento de janela original é salva em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).  
  
> [!NOTE]
>  Não chame `SubclassWindow` se você já tiver chamado [criar](#create).  
  
##  <a name="unsubclasswindow"></a>CWindowImpl::UnsubclassWindow  
 Desanexa a janela subclasse o `CWindowImpl` object e restaura o procedimento de janela original, salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).  
  
```
HWND UnsubclassWindow();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador para a janela anteriormente uma subclasse.  
  
##  <a name="windowproc"></a>CWindowImpl::WindowProc  
 A função estática implementa o procedimento de janela.  
  
```
static LRESULT CALLBACK WindowProc(
    HWND hWnd,
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 [in] O identificador para a janela.  
  
 `uMsg`  
 [in] A mensagem enviada para a janela.  
  
 `wParam`  
 [in] Informações adicionais de mensagem específica.  
  
 `lParam`  
 [in] Informações adicionais de mensagem específica.  
  
### <a name="return-value"></a>Valor de retorno  
 O resultado do processamento da mensagem.  
  
### <a name="remarks"></a>Comentários  
 `WindowProc`usa o mapa da mensagem padrão (declarado com [BEGIN_MSG_MAP](http://msdn.microsoft.com/library/8bbb5af9-18b1-48c6-880e-166f599ee554)) para direcionar mensagens para manipuladores adequados. Se necessário, `WindowProc` chamadas [DefWindowProc](#defwindowproc) para processamento de mensagens adicionais. Se a mensagem final não for tratada, `WindowProc` faz o seguinte:  
  
-   Executa unsubclassing se a janela foi unsubclassed.  
  
-   Limpa `m_hWnd`.  
  
-   Chamadas [OnFinalMessage](#onfinalmessage) antes que a janela for destruída.  
  
 Você pode substituir `WindowProc` para fornecer um mecanismo para manipulação de mensagens diferente.  
  
## <a name="see-also"></a>Consulte também  
 [BEGIN_MSG_MAP](http://msdn.microsoft.com/library/8bbb5af9-18b1-48c6-880e-166f599ee554)   
 [Classe de CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

