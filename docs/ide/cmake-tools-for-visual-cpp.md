---
title: Projetos do CMake no Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 08/08/2017
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- CMake in Visual C++
ms.assetid: 444d50df-215e-4d31-933a-b41841f186f8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f3a65ae6cc58f649fee5f47b33a146263a3b6c55
ms.sourcegitcommit: a4454b91d556a3dc43d8755cdcdeabcc9285a20e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/04/2018
ms.locfileid: "33337425"
---
# <a name="cmake-projects-in-visual-c"></a>Projetos do CMake no Visual C++

Este artigo pressupõe que você esteja familiarizado com o CMake, uma ferramenta de software livre multiplataforma para a definição dos processos de build executados em várias plataformas.

Até recentemente, os usuários do Visual Studio podiam usar o CMake para gerar arquivos de projeto do MSBuild, que, em seguida, eram consumidos pelo IDE para o IntelliSense, a navegação e o build. Começando pelo Visual Studio 2017, o componente **Ferramentas do Visual C++ para CMake** usa o recurso **Abrir Pasta** para permitir o consumo pelo IDE de arquivos de projeto do CMake (como CMakeLists.txt) diretamente para as finalidades do IntelliSense e de navegação. Se você usar um gerador do Visual Studio, um arquivo de projeto temporário será gerado e passado para msbuild.exe, mas nunca será carregado para as finalidades do IntelliSense ou de navegação. 

**Visual Studio 2017 versão 15.3**: o suporte é fornecido para geradores do Ninja e do Visual Studio.

**Visual Studio 2017 versão 15.4**: adição do suporte para o CMake no Linux. Para obter mais informações, consulte [Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md).

**Visual Studio 2017 versão 15.5**: adição de suporte para importação de um cache do CMake existente. O Visual Studio extrai variáveis personalizadas automaticamente e cria um arquivo CMakeSettings.json pré-populado.


## <a name="installation"></a>Instalação

As **Ferramentas do Visual C++ para CMake** são instaladas por padrão como parte da carga de trabalho **Desenvolvimento para desktop com C++**.

![Componente CMake na carga de trabalho Desktop com C++](media/cmake-install.png)
 
## <a name="ide-integration"></a>Integração com o IDE

Quando você escolhe **Arquivo | Abrir | Pasta** para abrir uma pasta que contém um arquivo CMakeLists.txt, as seguintes ações ocorrem:

- O Visual Studio adiciona um item de menu **CMake** ao menu principal, com comandos para exibição e edição de scripts do CMake.
- O **Gerenciador de Soluções** exibe a estrutura de pastas e os arquivos.
- O Visual Studio executa CMake.exe e gera o cache do CMake para a *configuração* padrão, que é Depuração x86. A linha de comando do CMake é exibida na **Janela de Saída**, juntamente com uma saída adicional do CMake.
- Em segundo plano, o Visual Studio começa a indexar os arquivos de origem para habilitar o IntelliSense, as informações de navegação, a refatoração e assim por diante. Conforme você trabalha, o Visual Studio monitora as alterações feitas no editor e também em disco para manter seu índice em sincronia com as fontes.
 
Você pode abrir pastas que contêm qualquer quantidade de projetos do CMake. O Visual Studio detecta e configura todos os arquivos CMakeLists.txt "raiz" no espaço de trabalho. As operações do CMake (configuração, build, depuração), bem como o C++ IntelliSense e a navegação, estão disponíveis para todos os projetos do CMake no espaço de trabalho.

![Projeto do CMake com várias raízes](media/cmake-multiple-roots.png) 

## <a name="import-an-existing-cache"></a>Importar um cache existente

Quando você importa um arquivo CMakeCache.txt existente, o Visual Studio extrai as variáveis personalizadas automaticamente e cria um arquivo CMakeSettings.json pré-populado baseado nelas. O cache original não é modificado de forma alguma e ainda pode ser usado na linha de comando ou com qualquer ferramenta ou IDE que foi usado para gerá-lo. O novo arquivo CMakeSettings.json é colocado ao lado de CMakeLists.txt raiz do projeto. O Visual Studio gera um novo cache com base no arquivo de configurações. Nem tudo no cache é importado.  Propriedades, como o gerador e o local dos compiladores, são substituídas pelos padrões conhecidos por funcionar bem com o IDE.

### <a name="to-import-an-existing-cache"></a>Para importar um cache existente

1. No menu principal, escolha **Arquivo | Abrir | CMake**:

   ![Abrir o CMake](media/cmake-file-open.png "Arquivo, Abrir, CMake") 

   Isso abrirá o assistente para **Importar o CMake do Cache**. 
   
2. Navegue para o arquivo CMakeCache.txt que deseja importar e, em seguida, clique em **OK**. O assistente para **Importar Projeto do CMake do Cache** será exibido:

   ![Importar um cache do CMake](media/cmake-import-wizard.png "Abrir o assistente para importar cache do CMake") 

   Quando o assistente for concluído, você poderá ver o novo arquivo CMakeCache.txt no **Gerenciador de Soluções** ao lado do arquivo CMakeLists.txt raiz no projeto.


## <a name="building-cmake-projects"></a>Compilando projetos do CMake

Para compilar um projeto do CMake, você tem estas opções:

1. Selecione o destino na lista suspensa **Depuração** e pressione **F5** ou clique no botão **Executar** (triângulo verde). O projeto será compilado automaticamente pela primeira vez, assim como uma solução do Visual Studio.
1. Clique com o botão direito do mouse em CMakeLists.txt e selecione **Build** no menu de contexto. Se você tiver vários destinos na estrutura de pastas, opte por compilar todos ou apenas um destino específico ou
1. No menu principal, selecione **Build | Compilar Solução** (**F7** ou **Ctrl+Shift+B**). Verifique se um destino do CMake já está selecionado na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**.

![Comando de menu de build do CMake](media/cmake-build-menu.png "Cmake build command menu") 

Quando um gerador do Visual Studio é selecionado para a configuração ativa, MSBuild.exe é invocado com `-m -v:minimal` argumentos. Para personalizar o build, dentro do arquivo CMakeSettings.json, especifique argumentos de linha de comando adicionais a serem passados para o sistema de build por meio da propriedade `buildCommandArgs`:

```json
"buildCommandArgs": "-m:8 -v:minimal -p:PreferredToolArchitecture=x64"
```

Como se esperaria, os resultados do build são mostrados na **Janela de Saída** e na **Lista de Erros**.
 
![Erros de build do CMake](media/cmake-build-errors.png "CMake build errors")

Em uma pasta com vários destinos de build, escolha o item **Build** no menu do **CMake** ou o menu de contexto **CMakeLists.txt** para especificar qual destino do CMake compilar. Se você pressionar **Ctrl+Shift+B** em um projeto do CMake, isso compilará o documento ativo atual.

## <a name="debug-the-project"></a>Depurar o projeto

Para depurar um projeto do CMake, escolha a configuração desejada e pressione **F5** ou pressione o botão **Executar** na barra de ferramentas. Se o botão **Executar** indicar "Selecione o Item de Inicialização", selecione a seta suspensa e escolha o destino que deseja executar. (Em um projeto do CMake, a opção "Documento atual" só é válida para arquivos .cpp.) 

![Botão Executar do CMake](media/cmake-run-button.png "Cmake run button")


Os comandos **Executar** ou **F5** primeiro compilam o projeto se as alterações foram feitas desde o build anterior.

## <a name="configure-cmake-debugging-sessions"></a>Configurar sessões de depuração do CMake

Todos os destinos executáveis do CMake são mostrados na lista suspensa **Item de Inicialização** na barra de ferramentas **Geral**. Para iniciar uma sessão de depuração, basta selecionar um e iniciar o depurador.

![Lista suspensa de item de inicialização do CMake](media/cmake-startup-item-dropdown.png "CMake startup item dropdown")


Inicie também uma sessão de depuração por meio dos menus do CMake.

Para personalizar as configurações do depurador para qualquer destino executável do CMake no projeto, clique com o botão direito do mouse no arquivo CMakeLists.txt específico e selecione **Configurações de Depuração e de Inicialização**. Quando você seleciona um destino do CMake no submenu, um arquivo chamado launch.vs.json é criado. Esse arquivo é pré-populado com informações sobre o destino do CMake selecionado e permite que você especifique parâmetros adicionais, como argumentos de programa ou o tipo de depurador. Para referenciar qualquer chave em um arquivo CMakeSettings.json, preceda-o com "cmake." em launch.vs.json. O seguinte exemplo mostra um arquivo launch.vs.json simples que extrai o valor da chave "remoteCopySources" no arquivo CMakeSettings.json da configuração atualmente selecionada:

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

Assim que você salva o arquivo launch.vs.json, uma entrada é criada na lista suspensa **Item de Inicialização** com o novo nome. Editando o arquivo launch.vs.json, crie quantas configurações de depuração desejar para qualquer quantidade de destinos do CMake.

**Visual Studio 2017 versão 15.4**: launch.vs.json dá suporte a variáveis que são declaradas em CMakeSettings.json (veja abaixo) e que são aplicáveis à configuração atualmente selecionada. Também contém uma chave chamada "currentDir", que define o diretório atual do aplicativo a ser iniciado:


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

## <a name="editing-cmakeliststxt-files"></a>Editando arquivos CMakeLists.txt

Para editar um arquivo CMakeLists.txt, clique com o botão direito do mouse no arquivo no **Gerenciador de Soluções** e escolha **Abrir**. Se você faz alterações no arquivo, uma barra de status amarela é exibida e informa você que o IntelliSense será atualizado, oferecendo a oportunidade de cancelar a operação de atualização. Para obter informações sobre CMakeLists.txt, confira a [documentação do CMake](https://cmake.org/documentation/).

   ![Edição do arquivo CMakeLists.txt](media/cmake-cmakelists.png "CMakeLists.txt file editing")


Assim que você salva o arquivo, a etapa de configuração é executada novamente de forma automática e exibe as informações na janela de **Saída**. Os erros e avisos são mostrados na **Lista de Erros** ou na janela de **Saída**. Clique duas vezes em um erro na **Lista de Erros** para navegar para a linha incorreta em CMakeLists.txt.

   ![Erros do arquivo CMakeLists.txt](media/cmake-cmakelists-error.png "CMakeLists.txt file errors")

## <a name="cmake_settings"></a> Configurações do CMake e configurações personalizadas

Por padrão, o Visual Studio fornece seis configurações padrão do CMake ("x86-Debug", "x86-Release", "x64-Debug", "x64-Release", "Linux-Debug" e "Linux-Release"). Essas configurações definem como CMake.exe é invocado para criar o cache do CMake para determinado projeto. Para modificar essas configurações ou criar uma configuração personalizada, escolha **CMake | Alterar Configurações do CMake** e, em seguida, escolha o arquivo CMakeLists.txt ao qual as configurações se aplicam. O comando **Alterar Configurações do CMake** também está disponível no menu de contexto do arquivo no **Gerenciador de Soluções**. Esse comando cria um arquivo CMakeSettings.json na pasta do projeto. Esse arquivo é usado para recriar o arquivo de cache do CMake, por exemplo, após uma operação de **Limpeza**. 

   ![Comando do menu principal do CMake para alterar as configurações](media/cmake-change-settings.png)


O JSON IntelliSense ajuda você a editar o arquivo CMakeSettings.json:

   ![CMake JSON IntelliSense](media/cmake-json-intellisense.png "CMake JSON IntelliSense")

O seguinte exemplo mostra uma configuração de exemplo, que você pode usar como ponto de partida para criar sua própria em CMakeSettings.json:

```json
    {
      "name": "x86-Debug",
      "generator": "Ninja",
      "configurationType": "Debug",
      "inheritEnvironments": [ "msvc_x86" ],
      "buildRoot": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}\\build\\${name}",
      "installRoot": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}\\install\\${name}",
      "cmakeCommandArgs": "",
      "buildCommandArgs": "-v",
      "ctestCommandArgs": ""
    },

```

1. **name**: o nome exibido na lista suspensa de configuração do C++. Esse valor de propriedade também pode ser usado como uma macro, `${name}`, para especificar outros valores de propriedade. Para obter um exemplo, confira a definição **buildRoot** em CMakeSettings.json.
1. **generator**: é mapeado para a opção **-G** e especifica o gerador a ser usado. Essa propriedade também pode ser usada como uma macro, `${generator}`, para ajudar a especificar outros valores de propriedade. No momento, o Visual Studio dá suporte aos seguintes geradores do CMake:


    - "Ninja"
    - "Visual Studio 14 2015"
    - "Visual Studio 14 2015 ARM"
    - "Visual Studio 14 2015 Win64"
    - "Visual Studio 15 2017"
    - "Visual Studio 15 2017 ARM"
    - "Visual Studio 15 2017 Win64"

Como o Ninja for projetado para velocidades rápidas de builds em vez de flexibilidade e função, ele está definido como padrão. No entanto, alguns projetos do CMake podem não conseguir executar o build corretamente usando o Ninja. Se isso ocorrer, instrua o CMake a gerar um projeto do Visual Studio em vez disso.

Para especificar um gerador do Visual Studio, abra o CMakeSettings.json no menu principal escolhendo **CMake | Alterar Configurações do CMake**. Exclua "Ninja" e digite "V". Isso ativa o IntelliSense, que permite escolher o gerador desejado.

1. **buildRoot**: é mapeado para a opção **-DCMAKE_BINARY_DIR** e especifica o local em que o cache do CMake será criado. Se a pasta não existir, ela será criada.
1. **variables**: contém um par nome-valor das variáveis do CMake que serão passadas como **-D**_name_**=**_value_ para o CMake. Se as instruções de build do projeto do CMake especificam a adição de variáveis diretamente ao arquivo de cache do CMake, é recomendável que você adicione-as aqui.
1. **cmakeCommandArgs**: especifica as opções adicionais que você deseja passar para CMake.exe.
1. **configurationType**: define o tipo de configuração de build para o gerador selecionado. Os valores compatíveis no momento são "Debug", "MinSizeRel", "Release" e "RelWithDebInfo".

### <a name="environment-variables"></a>Variáveis de ambiente

CMakeSettings.json também dá suporte ao consumo de variáveis de ambiente em uma das propriedades mencionadas acima. A sintaxe a ser usada é `${env.FOO}` para expandir a variável de ambiente %FOO%.
Você também tem acesso às macros internas dentro deste arquivo:

- `${workspaceRoot}` – fornece o caminho completo da pasta de espaço de trabalho
- `${workspaceHash}` – hash do local do espaço de trabalho; útil para criação de um identificador exclusivo para o espaço de trabalho atual (por exemplo, para uso em caminhos de pasta)
- `${projectFile}` – o caminho completo do arquivo CMakeLists.txt raiz
- `${projectDir}` – o caminho completo da pasta do arquivo CMakeLists.txt raiz
- `${thisFile}` – o caminho completo do arquivo CMakeSettings.json
- `${name}` – o nome da configuração
- `${generator}` – o nome do gerador do CMake usado nessa configuração

### <a name="ninja-command-line-arguments"></a>Argumentos da linha de comando do Ninja

Se os destinos não estão especificados, compila o destino 'padrão' (consulte o manual).

```cmd
C:\Program Files (x86)\Microsoft Visual Studio\Preview\Enterprise>ninja -?
ninja: invalid option -- `-?'
usage: ninja [options] [targets...]
```

|Opção|Descrição|
|--------------|------------|
| --version  | imprime a versão do Ninja ("1.7.1")|
|   -C DIR   | altera para DIR antes de qualquer outra ação|
|   -f FILE  | especifica o arquivo de entrada de build (padrão= build.ninja)|
|   -j N     | executa N trabalhos em paralelo (padrão= 14, derivado das CPUs disponíveis)|
|   -k N     | continua até N trabalhos falharem (padrão= 1)|
|   -l N     | não inicia novos trabalhos se a média de carga é maior que N|
|   -n      | simulação (não executa comandos, mas se comporta como se eles tiveram êxito)|
|   -v       | mostra todas as linhas de comando durante o build|
|   -d MODE  | habilita a depuração (usa a lista -d para listar os modos)|
|   -t TOOL  | executa uma subferramenta (usa a lista -t para listar as subferramentas). encerra as opções de nível superior; outros sinalizadores são passados para a ferramenta| 
|   -w FLAG  | ajusta os avisos (usa a lista -w para listar os avisos)|

### <a name="inherited-environments-visual-studio-2017-version-155"></a>Ambientes herdados (Visual Studio 2017 versão 15.5)
CMakeSettings.json agora dá suporte a ambientes herdados. Esse recurso permite que você (1) herde os ambientes padrão e (2) crie variáveis de ambiente personalizadas que são passadas para CMake.exe quando ele é executado.

```json
  "inheritEnvironments": [ "msvc_x64_x64" ]
```

O exemplo acima é o mesmo que executar o **Prompt de Comando do Desenvolvedor para VS 2017** com os argumentos **-arch=amd64 -host_arch=amd64**.

A seguinte tabela mostra os valores padrão e seus equivalentes de linha de comando:

|Nome do contexto|Descrição|
|-----------|-----------------|
|vsdev|O ambiente padrão do Visual Studio|
|msvc_x86|Compilar para x86 usando ferramentas x86|
|msvc_arm| Compilar para ARM usando ferramentas x86|
|msvc_arm64|Compilar para ARM64 usando ferramentas x86|
|msvc_x86_x64|Compilar para AMD64 usando ferramentas x86|
|msvc_x64_x64|Compilar para AMD64 usando ferramentas de 64 bits|
|msvc_arm_x64|Compilar para ARM usando ferramentas de 64 bits|
|msvc_arm64_x64|Compilar para ARM64 usando ferramentas de 64 bits|

### <a name="custom-environment-variables"></a>Variáveis de ambiente personalizadas
Em CMakeSettings.json, defina as variáveis de ambiente personalizadas globalmente ou por configuração na propriedade **environments**. O exemplo a seguir define uma variável global, **BuildDir**, que é herdada nas configurações x86-Debug e x64-Debug. Cada configuração usa a variável para especificar o valor para a propriedade **buildRoot** dessa configuração. Também observe como cada configuração usa a propriedade **inheritEnvironments** para especificar uma variável que só se aplica a essa configuração.

```json
{
  // The "environments" property is an array of key value pairs of the form
  // { "EnvVar1": "Value1", "EnvVar2": "Value2" }
  "environments": [
    {
      "BuildDir": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}\\build",
    }
  ],

  "configurations": [
    {
      "name": "x86-Debug",
      "generator": "Ninja",
      "configurationType": "Debug",
      // Inherit the defaults for using the MSVC x86 compiler.
      "inheritEnvironments": [ "msvc_x86" ],
      "buildRoot": "${env.BuildDir}\\${name}"    },
    {
      "name": "x64-Debug",
      "generator": "Ninja",
      "configurationType": "Debug",
      // Inherit the defaults for using the MSVC x64 compiler.
      "inheritEnvironments": [ "msvc_x64" ],
      "buildRoot": "${env.BuildDir}\\${name}"
    }
  ]
}
```

No próximo exemplo, a configuração x86-Debug define seu próprio valor para a propriedade **BuildDir**, e esse valor substitui o valor definido pela propriedade **BuildDir** global, de modo que **BuildRoot** seja avaliado como `D:\custom-builddir\x86-Debug`.

```json
{
  "environments": [
    {
      "BuildDir": "${env.USERPROFILE}\\CMakeBuilds\\${workspaceHash}",
    }
  ],

  "configurations": [
    {
      "name": "x86-Debug",

      // The syntax for this property is the same as the global one above.
      "environments": [
        {
          // Replace the global property entirely.
          "BuildDir": "D:\\custom-builddir",
        }
      ],

      "generator": "Ninja",
      "configurationType": "Debug",
      "inheritEnvironments": [ "msvc_x86" ],
      // Evaluates to "D:\custom-builddir\x86-Debug"
      "buildRoot": "${env.BuildDir}\\${name}"
    },
    {
      "name": "x64-Debug",

      "generator": "Ninja",
      "configurationType": "Debug",
      "inheritEnvironments": [ "msvc_x64" ], 
      // Since this configuration doesn’t modify BuildDir, it inherits
      // from the one defined globally.
      "buildRoot": "${env.BuildDir}\\${name}"
    }
  ]
}
```

## <a name="cmake-configure-step"></a>Etapa de configuração do CMake

Quando alterações significativas são feitas nos arquivos CMakeSettings.json ou CMakeLists.txt, o Visual Studio executa novamente a etapa de configuração do CMake de forma automática. Se a etapa de configuração é concluída sem erros, as informações coletadas ficam disponíveis nos serviços de linguagem e no C++ IntelliSense e também nas operações de build e de depuração.

Quando vários projetos do CMake usam o mesmo nome de configuração do CMake (por exemplo, x86-Debug), todos eles são configurados e compilados (em sua própria pasta raiz de build) quando essa configuração é selecionada. Depure os destinos de todos os projetos do CMake que participam dessa configuração do CMake.

   ![Item de menu Somente Build do CMake](media/cmake-build-only.png "CMake Build Only menu item")

Para limitar os builds e as sessões de depuração a um subconjunto dos projetos no espaço de trabalho, crie uma configuração com um nome exclusivo no arquivo CMakeSettings.json e aplique-a apenas a esses projetos. Quando essa configuração é selecionada, os comandos de build, de depuração e do IntelliSense são habilitados apenas para esses projetos especificados.

## <a name="troubleshooting-cmake-cache-errors"></a>Solução de problemas de erros do cache do CMake

Caso precise obter mais informações sobre o estado do cache do CMake para diagnosticar um problema, abra o menu principal do **CMake** ou o menu de contexto de **CMakeLists.txt** no **Gerenciador de Soluções** para executar um destes comandos:

- **Exibir Cache** abre o arquivo CMakeCache.txt na pasta raiz de build no editor. (Todas as edições feitas aqui em CMakeCache.txt são apagadas se o cache é limpo. Para fazer alterações que persistem depois que o cache é limpo, confira [Configurações do CMake e configurações personalizadas](#cmake_settings) anteriormente neste artigo.)
- **Abrir Pasta do Cache** abre uma janela do Explorer na pasta raiz de build.  
- **Limpar Cache** exclui a pasta raiz de build, de modo que a próxima etapa de configuração do CMake seja iniciada com um cache limpo.
- **Gerar Cache** força a execução da etapa de geração, mesmo se o Visual Studio considera o ambiente atualizado.
