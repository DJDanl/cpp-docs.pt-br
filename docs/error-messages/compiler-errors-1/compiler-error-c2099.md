---
title: Erro do compilador C2099
ms.date: 11/04/2016
f1_keywords:
- C2099
helpviewer_keywords:
- C2099
ms.assetid: 30e151ee-d458-4901-b0c0-d45054a913f5
ms.openlocfilehash: 9c83b4a50cb9cf5c5b1992f0f64e2eeb013b48e4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62376936"
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