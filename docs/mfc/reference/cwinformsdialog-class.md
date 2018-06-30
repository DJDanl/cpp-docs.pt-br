---
title: Classe CWinFormsDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
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
- CWinFormsDialog [MFC], CWinFormsDialog
- CWinFormsDialog [MFC], GetControl
- CWinFormsDialog [MFC], GetControlHandle
- CWinFormsDialog [MFC], OnInitDialog
ms.assetid: e3cec000-a578-448e-b06a-8af256312f61
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1fe7c8518366065e93360187247cbd07df42d79f
ms.sourcegitcommit: 208d445fd7ea202de1d372d3f468e784e77bd666
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/29/2018
ms.locfileid: "37122491"
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
  
### <a name="public-constructors"></a>Construtores Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinFormsDialog::CWinFormsDialog](#cwinformsdialog)|Constrói um objeto `CWinFormsDialog`.|  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CWinFormsDialog::GetControl](#getcontrol)|Recupera uma referência para o controle de usuário do Windows Forms.|  
|[CWinFormsDialog::GetControlHandle](#getcontrolhandle)|Recupera um identificador de janela para o controle de usuário do Windows Forms.|  
|[CWinFormsDialog::OnInitDialog](#oninitdialog)|Inicializa a caixa de diálogo MFC criando e hospedando um controle de usuário do Windows Forms nele.|  
  
### <a name="public-operators"></a>Operadores públicos  
  
|Nome||  
|----------|-|  
|[CWinFormsDialog::operator-&gt;](#operator_-_gt)|Substitui [CWinFormsDialog::GetControl](#getcontrol) em expressões.|  
|[CWinFormsDialog::operator TManagedControl ^](#operator_tmanagedcontrol)|Converte um tipo como uma referência a um controle de usuário do Windows Forms.|  
  
## <a name="remarks"></a>Comentários  
 `CWinFormsDialog` é um wrapper para uma classe de caixa de diálogo MFC ( [CDialog](../../mfc/reference/cdialog-class.md)) que hospeda um controle de usuário do Windows Forms. Isso permite que a exibição dos controles do .NET Framework em uma caixa de diálogo modal ou sem janela restrita do MFC.  
  
 Para obter mais informações sobre como usar formulários do Windows, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md) e [hospedando um controle de usuário do Windows Form como uma caixa de diálogo MFC](../../dotnet/hosting-a-windows-form-user-control-as-an-mfc-dialog-box.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinforms.h  
  
##  <a name="cwinformsdialog"></a>  CWinFormsDialog::CWinFormsDialog  
 Constrói um objeto `CWinFormsDialog`.  
  
```  
CWinFormsDialog(UINT nIDTemplate = IDD);
```  
  
### <a name="parameters"></a>Parâmetros  
 *nIDTemplate*  
 Contém a ID de um recurso de modelo de caixa de diálogo. Use o editor de caixa de diálogo para criar o modelo de caixa de diálogo e armazená-la no arquivo de script de recurso do aplicativo. Para obter mais informações sobre modelos de caixa de diálogo, consulte [classe CDialog](../../mfc/reference/cdialog-class.md).  
  
##  <a name="getcontrol"></a>  CWinFormsDialog::GetControl  
 Recupera uma referência para o controle de usuário do Windows Forms.  
  
```  
inline TManagedControl^ GetControl() const;  
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna uma referência para o controle de formulários do Windows na caixa de diálogo MFC.  
  
##  <a name="getcontrolhandle"></a>  CWinFormsDialog::GetControlHandle  
 Recupera um identificador de janela para o controle de usuário do Windows Forms.  
  
```  
inline HWND GetControlHandle() const throw();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um identificador de janela para o controle de usuário do Windows Forms.  
  
##  <a name="oninitdialog"></a>  CWinFormsDialog::OnInitDialog  
 Inicializa a caixa de diálogo MFC criando e hospedando um controle de usuário do Windows Forms nele.  
  
```  
virtual BOOL OnInitDialog();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Um valor booleano que especifica se o aplicativo definiu o foco de entrada para um dos controles na caixa de diálogo. Se `OnInitDialog` retorna zero, Windows define o foco de entrada para o primeiro controle na caixa de diálogo. Esse método pode retornar 0 somente se o aplicativo tenha definido explicitamente o foco de entrada para um dos controles na caixa de diálogo.  
  
### <a name="remarks"></a>Comentários  
 Quando a caixa de diálogo MFC é criada (usando o [criar](../../mfc/reference/cdialog-class.md#create), [CreateIndirect](../../mfc/reference/cdialog-class.md#createindirect), ou [DoModal](../../mfc/reference/cdialog-class.md#domodal) método herdado do [CDialog](../../mfc/reference/cdialog-class.md)), um WM _ INITDIALOG mensagem é enviada, e esse método é chamado. Ele cria uma instância de um controle de formulários do Windows na caixa de diálogo e ajusta o tamanho da caixa de diálogo para acomodar o tamanho do controle de usuário. Em seguida, ele hospeda o novo controle na caixa de diálogo MFC.  
  
 Substitua essa função de membro, se você precisar realizar processamento especial quando a caixa de diálogo é inicializada. Para obter mais informações sobre como usar esse método, consulte [CDialog::OnInitDialog](../../mfc/reference/cdialog-class.md#oninitdialog).  
  
##  <a name="operator_-_gt"></a>  CWinFormsDialog::operator-&gt;  
 Substitui [CWinFormsDialog::GetControl](#getcontrol) em expressões.  
  
```  
inline TManagedControl^  operator->() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Este operador fornece uma sintaxe conveniente que substitui `GetControl` em expressões.  
  
 Para obter informações sobre como usar formulários do Windows, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
##  <a name="operator_tmanagedcontrol_xor"></a>  CWinFormsDialog::operator TManagedControl ^  
 Converte um tipo como uma referência a um controle de usuário do Windows Forms.  
  
```  
inline operator TManagedControl^() const throw();
```  
  
### <a name="remarks"></a>Comentários  
 Este operador converte um tipo como uma referência a um controle de formulários do Windows. Ele é usado para passar um `CWinFormsDialog<TManagedControl>` caixa de diálogo para funções que aceitam um ponteiro para um objeto de controle de usuário do Windows Forms.  
  
## <a name="see-also"></a>Consulte também  
 [Classe CWnd](../../mfc/reference/cwnd-class.md)   
 [Classe CWinFormsView](../../mfc/reference/cwinformsview-class.md)   
 [Classe CDialog](../../mfc/reference/cdialog-class.md)
