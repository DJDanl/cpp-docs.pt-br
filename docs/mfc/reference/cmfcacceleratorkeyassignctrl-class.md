---
title: Classe CMFCAcceleratorKeyAssignCtrl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CMFCAcceleratorKeyAssignCtrl
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl::CMFCAcceleratorKeyAssignCtrl
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl::GetAccel
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl::IsFocused
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl::IsKeyDefined
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl::PreTranslateMessage
- AFXACCELERATORKEYASSIGNCTRL/CMFCAcceleratorKeyAssignCtrl::ResetKey
dev_langs:
- C++
helpviewer_keywords:
- CMFCAcceleratorKeyAssignCtrl [MFC], CMFCAcceleratorKeyAssignCtrl
- CMFCAcceleratorKeyAssignCtrl [MFC], GetAccel
- CMFCAcceleratorKeyAssignCtrl [MFC], IsFocused
- CMFCAcceleratorKeyAssignCtrl [MFC], IsKeyDefined
- CMFCAcceleratorKeyAssignCtrl [MFC], PreTranslateMessage
- CMFCAcceleratorKeyAssignCtrl [MFC], ResetKey
ms.assetid: 89fb8e62-596e-4e71-8c9a-32740347aaab
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1aacd22af0b2e0e14a3c1203a42e067b1f339c71
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="cmfcacceleratorkeyassignctrl-class"></a>Classe CMFCAcceleratorKeyAssignCtrl
O `CMFCAcceleratorKeyAssignCtrl` classe estende a [CEdit classe](../../mfc/reference/cedit-class.md) para dar suporte a botões de sistema adicionais, como SHIFT, ALT e controle.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCAcceleratorKeyAssignCtrl : public CEdit  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCAcceleratorKeyAssignCtrl::CMFCAcceleratorKeyAssignCtrl](#cmfcacceleratorkeyassignctrl)|Constrói um objeto `CMFCAcceleratorKeyAssignCtrl`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCAcceleratorKeyAssignCtrl::GetAccel](#getaccel)|Recupera o `ACCEL` estrutura para uma tecla de atalho pressionado o `CMFCAcceleratorKeyAssignCtrl` objeto.|  
|[CMFCAcceleratorKeyAssignCtrl::IsFocused](#isfocused)||  
|[CMFCAcceleratorKeyAssignCtrl::IsKeyDefined](#iskeydefined)|Determina se uma tecla de atalho foi definida.|  
|[CMFCAcceleratorKeyAssignCtrl::PreTranslateMessage](#pretranslatemessage)|Usado pela classe [CWinApp](../../mfc/reference/cwinapp-class.md) para converter as mensagens de janela antes de serem distribuídos para o [TranslateMessage](http://msdn.microsoft.com/library/windows/desktop/ms644955) e [DispatchMessage](http://msdn.microsoft.com/library/windows/desktop/ms644934) funções do Windows. (Substitui [CWnd::PreTranslateMessage](../../mfc/reference/cwnd-class.md#pretranslatemessage).)|  
|[CMFCAcceleratorKeyAssignCtrl::ResetKey](#resetkey)|Redefine a tecla de atalho.|  
  
## <a name="remarks"></a>Comentários  
 Essa classe estende a funcionalidade do `CEdit` classe oferecendo suporte a teclas de atalho, também conhecido como teclas de aceleração. O `CMFCAcceleratorKeyAssignCtrl` classe funciona como um [CEdit classe](../../mfc/reference/cedit-class.md) e que também pode reconhecer os botões do sistema.  
  
 Essa classe mapeia combinações de teclas de atalho físicos para valores de cadeia de caracteres. Por exemplo, suponha que a combinação de teclas ALT + B é mapeado para a cadeia de caracteres "Alt + B". Quando o usuário pressiona essa combinação de teclas em um `CMFCAcceleratorKeyAssignCtrl` do objeto, "Alt + B" é exibida ao usuário. Para obter mais informações sobre o mapeamento entre as teclas de atalho e um formato de cadeia de caracteres, consulte [CMFCAcceleratorKey classe](../../mfc/reference/cmfcacceleratorkey-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como construir um `CMFCAcceleratorKeyAssignCtrl` e usa seu `ResetKey` método para redefinir a tecla de atalho.  
  
 [!code-cpp[NVC_MFC_RibbonApp#31](../../mfc/reference/codesnippet/cpp/cmfcacceleratorkeyassignctrl-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 [CCmdTarget](../../mfc/reference/ccmdtarget-class.md)  
  
 [CWnd](../../mfc/reference/cwnd-class.md)  
  
 [CEdit](../../mfc/reference/cedit-class.md)  
  
 `CMFCAcceleratorKeyAssignCtrl`   
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxacceleratorkeyassignctrl.h  
  
##  <a name="cmfcacceleratorkeyassignctrl"></a>CMFCAcceleratorKeyAssignCtrl::CMFCAcceleratorKeyAssignCtrl  
 Constrói um [CMFCAcceleratorKeyAssignCtrl](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md) objeto.  
  
```  
CMFCAcceleratorKeyAssignCtrl();
```  
  
##  <a name="getaccel"></a>CMFCAcceleratorKeyAssignCtrl::GetAccel  
 Recupera o `ACCEL` estrutura para uma tecla de atalho pressionado o [CMFCAcceleratorKeyAssignCtrl](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md) objeto.  
  
```  
ACCEL const* GetAccel() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um `ACCEL` estrutura que descreve a tecla de atalho.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para recuperar o `ACCEL` estrutura para uma tecla de atalho que o usuário inserido em seu `CMFCAcceleratorKeyAssignCtrl` objeto.  
  
##  <a name="isfocused"></a>CMFCAcceleratorKeyAssignCtrl::IsFocused  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
BOOL IsFocused() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="iskeydefined"></a>CMFCAcceleratorKeyAssignCtrl::IsKeyDefined  
 Determina se uma tecla de atalho foi definida no [CMFCAcceleratorKeyAssignCtrl](../../mfc/reference/cmfcacceleratorkeyassignctrl-class.md) objeto.  
  
```  
BOOL IsKeyDefined() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se o usuário pressionou já uma combinação válida de chaves que definem uma tecla de atalho; Caso contrário, 0.  
  
### <a name="remarks"></a>Comentários  
 Use esta função para determinar se o usuário inseriu uma tecla de atalho válido no seu `CMFCAcceleratorKeyAssignCtrl` objeto. Se existir uma tecla de atalho, você pode usar [CMFCAcceleratorKeyAssignCtrl::GetAccel](#getaccel) método para obter o `ACCEL` estrutura associada a essa tecla de atalho.  
  
##  <a name="pretranslatemessage"></a>CMFCAcceleratorKeyAssignCtrl::PreTranslateMessage  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
virtual BOOL PreTranslateMessage(MSG* pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `pMsg`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="resetkey"></a>CMFCAcceleratorKeyAssignCtrl::ResetKey  
 Redefine a tecla de atalho.  
  
```  
void ResetKey();
```  
  
### <a name="remarks"></a>Comentários  
 A função apaga o texto do controle de edição. Isso inclui quaisquer teclas de atalho que o usuário pressionou.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCAcceleratorKey](../../mfc/reference/cmfcacceleratorkey-class.md)
