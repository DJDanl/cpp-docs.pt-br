---
title: Classe CPaintDC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CPaintDC
dev_langs:
- C++
helpviewer_keywords:
- OnPaint handler
- WM_PAINT message
- CPaintDC class
ms.assetid: 7e245baa-bf9b-403e-a637-7218adf28fab
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
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: b781db7d4a6676e6fc6ad5df7553b9c9a0154ab9
ms.lasthandoff: 02/25/2017

---
# <a name="cpaintdc-class"></a>Classe CPaintDC
Uma classe de contexto de dispositivo derivada de [CDC](../../mfc/reference/cdc-class.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CPaintDC : public CDC  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPaintDC::CPaintDC](#cpaintdc)|Constrói uma `CPaintDC` conectado ao especificado [CWnd](../../mfc/reference/cwnd-class.md).|  
  
### <a name="public-data-members"></a>Membros de Dados Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPaintDC::m_ps](#m_ps)|Contém o [PAINTSTRUCT](../../mfc/reference/paintstruct-structure.md) usados para pintar a área do cliente.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CPaintDC::m_hWnd](#m_hwnd)|O `HWND` ao qual este `CPaintDC` objeto está anexado.|  
  
## <a name="remarks"></a>Comentários  
 Ele executa uma [CWnd::BeginPaint](../../mfc/reference/cwnd-class.md#beginpaint) na ocasião da construção e [CWnd::EndPaint](../../mfc/reference/cwnd-class.md#endpaint) em tempo de destruição.  
  
 A `CPaintDC` objeto só pode ser usado ao responder a uma [WM_PAINT](http://msdn.microsoft.com/library/windows/desktop/dd145213) mensagem, normalmente em seu `OnPaint` função de membro de manipulador de mensagens.  
  
 Para obter mais informações sobre como usar o `CPaintDC`, consulte [contextos de dispositivo](../../mfc/device-contexts.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CDC](../../mfc/reference/cdc-class.md)  
  
 `CPaintDC`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="a-namecpaintdca--cpaintdccpaintdc"></a><a name="cpaintdc"></a>CPaintDC::CPaintDC  
 Constrói uma `CPaintDC` objeto, prepara a janela do aplicativo para pintura e armazena o [PAINTSTRUCT](../../mfc/reference/paintstruct-structure.md) estrutura no [m_ps](#m_ps) variável de membro.  
  
```  
explicit CPaintDC(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 Aponta para a `CWnd` objeto ao qual o `CPaintDC` objeto pertence.  
  
### <a name="remarks"></a>Comentários  
 Uma exceção (do tipo `CResourceException`) é gerada se o Windows [GetDC](http://msdn.microsoft.com/library/windows/desktop/dd144871) chamar falhar. Um contexto de dispositivo pode não estar disponível se Windows já alocado todos seus contextos de dispositivo disponível. Seu aplicativo compete para cinco comuns exibição contextos disponíveis a qualquer momento no Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#97;](../../mfc/codesnippet/cpp/cpaintdc-class_1.cpp)]  
  
##  <a name="a-namemhwnda--cpaintdcmhwnd"></a><a name="m_hwnd"></a>CPaintDC::m_hWnd  
 O `HWND` ao qual este `CPaintDC` objeto está anexado.  
  
```  
HWND m_hWnd;  
```  
  
### <a name="remarks"></a>Comentários  
 `m_hWnd`é uma variável do tipo protegida `HWND`.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#98;](../../mfc/codesnippet/cpp/cpaintdc-class_2.cpp)]  
  
##  <a name="a-namempsa--cpaintdcmps"></a><a name="m_ps"></a>CPaintDC::m_ps  
 `m_ps`é uma variável de membro público do tipo [PAINTSTRUCT](../../mfc/reference/paintstruct-structure.md).  
  
```  
PAINTSTRUCT m_ps;  
```  
  
### <a name="remarks"></a>Comentários  
 É o `PAINTSTRUCT` que é passado para e preenchido por [CWnd::BeginPaint](../../mfc/reference/cwnd-class.md#beginpaint).  
  
 O `PAINTSTRUCT` contém informações que o aplicativo usa para exibir a área de cliente da janela associada uma `CPaintDC` objeto.  
  
 Observe que você pode acessar o identificador de contexto de dispositivo por meio de `PAINTSTRUCT`. No entanto, você pode acessar o identificador mais diretamente por meio de `m_hDC` variável de membro que `CPaintDC` herda de `CDC`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CPaintDC::m_hWnd](#m_hwnd).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Classe CDC](../../mfc/reference/cdc-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




