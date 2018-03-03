---
title: "CXX0025 de erro do avaliador de expressão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- CXX0025
dev_langs:
- C++
helpviewer_keywords:
- CAN0025
- CXX0025
ms.assetid: 3e2fb541-63b3-46ac-9f93-3dadb253bcf6
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3f4154ca0aa0dcebecce40ed60420be0da6de456
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="expression-evaluator-error-cxx0025"></a>Erro CXX0025 (avaliador de expressão)
o operador necessita de struct/união  
  
 Um operador que usa uma expressão de `struct` ou **união** tipo foi aplicado a uma expressão que não é um `struct` ou **união**.  
  
 Componentes de classe, estrutura ou união variáveis devem ter um nome totalmente qualificado. Componentes não podem ser inseridos sem especificação completa.  
  
 Esse erro é idêntico ao CAN0025.