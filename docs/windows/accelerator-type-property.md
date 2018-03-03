---
title: Propriedade de tipo de acelerador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Type property
- VIRTKEY
ms.assetid: 8c349bc4-e6ad-43fa-959e-f29168af35b8
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 214d8ca9c45a3657215833764268794b152bd337
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="accelerator-type-property"></a>Propriedade do tipo de acelerador
O Acelerador de **tipo** propriedade determina se a combinação de teclas de atalho associada à ID de aceleração é uma combinação de teclas virtual ou um valor de chave ASCII/ANSI:  
  
-   Se o **tipo** é de propriedade **ASCII**, o [modificador](../windows/accelerator-modifier-property.md) só pode ser nenhum ou Alt, ou pode ter um acelerador que usa a tecla CTRL (especificado, precedendo a chave com um ^).  
  
-   Se o **tipo** é de propriedade **VIRTKEY**, qualquer combinação de valores de chave e modificador é válida.  
  
    > [!NOTE]
    >  Se você quiser inserir um valor para a tabela de teclas aceleradoras e tem o valor a ser tratado como ASCII/ANSI, simplesmente clique o tipo de entrada na tabela e selecione ASCII na lista suspensa. No entanto, se você usar o **próxima chave digitada** comando (**editar** menu) para especificar a chave, você deve alterar o **tipo** propriedade de VIRTKEY para ASCII *antes de* inserir o código de chave.  
  
## <a name="requirements"></a>Requisitos  
 Win32  
  
## <a name="see-also"></a>Consulte também  
 [Definindo propriedades de acelerador](../windows/setting-accelerator-properties.md)   
 [Editor de aceleradores](../windows/accelerator-editor.md)