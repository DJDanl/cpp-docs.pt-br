---
title: Classe CWindowDC | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CWindowDC
dev_langs:
- C++
helpviewer_keywords:
- device contexts, window
- screen output classes
- CWindowDC class
ms.assetid: 876a3641-4cde-471c-b0d1-fe58b32af79c
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
ms.openlocfilehash: 8a941e1b6f8a398706498ec5d1ce1bfc9156f115
ms.lasthandoff: 02/25/2017

---
# <a name="cwindowdc-class"></a>Classe de CWindowDC
Derivado de `CDC`.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CWindowDC : public CDC  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWindowDC::CWindowDC](#cwindowdc)|Constrói um objeto `CWindowDC`.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWindowDC::m_hWnd](#m_hwnd)|O `HWND` nos quais essa `CWindowDC` é anexado.|  
  
## <a name="remarks"></a>Comentários  
 Chama a função do Windows [GetWindowDC](http://msdn.microsoft.com/library/windows/desktop/dd144947\(v=vs.85\).aspx)na ocasião da construção e [ReleaseDC](http://msdn.microsoft.com/library/windows/desktop/dd162920\(v=vs.85\).aspx) em tempo de destruição. Isso significa que uma `CWindowDC` objeto acessa a área da tela inteira de uma [CWnd](../../mfc/reference/cwnd-class.md) (áreas cliente e não cliente).  
  
 Para obter mais informações sobre como usar o `CWindowDC`, consulte [contextos de dispositivo](../../mfc/device-contexts.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CDC](../../mfc/reference/cdc-class.md)  
  
 `CWindowDC`  
  
## <a name="requirements"></a>Requisitos  
 Cabeçalho: afxwin. h  
  
##  <a name="a-namecwindowdca--cwindowdccwindowdc"></a><a name="cwindowdc"></a>CWindowDC::CWindowDC  
 Constrói uma `CWindowDC` que acessa a área da tela inteira (cliente e não cliente) do objeto de `CWnd` objeto apontado por `pWnd`.  
  
```  
explicit CWindowDC(CWnd* pWnd);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pWnd`  
 A janela cuja área cliente acessará o objeto de contexto de dispositivo.  
  
### <a name="remarks"></a>Comentários  
 O construtor chama a função do Windows [GetWindowDC](http://msdn.microsoft.com/library/windows/desktop/dd144947).  
  
 Uma exceção (do tipo `CResourceException`) é gerada se o Windows `GetWindowDC` chamada falhará. Um contexto de dispositivo pode não estar disponível se Windows já alocado todos seus contextos de dispositivo disponível. Seu aplicativo compete para cinco comuns exibição contextos disponíveis a qualquer momento no Windows.  
  
### <a name="example"></a>Exemplo  
 [!code-cpp[NVC_MFCDocView&#188;](../../mfc/codesnippet/cpp/cwindowdc-class_1.cpp)]  
  
##  <a name="a-namemhwnda--cwindowdcmhwnd"></a><a name="m_hwnd"></a>CWindowDC::m_hWnd  
 O `HWND` do `CWnd` ponteiro é usado para construir o `CWindowDC` objeto.  
  
```  
HWND m_hWnd;  
```  
  
### <a name="remarks"></a>Comentários  
 `m_hWnd`é uma variável do tipo protegida `HWND`.  
  
### <a name="example"></a>Exemplo  
  Veja o exemplo de [CWindowDC::CWindowDC](#cwindowdc).  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDC](../../mfc/reference/cdc-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CDC](../../mfc/reference/cdc-class.md)

