---
title: Solucionando problemas de aplicativos isolados do C/C++ e assemblies lado a lado
ms.date: 11/04/2016
helpviewer_keywords:
- troubleshooting side-by-side assemblies
- troubleshooting isolated applications
- troubleshooting Visual C++
ms.assetid: 3257257a-1f0b-4ede-8564-9277a7113a35
ms.openlocfilehash: 1bd0d7638a8e7f2e3c671229e1f8d118d681e6f4
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492571"
---
# <a name="troubleshooting-cc-isolated-applications-and-side-by-side-assemblies"></a>Solucionando problemas de aplicativos isolados do C/C++ e assemblies lado a lado

O carregamento de umC++ C/aplicativo pode falhar se bibliotecas dependentes não puderem ser encontradas. Este artigo descreve alguns motivos comuns pelos quais um aplicativoC++ /C não consegue carregar e sugere etapas para resolver os problemas.

Se um aplicativo não for carregado porque ele tem um manifesto que especifica uma dependência em um assembly lado a lado, e o assembly não é instalado como um assembly privado na mesma pasta que o executável nem no cache de assembly nativo na pasta%WINDIR%\WinSxS\ , uma das seguintes mensagens de erro pode ser exibida, dependendo da versão do Windows na qual você tenta executar o aplicativo.

- O aplicativo não foi inicializado corretamente (0xc0000135).

- Falha ao iniciar este aplicativo porque a configuração do aplicativo está incorreta. A reinstalação do aplicativo pode corrigir esse problema.

- O sistema não pode executar o programa especificado.

Se seu aplicativo não tiver nenhum manifesto e depender de uma DLL que o Windows não consegue localizar nos locais de pesquisa típicos, uma mensagem de erro semelhante a esta poderá ser exibida:

- Falha ao iniciar este aplicativo porque *uma DLL necessária* não foi encontrada. A reinstalação do aplicativo pode corrigir esse problema.

Se seu aplicativo for implantado em um computador que não tem o Visual Studio e ele falhar com mensagens de erro que se assemelham aos anteriores, verifique estas coisas:

1. Siga as etapas descritas em [noções básicas sobre as dependências de C++ um aplicativo Visual](../windows/understanding-the-dependencies-of-a-visual-cpp-application.md). O Dependency Walker pode mostrar a maioria das dependências de um aplicativo ou DLL. Se você observar que algumas DLLs estão ausentes, instale-as no computador no qual você está tentando executar o aplicativo.

1. O carregador do sistema operacional usa o manifesto do aplicativo para carregar os assemblies dos quais o aplicativo depende. O manifesto pode ser inserido no binário como um recurso ou instalado como um arquivo separado na pasta do aplicativo. Para verificar se o manifesto está inserido no binário, abra o binário no Visual Studio e procure RT_MANIFEST em sua lista de recursos. Se você não encontrar um manifesto inserido, procure na pasta do aplicativo um arquivo chamado algo como < binary_name >. \<extensão >. manifest.

1. Se seu aplicativo depender de assemblies lado a lado e um manifesto não estiver presente, você precisará garantir que o vinculador gere um manifesto para seu projeto. Verifique se a opção de vinculador **gera o manifesto** na caixa de diálogo **Propriedades do projeto** para o projeto.

1. Se o manifesto for inserido no binário, verifique se a ID de RT_MANIFEST está correta para esse tipo de binário. Para obter mais informações sobre qual ID de recurso usar, consulte [usando assemblies lado a lado como um recurso (Windows)](/windows/win32/SbsCs/using-side-by-side-assemblies-as-a-resource). Se o manifesto estiver em um arquivo separado, abra-o em um editor de XML ou editor de texto. Para obter mais informações sobre manifestos e regras para implantação, consulte [manifestos](/windows/win32/sbscs/manifests).

   > [!NOTE]
   > Se um manifesto incorporado e um arquivo de manifesto separado estiverem presentes, o carregador do sistema operacional usará o manifesto incorporado e ignorará o arquivo separado. No entanto, no Windows XP, o oposto é verdadeiro — o arquivo de manifesto separado é usado e o manifesto incorporado é ignorado.

1. É recomendável que você incorpore um manifesto em cada dll porque os manifestos externos são ignorados quando uma DLL é `LoadLibrary` carregada por meio de uma chamada. Para obter mais informações, consulte [manifestos de assembly](/windows/win32/SbsCs/assembly-manifests).

1. Verifique se todos os assemblies enumerados no manifesto estão instalados corretamente no computador. Cada assembly é especificado no manifesto por seu nome, número de versão e arquitetura de processador. Se seu aplicativo depende de assemblies lado a lado, verifique se esses assemblies estão instalados corretamente no computador para que o carregador do sistema operacional possa encontrá-los, conforme descrito em [sequência de pesquisa de assembly](/windows/win32/SbsCs/assembly-searching-sequence). Lembre-se de que os assemblies de 64 bits não podem ser carregados em processos de 32 bits e não podem ser executados em sistemas operacionais de 32 bits.

## <a name="example"></a>Exemplo

Suponha que tenhamos um aplicativo, o Apl. exe, criado usando o Visual C++. O manifesto do aplicativo é inserido em Apl. exe como o recurso binário RT_MANIFEST, que tem uma ID igual a 1, ou é armazenado como o arquivo. exe. manifest separado. O conteúdo desse manifesto é semelhante a este:

```
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
  <dependency>
    <dependentAssembly>
      <assemblyIdentity type="win32" name="Fabrikam.SxS.Library" version="2.0.20121.0" processorArchitecture="x86" publicKeyToken="1fc8b3b9a1e18e3e"></assemblyIdentity>
    </dependentAssembly>
  </dependency>
</assembly>
```

Para o carregador do sistema operacional, esse manifesto diz que o Apl. exe depende de um assembly chamado Fabrikam. SxS. library, versão 2.0.20121.0, criado para uma arquitetura de processador x86 de 32 bits. O assembly lado a lado dependente pode ser instalado como um assembly compartilhado ou como um assembly privado.

O manifesto do assembly para um assembly compartilhado é instalado na pasta%WINDIR%\\WinSxS\\Manifests\\ Ele identifica o assembly e lista seu conteúdo, ou seja, as DLLs que fazem parte do assembly:

```
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
   <noInheritable/>
   <assemblyIdentity type="win32" name="Fabrikam.SxS.Library" version="2.0.20121.0" processorArchitecture="x86" publicKeyToken="1fc8b3b9a1e18e3e"/>
   <file name="Fabrikam.Main.dll" hash="3ca5156e8212449db6c622c3d10f37d9adb1ab12" hashalg="SHA1"/>
   <file name="Fabrikam.Helper.dll" hash="92cf8a9bb066aea821d324ca4695c69e55b2d1c2" hashalg="SHA1"/>
</assembly>
```

Os assemblies lado a lado também podem usar [arquivos de configuração do Publicador](/windows/win32/SbsCs/publisher-configuration-files)— também conhecidos como arquivos de política — para redirecionar globalmente aplicativos e assemblies para usar uma versão de um assembly lado a lado, em vez de outra versão do mesmo assembly. Você pode verificar as políticas para um assembly compartilhado na pasta%WINDIR%\WinSxS\Policies\. Aqui está um exemplo de arquivo de política:

```
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">

   <assemblyIdentity type="win32-policy" name="policy.2.0.Fabrikam.SxS.Library" version="2.0.20121.0" processorArchitecture="x86" publicKeyToken="1fc8b3b9a1e18e3e"/>
   <dependency>
      <dependentAssembly>
         <assemblyIdentity type="win32" name="Fabrikam.SxS.Library" processorArchitecture="x86" publicKeyToken="1fc8b3b9a1e18e3e"/>
         <bindingRedirect oldVersion="2.0.10000.0-2.0.20120.99" newVersion="2.0.20121.0"/>
      </dependentAssembly>
   </dependency>
</assembly>
```

Esse arquivo de política especifica que qualquer aplicativo ou assembly que solicite a versão 2.0.10000.0 desse assembly deve usar a versão 2.0.20121.0, que é a versão atual instalada no sistema. Se uma versão do assembly mencionada no manifesto do aplicativo for especificada no arquivo de política, o carregador procurará uma versão desse assembly especificada no manifesto na pasta%WINDIR%\WinSxS\ e, se essa versão não estiver instalada, a carga falhará. E se a versão do assembly 2.0.20121.0 não estiver instalada, o carregamento falhará para aplicativos que solicitam a versão do assembly 2.0.10000.0.

No entanto, o assembly também pode ser instalado como um assembly lado a lado privado na pasta do aplicativo instalado. Se o sistema operacional não conseguir localizar o assembly como um assembly compartilhado, ele o procurará como um assembly privado, na seguinte ordem:

1. Verifique a pasta do aplicativo em busca de um arquivo de manifesto \<que tenha o nome AssemblyName >. manifest. Neste exemplo, o carregador tenta localizar fabrikam. SxS. library. manifest na pasta que contém o Apl. exe. Se encontrar o manifesto, o carregador carregará o assembly da pasta do aplicativo. Se o assembly não for encontrado, o carregamento falhará.

1. \\Tente abrir a pasta < AssemblyName\>\ na pasta que contém o Apl. exe e, se \\< AssemblyName\>\ Exists, tente carregar um arquivo de manifesto com o nome \<AssemblyName >. manifesto desta pasta. Se o manifesto for encontrado, o carregador carregará o assembly da \\pasta <\>AssemblyName \. Se o assembly não for encontrado, o carregamento falhará.

Para obter mais informações sobre como o carregador procura assemblies dependentes, consulte [sequência de pesquisa de assembly](/windows/win32/SbsCs/assembly-searching-sequence). Se o carregador não conseguir localizar um assembly dependente como um assembly privado, a carga falhará e a mensagem "o sistema não pode executar o programa especificado" será exibida. Para resolver esse erro, verifique se os assemblies dependentes – e DLLs que fazem parte deles — estão instalados no computador como assemblies privados ou compartilhados.

## <a name="see-also"></a>Consulte também

[Conceitos de aplicativos isolados e assemblies lado a lado](concepts-of-isolated-applications-and-side-by-side-assemblies.md)<br/>
[Compilando aplicativos isolados do C/C++ e assemblies lado a lado](building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)
