---
title: Macros de mapa de mensagem (MFC)
ms.date: 11/04/2016
f1_keywords:
- AFXWIN/DECLARE_MESSAGE_MAP
- AFXWIN/BEGIN_MESSAGE_MAP
- AFXWIN/BEGIN_TEMPLATE_MESSAGE_MAP
- AFXWIN/END_MESSAGE_MAP
- AFXWIN/ON_COMMAND
- AFXWIN/ON_COMMAND_EX
- AFXWIN/ON_CONTROL
- AFXWIN/ON_MESSAGE
- AFXWIN/ON_OLECMD
- AFXWIN/ON_REGISTERED_MESSAGE
- AFXWIN/ON_REGISTERED_THREAD_MESSAGE
- AFXWIN/ON_THREAD_MESSAGE
- AFXWIN/ON_UPDATE_COMMAND_UI
- AFXWIN/ON_COMMAND_RANGE
- AFXWIN/ON_UPDATE_COMMAND_UI_RANGE
- AFXWIN/ON_CONTROL_RANGE
helpviewer_keywords:
- message map macros
- Windows messages [MFC], declaration
- demarcating Windows messages
- message maps [MFC], macros
- message maps [MFC], declaration and demarcation
- message mapping macros
- ranges, message map
- message map ranges
ms.assetid: 531b15ce-32b5-4ca0-a849-bb519616c731
ms.openlocfilehash: 6c6364dcf5d558bcdd25a2957721df1863d1f73f
ms.sourcegitcommit: c85c8a1226d8fbbaa29f4691ed719f8e6cc6575c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/24/2019
ms.locfileid: "54893659"
---
# <a name="message-map-macros-mfc"></a>Macros de mapa de mensagem (MFC)

Para dar suporte a mapas de mensagem, o MFC fornece as seguintes macros:

### <a name="message-map-declaration-and-demarcation-macros"></a>Mapa de mensagem de declaração e demarcação Macros

|||
|-|-|
|[DECLARE_MESSAGE_MAP](#declare_message_map)|Declara que um mapa de mensagem será usado em uma classe para mapear as mensagens para funções (deve ser usado na declaração de classe).|
|[BEGIN_MESSAGE_MAP](#begin_message_map)|Inicia a definição de um mapa de mensagem (deve ser usada na implementação da classe).|
|[BEGIN_TEMPLATE_MESSAGE_MAP](#begin_template_interface_map)|Inicia a definição de um mapa de mensagem em um tipo de classe que contém um argumento de modelo único. |
|[END_MESSAGE_MAP](#end_message_map)|Finaliza a definição de um mapa de mensagem (deve ser usada na implementação da classe).|

### <a name="message-mapping-macros"></a>Macros de mapeamento de mensagem

|||
|-|-|
|[ON_COMMAND](#on_command)|Indica qual função tratará uma mensagem de comando especificado.|
|[ON_COMMAND_EX](#on_command_ex)|Indica qual função tratará uma mensagem de comando especificado.|
|[ON_CONTROL](#on_control)|Indica qual função tratará uma mensagem de notificação do controle especificado.|
|[ON_MESSAGE](#on_message)|Indica qual função tratará uma mensagem definida pelo usuário.|
|[ON_OLECMD](#on_olecmd)|Indica qual função vai manipular um comando de menu de DocObject ou em seu contêiner.|
|[ON_REGISTERED_MESSAGE](#on_registered_message)|Indica qual função tratará uma mensagem de definida pelo usuário registrada.|
|[ON_REGISTERED_THREAD_MESSAGE](#on_registered_thread_message)|Indica qual função tratará uma mensagem de definida pelo usuário registrada quando você tem um `CWinThread` classe.|
|[ON_THREAD_MESSAGE](#on_thread_message)|Indica qual função tratará uma mensagem definida pelo usuário quando você tem um `CWinThread` classe.|
|[ON_UPDATE_COMMAND_UI](#on_update_command_ui)|Indica qual função tratará uma mensagem de comando de atualização de interface do usuário especificado.|

### <a name="message-map-range-macros"></a>Macros de mapa de mensagem de intervalo

|||
|-|-|
|[ON_COMMAND_RANGE](#on_command_range)|Indica qual função tratará o intervalo de IDs de comando especificadas nos dois primeiros parâmetros para a macro.|
|[ON_UPDATE_COMMAND_UI_RANGE](#on_update_command_ui_range)|Indica qual manipulador de atualização irá manipular o intervalo de IDs de comando especificado no pa duas primeiras] parâ à macro.|
|[ON_CONTROL_RANGE](#on_control_range)|Indica qual função manipulará notificações do intervalo de IDs especificadas no segundo e terceiro parâmetros para a macro de controle. O primeiro parâmetro é uma mensagem de notificação de controle, como BN_CLICKED.|

Para obter mais informações sobre mapas de mensagem, a declaração de mapa de mensagem e macros de demarcação e as macros de mapeamento de mensagem, consulte [mapas de mensagem](../../mfc/reference/message-maps-mfc.md) e [tópicos de mapeamento e manipulação de mensagens](../../mfc/message-handling-and-mapping.md). Para obter mais informações sobre intervalos de mapa de mensagem, consulte [manipuladores para intervalos de mapa de mensagem](../../mfc/handlers-for-message-map-ranges.md).

## <a name="begin_message_map"></a> BEGIN_MESSAGE_MAP

Inicia a definição de seu mapa de mensagem.

### <a name="syntax"></a>Sintaxe

```
BEGIN_MESSAGE_MAP( theClass, baseClass )
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Especifica o nome da classe cuja mensagem ser mapeado.

*baseClass*<br/>
Especifica o nome da classe base da *theClass*.

### <a name="remarks"></a>Comentários

No arquivo de implementação (. cpp) que define as funções de membro para a sua classe, inicie o mapa de mensagem com a macro BEGIN_MESSAGE_MAP, em seguida, adicionar entradas de macro para cada uma das suas funções de manipulador de mensagens e concluir o mapa de mensagem com o END_MESSAGE_MAP macro.

Para obter mais informações sobre mapas de mensagem, consulte [mapas de mensagem](message-maps-mfc.md)

### <a name="example"></a>Exemplo

```cpp
BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
   ON_WM_CREATE()
END_MESSAGE_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

##  <a name="begin_template_message_map"></a>BEGIN_TEMPLATE_MESSAGE_MAP

Inicia a definição de um mapa de mensagem em um tipo de classe que contém um argumento de modelo único.

### <a name="syntax"></a>Sintaxe

```
BEGIN_TEMPLATE_MESSAGE_MAP( theClass, type_name, baseClass )
```

### <a name="parameters"></a>Parâmetros

*theClass*<br/>
Especifica o nome da classe cuja mensagem ser mapeado.

*type_name*<br/>
O nome do parâmetro de modelo especificado para a classe.

*baseClass*<br/>
Especifica o nome da classe base da *theClass*.

### <a name="remarks"></a>Comentários

Essa macro é semelhante para o [BEGIN_MESSAGE_MAP](message-map-macros-mfc.md#begin_message_map) macro; no entanto, essa macro destina-se para as classes que contêm um argumento de modelo único.

Na seção de implementação de método de sua classe, inicie o mapa de mensagem com a macro BEGIN_TEMPLATE_MESSAGE_MAP; em seguida, adicione entradas de macro para cada um dos seus métodos de manipulador de mensagens como você faria para um mapa de mensagem padrão. Como com a macro BEGIN_MESSAGE_MAP, concluir o mapa de mensagem do modelo com o [END_MESSAGE_MAP](message-map-macros-mfc.md#end_message_map) macro.

Para obter mais informações sobre a implementação de mapas de mensagem para classes de modelo, consulte [como: Criar um mapa de mensagem para uma classe de modelo](../how-to-create-a-message-map-for-a-template-class.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

## <a name="declare_message_map"></a>  DECLARE_MESSAGE_MAP

Declara que a classe define um mapa de mensagem. Cada `CCmdTarget`-classe derivada em seu programa deve fornecer um mapa de mensagem para lidar com mensagens.

### <a name="syntax"></a>Sintaxe

```
DECLARE_MESSAGE_MAP( )
```

### <a name="remarks"></a>Comentários

Use a macro DECLARE_MESSAGE_MAP no final de sua declaração de classe. Em seguida, no arquivo. cpp que define as funções de membro da classe, use a macro BEGIN_MESSAGE_MAP, entradas de macro para cada uma das suas funções de manipulador de mensagens e a macro END_MESSAGE_MAP.

> [!NOTE]
>  Se você declarar qualquer membro depois DECLARE_MESSAGE_MAP, você deve especificar um novo tipo de acesso (**pública**, **privada**, ou **protegido**) para eles.

Para obter mais informações sobre mapas de mensagem e a macro DECLARE_MESSAGE_MAP, consulte [manipulação de mensagens e o mapeamento de tópicos](../../mfc/message-handling-and-mapping.md).

### <a name="example"></a>Exemplo

```cpp
class CMainFrame : public CMDIFrameWnd
{
   DECLARE_MESSAGE_MAP()

   // Remainder of class declaration omitted.
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

## <a name="end_message_map"></a>  END_MESSAGE_MAP

Finaliza a definição de seu mapa de mensagem.

### <a name="syntax"></a>Sintaxe

```
END_MESSAGE_MAP( )
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre mapas de mensagem e a macro END_MESSAGE_MAP, consulte [manipulação de mensagens e o mapeamento de tópicos](../../mfc/message-handling-and-mapping.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin. h

## <a name="on_command"></a>  ON_COMMAND

Essa macro mapeia uma mensagem de comando para uma função de membro.

### <a name="syntax"></a>Sintaxe

```
ON_COMMAND( id, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
A ID de comando.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para o qual o comando é mapeado.

### <a name="remarks"></a>Comentários

Ele indica qual função tratará uma mensagem de comando de um objeto de interface do usuário de comando como um botão de barra de ferramentas ou item de menu.

Quando um objeto de destino do comando recebe uma mensagem WM_COMMAND do Windows com a ID especificada, ON_COMMAND chamará a função de membro `memberFxn` para lidar com a mensagem.

Use ON_COMMAND para mapear um único comando para uma função de membro. Use [ON_COMMAND_RANGE](#on_command_range) para mapear um intervalo de ids de comando para a função de um membro. Apenas uma entrada de mapa de mensagem pode corresponder a uma id de comando especificada. Ou seja, você não pode mapear um comando para mais de um manipulador. Para obter mais informações e exemplos, consulte [manipulação de mensagens e o mapeamento de tópicos](../../mfc/message-handling-and-mapping.md).

### <a name="example"></a>Exemplo

```cpp
BEGIN_MESSAGE_MAP(CMFCListViewDoc, CDocument)
   ON_COMMAND(ID_MYCOMMAND, &CMFCListViewDoc::OnMycommand)
END_MESSAGE_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

## <a name="on_command_ex"></a>  ON_COMMAND_EX

Estendido a função de membro de manipulador de comandos.

### <a name="syntax"></a>Sintaxe

```
ON_COMMAND_EX(id, memberFxn);
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
A ID de comando.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para o qual o comando é mapeado.

### <a name="remarks"></a>Comentários

Uma forma estendida de manipuladores de mensagens de comando está disponível para usos avançados. A macro ON_COMMAND_EX é usada para esses manipuladores de mensagens e fornece um superconjunto do [ON_COMMAND](message-map-macros-mfc.md#on_command) funcionalidade. Funções de membro de manipulador de comandos estendidos usam um único parâmetro, UINT que contém a ID de comando e retornam um BOOL. O valor de retorno deve ser verdadeiro para indicar que o comando foi tratado; Caso contrário, o roteamento continuará a outros objetos de destino do comando.

Para obter mais informações, consulte a Observação técnica [TN006: Mapas de mensagem] tm006-mensagem-maps.md).

### <a name="requirements"></a>Requisitos

Arquivo de cabeçalho: afxmsg_.h

### <a name="see-also"></a>Consulte também

[ON_COMMAND](message-map-macros-mfc.md#on_command)<br/>
[TN006: Mapas de mensagem](../tn006-message-maps.md)

## <a name="on_control"></a>  ON_CONTROL

Indica qual função tratará uma mensagem de notificação do controle personalizado.

### <a name="syntax"></a>Sintaxe

```
ON_CONTROL( wNotifyCode, id, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*wNotifyCode*<br/>
O código de notificação do controle.

*id*<br/>
A ID de comando.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para o qual o comando é mapeado.

### <a name="remarks"></a>Comentários

Mensagens de notificação do controle são aquelas enviadas por um controle à sua janela pai.

Deve haver exatamente uma instrução de macro ON_CONTROL no seu mapa de mensagens para cada mensagem de notificação do controle que deve ser mapeada para uma função de manipulador de mensagens.

Para obter mais informações e exemplos, consulte [manipulação de mensagens e o mapeamento de tópicos](../../mfc/message-handling-and-mapping.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

## <a name="on_message"></a>  ON_MESSAGE

Indica qual função tratará uma mensagem definida pelo usuário.

### <a name="syntax"></a>Sintaxe

```
ON_MESSAGE( message, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*message*<br/>
A ID da mensagem.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para o qual a mensagem é mapeada.

O tipo da função deve ser `afx_msg LRESULT (CWnd::*)(WPARAM, LPARAM)`.

### <a name="remarks"></a>Comentários

Mensagens definidas pelo usuário são todas as mensagens que não são mensagens do Windows WM_MESSAGE padrão. Ao selecionar uma ID de mensagem, você deve usar valores dentro do intervalo de WM_USER (0x0400) 0x7FFF ou WM_APP (0x8000) para 0xBFFF. Para obter mais informações sobre IDs de mensagens, consulte [WM_APP](/windows/desktop/winmsg/wm-app).

Deve haver exatamente uma instrução de macro ON_MESSAGE no mapa de mensagem para todas as mensagens definidas pelo usuário que devem ser mapeada para uma função de manipulador de mensagens.

> [!NOTE]
>  Além de mensagens definidas pelo usuário, ON_MESSAGE lida com mensagens menos comuns do Windows. Para obter mais informações, consulte [mapas de mensagem](../../mfc/tn006-message-maps.md).

Para obter mais informações e exemplos, consulte [manipulação de mensagens e os tópicos de mapeamento](../../mfc/message-handling-and-mapping.md) e [manipuladores definidos pelo usuário](user-defined-handlers.md)

### <a name="example"></a>Exemplo

```cpp
#define WM_MYMESSAGE (WM_USER + 100)

BEGIN_MESSAGE_MAP(CMyWnd2, CWnd)
   ON_MESSAGE(WM_MYMESSAGE, OnMyMessage)
END_MESSAGE_MAP()

// inside the class declaration
afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);

LRESULT CMyWnd2::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
   UNREFERENCED_PARAMETER(wParam);
   UNREFERENCED_PARAMETER(lParam);

   // Handle message here.

   return 0;
}
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

## <a name="on_olecmd"></a>  ON_OLECMD

Roteia comandos por meio da interface de expedição do comando `IOleCommandTarget`.

### <a name="syntax"></a>Sintaxe

```
ON_OLECMD( pguid, olecmdid, id )
```

### <a name="parameters"></a>Parâmetros

*pguid*<br/>
Identificador do grupo de comando ao qual pertence o comando. Use NULL para o grupo padrão.

*olecmdid*<br/>
O identificador do comando OLE.

*id*<br/>
A ID do menu, ID da barra de ferramentas, button ID ou outra ID do recurso ou objeto emitindo o comando.

### <a name="remarks"></a>Comentários

`IOleCommandTarget` permite que um contêiner receber comandos que se originam na interface do usuário do DocObject e permite que o contêiner enviar os mesmos comandos (como novo, abrir, salvar como e imprimir no menu Arquivo; e copiar, colar, desfazer, e assim por diante no menu Editar) para DocObject.

`IOleCommandTarget` é mais simples do que a automação OLE `IDispatch`. `IOleCommandTarget` se baseia inteiramente em um conjunto padrão de comandos que raramente têm argumentos, e nenhuma informação de tipo está envolvida (segurança de tipos é reduzida para argumentos de comando também). Se você precisar enviar comandos com argumentos, use [COleServerDoc::OnExecOleCmd](coleserverdoc-class.md#onexecolecmd).

O `IOleCommandTarget` comandos de menu padrão foram implementados pelo MFC em macros a seguir:

**ON_OLECMD_CLEARSELECTION( )**

Envia o comando Editar Clear. Implementado como:

`ON_OLECMD(NULL, OLECMDID_CLEARSELECTION, ID_EDIT_CLEAR)`

**ON_OLECMD_COPY( )**

Envia o comando Editar cópia. Implementado como:

`ON_OLECMD(NULL, OLECMDID_COPY, ID_EDIT_COPY)`

**ON_OLECMD_CUT( )**

Envia o comando Editar recortar. Implementado como:

`ON_OLECMD(NULL, OLECMDID_CUT, ID_EDIT_CUT)`

**ON_OLECMD_NEW( )**

Envia o comando novo arquivo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_NEW, ID_FILE_NEW)`

**ON_OLECMD_OPEN( )**

Envia o comando Abrir arquivo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_OPEN, ID_FILE_OPEN)`

**ON_OLECMD_PAGESETUP( )**

Envia o comando de configuração de página do arquivo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PAGESETUP, ID_FILE_PAGE_SETUP)`

**ON_OLECMD_PASTE( )**

Envia o comando Colar editar. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PASTE, ID_EDIT_PASTE)`

**ON_OLECMD_PASTESPECIAL( )**

Envia o comando Editar Colar especial. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PASTESPECIAL, ID_EDIT_PASTE_SPECIAL)`

**ON_OLECMD_PRINT( )**

Envia o comando Print do arquivo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PRINT, ID_FILE_PRINT)`

**ON_OLECMD_PRINTPREVIEW( )**

Envia o comando de visualização de impressão do arquivo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PRINTPREVIEW, ID_FILE_PRINT_PREVIEW)`

**ON_OLECMD_REDO( )**

Envia o comando Editar refazer. Implementado como:

`ON_OLECMD(NULL, OLECMDID_REDO, ID_EDIT_REDO)`

**ON_OLECMD_SAVE( )**

Envia o comando Salvar do arquivo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_SAVE, ID_FILE_SAVE)`

**ON_OLECMD_SAVE_AS( )**

Envia o comando Salvar como arquivo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_SAVEAS, ID_FILE_SAVE_AS)`

**ON_OLECMD_SAVE_COPY_AS( )**

Envia o comando Arquivo-Salvar cópia como. Implementado como:

`ON_OLECMD(NULL, OLECMDID_SAVECOPYAS, ID_FILE_SAVE_COPY_AS)`

**ON_OLECMD_SELECTALL( )**

Envia o comando Editar Selecionar tudo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_SELECTALL, ID_EDIT_SELECT_ALL)`

**ON_OLECMD_UNDO( )**

Envia o comando Desfazer Editar. Implementado como:

`ON_OLECMD(NULL, OLECMDID_UNDO, ID_EDIT_UNDO)`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdocob.h

### <a name="see-also"></a>Consulte também

[Classe COleCmdUI](colecmdui-class.md)<br/>
[COleServerDoc::OnExecOleCmd](coleserverdoc-class.md#onexecolecmd)

## <a name="on_registered_message"></a>  ON_REGISTERED_MESSAGE

O Windows `RegisterWindowMessage` função é usada para definir uma nova mensagem de janela que é garantido que seja exclusivo em todo o sistema.

### <a name="syntax"></a>Sintaxe

```
ON_REGISTERED_MESSAGE( nMessageVariable, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*nMessageVariable*<br/>
A variável de ID de mensagem de janela registrada.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para o qual a mensagem é mapeada.

### <a name="remarks"></a>Comentários

Essa macro indica qual função irá manipular a mensagem registrada.

Para obter mais informações e exemplos, consulte [manipulação de mensagens e o mapeamento de tópicos](../../mfc/message-handling-and-mapping.md).

### <a name="example"></a>Exemplo

```cpp
static UINT NEAR WM_FIND = RegisterWindowMessage(_T("COMMDLG_FIND"));

BEGIN_MESSAGE_MAP(CMyWnd3, CWnd)
   ON_REGISTERED_MESSAGE(WM_FIND, OnFind)
END_MESSAGE_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

### <a name="see-also"></a>Consulte também

[RegisterWindowMessage](/windows/desktop/api/winuser/nf-winuser-registerwindowmessagea)<br/>
[Manipuladores definidos pelo usuário](user-defined-handlers.md)

## <a name="on_registered_thread_message"></a>  ON_REGISTERED_THREAD_MESSAGE

Indica qual função irá manipular a mensagem registrado pela função RegisterWindowMessage do Windows.

### <a name="syntax"></a>Sintaxe

```
ON_REGISTERED_THREAD_MESSAGE(nMessageVariable, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*nMessageVariable*<br/>
A variável de ID de mensagem de janela registrada.

*memberFxn*<br/>
O nome da função de manipulador de mensagens CWinThread ao qual a mensagem é mapeada.

### <a name="remarks"></a>Comentários

RegisterWindowMessage é usado para definir uma nova mensagem de janela que é garantido que seja exclusivo em todo o sistema. ON_REGISTERED_THREAD_MESSAGE deve ser usado em vez de ON_REGISTERED_MESSAGE quando você tem uma classe CWinThread.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

## <a name="on_thread_message"></a>  ON_THREAD_MESSAGE

Indica qual função tratará uma mensagem definida pelo usuário.

### <a name="syntax"></a>Sintaxe

```
ON_THREAD_MESSAGE( message, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*message*<br/>
A ID da mensagem.

*memberFxn*<br/>
O nome da `CWinThread`-mensagem-função de manipulador para o qual a mensagem é mapeada.

### <a name="remarks"></a>Comentários

ON_THREAD_MESSAGE deve ser usado em vez de ON_MESSAGE quando você tem um `CWinThread` classe. Mensagens definidas pelo usuário são todas as mensagens que não são mensagens do Windows WM_MESSAGE padrão. Deve haver exatamente uma instrução de macro ON_THREAD_MESSAGE no mapa de mensagem para todas as mensagens definidas pelo usuário que devem ser mapeada para uma função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="on_update_command_ui"></a>  ON_UPDATE_COMMAND_UI

Essa macro indica qual função tratará uma mensagem de comando de atualização de interface do usuário.

### <a name="syntax"></a>Sintaxe

```
ON_UPDATE_COMMAND_UI( id, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*id*<br/>
A ID da mensagem.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para o qual a mensagem é mapeada.

### <a name="remarks"></a>Comentários

Deve haver exatamente uma instrução de macro ON_UPDATE_COMMAND_UI no seu mapa de mensagem para cada comando de atualização de interface do usuário que deve ser mapeado para uma função de manipulador de mensagens.

Para obter mais informações e exemplos, consulte [manipulação de mensagens e o mapeamento de tópicos](../../mfc/message-handling-and-mapping.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

### <a name="see-also"></a>Consulte também

[Classe CCmdUI](ccmdui-class.md)

## <a name="on_command_range"></a>  ON_COMMAND_RANGE

Use essa macro para mapear um intervalo contíguo de IDs de comando para uma função de manipulador de mensagens única.

### <a name="syntax"></a>Sintaxe

```
ON_COMMAND_RANGE( id1, id2, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*id1*<br/>
ID de comando no início de um intervalo contíguo de IDs de comando.

*id2*<br/>
ID de comando ao final de um intervalo contíguo de IDs de comando.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para o qual os comandos são mapeados.

### <a name="remarks"></a>Comentários

O intervalo de IDs começa com *id1* e termina com *id2*.

Use ON_COMMAND_RANGE para mapear um intervalo de IDs de comando para a função de membro de um. Use [ON_COMMAND](#on_command) para mapear um único comando para uma função de membro. Apenas uma entrada de mapa de mensagem pode corresponder a uma ID de comando especificada. Ou seja, você não pode mapear um comando para mais de um manipulador. Para obter mais informações sobre intervalos de mensagens de mapeamento, consulte [manipuladores para intervalos de mapa de mensagem](../../mfc/handlers-for-message-map-ranges.md).

Não há nenhum suporte automático para intervalos de mapa de mensagem, portanto, você deve colocar a macro.

### <a name="example"></a>Exemplo

```cpp
// The code fragment below shows how to use ON_COMMAND_RANGE macro
// to map a contiguous range of command IDs to a single message
// handler function (i.e. OnRangeCmds() in the sample below). In
// addition, it also shows how to use CheckMenuRadioItem() to check a
// selected menu item and makes it a radio item.

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
   ON_COMMAND_RANGE(ID_COMMAND_RANGECMD1, ID_COMMAND_RANGECMD3, &CChildFrame::OnRangeCmds)
END_MESSAGE_MAP()

void CChildFrame::OnRangeCmds(UINT nID)
{
   CMenu* mmenu = AfxGetMainWnd()->GetMenu();
   CMenu* submenu = mmenu->GetSubMenu(5);
   submenu->CheckMenuRadioItem(ID_COMMAND_RANGECMD1, ID_COMMAND_RANGECMD3,
      nID, MF_BYCOMMAND);
}
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

## <a name="on_update_command_ui_range"></a>  ON_UPDATE_COMMAND_UI_RANGE

Mapeia um intervalo contíguo de IDs de comando para uma função de manipulador de mensagens única atualização.

### <a name="syntax"></a>Sintaxe

```
ON_UPDATE_COMMAND_UI_RANGE( id1, id2, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*id1*<br/>
ID de comando no início de um intervalo contíguo de IDs de comando.

*id2*<br/>
ID de comando ao final de um intervalo contíguo de IDs de comando.

*memberFxn*<br/>
O nome da função de manipulador de mensagens de atualização para o qual os comandos são mapeados.

### <a name="remarks"></a>Comentários

Manipuladores de mensagens de atualização de atualizar o estado dos itens de menu e botões de barra de ferramentas associadas ao comando. O intervalo de IDs começa com *id1* e termina com *id2*.

Não há nenhum suporte automático para intervalos de mapa de mensagem, portanto, você deve colocar a macro.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

## <a name="on_control_range"></a>  ON_CONTROL_RANGE

Use essa macro para mapear um intervalo contíguo de IDs de controle para uma função de manipulador de mensagem único para uma mensagem de notificação especificada do Windows, como BN_CLICKED.

### <a name="syntax"></a>Sintaxe

```
ON_CONTROL_RANGE( wNotifyCode, id1, id2, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*wNotifyCode*<br/>
O código de notificação para o qual o manipulador está respondendo.

*id1*<br/>
ID de comando no início de um intervalo contíguo de IDs de controle.

*id2*<br/>
ID de comando ao final de um intervalo contíguo de IDs de controle.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para o qual os controles são mapeados.

### <a name="remarks"></a>Comentários

O intervalo de IDs começa com *id1* e termina com *id2*. O manipulador é chamado para a notificação especificada provenientes de qualquer um dos controles mapeados.

Não há nenhum suporte automático para intervalos de mapa de mensagem, portanto, você deve colocar a macro.

Para obter mais informações sobre como implementar funções de manipulador para um intervalo de IDs de controle, consulte [manipuladores para intervalos de mapa de mensagem](../../mfc/handlers-for-message-map-ranges.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h
