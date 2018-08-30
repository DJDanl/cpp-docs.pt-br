---
title: Classe CComCompositeControl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- CComCompositeControl class
- composite controls, CComCompositeControl class
ms.assetid: 1304b931-27e8-4fbc-be8e-bb226ad887fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 892cccea65b9e1b6f0c1eec21d3973e84a0fba03
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43223253"
---
# <a name="ccomcompositecontrol-class"></a>Classe CComCompositeControl
Essa classe fornece os métodos necessários para implementar um controle composto.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T>  
class CComCompositeControl : public CComControl<T,CAxDialogImpl<T>>
```  
  
#### <a name="parameters"></a>Parâmetros  
 *T*  
 Sua classe, derivada de [CComObjectRoot](../../atl/reference/ccomobjectroot-class.md) ou [CComObjectRootEx](../../atl/reference/ccomobjectrootex-class.md), bem como de outras interfaces que você desejar dar suporte para controle de composição.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCompositeControl::CComCompositeControl](#ccomcompositecontrol)|O construtor.|  
|[CComCompositeControl:: ~ CComCompositeControl](#dtor)|O destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCompositeControl::AdviseSinkMap](#advisesinkmap)|Chame esse método para recomendar ou não recomendar a todos os controles hospedados pelo controle de composição.|  
|[CComCompositeControl::CalcExtent](#calcextent)|Chame esse método para calcular o tamanho em unidades HIMETRIC do recurso da caixa de diálogo usado para hospedar o controle de composição.|  
|[CComCompositeControl::Create](#create)|Esse método é chamado para criar a janela de controle para o controle composto.|  
|[CComCompositeControl::CreateControlWindow](#createcontrolwindow)|Chame esse método para criar a janela de controle e aconselha qualquer controle hospedado.|  
|[CComCompositeControl::SetBackgroundColorFromAmbient](#setbackgroundcolorfromambient)|Chame esse método para definir a cor do plano de fundo do controle composto usando a cor do plano de fundo do contêiner.|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CComCompositeControl::m_hbrBackground](#m_hbrbackground)|O pincel do plano de fundo.|  
|[CComCompositeControl::m_hWndFocus](#m_hwndfocus)|O identificador da janela que tem foco no momento.|  
  
## <a name="remarks"></a>Comentários  
 Classes derivadas da classe `CComCompositeControl` herdar a funcionalidade de um controle composto do ActiveX. Controles ActiveX que derivado de `CComCompositeControl` são hospedados por uma caixa de diálogo padrão. Esses tipos de controles são chamados de controles de composição porque eles são capazes de hospedar outros controles (controles nativos do Windows e controles ActiveX).  
  
 `CComCompositeControl` identifica o recurso de caixa de diálogo para usar na criação do controle composto procurando por um membro de dados enumerados na classe filho. O membro IDD dessa classe filho é definido como a ID de recurso do recurso da caixa de diálogo que será usado como a janela do controle. A seguir está um exemplo de membro de dados que a classe derivada de `CComCompositeControl` deve conter para identificar o recurso de caixa de diálogo a ser usado para a janela do controle:  
  
 [!code-cpp[NVC_ATL_COM#13](../../atl/codesnippet/cpp/ccomcompositecontrol-class_1.h)]  
  
> [!NOTE]
>  Controles de composição são sempre controles em janelas, embora possam conter controles sem janelas.  
  
 Um controle implementado por um `CComCompositeControl`-classe derivada tem um padrão de comportamento interno uso da tecla TAB. Quando o controle recebe o foco está sendo tabulado em um aplicativo recipiente, sucessivamente, pressionando a tecla TAB fará com que o foco para ser alternado em todos os controles de independentes do controle composto, em seguida, fora do controle de composição e para o próximo item no ordem de tabulação do contêiner. A ordem de tabulação dos controles hospedados é determinada pelo recurso de caixa de diálogo e determina a ordem na qual a tabulação ocorrerá.  
  
> [!NOTE]
>  Para que os aceleradores funcione corretamente com um `CComCompositeControl`, é necessário carregar uma tabela de aceleradores, como o controle é criado, passe o identificador e o número de aceleradores de volta ao [IOleControlImpl::GetControlInfo](../../atl/reference/iolecontrolimpl-class.md#getcontrolinfo), e Finalmente, destrua a tabela quando o controle é liberado.  
  
## <a name="example"></a>Exemplo  
 [!code-cpp[NVC_ATL_COM#14](../../atl/codesnippet/cpp/ccomcompositecontrol-class_2.h)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 `WinBase`  
  
 [CComControlBase](../../atl/reference/ccomcontrolbase-class.md)  
  
 [CComControl](../../atl/reference/ccomcontrol-class.md)  
  
 `CComCompositeControl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlctl.h  
  
##  <a name="advisesinkmap"></a>  CComCompositeControl::AdviseSinkMap  
 Chame esse método para recomendar ou não recomendar a todos os controles hospedados pelo controle de composição.  
  
```
HRESULT AdviseSinkMap(bool bAdvise);
```  
  
### <a name="parameters"></a>Parâmetros  
 *bAdvise*  
 True se todos os controles devem ser avisado; Caso contrário, false.  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK  
 Todos os controles no caso de mapa coletor foram conectado ou desconectado de sua origem de evento com êxito.  
  
 E_FAIL  
 Nem todos os controles no caso de mapa coletor pode ser conectado ou desconectado de sua origem de evento com êxito.  
  
 E_POINTER  
 Esse erro geralmente indica um problema com uma entrada no mapa de coletor de evento do controle ou um problema com um argumento de modelo usado em uma `IDispEventImpl` ou `IDispEventSimpleImpl` classe base.  
  
 CONNECT_E_ADVISELIMIT  
 O ponto de conexão já atingiu seu limite de conexões e não pode aceitar mais nenhuma.  
  
 CONNECT_E_CANNOTCONNECT  
 O coletor não oferece suporte a interface necessária por esse ponto de conexão.  
  
 CONNECT_E_NOCONNECTION  
 O valor do cookie não representa uma conexão válida. Esse erro geralmente indica um problema com uma entrada no mapa de coletor de evento do controle ou um problema com um argumento de modelo usado em uma `IDispEventImpl` ou `IDispEventSimpleImpl` classe base.  
  
### <a name="remarks"></a>Comentários  
 A implementação base desse método procura pelas entradas no evento mapa coletor. Em seguida, ele avisa ou unadvises os pontos de conexão para os objetos COM descrito pelas entradas de coletor do mapa de coletor de eventos. Esse método de membro também se baseia no fato de que a classe derivada herda de uma instância do `IDispEventImpl` para cada controle no mapa de coletor que deve ser aconselhável ou unadvised.  
  
##  <a name="calcextent"></a>  CComCompositeControl::CalcExtent  
 Chame esse método para calcular o tamanho em unidades HIMETRIC do recurso da caixa de diálogo usado para hospedar o controle de composição.  
  
```
BOOL CalcExtent(SIZE& size);
```  
  
### <a name="parameters"></a>Parâmetros  
 *size*  
 Uma referência a um `SIZE` estrutura a ser preenchida por este método.  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se o controle for hospedado por uma caixa de diálogo Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 O tamanho é retornado na *tamanho* parâmetro.  
  
##  <a name="create"></a>  CComCompositeControl::Create  
 Esse método é chamado para criar a janela de controle para o controle composto.  
  
```
HWND Create(
    HWND hWndParent,
    RECT& /* rcPos */,
    LPARAM dwInitParam = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hWndParent*  
 Um identificador para a janela pai do controle.  
  
 *rcPos*  
 Reservado.  
  
 *dwInitParam*  
 Dados a serem passados para o controle durante a criação do controle. Os dados passados como *dwInitParam* será exibida como o parâmetro LPARAM do [WM_INITDIALOG](/windows/desktop/dlgbox/wm-initdialog) mensagem, que será enviada ao controle de composição quando ela é criada.  
  
### <a name="return-value"></a>Valor de retorno  
 Um identificador para a caixa de diálogo controle de composição criado recentemente.  
  
### <a name="remarks"></a>Comentários  
 Geralmente, esse método é chamado durante a ativação no local do controle.  
  
##  <a name="ccomcompositecontrol"></a>  CComCompositeControl::CComCompositeControl  
 O construtor.  
  
```
CComCompositeControl();
```  
  
### <a name="remarks"></a>Comentários  
 Inicializa o [CComCompositeControl::m_hbrBackground](#m_hbrbackground) e [CComCompositeControl::m_hWndFocus](#m_hwndfocus) membros de dados como NULL.  
  
##  <a name="dtor"></a>  CComCompositeControl:: ~ CComCompositeControl  
 O destruidor.  
  
```
~CComCompositeControl();
```  
  
### <a name="remarks"></a>Comentários  
 Exclui o objeto de plano de fundo, caso ela exista.  
  
##  <a name="createcontrolwindow"></a>  CComCompositeControl::CreateControlWindow  
 Chame esse método para criar a janela de controle e aconselha todos os controles hospedados.  
  
```
virtual HWND CreateControlWindow(
    HWND hWndParent,
    RECT& rcPos);
```  
  
### <a name="parameters"></a>Parâmetros  
 *hWndParent*  
 Um identificador para a janela pai do controle.  
  
 *rcPos*  
 O retângulo de posição do controle de composição no cliente coordena relativo a *hWndParent*.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um identificador para a caixa de diálogo controle de composição criado recentemente.  
  
### <a name="remarks"></a>Comentários  
 Este método chama [CComCompositeControl::Create](#create) e [CComCompositeControl::AdviseSinkMap](#advisesinkmap).  
  
##  <a name="m_hbrbackground"></a>  CComCompositeControl::m_hbrBackground  
 O pincel do plano de fundo.  
  
```
HBRUSH m_hbrBackground;
```  
  
##  <a name="m_hwndfocus"></a>  CComCompositeControl::m_hWndFocus  
 O identificador da janela que tem foco no momento.  
  
```
HWND m_hWndFocus;
```  
  
##  <a name="setbackgroundcolorfromambient"></a>  CComCompositeControl::SetBackgroundColorFromAmbient  
 Chame esse método para definir a cor do plano de fundo do controle composto usando a cor do plano de fundo do contêiner.  
  
```
HRESULT SetBackgroundColorFromAmbient();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK no êxito ou um erro HRESULT em caso de falha.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CComControl](../../atl/reference/ccomcontrol-class.md)   
 [Fundamentos do controle composto](../../atl/atl-composite-control-fundamentals.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
