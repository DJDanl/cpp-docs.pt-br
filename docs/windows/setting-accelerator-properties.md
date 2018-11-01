---
title: Configurando propriedades do acelerador (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- accelerator properties
- properties [C++], accelerator properties
- Type property
- Key property
- Modifier property
ms.assetid: 0fce9156-3025-4e18-b034-e219a4c65812
ms.openlocfilehash: 47ebd54fdaff099e3a8ce828581a66b0ec871915
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50647012"
---
# <a name="setting-accelerator-properties"></a>Configurando propriedades do acelerador

Você pode definir propriedades do acelerador [janela de propriedades](/visualstudio/ide/reference/properties-window) a qualquer momento. Você também pode usar o **Accelerator** editor para modificar as propriedades de acelerador na tabela de aceleradores. As alterações feitas usando o **propriedades** janela ou o **Accelerator** editor tem o mesmo resultado: as edições são refletidas imediatamente na tabela de aceleradores.

Há três propriedades para cada ID do acelerador:

- O [propriedade de modificador](../windows/accelerator-modifier-property.md) define o controle de combinações de teclas para o acelerador.

   > [!NOTE]
   > No **propriedades** janela, essa propriedade é exibido como três propriedades Boolianas separadas, que pode ser controlada independentemente: **Alt**, **Ctrl**e **Shift**.

- O [propriedade de chave](../windows/accelerator-key-property.md) define a chave real a ser usado como o acelerador.

- O [a propriedade Type](../windows/accelerator-type-property.md) determina se a chave é interpretada como ASCII/ANSI ou de virtual (VIRTKEY).

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Teclas de aceleração predefinidas](../windows/predefined-accelerator-keys.md)<br/>
[Editores de recursos](../windows/resource-editors.md)<br/>
[Editor de aceleradores](../windows/accelerator-editor.md)