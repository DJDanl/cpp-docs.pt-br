---
title: Compilador aviso (nível 1) C4678
ms.date: 11/04/2016
f1_keywords:
- C4678
helpviewer_keywords:
- C4678
ms.assetid: 0c588f34-595d-4e5c-9470-8723fca2cc06
ms.openlocfilehash: 9e61d919f08bbbf4f3e74da7ba4f2388516d3152
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62374515"
---
# <a name="compiler-warning-level-1-c4678"></a>Compilador aviso (nível 1) C4678

a classe base 'base_type' é menos acessível que 'derived_type'

Um tipo público deriva de um tipo particular. Se o tipo público é instanciado em um assembly referenciado, os membros do tipo base privado não poderão ser acessados.

C4678 só está acessível usando a opção de compilador obsoletos **/CLR: oldSyntax**. É um erro ao usar **/clr**, para ter uma classe base que é menos acessível que sua classe derivada.
