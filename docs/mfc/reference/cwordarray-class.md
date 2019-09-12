---
title: Classe CWordArray
ms.date: 09/07/2019
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
ms.openlocfilehash: c136bbb14e0d7cffc604813731b6f87ba18063cf
ms.sourcegitcommit: 3caf5261b3ea80d9cf14038c116ba981d655cd13
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/11/2019
ms.locfileid: "70907906"
---
# <a name="cwordarray-class"></a>Classe CWordArray

Oferece suporte a matrizes de palavras de 16 bits.

## <a name="syntax"></a>Sintaxe

```
class CWordArray : public CObject
```

## <a name="members"></a>Membros

As funções de membro `CWordArray` do são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObArray` para obter a função específica de membro. Sempre que você vir um ponteiro [CObject](../../mfc/reference/cobject-class.md) como um parâmetro de função ou valor de retorno, substitua uma palavra.

`CObject* CObArray::GetAt( int <nIndex> ) const;`

por exemplo, traduz para

`WORD CWordArray::GetAt( int <nIndex> ) const;`

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[CObArray::CObArray](../../mfc/reference/cobarray-class.md#cobarray)|Constrói uma matriz vazia.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[CObArray::Add](../../mfc/reference/cobarray-class.md#add)|Inclui um elemento ao final da matriz; aumenta a matriz quando necessário.|
|[CObArray:: Append](../../mfc/reference/cobarray-class.md#append)|Acrescenta outra matriz à matriz; aumenta a matriz quando necessário.|
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

### <a name="public-operators"></a>Operadores públicos

|Nome|Descrição|
|----------|-----------------|
|[Operador CObArray::&#91;&#93;](../../mfc/reference/cobarray-class.md#operator_at)|Define ou obtém o elemento no índice especificado.|

## <a name="remarks"></a>Comentários

`CWordArray`incorpora a macro [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) para dar suporte à serialização e ao despejo de seus elementos. Se uma matriz de palavras for armazenada em um arquivo morto, com um operador de inserção sobrecarregado ou com a função de membro [CObject:: Serialize](../../mfc/reference/cobject-class.md#serialize) , cada elemento será, por sua vez, serializado.

> [!NOTE]
>  Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.

Se você precisar de um despejo de elementos individuais na matriz, deverá definir a profundidade do contexto de despejo como 1 ou maior.

Para obter mais informações sobre `CWordArray`como usar o, consulte o artigo [coleções](../../mfc/collections.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

`CWordArray`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxcoll. h

##  <a name="icommandsource_interface"></a>Interface ICommand

Gerencia comandos enviados de um objeto de origem de comando para um controle de usuário.

```
interface class ICommandSource
```

### <a name="remarks"></a>Comentários

Quando você hospeda um controle de usuário em uma exibição do MFC, a [classe CWinFormsView](../../mfc/reference/cwinformsview-class.md) roteia comandos e atualiza mensagens de interface do usuário de comando para o controle de usuários para permitir que ele manipule comandos do MFC (por exemplo, itens de menu de quadro e botões da barra de ferramentas). Ao implementar, você dá ao usuário controle uma referência ao `ICommandSource` objeto.

Confira [Como Adicione roteamento de comando ao controle](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) de Windows Forms para obter um exemplo de como usar. `ICommandTarget`

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

##  <a name="addcommandhandler"></a>  ICommandSource::AddCommandHandler

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

Esse método adiciona o manipulador de comandos *cmdHandler* ao objeto de origem de comando e mapeia o manipulador para *cmdID*.

Confira [Como Adicione roteamento de comando ao controle](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) de Windows Forms para obter um exemplo de como usar. `AddCommandHandler`

##  <a name="addcommandrangehandler"></a>  ICommandSource::AddCommandRangeHandler

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

##  <a name="addcommandrangeuihandler"></a>  ICommandSource::AddCommandRangeUIHandler

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

##  <a name="addcommanduihandler"></a>  ICommandSource::AddCommandUIHandler

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

Esse método adiciona o manipulador de mensagens de comando da interface do usuário *cmdHandler* ao objeto de origem de comando e mapeia o manipulador para *cmdID*.

##  <a name="postcommand"></a>ICommand::P ostCommand

Posta uma mensagem sem esperar que ela seja processada.

```
void PostCommand(unsigned int command);
```

### <a name="parameters"></a>Parâmetros

*command*<br/>
A ID de comando da mensagem a ser postada.

### <a name="remarks"></a>Comentários

Esse método posta de forma assíncrona a mensagem mapeada para a ID especificada pelo *comando*. Ele chama [CWnd::P ostmessage](../../mfc/reference/cwnd-class.md#postmessage) para colocar a mensagem na fila de mensagens da janela e, em seguida, retorna sem esperar que a janela correspondente processe a mensagem.

##  <a name="removecommandhandler"></a>  ICommandSource::RemoveCommandHandler

Remove um manipulador de comandos de um objeto de origem de comando.

```
void RemoveCommandHandler(unsigned int cmdID);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID do comando.

### <a name="remarks"></a>Comentários

Esse método remove o manipulador de comandos mapeado para *cmdID* do objeto de origem de comando.

##  <a name="removecommandrangehandler"></a>  ICommandSource::RemoveCommandRangeHandler

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

Esse método Remove um grupo de manipuladores de mensagens, mapeados para as IDs de comando especificadas por *cmdIDMin* e *cmdIDMax*, do objeto de origem de comando.

##  <a name="removecommandrangeuihandler"></a>  ICommandSource::RemoveCommandRangeUIHandler

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

Esse método Remove um grupo de manipuladores de mensagens de comando da interface do usuário, mapeados para as IDs de comando especificadas por *cmdIDMin* e *cmdIDMax*, do objeto de origem de comando.

##  <a name="removecommanduihandler"></a>  ICommandSource::RemoveCommandUIHandler

Remove um manipulador de mensagens de comando da interface do usuário de um objeto de origem de comando.

```
void RemoveCommandUIHandler(unsigned int cmdID);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID do comando.

### <a name="remarks"></a>Comentários

Esse método remove o manipulador de mensagens de comando da interface do usuário mapeado para *cmdID* do objeto de origem de comando.

##  <a name="sendcommand"></a>ICommand:: SendCommand

Envia uma mensagem e aguarda que ela seja processada antes de retornar.

```
void SendCommand(unsigned int command);
```

### <a name="parameters"></a>Parâmetros

*command*<br/>
A ID de comando da mensagem a ser enviada.

### <a name="remarks"></a>Comentários

Esse método envia de forma síncrona a mensagem mapeada para a ID especificada pelo *comando*. Ele chama [CWnd:: SendMessage](../../mfc/reference/cwnd-class.md#sendmessage) para colocar a mensagem na fila de mensagens da janela e aguarda até que o procedimento da janela tenha processado a mensagem antes de retornar.

##  <a name="icommandtarget_interface"></a>Interface ICommandTarget

Fornece um controle de usuário com uma interface para receber comandos de um objeto de origem de comando.

```
interface class ICommandTarget
```

### <a name="remarks"></a>Comentários

Quando você hospeda um controle de usuário em uma exibição do MFC, o [CWinFormsView](../../mfc/reference/cwinformsview-class.md) roteia comandos e atualiza mensagens da interface do usuário do comando para o controle de usuários para permitir que ele manipule comandos do MFC (por exemplo, itens de menu de quadro e botões da barra de ferramentas). Ao implementar `ICommandTarget`, você dá ao usuário controle uma referência ao objeto.

Confira [Como Adicione roteamento de comando ao controle](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) de Windows Forms para obter um exemplo de como usar. `ICommandTarget`

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

##  <a name="initialize"></a>  ICommandTarget::Initialize

Inicializa o objeto de destino do comando.

```
void Initialize(ICommandSource^ cmdSource);
```

### <a name="parameters"></a>Parâmetros

*cmdSource*<br/>
Um identificador para o objeto de origem de comando.

### <a name="remarks"></a>Comentários

Quando você hospeda um controle de usuário em uma exibição do MFC, o [CWinFormsView](../../mfc/reference/cwinformsview-class.md) roteia comandos e atualiza mensagens de interface do usuário de comando para o controle de usuários para permitir que ele manipule comandos do MFC.

Esse método inicializa o objeto de destino de comando e o associa ao objeto de origem de comando especificado *cmdSource*. Ele deve ser chamado na implementação da classe de controle de usuário. Na inicialização, você deve registrar manipuladores de comando com o objeto de origem de comando chamando [ICommand:: AddCommandHandler](../../mfc/reference/icommandsource-interface.md) na `Initialize` implementação. Confira [Como Adicione roteamento de comando ao controle](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) de Windows Forms para obter um exemplo de como usar `Initialize` para fazer isso.

##  <a name="icommandui_interface"></a>Interface ICommandUI

Gerencia comandos da interface do usuário.

```
interface class ICommandUI
```

### <a name="remarks"></a>Comentários

Essa interface fornece métodos e propriedades que gerenciam comandos de interface do usuário. `ICommandUI`é semelhante à [classe CCmdUI](../../mfc/reference/ccmdui-class.md), exceto que `ICommandUI` é usado para aplicativos MFC que interoperam com componentes .net.

`ICommandUI`é usado dentro de `ON_UPDATE_COMMAND_UI` um manipulador em uma classe derivada. Quando um usuário de um aplicativo é ativado (seleciona ou clica em) um menu, cada item de menu é exibido como habilitado ou desabilitado. O destino de cada comando de menu fornece essas informações implementando `ON_UPDATE_COMMAND_UI` um manipulador. Para cada um dos objetos de interface do usuário de comando em seu aplicativo, use o [Assistente de classe](mfc-class-wizard.md) ou a janela **propriedades** (em **modo de exibição de classe**) para criar uma entrada de mapa de mensagem e um protótipo de função para cada manipulador.

Para obter mais informações sobre como `ICommandUI` a interface é usada no roteamento de comandos [, consulte Como: Adicione o roteamento de comando ao controle](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)de Windows Forms.

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

Para obter mais informações sobre como os comandos da interface do usuário são gerenciados no MFC, consulte [classe CCmdUI](../../mfc/reference/ccmdui-class.md).

##  <a name="check"></a>ICommandUI:: verificar

Define o item de interface do usuário para esse comando para o estado de verificação apropriado.

```
property UICheckState Check;
```

### <a name="remarks"></a>Comentários

Essa propriedade define o item de interface do usuário para esse comando para o estado de verificação apropriado. Defina `Check` os seguintes valores:

|Termo|Definição|
|----------|----------------|
|0|Desmarque|
|1|Azure Functions|
|2|Definir indeterminado|

##  <a name="continuerouting"></a>  ICommandUI::ContinueRouting

Informa ao mecanismo de roteamento de comando para continuar a rotear a mensagem atual para baixo na cadeia de manipuladores.

```
void ContinueRouting();
```

### <a name="remarks"></a>Comentários

Essa é uma função de membro avançada que deve ser usada em conjunto com um manipulador [ON_COMMAND_EX](message-map-macros-mfc.md#on_command_ex) que retorna false. Para obter mais informações, consulte a [nota técnica TN006: Mapas](../../mfc/tn006-message-maps.md)de mensagens.

##  <a name="enabled"></a>ICommandUI:: habilitado

Habilita ou desabilita o item de interface do usuário para este comando.

```
property bool Enabled;
```

### <a name="remarks"></a>Comentários

Essa propriedade habilita ou desabilita o item de interface do usuário para este comando. Defina `Enabled` como true para habilitar o item, false para desabilitá-lo.

##  <a name="id"></a>  ICommandUI::ID

Obtém a ID do objeto da interface do usuário representado pelo `ICommandUI` objeto.

```
property unsigned int ID;
```

### <a name="remarks"></a>Comentários

Essa propriedade Obtém a ID (um identificador) do item de menu, botão da barra de ferramentas ou outro objeto de interface do `ICommandUI` usuário representado pelo objeto.

##  <a name="index"></a>ICommandUI:: index

Obtém o índice do objeto da interface do usuário representado pelo `ICommandUI` objeto.

```
property unsigned int Index;
```

### <a name="remarks"></a>Comentários

Essa propriedade Obtém o índice (um identificador) do item de menu, botão da barra de ferramentas ou outro objeto de interface do `ICommandUI` usuário representado pelo objeto.

##  <a name="radio"></a>ICommandUI:: Radio

Define o item de interface do usuário para esse comando para o estado de verificação apropriado.

```
property bool Radio;
```

### <a name="remarks"></a>Comentários

Essa propriedade define o item de interface do usuário para esse comando para o estado de verificação apropriado. Defina `Radio` como true para habilitar o item; caso contrário, false.

##  <a name="text"></a>  ICommandUI::Text

Define o texto do item de interface do usuário para este comando.

```
property String^ Text;
```

### <a name="remarks"></a>Comentários

Essa propriedade define o texto do item de interface do usuário para este comando. Defina `Text` como um identificador de cadeia de caracteres de texto.

##  <a name="iview_interface"></a>Interface do IView

Implementa vários métodos que o [CWinFormsView](../../mfc/reference/cwinformsview-class.md) usa para enviar notificações de exibição a um controle gerenciado.

```
interface class IView
```

### <a name="remarks"></a>Comentários

`IView`implementa vários métodos que `CWinFormsView` o usa para encaminhar notificações de exibição comuns a um controle gerenciado hospedado. São [OnInitialUpdate](../../mfc/reference/iview-interface.md), [OnUpdate](../../mfc/reference/iview-interface.md) e [OnActivateView](../../mfc/reference/iview-interface.md).

`IView`é semelhante a [cvisualização](../../mfc/reference/cview-class.md), mas é usado somente com exibições e controles gerenciados.

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

##  <a name="onactivateview"></a>  IView::OnActivateView

Chamado pelo MFC quando uma exibição é ativada ou desativada.

```
void OnActivateView(bool activate);
```

### <a name="parameters"></a>Parâmetros

*Activate*<br/>
Indica se a exibição está sendo ativada ou desativada.

##  <a name="oninitialupdate"></a>IView:: OnInitialUpdate

Chamado pelo Framework depois que a exibição é anexada primeiro ao documento, mas antes de a exibição ser inicialmente exibida.

```
void OnInitialUpdate();
```

##  <a name="onupdate"></a>IView:: OnUpdate

Chamado pelo MFC após a modificação do documento da exibição.

```
void OnUpdate();
```

### <a name="remarks"></a>Comentários

Essa função permite que a exibição Atualize sua exibição para refletir as modificações.

## <a name="see-also"></a>Consulte também

[COLETA de amostra do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe CObject](../../mfc/reference/cobject-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
