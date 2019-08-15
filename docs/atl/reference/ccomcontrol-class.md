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
ms.openlocfilehash: bf0f64d8c7b8e8a3347e4c0fcad902b9e8a0ecb4
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69497527"
---
# <a name="ccomcontrol-class"></a>Classe CComControl

Essa classe fornece métodos para criar e gerenciar controles ATL.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class T, class WinBase = CWindowImpl<T>>
class ATL_NO_VTABLE CComControl : public CComControlBase,
    public WinBase;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
A classe que implementa o controle.

*WinBase*<br/>
A classe base que implementa as funções de janela. O padrão é [CWindowImpl](../../atl/reference/cwindowimpl-class.md).

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControl::CComControl](#ccomcontrol)|Construtor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComControl::ControlQueryInterface](#controlqueryinterface)|Recupera um ponteiro para a interface solicitada.|
|[CComControl::CreateControlWindow](#createcontrolwindow)|Cria uma janela para o controle.|
|[CComControl::FireOnChanged](#fireonchanged)|Notifica o coletor do contêiner de que uma propriedade de controle foi alterada.|
|[CComControl::FireOnRequestEdit](#fireonrequestedit)|Notifica o coletor do contêiner que uma propriedade de controle está prestes a ser alterada e que o objeto está solicitando que o coletor prossiga.|
|[CComControl::MessageBox](#messagebox)|Chame esse método para criar, exibir e operar uma caixa de mensagem.|

## <a name="remarks"></a>Comentários

`CComControl`é um conjunto de funções auxiliares de controle úteis e membros de dados essenciais para controles ATL. Quando você cria um controle padrão ou um controle DHTML usando o assistente de controle ATL, o assistente irá derivar automaticamente a `CComControl`classe de. `CComControl`deriva a maioria de seus métodos de [CComControlBase](../../atl/reference/ccomcontrolbase-class.md).

Para obter mais informações sobre como criar um controle, consulte o [tutorial do ATL](../../atl/active-template-library-atl-tutorial.md). Para obter mais informações sobre o assistente de projeto do ATL, consulte o artigo [criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md).

Para uma demonstração de `CComControl` métodos e membros de dados, consulte o exemplo de [CIRC](../../overview/visual-cpp-samples.md) .

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`WinBase`

[CComControlBase](../../atl/reference/ccomcontrolbase-class.md)

`CComControl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl. h

##  <a name="ccomcontrol"></a>CComControl::CComControl

O construtor.

```
CComControl();
```

### <a name="remarks"></a>Comentários

Chama o construtor [CComControlBase](ccomcontrolbase-class.md#ccomcontrolbase) , passando o `m_hWnd` membro de dados herdado por meio de [CWindowImpl](../../atl/reference/cwindowimpl-class.md).

##  <a name="controlqueryinterface"></a>  CComControl::ControlQueryInterface

Recupera um ponteiro para a interface solicitada.

```
virtual HRESULT ControlQueryInterface(const IID& iid, void** ppv);
```

### <a name="parameters"></a>Parâmetros

*iid*<br/>
no O GUID da interface que está sendo solicitada.

*ppv*<br/>
fora Um ponteiro para o ponteiro de interface identificado por *IID*ou NULL se a interface não for encontrada.

### <a name="remarks"></a>Comentários

O só lida COM interfaces na tabela de mapa COM.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#15](../../atl/codesnippet/cpp/ccomcontrol-class_1.cpp)]

##  <a name="createcontrolwindow"></a>  CComControl::CreateControlWindow

Por padrão, o cria uma janela para o controle chamando `CWindowImpl::Create`.

```
virtual HWND CreateControlWindow(HWND hWndParent, RECT& rcPos);
```

### <a name="parameters"></a>Parâmetros

*hWndParent*<br/>
no Identificador para a janela pai ou proprietário. Um identificador de janela válido deve ser fornecido. A janela de controle é confinada na área de sua janela pai.

*rcPos*<br/>
no O tamanho inicial e a posição da janela a ser criada.

### <a name="remarks"></a>Comentários

Substitua esse método se desejar fazer algo diferente de criar uma única janela, por exemplo, para criar duas janelas, uma das quais se torna uma barra de ferramentas para seu controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#16](../../atl/codesnippet/cpp/ccomcontrol-class_2.cpp)]

##  <a name="fireonchanged"></a>  CComControl::FireOnChanged

Notifica o coletor do contêiner de que uma propriedade de controle foi alterada.

```
HRESULT FireOnChanged(DISPID dispID);
```

### <a name="parameters"></a>Parâmetros

*dispID*<br/>
no Identificador da propriedade que foi alterada.

### <a name="return-value"></a>Valor de retorno

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Se sua classe de controle deriva de [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink), esse método chama [CFirePropNotifyEvent:: FireOnChanged](cfirepropnotifyevent-class.md#fireonchanged) para notificar todas `IPropertyNotifySink` as interfaces conectadas que a propriedade de controle especificada alterou. Se a classe de controle não derivar `IPropertyNotifySink`de, esse método retornará S_OK.

Esse método é seguro para chamar mesmo que o controle não dê suporte a pontos de conexão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#17](../../atl/codesnippet/cpp/ccomcontrol-class_3.cpp)]

##  <a name="fireonrequestedit"></a>  CComControl::FireOnRequestEdit

Notifica o coletor do contêiner que uma propriedade de controle está prestes a ser alterada e que o objeto está solicitando que o coletor prossiga.

```
HRESULT FireOnRequestEdit(DISPID dispID);
```

### <a name="parameters"></a>Parâmetros

*dispID*<br/>
no Identificador da propriedade prestes a ser alterado.

### <a name="return-value"></a>Valor de retorno

Um dos valores de HRESULT padrão.

### <a name="remarks"></a>Comentários

Se sua classe de controle deriva de [IPropertyNotifySink](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink), esse método chama [CFirePropNotifyEvent:: FireOnRequestEdit](cfirepropnotifyevent-class.md#fireonrequestedit) para notificar todas `IPropertyNotifySink` as interfaces conectadas que a propriedade de controle especificada está prestes a alterar. Se a classe de controle não derivar `IPropertyNotifySink`de, esse método retornará S_OK.

Esse método é seguro para chamar mesmo que o controle não dê suporte a pontos de conexão.

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
O título da caixa de diálogo. Se NULL (o padrão), o título "Error" será usado.

*nType*<br/>
Especifica o conteúdo e o comportamento da caixa de diálogo. Consulte a entrada [MessageBox](/windows/win32/api/winuser/nf-winuser-messagebox) na documentação SDK do Windows para obter uma lista das diferentes caixas de mensagens disponíveis. O padrão fornece um botão **OK** simples.

### <a name="return-value"></a>Valor de retorno

Retorna um valor inteiro especificando um dos valores de menu-item listados em [MessageBox](/windows/win32/api/winuser/nf-winuser-messagebox) na documentação do SDK do Windows.

### <a name="remarks"></a>Comentários

`MessageBox`é útil durante o desenvolvimento e como uma maneira fácil de exibir um erro ou uma mensagem de aviso para o usuário.

## <a name="see-also"></a>Consulte também

[Classe CWindowImpl](../../atl/reference/cwindowimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComControlBase](../../atl/reference/ccomcontrolbase-class.md)<br/>
[Classe CComCompositeControl](../../atl/reference/ccomcompositecontrol-class.md)
