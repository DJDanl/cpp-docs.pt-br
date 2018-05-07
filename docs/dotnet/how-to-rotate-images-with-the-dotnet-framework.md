---
title: 'Como: Girar imagens com o .NET Framework | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- GDI+ [C++], rotating images
- graphics [C++], rotating images
ms.assetid: e32104d5-87d0-47a9-a22f-9bc835b7e8d7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: 94290c05ecca9fc7211e2bc85640ec0308137804
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="how-to-rotate-images-with-the-net-framework"></a>Como girar imagens com o .NET Framework
O exemplo de código a seguir demonstra o uso da <xref:System.Drawing.Image?displayProperty=fullName> classe para carregar uma imagem de disco, gira 90 graus e salvá-lo como um novo arquivo. jpg.  
  
## <a name="example"></a>Exemplo  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)