---
title: Erro do compilador C2692
ms.date: 11/04/2016
f1_keywords:
- C2692
helpviewer_keywords:
- C2692
ms.assetid: 02ade3b4-b757-448b-b065-d7d71bc3f441
ms.openlocfilehash: 7ce57cd50e9ec83cf80ec64e14f49eb9714f9208
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80177086"
---
# <a name="compiler-error-c2692"></a>Erro do compilador C2692

' function_name ': funções totalmente protótipos necessárias no compilador C com a opção '/CLR '

Ao compilar para código gerenciado do .NET, o compilador C requer declarações de função ANSI. Além disso, se uma função não usa parâmetros, ela deve declarar explicitamente `void` como o tipo de parâmetro.
