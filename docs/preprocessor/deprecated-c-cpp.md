---
title: obsoleto (C/C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- vc-pragma.deprecated
- deprecated_CPP
dev_langs:
- C++
helpviewer_keywords:
- deprecated pragma
- pragmas, deprecated
ms.assetid: 9c046f12-7875-499a-8d5d-12f8642fed2d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2280d5245292625bfc29815475eaca63d4d500bd
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="deprecated-cc"></a>deprecated (C/C++)
O **preterido** pragma permite você indicar que uma função, tipo ou qualquer outro identificador talvez não tenha suporte em um futuro de versão ou não deve mais ser usado.  
> [!NOTE]
> Para obter informações sobre o C++ 14 `[[deprecated]]` atributo e orientações sobre quando usar esse atributo vs o pragma ou declspec da Microsoft, consulte [atributos padrão do C++](../cpp/attributes.md) atributo.
  
## <a name="syntax"></a>Sintaxe  
  
```  
#pragma deprecated( identifier1 [,identifier2, ...] )  
```  
  
## <a name="remarks"></a>Comentários  
 Quando o compilador encontra um identificador especificado por uma **preterido** pragma, ele emite o aviso do compilador [C4995](../error-messages/compiler-warnings/compiler-warning-level-3-c4995.md).   
  
 Você pode preterir nomes de macro. Coloque o nome da macro entre aspas. Caso contrário, haverá uma expansão na macro.  
  
 Porque o **preterido** pragma funciona em todos os identificadores correspondentes e não consideram assinaturas, não é a melhor opção para reprovando versões específicas de funções sobrecarregadas. Qualquer nome de função correspondente que é colocado no escopo dispara o aviso.

  É recomendável usar o C++ 14 `[[deprecated]]` de atributo, quando possível, em vez do **preterido** pragma. Específicos do Microsoft [__declspec(deprecated)](../cpp/deprecated-cpp.md) modificador de declaração também é uma opção melhor em muitos casos que o **preterido** pragma. O `[[deprecated]]` atributo e `__declspec(deprecated)` modificador permitem que você especifique status preterido para formulários específicos de funções sobrecarregadas. O diagnóstico aviso aparece apenas sobre referências à função sobrecarregada específica o atributo ou modificador aplica-se a.  
  
## <a name="example"></a>Exemplo  
  
```  
// pragma_directive_deprecated.cpp  
// compile with: /W3  
#include <stdio.h>  
void func1(void) {  
}  
  
void func2(void) {  
}  
  
int main() {  
   func1();  
   func2();  
   #pragma deprecated(func1, func2)  
   func1();   // C4995  
   func2();   // C4995  
}  
```  
  
 O exemplo a seguir mostra como preterir uma classe:  
  
```  
// pragma_directive_deprecated2.cpp  
// compile with: /W3  
#pragma deprecated(X)  
class X {  // C4995  
public:  
   void f(){}  
};  
  
int main() {  
   X x;   // C4995  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)