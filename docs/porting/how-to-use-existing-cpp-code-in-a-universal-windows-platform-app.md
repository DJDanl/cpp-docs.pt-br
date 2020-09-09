---
title: 'Como: usar o código C++ existente em um aplicativo da Plataforma Universal do Windows'
description: Maneiras de usar seus aplicativos de código existentes e bibliotecas em Plataforma Universal do Windows aplicativos.
ms.date: 09/04/2020
ms.assetid: 87e5818c-3081-42f3-a30d-3dca2cf0645c
ms.openlocfilehash: 1e946d588f1a14018ebb11a60b319c2d54658f25
ms.sourcegitcommit: 0df2b7ab4e81284c5248e4584767591dcc1950c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/09/2020
ms.locfileid: "89609125"
---
# <a name="how-to-use-existing-c-code-in-a-universal-windows-platform-app"></a>Como: usar o código C++ existente em um aplicativo da Plataforma Universal do Windows

Há várias maneiras pelas quais você pode usar o código C++ existente em projetos Plataforma Universal do Windows (UWP). Algumas maneiras de não exigir que o código seja recompilado com as extensões de componente (C++/CX) habilitadas (ou seja, com a `/ZW` opção) e outras têm. Talvez seja necessário manter o código no C++ padrão ou preservar um ambiente de compilação do Win32 clássico para algum código. Você ainda pode fazer isso, com as opções de arquitetura apropriadas. Considere todo o código que contém a interface do usuário da UWP e os tipos expostos aos chamadores C#, Visual Basic e JavaScript. Esse código deve estar em projetos de aplicativos do Windows e Windows Runtime projetos de componentes. O código que você chama apenas do C++ (incluindo C++/CX) pode estar em um projeto que é compilado com a `/ZW` opção ou um projeto C++ padrão. Código somente binário que não usa APIs não permitidas pode ser usado vinculando-o como uma biblioteca estática. Ou você pode empacotá-lo com o aplicativo como conteúdo e carregá-lo em uma DLL.

Talvez a maneira mais fácil para que seu programa da área de trabalho seja executado no ambiente UWP seja usar as tecnologias de Ponte de Desktop. Eles incluem o conversor de aplicativo de área de trabalho, que empacotará seu aplicativo existente como um aplicativo UWP sem nenhuma alteração de código necessária. Para saber mais, veja [Ponte de Desktop](/windows/uwp/porting/desktop-to-uwp-root).

O restante deste artigo discute como portar bibliotecas C++ (DLLs e bibliotecas estáticas) para o Plataforma Universal do Windows. Talvez você queira portar seu código para que a lógica C++ principal possa ser usada com vários aplicativos UWP.

Os aplicativos UWP são executados em um ambiente protegido. Como resultado, muitas chamadas de API do Win32, COM e CRT que podem comprometer a segurança da plataforma não são permitidas. A `/ZW` opção do compilador pode detectar essas chamadas e gerar um erro. Você pode usar o kit de certificação de aplicativo em seu aplicativo para detectar o código que chama APIs não permitidas. Para obter mais informações, confira [Kit de certificação de aplicativos do Windows](/windows/uwp/debug-test-perf/windows-app-certification-kit).

Se o código-fonte estiver disponível para a biblioteca, você poderá tentar eliminar as chamadas de API não permitidas. Para obter uma lista de APIs que não são permitidas, consulte [Win32 e APIs com para aplicativos UWP](/uwp/win32-and-com/win32-and-com-for-uwp-apps) e [funções CRT sem suporte em aplicativos plataforma universal do Windows](../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md). Algumas alternativas podem ser encontradas em [Alternatives to Windows APIs in UWP apps](/uwp/win32-and-com/alternatives-to-windows-apis-uwp) (Alternativas para APIs do Windows em aplicativos UWP).

Se você tentar apenas adicionar uma referência de um projeto universal do Windows a uma biblioteca de desktops clássica, receberá uma mensagem de erro informando que a biblioteca não é compatível. Se for uma biblioteca estática, você poderá vincular à biblioteca adicionando a biblioteca ( *`.lib`* arquivo) à entrada do vinculador, da mesma forma que faria em um aplicativo Win32 clássico. Se apenas uma biblioteca binária estiver disponível, ela será a única opção. Uma biblioteca estática é vinculada ao executável do seu aplicativo. No entanto, uma DLL do Win32 que você consome em um aplicativo UWP deve ser empacotada no aplicativo, incluindo-o no projeto e marcá-lo como conteúdo. Para carregar uma DLL Win32 em um aplicativo UWP, você também precisa chamar [`LoadPackagedLibrary`](/windows/win32/api/winbase/nf-winbase-loadpackagedlibrary) em vez de `LoadLibrary` ou `LoadLibraryEx` .

Se você tiver o código-fonte para a DLL ou a biblioteca estática, poderá recompilá-lo como um projeto UWP usando a `/ZW` opção do compilador. Em seguida, você pode adicionar uma referência a ele usando o **Gerenciador de soluções**e usá-lo em aplicativos UWP do C++. Vincule a DLL usando a biblioteca de exportação.

Para expor a funcionalidade para chamadores em outras linguagens, você pode converter a biblioteca em um componente do Windows Runtime. Windows Runtime componentes diferem de DLLs comuns, pois eles incluem metadados na forma de *`.winmd`* arquivos que descrevem o conteúdo de uma maneira que os consumidores .net e JavaScript exigem.  Para expor elementos de API a outras linguagens, você pode adicionar construções C++/CX, como classes ref, e torná-las públicas. No Windows 10 e posterior, recomendamos a [biblioteca c++/WinRT](https://github.com/microsoft/cppwinrt) em vez de c++/CX.

A discussão anterior não se aplica a componentes COM, que devem ser tratados de forma diferente. Se você tiver um servidor COM em um EXE ou DLL, poderá usá-lo em um projeto universal do Windows. Empacote-o como um [componente com livre de registro](/windows/win32/sbscs/creating-registration-free-com-objects), adicione-o ao seu projeto como um arquivo de conteúdo e instancie-o usando [`CoCreateInstanceFromApp`](/windows/win32/api/combaseapi/nf-combaseapi-cocreateinstancefromapp) . Para obter mais informações, confira [Using Free-COM DLL in Windows Store C++ Project](/archive/blogs/win8devsupport/using-free-com-dll-in-windows-store-c-project) (Usando a DLL Free-COM no projeto C ++ da Windows Store).

Se você quiser portar uma biblioteca COM existente para a UWP, também é possível convertê-la em um componente Windows Runtime. Recomendamos a biblioteca C++/WinRT para essas portas, mas também é possível usar a [Windows Runtime WRL (biblioteca de modelos do c++)](../windows/windows-runtime-cpp-template-library-wrl.md). O WRL é preterido e não dá suporte a todos os recursos de ATL e OLE. A possibilidade de tal porta ser viável depende dos recursos de COM, ATL e OLE que seu componente requer.

Seja qual for o cenário de desenvolvimento escolhido, você deve estar ciente de várias definições de macro. Você pode usar essas macros em seu código para compilar código condicionalmente sob a área de trabalho clássica Win32 e UWP.

```cpp
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP)
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP)
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
```

Essas instruções aplicam-se, respectivamente, a aplicativos UWP e a aplicativos da Windows Phone Store, a ambos ou a nenhum (somente área de trabalho clássica do Win32). Essas macros só estão disponíveis no SDK do Windows 8,1 e posterior.

Este artigo contém os seguintes procedimentos:

- [Como usar uma DLL do Win32 em um aplicativo UWP](#BK_Win32DLL)

- [Usando uma biblioteca estática C++ nativa em um aplicativo UWP](#BK_StaticLib)

- [Portando uma biblioteca C++ para um componente Windows Runtime](#BK_WinRTComponent)

## <a name="using-a-win32-dll-in-a-uwp-app"></a><a name="BK_Win32DLL"></a> Usando uma DLL Win32 em um aplicativo UWP

Para melhorar a segurança e a confiabilidade, os aplicativos universais do Windows são executados em um ambiente de tempo de execução restrito. Você não pode simplesmente usar qualquer DLL nativa como faria em um aplicativo de área de trabalho do Windows clássico. Se você tiver o código-fonte para uma DLL, poderá transportar o código para que ele seja executado na UWP. Comece alterando algumas configurações do projeto e metadados de arquivo de projeto para identificar o projeto como um projeto UWP. Você recompilará o código da biblioteca usando a `/ZW` opção, que habilita o C++/CX. Determinadas chamadas à API não são permitidas em aplicativos UWP devido aos controles mais estritos associados a esse ambiente. Para obter mais informações, consulte [APIs do Win32 e com para aplicativos UWP](/uwp/win32-and-com/win32-and-com-for-uwp-apps).

Se houver uma DLL nativa que exporta funções usando `__declspec(dllexport)`, você poderá chamar essas funções em um aplicativo UWP recompilando a DLL como um projeto UWP. Por exemplo, suponha que tenhamos um projeto de DLL Win32 chamado *Giraffe* que exporta algumas classes e seus métodos, com um código como o seguinte arquivo de cabeçalho:

```cpp
// giraffe.h
// Define GIRAFFE_EXPORTS when building this DLL
#pragma once

#ifdef GIRAFFE_EXPORTS
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

```cpp
// giraffe.cpp
#include "pch.h"
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

Tudo o mais no projeto ( *`pch.h`* , *`dllmain.cpp`* ) faz parte do modelo de projeto Win32 padrão. O código define a macro `GIRAFFE_API` , que é resolvida `__declspec(dllexport)` quando `GIRAFFE_EXPORTS` é definida. Ou seja, ele é definido quando o projeto é compilado como uma DLL, mas não quando um cliente usa o *`giraffe.h`* cabeçalho. Essa DLL pode ser usada em um projeto UWP sem alterar o código-fonte. Somente algumas configurações e propriedades de projeto precisam ser alteradas.

O procedimento a seguir se aplica quando você tem uma DLL nativa que expõe funções usando o `__declspec(dllexport)` .

### <a name="to-port-a-native-dll-to-the-uwp-without-creating-a-new-project"></a>Para transportar uma DLL nativa para a UWP sem criar um novo projeto

1. Abra seu projeto de DLL no Visual Studio.

1. Abra as **Propriedades do projeto** para o projeto DLL e defina a **configuração** para **todas as configurações**.

1. Nas **Propriedades do Projeto**, na guia **C/C++** > **Geral**, defina **Consumir extensão do Windows Runtime** para **Yes (/ZW)**. Essa propriedade habilita extensões de componente (C++/CX).

1. Em **Gerenciador de soluções**, selecione o nó do projeto, abra o menu de atalho e escolha **descarregar projeto**. Em seguida, abra o menu de atalho no nó do projeto descarregado e escolha editar o arquivo de projeto. Localize o elemento `WindowsTargetPlatformVersion` e substitua-o pelos seguintes elementos.

    ```xml
    <AppContainerApplication>true</AppContainerApplication>
    <ApplicationType>Windows Store</ApplicationType>
    <WindowsTargetPlatformVersion>10.0.10156.0</WindowsTargetPlatformVersion>
    <WindowsTargetPlatformMinVersion>10.0.10156.0</WindowsTargetPlatformMinVersion>
    <ApplicationTypeRevision>10.0</ApplicationTypeRevision>
    ```

   Feche o *`.vcxproj`* arquivo, abra o menu de atalho novamente e escolha **recarregar projeto**.

   **Gerenciador de soluções** agora identifica o projeto como um projeto universal do Windows.

1. Verifique se o nome do arquivo de cabeçalho pré-compilado está correto. Na seção **cabeçalhos pré-compilados** , talvez seja necessário alterar o **arquivo de cabeçalho pré-compilado** do *`pch.h`* para *`stdafx.h`* o ou o contrário, se você vir um erro como este:

   > erro C2857: a instrução ' #include ' especificada com a **`/Ycpch.h`** opção de linha de comando não foi encontrada no arquivo de origem

   O problema é que os modelos de projeto mais antigos usam uma Convenção de nomenclatura diferente para o arquivo de cabeçalho pré-compilado. O Visual Studio 2019 e os projetos posteriores usam *`pch.h`* .

1. Compile o projeto. Você pode receber alguns erros sobre opções de linha de comando incompatíveis. Por exemplo, a opção usada com frequência, mas agora preterida **Habilitar Recompilação Mínima (/Gm)**, é definida por padrão em muitos projetos C++ mais antigos e é incompatível com `/ZW`.

   Algumas funções não estão disponíveis quando você compila para o Plataforma Universal do Windows. Você verá erros do compilador sobre quaisquer problemas. Resolva esses erros até ter uma compilação limpa.

1. Para usar a dll em um aplicativo UWP na mesma solução, abra o menu de atalho para o nó do projeto UWP e escolha **Adicionar**  >  **referência**.

   Em **Projects**  >  **solução**de projetos, marque a caixa de seleção ao lado do projeto de dll e escolha o botão **OK** .

1. Inclua os arquivos de cabeçalho da biblioteca no arquivo do seu aplicativo UWP *`pch.h`* .

    ```cpp
    #include "..\Giraffe\giraffe.h"
    ```

1. Adicione o código como de costume no projeto UWP para invocar funções e criar tipos da DLL.

    ```cpp
    MainPage::MainPage()
    {
        InitializeComponent();
        GiraffeFactory gf;
        Giraffe* g = gf.Create();
        int id = g->GetID();
    }
    ```

## <a name="using-a-native-c-static-library-in-a-uwp-app"></a><a name="BK_StaticLib"></a> Usando uma biblioteca estática em C++ nativa em um aplicativo UWP

Você pode usar uma biblioteca estática em C++ nativa em um projeto UWP, mas há algumas restrições e limitações para estar atento. Comece lendo sobre [bibliotecas estáticas em C++/CX](../cppcx/static-libraries-c-cx.md). Você pode acessar o código nativo na biblioteca estática do aplicativo UWP, mas não é recomendável criar tipos de referência pública nessa biblioteca estática. Se você compilar uma biblioteca estática com a opção `/ZW`, o bibliotecário (na verdade, o vinculador disfarçado) avisará:

> LNK4264: arquivando arquivo-objeto compilado com /ZW em uma biblioteca estática; observe que, na criação de tipos do Windows Runtime, não é recomendado vincular a uma biblioteca estática que contêm metadados do Windows Runtime

No entanto, você pode usar uma biblioteca estática em um aplicativo UWP sem recompilá-la com `/ZW` . Sua biblioteca não pode declarar tipos de referência nem usar construções C++/CX. Mas, se sua finalidade for usar apenas uma biblioteca de código nativo, você poderá fazer isso seguindo estas etapas.

### <a name="to-use-a-native-c-static-library-in-a-uwp-project"></a>Para usar uma biblioteca estática em C++ nativa em um projeto UWP

1. Nas propriedades do projeto para o projeto UWP, escolha **Configuration Properties**  >  entrada do**vinculador**de propriedades  >  **Input** de configuração no painel esquerdo. No painel direito, adicione o caminho para a biblioteca na propriedade **Dependências Adicionais**. Por exemplo, para uma biblioteca no projeto que coloca sua saída no *`<SolutionFolder>\Debug\MyNativeLibrary\MyNativeLibrary.lib`* , adicione o caminho relativo *`Debug\MyNativeLibrary\MyNativeLibrary.lib`* .

1. Adicione uma instrução include para referenciar o arquivo de cabeçalho em seu *`pch.h`* arquivo (se presente), ou em qualquer *`.cpp`* arquivo, conforme necessário, e comece a adicionar o código que usa a biblioteca.

   ```cpp
   #include "..\MyNativeLibrary\MyNativeLibrary.h"
   ```

   Não adicione uma referência no nó **referências** em **Gerenciador de soluções**. Esse mecanismo funciona somente para Componente do Windows Runtime.

## <a name="porting-a-c-library-to-a-windows-runtime-component"></a><a name="BK_WinRTComponent"></a> Portabilidade uma biblioteca C++ para um componente do Windows Runtime

Suponha que você deseja consumir APIs nativas em uma biblioteca estática de um aplicativo UWP. Se você tiver o código-fonte para a biblioteca nativa, poderá portar o código para um componente Windows Runtime. Ela não será mais uma biblioteca estática; Você o transforma em uma DLL que pode usar em qualquer aplicativo UWP do C++. Este procedimento descreve como criar um novo componente Windows Runtime que usa as extensões C++/CX. Para obter informações sobre como criar um componente que usa C++/WinRT em vez disso, consulte [Windows Runtime Components with c++/WinRT](/windows/uwp/winrt-components/create-a-windows-runtime-component-in-cppwinrt).

Ao usar C++/CX, você pode adicionar tipos de referência e outras construções C++/CX, que estão disponíveis para clientes em qualquer código de aplicativo UWP. Você pode acessar esses tipos em C#, Visual Basic ou JavaScript. O procedimento básico é:

- Criar um projeto de componente Windows Runtime (universal do Windows),
- Copie o código para sua biblioteca estática para ele e
- Resolva os erros do compilador causados pela `/ZW` opção.

### <a name="to-port-a-c-library-to-a-windows-runtime-component"></a>Para transportar uma biblioteca C++ para um componente do Windows Runtime

1. Crie um projeto de componente Windows Runtime (universal do Windows).

1. Feche o projeto.

1. No **Explorador de arquivos do Windows**, localize o novo projeto. Em seguida, localize o projeto de biblioteca C++ que contém o código que você deseja portar. Copie os arquivos de origem (arquivos de cabeçalho, arquivos de código e quaisquer outros recursos, incluindo em subdiretórios) do seu projeto de biblioteca C++. Cole-os na nova pasta do projeto, garantindo a preservação da mesma estrutura de pastas.

1. Reabra o projeto de componente Windows Runtime. Abra o menu de atalho do nó do projeto no **Gerenciador de soluções**e escolha **Adicionar**  >  **Item existente**.

1. Selecione todos os arquivos a serem adicionados do seu projeto original e escolha **OK**. Repita se necessário para as subpastas.

1. Agora você pode ter alguns códigos duplicados. Se houver mais de um cabeçalho pré-compilado (digamos, *`stdafx.h`* e *`pch.h`* ), escolha um para manter. Copie qualquer código necessário, como instruções include, no que você está mantendo. Em seguida, exclua o outro e, nas propriedades do projeto, em **cabeçalhos pré-compilados**, verifique se o nome do arquivo de cabeçalho está correto.

   Se você alterou o arquivo a ser usado como o cabeçalho pré-compilado, certifique-se de que as opções de cabeçalho pré-compilado estejam corretas para cada arquivo. Selecione cada *`.cpp`* arquivo por vez, abra sua janela Propriedades e verifique se todos estão definidos como **usar (/Yu)**, exceto para o cabeçalho pré-compilado, que deve ser definido como **Create (/Yc)**.

1. Compile o projeto e resolva quaisquer erros. Esses erros podem ser causados usando a `/ZW` opção ou podem ser causados por uma nova versão do SDK do Windows. Ou, eles podem refletir dependências como arquivos de cabeçalho dos quais sua biblioteca depende, ou diferenças nas configurações do projeto entre o projeto antigo e o novo.

1. Adicione tipos de referência públicos ao seu projeto ou converta tipos comuns em tipos de referência. Use esses tipos para expor pontos de entrada para a funcionalidade que você deseja chamar de aplicativos UWP.

1. Teste o componente adicionando uma referência a ela de um projeto de aplicativo UWP e adicione um pouco de código para chamar as APIs públicas criadas.

## <a name="see-also"></a>Confira também

[Portabilidade para a Plataforma Universal do Windows](../porting/porting-to-the-universal-windows-platform-cpp.md)
