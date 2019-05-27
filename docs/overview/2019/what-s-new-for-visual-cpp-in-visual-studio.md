---
title: Novidades do C++ no Visual Studio 2019
ms.date: 05/13/2019
ms.technology: cpp-ide
ms.assetid: 8801dbdb-ca0b-491f-9e33-01618bff5ae9
author: mikeblome
ms.author: mblome
ms.openlocfilehash: 19eaa9d4ed1cf12e721825f998fa674363eda488
ms.sourcegitcommit: 61121faf879cc581a4d39e4baccabf7cf1f673a5
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/20/2019
ms.locfileid: "65934131"
---
# <a name="whats-new-for-c-in-visual-studio-2019"></a>Novidades do C++ no Visual Studio 2019

O Visual Studio 2019 traz muitas atualizações e correções para o ambiente do Microsoft C++. Corrigimos muitos bugs e problemas no compilador e nas ferramentas, muitos deles enviados pelos clientes pelas opções [Relatar um Problema](/visualstudio/how-to-report-a-problem-with-visual-studio-2017) e [Fornecer uma Sugestão](https://developercommunity.visualstudio.com/spaces/62/index.html) em **Enviar Comentários**. Obrigado por relatar bugs! Para obter mais informações sobre todas as novidades do Visual Studio, visite [Novidades no Visual Studio](/visualstudio/ide/whats-new-visual-studio-2019).

## <a name="c-compiler"></a>compilador C++

- Suporte aprimorado para recursos e correções exatas do C++17, além de suporte experimental para recursos de C++20, como módulos e corrotinas. Para obter informações detalhadas, consulte [Aprimoramentos de conformidade do C++ no Visual Studio 2019](../cpp-conformance-improvements.md).

- A opção `/std:c++latest` agora inclui recursos do C++20 que não são necessariamente completos, incluindo o suporte inicial para o operador do C++20 \<=> ("espaçonave") para comparação de três vias.

- A opção de compilador C++ `/Gm` foi preterida. Considere desabilitar a opção `/Gm` em seus scripts de build se ela estiver definida explicitamente. No entanto, você pode ignorar com segurança o aviso de substituição para `/Gm`, pois ela não é tratada como erro ao usar "Tratar avisos como erros" (`/WX`).

- Como o MSVC começa a implementação dos recursos do rascunho padrão do C++20 sob o sinalizador `/std:c++latest`, `/std:c++latest` agora é compatível com `/clr` (todas as versões), `/ZW` e `/Gm`. No Visual Studio 2019, use os modos `/std:c++17` ou `/std:c++14` ao compilar com `/clr`, `/ZW` ou `/Gm` (mas consulte marcador anterior).

- Cabeçalhos pré-compilados não são mais gerados por padrão para aplicativos para desktop e de console do C++.

### <a name="codegen-security-diagnostics-and-versioning"></a>Geração de código, segurança, diagnóstico e controle de versão

Análise aprimorada com `/Qspectre` para fornecer assistência de mitigação para Variante de Espectro 1 (CVE-2017-5753). Para obter mais informações, consulte [Mitigações do Spectre no MSVC](https://devblogs.microsoft.com/cppblog/spectre-mitigations-in-msvc/).

## <a name="c-standard-library-improvements"></a>Melhorias da Biblioteca Padrão do C++

- Implementação de correções exatas e recursos de biblioteca adicionais do C++17 e do C++20. Para obter informações detalhadas, consulte [Aprimoramentos de conformidade do C++ no Visual Studio 2019](../cpp-conformance-improvements.md).

- Clang-Format aplicado aos cabeçalhos da Biblioteca Padrão de C++ para mais facilidade de leitura.

- Como o Visual Studio agora dá suporte a Apenas Meu Código para C++, a Biblioteca Padrão não precisa mais fornecer maquinário personalizado para que `std::function` e `std::visit` cheguem ao mesmo efeito. Remover amplamente esse maquinário não tem efeitos visíveis ao usuário, exceto que o compilador não produz mais diagnóstico que indique problemas na linha 15732480 ou 16707566 de \<type_traits> ou \<variant>.

## <a name="performancethroughput-improvements-in-the-compiler-and-standard-library"></a>Melhorias de desempenho/taxa de transferência no compilador e na Biblioteca Padrão

- Melhorias de produtividade de build, incluindo a forma como o vinculador manipula a E/S de Arquivo e o tempo de vinculação na criação e mesclagem de tipo PDB.

- Adicionamos suporte básico para vetorização de SIMD OpenMP. Você pode habilitá-lo usando a nova opção de compilador `-openmp:experimental`. Esta opção permite que loops anotados com `#pragma omp simd` sejam potencialmente vetorizados. A vetorização não é garantida. Um aviso será relatado para loops anotados, mas não vetorizados. Não há suporte para cláusulas SIMD, elas são simplesmente ignoradas com um aviso relatado.

- Foi adicionada uma nova opção de linha de comando de inlining `-Ob3`, que é uma versão mais agressiva de `-Ob2`. `-O2` (otimizar o binário para maior velocidade) ainda implica `-Ob2` por padrão. Se você achar que o compilador não executa o inlining agressivamente o suficiente, considere passar `-O2 -Ob3`.

- Para dar suporte à vetorização manual de loops com chamadas para funções de biblioteca de matemática e outras operações, como divisão de inteiros, adicionamos suporte a funções intrínsecas de SVML (biblioteca de matemática de vetor curto). Essas funções calculam os equivalentes do vetor de 128 bits, 256 bits ou 512 bits. Consulte o [Guia intrínseco Intel](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#!=undefined&techs=SVML) para obter definições das funções compatíveis.

- Novas e aprimoradas otimizações:

  - Avaliação de constantes e simplificações aritméticas para expressões usando intrínsecos de vetor de SIMD, tanto para formulários float quanto integer.

  - Uma análise mais eficiente para extrair informações do fluxo de controle (instruções if/else/switch) para remover branches que comprovadamente sempre resultam em true ou false.

  - Desenrolamento aprimorado de memset para usar as instruções do vetor SSE2.

  - Remoção aprimorada de cópias de classe/struct inúteis, especialmente para programas do C++ que passam por valor.

  - Aprimorada a otimização de códigos que usam `memmove`, como as construções `std::copy` ou `std::vector` e `std::string`.

- Otimização do design físico da Biblioteca Padrão para evitar a compilação de partes da biblioteca sem #include, diminuindo pela metade o tempo de compilação de um arquivo vazio que inclui apenas \<vector>. Como resultado dessa alteração, talvez você precise adicionar diretivas #include para os cabeçalhos que foram incluídos anteriormente de maneira indireta. Por exemplo, o código que usa `std::out_of_range` agora pode precisar #include \<stdexcept>. O código que usa um operador de inserção de fluxo agora pode precisar #include \<ostream>. A vantagem é que apenas as unidades de tradução que realmente usam os componentes \<stdexcept> ou \<ostream> pagam o custo da taxa de transferência para compilá-los.

- `if constexpr` foi aplicado em mais lugares na Biblioteca Padrão para aumento da taxa de transferência e redução do tamanho do código em operações de cópia, em permutações como reverter e girar, e na biblioteca de algoritmos paralelos. 

- A Biblioteca Padrão agora usa `if constexpr` internamente para reduzir os tempos de compilação, mesmo no modo C++14.

- A detecção de vinculação dinâmica do tempo de execução para a biblioteca de algoritmos paralelos não usa mais uma página inteira para armazenar a matriz do ponteiro de função. Marcar essa memória como somente leitura deixou de ser considerado relevante para fins de segurança.

- O construtor de `std::thread` não aguarda mais que o thread seja iniciado, e não insere mais tantas camadas de chamadas de função entre a biblioteca C subjacente `_beginthreadex` e o objeto fornecido que pode ser chamado. Anteriormente, `std::thread` colocava seis funções entre `_beginthreadex` e o objeto fornecido que pode ser chamado, o que foi reduzido a apenas três (dois dos quais são apenas `std::invoke`). Isso também resolve um bug obscuro de medição de tempo em que o construtor de `std::thread` podia ser interrompido se o relógio do sistema fosse alterado no exato momento que um `std::thread` estivesse sendo criado.

- Correção de uma regressão de desempenho em `std::hash` que introduzimos ao implementar `std::hash<std::filesystem::path>`.

- Em vários locais, agora a Biblioteca Padrão usa destruidores em vez de blocos catch para chegar à exatidão. Isso resulta na melhor interação do depurador; exceções que você lança por meio da Biblioteca Padrão nos locais afetados agora serão mostradas como sendo lançadas de seu site original de lançamento, e não como nosso relançamento. Nem todos os blocos catch da Biblioteca Padrão foram eliminados; esperamos que o número de blocos catch seja reduzido em versões futuras do MSVC.

- O gerador de código abaixo do ideal em `std::bitset` causado por um lançamento condicional em uma função noexcept foi corrigido pela fatoração do caminho de lançamento.

- A família `std::list` e `std::unordered_*` usa iteradores de não depuração internamente em mais locais.

- Vários membros `std::list` foram alterados para reutilizar os nós da lista onde possível, em vez de desalocá-los e realocá-los. Por exemplo, dada uma `list<int>` que já tem um tamanho igual a 3, uma chamada para `assign(4, 1729)` agora substituirá o ints nos 3 primeiros nós da lista, bem como alocará um novo nó de lista com o valor 1729, em vez de desalocar os 3 nós de lista e, em seguida, alocar 4 novos nós de listas com o valor 1729.

- Todas as chamadas da Biblioteca Padrão para `erase(begin(), end())` foram alteradas para `clear()`.

- Agora, `std::vector` inicializa e apaga os elementos com mais eficiência em determinados casos.

- Melhorias em `std::variant` para torná-lo mais adequado para otimizadores, resultando na geração de códigos melhores. O inlining de código agora está agora muito melhor com `std::visit`.

## <a name="c-ide"></a>C++ IDE

### <a name="live-share-c-support"></a>Suporte de Live Share para C++

Agora, o [Live Share](/visualstudio/liveshare/) dá suporte a C++, permitindo que desenvolvedores usem o Visual Studio ou o Visual Studio Code para colaborar em tempo real. Para obter mais informações, consulte [Apresentação do Live Share para C++: colaboração e compartilhamento em tempo real](https://devblogs.microsoft.com/cppblog/cppliveshare/)

### <a name="intellicode-for-c"></a>IntelliCode paraC++

O IntelliCode é uma extensão opcional (adicionada como um componente de carga de trabalho na versão 16.1) que usa seu próprio treinamento abrangente e seu contexto de código para colocar o que você mais provavelmente usará na parte superior da lista de conclusão. Frequentemente, ele é capaz de eliminar a necessidade de rolar para baixo na lista. Para C++, o IntelliCode oferece a maior ajuda quando você está usando bibliotecas populares como a Biblioteca Padrão. Para obter mais informações, consulte [Sugestões de preenchimento de código auxiliadas por IA para C++ usando IntelliCode](https://devblogs.microsoft.com/cppblog/cppintellicode/).

### <a name="template-intellisense"></a>IntelliSense de modelo

A **Barra de Modelo** agora utiliza a interface do usuário de **Janela de Inspeção** em vez de uma janela modal, dá suporte a modelos aninhados e pré-popula eventuais argumentos padrão na **Janela de Inspeção**. Para obter mais informações, veja [Melhorias de IntelliSense de modelo para Visual Studio 2019 versão prévia 2](https://devblogs.microsoft.com/cppblog/template-intellisense-improvements-for-visual-studio-2019-preview-2/). Uma lista suspensa **Usados recentemente** na **Barra de Modelo** permite alternar rapidamente entre conjuntos anteriores de argumentos de exemplo.

### <a name="new-start-window-experience"></a>Nova experiência de janela iniciar

Ao iniciar o IDE, uma nova janela de Iniciar é exibida, com opções para abrir projetos recentes, clonar código do controle do código-fonte, abrir código local como uma solução ou pasta ou criar um novo projeto. A caixa de diálogo Novo Projeto também foi aprimorada para uma experiência de pesquisa que pode ser filtrada.

### <a name="new-names-for-some-project-templates"></a>Novos nomes para alguns modelos de projeto

Modificamos vários nomes e descrições de modelo de projeto de acordo com a caixa de diálogo Novo Projeto atualizada.

### <a name="various-productivity-improvements"></a>Diversos aprimoramentos de produtividade

O Visual Studio 2019 inclui os seguintes recursos que o ajudarão a tornar a codificação mais fácil e intuitiva:

- Correções rápidas para:
  - Adicionar #include ausentes
  - NULL para nullptr
  - Adicionar ponto e vírgula ausente
  - Resolver namespace ou escopo ausente
  - Substituir operandos de indireção inválidos (\* para & e & para \*)
- Informações rápidas para um bloco passando o mouse sobre a chave de fechamento
- Espiar Cabeçalho / Arquivo de Código
- Ir para Definição em #include abre o arquivo

Para obter mais informações, veja [Aprimoramentos de produtividade do C++ no Visual Studio 2019 Versão Prévia 2](https://devblogs.microsoft.com/cppblog/c-productivity-improvements-in-visual-studio-2019-preview-2/).

**Visual Studio 2019 versão 16.1**

### <a name="quickinfo-improvements"></a>Melhorias de Informações Rápidas

A dica de ferramenta Informações Rápidas agora respeita a colorização semântica do seu editor. Ela também apresenta um novo link para **Pesquisa Online**, que pesquisará documentos online que traga mais informações sobre o constructo de código focalizado. Para código sublinhado em vermelho, o link fornecido por Informações Rápidas procurará o erro online. Dessa forma, você não precisa redigitar a mensagem no navegador. Para saber mais, confira [Melhorias de Informações Rápidas no Visual Studio 2019: colorização e pesquisa online](https://devblogs.microsoft.com/cppblog/quick-info-improvements-in-visual-studio-2019-colorization-and-search-online/).

### <a name="intellicode-available-in-c-workload"></a>IntelliCode disponível na carga de trabalho do C++

O IntelliCode agora é fornecido como um componente opcional na carga de trabalho **Desenvolvimento para desktop com C++** . Para saber mais, confira [IntelliCode aprimorado para C++ agora vem com o Visual Studio 2019](https://devblogs.microsoft.com/cppblog/).

## <a name="cmake-support"></a>Suporte para CMake

- Suporte para CMake 3.14

- O Visual Studio agora pode abrir caches do CMake existentes gerados por ferramentas externas, como o CMakeGUI, ou por sistemas de metabuild personalizados ou scripts de build que invocam cmake.exe eles mesmos.

- Desempenho aprimorado de IntelliSense.

- Um novo editor de configurações fornece uma alternativa para editar o arquivo CMakeSettings.json manualmente e oferece alguma paridade com CMakeGUI.

- O Visual Studio ajuda a impulsionar o desenvolvimento de C++ com o CMake no Linux, detectando se você tem uma versão compatível do CMake em seu computador Linux e, quando você não tem, se oferece para instalá-la.

- As incompatibilidades de configuração no CMakeSettings, como arquiteturas incompatíveis ou configurações incompatíveis do gerador de CMake, mostram linhas irregulares no editor JSON e erros na Lista de Erros.

- A cadeia de ferramentas do vcpkg é detectada automaticamente e habilitada para projetos do CMake que são abertos no IDE após `vcpkg integrate install` ser executado. Esse comportamento pode ser desativado especificando-se um arquivo de cadeia de ferramentas vazio no CMakeSettings.

- Projetos do CMake agora permitem depuração Apenas Meu Código por padrão.

- Avisos de análise estática agora podem ser processados em segundo plano e exibidos no editor para projetos do CMake.

- Mensagens 'begin' e 'end' mais claras de build e de configuração para projetos do CMake e suporte à interface do usuário de progresso do build do Visual Studio. Além disso, agora há uma configuração de detalhes de CMake em **Ferramentas > Opções** para personalizar o nível de detalhe das mensagens de build e configuração do CMake na Janela de Saída.

- A configuração `cmakeToolchain` agora é compatível com o CMakeSettings.json para especificar cadeias de ferramentas sem modificar manualmente a linha de comando do CMake.

- Um novo atalho de menu **Compilar Tudo** **Ctrl + Shift + B**.

**Visual Studio 2019 versão 16.1**

- Suporte integrado para edição, compilação e depuração de projetos CMake com Clang/LLVM. Para saber mais, veja [Suporte a Clang/LLVM no Visual Studio](https://devblogs.microsoft.com/cppblog/clang-llvm-support-in-visual-studio/).

## <a name="linux-and-wsl"></a>Linux e WSL

**Visual Studio 2019 versão 16.1**

- Suporte para [AddressSanitizer (ASan)](https://github.com/google/sanitizers/wiki/AddressSanitizer) em projetos de plataforma cruzada do Linux e CMake. Para saber mais, confira [AddressSanitizer (ASan) para carga de trabalho do Linux no Visual Studio 2019](https://devblogs.microsoft.com/cppblog/addresssanitizer-asan-for-the-linux-workload-in-visual-studio-2019/).

- Suporte integrado do Visual Studio para uso de C++ com o subsistema Windows para Linux (WSL). Para saber mais, confira [C++ com Visual Studio 2019 e subsistema Windows para Linux (WSL)](https://devblogs.microsoft.com/cppblog/c-with-visual-studio-2019-and-windows-subsystem-for-linux-wsl/).

## <a name="incredibuild-integration"></a>Integração de IncrediBuild

O IncrediBuild foi incluído como um componente opcional na carga de trabalho **Desenvolvimento para desktop com C++** . O Monitor de Compilação do IncrediBuild foi totalmente integrado no IDE do Visual Studio. Para saber mais, confira [Visualizar a compilação com o Monitor de Compilação do IncrediBuild e o Visual Studio 2019](https://devblogs.microsoft.com/cppblog/visualize-your-build-with-incredibuilds-build-monitor-and-visual-studio-2019/).
 
## <a name="debugging"></a>Depuração

- Para aplicativos C++ em execução no Windows, os arquivos PDBs agora são carregados em um processo separado de 64 bits. Essa mudança trata de um intervalo de falhas causadas por memória insuficiente no depurador durante a depuração de aplicativos que contêm um grande número de módulos e arquivos PDBs.

- A pesquisa está habilitada nas janelas **Inspeção**, **Autos** e **Locais**.

## <a name="windows-desktop-development-with-c"></a>Desenvolvimento da Área de Trabalho do Windows com C++

- Estes assistentes do C++ ATL/MFC não estão mais disponíveis:

  - Assistente de componente de COM+ 1.0 da ATL
  - Assistente do componente Active Server Page da ATL
  - Assistente de provedor OLE DB da ATL
  - Assistente de página de propriedades da ATL
  - Assistente de consumidor OLE DB da ATL
  - Consumidor ODBC do MFC
  - Classe MFC em Controle ActiveX
  - Classe MFC em TypeLib.

  O código de exemplo para essas tecnologias está arquivado em Microsoft Docs e no repositório GitHub VCSamples.

- O SDK do Windows 8.1 não está mais disponível no instalador do Visual Studio. Recomendamos atualizar seus projetos em C++ para o SDK do Windows 10 mais recente. Se você tiver uma dependência forte no 8.1, poderá baixá-la do arquivo do SDK do Windows.

- O direcionamento do Windows XP não estará mais disponível para o conjunto de ferramentas do C++ mais recente. O direcionamento do XP com bibliotecas e o compilador MSVC no nível do VS 2017 ainda é compatível e pode ser instalado por meio de "Componentes individuais".

- Nossa documentação desencoraja ativamente o uso de módulos de mesclagem para a implantação do Tempo de Execução do Visual C++. Estamos realizando, nesta versão, a etapa extra de marcar nossos MSMs como preteridos. Considere migrar sua implantação central do VCRuntime de MSMs para o pacote redistribuível.

## <a name="mobile-development-with-c-android-and-ios"></a>Desenvolvimento móvel com C++ (Android e iOS)

A experiência do Android C++ agora usa por padrão o SDK do Android 25 e o NDK do Android 16b.

## <a name="clangc2-platform-toolset"></a>Conjunto de ferramentas de plataforma Clang/C2

O componente experimental Clang/C2 foi removido. Use o conjunto de ferramentas do MSVC para conformidade total de padrões C++ com `/permissive-` e `/std:c++17` ou a cadeia de ferramentas Clang/LLVM para Windows.

## <a name="code-analysis"></a>Análise de código

- A análise de código agora é executada automaticamente em segundo plano. Avisos são exibidos como linhas irregulares verdes no editor conforme você digita. Para obter mais informações, consulte [Análise de código no editor no Visual Studio 2019 Versão Prévia 2](https://devblogs.microsoft.com/cppblog/in-editor-code-analysis-in-visual-studio-2019-preview-2/).

- Novas regras de ConcurrencyCheck experimentais para tipos conhecidos de Biblioteca Padrão do cabeçalho \<mutex>. Para obter mais informações, consulte [Análise de código de simultaneidade no Visual Studio 2019](https://devblogs.microsoft.com/cppblog/concurrency-code-analysis-in-visual-studio-2019/).

- Uma implementação parcial atualizada do [Verificador de perfil de tempo de vida](https://herbsutter.com/2018/09/20/lifetime-profile-v1-0-posted/), que detecta referências e ponteiros pendentes. Para obter mais informações, consulte [Atualização de perfil de tempo de vida no Visual Studio 2019 Versão Prévia 2](https://devblogs.microsoft.com/cppblog/lifetime-profile-update-in-visual-studio-2019-preview-2/).

- Mais verificações relacionadas à corrotina, incluindo C26138, C26810, C26811 e a regra experimental C26800. Para obter mais informações, consulte [Novas verificações de análise de código no Visual Studio 2019: uso após movimentação e corrotina](https://devblogs.microsoft.com/cppblog/new-code-analysis-checks-in-visual-studio-2019-use-after-move-and-coroutine/).

**Visual Studio 2019 versão 16.1**

Novas correções rápidas para verificações de variável não inicializadas. Para saber mais, confira [Novas correções rápidas de análise de código para memória não inicializada (C6001) e avisos de uso antes da inicialização (C26494)](https://devblogs.microsoft.com/cppblog/new-code-analysis-quick-fixes-for-uninitialized-memory-c6001-and-use-before-init-c26494-warnings/).

## <a name="unit-testing"></a>Teste de unidade

O modelo de projeto de teste do C++ gerenciado não está mais disponível. Você pode continuar usando a estrutura de teste do C++ gerenciado em seus projetos existentes. Para novos testes de unidade, considere usar uma das estruturas de teste nativas para as quais o Visual Studio fornece modelos (MSTest, Google Test) ou o modelo de projeto de teste de C# gerenciado.
