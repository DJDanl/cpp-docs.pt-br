---
title: Classe CContainedWindowT | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CContainedWindow
- CContainedWindowT
- ATL.CContainedWindowT
dev_langs:
- C++
helpviewer_keywords:
- CContainedWindow class
- contained windows
- CContainedWindowT class
ms.assetid: cde0ca36-9347-4068-995a-d294dae57ca9
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
ms.openlocfilehash: e10aa4b455696fd217f88b6eb1de2421fccda6de
ms.lasthandoff: 02/25/2017

---
# <a name="ccontainedwindowt-class"></a>Classe CContainedWindowT
Essa classe implementa uma janela contida dentro de outro objeto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class TBase = CWindow, class TWinTraits = CControlWinTraits>  
class CContainedWindowT : public TBase
```  
  
#### <a name="parameters"></a>Parâmetros  
 *TBase*  
 A classe base da nova classe. A classe base padrão é `CWindow`.  
  
 `TWinTraits`  
 Uma classe de características que define estilos para a sua janela. O padrão é `CControlWinTraits`.  
  
> [!NOTE]
> [CContainedWindow](ccontainedwindowt-class.md) é uma especialização de `CContainedWindowT`. Se você deseja alterar a classe base ou características, use `CContainedWindowT` diretamente.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CContainedWindowT::CContainedWindowT](#ccontainedwindowt)|Construtor. Inicializa membros de dados para especificar qual mapa da mensagem processará mensagens da janela independente.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CContainedWindowT::Create](#create)|Cria uma janela.|  
|[CContainedWindowT::DefWindowProc](#defwindowproc)|Fornece o processamento da mensagem padrão.|  
|[CContainedWindowT::GetCurrentMessage](#getcurrentmessage)|Retorna a mensagem atual.|  
|[CContainedWindowT::RegisterWndSuperclass](#registerwndsuperclass)|Registra a classe de janela da janela contida.|  
|[CContainedWindowT::SubclassWindow](#subclasswindow)|Subclasses de uma janela.|  
|[CContainedWindowT::SwitchMessageMap](#switchmessagemap)|Altera o mapa da mensagem é usado para processar as mensagens da janela independente.|  
|[CContainedWindowT::UnsubclassWindow](#unsubclasswindow)|Restaura uma janela subclasse anteriormente.|  
|[CContainedWindowT::WindowProc](#windowproc)|(Estático) Processa as mensagens enviadas para a janela independente.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CContainedWindowT::m_dwMsgMapID](#m_dwmsgmapid)|Identifica qual mapa da mensagem processará mensagens da janela independente.|  
|[CContainedWindowT::m_lpszClassName](#m_lpszclassname)|Especifica o nome de uma classe de janela existente no qual uma nova classe de janela será baseada.|  
|[CContainedWindowT::m_pfnSuperWindowProc](#m_pfnsuperwindowproc)|Aponta para o procedimento de janela original da classe de janela.|  
|[CContainedWindowT::m_pObject](#m_pobject)|Aponta para o objeto contido.|  
  
## <a name="remarks"></a>Comentários  
 `CContainedWindowT`implementa uma janela contida dentro de outro objeto. `CContainedWindowT`está usos do procedimento de janela mapear uma mensagem no objeto que contém as mensagens diretas para manipuladores adequados. Ao construir um `CContainedWindowT` do objeto, você especifica qual mapa da mensagem deve ser usado.  
  
 `CContainedWindowT`permite que você crie uma nova janela, superclassing uma classe de janela existente. O **criar** método registra pela primeira vez que se baseia em uma classe existente, mas usa uma classe de janela `CContainedWindowT::WindowProc`. **Criar** , em seguida, cria uma janela com base nessa nova classe de janela. Cada instância de `CContainedWindowT` pode superclasse uma classe de janela diferentes.  
  
 `CContainedWindowT`também oferece suporte a criação de classes de janela. O `SubclassWindow` método anexa uma janela existente para o `CContainedWindowT` de objeto e altera o procedimento de janela para `CContainedWindowT::WindowProc`. Cada instância de `CContainedWindowT` pode criar uma subclasse uma janela diferente.  
  
> [!NOTE]
>  Para qualquer dado `CContainedWindowT` de objeto, chame o **criar** ou `SubclassWindow`. Você não deve chamar os dois métodos no mesmo objeto.  
  
 Quando você usa o **adicionar controle com base em** opção ATL Project Wizard, o assistente adicionará automaticamente um `CContainedWindowT` membro de dados para a classe que implementa o controle. O exemplo a seguir mostra como a janela independente é declarada:  
  
 [!code-cpp[NVC_ATL_Windowing&38;](../../atl/codesnippet/cpp/ccontainedwindowt-class_1.h)]  
  
 [!code-cpp[NVC_ATL_Windowing&#39;](../../atl/codesnippet/cpp/ccontainedwindowt-class_2.h)]  
  
 [!code-cpp[40 NVC_ATL_Windowing](../../atl/codesnippet/cpp/ccontainedwindowt-class_3.h)]  
  
|Para obter mais informações sobre|Consulte|  
|--------------------------------|---------|  
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|  
|Usando o windows em ATL|[Classes de janela ATL](../../atl/atl-window-classes.md)|  
|Assistente de Projeto da ATL|[Criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)|  
|Windows|[Windows](http://msdn.microsoft.com/library/windows/desktop/ms632595) e tópicos subsequentes a[!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]|  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `TBase`  
  
 `CContainedWindowT`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="a-nameccontainedwindowta--ccontainedwindowtccontainedwindowt"></a><a name="ccontainedwindowt"></a>CContainedWindowT::CContainedWindowT  
 O construtor inicializa membros de dados.  
  
```
CContainedWindowT(
    LPTSTR lpszClassName,
    CMessageMap* pObject,
    DWORD dwMsgMapID = 0);

CContainedWindowT(
    CMessageMap* pObject,
    DWORD dwMsgMapID = 0)
    CContainedWindowT();
```     
  
### <a name="parameters"></a>Parâmetros  
 `lpszClassName`  
 [in] O nome de uma classe de janela existente no qual a janela independente será baseada.  
  
 `pObject`  
 [in] Um ponteiro para o objeto recipiente que declara o mapa da mensagem. Classe do objeto deve derivar de [CMessageMap](../../atl/reference/cmessagemap-class.md).  
  
 `dwMsgMapID`  
 [in] Identifica o mapa da mensagem que processará as mensagens da janela independente. O valor padrão, 0, especifica o mapa da mensagem padrão declarado com [BEGIN_MSG_MAP](http://msdn.microsoft.com/library/8bbb5af9-18b1-48c6-880e-166f599ee554). Para usar um mapa de mensagens alternativos declarados com [ALT_MSG_MAP(msgMapID)](http://msdn.microsoft.com/library/2c8871bf-abc0-4d52-bcf7-6b2ab9eb5af8), passar `msgMapID`.  
  
### <a name="remarks"></a>Comentários  
 Se você quiser criar uma nova janela por meio de [criar](#create), você deve passar o nome de uma classe de janela existente para o `lpszClassName` parâmetro. Para obter um exemplo, consulte o [CContainedWindow](../../atl/reference/ccontainedwindowt-class.md) visão geral.  
  
 Há três construtores:  
  
-   O construtor com três argumentos é a chamada normalmente.  
  
-   O construtor com dois argumentos usa o nome da classe de **TBase::GetWndClassName**.  
  
-   O construtor sem argumentos é usado para fornecer os argumentos posteriormente. Você deve fornecer o nome da classe de janela, objeto de mapa de mensagem e identificação de mapa de mensagem quando você chama **criar**.  
  
 Se subclasse uma janela existente por meio de [SubclassWindow](#subclasswindow), o `lpszClassName` valor não será usado; portanto, você pode passar **nulo** para esse parâmetro.  
  
##  <a name="a-namecreatea--ccontainedwindowtcreate"></a><a name="create"></a>CContainedWindowT::Create  
 Chamadas [RegisterWndSuperclass](#registerwndsuperclass) para registrar uma classe de janela que se baseia em uma classe existente, mas usa [CContainedWindowT::WindowProc](#windowproc).  
  
```
HWND Create(  
    HWND hWndParent,
    _U_RECT rect,
    LPCTSTR szWindowName = NULL,
    DWORD dwStyle = 0,
    DWORD dwExStyle = 0,
    _U_MENUorID MenuOrID = 0U,
    LPVOID lpCreateParam = NULL);

HWND Create(
    CMessageMap* pObject,
    DWORD dwMsgMapID,
    HWND hWndParent,
    _U_RECT rect,
    LPCTSTR szWindowName = NULL,
    DWORD dwStyle = 0,
    DWORD dwExStyle = 0,
    _U_MENUorID MenuOrID = 0U,
    LPVOID lpCreateParam = NULL);

HWND Create(
    LPCTSTR lpszClassName,
    CMessageMap* pObject,
    DWORD dwMsgMapID,
    HWND hWndParent,
    _U_RECT rect,
    LPCTSTR szWindowName = NULL,
    DWORD dwStyle = 0,
    DWORD dwExStyle = 0,
    _U_MENUorID MenuOrID = 0U,
    LPVOID lpCreateParam = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpszClassName`  
 [in] O nome de uma classe de janela existente no qual a janela independente será baseada.  
  
 `pObject`  
 [in] Um ponteiro para o objeto recipiente que declara o mapa da mensagem. Classe do objeto deve derivar de [CMessageMap](../../atl/reference/cmessagemap-class.md).  
  
 `dwMsgMapID`  
 [in] Identifica o mapa da mensagem que processará as mensagens da janela independente. O valor padrão, 0, especifica o mapa da mensagem padrão declarado com [BEGIN_MSG_MAP](http://msdn.microsoft.com/library/8bbb5af9-18b1-48c6-880e-166f599ee554). Para usar um mapa de mensagens alternativos declarados com [ALT_MSG_MAP(msgMapID)](http://msdn.microsoft.com/library/2c8871bf-abc0-4d52-bcf7-6b2ab9eb5af8), passar `msgMapID`.  
  
 `hWndParent`  
 [in] O identificador para a janela pai ou proprietário.  
  
 `rect`  
 [in] A [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura especificando a posição da janela. O `RECT` pode ser passado por ponteiro ou referência.  
  
 `szWindowName`  
 [in] Especifica o nome da janela. O valor padrão é **nulo**.  
  
 `dwStyle`  
 [in] O estilo da janela. O valor padrão é **WS_CHILD | WS_VISIBLE**. Para obter uma lista dos valores possíveis, consulte [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwExStyle`  
 [in] O estilo de janela estendidos. O valor padrão é 0, indicando que nenhum estilo estendido. Para obter uma lista dos valores possíveis, consulte [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `MenuOrID`  
 [in] Para uma janela filho, o identificador de janela. Para uma janela de nível superior, um identificador de menu da janela. O valor padrão é **0U**.  
  
 `lpCreateParam`  
 [in] Um ponteiro para dados de criação de janela. Para obter uma descrição completa, consulte a descrição para o parâmetro final para [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680).  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o identificador de janela criado recentemente. Caso contrário, **nulo**.  
  
### <a name="remarks"></a>Comentários  
 O nome da classe de janela existente é salvo em [m_lpszClassName](#m_lpszclassname). **Criar** , em seguida, cria uma janela com base em sua nova classe. A janela recém-criado é anexada automaticamente para o `CContainedWindowT` objeto.  
  
> [!NOTE]
>  Não chame **criar** se você já tiver chamado [SubclassWindow](#subclasswindow).  
  
> [!NOTE]
>  Se 0 for usado como o valor para o `MenuOrID` parâmetro, ele deverá ser especificado como 0U (o valor padrão) para evitar um erro do compilador.  
  
##  <a name="a-namedefwindowproca--ccontainedwindowtdefwindowproc"></a><a name="defwindowproc"></a>CContainedWindowT::DefWindowProc  
 Chamado por [WindowProc](#windowproc) para processar mensagens não tratadas pelo mapa de mensagens.  
  
```
LRESULT DefWindowProc()
LRESULT DefWindowProc(
    UINT uMsg,
    WPARAM wParam,
    LPARAM lParam);
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
  
##  <a name="a-namegetcurrentmessagea--ccontainedwindowtgetcurrentmessage"></a><a name="getcurrentmessage"></a>CContainedWindowT::GetCurrentMessage  
 Retorna a mensagem atual ( **m_pCurrentMsg**).  
  
```
const _ATL_MSG* GetCurrentMessage();
```  
  
### <a name="return-value"></a>Valor de retorno  
 A mensagem atual, empacotada no `MSG` estrutura.  
  
##  <a name="a-namemdwmsgmapida--ccontainedwindowtmdwmsgmapid"></a><a name="m_dwmsgmapid"></a>CContainedWindowT::m_dwMsgMapID  
 Contém o identificador do mapa de mensagens usado atualmente para a janela independente.  
  
```
DWORD m_dwMsgMapID;
```  
  
### <a name="remarks"></a>Comentários  
 Este mapa de mensagem deve ser declarado no objeto de recipiente.  
  
 O mapa da mensagem padrão declarado com [BEGIN_MSG_MAP](http://msdn.microsoft.com/library/8bbb5af9-18b1-48c6-880e-166f599ee554), é sempre identificado por zero. Um mapa de mensagens alternativos, declarado com [ALT_MSG_MAP(msgMapID)](http://msdn.microsoft.com/library/2c8871bf-abc0-4d52-bcf7-6b2ab9eb5af8), é identificado por `msgMapID`.  
  
 `m_dwMsgMapID`primeiro é inicializada pelo construtor e pode ser alterada chamando [SwitchMessageMap](#switchmessagemap). Para obter um exemplo, consulte o [visão geral de CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md).  
  
##  <a name="a-namemlpszclassnamea--ccontainedwindowtmlpszclassname"></a><a name="m_lpszclassname"></a>CContainedWindowT::m_lpszClassName  
 Especifica o nome de uma classe de janela existente.  
  
```
LPTSTR m_lpszClassName;
```  
  
### <a name="remarks"></a>Comentários  
 Quando você cria uma janela [criar](#create) registra uma nova classe de janela que se baseia essa classe existente, mas usa [CContainedWindowT::WindowProc](#windowproc).  
  
 `m_lpszClassName`é inicializada pelo construtor. Para obter um exemplo, consulte o [CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md) visão geral.  
  
##  <a name="a-namempfnsuperwindowproca--ccontainedwindowtmpfnsuperwindowproc"></a><a name="m_pfnsuperwindowproc"></a>CContainedWindowT::m_pfnSuperWindowProc  
 Se a janela contida em uma subclasse, `m_pfnSuperWindowProc` aponta para o procedimento de janela original da classe de janela.  
  
```
WNDPROC m_pfnSuperWindowProc;
```  
  
### <a name="remarks"></a>Comentários  
 Se a janela independente for superclassificados como de edição, que significa que ela é baseada em uma classe de janela que modifica uma classe existente, `m_pfnSuperWindowProc` aponta para o procedimento de janela da classe de janela existente.  
  
 O [DefWindowProc](#defwindowproc) método envia informações sobre a mensagem para o procedimento de janela salvo em `m_pfnSuperWindowProc`.  
  
##  <a name="a-namempobjecta--ccontainedwindowtmpobject"></a><a name="m_pobject"></a>CContainedWindowT::m_pObject  
 Aponta para o objeto que contém o `CContainedWindowT` objeto.  
  
```
CMessageMap* m_pObject;
```  
  
### <a name="remarks"></a>Comentários  
 Nesse contêiner, cuja classe deve derivar de [CMessageMap](../../atl/reference/cmessagemap-class.md), declara o mapa de mensagens usado pela janela independente.  
  
 `m_pObject`é inicializada pelo construtor. Para obter um exemplo, consulte o [CContainedWindowT](../../atl/reference/ccontainedwindowt-class.md) visão geral.  
  
##  <a name="a-nameregisterwndsuperclassa--ccontainedwindowtregisterwndsuperclass"></a><a name="registerwndsuperclass"></a>CContainedWindowT::RegisterWndSuperclass  
 Chamado por [criar](#create) para registrar a classe de janela da janela contida.  
  
```
ATOM RegisterWndSuperClass();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, um átomo que identifica exclusivamente a classe de janela que está sendo registrada; Caso contrário, zero.  
  
### <a name="remarks"></a>Comentários  
 Essa classe de janela é baseado em uma classe existente, mas usa [CContainedWindowT::WindowProc](#windowproc). Procedimento de janela e de nome da classe de janela existente são salvas em [m_lpszClassName](#m_lpszclassname) e [m_pfnSuperWindowProc](#m_pfnsuperwindowproc), respectivamente.  
  
##  <a name="a-namesubclasswindowa--ccontainedwindowtsubclasswindow"></a><a name="subclasswindow"></a>CContainedWindowT::SubclassWindow  
 Subclasses de janela identificada por `hWnd` e anexa-o para o `CContainedWindowT` objeto.  
  
```
BOOL SubclassWindow(HWND hWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 [in] O identificador para a janela que está sendo uma subclasse.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a janela estiver com êxito subclasse; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 A subclasse janela agora usa [CContainedWindowT::WindowProc](#windowproc). O procedimento de janela original é salva em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).  
  
> [!NOTE]
>  Não chame `SubclassWindow` se você já tiver chamado [criar](#create).  
  
##  <a name="a-nameswitchmessagemapa--ccontainedwindowtswitchmessagemap"></a><a name="switchmessagemap"></a>CContainedWindowT::SwitchMessageMap  
 Altera o mapa da mensagem será usado para processar as mensagens da janela independente.  
  
```
void SwitchMessageMap(DWORD dwMsgMapID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwMsgMapID`  
 [in] O identificador de mapa de mensagem. Usar o mapa de mensagem padrão declarado com [BEGIN_MSG_MAP](http://msdn.microsoft.com/library/8bbb5af9-18b1-48c6-880e-166f599ee554), transmitir zero. Para usar um mapa de mensagens alternativos declarados com [ALT_MSG_MAP(msgMapID)](http://msdn.microsoft.com/library/2c8871bf-abc0-4d52-bcf7-6b2ab9eb5af8), passar `msgMapID`.  
  
### <a name="remarks"></a>Comentários  
 O mapa da mensagem deve ser definido no objeto de recipiente.  
  
 Inicialmente, você especificar o identificador do mapa de mensagem no construtor.  
  
##  <a name="a-nameunsubclasswindowa--ccontainedwindowtunsubclasswindow"></a><a name="unsubclasswindow"></a>CContainedWindowT::UnsubclassWindow  
 Desanexa a janela subclasse o `CContainedWindowT` object e restaura o procedimento de janela original, salvo em [m_pfnSuperWindowProc](#m_pfnsuperwindowproc).  
  
```
HWND UnsubclassWindow(BOOL bForce = FALSE);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bForce`  
 [in] Definido como **TRUE** para forçar o procedimento de janela original a ser restaurado mesmo se o procedimento de janela para este `CContainedWindowT` objeto não está ativo no momento. Se `bForce` é definido como **FALSE** e o procedimento de janela para este `CContainedWindowT` objeto não está ativo no momento, o procedimento de janela original não será restaurado.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador para a janela anteriormente uma subclasse. Se `bForce` é definido como **FALSE** e o procedimento de janela para este `CContainedWindowT` objeto não está ativo no momento, retorna **nulo**.  
  
### <a name="remarks"></a>Comentários  
 Use esse método somente se você deseja restaurar o procedimento de janela original antes que a janela for destruída. Caso contrário, [WindowProc](#windowproc) faz isso automaticamente quando a janela for destruída.  
  
##  <a name="a-namewindowproca--ccontainedwindowtwindowproc"></a><a name="windowproc"></a>CContainedWindowT::WindowProc  
 Esse método estático implementa o procedimento de janela.  
  
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
 `WindowProc`direciona mensagens ao mapa da mensagem identificado por [m_dwMsgMapID](#m_dwmsgmapid). Se necessário, `WindowProc` chamadas [DefWindowProc](#defwindowproc) para processamento de mensagens adicionais.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWindow](../../atl/reference/cwindow-class.md)   
 [Classe CWindowImpl](../../atl/reference/cwindowimpl-class.md)   
 [Classe CMessageMap](../../atl/reference/cmessagemap-class.md)   
 [BEGIN_MSG_MAP](http://msdn.microsoft.com/library/8bbb5af9-18b1-48c6-880e-166f599ee554)   
 [ALT_MSG_MAP](http://msdn.microsoft.com/library/2c8871bf-abc0-4d52-bcf7-6b2ab9eb5af8)   
 [Visão geral da classe](../../atl/atl-class-overview.md)

