---
title: Portando para a Plataforma Universal do Windows (C++)
ms.date: 10/23/2019
ms.assetid: f662d2e4-8940-418d-8109-cb76cb8f8569
ms.openlocfilehash: 0013d85ad8c27c06560c9f9e541691f4335252d1
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80076849"
---
# <a name="porting-to-the-universal-windows-platform-c"></a>Portando para a Plataforma Universal do Windows (C++)

Neste tópico, você pode encontrar informações sobre como portar código C++ existente para a plataforma de aplicativo do Windows 10, a Plataforma Universal do Windows. O que significa que o termo *Universal* é que seu código pode ser executado em qualquer um dos dispositivos que executam o Windows 10. Você cria um único projeto e uma única interface do usuário baseada em XAML que funciona bem em qualquer dispositivo que executa Windows 10. Você pode usar recursos de layout dinâmico em XAML para permitir que a interface do usuário do aplicativo se adapte aos diferentes tamanhos de exibição.

A documentação do Centro de Desenvolvimento do Windows contém um guia para portabilidade de aplicativos do Windows 8.1 para a Plataforma Universal do Windows. Consulte [Mover do Windows Runtime 8 para UWP](/windows/uwp/porting/w8x-to-uwp-root). Embora o guia se concentre principalmente em código C#, a maioria das diretrizes são aplicáveis ao C++. Os procedimentos a seguir contêm informações mais detalhadas. Consulte também [mover de um aplicativo de área de trabalho para UWP](/windows/uwp/porting/desktop-to-uwp-migrate).

Este tópico contém os procedimentos a seguir para portabilidade de código para a UWP.

- [Portabilidade de um aplicativo da Windows 8.1 Store para a UWP](#BK_81StoreApp)

- [Portabilidade de um Componente do Runtime do Windows 8.1 para a UWP](#BK_81Component)

Se você tiver uma DLL de área de trabalho clássica Win32 e desejar chamá-la de um aplicativo da UWP, você poderá fazer isso também. Usando esses procedimentos, você pode criar uma camada da interface do usuário da UWP para um aplicativo C++ da área de trabalho do Windows clássica existente ou seu código C++ padrão de plataforma cruzada. Veja [Como usar o código C++ existente em um aplicativo da Plataforma Universal do Windows](../porting/how-to-use-existing-cpp-code-in-a-universal-windows-platform-app.md).

## <a name="porting-a-windows-81-store-app-to-the-uwp"></a><a name="BK_81StoreApp"></a> Portabilidade de um aplicativo da Windows 8.1 Store para a UWP

Se você tiver um aplicativo da Windows 8.1 Store, você poderá usar este procedimento para fazê-lo funcionar na UWP e em qualquer dispositivo que execute o Windows 10.  É uma boa ideia criar primeiro o projeto com o Visual Studio 2019 como um projeto Windows 8.1, para primeiro eliminar os problemas que surgirem de alterações no compilador e nas bibliotecas. Depois disso, há duas maneiras para converter isso em um projeto do Windows 10 da UWP. A maneira mais fácil (conforme explicado no procedimento a seguir) é criar um projeto Universal do Windows e copiar o código existente dentro dele. Se você estiver usando um projeto Universal para área de trabalho do Windows 8.1 e Windows 8.1 Phone, seu projeto será iniciado com dois layouts diferentes em XAML mas terminará com um único layout dinâmico, que se ajusta o tamanho de exibição.

### <a name="to-port-a-windows-81-store-app-to-the-uwp"></a>Para portar um aplicativo da Windows 8.1 Store para a UWP

1. Se você ainda não fez isso, abra o projeto de aplicativo do Windows 8.1 no Visual Studio 2017 e siga as instruções para atualizar o arquivo de projeto.

   Você precisa ter instalado as **Ferramentas do Windows 8.1 na instalação do Visual Studio**. Se essas ferramentas não estiverem instaladas, inicie a instalação do **Visual Studio** pela janela **Programas e Recursos**, escolha **Visual Studio 2017** e, na janela de instalação, escolha **Modificar**. Localize as **Ferramentas do Windows 8.1**, verifique se essa opção está selecionada e escolha **OK**.

1. Abra a janela **Propriedades do Projeto** e, em **C++**  > **Geral**, defina o **Conjunto de Ferramentas da Plataforma** como **v141**, o conjunto de ferramentas para o Visual Studio 2017.

1. Compile o projeto como um projeto Windows 8.1 e resolva eventuais erros de build. Quaisquer erros neste estágio são provavelmente devido a alterações interruptivas nas ferramentas de build e bibliotecas. Consulte [Histórico de alterações de 2003 – 2015 do Visual C++](../porting/visual-cpp-change-history-2003-2015.md) para obter uma explicação detalhada das alterações que podem afetar seu código.

   Depois que o projeto é compilado corretamente, você está pronto para portar para Universal do Windows (Windows 10).

1. Crie um novo projeto de aplicativo Universal do Windows usando o modelo em branco. Você talvez queira dar a ele o mesmo nome do seu projeto existente, embora os projetos precisem estar em diretórios diferentes para que seja possível fazer isso.

1. Feche a solução e, em seguida, usando o **Windows Explorer** ou a linha de comando, copie os arquivos de código (com extensões .cpp, .h e .xaml) do projeto do Windows 8.1 para a mesma pasta que o arquivo de projeto (.vcxproj) do projeto que você criou na Etapa 1. Não copie o arquivo Package.appxmanifest e, se você tiver códigos separados para telefone e área de trabalho do Windows 8.1, escolha um deles para portar primeiro (você precisará trabalhar um pouco mais tarde para adaptar-se ao outro). Certifique-se de copiar todas as subpastas e seus conteúdos. Se solicitado, escolha substituir todos os arquivos com nomes duplicados.

1. Reabra a solução e, em seguida, escolha **Adicionar** > **Item Existente** no menu de atalho do nó do projeto. Selecione todos os arquivos que você copiou, exceto eventuais arquivos que já sejam parte do projeto.

   Verifique eventuais subpastas e certifique-se de adicionar os arquivos nelas também.

1. Se você não estiver usando o mesmo nome do projeto usado em seu projeto anterior, abra o arquivo Package.appxmanifest e atualize o **Ponto de Entrada** para refletir o nome do namespace da classe `App`.

   O campo **Ponto de Entrada** no arquivo Package.appxmanifest contém um nome de escopo para a classe `App`, o qual inclui o namespace que contém a classe `App`. Quando você cria um projeto Universal do Windows, o namespace é definido como o nome do projeto. Se isso for diferente do que está nos arquivos copiados de seu projeto antigo, você deverá atualizar um ou outro para que eles correspondam.

1. Compile o projeto e resolva eventuais erros de build devidos a alterações interruptivas entre as diferentes versões do SDK do Windows.

1. Execute o projeto na área de trabalho local. Verifique se não há nenhum erro de implantação e se o layout do aplicativo parece razoável e se ele funciona corretamente na área de trabalho.

1. Se você tiver arquivos de código separados e .xaml para outro dispositivo, como Windows Phone 8.1, examine esse código e identifique onde ele difere do dispositivo padrão. Se a diferença for apenas no layout, você poderá usar um **Gerenciador de Estado Visual** no XAML para personalizar a exibição, dependendo do tamanho da tela. Para outras diferenças, você pode usar seções de condições no seu código usando as instruções #if a seguir.

    ```cpp
    #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PC_APP)
    #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_PHONE_APP)
    #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
    #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ```

   Essas instruções aplicam-se, respectivamente, a aplicativos UWP e a aplicativos da Windows Phone Store, a ambos ou a nenhum (somente área de trabalho clássica do Win32). Essas macros estão disponíveis apenas no SDK do Windows 8.1 e posterior, portanto, se seu código precisar ser compilado com versões anteriores do SDK do Windows ou para outras plataformas além do Windows, você também deverá considerar a possibilidade de que nenhuma delas esteja definida.

1. Execute e depure o aplicativo em um emulador ou um dispositivo físico para cada tipo de dispositivo ao qual seu aplicativo dá suporte. Para executar um emulador, você precisa executar o Visual Studio em um computador físico, não em uma máquina virtual.

## <a name="porting-a-windows-81-runtime-component-to-the-uwp"></a><a name="BK_81Component"></a> Portabilidade um Componente do Runtime do Windows 8.1 para a UWP

Se você tiver uma DLL ou um componente do Windows Runtime que já funciona com aplicativos da Windows 8.1 Store, você poderá usar este procedimento fazer com que o componente ou DLL funcione com a UWP e o Windows 10. O procedimento básico é criar um novo projeto e copiar seu código nele.

### <a name="to-port-a-windows-81-runtime-component-to-the-uwp"></a>Para portar um Componente do Runtime do Windows 8.1 para a UWP

1. Na caixa de diálogo **Novo Projeto** no Visual Studio 2017, localize o nó **Windows Universal**. Se você não vir esse nó, instale primeiro o [SDK do Windows 10](https://developer.microsoft.com/windows/downloads/windows-10-sdk). Escolha o modelo **componente do Windows Runtime**, dê um nome para seu componente e escolha o botão **OK**. O nome do componente será usado como o nome do namespace, então você talvez queira usar o mesmo nome do namespace do seu projeto antigo. Isso requer que você crie o projeto em uma pasta diferente da antiga. Se você escolher um nome diferente, você poderá atualizar o nome do namespace nos arquivos de código gerados.

1. Feche o projeto.

1. Copie todos os arquivos de código (.cpp, .h, .xaml, etc.) de seu componente Windows 8.1 para seu projeto recém-criado. Não copie o arquivo Package.appxmanifest.

1. Compile e resolva quaisquer erros devidos a alterações interruptivas entre versões diferentes do Windows SDK.

## <a name="troubleshooting"></a>solução de problemas

É possível encontrar vários erros durante o processo de portabilidade do código para a UWP. Aqui estão alguns dos problemas possíveis que podem ser encontrados.

### <a name="project-configuration-issues"></a>Problemas de configuração do projeto

Você pode receber o erro:

```Output
could not find assembly 'platform.winmd': please specify the assembly search path using /AI or by setting the LIBPATH environment variable
```

Se isso acontecer, o projeto não está sendo compilado como um projeto Universal do Windows. Verifique o arquivo de projeto e verifique se que ele tem os elementos XML corretos que identificam um projeto como um projeto Universal do Windows. Os elementos a seguir devem estar presentes (o número de versão da plataforma de destino pode ser diferente):

```xml
<AppContainerApplication>true</AppContainerApplication>
<ApplicationType>Windows Store</ApplicationType>
<WindowsTargetPlatformVersion>10.0.10156.0</WindowsTargetPlatformVersion>
<WindowsTargetPlatformMinVersion>10.0.10156.0</WindowsTargetPlatformMinVersion>
<ApplicationTypeRevision>10.0</ApplicationTypeRevision>
```

Se você criar um novo projeto UWP usando o Visual Studio, esse erro não deverá aparecer.

## <a name="see-also"></a>Confira também

[Guia de portabilidade do Visual C++](../porting/porting-to-the-universal-windows-platform-cpp.md)<br/>
[Desenvolver aplicativos para a UWP (Plataforma Universal do Windows)](/visualstudio/cross-platform/develop-apps-for-the-universal-windows-platform-uwp)