---
title: Delegar e macros de mapa de interface (MFC)
ms.date: 03/30/2017
helpviewer_keywords:
- delegate map macros [MFC]
- event map macros [MFC]
- interface map macros [MFC]
ms.assetid: 3840e642-ff7d-4bdc-998b-c7d8fc50890e
ms.openlocfilehash: 8f48b916f7130551fc8d4da5bb2ebc75d8d728d5
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78856657"
---
# <a name="delegate-and-interface-map-macros"></a>Macros de mapa de interface e delegado

O MFC dá suporte a essas macros para mapas de delegados e de interface:

|||
|-|-|
|[BEGIN_DELEGATE_MAP](#begin_delegate_map)|Inicia um mapa delegado.|
|[BEGIN_INTERFACE_MAP](#begin_interface_map)|Inicia a definição do mapa interfigurado.|
|[CommandHandler delegado](#commandhandler)|Registra métodos de retorno de chamada com uma fonte de comando.  |
|[END_DELEGATE_MAP](#end_delegate_map)|Finaliza um mapa de representante.|
|[END_INTERFACE_MAP](#end_interface_map)|Finaliza o mapa de interface no arquivo de implementação. |
|[EVENT_DELEGATE_ENTRY](#event_delegate_entry)|Cria uma entrada no mapa de representante.|
|[INTERFACE_PART](#interface_part)|Usado entre a macro BEGIN_INTERFACE_MAP e a macro END_INTERFACE_MAP para cada interface à qual seu objeto dará suporte.|
|[MAKE_DELEGATE](#make_delegate)|Anexa um manipulador de eventos a um controle gerenciado.|

## <a name="begin_delegate_map"></a>BEGIN_DELEGATE_MAP

Inicia um mapa delegado.

### <a name="syntax"></a>Sintaxe

```
BEGIN_DELEGATE_MAP(  CLASS );
```

### <a name="parameters"></a>Parâmetros

*CLASSES*<br/>
A classe na qual o controle gerenciado está hospedado.

### <a name="remarks"></a>Comentários

Esta macro marca o início de uma lista de entradas delegadas, que compõem um mapa delegado. Para obter um exemplo de como essa macro é usada, consulte [EVENT_DELEGATE_ENTRY](#event_delegate_entry).

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** msclr\event.h

##  <a name="begin_interface_map"></a>BEGIN_INTERFACE_MAP

Inicia a definição do mapa interfigurado quando usado no arquivo de implementação.

### <a name="syntax"></a>Sintaxe

```
BEGIN_INTERFACE_MAP( theClass, baseClass )
```

### <a name="parameters"></a>Parâmetros

*Classe*<br/>
A classe na qual o mapa de interface deve ser definido

*baseClass*<br/>
A classe da qual deriva a *classe* .

### <a name="remarks"></a>Comentários

Para cada interface implementada, há uma ou mais invocações de macro INTERFACE_PART. Para cada agregação que a classe usa, há uma chamada de macro INTERFACE_AGGREGATE.

Para obter mais informações sobre mapas de interface, consulte a [Nota técnica 38](../tn038-mfc-ole-iunknown-implementation.md).

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Afxwin. h

##  <a name="commandhandler"></a>CommandHandler delegado

Registra métodos de retorno de chamada com uma fonte de comando.

### <a name="syntax"></a>Sintaxe

```
delegate void CommandHandler(  UINT^ cmdID  );
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID do comando.

### <a name="remarks"></a>Comentários

Esse delegado registra métodos de retorno de chamada com uma fonte de comando. Quando você adiciona um delegado ao objeto de origem de comando, o método de retorno de chamada torna-se um manipulador para comandos provenientes da origem especificada.

Para obter mais informações, consulte [como: Adicionar roteamento de comando ao controle de Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md).

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Header:** afxwinforms. h (definido no assembly atlmfc\lib\mfcmifc80.dll)

##  <a name="commanduihandler"></a>Comandomanipuladoriu

Registra métodos de retorno de chamada com uma mensagem de comando de atualização de interface do usuário.

### <a name="syntax"></a>Sintaxe

```
delegate void CommandUIHandler(  unsigned int cmdID, ICommandUI^ cmdUI);
```

### <a name="parameters"></a>Parâmetros

*cmdID*<br/>
A ID do comando.

*cmdUI*<br/>
A ID da mensagem de comando.

### <a name="remarks"></a>Comentários

Esse delegado registra métodos de retorno de chamada com uma mensagem de comando de atualização da interface do usuário. `CommandUIHandler` é semelhante a [CommandHandler](#commandhandler) , exceto pelo fato de que esse delegado é usado com comandos de atualização de objeto de interface do usuário. Os comandos de atualização da interface do usuário devem ser mapeados um para um com métodos de manipulador de mensagens.

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Header:** afxwinforms. h (definido no assembly atlmfc\lib\mfcmifc80.dll)

##  <a name="end_delegate_map"></a>END_DELEGATE_MAP

Finaliza um mapa de representante.

### <a name="syntax"></a>Sintaxe

```
END_DELEGATE_MAP();
```

### <a name="remarks"></a>Comentários

Esta macro marca o final de uma lista de entradas delegadas, que compõem um mapa delegado. Para obter um exemplo de como essa macro é usada, consulte [EVENT_DELEGATE_ENTRY](#event_delegate_entry).

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** msclr\event.h

##  <a name="end_interface_map"></a>END_INTERFACE_MAP

Finaliza o mapa de interface no arquivo de implementação.

### <a name="syntax"></a>Sintaxe

```
END_INTERFACE_MAP( )
```

### <a name="remarks"></a>Comentários

Para obter mais informações sobre mapas de interface, consulte a [Nota técnica 38](../tn038-mfc-ole-iunknown-implementation.md).

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Afxwin. h

##  <a name="event_delegate_entry"></a>EVENT_DELEGATE_ENTRY

Cria uma entrada no mapa de representante.

### <a name="syntax"></a>Sintaxe

```
EVENT_DELEGATE_ENTRY(MEMBER, ARG0, ARG1);
```

### <a name="parameters"></a>Parâmetros

*ASSOCIADO*<br/>
O método do manipulador de eventos a ser anexado ao controle.

*ARG0*<br/>
O primeiro argumento do método do manipulador de eventos gerenciado, como `Object^`.

*ARG1*<br/>
O segundo argumento do método do manipulador de eventos gerenciado, como `EventArgs^`.

### <a name="remarks"></a>Comentários

Cada entrada no mapa delegado corresponde a um delegado manipulador de eventos gerenciado criado por [MAKE_DELEGATE](#make_delegate).

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo de código a seguir mostra como usar EVENT_DELEGATE_ENTRY para criar uma entrada no mapa delegado para o manipulador de eventos `OnClick`; Consulte também o exemplo de código em MAKE_DELEGATE. Para obter mais informações, consulte [como coletar eventos de Windows Forms de classes C++ nativas](../../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md).

```cpp
BEGIN_DELEGATE_MAP(CMyView)
   EVENT_DELEGATE_ENTRY(OnClick, System::Object^, System::EventArgs^)
END_DELEGATE_MAP()
```

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** msclr\event.h

##  <a name="interface_part"></a>INTERFACE_PART

Usado entre a macro BEGIN_INTERFACE_MAP e a macro END_INTERFACE_MAP para cada interface à qual seu objeto dará suporte.

### <a name="syntax"></a>Sintaxe

```
INTERFACE_PART( theClass, iid, localClass)
```

### <a name="parameters"></a>Parâmetros

*Classe*<br/>
O nome da classe que contém o mapa de interface.
*IID*<br/>
O IID que deve ser mapeado para a classe inserida.
*localClass*<br/>
O nome da classe local.

### <a name="remarks"></a>Comentários

Ele permite mapear um IID para um membro da classe indicada pela *classe* e *localClass*.

Para obter mais informações sobre mapas de interface, consulte a [Nota técnica 38](../tn038-mfc-ole-iunknown-implementation.md).

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** Afxwin. h

##  <a name="make_delegate"></a>MAKE_DELEGATE

Anexa um manipulador de eventos a um controle gerenciado.

### <a name="syntax"></a>Sintaxe

```
MAKE_DELEGATE( DELEGATE,  MEMBER) ;
```

### <a name="parameters"></a>Parâmetros

*DELEGÁ*<br/>
O tipo do delegado manipulador de eventos gerenciados, como [EventHandler](assetId:///T:System.EventHandler?qualifyHint=False&autoUpgrade=True).

*ASSOCIADO*<br/>
O nome do método do manipulador de eventos a ser anexado ao controle.

### <a name="remarks"></a>Comentários

Esta macro cria um delegado manipulador de eventos gerenciado do tipo *delegate* e do *membro*Name. O delegado manipulador de eventos gerenciados permite que uma classe nativa manipule eventos gerenciados.

### <a name="example"></a>{1&gt;Exemplo&lt;1}

O exemplo de código a seguir mostra como chamar `MAKE_DELEGATE` para anexar um manipulador de eventos de `OnClick` a um controle MFC `MyControl`. Para obter uma explicação mais ampla de como essa macro funciona em um aplicativo MFC, consulte [como coletar eventos de Windows Forms de classes C++ nativas](../../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md).

```cpp
// CMyView derives from CWinFormsView.
void CMyView::OnInitialUpdate()
{
   CWinFormsView::OnInitialUpdate();

   GetControl()->Click += MAKE_DELEGATE(System::EventHandler, OnClick);
}
```

### <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

**Cabeçalho:** msclr\event.h

## <a name="see-also"></a>Consulte também

[Como coletar eventos do Windows Forms de classes C++ nativas](../../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md)<br/>
[Como adicionar roteamento de comando ao controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)<br/>
[Macros e globais](mfc-macros-and-globals.md)<br/>
