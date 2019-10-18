---
title: Configurar as sessões de depuração do CMake no Visual Studio
ms.date: 03/21/2019
helpviewer_keywords:
- CMake debugging
ms.openlocfilehash: 41f53c0c3ea46a8a1aa11215968aaee6c13c2dea
ms.sourcegitcommit: e33126222c418daf977533ea9e2819d99e0d7b8d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/17/2019
ms.locfileid: "72534111"
---
# <a name="configure-cmake-debugging-sessions"></a>Configurar sessões de depuração do CMake

Todos os destinos executáveis do CMake são mostrados na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**. Para iniciar uma sessão de depuração, basta selecionar um e iniciar o depurador.

![Menu suspenso de item de inicialização CMake](media/cmake-startup-item-dropdown.png "Menu suspenso de item de inicialização CMake")

Você também pode iniciar uma sessão de depuração de Gerenciador de Soluções. Primeiro, alterne para o **modo de exibição de destinos CMake** na janela **Gerenciador de soluções** .

![Botão de exibição de destinos CMake](media/cmake-targets-view.png  "Item de menu de exibição de destinos CMake")

Em seguida, clique com o botão direito do mouse em qualquer executável e selecione **depurar** ou **depurar e iniciar as configurações**. **Debug** inicia automaticamente a depuração do destino selecionado, com base em sua configuração ativa. **Configurações de depuração e inicialização** abre o arquivo *Launch. vs. JSON* e adiciona uma nova configuração de depuração para o destino selecionado.

## <a name="customize-debugger-settings"></a>Personalizar configurações do depurador

Para personalizar as configurações do depurador para qualquer destino executável do CMake no projeto, clique com o botão direito do mouse no arquivo CMakeLists.txt específico e selecione **Configurações de Depuração e de Inicialização**. (Ou selecione um destino no **modo de exibição destinos** no **Gerenciador de soluções**.) Quando você seleciona um destino CMake no submenu, um arquivo chamado **Launch. vs. JSON** é criado. Esse arquivo é pré-populado com informações sobre o destino do CMake selecionado e permite que você especifique parâmetros adicionais, como argumentos de programa ou o tipo de depurador. Para fazer referência a qualquer chave em um arquivo **CMakeSettings. JSON** , preceda-a com `cmake.` em **Launch. vs. JSON**. O exemplo a seguir mostra um arquivo de **inicialização simples. vs. JSON** que efetua pull do valor da chave de `remoteCopySources` no arquivo **CMakeSettings. JSON** para a configuração selecionada no momento:

```json
{
  "version": "0.2.1",
  "defaults": {},
  "configurations": [
    {
      "type": "default",
      "project": "CMakeLists.txt",
      "projectTarget": "CMakeHelloWorld.exe (Debug\\CMakeHelloWorld.exe)",
      "name": "CMakeHelloWorld.exe (Debug\\CMakeHelloWorld.exe)",
      "args": ["${cmake.remoteCopySources}"]
    }
  ]
}
```

Assim que você salvar o arquivo **Launch. vs. JSON** , uma entrada será criada no menu suspenso **item de inicialização** com o novo nome. Editando o arquivo **Launch. vs. JSON** , você pode criar quantas configurações de depuração desejar para qualquer número de destinos CMake.

## <a name="support-for-cmakesettings-variables"></a>Suporte para variáveis de CMakeSettings

 **Inicialização. o vs. JSON** dá suporte a variáveis declaradas em **CMakeSettings. JSON** (veja abaixo) e que são aplicáveis à configuração selecionada no momento. Ele também tem uma chave chamada `currentDir`, que define o diretório atual do aplicativo de inicialização para um projeto local:

```json
{
  "type": "default",
  "project": "CMakeLists.txt",
  "projectTarget": "CMakeHelloWorld1.exe (C:\\Users\\satyan\\CMakeBuilds\\Test\\Debug\\CMakeHelloWorld1.exe)",
  "name": "CMakeHelloWorld1.exe (C:\\Users\\satyan\\CMakeBuilds\\Test\\Debug\\CMakeHelloWorld1.exe)",
  "currentDir": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}"
}
```

Quando você executa o aplicativo, o valor de `currentDir` é algo semelhante a

```cmd
C:\Users\satyan\7f14809a-2626-873e-952e-cdf038211175\
```

A chave ' CWD ' define o diretório atual do aplicativo de inicialização para um projeto remoto. O valor padrão é ' $ {debugInfo. defaultWorkingDirectory} ', que é avaliado como 

```cmd
/var/tmp/src/bfc6f7f4-4f0f-8b35-80d7-9198fa973fb9/Linux-Debug
```

## <a name="see-also"></a>Consulte também

[Projetos do CMake no Visual Studio](cmake-projects-in-visual-studio.md)<br/>
[Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md)<br/>
[Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)<br/>
[Personalizar as configurações de compilação do CMake](customize-cmake-settings.md)<br/>
[Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md)<br/>
[Implantar, executar e depurar o projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)<br/>
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)<br/>
