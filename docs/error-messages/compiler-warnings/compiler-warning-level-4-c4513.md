---
title: Compilador aviso (nível 4) C4513 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4513
dev_langs:
- C++
helpviewer_keywords:
- C4513
ms.assetid: 6877334a-f30a-4184-9483-dac3348737a4
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 75ae1c94d7a11fc9bb0049333c65a6677b04778a
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46087377"
---
# <a name="compiler-warning-level-4-c4513"></a>Compilador aviso (nível 4) C4513

'class': não foi possível gerar um destruidor

O compilador não gere um destruidor de padrão de uma determinada classe; Nenhum destruidor foi criado. O destruidor está em uma classe base que não está acessível para a classe derivada. Se a classe base tem um destruidor privado, torne-o público ou protegido.