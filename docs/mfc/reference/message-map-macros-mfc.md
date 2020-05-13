---
title: Macros de mapa de mensagem (MFC)
ms.date: 03/27/2019
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
ms.openlocfilehash: 6e9291f0f39057403bc27c7fe4ff5ca5a82dfe3a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81356593"
---
# <a name="message-map-macros-mfc"></a>Macros de mapa de mensagem (MFC)

Para suportar mapas de mensagens, o MFC fornece as seguintes macros:

### <a name="message-map-declaration-and-demarcation-macros"></a>Macros de Declaração e Demarcação do Mapa de Mensagens

|||
|-|-|
|[Declare_message_map](#declare_message_map)|Declara que um mapa de mensagens será usado em uma classe para mapear mensagens para funções (deve ser usado na declaração de classe).|
|[BEGIN_MESSAGE_MAP](#begin_message_map)|Começa a definição de um mapa de mensagem (deve ser usado na implementação da classe).|
|[BEGIN_TEMPLATE_MESSAGE_MAP](#begin_template_message_map)|Começa a definição de um mapa de mensagem em um tipo de classe contendo um único argumento de modelo. |
|[END_MESSAGE_MAP](#end_message_map)|Termina a definição de um mapa de mensagem (deve ser usado na implementação da classe).|

### <a name="message-mapping-macros"></a>Macros de mapeamento de mensagens

|||
|-|-|
|[ON_COMMAND](#on_command)|Indica qual função lidará com uma mensagem de comando especificada.|
|[ON_COMMAND_EX](#on_command_ex)|Indica qual função lidará com uma mensagem de comando especificada.|
|[ON_CONTROL](#on_control)|Indica qual função lidará com uma mensagem de notificação de controle especificada.|
|[ON_MESSAGE](#on_message)|Indica qual função lidará com uma mensagem definida pelo usuário.|
|[ON_OLECMD](#on_olecmd)|Indica qual função lidará com um comando de menu de um DocObject ou seu contêiner.|
|[ON_REGISTERED_MESSAGE](#on_registered_message)|Indica qual função lidará com uma mensagem definida pelo usuário registrada.|
|[ON_REGISTERED_THREAD_MESSAGE](#on_registered_thread_message)|Indica qual função lidará com uma mensagem `CWinThread` definida pelo usuário registrada quando você tiver uma classe.|
|[ON_THREAD_MESSAGE](#on_thread_message)|Indica qual função lidará com uma mensagem definida pelo usuário quando você tiver uma `CWinThread` classe.|
|[ON_UPDATE_COMMAND_UI](#on_update_command_ui)|Indica qual função lidará com uma mensagem de comando de atualização de interface de usuário especificada.|

### <a name="message-map-range-macros"></a>Macros de intervalo de mapa de mensagens

|||
|-|-|
|[ON_COMMAND_RANGE](#on_command_range)|Indica qual função lidará com o intervalo de IDs de comando especificados nos dois primeiros parâmetros para a macro.|
|[ON_UPDATE_COMMAND_UI_RANGE](#on_update_command_ui_range)|Indica qual manipulador de atualizações lidará com a gama de IDs de comando especificados nos dois primeiros parâmetros para a macro.|
|[ON_CONTROL_RANGE](#on_control_range)|Indica qual função lidará com notificações da faixa de IDs de controle especificadas no segundo e terceiro parâmetros para a macro. O primeiro parâmetro é uma mensagem de notificação de controle, como BN_CLICKED.|

Para obter mais informações sobre mapas de mensagens, as macros de declaração e demarcação do mapa de mensagens e as macros de mapeamento de mensagens, consulte Mapas de [mensagens](../../mfc/reference/message-maps-mfc.md) e [tópicos de manipulação e mapeamento de mensagens](../../mfc/message-handling-and-mapping.md). Para obter mais informações sobre os intervalos do mapa de mensagens, consulte [Manipuladores para intervalos de mapa de mensagens](../../mfc/handlers-for-message-map-ranges.md).

## <a name="begin_message_map"></a><a name="begin_message_map"></a>Begin_message_map

Começa a definição do seu mapa de mensagens.

### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_MESSAGE_MAP( theClass, baseClass )
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Especifica o nome da classe cujo mapa de mensagem é este.

*Baseclass*<br/>
Especifica o nome da classe base *doClass*.

### <a name="remarks"></a>Comentários

No arquivo de implementação (.cpp) que define as funções do membro para sua classe, inicie o mapa de mensagens com a BEGIN_MESSAGE_MAP macro, adicione entradas de macro para cada uma de suas funções de manipulador de mensagens e complete o mapa de mensagens com a END_MESSAGE_MAP macro.

Para obter mais informações sobre mapas de mensagens, consulte [Mapas de mensagens](message-maps-mfc.md)

### <a name="example"></a>Exemplo

```cpp
BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
   ON_WM_CREATE()
END_MESSAGE_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="begin_template_message_map"></a><a name="begin_template_message_map"></a>BEGIN_TEMPLATE_MESSAGE_MAP

Começa a definição de um mapa de mensagem em um tipo de classe contendo um único argumento de modelo.

### <a name="syntax"></a>Sintaxe

```cpp
BEGIN_TEMPLATE_MESSAGE_MAP( theClass, type_name, baseClass )
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
Especifica o nome da classe cujo mapa de mensagem é este.

*Type_name*<br/>
O nome do parâmetro de modelo especificado para a classe.

*Baseclass*<br/>
Especifica o nome da classe base *doClass*.

### <a name="remarks"></a>Comentários

Esta macro é semelhante à [BEGIN_MESSAGE_MAP](message-map-macros-mfc.md#begin_message_map) macro; no entanto, esta macro destina-se a classes que contenham um único argumento de modelo.

Na seção de implementação do método da sua classe, inicie o mapa de mensagens com a BEGIN_TEMPLATE_MESSAGE_MAP macro; em seguida, adicione entradas de macro para cada um de seus métodos de manipulador de mensagens como você faria para um mapa de mensagem padrão. Assim como na BEGIN_MESSAGE_MAP macro, complete o mapa de mensagem do modelo com a [END_MESSAGE_MAP](message-map-macros-mfc.md#end_message_map) macro.

Para obter mais informações sobre a implementação de mapas de mensagens para classes de modelo, consulte [Como: Criar um mapa de mensagens para uma classe de modelos](../how-to-create-a-message-map-for-a-template-class.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="declare_message_map"></a><a name="declare_message_map"></a>Declare_message_map

Declara que a classe define um mapa de mensagem. Cada `CCmdTarget`classe derivada do seu programa deve fornecer um mapa de mensagem para lidar com as mensagens.

### <a name="syntax"></a>Sintaxe

```cpp
DECLARE_MESSAGE_MAP( )
```

### <a name="remarks"></a>Comentários

Use a macro DECLARE_MESSAGE_MAP no final da declaração da classe. Em seguida, no arquivo .cpp que define as funções do membro para a classe, use a BEGIN_MESSAGE_MAP macro, as entradas de macro para cada uma de suas funções de manipulador de mensagens e a macro END_MESSAGE_MAP.

> [!NOTE]
> Se você declarar qualquer membro após DECLARE_MESSAGE_MAP, você deve especificar um novo tipo de acesso **(público,** **privado**ou **protegido)** para eles.

Para obter mais informações sobre mapas de mensagens e a macro DECLARE_MESSAGE_MAP, consulte [Tópicos de manipulação e mapeamento de mensagens](../../mfc/message-handling-and-mapping.md).

### <a name="example"></a>Exemplo

```cpp
class CMainFrame : public CMDIFrameWnd
{
   DECLARE_MESSAGE_MAP()

   // Remainder of class declaration omitted.
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="end_message_map"></a><a name="end_message_map"></a>End_message_map

Termina a definição do seu mapa de mensagens.

### <a name="syntax"></a>Sintaxe

```cpp
END_MESSAGE_MAP( )
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre mapas de mensagens e a macro END_MESSAGE_MAP, consulte [Tópicos de manipulação e mapeamento de mensagens](../../mfc/message-handling-and-mapping.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="on_command"></a><a name="on_command"></a>On_command

Esta macro mapeia uma mensagem de comando para uma função de membro.

### <a name="syntax"></a>Sintaxe

```cpp
ON_COMMAND( commandId, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*Commandid*<br/>
O id de comando.

*Memberfxn*<br/>
O nome da função de manipulador de mensagens para a qual o comando é mapeado.

### <a name="remarks"></a>Comentários

Ele indica qual função lidará com uma mensagem de comando de um objeto de interface de usuário de comando, como um item de menu ou botão de barra de ferramentas.

Quando um objeto de destino de comando recebe uma mensagem WM_COMMAND do `memberFxn` Windows com o ID especificado, ON_COMMAND chamará a função de membro para lidar com a mensagem.

Use ON_COMMAND para mapear um único comando para uma função de membro. Use [ON_COMMAND_RANGE](#on_command_range) para mapear uma gama de IDs de comando para uma função de membro. Apenas uma entrada de mapa de mensagem pode corresponder a um determinado ID de comando. Ou seja, você não pode mapear um comando para mais de um manipulador. Para obter mais informações e exemplos, consulte [Tópicos de manipulação e mapeamento de mensagens](../../mfc/message-handling-and-mapping.md).

### <a name="example"></a>Exemplo

```cpp
BEGIN_MESSAGE_MAP(CMFCListViewDoc, CDocument)
   ON_COMMAND(ID_MYCOMMAND, &CMFCListViewDoc::OnMycommand)
END_MESSAGE_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

## <a name="on_command_ex"></a><a name="on_command_ex"></a>On_command_ex

Função de membro do manipulador de comando estendida.

### <a name="syntax"></a>Sintaxe

```cpp
ON_COMMAND_EX(commandId, memberFxn);
```

### <a name="parameters"></a>Parâmetros

*Commandid*<br/>
O id de comando.

*Memberfxn*<br/>
O nome da função de manipulador de mensagens para a qual o comando é mapeado.

### <a name="remarks"></a>Comentários

Uma forma estendida de manipuladores de mensagens de comando está disponível para usos avançados. A ON_COMMAND_EX macro é usada para esses manipuladores de mensagens e fornece um superconjunto da funcionalidade [ON_COMMAND.](message-map-macros-mfc.md#on_command) As funções de membro do manipulador de comando estendidas pegam um único parâmetro, um UINT contendo o ID de comando e retornam um BOOL. O valor de retorno deve ser TRUE para indicar que o comando foi manipulado; caso contrário, o roteamento continuará para outros objetos de alvo de comando.

Para obter mais informações, consulte Nota Técnica [TN006: Mapas de mensagem]tm006-message-maps.md).

### <a name="requirements"></a>Requisitos

Arquivo de cabeçalho: afxmsg_.h

## <a name="on_control"></a><a name="on_control"></a>On_control

Indica qual função lidará com uma mensagem de notificação de controle personalizado.

### <a name="syntax"></a>Sintaxe

```cpp
ON_CONTROL( wNotifyCode, commandId, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*wNotifyCode*<br/>
O código de notificação do controle.

*Commandid*<br/>
O id de comando.

*Memberfxn*<br/>
O nome da função de manipulador de mensagens para a qual o comando é mapeado.

### <a name="remarks"></a>Comentários

As mensagens de notificação de controle são aquelas enviadas de um controle para sua janela pai.

Deve haver exatamente uma ON_CONTROL macro no mapa de mensagens para cada mensagem de notificação de controle que deve ser mapeada para uma função de manipulador de mensagens.

Para obter mais informações e exemplos, consulte [Tópicos de manipulação e mapeamento de mensagens](../../mfc/message-handling-and-mapping.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

## <a name="on_message"></a><a name="on_message"></a>On_message

Indica qual função lidará com uma mensagem definida pelo usuário.

### <a name="syntax"></a>Sintaxe

```cpp
ON_MESSAGE( message, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
A ID da mensagem.

*Memberfxn*<br/>
O nome da função de manipulador de mensagens para a qual a mensagem é mapeada.

O tipo de função `afx_msg LRESULT (CWnd::*)(WPARAM, LPARAM)`deve ser .

### <a name="remarks"></a>Comentários

Mensagens definidas pelo usuário são mensagens que não são mensagens padrão do Windows WM_MESSAGE. Ao selecionar um ID de mensagem, você deve usar valores dentro da faixa de WM_USER (0x0400) a 0x7FFF ou WM_APP (0x8000) a 0xBFFF. Para obter mais informações sobre as iDs de mensagem, consulte [WM_APP](/windows/win32/winmsg/wm-app).

Deve haver exatamente uma ON_MESSAGE de macro no mapa de mensagens para cada mensagem definida pelo usuário que deve ser mapeada para uma função de manipulador de mensagens.

> [!NOTE]
> Além das mensagens definidas pelo usuário, ON_MESSAGE lida com mensagens menos comuns do Windows. Para obter mais informações, consulte [Mapas de mensagens](../../mfc/tn006-message-maps.md).

Para obter mais informações e exemplos, consulte Tópicos [de manipulação e mapeamento de mensagens e manipuladores](../../mfc/message-handling-and-mapping.md) [definidos pelo usuário](user-defined-handlers.md)

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

## <a name="on_olecmd"></a><a name="on_olecmd"></a>On_olecmd

Comandos de rotas através `IOleCommandTarget`da interface de despacho de comando .

### <a name="syntax"></a>Sintaxe

```cpp
ON_OLECMD( pguid, olecmdid, commandId )
```

### <a name="parameters"></a>Parâmetros

*Pguid*<br/>
Identificador do grupo de comando ao qual o comando pertence. Use NULL para o grupo padrão.

*olecmdid*<br/>
O identificador do comando OLE.

*Commandid*<br/>
O ID do menu, o ID da barra de ferramentas, o ID do botão ou outro ID do recurso ou objeto que emite o comando.

### <a name="remarks"></a>Comentários

`IOleCommandTarget`permite que um contêiner receba comandos que se originam na interface de usuário de um DocObject e permite que o contêiner envie os mesmos comandos (como Novo, Abrir, SaveAs e Imprimir no menu Arquivo; e Copiar, Colar, Desfazer e assim por diante no menu Editar) para um DocObject.

`IOleCommandTarget`é mais simples do `IDispatch`que o Da OLE Automation. `IOleCommandTarget`depende inteiramente de um conjunto padrão de comandos que raramente têm argumentos, e nenhuma informação de tipo está envolvida (a segurança do tipo também é diminuída para argumentos de comando). Se você precisar despachar comandos com argumentos, use [COleServerDoc::OnExecOleCmd](coleserverdoc-class.md#onexecolecmd).

Os `IOleCommandTarget` comandos de menu padrão foram implementados pelo MFC nas seguintes macros:

**ON_OLECMD_CLEARSELECTION.**

Despacha o comando Editar limpar. Implementado como:

`ON_OLECMD(NULL, OLECMDID_CLEARSELECTION, ID_EDIT_CLEAR)`

**ON_OLECMD_COPY.**

Despacha o comando Editar copiar. Implementado como:

`ON_OLECMD(NULL, OLECMDID_COPY, ID_EDIT_COPY)`

**ON_OLECMD_CUT.**

Despacha o comando Editar cortar. Implementado como:

`ON_OLECMD(NULL, OLECMDID_CUT, ID_EDIT_CUT)`

**ON_OLECMD_NEW.**

Despacha o comando File New. Implementado como:

`ON_OLECMD(NULL, OLECMDID_NEW, ID_FILE_NEW)`

**ON_OLECMD_OPEN.**

Despacha o comando File Open. Implementado como:

`ON_OLECMD(NULL, OLECMDID_OPEN, ID_FILE_OPEN)`

**ON_OLECMD_PAGESETUP.**

Despacha o comando Configuração da página de arquivos. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PAGESETUP, ID_FILE_PAGE_SETUP)`

**ON_OLECMD_PASTE.**

Despacha o comando Editar colar. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PASTE, ID_EDIT_PASTE)`

**ON_OLECMD_PASTESPECIAL.**

Despacha o comando Editar colar especial. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PASTESPECIAL, ID_EDIT_PASTE_SPECIAL)`

**ON_OLECMD_PRINT.**

Despacha o comando File Print. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PRINT, ID_FILE_PRINT)`

**ON_OLECMD_PRINTPREVIEW.**

Despacha o comando File Print Preview. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PRINTPREVIEW, ID_FILE_PRINT_PREVIEW)`

**ON_OLECMD_REDO**

Despacha o comando Editar Redo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_REDO, ID_EDIT_REDO)`

**ON_OLECMD_SAVE.**

Despacha o comando 'Salvar arquivos'. Implementado como:

`ON_OLECMD(NULL, OLECMDID_SAVE, ID_FILE_SAVE)`

**ON_OLECMD_SAVE_AS.**

Despacha o comando 'Salvar arquivos como'. Implementado como:

`ON_OLECMD(NULL, OLECMDID_SAVEAS, ID_FILE_SAVE_AS)`

**ON_OLECMD_SAVE_COPY_AS.**

Despacha o comando 'Salvar cópia de arquivo' Como. Implementado como:

`ON_OLECMD(NULL, OLECMDID_SAVECOPYAS, ID_FILE_SAVE_COPY_AS)`

**ON_OLECMD_SELECTALL**

Despacha o comando Editar Selecionar Tudo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_SELECTALL, ID_EDIT_SELECT_ALL)`

**ON_OLECMD_UNDO.**

Despacha o comando Editar Desfazer. Implementado como:

`ON_OLECMD(NULL, OLECMDID_UNDO, ID_EDIT_UNDO)`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdocob.h

## <a name="on_registered_message"></a><a name="on_registered_message"></a>On_registered_message

A `RegisterWindowMessage` função Windows é usada para definir uma nova mensagem de janela que é garantida ser única em todo o sistema.

### <a name="syntax"></a>Sintaxe

```cpp
ON_REGISTERED_MESSAGE( nMessageVariable, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*nMessageVariable*<br/>
A variável de id de mensagem de janela registrada.

*Memberfxn*<br/>
O nome da função de manipulador de mensagens para a qual a mensagem é mapeada.

### <a name="remarks"></a>Comentários

Esta macro indica qual função lidará com a mensagem registrada.

Para obter mais informações e exemplos, consulte [Tópicos de manipulação e mapeamento de mensagens](../../mfc/message-handling-and-mapping.md).

### <a name="example"></a>Exemplo

```cpp
static UINT NEAR WM_FIND = RegisterWindowMessage(_T("COMMDLG_FIND"));

BEGIN_MESSAGE_MAP(CMyWnd3, CWnd)
   ON_REGISTERED_MESSAGE(WM_FIND, OnFind)
END_MESSAGE_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

## <a name="on_registered_thread_message"></a><a name="on_registered_thread_message"></a>ON_REGISTERED_THREAD_MESSAGE

Indica qual função lidará com a mensagem registrada pela função Windows RegisterWindowMessage.

### <a name="syntax"></a>Sintaxe

```cpp
ON_REGISTERED_THREAD_MESSAGE(nMessageVariable, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*nMessageVariable*<br/>
A variável de id de mensagem de janela registrada.

*Memberfxn*<br/>
O nome da função CWinThread-message-handler para a qual a mensagem é mapeada.

### <a name="remarks"></a>Comentários

RegisterWindowMessage é usado para definir uma nova mensagem de janela que é garantida como única em todo o sistema. ON_REGISTERED_THREAD_MESSAGE deve ser usado em vez de ON_REGISTERED_MESSAGE quando você tem uma classe CWinThread.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

## <a name="on_thread_message"></a><a name="on_thread_message"></a>ON_THREAD_MESSAGE

Indica qual função lidará com uma mensagem definida pelo usuário.

### <a name="syntax"></a>Sintaxe

```cpp
ON_THREAD_MESSAGE( message, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*Mensagem*<br/>
A ID da mensagem.

*Memberfxn*<br/>
O nome `CWinThread`da função de manipulador de mensagens para a qual a mensagem é mapeada.

### <a name="remarks"></a>Comentários

ON_THREAD_MESSAGE deve ser usado em vez `CWinThread` de ON_MESSAGE quando você tem uma aula. Mensagens definidas pelo usuário são mensagens que não são mensagens padrão do Windows WM_MESSAGE. Deve haver exatamente uma ON_THREAD_MESSAGE de macro no mapa de mensagens para cada mensagem definida pelo usuário que deve ser mapeada para uma função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="on_update_command_ui"></a><a name="on_update_command_ui"></a>On_update_command_ui

Esta macro indica qual função lidará com uma mensagem de comando de atualização de interface do usuário.

### <a name="syntax"></a>Sintaxe

```cpp
ON_UPDATE_COMMAND_UI( messageId, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*Messageid*<br/>
A ID da mensagem.

*Memberfxn*<br/>
O nome da função de manipulador de mensagens para a qual a mensagem é mapeada.

### <a name="remarks"></a>Comentários

Deve haver exatamente uma ON_UPDATE_COMMAND_UI de macro no seu mapa de mensagens para cada comando de atualização de interface de usuário que deve ser mapeado para uma função de manipulador de mensagens.

Para obter mais informações e exemplos, consulte [Tópicos de manipulação e mapeamento de mensagens](../../mfc/message-handling-and-mapping.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxole.h

## <a name="on_command_range"></a><a name="on_command_range"></a>On_command_range

Use esta macro para mapear um intervalo contíguo de IDs de comando para uma única função de manipulador de mensagens.

### <a name="syntax"></a>Sintaxe

```cpp
ON_COMMAND_RANGE( id1, id2, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*id1*<br/>
ID de comando no início de uma gama contígua de IDs de comando.

*id2*<br/>
ID de comando no final de uma gama contígua de IDs de comando.

*Memberfxn*<br/>
O nome da função de manipulador de mensagens para a qual os comandos são mapeados.

### <a name="remarks"></a>Comentários

O intervalo de IDs começa com *id1* e termina com *id2*.

Use ON_COMMAND_RANGE para mapear uma gama de IDs de comando para uma função de membro. Use [ON_COMMAND](#on_command) para mapear um único comando para uma função de membro. Apenas uma entrada de mapa de mensagem pode corresponder a um determinado ID de comando. Ou seja, você não pode mapear um comando para mais de um manipulador. Para obter mais informações sobre o mapeamento de intervalos de mensagens, consulte [Manipuladores para intervalos de mapa de mensagens](../../mfc/handlers-for-message-map-ranges.md).

Não há suporte automático para intervalos de mapa de mensagem, então você deve colocar a macro você mesmo.

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

## <a name="on_update_command_ui_range"></a><a name="on_update_command_ui_range"></a>ON_UPDATE_COMMAND_UI_RANGE

Mapeia uma gama contígua de IDs de comando para uma única função de manipulador de mensagens de atualização.

### <a name="syntax"></a>Sintaxe

```cpp
ON_UPDATE_COMMAND_UI_RANGE( id1, id2, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*id1*<br/>
ID de comando no início de uma gama contígua de IDs de comando.

*id2*<br/>
ID de comando no final de uma gama contígua de IDs de comando.

*Memberfxn*<br/>
O nome da função de manipulador de mensagens de atualização para a qual os comandos são mapeados.

### <a name="remarks"></a>Comentários

Os manipuladores de mensagens de atualização atualizam o estado dos itens do menu e os botões da barra de ferramentas associados ao comando. O intervalo de IDs começa com *id1* e termina com *id2*.

Não há suporte automático para intervalos de mapa de mensagem, então você deve colocar a macro você mesmo.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

## <a name="on_control_range"></a><a name="on_control_range"></a>On_control_range

Use esta macro para mapear uma gama contígua de IDs de controle para uma única função de manipulador de mensagens para uma mensagem de notificação do Windows especificada, como BN_CLICKED.

### <a name="syntax"></a>Sintaxe

```cpp
ON_CONTROL_RANGE( wNotifyCode, id1, id2, memberFxn )
```

### <a name="parameters"></a>Parâmetros

*wNotifyCode*<br/>
O código de notificação ao qual seu manipulador está respondendo.

*id1*<br/>
ID de comando no início de uma gama contígua de IDs de controle.

*id2*<br/>
ID de comando no final de uma gama contígua de IDs de controle.

*Memberfxn*<br/>
O nome da função de manipulador de mensagens para a qual os controles são mapeados.

### <a name="remarks"></a>Comentários

O intervalo de IDs começa com *id1* e termina com *id2*. O manipulador é chamado para a notificação especificada proveniente de qualquer um dos controles mapeados.

Não há suporte automático para intervalos de mapa de mensagem, então você deve colocar a macro você mesmo.

Para obter mais informações sobre a implementação de funções de manipulador para uma série de IDs de controle, consulte [Manipuladores para Intervalos de mapa de mensagens](../../mfc/handlers-for-message-map-ranges.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_.h

## <a name="see-also"></a>Confira também

[ON_COMMAND](message-map-macros-mfc.md#on_command)<br/>
[TN006: mapas de mensagem](../tn006-message-maps.md)<br/>
[Classe COleCmdUI](colecmdui-class.md)<br/>
[COleServerDoc::OnExecOleCmd](coleserverdoc-class.md#onexecolecmd)<br/>
[Registerwindowmessage](/windows/win32/api/winuser/nf-winuser-registerwindowmessagew)<br/>
[Manipuladores definidos do usuário](user-defined-handlers.md)<br/>
[Classe CCmdUI](ccmdui-class.md)
