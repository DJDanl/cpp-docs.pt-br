---
title: Erro do compilador C3839
ms.date: 11/04/2016
f1_keywords:
- C3839
helpviewer_keywords:
- C3839
ms.assetid: 0957faff-1e9f-439b-876b-85bd8d2c578d
ms.openlocfilehash: b8382213fbe7cc953dafd9610bfb993ba7837947
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400065"
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