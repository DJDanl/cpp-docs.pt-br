---
title: Interface ICommandUI | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- ICommandUI interface [MFC]
ms.assetid: 134afe8d-dcdf-47ca-857a-a166a6b665dd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cd9ea4397c655f0ebb28d10febe82581d6ad8771
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50055002"
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
|[ICommandUI::ContinueRouting](#continuerouting)|Informa ao mecanismo de roteamento de comando para continua a rotear a mensagem atual a cadeia de manipuladores.|
|[ICommandUI::Enabled](#enabled)|Habilita ou desabilita o item de interface do usuário para esse comando.|
|[ICommandUI::ID](#id)|Obtém a ID do objeto de interface do usuário representado pelo `ICommandUI` objeto.|
|[ICommandUI::Index](#index)|Obtém o índice do objeto de interface do usuário representado pelo `ICommandUI` objeto.|
|[ICommandUI::Radio](#radio)|Define o item de interface do usuário para esse comando para o estado de seleção apropriadas.|
|[ICommandUI::Text](#text)|Define o texto do item de interface de usuário para esse comando.|

## <a name="remarks"></a>Comentários

Essa interface fornece métodos e propriedades que gerenciam os comandos de interface do usuário. `ICommandUI` é semelhante à [classe CCmdUI](../../mfc/reference/ccmdui-class.md), exceto que `ICommandUI` é usado para aplicativos MFC que interoperam com componentes do .NET.

`ICommandUI` é usado dentro de um manipulador ON_UPDATE_COMMAND_UI em uma [ICommandTarget](../../mfc/reference/icommandtarget-interface.md)-classe derivada. Quando um usuário de um aplicativo ativa (seleciona ou cliques) será exibido um menu, cada item de menu como habilitado ou desabilitado. O destino de cada comando de menu fornece essas informações com a implementação de um manipulador de ON_UPDATE_COMMAND_UI. Para cada um dos objetos de interface do usuário de comando em seu aplicativo, use a janela Propriedades para criar uma entrada de mapa de mensagem e o protótipo de função para cada manipulador.

Para obter mais informações sobre como as `ICommandUI` interface é usada no roteamento de comando, consulte [como: Adicionar roteamento de comando para o controle de formulários do Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md).

Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

Para obter mais informações sobre como os comandos de interface do usuário são gerenciados no MFC, consulte [classe CCmdUI](../../mfc/reference/ccmdui-class.md).

## <a name="check"></a> ICommandUI::Check

Define o item de interface do usuário para esse comando para o estado de seleção apropriadas.
```
property UICheckState Check;
```

## <a name="remarks"></a>Comentários

Essa propriedade define o item de interface do usuário para esse comando para o estado de seleção apropriadas. Seleção de conjunto com os seguintes valores:
- Desmarque 0
- 1 verificação
- 2 definido indeterminado

## <a name="continuerouting"></a> ICommandUI::ContinueRouting

Informa ao mecanismo de roteamento de comando para continua a rotear a mensagem atual a cadeia de manipuladores.
```
void ContinueRouting();
```

## <a name="remarks"></a>Comentários

Essa é uma função de membro avançado que deve ser usada em conjunto com um manipulador de ON_COMMAND_EX que retorna FALSE. Para obter mais informações, consulte TN006 de observação técnica: mapas de mensagem.

## <a name="enabled"></a> ICommandUI::Enabled

Habilita ou desabilita o item de interface do usuário para esse comando.
```
property bool Enabled;
```

## <a name="remarks"></a>Comentários

Esta propriedade habilita ou desabilita o item de interface do usuário para esse comando. Defina habilitado para True para habilitar o item, FALSE para desabilitá-lo.

## <a name="id"></a> ICommandUI::ID

Obtém a ID do objeto de interface do usuário representado pelo objeto ICommandUI.
```
property unsigned int ID;
```

## <a name="remarks"></a>Comentários

Essa propriedade obtém a ID (um identificador) do item de menu, botão de barra de ferramentas ou outro objeto de interface do usuário representado pelo objeto ICommandUI.

## <a name="index"></a> ICommandUI::Index

Obtém o índice do objeto de interface do usuário representado pelo objeto ICommandUI.
```
property unsigned int Index;
```

## <a name="remarks"></a>Comentários

Essa propriedade obtém o índice (um identificador) do item de menu, botão de barra de ferramentas ou outro objeto de interface do usuário representado pelo objeto ICommandUI.

## <a name="radio"></a> ICommandUI::Radio

Define o item de interface do usuário para esse comando para o estado de seleção apropriadas.
```
property bool Radio;
```

## <a name="remarks"></a>Comentários

Essa propriedade define o item de interface do usuário para esse comando para o estado de seleção apropriadas. Defina a opção para True para habilitar o item; Caso contrário, FALSE.

## <a name="text"></a> ICommandUI::Text

Define o texto do item de interface de usuário para esse comando.
```
property String^ Text;
```

## <a name="remarks"></a>Comentários

Essa propriedade define o texto do item de interface de usuário para esse comando. Definir o texto a um identificador de cadeia de caracteres de texto.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)

## <a name="see-also"></a>Consulte também

[Classe CCmdUI](../../mfc/reference/ccmdui-class.md)
