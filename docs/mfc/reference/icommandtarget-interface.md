---
title: Interface ICommandTarget
ms.date: 11/04/2016
f1_keywords:
- ICommandTarget
- AFXWINFORMS/ICommandTarget
- AFXWINFORMS/ICommandTarget::Initialize
helpviewer_keywords:
- ICommandTarget interface [MFC]
ms.assetid: dd9927f6-3479-4e7c-8ef9-13206cf901f3
ms.openlocfilehash: be64f4e0367b9ecc1b24fa96f067f4acd45a9978
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81751458"
---
# <a name="icommandtarget-interface"></a>Interface ICommandTarget

Fornece um controle de usuário com uma interface para receber comandos de um objeto de origem de comando.

## <a name="syntax"></a>Sintaxe

```
interface class ICommandTarget
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[iCommandTarget::Inicializar](#initialize)|Inicializa o objeto alvo de comando.|

## <a name="remarks"></a>Comentários

Quando você hospeda um controle de usuário em uma exibição de MFC, [cWinFormsView](../../mfc/reference/cwinformsview-class.md) roteia comandos e atualiza mensagens de ida de comando para o controle do usuário para permitir que ele manuseie comandos MFC (por exemplo, itens de menu de quadroe botões de barra de ferramentas). Ao `ICommandTarget`implementar, você dá ao controle do usuário uma referência ao objeto [ICommandSource.](../../mfc/reference/icommandsource-interface.md)

[Veja como: Adicionar roteamento de comando ao controle de formulários do Windows](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para um exemplo de como usar `ICommandTarget`.

Para obter mais informações sobre o uso do Windows Forms, consulte [Usando um controle de usuário do formulário do Windows no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h (definido em montagem atlmfc\lib\mfcmifc80.dll)

## <a name="icommandtargetinitialize"></a><a name="initialize"></a>iCommandTarget::Inicializar

Inicializa o objeto alvo de comando.

```cpp
void Initialize(ICommandSource^ cmdSource);
```

### <a name="parameters"></a>Parâmetros

*cmdSource*<br/>
Uma alça para o objeto de origem de comando.

### <a name="remarks"></a>Comentários

Quando você hospeda um controle de usuário em uma exibição de MFC, cWinFormsView roteia comandos e atualiza mensagens de iu de comando para o controle do usuário para permitir que ele manuseie comandos MFC.

Este método inicializa o objeto de destino de comando e o associa ao objeto de origem de comando especificado cmdSource. Ele deve ser chamado na implementação da classe de controle do usuário. Na inicialização, você deve registrar manipuladores de comando com o objeto de origem de comando chamando ICommandSource::AddCommandHandler na implementação Inicialize. Veja Como: Adicionar roteamento de comando ao Controle de Formulários do Windows para um exemplo de como usar o Initialize para fazer isso.

## <a name="see-also"></a>Confira também

[Como adicionar roteamento de comando ao controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)<br/>
[Interface ICommandSource](../../mfc/reference/icommandsource-interface.md)
