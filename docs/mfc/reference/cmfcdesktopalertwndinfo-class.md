---
title: Classe CMFCDesktopAlertWndInfo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CMFCDesktopAlertWndInfo
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertWndInfo
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertWndInfo::m_hIcon
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertWndInfo::m_nURLCmdID
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertWndInfo::m_strText
- AFXDESKTOPALERTDIALOG/CMFCDesktopAlertWndInfo::m_strURL
dev_langs:
- C++
helpviewer_keywords:
- CMFCDesktopAlertWndInfo [MFC], m_hIcon
- CMFCDesktopAlertWndInfo [MFC], m_nURLCmdID
- CMFCDesktopAlertWndInfo [MFC], m_strText
- CMFCDesktopAlertWndInfo [MFC], m_strURL
ms.assetid: 5c9bb84e-6c96-4748-8e74-6951b6ae8e84
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b775b06f605edc68c6f1dbe47035d9ecf214b396
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="cmfcdesktopalertwndinfo-class"></a>Classe CMFCDesktopAlertWndInfo
O `CMFCDesktopAlertWndInfo` classe é usada com a [CMFCDesktopAlertWnd classe](../../mfc/reference/cmfcdesktopalertwnd-class.md). Especifica os controles que são exibidos se a janela da área de trabalho de alerta for exibido.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CMFCDesktopAlertWndInfo  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|`CMFCDesktopAlertWndInfo::~CMFCDesktopAlertWndInfo`|Destruidor.|  
  
### <a name="public-methods"></a>Métodos públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCDesktopAlertWndInfo::operator =](#operator_eq)||  
  
### <a name="data-members"></a>Membros de Dados  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CMFCDesktopAlertWndInfo::m_hIcon](#m_hicon)|Um identificador para o ícone que é exibido.|  
|[CMFCDesktopAlertWndInfo::m_nURLCmdID](#m_nurlcmdid)|A ID de comando associada a um link na janela de área de trabalho de alerta.|  
|[CMFCDesktopAlertWndInfo::m_strText](#m_strtext)|O texto que é exibido na janela da área de trabalho de alerta.|  
|[CMFCDesktopAlertWndInfo::m_strURL](#m_strurl)|O link que é exibido na janela da área de trabalho de alerta.|  
  
## <a name="remarks"></a>Comentários  
 O `CMFCDesktopAlertWndInfo` classe é passada para o [CMFCDesktopAlertWnd::Create](../../mfc/reference/cmfcdesktopalertwnd-class.md#create) método para especificar os elementos que são exibidos na caixa de diálogo padrão da janela de área de trabalho de alerta. A caixa de diálogo padrão pode conter três itens:  
  
-   Um ícone, que é definido pela chamada [CMFCDesktopAlertWndInfo::m_hIcon](#m_hicon).  
  
-   Um rótulo ou mensagem de texto, que é definida chamando [CMFCDesktopAlertWndInfo::m_strText](#m_strtext).  
  
-   Um link, o que é definido chamando [CMFCDesktopAlertWndInfo::m_strURL](#m_strurl). Para definir o comando que é executado quando o link é clicado, chame [CMFCDesktopAlertWndInfo::m_nURLCmdID](#m_nurlcmdid).  
  
 Se a caixa de diálogo padrão não for suficiente, você pode criar uma caixa de diálogo personalizada e passá-lo para o [CMFCDesktopAlertWnd::Create](../../mfc/reference/cmfcdesktopalertwnd-class.md#create) método em vez de usar essa classe. Para obter mais informações, consulte [CMFCDesktopAlertDialog classe](../../mfc/reference/cmfcdesktopalertdialog-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar os vários membros de `CMFCDesktopAlertWndInfo` classe. O exemplo demonstra como definir o identificador para o ícone que é exibido, o texto que é exibido na janela da área de trabalho de alerta, o link que é exibido na janela da área de trabalho de alerta e a ID de comando que está associada com um link na janela de área de trabalho de alerta. Este exemplo é parte do [exemplo de demonstração de alerta de área de trabalho](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DesktopAlertDemo#3](../../mfc/reference/codesnippet/cpp/cmfcdesktopalertwndinfo-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxDesktopAlertDialog.h  
  
##  <a name="operator_eq"></a>  CMFCDesktopAlertWndInfo::operator =  
 [!INCLUDE[cpp_fp_under_construction](../../mfc/reference/includes/cpp_fp_under_construction_md.md)]  
  
```  
CMFCDesktopAlertWndInfo& operator=(CMFCDesktopAlertWndInfo& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] `src`  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_hicon"></a>  CMFCDesktopAlertWndInfo::m_hIcon  
 Um identificador para o ícone que é exibido.  
  
```  
HICON m_hIcon;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_nurlcmdid"></a>  CMFCDesktopAlertWndInfo::m_nURLCmdID  
 A ID de comando associada a um link na janela de área de trabalho de alerta.  
  
```  
UINT m_nURLCmdID;  
```  
  
### <a name="remarks"></a>Comentários  
 A ID de comando é enviada ao proprietário da janela pop-up quando o usuário clica no link especificado por [CMFCDesktopAlertWndInfo::m_strURL](#m_strurl).  
  
##  <a name="m_strtext"></a>  CMFCDesktopAlertWndInfo::m_strText  
 O texto que é exibido na janela da área de trabalho de alerta.  
  
```  
CString m_strText;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_strurl"></a>  CMFCDesktopAlertWndInfo::m_strURL  
 O link que é exibido na janela da área de trabalho de alerta.  
  
```  
CString m_strURL;  
```  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário clica no link, o comando tem o [CMFCDesktopAlertWndInfo::m_nURLCmdID](#m_nurlcmdid) ID de comando será enviada ao proprietário da janela pop-up.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md)   
 [CMFCDesktopAlertWnd::Create](../../mfc/reference/cmfcdesktopalertwnd-class.md#create)   
 [Classe CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)
