---
title: Aviso LNK4010 das ferramentas de vinculador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4010
dev_langs:
- C++
helpviewer_keywords:
- LNK4010
ms.assetid: 2824cf99-4174-4b60-a6e2-c01e9f1ee52d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 266e377a917fe3ce9ae7bae228134f49384e15cb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33302666"
---
# <a name="linker-tools-warning-lnk4010"></a>Aviso LNK4010 (Ferramentas de Vinculador)
número de número de versão de subsistema inválido; versão de subsistema padrão assumida  
  
 Você pode especificar uma versão para o subsistema da imagem ([/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md)). Cada subsistema tem um requisito de versão mínima. Se a versão especificada é menor que o mínimo, esse aviso ocorrerá e o vinculador usará apenas o subsistema de padrão.