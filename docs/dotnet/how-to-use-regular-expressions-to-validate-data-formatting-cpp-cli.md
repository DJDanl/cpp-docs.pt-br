---
title: Usar expressões regulares para validar formatação (C + + CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- strings [C++], formatting
- data [C++], formatting
- regular expressions [C++], validating data formatting
ms.assetid: 225775c3-3efc-4734-bde2-1fdf73e3d397
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 59a553ac2d58f9304fce3961aa8212c33b26643a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33129610"
---
# <a name="how-to-use-regular-expressions-to-validate-data-formatting-ccli"></a>Como usar expressões regulares para validar formatação de dados (C++/CLI)
O exemplo de código a seguir demonstra o uso de expressões regulares para verificar a formatação de uma cadeia de caracteres. No exemplo de código a seguir, a cadeia de caracteres deve conter um número de telefone válido. O exemplo de código a seguir usa a cadeia de caracteres "\d{3}-\d{3}-\d{4}" para indicar que cada campo representa um número de telefone válido. "D" na cadeia de caracteres indica um dígito, e o argumento após cada "d" indica o número de dígitos que deve estar presente. Nesse caso, o número é necessário para ser separados por traços.  
  
## <a name="example"></a>Exemplo  
  
```  
// regex_validate.cpp  
// compile with: /clr  
#using <System.dll>  
  
using namespace System;  
using namespace Text::RegularExpressions;  
  
int main()  
{  
   array<String^>^ number =   
   {  
      "123-456-7890",   
      "444-234-22450",   
      "690-203-6578",   
      "146-893-232",  
      "146-839-2322",  
      "4007-295-1111",   
      "407-295-1111",   
      "407-2-5555",   
   };  
  
   String^ regStr = "^\\d{3}-\\d{3}-\\d{4}$";  
  
   for ( int i = 0; i < number->Length; i++ )  
   {  
      Console::Write( "{0,14}", number[i] );  
  
      if ( Regex::IsMatch( number[i], regStr ) )  
         Console::WriteLine(" - valid");  
      else  
         Console::WriteLine(" - invalid");  
   }  
   return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões regulares do .NET Framework](/dotnet/standard/base-types/regular-expressions)   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)