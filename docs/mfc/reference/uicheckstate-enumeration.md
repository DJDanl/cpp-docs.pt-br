---
title: Enumeração UICheckState
ms.date: 04/03/2017
f1_keywords:
- afxwinforms/uicheckstate
helpviewer_keywords:
- uicheckstate enumeration [MFC]
ms.assetid: 2ac0098c-20e7-410c-9685-5ead5cb02b63
ms.openlocfilehash: 1411e9b7cb088c063e17cc7c59871e5f0b83ad9c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62309792"
---
# <a name="uicheckstate-enumeration"></a>Enumeração UICheckState

Descreve o estado de seleção de um item de interface do usuário para o comando.

### <a name="syntax"></a>Sintaxe

```
public enum class
{
   [DefaultValue(typeid<Microsoft::VisualC::MFC::UICheckState>, "Checked")]
   Unchecked,
   Checked,
   Indeterminate
};
```

### <a name="remarks"></a>Comentários

[ICommandUI::Check](icommandui-interface.md#check) usa esses valores para descrever o estado de um item de interface do usuário.
Para obter mais informações sobre como usar o Windows Forms, consulte [usando um controle de usuário do Windows Form no MFC](../../dotnet/using-a-windows-form-user-control-in-mfc.md).

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxwinforms.h (definido no assembly atlmfc\lib\mfcmifc80.dll)
