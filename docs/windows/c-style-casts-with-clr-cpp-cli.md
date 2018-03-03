---
title: "Conversão do estilo C com - clr (C + + CLI) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- C-style casts and /clr
ms.assetid: d2a4401a-156a-4da9-8d12-923743e26913
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e529a40f8eb876791f49559d3970696fdece489d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="c-style-casts-with-clr-ccli"></a>Conversões de Estilo C-Style com /clr (C++/CLI)
O tópico a seguir se aplica somente a Common Language Runtime.  
  
 Quando usado com tipos CLR, o compilador tenta mapear C-style convertido em um as conversões listadas abaixo, na seguinte ordem:  
  
1.  const_cast  
  
2.  safe_cast  
  
3.  Safe_cast além de const_cast  
  
4.  static_cast  
  
5.  static_cast além de const_cast  
  
 Se nenhum as conversões listadas acima é válido e se o tipo da expressão e o tipo de destino são tipos de referência do CLR, conversão C-style é mapeado para uma verificação de tempo de execução (instrução de MSIL castclass). Caso contrário, uma conversão C-style é considerada inválida e o compilador emite um erro.  
  
## <a name="remarks"></a>Comentários  
 Uma conversão C-style não é recomendada. Ao compilar com [/clr (Common Language Runtime Compilation)](../build/reference/clr-common-language-runtime-compilation.md), use [safe_cast](../windows/safe-cast-cpp-component-extensions.md).  
  
 O exemplo a seguir mostra um C-style cast que mapeia para um `const_cast`.  
  
```  
// cstyle_casts_1.cpp  
// compile with: /clr  
using namespace System;  
  
ref struct R {};  
int main() {  
   const R^ constrefR = gcnew R();  
   R^ nonconstR = (R^)(constrefR);   
}  
```  
  
 O exemplo a seguir mostra um C-style cast que mapeia para um `safe_cast`.  
  
```  
// cstyle_casts_2.cpp  
// compile with: /clr  
using namespace System;  
int main() {  
   Object ^ o = "hello";  
   String ^ s = (String^)o;  
}  
```  
  
 O exemplo a seguir mostra um C-style cast que mapeia para um `safe_cast` mais `const_cast`.  
  
```  
// cstyle_casts_3.cpp  
// compile with: /clr  
using namespace System;  
  
ref struct R {};  
ref struct R2 : public R {};  
  
int main() {  
   const R^ constR2 = gcnew R2();  
   try {  
   R2^ b2DR = (R2^)(constR2);  
   }  
   catch(InvalidCastException^ e) {  
      System::Console::WriteLine("Invalid Exception");  
   }  
}  
```  
  
 O exemplo a seguir mostra um C-style cast que mapeia para um `static_cast`.  
  
```  
// cstyle_casts_4.cpp  
// compile with: /clr  
using namespace System;  
  
struct N1 {};  
struct N2 {  
   operator N1() {  
      return N1();  
   }  
};  
  
int main() {  
   N2 n2;  
   N1 n1 ;  
   n1 = (N1)n2;  
}  
```  
  
 O exemplo a seguir mostra um C-style cast que mapeia para um `static_cast` mais `const_cast`.  
  
```  
// cstyle_casts_5.cpp  
// compile with: /clr  
using namespace System;  
struct N1 {};  
  
struct N2 {  
   operator const N1*() {  
      static const N1 n1;  
      return &n1;  
   }  
};  
  
int main() {  
   N2 n2;  
   N1* n1 = (N1*)(const N1*)n2;   // const_cast + static_cast  
}  
```  
  
 O exemplo a seguir mostra um C-style cast que mapeia para uma verificação de tempo de execução.  
  
```  
// cstyle_casts_6.cpp  
// compile with: /clr  
using namespace System;  
  
ref class R1 {};  
ref class R2 {};  
  
int main() {  
   R1^ r  = gcnew R1();  
   try {  
      R2^ rr = ( R2^)(r);  
   }  
   catch(System::InvalidCastException^ e) {  
      Console::WriteLine("Caught expected exception");  
   }  
}  
```  
  
 O exemplo a seguir mostra um inválido C-style cast, que faz com que o compilador para emitir um erro.  
  
```  
// cstyle_casts_7.cpp  
// compile with: /clr  
using namespace System;  
int main() {  
   String^s = S"hello";  
   int i = (int)s;   // C2440  
}  
```  
  
## <a name="requirements"></a>Requisitos  
 Opção de compilador: **/clr**  
  
## <a name="see-also"></a>Consulte também  
 [Extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md)