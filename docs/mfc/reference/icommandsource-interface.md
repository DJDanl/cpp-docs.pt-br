---
title: Interface ICommandSource
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
ms.openlocfilehash: eed7abbbb40c532ad596f683b6ed2c98a0cadf9b
ms.sourcegitcommit: 309dc532f13242854b47759cef846de59bb807f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/28/2019
ms.locfileid: "58565604"
---
# <a name="icommandsource-interface"></a>Interface ICommandSource

Gerencia os comandos enviados de um objeto de origem de comando para um controle de usuário.

## <a name="syntax"></a>Sintaxe

```
interface class ICommandSource
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[ICommandSource::AddCommandHandler](#addcommandhandler)|Adiciona um manipulador de comandos para um objeto de fonte de comando.|
|[ICommandSource::AddCommandRangeHandler](#addcommandrangehandler)|Adiciona um grupo de manipuladores de comandos para um objeto de fonte de comando.|
|[ICommandSource::AddCommandRangeUIHandler](#addcommandrangeuihandler)|Adiciona um grupo de manipuladores de mensagens de comando de interface do usuário para um objeto de fonte de comando.|
|[ICommandSource::AddCommandUIHandler](#addcommandrangeuihandler)|Adiciona um manipulador de mensagens de comando de interface do usuário para um objeto de fonte de comando.|
|[ICommandSource::PostCommand](#postcommand)|Posta uma mensagem sem aguardar que ele seja processado.|
|[ICommandSource::RemoveCommandHandler](#removecommandhandler)|Remove um manipulador de comandos de um objeto de origem do comando.|
|[ICommandSource::RemoveCommandRangeHandler](#removecommandrangehandler)|Remove um grupo de manipuladores de comandos de um objeto de origem do comando.|
|[ICommandSource::RemoveCommandRangeUIHandler](#removecommandrangeuihandler)|Remove um grupo de manipuladores de mensagens de comando de interface do usuário de um objeto de origem do comando.|
|[ICommandSource::RemoveCommandUIHandler](#removecommandrangeuihandler)|Remove um manipulador de mensagens de comando de interface do usuário de um objeto de origem do comando.|
|[ICommandSource::SendCommand](#sendcommand)|Envia uma mensagem e aguarda até que ele seja processado antes de retornar.|

### <a name="remarks"></a>Comentários

Ao hospedar um controle de usuário em uma exibição do MFC [classe CWinFormsView](../../mfc/reference/cwinformsview-class.md) comandos de rotas e atualização de comando mensagens de interface do usuário para o controle de usuário para permitir a manipulação de comandos MFC (por exemplo, itens de menu do quadro e botões da barra de ferramentas). Implementando [ICommandTarget Interface](../../mfc/reference/icommandtarget-interface.md), você fornecer uma referência para o controle de usuário a `ICommandSource` objeto.

Confira [Como Adicione o roteamento de comando para o controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `ICommandTarget`.

Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)

## <a name="addcommandhandler"></a>  ICommandSource::AddCommandHandler

Adiciona um manipulador de comandos para um objeto de fonte de comando.
```
void AddCommandHandler(
    unsigned int cmdID,
    CommandHandler^ cmdHandler);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID de comando.
*cmdHandler*<br/>
Um identificador para o método de manipulador de comando.

### <a name="remarks"></a>Comentários

Esse método adiciona o cmdHandler do manipulador de comando para o objeto de fonte de comando e mapeia o manipulador para cmdID.
Confira [Como Adicione o roteamento de comando para o controle de formulários do Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar AddCommandHandler.

## <a name="addcommandrangehandler"></a> ICommandSource::AddCommandRangeHandler

Adiciona um grupo de manipuladores de comandos para um objeto de fonte de comando.
```
void AddCommandRangeHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax,
    CommandHandler^ cmdHandler);
```

### <a name="parameters"></a>Parâmetros

*cmdIDMin*<br/>
O índice de início do intervalo de IDs de comando.
*cmdIDMax*<br/>
O índice final do intervalo de IDs de comando.
*cmdHandler*<br/>
Um identificador para o método do manipulador de mensagem para o qual os comandos são mapeados.
### <a name="remarks"></a>Comentários

Esse método mapeia um intervalo contíguo de IDs de comando para um manipulador de mensagens única e o adiciona ao objeto de fonte de comando. Isso é usado para lidar com um grupo de botões com um método.

## <a name="addcommandrangeuihandler"></a> ICommandSource::AddCommandRangeUIHandler

Adiciona um grupo de manipuladores de mensagens de comando de interface do usuário para um objeto de fonte de comando.
```
void AddCommandRangeUIHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax,
    CommandUIHandler^ cmdUIHandler);
```

### <a name="parameters"></a>Parâmetros

*cmdIDMin*<br/>
O índice de início do intervalo de IDs de comando.
*cmdIDMax*<br/>
O índice final do intervalo de IDs de comando.
*cmdHandler*<br/>
Um identificador para o método do manipulador de mensagem para o qual os comandos são mapeados.

### <a name="remarks"></a>Comentários

Esse método mapeia um intervalo contíguo de IDs de comando para um manipulador de mensagens de comando de interface de usuário único e o adiciona ao objeto de fonte de comando. Isso é usado para lidar com um grupo de botões com um método.

## <a name="addcommanduihandler"></a> ICommandSource::AddCommandUIHandler

Adiciona um manipulador de mensagens de comando de interface do usuário para um objeto de fonte de comando.
```
void AddCommandUIHandler(
    unsigned int cmdID,
    CommandUIHandler^ cmdUIHandler);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID de comando.
*cmdUIHandler*<br/>
Um identificador para o método do manipulador de mensagem do comando de interface de usuário.

### <a name="remarks"></a>Comentários

Esse método adiciona cmdHandler de manipulador de mensagem de comando para interface do usuário para o objeto de fonte de comando e mapeia o manipulador para cmdID.

## <a name="postcommand"></a> ICommandSource::PostCommand

Posta uma mensagem sem aguardar que ele seja processado.
```
void PostCommand(unsigned int command);
```

### <a name="parameters"></a>Parâmetros

*command*<br/>
A ID de comando da mensagem a ser postada.
### <a name="remarks"></a>Comentários

Esse método assincronamente posta a mensagem mapeada para a ID especificada pelo comando. Ele chama CWnd::PostMessage para colocar a mensagem na fila de mensagens da janela e, em seguida, retorna sem aguardar a janela correspondente processar a mensagem.

## <a name="removecommandhandler"></a> ICommandSource::RemoveCommandHandler

Remove um manipulador de comandos de um objeto de origem do comando.
```
void RemoveCommandHandler(unsigned int cmdID);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID de comando.
### <a name="remarks"></a>Comentários

Esse método Remove o manipulador de comandos mapeado para cmdID do objeto de origem de comando.

## <a name="removecommandrangehandler"></a> ICommandSource::RemoveCommandRangeHandler

Remove um grupo de manipuladores de comandos de um objeto de origem do comando.
```
void RemoveCommandRangeUIHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax);
```

### <a name="parameters"></a>Parâmetros

*cmdIDMin*<br/>
O índice de início do intervalo de IDs de comando.
*cmdIDMax*<br/>
O índice final do intervalo de IDs de comando.
### <a name="remarks"></a>Comentários

Esse método Remove um grupo de manipuladores de mensagens, mapeados para as IDs de comando especificadas por cmdIDMin e cmdIDMax do objeto de origem de comando.

## <a name="removecommandrangeuihandler"></a> ICommandSource::RemoveCommandRangeUIHandler

Remove um grupo de manipuladores de mensagens de comando de interface do usuário de um objeto de origem do comando.
```
void RemoveCommandRangeUIHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax);
```

### <a name="parameters"></a>Parâmetros

*cmdIDMin*<br/>
O índice de início do intervalo de IDs de comando.
*cmdIDMax*<br/>
O índice final do intervalo de IDs de comando.
### <a name="remarks"></a>Comentários

Esse método Remove um grupo de usuário interface comando de manipuladores de mensagens, mapeados para as IDs de comando especificadas por cmdIDMin e cmdIDMax do objeto de origem de comando.

## <a name="removecommanduihandler"></a> ICommandSource::RemoveCommandUIHandler

Remove um manipulador de mensagens de comando de interface do usuário de um objeto de origem do comando.
```
void RemoveCommandUIHandler(unsigned int cmdID);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID de comando.
### <a name="remarks"></a>Comentários

Esse método Remove o manipulador de mensagens de comando do usuário interface mapeado para cmdID do objeto de origem de comando.

## <a name="sendcommand"></a> ICommandSource::SendCommand

Envia uma mensagem e aguarda até que ele seja processado antes de retornar.
```
void SendCommand(unsigned int command);
```

### <a name="parameters"></a>Parâmetros

*command*<br/>
A ID de comando da mensagem a ser enviada.
### <a name="remarks"></a>Comentários

Esse método envia a mensagem mapeada para a ID especificada pelo comando de forma síncrona. Ele chama CWnd::SendMessage para colocar a mensagem na fila de mensagens da janela e aguarda até que esse procedimento de janela processou a mensagem antes de retornar.
## <a name="see-also"></a>Consulte também

[Como: adicionar roteamento de comando ao controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)<br/>
[Interface ICommandTarget](../../mfc/reference/icommandtarget-interface.md)
