---
title: Aviso do compilador (nível 3) C4192
ms.date: 11/04/2016
f1_keywords:
- C4192
helpviewer_keywords:
- C4192
ms.assetid: ea5f91fa-8c96-4f3f-ac42-0c8a86d4e5df
ms.openlocfilehash: 38b346e0a90729bda431b9cb578a03806be1ea4c
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80198972"
---
# <a name="compiler-warning-level-3-c4192"></a>Aviso do compilador (nível 3) C4192

excluindo automaticamente ' name ' ao importar a biblioteca de tipos ' Library '

Uma biblioteca de `#import` contém um item, *nome*, que também é definido nos cabeçalhos do sistema Win32. Devido a limitações de bibliotecas de tipos, nomes como **IUnknown** ou GUID são geralmente definidos em uma biblioteca de tipos, duplicando a definição dos cabeçalhos do sistema. `#import` detectará esses itens e se recusará a incorporá-los nos arquivos de cabeçalho. tlh e. tli.

Para substituir esse comportamento, use atributos de `#import` [no_auto_exclude](../../preprocessor/no-auto-exclude.md) e [inclua ()](../../preprocessor/include-parens.md).
