---
title: "Como escrever um arquivo bin&#225;rio (C++/CLI) | Microsoft Docs"
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
  - "arquivos binários, gravando em C++"
  - "Arquivos  [C++], binário"
ms.assetid: 35d97ee6-fc7e-4c36-be18-8bbb3b44b3ae
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como escrever um arquivo bin&#225;rio (C++/CLI)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código a seguir demonstra dados binários de gravada em um arquivo.  Duas classes do namespace de <xref:System.IO> são usadas: <xref:System.IO.FileStream> e <xref:System.IO.BinaryWriter>.  <xref:System.IO.FileStream> representa o arquivo real, quando <xref:System.IO.BinaryWriter> fornecer uma interface para o fluxo que permite acesso binário.  
  
 O exemplo de código a seguir grava um arquivo que contenha inteiros em formato binário.  Este arquivo possa ser lido pelo código em [Como ler um arquivo binário](../Topic/How%20to:%20Read%20a%20Binary%20File%20\(C++-CLI\).md).  
  
## Exemplo  
  
```  
// binary_write.cpp  
// compile with: /clr  
#using<system.dll>  
using namespace System;  
using namespace System::IO;  
  
int main()  
{  
   array<Int32>^ data = {1, 2, 3, 10000};  
  
   FileStream^ fs = gcnew FileStream("data.bin", FileMode::Create);  
   BinaryWriter^ w = gcnew BinaryWriter(fs);  
  
   try   
   {  
      Console::WriteLine("writing data to file:");  
      for (int i=0; i<data->Length; i++)  
      {  
         Console::WriteLine(data[i]);  
         w->Write(data[i]);  
      }  
   }  
   catch (Exception^)   
   {  
     Console::WriteLine("data could not be written");  
     fs->Close();  
     return -1;  
   }  
  
   fs->Close();  
   return 0;  
}  
```  
  
## Consulte também  
 [E\/S de arquivo e de fluxo](../Topic/File%20and%20Stream%20I-O.md)   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)