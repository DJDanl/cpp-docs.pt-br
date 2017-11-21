---
title: 'Como: declarar identificadores em tipos nativos | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
f1_keywords: gcroot
dev_langs: C++
helpviewer_keywords:
- handles, declaring
- gcroot keyword [C++]
- types [C++], declaring handles in
ms.assetid: b8c0eead-17e5-4003-b21f-b673f997d79f
caps.latest.revision: "14"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: b7507a0c941fa651f55fdf462b9d832cfd929632
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-declare-handles-in-native-types"></a>Como declarar identificadores em tipos nativos
Você não pode declarar um tipo de identificador em um tipo nativo. vcclr.h fornece o modelo de wrapper de tipo seguro `gcroot` para se referir a um objeto CLR do heap C++. Este modelo permite que você inserir um identificador virtual em um tipo nativo e tratá-lo como se fosse o tipo subjacente. Na maioria dos casos, você pode usar o `gcroot` objeto como o tipo incorporado sem qualquer conversão. No entanto, com [para cada um, no](../dotnet/for-each-in.md), você deve usar `static_cast` para recuperar a referência gerenciada subjacente.  
  
 O `gcroot` modelo é implementado usando os recursos da classe de valor System::Runtime::InteropServices::GCHandle, que fornece "identificadores" para o heap coletado como lixo. Observe que os identificadores de si mesmos não são coletados pelo Garbage Collector e são liberados quando não mais em uso por destruidor no `gcroot` classe (este destruidor não pode ser chamado manualmente). Se você criar uma instância de um `gcroot` de objetos no heap nativo, você deve chamar delete no recurso.  
  
 O tempo de execução mantém uma associação entre o identificador e o objeto CLR, que faz referência a ele. Quando o objeto CLR é movida com a pilha de coletor de lixo, o identificador retornará o novo endereço do objeto. Uma variável não precisa ser fixado antes que ela é atribuída a um `gcroot` modelo.  
  
## <a name="example"></a>Exemplo  
 Este exemplo mostra como criar um `gcroot` objeto na pilha nativo.  
  
```  
// mcpp_gcroot.cpp  
// compile with: /clr  
#include <vcclr.h>  
using namespace System;  
  
class CppClass {  
public:  
   gcroot<String^> str;   // can use str as if it were String^  
   CppClass() {}  
};  
  
int main() {  
   CppClass c;  
   c.str = gcnew String("hello");  
   Console::WriteLine( c.str );   // no cast required  
}  
```  
  
```Output  
hello  
```  
  
## <a name="example"></a>Exemplo  
 Este exemplo mostra como criar um `gcroot` objeto no heap nativo.  
  
```  
// mcpp_gcroot_2.cpp  
// compile with: /clr  
// compile with: /clr  
#include <vcclr.h>  
using namespace System;  
  
struct CppClass {  
   gcroot<String ^> * str;  
   CppClass() : str(new gcroot<String ^>) {}  
  
   ~CppClass() { delete str; }  
  
};  
  
int main() {  
   CppClass c;  
   *c.str = gcnew String("hello");  
   Console::WriteLine( *c.str );  
}  
```  
  
```Output  
hello  
```  
  
## <a name="example"></a>Exemplo  
 Este exemplo mostra como usar `gcroot` para manter as referências aos tipos de valor (tipos de referência não) em um tipo nativo usando `gcroot` no tipo de processador.  
  
```  
// mcpp_gcroot_3.cpp  
// compile with: /clr  
#include < vcclr.h >  
using namespace System;  
  
public value struct V {  
   String^ str;  
};  
  
class Native {  
public:  
   gcroot< V^ > v_handle;  
};  
  
int main() {  
   Native native;  
   V v;  
   native.v_handle = v;  
   native.v_handle->str = "Hello";  
   Console::WriteLine("String in V: {0}", native.v_handle->str);  
}  
```  
  
```Output  
String in V: Hello  
```  
  
## <a name="see-also"></a>Consulte também  
 [Usando interop do C++ (PInvoke implícito)](../dotnet/using-cpp-interop-implicit-pinvoke.md)