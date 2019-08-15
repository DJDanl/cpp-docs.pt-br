---
title: Conceitos de aplicativos isolados e assemblies lado a lado
ms.date: 05/06/2019
helpviewer_keywords:
- side-by-side assemblies [C++]
- isolated assemblies [C++]
ms.assetid: 945a885f-cb3e-4c8a-a0b9-2c2e3e02cc50
ms.openlocfilehash: f75a95ccca214f437152d13e099fbd9d03eaaee2
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493302"
---
# <a name="concepts-of-isolated-applications-and-side-by-side-assemblies"></a>Conceitos de aplicativos isolados e assemblies lado a lado

Um aplicativo é considerado um [aplicativo isolado](/windows/win32/SbsCs/isolated-applications) se todos os seus componentes forem [assemblies lado a lado](/windows/win32/SbsCs/about-side-by-side-assemblies-). Um assembly lado a lado é uma coleção de recursos – um grupo de DLLs, classes windows, servidores COM, bibliotecas de tipos ou interfaces – que são implantados juntos e disponibilizados para um aplicativo usar no tempo de execução. Normalmente, um assembly lado a lado é um para várias DLLs.

## <a name="shared-or-private"></a>Compartilhado ou particular

Um assembly lado a lado pode ser compartilhado ou particular. Os [assemblies compartilhados lado a lado](/windows/win32/sbscs/about-shared-assemblies-) podem ser usados por vários aplicativos que especificam, em seus manifestos, uma dependência no assembly. Várias versões de um assembly lado a lado podem ser compartilhadas por aplicativos diferentes que são executados ao mesmo tempo. Um [assembly privado](/windows/win32/SbsCs/about-private-assemblies-) é um assembly que é implantado junto com um aplicativo para o uso exclusivo desse aplicativo. Os assemblies particulares são instalados na pasta que contém o arquivo executável do aplicativo ou uma de suas subpastas.

## <a name="manifests-and-search-order"></a>Manifestos e ordem de pesquisa

Os aplicativos isolados e os assemblies lado a lado são descritos por [manifestos](/windows/win32/sbscs/manifests). Um manifesto é um documento XML que pode ser um arquivo externo ou pode ser inserido em um aplicativo ou em um assembly como um recurso. O arquivo de manifesto de um aplicativo isolado é usado para gerenciar os nomes e as versões dos assemblies lado a lado compartilhados aos quais o aplicativo deve se associar no tempo de execução. O manifesto de um assembly lado a lado especifica nomes, versões, recursos e os assemblies dependentes de assemblies lado a lado. Para um assembly lado a lado compartilhado, seu manifesto é instalado na pasta %WINDIR%\WinSxS\Manifests\. No caso de um assembly particular, recomendamos que você inclua seu manifesto na DLL como um recurso que tenha uma ID igual a 1. Você também pode dar ao assembly particular o mesmo nome da DLL. Para obter mais informações, consulte [sobre assemblies privados](/windows/win32/SbsCs/about-private-assemblies-).

No momento da execução, o Windows usa as informações do assembly do manifesto do aplicativo para procurar e carregar o assembly lado a lado correspondente. Se um aplicativo isolado especificar uma dependência do assembly, o sistema operacional procura pelo assembly primeiro entre os assemblies compartilhados em cache de assembly nativo na pasta %WINDIR%\WinSxS\. Se o assembly necessário não for localizado, o sistema operacional procurará um assembly particular em uma pasta da estrutura de diretórios do aplicativo. Para obter mais informações, consulte [sequência de pesquisa de assembly](/windows/win32/SbsCs/assembly-searching-sequence).

## <a name="changing-dependencies"></a>Alterando dependências

Você pode alterar as dependências do assembly lado a lado depois que um aplicativo tiver sido implantado, modificando os [arquivos de configuração](/windows/win32/SbsCs/publisher-configuration-files) do Publicador e [os arquivos de configuração do aplicativo](/windows/win32/SbsCs/application-configuration-files). Um arquivo de configuração do editor, também conhecido como um arquivo de política do editor, é um arquivo XML que redireciona globalmente aplicativos e assemblies do uso de uma versão de um assembly lado a lado para o uso de outra versão do mesmo assembly. Por exemplo, você poderia alterar uma dependência quando uma correção de bug ou de segurança é implantada para um assembly lado a lado e você deseja redirecionar todos os aplicativos para usar a versão corrigida. Um arquivo de configuração do aplicativo é um arquivo XML que redireciona um aplicativo específico do uso de uma versão de um assembly lado a lado para o uso de outra versão do mesmo assembly. Você pode usar um arquivo de configuração do aplicativo para redirecionar um aplicativo específico para usar uma versão de um assembly lado a lado que seja diferente daquela definida no arquivo de configuração do editor. Para obter mais informações, consulte [Configuração](/windows/win32/SbsCs/configuration).

## <a name="visual-c-libraries"></a>Bibliotecas do Visual C++

No Visual Studio 2005 e no Visual Studio 2008, as bibliotecas redistribuíveis como ATL, MFC, CRT, C++ padrão, OpenMP e MSDIA foram implantadas como assemblies lado a lado compartilhados no cache de assembly nativo. Na versão atual, as bibliotecas redistribuíveis usam a implantação central. Por padrão, todos os aplicativos criados usando o Visual Studio são criados com o manifesto inserido no binário final e o manifesto descreve as dependências do binário nas bibliotecas visuais C++ . Para entender a geração de C++ manifesto para aplicativos, consulte [noções básicas sobre aC++ geração de manifesto para C/Programs](understanding-manifest-generation-for-c-cpp-programs.md). Um manifesto não é necessário para aplicativos que são vinculados estaticamente às bibliotecas que eles usam, ou que usam a implantação local. Para saber mais sobre implantação, confira [Implantação no Visual C++](../windows/deployment-in-visual-cpp.md).

## <a name="see-also"></a>Consulte também

[Compilando aplicativos isolados do C/C++ e assemblies lado a lado](building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)
