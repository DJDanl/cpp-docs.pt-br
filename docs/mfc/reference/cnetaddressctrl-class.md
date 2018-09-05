---
title: Classe CNetAddressCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CNetAddressCtrl
- AFXCMN/CNetAddressCtrl
- AFXCMN/CNetAddressCtrl::CNetAddressCtrl
- AFXCMN/CNetAddressCtrl::Create
- AFXCMN/CNetAddressCtrl::CreateEx
- AFXCMN/CNetAddressCtrl::DisplayErrorTip
- AFXCMN/CNetAddressCtrl::GetAddress
- AFXCMN/CNetAddressCtrl::GetAllowType
- AFXCMN/CNetAddressCtrl::SetAllowType
dev_langs:
- C++
helpviewer_keywords:
- CNetAddressCtrl [MFC], CNetAddressCtrl
- CNetAddressCtrl [MFC], Create
- CNetAddressCtrl [MFC], CreateEx
- CNetAddressCtrl [MFC], DisplayErrorTip
- CNetAddressCtrl [MFC], GetAddress
- CNetAddressCtrl [MFC], GetAllowType
- CNetAddressCtrl [MFC], SetAllowType
ms.assetid: cb4c6aca-3f49-4b52-b76c-65f57096155b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 07581805edd92e5b577889c8dfb12c5cf08ac20b
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43680753"
---
# <a name="cnetaddressctrl-class"></a>CNetAddressCtrl Class
O `CNetAddressCtrl` classe representa o controle de endereço de rede, que você pode usar a entrada e validar o formato de IPv4, IPv6 e endereços DNS nomeados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CNetAddressCtrl : public CEdit  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CNetAddressCtrl::CNetAddressCtrl](#cnetaddressctrl)|Constrói um objeto `CNetAddressCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CNetAddressCtrl::Create](#create)|Cria um controle de endereço de rede com estilos especificados e a anexa ao atual `CNetAddressCtrl` objeto.|  
|[CNetAddressCtrl::CreateEx](#createex)|Cria um controle de endereço de rede com estilos estendidos especificados e a anexa ao atual `CNetAddressCtrl` objeto.|  
|[CNetAddressCtrl::DisplayErrorTip](#displayerrortip)|Exibe uma dica de balão do erro quando o usuário insere um endereço de rede sem suporte no controle de endereço de rede atual.|  
|[CNetAddressCtrl::GetAddress](#getaddress)|Recupera uma representação analisada e validada do endereço de rede associado ao controle de endereço de rede atual.|  
|[CNetAddressCtrl::GetAllowType](#getallowtype)|Recupera o tipo de endereço de rede que pode dar suporte a controle de endereço de rede atual.|  
|[CNetAddressCtrl::SetAllowType](#setallowtype)|Define o tipo de endereço de rede que pode dar suporte a controle de endereço de rede atual.|  
  
## <a name="remarks"></a>Comentários  
 O controle de endereço de rede verifica se o formato do endereço que o usuário insere está correto. O controle não realmente se conectar ao endereço da rede. O [CNetAddressCtrl::SetAllowType](#setallowtype) método Especifica um ou mais tipos de endereço que o [CNetAddressCtrl::GetAddress](#getaddress) método pode analisar e verificar. Um endereço pode ser na forma de um IPv4, IPv6 ou endereço nomeado para um servidor, a rede, o host ou o destino da mensagem de difusão. Se o formato do endereço estiver incorreto, você pode usar o [CNetAddressCtrl::DisplayErrorTip](#displayerrortip) método para exibir uma caixa de mensagem InfoDica que aponta para a caixa de texto do controle de endereço de rede graficamente e exibe um modelo predefinido mensagem de erro.  
  
 O `CNetAddressCtrl` classe é derivada de [CEdit](../../mfc/reference/cedit-class.md) classe. Consequentemente, o controle de endereço de rede fornece acesso a todas as mensagens de controle de edição de Windows.  
  
 A figura abaixo mostra uma caixa de diálogo que contém um controle de endereço de rede. O texto caixa (1) para o controle de endereço de rede contém um endereço de rede inválido. A mensagem de InfoDica (2) é exibida se o endereço de rede é inválido.  
  
 ![Caixa de diálogo com um controle de endereço de rede e uma InfoDica. ](../../mfc/reference/media/cnetaddctrl.png "cnetaddctrl")  
  
## <a name="example"></a>Exemplo  
 O exemplo de código a seguir é uma parte de uma caixa de diálogo que valida um endereço de rede. Os manipuladores de eventos para três botões de opção especificam que o endereço de rede pode ser um dos três tipos de endereço. O usuário insere um endereço na caixa de texto do controle de rede e, em seguida, pressiona um botão para validar o endereço. Se o endereço é válido, uma mensagem de êxito será exibida; Caso contrário, é exibida a mensagem de erro predefinidos InfoDica.  
  
 [!code-cpp[NVC_MFC_CNetAddressCtrl_s1#1](../../mfc/reference/codesnippet/cpp/cnetaddressctrl-class_1.cpp)]  
  
## <a name="example"></a>Exemplo  
 O seguinte exemplo de código do arquivo de cabeçalho da caixa de diálogo define a [NC_ADDRESS](/windows/desktop/api/shellapi/ns-shellapi-tagnc_address) e [NET_ADDRESS_INFO](https://msdn.microsoft.com/library/windows/desktop/bb773346) variáveis que são exigidas pelo [CNetAddressCtrl::GetAddress](#getaddress)método.  
  
 [!code-cpp[NVC_MFC_CNetAddressCtrl_s1#2](../../mfc/reference/codesnippet/cpp/cnetaddressctrl-class_2.h)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CEdit](../../mfc/reference/cedit-class.md)  
  
 `CNetAddressCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn. h  
  
 Essa classe tem suporte no Windows Vista e posterior.  
  
 Requisitos adicionais para esta classe são descritos em [compilar requisitos para o Windows Vista controles comuns](../../mfc/build-requirements-for-windows-vista-common-controls.md).  
  
##  <a name="cnetaddressctrl"></a>  CNetAddressCtrl::CNetAddressCtrl  
 Constrói um objeto `CNetAddressCtrl`.  
  
```  
CNetAddressCtrl();
```  
  
### <a name="remarks"></a>Comentários  
 Use o [CNetAddressCtrl::Create](#create) ou [CNetAddressCtrl::CreateEx](#createex) método para criar um controle de rede e anexá-lo para o `CNetAddressCtrl` objeto.  
  
##  <a name="create"></a>  CNetAddressCtrl::Create  
 Cria um controle de endereço de rede com estilos especificados e a anexa ao atual `CNetAddressCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,   
    const RECT& rect,   
    CWnd* pParentWnd,   
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *dwStyle*|Uma combinação bit a bit de estilos a serem aplicados ao controle. Para obter mais informações, consulte [Editar estilos](../../mfc/reference/styles-used-by-mfc.md#edit-styles).|  
|[in] *rect*|Uma referência a um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que contém a posição e o tamanho do controle.|  
|[in] *pParentWnd*|Um ponteiro não nulo para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle.|  
|[in] *nID*|A ID do controle.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
##  <a name="createex"></a>  CNetAddressCtrl::CreateEx  
 Cria um controle de endereço de rede com estilos estendidos especificados e a anexa ao atual `CNetAddressCtrl` objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwExStyle,   
    DWORD dwStyle,   
    const RECT& rect,   
    CWnd* pParentWnd,   
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *dwExStyle*|Uma combinação bit a bit (OR) dos estilos estendidos para ser aplicado ao controle. Para obter mais informações, consulte o *dwExStyle* parâmetro do [CreateWindowEx](/windows/desktop/api/winuser/nf-winuser-createwindowexa) função.|  
|[in] *dwStyle*|Uma combinação bit a bit (OR) de estilos a serem aplicados ao controle. Para obter mais informações, consulte [Editar estilos](../../mfc/reference/styles-used-by-mfc.md#edit-styles).|  
|[in] *rect*|Uma referência a um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que contém a posição e o tamanho do controle.|  
|[in] *pParentWnd*|Um ponteiro não nulo para um [CWnd](../../mfc/reference/cwnd-class.md) objeto que é a janela pai do controle.|  
|[in] *nID*|A ID do controle.|  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se esse método for bem-sucedida; Caso contrário, FALSE.  
  
##  <a name="displayerrortip"></a>  CNetAddressCtrl::DisplayErrorTip  
 Exibe uma mensagem de erro na dica de balão que está associada com o controle de endereço de rede atual.  
  
```  
HRESULT DisplayErrorTip();
```  
  
### <a name="return-value"></a>Valor de retorno  
 O valor `S_OK` se esse método for bem-sucedida; caso contrário, um código de erro.  
  
### <a name="remarks"></a>Comentários  
 Use o [CNetAddressCtrl::SetAllowType](#setallowtype) método para especificar os tipos de endereços que pode dar suporte a controle de endereço de rede atual. Use o [CNetAddressCtrl::GetAddress](#getaddress) método para validar e analisar o endereço de rede que o usuário insere. Use o [CNetAddressCtrl::DisplayErrorTip](#displayerrortip) método para exibir uma InfoDica de mensagem de erro se o [CNetAddressCtrl::GetAddress](#getaddress) método for bem-sucedido.  
  
 Essa mensagem invoca o [NetAddr_DisplayErrorTip](/windows/desktop/api/shellapi/nf-shellapi-netaddr_displayerrortip) macro, que é descrita no SDK do Windows. Essa macro envia o `NCM_DISPLAYERRORTIP` mensagem.  
  
##  <a name="getaddress"></a>  CNetAddressCtrl::GetAddress  
 Recupera uma representação analisada e validada do endereço de rede que está associado com o controle de endereço de rede atual.  
  
```  
HRESULT GetAddress(PNC_ADDRESS pAddress) const;  
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[no, out] *pAddress*|Ponteiro para um [NC_ADDRESS](/windows/desktop/api/shellapi/ns-shellapi-tagnc_address) estrutura.  Defina as *pAddrInfo* membro dessa estrutura para o endereço de uma [NET_ADDRESS_INFO](https://msdn.microsoft.com/library/windows/desktop/bb773346) estrutura antes de chamar o método GetAddress.|  
  
### <a name="return-value"></a>Valor de retorno  
 O valor S_OK se esse método for bem-sucedida; Caso contrário, um código de erro COM. Para obter mais informações sobre possíveis códigos de erro, consulte a seção de retornar o valor da [NetAddr_GetAddress](/windows/desktop/api/shellapi/nf-shellapi-netaddr_getaddress) macro.  
  
### <a name="remarks"></a>Comentários  
 Se esse método for bem-sucedida, o [NET_ADDRESS_INFO](https://msdn.microsoft.com/library/windows/desktop/bb773346) estrutura contém informações adicionais sobre o endereço de rede.  
  
 Use o [CNetAddressCtrl::SetAllowType](#setallowtype) método para especificar os tipos de endereços pode dar suporte a controle de endereço de rede atual. Use o [CNetAddressCtrl::GetAddress](#getaddress) método para validar e analisar o endereço de rede que o usuário insere. Use o [CNetAddressCtrl::DisplayErrorTip](#displayerrortip) método para exibir uma InfoDica de mensagem de erro se o [CNetAddressCtrl::GetAddress](#getaddress) método for bem-sucedido.  
  
 Este método invoca o [NetAddr_GetAddress](/windows/desktop/api/shellapi/nf-shellapi-netaddr_getaddress) macro, que é descrita no SDK do Windows. Essa macro envia a mensagem NCM_GETADDRESS.  
  
##  <a name="getallowtype"></a>  CNetAddressCtrl::GetAllowType  
 Recupera o tipo de endereço de rede que pode dar suporte a controle de endereço de rede atual.  
  
```  
DWORD GetAllowType() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Uma combinação bit a bit (OR) de sinalizadores que especifica os tipos de endereços de controle de endereço de rede pode dar suporte. Para obter mais informações, consulte [NET_STRING](https://msdn.microsoft.com/library/windows/desktop/bb762586).  
  
### <a name="remarks"></a>Comentários  
 Essa mensagem invoca o [NetAddr_GetAllowType](/windows/desktop/api/shellapi/nf-shellapi-netaddr_getallowtype) macro, que é descrita no SDK do Windows. Essa macro envia a mensagem NCM_GETALLOWTYPE.  
  
##  <a name="setallowtype"></a>  CNetAddressCtrl::SetAllowType  
 Define o tipo de endereço de rede que pode dar suporte a controle de endereço de rede atual.  
  
```  
HRESULT SetAllowType(DWORD dwAddrMask);
```  
  
### <a name="parameters"></a>Parâmetros  
  
|Parâmetro|Descrição|  
|---------------|-----------------|  
|[in] *dwAddrMask*|Uma combinação bit a bit (OR) de sinalizadores que especifica os tipos de endereços de controle de endereço de rede pode dar suporte. Para obter mais informações, consulte [NET_STRING](https://msdn.microsoft.com/library/windows/desktop/bb762586).|  
  
### <a name="return-value"></a>Valor de retorno  
 S_OK se esse método for bem-sucedida; Caso contrário, um código de erro COM.  
  
### <a name="remarks"></a>Comentários  
 Use o [CNetAddressCtrl::SetAllowType](#setallowtype) método para especificar os tipos de endereços que pode dar suporte a controle de endereço de rede atual. Use o [CNetAddressCtrl::GetAddress](#getaddress) método para validar e analisar o endereço de rede que o usuário insere. Use o [CNetAddressCtrl::DisplayErrorTip](#displayerrortip) método para exibir uma InfoDica de mensagem de erro se o [CNetAddressCtrl::GetAddress](#getaddress) método for bem-sucedido.  
  
 Essa mensagem invoca o [NetAddr_SetAllowType](/windows/desktop/api/shellapi/nf-shellapi-netaddr_setallowtype) macro, que é descrita no SDK do Windows. Essa macro envia a mensagem NCM_SETALLOWTYPE.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CNetAddressCtrl](../../mfc/reference/cnetaddressctrl-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CEdit](../../mfc/reference/cedit-class.md)
