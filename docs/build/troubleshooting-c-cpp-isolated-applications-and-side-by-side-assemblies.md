---
title: Solucionando problemas do C/C++ aplicativos isolados e Assemblies lado a lado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- troubleshooting side-by-side assemblies
- troubleshooting isolated applications
- troubleshooting Visual C++
ms.assetid: 3257257a-1f0b-4ede-8564-9277a7113a35
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 6f5645270cbc8fbb71dd841cb4f1affa6bef1295
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="troubleshooting-cc-isolated-applications-and-side-by-side-assemblies"></a>Solucionando problemas de aplicativos isolados do C/C++ e assemblies lado a lado
Carregar um aplicativo C/C++ pode falhar se bibliotecas dependentes não podem ser encontradas. Este artigo descreve algumas das razões comuns por que um aplicativo C/C++ Falha ao carregar, e sugere etapas para resolver os problemas.  
  
 Se um aplicativo falhar ao carregar porque ele contém um manifesto que especifica uma dependência em um assembly lado a lado e o assembly não é instalado como um assembly privado na mesma pasta do executável nem no cache de assembly nativo na pasta %WINDIR%\WinSxS\ , uma das seguintes mensagens de erro pode ser exibida, dependendo da versão do Windows na qual você tentar executar o aplicativo.  
  
-   O aplicativo falhou ao inicializar corretamente (0xc0000135).  
  
-   Este aplicativo falhou ao iniciar porque a configuração do aplicativo está incorretova. Reinstalar o aplicativo pode corrigir esse problema.  
  
-   O sistema não pode executar o programa especificado.  
  
 Se seu aplicativo não tiver nenhum manifesto e depende de uma DLL que o Windows não pode localizar nos locais comuns de pesquisa, pode ser exibida uma mensagem de erro semelhante a esta:  
  
-   Este aplicativo falhou ao iniciar porque *um DLL necessário* não foi encontrado. Reinstalação do aplicativo pode corrigir esse problema.  
  
 Se o aplicativo for implantado em um computador que não tenha o Visual Studio, e ele falhar com mensagens de erro semelhantes às anteriores, verifique essas coisas:  
  
1.  Siga as etapas descritas em [Noções básicas sobre as dependências de um aplicativo do Visual C++](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md). O dependência walker pode mostrar a maioria das dependências para um aplicativo ou DLL. Se você observar que algumas DLLs estão faltando, instale-os no computador no qual você está tentando executar seu aplicativo.  
  
2.  O carregador do sistema operacional usa o manifesto do aplicativo para carregar assemblies que o aplicativo depende. O manifesto pode ser inserido no binário como um recurso ou instalado como um arquivo separado na pasta do aplicativo. Para verificar se o manifesto é inserido no binário, abra o binário no [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] e procure RT_MANIFEST em sua lista de recursos. Se você não encontrar um manifesto inserido, procure na pasta do aplicativo para um arquivo que tem nome como < binary_name >. \<extensão >. manifest.  
  
3.  Se seu aplicativo depende de assemblies lado a lado e um manifesto não estiver presente, você precisa garantir que o vinculador gera um manifesto para seu projeto. Marque a opção de vinculador **gerar manifesto** no **propriedades do projeto** caixa de diálogo para o projeto.  
  
4.  Se o manifesto é inserido no binário, certifique-se de que a ID de RT_MANIFEST está correto para esse tipo de binário. Para obter mais informações sobre qual ID de recurso para usar, consulte [Assemblies lado a lado de uso como um recurso (Windows)](http://msdn.microsoft.com/library/windows/desktop/aa376617.aspx). Se o manifesto está em um arquivo separado, abra-o em um editor de XML ou editor de texto. Para obter mais informações sobre manifestos e regras de implantação, consulte [manifestos](http://msdn.microsoft.com/library/aa375365).  
  
    > [!NOTE]
    >  Se um manifesto inserido e um arquivo de manifesto separado estiverem presentes, o carregador do sistema operacional usa o manifesto inserido e ignora o arquivo separado. No entanto, no Windows XP, o oposto é verdadeiro, o arquivo de manifesto separado é usado e o manifesto inserido é ignorado.  
  
5.  É recomendável que você insere um manifesto em cada DLL pois manifestos externos são ignorados quando uma DLL é carregada, embora um `LoadLibrary` chamar. Para obter mais informações, consulte [manifestos Assembly](http://msdn.microsoft.com/library/aa374219).  
  
6.  Verifique se todos os assemblies que são enumerados no manifesto estão corretamente instalados no computador. Cada assembly é especificado no manifesto pelo seu nome, número de versão e arquitetura de processador. Se seu aplicativo depende de assemblies lado a lado, verifique se esses assemblies estão corretamente instalados no computador para que o carregador do sistema operacional pode encontrá-los, conforme descrito em [a sequência de pesquisa de Assembly](http://msdn.microsoft.com/library/aa374224). Lembre-se de que os assemblies de 64 bits não podem ser carregados em processos de 32 bits e não podem ser executados em sistemas operacionais de 32 bits.  
  
## <a name="example"></a>Exemplo  
 Suponha que temos um aplicativo, appl.exe, que é criado usando o Visual C++. O manifesto do aplicativo ou será inserido no appl.exe como recurso binário RT_MANIFEST, que tem a ID igual a 1, ou é armazenado como o appl.exe.manifest de arquivo separado. O conteúdo deste manifesto é semelhante a esta:  
  
```  
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">  
  <dependency>  
    <dependentAssembly>  
      <assemblyIdentity type="win32" name="Fabrikam.SxS.Library" version="2.0.20121.0" processorArchitecture="x86" publicKeyToken="1fc8b3b9a1e18e3e"></assemblyIdentity>  
    </dependentAssembly>  
  </dependency>  
</assembly>  
```  
  
 O carregador do sistema operacional, esse manifesto diz que appl.exe depende de um assembly chamado Fabrikam.SxS.Library, versão 2.0.20121.0, que é criado para um x86 de 32 bits arquitetura do processador. O assembly dependente do lado a lado pode ser instalado como um assembly compartilhado ou como um assembly privado.  
  
 O manifesto do assembly para um assembly compartilhado é instalado na pasta %WINDIR%\WinSxS\Manifests\. Ele identifica o assembly e lista seu conteúdo — ou seja, as DLLs que fazem parte do assembly:  
  
```  
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>  
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">  
   <noInheritable/>  
   <assemblyIdentity type="win32" name="Fabrikam.SxS.Library" version="2.0.20121.0" processorArchitecture="x86" publicKeyToken="1fc8b3b9a1e18e3e"/>  
   <file name="Fabrikam.Main.dll" hash="3ca5156e8212449db6c622c3d10f37d9adb1ab12" hashalg="SHA1"/>  
   <file name="Fabrikam.Helper.dll" hash="92cf8a9bb066aea821d324ca4695c69e55b2d1c2" hashalg="SHA1"/>  
</assembly>  
```  
  
 Também podem usar assemblies lado a lado [arquivos de configuração do publicador](http://msdn.microsoft.com/library/aa375682)— também conhecido como arquivos de política — para redirecionar global de assemblies e aplicativos para usar uma versão de um assembly lado a lado em vez de outra versão do mesmo assembly. Você pode verificar as políticas para um assembly compartilhado na pasta %WINDIR%\WinSxS\Policies\. Aqui está um exemplo de arquivo de política:  
  
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
  
 Este arquivo de política especifica que qualquer aplicativo ou o assembly que solicita versão 2.0.10000.0 desse assembly deve em vez disso, use versão 2.0.20121.0, que é a versão atual que está instalada no sistema. Se uma versão do assembly que é mencionado no manifesto do aplicativo é especificada no arquivo de política, o carregador de procura uma versão desse assembly que é especificado no manifesto na pasta %WINDIR%\WinSxS\ e se essa versão não estiver instalado, o carregamento falhará. E se a versão do assembly 2.0.20121.0 não estiver instalado, o carregamento falhará para aplicativos que solicitam 2.0.10000.0 de versão do assembly.  
  
 No entanto, o assembly também pode ser instalado como um assembly privado de lado a lado na pasta do aplicativo instalado. Se o sistema operacional não conseguir encontrar o assembly como um assembly compartilhado, ele procura-lo como um assembly privado, na seguinte ordem:  
  
1.  Verifique a pasta de aplicativo para um arquivo de manifesto que tem o nome \<assemblyName >. manifest. Neste exemplo, o carregador tenta localizar Fabrikam.SxS.Library.manifest na pasta que contém appl.exe. Se ele encontrar o manifesto, o carregador carrega o assembly da pasta de aplicativo. Se o assembly não for encontrado, o carregamento falhará.  
  
2.  Tente abrir o \\< assemblyName\>\ na pasta que contém appl.exe, e se \\< assemblyName\>\ existe, tente carregar um arquivo de manifesto que tem o nome \<assemblyName >. manifesto dessa pasta. Se o manifesto for encontrado, o carregador carrega o assembly a partir de \\< assemblyName\>\ pasta. Se o assembly não for encontrado, o carregamento falhará.  
  
 Para obter mais informações sobre como o carregador de pesquisa para assemblies dependentes, consulte [a sequência de pesquisa de Assembly](http://msdn.microsoft.com/library/aa374224). Se o carregador não conseguir localizar um assembly dependente como um assembly privado, o carregamento falhará e será exibida a mensagem "o sistema não é possível executar o programa especificado". Para resolver esse erro, verifique se os assemblies dependentes — e DLLs que são parte deles — são instalados no computador como assemblies privados ou compartilhados.  
  
## <a name="see-also"></a>Consulte também  
 [Conceitos de aplicativos isolados e Assemblies lado a lado](../build/concepts-of-isolated-applications-and-side-by-side-assemblies.md)   
 [Compilando aplicativos isolados do C/C++ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)