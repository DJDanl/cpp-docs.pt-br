---
title: Classe Debug (C++/CLI)
ms.date: 11/04/2016
helpviewer_keywords:
- Trace class, Visual C++
- .NET Framework [C++], Debug class
- Debug class
ms.assetid: 076bd528-1b6f-4e8a-a372-eb5849cf969a
ms.openlocfilehash: 3a262a0d2ef429cb94f4648eb7c7180e7b130279
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57743610"
---
# <a name="debug-class-ccli"></a>Classe Debug (C++/CLI)

Ao usar <xref:System.Diagnostics.Debug> em um aplicativo do Visual C++, o comportamento não é alterado entre uma depuração e um build de versão.

## <a name="remarks"></a>Comentários

O comportamento para <xref:System.Diagnostics.Trace> é idêntico ao comportamento para a classe de depuração, mas é dependente no símbolo de rastreamento que está sendo definido. Isso significa que você deve `#ifdef` qualquer código relacionado ao rastreamento para impedir que o comportamento de depuração em um build de versão.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo a seguir sempre executa as instruções de saída, independentemente se você compilar com **/DDEBUG** ou **/DTRACE**.

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

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

Para obter o comportamento esperado (ou seja, nenhuma saída de "teste" impresso para uma compilação de versão), você deve usar o `#ifdef` e `#endif` diretivas. Para demonstrar essa correção, o exemplo de código anterior é modificado abaixo:

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

## <a name="see-also"></a>Consulte também

[Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)
