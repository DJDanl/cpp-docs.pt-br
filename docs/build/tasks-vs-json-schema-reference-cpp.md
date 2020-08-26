---
title: tasks.vs.jsna referência de esquema (C++)
ms.date: 08/20/2019
helpviewer_keywords:
- tasks.vs.json file [C++]
ms.assetid: abd1985e-3717-4338-9e80-869db5435175
ms.openlocfilehash: a2aea1b64d5a6c62604c680bf1a4a26478b7b52a
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88844984"
---
# <a name="tasksvsjson-schema-reference-c"></a>tasks.vs.jsna referência de esquema (C++)

Para informar ao Visual Studio como criar seu código-fonte em um projeto de pasta aberta, adicione um *tasks.vs.jsno* arquivo. Você pode definir qualquer tarefa arbitrária aqui e, em seguida, chamá-la no menu de contexto **Gerenciador de soluções** . Os projetos CMake não usam esse arquivo porque todos os comandos de compilação são especificados em *CMakeLists.txt*. Para sistemas de compilação diferentes de CMake, *tasks.vs.jsem* é onde você pode especificar comandos de compilação e invocar scripts de compilação. Para obter informações gerais sobre como usar *tasks.vs.jsem*, consulte [Personalizar tarefas de compilação e depuração para o desenvolvimento de "pasta aberta"](/visualstudio/ide/customize-build-and-debug-tasks-in-visual-studio).

Uma tarefa tem uma `type` propriedade que pode ter um dos quatro valores: `default` , `launch` , `remote` ou `msbuild` . A maioria das tarefas deve usar `launch` a menos que uma conexão remota seja necessária.

## <a name="default-properties"></a>Propriedades padrão

As propriedades padrão estão disponíveis em todos os tipos de tarefas:

|Propriedade|Type|Descrição|
|-|-|-|
|`taskLabel`|string| (Obrigatório). Especifica o rótulo da tarefa usada na interface do usuário.|
|`appliesTo`|string| (Obrigatório). Especifica em quais arquivos o comando pode ser executado. Há suporte para o uso de curingas, por exemplo: "*", "*. cpp", "/*. txt"|
|`contextType`|string| Valores permitidos: "personalizado", "Compilar", "limpar", "recompilar". Determina onde o menu de contexto a tarefa será exibida. O padrão é "Custom".|
|`output`|string| Especifica uma marca de saída para sua tarefa.|
|`inheritEnvironments`|matriz| Especifica um conjunto de variáveis de ambiente herdadas de várias fontes. Você pode definir variáveis em arquivos como *CMakeSettings.jsno* ou *CppProperties.js* e disponibilizá-los para o contexto da tarefa. **Visual Studio 16,4:**: especificar variáveis de ambiente por tarefa usando a `env.VARIABLE_NAME` sintaxe. Para remover a definição de uma variável, defina-a como "NULL".|
|`passEnvVars`|booleano| Especifica se deve ou não incluir variáveis de ambiente adicionais ao contexto da tarefa. Essas variáveis são diferentes das definidas usando a `envVars` propriedade. O padrão é "true".|

## <a name="launch-properties"></a>Propriedades de inicialização

Quando o tipo de tarefa é `launch` , essas propriedades estão disponíveis:

|Propriedade|Type|Descrição|
|-|-|-|
|`command`|string| Especifica o caminho completo do processo ou do script a ser iniciado.|
|`args`|matriz| Especifica uma lista separada por vírgulas de argumentos passados para o comando.|
|`launchOption`|string| Valores permitidos: "None", "ContinueOnError", "IgnoreError". Especifica como prosseguir com o comando quando houver erros.|
|`workingDirectory`|string| Especifica o diretório no qual o comando será executado. O padrão é o diretório de trabalho atual do projeto.|
|`customLaunchCommand`|string| Especifica uma personalização de escopo global a ser aplicada antes da execução do comando. Útil para definir variáveis de ambiente como% PATH%.|
|`customLaunchCommandArgs`|string| Especifica os argumentos para customLaunchCommand. (Requer `customLaunchCommand` .)|
 `env`| Especifica uma lista de valores-chave de variáveis de ambiente personalizadas. Por exemplo, "myEnv": "myVal"|
|`commands`|matriz| Especifica uma lista de comandos a serem invocados na ordem.|

### <a name="example"></a>Exemplo

As tarefas a seguir invocam *make.exe* quando um makefile é fornecido na pasta e o `Mingw64` ambiente foi definido no *CppProperties.jsem*, conforme mostrado no [CppProperties.jsna referência do esquema](cppproperties-schema-reference.md#user_defined_environments):

```json
 {
  "version": "0.2.1",
  "tasks": [
    {
      "taskLabel": "gcc make",
      "appliesTo": "*.cpp",
      "type": "launch",
      "contextType": "custom",
      "inheritEnvironments": [
        "Mingw64"
      ],
      "command": "make"
    },
    {
      "taskLabel": "gcc clean",
      "appliesTo": "*.cpp",
      "type": "launch",
      "contextType": "custom",
      "inheritEnvironments": [
        "Mingw64"
      ],
      "command": "make",
      "args": ["clean"]
    }
  ]
}
```

Essas tarefas podem ser invocadas no menu de contexto quando você clica com o botão direito do mouse em um arquivo *. cpp* em **Gerenciador de soluções**.

## <a name="remote-properties"></a>Propriedades remotas

As tarefas remotas são habilitadas quando você instala o desenvolvimento do Linux com carga de trabalho do C++ e adiciona uma conexão a um computador remoto usando o Gerenciador de conexões do Visual Studio. Uma tarefa remota executa comandos em um sistema remoto e também pode copiar arquivos nele.

Quando o tipo de tarefa é `remote` , essas propriedades estão disponíveis:

|Propriedade|Type|Descrição|
|-|-|-|
|`remoteMachineName`|string|O nome do computador remoto. Deve corresponder a um nome de computador no **Gerenciador de conexões**.|
|`command`|string|O comando a ser enviado para o computador remoto. Por padrão, os comandos são executados no diretório $HOME no sistema remoto.|
|`remoteWorkingDirectory`|string|O diretório de trabalho atual no computador remoto.|
|`localCopyDirectory`|string|O diretório local a ser copiado para o computador remoto. O padrão é o diretório de trabalho atual.|
|`remoteCopyDirectory`|string|O diretório no computador remoto no qual `localCopyDirectory` é copiado.|
|`remoteCopyMethod`|string| O método a ser usado para copiar. Valores permitidos: "None", "SFTP", "rsync". rsync é recomendado para projetos grandes.|
|`remoteCopySourcesOutputVerbosity`|string| Valores permitidos: "normal", "detalhado", "diagnóstico".|
|`rsyncCommandArgs`|string|O padrão é "-t--delete".|
|`remoteCopyExclusionList`|matriz|Lista separada por vírgulas de arquivos no `localCopyDirectory` para excluir das operações de cópia.|

### <a name="example"></a>Exemplo

A tarefa a seguir será exibida no menu de contexto quando você clicar com o botão direito do mouse em *Main. cpp* em **Gerenciador de soluções**. Depende de um computador remoto chamado `ubuntu` no **Gerenciador de conexões**. A tarefa copia a pasta aberta atual no Visual Studio para o `sample` diretório no computador remoto e, em seguida, invoca g + + para compilar o programa.

```json
{
  "version": "0.2.1",
  "tasks": [
    {
      "taskLabel": "Build",
      "appliesTo": "main.cpp",
      "type": "remote",
      "contextType": "build",
      "command": "g++ main.cpp",
      "remoteMachineName": "ubuntu",
      "remoteCopyDirectory": "~/sample",
      "remoteCopyMethod": "sftp",
      "remoteWorkingDirectory": "~/sample/hello",
      "remoteCopySourcesOutputVerbosity": "Verbose"
    }
  ]
}
```

## <a name="msbuild-properties"></a>propriedades MSBuild

Quando o tipo de tarefa é `msbuild` , essas propriedades estão disponíveis:

|Propriedade|Type|Descrição|
|-|-|-|
|`verbosity`|string| Especifica os valores de verbosityAllowed de saída de compilação do projeto do MSBuild: "Quiet", "mínimo", "normal", "detalhado", "diagnóstico".|
|`toolsVersion`|string| Especifica a versão do conjunto de ferramentas para compilar o projeto, por exemplo "2,0", "3,5", "4,0", "atual". O padrão é "atual".|
|`globalProperties`|objeto|Especifica uma lista de valores-chave das propriedades globais a serem passadas para o projeto, por exemplo, "configuração": "versão"|
|`properties`|objeto| Especifica uma lista de valores-chave de propriedades adicionais do projeto.|
|`targets`|matriz| Especifica a lista de destinos a serem invocados, em ordem, no projeto. O destino padrão do projeto será usado se nenhum for especificado.|
