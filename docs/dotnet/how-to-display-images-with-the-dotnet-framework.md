---
title: "Como exibir imagens com o .NET Framework | Microsoft Docs"
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
  - "GDI+ [C++], exibindo imagens"
  - "gráficos [C++], exibindo imagens"
ms.assetid: c0eddfa1-4bd6-4af5-a533-1fa84b360325
caps.latest.revision: 16
caps.handback.revision: 16
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como exibir imagens com o .NET Framework
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O exemplo de código a seguir altera o manipulador de eventos de OnPaint para recuperar um ponteiro para o objeto de <xref:System.Drawing.Graphics> para o formulário principal.  A função de <xref:System.Windows.Forms.Form.OnPaint%2A> foi desenvolvida para um aplicativo Windows Forms, provavelmente criado com um assistente do aplicativo do Visual Studio.  
  
 A imagem é representada pela classe de <xref:System.Drawing.Image> .  Os dados de imagem são carregados de um arquivo .jpg usando o método de <xref:System.Drawing.Image.FromFile%2A?displayProperty=fullName> .  Antes que ela esteja desenhada no formato, o formulário será redimensionado para acomodar a imagem.  O desenho da imagem é executado com o método de <xref:System.Drawing.Graphics.DrawImage%2A?displayProperty=fullName> .  
  
 As classes de <xref:System.Drawing.Graphics> e de <xref:System.Drawing.Image> ambas estão no namespace de <xref:System.Drawing?displayProperty=fullName> .  
  
> [!NOTE]
>  GDI\+ está incluído no Windows XP e está disponível como um redistribuível para SP 6 do Windows NT 4,0, Windows 2000, Windows 98, Windows e Me.  Para baixar o redistribuível o último, consulte [http:\/\/go.microsoft.com\/fwlink\/?linkid\=11232](http://go.microsoft.com/fwlink/?linkid=11232).  Para obter mais informações, consulte a documentação do SDK em [GDI\+](_gdiplus_GDI_start_cpp)GDI\+.  
  
## Exemplo  
  
```  
#using <system.drawing.dll>  
  
using namespace System;  
using namespace System::Drawing;  
  
protected:  
virtual Void Form1::OnPaint(PaintEventArgs^ pe) override  
{  
    Graphics^ g = pe->Graphics;  
    Image^ image = Image::FromFile("SampleImage.jpg");  
    Form::ClientSize = image->Size;  
    g->DrawImage( image, 0, 0, image->Size.Width, image->Size.Height );  
}  
```  
  
## Consulte também  
 <xref:System.Drawing?displayProperty=fullName>   
 [Programação do .NET com o C \+ \+ \/ CLI \(Visual C\+\+\)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)