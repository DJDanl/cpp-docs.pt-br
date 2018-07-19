---
title: Expressões regulares (C + + / CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- regular expressions [C++]
- .NET Framework [C++], regular expressions
- regular expressions [C++], about regular expressions
- parsing strings [C++]
- examples [C++], strings
- regular expressions [C++], parsing strings
- Split method, parsing strings
- strings [C++], parsing
- substrings, simple matches
- searching, exact substring matches
- strings [C++], exact substring matching
- regular expressions [C++], simple matching
- IsMatch method
- strings [C++], extracting data from
- formatted strings [C++]
- regular expressions [C++], extracting data fields
- data [C++], extracting from strings
- regular expressions [C++], rearranging data
- data [C++], rearranging
- search and replace
- Replace method
- regular expressions [C++], search and replace
- strings [C++], formatting
- data [C++], formatting
- regular expressions [C++], validating data formatting
ms.assetid: 838bab49-0dbc-4089-a604-ef146269ef5a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: c11a75d5d97f4e8b7f3487b0ff2bd0173f29366f
ms.sourcegitcommit: 9ad287c88bdccee2747832659fe50c2e5d682a0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/13/2018
ms.locfileid: "39034719"
---
# <a name="regular-expressions-ccli"></a>Expressões regulares (C++/CLI)
Demonstra várias operações de cadeia de caracteres usando classes de expressões regulares no .NET Framework.  
  
 Os tópicos a seguir demonstram o uso do .NET Framework <xref:System.Text.RegularExpressions> namespace (e, em um caso de <xref:System.String.Split%2A?displayProperty=fullName> método) para pesquisar, analisar e modificar cadeias de caracteres.  

## <a name="parse_regex"></a> Analisar cadeias de caracteres usando expressões regulares
O exemplo de código a seguir demonstra a análise de cadeia de caracteres simple usando o <xref:System.Text.RegularExpressions.Regex> classe o <xref:System.Text.RegularExpressions?displayProperty=fullName> namespace. Uma cadeia de caracteres que contém vários tipos de delineadores do word é construída. A cadeia de caracteres, em seguida, é analisada usando o <xref:System.Text.RegularExpressions.Regex> classe junto com o <xref:System.Text.RegularExpressions.Match> classe. Em seguida, cada palavra na frase será exibida separadamente.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// regex_parse.cpp  
// compile with: /clr  
#using <system.dll>  
  
using namespace System;  
using namespace System::Text::RegularExpressions;  
  
int main( )  
{  
   int words = 0;  
   String^ pattern = "[a-zA-Z]*";  
   Console::WriteLine( "pattern : '{0}'", pattern );  
   Regex^ regex = gcnew Regex( pattern );  
  
   String^ line = "one\ttwo three:four,five six  seven";     
   Console::WriteLine( "text : '{0}'", line );  
   for( Match^ match = regex->Match( line );   
        match->Success; match = match->NextMatch( ) )   
   {  
      if( match->Value->Length > 0 )  
      {  
         words++;  
         Console::WriteLine( "{0}", match->Value );  
      }  
   }  
   Console::WriteLine( "Number of Words : {0}", words );  
  
   return 0;  
}  
```  

## <a name="parse_split"></a> Analisar cadeias de caracteres usando o método Split
O exemplo de código a seguir demonstra como usar o <xref:System.String.Split%2A?displayProperty=fullName> método para extrair cada palavra de uma cadeia de caracteres. Uma cadeia de caracteres que contém vários tipos de delineadores do word é construída e, em seguida, analisada chamando <xref:System.String.Split%2A> com uma lista das delineadores. Em seguida, cada palavra na frase será exibida separadamente.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
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

## <a name="regex_simple"></a> Usar expressões regulares para correspondência simples
O exemplo de código a seguir usa expressões regulares para procurar as correspondências exatas de subcadeia de caracteres. A pesquisa é realizada pelo estático <xref:System.Text.RegularExpressions.Regex.IsMatch%2A> método, que usa duas cadeias de caracteres como entrada. A primeira é a cadeia de caracteres a ser pesquisada e a segunda é o padrão a ser procurado.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// regex_simple.cpp  
// compile with: /clr  
#using <System.dll>  
  
using namespace System;  
using namespace System::Text::RegularExpressions;  
  
int main()  
{  
   array<String^>^ sentence =   
   {  
      "cow over the moon",  
      "Betsy the Cow",  
      "cowering in the corner",  
      "no match here"  
   };  
  
   String^ matchStr = "cow";  
   for (int i=0; i<sentence->Length; i++)  
   {  
      Console::Write( "{0,24}", sentence[i] );  
      if ( Regex::IsMatch( sentence[i], matchStr,  
                     RegexOptions::IgnoreCase ) )  
         Console::WriteLine("  (match for '{0}' found)", matchStr);  
      else  
         Console::WriteLine("");  
   }  
   return 0;  
}  
```  

## <a name="regex_extract"></a> Usar expressões regulares para extrair campos de dados
O exemplo de código a seguir demonstra o uso de expressões regulares para extrair dados de uma cadeia de caracteres formatada. O seguinte exemplo de código usa o <xref:System.Text.RegularExpressions.Regex> classe para especificar um padrão que corresponde ao endereço de email. Esse padrão inclui os identificadores de campo que podem ser usados para recuperar o usuário e partes de nome de host de cada endereço de email. O <xref:System.Text.RegularExpressions.Match> classe é usada para executar a correspondência de padrão real. Se o endereço de email fornecido é válido, o nome de usuário e nomes de host são extraídos e exibidos.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
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

## <a name="regex_rearrange"></a> Usar expressões regulares para reorganizar dados
O exemplo de código a seguir demonstra como o suporte a expressões regulares do .NET Framework pode ser usado para reorganizar ou reformatar os dados. O seguinte exemplo de código usa o <xref:System.Text.RegularExpressions.Regex> e <xref:System.Text.RegularExpressions.Match> classes para extrair os nomes e sobrenomes de uma cadeia de caracteres e, em seguida, exibir esses nomes de elementos na ordem inversa.  
  
 O <xref:System.Text.RegularExpressions.Regex> classe é usada para construir uma expressão regular que descreve o formato atual dos dados. Os dois nomes devem ser separados por uma vírgula e podem usar qualquer quantidade de espaço em branco em torno de vírgulas. O <xref:System.Text.RegularExpressions.Match> método é usado para analisar cada cadeia de caracteres. Se for bem-sucedido, os nomes e sobrenomes são recuperados do <xref:System.Text.RegularExpressions.Match> do objeto e exibido.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// regex_reorder.cpp  
// compile with: /clr  
#using <System.dll>  
using namespace System;  
using namespace Text::RegularExpressions;  
  
int main()  
{  
   array<String^>^ name =   
   {  
      "Abolrous, Sam",   
      "Berg,Matt",   
      "Berry , Jo",  
      "www.contoso.com"  
   };  
  
   Regex^ reg = gcnew Regex("(?<last>\\w*)\\s*,\\s*(?<first>\\w*)");  
  
   for ( int i=0; i < name->Length; i++ )  
   {  
      Console::Write( "{0,-20}", name[i] );  
      Match^ m = reg->Match( name[i] );  
      if ( m->Success )  
      {  
         String^ first = m->Groups["first"]->Value;  
         String^ last = m->Groups["last"]->Value;  
         Console::WriteLine("{0} {1}", first, last);  
      }  
      else  
         Console::WriteLine("(invalid)");  
   }  
   return 0;  
}  
```  

## <a name="regex_search"></a> Usar expressões regulares para pesquisar e substituir
O exemplo de código a seguir demonstra como a classe de expressão regular <xref:System.Text.RegularExpressions.Regex> pode ser usado para executar a pesquisa e substituição. Isso é feito com o <xref:System.Text.RegularExpressions.Regex.Replace%2A> método. A versão usada usa duas cadeias de caracteres como entrada: a cadeia de caracteres a ser modificado e a cadeia de caracteres a ser inserido no lugar de seções (se houver) que correspondem ao padrão fornecido para o <xref:System.Text.RegularExpressions.Regex> objeto.  
  
 Esse código substitui todos os dígitos em uma cadeia de caracteres com sublinhados (_) e, em seguida, substitui aqueles com uma cadeia de caracteres vazia, removendo efetivamente-los. O mesmo efeito pode ser feito em uma única etapa, mas duas etapas são usadas aqui para fins de demonstração.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
// regex_replace.cpp  
// compile with: /clr  
#using <System.dll>  
using namespace System::Text::RegularExpressions;  
using namespace System;  
  
int main()  
{  
   String^ before = "The q43uick bro254wn f0ox ju4mped";  
   Console::WriteLine("original  : {0}", before);  
  
   Regex^ digitRegex = gcnew Regex("(?<digit>[0-9])");  
   String^ after = digitRegex->Replace(before, "_");  
   Console::WriteLine("1st regex : {0}", after);  
  
   Regex^ underbarRegex = gcnew Regex("_");  
   String^ after2 = underbarRegex->Replace(after, "");  
   Console::WriteLine("2nd regex : {0}", after2);  
  
   return 0;  
}  
```  

## <a name="regex_validate"></a> Usar expressões regulares para validar formatação de dados
O exemplo de código a seguir demonstra o uso de expressões regulares para verificar a formatação de uma cadeia de caracteres. No exemplo de código a seguir, a cadeia de caracteres deve conter um número de telefone válido. O exemplo de código a seguir usa a cadeia de caracteres "\d{3}-\d{3}-\d{4}" para indicar que cada campo representa um número de telefone válido. Na cadeia de caracteres "d" indica um dígito e o argumento após cada "d" indica o número de dígitos que devem estar presentes. Nesse caso, o número é necessário ser separados por traços.  
  
### <a name="example"></a>Exemplo  
  
```cpp  
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

## <a name="related-sections"></a>Seções relacionadas  
 [Expressões regulares do .NET Framework](/dotnet/standard/base-types/regular-expressions)  
  
## <a name="see-also"></a>Consulte também  
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)