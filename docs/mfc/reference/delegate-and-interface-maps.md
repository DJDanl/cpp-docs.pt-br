---
title: Delegado e a Interface mapear Macros (MFC) | Microsoft Docs
ms.custom: ''
ms.date: 03/30/2017
ms.technology:
- cpp-mfc
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- delegate map macros [MFC]
- event map macros [MFC]
- interface map macros [MFC]
ms.assetid: 3840e642-ff7d-4bdc-998b-c7d8fc50890e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a1e6f2e8cc501f9a466e4970d27a2e6ecd9174ca
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
|||  
|-|-|  
|[BEGIN_DELEGATE_MAP](#begin_delegate_map)|Inicia um mapa de delegado.|
|[BEGIN_INTERFACE_MAP](#begin_interface_map)|Começa a definição do mapa interfaced.|
|[Delegado CommandHandler](#commandhandler)|Registra os métodos de retorno de chamada com uma fonte de comando.  |
|[END_DELEGATE_MAP](#end_delegate_map)|Termina um mapa de delegado.|
|[END_INTERFACE_MAP](#end_interface_map)|Termina o mapa de interface no arquivo de implementação. |
|[EVENT_DELEGATE_ENTRY](#event_delegate_entry)|Cria uma entrada no mapa do delegado.|
|[INTERFACE_PART](#interface_part)|Usado entre o `BEGIN_INTERFACE_MAP` macro e `END_INTERFACE_MAP` macro para cada interface que seu objeto oferecerá suporte.|
|[MAKE_DELEGATE](#make_delegate)|Anexa um manipulador de eventos para um controle gerenciado.|


## <a name="begin_delegate_map"></a> BEGIN_DELEGATE_MAP
Inicia um mapa de delegado.  
   
### <a name="syntax"></a>Sintaxe    
```  
BEGIN_DELEGATE_MAP(  CLASS );  
```
### <a name="parameters"></a>Parâmetros  
 `CLASS`  
 A classe em que o controle gerenciado está hospedado.  
   
### <a name="remarks"></a>Comentários  
 Esta macro marca o início de uma lista de entradas de delegado, que compõem um mapa de delegado. Para obter um exemplo de como essa macro é usada, consulte [EVENT_DELEGATE_ENTRY](#event_delegate_entry).  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** msclr\event.h  
   
### <a name="see-also"></a>Consulte também  
 [Como coletar eventos do Windows Forms de classes C++ nativas](../../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md)
 
##  <a name="begin_interface_map"></a>BEGIN_INTERFACE_MAP
Começa a definição do mapa interfaced quando usado no arquivo de implementação.  
   
### <a name="syntax"></a>Sintaxe    
```
BEGIN_INTERFACE_MAP( theClass, baseClass )  
```
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 A classe na qual o mapa de interface é a ser definido  
  
 `baseClass`  
 A classe da qual `theClass` deriva.  
   
### <a name="remarks"></a>Comentários  
 Para cada interface que é implementada, há um ou mais `INTERFACE_PART` invocações de macro. Para cada agregação, que usa a classe, há um **INTERFACE_AGGREGATE** invocação de macro.  
  
 Para obter mais informações sobre mapas de interface, consulte [38 de observação técnica](../tn038-mfc-ole-iunknown-implementation.md).  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
 
##  <a name="commandhandler"></a>Delegado CommandHandler
Registra os métodos de retorno de chamada com uma fonte de comando.  
   
### <a name="syntax"></a>Sintaxe    
```  
delegate void CommandHandler(  UINT^ cmdID  );  
```
### <a name="parameters"></a>Parâmetros  
 `cmdID`  
 A ID de comando.  
   
### <a name="remarks"></a>Comentários  
 Este delegado registra os métodos de retorno de chamada com uma fonte de comando. Quando você adiciona um delegado para o objeto de origem de comando, o método de retorno de chamada se torna um manipulador de comandos provenientes da fonte especificada.  
  
 Para obter mais informações, consulte [como: Adicionar roteamento de comando para o controle de formulários do Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md).  
  
 Para obter mais informações sobre como usar formulários do Windows, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)  
   
### <a name="see-also"></a>Consulte também  
 [Como adicionar roteamento de comando ao controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)
 
##  <a name="commanduihandler"></a>CommandUIHandler
Registra os métodos de retorno de chamada com uma mensagem de comando de atualização de interface do usuário.  
   
### <a name="syntax"></a>Sintaxe    
```  
delegate void CommandUIHandler(  unsigned int cmdID, ICommandUI^ cmdUI);  
```
### <a name="parameters"></a>Parâmetros  
 `cmdID`  
 A ID de comando.  
  
 `cmdUI`  
 A ID de mensagem de comando.  
   
### <a name="remarks"></a>Comentários  
 Este delegado registra os métodos de retorno de chamada com uma mensagem de comando de atualização de interface do usuário. `CommandUIHandler` é semelhante a [CommandHandler](#commandhandler) exceto que este delegado é usado com comandos de atualização do objeto de interface de usuário. Comandos de atualização de interface do usuário devem ser mapeados-para-um com métodos de manipulador de mensagens.  
  
 Para obter mais informações sobre como usar formulários do Windows, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)  
   
### <a name="see-also"></a>Consulte também  
 [Como: adicionar comandos de controle de formulários do roteamento para o Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)   
 [CommandHandler](#commandhandler)

##  <a name="end_delegate_map"></a>END_DELEGATE_MAP
Termina um mapa de delegado.  
   
### <a name="syntax"></a>Sintaxe    
```  
END_DELEGATE_MAP();  
```  
   
### <a name="remarks"></a>Comentários  
 Esta macro marca o final de uma lista de entradas de delegado, que compõem um mapa de delegado. Para obter um exemplo de como essa macro é usada, consulte [EVENT_DELEGATE_ENTRY](#event_delegate_entry).  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** msclr\event.h  
   
### <a name="see-also"></a>Consulte também  

 [Como coletar eventos do Windows Forms de classes C++ nativas](../../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md)

 
##  <a name="end_interface_map"></a>END_INTERFACE_MAP
Termina o mapa de interface no arquivo de implementação.  
   
### <a name="syntax"></a>Sintaxe    
```
END_INTERFACE_MAP( )    
```  
   
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre mapas de interface, consulte [38 de observação técnica](../tn038-mfc-ole-iunknown-implementation.md).  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
   
### <a name="see-also"></a>Consulte também  
 [Macros e globais](mfc-macros-and-globals.md)   
 [BEGIN_INTERFACE_MAP](#begin_interface_map)
 

##  <a name="event_delegate_entry"></a>EVENT_DELEGATE_ENTRY
Cria uma entrada no mapa do delegado.  
   
### <a name="syntax"></a>Sintaxe    
```  
EVENT_DELEGATE_ENTRY(MEMBER, ARG0, ARG1);  
```
### <a name="parameters"></a>Parâmetros  
 `MEMBER`  
 O método do manipulador de eventos a ser anexado ao controle.  
  
 `ARG0`  
 O primeiro argumento do método do manipulador de eventos gerenciados, como **objeto ^**.  
  
 `ARG1`  
 O segundo argumento do método do manipulador de eventos gerenciados, como **EventArgs ^**.  
   
### <a name="remarks"></a>Comentários  
 Cada entrada no mapa de delegado corresponde a um delegado de manipulador de eventos gerenciado criado por [MAKE_DELEGATE](#make_delegate).  
   
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir mostra como usar `EVENT_DELEGATE_ENTRY` para criar uma entrada no mapa do representante para o `OnClick` manipulador de eventos; também consulte o exemplo de código em `MAKE_DELEGATE`. Para obter mais informações, consulte [como: coletor de eventos do Windows Forms de Classes C++ nativas](../../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md).  
  
 ```cpp
BEGIN_DELEGATE_MAP(CMyView)
   EVENT_DELEGATE_ENTRY(OnClick, System::Object^, System::EventArgs^)
END_DELEGATE_MAP()

```  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** msclr\event.h  
   
### <a name="see-also"></a>Consulte também  
 [MAKE_DELEGATE](#make_delegate)   
 [BEGIN_DELEGATE_MAP](#begin_delegate_map)   
 [END_DELEGATE_MAP](#end_delegate_map)
 

##  <a name="interface_part"></a>INTERFACE_PART
Usado entre o `BEGIN_INTERFACE_MAP` macro e `END_INTERFACE_MAP` macro para cada interface que seu objeto oferecerá suporte.  
   
### <a name="syntax"></a>Sintaxe    
```
INTERFACE_PART( theClass, iid, localClass)  
```
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 O nome da classe que contém o mapa de interface.    
 `iid`  
 O IID deve ser mapeada para a classe incorporada.    
 *localClass*  
 O nome da classe local.  
   
### <a name="remarks"></a>Comentários  
 Ele permite que você mapeie um IID para um membro da classe indicado pelo `theClass` e *localClass*.  
  
 Para obter mais informações sobre mapas de interface, consulte [38 de observação técnica](../tn038-mfc-ole-iunknown-implementation.md).  
   
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin.h  
   
 
##  <a name="make_delegate"></a>MAKE_DELEGATE
Anexa um manipulador de eventos para um controle gerenciado.  
   
### <a name="syntax"></a>Sintaxe    
```  
MAKE_DELEGATE( DELEGATE,  MEMBER) ;  
```
### <a name="parameters"></a>Parâmetros  
 `DELEGATE`  
 Delegar o tipo do manipulador de eventos gerenciados, como [EventHandler](assetId:///T:System.EventHandler?qualifyHint=False&autoUpgrade=True).  
  
 `MEMBER`  
 O nome do método do manipulador de eventos a ser anexado ao controle.  
   
### <a name="remarks"></a>Comentários  
 Esta macro cria um delegado de manipulador de eventos gerenciado do tipo `DELEGATE` e do nome `MEMBER`. O delegado de manipulador de eventos gerenciado permite que uma classe nativa manipular eventos gerenciados.  
   
### <a name="example"></a>Exemplo  
 O exemplo de código a seguir mostra como chamar `MAKE_DELEGATE` para anexar um `OnClick` manipulador de eventos para um controle MFC `MyControl`. Para obter uma explicação mais ampla de como essa macro funciona em um aplicativo MFC, consulte [como: coletor de eventos do Windows Forms de Classes C++ nativas](../../dotnet/how-to-sink-windows-forms-events-from-native-cpp-classes.md).  
  
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
   
### <a name="see-also"></a>Consulte também  
 [BEGIN_DELEGATE_MAP](#begin_delegate_map)   
 [END_DELEGATE_MAP](#end_delegate_map)   
 [EVENT_DELEGATE_ENTRY](#event_delegate_entry)
 



