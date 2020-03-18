---
title: Interface ICommand
ms.date: 03/27/2019
f1_keywords:
- ICommandSource
- AFXWINFORMS/ICommandSource
- AFXWINFORMS/ICommandSource::AddCommandHandler
- AFXWINFORMS/ICommandSource::AddCommandRangeHandler
- AFXWINFORMS/ICommandSource::AddCommandRangeUIHandler
- AFXWINFORMS/ICommandSource::AddCommandUIHandler
- AFXWINFORMS/ICommandSource::PostCommand
- AFXWINFORMS/ICommandSource::RemoveCommandHandler
- AFXWINFORMS/ICommandSource::RemoveCommandRangeHandler
- AFXWINFORMS/ICommandSource::RemoveCommandRangeUIHandler
- AFXWINFORMS/ICommandSource::RemoveCommandUIHandler
- AFXWINFORMS/ICommandSource::SendCommand
helpviewer_keywords:
- ICommandSource interface [MFC]
ms.assetid: a4b1f698-c09f-4ba8-9b13-0e74a0a4967e
ms.openlocfilehash: a57ca6f36546a17b9a35ebea875ff01b43de1332
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79445705"
---
# <a name="icommandsource-interface"></a>Interface ICommand

Gerencia comandos enviados de um objeto de origem de comando para um controle de usuário.

## <a name="syntax"></a>Sintaxe

```
interface class ICommandSource
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|{1&gt;Nome&lt;1}|Descrição|
|----------|-----------------|
|[ICommand:: AddCommandHandler](#addcommandhandler)|Adiciona um manipulador de comando a um objeto de origem de comando.|
|[ICommand:: AddCommandRangeHandler](#addcommandrangehandler)|Adiciona um grupo de manipuladores de comando a um objeto de origem de comando.|
|[ICommand:: AddCommandRangeUIHandler](#addcommandrangeuihandler)|Adiciona um grupo de manipuladores de mensagens de comando da interface do usuário a um objeto de origem de comando.|
|[ICommand:: AddCommandUIHandler](#addcommandrangeuihandler)|Adiciona um manipulador de mensagens de comando da interface do usuário a um objeto de origem de comando.|
|[ICommand::P ostCommand](#postcommand)|Posta uma mensagem sem esperar que ela seja processada.|
|[ICommand:: RemoveCommandHandler](#removecommandhandler)|Remove um manipulador de comandos de um objeto de origem de comando.|
|[ICommand:: RemoveCommandRangeHandler](#removecommandrangehandler)|Remove um grupo de manipuladores de comando de um objeto de origem de comando.|
|[ICommand:: RemoveCommandRangeUIHandler](#removecommandrangeuihandler)|Remove um grupo de manipuladores de mensagens de comando da interface do usuário de um objeto de origem de comando.|
|[ICommand:: RemoveCommandUIHandler](#removecommandrangeuihandler)|Remove um manipulador de mensagens de comando da interface do usuário de um objeto de origem de comando.|
|[ICommand:: SendCommand](#sendcommand)|Envia uma mensagem e aguarda que ela seja processada antes de retornar.|

### <a name="remarks"></a>Comentários

Quando você hospeda um controle de usuário em uma exibição do MFC, a [classe CWinFormsView](../../mfc/reference/cwinformsview-class.md) roteia comandos e atualiza mensagens de interface do usuário de comando para o controle de usuários para permitir que ele manipule comandos do MFC (por exemplo, itens de menu de quadro e botões da barra de ferramentas). Ao implementar a [interface ICommandTarget](../../mfc/reference/icommandtarget-interface.md), você dá ao usuário controle uma referência ao objeto `ICommandSource`.

Consulte [como: Adicionar roteamento de comando ao controle de Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `ICommandTarget`.

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Header:** afxwinforms. h (definido no assembly atlmfc\lib\mfcmifc80.dll)

## <a name="addcommandhandler"></a>ICommand:: AddCommandHandler

Adiciona um manipulador de comando a um objeto de origem de comando.

```
void AddCommandHandler(
    unsigned int cmdID,
    CommandHandler^ cmdHandler);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID do comando.
*cmdHandler*<br/>
Um identificador para o método de manipulador de comando.

### <a name="remarks"></a>Comentários

Esse método adiciona o manipulador de comandos cmdHandler ao objeto de origem de comando e mapeia o manipulador para cmdID.
Consulte [como: Adicionar roteamento de comando ao controle de Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar o AddCommandHandler.

## <a name="addcommandrangehandler"></a>ICommand:: AddCommandRangeHandler

Adiciona um grupo de manipuladores de comando a um objeto de origem de comando.

```
void AddCommandRangeHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax,
    CommandHandler^ cmdHandler);
```

### <a name="parameters"></a>Parâmetros

*cmdIDMin*<br/>
O índice inicial do intervalo de ID de comando.
*cmdIDMax*<br/>
O índice final do intervalo de ID de comando.
*cmdHandler*<br/>
Um identificador para o método de manipulador de mensagens para o qual os comandos são mapeados.
### <a name="remarks"></a>Comentários

Esse método mapeia um intervalo contíguo de IDs de comando para um único manipulador de mensagens e o adiciona ao objeto de origem de comando. Isso é usado para lidar com um grupo de botões relacionados com um método.

## <a name="addcommandrangeuihandler"></a>ICommand:: AddCommandRangeUIHandler

Adiciona um grupo de manipuladores de mensagens de comando da interface do usuário a um objeto de origem de comando.

```
void AddCommandRangeUIHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax,
    CommandUIHandler^ cmdUIHandler);
```

### <a name="parameters"></a>Parâmetros

*cmdIDMin*<br/>
O índice inicial do intervalo de ID de comando.
*cmdIDMax*<br/>
O índice final do intervalo de ID de comando.
*cmdHandler*<br/>
Um identificador para o método de manipulador de mensagens para o qual os comandos são mapeados.

### <a name="remarks"></a>Comentários

Esse método mapeia um intervalo contíguo de IDs de comando para um único manipulador de mensagens de comando de interface de usuário e a adiciona ao objeto de origem de comando. Isso é usado para lidar com um grupo de botões relacionados com um método.

## <a name="addcommanduihandler"></a>ICommand:: AddCommandUIHandler

Adiciona um manipulador de mensagens de comando da interface do usuário a um objeto de origem de comando.

```
void AddCommandUIHandler(
    unsigned int cmdID,
    CommandUIHandler^ cmdUIHandler);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID do comando.
*cmdUIHandler*<br/>
Um identificador para o método do manipulador de mensagens de comando da interface do usuário.

### <a name="remarks"></a>Comentários

Esse método adiciona o manipulador de mensagens de comando da interface do usuário cmdHandler ao objeto de origem de comando e mapeia o manipulador para cmdID.

## <a name="postcommand"></a>ICommand::P ostCommand

Posta uma mensagem sem esperar que ela seja processada.

```
void PostCommand(unsigned int command);
```

### <a name="parameters"></a>Parâmetros

*command*<br/>
A ID de comando da mensagem a ser postada.
### <a name="remarks"></a>Comentários

Esse método posta de forma assíncrona a mensagem mapeada para a ID especificada pelo comando. Ele chama CWnd::P ostMessage para colocar a mensagem na fila de mensagens da janela e, em seguida, retorna sem esperar que a janela correspondente processe a mensagem.

## <a name="removecommandhandler"></a>ICommand:: RemoveCommandHandler

Remove um manipulador de comandos de um objeto de origem de comando.

```
void RemoveCommandHandler(unsigned int cmdID);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID do comando.
### <a name="remarks"></a>Comentários

Esse método remove o manipulador de comandos mapeado para cmdID do objeto de origem de comando.

## <a name="removecommandrangehandler"></a>ICommand:: RemoveCommandRangeHandler

Remove um grupo de manipuladores de comando de um objeto de origem de comando.

```
void RemoveCommandRangeUIHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax);
```

### <a name="parameters"></a>Parâmetros

*cmdIDMin*<br/>
O índice inicial do intervalo de ID de comando.
*cmdIDMax*<br/>
O índice final do intervalo de ID de comando.
### <a name="remarks"></a>Comentários

Esse método Remove um grupo de manipuladores de mensagens, mapeados para as IDs de comando especificadas por cmdIDMin e cmdIDMax, do objeto de origem de comando.

## <a name="removecommandrangeuihandler"></a>ICommand:: RemoveCommandRangeUIHandler

Remove um grupo de manipuladores de mensagens de comando da interface do usuário de um objeto de origem de comando.

```
void RemoveCommandRangeUIHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax);
```

### <a name="parameters"></a>Parâmetros

*cmdIDMin*<br/>
O índice inicial do intervalo de ID de comando.
*cmdIDMax*<br/>
O índice final do intervalo de ID de comando.
### <a name="remarks"></a>Comentários

Esse método Remove um grupo de manipuladores de mensagens de comando da interface do usuário, mapeados para as IDs de comando especificadas por cmdIDMin e cmdIDMax, do objeto de origem de comando.

## <a name="removecommanduihandler"></a>ICommand:: RemoveCommandUIHandler

Remove um manipulador de mensagens de comando da interface do usuário de um objeto de origem de comando.

```
void RemoveCommandUIHandler(unsigned int cmdID);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID do comando.
### <a name="remarks"></a>Comentários

Esse método remove o manipulador de mensagens de comando da interface do usuário mapeado para cmdID do objeto de origem de comando.

## <a name="sendcommand"></a>ICommand:: SendCommand

Envia uma mensagem e aguarda que ela seja processada antes de retornar.

```
void SendCommand(unsigned int command);
```

### <a name="parameters"></a>Parâmetros

*command*<br/>
A ID de comando da mensagem a ser enviada.
### <a name="remarks"></a>Comentários

Esse método envia de forma síncrona a mensagem mapeada para a ID especificada pelo comando. Ele chama CWnd:: SendMessage para colocar a mensagem na fila de mensagens da janela e aguarda até que o procedimento da janela tenha processado a mensagem antes de retornar.
## <a name="see-also"></a>Consulte também

[Como adicionar roteamento de comando ao controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)<br/>
[Interface ICommandTarget](../../mfc/reference/icommandtarget-interface.md)
