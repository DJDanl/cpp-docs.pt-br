---
title: Propriedade de tipo de acelerador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Type property
- VIRTKEY
ms.assetid: 8c349bc4-e6ad-43fa-959e-f29168af35b8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 59fae6d0809e32883d5d56e43e64525e23643d91
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42602320"
---
# <a name="accelerator-type-property"></a>Propriedade do tipo de acelerador

O acelerador **tipo** propriedade determina se a combinação de teclas de atalho associada com a ID do acelerador é uma combinação de teclas virtual ou um valor de chave ASCII/ANSI:

- Se o **tipo** propriedade é ASCII, o [modificador](../windows/accelerator-modifier-property.md) só podem ser `None` ou `Alt`, ou pode ter um acelerador que usa o **Ctrl** chave (especificada pelo precede a chave com um `^`).

- Se o **tipo** propriedade é VIRTKEY, qualquer combinação de `Modifier` e `Key` valores é válido.

   > [!NOTE]
   > Se você quiser inserir um valor para a tabela de Aceleradores e têm o valor a ser tratado como ASCII/ANSI, basta clicar o **tipo** para a entrada na tabela e selecione ASCII na lista suspensa. No entanto, se você usar o **próxima chave digitada** comando (**editar** menu) para especificar o `Key`, você deve alterar o **tipo** propriedade de VIRTKEY para ASCII *antes de* inserindo o `Key` código.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Configurando propriedades do acelerador](../windows/setting-accelerator-properties.md)  
[Editor de aceleradores](../windows/accelerator-editor.md)