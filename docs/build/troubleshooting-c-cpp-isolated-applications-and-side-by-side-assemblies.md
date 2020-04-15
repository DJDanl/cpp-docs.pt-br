---
title: Solucionando problemas de aplicativos isolados do C/C++ e assemblies lado a lado
ms.date: 11/04/2016
helpviewer_keywords:
- troubleshooting side-by-side assemblies
- troubleshooting isolated applications
- troubleshooting Visual C++
ms.assetid: 3257257a-1f0b-4ede-8564-9277a7113a35
ms.openlocfilehash: 0dc8488acc90f1a38a4c0de0f052590ef4f398af
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81335448"
---
# <a name="troubleshooting-cc-isolated-applications-and-side-by-side-assemblies"></a>Solucionando problemas de aplicativos isolados do C/C++ e assemblies lado a lado

O carregamento de um aplicativo C/C++ pode falhar se bibliotecas dependentes não puderem ser encontradas. Este artigo descreve algumas razões comuns pelas quais um aplicativo C/C++ falha em carregar e sugere etapas para resolver os problemas.

Se um aplicativo não for carregado porque possui um manifesto que especifica uma dependência de um conjunto lado a lado, e o conjunto não estiver instalado como um conjunto privado na mesma pasta do executável nem no cache de montagem nativo na pasta %WINDIR%\WinSxS\, uma das seguintes mensagens de erro pode ser exibida, dependendo da versão do Windows em que você tenta executar o aplicativo.

- O aplicativo não foi inicializado corretamente (0xc0000135).

- Este aplicativo falhou porque a configuração do aplicativo está incorreta. A reinstalação do aplicativo pode corrigir esse problema.

- O sistema não pode executar o programa especificado.

Se o seu aplicativo não tiver manifesto e depender de uma DLL que o Windows não pode encontrar nos locais típicos de pesquisa, uma mensagem de erro que se assemelha a esta pode ser exibida:

- Este aplicativo não foi recomeçado porque *uma DLL necessária* não foi encontrada. A reinstalação do aplicativo pode corrigir este problema.

Se o seu aplicativo for implantado em um computador que não tenha visual studio, e ele falhar com mensagens de erro que se assemelham às anteriores, verifique estas coisas:

1. Siga as etapas descritas no [Entendimento das Dependências de um Aplicativo Visual C++.](../windows/understanding-the-dependencies-of-a-visual-cpp-application.md) O andador de dependência pode mostrar a maioria das dependências para um aplicativo ou DLL. Se você observar que alguns DLLs estão faltando, instale-os no computador no qual você está tentando executar seu aplicativo.

1. O carregador do sistema operacional usa o manifesto de aplicação para carregar conjuntos dos que o aplicativo depende. O manifesto pode ser incorporado no binário como um recurso ou instalado como um arquivo separado na pasta do aplicativo. Para verificar se o manifesto está incorporado no binário, abra o binário no Visual Studio e procure RT_MANIFEST em sua lista de recursos. Se você não conseguir encontrar um manifesto incorporado, procure na pasta de aplicativos um arquivo chamado algo como <binary_name>. \<extensão>.manifest.

1. Se sua aplicação depende de montagens lado a lado e um manifesto não está presente, você tem que garantir que o linker gere um manifesto para o seu projeto. Verifique a opção linker **Gerar manifesto** na caixa de diálogo Propriedades do **Projeto** para o projeto.

1. Se o manifesto estiver incorporado no binário, certifique-se de que o ID de RT_MANIFEST esteja correto para este tipo de binário. Para obter mais informações sobre qual ID de recurso usar, consulte Usando conjuntos lado a [lado como um recurso (Windows)](/windows/win32/SbsCs/using-side-by-side-assemblies-as-a-resource). Se o manifesto estiver em um arquivo separado, abra-o em um editor XML ou editor de texto. Para obter mais informações sobre manifestos e regras para implantação, consulte [Manifests](/windows/win32/sbscs/manifests).

   > [!NOTE]
   > Se um manifesto incorporado e um arquivo manifesto separado estiverem presentes, o carregador do sistema operacional usará o manifesto incorporado e ignorará o arquivo separado. No entanto, no Windows XP, o oposto é verdadeiro — o arquivo manifesto separado é usado e o manifesto incorporado é ignorado.

1. Recomendamos que você incorpore um manifesto em cada DLL porque manifestos externos `LoadLibrary` são ignorados quando uma DLL é carregada apesar de uma chamada. Para obter mais informações, consulte [manifestos da Assembléia](/windows/win32/SbsCs/assembly-manifests).

1. Verifique se todos os conjuntos que estão enumerados no manifesto estão corretamente instalados no computador. Cada conjunto é especificado no manifesto pelo nome, número da versão e arquitetura do processador. Se a sua aplicação depender de conjuntos lado a lado, verifique se esses conjuntos estão corretamente instalados no computador para que o carregador do sistema operacional possa encontrá-los, conforme descrito na [Seqüência de Pesquisa de Montagem](/windows/win32/SbsCs/assembly-searching-sequence). Lembre-se que conjuntos de 64 bits não podem ser carregados em processos de 32 bits e não podem ser executados em sistemas operacionais de 32 bits.

## <a name="example"></a>Exemplo

Suponha que temos um aplicativo, appl.exe, que é construído usando Visual C++. O manifesto do aplicativo está incorporado em appl.exe como o recurso binário RT_MANIFEST, que tem um ID igual a 1, ou é armazenado como o arquivo separado appl.exe.manifest. O conteúdo deste manifesto se assemelha a isso:

```
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
  <dependency>
    <dependentAssembly>
      <assemblyIdentity type="win32" name="Fabrikam.SxS.Library" version="2.0.20121.0" processorArchitecture="x86" publicKeyToken="1fc8b3b9a1e18e3e"></assemblyIdentity>
    </dependentAssembly>
  </dependency>
</assembly>
```

Para o carregador do sistema operacional, este manifesto diz que appl.exe depende de um conjunto chamado Fabrikam.SxS.Library, versão 2.0.20121.0, que é construído para uma arquitetura de processador x86 de 32 bits. O conjunto lado a lado dependente pode ser instalado como um conjunto compartilhado ou como uma montagem privada.

O manifesto de montagem para um conjunto compartilhado está instalado na pasta %WINDIR%\WinSxS\Manifests\.. Ele identifica a montagem e lista seu conteúdo — ou seja, os DLLs que fazem parte da montagem:

```
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">
   <noInheritable/>
   <assemblyIdentity type="win32" name="Fabrikam.SxS.Library" version="2.0.20121.0" processorArchitecture="x86" publicKeyToken="1fc8b3b9a1e18e3e"/>
   <file name="Fabrikam.Main.dll" hash="3ca5156e8212449db6c622c3d10f37d9adb1ab12" hashalg="SHA1"/>
   <file name="Fabrikam.Helper.dll" hash="92cf8a9bb066aea821d324ca4695c69e55b2d1c2" hashalg="SHA1"/>
</assembly>
```

Os conjuntos lado a lado também podem usar arquivos de [configuração de editores](/windows/win32/SbsCs/publisher-configuration-files)— também conhecidos como arquivos de diretiva — para redirecionar globalmente aplicativos e conjuntos para usar uma versão de um conjunto lado a lado, em vez de outra versão do mesmo conjunto. Você pode verificar as políticas de um conjunto compartilhado na pasta %WINDIR%\WinSxS\Policies\\. Aqui está um arquivo de política de exemplo:

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

Este arquivo de diretiva especifica que qualquer aplicativo ou conjunto que solicite a versão 2.0.10000.0 deste conjunto deve, em vez disso, usar a versão 2.0.20121.0, que é a versão atual instalada no sistema. Se uma versão do conjunto mencionada no manifesto do aplicativo for especificada no arquivo de diretiva, o carregador procurará uma versão deste conjunto especificada no manifesto na pasta %WINDIR%\WinSxS\, e se essa versão não estiver instalada, a carga falhará. E se a versão de montagem 2.0.20121.0 não estiver instalada, a carga falhará para aplicativos que pedem a versão de montagem 2.0.10000.0.

No entanto, o conjunto também pode ser instalado como um conjunto privado lado a lado na pasta de aplicativos instalada. Se o sistema operacional não encontrar o conjunto como uma montagem compartilhada, ele o procura como uma montagem privada, na seguinte ordem:

1. Verifique a pasta do aplicativo para \<obter um arquivo manifesto que tenha o nome assemblyName>.manifest. Neste exemplo, o carregador tenta encontrar Fabrikam.SxS.Library.manifest na pasta que contém appl.exe. Se encontrar o manifesto, o carregador carrega o conjunto da pasta de aplicação. Se o conjunto não for encontrado, a carga falhará.

1. Tente abrir \\ a pasta\><assemblyName \ na pasta que contém \\ appl.exe e se<assemblyName\> \<\ existir, tente carregar um arquivo manifesto que tenha o nome assemblyName>.manifest desta pasta. Se o manifesto for encontrado, o carregador \\ carregará\>o conjunto a partir da pasta<assemblyName \. Se o conjunto não for encontrado, a carga falhará.

Para obter mais informações sobre como o carregador procura montagens dependentes, consulte [Assembly Search Sequence](/windows/win32/SbsCs/assembly-searching-sequence). Se o carregador não encontrar um conjunto dependente como um conjunto privado, a carga falhará e a mensagem "O sistema não pode executar o programa especificado" será exibida. Para resolver esse erro, certifique-se de que conjuntos dependentes — e DLLs que fazem parte deles — sejam instalados no computador como conjuntos privados ou compartilhados.

## <a name="see-also"></a>Confira também

[Conceitos de Aplicações Isoladas e Montagens Lado a lado](concepts-of-isolated-applications-and-side-by-side-assemblies.md)<br/>
[Construindo aplicações isoladas C/C++ e conjuntos lado a lado](building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)
