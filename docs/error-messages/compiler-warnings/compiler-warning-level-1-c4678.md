---
title: Compilador aviso (nível 1) C4678 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4678
dev_langs:
- C++
helpviewer_keywords:
- C4678
ms.assetid: 0c588f34-595d-4e5c-9470-8723fca2cc06
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 81eb7df618f97300c2654cc0f4f7a58d18215b26
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46076093"
---
# <a name="compiler-warning-level-1-c4678"></a>Compilador aviso (nível 1) C4678

a classe base 'base_type' é menos acessível que 'derived_type'

Um tipo público deriva de um tipo particular. Se o tipo público é instanciado em um assembly referenciado, os membros do tipo base privado não poderão ser acessados.

C4678 só está acessível usando a opção de compilador obsoletos **/CLR: oldSyntax**. É um erro ao usar **/clr**, para ter uma classe base que é menos acessível que sua classe derivada.
