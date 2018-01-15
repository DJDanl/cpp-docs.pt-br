---
title: "-Zc: rvalueCast (Aplicar regras de conversão de tipo) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- rvaluecast
- /Zc:rvalueCast
- VC.Project.VCCLCompilerTool.EnforceTypeConversionRules
dev_langs: C++
helpviewer_keywords:
- -Zc compiler options (C++)
- rvaluecast
- Enforce type conversion rules
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: 7825277d-e565-4c48-b0fb-76ac0b0c6e38
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 8f4b888dde70708ee10b2d8000ff6380709dc870
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="zcrvaluecast-enforce-type-conversion-rules"></a>/Zc:rvalueCast (Aplicar regras de conversão de tipo)
Quando o **/ZC: rvaluecast** opção for especificada, o compilador identifica corretamente um tipo de referência de rvalue como resultado de uma operação de conversão de acordo com o padrão C++ 11. Quando a opção não está especificada, o comportamento do compilador é o mesmo do Visual Studio 2012. Por padrão, **/ZC: rvaluecast** está desativado. Para conformidade e para eliminar erros no uso de casts, recomendamos que você use **/ZC: rvaluecast**.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
/Zc:rvalueCast[-]  
```  
  
## <a name="remarks"></a>Comentários  
 Se **/ZC: rvaluecast** for especificado, o compilador segue o padrão C++ 11 seção 5.4 e trata somente converter expressões que resultam em tipos de referência não e converter expressões que resultam em referências de rvalue para tipos de função não como tipos de rvalue. Por padrão, ou se **/Zc:rvalueCast-** for especificado, o compilador não é compatível e trata todas as expressões de conversão que resultam em referências de rvalue como rvalues.  
  
 Use **/ZC: rvaluecast** se você passar uma expressão de conversão como um argumento para uma função que usa um tipo de referência rvalue. O comportamento padrão faz com que o erro do compilador [C2664](../../error-messages/compiler-errors-2/compiler-error-c2664.md) quando o compilador incorretamente determina o tipo da expressão de conversão. O exemplo mostra um erro de compilador no código correto quando /Zc:rvalueCast não é especificado:  
  
```cpp  
// Test of /Zc:rvalueCast  
// compile by using:  
// cl /c /Zc:rvalueCast- make_thing.cpp  
// cl /c /Zc:rvalueCast make_thing.cpp  
  
#include <utility>  
  
template <typename T>   
struct Thing {  
   // Construct a Thing by using two rvalue reference parameters  
   Thing(T&& t1, T&& t2)  
      : thing1(t1), thing2(t2) {}  
  
   T& thing1;  
   T& thing2;  
};  
  
// Create a Thing, using move semantics if possible  
template <typename T>  
Thing<T> make_thing(T&& t1, T&& t2)  
{  
   return (Thing<T>(std::forward<T>(t1), std::forward<T>(t2)));  
}  
  
struct Test1 {  
   long a;  
   long b;  
  
   Thing<long> test() {   
      // Use identity casts to create rvalues as arguments  
      return make_thing(static_cast<long>(a), static_cast<long>(b));   
   }  
};  
  
```  
  
 Talvez o comportamento do compilador padrão não relate o erro C2102 quando apropriado. Neste exemplo, o compilador não relata um erro se o endereço de um criado por uma identidade de conversão de rvalue é obtido quando **/ZC: rvaluecast** não for especificado:  
  
```cpp  
int main() {  
   int a = 1;  
   int *p = &a;   // Okay, take address of lvalue   
                  // Identity cast creates rvalue from lvalue;    
   p = &(int)a;   // problem: should cause C2102: '&' requires l-value  
}  
```  
  
 Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).  
  
### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).  
  
2.  Selecione o **C/C++** pasta.  
  
3.  Selecione o **linha de comando** página de propriedades.  
  
4.  Modificar o **opções adicionais** propriedade incluir **/ZC: rvaluecast** e, em seguida, escolha **Okey**.  
  
## <a name="see-also"></a>Consulte também  
 [/ZC (conformidade)](../../build/reference/zc-conformance.md)