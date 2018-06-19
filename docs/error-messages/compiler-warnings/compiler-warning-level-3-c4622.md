---
title: Compilador aviso (nível 3) C4622 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4622
dev_langs:
- C++
helpviewer_keywords:
- C4622
ms.assetid: d3c879f0-4492-4f4b-b26d-230993f3a933
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0b82e87f37b50b8df727d043889cb35ca02d3f78
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33291535"
---
# <a name="compiler-warning-level-3-c4622"></a>Compilador C4622 de aviso (nível 3)
substituindo informação de depuração formada durante a criação do cabeçalho pré-compilado no arquivo de objeto: 'file'  
  
 Informações do CodeView no arquivo especificado eram perdidas quando ele foi compilado com o [/Yu](../../build/reference/yu-use-precompiled-header-file.md) opção (usar cabeçalhos pré-compilados).  
  
 Renomeie o arquivo de objeto (usando [/Fo](../../build/reference/fo-object-file-name.md)) ao criar ou usando o cabeçalho pré-compilado de arquivo e vincular a usar o novo arquivo de objeto.