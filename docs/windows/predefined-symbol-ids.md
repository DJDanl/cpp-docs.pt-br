---
title: Predefinidas IDs de símbolo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- symbols, predefined IDs
- predefined symbol IDs
ms.assetid: 91a5d610-1a04-47e8-b8a4-63ad650a90df
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ee34744a110b31eba125e4b6cbef48207081f5d7
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42578634"
---
# <a name="predefined-symbol-ids"></a>IDs de símbolo predefinido

Quando você começar um novo projeto, dependendo do tipo de projeto, algumas IDs de símbolo são predefinidos para seu uso. Essas IDs de símbolo dão suporte a várias bibliotecas e tipos de projeto, como o MFC. Eles representam tarefas comuns que normalmente são incluídas em qualquer aplicativo ou ações de itens de hardware, como um mouse ou uma impressora.

Essas IDs de símbolo se tornam importantes ao trabalhar com recursos. Eles estão disponíveis quando você edita as tabelas de aceleradores; Alguns deles já estão associados às chaves virtuais. Eles também estão disponíveis para você por meio de [janela de propriedades](/visualstudio/ide/reference/properties-window). Você pode atribuir qualquer uma das IDs do símbolo predefinido para novos recursos, ou você pode atribuir teclas de aceleração a eles e a funcionalidade associada com o símbolo de que ID automaticamente associa a combinação de teclas.

Essas bibliotecas têm predefinidos símbolos que serão exibido como parte do projeto:

- [Símbolos predefinidos do MFC](../windows/mfc-predefined-symbols.md)

- [Símbolos predefinidos da ATL](../windows/atl-predefined-symbols.md)

- [Símbolos predefinidos do Win32](../windows/win32-predefined-symbols.md)

   > [!NOTE]
   > Símbolos predefinidos são sempre somente leitura.

## <a name="requirements"></a>Requisitos

Win32, MFC ou ATL

## <a name="see-also"></a>Consulte também

[Símbolos: identificadores de recursos](../windows/symbols-resource-identifiers.md)