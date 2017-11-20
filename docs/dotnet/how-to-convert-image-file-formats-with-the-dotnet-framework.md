---
title: 'Como: Converter formatos de arquivo de imagem com o .NET Framework | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- GDI+ [C++], converting image file formats
- graphics [C++], converting image file formats
ms.assetid: 5d5384b0-b9b7-4262-b9ad-c4cb95f75ee4
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: eff94d00f92fe0a52162c986662209168974e072
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="how-to-convert-image-file-formats-with-the-net-framework"></a>Como converter formatos de arquivo de imagem com o .NET Framework
O exemplo de código a seguir demonstra o <xref:System.Drawing.Image?displayProperty=fullName> classe e o <xref:System.Drawing.Imaging.ImageFormat?displayProperty=fullName> enumeração usada para converter e salvar arquivos de imagem. O código a seguir carrega uma imagem de um arquivo. jpg e, em seguida, salva-o em formatos de arquivos. gif e. bmp.  
  
> [!NOTE]
>  GDI+ está incluído no Windows XP, Windows Server 2003 e Windows Vista e está disponível como um redistribuível para o Windows 2000. Para baixar o redistribuível mais recente, consulte [http://go.microsoft.com/fwlink/?linkid=11232](http://go.microsoft.com/fwlink/?linkid=11232).   
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="see-also"></a>Consulte também  
 <xref:System.Drawing>   
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)