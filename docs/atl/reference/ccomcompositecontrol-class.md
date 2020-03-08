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
ms.openlocfilehash: b57eaf105bfca1a49d53b5e5e99969b0fa2fc82f
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78864938"
---
# <a name="ccomcompositecontrol-class"></a>Classe CComCompositeControl

Essa classe fornece os métodos necessários para implementar um controle composto.

> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados no Windows Runtime.

## <a name="syntax"></a>Sintaxe

```
template <class T>
class CComCompositeControl : public CComControl<T,CAxDialogImpl<T>>
```

#### <a name="parameters"></a>Parâmetros

*T*<br/>
Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de quaisquer outras interfaces às quais você deseja dar suporte para seu controle composto.

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CComCompositeControl::CComCompositeControl](#ccomcompositecontrol)|O construtor.|
|[CComCompositeControl:: ~ CComCompositeControl](#dtor)|O destruidor.|

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CComCompositeControl::AdviseSinkMap](#advisesinkmap)|Chame esse método para aconselhar ou cancelar todos os controles hospedados pelo controle composto.|
|[CComCompositeControl::CalcExtent](#calcextent)|Chame esse método para calcular o tamanho em unidades HIMETRIC do recurso de caixa de diálogo usado para hospedar o controle composto.|
|[CComCompositeControl:: criar](#create)|Esse método é chamado para criar a janela de controle para o controle composto.|
|[CComCompositeControl::CreateControlWindow](#createcontrolwindow)|Chame esse método para criar a janela de controle e aconselhar qualquer controle hospedado.|
|[CComCompositeControl::SetBackgroundColorFromAmbient](#setbackgroundcolorfromambient)|Chame esse método para definir a cor do plano de fundo do controle composto usando a cor do plano de fundo do contêiner.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[CComCompositeControl:: m_hbrBackground](#m_hbrbackground)|O pincel de plano de fundo.|
|[CComCompositeControl:: m_hWndFocus](#m_hwndfocus)|O identificador da janela que atualmente tem foco.|

## <a name="remarks"></a>Comentários

Classes derivadas da classe `CComCompositeControl` herdam a funcionalidade de um controle composto do ActiveX. Os controles ActiveX derivados de `CComCompositeControl` são hospedados por uma caixa de diálogo padrão. Esses tipos de controles são chamados de controles compostos porque são capazes de hospedar outros controles (controles nativos do Windows e controles ActiveX).

`CComCompositeControl` identifica o recurso de caixa de diálogo a ser usado na criação do controle composto procurando um membro de dados enumerados na classe filho. O membro IDD dessa classe filho é definido como a ID de recurso do recurso de caixa de diálogo que será usado como a janela do controle. Veja a seguir um exemplo do membro de dados que a classe derivada de `CComCompositeControl` deve conter para identificar o recurso de caixa de diálogo a ser usado para a janela do controle:

[!code-cpp[NVC_ATL_COM#13](../../atl/codesnippet/cpp/ccomcompositecontrol-class_1.h)]

> [!NOTE]
>  Os controles compostos sempre são controles em janela, embora possam conter controles sem janela.

Um controle implementado por uma classe derivada de `CComCompositeControl`tem um comportamento de tabulação padrão interno. Quando o controle recebe o foco, sendo tabulado para em um aplicativo de contenção, pressionar sucessivamente a tecla TAB fará com que o foco seja alternado por todos os controles contidos do controle composto, então, do controle composto e para o próximo item da ordem de tabulação do contêiner. A ordem de tabulação dos controles hospedados é determinada pelo recurso de caixa de diálogo e determina a ordem em que ocorrerá a tabulação.

> [!NOTE]
>  Para que os aceleradores funcionem corretamente com um `CComCompositeControl`, é necessário carregar uma tabela de acelerador à medida que o controle é criado, passar o identificador e o número de aceleradores de volta para [IOleControlImpl:: GetControlInfo](../../atl/reference/iolecontrolimpl-class.md#getcontrolinfo)e, finalmente, destruir a tabela quando o controle for liberado.

## <a name="example"></a>{1&gt;Exemplo&lt;1}

[!code-cpp[NVC_ATL_COM#14](../../atl/codesnippet/cpp/ccomcompositecontrol-class_2.h)]

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

`WinBase`

[CComControlBase](../../atl/reference/ccomcontrolbase-class.md)

[CComControl](../../atl/reference/ccomcontrol-class.md)

`CComCompositeControl`

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** atlctl. h

##  <a name="advisesinkmap"></a>CComCompositeControl::AdviseSinkMap

Chame esse método para aconselhar ou cancelar todos os controles hospedados pelo controle composto.

```
HRESULT AdviseSinkMap(bool bAdvise);
```

### <a name="parameters"></a>Parâmetros

*bAdvise*<br/>
True se todos os controles forem aconselhados; caso contrário, false.

### <a name="return-value"></a>Valor retornado

|||
|-|-|
|S_OK  |Todos os controles no mapa do coletor de eventos foram conectados ou desconectados da origem do evento com êxito.|
|{1&gt;E_FAIL&lt;1}  |Nem todos os controles no mapa do coletor de eventos podem ser conectados ou desconectados da origem do evento com êxito.|
|{1&gt;E_POINTER&lt;1}  |Esse erro geralmente indica um problema com uma entrada no mapa do coletor de eventos do controle ou um problema com um argumento de modelo usado em uma classe base `IDispEventImpl` ou `IDispEventSimpleImpl`.|
|CONNECT_E_ADVISELIMIT  |O ponto de conexão já atingiu seu limite de conexões e não pode aceitar mais nenhuma.|
|CONNECT_E_CANNOTCONNECT  |O coletor não dá suporte à interface exigida por este ponto de conexão.|
|CONNECT_E_NOCONNECTION  |O valor do cookie não representa uma conexão válida. Esse erro geralmente indica um problema com uma entrada no mapa do coletor de eventos do controle ou um problema com um argumento de modelo usado em uma classe base `IDispEventImpl` ou `IDispEventSimpleImpl`.|

### <a name="remarks"></a>Comentários

A implementação base desse método pesquisa as entradas no mapa do coletor de eventos. Em seguida, ele aconselha ou desaconselha os pontos de conexão com os objetos COM descritos pelas entradas de coletor do mapa do coletor de eventos. Esse método de membro também se baseia no fato de que a classe derivada herda de uma instância do `IDispEventImpl` para cada controle no mapa do coletor que deve ser avisado ou não-aconselhado.

##  <a name="calcextent"></a>CComCompositeControl::CalcExtent

Chame esse método para calcular o tamanho em unidades HIMETRIC do recurso de caixa de diálogo usado para hospedar o controle composto.

```
BOOL CalcExtent(SIZE& size);
```

### <a name="parameters"></a>Parâmetros

*size*<br/>
Uma referência a uma estrutura de `SIZE` a ser preenchida por este método.

### <a name="return-value"></a>Valor retornado

TRUE se o controle for hospedado por uma caixa de diálogo; caso contrário, FALSE.

### <a name="remarks"></a>Comentários

O tamanho é retornado no parâmetro *size* .

##  <a name="create"></a>CComCompositeControl:: criar

Esse método é chamado para criar a janela de controle para o controle composto.

```
HWND Create(
    HWND hWndParent,
    RECT& /* rcPos */,
    LPARAM dwInitParam = NULL);
```

### <a name="parameters"></a>Parâmetros

*hWndParent*<br/>
Um identificador para a janela pai do controle.

*rcPos*<br/>
Reservado.

*dwInitParam*<br/>
Dados a serem passados para o controle durante a criação do controle. Os dados passados como *dwInitParam* serão exibidos como o parâmetro lParam da mensagem de [WM_INITDIALOG](/windows/win32/dlgbox/wm-initdialog) , que será enviada ao controle composto quando ele for criado.

### <a name="return-value"></a>Valor retornado

Um identificador para a caixa de diálogo controle composto recém-criado.

### <a name="remarks"></a>Comentários

Esse método é geralmente chamado durante a ativação in-loco do controle.

##  <a name="ccomcompositecontrol"></a>CComCompositeControl::CComCompositeControl

O construtor.

```
CComCompositeControl();
```

### <a name="remarks"></a>Comentários

Inicializa os membros de dados [CComCompositeControl:: m_hbrBackground](#m_hbrbackground) e [CComCompositeControl:: m_hWndFocus](#m_hwndfocus) como NULL.

##  <a name="dtor"></a>CComCompositeControl:: ~ CComCompositeControl

O destruidor.

```
~CComCompositeControl();
```

### <a name="remarks"></a>Comentários

Exclui o objeto de plano de fundo, se ele existir.

##  <a name="createcontrolwindow"></a>CComCompositeControl::CreateControlWindow

Chame esse método para criar a janela de controle e avisar os controles hospedados.

```
virtual HWND CreateControlWindow(
    HWND hWndParent,
    RECT& rcPos);
```

### <a name="parameters"></a>Parâmetros

*hWndParent*<br/>
Um identificador para a janela pai do controle.

*rcPos*<br/>
O retângulo de posição do controle composto em coordenadas de cliente em relação a *hwndParent*.

### <a name="return-value"></a>Valor retornado

Retorna um identificador para a caixa de diálogo de controle composto recém-criada.

### <a name="remarks"></a>Comentários

Esse método chama [CComCompositeControl:: Create](#create) e [CComCompositeControl:: AdviseSinkMap](#advisesinkmap).

##  <a name="m_hbrbackground"></a>CComCompositeControl:: m_hbrBackground

O pincel de plano de fundo.

```
HBRUSH m_hbrBackground;
```

##  <a name="m_hwndfocus"></a>CComCompositeControl:: m_hWndFocus

O identificador da janela que atualmente tem foco.

```
HWND m_hWndFocus;
```

##  <a name="setbackgroundcolorfromambient"></a>CComCompositeControl::SetBackgroundColorFromAmbient

Chame esse método para definir a cor do plano de fundo do controle composto usando a cor do plano de fundo do contêiner.

```
HRESULT SetBackgroundColorFromAmbient();
```

### <a name="return-value"></a>Valor retornado

Retorna S_OK em caso de êxito ou um erro HRESULT em caso de falha.

## <a name="see-also"></a>Consulte também

[Classe CComControl](../../atl/reference/ccomcontrol-class.md)<br/>
[Fundamentos do controle composto](../../atl/atl-composite-control-fundamentals.md)<br/>
[Visão geral da classe](../../atl/atl-class-overview.md)
