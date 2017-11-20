---
title: Classe CWindowImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
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
dev_langs: C++
helpviewer_keywords:
- CWindowImpl class
- subclassing windows, ATL
ms.assetid: 02eefd45-a0a6-4d1b-99f6-dbf627e2cc2f
caps.latest.revision: "22"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: ba2633fe88b83dda2f0d0edcf58d477f8f760b89
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="cwindowimpl-class"></a>Classe CWindowImpl
Fornece métodos para criar ou subclasses de uma janela.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, class TBase = CWindow, class TWinTraits = CControlWinTraits>  
class ATL_NO_VTABLE CWindowImpl : public CWindowImplBaseT<TBase, TWinTraits>
```    
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A nova classe, derivada de `CWindowImpl`.  
  
 *TBase*  
 A classe base da sua classe. Por padrão, a classe base é [CWindow](../../atl/reference/cwindow-class.md).  
  
 `TWinTraits`  
 Um [classe características](../../atl/understanding-window-traits.md) que define estilos para a janela. O padrão é `CControlWinTraits`.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWindowImpl::Create](#create)|Cria uma janela.|  
  
### <a name="cwindowimplbaset-methods"></a>Métodos de CWindowImplBaseT  
  
|||  
|-|-|  
|[DefWindowProc](#defwindowproc)|Fornece processamento de mensagem padrão.|  
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
 Você pode usar `CWindowImpl` para criar uma janela ou uma subclasse de uma janela existente. o `CWindowImpl` procedimento de janela usa um mapa de mensagem para direcionar as mensagens para os manipuladores apropriados.  
  
 `CWindowImpl::Create`cria uma janela com base nas informações de classe de janela que são gerenciadas pelo [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md). `CWindowImpl`contém o [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) macro, o que significa `CWndClassInfo` registra uma nova classe de janela. Se você quiser superclasse uma classe de janela existente, derive sua classe de `CWindowImpl` e incluir o [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro. Nesse caso, `CWndClassInfo` registra uma classe de janela que é baseada em uma classe existente, mas usa `CWindowImpl::WindowProc`. Por exemplo:  
  
 [!code-cpp[NVC_ATL_Windowing#43](../../atl/codesnippet/cpp/cwindowimpl-class_1.h)]  
  
> [!NOTE]
>  Porque `CWndClassInfo` gerencia as informações para apenas uma classe de janela, cada janela criada por meio de uma instância de `CWindowImpl` baseia-se na mesma classe de janela.  
  
 `CWindowImpl`também suporta subclassificação de janela. O `SubclassWindow` método anexa uma janela existente para o `CWindowImpl` de objeto e altera o procedimento de janela para `CWindowImpl::WindowProc`. Cada instância de `CWindowImpl` pode subclasse uma janela diferente.  
  
> [!NOTE]
>  Para qualquer dado `CWindowImpl` de objeto, chame o **criar** ou `SubclassWindow`. Não chama ambos os métodos no mesmo objeto.  
  
 Além `CWindowImpl`, ATL fornece [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) para criar uma janela que está contida em outro objeto.  
  
 O destruidor da classe base (~ **CWindowImplRoot**) garante que a janela será excluída antes que o objeto é destruído.  
  
 `CWindowImpl`deriva **CWindowImplBaseT**, que é derivado de **CWindowImplRoot**, que é derivado de **TBase** e [CMessageMap](../../atl/reference/cmessagemap-class.md).  
  
|Para obter mais informações sobre|Consulte|  
|--------------------------------|---------|  
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|  
|Usando o windows no ATL|[Classes de janela da ATL](../../atl/atl-window-classes.md)|  
|Assistente de projeto ATL|[Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)|  
  
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
 [in] Um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura especificando a posição da janela. O `RECT` pode ser passado pelo ponteiro ou referência.  
  
 `szWindowName`  
 [in] Especifica o nome da janela. O valor padrão é **nulo**.  
  
 `dwStyle`  
 [in] O estilo da janela. Esse valor é combinado com o estilo fornecido pela classe características da janela. O valor padrão fornece as características de controle completo sobre o estilo de classe. Para obter uma lista de valores possíveis, consulte [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) no SDK do Windows.  
  
 `dwExStyle`  
 [in] O estilo de janela estendidos. Esse valor é combinado com o estilo fornecido pela classe características da janela. O valor padrão fornece as características de controle completo sobre o estilo de classe. Para obter uma lista de valores possíveis, consulte [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no SDK do Windows.  
  
 `MenuOrID`  
 [in] Para uma janela filho, o identificador de janela. Para uma janela de nível superior, um identificador de menu da janela. O valor padrão é **0U**.  
  
 `lpCreateParam`  
 [in] Um ponteiro para dados de criação de janela. Para obter uma descrição completa, consulte a descrição para o parâmetro final para [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680).  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o identificador para a janela recém-criado. Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 **Criar** primeiro se ele ainda não tiver sido registrado, registra a classe de janela. A janela recém-criado é anexada automaticamente para o `CWindowImpl` objeto.  
  
> [!NOTE]
>  Não chame **criar** se você já tiver sido chamado [SubclassWindow](#subclasswindow).  
  
 Para usar uma classe de janela com base em uma classe de janela existente, derive a classe de `CWindowImpl` e incluir o [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro. O procedimento de janela da classe de janela existente é salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc). Para obter mais informações, consulte o [CWindowImpl](../../atl/reference/cwindowimpl-class.md) visão geral.  
  
> [!NOTE]
>  Se 0 for usado como o valor para o `MenuOrID` parâmetro, ele deve ser especificado como 0U (o valor padrão) para evitar um erro do compilador.  
  
##  <a name="defwindowproc"></a>CWindowImpl::DefWindowProc  
 Chamado pelo [WindowProc](#windowproc) para processar mensagens não lida com o mapa de mensagens.  
  
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
 Por padrão, `DefWindowProc` chama o [CallWindowProc](http://msdn.microsoft.com/library/windows/desktop/ms633571) função Win32 para enviar as informações de mensagem para o procedimento de janela especificado em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).  
  
 A função sem parâmetros recupera os parâmetros necessários automaticamente a mensagem atual.  
  
##  <a name="getcurrentmessage"></a>CWindowImpl::GetCurrentMessage  
 Retorna a mensagem atual, empacotada no `MSG` estrutura.  
  
```
const MSG* GetCurrentMessage();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A mensagem atual.  
  
##  <a name="getwindowproc"></a>CWindowImpl::GetWindowProc  
 Retorna `WindowProc`, o procedimento da janela atual.  
  
```
virtual WNDPROC GetWindowProc();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O procedimento da janela atual.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para substituir o procedimento de janela com seus próprios.  
  
##  <a name="getwndclassinfo"></a>CWindowImpl::GetWndClassInfo  
 Chamado pelo [criar](#create) para acessar as informações de classe de janela.  
  
```
static CWndClassInfo& GetWndClassInfo();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma instância estática de [CWndClassInfo](../../atl/reference/cwndclassinfo-class.md).  
  
### <a name="remarks"></a>Comentários  
 Por padrão, `CWindowImpl` obtém esse método por meio de [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) macro, que especifica uma nova classe de janela.  
  
 Para uma classe de janela existente da superclasse, derive sua classe da `CWindowImpl` e incluir o [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro substituir `GetWndClassInfo`. Para obter mais informações, consulte o [CWindowImpl](../../atl/reference/cwindowimpl-class.md) visão geral.  
  
 Além de usar o `DECLARE_WND_CLASS` e `DECLARE_WND_SUPERCLASS` macros, você pode substituir `GetWndClassInfo` com sua própria implementação.  
  
##  <a name="m_pfnsuperwindowproc"></a>CWindowImpl::m_pfnSuperWindowProc  
 Dependendo da janela, aponta para um dos seguintes procedimentos de janela.  
  
```
WNDPROC m_pfnSuperWindowProc;
```  
  
### <a name="remarks"></a>Comentários  
  
|Tipo de janela|Procedimento de janela|  
|--------------------|----------------------|  
|Uma janela com base em uma nova classe de janela, especificada por meio de [DECLARE_WND_CLASS](window-class-macros.md#declare_wnd_class) macro.|O [DefWindowProc](http://msdn.microsoft.com/library/windows/desktop/ms633572) função Win32.|  
|Uma janela com base em uma classe de janela que modifica uma classe existente, especificada por meio de [DECLARE_WND_SUPERCLASS](window-class-macros.md#declare_wnd_superclass) macro.|Procedimento de janela da classe de janela existente.|  
|Uma janela de subclasse.|A subclasse original procedimento da janela.|  
  
 [CWindowImpl::DefWindowProc](#defwindowproc) envia mensagem de informações para o procedimento de janela salvado em `m_pfnSuperWindowProc`.  
  
##  <a name="onfinalmessage"></a>CWindowImpl::OnFinalMessage  
 Chamado após o recebimento da última mensagem (geralmente `WM_NCDESTROY`).  
  
```
virtual void OnFinalMessage(HWND hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 [in] Um identificador para a janela que está sendo destruído.  
  
### <a name="remarks"></a>Comentários  
 A implementação padrão de `OnFinalMessage` não faz nada, mas você pode substituir essa função para manipular limpeza antes de destruir uma janela. Se você quiser excluir automaticamente seu objeto após a destruição de janela, você pode chamar `delete this;` nesta função.  
  
##  <a name="subclasswindow"></a>CWindowImpl::SubclassWindow  
 Subclasses de janela identificada por `hWnd` e anexa-o para o `CWindowImpl` objeto.  
  
```
BOOL SubclassWindow(HWND hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 [in] O identificador para a janela que está sendo derivado.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a janela estiver com êxito subclasse; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 A subclasse janela agora usa [CWindowImpl::WindowProc](#windowproc). O procedimento de janela original é salva em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).  
  
> [!NOTE]
>  Não chame `SubclassWindow` se você já tiver sido chamado [criar](#create).  
  
##  <a name="unsubclasswindow"></a>CWindowImpl::UnsubclassWindow  
 Desanexa a subclasse na janela de `CWindowImpl` de objeto e restaura o procedimento de janela original, salvado em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).  
  
```
HWND UnsubclassWindow();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador para a janela anteriormente uma subclasse.  
  
##  <a name="windowproc"></a>CWindowImpl::WindowProc  
 Função estática implementa o procedimento de janela.  
  
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
 `WindowProc`usa o mapa da mensagem padrão (declarado com [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)) para direcionar as mensagens para os manipuladores apropriados. Se necessário, `WindowProc` chamadas [DefWindowProc](#defwindowproc) para processamento de mensagens adicionais. Se a mensagem final não é tratada, `WindowProc` faz o seguinte:  
  
-   Executa unsubclassing se a janela foi unsubclassed.  
  
-   Limpa `m_hWnd`.  
  
-   Chamadas [OnFinalMessage](#onfinalmessage) antes que a janela é destruída.  
  
 Você pode substituir `WindowProc` para fornecer um mecanismo diferente para manipulação de mensagens.  
  
## <a name="see-also"></a>Consulte também  
 [BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)   
 [Classe CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
