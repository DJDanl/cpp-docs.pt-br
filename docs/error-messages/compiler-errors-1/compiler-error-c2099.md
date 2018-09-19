---
title: Erro do compilador C2099 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2099
dev_langs:
- C++
helpviewer_keywords:
- C2099
ms.assetid: 30e151ee-d458-4901-b0c0-d45054a913f5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8fcbefa4d8fb9d5503f28cf3bf39cafc6b05a225
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46116822"
---
# <a name="compiler-error-c2099"></a>Erro do compilador C2099

inicializador não é uma constante

Esse erro é emitido apenas pelo compilador C e ocorre apenas para variáveis não automático.  O compilador a inicializa variáveis não automático ao início do programa e os valores que eles são inicializados com devem ser constantes.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2099.

```
// C2099.c
int j;
int *p;
j = *p;   // C2099 *p is not a constant
```

## <a name="example"></a>Exemplo

C2099 também pode ocorrer porque o compilador não consegue realizar dobra constante em uma expressão em **/fp: strict** porque o ponto flutuante as configurações de ambiente de precisão (consulte [controlfp_s](../../c-runtime-library/reference/controlfp-s.md) para obter mais informações) podem diferir da compilação para o tempo de execução.

Quando a constante dobra falhar, o compilador invoca inicialização dinâmica, que não é permitida em C.

Para resolver esse erro, compile o módulo como um arquivo. cpp ou Simplifique a expressão.

Para obter mais informações, consulte [/fp (especificar comportamento de ponto flutuante)](../../build/reference/fp-specify-floating-point-behavior.md).

O exemplo a seguir gera C2099.

```
// C2099_2.c
// compile with: /fp:strict /c
float X = 2.0 - 1.0;   // C2099
float X2 = 1.0;   // OK
```