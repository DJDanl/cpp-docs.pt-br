---
title: Classe CPaintDC | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPaintDC
- AFXWIN/CPaintDC
- AFXWIN/CPaintDC::CPaintDC
- AFXWIN/CPaintDC::m_ps
- AFXWIN/CPaintDC::m_hWnd
dev_langs:
- C++
helpviewer_keywords:
- CPaintDC [MFC], CPaintDC
- CPaintDC [MFC], m_ps
- CPaintDC [MFC], m_hWnd
ms.assetid: 7e245baa-bf9b-403e-a637-7218adf28fab
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 451cc5690e871c1292f0a8ff2450eca950ada65b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cpaintdc-class"></a>Classe CPaintDC
Uma classe de contexto de dispositivo derivada de [CDC](../../mfc/reference/cdc-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPaintDC : public CDC  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPaintDC::CPaintDC](#cpaintdc)|Constrói um `CPaintDC` conectado especificado [CWnd](../../mfc/reference/cwnd-class.md).|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPaintDC::m_ps](#m_ps)|Contém o [PAINTSTRUCT](../../mfc/reference/paintstruct-structure.md) usados para pintar a área cliente.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPaintDC::m_hWnd](#m_hwnd)|O `HWND` ao qual este `CPaintDC` objeto está anexado.|  
  
## <a name="remarks"></a>Comentários  
 Ele executa um [CWnd::BeginPaint](../../mfc/reference/cwnd-class.md#beginpaint) em tempo de construção e [CWnd::EndPaint](../../mfc/reference/cwnd-class.md#endpaint) em tempo de destruição.  
  
 Um `CPaintDC` objeto só pode ser usado ao responder a uma [WM_PAINT](http://msdn.microsoft.com/library/windows/desktop/dd145213) mensagem, normalmente em seu `OnPaint` função de membro de manipulador de mensagens.  
  
 Para obter mais informações sobre como usar `CPaintDC`, consulte [contextos de dispositivo](../../mfc/device-contexts.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CDC](../../mfc/reference/cdc-class.md)  
  
 `CPaintDC`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
  
##  <a name="cpaintdc"></a>CPaintDC::CPaintDC  
 Constrói um `CPaintDC` objeto prepara a janela do aplicativo para pintura e armazena o [PAINTSTRUCT](../../mfc/reference/paintstruct-structure.md) estrutura no [m_ps](#m_ps) variável de membro.  
  
```  
explicit CPaintDC(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para o `CWnd` objeto ao qual o `CPaintDC` objeto pertence.  
  
### <a name="remarks"></a>Comentários  
 Uma exceção (do tipo `CResourceException`) é gerada se o Windows [GetDC](http://msdn.microsoft.com/library/windows/desktop/dd144871) chamada falhará. Um contexto de dispositivo pode não estar disponível se o Windows já alocado todos os seus contextos de dispositivo disponível. Seu aplicativo compete para os cinco comuns contextos de exibição disponíveis a qualquer momento no Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#97](../../mfc/codesnippet/cpp/cpaintdc-class_1.cpp)]  
  
##  <a name="m_hwnd"></a>CPaintDC::m_hWnd  
 O `HWND` ao qual este `CPaintDC` objeto está anexado.  
  
```  
HWND m_hWnd;  
```  
  
### <a name="remarks"></a>Comentários  
 `m_hWnd`é uma variável protegida do tipo `HWND`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView#98](../../mfc/codesnippet/cpp/cpaintdc-class_2.cpp)]  
  
##  <a name="m_ps"></a>CPaintDC::m_ps  
 `m_ps`é uma variável de membro público do tipo [PAINTSTRUCT](../../mfc/reference/paintstruct-structure.md).  
  
```  
PAINTSTRUCT m_ps;  
```  
  
### <a name="remarks"></a>Comentários  
 É o `PAINTSTRUCT` que é passado para e preenchido por [CWnd::BeginPaint](../../mfc/reference/cwnd-class.md#beginpaint).  
  
 O `PAINTSTRUCT` contém informações que o aplicativo usa para exibir a área de cliente da janela associada com um `CPaintDC` objeto.  
  
 Observe que você pode acessar o identificador de contexto de dispositivo por meio de `PAINTSTRUCT`. No entanto, você pode acessar o identificador mais diretamente por meio de `m_hDC` variável de membro que `CPaintDC` herda de `CDC`.  
  
### <a name="example"></a>Exemplo  
  Consulte o exemplo para [CPaintDC::m_hWnd](#m_hwnd).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Classe CDC](../../mfc/reference/cdc-class.md)   
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



