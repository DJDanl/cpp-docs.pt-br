---
title: Classe CDialogImpl | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CDialogImpl
- ATL.CDialogImpl
- ATL::CDialogImpl
dev_langs:
- C++
helpviewer_keywords:
- dialog boxes, ATL
- CDialogImpl class
ms.assetid: d430bc7b-8a28-4ad3-9507-277bdd2c2c2e
caps.latest.revision: 25
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
ms.openlocfilehash: 732227ef8566ce5e2985a3e65a1153a130df6b20
ms.lasthandoff: 02/25/2017

---
# <a name="cdialogimpl-class"></a>Classe CDialogImpl
Essa classe fornece métodos para criar uma caixa de diálogo modal ou sem janela restrita.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados no tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
 
template <class T,  
    class TBase = CWindow>  
    class ATL_NO_VTABLE CDialogImpl : public CDialogImplBaseT<TBase>  
 
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 Sua classe derivada de `CDialogImpl`.  
  
 *TBase*  
 A classe base da nova classe. A classe base padrão é [CWindow](../../atl/reference/cwindow-class.md).  
  
## <a name="members"></a>Membros  
  
### <a name="methods"></a>Métodos  
  
|||  
|-|-|  
|[Criar](#create)|Cria uma caixa de diálogo sem janela restrita.|  
|[DestroyWindow](#destroywindow)|Destrói a uma caixa de diálogo sem janela restrita.|  
|[DoModal](#domodal)|Cria uma caixa de diálogo modal.|  
|[EndDialog](#enddialog)|Destrói a caixa de diálogo modal.|  
  
### <a name="cdialogimplbaset-methods"></a>Métodos de CDialogImplBaseT  
  
|||  
|-|-|  
|[GetDialogProc](#getdialogproc)|Retorna o procedimento de caixa de diálogo atual.|  
|[MapDialogRect](#mapdialogrect)|Mapeia as unidades de caixa de diálogo do retângulo especificado para unidades de tela (pixels).|  
|[OnFinalMessage](#onfinalmessage)|Chamado após o recebimento da última mensagem, normalmente `WM_NCDESTROY`.|  
  
### <a name="static-functions"></a>Funções estáticas  
  
|||  
|-|-|  
|[DialogProc](#dialogproc)|Processa as mensagens enviadas para a caixa de diálogo.|  
|[StartDialogProc](#startdialogproc)|Chamado quando a primeira mensagem é recebida para processar as mensagens enviadas para a caixa de diálogo.|  
  
## <a name="remarks"></a>Comentários  
 Com `CDialogImpl` você pode criar uma caixa de diálogo modal ou sem janela restrita. `CDialogImpl`fornece o procedimento de caixa de diálogo, que usa o mapa da mensagem padrão para direcionar mensagens para manipuladores adequados.  
  
 O destruidor de classe base **~ CWindowImplRoot** garante que a janela desapareceu antes de destruir o objeto.  
  
 `CDialogImpl`deriva de **CDialogImplBaseT**, que por sua vez deriva de **CWindowImplRoot**.  
  
> [!NOTE]
>  Sua classe deve definir um **IDD** membro que especifica a ID de recurso de modelo de caixa de diálogo. Por exemplo, ATL Project Wizard adiciona automaticamente a linha a seguir à sua classe:  
  
 [!code-cpp[41 NVC_ATL_Windowing](../../atl/codesnippet/cpp/cdialogimpl-class_1.h)]  
  
 onde `MyDlg` é o **nome curto** digitado no Assistente do **nomes** página.  
  
|Para obter mais informações sobre|Consulte|  
|--------------------------------|---------|  
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|  
|Usando caixas de diálogo do ATL|[Classes de janela ATL](../../atl/atl-window-classes.md)|  
|Assistente de Projeto da ATL|[Criando um projeto do ATL](../../atl/reference/creating-an-atl-project.md)|  
|Caixas de diálogo|[Caixas de diálogo](http://msdn.microsoft.com/library/windows/desktop/ms632588) e tópicos subsequentes a[!INCLUDE[winSDK](../../atl/includes/winsdk_md.md)]|  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="a-namecreatea--cdialogimplcreate"></a><a name="create"></a>CDialogImpl::Create  
 Cria uma caixa de diálogo sem janela restrita.  
  
```  
HWND Create(
    HWND hWndParent,  
    LPARAM dwInitParam = NULL );  

HWND Create(
    HWND hWndParent,  
    RECT&, 
    LPARAM dwInitParam = NULL); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWndParent`  
 [in] O identificador para a janela do proprietário.  
  
 **RECT < /**`rect`  
 [in] A [RECT](http://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que especifica o tamanho e a posição da caixa de diálogo.  
  
 `dwInitParam`  
 [in] Especifica o valor para passar para a caixa de diálogo no **lParam** parâmetro o **WM_INITDIALOG** mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador para a caixa de diálogo recém-criado.  
  
### <a name="remarks"></a>Comentários  
 Essa caixa de diálogo é anexada automaticamente para o `CDialogImpl` objeto. Para criar uma caixa de diálogo modal, chame [DoModal](#domodal). A segunda substituição acima é usada apenas com [CComControl](../../atl/reference/ccomcontrol-class.md).  
  
##  <a name="a-namedestroywindowa--cdialogimpldestroywindow"></a><a name="destroywindow"></a>CDialogImpl::DestroyWindow  
 Destrói a uma caixa de diálogo sem janela restrita.  
  
```  
 
BOOL DestroyWindow();

 
```  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a caixa de diálogo foi destruído com êxito; do contrário **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 Retorna **TRUE** se a caixa de diálogo foi destruído com êxito; do contrário **FALSE**.  
  
##  <a name="a-namedialogproca--cdialogimpldialogproc"></a><a name="dialogproc"></a>CDialogImpl::DialogProc  
 A função estática implementa o procedimento da caixa de diálogo.  
  
```  
 
static LRESULT CALLBACK DialogProc(
    HWND hWnd,  
    UINT uMsg,  
    WPARAM wParam,  
    LPARAM lParam);

 
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 [in] O identificador para a caixa de diálogo.  
  
 `uMsg`  
 [in] A mensagem enviada para a caixa de diálogo.  
  
 `wParam`  
 [in] Informações adicionais de mensagem específica.  
  
 `lParam`  
 [in] Informações adicionais de mensagem específica.  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a mensagem for processada; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 `DialogProc`usa o mapa da mensagem padrão para direcionar mensagens para manipuladores adequados.  
  
 Você pode substituir `DialogProc` para fornecer um mecanismo para manipulação de mensagens diferente.  
  
##  <a name="a-namedomodala--cdialogimpldomodal"></a><a name="domodal"></a>CDialogImpl::DoModal  
 Cria uma caixa de diálogo modal.  
  
```   
INT_PTR DoModal(  
    HWND hWndParent = ::GetActiveWindow(),   
    LPARAM dwInitParam = NULL); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWndParent`  
 [in] O identificador para a janela do proprietário. O valor padrão é o valor de retorno de [GetActiveWindow](http://msdn.microsoft.com/library/windows/desktop/ms646292) função do Win32.  
  
 `dwInitParam`  
 [in] Especifica o valor para passar para a caixa de diálogo no **lParam** parâmetro o **WM_INITDIALOG** mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o valor de `nRetCode` parâmetro especificado na chamada para [EndDialog](#enddialog). Caso contrário, retornará -1.  
  
### <a name="remarks"></a>Comentários  
 Essa caixa de diálogo é anexada automaticamente para o `CDialogImpl` objeto.  
  
 Para criar uma caixa de diálogo sem janela restrita, chame [criar](#create).  
  
##  <a name="a-nameenddialoga--cdialogimplenddialog"></a><a name="enddialog"></a>CDialogImpl::EndDialog  
 Destrói a caixa de diálogo modal.  
  
```   
BOOL EndDialog(int nRetCode); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `nRetCode`  
 [in] O valor a ser retornado por [CDialogImpl::DoModal](#domodal).  
  
### <a name="return-value"></a>Valor de retorno  
 **TRUE** se a caixa de diálogo for destruído; caso contrário, **FALSE**.  
  
### <a name="remarks"></a>Comentários  
 `EndDialog`deve ser chamado por meio do procedimento de diálogo. Depois que a caixa de diálogo for destruída, o Windows usa o valor de `nRetCode` como o valor de retorno para `DoModal`, que criou a caixa de diálogo.  
  
> [!NOTE]
>  Não chame `EndDialog` destruir uma caixa de diálogo sem janela restrita. Chamar [CWindow::DestroyWindow](../../atl/reference/cwindow-class.md#destroywindow) em vez disso.  
  
##  <a name="a-namegetdialogproca--cdialogimplgetdialogproc"></a><a name="getdialogproc"></a>CDialogImpl::GetDialogProc  
 Retorna `DialogProc`, o procedimento de caixa de diálogo atual.  
  
```   
virtual WNDPROC GetDialogProc(); 
```  
  
### <a name="return-value"></a>Valor de retorno  
 O procedimento de caixa de diálogo atual.  
  
### <a name="remarks"></a>Comentários  
 Substitua este método para substituir o procedimento da caixa de diálogo com seus próprios.  
  
##  <a name="a-namemapdialogrecta--cdialogimplmapdialogrect"></a><a name="mapdialogrect"></a>CDialogImpl::MapDialogRect  
 Converte unidades (maps) as unidades de caixa de diálogo do retângulo especificado à tela (pixels).  
  
```   
BOOL MapDialogRect(LPRECT lpRect); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `lpRect`  
 Aponta para um `CRect` objeto ou [RECT](../../mfc/reference/rect-structure1.md) estrutura que receberá as coordenadas do cliente da atualização que inclui a região de atualização.  
  
### <a name="return-value"></a>Valor de retorno  
 Diferente de zero se a atualização for bem-sucedida; 0 se a atualização falhar. Para obter outras informações sobre o erro, chame `GetLastError`.  
  
### <a name="remarks"></a>Comentários  
 A função substitui as coordenadas do `RECT` estrutura com as coordenadas de convertido, que permite que a estrutura a ser usada para criar uma caixa de diálogo ou posicionar um controle em uma caixa de diálogo.  
  
##  <a name="a-nameonfinalmessagea--cdialogimplonfinalmessage"></a><a name="onfinalmessage"></a>CDialogImpl::OnFinalMessage  
 Chamado após o recebimento da última mensagem (geralmente `WM_NCDESTROY`).  
  
```   
virtual void OnFinalMessage(HWND hWnd); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 [in] Um identificador para a janela que está sendo destruído.  
  
### <a name="remarks"></a>Comentários  
 Observe que se você quiser excluir automaticamente seu objeto após a destruição de janela, você pode chamar `delete this;` aqui.  
  
##  <a name="a-namestartdialogproca--cdialogimplstartdialogproc"></a><a name="startdialogproc"></a>CDialogImpl::StartDialogProc  
 Chamado somente uma vez, quando a primeira mensagem é recebida, para processar as mensagens enviadas para a caixa de diálogo.  
  
```   
static LRESULT CALLBACK StartDialogProc(
    HWND hWnd,  
    UINT uMsg,  
    WPARAM wParam,  
    LPARAM lParam); 
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWnd`  
 [in] O identificador para a caixa de diálogo.  
  
 `uMsg`  
 [in] A mensagem enviada para a caixa de diálogo.  
  
 `wParam`  
 [in] Informações adicionais de mensagem específica.  
  
 `lParam`  
 [in] Informações adicionais de mensagem específica.  
  
### <a name="return-value"></a>Valor de retorno  
 O procedimento de janela.  
  
### <a name="remarks"></a>Comentários  
 Após a chamada inicial para `StartDialogProc`, `DialogProc` estiver definido como um procedimento de caixa de diálogo e outras chamadas por aí.  
  
## <a name="see-also"></a>Consulte também  
 [BEGIN_MSG_MAP](http://msdn.microsoft.com/library/8bbb5af9-18b1-48c6-880e-166f599ee554)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
