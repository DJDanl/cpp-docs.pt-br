---
title: Compilador (nível 1) de aviso C4399 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C4399
dev_langs:
- C++
helpviewer_keywords:
- C4399
ms.assetid: f58d9ba7-71a0-4c3b-b26f-f946dda8af30
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: aedad6aed07a6056f74ad338037a7268c722627f
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/01/2018
ms.locfileid: "34703714"
---
# <a name="compiler-warning-level-1-c4399"></a>Compilador C4399 de aviso (nível 1)

> '*símbolo*': símbolo per-process não deve ser marcado com __declspec(dllimport) quando compilado com /clr: pure

## <a name="remarks"></a>Comentários

O **/clr: pure** opção de compilador foi preterida no Visual Studio 2015 e sem suporte no Visual Studio de 2017.

Dados de uma imagem nativa ou uma imagem com nativo e construções CLR não podem ser importados em uma imagem pura. Para resolver este aviso, compile com **/clr** (não **/clr: pure**) ou excluir `__declspec(dllimport)`.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4399.

```cpp
// C4399.cpp
// compile with: /clr:pure /doc /W1 /c
__declspec(dllimport) __declspec(process) extern const int i;   // C4399
```