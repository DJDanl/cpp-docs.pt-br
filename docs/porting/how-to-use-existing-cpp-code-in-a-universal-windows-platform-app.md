---
title: Como usar o código C++ existente em um aplicativo da Plataforma Universal do Windows | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 87e5818c-3081-42f3-a30d-3dca2cf0645c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a3f8cb26a66fce9c4b87822ffbfa4005f3a2e758
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="how-to-use-existing-c-code-in-a-universal-windows-platform-app"></a>Como usar o código C++ existente em um aplicativo da Plataforma Universal do Windows
Talvez a maneira mais fácil para que seu programa da área de trabalho seja executado no ambiente UWP seja usar as tecnologias de Ponte de Desktop. Elas incluem o Desktop App Converter, que empacotará o aplicativo existente como um aplicativo UWP sem nenhuma alteração de código necessária. Para obter mais informações, consulte [Traga o aplicativo da área de trabalho para a UWP (Plataforma Universal do Windows) usando a Ponte de Desktop](https://msdn.microsoft.com/windows/uwp/porting/desktop-to-uwp-root).

O restante deste tópico discute como transportar as bibliotecas C++ (bibliotecas estáticas e de DLLs) para a UWP (Plataforma Universal do Windows). Talvez você queira fazer isso para que sua lógica de C++ Core possa ser usada com vários aplicativos UWP. 
  
 Os aplicativos da UWP são executados em um ambiente protegido e, como resultado, muitas chamadas à API, Win32, COM e CRT que poderiam comprometer a segurança da plataforma não são permitidas. O compilador poderá detectar essas chamadas e gerar um erro, se a opção /ZW for usada. Você pode usar o Kit de Certificação de Aplicativo em seu aplicativo para detectar o código que chama as APIs proibidas. Consulte [Usando o Kit de Certificação de Aplicativos](https://msdn.microsoft.com/library/windows/apps/hh694081.aspx).  
  
 Se o código-fonte estiver disponível para a biblioteca, você poderá eliminar as chamadas à API proibidas. Para obter detalhes, incluindo uma lista de APIs permitidas ou proibidas, confira [Win32 e COM para aplicativos do Windows Runtime e aplicativos UWP (Plataforma Universal do Windows)](https://msdn.microsoft.com/library/windows/apps/br205762.aspx) e [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md). Algumas alternativas podem ser encontradas em [Alternatives to Windows APIs in UWP apps](/uwp/win32-and-com/alternatives-to-windows-apis-uwp) (Alternativas para APIs do Windows em aplicativos UWP).  
  
 Se você tentar adicionar uma referência de um Projeto Universal do Windows a uma biblioteca de área de trabalho clássica, você obterá uma mensagem de erro que diz que a biblioteca não é compatível. No caso de uma biblioteca estática, você pode vincular à sua biblioteca simplesmente adicionando a biblioteca (arquivo .lib) à sua entrada de vinculador, assim como faria em um aplicativo Win32 clássico. Para bibliotecas em que somente um binário estiver disponível, isso será a única opção. Uma biblioteca estática é vinculada ao executável do aplicativo, mas uma DLL Win32 que você consumirá em um aplicativo UWP deve ser empacotado em um aplicativo incluindo-a no projeto e marcando-o como Conteúdo. Para carregar uma DLL do Win32 em um aplicativo UWP, você também precisa chamar [LoadPackagedLibrary](https://msdn.microsoft.com/library/windows/desktop/hh447159.aspx) em vez de LoadLibrary ou LoadLibraryEx.  
  
 Se você tiver o código-fonte para a DLL ou biblioteca estática, poderá recompilar com /ZW como um projeto UWP. Se você fizer isso, poderá adicionar uma referência usando o Gerenciador de Soluções e usá-la em aplicativos UWP C++. No caso de uma DLL, você deve vincular com a biblioteca de exportação.  
  
 Para expor a funcionalidade para chamadores em outras linguagens, você pode converter a biblioteca em um Componente do Tempo de Execução do Windows. Os Componentes do Windows Runtime diferem de DLLs comuns na medida em que eles incluem metadados na forma de arquivos .winmd que descrevem os conteúdos de uma maneira que os consumidores .NET e JavaScript exigem. Para expor elementos de API para outras linguagens, você pode adicionar constructos C++/CX, como classes de referência e torná-los públicos ou use a [WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/windows-runtime-cpp-template-library-wrl.md).  No Windows 10 e posterior, você pode usar a [biblioteca C++/WinRT](https://github.com/microsoft/cppwinrt) em vez do C++/CX. 
  
 A discussão anterior não se aplica ao caso de componentes COM, que devem ser tratados de maneira diferente. Se você tiver um servidor COM em um arquivo EXE ou DLL, poderá usá-lo em um Projeto Universal do Windows contanto que o empacote como um [componente COM sem registro](https://msdn.microsoft.com/library/dd408052.aspx), adicione-o ao projeto como um arquivo de conteúdo e crie uma instância dele usando [CoCreateInstanceFromApp](https://msdn.microsoft.com/library/windows/apps/hh404137.aspx). Consulte [Using Free-COM DLL in Windows Store C++ Project](http://blogs.msdn.com/b/win8devsupport/archive/2013/05/20/using-free-com-dll-in-windows-store-c-project.aspx) (Usando DLL COM gratuito no Projeto C++ da Windows Store).  
  
 Se você desejar portar uma biblioteca COM existente para a UWP, talvez seja possível convertê-la em um componente do Tempo de Execução do Windows usando a [WRL (Biblioteca de Modelos C++ do Tempo de Execução do Windows)](../windows/windows-runtime-cpp-template-library-wrl.md). A WRL não dá suporte a todos os recursos da ATL e OLE, portanto, se tal transporte é viável depende de quanto seu código COM depende de quais recursos do COM, ATL e OLE seu componente requer.  
  
 Estas são as várias maneiras de usar o código C++ existente em projetos UWP. Algumas formas não exigem que o código seja recompilado com as extensões de componente (C++/CX) habilitadas (ou seja, com a opção /ZW) e algumas exigem, portanto, se você precisar manter o código em C++ padrão ou preservar o ambiente de compilação Win32 clássico, pode fazê-lo com escolhas de arquitetura apropriadas. Por exemplo, todos os códigos que contêm interfaces do usuário e tipos da UWP e precisarem ser expostos a chamadores C#, Visual Basic e JavaScript deverão estar em projetos de aplicativo do Windows e em projetos de componente do Tempo de Execução do Windows. O código que precisa ser consumido apenas em código C++ (incluindo C++/CX) pode estar em um projeto que é compilado com a opção /WX ou um projeto C++ padrão. O código apenas binário pode ser usado vinculando-o como uma biblioteca estática ou empacotado com um aplicativo como conteúdo e carregado em uma DLL apenas se não usar APIs proibidas.  
  
 Independentemente de qual desses cenários de desenvolvimento você escolher, conheça as inúmeras definições de macro que você pode usar no código para compilar o código condicionalmente, tanto na área de trabalho clássica do Win32 quanto na UWP.  
  
```cpp  
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP)  
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP)  
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)  
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)  
```  
  
 Essas instruções aplicam-se, respectivamente, a aplicativos UWP e a aplicativos da Windows Phone Store, a ambos ou a nenhum (somente área de trabalho clássica do Win32). Essas macros estão disponíveis apenas no SDK do Windows 8.1 e posterior, portanto, se seu código precisar ser compilado com versões anteriores do SDK do Windows ou para outras plataformas além do Windows, você também deverá considerar a possibilidade de que nenhuma delas esteja definida.  
  
 Este tópico contém os seguintes procedimentos.  
  
1.  [Usando uma DLL do Win32 em um aplicativo UWP](#BK_Win32DLL)  
  
2.  [Usando uma biblioteca estática em C++ nativa em um aplicativo UWP](#BK_StaticLib)  
  
3.  [Portabilidade uma biblioteca C++ para um Componente do Tempo de Execução do Windows](#BK_WinRTComponent)  
  
##  <a name="BK_Win32DLL"></a> Usando uma DLL do Win32 em um aplicativo UWP  
 Para obter melhor segurança e confiabilidade, os aplicativos Universais do Windows são executados em um ambiente de tempo de execução restrito, portanto, não é possível simplesmente usar qualquer DLL nativa como você faria em um aplicativo de área de trabalho clássico do Windows. Se você tiver o código-fonte para uma DLL, poderá transportar o código para que ele seja executado na UWP. Comece alterando algumas configurações do projeto e metadados de arquivo de projeto para identificar o projeto como um projeto UWP. Você precisa compilar o código de biblioteca usando a opção /ZW, que habilita o C++/CX. Determinadas chamadas à API não são permitidas em aplicativos UWP devido aos controles mais rigorosos associados a esse ambiente. Consulte [Win32 e COM para aplicativos de Windows Runtime e aplicativos UWP (Plataforma Universal do Windows)](https://msdn.microsoft.com/library/windows/apps/br205757.aspx).  
  
 O procedimento a seguir se aplica ao caso em que você tem uma DLL nativa que expõe funções usando __declspec(dllexport).  
  
#### <a name="to-port-a-native-dll-to-the-uwp-without-creating-a-new-project"></a>Para transportar uma DLL nativa para a UWP sem criar um novo projeto  
  
1.  Se você tiver uma DLL nativa que exporta funções usando __declspec(dllexport), poderá chamar essas funções em um aplicativo UWP recompilando a DLL como um projeto UWP. Por exemplo, suponha que temos uma DLL que exporta algumas classes e seus métodos, com um código como o seguinte arquivo de cabeçalho:  
  
    ```  
    // giraffe.h  
    #pragma once  
  
    #ifdef _DLL  
    #define GIRAFFE_API __declspec(dllexport)  
    #else  
    #define GIRAFFE_API   
    #endif  
  
    GIRAFFE_API int giraffeFunction();  
  
    class Giraffe  
    {  
        int id;  
            Giraffe(int id_in);  
        friend class GiraffeFactory;  
  
    public:  
        GIRAFFE_API int GetID();  
    };  
  
    class GiraffeFactory  
    {  
        static int nextID;  
    
    public:  
        GIRAFFE_API GiraffeFactory();  
        GIRAFFE_API static int GetNextID();  
        GIRAFFE_API static Giraffe* Create();  
   };  
    ```  
  
     E o seguinte arquivo de código:  
  
    ```  
    // giraffe.cpp  
    #include "stdafx.h"  
    #include "giraffe.h"  
  
    Giraffe::Giraffe(int id_in) : id(id_in)  
    {  
    }  
  
    int Giraffe::GetID()  
    {  
      return id;  
    }  
  
    int GiraffeFactory::nextID = 0;  
  
    GiraffeFactory::GiraffeFactory()  
    {  
        nextID = 0;  
    }  
  
    int GiraffeFactory::GetNextID()  
    {  
        return nextID;  
    }  
  
    Giraffe* GiraffeFactory::Create()  
    {  
        return new Giraffe(nextID++);  
    }  
  
    int giraffeFunction();  
    ```  
  
     Todo o resto do projeto (stdafx.h, dllmain.cpp) é parte do modelo de projeto Win32 padrão. Se você quiser acompanhar, mas não quiser usar sua própria DLL ainda com estas etapas, tente criar um projeto do Win32, selecione a DLL no assistente de projeto e adicione um arquivo de cabeçalho giraffe.cpp e copie o conteúdo do código nessa etapa nos arquivos apropriados.  
  
     O código define a macro GIRAFFE_API que resolve para __declspec(dllexport) quando _DLL é definida (isto é, quando o projeto é compilado como uma DLL).  
  
2.  Abra as Propriedades do Projeto para o projeto DLL e defina a Configuração como **Todas as Configurações**.  
  
3.  Nas Propriedades do Projeto, em **C/C++**, guia **Geral**, defina **Utilizar Extensão do Windows Runtime** como **Sim (/ZW)**. Isso habilita extensões de componente (C++/CX).  
  
4.  No **Gerenciador de Soluções**, selecione o nó do projeto, abra o menu de atalho e escolha **Descarregar Projeto**. Em seguida, abra o menu de atalho no nó do projeto descarregado e escolha editar o arquivo de projeto. Localize o elemento WindowsTargetPlatformVersion e substitua-o pelos seguintes elementos.  
  
    ```xml  
    <AppContainerApplication>true</AppContainerApplication>  
    <ApplicationType>Windows Store</ApplicationType>  
    <WindowsTargetPlatformVersion>10.0.10156.0</WindowsTargetPlatformVersion>  
    <WindowsTargetPlatformMinVersion>10.0.10156.0</WindowsTargetPlatformMinVersion>  
    <ApplicationTypeRevision>10.0</ApplicationTypeRevision>  
    ```  
  
     Feche o arquivo .vcxproj, abra o menu de atalho novamente e escolha **Recarregar Projeto**.  
  
     Agora o Gerenciador de Soluções identifica o projeto como um Projeto Universal do Windows.  
  
5.  Verifique se o nome do arquivo de cabeçalho pré-compilado está correto. Na seção Cabeçalhos Pré-compilados, altere o Arquivo de Cabeçalho Pré-compilado de pch.h para stdafx.h. Se você não fizer isso, verá o seguinte erro.  
  
    ```Output  
    error C2857: '#include' statement specified with the /Ycpch.h command-line option was not found in the source file  
    ```  
  
     O problema é que os Projetos Universais do Windows usam uma convenção de nomenclatura diferente para o arquivo de cabeçalho pré-compilado.  
  
6.  Compile o projeto. Você pode obter alguns erros sobre as opções de linha de comando incompatíveis. Por exemplo, a opção usada com frequência Habilita Recompilação Mínima (/Gm) é definida por padrão em muitos projetos C++ e é incompatível com /ZW.  
  
     Algumas funções não estão disponíveis ao compilar para a Plataforma Universal do Windows. Você verá erros de compilador sobre quaisquer problemas. Resolva-os até ter um build limpo.  
  
7.  Para usar a DLL em um aplicativo UWP na mesma solução, abra o menu de atalho para o nó do projeto UWP e escolha **Adicionar, Referência**.  
  
     Em **Projetos, Solução**, marque a caixa de seleção ao lado do projeto DLL e escolha o botão **OK**.  
  
8.  Inclua os arquivos de cabeçalho da biblioteca no arquivo pch.h do aplicativo UWP.  
  
    ```  
    #include "..\MyNativeDLL\giraffe.h"  
    ```  
  
9. Adicione o código como de costume no projeto UWP para invocar funções e criar tipos da DLL.  
  
    ```  
    MainPage::MainPage()  
    {  
        InitializeComponent();  
        GiraffeFactory gf;  
        Giraffe* g = gf.Create();  
        int id = g->GetID();  
    }  
  
    ```  
  
##  <a name="BK_StaticLib"></a> Usando uma biblioteca estática em C++ nativa em um aplicativo UWP  
 Você pode usar uma biblioteca estática em C++ nativa em um projeto UWP, mas há algumas restrições e limitações para estar atento. Comece lendo este [tópico](https://msdn.microsoft.com/library/hh771041.aspx) sobre bibliotecas estáticas no C++/CX. Você pode acessar o código nativo na biblioteca estática do aplicativo UWP, mas não é recomendável criar tipos de referência pública nessa biblioteca estática. Se você compilar uma biblioteca estática com a opção /ZW, o bibliotecário (na verdade o vinculador disfarçado) avisará:  
  
```  
LNK4264: archiving object file compiled with /ZW into a static library; note that when authoring Windows Runtime types it is not recommended to link with a static library that contains Windows Runtime metadata  
```  
  
 No entanto, você pode usar uma biblioteca estática em uma UWP sem recompilá-la com /ZW. Você não poderá declarar qualquer tipo de referência ou usar constructos C++/CX, mas se seu objetivo for simplesmente usar a biblioteca de código nativo, poderá fazer isso seguindo essas etapas.  
  
#### <a name="to-use-a-native-c-static-library-in-a-uwp-project"></a>Para usar uma biblioteca estática em C++ nativa em um projeto UWP  
  
1.  Nas propriedades do projeto para o projeto UWP, na seção Vinculador, adicione o caminho para a biblioteca na propriedade Entrada. Por exemplo, para uma biblioteca no projeto que coloca a saída em *SolutionFolder*\Debug\MyNativeLibrary\MyNativeLibrary.lib, adicione o caminho relativo `Debug\MyNativeLibrary\MyNativeLibrary.lib`.  
  
2.  Adicione uma instrução include para fazer referência ao arquivo de cabeçalho para o pch.h no projeto UWP e comece a adicionar código que usa a biblioteca.  
  
    ```  
    #include "..\MyNativeLibrary\giraffe.h"  
    ```  
  
     Não adicione uma referência no nó **Referências** no **Gerenciador de Soluções**. Esse mecanismo funciona somente para Componente do Windows Runtime.  
  
##  <a name="BK_WinRTComponent"></a> Portabilidade uma biblioteca C++ para um Componente do Tempo de Execução do Windows  
 Se desejar consumir APIs nativas em uma biblioteca estática de um aplicativo UWP e tiver o código-fonte para a biblioteca nativa, você poderá transportar o código para um Componente do Tempo de Execução do Windows. Não será mais uma biblioteca estática, será uma DLL. Você pode usá-la em qualquer aplicativo UWP em C++, mas ao contrário do caso de biblioteca estática, você pode adicionar tipos de referência e outros constructos C++/CX que estão disponíveis para clientes em qualquer código de aplicativo UWP, independentemente da linguagem. Portanto, você pode acessar esses tipos do C#, Visual Basic ou JavaScript.  O procedimento básico é criar um projeto de Componente do Tempo de Execução do Windows, copiar o código da biblioteca estática para ele e resolver todos os erros provenientes da mudança do código de uma compilação C++ padrão para uma compilação /ZW.  
  
#### <a name="to-port-a-c-library-to-a-windows-runtime-component"></a>Para transportar uma biblioteca C++ para um Componente do Tempo de Execução do Windows  
  
1.  Crie um projeto de Componente do Tempo de Execução do Windows.  
  
2.  Feche o projeto.  
  
3.  No Explorador de Arquivos do Windows, localize o projeto. Por padrão, o Visual Studio usa a pasta Visual Studio 2017\Projects na pasta Documentos. Localize o projeto de biblioteca em C++ que contém o código que você deseja transportar. Copie os arquivos de origem (arquivos de cabeçalho, arquivos de código e outros recursos, inclusive em subdiretórios) do seu projeto de biblioteca em C++ e cole-os na pasta do projeto, certificando-se de preservar a mesma estrutura de pasta.  
  
4.  Reabra o projeto do Componente do Tempo de Execução do Windows e abra o menu de atalho para o nó do projeto no **Gerenciador de Soluções** e escolha **Adicionar, Item Existente**.  
  
5.  Selecione todos os arquivos para adicionar de seu projeto original e escolha OK. Repita se necessário para as subpastas.  
  
6.  Agora você pode ter alguns códigos duplicados. Se você tiver mais de um cabeçalho pré-compilado (digamos stdafx.h e pch.h), escolha um para manter. Copie qualquer código necessário, como instruções include, no que você está mantendo. Em seguida, exclua o outro e, nas propriedades do projeto, em **Cabeçalhos Pré-compilados**, certifique-se de que o nome do arquivo de cabeçalho esteja correto.  
  
     Se você alterou o arquivo a ser usado como o cabeçalho pré-compilado, certifique-se de que as opções de cabeçalho pré-compilado estejam corretas para cada arquivo. Selecione cada arquivo .cpp separadamente, abra sua janela Propriedades e certifique-se de que todos estejam definidos como **Usar (/Yu)**, exceto o cabeçalho pré-compilado desejado, que deve ser definido como **Criar (/Yc)**.  
  
7.  Compile o projeto e resolva quaisquer erros. Esses erros podem ser causados pelo uso da opção /ZW ou por uma nova versão do SDK do Windows ou podem refletir dependências como arquivos de cabeçalho dos quais sua biblioteca depende ou diferenças nas configurações do projeto entre o projeto antigo e o novo.  
  
8.  Adicione tipos de referência pública ao projeto ou converta tipos comuns em tipos de referência para expor os pontos de entrada na funcionalidade que você deseja chamar de aplicativos UWP.  
  
9. Teste o componente adicionando uma referência a ela de um projeto de aplicativo UWP e adicione um pouco de código para chamar as APIs públicas criadas.  
  
## <a name="see-also"></a>Consulte também  
 [Portabilidade para a Plataforma Universal do Windows](../porting/porting-to-the-universal-windows-platform-cpp.md)