---
title: Configurar as sessões de depuração do CMake no Visual Studio
ms.date: 03/05/2019
helpviewer_keywords:
- CMake debugging
ms.openlocfilehash: 9a4dd009544a4590c336697ba2162eec45718869
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824637"
---
# <a name="configure-cmake-debugging-sessions"></a>Configurar sessões de depuração do CMake

Todos os destinos executáveis do CMake são mostrados na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**. Para iniciar uma sessão de depuração, basta selecionar um e iniciar o depurador.

![Lista suspensa de item de inicialização do CMake](media/cmake-startup-item-dropdown.png "CMake startup item dropdown")

Inicie também uma sessão de depuração por meio dos menus do CMake.

## <a name="customize-debugger-settings"></a>Personalizar configurações do depurador

Para personalizar as configurações do depurador para qualquer destino executável do CMake no projeto, clique com o botão direito do mouse no arquivo CMakeLists.txt específico e selecione **Configurações de Depuração e de Inicialização**. Quando você seleciona um destino do CMake no submenu, um arquivo chamado `launch.vs.json` é criado. Esse arquivo é pré-populado com informações sobre o destino do CMake selecionado e permite que você especifique parâmetros adicionais, como argumentos de programa ou o tipo de depurador. Para fazer referência a qualquer chave em um arquivo `CMakeSettings.json`, preceda-o com `cmake.` em `launch.vs.json`. O exemplo a seguir mostra um arquivo `launch.vs.json` simples que captura o valor da chave `remoteCopySources` no arquivo `CMakeSettings.json` para a configuração selecionada no momento:

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

Assim que você salva o arquivo `launch.vs.json`, uma entrada é criada na lista suspensa **Item de Inicialização** com o novo nome. Editando o arquivo `launch.vs.json`, crie quantas configurações de depuração desejar para qualquer quantidade de destinos do CMake.

## <a name="support-for-cmakesettings-variables"></a>Suporte para variáveis de CMakeSettings

 `Launch.vs.json` dá suporte a variáveis declaradas no `CMakeSettings.json` (veja abaixo) aplicáveis à configuração selecionada no momento. Também contém uma chave chamada `currentDir`, que define o diretório atual do aplicativo a ser iniciado:

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
## <a name="see-also"></a>Consulte também

[Projetos de CMake no Visual Studio](cmake-projects-in-visual-studio.md)<br/>
[Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md)<br/>
[Conectar-se ao computador Linux remoto](../linux/connect-to-your-remote-linux-computer.md)<br/>
[Personalizar as configurações de compilação do CMake](customize-cmake-settings.md)<br/>
[Configurar sessões de depuração do CMake](configure-cmake-debugging-sessions.md)<br/>
[Implantar, executar e depurar o projeto do Linux](../linux/deploy-run-and-debug-your-linux-project.md)<br/>
[Referência de configuração predefinida do CMake](cmake-predefined-configuration-reference.md)<br/>