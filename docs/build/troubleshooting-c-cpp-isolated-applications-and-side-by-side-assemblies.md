---
title: "Solucionando problemas de aplicativos isolados do C/C++ e assemblies lado a lado | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "solucionando problemas em aplicativos isolados"
  - "solucionando problemas em assemblies lado a lado"
  - "solucionando problemas do Visual C++"
ms.assetid: 3257257a-1f0b-4ede-8564-9277a7113a35
caps.latest.revision: 28
caps.handback.revision: 28
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Solucionando problemas de aplicativos isolados do C/C++ e assemblies lado a lado
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Carregar um aplicativo C\/C\+\+ pode falhar se bibliotecas dependentes não podem ser encontradas.  Este artigo descreve algumas razões comuns por que um aplicativo C\/C\+\+ Falha ao carregar, e sugere etapas para resolver os problemas.  
  
 Se um aplicativo falha ao carregar porque ele contém um manifesto que especifique uma dependência em um assembly lado a lado e o assembly não é instalado como um assembly particular na mesma pasta que o executável, nem no cache de assembly nativo na pasta %Windir%\\winsxs\\., uma das seguintes mensagens de erro pode ser exibida, dependendo da versão do Windows em que você tentar executar o aplicativo.  
  
-   O aplicativo não inicializado corretamente \(0xc0000135\).  
  
-   Este aplicativo falhou ao iniciar porque a configuração do aplicativo está incorreta.  Reinstalar o aplicativo pode corrigir esse problema.  
  
-   O sistema não pode executar o programa especificado.  
  
 Se seu aplicativo não tem nenhum manifesto e depende de uma DLL que o Windows não pode encontrar nos locais comuns de pesquisa, pode ser exibida uma mensagem de erro semelhante a esta:  
  
-   Este aplicativo falhou ao iniciar porque *uma DLL necessária* não foi encontrado.  Reinstalação do aplicativo pode corrigir esse problema.  
  
 Se o aplicativo for implantado em um computador que não tenha o Visual Studio, e ele falhar com mensagens de erro semelhantes do anteriores, verifique essas coisas:  
  
1.  Siga as etapas descritas na [Noções básicas sobre as dependências de um aplicativo do Visual C\+\+](../ide/understanding-the-dependencies-of-a-visual-cpp-application.md).  O dependency walker pode mostrar a maioria das dependências para um aplicativo ou DLL.  Se você observar que algumas DLLs estão ausentes, instalá\-los no computador no qual você está tentando executar o aplicativo.  
  
2.  O carregador do sistema operacional usa o manifesto do aplicativo para carregar assemblies que o aplicativo depende.  O manifesto pode ser inserido no binário como um recurso ou instalado como um arquivo separado na pasta do aplicativo.  Para verificar se o manifesto é incorporado no binário, abra o binário no [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)] e procure RT\_MANIFEST em sua lista de recursos.  Se você não encontrar um manifesto inserido, procure na pasta do aplicativo para um arquivo que tem nomes como \< binary\_name \>. \< extensão \> manifest.  
  
3.  Se seu aplicativo depende de assemblies lado a lado e um manifesto não estiver presente, você precisa garantir que o vinculador gera um manifesto para o seu projeto.  Marque a opção de vinculador **Gerar manifesto** no **Propriedades do projeto** caixa de diálogo para o projeto.  
  
4.  Se o manifesto é incorporado no binário, certifique\-se de que a ID de RT\_MANIFEST está correto para esse tipo de binário.  Para obter mais informações sobre o ID do recurso usar, consulte [Assemblies lado a lado de uso como um recurso \(Windows\)](http://msdn.microsoft.com/library/windows/desktop/aa376617.aspx).  Se o manifesto é em um arquivo separado, abra\-o em um editor de XML ou editor de texto.  Para obter mais informações sobre manifestos e regras para implantação, consulte [manifestos](http://msdn.microsoft.com/library/aa375365).  
  
    > [!NOTE]
    >  Se um manifesto inserido e um arquivo de manifesto separado estiverem presentes, o carregador do sistema operacional usa o manifesto inserido e ignora o arquivo separado.  No entanto, no Windows XP, o oposto é verdadeiro, o arquivo de manifesto separado é usado e o manifesto inserido é ignorado.  
  
5.  É recomendável que você incorpore um manifesto em cada DLL porque manifestos externos são ignorados quando uma DLL é carregada, embora um `LoadLibrary` chamar.  Para obter mais informações, consulte [manifestos Assembly](http://msdn.microsoft.com/library/aa374219).  
  
6.  Verifique se todos os assemblies que são enumerados no manifesto estão corretamente instalados no computador.  Cada assembly é especificado no manifesto por seu nome, número de versão e arquitetura do processador.  Se seu aplicativo depende de assemblies lado a lado, verifique se esses assemblies estão corretamente instalados no computador para que o carregador do sistema operacional possa localizá\-los, conforme descrito em [a sequência de pesquisa de Assembly](http://msdn.microsoft.com/library/aa374224).  Lembre\-se de que os assemblies de 64 bits não podem ser carregados em processos de 32 bits e não podem ser executados em sistemas operacionais de 32 bits.  
  
## Exemplo  
 Suponha que você tenha um aplicativo, appl.exe, que é criado usando [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)].  O manifesto do aplicativo é incorporado na appl.exe como o recurso binário RT\_MANIFEST, que tem a ID igual a 1 ou é armazenado como appl.exe.manifest o arquivo separado.  O conteúdo desse manifesto é semelhante a esta:  
  
```  
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">  
  <dependency>  
    <dependentAssembly>  
      <assemblyIdentity type="win32" name="Fabrikam.SxS.Library" version="2.0.20121.0" processorArchitecture="x86" publicKeyToken="1fc8b3b9a1e18e3e"></assemblyIdentity>  
    </dependentAssembly>  
  </dependency>  
</assembly>  
```  
  
 O carregador do sistema operacional, esse manifesto diz que appl.exe depende de um assembly denominado Fabrikam.SxS.Library, versão 2.0.20121.0, que é criado para uma arquitetura de processador x86 de 32 bits.  O assembly lado a lado dependente pode ser instalado como um assembly compartilhado ou um assembly privado.  
  
 O manifesto do assembly para um assembly compartilhado é instalado na pasta %Windir%\\winsxs\\manifests\\..  Ele identifica o assembly e lista seu conteúdo — isto é, as DLLs que fazem parte do assembly:  
  
```  
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>  
<assembly xmlns="urn:schemas-microsoft-com:asm.v1" manifestVersion="1.0">  
   <noInheritable/>  
   <assemblyIdentity type="win32" name="Fabrikam.SxS.Library" version="2.0.20121.0" processorArchitecture="x86" publicKeyToken="1fc8b3b9a1e18e3e"/>  
   <file name="Fabrikam.Main.dll" hash="3ca5156e8212449db6c622c3d10f37d9adb1ab12" hashalg="SHA1"/>  
   <file name="Fabrikam.Helper.dll" hash="92cf8a9bb066aea821d324ca4695c69e55b2d1c2" hashalg="SHA1"/>  
</assembly>  
```  
  
 Também podem usar assemblies lado a lado [arquivos de configuração do publicador](http://msdn.microsoft.com/library/aa375682)— também conhecido como arquivos de política — para redirecionar globalmente aplicativos e assemblies para usar uma versão de um assembly lado a lado em vez de outra versão do mesmo assembly.  Você pode verificar as políticas para um assembly compartilhado na pasta %WINDIR%\\WinSxS\\Policies\\.  Aqui está um exemplo de arquivo de política:  
  
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
  
 Esse arquivo de política especifica que qualquer aplicativo ou assembly que solicita versão 2.0.10000.0 desse assembly deverá usar a versão 2.0.20121.0, que é a versão atual que está instalada no sistema.  Se uma versão do assembly mencionado no manifesto do aplicativo é especificada no arquivo de política, o carregador procura uma versão desse assembly especificado no manifesto na pasta %Windir%\\winsxs\\. e se essa versão não estiver instalada, o carregamento falhará.  E se a versão do assembly 2.0.20121.0 não estiver instalado, o carregamento falhará para aplicativos que pedem a versão do assembly 2.0.10000.0.  
  
 No entanto, o assembly também pode ser instalado como um assembly lado a lado privado na pasta do aplicativo instalado.  Se o sistema operacional não conseguir localizar o assembly como um assembly compartilhado, ele procura\-lo como um assembly particular, na seguinte ordem:  
  
1.  Verifique a pasta de aplicativo para um arquivo de manifesto que tem o nome \< assemblyName \> manifest.  Neste exemplo, o carregador tenta encontrar Fabrikam.SxS.Library.manifest na pasta que contém appl.exe.  Se ele encontrar o manifesto, o carregador carrega o assembly da pasta de aplicativo.  Se o assembly não for encontrado, o carregamento falhará.  
  
2.  Tente abrir o \\ \< assemblyName \> \\ na pasta que contém appl.exe, e se \\ \< assemblyName \> \\ existe, tentar carregar um arquivo de manifesto que tem o nome \< assemblyName \> manifest desta pasta.  Se o manifesto for encontrado, o carregador carrega o assembly da \\ \< assemblyName \> \\ pasta.  Se o assembly não for encontrado, o carregamento falhará.  
  
 Para obter mais informações sobre como o carregador procura assemblies dependentes, consulte [a sequência de pesquisa de Assembly](http://msdn.microsoft.com/library/aa374224).  Se o carregador não encontrar um assembly dependente como um assembly privado, carregamento falhará e será exibida a mensagem "o sistema não pode executar o programa especificado".  Para resolver esse erro, verifique se assemblies dependentes — e DLLs que são parte deles — são instalados no computador como assemblies particulares ou compartilhados.  
  
## Consulte também  
 [Conceitos de aplicativos isolados e assemblies lado a lado](../build/concepts-of-isolated-applications-and-side-by-side-assemblies.md)   
 [Compilando aplicativos isolados do C\/C\+\+ e assemblies lado a lado](../build/building-c-cpp-isolated-applications-and-side-by-side-assemblies.md)