---
title: ICommandUI Interface
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
ms.openlocfilehash: 335deefc04a80f47151c5d5e71486e30f9918abd
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81356624"
---
# <a name="icommandui-interface"></a>ICommandUI Interface

Gerencia comandos de interface de usuário.

## <a name="syntax"></a>Sintaxe

```
interface class ICommandUI
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[icommandui__Check](#check)|Define o item da interface do usuário para este comando para o estado de verificação apropriado.|
|[ICommandUI::Continuarde](#continuerouting)|Diz ao mecanismo de roteamento de comando para continuar encaminhando a mensagem atual para baixo da cadeia de manipuladores.|
|[ICommandUI::Ativado](#enabled)|Ativa ou desativa o item da interface do usuário para este comando.|
|[iCommandUI::ID](#id)|Obtém o ID do objeto `ICommandUI` de interface do usuário representado pelo objeto.|
|[iCommandUI::Índice](#index)|Obtém o índice do objeto `ICommandUI` de interface do usuário representado pelo objeto.|
|[iCommandUI::Rádio](#radio)|Define o item da interface do usuário para este comando para o estado de verificação apropriado.|
|[iCommandUI::Texto](#text)|Define o texto do item da interface do usuário para este comando.|

## <a name="remarks"></a>Comentários

Esta interface fornece métodos e propriedades que gerenciam comandos de interface do usuário. `ICommandUI`é semelhante à [Classe CCmdUI,](../../mfc/reference/ccmdui-class.md)exceto que `ICommandUI` é usada para aplicações MFC que interoperam com componentes .NET.

`ICommandUI`é usado dentro de um manipulador de ON_UPDATE_COMMAND_UI em uma classe derivada do [ICommandTarget.](../../mfc/reference/icommandtarget-interface.md) Quando um usuário de um aplicativo ativa (seleciona ou clica) um menu, cada item do menu é exibido como ativado ou desativado. O objetivo de cada comando de menu fornece essas informações implementando um manipulador de ON_UPDATE_COMMAND_UI. Para cada um dos objetos de interface do usuário de comando em seu aplicativo, use o [Assistente de Classe](mfc-class-wizard.md) para criar um protótipo de entrada e função de mapa de mensagem para cada manipulador.

Para obter mais `ICommandUI` informações sobre como a interface é usada no roteamento de comandos, consulte [Como: Adicionar roteamento de comando ao Controle de Formulários do Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md).

Para obter mais informações sobre o uso do Windows Forms, consulte [Usando um controle de usuário do formulário do Windows no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

Para obter mais informações sobre como os comandos de interface do usuário são gerenciados no MFC, consulte [CCmdUI Class](../../mfc/reference/ccmdui-class.md).

## <a name="icommanduicheck"></a><a name="check"></a>iCommandUI::Check

Define o item da interface do usuário para este comando para o estado de verificação apropriado.

```
property UICheckState Check;
```

## <a name="remarks"></a>Comentários

Esta propriedade define o item da interface do usuário para este comando para o estado de verificação apropriado. Definir Verificar para os seguintes valores:

- 0 Desmarcar
- 1 Verificar
- 2 Conjunto indeterminado

## <a name="icommanduicontinuerouting"></a><a name="continuerouting"></a>ICommandUI::Continuarde

Diz ao mecanismo de roteamento de comando para continuar encaminhando a mensagem atual para baixo da cadeia de manipuladores.

```
void ContinueRouting();
```

## <a name="remarks"></a>Comentários

Esta é uma função de membro avançado que deve ser usada em conjunto com um manipulador de ON_COMMAND_EX que retorna FALSE. Para obter mais informações, consulte Nota Técnica TN006: Mapas de mensagens.

## <a name="icommanduienabled"></a><a name="enabled"></a>ICommandUI::Ativado

Ativa ou desativa o item da interface do usuário para este comando.

```
property bool Enabled;
```

## <a name="remarks"></a>Comentários

Esta propriedade ativa ou desativa o item da interface do usuário para este comando. Defina 'TRUE' para habilitar o item, FALSE para desativá-lo.

## <a name="icommanduiid"></a><a name="id"></a>iCommandUI::ID

Obtém o ID do objeto de interface do usuário representado pelo objeto ICommandUI.

```
property unsigned int ID;
```

## <a name="remarks"></a>Comentários

Essa propriedade obtém o ID (uma alça) do item do menu, botão da barra de ferramentas ou outro objeto de interface do usuário representado pelo objeto ICommandUI.

## <a name="icommanduiindex"></a><a name="index"></a>iCommandUI::Índice

Obtém o índice do objeto de interface de usuário representado pelo objeto ICommandUI.

```
property unsigned int Index;
```

## <a name="remarks"></a>Comentários

Essa propriedade obtém o índice (uma alça) do item do menu, botão da barra de ferramentas ou outro objeto de interface do usuário representado pelo objeto ICommandUI.

## <a name="icommanduiradio"></a><a name="radio"></a>iCommandUI::Rádio

Define o item da interface do usuário para este comando para o estado de verificação apropriado.

```
property bool Radio;
```

## <a name="remarks"></a>Comentários

Esta propriedade define o item da interface do usuário para este comando para o estado de verificação apropriado. Definir o Rádio como TRUE para habilitar o item; caso contrário, FALSO.

## <a name="icommanduitext"></a><a name="text"></a>iCommandUI::Texto

Define o texto do item da interface do usuário para este comando.

```
property String^ Text;
```

## <a name="remarks"></a>Comentários

Esta propriedade define o texto do item da interface do usuário para este comando. Defina texto como uma alça de seqüência de texto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h (definido em montagem atlmfc\lib\mfcmifc80.dll)

## <a name="see-also"></a>Confira também

[Classe CCmdUI](../../mfc/reference/ccmdui-class.md)
