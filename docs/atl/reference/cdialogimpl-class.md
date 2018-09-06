---
title: Classe CDialogImpl | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- CDialogImpl
- ATLWIN/ATL::CDialogImpl
- ATLWIN/ATL::Create
- ATLWIN/ATL::DestroyWindow
- ATLWIN/ATL::DoModal
- ATLWIN/ATL::EndDialog
- ATLWIN/ATL::GetDialogProc
- ATLWIN/ATL::MapDialogRect
- ATLWIN/ATL::OnFinalMessage
- ATLWIN/ATL::DialogProc
- ATLWIN/ATL::StartDialogProc
dev_langs:
- C++
helpviewer_keywords:
- dialog boxes, ATL
- CDialogImpl class
ms.assetid: d430bc7b-8a28-4ad3-9507-277bdd2c2c2e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1780a4f77cce4812ebdb03ebc89936da0dc0d5d0
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43767049"
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

*T*  
Sua classe, derivada de `CDialogImpl`.

*Tdígitos de base*  
A classe base da sua nova classe. A classe base padrão é [CWindow](../../atl/reference/cwindow-class.md).

## <a name="members"></a>Membros

### <a name="methods"></a>Métodos

|||
|-|-|
|[criar](#create)|Cria uma caixa de diálogo sem janela restrita.|
|[DestroyWindow](#destroywindow)|Destrói uma caixa de diálogo sem janela restrita.|
|[DoModal](#domodal)|Cria uma caixa de diálogo modal.|
|[EndDialog](#enddialog)|Destrói uma caixa de diálogo modal.|

### <a name="cdialogimplbaset-methods"></a>Métodos de CDialogImplBaseT

|||
|-|-|
|[GetDialogProc](#getdialogproc)|Retorna o procedimento de caixa de diálogo atual.|
|[MapDialogRect](#mapdialogrect)|Mapeia as unidades de caixa de diálogo do retângulo especificado para unidades de tela (pixels).|
|[OnFinalMessage](#onfinalmessage)|Chamado após o recebimento da última mensagem, normalmente WM_NCDESTROY.|

### <a name="static-functions"></a>Funções estáticas

|||
|-|-|
|[DialogProc](#dialogproc)|Processa as mensagens enviadas para a caixa de diálogo.|
|[StartDialogProc](#startdialogproc)|Chamado quando a primeira mensagem é recebida para processar as mensagens enviadas para a caixa de diálogo.|

## <a name="remarks"></a>Comentários

Com `CDialogImpl` você pode criar uma caixa de diálogo modal ou sem janela restrita. `CDialogImpl` fornece o procedimento de caixa de diálogo, que usa o mapa de mensagem padrão para direcionar mensagens para manipuladores adequados.

O destruidor de classe base `~CWindowImplRoot` garante que a janela desapareceu antes de destruir o objeto.

`CDialogImpl` deriva `CDialogImplBaseT`, que por sua vez deriva `CWindowImplRoot`.

> [!NOTE]
>  Sua classe deve definir um `IDD` membro que especifica a ID de recurso de modelo de caixa de diálogo. Por exemplo, o Assistente de projeto de ATL adiciona automaticamente a linha a seguir à sua classe:

[!code-cpp[NVC_ATL_Windowing#41](../../atl/codesnippet/cpp/cdialogimpl-class_1.h)]

em que `MyDlg` é o **nome curto** inserida no Assistente de **nomes** página.

|Para obter mais informações sobre|Consulte|
|--------------------------------|---------|
|Criando controles|[Tutorial da ATL](../../atl/active-template-library-atl-tutorial.md)|
|Usando as caixas de diálogo do ATL|[Classes de janela da ATL](../../atl/atl-window-classes.md)|
|ATL Project Wizard|[Criando um projeto ATL](../../atl/reference/creating-an-atl-project.md)|
|Caixas de diálogo|[Caixas de diálogo](https://msdn.microsoft.com/library/windows/desktop/ms632588) e tópicos subsequentes no SDK do Windows|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** atlwin

##  <a name="create"></a>  CDialogImpl::Create

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

*hWndParent*  
[in] O identificador para a janela do proprietário.

**RECT &** *rect*  
[in] Um [RECT](https://msdn.microsoft.com/library/windows/desktop/dd162897) estrutura que especifica o tamanho e a posição da caixa de diálogo.

*dwInitParam*  
[in] Especifica o valor para passar para a caixa de diálogo do *lParam* parâmetro da mensagem WM_INITDIALOG.

### <a name="return-value"></a>Valor de retorno

O identificador para a caixa de diálogo recém-criado.

### <a name="remarks"></a>Comentários

Essa caixa de diálogo é anexada automaticamente ao `CDialogImpl` objeto. Para criar uma caixa de diálogo modal, chame [DoModal](#domodal). A segunda substituição acima é usada somente com [CComControl](../../atl/reference/ccomcontrol-class.md).

##  <a name="destroywindow"></a>  CDialogImpl::DestroyWindow

Destrói uma caixa de diálogo sem janela restrita.  

```
BOOL DestroyWindow();
```

### <a name="return-value"></a>Valor de retorno

TRUE se a caixa de diálogo foi destruída com êxito; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

Retornará TRUE se a caixa de diálogo foi destruída com êxito; Caso contrário, FALSE.

##  <a name="dialogproc"></a>  CDialogImpl::DialogProc

A função estática implementa o procedimento de caixa de diálogo.  

```
static LRESULT CALLBACK DialogProc(
    HWND hWnd,  
    UINT uMsg,  
    WPARAM wParam,  
    LPARAM lParam);
```

### <a name="parameters"></a>Parâmetros

*hWnd*  
[in] O identificador para a caixa de diálogo.

*uMsg*  
[in] A mensagem enviada para a caixa de diálogo.

*wParam*  
[in] Obter informações adicionais específicas de mensagem.

*lParam*  
[in] Obter informações adicionais específicas de mensagem.

### <a name="return-value"></a>Valor de retorno

TRUE se a mensagem é processada; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`DialogProc` usa o mapa de mensagem padrão para direcionar mensagens para manipuladores adequados.

Você pode substituir `DialogProc` para fornecer um mecanismo diferente para lidar com mensagens.

##  <a name="domodal"></a>  CDialogImpl::DoModal

Cria uma caixa de diálogo modal.

```   
INT_PTR DoModal(  
    HWND hWndParent = ::GetActiveWindow(),   
    LPARAM dwInitParam = NULL); 
```

### <a name="parameters"></a>Parâmetros

*hWndParent*  
[in] O identificador para a janela do proprietário. O valor padrão é o valor de retorno de [GetActiveWindow](https://msdn.microsoft.com/library/windows/desktop/ms646292) função do Win32.

*dwInitParam*  
[in] Especifica o valor para passar para a caixa de diálogo do *lParam* parâmetro da mensagem WM_INITDIALOG.

### <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, o valor de *nRetCode* parâmetro especificado na chamada para [EndDialog](#enddialog). Caso contrário, -1.

### <a name="remarks"></a>Comentários

Essa caixa de diálogo é anexada automaticamente ao `CDialogImpl` objeto.

Para criar uma caixa de diálogo sem janela restrita, chame [criar](#create).

##  <a name="enddialog"></a>  CDialogImpl::EndDialog

Destrói uma caixa de diálogo modal.

```   
BOOL EndDialog(int nRetCode); 
```

### <a name="parameters"></a>Parâmetros

*nRetCode*  
[in] O valor a ser retornado por [CDialogImpl::DoModal](#domodal).

### <a name="return-value"></a>Valor de retorno

TRUE se a caixa de diálogo é destruída; Caso contrário, FALSE.

### <a name="remarks"></a>Comentários

`EndDialog` deve ser chamado por meio do procedimento de caixa de diálogo. Depois que a caixa de diálogo é destruída, o Windows usa o valor de *nRetCode* como o valor de retorno para `DoModal`, que criou a caixa de diálogo.

> [!NOTE]
>  Não chame `EndDialog` destruir uma caixa de diálogo sem janela restrita. Chame [CWindow::DestroyWindow](../../atl/reference/cwindow-class.md#destroywindow) em vez disso.

##  <a name="getdialogproc"></a>  CDialogImpl::GetDialogProc

Retorna `DialogProc`, o procedimento de caixa de diálogo atual.

```   
virtual WNDPROC GetDialogProc(); 
```

### <a name="return-value"></a>Valor de retorno

O procedimento de caixa de diálogo atual.

### <a name="remarks"></a>Comentários

Substitua este método para substituir o procedimento de caixa de diálogo com seus próprios.

##  <a name="mapdialogrect"></a>  CDialogImpl::MapDialogRect

Converte as unidades (maps) as unidades de caixa de diálogo do retângulo especificado para a tela (pixels).

```   
BOOL MapDialogRect(LPRECT lpRect); 
```

### <a name="parameters"></a>Parâmetros

*lpRect*  
Aponta para um `CRect` objeto ou [RECT](../../mfc/reference/rect-structure1.md) estrutura que receberá as coordenadas do cliente da atualização que inclui a região de atualização.

### <a name="return-value"></a>Valor de retorno

Diferente de zero se a atualização for bem-sucedida; 0 se a atualização falhar. Para obter outras informações sobre o erro, chame `GetLastError`.

### <a name="remarks"></a>Comentários

A função substitui as coordenadas especificado no `RECT` estrutura com as coordenadas convertidas, que permite que a estrutura a ser usado para criar uma caixa de diálogo ou posicionar um controle dentro de uma caixa de diálogo.

##  <a name="onfinalmessage"></a>  CDialogImpl::OnFinalMessage

Chamado após o recebimento da última mensagem (normalmente `WM_NCDESTROY`).

```   
virtual void OnFinalMessage(HWND hWnd); 
```

### <a name="parameters"></a>Parâmetros

*hWnd*  
[in] Um identificador para a janela que está sendo destruído.

### <a name="remarks"></a>Comentários

Observe que se você quiser excluir automaticamente seu objeto após a destruição de janela, você pode chamar **excluir este;** aqui.

##  <a name="startdialogproc"></a>  CDialogImpl::StartDialogProc

Chamado apenas uma vez, quando a primeira mensagem é recebida, para processar as mensagens enviadas para a caixa de diálogo.

```   
static LRESULT CALLBACK StartDialogProc(
    HWND hWnd,  
    UINT uMsg,  
    WPARAM wParam,  
    LPARAM lParam); 
```

### <a name="parameters"></a>Parâmetros

*hWnd*  
[in] O identificador para a caixa de diálogo.

*uMsg*  
[in] A mensagem enviada para a caixa de diálogo.

*wParam*  
[in] Obter informações adicionais específicas de mensagem.

*lParam*  
[in] Obter informações adicionais específicas de mensagem.

### <a name="return-value"></a>Valor de retorno

O procedimento de janela.

### <a name="remarks"></a>Comentários

Após a chamada inicial para `StartDialogProc`, `DialogProc` for definido como um procedimento de caixa de diálogo e ainda mais chamadas ir lá.

## <a name="see-also"></a>Consulte também

[BEGIN_MSG_MAP](message-map-macros-atl.md#begin_msg_map)   
[Visão geral da classe](../../atl/atl-class-overview.md)