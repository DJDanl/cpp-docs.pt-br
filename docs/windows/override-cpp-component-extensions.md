---
title: Substituir (extensões de componentes C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- overriding, override keyword [C++]
- override keyword [C++]
ms.assetid: 34d19257-1686-4fcd-96f5-af07c70ba914
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 6818256aafc64702e5423a5560c251e6d46750fa
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33878873"
---
# <a name="override--c-component-extensions"></a>substituir (Extensões de Componentes C++)
O `override` palavra-chave contextual indica que um membro de um tipo substitui uma classe base ou um membro de interface base.  
  
## <a name="remarks"></a>Comentários  
 O `override` palavra-chave é válido durante a compilação de destinos nativo (opção de compilador padrão), os destinos de tempo de execução do Windows (**/ZW** opção de compilador), ou destinos de tempo de execução de linguagem comum (**/clr** compilador opção).  
  
 Para obter mais informações sobre especificadores de substituição, consulte [especificador de substituição](../cpp/override-specifier.md) e [especificadores de substituição e compilações nativas](../dotnet/how-to-declare-override-specifiers-in-native-compilations-cpp-cli.md).  
  
 Para obter mais informações sobre palavras-chave contextuais, consulte [sensível ao contexto palavras-chave](../windows/context-sensitive-keywords-cpp-component-extensions.md).  
  
## <a name="examples"></a>Exemplos  
 **Exemplo**  
  
 O exemplo de código a seguir mostra que `override` também pode ser usado em compilações nativas.  
  
```cpp#  
// override_keyword_1.cpp  
// compile with: /c  
struct I1 {  
   virtual void f();  
};  
  
struct X : public I1 {  
   virtual void f() override {}  
};  
```  
  
 **Exemplo**  
  
 O exemplo de código a seguir mostra que `override` pode ser usado em compilações de tempo de execução do Windows.  
  
```cpp#  
// override_keyword_2.cpp  
// compile with: /ZW /c  
ref struct I1 {  
   virtual void f();  
};  
  
ref struct X : public I1 {  
   virtual void f() override {}  
};  
```  
  
 **Requisitos**  
  
 Opção do compilador: **/ZW**  
  
 **Exemplo**  
  
 O exemplo de código a seguir mostra que `override` pode ser usado em compilações de tempo de execução de linguagem comum.  
  
```cpp#  
// override_keyword_3.cpp  
// compile with: /clr /c  
ref struct I1 {  
   virtual void f();  
};  
  
ref struct X : public I1 {  
   virtual void f() override {}  
};  
```  
  
 **Requisitos**  
  
 Opção de compilador: **/clr**  
  
## <a name="see-also"></a>Consulte também  
 [Especificador de substituição](../cpp/override-specifier.md)   
 [Especificadores de substituição](../windows/override-specifiers-cpp-component-extensions.md)