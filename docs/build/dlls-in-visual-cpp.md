---
title: Criar DLLs de C/C++ no Visual Studio
ms.date: 05/06/2019
helpviewer_keywords:
- executable files [C++]
- dynamic linking [C++]
- linking [C++], dynamic vs. static
- DLLs [C++]
- DLLs [C++], about DLLs
ms.assetid: 5216bca4-51e2-466b-b221-0e3e776056f0
ms.openlocfilehash: 7f1c2b71a58c59bf0662aa4ffec53344ce657df0
ms.sourcegitcommit: da32511dd5baebe27451c0458a95f345144bd439
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2019
ms.locfileid: "65220752"
---
# <a name="create-cc-dlls-in-visual-studio"></a>Criar DLLs de C/C++ no Visual Studio

No Windows, uma biblioteca de vínculo dinâmico (DLL) é um tipo de arquivo executável que atua como uma biblioteca compartilhada de funções e recursos. A vinculação dinâmica é um recurso de sistema operacional que permite que um executável chamar funções ou usar os recursos armazenados em um arquivo separado. Essas funções e recursos podem ser compilados e implantados separadamente dos executáveis que usá-los. Uma DLL não é um executável autônomo; ele é executado no contexto de um aplicativo que o chama. O sistema operacional pode carregar a DLL no espaço de memória do aplicativo quando o aplicativo é carregado (*vinculação implícita*), ou sob demanda no tempo de execução (*vinculação explícita*). DLLs também facilitam a compartilhar funções e recursos em executáveis. Vários aplicativos podem acessar o conteúdo de uma única cópia de uma DLL na memória ao mesmo tempo.

## <a name="differences-between-dynamic-linking-and-static-linking"></a>Diferenças entre a vinculação dinâmica e a vinculação estática

Vinculação estática copia todo o código de objeto em uma biblioteca estática para os executáveis que usá-lo quando eles são criados. A vinculação dinâmica inclui apenas as informações necessárias para o Windows em tempo de execução para localizar e carregar a DLL que contém um item de dados ou uma função. Quando você cria uma DLL, você também criar uma biblioteca de importação que contém essas informações. Quando você compila um executável que chama a DLL, o vinculador usa símbolos exportados na biblioteca de importação para armazenar essas informações para o carregador do Windows. Quando o carregador carrega uma DLL, a DLL é mapeada no espaço de memória do seu aplicativo. Se estiver presente, um especial de função na DLL, `DllMain`, é chamado para realizar qualquer inicialização exige que a DLL.

<a name="differences-between-applications-and-dlls"></a>

## <a name="differences-between-applications-and-dlls"></a>Diferenças entre aplicativos e DLLs

Mesmo que os aplicativos e DLLs são os dois módulos executáveis, eles diferem de várias maneiras. Para o usuário final, a diferença mais óbvia é que as DLLs não são aplicativos que podem ser executados diretamente. Do ponto de vista do sistema, há duas diferenças fundamentais entre aplicativos e DLLs:

- Um aplicativo pode ter várias instâncias de si mesmo em execução no sistema ao mesmo tempo, enquanto que uma DLL pode ter apenas uma instância.

- Um aplicativo pode ser carregado como um processo que pode ter coisas como uma pilha, segmentos de execução, memória global, identificadores de arquivos e uma fila de mensagens, mas não de uma DLL.

<a name="advantages-of-using-dlls"></a>

## <a name="advantages-of-using-dlls"></a>Vantagens de usar DLLs

Vinculação dinâmica em vez de vinculação estática de código e recursos oferece diversas vantagens. Quando você usa DLLs, você pode economizar espaço de memória e reduzem as trocas. Quando vários aplicativos podem usar uma única cópia de uma DLL, você pode economizar espaço em disco e fazer o download de largura de banda. DLLs podem ser implantadas e atualizados separadamente, que permite que você fornecer atualizações de software e suporte pós-mercado sem ter que recompilar e enviar todo o seu código. DLLs são uma maneira conveniente de fornecer recursos específicos da localidade, que podem oferecer suporte a vários idiomas programas e facilitar a criação de versões internacionais dos seus aplicativos. A vinculação explícita pode permitir que seu aplicativo descobrir e carregar DLLs em tempo de execução, como extensões que fornecem novos recursos.

A vinculação dinâmica tem as seguintes vantagens:

- Vinculação dinâmica economiza memória e reduz a troca. Muitos processos podem usar uma DLL simultaneamente, compartilhando uma única cópia de partes de uma DLL na memória somente leitura. Por outro lado, cada aplicativo que é criado usando uma biblioteca vinculada estaticamente tem uma cópia completa do código de biblioteca Windows devem carregar na memória.

- A vinculação dinâmica economiza largura de banda e espaço em disco. Muitos aplicativos podem compartilhar uma única cópia da DLL no disco. Por outro lado, cada aplicativo criado usando uma biblioteca de vínculo estático tem o código de biblioteca vinculado a sua imagem executável, que usa mais espaço em disco e leva mais largura de banda para transferir.

- Correções de segurança de manutenção, e os upgrades podem ser mais fácil. Quando seus aplicativos usam funções comuns em uma DLL, em seguida, desde que os argumentos de função e valores de retorno não alterar, você pode implementar correções de bugs e implantar atualizações para a DLL. Quando DLLs são atualizadas, os aplicativos que utilizam não precisarão ser recompilado ou vinculados novamente, e eles usarem a nova DLL assim que ele é implantado. Em contraste, correções feitas no código do objeto vinculado estaticamente exigem que você vincule novamente e reimplantar todos os aplicativos que o utiliza.

- Você pode usar DLLs para fornecer suporte pós-mercado. Por exemplo, um DLL do driver de vídeo pode ser modificado para dar suporte a uma exibição que não estava disponível quando o aplicativo foi enviado. Você pode usar a vinculação explícita ao carregar extensões de aplicativo como DLLs e adicionar novas funcionalidades ao seu aplicativo sem recompilar ou reimplantá-lo.

- A vinculação dinâmica torna mais fácil dar suporte a aplicativos escritos em linguagens de programação diferentes. Programas escritos em linguagens de programação diferentes podem chamar a mesma função DLL, contanto que os programas siga a convenção de chamada da função. Os programas e a função DLL devem ser compatíveis das seguintes maneiras: a ordem na qual a função espera que seus argumentos para ser enviado para a pilha, se a função ou o aplicativo é responsável pela limpeza da pilha e se os argumentos são passados em registros.

- A vinculação dinâmica fornece um mecanismo para estender as classes de biblioteca MFC. Você pode derivar classes de classes existentes do MFC e colocá-los em uma DLL de extensão MFC para uso por aplicativos do MFC.

- A vinculação dinâmica facilita a criação de versões internacionais do seu aplicativo. Ao colocar recursos específicos da localidade em uma DLL, é muito mais fácil criar versões internacionais de um aplicativo. Em vez de envio de várias versões localizadas do seu aplicativo, você pode colocar as imagens para cada idioma e cadeias de caracteres em uma DLL de recursos separado e, em seguida, o aplicativo possa carregar os recursos apropriados para essa localidade em tempo de execução.

Uma desvantagem em potencial do uso de DLLs é que o aplicativo não é autônomo; ele depende da existência de um módulo DLL separada que você deve implantar ou verificar por conta própria como parte de sua instalação.

## <a name="more-information-on-how-to-create-and-use-dlls"></a>Para obter mais informações sobre como criar e usar DLLs

Os tópicos a seguir fornecem informações detalhadas sobre como criar C /C++ DLLs no Visual Studio.

[Passo a passo: Criando e usando uma biblioteca de vínculo dinâmico (C++)](walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)<br/>
Descreve como criar e usar uma DLL com o Visual Studio.

[Tipos de DLLs](kinds-of-dlls.md)<br/>
Fornece informações sobre os diferentes tipos de DLLs que podem ser compilados.

[Perguntas frequentes sobre DLL](dll-frequently-asked-questions.md)<br/>
Fornece respostas para perguntas frequentes sobre DLLs.

[Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md)<br/>
Descreve a vinculação explícita e implícita a uma DLL.

[Inicialize um DLL](run-time-library-behavior.md#initializing-a-dll)<br/>
Discute o código de inicialização da DLL que deve ser executado quando a DLL é carregada.

[Comportamento de DLLs e da biblioteca em tempo de execução do Visual C++](run-time-library-behavior.md)<br/>
Descreve como a biblioteca em tempo de execução executa a sequência de inicialização da DLL.

[LoadLibrary e AfxLoadLibrary](loadlibrary-and-afxloadlibrary.md)<br/>
Discute o uso **LoadLibrary** e `AfxLoadLibrary` para vincular explicitamente para uma DLL em tempo de execução.

[GetProcAddress](getprocaddress.md)<br/>
Discute o uso **GetProcAddress** para obter o endereço de uma função exportada na DLL.

[FreeLibrary e AfxFreeLibrary](freelibrary-and-afxfreelibrary.md)<br/>
Discute o uso **FreeLibrary** e `AfxFreeLibrary` quando o módulo DLL não é mais necessário.

[Ordem de pesquisa de biblioteca de vínculo dinâmico](/windows/desktop/Dlls/dynamic-link-library-search-order)<br/>
Descreve o caminho de pesquisa que o sistema operacional Windows usa para localizar uma DLL no sistema.

[Estados de módulo de uma DLL MFC regular vinculada dinamicamente ao MFC](module-states-of-a-regular-dll-dynamically-linked-to-mfc.md)<br/>
Descreve os estados de módulo de uma expressão de que DLL do MFC vinculada dinamicamente ao MFC.

[DLLs de extensão de MFC](extension-dlls-overview.md)<br/>
Explica as DLLs que normalmente implementam classes reutilizáveis derivadas das classes existentes da biblioteca Microsoft Foundation Class.

[Criando uma DLL somente de recurso](creating-a-resource-only-dll.md)<br/>
Descreve uma DLL somente de recurso, que contém apenas recursos, como ícones, bitmaps, cadeias de caracteres e caixas de diálogo.

[Recursos localizados em aplicativos MFC: DLLs satélites](localized-resources-in-mfc-applications-satellite-dlls.md)<br/>
Fornece suporte avançado para DLLs satélite, um recurso que ajuda na criação de aplicativos localizados para vários idiomas.

[Importando e exportando](importing-and-exporting.md)<br/>
Descreve a importação de símbolos públicos para um aplicativo ou a exportação de funções de uma DLL

[Tecnologia ativa e DLLs](active-technology-and-dlls.md)<br/>
Permite que os servidores de objeto a ser implementada dentro de uma DLL.

[Automação em uma DLL](automation-in-a-dll.md)<br/>
Descreve o que a opção de automação no assistente de DLL do MFC fornece.

[Convenções de nomenclatura para DLLs do MFC](../mfc/mfc-library-versions.md#mfc-static-library-naming-conventions)<br/>
Discute como as DLLs e as bibliotecas incluídas no MFC seguem uma convenção de nomenclatura estruturada.

[Chamando funções DLL a partir de aplicativos do Visual Basic](calling-dll-functions-from-visual-basic-applications.md)<br/>
Descreve como chamar funções de DLL a partir de aplicativos do Visual Basic.

## <a name="related-sections"></a>Seções relacionadas

[Usando MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)<br/>
Descreve DLLs normais do MFC, que permitem que você use a biblioteca do MFC como parte de uma biblioteca de vínculo dinâmico do Windows.

[Versão DLL do MFC](../mfc/tn033-dll-version-of-mfc.md)<br/>
Descreve como você pode usar o compartilhadas e Mfcxxd (onde x é o número de versão do MFC) compartilhado bibliotecas de vínculo dinâmico com aplicativos do MFC e DLLs de extensão do MFC.
