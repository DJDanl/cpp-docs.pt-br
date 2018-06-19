---
title: CXX0025 de erro do avaliador de expressão | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- CXX0025
dev_langs:
- C++
helpviewer_keywords:
- CAN0025
- CXX0025
ms.assetid: 3e2fb541-63b3-46ac-9f93-3dadb253bcf6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 843de39120cee18b01d17d88fb2759bebb9d2dc9
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33302835"
---
# <a name="expression-evaluator-error-cxx0025"></a>Erro CXX0025 (avaliador de expressão)
o operador necessita de struct/união  
  
 Um operador que usa uma expressão de `struct` ou **união** tipo foi aplicado a uma expressão que não é um `struct` ou **união**.  
  
 Componentes de classe, estrutura ou união variáveis devem ter um nome totalmente qualificado. Componentes não podem ser inseridos sem especificação completa.  
  
 Esse erro é idêntico ao CAN0025.