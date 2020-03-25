---
title: Aviso do compilador (nível 4) C4092
ms.date: 11/04/2016
f1_keywords:
- C4092
helpviewer_keywords:
- C4092
ms.assetid: 396ae826-a892-4327-bd66-f4762376d72b
ms.openlocfilehash: 6786d692785dbca575d4b241b7b3e3d40575b686
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198543"
---
# <a name="compiler-warning-level-4-c4092"></a>Aviso do compilador (nível 4) C4092

sizeof retorna ' sem sinal Long '

O operando do operador de `sizeof` era muito grande, portanto `sizeof` retornou um **longo**não assinado. Esse aviso ocorre sob as extensões da Microsoft ([/ze](../../build/reference/za-ze-disable-language-extensions.md)). Em vez de compatibilidade com ANSI (/Za), o resultado é truncado.
