---
title: Compilador aviso (nível 3) C4192
ms.date: 11/04/2016
f1_keywords:
- C4192
helpviewer_keywords:
- C4192
ms.assetid: ea5f91fa-8c96-4f3f-ac42-0c8a86d4e5df
ms.openlocfilehash: 56b27596296b87edcc6de406e7b6621d5723815d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519699"
---
# <a name="compiler-warning-level-3-c4192"></a>Compilador aviso (nível 3) C4192

excluindo automaticamente 'name' durante a importação de biblioteca de tipos 'library'

Um `#import` biblioteca contém um item *nome*, que é também definida nos cabeçalhos do sistema de Win32. Devido a limitações de bibliotecas de tipos, nomes, como **IUnknown** ou GUID geralmente são definidos em uma biblioteca de tipos, duplicar a definição dos cabeçalhos do sistema. `#import` detecta esses itens e se recusar a incorporá-las nos arquivos de cabeçalho. TLH e. TLI.

Para substituir esse comportamento, use `#import` atributos [no_auto_exclude](../../preprocessor/no-auto-exclude.md) e [include ()](../../preprocessor/include-parens.md).