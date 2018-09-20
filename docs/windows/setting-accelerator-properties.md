---
title: Configurando propriedades do acelerador (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- accelerator properties
- properties [C++], accelerator properties
- Type property
- Key property
- Modifier property
ms.assetid: 0fce9156-3025-4e18-b034-e219a4c65812
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 85d32a3dc01f5c0a496e6471472dab1cfafa0ca0
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46437463"
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