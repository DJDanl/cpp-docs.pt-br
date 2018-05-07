---
title: 'Como: analisar cadeias de caracteres usando o método Split (C + + CLI) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- parsing strings [C++]
- examples [C++], strings
- regular expressions [C++], parsing strings
- Split method, parsing strings
- strings [C++], parsing
ms.assetid: d52d2539-5ebb-4716-86b3-07314dd7e4bd
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 48c5f26cae67dbfa9feb412917ed3a1d3dc7abbf
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="how-to-parse-strings-using-the-split-method-ccli"></a>Como analisar cadeias de caracteres usando o método split (C++/CLI)
O exemplo de código a seguir demonstra como usar o <xref:System.String.Split%2A?displayProperty=fullName> método para extrair cada palavra de uma cadeia de caracteres. Uma cadeia de caracteres que contém vários tipos de delineadores word é criada e, em seguida, analisar chamando <xref:System.String.Split%2A> com uma lista dos delineadores. Em seguida, cada palavra da frase será exibida separadamente.  
  
## <a name="example"></a>Exemplo  
  
```  
// regex_split.cpp  
// compile with: /clr  
using namespace System;  
  
int main()  
{  
   String^ delimStr = " ,.:\t";  
   Console::WriteLine( "delimiter : '{0}'", delimStr );  
   array<Char>^ delimiter = delimStr->ToCharArray( );  
   array<String^>^ words;  
   String^ line = "one\ttwo three:four,five six seven";  
  
   Console::WriteLine( "text : '{0}'", line );  
   words = line->Split( delimiter );  
   Console::WriteLine( "Number of Words : {0}", words->Length );  
   for (int word=0; word<words->Length; word++)  
      Console::WriteLine( "{0}", words[word] );  
  
   return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões regulares do .NET Framework](/dotnet/standard/base-types/regular-expressions)   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)