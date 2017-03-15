---
title: "Como converter formatos de arquivo de imagem com o .NET Framework | Microsoft Docs"
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
  - "GDI+ [C++], convertendo formatos de arquivo de imagem"
  - "gráficos [C++], convertendo formatos de arquivo de imagem"
ms.assetid: 5d5384b0-b9b7-4262-b9ad-c4cb95f75ee4
caps.latest.revision: 13
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como converter formatos de arquivo de imagem com o .NET Framework
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código a seguir demonstra a classe de <xref:System.Drawing.Image?displayProperty=fullName> e a enumeração de <xref:System.Drawing.Imaging.ImageFormat?displayProperty=fullName> usadas para converter e salvar arquivos de imagem.  O código a seguir carrega uma imagem de um arquivo .jpg e a salva em ambos os formatos de .gif e arquivos .bmp.  
  
> [!NOTE]
>  GDI\+ está incluído no Windows XP, 2003, Windows Server e Windows Vista e está disponível como um redistribuível para Windows 2000.  Para baixar o redistribuível o último, consulte [http:\/\/go.microsoft.com\/fwlink\/?linkid\=11232](http://go.microsoft.com/fwlink/?linkid=11232).  Para obter mais informações, consulte [GDI\+](_gdiplus_GDI_start_cpp).  
  
## Exemplo  
  
```  
#using <system.drawing.dll>  
  
using namespace System;  
using namespace System::Drawing;  
using namespace System::Drawing::Imaging;  
  
int main()  
{  
   Image^ image = Image::FromFile("SampleImage.jpg");  
   image->Save("SampleImage.png", ImageFormat::Png);  
   image->Save("SampleImage.bmp", ImageFormat::Bmp);  
  
   return 0;  
}  
```  
  
## Consulte também  
 <xref:System.Drawing>   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)