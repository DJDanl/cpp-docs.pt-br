---
title: Classe CAxDialogImpl | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CAxDialogImpl
- ATLWIN/ATL::CAxDialogImpl
- ATLWIN/ATL::CAxDialogImpl::AdviseSinkMap
- ATLWIN/ATL::CAxDialogImpl::Create
- ATLWIN/ATL::CAxDialogImpl::DestroyWindow
- ATLWIN/ATL::CAxDialogImpl::DoModal
- ATLWIN/ATL::CAxDialogImpl::EndDialog
- ATLWIN/ATL::CAxDialogImpl::GetDialogProc
- ATLWIN/ATL::CAxDialogImpl::GetIDD
- ATLWIN/ATL::CAxDialogImpl::IsDialogMessage
- ATLWIN/ATL::CAxDialogImpl::m_bModal
dev_langs:
- C++
helpviewer_keywords:
- CAxDialogImpl class
- ATL, dialog boxes
ms.assetid: 817df483-3fa8-44e7-8487-72ba0881cd27
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2db97c0de9f262936212cf7f38abddf7c91eb5a6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="caxdialogimpl-class"></a>Classe CAxDialogImpl
Essa classe implementa uma caixa de diálogo (modal ou sem janela restrita) que hospeda os controles ActiveX.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos que são executados o tempo de execução do Windows.  
  
## <a name="syntax"></a>Sintaxe  
  
```
template <class T, class TBase = CWindow>  
class ATL_NO_VTABLE CAxDialogImpl : public CDialogImplBaseT<TBase>
```  
  
#### <a name="parameters"></a>Parâmetros  
 `T`  
 A classe derivada de `CAxDialogImpl`.  
  
 *TBase*  
 A classe de janela base para **CDialogImplBaseT**.  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAxDialogImpl::AdviseSinkMap](#advisesinkmap)|Chame esse método para informar ou unadvise todas as entradas no mapa do objeto coletor de eventos de mapa.|  
|[CAxDialogImpl::Create](#create)|Chame este método para criar uma caixa de diálogo sem janela restrita.|  
|[CAxDialogImpl::DestroyWindow](#destroywindow)|Chame este método para destruir uma caixa de diálogo sem janela restrita.|  
|[CAxDialogImpl::DoModal](#domodal)|Chame este método para criar uma caixa de diálogo modal.|  
|[CAxDialogImpl::EndDialog](#enddialog)|Chame este método para destruir uma caixa de diálogo modal.|  
|[CAxDialogImpl::GetDialogProc](#getdialogproc)|Chame esse método para obter um ponteiro para o `DialogProc` função de retorno de chamada.|  
|[CAxDialogImpl::GetIDD](#getidd)|Chame esse método para obter a ID de recurso de modelo de caixa de diálogo|  
|[CAxDialogImpl::IsDialogMessage](#isdialogmessage)|Chame esse método para determinar se uma mensagem é destinada a essa caixa de diálogo e, se for, processar a mensagem.|  
  
### <a name="protected-data-members"></a>Membros de dados protegidos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[CAxDialogImpl::m_bModal](#m_bmodal)|Uma variável que existe apenas na depuração compila e é definido como true se a caixa de diálogo modal.|  
  
## <a name="remarks"></a>Comentários  
 `CAxDialogImpl`permite que você crie uma caixa de diálogo modal ou sem janela restrita. `CAxDialogImpl`fornece o procedimento de caixa de diálogo, que usa o mapa da mensagem padrão para direcionar as mensagens para os manipuladores apropriados.  
  
 `CAxDialogImpl`deriva `CDialogImplBaseT`, que por sua vez é derivada de *TBase* (por padrão, `CWindow`) e `CMessageMap`.  
  
 A classe deve definir um membro IDD que especifica a ID de recurso de modelo de caixa de diálogo. Por exemplo, adicionando um objeto de caixa de diálogo do ATL usando o **Adicionar classe** caixa de diálogo adiciona automaticamente a linha a seguir à sua classe:  
  
 [!code-cpp[NVC_ATL_Windowing#41](../../atl/codesnippet/cpp/caxdialogimpl-class_1.h)]  
  
 onde `MyDialog` é o **nome curto** inserido na caixa de diálogo Assistente ATL.  
  
 Consulte [implementando uma caixa de diálogo](../../atl/implementing-a-dialog-box.md) para obter mais informações.  
  
 Observe que um controle ActiveX em uma caixa de diálogo modal criado com `CAxDialogImpl` não dará suporte a teclas de aceleração. Para dar suporte a teclas de aceleração em uma caixa de diálogo criada com `CAxDialogImpl`, criar uma caixa de diálogo sem janela restrita e, usando seu próprio loop de mensagem, use [CAxDialogImpl::IsDialogMessage](#isdialogmessage) depois de obter uma mensagem da fila para lidar com um tecla de aceleração.  
  
 Para obter mais informações sobre `CAxDialogImpl`, consulte [perguntas frequentes sobre contenção de controle ATL](../../atl/atl-control-containment-faq.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CMessageMap](../../atl/reference/cmessagemap-class.md)  
  
 `TBase`  
  
 `CWindowImplRoot`  
  
 `CDialogImplBaseT`  
  
 `CAxDialogImpl`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atlwin.h  
  
##  <a name="advisesinkmap"></a>CAxDialogImpl::AdviseSinkMap  
 Chame esse método para informar ou unadvise todas as entradas no mapa do objeto coletor de eventos de mapa.  
  
```
HRESULT AdviseSinkMap(bool bAdvise);
```  
  
### <a name="parameters"></a>Parâmetros  
 `bAdvise`  
 Defina como verdadeiro se todas as entradas de coletor devem ser avisado; as entradas de coletor false se todos devem ser unadvised.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna S_OK em caso de sucesso, ou um erro HRESULT em caso de falha.  
  
##  <a name="create"></a>CAxDialogImpl::Create  
 Chame este método para criar uma caixa de diálogo sem janela restrita.  
  
```
HWND Create(HWND hWndParent, LPARAM dwInitParam = NULL);
HWND Create(HWND hWndParent, RECT&, LPARAM dwInitParam = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWndParent`  
 [in] O identificador para a janela do proprietário.  
  
 `dwInitParam`  
 [in] Especifica o valor para passar para a caixa de diálogo o `lParam` parâmetro o **WM_INITDIALOG** mensagem.  
  
 **RECT &**  
 Este parâmetro não é usado. Esse parâmetro é passado `CComControl`.  
  
### <a name="return-value"></a>Valor de retorno  
 O identificador para a caixa de diálogo recém-criado.  
  
### <a name="remarks"></a>Comentários  
 Essa caixa de diálogo é anexada automaticamente para o `CAxDialogImpl` objeto. Para criar uma caixa de diálogo modal, chame [DoModal](#domodal).  
  
 A substituição de segundo é fornecida somente para caixas de diálogo podem ser usadas com [CComControl](../../atl/reference/ccomcontrol-class.md).  
  
##  <a name="destroywindow"></a>CAxDialogImpl::DestroyWindow  
 Chame este método para destruir uma caixa de diálogo sem janela restrita.  
  
```
BOOL DestroyWindow();
```  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a janela é destruída com êxito; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 Não chame `DestroyWindow` destruir uma caixa de diálogo modal. Chamar [EndDialog](#enddialog) em vez disso.  
  
##  <a name="domodal"></a>CAxDialogImpl::DoModal  
 Chame este método para criar uma caixa de diálogo modal.  
  
```
INT_PTR DoModal(
  HWND hWndParent = ::GetActiveWindow(), 
  LPARAM dwInitParam = NULL);
```  
  
### <a name="parameters"></a>Parâmetros  
 `hWndParent`  
 [in] O identificador para a janela do proprietário. O valor padrão é o valor de retorno de [GetActiveWindow](http://msdn.microsoft.com/library/windows/desktop/ms646292) função Win32.  
  
 `dwInitParam`  
 [in] Especifica o valor para passar para a caixa de diálogo o `lParam` parâmetro o **WM_INITDIALOG** mensagem.  
  
### <a name="return-value"></a>Valor de retorno  
 Se for bem-sucedido, o valor de `nRetCode` parâmetro especificado na chamada para [EndDialog](#enddialog); caso contrário, -1.  
  
### <a name="remarks"></a>Comentários  
 Essa caixa de diálogo é anexada automaticamente para o `CAxDialogImpl` objeto.  
  
 Para criar uma caixa de diálogo sem janela restrita, chame [criar](#create).  
  
##  <a name="enddialog"></a>CAxDialogImpl::EndDialog  
 Chame este método para destruir uma caixa de diálogo modal.  
  
```
BOOL EndDialog(int nRetCode);
```  
  
### <a name="parameters"></a>Parâmetros  
 `nRetCode`  
 [in] O valor a ser retornado por [DoModal](#domodal).  
  
### <a name="return-value"></a>Valor de retorno  
 TRUE se a caixa de diálogo é destruída; Caso contrário, FALSE.  
  
### <a name="remarks"></a>Comentários  
 `EndDialog`deve ser chamado por meio do procedimento de caixa de diálogo. Depois que a caixa de diálogo é destruída, o Windows usará o valor de `nRetCode` como o valor de retorno para `DoModal`, que criou a caixa de diálogo.  
  
> [!NOTE]
>  Não chame `EndDialog` destruir uma caixa de diálogo sem janela restrita. Chamar [DestroyWindow](#destroywindow) em vez disso.  
  
##  <a name="getdialogproc"></a>CAxDialogImpl::GetDialogProc  
 Chame esse método para obter um ponteiro para o `DialogProc` função de retorno de chamada.  
  
```
virtual DLGPROC GetDialogProc();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna um ponteiro para o `DialogProc` função de retorno de chamada.  
  
### <a name="remarks"></a>Comentários  
 O `DialogProc` função é uma função de retorno de chamada definido pelo aplicativo.  
  
##  <a name="getidd"></a>CAxDialogImpl::GetIDD  
 Chame esse método para obter a ID de recurso de modelo de caixa de diálogo.  
  
```
int GetIDD();
```  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna a ID de recurso de modelo de caixa de diálogo.  
  
##  <a name="isdialogmessage"></a>CAxDialogImpl::IsDialogMessage  
 Chame esse método para determinar se uma mensagem é destinada a essa caixa de diálogo e, se for, processar a mensagem.  
  
```
BOOL IsDialogMessage(LPMSG pMsg);
```  
  
### <a name="parameters"></a>Parâmetros  
 `pMsg`  
 Ponteiro para um [MSG](http://msdn.microsoft.com/library/windows/desktop/ms644958) estrutura que contém a mensagem a ser verificada.  
  
### <a name="return-value"></a>Valor de retorno  
 Retorna VERDADEIRO se a mensagem tiver sido processada, FALSO caso contrário.  
  
### <a name="remarks"></a>Comentários  
 Este método destina-se a ser chamado de dentro de um loop de mensagem.  
  
##  <a name="m_bmodal"></a>CAxDialogImpl::m_bModal  
 Uma variável que existe apenas na depuração compila e é definido como true se a caixa de diálogo modal.  
  
```
bool m_bModal;
```  
  
## <a name="see-also"></a>Consulte também  
 [Classe CDialogImpl](../../atl/reference/cdialogimpl-class.md)   
 [Visão geral da classe](../../atl/atl-class-overview.md)
