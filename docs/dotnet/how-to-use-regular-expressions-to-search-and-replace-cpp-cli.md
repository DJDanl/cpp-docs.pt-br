---
title: 'Como: usar expressões regulares para pesquisar e substituir (C + + CLI) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- search and replace
- Replace method
- regular expressions [C++], search and replace
ms.assetid: 12fe3e18-fe10-4b25-a221-19dc5eab3821
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: feb64670accef1cdcc5eedf9aa2b081dc41615b6
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33132408"
---
# <a name="how-to-use-regular-expressions-to-search-and-replace-ccli"></a>Como usar expressões regulares para pesquisar e substituir (C++/CLI)
O exemplo de código a seguir demonstra como a classe de expressão regular <xref:System.Text.RegularExpressions.Regex> podem ser usados para executar a pesquisa e substituição. Isso é feito com o <xref:System.Text.RegularExpressions.Regex.Replace%2A> método. A versão usada usa duas cadeias de caracteres como entrada: a cadeia de caracteres a ser modificado e a cadeia de caracteres a ser inserido no lugar de seções (se houver) que correspondem ao padrão fornecido para o <xref:System.Text.RegularExpressions.Regex> objeto.  
  
 Esse código substitui todos os números em uma cadeia de caracteres com sublinhados (_) e, em seguida, substitui aqueles com uma cadeia de caracteres vazia, efetivamente removê-los. O mesmo efeito que pode ser realizado em uma única etapa, mas as duas etapas são usadas aqui para fins de demonstração.  
  
## <a name="example"></a>Exemplo  
  
```  
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
  
## <a name="see-also"></a>Consulte também  
 [Expressões regulares do .NET Framework](/dotnet/standard/base-types/regular-expressions)   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)