---
title: "Como usar express&#245;es regulares para extrair campos de dados (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "dados [C++], extraindo de cadeias de caracteres"
  - "cadeias de caracteres formatadas [C++]"
  - "expressões regulares [C++], extraindo campos de dados"
  - "cadeias de caracteres [C++], extraindo dados de"
ms.assetid: b581d9b6-630e-48fa-94fe-20b0f7b89b06
caps.latest.revision: 11
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como usar express&#245;es regulares para extrair campos de dados (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código a seguir demonstra o uso de expressões regulares extrair dados de uma cadeia de caracteres formatada.  O exemplo de código usa a classe de <xref:System.Text.RegularExpressions.Regex> para especificar um padrão que corresponde a um endereço de email.  Este alinhador longitudinal inclui os identificadores do campo que podem ser usados para recuperar o usuário e as partes do nome de host de cada endereço de email.  A classe de <xref:System.Text.RegularExpressions.Match> é usada para executar a correspondência de padrão real.  Se o endereço de email fornecido é válido, o nome de usuário e os nomes de host são extraídos e exibidos.  
  
## Exemplo  
  
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
  
## Consulte também  
 [Expressões regulares do .NET Framework](../Topic/.NET%20Framework%20Regular%20Expressions.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)