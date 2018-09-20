---
title: Interface ICommandTarget | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- ICommandTarget
- AFXWINFORMS/ICommandTarget
- AFXWINFORMS/ICommandTarget::Initialize
dev_langs:
- C++
helpviewer_keywords:
- ICommandTarget interface [MFC]
ms.assetid: dd9927f6-3479-4e7c-8ef9-13206cf901f3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 95faae4de2e9fa756a4f69f231839e19019e08fd
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46436800"
---
# <a name="icommandtarget-interface"></a>Interface ICommandTarget

Fornece um controle de usuário com uma interface para receber comandos de um objeto de fonte de comando.

## <a name="syntax"></a>Sintaxe

```
interface class ICommandTarget
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[ICommandTarget::Initialize](#initialize)|Inicializa o objeto de destino do comando.|

## <a name="remarks"></a>Comentários

Ao hospedar um controle de usuário em uma exibição do MFC [CWinFormsView](../../mfc/reference/cwinformsview-class.md) comandos de rotas e atualização de comando mensagens de interface do usuário para o controle de usuário para permitir a manipulação de comandos MFC (por exemplo, itens de menu do quadro e botões da barra de ferramentas). Implementando `ICommandTarget`, você dar o controle de usuário, uma referência para o [ICommandSource](../../mfc/reference/icommandsource-interface.md) objeto.

Ver [como: Adicionar roteamento de comando para o controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md) para obter um exemplo de como usar `ICommandTarget`.

Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)

##  <a name="initialize"></a> ICommandTarget::Initialize

Inicializa o objeto de destino do comando.

```
void Initialize(ICommandSource^ cmdSource);
```

### <a name="parameters"></a>Parâmetros

*cmdSource*<br/>
Um identificador para o objeto de fonte de comando.

### <a name="remarks"></a>Comentários

Ao hospedar um controle de usuário em uma exibição do MFC, CWinFormsView roteia comandos e mensagens de interface do usuário do comando de atualização para o controle de usuário para permitir a manipulação de comandos MFC.

Esse método inicializa o objeto de destino do comando e associa-o a cmdSource de objeto de origem do comando especificado. Ele deve ser chamado na implementação de classe do controle de usuário. Na inicialização, você deve registrar manipuladores de comandos com o objeto de fonte de comando por chamada ICommandSource::AddCommandHandler na implementação de inicialização. Consulte como: Adicionar roteamento de comando para o controle de formulários do Windows para obter um exemplo de como usar a inicialização para fazer isso.

## <a name="see-also"></a>Consulte também

[Como adicionar roteamento de comando ao controle do Windows Forms](../../dotnet/how-to-add-command-routing-to-the-windows-forms-control.md)<br/>
[Interface ICommandSource](../../mfc/reference/icommandsource-interface.md)



