---
title: Erro do compilador C2030 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2030
dev_langs:
- C++
helpviewer_keywords:
- C2030
ms.assetid: 5806cead-64df-4eff-92de-52c9a3f5ee62
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b0c5849c372cc4c7ebf27dbe010e65d406ad1ab1
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46032882"
---
# <a name="compiler-error-c2030"></a>Erro do Compilador C2030

um destruidor com acessibilidade 'privada protegida' não pode ser um membro de uma classe declarada 'selada'

Uma classe de tempo de execução do Windows declarado como `sealed` não pode ter um destruidor privado protegido. Somente os destruidores não virtual públicos virtuais e privados são permitidos em tipos lacrados. Para obter mais informações, consulte [classes e estruturas Ref](../../cppcx/ref-classes-and-structs-c-cx.md).

Para corrigir esse erro, altere a acessibilidade do destruidor.