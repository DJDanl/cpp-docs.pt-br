---
title: Classe Debug (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- Trace class, Visual C++
- .NET Framework [C++], Debug class
- Debug class
ms.assetid: 076bd528-1b6f-4e8a-a372-eb5849cf969a
ms.openlocfilehash: 47e1b949cb6e998508a3bd362b1c74961cf4cc23
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91414146"
---
# <a name="debug-class-ccli"></a>Classe Debug (C++/CLI)

Ao usar <xref:System.Diagnostics.Debug> o em um aplicativo Visual C++, o comportamento não é alterado entre uma depuração e uma compilação de versão.

## <a name="remarks"></a>Comentários

O comportamento de <xref:System.Diagnostics.Trace> é idêntico ao comportamento da classe Debug, mas depende do rastreamento de símbolo que está sendo definido. Isso significa que você deve ter `#ifdef` qualquer código relacionado ao rastreamento para evitar o comportamento de depuração em uma compilação de versão.

## <a name="example-always-executes-output-statements"></a>Exemplo: sempre executa instruções output

### <a name="description"></a>Description

O exemplo a seguir sempre executa as instruções de saída, independentemente de você compilar com **/DDEBUG** ou **/DTrace**.

### <a name="code"></a>Código

```cpp
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

```Output
    Entering Main
Hello World.
    Exiting Main
test
```

## <a name="example-use-ifdef-and-endif-directives"></a>Exemplo: Use as diretivas #ifdef e #endif

### <a name="description"></a>Description

Para obter o comportamento esperado (ou seja, nenhuma saída de "teste" impressa para uma compilação de versão), você deve usar as `#ifdef` `#endif` diretivas e. O exemplo de código anterior é modificado abaixo para demonstrar essa correção:

### <a name="code"></a>Código

```cpp
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

## <a name="see-also"></a>Confira também

[Programação .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)
