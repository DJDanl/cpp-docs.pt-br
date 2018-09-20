---
title: Operações de gráficos (C + + / CLI) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-cli
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- GDI+ [C++]
- .NET Framework [C++], graphics
- images [C++], .NET Framework and
- GDI+ [C++], about graphics operations
- graphics [C++], .NET Framework and
- GDI+ [C++], displaying images
- graphics [C++], displaying images
- GDI+, drawing shapes
- drawing, shapes
- shapes
- shapes, drawing
- GDI+ [C++], rotating images
- graphics [C++], rotating images
- GDI+ [C++], converting image file formats
- graphics [C++], converting image file formats
ms.assetid: bba27228-b9b3-4c9c-b31c-a04b76702a95
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: fd3c988f28e8de864fd22790ad60b49f1b6340b3
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46438543"
---
# <a name="graphics-operations-ccli"></a>Operações de gráficos (C++/CLI)

Demonstra a manipulação de imagens usando o SDK do Windows.

Os tópicos a seguir demonstram o uso da <xref:System.Drawing.Image?displayProperty=fullName> classe para executar a manipulação de imagem.

## <a name="display"></a> Exibir imagens com o .NET Framework

O exemplo de código a seguir modifica o manipulador de evento OnPaint para recuperar um ponteiro para o <xref:System.Drawing.Graphics> objeto para o formulário principal. O <xref:System.Windows.Forms.Form.OnPaint%2A> função destina-se um aplicativo Windows Forms, provavelmente criado com um Assistente de aplicativo do Visual Studio.

A imagem é representada pelo <xref:System.Drawing.Image> classe. Os dados da imagem são carregados de um arquivo. jpg utilizando o <xref:System.Drawing.Image.FromFile%2A?displayProperty=fullName> método. Antes da imagem é desenhada ao formulário, o formulário é redimensionado para acomodar a imagem. O desenho da imagem é executado com o <xref:System.Drawing.Graphics.DrawImage%2A?displayProperty=fullName> método.

O <xref:System.Drawing.Graphics> e <xref:System.Drawing.Image> classes estiverem no <xref:System.Drawing?displayProperty=fullName> namespace.

### <a name="example"></a>Exemplo

```cpp
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

## <a name="draw"></a> Desenhar formas com o .NET Framework

O seguinte exemplo de código usa o <xref:System.Drawing.Graphics> classe para modificar os <xref:System.Windows.Forms.Form.OnPaint%2A> manipulador de eventos para recuperar um ponteiro para o <xref:System.Drawing.Graphics> objeto para o formulário principal. Esse ponteiro é usado para definir a cor do plano de fundo do formulário e desenhar uma linha e um arco usando o <xref:System.Drawing.Graphics.DrawLine%2A?displayProperty=fullName> e <xref:System.Drawing.Graphics.DrawArc%2A> métodos.

### <a name="example"></a>Exemplo

```cpp
#using <system.drawing.dll>
using namespace System;
using namespace System::Drawing;
// ...
protected:
virtual Void Form1::OnPaint(PaintEventArgs^ pe ) override
{
   Graphics^ g = pe->Graphics;
   g->Clear(Color::AntiqueWhite);

   Rectangle rect = Form::ClientRectangle;
   Rectangle smallRect;
   smallRect.X = rect.X + rect.Width / 4;
   smallRect.Y = rect.Y + rect.Height / 4;
   smallRect.Width = rect.Width / 2;
   smallRect.Height = rect.Height / 2;

   Pen^ redPen = gcnew Pen(Color::Red);
   redPen->Width = 4;
   g->DrawLine(redPen, 0, 0, rect.Width, rect.Height);

   Pen^ bluePen = gcnew Pen(Color::Blue);
   bluePen->Width = 10;
   g->DrawArc( bluePen, smallRect, 90, 270 );
}
```

## <a name="rotate"></a> Girar imagens com o .NET Framework

O exemplo de código a seguir demonstra o uso da <xref:System.Drawing.Image?displayProperty=fullName> classe para carregar uma imagem do disco, girá-lo 90 graus e salvá-lo como um novo arquivo. jpg.

### <a name="example"></a>Exemplo

```cpp
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

## <a name="convert"></a> Converter formatos de arquivo de imagem com o .NET Framework

O exemplo de código a seguir demonstra a <xref:System.Drawing.Image?displayProperty=fullName> classe e o <xref:System.Drawing.Imaging.ImageFormat?displayProperty=fullName> enumeração usada para converter e salvar arquivos de imagem. O código a seguir carrega uma imagem de um arquivo. jpg e, em seguida, salva-o em formatos de arquivo. gif e. bmp.

### <a name="example"></a>Exemplo

```cpp
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

## <a name="related-sections"></a>Seções relacionadas

[Introdução à Programação de Elementos Gráficos](/dotnet/framework/winforms/advanced/getting-started-with-graphics-programming)

[Sobre o Código Gerenciado no GDI+](/dotnet/framework/winforms/advanced/about-gdi-managed-code)

## <a name="see-also"></a>Consulte também

[Programação do .NET com C++/CLI (Visual C++)](../dotnet/dotnet-programming-with-cpp-cli-visual-cpp.md)

<xref:System.Drawing>
