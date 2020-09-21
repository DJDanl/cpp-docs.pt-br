---
title: Erro do compilador C2099
ms.date: 11/04/2016
f1_keywords:
- C2099
helpviewer_keywords:
- C2099
ms.assetid: 30e151ee-d458-4901-b0c0-d45054a913f5
ms.openlocfilehash: 84070b36506a657dde5d2e7bd5594c2b7434d81d
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90743406"
---
# <a name="compiler-error-c2099"></a>Erro do compilador C2099

inicializador não é uma constante

Esse erro é emitido somente pelo compilador C e ocorre apenas para variáveis não automáticas.  O compilador inicializa as variáveis não automáticas no início do programa e os valores que elas são inicializadas devem ser constantes.

## <a name="examples"></a>Exemplos

O exemplo a seguir gera C2099.

```c
// C2099.c
int j;
int *p;
j = *p;   // C2099 *p is not a constant
```

C2099 também pode ocorrer porque o compilador não é capaz de executar o dobramento constante em uma expressão sob **/fp: strict** porque as configurações do ambiente de precisão de ponto flutuante (consulte [_controlfp_s](../../c-runtime-library/reference/controlfp-s.md) para obter mais informações) podem ser diferentes da compilação para o tempo de execução.

Quando o dobramento de constante falha, o compilador invoca a inicialização dinâmica, o que não é permitido em C.

Para resolver esse erro, compile o módulo como um arquivo. cpp ou Simplifique a expressão.

Para obter mais informações, consulte [/fp (especificar comportamento de ponto flutuante)](../../build/reference/fp-specify-floating-point-behavior.md).

O exemplo a seguir gera C2099.

```c
// C2099_2.c
// compile with: /fp:strict /c
float X = 2.0 - 1.0;   // C2099
float X2 = 1.0;   // OK
```
