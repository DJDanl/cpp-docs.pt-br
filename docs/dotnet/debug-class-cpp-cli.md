---
title: Classe Debug (C + + CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Trace class, Visual C++
- .NET Framework [C++], Debug class
- Debug class
ms.assetid: 076bd528-1b6f-4e8a-a372-eb5849cf969a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: fddf192b21b878c82ca663da657c55e32fd9173d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33106200"
---
# <a name="debug-class-ccli"></a>Classe Debug (C++/CLI)
Ao usar <xref:System.Diagnostics.Debug> em um aplicativo do Visual C++, o comportamento não altera entre uma depuração e uma compilação de versão.  
  
## <a name="remarks"></a>Comentários  
 O comportamento de <xref:System.Diagnostics.Trace> é idêntico ao comportamento para a classe de depuração, mas depende do símbolo de rastreamento está sendo definido. Isso significa que você deve `#ifdef` qualquer código relacionado ao rastreamento para impedir que o comportamento de depuração em uma compilação de versão.  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 O exemplo a seguir sempre executa as instruções de saída, independentemente se você compilar com **/DDEBUG** ou **/DTRACE**.  
  
### <a name="code"></a>Código  
  
```  
// mcpp_debug_class.cpp  
// compile with: /clr  
#using <system.dll>  
using namespace System::Diagnostics;  
using namespace System;  
  
int main() {  
   Trace::Listeners->Add( gcnew TextWriterTraceListener( Console::Out ) );  
   Trace::AutoFlush = true;  
   Trace::Indent();  
   Trace::WriteLine( "Entering Main" );  
   Console::WriteLine( "Hello World." );  
   Trace::WriteLine( "Exiting Main" );  
   Trace::Unindent();  
  
   Debug::WriteLine("test");  
}  
```  
  
### <a name="output"></a>Saída  
  
```  
    Entering Main  
Hello World.  
    Exiting Main  
test  
```  
  
## <a name="example"></a>Exemplo  
  
### <a name="description"></a>Descrição  
 Para obter o comportamento esperado (ou seja, nenhuma saída de "teste" impresso para uma compilação de versão), você deve usar o `#ifdef` e `#endif` diretivas. O exemplo de código anterior é modificado abaixo para demonstrar essa correção:  
  
### <a name="code"></a>Código  
  
```  
// mcpp_debug_class2.cpp  
// compile with: /clr  
#using <system.dll>  
using namespace System::Diagnostics;  
using namespace System;  
  
int main() {  
   Trace::Listeners->Add( gcnew TextWriterTraceListener( Console::Out ) );  
   Trace::AutoFlush = true;  
   Trace::Indent();  
  
#ifdef TRACE   // checks for a debug build  
   Trace::WriteLine( "Entering Main" );  
   Console::WriteLine( "Hello World." );  
   Trace::WriteLine( "Exiting Main" );  
#endif  
   Trace::Unindent();  
  
#ifdef DEBUG   // checks for a debug build  
   Debug::WriteLine("test");  
#endif   //ends the conditional block  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)