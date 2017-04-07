---
title: Classe CClientDC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CClientDC
- AFXWIN/CClientDC
- AFXWIN/CClientDC::CClientDC
- AFXWIN/CClientDC::m_hWnd
dev_langs:
- C++
helpviewer_keywords:
- CClientDC class
- device contexts, client area
- client-area device context
- CDC class, device contexts for client areas
ms.assetid: 8a871d6b-06f8-496e-9fa3-9a5780848369
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
ms.openlocfilehash: 619bed4d31994bde8464ad710e9f050d6ba0696a
ms.lasthandoff: 02/25/2017

---
# <a name="cclientdc-class"></a>Classe CClientDC
Se encarrega de chamar as funções do Windows [GetDC](http://msdn.microsoft.com/library/windows/desktop/dd144871) na ocasião da construção e [ReleaseDC](http://msdn.microsoft.com/library/windows/desktop/dd162920) em tempo de destruição.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CClientDC : public CDC  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CClientDC::CClientDC](#cclientdc)|Constrói uma `CClientDC` objeto conectado para o `CWnd`.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CClientDC::m_hWnd](#m_hwnd)|O `HWND` da janela para o qual o `CClientDC` é válido.|  
  
## <a name="remarks"></a>Comentários  
 Isso significa que o contexto de dispositivo associado um `CClientDC` objeto é a área de cliente de uma janela.  
  
 Para obter mais informações sobre `CClientDC`, consulte [contextos de dispositivo](../../mfc/device-contexts.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CDC](../../mfc/reference/cdc-class.md)  
  
 `CClientDC`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  
  
##  <a name="cclientdc"></a>CClientDC::CClientDC  
 Constrói uma `CClientDC` objeto que acessa a área do cliente do [CWnd](../../mfc/reference/cwnd-class.md) apontada por `pWnd`.  
  
```  
explicit CClientDC(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 A janela cuja área cliente acessará o objeto de contexto de dispositivo.  
  
### <a name="remarks"></a>Comentários  
 O construtor chama a função do Windows [GetDC](http://msdn.microsoft.com/library/windows/desktop/dd144871).  
  
 Uma exceção (do tipo `CResourceException`) é gerada se o Windows `GetDC` chamada falhará. Um contexto de dispositivo pode não estar disponível se Windows já alocado todos seus contextos de dispositivo disponível. Seu aplicativo compete para cinco comuns exibição contextos disponíveis a qualquer momento no Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&42;](../../mfc/codesnippet/cpp/cclientdc-class_1.cpp)]  
  
##  <a name="m_hwnd"></a>CClientDC::m_hWnd  
 O `HWND` do `CWnd` ponteiro usado para construir o `CClientDC` objeto.  
  
```  
HWND m_hWnd;  
```  
  
### <a name="remarks"></a>Comentários  
 `m_hWnd`é uma variável protegida.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CClientDC::CClientDC](#cclientdc).  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC MDI](../../visual-cpp-samples.md)   
 [Classe CDC](../../mfc/reference/cdc-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDC](../../mfc/reference/cdc-class.md)

