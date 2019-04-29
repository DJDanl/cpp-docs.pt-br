---
title: Erro do compilador C2449
ms.date: 11/04/2016
f1_keywords:
- C2449
helpviewer_keywords:
- C2449
ms.assetid: 544bf0b6-daa0-40e8-9f21-8e583d472a2d
ms.openlocfilehash: f674bbec7cee8c00792848ee7e51b1e46299dd58
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62302066"
---
# <a name="compiler-error-c2449"></a>Erro do compilador C2449

encontrado ' {' no escopo do arquivo (faltando cabeçalho de função?)

Uma chave de abertura ocorre no escopo do arquivo.

Esse erro pode ser causado por um ponto e vírgula entre um cabeçalho de função e a chave de abertura da definição da função.

O exemplo a seguir gera C2499:

```
// C2449.c
// compile with: /c
void __stdcall func(void) {}   // OK
void __stdcall func(void);  // extra semicolon on this line
{                         // C2449 detected here
```