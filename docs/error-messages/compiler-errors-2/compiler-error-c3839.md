---
title: Erro do compilador C3839 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3839
dev_langs:
- C++
helpviewer_keywords:
- C3839
ms.assetid: 0957faff-1e9f-439b-876b-85bd8d2c578d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 597d02ff347d399833e2376743b50f65e7674a18
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46092902"
---
# <a name="compiler-error-c3839"></a>Erro do compilador C3839

não é possível alterar alinhamento em gerenciado ou o tipo de WinRT

Alinhamento de variáveis em gerenciados ou tipos de tempo de execução do Windows é controlada pelo CLR ou tempo de execução do Windows e não pode ser modificado com [alinhar](../../cpp/align-cpp.md).

O exemplo a seguir gera C3839:

```
// C3839a.cpp
// compile with: /clr
ref class C
{
public:
   __declspec(align(32)) int m_j; // C3839
};

int main()
{
}
```