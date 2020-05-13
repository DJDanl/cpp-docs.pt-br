---
title: Classe CComCompositeControl
ms.date: 11/04/2016
f1_keywords:
- CComCompositeControl
- ATLCTL/ATL::CComCompositeControl
- ATLCTL/ATL::CComCompositeControl::CComCompositeControl
- ATLCTL/ATL::CComCompositeControl::AdviseSinkMap
- ATLCTL/ATL::CComCompositeControl::CalcExtent
- ATLCTL/ATL::CComCompositeControl::Create
- ATLCTL/ATL::CComCompositeControl::CreateControlWindow
- ATLCTL/ATL::CComCompositeControl::SetBackgroundColorFromAmbient
- ATLCTL/ATL::CComCompositeControl::m_hbrBackground
- ATLCTL/ATL::CComCompositeControl::m_hWndFocus
helpviewer_keywords:
- CComCompositeControl class
- composite controls, CComCompositeControl class
ms.assetid: 1304b931-27e8-4fbc-be8e-bb226ad887fb
ms.openlocfilehash: 700a8047ab1fa9df85c8e6530eb3eed5f29bd3d3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81320798"
---
# <a name="ccomcompositecontrol-class"></a>Classe CComCompositeControl

Esta classe fornece os métodos necessários para implementar um controle composto.

> [!IMPORTANT]
> Esta classe e seus membros não podem ser usados em aplicativos executados no Tempo de execução do Windows.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class CComCompositeControl : public CComControl<T,CAxDialogImpl<T>>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx,](../../atl/reference/ccomobjectrootex-class.md)bem como de quaisquer outras interfaces que você deseja suportar para o seu controle composto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCompositeControl::CComCompositeControl](#ccomcompositecontrol)|O construtor.|
|[CComCompositeControl::~CComCompositecontrol](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCompositeControl::AdvisesinkMap](#advisesinkmap)|Chame este método para aconselhar ou desaconselhar todos os controles hospedados pelo controle composto.|
|[CComCompositeControl::CalcExtent](#calcextent)|Chame este método para calcular o tamanho em unidades HIMETRIC do recurso de diálogo usado para hospedar o controle composto.|
|[CComCompositeControl::Criar](#create)|Este método é chamado para criar a janela de controle para o controle composto.|
|[CComCompositeControl::CreateControlWindow](#createcontrolwindow)|Chame este método para criar a janela de controle e aconselhar qualquer controle hospedado.|
|[ccomcompositecontrol::setbackgroundColorFromambient](#setbackgroundcolorfromambient)|Chame este método para definir a cor de fundo do controle composto usando a cor de fundo do contêiner.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[CComCompositeControl::m_hbrBackground](#m_hbrbackground)|A escova de fundo.|
|[CComCompositeControl::m_hWndFocus](#m_hwndfocus)|A alça da janela que atualmente tem foco.|

## <a name="remarks"></a>Comentários

As classes derivadas da classe `CComCompositeControl` herdam a funcionalidade de um controle composto ActiveX. Os controles ActiveX `CComCompositeControl` derivados são hospedados por uma caixa de diálogo padrão. Esses tipos de controles são chamados de controles compostos porque são capazes de hospedar outros controles (controles nativos do Windows e controles ActiveX).

`CComCompositeControl`identifica o recurso de diálogo a ser usado na criação do controle composto procurando um membro de dados enumerado na classe criança. O IDD de membro desta classe criança é definido como o ID de recurso de recurso do recurso de diálogo que será usado como janela do controle. A seguir, um exemplo do membro de `CComCompositeControl` dados do qual a classe derivada deve conter para identificar o recurso de diálogo a ser usado na janela do controle:

[!code-cpp[NVC_ATL_COM#13](../../atl/codesnippet/cpp/ccomcompositecontrol-class_1.h)]

> [!NOTE]
> Os controles compostos são sempre controles com janelas, embora possam conter controles sem janelas.

Um controle implementado `CComCompositeControl`por uma classe derivada tem um comportamento padrão de tabulação incorporado. Quando o controle recebe foco sendo guiado em um aplicativo de contenção, pressionar sucessivamente a tecla TAB fará com que o foco seja ciclado através de todos os controles contidos do controle composto, em seguida, fora do controle composto e para o próximo item na ordem de guia do recipiente. A ordem de guia dos controles hospedados é determinada pelo recurso de diálogo e determina a ordem em que a tabulação ocorrerá.

> [!NOTE]
> Para que os aceleradores funcionem corretamente com a, `CComCompositeControl`é necessário carregar uma tabela do acelerador à medida que o controle é criado, passar a alça e o número de aceleradores de volta para [IOleControlImpl::GetControlInfo](../../atl/reference/iolecontrolimpl-class.md#getcontrolinfo), e finalmente destruir a tabela quando o controle for liberado.

## <a name="example"></a>Exemplo

[!code-cpp[NVC_ATL_COM#14](../../atl/codesnippet/cpp/ccomcompositecontrol-class_2.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`WinBase`

[Ccomcontrolbase](../../atl/reference/ccomcontrolbase-class.md)

[Ccomcontrol](../../atl/reference/ccomcontrol-class.md)

`CComCompositeControl`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlctl.h

## <a name="ccomcompositecontroladvisesinkmap"></a><a name="advisesinkmap"></a>CComCompositeControl::AdvisesinkMap

Chame este método para aconselhar ou desaconselhar todos os controles hospedados pelo controle composto.

```
HRESULT AdviseSinkMap(bool bAdvise);
```

### <a name="parameters"></a>Parâmetros

*bAconselhar*<br/>
É verdade se todos os controles forem aconselhados; caso contrário, falso.

### <a name="return-value"></a>Valor retornado

|||
|-|-|
|S_OK  |Todos os controles no mapa do dissipador de eventos foram conectados ou desconectados da fonte do evento com sucesso.|
|E_FAIL  |Nem todos os controles no mapa do dissipador de eventos podem ser conectados ou desconectados da fonte de evento com sucesso.|
|E_POINTER  |Esse erro geralmente indica um problema com uma entrada no mapa de sumidouro de eventos do controle ou um problema com um argumento de modelo usado em uma `IDispEventImpl` classe ou `IDispEventSimpleImpl` base.|
|CONNECT_E_ADVISELIMIT  |O ponto de conexão já atingiu seu limite de conexões e não pode aceitar mais nenhuma.|
|CONNECT_E_CANNOTCONNECT  |O dissipador não suporta a interface exigida por este ponto de conexão.|
|CONNECT_E_NOCONNECTION  |O valor do cookie não representa uma conexão válida. Esse erro geralmente indica um problema com uma entrada no mapa de sumidouro de eventos do controle ou um problema com um argumento de modelo usado em uma `IDispEventImpl` classe ou `IDispEventSimpleImpl` base.|

### <a name="remarks"></a>Comentários

A implementação base deste método é pesquisada através das entradas no mapa do dissipador de eventos. Em seguida, aconselha ou desaconselha os pontos de conexão aos objetos COM descritos pelas entradas de pia do mapa do dissipador de eventos. Este método de membro também se baseia no fato de `IDispEventImpl` que a classe derivada herda de uma instância de para cada controle no mapa da pia que deve ser aconselhado ou desaconselhado.

## <a name="ccomcompositecontrolcalcextent"></a><a name="calcextent"></a>CComCompositeControl::CalcExtent

Chame este método para calcular o tamanho em unidades HIMETRIC do recurso de diálogo usado para hospedar o controle composto.

```
BOOL CalcExtent(SIZE& size);
```

### <a name="parameters"></a>Parâmetros

*Tamanho*<br/>
Uma referência `SIZE` a uma estrutura a ser preenchida por este método.

### <a name="return-value"></a>Valor retornado

TRUE se o controle estiver hospedado por uma caixa de diálogo; caso contrário, FALSO.

### <a name="remarks"></a>Comentários

O tamanho é devolvido no parâmetro *tamanho.*

## <a name="ccomcompositecontrolcreate"></a><a name="create"></a>CComCompositeControl::Criar

Este método é chamado para criar a janela de controle para o controle composto.

```
HWND Create(
    HWND hWndParent,
    RECT& /* rcPos */,
    LPARAM dwInitParam = NULL);
```

### <a name="parameters"></a>Parâmetros

*Hwndparent*<br/>
Uma alça para a janela dos pais do controle.

*rcPos*<br/>
Reservado.

*dwInitParam*<br/>
Dados a serem passados para o controle durante a criação do controle. Os dados passados como *dwInitParam* aparecerão como o parâmetro LPARAM da mensagem [WM_INITDIALOG,](/windows/win32/dlgbox/wm-initdialog) que será enviada para o controle composto quando for criada.

### <a name="return-value"></a>Valor retornado

Uma alça para a caixa de diálogo de controle composto recém-criada.

### <a name="remarks"></a>Comentários

Este método é geralmente chamado durante a ativação no local do controle.

## <a name="ccomcompositecontrolccomcompositecontrol"></a><a name="ccomcompositecontrol"></a>CComCompositeControl::CComCompositeControl

O construtor.

```
CComCompositeControl();
```

### <a name="remarks"></a>Comentários

Inicializa os membros do [CComCompositeControl::m_hbrBackground](#m_hbrbackground) e [CComCompositeControl::m_hWndFocus](#m_hwndfocus) para NULL.

## <a name="ccomcompositecontrolccomcompositecontrol"></a><a name="dtor"></a>CComCompositeControl::~CComCompositecontrol

O destruidor.

```
~CComCompositeControl();
```

### <a name="remarks"></a>Comentários

Exclui o objeto de fundo, se ele existir.

## <a name="ccomcompositecontrolcreatecontrolwindow"></a><a name="createcontrolwindow"></a>CComCompositeControl::CreateControlWindow

Chame este método para criar a janela de controle e aconselhar quaisquer controles hospedados.

```
virtual HWND CreateControlWindow(
    HWND hWndParent,
    RECT& rcPos);
```

### <a name="parameters"></a>Parâmetros

*Hwndparent*<br/>
Uma alça para a janela dos pais do controle.

*rcPos*<br/>
O retângulo de posição do controle composto nas coordenadas do cliente em relação a *hWndParent*.

### <a name="return-value"></a>Valor retornado

Retorna uma alça para a caixa de diálogo de controle composto recém-criada.

### <a name="remarks"></a>Comentários

Este método chama [CComCompositeControl::Create](#create) e [CComCompositeControl::AdviseSinkMap](#advisesinkmap).

## <a name="ccomcompositecontrolm_hbrbackground"></a><a name="m_hbrbackground"></a>CComCompositeControl::m_hbrBackground

A escova de fundo.

```
HBRUSH m_hbrBackground;
```

## <a name="ccomcompositecontrolm_hwndfocus"></a><a name="m_hwndfocus"></a>CComCompositeControl::m_hWndFocus

A alça da janela que atualmente tem foco.

```
HWND m_hWndFocus;
```

## <a name="ccomcompositecontrolsetbackgroundcolorfromambient"></a><a name="setbackgroundcolorfromambient"></a>ccomcompositecontrol::setbackgroundColorFromambient

Chame este método para definir a cor de fundo do controle composto usando a cor de fundo do contêiner.

```
HRESULT SetBackgroundColorFromAmbient();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK no sucesso, ou um erro HRESULT no fracasso.

## <a name="see-also"></a>Confira também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Fundamentos do controle composto](../../atl/atl-composite-control-fundamentals.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
