---
title: 'Como: usar expressões regulares para extrair campos de dados (C + + CLI) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- strings [C++], extracting data from
- formatted strings [C++]
- regular expressions [C++], extracting data fields
- data [C++], extracting from strings
ms.assetid: b581d9b6-630e-48fa-94fe-20b0f7b89b06
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 20e1139ccee0c3cc1533f42fb1b9e1eafaca3afd
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="how-to-use-regular-expressions-to-extract-data-fields-ccli"></a>Como usar expressões regulares para extrair campos de dados (C++/CLI)
O exemplo de código a seguir demonstra o uso de expressões regulares para extrair dados de uma cadeia de caracteres formatada. O seguinte exemplo de código usa a <xref:System.Text.RegularExpressions.Regex> classe para especificar um padrão que corresponde ao endereço de email. Esse padrão inclui identificadores de campo que podem ser usados para recuperar o usuário e partes de nome de host de cada endereço de email. O <xref:System.Text.RegularExpressions.Match> classe é usada para executar a correspondência de padrão real. Se o endereço de email fornecido é válido, o nome de usuário e nomes de host são extraídos e exibidos.  
  
## <a name="example"></a>Exemplo  
  
```  
// Regex_extract.cpp  
// compile with: /clr  
#using <System.dll>  
  
using namespace System;  
using namespace System::Text::RegularExpressions;  
  
int main()  
{  
    array<String^>^ address=  
    {  
        "jay@southridgevideo.com",  
        "barry@adatum.com",  
        "treyresearch.net",  
        "karen@proseware.com"  
    };  
  
    Regex^ emailregex = gcnew Regex("(?<user>[^@]+)@(?<host>.+)");  
  
    for (int i=0; i<address->Length; i++)  
    {  
        Match^ m = emailregex->Match( address[i] );  
        Console::Write("\n{0,25}", address[i]);  
  
        if ( m->Success )   
        {  
            Console::Write("   User='{0}'",   
            m->Groups["user"]->Value);  
            Console::Write("   Host='{0}'",   
            m->Groups["host"]->Value);  
        }  
        else   
            Console::Write("   (invalid email address)");  
        }  
  
    Console::WriteLine("");  
    return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões regulares do .NET Framework](/dotnet/standard/base-types/regular-expressions)   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)