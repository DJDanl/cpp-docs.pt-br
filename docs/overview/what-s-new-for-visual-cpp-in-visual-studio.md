---
title: Novidades do C++ no Visual Studio
ms.date: 07/02/2019
ms.technology: cpp-ide
ms.assetid: 8801dbdb-ca0b-491f-9e33-01618bff5ae9
author: mikeblome
ms.author: mblome
ms.openlocfilehash: bde8b8e17c3186d22493f099a5f7d1b5a2646a67
ms.sourcegitcommit: 2362d15b5eb18d27773c3f7522da3d0eed9e2571
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/07/2019
ms.locfileid: "73754141"
---
# <a name="whats-new-for-c-in-visual-studio"></a>Novidades do C++ no Visual Studio

::: moniker range=">=vs-2019"

O Visual Studio 2019 traz muitas atualizações e correções para o ambiente do Microsoft C++. Corrigimos vários bugs e problemas no compilador e nas ferramentas. Muitos deles enviados pelos clientes pelas opções [Relatar um Problema](/visualstudio/ide/how-to-report-a-problem-with-visual-studio?view=vs-2019) e [Fornecer uma Sugestão](https://developercommunity.visualstudio.com/spaces/62/index.html) em **Enviar Comentários**. Obrigado por relatar bugs! Para saber mais sobre todas as novidades do Visual Studio, visite [Novidades no Visual Studio 2019](/visualstudio/ide/whats-new-visual-studio-2019). Para saber mais sobre novidades de C++ no Visual Studio 2017, confira [Novidades de C++ no Visual Studio 2017](/cpp/overview/what-s-new-for-visual-cpp-in-visual-studio?view=vs-2017). Para saber mais sobre as novidades de C++ no Visual Studio 2015 e em versões anteriores, confira [O que há de novo no Visual C++ de 2003 a 2015](/cpp/porting/visual-cpp-what-s-new-2003-through-2015).

## <a name="c-compiler"></a>compilador C++

- Suporte aprimorado para recursos e correções exatas do C++17, além de suporte experimental para recursos de C++20, como módulos e corrotinas. Para obter informações detalhadas, consulte [Aprimoramentos de conformidade do C++ no Visual Studio 2019](cpp-conformance-improvements.md).

- A opção `/std:c++latest` agora inclui recursos do C++20 que não são necessariamente completos, incluindo o suporte inicial para o operador do C++20 \<=> ("espaçonave") para comparação de três vias.

- A opção de compilador C++ `/Gm` foi preterida. Considere desabilitar a opção `/Gm` em seus scripts de build se ela estiver definida explicitamente. No entanto, você pode ignorar com segurança o aviso de substituição para `/Gm`, pois ela não é tratada como erro ao usar "Tratar avisos como erros" (`/WX`).

- Como o MSVC começa a implementação dos recursos do rascunho padrão do C++20 sob o sinalizador `/std:c++latest`, `/std:c++latest` agora é compatível com `/clr` (todas as versões), `/ZW` e `/Gm`. No Visual Studio 2019, use os modos `/std:c++17` ou `/std:c++14` ao compilar com `/clr`, `/ZW` ou `/Gm` (mas consulte marcador anterior).

- Cabeçalhos pré-compilados não são mais gerados por padrão para aplicativos para desktop e de console do C++.

### <a name="codegen-security-diagnostics-and-versioning"></a>Geração de código, segurança, diagnóstico e controle de versão

Análise aprimorada com `/Qspectre` para fornecer assistência de mitigação para Variante de Espectro 1 (CVE-2017-5753). Para obter mais informações, consulte [Mitigações do Spectre no MSVC](https://devblogs.microsoft.com/cppblog/spectre-mitigations-in-msvc/).

## <a name="c-standard-library-improvements"></a>Melhorias da biblioteca padrão do C++

- Implementação de correções exatas e recursos de biblioteca adicionais do C++17 e do C++20. Para obter informações detalhadas, consulte [Aprimoramentos de conformidade do C++ no Visual Studio 2019](cpp-conformance-improvements.md).

- Clang-Format aplicado aos cabeçalhos da biblioteca padrão de C++ para mais facilidade de leitura.

- Como o Visual Studio agora dá suporte a Apenas Meu Código para C++, a biblioteca padrão não precisa mais fornecer maquinário personalizado para que `std::function` e `std::visit` cheguem ao mesmo efeito. A remoção desse mecanismo não tem efeitos visíveis pelo usuário. Uma exceção é a de que o compilador não produz mais diagnóstico que indique problemas na linha 15732480 ou 16707566 de \<type_traits> ou \<variant>.

## <a name="performancethroughput-improvements-in-the-compiler-and-standard-library"></a>Melhorias de desempenho/taxa de transferência no compilador e na biblioteca padrão

- Melhorias de produtividade de build, incluindo a forma como o vinculador manipula a E/S de Arquivo e o tempo de vinculação na criação e mesclagem de tipo PDB.

- Adicionamos suporte básico para vetorização de SIMD OpenMP. Você pode habilitá-lo usando a nova opção de compilador `-openmp:experimental`. Esta opção permite que loops anotados com `#pragma omp simd` sejam potencialmente vetorizados. A vetorização não é garantida. Um aviso será relatado para loops anotados, mas não vetorizados. Não há suporte para cláusulas SIMD, elas são ignoradas com um aviso relatado.

- Foi adicionada uma nova opção de linha de comando de inlining `-Ob3`, que é uma versão mais agressiva de `-Ob2`. `-O2` (otimizar o binário para maior velocidade) ainda implica `-Ob2` por padrão. Se você achar que o compilador não executa o inlining agressivamente o suficiente, considere passar `-O2 -Ob3`.

- Para dar suporte à vetorização manual de loops com chamadas para funções de biblioteca de matemática e outras operações, como divisão de inteiros, adicionamos suporte a funções intrínsecas de SVML (biblioteca de matemática de vetor curto). Essas funções calculam os equivalentes do vetor de 128 bits, 256 bits ou 512 bits. Consulte o [Guia intrínseco Intel](https://software.intel.com/sites/landingpage/IntrinsicsGuide/#!=undefined&techs=SVML) para obter definições das funções compatíveis.

- Novas e aprimoradas otimizações:

  - Avaliação de constantes e simplificações aritméticas para expressões usando intrínsecos de vetor de SIMD, tanto para formulários float quanto integer.

  - Uma análise mais eficiente para extrair informações do fluxo de controle (instruções if/else/switch) para remover branches que comprovadamente sempre resultam em true ou false.

  - Desenrolamento aprimorado de memset para usar as instruções do vetor SSE2.

  - Remoção aprimorada de cópias de classe/struct inúteis, especialmente para programas do C++ que passam por valor.

  - Aprimorada a otimização de códigos que usam `memmove`, como as construções `std::copy` ou `std::vector` e `std::string`.

- Otimizado o design físico de biblioteca padrão para evitar a compilação de partes da biblioteca padrão não incluídas diretamente. Essa alteração reduz o tempo de criação de um arquivo em branco que inclui apenas \<vector> in half. Como consequência, talvez você precise adicionar diretivas `#include` aos cabeçalhos que foram incluídos anteriormente de maneira indireta. Por exemplo, o código que usa `std::out_of_range` agora pode precisar de `#include <stdexcept>`. O código que usa um operador de inserção de fluxo agora pode precisar de `#include <ostream>`. A vantagem é que apenas as unidades de tradução que realmente usam os componentes \<stdexcept> ou \<ostream> pagam o custo da taxa de transferência para compilá-los.

- `if constexpr` foi aplicado em mais lugares na biblioteca padrão para aumento da taxa de transferência e redução do tamanho do código em operações de cópia, em permutações como reverter e girar, e na biblioteca de algoritmos paralelos.

- A biblioteca padrão agora usa `if constexpr` internamente para reduzir os tempos de compilação, mesmo no modo C++14.

- A detecção de vinculação dinâmica do runtime para a biblioteca de algoritmos paralelos não usa mais uma página inteira para armazenar a matriz do ponteiro de função. Marcar essa memória como somente leitura deixou de ser considerado relevante para fins de segurança.

- O construtor de `std::thread` não aguarda mais que o thread seja iniciado, e não insere mais tantas camadas de chamadas de função entre a biblioteca C subjacente `_beginthreadex` e o objeto fornecido que pode ser chamado. Anteriormente, `std::thread` colocava seis funções entre `_beginthreadex` e o objeto fornecido que pode ser chamado, o que foi reduzido a apenas três (dois dos quais são apenas `std::invoke`). Essa alteração também resolve um bug obscuro de medição de tempo em que um construtor de `std::thread` podia ser interrompido se o relógio do sistema fosse alterado no exato momento que o `std::thread` estivesse sendo criado.

- Correção de uma regressão de desempenho em `std::hash` que introduzimos ao implementar `std::hash<std::filesystem::path>`.

- A biblioteca padrão usa destruidores em vez de blocos catch em diversos lugares para chegar à exatidão. Essa alteração resulta em melhor interação do depurador: exceções que você joga pela biblioteca padrão nos locais afetados agora aparecem como sendo geradas de seu site de lançamento original, em vez de nossa Rethrow. Nem todos os blocos catch da biblioteca padrão foram eliminados; esperamos que o número de blocos catch seja reduzido em versões futuras do MSVC.

- O gerador de código abaixo do ideal em `std::bitset` causado por um lançamento condicional em uma função noexcept foi corrigido pela fatoração do caminho de lançamento.

- A família `std::list` e `std::unordered_*` usa iteradores de não depuração internamente em mais locais.

- Vários membros `std::list` foram alterados para reutilizar os nós da lista onde possível, em vez de desalocá-los e realocá-los. Por exemplo, com um `list<int>` que já tem o tamanho de 3, uma chamada para `assign(4, 1729)` agora substitui os ints nos 3 primeiros nós de lista e aloca um novo nó de lista com o valor 1729.

- Todas as chamadas da biblioteca padrão para `erase(begin(), end())` foram alteradas para `clear()`.

- Agora, `std::vector` inicializa e apaga os elementos com mais eficiência em determinados casos.

- Melhorias em `std::variant` para torná-lo mais adequado para otimizadores, resultando na geração de códigos melhores. O inlining de código agora está agora muito melhor com `std::visit`.

## <a name="c-ide"></a>C++ IDE

### <a name="live-share-c-support"></a>Suporte de Live Share para C++

Agora, o [Live Share](/visualstudio/liveshare/) dá suporte a C++, permitindo que desenvolvedores usem o Visual Studio ou o Visual Studio Code para colaborar em tempo real. Para obter mais informações, consulte [anunciando Live share C++para: compartilhamento e colaboração em tempo real](https://devblogs.microsoft.com/cppblog/cppliveshare/)

### <a name="intellicode-for-c"></a>IntelliCode paraC++

##### <a name="visual-studio-2019-version-161"></a>Visual Studio 2019 versão 16.1

O IntelliCode é uma extensão opcional que usa seu próprio treinamento abrangente e seu contexto de código para colocar o que você mais provavelmente usará na parte superior da lista de conclusão. Frequentemente, ele é capaz de eliminar a necessidade de rolar para baixo na lista. Para C++, o IntelliCode oferece a maior ajuda quando você está usando bibliotecas populares como a biblioteca padrão. Ele está disponível como um componente da carga de trabalho no instalador. Para obter mais informações, consulte [Sugestões de preenchimento de código auxiliadas por IA para C++ usando IntelliCode](https://devblogs.microsoft.com/cppblog/cppintellicode/).

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

### <a name="quickinfo-improvements"></a>Melhorias de Informações Rápidas

##### <a name="visual-studio-2019-version-161"></a>Visual Studio 2019 versão 16.1

A dica de ferramenta Informações Rápidas agora respeita a colorização semântica do seu editor. Ela também apresenta um novo link para **Pesquisa Online**, que pesquisará documentos online que traga mais informações sobre o constructo de código focalizado. Para código sublinhado em vermelho, o link fornecido por Informações Rápidas procurará o erro online. Dessa forma, você não precisa redigitar a mensagem no navegador. Para obter mais informações, consulte [melhorias de informações rápidas no Visual Studio 2019: colorização e pesquisa online](https://devblogs.microsoft.com/cppblog/quick-info-improvements-in-visual-studio-2019-colorization-and-search-online/).

### <a name="intellicode-available-in-c-workload"></a>IntelliCode disponível na carga de trabalho do C++

##### <a name="visual-studio-2019-version-161"></a>Visual Studio 2019 versão 16.1

O IntelliCode agora é fornecido como um componente opcional na carga de trabalho **Desenvolvimento para desktop com C++** . Para saber mais, confira [IntelliCode aprimorado para C++ agora vem com o Visual Studio 2019](https://devblogs.microsoft.com/cppblog/improved-c-intellicode-now-ships-with-visual-studio-2019/).

## <a name="cmake-support"></a>Suporte para CMake

- Suporte para CMake 3.14

- O Visual Studio agora pode abrir caches do CMake existentes gerados por ferramentas externas, como o CMakeGUI, ou por sistemas de metabuild personalizados ou scripts de build que invocam cmake.exe eles mesmos.

- Desempenho aprimorado de IntelliSense.

- Um novo editor de configurações fornece uma alternativa para editar o arquivo CMakeSettings.json manualmente e oferece alguma paridade com CMakeGUI.

- O Visual Studio ajuda a impulsionar o desenvolvimento de C++ com o CMake no Linux, detectando se você tem uma versão compatível do CMake em seu computador Linux. Caso contrário, ele oferece instalá-lo para você.

- As incompatibilidades de configuração no CMakeSettings, como arquiteturas incompatíveis ou configurações incompatíveis do gerador de CMake, mostram linhas irregulares no editor JSON e erros na Lista de Erros.

- A cadeia de ferramentas do vcpkg é detectada automaticamente e habilitada para projetos do CMake que são abertos no IDE após `vcpkg integrate install` ser executado. Esse comportamento pode ser desativado especificando-se um arquivo de cadeia de ferramentas vazio no CMakeSettings.

- Projetos do CMake agora permitem depuração Apenas Meu Código por padrão.

- Avisos de análise estática agora podem ser processados em segundo plano e exibidos no editor para projetos do CMake.

- Mensagens 'begin' e 'end' mais claras de build e de configuração para projetos do CMake e suporte à interface do usuário de progresso do build do Visual Studio. Além disso, agora há uma configuração de detalhes de CMake em **Ferramentas > Opções** para personalizar o nível de detalhe das mensagens de build e configuração do CMake na Janela de Saída.

- A configuração `cmakeToolchain` agora é compatível com o CMakeSettings.json para especificar cadeias de ferramentas sem modificar manualmente a linha de comando do CMake.

- Um novo atalho de menu **Compilar Tudo** **Ctrl + Shift + B**.

##### <a name="visual-studio-2019-version-161"></a>Visual Studio 2019 versão 16.1

- Suporte integrado para edição, compilação e depuração de projetos CMake com Clang/LLVM. Para saber mais, veja [Suporte a Clang/LLVM no Visual Studio](https://devblogs.microsoft.com/cppblog/clang-llvm-support-in-visual-studio/).

## <a name="linux-and-the-windows-subsystem-for-linux"></a>Linux e o Subsistema do Windows para Linux

##### <a name="visual-studio-2019-version-161"></a>Visual Studio 2019 versão 16.1

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

- Nossa documentação desencoraja ativamente o uso de módulos de mesclagem para a implantação do Runtime do Visual C++. Estamos realizando, nesta versão, a etapa extra de marcar nossos MSMs como preteridos. Considere migrar sua implantação central do VCRuntime de MSMs para o pacote redistribuível.

## <a name="mobile-development-with-c-android-and-ios"></a>Desenvolvimento móvel com C++ (Android e iOS)

A experiência do Android C++ agora usa por padrão o SDK do Android 25 e o NDK do Android 16b.

## <a name="clangc2-platform-toolset"></a>Conjunto de ferramentas de plataforma Clang/C2

O componente experimental Clang/C2 foi removido. Use o conjunto de ferramentas do MSVC para conformidade total de padrões C++ com `/permissive-` e `/std:c++17` ou a cadeia de ferramentas Clang/LLVM para Windows.

## <a name="code-analysis"></a>Análise de código

- A análise de código agora é executada automaticamente em segundo plano. Avisos são exibidos como linhas irregulares verdes no editor conforme você digita. Para obter mais informações, consulte [Análise de código no editor no Visual Studio 2019 Versão Prévia 2](https://devblogs.microsoft.com/cppblog/in-editor-code-analysis-in-visual-studio-2019-preview-2/).

- Novas regras de ConcurrencyCheck experimentais para tipos conhecidos de biblioteca padrão do cabeçalho \<mutex>. Para obter mais informações, consulte [Análise de código de simultaneidade no Visual Studio 2019](https://devblogs.microsoft.com/cppblog/concurrency-code-analysis-in-visual-studio-2019/).

- Uma implementação parcial atualizada do [Verificador de perfil de tempo de vida](https://herbsutter.com/2018/09/20/lifetime-profile-v1-0-posted/), que detecta referências e ponteiros pendentes. Para obter mais informações, consulte [Atualização de perfil de tempo de vida no Visual Studio 2019 Versão Prévia 2](https://devblogs.microsoft.com/cppblog/lifetime-profile-update-in-visual-studio-2019-preview-2/).

- Mais verificações relacionadas à corrotina, incluindo C26138, C26810, C26811 e a regra experimental C26800. Para obter mais informações, consulte [Novas verificações de análise de código no Visual Studio 2019: uso após movimentação e corrotina](https://devblogs.microsoft.com/cppblog/new-code-analysis-checks-in-visual-studio-2019-use-after-move-and-coroutine/).

##### <a name="visual-studio-2019-version-161"></a>Visual Studio 2019 versão 16.1

- Novas correções rápidas para verificações de variável não inicializadas. Para saber mais, confira [Novas correções rápidas de análise de código para memória não inicializada (C6001) e avisos de uso antes da inicialização (C26494)](https://devblogs.microsoft.com/cppblog/new-code-analysis-quick-fixes-for-uninitialized-memory-c6001-and-use-before-init-c26494-warnings/).

## <a name="unit-testing"></a>Teste de unidade

O modelo de projeto de teste do C++ gerenciado não está mais disponível. Você pode continuar usando a estrutura de teste do C++ gerenciado em seus projetos existentes. Para novos testes de unidade, considere usar uma das estruturas de teste nativas para as quais o Visual Studio fornece modelos (MSTest, Google Test) ou o modelo de projeto de teste de C# gerenciado.

::: moniker-end

::: moniker range="=vs-2017"

O Visual Studio 2017 traz muitas atualizações e correções para o ambiente do C++. Corrigimos mais de 250 bugs e problemas relatados no compilador e nas ferramentas, muitos deles enviados pelos clientes pelas opções Relatar um Problema e [Fornecer uma Sugestão](/visualstudio/ide/how-to-report-a-problem-with-visual-studio?view=vs-2017) em **Enviar Comentários**. Obrigado por relatar bugs! Para saber mais sobre todas as novidades do Visual Studio, visite [Novidades no Visual Studio 2017](/visualstudio/ide/whats-new-visual-studio-2017?view=vs-2017). Para saber mais sobre novidades de C++ no Visual Studio 2019, confira [Novidades de C++ no Visual Studio](/cpp/overview/what-s-new-for-visual-cpp-in-visual-studio?view=vs-2019). Para saber mais sobre as novidades de C++ no Visual Studio 2015 e em versões anteriores, confira [O que há de novo no Visual C++ de 2003 a 2015](/cpp/porting/visual-cpp-what-s-new-2003-through-2015).

## <a name="c-compiler"></a>compilador C++

### <a name="c-conformance-improvements"></a>Aprimoramentos de conformidade do C++

Nesta versão, atualizamos o compilador do C++ e a biblioteca padrão com suporte aprimorado para os recursos C++11 e C++14, bem como o suporte preliminar para determinados recursos esperados no padrão C++ 17. Para obter informações detalhadas, consulte [Aprimoramentos de conformidade do C++ no Visual Studio 2017](cpp-conformance-improvements.md).

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

O compilador é compatível com cerca de 75% das funcionalidades novas do C++17, incluindo associações estruturadas, lambdas `constexpr`, `if constexpr`, variáveis embutidas, expressões de dobra e adição de `noexcept` ao tipo sistema. Esses recursos estão disponíveis na opção **/std:c++17**. Para obter mais informações, veja [Melhorias de conformidade do C++ no Visual Studio 2017](cpp-conformance-improvements.md)

##### <a name="visual-studio-2017-version-157"></a>Visual Studio 2017 versão 15.7

Agora, o conjunto de ferramentas do compilador do MSVC no Visual Studio versão 15.7 é compatível com o padrão do C++. Para obter mais informações, consulte [anunciando: MSVC está de acordo com C++ a conformidade com o idioma padrão e com a](https://devblogs.microsoft.com/cppblog/announcing-msvc-conforms-to-the-c-standard/) [Microsoft C++ ](../visual-cpp-language-conformance.md).

##### <a name="visual-studio-2017-version-158"></a>Visual Studio 2017 versão 15.8

A opção de compilador [/experimental: pré-processador](../build/reference/experimental-preprocessor.md) habilita o novo pré-processador de MSVC experimental que eventualmente será compatível com todos os padrões e C++ C aplicáveis. Para obter mais informações, consulte [visão geral do pré-processador do MSVC experimental](../preprocessor/preprocessor-experimental-overview.md).

### <a name="new-compiler-options"></a>Novas opções do compilador

- [/permissive-](../build/reference/permissive-standards-conformance.md): habilite todas as opções do compilador de conformidade estrita com os padrões e desabilite a maioria das extensões do compilador específicas da Microsoft (mas não `__declspec(dllimport)`, por exemplo). Essa opção está ativada por padrão no Visual Studio 2017 versão 15.5.  O modo de conformidade **/permissive-** inclui compatibilidade com a pesquisa de nome em duas fases. Para obter mais informações, veja [Melhorias de conformidade do C++ no Visual Studio](cpp-conformance-improvements.md).

- [/diagnostics](../build/reference/diagnostics-compiler-diagnostic-options.md): habilite a exibição do número de linha, do número de linha e da coluna ou do número de linha e da coluna e de um cursor sob a linha de código em que o erro ou o aviso do diagnóstico é encontrado.

- [/debug: FASTLINK](../build/reference/debug-generate-debug-info.md): habilitar até 30% de tempo de link incremental mais rápido (vs. Visual Studio 2015), não copiando todas as informações de depuração no arquivo PDB. Em vez disso, o arquivo PDB aponta para as informações de depuração para os arquivos de biblioteca e de objeto usados para criar o executável. Veja [Faster C++ build cycle in VS "15" with /Debug:fastlink](https://devblogs.microsoft.com/cppblog/faster-c-build-cycle-in-vs-15-with-debugfastlink/) (Ciclo de build do C++ mais rápido no VS "15" com /Debug:fastlink) e [Recommendations to speed C++ builds in Visual Studio](https://devblogs.microsoft.com/cppblog/recommendations-to-speed-c-builds-in-visual-studio/) (Recomendações para acelerar builds do C++ no Visual Studio).

- O Visual Studio 2017 permite o uso de [/sdl](../build/reference/sdl-enable-additional-security-checks.md) com [/await](../build/reference/await-enable-coroutine-support.md). Removemos a limitação [/RTC](../build/reference/rtc-run-time-error-checks.md) com corrotinas.

##### <a name="visual-studio-2017-version-153"></a>Visual Studio 2017 versão 15.3

- [/std: c++ 14 e/std: c + + mais recente](../build/reference/std-specify-language-standard-version.md): essas opções de compilador permitem que você aceite versões específicas da linguagem de C++ programação ISO em um projeto. A maioria das novas funcionalidades padrão de rascunho é protegida pela opção **/std:c++latest**.

- [/std:c++17](../build/reference/std-specify-language-standard-version.md) habilita o conjunto de funcionalidades do C++17 implementado pelo compilador. Essa opção desabilita o suporte ao compilador e à biblioteca padrão para funcionalidades alteradas ou novas nas versões das atualizações de defeito e de rascunho de trabalho do C++ Standard após o C++17. Para habilitar essas funcionalidades, use **/std:c++latest**.

### <a name="codegen-security-diagnostics-and-versioning"></a>Geração de código, segurança, diagnóstico e controle de versão

Esta versão apresenta várias melhorias na otimização, na geração de código, no controle de versão do conjunto de ferramentas e nos diagnósticos. Alguns aprimoramentos importantes incluem:

- Melhor geração de código de loops: suporte para vetorização automática da divisão de inteiros constantes, melhor identificação de padrões de memset.
- Melhor segurança do código: melhoria na emissão de diagnóstico do compilador de estouro de buffer e o [/guard:cf](../build/reference/guard-enable-control-flow-guard.md) agora protege instruções de opções que geram uma tabelas de saltos.
- Controle de versão: o valor da macro do pré-processador interna **\_MSC\_VER** está sendo monotonicamente atualizado a cada atualização do conjunto de ferramentas do Visual C++. Para obter mais informações, consulte [Versão do compilador do Visual C++](https://devblogs.microsoft.com/cppblog/visual-c-compiler-version/).
- Novo layout do conjunto de ferramentas: o compilador e as ferramentas de build relacionadas têm um novo local e nova estrutura de diretório em seu computador de desenvolvimento. O novo layout habilita instalações lado a lado de várias versões do compilador. Para saber mais, confira [Layout de ferramentas do compilador no Visual Studio 2017](https://devblogs.microsoft.com/cppblog/compiler-tools-layout-in-visual-studio-15/).
- Diagnósticos aprimorados: a janela de saída agora mostra a coluna em que ocorre um erro. Para obter mais informações, consulte [Aprimoramentos de diagnóstico do compilador do C++ no VS "15" Preview 5](https://devblogs.microsoft.com/cppblog/c-compiler-diagnostics-improvements-in-vs-15-rc/).
- Ao usar corrotinas, a palavra-chave experimental **yield** (disponível na opção **/await**) foi removida. Em vez disso, seu código deve ser atualizado para usar `co_yield`. Para saber mais, confira a palavra-chave [`yield` para se tornar `co_yield` no VS 2017](https://devblogs.microsoft.com/cppblog/yield-keyword-to-become-co_yield-in-vs-2017/).

##### <a name="visual-studio-2017-version-153"></a>Visual Studio 2017 versão 15.3

Aprimoramentos adicionais para o diagnóstico no compilador. Para saber mais, confira [Aperfeiçoamentos de diagnóstico no Visual Studio 2017 15.3.0](https://devblogs.microsoft.com/cppblog/diagnostic-improvements-in-vs2017-15-3-0/).

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

O desempenho do runtime do Visual C++ continua a melhorar devido à melhor qualidade do código gerado. Agora você pode simplesmente recompilar o código e o aplicativo será executado mais rapidamente. Algumas das otimizações do compilador são totalmente novas, como a vetorização de repositórios escalares condicionais, a combinação de chamadas `sin(x)` e `cos(x)` em um novo `sincos(x)` e a eliminação de instruções redundantes do otimizador de SSA. Outras otimizações do compilador são melhorias de funcionalidades existentes, como a heurística do vetorizador para expressões condicionais, melhores otimizações de loop e codegen mín/máx de float. O vinculador tem uma implementação de **/OPT:ICF** nova e mais rápida que pode resultar em aceleração de até 9% do tempo de vinculação, além de outras correções de desempenho na vinculação incremental. Para obter mais informações, consulte [/OPT (Otimizações)](../build/reference/opt-optimizations.md) e [/INCREMENTAL (Vincular de maneira incremental)](../build/reference/incremental-link-incrementally.md).

O compilador do Microsoft C++ é compatível com o AVX-512 da Intel, inclusive as instruções de Tamanho do Vetor que traz novas funções no AVX-512 para Registros de 128 e 256 bits.

A opção [/Zc:noexceptTypes-](../build/reference/zc-noexcepttypes.md) pode ser usada para reverter para a versão C++14 do `noexcept` ao usar o modo C++17 em geral. Essa opção permite que você atualize seu código-fonte para estar em conformidade com a C++17 sem precisar reescrever todo o código `throw()` ao mesmo tempo. Para obter mais informações, consulte [Remoção de especificação de exceção dinâmica e noexcept](cpp-conformance-improvements.md#noexcept_removal).

##### <a name="visual-studio-2017-version-157"></a>Visual Studio 2017 versão 15.7

- Novo comutador do compilador [/Qspectre](../build/reference/qspectre.md) para ajudar a reduzir ataques de temporização de execução especulativa. Para saber mais, confira [Mitigações do Spectre no MSVC](https://devblogs.microsoft.com/cppblog/spectre-mitigations-in-msvc/).
- Novo aviso de diagnóstico da mitigação do Spectre. Para saber mais, confira [Diagnóstico do Spectre no Visual Studio 2017 versão 15.7 versão prévia 4](https://devblogs.microsoft.com/cppblog/spectre-diagnostic-in-visual-studio-2017-version-15-7-preview-4/).
- Um novo valor para /Zc, **/Zc:__cplusplus**, permite corrigir relatórios do suporte padrão do C++. Por exemplo, quando o comutador é definido e o compilador está no modo /std:c++17, o valor expande para **201703L**. Para saber mais, confira [Agora o MSVC relata corretamente __cplusplus](https://devblogs.microsoft.com/cppblog/msvc-now-correctly-reports-__cplusplus/).

## <a name="c-standard-library"></a>Biblioteca padrão C++

### <a name="correctness-improvements"></a>Melhorias de correção

##### <a name="visual-studio-2017-rtm-version-150"></a>Visual Studio 2017 RTM (versão 15.0)

- Pequenas melhorias de diagnóstico `basic_string` `_ITERATOR_DEBUG_LEVEL != 0`. Acionar uma verificação de IDL no mecanismo de cadeia de caracteres agora relatará o comportamento específico que acionou a verificação. Por exemplo, em vez de "não é possível desreferenciar o iterador de cadeia de caracteres", você verá "não é possível desreferenciar o iterador de cadeia de caracteres porque ele está fora do intervalo (por exemplo, um iterador de fim)".
- O operador de atribuição de mudança `std::promise` foi corrigido, pois anteriormente poderia causar bloqueio indefinido no código.
- Erros de compilador corrigidos, com a conversão implícita de `atomic<T*>` em `T*`.
- `pointer_traits<Ptr>` agora detecta `Ptr::rebind<U>` corretamente.
- Corrigido o qualificador `const` ausente no operador de subtração `move_iterator`.
- Corrigido o gerador de código inválido silencioso para alocadores definidos pelo usuário com estado solicitando `propagate_on_container_copy_assignment` e `propagate_on_container_move_assignment`.
- `atomic<T>` agora tolera o `operator&()` sobrecarregado.
- Pequena melhoria no diagnóstico do compilador para chamadas `bind()` incorretas.

Para obter uma lista completa de aprimoramentos do Visual Studio 2017 RTM, confira o post do Blog da Equipe de C++ [Correções da Biblioteca Padrão no VS 2017 RTM](https://devblogs.microsoft.com/cppblog/stl-fixes-in-vs-2017-rtm/).

##### <a name="visual-studio-2017-version-153"></a>Visual Studio 2017 versão 15.3

- Os contêineres da biblioteca padrão agora fixam o `max_size()` ao `numeric_limits<difference_type>::max()` em vez do `max()` de `size_type`. Essa alteração garante que o resultado de `distance()` nos iteradores do contêiner seja representável no tipo de retorno de `distance()`.
- Especialização `auto_ptr<void>` ausente corrigida.
- Os algoritmos `for_each_n()`, `generate_n()` e `search_n()` não conseguiam ser compilados se o argumento de comprimento não fosse um tipo integral; eles agora tentarão converter comprimentos não integrais em `difference_type` dos iteradores.
- `normal_distribution<float>` não emite mais avisos na biblioteca padrão sobre o estreitamento de double para float.
- Corrigidas algumas operações `basic_string` que usavam `npos` em vez de `max_size()` durante a verificação de estouro de tamanho máximo.
- `condition_variable::wait_for(lock, relative_time, predicate)` esperava todo o tempo relativo no caso de uma ativação falsa. Agora ele aguardará apenas um único intervalo do tempo relativo.
- `future::get()` agora invalida o `future`, como o padrão exige.
- `iterator_traits<void *>` era um erro de hardware porque tentava formar `void&`; agora claramente torna-se um struct vazio para permitir o uso de `iterator_traits` em condições SFINAE "is iterator".
- Alguns avisos relatados pelo Clang **-Wsystem-headers** foram corrigidos.
- Também corrigida a "especificação de exceção na declaração não corresponde à declaração anterior" relatada pelo Clang **-Wmicrosoft-exception-spec**.
- Também corrigidos os avisos de ordenação mem-initializer-list relatados por Clang e C1XX.
- Os contêineres não ordenados não trocavam funções de hash ou predicados quando os próprios contêineres eram trocados. Agora eles fazem isso.
- Muitas operações de troca de contêiner agora são marcadas com `noexcept` (como a biblioteca padrão nunca pretende lançar uma exceção ao detectar a condição de um comportamento indefinido non-equal-allocator de non-`propagate_on_container_swap`).
- Muitas operações `vector<bool>` agora são marcadas com `noexcept`.
- A biblioteca padrão agora imporá o alocador de correspondência `value_type` (no modo C++17) com uma hachura de escape de recusa.
- Corrigidas algumas condições em que self-range-insert em `basic_string` misturaria o conteúdo das cadeias de caracteres. (Observação: self-range-insert em vectors ainda é proibido pelo Standard.)
- `basic_string::shrink_to_fit()` não é mais afetado pelo `propagate_on_container_swap` do alocador.
- `std::decay` agora manipula tipos de função abomináveis, ou seja, tipos de função qualificados para cv- e/ou ref.
- Alteradas as diretivas de inclusão para usar diferenciação adequada de maiúsculas e minúsculas e barras invertidas, melhorando a portabilidade.
- Corrigido o aviso C4061 "enumerador '*enumerador*' na opção de enumeração '*enumeração*' não é manipulado explicitamente por um rótulo case". Esse aviso é desativado por padrão e foi corrigido como uma exceção à política geral da biblioteca padrão para avisos. (A biblioteca padrão é **/W4** limpo, mas não tenta ser **/Wall** limpo. Muitos avisos de desativação por padrão são muito barulhentos e não devem ser usados com regularidade.)
- Melhoria nas verificações de depuração de `std::list`. Os iteradores de lista agora verificam `operator->()` e `list::unique()` agora marca os iteradores como invalidados.
- Corrigida a metaprogramação de uses-allocator em `tuple`.

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

- `std::partition` agora chama o predicado N vezes e não N vezes + 1, como o padrão exige.
- As tentativas de evitar estáticas mágicas na versão 15.3 foram reparadas na versão 15.5.
- `std::atomic<T>` não requer mais que `T` seja construível por padrão.
- Algoritmos de heap que usam o tempo logarítmico não fazem mais uma declaração de tempo linear de que a entrada é na verdade um heap quando a depuração do iterador está habilitada.
- `__declspec(allocator)` agora é protegido apenas para C1XX a fim de evitar avisos do Clang que não entendem esse declspec.
- `basic_string::npos` agora está disponível como uma constante de tempo de compilação.
- `std::allocator` no modo C++17 agora manipula corretamente a alocação de tipos excessivamente alinhados, isto é, tipos cujo alinhamento é superior a `max_align_t`, a menos que seja desabilitado por **/Zc:alignedNew-** .  Por exemplo, vetores de objetos com alinhamento de 16 ou de 32 bytes agora serão corretamente alinhados para instruções SSE e AVX.

### <a name="conformance-improvements"></a>Aprimoramentos de conformidade

- Adicionamos \<any\>, \<string_view\>, `apply()` e `make_from_tuple()`.
- Adicionamos \<optional\>, \<variant\>, `shared_ptr::weak_type` e \<cstdalign\>.
- O `constexpr` do C++14 foi habilitado em `min(initializer_list)`, em `max(initializer_list)`, em `minmax(initializer_list)`, em `min_element()`, em `max_element()` e em `minmax_element()`.

Para obter mais informações, [consulte C++ tabela de conformidade de idioma da Microsoft](../visual-cpp-language-conformance.md).

##### <a name="visual-studio-2017-version-153"></a>Visual Studio 2017 versão 15.3

- Vários recursos adicionais do C++17 foram implementados. Para obter mais informações, [consulte C++ tabela de conformidade de idioma da Microsoft](cpp-conformance-improvements.md#improvements_153).
- Implementado P0602R0 "variante e opcional devem propagar a trivialidade copiar/mover".
- A biblioteca padrão agora oficialmente tolera RTTI dinâmico sendo desabilitado por meio da opção [/GR-](../build/reference/gr-enable-run-time-type-information.md). Tanto `dynamic_pointer_cast()` quanto `rethrow_if_nested()` exigem `dynamic_cast` de maneira inerente, portanto a biblioteca padrão marca-os agora como `=delete` em **/GR-** .
- Mesmo quando o RTTI dinâmico for desabilitado por meio de **/GR-** , o "RTTI estático" na forma de `typeid(SomeType)` ainda estará disponível e será usado por vários componentes da biblioteca padrão. A biblioteca padrão agora também permite desabilitar esse recurso usando **/D\_HAS\_STATIC\_RTTI=0**. Esse sinalizador também desabilitará `std::any`, as funções membro `target()` e `target_type()` de `std::function` e a função membro amigável `get_deleter()` de `std::shared_ptr` e de `std::weak_ptr`.
- A biblioteca padrão agora usa `constexpr` de C++14 incondicionalmente, em vez de macros definidas condicionalmente.
- A biblioteca padrão agora usa modelos de alias internamente.
- A biblioteca padrão agora usa `nullptr` internamente, em vez de `nullptr_t{}`. (O uso interno de NULL foi erradicado. O uso interno de 0-as-null está sendo eliminado gradualmente.)
- A biblioteca padrão agora usa `std::move()` internamente, em vez de usar `std::forward()` de maneira estilística indevidamente.
- `static_assert(false, "message")` foi alterado por `#error message`. Essa alteração melhora o diagnóstico do compilador porque `#error` interrompe imediatamente a compilação.
- A biblioteca padrão não marca mais funções como `__declspec(dllimport)`. A tecnologia moderna de vinculador não exige mais isso.
- SFINAE extraído para argumentos de modelo padrão, o que reduzia a desordem em comparação com tipos de retorno e tipos de argumento de função.
- As verificações de depuração em \<random\> agora usam o maquinário usual da biblioteca padrão, em vez da função interna `_Rng_abort()` que chamava `fputs()` para **stderr**. A implementação dessa função está sendo retida para compatibilidade binária, mas foi removida na próxima versão incompatível com binário da biblioteca padrão.

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

- Vários recursos foram adicionados, preteridos ou removidos da biblioteca padrão em conformidade com o padrão do C++17. Para saber mais, veja [Melhorias de conformidade do C++ no Visual Studio](cpp-conformance-improvements.md#improvements_155).
- Suporte experimental para os seguintes algoritmos paralelos:
  - `all_of`
  - `any_of`
  - `for_each`
  - `for_each_n`
  - `none_of`
  - `reduce`
  - `replace`
  - `replace_if`
  - `sort`
- As assinaturas para os seguintes algoritmos paralelos são adicionadas, mas não paralelizadas neste momento. A criação de perfil não demonstrou nenhum benefício na paralelização de algoritmos que apenas movem ou permutam elementos:
  - `copy`
  - `copy_n`
  - `fill`
  - `fill_n`
  - `move`
  - `reverse`
  - `reverse_copy`
  - `rotate`
  - `rotate_copy`
  - `swap_ranges`

##### <a name="visual-studio-2017-version-156"></a>Visual Studio 2017 versão 15.6

- \<memory_resource>
- Princípios básicos da biblioteca V1
- Exclusão da atribuição `polymorphic_allocator`
- Melhorias na dedução de argumento de modelo de classe

##### <a name="visual-studio-2017-version-157"></a>Visual Studio 2017 versão 15.7

- Suporte a algoritmos paralelos não é mais experimental
- Uma nova implementação de \<filesystem>
- Conversões elementares de cadeia de caracteres (parcial)
- `std::launder()`
- `std::byte`
- `hypot(x,y,z)`
- Evitar decaimento desnecessário
- Funções matemáticas especiais
- `constexpr char_traits`
- Guias de dedução da biblioteca padrão

Para obter mais informações, [consulte C++ tabela de conformidade de idioma da Microsoft](../visual-cpp-language-conformance.md).

### <a name="performance-and-throughput-fixes"></a>Correções de desempenho e taxa de transferência

- Fez sobrecargas `basic_string::find(char)` chamar `traits::find` apenas uma vez. Anteriormente, isso era implementado como uma pesquisa de cadeia de caracteres geral para de uma cadeia de caracteres de comprimento 1.
- `basic_string::operator==` agora verifica o tamanho da cadeia de caracteres antes de comparar o conteúdo das cadeias de caracteres.
- Removido o acoplamento de controle em `basic_string`, que dificultava a análise do otimizador do compilador. Para todas as cadeias de caracteres curtas, chamar `reserve` ainda não tem certo custo por não fazer nada.
- `std::vector` foi revisado em relação à sua correção e desempenho: a suavização durante as operações de inserção e posicionamento agora é tratada corretamente como exigido pelo padrão, a garantia de exceção forte agora é fornecida quando exigida pelo padrão por meio de `move_if_noexcept()` e outra lógica e inserção e posicionamento executam menos operações de elemento.
- A biblioteca padrão do C++ agora evita desreferenciar ponteiros nulos sofisticados.
- Desempenho de `weak_ptr::lock()` aprimorado.
- Para aumentar a taxa de transferência do compilador, os cabeçalhos da biblioteca padrão do C++ agora evitam incluir declarações para intrínsecos do compilador que são desnecessários.
- Aumento mais de três vezes do desempenho dos construtores de movimento `std::string` e `std::wstring`.

##### <a name="visual-studio-2017-version-153"></a>Visual Studio 2017 versão 15.3

- Solucionadas as interações com `noexcept` que impediam a implementação embutida de `std::atomic` em funções que usam o SEH (tratamento de exceções estruturado).
- Alterada a função interna `_Deallocate()` da biblioteca padrão para ser otimizada em código menor, permitindo que ele seja embutido em outros locais.
- Alterado `std::try_lock()` para usar a expansão de pacote em vez de recursão.
- O algoritmo de impedimento de deadlock `std::lock()` foi melhorado para usar operações `lock()` em vez de girar em `try_lock()` em todos os bloqueios.
- Habilitada a otimização de valor retornado nomeado em `system_category::message()`.
- `conjunction` e `disjunction` agora instanciam de N + 1 tipos, em vez de 2N + 2 tipos.
- `std::function` não instancia mais máquinas de suporte de alocador para cada chamável apagado por tipo, melhorando a taxa de transferência e reduzindo o tamanho de .obj em programas que passam vários lambdas distintos para `std::function`.
- `allocator_traits<std::allocator>` contém operações `std::allocator` manualmente embutidas, o que reduz o tamanho do código que interage com `std::allocator` apenas por meio de `allocator_traits` (ou seja, no maioria dos códigos).
- A interface de alocador mínima C++11 agora é manipulada pela biblioteca padrão chamando `allocator_traits` diretamente, em vez de encapsular o alocador em uma classe interna `_Wrap_alloc`. Isso reduz o tamanho do código gerado compatível com o alocador, melhora a capacidade do otimizador de raciocinar sobre contêineres da Biblioteca Padrão em alguns casos e fornece uma melhor experiência de depuração (porque agora você pode ver o tipo de alocador, em vez de `_Wrap_alloc<your_allocator_type>` no depurador).
- Removida a metaprogramação para `allocator::reference` personalizada, que os alocadores, na verdade, não têm permissão para serem personalizados. (Os alocadores podem fazer contêineres usarem ponteiros sofisticados, mas não referências sofisticadas.)
- O front-end do compilador foi ensinado a descompactar iteradores de depuração em loops for baseados em intervalo, melhorando o desempenho de compilações de depuração.
- O caminho de redução interna de `basic_string` para `shrink_to_fit()` e para `reserve()` não está mais no caminho das operações de realocação, o que reduz o tamanho do código para todos os membros de mutação.
- O caminho de crescimento interno `basic_string` não está no caminho de `shrink_to_fit()`.
- As operações de mutação de `basic_string` agora são fatoradas em funções de caminho rápido de não alocação e de caminho lento de alocação, aumentando a probabilidade de o caso comum de não realocação ser embutido em chamadores.
- As operações de mutação de `basic_string` agora constroem buffers realocados no estado desejado em vez do redimensionamento em vigor. Por exemplo, inserir no início de uma cadeia de caracteres agora move o conteúdo após a inserção exatamente uma vez (para baixo ou para o buffer recém-alocado), em vez de duas vezes no caso de realocação (para o buffer recém-alocado e, em seguida, para baixo).
- As operações chamando a biblioteca padrão C em \<cadeia de caracteres\> agora armazena em cache o endereço `errno` para remover interações repetidas com TLS.
- Implementação `is_pointer` simplificada.
- Concluída a alteração da expressão SFINAE baseada em função para baseada em `struct` e em `void_t`.
- Os algoritmos de biblioteca padrão agora evitam iteradores de pós-incrementação.
- Corrigidos os avisos de truncamento ao usar alocadores de 32 bits em sistemas de 64 bits.
- A atribuição de movimentação `std::vector` agora é mais eficiente para o caso de alocador não igual a não POCMA reutilizando o buffer quando possível.

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

- `basic_string<char16_t>` agora aciona o mesmo `memcmp`, `memcpy` e otimizações semelhantes que acionam `basic_string<wchar_t>`.
- Uma limitação do otimizador que impedia os ponteiros de função de serem embutidos e que foi exposta pelo nosso trabalho "evitar a cópia de funções" no Visual Studio 2015 Atualização 3 foi solucionada, restaurando o desempenho de `lower_bound(iter, iter, function pointer)`.
- A sobrecarga da verificação da ordem de entradas da depuração do iterador para `includes`, `set_difference`, `set_symmetric_difference` e `set_union` foi reduzida desencapsulando iteradores antes de verificar a ordem.
- `std::inplace_merge` agora ignora elementos que já estão no lugar.
- Construir `std::random_device` agora não constrói e, em seguida, destrói um `std::string`.
- `std::equal` e `std::partition` tinham uma passagem de otimização de jump-threading que salvava uma comparação de iterador.
- Quando for passado ponteiros em `std::reverse` para `T` facilmente copiado, ele agora enviará uma implementação vetorizada manuscrita.
- `std::fill`, `std::equal` e `std::lexicographical_compare` foram ensinados a enviar a `memset` e a `memcmp` para `std::byte` e para `gsl::byte` (e outras classes de enumeração e enumerações similares a char). Como `std::copy` envia usando `is_trivially_copyable`, ele não precisa de nenhuma alteração.
- A biblioteca padrão não contém mais destruidores com chaves vazias cujo único comportamento era tornar os tipos em não facilmente destrutíveis.

## <a name="other-libraries"></a>Outras bibliotecas

### <a name="open-source-library-support"></a>Suporte à biblioteca de software livre

**Vcpkg** é uma ferramenta de linha de comando de software livre que simplifica bastante o processo de aquisição e de compilação de bibliotecas estáticas e de DLLS de software livre do C++ no Visual Studio. Para obter mais informações, consulte [vcpkg: um gerenciador de pacotes para C++](../build/vcpkg.md).

### <a name="cpprest-sdk-290"></a>CPPRest SDK 2.9.0

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

A CPPRestSDK, uma API da Web de plataforma cruzada para o C++, foi atualizada para a versão 2.9.0. Para obter mais informações, consulte [CppRestSDK 2.9.0 está disponível no GitHub](https://devblogs.microsoft.com/cppblog/cpprestsdk-2-9-0-is-available-on-github/).

### <a name="atl"></a>ATL

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

- Ainda outro conjunto de correções de compatibilidade de pesquisa de nome
- Construtores de movimentação e operadores de atribuição existentes são agora corretamente marcados como sem lançamento
- Não suprimir aviso C4640 válido sobre a inicialização segura de thread de estatísticas locais no atlstr.h
- A inicialização segura de thread de estatísticas locais foi desabilitada automaticamente no conjunto de ferramentas XP ao usar ATL para compilar uma DLL, mas agora não está. Você poderá adicionar **/Zc:threadSafeInit-** nas configurações de projeto se desejar que a inicialização segura de thread seja desativada.

### <a name="visual-c-runtime"></a>runtime do Visual C++

- Novo cabeçalho "cfguard.h" para símbolos de proteção de fluxo de controle.

## <a name="c-ide"></a>C++ IDE

- Agora, o desempenho de alteração de configuração é melhor para projetos nativos C++ e muito melhor para projetos C++/CLI. Quando uma configuração de solução for ativada pela primeira vez, depois ela será mais rápida, e todas as ativações subsequentes dessa configuração de solução serão quase instantâneas.

##### <a name="visual-studio-2017-version-153"></a>Visual Studio 2017 versão 15.3

- Vários assistentes de código e de projeto foram reescritos no estilo de caixa de diálogo de assinatura.
- **Adicionar Classe** agora inicia o assistente para Adicionar Classe diretamente. Todos os outros itens que estavam anteriormente aqui agora estão disponíveis em **Adicionar > Novo Item**.
- Os projetos do Win32 agora estão na categoria **Área de Trabalho do Windows** na caixa de diálogo **Novo Projeto**.
- Os modelos de **Console do Windows** e de **Aplicativo da Área de Trabalho** agora criam projetos sem exibir um assistente. Há um novo **Assistente de Área de Trabalho do Windows** na mesma categoria que exibe as mesmas opções que o antigo assistente **Aplicativo de Console do Win32**.

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

Diversas operações C++ que usam o mecanismo IntelliSense para refatoração e navegação de código são executadas muito mais rápido. Os números a seguir se baseiam na solução do Visual Studio Chromium com 3500 projetos:

|||
|-|-|
|Recurso|Melhoria de desempenho|
|Renomear|5.3x|
|Alterar assinatura |4.5x|
|Localizar Todas as Referências|4.7x|

O C++ agora é compatível com Ctrl + Clique em **Ir para Definição**, facilitando a navegação do mouse para definições. O Visualizador de Estrutura do pacote de Ferramentas Avançadas de Produtividade agora também está incluído no produto por padrão.

## <a name="intellisense"></a>IntelliSense

- O novo mecanismo de banco de dados com base em SQLite agora está sendo usado por padrão. Isso acelerará operações de banco de dados como **Ir para Definição** e **Localizar Todas as Referências** e melhorará significativamente o tempo de análise inicial da solução. A configuração foi movida para **Ferramentas > Opções > Editor de Texto > C/C++ > Avançado** (estava anteriormente em... C/C++ | Experimental).

- Melhoramos o desempenho do IntelliSense em projetos e arquivos que não estão usando cabeçalhos pré-compilados – um Cabeçalho Pré-Compilado Automático será criado para os cabeçalhos no arquivo atual.

- Adicionamos filtragem de erros e ajuda para erros do IntelliSense e na lista de erros. Agora, ao clicar na coluna de erro é possível filtrar. Além disso, clicar em erros específicos ou pressionar F1 iniciará uma pesquisa online sobre a mensagem de erro.

  ![Lista de Erros](media/ErrorList1.png "Lista de Erros")

  ![Lista de Erros filtrados](media/ErrorList2.png "Lista de Erros filtrada")

- Adicionada a capacidade de filtrar por tipo os itens da Lista de Membros.

  ![Filtragem da lista de membros](media/mlfiltering.png "Filtragem da Lista de Membros")

- Adicionado um novo recurso experimental Predictive IntelliSense, que fornece filtragem ciente de contexto daquilo que aparece na Lista de Membros. Para saber mais, confira [Melhorias do IntelliSense no C++ – IntelliSense Preditivo e Filtragem](https://devblogs.microsoft.com/cppblog/c-intellisense-improvements-predictive-intellisense-filtering/).
- **Localizar Todas as Referências** (Shift+F12) agora ajuda a movimentar-se facilmente, até mesmo em bases de código complexas. Ela fornece agrupamento, filtragem, classificação e pesquisa avançada nos resultados e, para algumas linguagens, colorização, para que você obtenha uma compreensão clara de suas referências. Para o C++, a nova interface do usuário inclui informações sobre se estamos lendo de uma variável ou gravando em uma variável.
- O recurso Dot-to-Arrow IntelliSense passou de experimental a avançado e agora está habilitado por padrão. As funcionalidades do editor **Expandir Escopos** e **Expandir Precedência** também passaram de experimentais para avançadas.
- As funcionalidades de refatoração experimentais **Alterar Assinatura** e **Extrair Função** agora estão disponíveis por padrão.
- Adicionada uma funcionalidade experimental "Carregamento de projeto mais rápido" para projetos C++. Na próxima vez que você abrir um projeto C++, ele será carregado mais rapidamente e, depois disso, ele será carregado *muito* mais rapidamente!
- Alguns desses recursos são comuns a outras linguagens e alguns são específicos do C++. Para saber mais sobre essas novas funcionalidades, veja [Anúncio do Visual Studio "15" Preview 5](https://devblogs.microsoft.com/visualstudio/announcing-visual-studio-15-preview-5/).

##### <a name="visual-studio-2017-version-157"></a>Visual Studio 2017 versão 15.7

- Foi adicionado o suporte a ClangFormat. Para obter mais informações, veja [Suporte a ClangFormat no Visual Studio 2017](https://devblogs.microsoft.com/cppblog/clangformat-support-in-visual-studio-2017-15-7-preview-1/).

## <a name="non-msbuild-projects-with-open-folder"></a>Projetos não MSBuild com Abrir Pasta

O Visual Studio 2017 apresenta a funcionalidade **Abrir Pasta**, que permite codificar, compilar e depurar em uma pasta que contém o código-fonte sem a necessidade de criar soluções ou projetos. Agora ficou muito mais fácil começar a usar o Visual Studio, mesmo que seu projeto não seja um projeto do MSBuild. Com a **Abrir Pasta**, você obtém acesso às funcionalidades avançadas de entendimento, de edição, de compilação e de depuração de código que o Visual Studio já fornece para os projetos do MSBuild. Para saber mais, veja [Projetos Open Folder para C++](../build/open-folder-projects-cpp.md).

- Melhorias na experiência de Abrir Pasta. Você pode personalizar a experiência por meio destes arquivos .json:
  - CppProperties.json para personalizar a experiência de navegação e do IntelliSense.
  - Tasks.json para personalizar as etapas de build.
  - Launch.json para personalizar a experiência de depuração.

##### <a name="visual-studio-2017-version-153"></a>Visual Studio 2017 versão 15.3

- Suporte aprimorado para ambientes de compilação e compiladores alternativos como MinGW e Cygwin. Para saber mais, veja [Usando MinGW e Cygwin com Visual C++ e Abrir Pasta](https://devblogs.microsoft.com/cppblog/using-mingw-and-cygwin-with-visual-cpp-and-open-folder/).
- Adicionado compatibilidade para definir variáveis de ambiente globais e específicas de configuração em CppProperties.json e em CMakeSettings.json. Essas variáveis de ambiente podem ser consumidas por configurações de depuração definidas em launch.vs.json e em tarefas em tasks.vs.json. Para saber mais, veja [Personalizando seu ambiente com o Visual C++ e Abrir Pasta](https://devblogs.microsoft.com/cppblog/customizing-your-environment-with-visual-c-and-open-folder/).
- Suporte aprimorado para o gerador Ninja do CMake, incluindo a capacidade de direcionar facilmente plataformas de 64 bits.

## <a name="cmake-support-via-open-folder"></a>Suporte a CMake através do Open Folder

O Visual Studio 2017 apresenta suporte ao uso de projetos CMake sem a conversão para arquivos de projeto MSBuild (.vcxproj). Para saber mais, confira [Projetos CMake no Visual Studio](../build/cmake-projects-in-visual-studio.md). Abrir projetos CMake com **Abrir Pasta** configurará automaticamente o ambiente para editar, compilar e depurar com o C++.

- O C++ IntelliSense funciona sem a necessidade de criar um arquivo CppProperties.json na pasta raiz. Também adicionamos uma nova lista suspensa para permitir aos usuários mudar facilmente entre as configurações fornecidas pelos arquivos CppProperties.json e CMake.

- Há suporte para configurações adicionais por meio de um arquivo CMakeSettings.json que reside na mesma pasta que o arquivo CMakeLists.txt.

  ![CMake abrir pasta](media/cmake-cpp.png "CMake abrir pasta")

##### <a name="visual-studio-2017-version-153"></a>Visual Studio 2017 versão 15.3

- Suporte adicionado para o gerador Ninja do CMake.

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

- Suporte adicionado para importação de caches de CMake existentes.

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

- Suporte adicionado para CMake 3.11, análise de código em projetos CMake, exibição de destinos no Gerenciador de Soluções, opções de geração de cache e compilação de arquivo único. Para obter mais informações, confira [Suporte a CMake no Visual Studio](https://devblogs.microsoft.com/cppblog/cmake-support-in-visual-studio-targets-view-single-file-compilation-and-cache-generation-settings/) e [Projetos CMake no Visual Studio](../build/cmake-projects-in-visual-studio.md).

## <a name="windows-desktop-development-with-c"></a>Desenvolvimento da Área de Trabalho do Windows com C++

Agora, fornecemos uma experiência de instalação mais granular da carga de trabalho original do C++. Adicionamos componentes selecionáveis que permitem a instalação apenas das ferramentas das quais você precisa. Observe que os tamanhos de instalação indicados para os componentes listados na interface de usuário do instalador não são precisos e subestimam o tamanho total.

Para criar projetos Win32 com êxito na carga de trabalho de área de trabalho C++, é necessário instalar um conjunto de ferramentas e um SDK do Windows. Instalar os componentes recomendados (selecionados) **Conjunto de ferramentas do VC++ 2017 v141 (x86, x64)** e **SDK do Windows 10 (10.0.nnnnn)** garantirá que isso funcionará. Se as ferramentas necessárias não estiverem instaladas, os projetos não serão criados com êxito e o assistente parará de responder.

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

As Ferramentas de Build do Visual C++ (anteriormente disponíveis como um produto autônomo) agora estão incluídas como uma carga de trabalho no Instalador do Visual Studio. Essa carga de trabalho instala somente as ferramentas necessárias para compilar projetos C++ sem instalar o IDE do Visual Studio. Ambos os conjuntos de ferramentas v140 e v141 estão incluídos. O conjunto de ferramentas v141 contém as melhorias mais recentes do Visual Studio 2017 versão 15.5. Para obter mais informações, consulte [As Ferramentas de Build do Visual Studio agora incluem o VS2017 e Conjuntos de Ferramentas do VS2015 MSVC](https://devblogs.microsoft.com/cppblog/visual-studio-build-tools-now-include-the-vs2017-and-vs2015-msvc-toolsets/).

## <a name="linux-development-with-c"></a>Desenvolvimento de Linux com C++

A extensão popular [Visual C++ para Desenvolvimento no Linux](https://visualstudiogallery.msdn.microsoft.com/725025cf-7067-45c2-8d01-1e0fd359ae6e) agora faz parte do Visual Studio. Essa instalação fornece tudo o que você precisa para desenvolver e depurar aplicativos em C++, em execução em um ambiente Linux.

##### <a name="visual-studio-2017-version-152"></a>Visual Studio 2017 versão 15.2

Foram feitas melhorias na visualização de tipo e no compartilhamento de código multiplataforma. Para saber mais, veja [Aprimoramentos do C++ para Linux para compartilhamento de código entre plataformas e visualização de tipo](https://devblogs.microsoft.com/cppblog/linux-cross-platform-and-type-visualization/).

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

- A carga de trabalho do Linux adicionou compatibilidade com **rsync** como uma alternativa ao **sftp** para a sincronização de arquivos para computadores Linux remotos.
- Foi adicionado suporte compilação cruzada direcionada a microcontroladores ARM. Para habilitar isso na instalação, escolha a carga de trabalho **Desenvolvimento para Linux com C++** e selecione a opção para **Desenvolvimento Incorporado e de IoT**. Essa opção adiciona as ferramentas de compilação cruzada do ARM GCC e Make à sua instalação. Para obter mais informações, consulte [Compilação cruzada do ARM GCC no Visual Studio](https://devblogs.microsoft.com/cppblog/arm-gcc-cross-compilation-in-visual-studio/).
- Foi adicionado o suporte a CMake. Agora, você pode trabalhar em sua base de código existente do CMake sem precisar convertê-la em um projeto do Visual Studio. Para obter mais informações, consulte [Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md).
- Foi adicionado suporte à execução de tarefas remotas. Essa capacidade permite executar qualquer comando em um sistema remoto definido no Gerenciador de Conexões do Visual Studio. As tarefas remotas também fornecem a capacidade de copiar arquivos para o sistema remoto.
Para obter mais informações, consulte [Configurar um projeto do Linux CMake](../linux/cmake-linux-project.md).

##### <a name="visual-studio-2017-version-157"></a>Visual Studio 2017 versão 15.7

- Várias melhorias para cenários de carga de trabalho do Linux. Para obter mais informações, veja [Melhorias na carga de trabalho do Linux C++ para o Sistema de Projeto, para a Janela de Console do Linux, para rsync e para Anexar ao Processo](https://devblogs.microsoft.com/cppblog/linux-c-workload-improvements-to-the-project-system-linux-console-window-rsync-and-attach-to-process/).
- IntelliSense para cabeçalhos em conexões remotas do Linux. Para obter mais informações, veja [IntelliSense para cabeçalhos remotos do Linux](https://devblogs.microsoft.com/cppblog/intellisense-for-remote-linux-headers/) e [Configurar um projeto CMake do Linux](../linux/cmake-linux-project.md).

## <a name="game-development-with-c"></a>Desenvolvimento de jogos com C++

Use todo o poder do C++ para compilar jogos profissionais com DirectX ou Cocos2d.

## <a name="mobile-development-with-c-android-and-ios"></a>Desenvolvimento móvel com C++ (Android e iOS)

Agora, você pode criar e depurar aplicativos móveis usando o Visual Studio, que pode ser destinado ao Android e iOS.

## <a name="universal-windows-apps"></a>Aplicativos universais do Windows

O C++ é fornecido como um componente opcional para a carga de trabalho do Aplicativo Universal do Windows.  Atualmente, a atualização de projetos em C++ deve ser feita manualmente. Se abrir um projeto da UWP (Plataforma Universal do Windows) voltado ao v140 no Visual Studio 2017, será necessário selecionar o conjunto de ferramentas de plataforma v141 nas páginas de propriedades do projeto se você não tiver instalado o Visual Studio 2015.

## <a name="new-options-for-c-on-universal-windows-platform-uwp"></a>Novas opções para C++ na UWP (Plataforma Universal do Windows)

Agora você tem novas opções para gravar e empacotar aplicativos do C++ para a Plataforma Universal do Windows e para a Windows Store: você pode usar a infraestrutura de Ponte de Desktop para empacotar o objeto COM ou aplicativo da área de trabalho existente para implantação por meio da Windows Store ou por meio dos canais existentes de sideload. Novos recursos no Windows 10 permitem que você adicione a funcionalidade UWP para seu aplicativo de área de trabalho de várias maneiras. Para saber mais, veja [Ponte de Desktop](/windows/uwp/porting/desktop-to-uwp-root).

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

Foi adicionado um modelo de projeto do **Projeto de Empacotamento de Aplicativo do Windows**, que simplifica muito o empacotamento de aplicativos de área de trabalho usando a Ponte de Desktop. Ele está disponível em **Arquivo | Novo | Projeto | Instalado | Visual C++ | Plataforma Universal do Windows**. Para saber mais, veja [Empacotar um aplicativo usando o Visual Studio (Ponte de Desktop)](/windows/uwp/porting/desktop-to-uwp-packaging-dot-net).

Ao escrever código novo, você pode usar a C++/WinRT, uma projeção de linguagem C++ padrão para o Windows Runtime implementada exclusivamente em arquivos de cabeçalho. Ela permite que você crie e consuma APIs de Windows Runtime usando qualquer compilador C++ em conformidade com os padrões. A C++/WinRT foi concebida para oferecer aos desenvolvedores em C++ um acesso de primeira classe à moderna API do Windows. Para obter mais informações, consulte [ C++/WinRT: C++ moderno para o Windows Runtime](https://moderncpp.com/).

A partir do build 17025 do SDK do Windows Insider Preview, o C++/WinRT está incluído no SDK do Windows. Para obter mais informações, consulte [C++/WinRT agora está incluído no SDK do Windows](https://devblogs.microsoft.com/cppblog/cppwinrt-is-now-included-the-windows-sdk/).

## <a name="clangc2-platform-toolset"></a>Conjunto de ferramentas de plataforma Clang/C2

O conjunto de ferramentas Clang/C2 que acompanha o Visual Studio 2017 agora dá suporte à opção **/bigobj**, essencial para a criação de projetos grandes. Ele também inclui várias correções de bugs importantes, tanto em front-end quanto em back-end do compilador.

## <a name="c-code-analysis"></a>Análise de código C++

Os verificadores principais do C++ para impor as [principais diretrizes do C++](https://github.com/isocpp/CppCoreGuidelines) agora são distribuídas com o Visual Studio. Basta habilitar os verificadores na página **Extensões de Análise de Código** nas páginas de propriedades do projeto e as extensões serão incluídas quando você executar a análise de código. Para saber mais, veja [Uso dos verificadores de diretrizes de núcleo do C++](/visualstudio/code-quality/using-the-cpp-core-guidelines-checkers).

![CppCoreCheck](media/CppCoreCheck.png "Página de propriedades do CppCoreCheck")

##### <a name="visual-studio-2017-version-153"></a>Visual Studio 2017 versão 15.3

- Adicionada compatibilidade com regras relacionadas ao gerenciamento de recursos.

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

- As novas verificações das Diretrizes Principais do C++ abrangem a exatidão do ponteiro inteligente, o uso correto de inicializadores globais e os usos das sinalizações de usos de constructos como `goto` e conversões incorretas.

- Alguns números de aviso que podem ser encontrados na 15.3 não estão mais disponíveis no 15.5. Esses avisos foram substituídos por verificações mais específicas.

##### <a name="visual-studio-2017-version-156"></a>Visual Studio 2017 versão 15.6

- Suporte adicionado para análise de arquivo único e melhorias no desempenho de tempo de execução de análise. Para obter mais informações, veja [Melhorias de análise estática do C++ para Visual Studio 2017 15.6 versão prévia 2](https://devblogs.microsoft.com/cppblog/c-static-analysis-improvements-for-visual-studio-2017-15-6-preview-2/)

##### <a name="visual-studio-2017-version-157"></a>Visual Studio 2017 versão 15.7

- Suporte adicionado para [/analyze:ruleset](../build/reference/analyze-code-analysis.md), com o qual é possível especificar quais regras de análise de código são executadas.
- Suporte adicionado para regras de Diretrizes Principais do C++ adicionais.  Para saber mais, veja [Uso dos verificadores de diretrizes de núcleo do C++](/visualstudio/code-quality/using-the-cpp-core-guidelines-checkers).

## <a name="unit-testing"></a>Teste de unidade

##### <a name="visual-studio-2017-version-155"></a>Visual Studio 2017 versão 15.5

Os adaptadores do Google Test e do Boost.Test agora estão disponíveis como componentes da carga de trabalho de **Desenvolvimento para Área de Trabalho com C++** e estão integrados ao **Gerenciador de Testes**. Foi adicionado o suporte a CTest para projetos Cmake (usando Abrir Pasta), embora a integração total com o **Gerenciador de Testes** ainda não esteja disponível. Para obter mais informações, consulte [Escrevendo testes de unidade para C/C++](/visualstudio/test/writing-unit-tests-for-c-cpp).

##### <a name="visual-studio-2017-version-156"></a>Visual Studio 2017 versão 15.6

- Suporte adicionado para suporte à biblioteca dinâmica Boost.Test.
- Um modelo de item Boost.Test já está disponível no IDE.

Para obter mais informações, veja [Teste de unidade do Boost.Test: suporte à biblioteca dinâmica e novo modelo de item](https://devblogs.microsoft.com/cppblog/boost-test-unit-testing-dynamic-library-support-and-new-item-template/).

##### <a name="visual-studio-2017-version-157"></a>Visual Studio 2017 versão 15.7

Suporte de [CodeLens](/visualstudio/ide/find-code-changes-and-other-history-with-codelens) adicionado para projetos de teste de unidade do C++. Para obter mais informações, veja [Apresentação do CodeLens para teste de unidade do C++](https://devblogs.microsoft.com/cppblog/announcing-codelens-for-c-unit-testing/).

## <a name="visual-studio-graphics-diagnostics"></a>Diagnóstico de gráficos do Visual Studio

O Diagnóstico de Gráficos do Visual Studio é um conjunto de ferramentas de registro e análise de problemas de desempenho e renderização em aplicativos Direct3D. Os recursos de Diagnóstico de Gráficos podem ser usados com aplicativos em execução localmente no seu computador Windows, em um emulador de dispositivo Windows ou em um dispositivo ou computador remoto.

- **Entrada & saída para os sombreadores de vértice e de geometria:** A capacidade de exibir entrada e saída de sombreadores de vértice e sombreadores de geometria tem sido um dos recursos mais solicitados e agora tem suporte nas ferramentas. É só selecionar o estágio VS ou GS na exibição de Estágios da Pipeline para iniciar a inspeção de sua entrada e saída na tabela abaixo.

  ![Entrada/saída de sombreadores](media/io-shaders.png)

- **Pesquisa e filtro na tabela de objetos:** fornece uma maneira rápida e fácil de localizar os recursos que você está procurando.

  ![Pesquisar](media/search.png)

- **Histórico de Recursos:** esse novo modo de exibição fornece uma maneira simplificada de ver todo o histórico de modificações de um recurso, enquanto ele foi usado durante a renderização de um quadro capturado. Para invocar o histórico de qualquer recurso, basta clicar no ícone de relógio ao lado de qualquer hiperlink de recurso.

  ![Histórico de recurso](media/resource-history.png)

  Isso exibirá a nova janela de ferramentas **Histórico de Recursos**, preenchida com o histórico de alterações do recurso.

  ![Alteração de histórico do recurso](media/resource-history-change.png)

  Se o quadro for capturado com a captura de pilha de chamadas completa habilitada (**Visual Studio > Ferramentas > Opções** em **Diagnóstico de Gráficos**), o contexto de cada evento de alteração poderá ser rapidamente deduzido e inspecionado no projeto do Visual Studio.

- **Estatísticas de API:** exibir um resumo de alto nível do uso da API em seu quadro. Isso pode ser útil na descoberta de chamadas que você pode nem perceber que está fazendo ou chamadas que você está fazendo demasiadamente. Esta janela está disponível por meio de **Exibir > Estatísticas de API** no Analisador de Gráficos do Visual Studio.

  ![Estatísticas de API](media/api-stats.png)

- **Estatísticas de Memória:** exibir a quantidade de memória que o driver está alocando para os recursos que você cria no quadro. Esta janela está disponível por meio de **Exibir > Estatísticas de Memória** no **Analisador de Gráficos do Visual Studio**. Os dados podem ser copiados para um arquivo CSV para exibição em uma planilha clicando com o botão direito do mouse e escolhendo **Copiar Tudo**.

  ![Estatísticas de memória](media/memory-stats.png)

- **Validação de Quadro:** a nova lista de erros e avisos fornece uma maneira fácil de navegar em sua lista de eventos com base em problemas potenciais detectados pela camada de depuração Direct3D. Clique em **Exibir > Validação de Quadro** no Analisador de Gráficos do Visual Studio para abrir a janela. Em seguida, clique em **Executar Validação** para iniciar a análise. Pode levar vários minutos para a análise ser concluída, dependendo da complexidade do quadro.

  ![Validação de quadro](media/frame-validation.png)

- **Análise de quadros para D3D12:** Use a análise de quadros para analisar o desempenho de chamada de empate com experimentos "What-If" direcionados. Mudar para a guia de Análise de Quadros e executar uma análise para exibir o relatório. Para obter mais detalhes, assista ao vídeo [GoingNative 25: Análise de Quadros de Gráficos do Visual Studio](https://channel9.msdn.com/Shows/C9-GoingNative/GoingNative-25-Offline-Analysis-Graphics-Tool).

  ![Análise de quadro](media/frame-analysis.png)

- **Aprimoramentos de uso de GPU:** Os rastreamentos abertos podem ser obtidos por meio do criador de perfil de uso da GPU do Visual Studio com a exibição de GPU ou a ferramenta de Windows Performance Analyzer (WPA) para uma análise mais detalhada. Se você tiver o Windows Performance Toolkit instalado, haverá dois hiperlinks na parte inferior direita da visão geral da sessão: um para a WPA e outro para a Exibição de GPU.

  ![Uso de GPU](media/gpu-usage.png)

  Os rastreamentos abertos na Exibição de GPU por meio desse link oferecem suporte a aplicação de zoom e ao movimento panorâmico sincronizados na linha do tempo entre o VS e a Exibição de GPU. Uma caixa de seleção no VS é usada para controlar se a sincronização está habilitada ou não.

  ![Exibição de GPU](media/gpu-view.png)

::: moniker-end

::: moniker range="=vs-2015"

Para obter uma lista do que há de novo até o Visual Studio 2015, Atualização 3, confira [Visual C++ What's New 2003 through 2015 (Novidades do Visual C++ 2003 a 2015)](/cpp/porting/visual-cpp-what-s-new-2003-through-2015). Para saber mais sobre as novidades no Visual Studio 2015, veja as notas de versão em [Histórico de Notas de Versão do Visual Studio 2015](/visualstudio/releasenotes/vs2015-version-history). Para saber mais sobre novidades de C++ no Visual Studio 2019, confira [Novidades de C++ no Visual Studio](/cpp/overview/what-s-new-for-visual-cpp-in-visual-studio?view=vs-2019). Para saber mais sobre novidades de C++ no Visual Studio 2017, confira [Novidades de C++ no Visual Studio 2017](/cpp/overview/what-s-new-for-visual-cpp-in-visual-studio?view=vs-2017).

::: moniker-end
