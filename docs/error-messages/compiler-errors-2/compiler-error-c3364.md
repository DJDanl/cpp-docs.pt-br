---
title: Erro do compilador C3364 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3364
dev_langs:
- C++
helpviewer_keywords:
- C3364
ms.assetid: 98654741-60fe-4472-a6af-e580f8c0a6e1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 65ac2c54ccd0fe4a086cfcc79cf4dba269876ad3
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46096243"
---
# <a name="compiler-error-c3364"></a>Erro do compilador C3364

'delegate': construtor delegate: o argumento deve ser um ponteiro para a função global ou de função de membro de classe gerenciada

O segundo parâmetro do construtor do delegado usa o endereço de uma função de membro ou o endereço de uma função de membro estático de qualquer classe. Ambos são tratadas como endereços simples.

O exemplo a seguir gera C3364:

```
// C3364_2.cpp
// compile with: /clr

delegate int D( int, int );

ref class C {
public:
   int mf( int, int ) {
      return 1;
   }
};

int main() {
   C^ pC = gcnew C;
   System::Delegate^ pD = gcnew D( pC,pC->mf( 1, 2 ) ); // C3364

   // try the following line instead
   // System::Delegate^ pD = gcnew D(pC, &C::mf);
}
```
