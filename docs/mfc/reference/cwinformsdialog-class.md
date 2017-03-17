---
title: Classe CWinFormsDialog | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CWinFormsDialog
- AFXWINFORMS/CWinFormsDialog
- AFXWINFORMS/CWinFormsDialog::CWinFormsDialog
- AFXWINFORMS/CWinFormsDialog::GetControl
- AFXWINFORMS/CWinFormsDialog::GetControlHandle
- AFXWINFORMS/CWinFormsDialog::OnInitDialog
dev_langs:
- C++
helpviewer_keywords:
- MFC [C++], Windows Forms support
- CWinFormsDialog class
- Windows Forms [C++], MFC support
ms.assetid: e3cec000-a578-448e-b06a-8af256312f61
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
translationtype: Machine Translation
ms.sourcegitcommit: 0e0c08ddc57d437c51872b5186ae3fc983bb0199
ms.openlocfilehash: 86768a849b0112f7c4f8b6b2a694b80065169575
ms.lasthandoff: 02/25/2017

---
# <a name="cwinformsdialog-class"></a>Classe CWinFormsDialog
Um wrapper para uma classe de caixa de diálogo do MFC que hospeda um controle de usuário do Windows Forms.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
template <typename TManagedControl>  
class CWinFormsDialog :   
    public CDialog  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `TManagedControl`  
 O controle de usuário do .NET Framework a ser exibido no aplicativo do MFC.  
  
## <a name="members"></a>Membros  
  
### <a name="public-constructors"></a>Construtores públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinFormsDialog::CWinFormsDialog](#cwinformsdialog)|Constrói um objeto `CWinFormsDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinFormsDialog::GetControl](#getcontrol)|Recupera uma referência ao controle de usuário do Windows Forms.|  
|[CWinFormsDialog::GetControlHandle](#getcontrolhandle)|Recupera um identificador de janela para o controle de usuário do Windows Forms.|  
|[CWinFormsDialog::OnInitDialog](#oninitdialog)|Inicializa a caixa de diálogo do MFC, criando e hospedando um controle de usuário do Windows Forms nele.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome||  
|----------|-|  
|[CWinFormsDialog::operator-&gt;](#operator_-_gt)|Substitui [CWinFormsDialog::GetControl](#getcontrol) em expressões.|  
|[CWinFormsDialog::operator TManagedControl ^](#operator_tmanagedcontrol)|Converte um tipo como uma referência a um controle de usuário do Windows Forms.|  
  
## <a name="remarks"></a>Comentários  
 `CWinFormsDialog`é um wrapper para uma classe de caixa de diálogo do MFC ( [CDialog](../../mfc/reference/cdialog-class.md)) que hospeda um controle de usuário do Windows Forms. Isso permite a exibição de controles do .NET Framework em uma caixa de diálogo modal ou sem janela restrita do MFC.  
  
 Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md) e [hospedando um controle de usuário do Windows Form como uma caixa de diálogo do MFC](../../dotnet/hosting-a-windows-form-user-control-as-an-mfc-dialog-box.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinforms.h  
  
##  <a name="cwinformsdialog"></a>CWinFormsDialog::CWinFormsDialog  
 Constrói um objeto `CWinFormsDialog`.  
  
```  
CWinFormsDialog(UINT nIDTemplate = IDD);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nIDTemplate`  
 Contém a ID de um recurso de modelo de caixa de diálogo. Use o editor de diálogo para criar o modelo de caixa de diálogo e armazená-lo no arquivo de script de recurso do aplicativo. Para obter mais informações sobre modelos de caixa de diálogo, consulte [classe CDialog](../../mfc/reference/cdialog-class.md).  
  
##  <a name="getcontrol"></a>CWinFormsDialog::GetControl  
 Recupera uma referência ao controle de usuário do Windows Forms.  
  
```  
inline TManagedControl^ GetControl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência ao controle de formulários do Windows na caixa de diálogo do MFC.  
  
##  <a name="getcontrolhandle"></a>CWinFormsDialog::GetControlHandle  
 Recupera um identificador de janela para o controle de usuário do Windows Forms.  
  
```  
inline HWND GetControlHandle() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um identificador de janela para o controle de usuário do Windows Forms.  
  
##  <a name="oninitdialog"></a>CWinFormsDialog::OnInitDialog  
 Inicializa a caixa de diálogo do MFC, criando e hospedando um controle de usuário do Windows Forms nele.  
  
```  
virtual BOOL OnInitDialog();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booleano que especifica se o aplicativo tenha definido o foco de entrada para um dos controles na caixa de diálogo. Se `OnInitDialog` retorna zero, Windows define o foco de entrada para o primeiro controle na caixa de diálogo. Esse método pode retornar 0 somente se o aplicativo tiver definido explicitamente o foco de entrada para um dos controles na caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Quando a caixa de diálogo do MFC é criada (usando o [criar](../../mfc/reference/cdialog-class.md#create), [CreateIndirect](../../mfc/reference/cdialog-class.md#createindirect), ou [DoModal](../../mfc/reference/cdialog-class.md#domodal) método herdado do [CDialog](../../mfc/reference/cdialog-class.md)), um `WM_INITDIALOG` mensagem é enviada e esse método é chamado. Ele cria uma instância de um controle de formulários do Windows na caixa de diálogo e ajusta o tamanho da caixa de diálogo para acomodar o tamanho do controle de usuário. Em seguida, ele hospeda o novo controle na caixa de diálogo do MFC.  
  
 Substitua essa função de membro, se você precisar realizar processamento especial quando a caixa de diálogo é inicializada. Para obter mais informações sobre como usar esse método, consulte [CDialog::OnInitDialog](../../mfc/reference/cdialog-class.md#oninitdialog).  
  
##  <a name="operator_-_gt"></a>CWinFormsDialog::operator-&gt;  
 Substitui [CWinFormsDialog::GetControl](#getcontrol) em expressões.  
  
```  
inline TManagedControl^  operator->() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Este operador fornece uma sintaxe conveniente que substitui `GetControl` em expressões.  
  
 Para obter informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
##  <a name="operator_tmanagedcontrol_xor"></a>CWinFormsDialog::operator TManagedControl ^  
 Converte um tipo como uma referência a um controle de usuário do Windows Forms.  
  
```  
inline operator TManagedControl^() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Este operador converte um tipo como uma referência a um controle de formulários do Windows. Ele é usado para passar um `CWinFormsDialog<``TManagedControl``>` caixa de diálogo para funções que aceitam um ponteiro para um objeto de controle de usuário do Windows Forms.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)   
 [Classe CDialog](../../mfc/reference/cdialog-class.md)

