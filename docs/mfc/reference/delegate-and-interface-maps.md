---
title: Macros de mapa de delegados e interface (MFC)
ms.date: 03/30/2017
helpviewer_keywords:
- delegate map macros [MFC]
- event map macros [MFC]
- interface map macros [MFC]
ms.assetid: 3840e642-ff7d-4bdc-998b-c7d8fc50890e
ms.openlocfilehash: e08597d024f5e3a74dcf47363ad3de0aa60cf6c0
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365830"
---
# <a name="delegate-and-interface-map-macros"></a>Macros de mapa de interface e delegado

O MFC suporta essas macros para mapas de delegados e interfaces:

|||
|-|-|
|[BEGIN_DELEGATE_MAP](#begin_delegate_map)|Começa um mapa de delegados.|
|[BEGIN_INTERFACE_MAP](#begin_interface_map)|Começa a definição do mapa interfaced.|
|[Delegado manipulador de comandos](#commandhandler)|Registra métodos de retorno de chamada com uma fonte de comando.  |
|[END_DELEGATE_MAP](#end_delegate_map)|Termina um mapa de delegados.|
|[END_INTERFACE_MAP](#end_interface_map)|Termina o mapa de interface no arquivo de implementação. |
|[EVENT_DELEGATE_ENTRY](#event_delegate_entry)|Cria uma entrada no mapa do delegado.|
|[INTERFACE_PART](#interface_part)|Usado entre a BEGIN_INTERFACE_MAP macro e a macro END_INTERFACE_MAP para cada interface que seu objeto suportará.|
|[MAKE_DELEGATE](#make_delegate)|Anexa um manipulador de eventos a um controle gerenciado.|

## <a name="begin_delegate_map"></a><a name="begin_delegate_map"></a>BEGIN_DELEGATE_MAP

Começa um mapa de delegados.

### <a name="syntax"></a>Sintaxe

```
BEGIN_DELEGATE_MAP(  CLASS );
```

### <a name="parameters"></a>Parâmetros

*Classe*<br/>
A classe em que o controle gerenciado está hospedado.

### <a name="remarks"></a>Comentários

Esta macro marca o início de uma lista de entradas de delegados, que compõem um mapa de delegados. Para um exemplo de como essa macro é usada, consulte [EVENT_DELEGATE_ENTRY](#event_delegate_entry).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** msclr\event.h

## <a name="begin_interface_map"></a><a name="begin_interface_map"></a>Begin_interface_map

Começa a definição do mapa interfacedo quando usado no arquivo de implementação.

### <a name="syntax"></a>Sintaxe

```
BEGIN_INTERFACE_MAP( theClass, baseClass )
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
A classe em que o mapa de interface deve ser definido

*Baseclass*<br/>
A classe da qual *a Classe* deriva.

### <a name="remarks"></a>Comentários

Para cada interface implementada, há uma ou mais INTERFACE_PART invocações macro. Para cada agregado que a classe usa, há uma INTERFACE_AGGREGATE a invocação macro.

Para obter mais informações sobre mapas de interface, consulte [Nota Técnica 38](../tn038-mfc-ole-iunknown-implementation.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="commandhandler-delegate"></a><a name="commandhandler"></a>Delegado manipulador de comandos

Registra métodos de retorno de chamada com uma fonte de comando.

### <a name="syntax"></a>Sintaxe

```
delegate void CommandHandler(  UINT^ cmdID  );
```

### <a name="parameters"></a>Parâmetros

*Cmdid*<br/>
O id de comando.

### <a name="remarks"></a>Comentários

Este delegado registra métodos de retorno de chamada com uma fonte de comando. Quando você adiciona um delegado ao objeto de origem de comando, o método de retorno de chamada torna-se um manipulador para comandos provenientes da fonte especificada.

Para obter mais informações, consulte [Como: Adicionar roteamento de comando ao Controle de Formulários do Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md).

Para obter mais informações sobre o uso do Windows Forms, consulte [Usando um controle de usuário do formulário do Windows no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h (definido em montagem atlmfc\lib\mfcmifc80.dll)

## <a name="commanduihandler"></a><a name="commanduihandler"></a>CommandUIHandler

Registra métodos de retorno de chamada com uma mensagem de comando de atualização da interface do usuário.

### <a name="syntax"></a>Sintaxe

```
delegate void CommandUIHandler(  unsigned int cmdID, ICommandUI^ cmdUI);
```

### <a name="parameters"></a>Parâmetros

*Cmdid*<br/>
O id de comando.

*cmdUI*<br/>
A id da mensagem de comando.

### <a name="remarks"></a>Comentários

Este delegado registra métodos de retorno de chamada com uma mensagem de comando de atualização da interface do usuário. `CommandUIHandler`é semelhante ao [CommandHandler,](#commandhandler) exceto que este delegado é usado com comandos de atualização de objeto da interface do usuário. Os comandos de atualização da interface do usuário devem ser mapeados um para um com métodos de manipulador de mensagens.

Para obter mais informações sobre o uso do Windows Forms, consulte [Usando um controle de usuário do formulário do Windows no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h (definido em montagem atlmfc\lib\mfcmifc80.dll)

## <a name="end_delegate_map"></a><a name="end_delegate_map"></a>END_DELEGATE_MAP

Termina um mapa de delegados.

### <a name="syntax"></a>Sintaxe

```
END_DELEGATE_MAP();
```

### <a name="remarks"></a>Comentários

Esta macro marca o fim de uma lista de entradas de delegados, que compõem um mapa de delegados. Para um exemplo de como essa macro é usada, consulte [EVENT_DELEGATE_ENTRY](#event_delegate_entry).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** msclr\event.h

## <a name="end_interface_map"></a><a name="end_interface_map"></a>End_interface_map

Termina o mapa de interface no arquivo de implementação.

### <a name="syntax"></a>Sintaxe

```
END_INTERFACE_MAP( )
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre mapas de interface, consulte [Nota Técnica 38](../tn038-mfc-ole-iunknown-implementation.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="event_delegate_entry"></a><a name="event_delegate_entry"></a>EVENT_DELEGATE_ENTRY

Cria uma entrada no mapa do delegado.

### <a name="syntax"></a>Sintaxe

```
EVENT_DELEGATE_ENTRY(MEMBER, ARG0, ARG1);
```

### <a name="parameters"></a>Parâmetros

*Membro*<br/>
O método do manipulador de eventos a ser anexado ao controle.

*ARG0*<br/>
O primeiro argumento do método gerenciado de `Object^`manipulador de eventos, tais como .

*ARG1*<br/>
O segundo argumento do método gerenciado de `EventArgs^`manipulador de eventos, tais como .

### <a name="remarks"></a>Comentários

Cada entrada no mapa de delegado corresponde a um delegado gerenciado de manipulador de eventos criado por [MAKE_DELEGATE](#make_delegate).

### <a name="example"></a>Exemplo

O exemplo de código a seguir mostra como usar EVENT_DELEGATE_ENTRY `OnClick` para criar uma entrada no mapa de delegados para o manipulador de eventos; também veja o exemplo de código em MAKE_DELEGATE. Para obter mais informações, consulte [Como: Afundar o Windows Forms Eventos das Classes C++ nativas](../../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md).

```cpp
BEGIN_DELEGATE_MAP(CMyView)
   EVENT_DELEGATE_ENTRY(OnClick, System::Object^, System::EventArgs^)
END_DELEGATE_MAP()
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** msclr\event.h

## <a name="interface_part"></a><a name="interface_part"></a>Interface_part

Usado entre a BEGIN_INTERFACE_MAP macro e a macro END_INTERFACE_MAP para cada interface que seu objeto suportará.

### <a name="syntax"></a>Sintaxe

```
INTERFACE_PART( theClass, iid, localClass)
```

### <a name="parameters"></a>Parâmetros

*Theclass*<br/>
O nome da classe que contém o mapa de interface.
*Iid*<br/>
O IID que deve ser mapeado para a classe incorporada.
*localClass*<br/>
O nome da classe local.

### <a name="remarks"></a>Comentários

Ele permite mapear um IID para um membro da classe indicada *pelo Class* e *localClass*.

Para obter mais informações sobre mapas de interface, consulte [Nota Técnica 38](../tn038-mfc-ole-iunknown-implementation.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwin.h

## <a name="make_delegate"></a><a name="make_delegate"></a>Make_delegate

Anexa um manipulador de eventos a um controle gerenciado.

### <a name="syntax"></a>Sintaxe

```
MAKE_DELEGATE( DELEGATE,  MEMBER) ;
```

### <a name="parameters"></a>Parâmetros

*Delegado*<br/>
O tipo de delegado manipulador de eventos gerenciado, como [EventHandler](/dotnet/api/system.eventhandler).

*Membro*<br/>
O nome do método manipulador de eventos a ser anexado ao controle.

### <a name="remarks"></a>Comentários

Esta macro cria um delegado gerenciado de manipulador de eventos do tipo *DELEGATE* e do nome *MEMBER*. O delegado gerenciado de manipulador de eventos permite que uma classe nativa manuseie eventos gerenciados.

### <a name="example"></a>Exemplo

O exemplo de código `MAKE_DELEGATE` a seguir `OnClick` mostra como ligar `MyControl`para anexar um manipulador de eventos a um controle MFC . Para obter uma explicação mais ampla de como essa macro funciona em um aplicativo MFC, consulte [Como: Afundar o Windows Forms Eventos de Classes C++ nativas](../../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md).

```cpp
// CMyView derives from CWinFormsView.
void CMyView::OnInitialUpdate()
{
   CWinFormsView::OnInitialUpdate();

   GetControl()->Click += MAKE_DELEGATE(System::EventHandler, OnClick);
}
```

### <a name="requirements"></a>Requisitos

**Cabeçalho:** msclr\event.h

## <a name="see-also"></a>Confira também

[Como coletar eventos dos Windows Forms a partir de classes C++ nativas](../../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md)<br/>
[Como adicionar roteamento de comando ao controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)<br/>
[Macros e globais](mfc-macros-and-globals.md)<br/>
