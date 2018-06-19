---
title: 'Como: exibir imagens com o .NET Framework | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- GDI+ [C++], displaying images
- graphics [C++], displaying images
ms.assetid: c0eddfa1-4bd6-4af5-a533-1fa84b360325
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 4a7f3ed2d8fe90501b5ef3d0ae5028890fe5290e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33128573"
---
# <a name="how-to-display-images-with-the-net-framework"></a>Como exibir imagens com o .NET Framework
O exemplo de código a seguir modifica o manipulador de eventos OnPaint para recuperar um ponteiro para o <xref:System.Drawing.Graphics> objeto para o formulário principal. O <xref:System.Windows.Forms.Form.OnPaint%2A> função destina-se um aplicativo do Windows Forms, provavelmente criado com um Assistente de aplicativo do Visual Studio.  
  
 A imagem é representada pela <xref:System.Drawing.Image> classe. Os dados de imagem serão carregados a partir de um arquivo. jpg usando o <xref:System.Drawing.Image.FromFile%2A?displayProperty=fullName> método. Antes que a imagem é desenhada para o formulário, o formulário é redimensionado para acomodar a imagem. O desenho da imagem é executado com o <xref:System.Drawing.Graphics.DrawImage%2A?displayProperty=fullName> método.  
  
 O <xref:System.Drawing.Graphics> e <xref:System.Drawing.Image> classes estiverem no <xref:System.Drawing?displayProperty=fullName> namespace.  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="see-also"></a>Consulte também  
 <xref:System.Drawing?displayProperty=fullName>   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)