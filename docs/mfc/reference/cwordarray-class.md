---
title: Classe CWordArray | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CWordArray
dev_langs:
- C++
helpviewer_keywords:
- INT
- UINT
- indexed arrays
- arrays [C++], indexed
- WORD data type
- CWordArray class
ms.assetid: 2ba2c194-2c6c-40ff-9db4-e9dbe57e1f57
caps.latest.revision: 26
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: cd6c26c49c6b46449ec6d7da42b9166d17d563da
ms.lasthandoff: 02/25/2017

---
# <a name="cwordarray-class"></a>Classe CWordArray
Oferece suporte a matrizes de palavras de 16 bits.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
class CWordArray : public CObject  
```  
  
## <a name="members"></a>Membros  
 As funções de membro do `CWordArray` são semelhantes às funções de membro da classe [CObArray](../../mfc/reference/cobarray-class.md). Devido a essa semelhança, é possível usar a documentação de referência da `CObArray` para obter a função específica de membro. Ao ver um [CObject](../../mfc/reference/cobject-class.md) ponteiro como um parâmetro de função ou o valor de retorno, substitua um **WORD**.  
  
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
|[CObArray::GetData](../../mfc/reference/cobarray-class.md#getdata)|Permite acesso aos elementos na matriz. Pode ser **nulo**.|  
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
|[[CObArray::operator]](../../mfc/reference/cobarray-class.md#operator_at)|Define ou obtém o elemento no índice especificado.|  
  
## <a name="remarks"></a>Comentários  
 `CWordArray`incorpora o [IMPLEMENT_SERIAL](run-time-object-model-services.md#implement_serial) macro para oferecer suporte a serialização e despejo de seus elementos. Se uma matriz de palavras é armazenada em um arquivo, com um operador de inserção sobrecarregado ou com o [CObject::Serialize](../../mfc/reference/cobject-class.md#serialize) função de membro, cada elemento é, por sua vez, serializado.  
  
> [!NOTE]
>  Antes de usar uma matriz, utilize `SetSize` para estabelecer seu tamanho e alocar memória para ela. Se `SetSize` não for utilizado, incluir elementos à matriz fará com que ela seja frequentemente realocada e copiada. Realocações e cópias frequentes são ineficientes e podem fragmentar a memória.  
  
 Se você precisar de um despejo de elementos individuais da matriz, você deve definir a profundidade do contexto do despejo como 1 ou maior.  
  
 Para obter mais informações sobre como usar o `CWordArray`, consulte o artigo [coleções](../../mfc/collections.md).  
  
## <a name="inheritance-hierarchy"></a>Hierarquia de herança  
 [CObject](../../mfc/reference/cobject-class.md)  
  
 `CWordArray`  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxcoll. h  
  
##  <a name="a-nameicommandsourceinterfacea--icommandsource-interface"></a><a name="icommandsource_interface"></a>Interface ICommandSource  
 Gerencia os comandos enviados de um objeto de origem de comando para um controle de usuário.  
  
```  
interface class ICommandSource  
```  
  
### <a name="remarks"></a>Comentários  
 Quando você hospeda um controle de usuário em uma exibição MFC, [CWinFormsView classe](../../mfc/reference/cwinformsview-class.md) comandos de rotas e atualização de comando mensagens de interface do usuário para o controle de usuário para permitir que ele manipule comandos MFC (por exemplo, itens de menu do quadro e botões de barra de ferramentas). Implementando, você dá o controle de usuário uma referência para o `ICommandSource` objeto.  
  
 Consulte [como: Adicionar roteamento de comando para o controle Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `ICommandTarget`.  
  
 Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
##  <a name="a-nameaddcommandhandlera--icommandsourceaddcommandhandler"></a><a name="addcommandhandler"></a>ICommandSource::AddCommandHandler  
 Adiciona um manipulador de comandos a um objeto de origem.  
  
```  
void AddCommandHandler(
    unsigned int cmdID,  
    CommandHandler^ cmdHandler);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdID`  
 A ID do comando.  
  
 `cmdHandler`  
 Um identificador para o método de manipulador de comando.  
  
### <a name="remarks"></a>Comentários  
 Este método adiciona o manipulador de comandos `cmdHandler` ao objeto de origem de comando e mapeia o manipulador para `cmdID`.  
  
 Consulte [como: Adicionar roteamento de comando para o controle Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `AddCommandHandler`.  
  
##  <a name="a-nameaddcommandrangehandlera--icommandsourceaddcommandrangehandler"></a><a name="addcommandrangehandler"></a>ICommandSource::AddCommandRangeHandler  
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
 Um identificador para o método de manipulador de mensagens no qual os comandos são mapeados.  
  
### <a name="remarks"></a>Comentários  
 Esse método mapeia um intervalo contíguo de IDs de comando para um manipulador de mensagem única e o adiciona ao objeto de origem de comando. Isso é usado para tratar de um grupo de botões com um método.  
  
##  <a name="a-nameaddcommandrangeuihandlera--icommandsourceaddcommandrangeuihandler"></a><a name="addcommandrangeuihandler"></a>ICommandSource::AddCommandRangeUIHandler  
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
 Um identificador para o método de manipulador de mensagens no qual os comandos são mapeados.  
  
### <a name="remarks"></a>Comentários  
 Esse método mapeia um intervalo contíguo de IDs de comando para um manipulador de mensagens de comando de interface de usuário único e o adiciona ao objeto de origem de comando. Isso é usado para tratar de um grupo de botões com um método.  
  
##  <a name="a-nameaddcommanduihandlera--icommandsourceaddcommanduihandler"></a><a name="addcommanduihandler"></a>ICommandSource::AddCommandUIHandler  
 Adiciona um manipulador de mensagens de comando de interface do usuário a um objeto de origem.  
  
```  
void AddCommandUIHandler(
    unsigned int cmdID,   
    CommandUIHandler^ cmdUIHandler);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdID`  
 A ID do comando.  
  
 `cmdUIHandler`  
 Um identificador para o método de manipulador de mensagem para comando de interface de usuário.  
  
### <a name="remarks"></a>Comentários  
 Este método adiciona o manipulador de mensagens de comando de interface do usuário `cmdHandler` ao objeto de origem de comando e mapeia o manipulador para `cmdID`.  
  
##  <a name="a-namepostcommanda--icommandsourcepostcommand"></a><a name="postcommand"></a>ICommandSource::PostCommand  
 Posta uma mensagem sem esperar que ele seja processado.  
  
```  
void PostCommand(unsigned int command);
```  
  
### <a name="parameters"></a>Parâmetros  
 `command`  
 A ID de comando da mensagem a ser lançada.  
  
### <a name="remarks"></a>Comentários  
 Esse método de forma assíncrona publica a mensagem mapeada para a ID especificada por `command`. Ele chama [CWnd::PostMessage](../../mfc/reference/cwnd-class.md#postmessage) coloca a mensagem na fila de mensagens da janela e retorna sem esperar que a janela correspondente processar a mensagem.  
  
##  <a name="a-nameremovecommandhandlera--icommandsourceremovecommandhandler"></a><a name="removecommandhandler"></a>ICommandSource::RemoveCommandHandler  
 Remove um manipulador de comandos de um objeto de fonte de comando.  
  
```  
void RemoveCommandHandler(unsigned int cmdID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdID`  
 A ID do comando.  
  
### <a name="remarks"></a>Comentários  
 Este método Remove o manipulador de comandos mapeado para `cmdID` do objeto de origem de comando.  
  
##  <a name="a-nameremovecommandrangehandlera--icommandsourceremovecommandrangehandler"></a><a name="removecommandrangehandler"></a>ICommandSource::RemoveCommandRangeHandler  
 Remove um grupo de manipuladores de comandos de um objeto de fonte de comando.  
  
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
 Esse método Remove um grupo de manipuladores de mensagens, mapeado para o especificado de IDs de comando por `cmdIDMin` e `cmdIDMax`, do objeto de origem de comando.  
  
##  <a name="a-nameremovecommandrangeuihandlera--icommandsourceremovecommandrangeuihandler"></a><a name="removecommandrangeuihandler"></a>ICommandSource::RemoveCommandRangeUIHandler  
 Remove um grupo de manipuladores de mensagens de comando de interface de usuário de um objeto de fonte de comando.  
  
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
 Esse método Remove um grupo de usuário interface comando de manipuladores de mensagens, mapeado para o especificado de IDs de comando por `cmdIDMin` e `cmdIDMax`, do objeto de origem de comando.  
  
##  <a name="a-nameremovecommanduihandlera--icommandsourceremovecommanduihandler"></a><a name="removecommanduihandler"></a>ICommandSource::RemoveCommandUIHandler  
 Remove um manipulador de mensagens de comando de interface de usuário de um objeto de fonte de comando.  
  
```  
void RemoveCommandUIHandler(unsigned int cmdID);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdID`  
 A ID do comando.  
  
### <a name="remarks"></a>Comentários  
 Este método Remove o manipulador de mensagens do usuário interface comando mapeado para `cmdID` do objeto de origem de comando.  
  
##  <a name="a-namesendcommanda--icommandsourcesendcommand"></a><a name="sendcommand"></a>ICommandSource::SendCommand  
 Envia uma mensagem e aguarda até que ele seja processado antes de retornar.  
  
```  
void SendCommand(unsigned int command);
```  
  
### <a name="parameters"></a>Parâmetros  
 `command`  
 A ID de comando da mensagem a ser enviada.  
  
### <a name="remarks"></a>Comentários  
 Esse método envia de forma síncrona a mensagem mapeada para a ID especificada por `command`. Ele chama [CWnd::SendMessage](../../mfc/reference/cwnd-class.md#sendmessage) coloca a mensagem na fila de mensagens e aguarda a janela até que esse procedimento de janela processou a mensagem antes de retornar.  
  
##  <a name="a-nameicommandtargetinterfacea--icommandtarget-interface"></a><a name="icommandtarget_interface"></a>Interface ICommandTarget  
 Fornece um controle de usuário com uma interface para receber comandos de um objeto de origem do comando.  
  
```  
interface class ICommandTarget  
```  
  
### <a name="remarks"></a>Comentários  
 Quando você hospeda um controle de usuário em uma exibição MFC, [CWinFormsView](../../mfc/reference/cwinformsview-class.md) comandos de rotas e atualização de comando mensagens de interface do usuário para o controle de usuário para permitir que ele manipule comandos MFC (por exemplo, itens de menu do quadro e botões de barra de ferramentas). Implementando `ICommandTarget`, você dá o controle de usuário, uma referência ao objeto.  
  
 Consulte [como: Adicionar roteamento de comando para o controle Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `ICommandTarget`.  
  
 Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
##  <a name="a-nameinitializea--icommandtargetinitialize"></a><a name="initialize"></a>ICommandTarget::Initialize  
 Inicializa o objeto de destino de comando.  
  
```  
void Initialize(ICommandSource^ cmdSource);
```  
  
### <a name="parameters"></a>Parâmetros  
 `cmdSource`  
 Um identificador para o objeto de origem do comando.  
  
### <a name="remarks"></a>Comentários  
 Quando você hospeda um controle de usuário em uma exibição MFC, [CWinFormsView](../../mfc/reference/cwinformsview-class.md) comandos de rotas e atualização de comando mensagens de interface do usuário para o controle de usuário para permitir que lidar com comandos do MFC.  
  
 Esse método inicializa o objeto de destino de comando e associa o objeto de origem do comando especificado `cmdSource`. Ele deve ser chamado na implementação de classe do controle de usuário. Na inicialização, você deve registrar manipuladores de comandos com o objeto de origem do comando chamando [ICommandSource::AddCommandHandler](../../mfc/reference/icommandsource-interface.md) no `Initialize` implementação. Consulte [como: Adicionar roteamento de comando para o controle Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `Initialize` para fazer isso.  
  
##  <a name="a-nameicommanduiinterfacea--icommandui-interface"></a><a name="icommandui_interface"></a>Interface ICommandUI  
 Gerencia os comandos de interface do usuário.  
  
```  
interface class ICommandUI  
```  
  
### <a name="remarks"></a>Comentários  
 Essa interface fornece métodos e propriedades que gerenciam os comandos de interface do usuário. `ICommandUI`é semelhante ao [classe CCmdUI](../../mfc/reference/ccmdui-class.md), exceto que `ICommandUI` é usado para aplicativos MFC que interoperam com componentes do .NET.  
  
 `ICommandUI`é usada dentro de uma `ON_UPDATE_COMMAND_UI` manipulador em-classe derivada. Quando um usuário de um aplicativo ativa (seleciona ou cliques) um menu, cada item de menu é exibido como habilitado ou desabilitado. O destino de cada comando de menu fornece essas informações ao implementar um `ON_UPDATE_COMMAND_UI` manipulador. Para cada um dos objetos de interface do usuário de comando em seu aplicativo, use a janela Propriedades para criar uma entrada de mapa da mensagem e o protótipo de função para cada manipulador.  
  
 Para obter mais informações sobre como o `ICommandUI` interface é usada no roteamento de comando, consulte [como: Adicionar roteamento de comando para o controle Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md).  
  
 Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
 Para obter mais informações sobre como os comandos da interface de usuário são gerenciados no MFC, consulte [classe CCmdUI](../../mfc/reference/ccmdui-class.md).  
  
##  <a name="a-namechecka--icommanduicheck"></a><a name="check"></a>ICommandUI::Check  
 Define o item de interface do usuário para esse comando para o estado de seleção apropriadas.  
  
```  
property UICheckState Check;  
```  
  
### <a name="remarks"></a>Comentários  
 Essa propriedade define o item de interface do usuário para esse comando para o estado de seleção apropriadas. Defina `Check` com os seguintes valores:  
  
|Termo|Definição|  
|----------|----------------|  
|0|Desmarcar|  
|1|Marcar|  
|2|Definir indeterminada|  
  
##  <a name="a-namecontinueroutinga--icommanduicontinuerouting"></a><a name="continuerouting"></a>ICommandUI::ContinueRouting  
 Informa ao mecanismo de roteamento de comando para continuar a rotear a mensagem atual a cadeia de manipuladores.  
  
```  
void ContinueRouting();
```  
  
### <a name="remarks"></a>Comentários  
 Essa é uma função de membro avançado que deve ser usada em conjunto com um [ON_COMMAND_EX](http://msdn.microsoft.com/library/0bb49090-aee8-4203-87c8-dd001d3dd26e) manipulador retorna `FALSE`. Para obter mais informações, consulte a nota técnica [TN006: mapas de mensagem](../../mfc/tn006-message-maps.md).  
  
##  <a name="a-nameenableda--icommanduienabled"></a><a name="enabled"></a>ICommandUI::Enabled  
 Habilita ou desabilita o item de interface do usuário para este comando.  
  
```  
property bool Enabled;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta propriedade habilita ou desabilita o item de interface do usuário para este comando. Definir `Enabled` para `TRUE` para habilitar o item `FALSE` para desabilitá-lo.  
  
##  <a name="a-nameida--icommanduiid"></a><a name="id"></a>ICommandUI::ID  
 Obtém a ID do objeto de interface do usuário representado pelo `ICommandUI` objeto.  
  
```  
property unsigned int ID;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta propriedade obtém a ID (um identificador) do item de menu, botão da barra de ferramentas, ou outro objeto de interface do usuário representado pelo `ICommandUI` objeto.  
  
##  <a name="a-nameindexa--icommanduiindex"></a><a name="index"></a>ICommandUI::Index  
 Obtém o índice do objeto de interface do usuário representado pelo `ICommandUI` objeto.  
  
```  
property unsigned int Index;  
```  
  
### <a name="remarks"></a>Comentários  
 Esta propriedade obtém o índice (um identificador) do item de menu, botão da barra de ferramentas, ou outro objeto de interface do usuário representado pelo `ICommandUI` objeto.  
  
##  <a name="a-nameradioa--icommanduiradio"></a><a name="radio"></a>ICommandUI::Radio  
 Define o item de interface do usuário para esse comando para o estado de seleção apropriadas.  
  
```  
property bool Radio;  
```  
  
### <a name="remarks"></a>Comentários  
 Essa propriedade define o item de interface do usuário para esse comando para o estado de seleção apropriadas. Definir `Radio` para `TRUE` para habilitar o item; caso contrário, `FALSE`.  
  
##  <a name="a-nametexta--icommanduitext"></a><a name="text"></a>ICommandUI::Text  
 Define o texto do item de interface do usuário para este comando.  
  
```  
property String^ Text;  
```  
  
### <a name="remarks"></a>Comentários  
 Essa propriedade define o texto do item de interface do usuário para este comando. Definir `Text` para um identificador de cadeia de caracteres de texto.  
  
##  <a name="a-nameiviewinterfacea--iview-interface"></a><a name="iview_interface"></a>Interface IView  
 Implementa vários métodos que [CWinFormsView](../../mfc/reference/cwinformsview-class.md) usa para enviar notificações de exibição para um controle gerenciado.  
  
```  
interface class IView  
```  
  
### <a name="remarks"></a>Comentários  
 `IView`implementa vários métodos que `CWinFormsView` usa para encaminhar notificações de exibição comuns para um controle gerenciado hospedado. Esses são [OnInitialUpdate](../../mfc/reference/iview-interface.md), [OnUpdate](../../mfc/reference/iview-interface.md) e [OnActivateView](../../mfc/reference/iview-interface.md).  
  
 `IView`é semelhante ao [CView](../../mfc/reference/cview-class.md), mas é usado somente com os modos de exibição gerenciados e controles.  
  
 Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
##  <a name="a-nameonactivateviewa--iviewonactivateview"></a><a name="onactivateview"></a>IView::OnActivateView  
 Chamado pelo MFC quando uma exibição é ativada ou desativada.  
  
```  
void OnActivateView(bool activate);
```  
  
### <a name="parameters"></a>Parâmetros  
 `activate`  
 Indica se o modo de exibição está sendo ativada ou desativada.  
  
##  <a name="a-nameoninitialupdatea--iviewoninitialupdate"></a><a name="oninitialupdate"></a>IView::OnInitialUpdate  
 Chamado pela estrutura depois que o modo de exibição é anexado ao documento pela primeira vez, mas antes que o modo de exibição é exibido inicialmente.  
  
```  
void OnInitialUpdate();
```  
  
##  <a name="a-nameonupdatea--iviewonupdate"></a><a name="onupdate"></a>IView::OnUpdate  
 Chamado pelo MFC depois que o documento da exibição foi modificado.  
  
```  
void OnUpdate();
```  
  
### <a name="remarks"></a>Comentários  
 Essa função permite que o modo de exibição atualizar sua exibição para refletir as modificações.  
  
## <a name="see-also"></a>Consulte também  
 [Exemplo MFC COLETAR](../../visual-cpp-samples.md)   
 [Classe CObject](../../mfc/reference/cobject-class.md)   
 [Gráfico de hierarquia](../../mfc/hierarchy-chart.md)




