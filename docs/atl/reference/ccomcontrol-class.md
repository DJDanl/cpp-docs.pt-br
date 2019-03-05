---
title: Classe CComControl
ms.date: 11/04/2016
f1_keywords:
- CComControl
- ATLCTL/ATL::CComControl
- ATLCTL/ATL::CComControl::CComControl
- ATLCTL/ATL::CComControl::ControlQueryInterface
- ATLCTL/ATL::CComControl::CreateControlWindow
- ATLCTL/ATL::CComControl::FireOnChanged
- ATLCTL/ATL::CComControl::FireOnRequestEdit
- ATLCTL/ATL::CComControl::MessageBox
helpviewer_keywords:
- control flags
- CComControlBase class, CComControl class
- stock properties, ATL
- CComControl class
- controls [ATL], control helper functions
- ambient properties
- controls [ATL], properties
ms.assetid: 55368c27-bd16-45a7-b701-edb36157c8e8
ms.openlocfilehash: 29eeb31c0823a0614fa1404cf7efc1c281bab3a4
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57261577"
---
# <a name="ccomcontrol-class"></a>Classe CComControl

Essa classe fornece métodos para criar e gerenciar os controles ATL.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T, class WinBase = CWindowImpl<T>>
class ATL_NO_VTABLE CComControl : public CComControlBase,
    public WinBase;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
A classe de implementação do controle.

*WinBase*<br/>
A classe base que implementa as funções de janela. O padrão é [CWindowImpl](../../atl/reference/cwindowimpl-class.md).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControl::CComControl](#ccomcontrol)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControl::ControlQueryInterface](#controlqueryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CComControl::CreateControlWindow](#createcontrolwindow)|Cria uma janela para o controle.|
|[CComControl::FireOnChanged](#fireonchanged)|Notifica o coletor do contêiner que uma propriedade de controle foi alterado.|
|[CComControl::FireOnRequestEdit](#fireonrequestedit)|Notifica o coletor do contêiner que uma propriedade de controle está prestes a ser alterada e que o objeto está solicitando que o coletor como proceder.|
|[CComControl::MessageBox](#messagebox)|Chame esse método para criar, exibir e operar uma caixa de mensagem.|

## <a name="remarks"></a>Comentários

`CComControl` é um conjunto de funções de auxiliar de controle útil e membros de dados essenciais para controles da ATL. Quando você cria um controle padrão ou um controle DHTML usando o Assistente de controle do ATL, o assistente automaticamente será derive sua classe da `CComControl`. `CComControl` deriva a maioria de seus métodos de [CComControlBase](../../atl/reference/ccomcontrolbase-class.md).

Para obter mais informações sobre como criar um controle, consulte o [Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md). Para obter mais informações sobre o Assistente de projeto da ATL, consulte o artigo [criando um projeto ATL](../../atl/reference/creating-an-atl-project.md).

Para obter uma demonstração `CComControl` métodos e membros de dados, consulte a [c](../../visual-cpp-samples.md) exemplo.

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`WinBase`

[CComControlBase](../../atl/reference/ccomcontrolbase-class.md)

`CComControl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

##  <a name="ccomcontrol"></a>  CComControl::CComControl

O construtor.

```
CComControl();
```

### <a name="remarks"></a>Comentários

Chamadas a [CComControlBase](ccomcontrolbase-class.md#ccomcontrolbase) construtor, passando a `m_hWnd` membro de dados herdadas por meio [CWindowImpl](../../atl/reference/cwindowimpl-class.md).

##  <a name="controlqueryinterface"></a>  CComControl::ControlQueryInterface

Recupera um ponteiro para a interface solicitada.

```
virtual HRESULT ControlQueryInterface(const IID& iid, void** ppv);
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
[in] O GUID da interface que está sendo solicitado.

*ppv*<br/>
[out] Um ponteiro para o ponteiro de interface identificado pelo *iid*, ou nulo se a interface não foi encontrada.

### <a name="remarks"></a>Comentários

somente lida com interfaces na tabela de mapa COM.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#15](../../atl/codesnippet/cpp/ccomcontrol-class_1.cpp)]

##  <a name="createcontrolwindow"></a>  CComControl::CreateControlWindow

Por padrão, cria uma janela para o controle chamando `CWindowImpl::Create`.

```
virtual HWND CreateControlWindow(HWND hWndParent, RECT& rcPos);
```

### <a name="parameters"></a>Parâmetros

*hWndParent*<br/>
[in] Identificador da janela pai ou proprietária. Um identificador de janela válido deve ser fornecido. A janela de controle está confinada à área da sua janela pai.

*rcPos*<br/>
[in] O tamanho inicial e a posição da janela a ser criado.

### <a name="remarks"></a>Comentários

Substitua este método se você quiser fazer algo diferente de criar uma única janela, por exemplo, para criar duas janelas, um dos quais se tornará uma barra de ferramentas para o seu controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#16](../../atl/codesnippet/cpp/ccomcontrol-class_2.cpp)]

##  <a name="fireonchanged"></a>  CComControl::FireOnChanged

Notifica o coletor do contêiner que uma propriedade de controle foi alterado.

```
HRESULT FireOnChanged(DISPID dispID);
```

### <a name="parameters"></a>Parâmetros

*dispID*<br/>
[in] Identificador da propriedade que foi alterado.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Se sua classe de controle deriva [IPropertyNotifySink](/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink), este método chama [CFirePropNotifyEvent::FireOnChanged](cfirepropnotifyevent-class.md#fireonchanged) notificar todos conectados `IPropertyNotifySink` interfaces que o controle especificado propriedade foi alterada. Se sua classe de controle não é derivado de `IPropertyNotifySink`, esse método retorna S_OK.

Esse método é seguro chamar o mesmo que o controle não dá suporte a pontos de conexão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#17](../../atl/codesnippet/cpp/ccomcontrol-class_3.cpp)]

##  <a name="fireonrequestedit"></a>  CComControl::FireOnRequestEdit

Notifica o coletor do contêiner que uma propriedade de controle está prestes a ser alterada e que o objeto está solicitando que o coletor como proceder.

```
HRESULT FireOnRequestEdit(DISPID dispID);
```

### <a name="parameters"></a>Parâmetros

*dispID*<br/>
[in] Identificador da propriedade prestes a ser alterada.

### <a name="return-value"></a>Valor de retorno

Um dos valores HRESULT padrão.

### <a name="remarks"></a>Comentários

Se sua classe de controle deriva [IPropertyNotifySink](/windows/desktop/api/ocidl/nn-ocidl-ipropertynotifysink), este método chama [CFirePropNotifyEvent::FireOnRequestEdit](cfirepropnotifyevent-class.md#fireonrequestedit) notificar todos conectados `IPropertyNotifySink` interfaces que especificado propriedade de controle está prestes a ser alterada. Se sua classe de controle não é derivado de `IPropertyNotifySink`, esse método retorna S_OK.

Esse método é seguro chamar o mesmo que o controle não dá suporte a pontos de conexão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#18](../../atl/codesnippet/cpp/ccomcontrol-class_4.cpp)]

##  <a name="messagebox"></a>  CComControl::MessageBox

Chame esse método para criar, exibir e operar uma caixa de mensagem.

```
int MessageBox(
    LPCTSTR lpszText,
    LPCTSTR lpszCaption = _T(""),
    UINT nType = MB_OK);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
O texto a ser exibido na caixa de mensagem.

*lpszCaption*<br/>
O título da caixa de diálogo. Se NULL (o padrão), o título "Error" é usado.

*nType*<br/>
Especifica o conteúdo e o comportamento da caixa de diálogo. Consulte a [MessageBox](/windows/desktop/api/winuser/nf-winuser-messagebox) entrada na documentação do SDK do Windows para obter uma lista das caixas de mensagem diferentes disponíveis. O padrão fornece um simples **Okey** botão.

### <a name="return-value"></a>Valor de retorno

Retorna um valor inteiro especificando um dos valores de item de menu listados na [MessageBox](/windows/desktop/api/winuser/nf-winuser-messagebox) na documentação do SDK do Windows.

### <a name="remarks"></a>Comentários

`MessageBox` é útil durante o desenvolvimento e como uma maneira fácil de exibir uma mensagem de aviso ou erro para o usuário.

## <a name="see-also"></a>Consulte também

[Classe CWindowImpl](../../atl/reference/cwindowimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComControlBase](../../atl/reference/ccomcontrolbase-class.md)<br/>
[Classe CComCompositeControl](../../atl/reference/ccomcompositecontrol-class.md)
