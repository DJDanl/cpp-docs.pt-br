---
title: C2865 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2865
dev_langs:
- C++
helpviewer_keywords:
- C2865
ms.assetid: 973eb6a0-c99a-4d25-b3e5-fe0539794d77
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 70b2c6c831fde18f9054e139a120d834a75b6950
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33246210"
---
# <a name="compiler-error-c2865"></a>C2865 de erro do compilador
'function': comparação inválida para handle_or_pointer  
  
 Você pode comparar as referências a [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md) ou tipos de referência somente para fins de igualdade para ver se elas se referem ao mesmo objeto (= =) ou a diferentes objetos gerenciados (! =).  
  
 Você não pode compará-los para ordenação porque o tempo de execução do .NET pode mover objetos gerenciados a qualquer momento, alterando o resultado do teste.