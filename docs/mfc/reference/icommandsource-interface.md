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
ms.openlocfilehash: 6a03c46c972f7746f39a3c5c65ca9b5509983d59
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81356985"
---
# <a name="icommandsource-interface"></a>Interface ICommandSource

Gerencia comandos enviados de um objeto de origem de comando para um controle de usuário.

## <a name="syntax"></a>Sintaxe

```cpp
interface class ICommandSource
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[iCommandSource::AddCommandHandler](#addcommandhandler)|Adiciona um manipulador de comando a um objeto de origem de comando.|
|[iCommandSource::AddCommand'SHandler](#addcommandrangehandler)|Adiciona um grupo de manipuladores de comando a um objeto de origem de comando.|
|[iCommandSource::AddCommandRangeUIHandler](#addcommandrangeuihandler)|Adiciona um grupo de manipuladores de mensagens de comando da interface do usuário a um objeto de origem de comando.|
|[iCommandSource::AddCommandUIHandler](#addcommandrangeuihandler)|Adiciona um manipulador de mensagens de comando da interface do usuário a um objeto de origem de comando.|
|[iCommandSource::PostCommand](#postcommand)|Posta uma mensagem sem esperar que ela seja processada.|
|[ICommandSource::RemoveCommandHandler](#removecommandhandler)|Remove um manipulador de comando de um objeto de origem de comando.|
|[iCommandSource::RemoveCommand'SHandler](#removecommandrangehandler)|Remove um grupo de manipuladores de comando de um objeto de origem de comando.|
|[iCommandSource::RemoveCommandRangeUIHandler](#removecommandrangeuihandler)|Remove um grupo de manipuladores de mensagens de comando da interface do usuário de um objeto de origem de comando.|
|[iCommandSource::RemoveCommandUIHandler](#removecommandrangeuihandler)|Remove um manipulador de mensagens de comando da interface do usuário de um objeto de origem de comando.|
|[iCommandSource::SendCommand](#sendcommand)|Envia uma mensagem e espera que ela seja processada antes de retornar.|

### <a name="remarks"></a>Comentários

Quando você hospeda um controle de usuário em uma exibição de MFC, [o CWinFormsView Class](../../mfc/reference/cwinformsview-class.md) roteia comandos e atualiza mensagens de ida de comando para o controle do usuário para permitir que ele manuseie comandos MFC (por exemplo, itens de menu de quadros e botões de barra de ferramentas). Ao implementar [o ICommandTarget Interface,](../../mfc/reference/icommandtarget-interface.md)você dá `ICommandSource` ao controle do usuário uma referência ao objeto.

[Veja como: Adicionar roteamento de comando ao controle de formulários do Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para um exemplo de como usar `ICommandTarget`.

Para obter mais informações sobre o uso do Windows Forms, consulte [Usando um controle de usuário do formulário do Windows no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h (definido em montagem atlmfc\lib\mfcmifc80.dll)

## <a name="icommandsourceaddcommandhandler"></a><a name="addcommandhandler"></a>iCommandSource::AddCommandHandler

Adiciona um manipulador de comando a um objeto de origem de comando.

```cpp
void AddCommandHandler(
    unsigned int cmdID,
    CommandHandler^ cmdHandler);
```

### <a name="parameters"></a>Parâmetros

*Cmdid*<br/>
O id de comando.
*cmdHandler*<br/>
Uma alça para o método do manipulador de comando.

### <a name="remarks"></a>Comentários

Este método adiciona o manipulador de comando cmdHandler ao objeto de origem de comando e mapeia o manipulador para cmdID.
[Veja Como: Adicionar roteamento de comando ao Controle de Formulários do Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para um exemplo de como usar o AddCommandHandler.

## <a name="icommandsourceaddcommandrangehandler"></a><a name="addcommandrangehandler"></a>iCommandSource::AddCommand'SHandler

Adiciona um grupo de manipuladores de comando a um objeto de origem de comando.

```cpp
void AddCommandRangeHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax,
    CommandHandler^ cmdHandler);
```

### <a name="parameters"></a>Parâmetros

*cmdIDMin*<br/>
O índice inicial do intervalo de id de comando.
*Cmdidmax*<br/>
O índice final do intervalo de id de comando.
*cmdHandler*<br/>
Uma alça para o método de manipulador de mensagens para o qual os comandos são mapeados.

### <a name="remarks"></a>Comentários

Este método mapeia um intervalo contíguo de IDs de comando para um único manipulador de mensagens e adiciona-o ao objeto de origem de comando. Isto é usado para manusear um grupo de botões relacionados com um método.

## <a name="icommandsourceaddcommandrangeuihandler"></a><a name="addcommandrangeuihandler"></a>iCommandSource::AddCommandRangeUIHandler

Adiciona um grupo de manipuladores de mensagens de comando da interface do usuário a um objeto de origem de comando.

```cpp
void AddCommandRangeUIHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax,
    CommandUIHandler^ cmdUIHandler);
```

### <a name="parameters"></a>Parâmetros

*cmdIDMin*<br/>
O índice inicial do intervalo de id de comando.
*Cmdidmax*<br/>
O índice final do intervalo de id de comando.
*cmdHandler*<br/>
Uma alça para o método de manipulador de mensagens para o qual os comandos são mapeados.

### <a name="remarks"></a>Comentários

Este método mapeia uma gama contígua de IDs de comando para um único manipulador de mensagens de comando da interface do usuário e adiciona-o ao objeto de origem de comando. Isto é usado para manusear um grupo de botões relacionados com um método.

## <a name="icommandsourceaddcommanduihandler"></a><a name="addcommanduihandler"></a>iCommandSource::AddCommandUIHandler

Adiciona um manipulador de mensagens de comando da interface do usuário a um objeto de origem de comando.

```cpp
void AddCommandUIHandler(
    unsigned int cmdID,
    CommandUIHandler^ cmdUIHandler);
```

### <a name="parameters"></a>Parâmetros

*Cmdid*<br/>
O id de comando.
*cmdUIHandler*<br/>
Uma alça para o método de manipulador de mensagens de comando da interface do usuário.

### <a name="remarks"></a>Comentários

Este método adiciona o manipulador de mensagens de comando da interface do usuário cmdHandler ao objeto de origem de comando e mapeia o manipulador para cmdID.

## <a name="icommandsourcepostcommand"></a><a name="postcommand"></a>iCommandSource::PostCommand

Posta uma mensagem sem esperar que ela seja processada.

```cpp
void PostCommand(unsigned int command);
```

### <a name="parameters"></a>Parâmetros

*Comando*<br/>
O id de comando da mensagem a ser postada.

### <a name="remarks"></a>Comentários

Este método posta assíncronamente a mensagem mapeada para o ID especificado pelo comando. Ele chama CWnd::PostMessage para colocar a mensagem na fila de mensagens da janela e, em seguida, retorna sem esperar que a janela correspondente processe a mensagem.

## <a name="icommandsourceremovecommandhandler"></a><a name="removecommandhandler"></a>ICommandSource::RemoveCommandHandler

Remove um manipulador de comando de um objeto de origem de comando.

```cpp
void RemoveCommandHandler(unsigned int cmdID);
```

### <a name="parameters"></a>Parâmetros

*Cmdid*<br/>
O id de comando.

### <a name="remarks"></a>Comentários

Este método remove o manipulador de comando mapeado para cmdID do objeto de origem de comando.

## <a name="icommandsourceremovecommandrangehandler"></a><a name="removecommandrangehandler"></a>iCommandSource::RemoveCommand'SHandler

Remove um grupo de manipuladores de comando de um objeto de origem de comando.

```cpp
void RemoveCommandRangeUIHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax);
```

### <a name="parameters"></a>Parâmetros

*cmdIDMin*<br/>
O índice inicial do intervalo de id de comando.
*Cmdidmax*<br/>
O índice final do intervalo de id de comando.

### <a name="remarks"></a>Comentários

Este método remove um grupo de manipuladores de mensagens, mapeados para os IDs de comando especificados por cmdIDMin e cmdIDMax, do objeto de origem de comando.

## <a name="icommandsourceremovecommandrangeuihandler"></a><a name="removecommandrangeuihandler"></a>iCommandSource::RemoveCommandRangeUIHandler

Remove um grupo de manipuladores de mensagens de comando da interface do usuário de um objeto de origem de comando.

```cpp
void RemoveCommandRangeUIHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax);
```

### <a name="parameters"></a>Parâmetros

*cmdIDMin*<br/>
O índice inicial do intervalo de id de comando.
*Cmdidmax*<br/>
O índice final do intervalo de id de comando.

### <a name="remarks"></a>Comentários

Este método remove um grupo de manipuladores de mensagens de comando da interface do usuário, mapeados para os IDs de comando especificados por cmdIDMin e cmdIDMax, do objeto de origem de comando.

## <a name="icommandsourceremovecommanduihandler"></a><a name="removecommanduihandler"></a>iCommandSource::RemoveCommandUIHandler

Remove um manipulador de mensagens de comando da interface do usuário de um objeto de origem de comando.

```cpp
void RemoveCommandUIHandler(unsigned int cmdID);
```

### <a name="parameters"></a>Parâmetros

*Cmdid*<br/>
O id de comando.

### <a name="remarks"></a>Comentários

Este método remove o manipulador de mensagens de comando da interface do usuário mapeado para cmdID do objeto de origem de comando.

## <a name="icommandsourcesendcommand"></a><a name="sendcommand"></a>iCommandSource::SendCommand

Envia uma mensagem e espera que ela seja processada antes de retornar.

```cpp
void SendCommand(unsigned int command);
```

### <a name="parameters"></a>Parâmetros

*Comando*<br/>
O id de comando da mensagem a ser enviada.

### <a name="remarks"></a>Comentários

Este método envia sincronicamente a mensagem mapeada para o ID especificado pelo comando. Ele chama CWnd::SendMessage para colocar a mensagem na fila de mensagens da janela e espera até que o procedimento da janela tenha processado a mensagem antes de retornar.

## <a name="see-also"></a>Confira também

[Como adicionar roteamento de comando ao controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)<br/>
[Interface ICommandTarget](../../mfc/reference/icommandtarget-interface.md)
