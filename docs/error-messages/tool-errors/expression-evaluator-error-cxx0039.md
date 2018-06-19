---
title: CXX0039 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0039
dev_langs:
- C++
helpviewer_keywords:
- CXX0039
- CAN0039
ms.assetid: 8bf698d2-e015-4595-944f-72b81aa43d22
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8681d73d2889433516b205a47c500193bbeabdb0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33297762"
---
# <a name="expression-evaluator-error-cxx0039"></a>Erro CXX0039 (avaliador de expressão)
o símbolo é ambíguo  
  
 O avaliador de expressão C não pode determinar qual instância de um símbolo a ser usado em uma expressão. O símbolo ocorre mais de uma vez na árvore de herança.  
  
 Você deve usar o operador de resolução do escopo (`::`) para especificar explicitamente a instância a ser usado na expressão.  
  
 Esse erro é idêntico ao CAN0039.