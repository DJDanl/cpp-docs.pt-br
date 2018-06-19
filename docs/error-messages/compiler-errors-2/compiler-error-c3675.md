---
title: C3675 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3675
dev_langs:
- C++
helpviewer_keywords:
- C3675
ms.assetid: 87461613-6633-430b-b95d-c7cb1bb63776
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 1b4aaa53ae1d92364fad143f127ee3e7b504acdd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33273638"
---
# <a name="compiler-error-c3675"></a>C3675 de erro do compilador
'function': é reservado porque 'property' está definido  
  
 Quando você declara uma propriedade simples, o compilador gera get e métodos de acessador set e os nomes estão presentes no escopo do seu programa.  Os nomes gerados pelo compilador são formados anexando get _ e set _ ao nome da propriedade.  Portanto, você não pode declarar funções com o mesmo nome que os acessadores gerados pelo compilador.  
  
 Consulte [propriedade](../../windows/property-cpp-component-extensions.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3675.  
  
```  
// C3675.cpp  
// compile with: /clr /c  
ref struct C {  
public:  
   property int Size;  
   int get_Size() { return 0; }   // C3675  
};  
```