---
title: "Como armazenar texto na &#193;rea de Transfer&#234;ncia (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
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
  - "Área de Transferência, armazenando texto"
  - "texto, armazenando na Área de Transferência"
ms.assetid: 9996023f-b700-47ad-8ad9-1ba201eaa5a6
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como armazenar texto na &#193;rea de Transfer&#234;ncia (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código usa o objeto de <xref:System.Windows.Forms.Clipboard> definido no namespace de <xref:System.Windows.Forms> para armazenar uma cadeia de caracteres.  Esse objeto fornece duas funções de membro: <xref:System.Windows.Forms.Clipboard.SetDataObject%2A> e <xref:System.Windows.Forms.Clipboard.GetDataObject%2A>.  Os dados são armazenados na área de transferência enviando qualquer objeto derivado de <xref:System.Object> a <xref:System.Windows.Forms.Clipboard.SetDataObject%2A>.  
  
## Exemplo  
  
```  
// store_clipboard.cpp  
// compile with: /clr  
#using <System.dll>  
#using <System.Drawing.dll>  
#using <System.Windows.Forms.dll>  
  
using namespace System;  
using namespace System::Windows::Forms;  
  
[STAThread] int main()  
{  
   String^ str = "This text is copied into the Clipboard.";  
  
   // Use 'true' as the second argument if  
   // the data is to remain in the clipboard  
   // after the program terminates.  
   Clipboard::SetDataObject(str, true);  
  
   Console::WriteLine("Added text to the Clipboard.");  
  
   return 0;  
}  
```  
  
## Consulte também  
 [Como recuperar texto a partir da Área de Transferência](../Topic/How%20to:%20Retrieve%20Text%20from%20the%20Clipboard%20\(C++-CLI\).md)   
 [Operações do Windows](../dotnet/windows-operations-cpp-cli.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)