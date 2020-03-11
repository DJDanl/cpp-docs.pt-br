---
title: Interface ICommandUI
ms.date: 09/07/2019
f1_keywords:
- ICommandUI
- AFXWINFORMS/ICommandUI
- AFXWINFORMS/icommandui__Check
- AFXWINFORMS/ICommandUI::ContinueRouting
- AFXWINFORMS/ICommandUI::Enabled
- AFXWINFORMS/ICommandUI::ID
- AFXWINFORMS/ICommandUI::Index
- AFXWINFORMS/ICommandUI::Radio
- AFXWINFORMS/ICommandUI::Text
helpviewer_keywords:
- ICommandUI interface [MFC]
ms.assetid: 134afe8d-dcdf-47ca-857a-a166a6b665dd
ms.openlocfilehash: a7bb3ab5ed292cef8108e937e67bc9e2ccc1ebce
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78866575"
---
# <a name="icommandui-interface"></a>Interface ICommandUI

Gerencia comandos da interface do usuário.

## <a name="syntax"></a>Sintaxe

```
interface class ICommandUI
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|DESCRIÇÃO|
|----------|-----------------|
|[icommandui__Check](#check)|Define o item de interface do usuário para esse comando para o estado de verificação apropriado.|
|[ICommandUI::ContinueRouting](#continuerouting)|Informa ao mecanismo de roteamento de comandos para continuar a rotear a mensagem atual para baixo na cadeia de manipuladores.|
|[ICommandUI:: habilitado](#enabled)|Habilita ou desabilita o item de interface do usuário para este comando.|
|[ICommandUI:: ID](#id)|Obtém a ID do objeto da interface do usuário representado pelo objeto `ICommandUI`.|
|[ICommandUI:: index](#index)|Obtém o índice do objeto da interface do usuário representado pelo objeto `ICommandUI`.|
|[ICommandUI:: Radio](#radio)|Define o item de interface do usuário para esse comando para o estado de verificação apropriado.|
|[ICommandUI:: texto](#text)|Define o texto do item de interface do usuário para este comando.|

## <a name="remarks"></a>Comentários

Essa interface fornece métodos e propriedades que gerenciam comandos de interface do usuário. `ICommandUI` é semelhante à [classe CCmdUI](../../mfc/reference/ccmdui-class.md), exceto que `ICommandUI` é usado para aplicativos MFC que interoperam com componentes .net.

`ICommandUI` é usado dentro de um manipulador de ON_UPDATE_COMMAND_UI em uma classe derivada de [ICommandTarget](../../mfc/reference/icommandtarget-interface.md). Quando um usuário de um aplicativo é ativado (seleciona ou clica em) um menu, cada item de menu é exibido como habilitado ou desabilitado. O destino de cada comando de menu fornece essas informações implementando um manipulador de ON_UPDATE_COMMAND_UI. Para cada um dos objetos de interface do usuário de comando em seu aplicativo, use o [Assistente de classe](mfc-class-wizard.md) para criar uma entrada de mapa de mensagem e um protótipo de função para cada manipulador.

Para obter mais informações sobre como a interface de `ICommandUI` é usada no roteamento de comandos, consulte [como: Adicionar roteamento de comando ao controle de Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md).

Para obter mais informações sobre como usar Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

Para obter mais informações sobre como os comandos da interface do usuário são gerenciados no MFC, consulte [classe CCmdUI](../../mfc/reference/ccmdui-class.md).

## <a name="check"></a>ICommandUI:: verificar

Define o item de interface do usuário para esse comando para o estado de verificação apropriado.
```
property UICheckState Check;
```

## <a name="remarks"></a>Comentários

Essa propriedade define o item de interface do usuário para esse comando para o estado de verificação apropriado. Defina verificar para os seguintes valores:
- 0 desmarcar
- 1 verificação
- 2 definir indeterminado

## <a name="continuerouting"></a>ICommandUI::ContinueRouting

Informa ao mecanismo de roteamento de comando para continuar a rotear a mensagem atual para baixo na cadeia de manipuladores.
```
void ContinueRouting();
```

## <a name="remarks"></a>Comentários

Essa é uma função de membro avançada que deve ser usada em conjunto com um manipulador de ON_COMMAND_EX que retorna FALSE. Para obter mais informações, consulte a observação técnica TN006: mapas de mensagem.

## <a name="enabled"></a>ICommandUI:: habilitado

Habilita ou desabilita o item de interface do usuário para este comando.
```
property bool Enabled;
```

## <a name="remarks"></a>Comentários

Essa propriedade habilita ou desabilita o item de interface do usuário para este comando. Defina habilitado como verdadeiro para habilitar o item, FALSE para desabilitá-lo.

## <a name="id"></a>ICommandUI:: ID

Obtém a ID do objeto da interface do usuário representado pelo objeto ICommandUI.
```
property unsigned int ID;
```

## <a name="remarks"></a>Comentários

Essa propriedade Obtém a ID (um identificador) do item de menu, botão da barra de ferramentas ou outro objeto de interface do usuário representado pelo objeto ICommandUI.

## <a name="index"></a>ICommandUI:: index

Obtém o índice do objeto da interface do usuário representado pelo objeto ICommandUI.
```
property unsigned int Index;
```

## <a name="remarks"></a>Comentários

Essa propriedade Obtém o índice (um identificador) do item de menu, botão da barra de ferramentas ou outro objeto de interface do usuário representado pelo objeto ICommandUI.

## <a name="radio"></a>ICommandUI:: Radio

Define o item de interface do usuário para esse comando para o estado de verificação apropriado.
```
property bool Radio;
```

## <a name="remarks"></a>Comentários

Essa propriedade define o item de interface do usuário para esse comando para o estado de verificação apropriado. Defina Radio como TRUE para habilitar o item; caso contrário, FALSE.

## <a name="text"></a>ICommandUI:: texto

Define o texto do item de interface do usuário para este comando.
```
property String^ Text;
```

## <a name="remarks"></a>Comentários

Essa propriedade define o texto do item de interface do usuário para este comando. Defina texto como um identificador de cadeia de caracteres de texto.

## <a name="requirements"></a>Requisitos

**Header:** afxwinforms. h (definido no assembly atlmfc\lib\mfcmifc80.dll)

## <a name="see-also"></a>Confira também

[Classe CCmdUI](../../mfc/reference/ccmdui-class.md)
