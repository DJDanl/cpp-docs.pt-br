---
title: Configurando propriedades do acelerador | Microsoft Docs
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
ms.openlocfilehash: 7d329d902014b3dff6f66fd6e3f1877a3bc70822
ms.sourcegitcommit: 38af5a1bf35249f0a51e3aafc6e4077859c8f0d9
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/09/2018
ms.locfileid: "40016246"
---
# <a name="setting-accelerator-properties"></a>Configurando propriedades do acelerador
Você pode definir propriedades do acelerador [janela de propriedades](/visualstudio/ide/reference/properties-window) a qualquer momento. Você também pode usar o **Accelerator** editor para modificar as propriedades de acelerador na tabela de aceleradores. As alterações feitas usando o **propriedades** janela ou o **Accelerator** editor tem o mesmo resultado: as edições são refletidas imediatamente na tabela de aceleradores.  
  
 Há três propriedades para cada Acelerador [ID](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/3487f185-de96-4b1d-87db-034a52223160):  
  
-   O [propriedade de modificador](../windows/accelerator-modifier-property.md) define o controle de combinações de teclas para o acelerador.  
  
    > [!NOTE]
    >  No **propriedades** janela, essa propriedade é exibido como três propriedades Boolianas separadas, que pode ser controlada independentemente: **Alt**, **Ctrl**e **Shift**.  
  
-   O [propriedade de chave](../windows/accelerator-key-property.md) define a chave real a ser usado como o acelerador.  
  
-   O [a propriedade Type](../windows/accelerator-type-property.md) determina se a chave é interpretada como ASCII/ANSI ou de virtual (VIRTKEY).  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração predefinidas](../windows/predefined-accelerator-keys.md)   
 [Editores de recursos](../windows/resource-editors.md)   
 [Editor de aceleradores](../windows/accelerator-editor.md)