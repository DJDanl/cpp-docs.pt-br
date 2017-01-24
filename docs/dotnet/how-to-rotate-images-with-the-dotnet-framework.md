---
title: "Como girar imagens com o .NET Framework | Microsoft Docs"
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
  - "GDI+ [C++], girando imagens"
  - "gráficos [C++], girando imagens"
ms.assetid: e32104d5-87d0-47a9-a22f-9bc835b7e8d7
caps.latest.revision: 12
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como girar imagens com o .NET Framework
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código a seguir demonstra o uso da classe de <xref:System.Drawing.Image?displayProperty=fullName> carregar uma imagem de disco, girar\-la 90 graus, e salvá\-lo em um novo arquivo .jpg.  
  
> [!NOTE]
>  GDI\+ está incluído no Windows XP e está disponível como um redistribuível para SP 6 do Windows NT 4,0, Windows 2000, Windows 98, Windows e Millennium Edition.  Para baixar o redistribuível o último, consulte [http:\/\/go.microsoft.com\/fwlink\/?linkid\=11232](http://go.microsoft.com/fwlink/?linkid=11232).  Para obter mais informações, consulte [GDI\+](_gdiplus_GDI_start_cpp).  
  
## Exemplo  
  
```  
#using <system.drawing.dll>  
  
using namespace System;  
using namespace System::Drawing;  
  
int main()  
{  
   Image^ image = Image::FromFile("SampleImage.jpg");  
   image->RotateFlip( RotateFlipType::Rotate90FlipNone );  
   image->Save("SampleImage_rotated.jpg");  
   return 0;  
}  
```  
  
## Consulte também  
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)