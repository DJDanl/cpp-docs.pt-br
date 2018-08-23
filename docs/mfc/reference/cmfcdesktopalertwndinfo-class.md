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
ms.openlocfilehash: 4d5cf3c8804595aa3d0f3a83bc2628ea830e786a
ms.sourcegitcommit: a41c4d096afca1e9b619bbbce045b77135d32ae2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/14/2018
ms.locfileid: "42543084"
---
# <a name="cmfcdesktopalertwndinfo-class"></a>Classe CMFCDesktopAlertWndInfo
O `CMFCDesktopAlertWndInfo` classe é usada com o [classe CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md). Especifica os controles que são exibidos se a janela de alerta da área de trabalho é exibida.  
  
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
|[CMFCDesktopAlertWndInfo::m_nURLCmdID](#m_nurlcmdid)|A ID de comando associada com um link na janela de alerta da área de trabalho.|  
|[CMFCDesktopAlertWndInfo::m_strText](#m_strtext)|O texto que é exibido na janela de alerta da área de trabalho.|  
|[CMFCDesktopAlertWndInfo::m_strURL](#m_strurl)|O link que é exibido na janela de alerta da área de trabalho.|  
  
## <a name="remarks"></a>Comentários  
 O `CMFCDesktopAlertWndInfo` classe é passada para o [CMFCDesktopAlertWnd::Create](../../mfc/reference/cmfcdesktopalertwnd-class.md#create) método para especificar os elementos que são exibidos na caixa de diálogo padrão da janela de alerta da área de trabalho. A caixa de diálogo padrão pode conter três itens:  
  
-   Um ícone, que é definido chamando [CMFCDesktopAlertWndInfo::m_hIcon](#m_hicon).  
  
-   Um rótulo ou a mensagem de texto, que é definida chamando [CMFCDesktopAlertWndInfo::m_strText](#m_strtext).  
  
-   Um link, que é definido chamando [CMFCDesktopAlertWndInfo::m_strURL](#m_strurl). Para definir o comando que é executado quando o link é clicado, chame [CMFCDesktopAlertWndInfo::m_nURLCmdID](#m_nurlcmdid).  
  
 Se a caixa de diálogo padrão não for suficiente, você pode criar uma caixa de diálogo personalizada e passá-lo para o [CMFCDesktopAlertWnd::Create](../../mfc/reference/cmfcdesktopalertwnd-class.md#create) método em vez de usar essa classe. Para obter mais informações, consulte [classe CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir demonstra como usar vários membros no `CMFCDesktopAlertWndInfo` classe. O exemplo demonstra como definir o identificador para o ícone que é exibido, o texto que é exibido na janela de alerta da área de trabalho, o link que é exibido na janela de alerta da área de trabalho e a ID de comando que está associada com um link na janela de alerta da área de trabalho. Este exemplo faz parte de [amostra de demonstração de alerta da área de trabalho](../../visual-cpp-samples.md).  
  
 [!code-cpp[NVC_MFC_DesktopAlertDemo#3](../../mfc/reference/codesnippet/cpp/cmfcdesktopalertwndinfo-class_1.cpp)]  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CMFCDesktopAlertWndInfo](../../mfc/reference/cmfcdesktopalertwndinfo-class.md)  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxDesktopAlertDialog.h  
  
##  <a name="operator_eq"></a>  CMFCDesktopAlertWndInfo::operator =  
 Para obter mais detalhes, consulte o código-fonte localizado na **VC\\atlmfc\\src\\mfc** pasta de instalação do Visual Studio.  
  
```  
CMFCDesktopAlertWndInfo& operator=(CMFCDesktopAlertWndInfo& src);
```  
  
### <a name="parameters"></a>Parâmetros  
 [in] *src*  
  
### <a name="return-value"></a>Valor de retorno  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_hicon"></a>  CMFCDesktopAlertWndInfo::m_hIcon  
 Um identificador para o ícone que é exibido.  
  
```  
HICON m_hIcon;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_nurlcmdid"></a>  CMFCDesktopAlertWndInfo::m_nURLCmdID  
 A ID de comando associada com um link na janela de alerta da área de trabalho.  
  
```  
UINT m_nURLCmdID;  
```  
  
### <a name="remarks"></a>Comentários  
 A ID de comando é enviada ao proprietário da janela pop-up quando o usuário clica no link especificado por [CMFCDesktopAlertWndInfo::m_strURL](#m_strurl).  
  
##  <a name="m_strtext"></a>  CMFCDesktopAlertWndInfo::m_strText  
 O texto que é exibido na janela de alerta da área de trabalho.  
  
```  
CString m_strText;  
```  
  
### <a name="remarks"></a>Comentários  
  
##  <a name="m_strurl"></a>  CMFCDesktopAlertWndInfo::m_strURL  
 O link que é exibido na janela de alerta da área de trabalho.  
  
```  
CString m_strURL;  
```  
  
### <a name="remarks"></a>Comentários  
 Quando o usuário clica no link, o comando tem o [CMFCDesktopAlertWndInfo::m_nURLCmdID](#m_nurlcmdid) ID de comando será enviada ao proprietário da janela pop-up.  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico da hierarquia](../../mfc/hierarchy-chart.md)   
 [Classes](../../mfc/reference/mfc-classes.md)   
 [Classe CMFCDesktopAlertWnd](../../mfc/reference/cmfcdesktopalertwnd-class.md)   
 [CMFCDesktopAlertWnd::Create](../../mfc/reference/cmfcdesktopalertwnd-class.md#create)   
 [Classe CMFCDesktopAlertDialog](../../mfc/reference/cmfcdesktopalertdialog-class.md)
