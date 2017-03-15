---
title: "Como ler um arquivo de texto (C++/CLI) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
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
  - "lendo arquivos de texto"
  - "arquivos de texto, lendo"
ms.assetid: 80551c01-d769-4b6d-8db7-fd53bde21b62
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como ler um arquivo de texto (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código demonstra como abrir e ler um arquivo de texto uma linha por vez, usando a classe <xref:System.IO.StreamReader>, que é definida no namespace <xref:System.IO?displayProperty=fullName>.  Uma instância dessa classe é usada para abrir um arquivo de texto e o método <xref:System.IO.StreamReader.ReadLine%2A?displayProperty=fullName> é usado para recuperar cada linha.  
  
 Esse exemplo de código lê um arquivo chamado textfile.txt e contém o texto.  Para obter informações sobre esse tipo de arquivo, consulte [Como escrever um arquivo de texto](../Topic/How%20to:%20Write%20a%20Text%20File%20\(C++-CLI\).md).  
  
## Exemplo  
  
```  
// text_read.cpp  
// compile with: /clr  
#using<system.dll>  
using namespace System;  
using namespace System::IO;  
  
int main()  
{  
   String^ fileName = "textfile.txt";  
   try   
   {  
      Console::WriteLine("trying to open file {0}...", fileName);  
      StreamReader^ din = File::OpenText(fileName);  
  
      String^ str;  
      int count = 0;  
      while ((str = din->ReadLine()) != nullptr)   
      {  
         count++;  
         Console::WriteLine("line {0}: {1}", count, str );  
      }  
   }  
   catch (Exception^ e)  
   {  
      if (dynamic_cast<FileNotFoundException^>(e))  
         Console::WriteLine("file '{0}' not found", fileName);  
      else  
         Console::WriteLine("problem reading file '{0}'", fileName);  
   }  
  
   return 0;  
}  
```  
  
## Consulte também  
 [E\/S de arquivo e de fluxo](../Topic/File%20and%20Stream%20I-O.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)