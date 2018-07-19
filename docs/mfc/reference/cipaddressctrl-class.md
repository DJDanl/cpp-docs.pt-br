---
title: Classe CIPAddressCtrl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CIPAddressCtrl [MFC], CIPAddressCtrl
- CIPAddressCtrl [MFC], ClearAddress
- CIPAddressCtrl [MFC], Create
- CIPAddressCtrl [MFC], CreateEx
- CIPAddressCtrl [MFC], GetAddress
- CIPAddressCtrl [MFC], IsBlank
- CIPAddressCtrl [MFC], SetAddress
- CIPAddressCtrl [MFC], SetFieldFocus
- CIPAddressCtrl [MFC], SetFieldRange
ms.assetid: 9764d2f4-cb14-4ba8-b799-7f57a55a47c6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b6c7d45c36534ab2c67765dc6e4e9ea61b79b3ea
ms.sourcegitcommit: 6408139d5f5ff8928f056bde93d20eecb3520361
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/02/2018
ms.locfileid: "37338026"
---
# <a name="cipaddressctrl-class"></a>Classe CIPAddressCtrl
Fornece a funcionalidade de controle de endereço IP comum do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CIPAddressCtrl : public CWnd  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CIPAddressCtrl::CIPAddressCtrl](#cipaddressctrl)|Constrói um objeto `CIPAddressCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CIPAddressCtrl::ClearAddress](#clearaddress)|Limpa o conteúdo do controle de endereço IP.|  
|[CIPAddressCtrl::Create](#create)|Cria um controle de endereço IP e a anexa a um `CIPAddressCtrl` objeto.|  
|[CIPAddressCtrl::CreateEx](#createex)|Cria um controle de endereço IP com os estilos estendidos do Windows especificados e anexa-o para um `CIPAddressCtrl` objeto.|  
|[CIPAddressCtrl::GetAddress](#getaddress)|Recupera os valores de endereço para todos os quatro campos no controle de endereço IP.|  
|[CIPAddressCtrl::IsBlank](#isblank)|Determina se todos os campos no controle de endereço IP estão vazios.|  
|[CIPAddressCtrl::SetAddress](#setaddress)|Define os valores de endereço para todos os quatro campos no controle de endereço IP.|  
|[CIPAddressCtrl::SetFieldFocus](#setfieldfocus)|Define o foco do teclado para o campo especificado no controle de endereço IP.|  
|[CIPAddressCtrl::SetFieldRange](#setfieldrange)|Define o intervalo no campo especificado no controle de endereço IP.|  
  
## <a name="remarks"></a>Comentários  
 Um controle de endereço IP, um controle semelhante a um controle de edição, permite que você insira e manipular um endereço numérico em formato de IP (Internet Protocol).  
  
 Esse controle (e, portanto, o `CIPAddressCtrl` classe) está disponível somente para programas em execução no Microsoft Internet Explorer 4.0 e posterior. Eles também estarão disponíveis em versões futuras do Windows e Windows NT.  
  
 Para obter mais informações sobre o controle de endereço IP, consulte [controles de endereço IP](http://msdn.microsoft.com/library/windows/desktop/bb761372) no SDK do Windows.  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 `CIPAddressCtrl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcmn. h  
  
##  <a name="cipaddressctrl"></a>  CIPAddressCtrl::CIPAddressCtrl  
 Cria um objeto `CIPAddressCtrl`.  
  
```  
CIPAddressCtrl();
```  
  
##  <a name="clearaddress"></a>  CIPAddressCtrl::ClearAddress  
 Limpa o conteúdo do controle de endereço IP.  
  
```  
void ClearAddress();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [IPM_CLEARADDRESS](http://msdn.microsoft.com/library/windows/desktop/bb761377), conforme descrito no SDK do Windows.  
  
##  <a name="create"></a>  CIPAddressCtrl::Create  
 Cria um controle de endereço IP e a anexa a um `CIPAddressCtrl` objeto.  
  
```  
virtual BOOL Create(
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwStyle*  
 Estilo do controle de endereço IP. Aplica uma combinação de estilos de janela. Você deve incluir o estilo WS_CHILD porque o controle deve ser uma janela filho. Ver [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) no SDK do Windows para obter uma lista de estilos do windows.  
  
 *Rect*  
 Uma referência ao tamanho e a posição do controle de endereço IP. Ela pode ser um [CRect](../../atl-mfc-shared/reference/crect-class.md) objeto ou uma [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura.  
  
 *pParentWnd*  
 Um ponteiro para a janela pai do controle de endereço IP. Ele não deve ser NULL.  
  
 *nID*  
 ID. do controle de endereço IP  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a inicialização foi bem-sucedida; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Você constrói um `CIPAddressCtrl` objeto em duas etapas.  
  
1.  Chame o construtor, que cria o `CIPAddressCtrl` objeto.  
  
2.  Chamar `Create`, que cria o controle de endereço IP.  
  
 Se você quiser usar estilos estendidos do windows com o seu controle, chame [CreateEx](#createex) em vez de `Create`.  
  
##  <a name="createex"></a>  CIPAddressCtrl::CreateEx  
 Chame essa função para criar um controle (uma janela filho) e associá-la com o `CIPAddressCtrl` objeto.  
  
```  
virtual BOOL CreateEx(
    DWORD dwExStyle,  
    DWORD dwStyle,  
    const RECT& rect,  
    CWnd* pParentWnd,  
    UINT nID);
```  
  
### <a name="parameters"></a>Parâmetros  
 *dwExStyle*  
 Especifica o estilo estendido do controle que está sendo criado. Para obter uma lista dos estilos estendidos do Windows, consulte o *dwExStyle* parâmetro para [CreateWindowEx](http://msdn.microsoft.com/library/windows/desktop/ms632680) no SDK do Windows.  
  
 *dwStyle*  
 Estilo do controle de endereço IP. Aplica uma combinação de estilos de janela. Você deve incluir o estilo WS_CHILD porque o controle deve ser uma janela filho. Ver [CreateWindow](http://msdn.microsoft.com/library/windows/desktop/ms632679) no SDK do Windows para obter uma lista de estilos do windows.  
  
 *Rect*  
 Uma referência a um [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que descreve o tamanho e posição da janela a ser criado, em coordenadas do cliente do *pParentWnd*.  
  
 *pParentWnd*  
 Um ponteiro para a janela que é o pai do controle.  
  
 *nID*  
 ID da janela filho. do controle  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se bem-sucedido; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use `CreateEx` em vez de [Create](#create) para aplicar estilos estendidos do Windows, especificados pelo prefácio de estilo estendido do Windows **WS_EX_**.  
  
##  <a name="getaddress"></a>  CIPAddressCtrl::GetAddress  
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
 *nField0*  
 Uma referência ao valor do campo 0 de um endereço IP compactado.  
  
 *nField1*  
 Uma referência ao valor do campo 1 de um endereço IP compactado.  
  
 *nField2*  
 Uma referência ao valor do campo de 2 de um endereço IP compactado.  
  
 *nField3*  
 Uma referência ao valor do campo 3 de um endereço IP compactado.  
  
 *dwAddress*  
 Uma referência para o endereço de um valor DWORD que recebe o endereço IP. Ver **Remarks** para uma tabela que mostra como *dwAddress* é preenchido.  
  
### <a name="return-value"></a>Valor de retorno  
 O número de campos não em branco no controle de endereço IP.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [IPM_GETADDRESS](http://msdn.microsoft.com/library/windows/desktop/bb761378), conforme descrito no SDK do Windows. No primeiro protótipo acima, os números nos campos de 0 a 3 do controle, lidos da esquerda para a direita, respectivamente, preencha os quatro parâmetros. No protótipo acima, segunda *dwAddress* é populado da seguinte maneira.  
  
|Campo|Que contém o valor do campo de bits|  
|-----------|-------------------------------------|  
|0|24 a 31|  
|1|16 por meio do 23|  
|2|8 a 15|  
|3|0 a 7|  
  
##  <a name="isblank"></a>  CIPAddressCtrl::IsBlank  
 Determina se todos os campos no controle de endereço IP estão vazios.  
  
```  
BOOL IsBlank() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se todos os campos de controle de endereço IP estiverem vazios; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [IPM_ISBLANK](http://msdn.microsoft.com/library/windows/desktop/bb761379), conforme descrito no SDK do Windows.  
  
##  <a name="setaddress"></a>  CIPAddressCtrl::SetAddress  
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
 *nField0*  
 O valor do campo 0 de um endereço IP compactado.  
  
 *nField1*  
 O valor do campo 1 de um endereço IP compactado.  
  
 *nField2*  
 O valor do campo 2 de um endereço IP compactado.  
  
 *nField3*  
 O valor do campo 3 de um endereço IP compactado.  
  
 *dwAddress*  
 Um valor DWORD que contém o novo endereço IP. Ver **comentários** para uma tabela que mostra como o valor de DWORD é preenchido.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [IPM_SETADDRESS](http://msdn.microsoft.com/library/windows/desktop/bb761380), conforme descrito no SDK do Windows. No primeiro protótipo acima, os números nos campos de 0 a 3 do controle, lidos da esquerda para a direita, respectivamente, preencha os quatro parâmetros. No protótipo acima, segunda *dwAddress* é populado da seguinte maneira.  
  
|Campo|Que contém o valor do campo de bits|  
|-----------|-------------------------------------|  
|0|24 a 31|  
|1|16 por meio do 23|  
|2|8 a 15|  
|3|0 a 7|  
  
##  <a name="setfieldfocus"></a>  CIPAddressCtrl::SetFieldFocus  
 Define o foco do teclado para o campo especificado no controle de endereço IP.  
  
```  
void SetFieldFocus(WORD nField);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nField*  
 Índice baseado em zero do campo ao qual o foco deve ser definido. Se esse valor for maior que o número de campos, o foco é definido para o primeiro campo em branco. Se todos os campos são não em branco, o foco é definido para o primeiro campo.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [IPM_SETFOCUS](http://msdn.microsoft.com/library/windows/desktop/bb761381), conforme descrito no SDK do Windows.  
  
##  <a name="setfieldrange"></a>  CIPAddressCtrl::SetFieldRange  
 Define o intervalo no campo especificado no controle de endereço IP.  
  
```  
void SetFieldRange(
    int nField,  
    BYTE nLower,  
    BYTE nUpper);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nField*  
 Índice baseado em zero do campo ao qual o intervalo será aplicado.  
  
 *nLower*  
 Uma referência a um número inteiro recebendo o limite inferior do campo especificado neste controle de endereço IP.  
  
 *nUpper*  
 Uma referência a um número inteiro recebendo o limite superior do campo especificado neste controle de endereço IP.  
  
### <a name="remarks"></a>Comentários  
 Essa função membro implementa o comportamento da mensagem do Win32 [IPM_SETRANGE](http://msdn.microsoft.com/library/windows/desktop/bb761382), conforme descrito no SDK do Windows. Use os dois parâmetros, *nLower* e *nUpper*, para indicar os limites superiores e inferiores do campo, em vez da *wRange* parâmetro usado com a mensagem do Win32.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



