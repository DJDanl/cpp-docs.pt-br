---
title: Interface ICommandUI | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- ICommandUI
dev_langs:
- C++
helpviewer_keywords:
- ICommandUI interface
ms.assetid: 134afe8d-dcdf-47ca-857a-a166a6b665dd
caps.latest.revision: 24
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
ms.openlocfilehash: 1db6b3fa58639140322816c37103566353b15633
ms.lasthandoff: 02/25/2017

---
# <a name="icommandui-interface"></a>Interface ICommandUI
Gerencia os comandos de interface do usuário.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
interface class ICommandUI  
```  
  
## <a name="members"></a>Membros  
  
### <a name="public-methods"></a>Métodos Públicos  
  
|Nome|Descrição|  
|----------|-----------------|  
|[icommandui__Check](#check)|Define o item de interface do usuário para esse comando para o estado de seleção apropriadas.|  
|[ICommandUI::ContinueRouting](#continuerouting)|Informa ao mecanismo de roteamento de comando para continuar a rotear a mensagem atual a cadeia de manipuladores.|  
|[ICommandUI::Enabled](#enabled)|Habilita ou desabilita o item de interface do usuário para este comando.|  
|[ICommandUI::ID](#id)|Obtém a ID do objeto de interface do usuário representado pelo `ICommandUI` objeto.|  
|[ICommandUI::Index](#index)|Obtém o índice do objeto de interface do usuário representado pelo `ICommandUI` objeto.|  
|[ICommandUI::Radio](#radio)|Define o item de interface do usuário para esse comando para o estado de seleção apropriadas.|  
|[ICommandUI::Text](#text)|Define o texto do item de interface do usuário para este comando.|  
  
## <a name="remarks"></a>Comentários  
 Essa interface fornece métodos e propriedades que gerenciam os comandos de interface do usuário. `ICommandUI`é semelhante ao [classe CCmdUI](../../mfc/reference/ccmdui-class.md), exceto que `ICommandUI` é usado para aplicativos MFC que interoperam com componentes do .NET.  
  
 `ICommandUI`é usada dentro de uma `ON_UPDATE_COMMAND_UI` manipulador em um [ICommandTarget](../../mfc/reference/icommandtarget-interface.md)-classe derivada. Quando um usuário de um aplicativo ativa (seleciona ou cliques) um menu, cada item de menu é exibido como habilitado ou desabilitado. O destino de cada comando de menu fornece essas informações ao implementar um `ON_UPDATE_COMMAND_UI` manipulador. Para cada um dos objetos de interface do usuário de comando em seu aplicativo, use a janela Propriedades para criar uma entrada de mapa da mensagem e o protótipo de função para cada manipulador.  
  
 Para obter mais informações sobre como o `ICommandUI` interface é usada no roteamento de comando, consulte [como: Adicionar roteamento de comando para o controle Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md).  
  
 Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).  
  
 Para obter mais informações sobre como os comandos da interface de usuário são gerenciados no MFC, consulte [classe CCmdUI](../../mfc/reference/ccmdui-class.md).  
  
## <a name="a-namechecka-icommanduicheck"></a><a name="check"></a>ICommandUI::Check  
Define o item de interface do usuário para esse comando para o estado de seleção apropriadas.
```
property UICheckState Check;
```
## <a name="remarks"></a>Comentários  
Essa propriedade define o item de interface do usuário para esse comando para o estado de seleção apropriadas. Seleção de conjunto com os seguintes valores:  
- Desmarque&0;  
- 1 verificação  
- 2 definido indeterminada  

## <a name="a-namecontinueroutinga-icommanduicontinuerouting"></a><a name="continuerouting"></a>ICommandUI::ContinueRouting   
Informa ao mecanismo de roteamento de comando para continuar a rotear a mensagem atual a cadeia de manipuladores.
```
void ContinueRouting();
```
## <a name="remarks"></a>Comentários
Essa é uma função de membro avançado que deve ser usada em conjunto com um manipulador ON_COMMAND_EX que retorna FALSE. Para obter mais informações, consulte técnicas Observação TN006: mapas de mensagem.

## <a name="a-nameenableda-icommanduienabled"></a><a name="enabled"></a>ICommandUI::Enabled 
Habilita ou desabilita o item de interface do usuário para este comando.
```
property bool Enabled;
```
## <a name="remarks"></a>Comentários
Esta propriedade habilita ou desabilita o item de interface do usuário para este comando. Defina Enabled como True para habilitar o item, FALSE para desabilitá-lo.

## <a name="a-nameida-icommanduiid"></a><a name="id"></a>ICommandUI::ID  
Obtém a ID do objeto de interface do usuário representado pelo objeto ICommandUI.
```
property unsigned int ID;
```
## <a name="remarks"></a>Comentários
Esta propriedade obtém a ID (um identificador) do item de menu, botão da barra de ferramentas ou outro objeto de interface do usuário representado pelo objeto ICommandUI.

## <a name="a-nameindexa-icommanduiindex"></a><a name="index"></a>ICommandUI::Index   
Obtém o índice do objeto de interface do usuário representado pelo objeto ICommandUI.
```
property unsigned int Index;
```
## <a name="remarks"></a>Comentários
Esta propriedade obtém o índice (um identificador) do item de menu, botão da barra de ferramentas ou outro objeto de interface do usuário representado pelo objeto ICommandUI.

## <a name="a-nameradioa-icommanduiradio"></a><a name="radio"></a>ICommandUI::Radio 
Define o item de interface do usuário para esse comando para o estado de seleção apropriadas.
```
property bool Radio;
```
## <a name="remarks"></a>Comentários
Essa propriedade define o item de interface do usuário para esse comando para o estado de seleção apropriadas. Definir a opção para True para habilitar o item; Caso contrário, FALSE.

## <a name="a-nametexta-icommanduitext"></a><a name="text"></a>ICommandUI::Text 
Define o texto do item de interface do usuário para este comando.
```
property String^ Text;
```
## <a name="remarks"></a>Comentários
Essa propriedade define o texto do item de interface do usuário para este comando. Definir o texto para um identificador de cadeia de caracteres de texto.

## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCmdUI](../../mfc/reference/ccmdui-class.md)

