---
title: Interface ICommandSource | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- ICommandSource interface [MFC]
ms.assetid: a4b1f698-c09f-4ba8-9b13-0e74a0a4967e
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dc8ad34ccce059caca8e86a014622e29c14022ed
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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
|[ICommandSource::AddCommandHandler](#addcommandhandler)|Adiciona um manipulador de comandos a um objeto de origem.|  
|[ICommandSource::AddCommandRangeHandler](#addcommandrangehandler)|Adiciona um grupo de manipuladores de comandos a um objeto de origem.|  
|[ICommandSource::AddCommandRangeUIHandler](#addcommandrangeuihandler)|Adiciona um grupo de manipuladores de mensagens de comando de interface de usuário a um objeto de origem.|  
|[ICommandSource::AddCommandUIHandler](#addcommandrangeuihandler)|Adiciona um manipulador de mensagens de comando de interface do usuário a um objeto de origem.|  
|[ICommandSource::PostCommand](#postcommand)|Publica uma mensagem sem esperar que ele seja processado.|  
|[ICommandSource::RemoveCommandHandler](#removecommandhandler)|Remove um manipulador de comandos de um objeto de fonte de comando.|  
|[ICommandSource::RemoveCommandRangeHandler](#removecommandrangehandler)|Remove um grupo de manipuladores de comandos de um objeto de origem de comando.|  
|[ICommandSource::RemoveCommandRangeUIHandler](#removecommandrangeuihandler)|Remove um grupo de manipuladores de mensagens de comando de interface de usuário de um objeto de origem de comando.|  
|[ICommandSource::RemoveCommandUIHandler](#removecommandrangeuihandler)|Remove um manipulador de mensagens de comando de interface de usuário de um objeto de fonte de comando.|  
|[ICommandSource::SendCommand](#sendcommand)|Envia uma mensagem e aguarda até que ele seja processado antes de retornar.|  
  
### <a name="remarks"></a>Comentários  
 Quando você hospeda um controle de usuário em uma exibição MFC, [CWinFormsView classe](../../mfc/reference/cwinformsview-class.md) comandos de rotas e atualização de comando mensagens de interface do usuário para o controle de usuário para permitir que ele trate comandos MFC (por exemplo, itens de menu do quadro e botões de barra de ferramentas). Implementando [ICommandTarget Interface](../../mfc/reference/icommandtarget-interface.md), você concede o controle de usuário, uma referência para o `ICommandSource` objeto.  
  
 Consulte [como: Adicionar roteamento de comando para o controle Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `ICommandTarget`.  
  
 Para obter mais informações sobre como usar formulários do Windows, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)  
  
## <a name="addcommandhandler"></a>ICommandSource::AddCommandHandler
Adiciona um manipulador de comandos a um objeto de origem.
```
void AddCommandHandler(
    unsigned int cmdID,
    CommandHandler^ cmdHandler);
```

### <a name="parameters"></a>Parâmetros  
`cmdID`  
A ID de comando.  
`cmdHandler`  
Um identificador para o método de manipulador de comando.

### <a name="remarks"></a>Comentários
Este método adiciona o cmdHandler de manipulador de comando para o objeto de origem de comando e mapeia o manipulador para cmdID.
Consulte [como: Adicionar roteamento de comando para o controle Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar AddCommandHandler.

## <a name="addcommandrangehandler"></a>ICommandSource::AddCommandRangeHandler

Adiciona um grupo de manipuladores de comandos a um objeto de origem.
```
void AddCommandRangeHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax,
    CommandHandler^ cmdHandler);
```
### <a name="parameters"></a>Parâmetros  
`cmdIDMin`  
O índice de início do intervalo de ID de comando.
`cmdIDMax`  
O índice final do intervalo de ID de comando.
`cmdHandler`  
Um identificador para o método de manipulador de mensagem no qual os comandos são mapeados.
### <a name="remarks"></a>Comentários
Esse método mapeia um intervalo contíguo de IDs de comando para um manipulador de mensagem única e o adiciona ao objeto de origem de comando. Isso é usado para tratar de um grupo de botões com um método.

## <a name="addcommandrangeuihandler"></a>ICommandSource::AddCommandRangeUIHandler
Adiciona um grupo de manipuladores de mensagens de comando de interface de usuário a um objeto de origem.
```
void AddCommandRangeUIHandler(
    unsigned int cmdIDMin, 
    unsigned int cmdIDMax, 
    CommandUIHandler^ cmdUIHandler);
```
### <a name="parameters"></a>Parâmetros  
`cmdIDMin`  
O índice de início do intervalo de ID de comando.
`cmdIDMax`  
O índice final do intervalo de ID de comando.
`cmdHandler`  
Um identificador para o método de manipulador de mensagem no qual os comandos são mapeados.

### <a name="remarks"></a>Comentários
Esse método mapeia um intervalo contíguo de IDs de comando para um manipulador de mensagens de comando de interface de usuário único e o adiciona ao objeto de origem de comando. Isso é usado para tratar de um grupo de botões com um método.

## <a name="addcommanduihandler"></a>ICommandSource::AddCommandUIHandler
Adiciona um manipulador de mensagens de comando de interface do usuário a um objeto de origem.
```
void AddCommandUIHandler(
    unsigned int cmdID, 
    CommandUIHandler^ cmdUIHandler);
```
### <a name="parameters"></a>Parâmetros
`cmdID`  
A ID de comando.  
`cmdUIHandler`  
Um identificador para o método de manipulador de mensagem para comando de interface de usuário.

### <a name="remarks"></a>Comentários
Este método adiciona cmdHandler de manipulador de mensagem de comando para interface do usuário para o objeto de origem de comando e mapeia o manipulador para cmdID.

## <a name="postcommand"></a>ICommandSource::PostCommand
Publica uma mensagem sem esperar que ele seja processado.
```
void PostCommand(unsigned int command);
```
### <a name="parameters"></a>Parâmetros
`command`  
A ID de comando da mensagem a ser lançada.
### <a name="remarks"></a>Comentários
Este método lança Assincronamente a mensagem mapeada para a ID especificada pelo comando. Ele chama CWnd::PostMessage para colocar a mensagem na fila de mensagens da janela e, em seguida, retorna sem esperar que a janela correspondente processar a mensagem.


## <a name="removecommandhandler"></a>ICommandSource::RemoveCommandHandler
Remove um manipulador de comandos de um objeto de fonte de comando.
```
void RemoveCommandHandler(unsigned int cmdID);
```
### <a name="parameters"></a>Parâmetros
`cmdID`  
A ID de comando.
### <a name="remarks"></a>Comentários
Este método Remove o manipulador de comandos mapeado para cmdID do objeto de origem de comando.


## <a name="removecommandrangecommandhandler"></a>ICommandSource::RemoveCommandRangeHandler 
Remove um grupo de manipuladores de comandos de um objeto de origem de comando.
```
void RemoveCommandRangeUIHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax);
```
### <a name="parameters"></a>Parâmetros
`cmdIDMin`  
O índice de início do intervalo de ID de comando.
`cmdIDMax`  
O índice final do intervalo de ID de comando.
### <a name="remarks"></a>Comentários
Esse método Remove um grupo de manipuladores de mensagens, mapeado para o comando IDs especificados pela cmdIDMin e cmdIDMax, do objeto de origem de comando.

## <a name="removecommandrangeuihandler"></a>ICommandSource::RemoveCommandRangeUIHandler 
Remove um grupo de manipuladores de mensagens de comando de interface de usuário de um objeto de origem de comando.
```
void RemoveCommandRangeUIHandler(
    unsigned int cmdIDMin,
    unsigned int cmdIDMax);
```
### <a name="parameters"></a>Parâmetros
`cmdIDMin`  
O índice de início do intervalo de ID de comando.
`cmdIDMax`  
O índice final do intervalo de ID de comando.
### <a name="remarks"></a>Comentários
Esse método Remove um grupo de manipuladores de mensagens do usuário interface comando, mapeado para o comando IDs especificados pela cmdIDMin e cmdIDMax, do objeto de origem de comando.

## <a name="removecommanduihandler"></a>ICommandSource::RemoveCommandUIHandler 
Remove um manipulador de mensagens de comando de interface de usuário de um objeto de fonte de comando.
```
void RemoveCommandUIHandler(unsigned int cmdID);
```
### <a name="parameters"></a>Parâmetros
`cmdID`  
A ID de comando.
### <a name="remarks"></a>Comentários
Este método Remove o manipulador de mensagens de comando do usuário interface mapeado para cmdID do objeto de origem de comando.

## <a name="sendcommand"></a>ICommandSource::SendCommand 
Envia uma mensagem e aguarda até que ele seja processado antes de retornar.
```
void SendCommand(unsigned int command);
```
### <a name="parameters"></a>Parâmetros
`command`  
A ID de comando da mensagem a ser enviada.
### <a name="remarks"></a>Comentários
Esse método de forma síncrona envia a mensagem mapeada para a ID especificada pelo comando. Ele chama CWnd::SendMessage para colocar a mensagem na fila de mensagens da janela e aguarda até que esse procedimento de janela processou a mensagem antes de retornar.
## <a name="see-also"></a>Consulte também  
 [Como: adicionar comandos de controle de formulários do roteamento para o Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)   
 [Interface ICommandTarget](../../mfc/reference/icommandtarget-interface.md)
