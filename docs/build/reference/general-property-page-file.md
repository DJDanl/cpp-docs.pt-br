---
title: Página de propriedade geral (arquivo)
ms.date: 08/30/2019
f1_keywords:
- VC.Project.VCFileConfiguration.ExcludedFromBuild
- VC.Project.VCFileConfiguration.Tool
ms.assetid: 26e3711e-9e7d-4e8d-bc4c-2474538efdad
ms.openlocfilehash: 7626e161e6f59de32d426b558827c423a0bb050d
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90041374"
---
# <a name="general-property-page-file"></a>Página de propriedade geral (arquivo)

Este tópico se aplica a projetos do Windows. Para projetos não Windows, confira [Referência de página de propriedades do Linux C++](../../linux/prop-pages-linux.md).

Quando você clica com o botão direito do mouse em um nó de arquivo **Gerenciador de soluções**, a página de propriedades **geral** no nó **Propriedades de configuração** é aberta. Ele contém as seguintes propriedades:

- **Excluído da compilação**

   Especifica se o arquivo deve estar no build da configuração atual.

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCFileConfiguration.ExcludedFromBuild%2A>.

- **Conteúdo** (aplica-se somente a aplicativos UWP.) Especifica se o arquivo contém o conteúdo a ser incluído no pacote do aplicativo.

- **Tipo de item**

   O **tipo de item** especifica a ferramenta que será usada para processar o arquivo durante o processo de compilação. [Arquivos cuja extensão é conhecida pelo Visual Studio](/visualstudio/extensibility/visual-cpp-project-extensibility#project-items) têm um valor padrão nessa propriedade. Você pode especificar uma ferramenta personalizada aqui se tiver um tipo de arquivo personalizado ou desejar substituir a ferramenta padrão por um tipo de arquivo conhecido. Confira [Especificando ferramentas de build personalizadas](../specifying-custom-build-tools.md) para obter mais informações. Você também pode usar essa página de propriedades para especificar que um arquivo não faz parte do processo de compilação.

   A ilustração a seguir mostra a página de propriedades de um arquivo *. cpp* . O **tipo de item** padrão para esse tipo de arquivo é o **compilador C/C++** (*cl.exe*) e a página de propriedades expõe várias configurações de compilador que podem ser aplicadas somente a esse arquivo.

   ![Página de propriedades geral para um item de projeto](media/file-general-item-type.png "Opções de tipo de item")

    A tabela a seguir lista os tipos de item padrão:

    |Extensão de arquivo|Tipo de item|Ferramenta padrão|
    |-|-|-|
    |.appx|Definição de aplicativo XAML|[Empacotador do aplicativo](/windows/win32/appxpkg/make-appx-package--makeappx-exe-)|
    |. HLSL,. CSO|Compilador HLSL|[fxc.exe](/windows/win32/direct3dtools/fxc)|
    |.h|Cabeçalho C/C++|[Pré-processador de C/C++](../../preprocessor/c-cpp-preprocessor-reference.md)|
    |N/D|Não participa da compilação|N/D|
    |. xml,. XSLT,. xsl|Xml|[Editor de XML](/visualstudio/xml-tools/xml-editor)|
    |. resw,. resjson|Recurso PRI (aplicativos UWP)|[MakePri.exe](/windows/uwp/app-resources/compile-resources-manually-with-makepri)|
    ||Mídia (UWP)|[Empacotador do aplicativo](/windows/win32/appxpkg/make-appx-package--makeappx-exe-)|
    |.xsd|Ferramenta de gerador de dados XML|[Ferramenta de definição de esquema XML (Xsd.exe)](/dotnet/standard/serialization/xml-schema-definition-tool-xsd-exe) (requer carga de trabalho .net. Não incluído com MSVC.)|
    ||Ferramenta de Manifesto|[mt.exe](/windows/win32/sbscs/mt-exe)|
    |.rc|Recurso|[Compilador de recursos do Windows (rc.exe)](/windows/win32/menurc/resource-compiler)|
    |. appxmanifest|Manifesto do pacote de aplicativo|[Empacotador do aplicativo](/windows/win32/appxpkg/make-appx-package--makeappx-exe-)|
    |.obj|Objeto|[Vinculador C/C++ (link.exe)](cl-invokes-the-linker.md)|
    |.ttf|Fonte|N/D|
    |.txt|Texto|n/d|
    |n/d|Ferramenta de compilação personalizada|Definido pelo usuário|
    |N/D|Copiar arquivo|N/D|
    |. packagelayout|Layout do pacote de aplicativo|[Empacotador do aplicativo](/windows/win32/appxpkg/make-appx-package--makeappx-exe-)|
    |.resx|Recurso gerenciado do compilador|[Resgen.exe (gerador de arquivo de recurso)](/dotnet/framework/tools/resgen-exe-resource-file-generator)|
    |. natvis|Arquivo de visualização do depurador do C++|[Estrutura de Natvis](/visualstudio/debugger/create-custom-views-of-native-objects)|
    |. jpg,. bmp,. ico, etc.|Imagem|Compilador de recurso baseado no tipo de aplicativo.|
    |.cpp|Compilador C/C++|cl.exe|

   Para acessar essa propriedade de forma programática, confira <xref:Microsoft.VisualStudio.VCProjectEngine.VCFileConfiguration.Tool%2A>.

Para obter informações sobre como acessar a página de propriedades **geral** no nó **Propriedades de configuração** , consulte [definir compilador C++ e propriedades de compilação no Visual Studio](../working-with-project-properties.md).

## <a name="see-also"></a>Confira também

[Referência de página de propriedades do projeto C++](property-pages-visual-cpp.md)
