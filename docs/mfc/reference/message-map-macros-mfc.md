---
title: Macros de mapa (MFC) da mensagem | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.mfc.messages
dev_langs:
- C++
helpviewer_keywords:
- message map macros
- Windows messages [C++], declaration
- demarcating Windows messages
- message maps [C++], macros
- message maps [C++], declaration and demarcation
- message mapping macros
- ranges, message map
- message map ranges
ms.assetid: 531b15ce-32b5-4ca0-a849-bb519616c731
caps.latest.revision: 10
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
ms.sourcegitcommit: d4b97ed874b145f9c6d9a9536476243bba0fd1c1
ms.openlocfilehash: 0c5856dce919ca8ea2d396fbf2523dc45409b519
ms.lasthandoff: 03/06/2017

---
# <a name="message-map-macros-mfc"></a>Macros de mapa de mensagem (MFC)
Para oferecer suporte a mapas de mensagem, o MFC fornece as seguintes macros:  
  
### <a name="message-map-declaration-and-demarcation-macros"></a>Mapa de mensagem declaração e demarcação Macros  
  
|||  
|-|-|  
|[DECLARE_MESSAGE_MAP](#declare_message_map)|Declara que um mapa da mensagem será usado em uma classe para mapear mensagens para funções (deve ser usado na declaração da classe).|  
|[BEGIN_MESSAGE_MAP](#begin_message_map)|Começa a definição de um mapa de mensagem (deve ser usado na implementação da classe).|  
|[END_MESSAGE_MAP](#end_message_map)|Termina a definição de um mapa de mensagem (deve ser usado na implementação da classe).|  
  
### <a name="message-mapping-macros"></a>Macros de mapeamento de mensagem  
  
|||  
|-|-|  
|[ON_COMMAND](#on_command)|Indica qual função tratará uma mensagem de comando especificado.|  
|[ON_CONTROL](#on_control)|Indica qual função tratará uma mensagem de notificação do controle especificado.|  
|[ON_MESSAGE](#on_message)|Indica qual função tratará uma mensagem definida pelo usuário.|  
|[ON_OLECMD](#on_olecmd)|Indica qual função irá manipular um comando de menu de um DocObject ou em seu contêiner.|  
|[ON_REGISTERED_MESSAGE](#on_registered_message)|Indica qual função tratará uma mensagem registrada definidos pelo usuário.|  
|[ON_REGISTERED_THREAD_MESSAGE](#on_registered_thread_message)|Indica qual função tratará uma mensagem registrada definida pelo usuário quando você tem um `CWinThread` classe.|  
|[ON_THREAD_MESSAGE](#on_thread_message)|Indica qual função tratará uma mensagem definida pelo usuário quando você tem um `CWinThread` classe.|  
|[ON_UPDATE_COMMAND_UI](#on_update_command_ui)|Indica qual função tratará uma mensagem de comando de atualização de interface do usuário especificado.|  
  
### <a name="message-map-range-macros"></a>Macros de intervalo de mapa de mensagem  
  
|||  
|-|-|  
|[ON_COMMAND_RANGE](#on_command_range)|Indica qual função tratará o intervalo de IDs de comando especificadas nos dois primeiros parâmetros para a macro.|  
|[ON_UPDATE_COMMAND_UI_RANGE](#on_update_command_ui_range)|Indica qual manipulador de atualização tratará o intervalo de IDs de comando especificado no pa duas primeiras] parâ à macro.|  
|[ON_CONTROL_RANGE](#on_control_range)|Indica qual função manipulará notificações do intervalo de IDs especificadas no segundo e terceiro parâmetros para a macro do controle. O primeiro parâmetro é uma mensagem de notificação de controle, como **BN_CLICKED**.|  
  
 Para obter mais informações sobre mapas de mensagem, a declaração de mapa de mensagem e macros demarcação e as macros de mapeamento de mensagem, consulte [mapas de mensagem](../../mfc/reference/message-maps-mfc.md) e [tópicos de mapeamento e tratamento de mensagem](../../mfc/message-handling-and-mapping.md). Para obter mais informações sobre intervalos de mapas de mensagem, consulte [manipuladores para intervalos de mapas de mensagem](../../mfc/handlers-for-message-map-ranges.md).  

## <a name="declare_message_map"></a>DECLARE_MESSAGE_MAP
 Declara que a classe define um mapa da mensagem. Cada `CCmdTarget`-classe derivada em seu programa deve fornecer um mapa da mensagem para lidar com mensagens.  
  
### <a name="syntax"></a>Sintaxe  
  
```    
DECLARE_MESSAGE_MAP( )  
```  
  
### <a name="remarks"></a>Comentários  
 Use o `DECLARE_MESSAGE_MAP` macro no final da sua declaração de classe. Em seguida, no arquivo. cpp que define as funções de membro da classe, use o `BEGIN_MESSAGE_MAP` macro, entradas de macro para cada uma de suas funções de manipulador de mensagens e o `END_MESSAGE_MAP` macro.  
  
> [!NOTE]
>  Se você declarar qualquer membro após `DECLARE_MESSAGE_MAP`, você deve especificar um novo tipo de acesso (**pública**, `private`, ou `protected`) para eles.  
  
 Para obter mais informações sobre mensagens mapeia e `DECLARE_MESSAGE_MAP` macro, consulte [tópicos de mapeamento e tratamento de mensagem](../../mfc/message-handling-and-mapping.md).  
  
### <a name="example"></a>Exemplo  
```cpp  
class CMainFrame : public CMDIFrameWnd
{
   DECLARE_MESSAGE_MAP()

   // Remainder of class declaration omitted.
``` 
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  

## <a name="begin_message_map"></a>BEGIN_MESSAGE_MAP
Começa a definição de seu mapa de mensagem.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
BEGIN_MESSAGE_MAP( theClass, baseClass )  
```  
  
### <a name="parameters"></a>Parâmetros  
 `theClass`  
 Especifica o nome da classe cuja mensagem mapear isso.  
  
 `baseClass`  
 Especifica o nome da classe base da `theClass`.  
  
### <a name="remarks"></a>Comentários  
 No arquivo de implementação (. cpp) que define as funções de membro da sua classe, inicie o mapa da mensagem com o `BEGIN_MESSAGE_MAP` macro, em seguida, adicionar entradas de macro para cada uma de suas funções de manipulador de mensagens e concluir o mapa da mensagem com o `END_MESSAGE_MAP` macro.  
  
 Para obter mais informações sobre mapas de mensagem, consulte [mapas de mensagem](message-maps-mfc.md)  
  
### <a name="example"></a>Exemplo  
```cpp  
BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
   ON_WM_CREATE()
END_MESSAGE_MAP()
```
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h 

## <a name="end_message_map"></a>END_MESSAGE_MAP
Termina a definição de seu mapa de mensagem.  
  
### <a name="syntax"></a>Sintaxe  
  
```   
END_MESSAGE_MAP( )  
```  
  
### <a name="remarks"></a>Comentários  
 Para obter mais informações sobre mensagens mapeia e `END_MESSAGE_MAP` macro, consulte [tópicos de mapeamento e tratamento de mensagem](../../mfc/message-handling-and-mapping.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwin. h  

## <a name="on_command"></a>ON_COMMAND
Essa macro mapeia uma mensagem de comando para uma função de membro.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ON_COMMAND( id, memberFxn )  
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 A ID do comando.  
  
 `memberFxn`  
 O nome da função de manipulador de mensagens para o qual o comando é mapeado.  
  
### <a name="remarks"></a>Comentários  
 Indica qual função tratará uma mensagem de comando de um objeto de interface do usuário de comando como um botão de barra de ferramentas ou item de menu.  
  
 Quando um objeto de destino do comando recebe um Windows **WM_COMMAND** mensagem com a ID especificada, `ON_COMMAND` chamará a função de membro `memberFxn` para manipular a mensagem.  
  
 Use `ON_COMMAND` para mapear um único comando para uma função de membro. Use [ON_COMMAND_RANGE](#on_command_range) para mapear um intervalo de ids de comando para a função de um membro. Apenas uma entrada de mapa da mensagem pode corresponder a uma id de comando especificado. Ou seja, você não pode mapear um comando para mais de um manipulador. Para obter mais informações e exemplos, consulte [tópicos de mapeamento e tratamento de mensagem](../../mfc/message-handling-and-mapping.md).  
  
### <a name="example"></a>Exemplo  
```cpp  
BEGIN_MESSAGE_MAP(CMFCListViewDoc, CDocument)
   ON_COMMAND(ID_MYCOMMAND, &CMFCListViewDoc::OnMycommand)
END_MESSAGE_MAP()
``` 
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmsg_.h  
  
## <a name="on_control"></a>ON_CONTROL
Indica qual função tratará uma mensagem de notificação do controle personalizado.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ON_CONTROL( wNotifyCode, id, memberFxn )  
```  
  
### <a name="parameters"></a>Parâmetros  
 `wNotifyCode`  
 O código de notificação do controle.  
  
 `id`  
 A ID do comando.  
  
 `memberFxn`  
 O nome da função de manipulador de mensagens para o qual o comando é mapeado.  
  
### <a name="remarks"></a>Comentários  
 Mensagens de notificação de controle são aquelas enviadas por um controle à sua janela pai.  
  
 Deve haver exatamente um `ON_CONTROL` instrução de macro em seu mapa de mensagens para cada mensagem de notificação do controle deve ser mapeado para uma função de manipulador de mensagens.  
  
 Para obter mais informações e exemplos, consulte [tópicos de mapeamento e tratamento de mensagem](../../mfc/message-handling-and-mapping.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmsg_.h  
  

## <a name="on_message"></a>ON_MESSAGE  
Indica qual função tratará uma mensagem definida pelo usuário.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ON_MESSAGE( message, memberFxn )  
```  
  
### <a name="parameters"></a>Parâmetros  
 `message`  
 A ID da mensagem.  
  
 `memberFxn`  
 O nome da função de manipulador de mensagens ao qual a mensagem está mapeada.  
  
 O tipo da função deve ser `afx_msg LRESULT (CWnd::*)(WPARAM, LPARAM)`.  
  
### <a name="remarks"></a>Comentários  
 Mensagens definidas pelo usuário são as mensagens que não são padrão do Windows `WM_MESSAGE` mensagens. Ao selecionar uma ID de mensagem, você deve usar valores dentro do intervalo de `WM_USER` (0x0400) para 0x7FFF ou `WM_APP` (0x8000) para 0xBFFF. Para obter mais informações sobre identificações de mensagem, consulte [WM_APP](http://msdn.microsoft.com/library/windows/desktop/ms644930).  
  
 Deve haver exatamente um `ON_MESSAGE` instrução de macro em seu mapa de mensagens para cada mensagem definida pelo usuário que deve ser mapeado para uma função de manipulador de mensagens.  
  
> [!NOTE]
>  Além de mensagens definidas pelo usuário, `ON_MESSAGE` manipula mensagens menos comuns do Windows. Para obter mais informações, consulte o artigo [99848: INFO: Use ON_MESSAGE() Macro mapa menos comuns mensagens](http://go.microsoft.com/fwlink/?linkId=192022).  
  
 Para obter mais informações e exemplos, consulte [tópicos de mapeamento e tratamento de mensagem](../../mfc/message-handling-and-mapping.md) e [manipuladores definidos pelo usuário](user-defined-handlers.md)  
  
### <a name="example"></a>Exemplo  
```cpp  
#define WM_MYMESSAGE (WM_USER + 100)

BEGIN_MESSAGE_MAP(CMyWnd2, CWnd)
   ON_MESSAGE(WM_MYMESSAGE, OnMyMessage)
END_MESSAGE_MAP()

// inside the class declaration
 afx_msg LRESULT OnMyMessage(WPARAM wParam, LPARAM lParam);

 LRESULT CMyWnd2::OnMyMessage(WPARAM wParam, LPARAM lParam)
{
   UNREFERENCED_PARAMETER(wParam);
   UNREFERENCED_PARAMETER(lParam);

   // Handle message here. 

   return 0;
}
```   
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmsg_.h  

## <a name="on_olecmd"></a>ON_OLECMD    
Roteia comandos por meio da interface de envio do comando `IOleCommandTarget`.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ON_OLECMD( pguid, olecmdid, id )  
```  
  
### <a name="parameters"></a>Parâmetros  
 `pguid`  
 Identificador do grupo de comando ao qual pertence o comando. Use **nulo** para o grupo padrão.  
  
 *olecmdid*  
 O identificador do comando OLE.  
  
 `id`  
 A ID do menu, ID de barra de ferramentas, button ID ou outra ID de recurso ou objeto emitindo o comando.  
  
### <a name="remarks"></a>Comentários  
 `IOleCommandTarget`permite que um contêiner para receber comandos originadas na interface do usuário do DocObject e permite que o contêiner enviar os mesmos comandos (como novo, abrir, salvar como e imprimir no menu Arquivo; e copiar, colar, desfazer, e assim por diante no menu Editar) para um DocObject.  
  
 `IOleCommandTarget`é mais simples do que a automação OLE `IDispatch`. `IOleCommandTarget`se baseia inteiramente em um conjunto padrão de comandos que raramente têm argumentos, e nenhuma informação de tipo está envolvida (segurança de tipo é reduzida para argumentos de comando também). Se você precisar enviar comandos com argumentos, use [COleServerDoc::OnExecOleCmd](coleserverdoc-class.md#onexecolecmd).  
  
 O `IOleCommandTarget` comandos de menu padrão foram implementados pelo MFC em macros a seguir:  
  
 **(ON_OLECMD_CLEARSELECTION)**  
  
 Envia o comando Editar Clear. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_CLEARSELECTION, ID_EDIT_CLEAR)`  
  
 **(ON_OLECMD_COPY)**  
  
 Envia o comando Editar cópia. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_COPY, ID_EDIT_COPY)`  
  
 **(ON_OLECMD_CUT)**  
  
 Envia o comando Editar recortar. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_CUT, ID_EDIT_CUT)`  
  
 **(ON_OLECMD_NEW)**  
  
 Envia o comando novo arquivo. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_NEW, ID_FILE_NEW)`  
  
 **(ON_OLECMD_OPEN)**  
  
 Envia o comando Abrir arquivo. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_OPEN, ID_FILE_OPEN)`  
  
 **(ON_OLECMD_PAGESETUP)**  
  
 Envia o comando de configuração de página do arquivo. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_PAGESETUP, ID_FILE_PAGE_SETUP)`  
  
 **(ON_OLECMD_PASTE)**  
  
 Envia o comando Editar colar. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_PASTE, ID_EDIT_PASTE)`  
  
 **(ON_OLECMD_PASTESPECIAL)**  
  
 Envia o comando Editar Colar especial. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_PASTESPECIAL, ID_EDIT_PASTE_SPECIAL)`  
  
 **(ON_OLECMD_PRINT)**  
  
 Envia o comando Imprimir do arquivo. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_PRINT, ID_FILE_PRINT)`  
  
 **(ON_OLECMD_PRINTPREVIEW)**  
  
 Envia o comando de visualização de impressão do arquivo. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_PRINTPREVIEW, ID_FILE_PRINT_PREVIEW)`  
  
 **(ON_OLECMD_REDO)**  
  
 Envia o comando Editar refazer. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_REDO, ID_EDIT_REDO)`  
  
 **(ON_OLECMD_SAVE)**  
  
 Envia o comando Salvar arquivo. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_SAVE, ID_FILE_SAVE)`  
  
 **(ON_OLECMD_SAVE_AS)**  
  
 Envia o comando Salvar como arquivo. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_SAVEAS, ID_FILE_SAVE_AS)`  
  
 **(ON_OLECMD_SAVE_COPY_AS)**  
  
 Envia o comando Arquivo Salvar cópia como. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_SAVECOPYAS, ID_FILE_SAVE_COPY_AS)`  
  
 **(ON_OLECMD_SELECTALL)**  
  
 Envia o comando Editar Selecionar tudo. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_SELECTALL, ID_EDIT_SELECT_ALL)`  
  
 **(ON_OLECMD_UNDO)**  
  
 Envia o comando Desfazer Editar. Implementada como:  
  
 `ON_OLECMD(NULL, OLECMDID_UNDO, ID_EDIT_UNDO)`  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxdocob.h  
  
### <a name="see-also"></a>Consulte também  
 [Classe COleCmdUI](colecmdui-class.md)   
 [COleServerDoc::OnExecOleCmd](coleserverdoc-class.md#onexecolecmd)

## <a name="on_registered_message"></a>ON_REGISTERED_MESSAGE
O Windows **RegisterWindowMessage** função é usada para definir uma nova mensagem de janela é garantida como sendo exclusivo em todo o sistema.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ON_REGISTERED_MESSAGE( nMessageVariable, memberFxn )  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMessageVariable`  
 A variável de ID de mensagem da janela registrado.  
  
 `memberFxn`  
 O nome da função de manipulador de mensagens ao qual a mensagem está mapeada.  
  
### <a name="remarks"></a>Comentários  
 Essa macro indica qual função tratará a mensagem registrada.  
  
 Para obter mais informações e exemplos, consulte [tópicos de mapeamento e tratamento de mensagem](../../mfc/message-handling-and-mapping.md).  
  
### <a name="example"></a>Exemplo  
```cpp  
static UINT NEAR WM_FIND = RegisterWindowMessage(_T("COMMDLG_FIND"));


BEGIN_MESSAGE_MAP(CMyWnd3, CWnd)
   ON_REGISTERED_MESSAGE(WM_FIND, OnFind)
END_MESSAGE_MAP()
```  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmsg_.h  
  
### <a name="see-also"></a>Consulte também  
 [RegisterWindowMessage](http://msdn.microsoft.com/library/windows/desktop/ms644947)   
 [Manipuladores definidos pelo usuário](user-defined-handlers.md)

## <a name="on_registered_thread_message"></a>ON_REGISTERED_THREAD_MESSAGE    
Indica qual função tratará a mensagem registrada pela função RegisterWindowMessage do Windows.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ON_REGISTERED_THREAD_MESSAGE(nMessageVariable, memberFxn )  
```  
  
### <a name="parameters"></a>Parâmetros  
 `nMessageVariable`  
 A variável de ID de mensagem da janela registrado.  
  
 `memberFxn`  
 O nome da função de manipulador de mensagens CWinThread ao qual a mensagem está mapeada.  
  
### <a name="remarks"></a>Comentários  
 RegisterWindowMessage é usado para definir uma nova mensagem de janela é garantida como sendo exclusivo em todo o sistema. ON_REGISTERED_THREAD_MESSAGE deve ser usado em vez de ON_REGISTERED_MESSAGE quando você tem uma classe CWinThread. 
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmsg_.h  

## <a name="on_thread_message"></a>ON_THREAD_MESSAGE    
Indica qual função tratará uma mensagem definida pelo usuário.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ON_THREAD_MESSAGE( message, memberFxn )  
```  
  
### <a name="parameters"></a>Parâmetros  
 `message`  
 A ID da mensagem.  
  
 `memberFxn`  
 O nome do `CWinThread`-mensagem-função de manipulador para o qual o mapeamento da mensagem.  
  
### <a name="remarks"></a>Comentários  
 `ON_THREAD_MESSAGE`deve ser usado em vez de `ON_MESSAGE` quando você tem um `CWinThread` classe. Mensagens definidas pelo usuário são as mensagens que não são padrão do Windows **WM_MESSAGE** mensagens. Deve haver exatamente um `ON_THREAD_MESSAGE` instrução de macro em seu mapa de mensagens para cada mensagem definida pelo usuário que deve ser mapeado para uma função de manipulador de mensagens.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  

## <a name="on_update_command_ui"></a>ON_UPDATE_COMMAND_UI    
Essa macro indica qual função tratará uma mensagem de comando de atualização de interface do usuário.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ON_UPDATE_COMMAND_UI( id, memberFxn )  
```  
  
### <a name="parameters"></a>Parâmetros  
 `id`  
 A ID da mensagem.  
  
 `memberFxn`  
 O nome da função de manipulador de mensagens ao qual a mensagem está mapeada.  
  
### <a name="remarks"></a>Comentários  
 Deve haver exatamente um `ON_UPDATE_COMMAND_UI` instrução de macro em seu mapa de mensagem para cada comando de atualização de interface do usuário que deve ser mapeado para uma função de manipulador de mensagens.  
  
 Para obter mais informações e exemplos, consulte [tópicos de mapeamento e tratamento de mensagem](../../mfc/message-handling-and-mapping.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxole.h  
  
### <a name="see-also"></a>Consulte também  
 [Classe CCmdUI](ccmdui-class.md)

## <a name="on_command_range"></a>ON_COMMAND_RANGE  
Use essa macro para mapear um intervalo contíguo de IDs de comando para uma função de manipulador de mensagem única.  
  
### <a name="syntax"></a>Sintaxe
  
```  
ON_COMMAND_RANGE( id1, id2, memberFxn )  
```  
  
### <a name="parameters"></a>Parâmetros  
 `id1`  
 ID do comando no início de um intervalo contíguo de IDs de comando.  
  
 `id2`  
 ID de comando ao final de um intervalo contíguo de IDs de comando.  
  
 `memberFxn`  
 O nome da função de manipulador de mensagens no qual os comandos são mapeados.  
  
### <a name="remarks"></a>Comentários  
 O intervalo de IDs começa com `id1` e termina com `id2`.  
  
 Use `ON_COMMAND_RANGE` para mapear um intervalo de IDs de comando para a função de um membro. Use [ON_COMMAND](#on_command) para mapear um único comando para uma função de membro. Apenas uma entrada de mapa da mensagem pode corresponder a uma ID de comando especificado. Ou seja, você não pode mapear um comando para mais de um manipulador. Para obter mais informações sobre intervalos de mapeamento de mensagens, consulte [manipuladores para intervalos de mapas de mensagem](../../mfc/handlers-for-message-map-ranges.md).  
  
 Não há nenhum suporte automático para intervalos de mapas de mensagem, portanto você deve colocar a macro.  
  
### <a name="example"></a>Exemplo  
```cpp  
// The code fragment below shows how to use ON_COMMAND_RANGE macro 
// to map a contiguous range of command IDs to a single message  
// handler function (i.e. OnRangeCmds() in the sample below). In  
// addition, it also shows how to use CheckMenuRadioItem() to check a  
// selected menu item and makes it a radio item.

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
   ON_COMMAND_RANGE(ID_COMMAND_RANGECMD1, ID_COMMAND_RANGECMD3, &CChildFrame::OnRangeCmds)
END_MESSAGE_MAP()

void CChildFrame::OnRangeCmds(UINT nID)
{
   CMenu* mmenu = AfxGetMainWnd()->GetMenu();
   CMenu* submenu = mmenu->GetSubMenu(5);
   submenu->CheckMenuRadioItem(ID_COMMAND_RANGECMD1, ID_COMMAND_RANGECMD3, 
      nID, MF_BYCOMMAND);
}
```
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmsg_.h  

## <a name="on_update_command_ui_range"></a>ON_UPDATE_COMMAND_UI_RANGE    
Mapeia um intervalo contíguo de IDs de comando para uma função de manipulador de mensagem única atualização.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ON_UPDATE_COMMAND_UI_RANGE( id1, id2, memberFxn )  
```  
  
### <a name="parameters"></a>Parâmetros  
 `id1`  
 ID do comando no início de um intervalo contíguo de IDs de comando.  
  
 `id2`  
 ID de comando ao final de um intervalo contíguo de IDs de comando.  
  
 `memberFxn`  
 O nome da função de manipulador de mensagens de atualização no qual os comandos são mapeados.  
  
### <a name="remarks"></a>Comentários  
 Manipuladores de mensagens de atualização de atualizar o estado dos itens de menu e botões da barra de ferramentas associada ao comando. O intervalo de IDs começa com `id1` e termina com `id2`.  
  
 Não há nenhum suporte automático para intervalos de mapas de mensagem, portanto você deve colocar a macro.  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmsg_.h  

## <a name="on_control_range"></a>ON_CONTROL_RANGE     
Usar essa macro para mapear um intervalo contíguo de IDs de controle para uma função de manipulador de mensagem única para uma mensagem de notificação do Windows especificada, como **BN_CLICKED**.  
  
### <a name="syntax"></a>Sintaxe  
  
```  
ON_CONTROL_RANGE( wNotifyCode, id1, id2, memberFxn )  
```  
  
### <a name="parameters"></a>Parâmetros  
 `wNotifyCode`  
 O código de notificação para que o manipulador está respondendo.  
  
 `id1`  
 ID do comando no início de um intervalo contíguo de IDs de controle.  
  
 `id2`  
 ID de comando ao final de um intervalo contíguo de IDs de controle.  
  
 `memberFxn`  
 O nome da função de manipulador de mensagens para que os controles são mapeados.  
  
### <a name="remarks"></a>Comentários  
 O intervalo de IDs começa com `id1` e termina com `id2`. O manipulador é chamado para a notificação especificada provenientes de qualquer um dos controles mapeados.  
  
 Não há nenhum suporte automático para intervalos de mapas de mensagem, portanto você deve colocar a macro.  
  
 Para obter mais informações sobre como implementar funções de manipulador para um intervalo de IDs de controle, consulte [manipuladores para intervalos de mapas de mensagem](../../mfc/handlers-for-message-map-ranges.md).  
  
### <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxmsg_.h  
  



