---
title: Obtendo ponteiros para buffers de dados (C++/CX)
ms.date: 11/19/2018
ms.assetid: db4f9370-dd95-4896-b5b8-4b202284f579
ms.openlocfilehash: 46a81fa9e3d278645b654dca3c652653f6c21037
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62162299"
---
# <a name="obtaining-pointers-to-data-buffers-ccx"></a>Obtendo ponteiros para buffers de dados (C++/CX)

No Tempo de Execução do Windows, a interface [Windows::Storage::Streams::IBuffer](/uwp/api/windows.storage.streams.ibuffer) oferece meios baseados em transmissão de linguagem neutra para acessar buffers de dados. Em C++, você pode obter um ponteiro bruto para a matriz de bytes subjacente usando a interface IBufferByteAccess da Biblioteca em Tempo de Execução do Windows definida em robuffer.h. Usando essa abordagem, você pode modificar a matriz de bytes in-loco sem fazer cópias desnecessárias dos dados.

O diagrama a seguir mostra um elemento de imagem XAML, cuja origem é um [Windows::UI::Xaml::Media::Imaging WriteableBitmap](/uwp/api/Windows.UI.Xaml.Media.Imaging.WriteableBitmap). Um aplicativo cliente escrito em qualquer linguagem pode transmitir uma referência ao `WriteableBitmap` para o código C++, e o C++ pode usar a referência para obter o buffer subjacente. Em um aplicativo de plataforma Universal do Windows que está escrito em C++, você pode usar a função no exemplo a seguir diretamente no código-fonte sem empacotá-la em um componente de tempo de execução do Windows.

![C&#43; &#43; o código que acessa dados de pixel diretamente](../cppcx/media/ibufferbyteaccessdiagram.png "C&#43; &#43; o código que acessa dados de pixel diretamente")

## <a name="getpointertopixeldata"></a>GetPointerToPixelData

O método a seguir aceita um [Windows::Storage::Streams::IBuffer](/uwp/api/windows.storage.streams.ibuffer) e retorna um ponteiro bruto à matriz de bytes subjacente. Para chamar a função, transmita a propriedade [WriteableBitmap::PixelBuffer](/uwp/api/windows.ui.xaml.media.imaging.writeablebitmap.pixelbuffer) .

```cpp
#include <wrl.h>
#include <robuffer.h>
using namespace Windows::Storage::Streams;
using namespace Microsoft::WRL;
typedef uint8 byte;
// Retrieves the raw pixel data from the provided IBuffer object.
// Warning: The lifetime of the returned buffer is controlled by
// the lifetime of the buffer object that's passed to this method.
// When the buffer has been released, the pointer becomes invalid
// and must not be used.
byte* Class1::GetPointerToPixelData(IBuffer^ pixelBuffer, unsigned int *length)
{
    if (length != nullptr)
    {
        *length = pixelBuffer ->Length;
    }
    // Query the IBufferByteAccess interface.
    ComPtr<IBufferByteAccess> bufferByteAccess;
    reinterpret_cast<IInspectable*>( pixelBuffer)->QueryInterface(IID_PPV_ARGS(&bufferByteAccess));

    // Retrieve the buffer data.
    byte* pixels = nullptr;
    bufferByteAccess->Buffer(&pixels);
    return pixels;
}
```

## <a name="complete-example"></a>Exemplo completo

As etapas a seguir mostram como criar um aplicativo c# Universal Windows Platform que passa um `WriteableBitmap` para uma DLL do componente de tempo de execução do C++ Windows. O código C++ obtém um ponteiro para o buffer de pixels e executa uma simples modificação in-loco na imagem. Como alternativa, você pode criar o aplicativo cliente no Visual Basic, em JavaScript ou C++ em vez de C#. Se você usar C++, o componente DLL não será necessário; basta adicionar esses métodos diretamente à classe MainPage ou qualquer outra classe que você defina.

#### <a name="create-the-client"></a>Criar o cliente

1. Use o modelo de projeto de aplicativo em branco para criar um aplicativo c# Universal Windows Platform.

1. Em MainPage.xaml

   - Use este XAML para substituir o elemento `Grid` :

        ```xml
        <Grid Background="{StaticResource ApplicationPageBackgroundThemeBrush}">
            <StackPanel HorizontalAlignment="Left" Margin="176,110,0,0" VerticalAlignment="Top" Width="932">
                <Image x:Name="Pic"/>
                <Button Content="Process Image" HorizontalAlignment="Stretch" VerticalAlignment="Stretch" Height="47" Click="Button_Click_1"/>
            </StackPanel>
        </Grid>
        ```

1. Em MainPage.xaml.cs

   1. Adicione estas declarações de namespace:

        ```csharp
        using Windows.Storage;
        using Windows.Storage.FileProperties;
        using Windows.UI.Xaml.Media.Imaging;
        using Windows.Storage.Streams;
        using Windows.Storage.Pickers;
        ```

   1. Adicione um variável de membro `WriteableBitmap` à classe `MainPage` com o nome `m_bm`.

        ```csharp
        private WriteableBitmap m_bm;
        ```

   1. Use o código a seguir para substituir o stub do método `OnNavigatedTo` . Isso abrirá o seletor de arquivos quando o aplicativo for iniciado. (Observe que a palavra-chave `async` será adicionada à assinatura da função).

        ```csharp
        async protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            FileOpenPicker openPicker = new FileOpenPicker();
            openPicker.ViewMode = PickerViewMode.Thumbnail;
            openPicker.SuggestedStartLocation = PickerLocationId.PicturesLibrary;
            openPicker.FileTypeFilter.Add(".jpg");
            openPicker.FileTypeFilter.Add(".jpeg");
            openPicker.FileTypeFilter.Add(".png");

            StorageFile file = await openPicker.PickSingleFileAsync();
            if (file != null)
            {
                // Get the size of the image for the WriteableBitmap constructor.
                ImageProperties props = await file.Properties.GetImagePropertiesAsync();
                m_bm = new WriteableBitmap((int)props.Height, (int)props.Width);
                m_bm.SetSource(await file.OpenReadAsync());
                Pic.Source = m_bm;
            }
            else
            {
                //  Handle error...
            }
        }
        ```

   1. Adicione um manipulador de eventos para o clique do botão. (Como a referência ao namespace `ImageManipCPP` ainda não foi criada, é possível que haja um sublinhado ondulado na janela do editor.)

        ```csharp
        async private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            ImageManipCPP.Class1 obj = new ImageManipCPP.Class1();
            await obj.Negativize(m_bm);
            Pic.Source = m_bm;
        }
        ```

#### <a name="create-the-c-component"></a>Criar o componente em C++

1. Adicione um novo componente de tempo de execução do C++ Windows à solução existente e nomeie- `ImageManipCPP`. Adicione uma referência a ele no projeto C# clicando com o botão direito do mouse nesse projeto em **Gerenciador de Soluções** e selecionando **Adicionar**, **Referência**.

1. Em Class1.h

   1. Adicione esse `typedef` à segunda linha, imediatamente depois de `#pragma once`:

        ```cpp
        typedef uint8 byte;
        ```

   1. Adicione o atributo `WebHostHidden` logo acima do início da declaração `Class1` .

        ```cpp
        [Windows::Foundation::Metadata::WebHostHidden]
        ```

   1. Adicione esta assinatura do método público a `Class1`:

        ```cpp
        Windows::Foundation::IAsyncAction^ Negativize(Windows::UI::Xaml::Media::Imaging::WriteableBitmap^ bm);
        ```

   1. Adicione a assinatura do método `GetPointerToPixelData` mostrado no snippet de código anterior. Verifique se esse método é privado.

1. Em Class1.cpp

   1. Adicione estas diretivas `#include` e declarações de namespace:

        ```cpp
        #include <ppltasks.h>
        #include <wrl.h>
        #include <robuffer.h>

        using namespace Windows::Storage;
        using namespace Windows::UI::Xaml::Media::Imaging;
        using namespace Windows::Storage::Streams;
        using namespace Microsoft::WRL;
        ```

   1. Adicione a implementação de `GetPointerToPixelData` do snippet de código anterior.

   1. Adicione a implementação de `Negativize`. Esse método cria um efeito semelhante a um negativo de filme invertendo cada valor de RGB no pixel. Tornamos o método assíncrono porque em imagens maiores ele pode demorar um tempo considerável para ser concluído.

        ```cpp
        IAsyncAction^ Class1::Negativize(WriteableBitmap^ bm)
        {
            unsigned int length;
            byte* sourcePixels = GetPointerToPixelData(bm->PixelBuffer, &length);
            const unsigned int width = bm->PixelWidth;
            const unsigned int height = bm->PixelHeight;

            return create_async([this, width, height, sourcePixels]
            {
                byte* temp = sourcePixels;
                for(unsigned int k = 0; k < height; k++)
                {
                    for (unsigned int i = 0; i < (width * 4); i += 4)
                    {
                        int pos = k * (width * 4) + (i);
                        temp[pos] = ~temp[pos];
                        temp[pos + 1] = ~temp[pos + 1] / 3;
                        temp[pos + 2] = ~temp[pos + 2] / 2;
                        temp[pos + 3] = ~temp[pos + 3];
                    }
                }
            });

        }
        ```

      > [!NOTE]
      > Esse método pode ser executado mais rapidamente se você usar o AMP ou a Biblioteca de Padrões Paralelos para paralelizar a operação.

1. Verifique se você tem pelo menos uma imagem na pasta de imagens e pressione F5 para compilar e executar o programa.
