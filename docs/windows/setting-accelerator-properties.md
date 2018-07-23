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
ms.openlocfilehash: 5198fc1958863d3b5ad560ffeb8c5576506e9e46
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33888839"
---
# <a name="setting-accelerator-properties"></a>Configurando propriedades do acelerador
Você pode definir propriedades de acelerador no [janela propriedades](/visualstudio/ide/reference/properties-window) a qualquer momento. Você também pode usar o editor de aceleradores para modificar as propriedades de acelerador na tabela de teclas aceleradoras. As alterações feitas usando a janela Propriedades ou o editor de aceleradores têm o mesmo resultado: edições são refletidas imediatamente na tabela de teclas aceleradoras.  
  
 Há três propriedades para cada Acelerador [ID](https://www.microsoftonedoc.com/#/organizations/e6f6a65cf14f462597b64ac058dbe1d0/projects/3fedad16-eaf1-41a6-8f96-0c1949c68f32/containers/a3daf831-1c5f-4bbe-964d-503870caf874/tocpaths/3487f185-de96-4b1d-87db-034a52223160/locales/en-US):  
  
-   O [propriedade de modificador](../windows/accelerator-modifier-property.md) define o controle combinações de tecla para o acelerador.  
  
    > [!NOTE]
    >  Na janela Propriedades, essa propriedade aparece como três propriedades Boolianas separadas, que pode ser controlado independentemente: Shift, Alt e Ctrl.  
  
-   O [propriedade de chave](../windows/accelerator-key-property.md) define a chave real para usar como o acelerador.  
  
-   O [a propriedade Type](../windows/accelerator-type-property.md) determina se a chave é interpretada como virtual (VIRTKEY) ou ASCII/ANSI.  
  

  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Teclas de aceleração predefinidas](../windows/predefined-accelerator-keys.md)   
 [Editores de recursos](../windows/resource-editors.md)   
 [Editor de aceleradores](../windows/accelerator-editor.md)