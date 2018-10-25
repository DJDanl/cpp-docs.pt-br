---
title: Classe CWordArray | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- CWordArray
- AFXCOLL/CWordArray
- AFXCOLL/CObArray::CObArray
- AFXCOLL/CObArray::Add
- AFXCOLL/CObArray::Append
- AFXCOLL/CObArray::Copy
- AFXCOLL/CObArray::ElementAt
- AFXCOLL/CObArray::FreeExtra
- AFXCOLL/CObArray::GetAt
- AFXCOLL/CObArray::GetCount
- AFXCOLL/CObArray::GetData
- AFXCOLL/CObArray::GetSize
- AFXCOLL/CObArray::GetUpperBound
- AFXCOLL/CObArray::InsertAt
- AFXCOLL/CObArray::IsEmpty
- AFXCOLL/CObArray::RemoveAll
- AFXCOLL/CObArray::RemoveAt
- AFXCOLL/CObArray::SetAt
- AFXCOLL/CObArray::SetAtGrow
- AFXCOLL/CObArray::SetSize
dev_langs:
- C++
helpviewer_keywords:
- CObArray [MFC], CObArray
- CObArray [MFC], Add
- CObArray [MFC], Append
- CObArray [MFC], Copy
- CObArray [MFC], ElementAt
- CObArray [MFC], FreeExtra
- CObArray [MFC], GetAt
- CObArray [MFC], GetCount
- CObArray [MFC], GetData
- CObArray [MFC], GetSize
- CObArray [MFC], GetUpperBound
- CObArray [MFC], InsertAt
- CObArray [MFC], IsEmpty
- CObArray [MFC], RemoveAll
- CObArray [MFC], RemoveAt
- CObArray [MFC], SetAt
- CObArray [MFC], SetAtGrow
- CObArray [MFC], SetSize
ms.assetid: 2ba2c194-2c6c-40ff-9db4-e9dbe57e1f57
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 798e3d0a7cc8d8573c03f9859b722c95b8c640af
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50070251"
---
# <a name="cwordarray-class"></a>Classe CWordArray

Dá suporte a matrizes de palavras de 16 bits.

## <a name="syntax"></a>Sintaxe

```
class CWordArray : public CObject
```

## <a name="members"></a>Membros

As funções membro da `CWordArray` são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObArray` para obter a função específica de membro. Onde quer que você vê uma [CObject](../../mfc/reference/cobject-class.md) ponteiro como um parâmetro de função ou um valor de retorno, substituir uma palavra.

`CObject* CObArray::GetAt( int <nIndex> ) const;`

por exemplo, traduz para

`WORD CWordArray::GetAt( int <nIndex> ) const;`

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CObArray::CObArray](../../mfc/reference/cobarray-class.md#cobarray)|Constrói uma matriz vazia.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[CObArray::Add](../../mfc/reference/cobarray-class.md#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CObArray::Append](../../mfc/reference/cobarray-class.md#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|
|[CObArray::Copy](../../mfc/reference/cobarray-class.md#copy)|Copia outra matriz à matriz; aumenta a matriz quando necessário.|
|[CObArray::ElementAt](../../mfc/reference/cobarray-class.md#elementat)|Retorna uma referência temporária ao ponteiro do elemento dentro da matriz.|
|[CObArray::FreeExtra](../../mfc/reference/cobarray-class.md#freeextra)|Libera toda memória não usada acima do limite superior atual.|
|[CObArray::GetAt](../../mfc/reference/cobarray-class.md#getat)|Retorna o valor a um determinado índice.|
|[CObArray::GetCount](../../mfc/reference/cobarray-class.md#getcount)|Obtém o número de elementos nesta matriz.|
|[CObArray::GetData](../../mfc/reference/cobarray-class.md#getdata)|Permite acesso aos elementos na matriz. Pode ser NULL.|
|[CObArray::GetSize](../../mfc/reference/cobarray-class.md#getsize)|Obtém o número de elementos nesta matriz.|
|[CObArray::GetUpperBound](../../mfc/reference/cobarray-class.md#getupperbound)|Retorna o maior índice válido.|
|[CObArray::InsertAt](../../mfc/reference/cobarray-class.md#insertat)|Insere um elemento (ou todos os elementos em outra matriz) em um índice especificado.|
|[CObArray::IsEmpty](../../mfc/reference/cobarray-class.md#isempty)|Determina se a matriz está vazia.|
|[CObArray::RemoveAll](../../mfc/reference/cobarray-class.md#removeall)|Remove todos os elementos dessa matriz.|
|[CObArray::RemoveAt](../../mfc/reference/cobarray-class.md#removeat)|Remove um elemento a um índice específico.|
|[CObArray::SetAt](../../mfc/reference/cobarray-class.md#setat)|Define o valor de um determinado índice; não é permitido à matriz aumentar.|
|[CObArray::SetAtGrow](../../mfc/reference/cobarray-class.md#setatgrow)|Define o valor de um determinado índice; aumenta a matriz quando necessário.|
|[CObArray::SetSize](../../mfc/reference/cobarray-class.md#setsize)|Define o número de elementos a ser contido nesta matriz.|

### <a name="public-operators"></a>Operadores Públicos

|Nome|Descrição|
|----------|-----------------|
|[CObArray::operator&#91;&#93;](../../mfc/reference/cobarray-class.md#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

`CWordArray` incorpora o [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro para dar suporte à serialização e despejo de seus elementos. Se uma matriz de palavras é armazenada em um arquivo, com um operador de inserção sobrecarregado ou com o [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) função de membro, cada elemento é, por sua vez, serializado.

> [!NOTE]
>  Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

Se você precisar de um despejo de elementos individuais na matriz, você deve definir a profundidade do contexto de despejo para 1 ou maior.

Para obter mais informações sobre como usar `CWordArray`, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CWordArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** & amp;lt;1}afxcoll.h

##  <a name="icommandsource_interface"></a>  Interface ICommandSource

Gerencia os comandos enviados de um objeto de origem de comando para um controle de usuário.

```
interface class ICommandSource
```

### <a name="remarks"></a>Comentários

Ao hospedar um controle de usuário em uma exibição do MFC [classe CWinFormsView](../../mfc/reference/cwinformsview-class.md) comandos de rotas e atualização de comando mensagens de interface do usuário para o controle de usuário para permitir a manipulação de comandos MFC (por exemplo, itens de menu do quadro e botões da barra de ferramentas). Com a implementação, você dar o controle de usuário uma referência para o `ICommandSource` objeto.

Ver [como: Adicionar roteamento de comando para o controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `ICommandTarget`.

Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

##  <a name="addcommandhandler"></a>  ICommandSource::AddCommandHandler

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

Esse método adiciona o manipulador de comandos *cmdHandler* ao objeto de origem de comando e mapeia o manipulador a ser *cmdID*.

Ver [como: Adicionar roteamento de comando para o controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `AddCommandHandler`.

##  <a name="addcommandrangehandler"></a>  ICommandSource::AddCommandRangeHandler

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

##  <a name="addcommandrangeuihandler"></a>  ICommandSource::AddCommandRangeUIHandler

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

##  <a name="addcommanduihandler"></a>  ICommandSource::AddCommandUIHandler

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

Esse método adiciona o manipulador de mensagens de comando de interface do usuário *cmdHandler* ao objeto de origem de comando e mapeia o manipulador a ser *cmdID*.

##  <a name="postcommand"></a>  ICommandSource::PostCommand

Posta uma mensagem sem aguardar que ele seja processado.

```
void PostCommand(unsigned int command);
```

### <a name="parameters"></a>Parâmetros

*command*<br/>
A ID de comando da mensagem a ser postada.

### <a name="remarks"></a>Comentários

Esse método assincronamente posta a mensagem mapeada para a ID especificada por *comando*. Ele chama [CWnd::PostMessage](../../mfc/reference/cwnd-class.md#postmessage) colocar a mensagem na fila de mensagens da janela e o retorna sem aguardar a janela correspondente processar a mensagem.

##  <a name="removecommandhandler"></a>  ICommandSource::RemoveCommandHandler

Remove um manipulador de comandos de um objeto de origem do comando.

```
void RemoveCommandHandler(unsigned int cmdID);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID de comando.

### <a name="remarks"></a>Comentários

Esse método Remove o manipulador de comandos mapeado para *cmdID* do objeto de origem de comando.

##  <a name="removecommandrangehandler"></a>  ICommandSource::RemoveCommandRangeHandler

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

Esse método Remove um grupo de manipuladores de mensagens, mapeado para o especificado de IDs de comando por *cmdIDMin* e *cmdIDMax*, do objeto de origem de comando.

##  <a name="removecommandrangeuihandler"></a>  ICommandSource::RemoveCommandRangeUIHandler

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

Esse método Remove um grupo de usuário interface comando de manipuladores de mensagens, mapeado para o especificado de IDs de comando por *cmdIDMin* e *cmdIDMax*, do objeto de origem de comando.

##  <a name="removecommanduihandler"></a>  ICommandSource::RemoveCommandUIHandler

Remove um manipulador de mensagens de comando de interface do usuário de um objeto de origem do comando.

```
void RemoveCommandUIHandler(unsigned int cmdID);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID de comando.

### <a name="remarks"></a>Comentários

Esse método Remove o manipulador de mensagens de comando do usuário interface mapeado para *cmdID* do objeto de origem de comando.

##  <a name="sendcommand"></a>  ICommandSource::SendCommand

Envia uma mensagem e aguarda até que ele seja processado antes de retornar.

```
void SendCommand(unsigned int command);
```

### <a name="parameters"></a>Parâmetros

*command*<br/>
A ID de comando da mensagem a ser enviada.

### <a name="remarks"></a>Comentários

Esse método envia de forma síncrona a mensagem mapeada para a ID especificada por *comando*. Ele chama [CWnd::SendMessage](../../mfc/reference/cwnd-class.md#sendmessage) colocar a mensagem na fila de mensagens da janela e o aguarda até que esse procedimento de janela processou a mensagem antes de retornar.

##  <a name="icommandtarget_interface"></a>  Interface ICommandTarget

Fornece um controle de usuário com uma interface para receber comandos de um objeto de fonte de comando.

```
interface class ICommandTarget
```

### <a name="remarks"></a>Comentários

Ao hospedar um controle de usuário em uma exibição do MFC [CWinFormsView](../../mfc/reference/cwinformsview-class.md) comandos de rotas e atualização de comando mensagens de interface do usuário para o controle de usuário para permitir a manipulação de comandos MFC (por exemplo, itens de menu do quadro e botões da barra de ferramentas). Implementando `ICommandTarget`, você dar o controle de usuário, uma referência ao objeto.

Ver [como: Adicionar roteamento de comando para o controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `ICommandTarget`.

Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

##  <a name="initialize"></a>  ICommandTarget::Initialize

Inicializa o objeto de destino do comando.

```
void Initialize(ICommandSource^ cmdSource);
```

### <a name="parameters"></a>Parâmetros

*cmdSource*<br/>
Um identificador para o objeto de fonte de comando.

### <a name="remarks"></a>Comentários

Ao hospedar um controle de usuário em uma exibição do MFC [CWinFormsView](../../mfc/reference/cwinformsview-class.md) comandos de rotas e atualização de comando mensagens de interface do usuário para o controle de usuário para permitir a manipulação de comandos MFC.

Esse método inicializa o objeto de destino do comando e a associa o objeto de origem do comando especificado *cmdSource*. Ele deve ser chamado na implementação de classe do controle de usuário. Na inicialização, você deve registrar manipuladores de comandos com o objeto de fonte de comando chamando [ICommandSource::AddCommandHandler](../../mfc/reference/icommandsource-interface.md) no `Initialize` implementação. Ver [como: Adicionar roteamento de comando para o controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `Initialize` para fazer isso.

##  <a name="icommandui_interface"></a>  Interface ICommandUI

Gerencia os comandos de interface do usuário.

```
interface class ICommandUI
```

### <a name="remarks"></a>Comentários

Essa interface fornece métodos e propriedades que gerenciam os comandos de interface do usuário. `ICommandUI` é semelhante à [classe CCmdUI](../../mfc/reference/ccmdui-class.md), exceto que `ICommandUI` é usado para aplicativos MFC que interoperam com componentes do .NET.

`ICommandUI` é usado dentro de um `ON_UPDATE_COMMAND_UI` manipulador em uma - classe derivada. Quando um usuário de um aplicativo ativa (seleciona ou cliques) será exibido um menu, cada item de menu como habilitado ou desabilitado. O destino de cada comando de menu fornece essas informações com a implementação de um `ON_UPDATE_COMMAND_UI` manipulador. Para cada um dos objetos de interface do usuário de comando em seu aplicativo, use a janela Propriedades para criar uma entrada de mapa de mensagem e o protótipo de função para cada manipulador.

Para obter mais informações sobre como as `ICommandUI` interface é usada no roteamento de comando, consulte [como: Adicionar roteamento de comando para o controle de formulários do Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md).

Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

Para obter mais informações sobre como os comandos de interface do usuário são gerenciados no MFC, consulte [classe CCmdUI](../../mfc/reference/ccmdui-class.md).

##  <a name="check"></a>  ICommandUI::Check

Define o item de interface do usuário para esse comando para o estado de seleção apropriadas.

```
property UICheckState Check;
```

### <a name="remarks"></a>Comentários

Essa propriedade define o item de interface do usuário para esse comando para o estado de seleção apropriadas. Definir `Check` com os seguintes valores:

|Termo|Definição|
|----------|----------------|
|0|Desmarque a opção|
|1|Azure Functions|
|2|Definir indeterminado|

##  <a name="continuerouting"></a>  ICommandUI::ContinueRouting

Informa ao mecanismo de roteamento de comando para continua a rotear a mensagem atual a cadeia de manipuladores.

```
void ContinueRouting();
```

### <a name="remarks"></a>Comentários

Essa é uma função de membro avançado que deve ser usada em conjunto com um [ON_COMMAND_EX](message-map-macros-mfc.md#on_command_ex) manipulador que retorna FALSE. Para obter mais informações, consulte a Observação técnica [TN006: mapas de mensagem](../../mfc/tn006-message-maps.md).

##  <a name="enabled"></a>  ICommandUI::Enabled

Habilita ou desabilita o item de interface do usuário para esse comando.

```
property bool Enabled;
```

### <a name="remarks"></a>Comentários

Esta propriedade habilita ou desabilita o item de interface do usuário para esse comando. Definir `Enabled` como TRUE para habilitar o item, FALSE para desabilitá-lo.

##  <a name="id"></a>  ICommandUI::ID

Obtém a ID do objeto de interface do usuário representado pelo `ICommandUI` objeto.

```
property unsigned int ID;
```

### <a name="remarks"></a>Comentários

Essa propriedade obtém a ID (um identificador) do item de menu, botão de barra de ferramentas, ou outro objeto de interface do usuário representado pelo `ICommandUI` objeto.

##  <a name="index"></a>  ICommandUI::Index

Obtém o índice do objeto de interface do usuário representado pelo `ICommandUI` objeto.

```
property unsigned int Index;
```

### <a name="remarks"></a>Comentários

Essa propriedade obtém o índice (um identificador) do item de menu, botão de barra de ferramentas, ou outro objeto de interface do usuário representado pelo `ICommandUI` objeto.

##  <a name="radio"></a>  ICommandUI::Radio

Define o item de interface do usuário para esse comando para o estado de seleção apropriadas.

```
property bool Radio;
```

### <a name="remarks"></a>Comentários

Essa propriedade define o item de interface do usuário para esse comando para o estado de seleção apropriadas. Definir `Radio` como TRUE para habilitar o item; caso contrário, FALSE.

##  <a name="text"></a>  ICommandUI::Text

Define o texto do item de interface de usuário para esse comando.

```
property String^ Text;
```

### <a name="remarks"></a>Comentários

Essa propriedade define o texto do item de interface de usuário para esse comando. Definir `Text` a um identificador de cadeia de caracteres de texto.

##  <a name="iview_interface"></a>  Interface IView

Implementa vários métodos que [CWinFormsView](../../mfc/reference/cwinformsview-class.md) usa para enviar notificações de exibição para um controle gerenciado.

```
interface class IView
```

### <a name="remarks"></a>Comentários

`IView` implementa vários métodos que `CWinFormsView` usa para encaminhar as notificações de exibição comuns para um controle gerenciado hospedado. Esses são [OnInitialUpdate](../../mfc/reference/iview-interface.md), [OnUpdate](../../mfc/reference/iview-interface.md) e [OnActivateView](../../mfc/reference/iview-interface.md).

`IView` é semelhante à [CView](../../mfc/reference/cview-class.md), mas é usado somente com exibições gerenciadas e controles.

Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

##  <a name="onactivateview"></a>  IView::OnActivateView

Chamado pelo MFC quando uma exibição é ativada ou desativada.

```
void OnActivateView(bool activate);
```

### <a name="parameters"></a>Parâmetros

*Ativar*<br/>
Indica se o modo de exibição está sendo ativada ou desativada.

##  <a name="oninitialupdate"></a>  IView::OnInitialUpdate

Chamado pelo framework depois que o modo de exibição é anexado pela primeira vez no documento, mas antes que o modo de exibição é exibido inicialmente.

```
void OnInitialUpdate();
```

##  <a name="onupdate"></a>  IView::OnUpdate

Chamado pelo MFC depois que o documento da exibição foi modificado.

```
void OnUpdate();
```

### <a name="remarks"></a>Comentários

Essa função permite que o modo de exibição atualizar sua exibição para refletir as modificações.

## <a name="see-also"></a>Consulte também

[Exemplo MFC COLETAR](../../visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)

