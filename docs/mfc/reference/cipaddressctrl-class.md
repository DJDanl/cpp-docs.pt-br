---
title: Classe CIPAddressCtrl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CIPAddressCtrl
- AFXCMN/CIPAddressCtrl
- AFXCMN/CIPAddressCtrl::CIPAddressCtrl
- AFXCMN/CIPAddressCtrl::ClearAddress
- AFXCMN/CIPAddressCtrl::Create
- AFXCMN/CIPAddressCtrl::CreateEx
- AFXCMN/CIPAddressCtrl::GetAddress
- AFXCMN/CIPAddressCtrl::IsBlank
- AFXCMN/CIPAddressCtrl::SetAddress
- AFXCMN/CIPAddressCtrl::SetFieldFocus
- AFXCMN/CIPAddressCtrl::SetFieldRange
dev_langs:
- C++
helpviewer_keywords:
- IP address control
- Internet address edit box
- CIPAddressCtrl class
- Internet protocol address box
- common controls, Internet Explorer 4.0
- Internet Explorer 4.0 common controls
ms.assetid: 9764d2f4-cb14-4ba8-b799-7f57a55a47c6
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: b3849580c7bfd07f241e55cc48144959566d7d09
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cipaddressctrl-class"></a>Classe CIPAddressCtrl
Fornece a funcionalidade do controle de endereço IP comuns do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CIPAddressCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CIPAddressCtrl::CIPAddressCtrl](#cipaddressctrl)|Constrói um objeto `CIPAddressCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CIPAddressCtrl::ClearAddress](#clearaddress)|Limpa o conteúdo do controle de endereço IP.|  
|[CIPAddressCtrl::Create](#create)|Cria um controle de endereço IP e a anexa a um `CIPAddressCtrl` objeto.|  
|[CIPAddressCtrl::CreateEx](#createex)|Cria um controle de endereço IP com os estilos estendidos do Windows especificados e a anexa a um `CIPAddressCtrl` objeto.|  
|[CIPAddressCtrl::GetAddress](#getaddress)|Recupera os valores de endereço para todos os quatro campos no controle de endereço IP.|  
|[CIPAddressCtrl::IsBlank](#isblank)|Determina se todos os campos no controle de endereço IP estão vazios.|  
|[CIPAddressCtrl::SetAddress](#setaddress)|Define os valores de endereço para todos os quatro campos no controle de endereço IP.|  
|[CIPAddressCtrl::SetFieldFocus](#setfieldfocus)|Define o foco do teclado para o campo especificado no controle de endereço IP.|  
|[CIPAddressCtrl::SetFieldRange](#setfieldrange)|Define o intervalo no campo especificado no controle de endereço IP.|  
  
## <a name="remarks"></a>Comentários  
 Um controle de endereço IP, um controle semelhante a um controle de edição permite que você insira e manipular um endereço numérico em formato de IP (Internet Protocol).  
  
 Esse controle (e, portanto, a `CIPAddressCtrl` classe) está disponível apenas para programas em execução no Microsoft Internet Explorer 4.0 e posterior. Eles também estarão disponíveis em versões futuras do Windows e Windows NT.  
  
 Para obter mais informações sobre o controle de endereço IP, consulte [controles de endereço IP](http://msdn.microsoft.com/library/windows/desktop/bb761372) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CIPAddressCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn.h  
  
##  <a name="cipaddressctrl"></a>CIPAddressCtrl::CIPAddressCtrl  
 Cria um objeto `CIPAddressCtrl`.  
  
```  
CIPAddressCtrl();
```  
  
##  <a name="clearaddress"></a>CIPAddressCtrl::ClearAddress  
 Limpa o conteúdo do controle de endereço IP.  
  
```  
void ClearAddress();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [IPM_CLEARADDRESS](http://msdn.microsoft.com/library/windows/desktop/bb761377), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="create"></a>CIPAddressCtrl::Create  
 Cria um controle de endereço IP e a anexa a um `CIPAddressCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwStyle`  
 Estilo do controle de endereço IP. Aplica uma combinação de estilos de janela. Você deve incluir o **WS_CHILD** porque o controle deve ser uma janela filho de estilo. Consulte [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de estilos do windows.  
  
 `rect`  
 Uma referência para o tamanho e a posição do controle de endereço IP. Ele pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura.  
  
 `pParentWnd`  
 Um ponteiro para a janela pai do controle de endereço IP. Ele não deve ser **nulo.**  
  
 `nID`  
 Identificação. do controle de endereço IP  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização foi bem sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você construir um `CIPAddressCtrl` objeto em duas etapas.  
  
1.  Chame o construtor, que cria o `CIPAddressCtrl` objeto.  
  
2.  Chamar **criar**, que cria o controle de endereço IP.  
  
 Se você quiser usar estilos estendidos do windows com o controle, chame [CreateEx](#createex) em vez de **criar**.  
  
##  <a name="createex"></a>CIPAddressCtrl::CreateEx  
 Chame essa função para criar um controle (uma janela filho) e associá-lo a `CIPAddressCtrl` objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwExStyle,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `dwExStyle`  
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o `dwExStyle` parâmetro [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
 `dwStyle`  
 Estilo do controle de endereço IP. Aplica uma combinação de estilos de janela. Você deve incluir o **WS_CHILD** porque o controle deve ser uma janela filho de estilo. Consulte [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) no [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)] para obter uma lista de estilos do windows.  
  
 `rect`  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e a posição da janela deve ser criada, nas coordenadas do cliente de `pParentWnd`.  
  
 `pParentWnd`  
 Um ponteiro para a janela que é o pai do controle.  
  
 `nID`  
 ID da janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se for bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de [criar](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido Windows **WS_EX_**.  
  
##  <a name="getaddress"></a>CIPAddressCtrl::GetAddress  
 Recupera os valores de endereço para todos os quatro campos no controle de endereço IP.  
  
```  
int GetAddress(
    BYTE& nField0,  
    BYTE& nField1,  
    BYTE& nField2,  
    BYTE& nField3);  
  
int GetAddress(DWORD& dwAddress);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nField0`  
 Uma referência para o valor do campo 0 de um endereço IP compactada.  
  
 `nField1`  
 Uma referência para o valor do campo 1 de um endereço IP compactada.  
  
 `nField2`  
 Uma referência para o valor do campo 2 de um endereço IP compactada.  
  
 `nField3`  
 Uma referência para o valor do campo 3 de um endereço IP compactada.  
  
 `dwAddress`  
 Uma referência para o endereço de uma `DWORD` valor que recebe o endereço IP. Consulte **comentários** para uma tabela que mostra como `dwAddress` é preenchido.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de campos de linha em branco no controle de endereço IP.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [IPM_GETADDRESS](http://msdn.microsoft.com/library/windows/desktop/bb761378), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. No primeiro protótipo acima, os números nos campos de 0 a 3 do controle, lidos da esquerda para a direita, respectivamente, preencher os quatro parâmetros. No segundo protótipo acima, `dwAddress` é preenchida da seguinte maneira.  
  
|Campo|Que contém o valor do campo de bits|  
|-----------|-------------------------------------|  
|0|24 a 31|  
|1|16 a 23|  
|2|8 a 15|  
|3|0 a 7|  
  
##  <a name="isblank"></a>CIPAddressCtrl::IsBlank  
 Determina se todos os campos no controle de endereço IP estão vazios.  
  
```  
BOOL IsBlank() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se todos os campos de controle de endereço IP estiverem vazios; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [IPM_ISBLANK](http://msdn.microsoft.com/library/windows/desktop/bb761379), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setaddress"></a>CIPAddressCtrl::SetAddress  
 Define os valores de endereço para todos os quatro campos no controle de endereço IP.  
  
```  
void SetAddress(
    BYTE nField0,  
    BYTE nField1,  
    BYTE nField2,  
    BYTE nField3);  
  
void SetAddress(DWORD dwAddress);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nField0`  
 O valor do campo 0 de um endereço IP compactado.  
  
 `nField1`  
 O valor do campo 1 de um endereço IP compactado.  
  
 `nField2`  
 O valor do campo 2 de um endereço IP compactado.  
  
 `nField3`  
 O valor do campo 3 de um endereço IP compactado.  
  
 `dwAddress`  
 Um `DWORD` valor que contém o novo endereço IP. Consulte **comentários** para uma tabela que mostra como o `DWORD` valor é preenchido.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [IPM_SETADDRESS](http://msdn.microsoft.com/library/windows/desktop/bb761380), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. No primeiro protótipo acima, os números nos campos de 0 a 3 do controle, lidos da esquerda para a direita, respectivamente, preencher os quatro parâmetros. No segundo protótipo acima, `dwAddress` é preenchida da seguinte maneira.  
  
|Campo|Que contém o valor do campo de bits|  
|-----------|-------------------------------------|  
|0|24 a 31|  
|1|16 a 23|  
|2|8 a 15|  
|3|0 a 7|  
  
##  <a name="setfieldfocus"></a>CIPAddressCtrl::SetFieldFocus  
 Define o foco do teclado para o campo especificado no controle de endereço IP.  
  
```  
void SetFieldFocus(WORD nField);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nField`  
 Índice do campo com base em zero para o qual o foco deve ser definido. Se esse valor for maior que o número de campos, o foco será definido para o primeiro campo em branco. Se todos os campos são não em branco, o foco será definido para o primeiro campo.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [IPM_SETFOCUS](http://msdn.microsoft.com/library/windows/desktop/bb761381), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)].  
  
##  <a name="setfieldrange"></a>CIPAddressCtrl::SetFieldRange  
 Define o intervalo no campo especificado no controle de endereço IP.  
  
```  
void SetFieldRange(
    int nField,  
    BYTE nLower,  
    BYTE nUpper);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nField`  
 Índice do campo com base em zero para o qual o intervalo será aplicado.  
  
 `nLower`  
 Uma referência a um número inteiro recebendo o limite inferior do campo especificado neste controle de endereço IP.  
  
 `nUpper`  
 Uma referência a um número inteiro recebendo o limite superior do campo especificado neste controle de endereço IP.  
  
### <a name="remarks"></a>Comentários  
 Essa função de membro implementa o comportamento da mensagem Win32 [IPM_SETRANGE](http://msdn.microsoft.com/library/windows/desktop/bb761382), conforme descrito na [!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]. Use os dois parâmetros, `nLower` e `nUpper`, para indicar os limites inferiores e superiores do campo, em vez do *wRange* parâmetro usado com a mensagem do Win32.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




