---
title: Configurar projetos do Linux para usar o Address Sanitizer
description: Descreve como configurar projetos do C++ Linux no Visual Studio para usar o Address Sanitizer.
ms.date: 06/07/2019
ms.openlocfilehash: 2415e8971614de35f046b699ce99c3822faf9372
ms.sourcegitcommit: 8adabe177d557c74566c13145196c11cef5d10d4
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/10/2019
ms.locfileid: "66824170"
---
# <a name="configure-linux-projects-to-use-address-sanitizer"></a>Configurar projetos do Linux para usar o Address Sanitizer

No Visual Studio 2019 versão 16.1, o suporte ao ASan (AddressSanitizer) é integrado aos projetos do Linux. Você pode habilitar o ASan para projetos do Linux baseados no MSBuild e projetos do CMake. Ele funciona em sistemas Linux remotos e no WSL (Subsistema do Windows para Linux).

## <a name="about-asan"></a>Sobre o ASan

O ASan é um detector de erros de memória de tempo de execução para o C/C++ que captura os seguintes erros:

- Usar após liberar (referência de ponteiro pendente)
- Estouro de buffer do heap
- Estouro de buffer da pilha
- Usar após retornar
- Usar após definir o escopo
- Bugs de ordem de inicialização

Quando o ASan detecta um erro, ele interrompe a execução imediatamente. Se você executar um programa habilitado pelo ASan no depurador, verá uma mensagem que descreve o tipo de erro, o endereço de memória e a localização no arquivo de origem em que ocorreu o erro:

   ![Mensagem de erro do ASan](media/asan-error.png)

Também é possível ver a saída completa do ASan (incluindo a localização em que a memória corrompida foi alocada/desalocada) no painel Depurar da Janela de Saída.

## <a name="enable-asan-for-msbuild-based-linux-projects"></a>Habilitar o ASan em projetos do Linux baseados no MSBuild

Para habilitar o ASan em projetos do Linux baseados no MSBuild, clique com o botão direito do mouse no projeto no **Gerenciador de Soluções** e selecione **Propriedades**. Em seguida, navegue até **Propriedades de Configuração** > **C/C++**  > **Sanitizers**. O ASan é habilitado por meio de sinalizadores do compilador e do vinculador e, para funcionar, exige a recompilação do projeto.

![Habilitar o ASan em um projeto do MSBuild](media/msbuild-asan-prop-page.png)

Passe sinalizadores opcionais de tempo de execução do ASan navegando até **Propriedades de Configuração** > **Depuração** > **Sinalizadores de Tempo de Execução do AddressSanitizer**. Clique na seta para baixo para adicionar ou remover sinalizadores.

![Configurar sinalizadores de tempo de execução do ASan](media/msbuild-asan-runtime-flags.png)

## <a name="enable-asan-for-visual-studio-cmake-projects"></a>Habilitar o ASan em projetos do CMake no Visual Studio

Para habilitar o ASan no CMake, clique com o botão direito do mouse no arquivo CMakeLists.txt no **Gerenciador de Soluções** e escolha **Configurações do CMake para o Projeto**.

Verifique se você tem uma configuração do Linux (por exemplo, **Linux-Debug**) selecionada no painel esquerdo da caixa de diálogo:

![A configuração de depuração do Linux](media/linux-debug-configuration.png)

As opções do ASan estão na guia **Geral**. Insira os sinalizadores de tempo de execução do ASan no formato "sinalizador=valor", separados por ponto-e-vírgula.

![A configuração de depuração do Linux](media/cmake-settings-asan-options.png)

## <a name="install-the-asan-debug-symbols"></a>Instalar os símbolos de depuração do ASan

Para habilitar o diagnóstico do ASan, é necessário instalar seus símbolos de depuração (libasan-dbg) no computador Linux remoto ou na instalação do WSL. A versão do libasan-dbg carregada depende da versão do GCC instalada no computador Linux:

|**Versão do ASan**|**Versão do GCC**|
| --- | --- |
|libasan0|gcc-4.8|
|libasan2|gcc-5|
|libasan3|gcc-6|
|libasan4|gcc-7|
|libasan5|gcc-8|

Você pode determinar qual versão do GCC você tem usando este comando:

```bash
gcc --version
```

Para exibir a versão do libasan-dbg necessária, execute o programa e, em seguida, examine o painel **Depurar** da Janela de **Saída**. A versão do ASan carregada corresponde à versão do libasan-dbg necessária no computador Linux. Use **Ctrl+F** para pesquisar "libasan" na janela. Se você tiver o libasan4, por exemplo, você verá uma linha como esta:

```Output
Loaded '/usr/lib/x86_64-linux-gnu/libasan.so.4'. Symbols loaded.
```

Instale os bits de depuração do ASan nas distribuições do Linux que usam apt com o comando a seguir. Este comando instala a versão 4:

```bash
sudo apt-get install libasan4-dbg
```

Se o ASan estiver habilitado, o Visual Studio solicitará que, na parte superior do painel **Depurar** da Janela de **Saída**, você instale os símbolos de depuração do ASan.
