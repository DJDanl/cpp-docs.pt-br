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
ms.openlocfilehash: b88b745e3b70cf030f77f247ab03cd69d910109f
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420928"
---
# <a name="message-map-macros-mfc"></a>Macros de mapa de mensagem (MFC)

Para dar suporte a mapas de mensagens, o MFC fornece as seguintes macros:

### <a name="message-map-declaration-and-demarcation-macros"></a>Declaração de mapa de mensagem e macros de demarcação

|||
|-|-|
|[DECLARE_MESSAGE_MAP](#declare_message_map)|Declara que um mapa de mensagem será usado em uma classe para mapear mensagens para funções (deve ser usado na declaração de classe).|
|[BEGIN_MESSAGE_MAP](#begin_message_map)|Inicia a definição de um mapa de mensagens (deve ser usado na implementação da classe).|
|[BEGIN_TEMPLATE_MESSAGE_MAP](#begin_template_message_map)|Inicia a definição de um mapa de mensagens em um tipo de classe que contém um único argumento de modelo. |
|[END_MESSAGE_MAP](#end_message_map)|Termina a definição de um mapa de mensagens (deve ser usado na implementação da classe).|

### <a name="message-mapping-macros"></a>Macros de mapeamento de mensagens

|||
|-|-|
|[ON_COMMAND](#on_command)|Indica qual função tratará uma mensagem de comando especificada.|
|[ON_COMMAND_EX](#on_command_ex)|Indica qual função tratará uma mensagem de comando especificada.|
|[ON_CONTROL](#on_control)|Indica qual função tratará uma mensagem de notificação de controle especificada.|
|[ON_MESSAGE](#on_message)|Indica qual função tratará uma mensagem definida pelo usuário.|
|[ON_OLECMD](#on_olecmd)|Indica qual função tratará um comando de menu de um DocObject ou de seu contêiner.|
|[ON_REGISTERED_MESSAGE](#on_registered_message)|Indica qual função tratará uma mensagem registrada definida pelo usuário.|
|[ON_REGISTERED_THREAD_MESSAGE](#on_registered_thread_message)|Indica qual função tratará uma mensagem registrada definida pelo usuário quando você tiver uma classe `CWinThread`.|
|[ON_THREAD_MESSAGE](#on_thread_message)|Indica qual função tratará uma mensagem definida pelo usuário quando você tiver uma classe `CWinThread`.|
|[ON_UPDATE_COMMAND_UI](#on_update_command_ui)|Indica qual função tratará uma mensagem de comando de atualização de interface do usuário especificada.|

### <a name="message-map-range-macros"></a>Macros de intervalo de mapa de mensagens

|||
|-|-|
|[ON_COMMAND_RANGE](#on_command_range)|Indica qual função tratará o intervalo de IDs de comando especificado nos dois primeiros parâmetros para a macro.|
|[ON_UPDATE_COMMAND_UI_RANGE](#on_update_command_ui_range)|Indica qual manipulador de atualização tratará o intervalo de IDs de comando especificado nos dois primeiros parâmetros para a macro.|
|[ON_CONTROL_RANGE](#on_control_range)|Indica qual função tratará as notificações do intervalo de IDs de controle especificado no segundo e terceiro parâmetros para a macro. O primeiro parâmetro é uma mensagem de notificação de controle, como BN_CLICKED.|

Para obter mais informações sobre mapas de mensagens, a declaração de mapa de mensagens e as macros de demarcação e as macros de mapeamento de mensagens, consulte [mapas de mensagens](../../mfc/reference/message-maps-mfc.md) e [Tópicos de mapeamento e manipulação de](../../mfc/message-handling-and-mapping.md)mensagens. Para obter mais informações sobre intervalos de mapa de mensagem, consulte [manipuladores para intervalos de mapa de mensagem](../../mfc/handlers-for-message-map-ranges.md).

## <a name="begin_message_map"></a>BEGIN_MESSAGE_MAP

Inicia a definição do seu mapa de mensagens.

### <a name="syntax"></a>Sintaxe

```
BEGIN_MESSAGE_MAP( theClass, baseClass )
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Especifica o nome da classe cujo mapeamento de mensagem é.

*baseClass*<br/>
Especifica o nome da classe base da *classe*.

### <a name="remarks"></a>Comentários

No arquivo de implementação (. cpp) que define as funções de membro para sua classe, inicie o mapa de mensagens com a macro BEGIN_MESSAGE_MAP e, em seguida, adicione entradas de macro para cada uma das suas funções de manipulador de mensagens e conclua o mapa de mensagens com o END_MESSAGE_MAP Ela.

Para obter mais informações sobre mapas de mensagens, consulte [mapas de mensagens](message-maps-mfc.md)

### <a name="example"></a>Exemplo

```cpp
BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
   ON_WM_CREATE()
END_MESSAGE_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="begin_template_message_map"></a>BEGIN_TEMPLATE_MESSAGE_MAP

Inicia a definição de um mapa de mensagens em um tipo de classe que contém um único argumento de modelo.

### <a name="syntax"></a>Sintaxe

```
BEGIN_TEMPLATE_MESSAGE_MAP( theClass, type_name, baseClass )
```

### <a name="parameters"></a>parâmetros

*Classe*<br/>
Especifica o nome da classe cujo mapeamento de mensagem é.

*type_name*<br/>
O nome do parâmetro de modelo especificado para a classe.

*baseClass*<br/>
Especifica o nome da classe base da *classe*.

### <a name="remarks"></a>Comentários

Essa macro é semelhante à macro de [BEGIN_MESSAGE_MAP](message-map-macros-mfc.md#begin_message_map) ; no entanto, essa macro destina-se a classes que contêm um único argumento de modelo.

Na seção implementação do método da sua classe, inicie o mapa de mensagens com a macro BEGIN_TEMPLATE_MESSAGE_MAP; em seguida, adicione entradas de macro para cada um dos seus métodos de manipulador de mensagens como você faria para um mapa de mensagens padrão. Assim como acontece com a macro BEGIN_MESSAGE_MAP, preencha o mapa de mensagens de modelo com a macro [END_MESSAGE_MAP](message-map-macros-mfc.md#end_message_map) .

Para obter mais informações sobre como implementar mapas de mensagens para classes de modelo, consulte [como criar um mapa de mensagens para uma classe de modelo](../how-to-create-a-message-map-for-a-template-class.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="declare_message_map"></a>DECLARE_MESSAGE_MAP

Declara que a classe define um mapa de mensagens. Cada classe derivada de `CCmdTarget`em seu programa deve fornecer um mapa de mensagem para tratar mensagens.

### <a name="syntax"></a>Sintaxe

```
DECLARE_MESSAGE_MAP( )
```

### <a name="remarks"></a>Comentários

Use a macro DECLARE_MESSAGE_MAP no final da declaração de sua classe. Em seguida, no arquivo. cpp que define as funções de membro para a classe, use a macro BEGIN_MESSAGE_MAP, entradas de macro para cada uma das suas funções de manipulador de mensagens e a macro END_MESSAGE_MAP.

> [!NOTE]
>  Se você declarar qualquer membro após DECLARE_MESSAGE_MAP, deverá especificar um novo tipo de acesso (**público**, **privado**ou **protegido**) para eles.

Para obter mais informações sobre mapas de mensagens e a macro DECLARE_MESSAGE_MAP, consulte [tópicos sobre manipulação de mensagens e mapeamento](../../mfc/message-handling-and-mapping.md).

### <a name="example"></a>Exemplo

```cpp
class CMainFrame : public CMDIFrameWnd
{
   DECLARE_MESSAGE_MAP()

   // Remainder of class declaration omitted.
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="end_message_map"></a>END_MESSAGE_MAP

Finaliza a definição do seu mapa de mensagens.

### <a name="syntax"></a>Sintaxe

```
END_MESSAGE_MAP( )
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre mapas de mensagens e a macro END_MESSAGE_MAP, consulte [tópicos sobre manipulação de mensagens e mapeamento](../../mfc/message-handling-and-mapping.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxwin. h

## <a name="on_command"></a>ON_COMMAND

Essa macro mapeia uma mensagem de comando para uma função de membro.

### <a name="syntax"></a>Sintaxe

```
ON_COMMAND( commandId, memberFxn )
```

### <a name="parameters"></a>parâmetros

*commandId*<br/>
A ID do comando.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para a qual o comando é mapeado.

### <a name="remarks"></a>Comentários

Ele indica qual função tratará uma mensagem de comando de um objeto de interface de usuário de comando, como um item de menu ou botão de barra de ferramentas.

Quando um objeto de destino de comando recebe uma mensagem do Windows WM_COMMAND com a ID especificada, ON_COMMAND chamará a função de membro `memberFxn` para manipular a mensagem.

Use ON_COMMAND para mapear um único comando para uma função de membro. Use [ON_COMMAND_RANGE](#on_command_range) para mapear um intervalo de IDs de comando para uma função membro. Somente uma entrada de mapa de mensagem pode corresponder a uma determinada ID de comando. Ou seja, você não pode mapear um comando para mais de um manipulador. Para obter mais informações e exemplos, consulte [tópicos sobre manipulação de mensagens e mapeamento](../../mfc/message-handling-and-mapping.md).

### <a name="example"></a>Exemplo

```cpp
BEGIN_MESSAGE_MAP(CMFCListViewDoc, CDocument)
   ON_COMMAND(ID_MYCOMMAND, &CMFCListViewDoc::OnMycommand)
END_MESSAGE_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_. h

## <a name="on_command_ex"></a>ON_COMMAND_EX

Função de membro de manipulador de comandos estendida.

### <a name="syntax"></a>Sintaxe

```
ON_COMMAND_EX(commandId, memberFxn);
```

### <a name="parameters"></a>parâmetros

*commandId*<br/>
A ID do comando.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para a qual o comando é mapeado.

### <a name="remarks"></a>Comentários

Uma forma estendida de manipuladores de mensagem de comando está disponível para usos avançados. A macro ON_COMMAND_EX é usada para esses manipuladores de mensagens e fornece um superconjunto da funcionalidade de [ON_COMMAND](message-map-macros-mfc.md#on_command) . As funções de membro do manipulador de comandos estendidas usam um único parâmetro, um UINT contendo a ID de comando e retornam um BOOL. O valor de retorno deve ser verdadeiro para indicar que o comando foi manipulado; caso contrário, o roteamento continuará com outros objetos de destino de comando.

Para obter mais informações, consulte a observação técnica [TN006: mapas de mensagem] TM006-Message-maps.md).

### <a name="requirements"></a>Requisitos

Arquivo de cabeçalho: afxmsg_. h

## <a name="on_control"></a>ON_CONTROL

Indica qual função tratará uma mensagem de notificação de controle personalizado.

### <a name="syntax"></a>Sintaxe

```
ON_CONTROL( wNotifyCode, commandId, memberFxn )
```

### <a name="parameters"></a>parâmetros

*wNotifyCode*<br/>
O código de notificação do controle.

*commandId*<br/>
A ID do comando.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para a qual o comando é mapeado.

### <a name="remarks"></a>Comentários

As mensagens de notificação de controle são aquelas enviadas de um controle para sua janela pai.

Deve haver exatamente uma ON_CONTROL instrução de macro em seu mapa de mensagens para cada mensagem de notificação de controle que deve ser mapeada para uma função de manipulador de mensagens.

Para obter mais informações e exemplos, consulte [tópicos sobre manipulação de mensagens e mapeamento](../../mfc/message-handling-and-mapping.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_. h

## <a name="on_message"></a>ON_MESSAGE

Indica qual função tratará uma mensagem definida pelo usuário.

### <a name="syntax"></a>Sintaxe

```
ON_MESSAGE( message, memberFxn )
```

### <a name="parameters"></a>parâmetros

*message*<br/>
A ID da mensagem.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para a qual a mensagem está mapeada.

O tipo da função deve ser `afx_msg LRESULT (CWnd::*)(WPARAM, LPARAM)`.

### <a name="remarks"></a>Comentários

As mensagens definidas pelo usuário são mensagens que não são mensagens padrão do Windows WM_MESSAGE. Ao selecionar uma ID de mensagem, você deve usar valores dentro do intervalo de WM_USER (0x0400) para 0x7FFF ou WM_APP (0x8000) para 0xBFFF. Para obter mais informações sobre IDs de mensagem, consulte [WM_APP](/windows/win32/winmsg/wm-app).

Deve haver exatamente uma ON_MESSAGE instrução de macro em seu mapa de mensagens para cada mensagem definida pelo usuário que deve ser mapeada para uma função de manipulador de mensagens.

> [!NOTE]
>  Além das mensagens definidas pelo usuário, o ON_MESSAGE manipula mensagens menos comuns do Windows. Para obter mais informações, consulte [mapas de mensagens](../../mfc/tn006-message-maps.md).

Para obter mais informações e exemplos, consulte [Tópicos de manipulação e mapeamento de mensagens](../../mfc/message-handling-and-mapping.md) e [manipuladores definidos pelo usuário](user-defined-handlers.md)

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

**Cabeçalho:** afxmsg_. h

## <a name="on_olecmd"></a>ON_OLECMD

Roteia comandos por meio da interface de expedição de comando `IOleCommandTarget`.

### <a name="syntax"></a>Sintaxe

```
ON_OLECMD( pguid, olecmdid, commandId )
```

### <a name="parameters"></a>parâmetros

*pguid*<br/>
Identificador do grupo de comandos ao qual o comando pertence. Use NULL para o grupo padrão.

*olecmdid*<br/>
O identificador do comando OLE.

*commandId*<br/>
A ID do menu, a ID da barra de ferramentas, a ID do botão ou outra ID do recurso ou objeto que emite o comando.

### <a name="remarks"></a>Comentários

`IOleCommandTarget` permite que um contêiner receba comandos que se originam na interface do usuário de um DocObject e permite que o contêiner envie os mesmos comandos (como novo, abrir, salvar e imprimir no menu arquivo; e copiar, colar, desfazer e assim por diante no menu Editar) para um DocObject.

`IOleCommandTarget` é mais simples do que a `IDispatch`da automação de OLE. `IOleCommandTarget` se baseia inteiramente em um conjunto padrão de comandos que raramente têm argumentos, e nenhuma informação de tipo está envolvida (a segurança de tipo também é reduzida para argumentos de comando). Se você precisar distribuir comandos com argumentos, use [COleServerDoc:: OnExecOleCmd](coleserverdoc-class.md#onexecolecmd).

Os comandos do menu padrão `IOleCommandTarget` foram implementados pelo MFC nas seguintes macros:

**ON_OLECMD_CLEARSELECTION ()**

Despacha o comando Editar limpar. Implementado como:

`ON_OLECMD(NULL, OLECMDID_CLEARSELECTION, ID_EDIT_CLEAR)`

**ON_OLECMD_COPY ()**

Despacha o comando editar cópia. Implementado como:

`ON_OLECMD(NULL, OLECMDID_COPY, ID_EDIT_COPY)`

**ON_OLECMD_CUT ()**

Despacha o comando Editar recortar. Implementado como:

`ON_OLECMD(NULL, OLECMDID_CUT, ID_EDIT_CUT)`

**ON_OLECMD_NEW ()**

Despacha o comando arquivo novo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_NEW, ID_FILE_NEW)`

**ON_OLECMD_OPEN ()**

Despacha o comando File Open. Implementado como:

`ON_OLECMD(NULL, OLECMDID_OPEN, ID_FILE_OPEN)`

**ON_OLECMD_PAGESETUP ()**

Despacha o comando de configuração de página de arquivo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PAGESETUP, ID_FILE_PAGE_SETUP)`

**ON_OLECMD_PASTE ()**

Despacha o comando Editar Colar. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PASTE, ID_EDIT_PASTE)`

**ON_OLECMD_PASTESPECIAL ()**

Despacha o comando Editar Colar especial. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PASTESPECIAL, ID_EDIT_PASTE_SPECIAL)`

**ON_OLECMD_PRINT ()**

Despacha o comando File Print. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PRINT, ID_FILE_PRINT)`

**ON_OLECMD_PRINTPREVIEW ()**

Despacha o comando visualização de impressão de arquivo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_PRINTPREVIEW, ID_FILE_PRINT_PREVIEW)`

**ON_OLECMD_REDO ()**

Despacha o comando Editar refazer. Implementado como:

`ON_OLECMD(NULL, OLECMDID_REDO, ID_EDIT_REDO)`

**ON_OLECMD_SAVE ()**

Despacha o comando File Save. Implementado como:

`ON_OLECMD(NULL, OLECMDID_SAVE, ID_FILE_SAVE)`

**ON_OLECMD_SAVE_AS ()**

Despacha o comando File Save as. Implementado como:

`ON_OLECMD(NULL, OLECMDID_SAVEAS, ID_FILE_SAVE_AS)`

**ON_OLECMD_SAVE_COPY_AS ()**

Despacha o comando salvar cópia de arquivo como. Implementado como:

`ON_OLECMD(NULL, OLECMDID_SAVECOPYAS, ID_FILE_SAVE_COPY_AS)`

**ON_OLECMD_SELECTALL ()**

Despacha o comando Editar selecionar tudo. Implementado como:

`ON_OLECMD(NULL, OLECMDID_SELECTALL, ID_EDIT_SELECT_ALL)`

**ON_OLECMD_UNDO ()**

Distribui o comando de desfazer de edição. Implementado como:

`ON_OLECMD(NULL, OLECMDID_UNDO, ID_EDIT_UNDO)`

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AfxDocOb. h

## <a name="on_registered_message"></a>ON_REGISTERED_MESSAGE

A função `RegisterWindowMessage` do Windows é usada para definir uma nova mensagem de janela que tem a garantia de ser exclusiva em todo o sistema.

### <a name="syntax"></a>Sintaxe

```
ON_REGISTERED_MESSAGE( nMessageVariable, memberFxn )
```

### <a name="parameters"></a>parâmetros

*nMessageVariable*<br/>
A variável de ID de mensagem de janela registrada.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para a qual a mensagem está mapeada.

### <a name="remarks"></a>Comentários

Essa macro indica qual função tratará a mensagem registrada.

Para obter mais informações e exemplos, consulte [tópicos sobre manipulação de mensagens e mapeamento](../../mfc/message-handling-and-mapping.md).

### <a name="example"></a>Exemplo

```cpp
static UINT NEAR WM_FIND = RegisterWindowMessage(_T("COMMDLG_FIND"));

BEGIN_MESSAGE_MAP(CMyWnd3, CWnd)
   ON_REGISTERED_MESSAGE(WM_FIND, OnFind)
END_MESSAGE_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_. h

## <a name="on_registered_thread_message"></a>ON_REGISTERED_THREAD_MESSAGE

Indica qual função tratará a mensagem registrada pela função RegisterWindowMessage do Windows.

### <a name="syntax"></a>Sintaxe

```
ON_REGISTERED_THREAD_MESSAGE(nMessageVariable, memberFxn )
```

### <a name="parameters"></a>parâmetros

*nMessageVariable*<br/>
A variável de ID de mensagem de janela registrada.

*memberFxn*<br/>
O nome da função de manipulador de mensagens CWinThread para a qual a mensagem é mapeada.

### <a name="remarks"></a>Comentários

RegisterWindowMessage é usado para definir uma nova mensagem de janela que tem a garantia de ser exclusiva em todo o sistema. ON_REGISTERED_THREAD_MESSAGE deve ser usado em vez de ON_REGISTERED_MESSAGE quando você tem uma classe CWinThread.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_. h

## <a name="on_thread_message"></a>ON_THREAD_MESSAGE

Indica qual função tratará uma mensagem definida pelo usuário.

### <a name="syntax"></a>Sintaxe

```
ON_THREAD_MESSAGE( message, memberFxn )
```

### <a name="parameters"></a>parâmetros

*message*<br/>
A ID da mensagem.

*memberFxn*<br/>
O nome da função de manipulador de mensagens `CWinThread`para a qual a mensagem é mapeada.

### <a name="remarks"></a>Comentários

ON_THREAD_MESSAGE deve ser usado em vez de ON_MESSAGE quando você tem uma classe `CWinThread`. As mensagens definidas pelo usuário são mensagens que não são mensagens padrão do Windows WM_MESSAGE. Deve haver exatamente uma ON_THREAD_MESSAGE instrução de macro em seu mapa de mensagens para cada mensagem definida pelo usuário que deve ser mapeada para uma função de manipulador de mensagens.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

## <a name="on_update_command_ui"></a>ON_UPDATE_COMMAND_UI

Essa macro indica qual função tratará uma mensagem de comando de atualização da interface do usuário.

### <a name="syntax"></a>Sintaxe

```
ON_UPDATE_COMMAND_UI( messageId, memberFxn )
```

### <a name="parameters"></a>parâmetros

*messageId*<br/>
A ID da mensagem.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para a qual a mensagem está mapeada.

### <a name="remarks"></a>Comentários

Deve haver exatamente uma ON_UPDATE_COMMAND_UI instrução de macro em seu mapa de mensagens para cada comando de atualização de interface do usuário que deve ser mapeado para uma função de manipulador de mensagens.

Para obter mais informações e exemplos, consulte [tópicos sobre manipulação de mensagens e mapeamento](../../mfc/message-handling-and-mapping.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** Afxole. h

## <a name="on_command_range"></a>ON_COMMAND_RANGE

Use esta macro para mapear um intervalo contíguo de IDs de comando para uma única função de manipulador de mensagens.

### <a name="syntax"></a>Sintaxe

```
ON_COMMAND_RANGE( id1, id2, memberFxn )
```

### <a name="parameters"></a>parâmetros

*ID1*<br/>
ID de comando no início de um intervalo contíguo de IDs de comando.

*ID2*<br/>
ID de comando no final de um intervalo contíguo de IDs de comando.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para a qual os comandos são mapeados.

### <a name="remarks"></a>Comentários

O intervalo de IDs começa com *ID1* e termina com *ID2*.

Use ON_COMMAND_RANGE para mapear um intervalo de IDs de comando para uma função membro. Use [ON_COMMAND](#on_command) para mapear um único comando para uma função de membro. Somente uma entrada de mapa de mensagem pode corresponder a uma determinada ID de comando. Ou seja, você não pode mapear um comando para mais de um manipulador. Para obter mais informações sobre como mapear intervalos de mensagens, consulte [manipuladores para intervalos de mapa de mensagens](../../mfc/handlers-for-message-map-ranges.md).

Não há suporte automático para os intervalos de mapa de mensagens, portanto, você deve colocá-la por conta própria.

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

**Cabeçalho:** afxmsg_. h

## <a name="on_update_command_ui_range"></a>ON_UPDATE_COMMAND_UI_RANGE

Mapeia um intervalo contíguo de IDs de comando para uma única função de manipulador de mensagens de atualização.

### <a name="syntax"></a>Sintaxe

```
ON_UPDATE_COMMAND_UI_RANGE( id1, id2, memberFxn )
```

### <a name="parameters"></a>parâmetros

*ID1*<br/>
ID de comando no início de um intervalo contíguo de IDs de comando.

*ID2*<br/>
ID de comando no final de um intervalo contíguo de IDs de comando.

*memberFxn*<br/>
O nome da função de manipulador de mensagens de atualização para a qual os comandos são mapeados.

### <a name="remarks"></a>Comentários

Atualizar manipuladores de mensagens atualize o estado dos itens de menu e dos botões da barra de ferramentas associados ao comando. O intervalo de IDs começa com *ID1* e termina com *ID2*.

Não há suporte automático para os intervalos de mapa de mensagens, portanto, você deve colocá-la por conta própria.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_. h

## <a name="on_control_range"></a>ON_CONTROL_RANGE

Use essa macro para mapear um intervalo contíguo de IDs de controle para uma única função de manipulador de mensagens para uma mensagem de notificação do Windows especificada, como BN_CLICKED.

### <a name="syntax"></a>Sintaxe

```
ON_CONTROL_RANGE( wNotifyCode, id1, id2, memberFxn )
```

### <a name="parameters"></a>parâmetros

*wNotifyCode*<br/>
O código de notificação ao qual seu manipulador está respondendo.

*ID1*<br/>
ID de comando no início de um intervalo contíguo de IDs de controle.

*ID2*<br/>
ID de comando no final de um intervalo contíguo de IDs de controle.

*memberFxn*<br/>
O nome da função de manipulador de mensagens para a qual os controles são mapeados.

### <a name="remarks"></a>Comentários

O intervalo de IDs começa com *ID1* e termina com *ID2*. O manipulador é chamado para a notificação especificada proveniente de qualquer um dos controles mapeados.

Não há suporte automático para os intervalos de mapa de mensagens, portanto, você deve colocá-la por conta própria.

Para obter mais informações sobre como implementar funções de manipulador para um intervalo de IDs de controle, consulte [manipuladores para intervalos de mapa de mensagem](../../mfc/handlers-for-message-map-ranges.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxmsg_. h

## <a name="see-also"></a>Confira também

[ON_COMMAND](message-map-macros-mfc.md#on_command)<br/>
[TN006: mapas de mensagem](../tn006-message-maps.md)<br/>
[Classe COleCmdUI](colecmdui-class.md)<br/>
[COleServerDoc::OnExecOleCmd](coleserverdoc-class.md#onexecolecmd)<br/>
[RegisterWindowMessage](/windows/win32/api/winuser/nf-winuser-registerwindowmessagew)<br/>
[Manipuladores definidos pelo usuário](user-defined-handlers.md)<br/>
[Classe CCmdUI](ccmdui-class.md)
