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
ms.openlocfilehash: 3518de3596748fa284c1f898b69d1576903e9510
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320761"
---
# <a name="ccomcontrol-class"></a>Classe CComControl

Esta classe fornece métodos para criar e gerenciar controles ATL.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T, class WinBase = CWindowImpl<T>>
class ATL_NO_VTABLE CComControl : public CComControlBase,
    public WinBase;
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
A classe que implementa o controle.

*Winbase*<br/>
A classe base que implementa funções de janelas. Padrão para [CWindowImpl](../../atl/reference/cwindowimpl-class.md).

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
|[Ccomcontrol::FireonChanged](#fireonchanged)|Notifica a pia do contêiner que uma propriedade de controle mudou.|
|[Ccomcontrol::FireonRequestEdit](#fireonrequestedit)|Notifica a pia do contêiner de que uma propriedade de controle está prestes a mudar e que o objeto está perguntando à pia como proceder.|
|[CComControl::Caixa de mensagens](#messagebox)|Chame este método para criar, exibir e operar uma caixa de mensagens.|

## <a name="remarks"></a>Comentários

`CComControl`é um conjunto de funções úteis de auxiliar de controle e membros de dados essenciais para controles ATL. Quando você cria um controle padrão ou um controle DHTML usando o Assistente `CComControl`de Controle ATL, o assistente derivará automaticamente sua classe de . `CComControl`deriva a maioria de seus métodos do [CComControlBase](../../atl/reference/ccomcontrolbase-class.md).

Para obter mais informações sobre como criar um controle, consulte o [Tutorial ATL](../../atl/active-template-library-atl-tutorial.md). Para obter mais informações sobre o ASSISTENTE DE PROJETO ATL, consulte o artigo [Criando um Projeto ATL](../../atl/reference/creating-an-atl-project.md).

Para uma `CComControl` demonstração de métodos e membros de dados, consulte a amostra [CIRC.](../../overview/visual-cpp-samples.md)

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`WinBase`

[Ccomcontrolbase](../../atl/reference/ccomcontrolbase-class.md)

`CComControl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="ccomcontrolccomcontrol"></a><a name="ccomcontrol"></a>CComControl::CComControl

O construtor.

```
CComControl();
```

### <a name="remarks"></a>Comentários

Chama o [construtor CComControlBase,](ccomcontrolbase-class.md#ccomcontrolbase) passando o membro de `m_hWnd` dados herdado através do [CWindowImpl](../../atl/reference/cwindowimpl-class.md).

## <a name="ccomcontrolcontrolqueryinterface"></a><a name="controlqueryinterface"></a>CComControl::ControlQueryInterface

Recupera um ponteiro para a interface solicitada.

```
virtual HRESULT ControlQueryInterface(const IID& iid, void** ppv);
```

### <a name="parameters"></a>Parâmetros

*Iid*<br/>
[em] O GUID da interface que está sendo solicitada.

*Ppv*<br/>
[fora] Um ponteiro para o ponteiro de interface identificado por *iid*ou NULL se a interface não for encontrada.

### <a name="remarks"></a>Comentários

Apenas lida com interfaces na tabela de mapas COM.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#15](../../atl/codesnippet/cpp/ccomcontrol-class_1.cpp)]

## <a name="ccomcontrolcreatecontrolwindow"></a><a name="createcontrolwindow"></a>CComControl::CreateControlWindow

Por padrão, cria uma janela `CWindowImpl::Create`para o controle chamando .

```
virtual HWND CreateControlWindow(HWND hWndParent, RECT& rcPos);
```

### <a name="parameters"></a>Parâmetros

*Hwndparent*<br/>
[em] Manuseie a janela dos pais ou donos. Uma alça de janela válida deve ser fornecida. A janela de controle está confinada à área de sua janela pai.

*rcPos*<br/>
[em] O tamanho inicial e a posição da janela a ser criada.

### <a name="remarks"></a>Comentários

Anular este método se você quiser fazer algo além de criar uma única janela, por exemplo, para criar duas janelas, uma das quais se torna uma barra de ferramentas para o seu controle.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#16](../../atl/codesnippet/cpp/ccomcontrol-class_2.cpp)]

## <a name="ccomcontrolfireonchanged"></a><a name="fireonchanged"></a>Ccomcontrol::FireonChanged

Notifica a pia do contêiner que uma propriedade de controle mudou.

```
HRESULT FireOnChanged(DISPID dispID);
```

### <a name="parameters"></a>Parâmetros

*Dispid*<br/>
[em] Identificador da propriedade que mudou.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Se sua classe de controle derivar de [IPropertyNotifySink,](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink)este método chama [CFirePropNotifyEvent::FireOnChanged](cfirepropnotifyevent-class.md#fireonchanged) para notificar todas as interfaces conectadas `IPropertyNotifySink` que a propriedade de controle especificada foi alterada. Se sua classe de `IPropertyNotifySink`controle não derivar, este método retorna S_OK.

Este método é seguro de chamar mesmo que seu controle não suporte pontos de conexão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#17](../../atl/codesnippet/cpp/ccomcontrol-class_3.cpp)]

## <a name="ccomcontrolfireonrequestedit"></a><a name="fireonrequestedit"></a>Ccomcontrol::FireonRequestEdit

Notifica a pia do contêiner de que uma propriedade de controle está prestes a mudar e que o objeto está perguntando à pia como proceder.

```
HRESULT FireOnRequestEdit(DISPID dispID);
```

### <a name="parameters"></a>Parâmetros

*Dispid*<br/>
[em] Identificador da propriedade prestes a mudar.

### <a name="return-value"></a>Valor retornado

Um dos valores padrão de HRESULT.

### <a name="remarks"></a>Comentários

Se sua classe de controle deriva ré do [IPropertyNotifySink,](/windows/win32/api/ocidl/nn-ocidl-ipropertynotifysink)este método chama [CFirePropNotifyEvent::FireOnRequestEdit](cfirepropnotifyevent-class.md#fireonrequestedit) para notificar todas as interfaces conectadas `IPropertyNotifySink` que a propriedade de controle especificada está prestes a ser alterada. Se sua classe de `IPropertyNotifySink`controle não derivar, este método retorna S_OK.

Este método é seguro de chamar mesmo que seu controle não suporte pontos de conexão.

### <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#18](../../atl/codesnippet/cpp/ccomcontrol-class_4.cpp)]

## <a name="ccomcontrolmessagebox"></a><a name="messagebox"></a>CComControl::Caixa de mensagens

Chame este método para criar, exibir e operar uma caixa de mensagens.

```
int MessageBox(
    LPCTSTR lpszText,
    LPCTSTR lpszCaption = _T(""),
    UINT nType = MB_OK);
```

### <a name="parameters"></a>Parâmetros

*lpszText*<br/>
O texto a ser exibido na caixa de mensagens.

*lpszCaption*<br/>
O título da caixa de diálogo. Se NULL (o padrão), o título "Erro" é usado.

*nType*<br/>
Especifica o conteúdo e o comportamento da caixa de diálogo. Consulte a entrada [MessageBox](/windows/win32/api/winuser/nf-winuser-messagebox) na documentação do Windows SDK para obter uma lista das diferentes caixas de mensagens disponíveis. O padrão fornece um simples botão **OK.**

### <a name="return-value"></a>Valor retornado

Retorna um valor inteiro especificando um dos valores do item do menu listados na [MessageBox](/windows/win32/api/winuser/nf-winuser-messagebox) na documentação do Windows SDK.

### <a name="remarks"></a>Comentários

`MessageBox`é útil tanto durante o desenvolvimento quanto como uma maneira fácil de exibir um erro ou mensagem de aviso para o usuário.

## <a name="see-also"></a>Confira também

[Classe CWindowImpl](../../atl/reference/cwindowimpl-class.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)<br/>
[Classe CComControlBase](../../atl/reference/ccomcontrolbase-class.md)<br/>
[Classe CComCompositeControl](../../atl/reference/ccomcompositecontrol-class.md)
