---
title: Classe CWinFormsView | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CWinFormsView
- AFXWINFORMS/CWinFormsView
- AFXWINFORMS/CWinFormsView::CWinFormsView
- AFXWINFORMS/CWinFormsView::GetControl
dev_langs:
- C++
helpviewer_keywords:
- MFC [C++], Windows Forms support
- CWinFormsView class
- Windows Forms [C++], MFC support
ms.assetid: d597e397-6529-469b-88f5-7f65a6b9e895
caps.latest.revision: 26
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
ms.sourcegitcommit: 6c49d711da747e4c6cbad0f883d93196b6a98057
ms.openlocfilehash: 7aadcc1aa887cb6be1ddbb8f3797c4a9e1af5b6a
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="cwinformsview-class"></a>Classe CWinFormsView
Fornece funcionalidade genérica para hospedagem de um controle Windows Forms como uma exibição MFC.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CWinFormsView : public CView;  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinFormsView::CWinFormsView](#cwinformsview)|Constrói um objeto `CWinFormsView`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinFormsView::GetControl](#getcontrol)|Recupera um ponteiro para o controle Windows Forms.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome||  
|----------|-|  
|[Controle CWinFormsView::operator ^](#operator_control)|Converte um tipo como um ponteiro para um controle Windows Forms.|  
  
## <a name="remarks"></a>Comentários  
 O MFC usa o `CWinFormsView` classe para hospedar um controle Windows Forms do .NET Framework em uma exibição MFC. O controle é um filho do modo nativo e ocupa toda a área cliente do modo de exibição do MFC. O resultado é semelhante a um `CFormView` exibição, permitindo que você tirar proveito do Windows Forms designer e tempo de execução a criar modos de exibição avançados baseado em formulário.  
  
 Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
> [!NOTE]
>  Integração de formulários do Windows MFC funciona apenas em projetos que vinculam dinamicamente com MFC (projetos no qual AFXDLL é definido).  
  
> [!NOTE]
>  CWinFormsView não oferece suporte a janela separadora MFC ( [CSplitterWnd classe](../../mfc/reference/csplitterwnd-class.md)). No momento apenas o Windows Forms divisor controle tem suporte.  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinforms.h  
  
##  <a name="cwinformsview"></a>CWinFormsView::CWinFormsView  
 Constrói um objeto `CWinFormsView`.  
  
```  
CWinFormsView(System::Type^ pManagedViewType);  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pManagedViewType`  
 Um ponteiro para o tipo de dados do controle de usuário do Windows Forms.   
  
### <a name="example"></a>Exemplo  
 No exemplo a seguir, o `CUserView` classe herda de `CWinFormsView` e passa o tipo de `UserControl1` para o `CWinFormsView` construtor. `UserControl1`é um controle personalizado no ControlLibrary1.dll.  
  
 [!code-cpp[NVC_MFC_Managed n º&1;](../../mfc/reference/codesnippet/cpp/cwinformsview-class_1.h)]  
  
 [!code-cpp[NVC_MFC_Managed n º&2;](../../mfc/reference/codesnippet/cpp/cwinformsview-class_2.cpp)]  
  
##  <a name="getcontrol"></a>CWinFormsView::GetControl  
 Recupera um ponteiro para o controle Windows Forms.  
  
```  
System::Windows::Forms::Control^ GetControl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um ponteiro para um `System.Windows.Forms.Control` objeto.  
  
### <a name="remarks"></a>Comentários  
 Para obter um exemplo de como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
##  <a name="operator_control"></a>Controle CWinFormsView::operator ^  
 Converte um tipo como um ponteiro para um controle Windows Forms.  
  
```  
operator System::Windows::Forms::Control^() const;  
```  
  
### <a name="remarks"></a>Comentários  
 Este operador permite que você passe uma `CWinFormsView` exibição para funções que aceitam um ponteiro para um controle Windows Forms do tipo <xref:System.Windows.Forms.Control>.</xref:System.Windows.Forms.Control>  
  
### <a name="example"></a>Exemplo  
  Consulte [CWinFormsView::GetControl](#getcontrol).  
  
## <a name="see-also"></a>Consulte também  
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)   
 [Classe CWinFormsControl](../../mfc/reference/cwinformscontrol-class.md)   
 [Classe CWinFormsDialog](../../mfc/reference/cwinformsdialog-class.md)   
 [Classe CFormView](../../mfc/reference/cformview-class.md)

