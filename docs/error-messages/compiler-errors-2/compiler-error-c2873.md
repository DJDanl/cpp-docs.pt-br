---
title: Erro do compilador C2873
ms.date: 11/04/2016
f1_keywords:
- C2873
helpviewer_keywords:
- C2873
ms.assetid: 7a10036b-400e-4364-bd2f-dcd7370c5e28
ms.openlocfilehash: 69be18e5f3e06392d4f2fa11c6343a07298b84bb
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62164924"
---
# <a name="compiler-error-c2873"></a>Erro do compilador C2873

'symbol': símbolo não pode ser usado em uma declaração using

Um `using` diretiva está falta um [namespace](../../cpp/namespaces-cpp.md) palavra-chave. Isso faz com que o compilador a interpretar incorretamente o código como um [usando a declaração](../../cpp/using-declaration.md) em vez de uma [diretiva using](../../cpp/namespaces-cpp.md#using_directives).