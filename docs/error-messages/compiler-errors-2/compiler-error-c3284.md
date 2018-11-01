---
title: Erro do compilador C3284
ms.date: 11/04/2016
f1_keywords:
- C3824
helpviewer_keywords:
- C3284
ms.assetid: e582f316-e9db-4d27-9c70-fdfa737a9d5f
ms.openlocfilehash: 6e79de18e277de9ee79945d319640fa906dea622
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50511625"
---
# <a name="compiler-error-c3284"></a>Erro do compilador C3284

as restrições de parâmetro genérico 'parâmetro' da função 'function' devem coincidir com as restrições de parâmetro genérico 'parâmetro' da função 'function'

Uma função genérica virtual deve usar as mesmas restrições que uma função virtual com o mesmo nome e o conjunto de argumentos na classe base.

O exemplo a seguir gera C3284:

```
// C3284.cpp
// compile with: /clr /c
// C3284 expected
public interface class IGettable {
   int Get();
};

public interface class B {
   generic<typename T>
   where T : IGettable
   virtual int mf(T t);
};

public ref class D : public B {
public:
   generic<typename T>
   // Uncomment the following line to resolve.
   // where T : IGettable
   virtual int mf(T t) {
      return 4;
   }
};
```