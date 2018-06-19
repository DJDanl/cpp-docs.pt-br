---
title: 'Como: gravar um arquivo de texto (C + + CLI) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- files [C++], text
- text files, writing in C++
ms.assetid: 39ecdba6-84e0-485c-a202-84cf6d7b8d4a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 7e0ce3839a5d0a0668d921a2d64cb0cf7bd1c775
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33131235"
---
# <a name="how-to-write-a-text-file-ccli"></a>Como escrever um arquivo de texto (C++/CLI)
O exemplo de código a seguir demonstra como criar um arquivo de texto e escrever texto usando o <xref:System.IO.StreamWriter> classe, que é definida no <xref:System.IO> namespace. O <xref:System.IO.StreamWriter> construtor usa o nome do arquivo a ser criado. Se o arquivo existir, ele será substituído (a menos que você passar True como o segundo <xref:System.IO.StringWriter> argumento de construtor).  
  
 O arquivo é arquivado, em seguida, usando o <xref:System.IO.StreamWriter.Write%2A> e <xref:System.IO.TextWriter.WriteLine%2A> funções.  
  
## <a name="example"></a>Exemplo  
  
```  
// text_write.cpp  
// compile with: /clr  
using namespace System;  
using namespace System::IO;  
  
int main()   
{  
   String^ fileName = "textfile.txt";  
  
   StreamWriter^ sw = gcnew StreamWriter(fileName);  
   sw->WriteLine("A text file is born!");  
   sw->Write("You can use WriteLine");  
   sw->WriteLine("...or just Write");  
   sw->WriteLine("and do {0} output too.", "formatted");  
   sw->WriteLine("You can also send non-text objects:");  
   sw->WriteLine(DateTime::Now);  
   sw->Close();  
   Console::WriteLine("a new file ('{0}') has been written", fileName);  
  
   return 0;  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Arquivos e fluxo de e-S](http://msdn.microsoft.com/Library/4f4a33a9-66b7-4cd7-a285-4ad3e4276cd2)   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)