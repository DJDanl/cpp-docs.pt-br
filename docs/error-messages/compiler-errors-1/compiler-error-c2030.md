---
title: Erro do Compilador C2030
ms.date: 11/04/2016
f1_keywords:
- C2030
helpviewer_keywords:
- C2030
ms.assetid: 5806cead-64df-4eff-92de-52c9a3f5ee62
ms.openlocfilehash: 217f97d205e1da075277b8b0bc22ff3baab13482
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400520"
---
# <a name="compiler-error-c2030"></a>Erro do Compilador C2030

um destruidor com acessibilidade 'privada protegida' não pode ser um membro de uma classe declarada 'selada'

Uma classe de tempo de execução do Windows declarado como `sealed` não pode ter um destruidor privado protegido. Somente os destruidores não virtual públicos virtuais e privados são permitidos em tipos lacrados. Para obter mais informações, consulte [classes e estruturas Ref](../../cppcx/ref-classes-and-structs-c-cx.md).

Para corrigir esse erro, altere a acessibilidade do destruidor.