---
title: Criar C/C++ DLLs no Visual Studio
description: Uma visão geral de como e como criar e usar DLLs com C++ o no Visual Studio.
ms.date: 01/27/2020
helpviewer_keywords:
- executable files [C++]
- dynamic linking [C++]
- linking [C++], dynamic vs. static
- DLLs [C++]
- DLLs [C++], about DLLs
ms.assetid: 5216bca4-51e2-466b-b221-0e3e776056f0
ms.openlocfilehash: 7083924f137fa9283da40404c7d15183e59c0b1c
ms.sourcegitcommit: b8c22e6d555cf833510753cba7a368d57e5886db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/29/2020
ms.locfileid: "76821415"
---
# <a name="create-cc-dlls-in-visual-studio"></a>Criar C/C++ DLLs no Visual Studio

No Windows, uma DLL (biblioteca de vínculo dinâmico) é um tipo de arquivo executável que atua como uma biblioteca compartilhada de funções e recursos. A vinculação dinâmica é uma funcionalidade do sistema operacional. Ele permite que um executável chame funções ou use recursos armazenados em um arquivo separado. Essas funções e recursos podem ser compilados e implantados separadamente dos executáveis que os usam.

Uma DLL não é um executável autônomo. As DLLs são executadas no contexto dos aplicativos que as chamam. O sistema operacional carrega a DLL no espaço de memória de um aplicativo. Isso é feito quando o aplicativo é carregado (*vinculação implícita*) ou sob demanda em tempo de execução (*vinculação explícita*). As DLLs também facilitam o compartilhamento de funções e recursos entre executáveis. Vários aplicativos podem acessar o conteúdo de uma única cópia de uma DLL na memória ao mesmo tempo.

## <a name="differences-between-dynamic-linking-and-static-linking"></a>Diferenças entre vinculação dinâmica e vinculação estática

A vinculação estática copia todo o código de objeto em uma biblioteca estática para os executáveis que o utilizam quando são criados. A vinculação dinâmica inclui apenas as informações necessárias para o Windows em tempo de execução para localizar e carregar a DLL que contém um item de dados ou uma função. Ao criar uma DLL, você também cria uma biblioteca de importação que contém essas informações. Quando você cria um executável que chama a DLL, o vinculador usa os símbolos exportados na biblioteca de importação para armazenar essas informações para o carregador do Windows. Quando o carregador carrega uma DLL, a DLL é mapeada para o espaço de memória do seu aplicativo. Se estiver presente, uma função especial na DLL, `DllMain`, será chamada para fazer qualquer inicialização que a DLL exigir.

<a name="differences-between-applications-and-dlls"></a>

## <a name="differences-between-applications-and-dlls"></a>Diferenças entre aplicativos e DLLs

Embora DLLs e aplicativos sejam ambos módulos executáveis, eles diferem de várias maneiras. A diferença mais óbvia é que você não pode executar uma DLL. Do ponto de vista do sistema, há duas diferenças fundamentais entre aplicativos e DLLs:

- Um aplicativo pode ter várias instâncias de execução no sistema simultaneamente. Uma DLL pode ter apenas uma instância.

- Um aplicativo pode ser carregado como um processo. Ele pode ter coisas como uma pilha, threads de execução, memória global, identificadores de arquivo e uma fila de mensagens. Uma DLL não pode possuir essas coisas.

<a name="advantages-of-using-dlls"></a>

## <a name="advantages-of-using-dlls"></a>Vantagens de usar DLLs

A vinculação dinâmica ao código e aos recursos oferece várias vantagens em relação à vinculação estática:

- A vinculação dinâmica economiza memória e reduz a troca. Muitos processos podem usar uma DLL simultaneamente, compartilhando uma única cópia das partes somente leitura de uma DLL na memória. Por outro lado, cada aplicativo criado usando uma biblioteca vinculada estaticamente tem uma cópia completa do código de biblioteca que o Windows deve carregar na memória.

- A vinculação dinâmica economiza espaço em disco e largura de banda. Muitos aplicativos podem compartilhar uma única cópia da DLL no disco. Por outro lado, cada aplicativo criado usando uma biblioteca de vínculo estático tem o código de biblioteca vinculado à sua imagem executável. Isso usa mais espaço em disco e leva mais largura de banda para transferir.

- A manutenção, as correções de segurança e as atualizações podem ser mais fáceis. Quando seus aplicativos usam funções comuns em uma DLL, você pode implementar correções de bugs e implantar atualizações na DLL. Quando as DLLs são atualizadas, os aplicativos que as usam não precisam ser recompilados ou vinculados novamente. Eles podem fazer uso da nova DLL assim que ela é implantada. Por outro lado, quando você faz correções no código de objeto vinculado estaticamente, você deve vincular novamente e reimplantar todos os aplicativos que o utilizam.

- Você pode usar DLLs para fornecer suporte após o mercado. Por exemplo, uma DLL de driver de vídeo pode ser modificada para dar suporte a uma exibição que não estava disponível quando o aplicativo foi enviado.

- Você pode usar a vinculação explícita para descobrir e carregar DLLs em tempo de execução. Por exemplo, extensões de aplicativo que adicionam nova funcionalidade ao seu aplicativo sem recompilar ou reimplantá-lo.

- A vinculação dinâmica torna mais fácil dar suporte a aplicativos escritos em linguagens de programação diferentes. Programas escritos em linguagens de programação diferentes podem chamar a mesma função de DLL, desde que os programas sigam a Convenção de chamada da função. Os programas e a função DLL devem ser compatíveis das seguintes maneiras: a ordem na qual a função espera que seus argumentos sejam enviados para a pilha. Se a função ou o aplicativo é responsável por limpar a pilha. E se os argumentos são passados em registros.

- A vinculação dinâmica fornece um mecanismo para estender as classes da Microsoft Foundation Class Library (MFC). Você pode derivar classes das classes existentes do MFC e colocá-las em uma DLL de extensão do MFC para uso por aplicativos do MFC.

- A vinculação dinâmica torna a criação de versões internacionais do seu aplicativo mais fácil. As DLLs são uma maneira conveniente de fornecer recursos específicos à localidade, o que torna muito mais fácil criar versões internacionais de um aplicativo. Em vez de enviar muitas versões localizadas do seu aplicativo, você pode posicionar as cadeias de caracteres e as imagens de cada idioma em uma DLL de recurso separada. Em seguida, seu aplicativo pode carregar os recursos apropriados para essa localidade no tempo de execução.

Uma desvantagem potencial de usar DLLs é que o aplicativo não é independente. Depende da existência de um módulo DLL separado: um que você deve implantar ou verificar como parte de sua instalação.

## <a name="more-information-on-how-to-create-and-use-dlls"></a>Mais informações sobre como criar e usar DLLs

Os artigos a seguir fornecem informações detalhadas sobre como criar C/C++ DLLs no Visual Studio.

[Walkthrough: Criando e usando uma biblioteca de vínculo dinâmicoC++()](walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)\
Descreve como criar e usar uma DLL com o Visual Studio.

[Tipos de DLLs](kinds-of-dlls.md)\
Fornece informações sobre os diferentes tipos de DLLs que podem ser compilados.

[Perguntas](dll-frequently-asked-questions.md) frequentes do DLL\
Fornece respostas para perguntas frequentes sobre DLLs.

[Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md)\
Descreve a vinculação explícita e implícita a uma DLL.

[Inicializar uma DLL](run-time-library-behavior.md#initializing-a-dll)\
Discute o código de inicialização de DLL que deve ser executado quando sua DLL é carregada.

[DLLs e comportamento C++ de biblioteca de tempo de execução Visual](run-time-library-behavior.md)\
Descreve a sequência de inicialização da DLL da biblioteca de tempo de execução.

[LoadLibrary e AfxLoadLibrary](loadlibrary-and-afxloadlibrary.md)\
Discute o uso de `LoadLibrary` e `AfxLoadLibrary` para vincular explicitamente a uma DLL em tempo de execução.

\ de [GetProcAddress](getprocaddress.md)
Discute o uso de `GetProcAddress` para obter o endereço de uma função exportada na DLL.

[FreeLibrary e AfxFreeLibrary](freelibrary-and-afxfreelibrary.md)\
Discute o uso de `FreeLibrary` e `AfxFreeLibrary` quando o módulo DLL não é mais necessário.

\ [de ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-search-order)
Descreve o caminho de pesquisa que o sistema operacional Windows usa para localizar uma DLL no sistema.

[Estados de módulo de uma DLL de MFC regular vinculada dinamicamente ao MFC](module-states-of-a-regular-dll-dynamically-linked-to-mfc.md)\
Descreve os Estados de módulo de uma DLL do MFC regular vinculada dinamicamente ao MFC.

[DLLs de extensão do MFC](extension-dlls-overview.md)\
Explica DLLs que normalmente implementam classes reutilizáveis derivadas das classes existentes do MFC.

[Criando uma DLL somente de recursos](creating-a-resource-only-dll.md)\
Descreve uma DLL somente de recurso, que contém apenas recursos, como ícones, bitmaps, cadeias de caracteres e caixas de diálogo.

[Recursos localizados em aplicativos do MFC: DLLs satélite](localized-resources-in-mfc-applications-satellite-dlls.md)\
Fornece suporte avançado para DLLs satélite, um recurso que ajuda na criação de aplicativos localizados para vários idiomas.

[Importando e exportando](importing-and-exporting.md)\
Descreve a importação de símbolos públicos para um aplicativo ou a exportação de funções de uma DLL

\ [de tecnologia e DLLs ativas](active-technology-and-dlls.md)
Permite que os servidores de objetos sejam implementados dentro de uma DLL.

[Automação em uma DLL](automation-in-a-dll.md)\
Descreve o que a opção de automação no assistente de DLL do MFC fornece.

[Convenções de nomenclatura para DLLs do MFC](../mfc/mfc-library-versions.md#mfc-static-library-naming-conventions)\
Discute como as DLLs e as bibliotecas incluídas no MFC seguem uma convenção de nomenclatura estruturada.

[Chamando funções de DLL de aplicativos Visual Basic](calling-dll-functions-from-visual-basic-applications.md)\
Descreve como chamar funções de DLL a partir de aplicativos do Visual Basic.

## <a name="related-sections"></a>Seções Relacionadas

[Usando o MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)\
Descreve as DLLs do MFC regulares, que permitem usar a biblioteca do MFC como parte de uma biblioteca de vínculo dinâmico do Windows.

[Versão de DLL do MFC](../mfc/tn033-dll-version-of-mfc.md)\
Descreve como você pode usar o MFCxx. dll e o MFCxxD. dll (onde x é o número de versão do MFC) bibliotecas de vínculo dinâmico compartilhado com aplicativos MFC e DLLs de extensão MFC.
