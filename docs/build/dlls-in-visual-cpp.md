---
title: Criar C/C++ DLLs no Visual Studio
ms.date: 07/18/2019
helpviewer_keywords:
- executable files [C++]
- dynamic linking [C++]
- linking [C++], dynamic vs. static
- DLLs [C++]
- DLLs [C++], about DLLs
ms.assetid: 5216bca4-51e2-466b-b221-0e3e776056f0
ms.openlocfilehash: 33f002143e306c99b4d17b7a01ddd4a9738e38e7
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69493283"
---
# <a name="create-cc-dlls-in-visual-studio"></a>Criar C/C++ DLLs no Visual Studio

No Windows, uma DLL (biblioteca de vínculo dinâmico) é um tipo de arquivo executável que atua como uma biblioteca compartilhada de funções e recursos. A vinculação dinâmica é uma funcionalidade do sistema operacional que permite que um executável chame funções ou use recursos armazenados em um arquivo separado. Essas funções e recursos podem ser compilados e implantados separadamente dos executáveis que os usam. Uma DLL não é um executável autônomo; Ele é executado no contexto de um aplicativo que o chama. O sistema operacional pode carregar a DLL no espaço de memória de um aplicativo quando o aplicativo é carregado (*vinculação implícita*) ou sob demanda em tempo de execução (*vinculação explícita*). As DLLs também facilitam o compartilhamento de funções e recursos entre executáveis. Vários aplicativos podem acessar o conteúdo de uma única cópia de uma DLL na memória ao mesmo tempo.

## <a name="differences-between-dynamic-linking-and-static-linking"></a>Diferenças entre vinculação dinâmica e vinculação estática

A vinculação estática copia todo o código de objeto em uma biblioteca estática para os executáveis que o utilizam quando são criados. A vinculação dinâmica inclui apenas as informações necessárias para o Windows em tempo de execução para localizar e carregar a DLL que contém um item de dados ou uma função. Ao criar uma DLL, você também cria uma biblioteca de importação que contém essas informações. Quando você cria um executável que chama a DLL, o vinculador usa os símbolos exportados na biblioteca de importação para armazenar essas informações para o carregador do Windows. Quando o carregador carrega uma DLL, a DLL é mapeada para o espaço de memória do seu aplicativo. Se estiver presente, uma função especial na dll `DllMain`,, será chamada para executar qualquer inicialização que a dll exigir.

<a name="differences-between-applications-and-dlls"></a>

## <a name="differences-between-applications-and-dlls"></a>Diferenças entre aplicativos e DLLs

Embora DLLs e aplicativos sejam ambos módulos executáveis, eles diferem de várias maneiras. Para o usuário final, a diferença mais óbvia é que DLLs não são aplicativos que podem ser executados diretamente. Do ponto de vista do sistema, há duas diferenças fundamentais entre aplicativos e DLLs:

- Um aplicativo pode ter várias instâncias de execução no sistema simultaneamente, enquanto uma DLL pode ter apenas uma instância.

- Um aplicativo pode ser carregado como um processo que pode ter coisas como uma pilha, threads de execução, memória global, identificadores de arquivo e uma fila de mensagens, mas uma DLL não pode.

<a name="advantages-of-using-dlls"></a>

## <a name="advantages-of-using-dlls"></a>Vantagens de usar DLLs

A vinculação dinâmica ao código e aos recursos oferece várias vantagens em relação à vinculação estática:

- A vinculação dinâmica economiza memória e reduz a troca. Muitos processos podem usar uma DLL simultaneamente, compartilhando uma única cópia das partes somente leitura de uma DLL na memória. Por outro lado, cada aplicativo criado usando uma biblioteca vinculada estaticamente tem uma cópia completa do código de biblioteca que o Windows deve carregar na memória.

- A vinculação dinâmica economiza espaço em disco e largura de banda. Muitos aplicativos podem compartilhar uma única cópia da DLL no disco. Por outro lado, cada aplicativo criado usando uma biblioteca de vínculo estático tem o código de biblioteca vinculado à sua imagem executável, que usa mais espaço em disco e leva mais largura de banda para transferir.

- Manutenção, correções de segurança e atualizações podem ser mais fáceis. Quando seus aplicativos usam funções comuns em uma DLL, desde que os argumentos da função e os valores de retorno não sejam alterados, você pode implementar correções de bugs e implantar atualizações na DLL. Quando as DLLs são atualizadas, os aplicativos que as usam não precisam ser recompilados ou revinculados e usam a nova DLL assim que ela é implantada. Por outro lado, as correções feitas no código de objeto vinculado estaticamente exigem que você vincule novamente e reimplante todos os aplicativos que o utilizam.

- Você pode usar DLLs para fornecer suporte após o mercado. Por exemplo, uma DLL de driver de vídeo pode ser modificada para dar suporte a uma exibição que não estava disponível quando o aplicativo foi enviado.

- Você pode usar a vinculação explícita para descobrir e carregar DLLS em tempo de execução, como extensões de aplicativo que adicionam nova funcionalidade ao seu aplicativo sem recompilar ou reimplantá-lo.

- A vinculação dinâmica torna mais fácil dar suporte a aplicativos escritos em linguagens de programação diferentes. Programas escritos em linguagens de programação diferentes podem chamar a mesma função de DLL, desde que os programas sigam a Convenção de chamada da função. Os programas e a função DLL devem ser compatíveis das seguintes maneiras: a ordem na qual a função espera que seus argumentos sejam enviados por push para a pilha, independentemente de a função ou o aplicativo ser responsável por limpar a pilha e se os argumentos são passados em registros.

- A vinculação dinâmica fornece um mecanismo para estender as classes de biblioteca do MFC. Você pode derivar classes das classes existentes do MFC e colocá-las em uma DLL de extensão do MFC para uso por aplicativos do MFC.

- A vinculação dinâmica torna a criação de versões internacionais do seu aplicativo mais fácil. As DLLs são uma maneira conveniente de fornecer recursos específicos à localidade, o que torna muito mais fácil criar versões internacionais de um aplicativo. Em vez de enviar muitas versões localizadas do seu aplicativo, você pode posicionar as cadeias de caracteres e as imagens de cada idioma em uma DLL de recurso separada e, em seguida, o aplicativo pode carregar os recursos apropriados para essa localidade em tempo de execução.

Uma desvantagem potencial de usar DLLs é que o aplicativo não é independente; depende da existência de um módulo DLL separado que você deve implantar ou verificar como parte de sua instalação.

## <a name="more-information-on-how-to-create-and-use-dlls"></a>Mais informações sobre como criar e usar DLLs

Os tópicos a seguir fornecem informações detalhadas sobre como criar C/C++ DLLs no Visual Studio.

[Passo a passo: Criando e usando uma biblioteca de vínculo dinâmico (C++)](walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)<br/>
Descreve como criar e usar uma DLL com o Visual Studio.

[Tipos de DLLs](kinds-of-dlls.md)<br/>
Fornece informações sobre os diferentes tipos de DLLs que podem ser compilados.

[Perguntas frequentes sobre DLL](dll-frequently-asked-questions.md)<br/>
Fornece respostas para perguntas frequentes sobre DLLs.

[Vincular um executável a uma DLL](linking-an-executable-to-a-dll.md)<br/>
Descreve a vinculação explícita e implícita a uma DLL.

[Inicializar uma DLL](run-time-library-behavior.md#initializing-a-dll)<br/>
Discute o código de inicialização de DLL que deve ser executado quando sua DLL é carregada.

[Comportamento de DLLs e da biblioteca em tempo de execução do Visual C++](run-time-library-behavior.md)<br/>
Descreve como a biblioteca em tempo de execução executa a sequência de inicialização da DLL.

[LoadLibrary e AfxLoadLibrary](loadlibrary-and-afxloadlibrary.md)<br/>
Discute o uso de LoadLibrary `AfxLoadLibrary` e a vinculação explícita a uma dll em tempo de execução.

[GetProcAddress](getprocaddress.md)<br/>
Discute o uso de **GetProcAddress** para obter o endereço de uma função exportada na dll.

[FreeLibrary e AfxFreeLibrary](freelibrary-and-afxfreelibrary.md)<br/>
Discute o uso de FreeLibrary `AfxFreeLibrary` e quando o módulo DLL não é mais necessário.

[Ordem de pesquisa da biblioteca de vínculo dinâmico](/windows/win32/Dlls/dynamic-link-library-search-order)<br/>
Descreve o caminho de pesquisa que o sistema operacional Windows usa para localizar uma DLL no sistema.

[Estados de módulo de uma DLL MFC regular vinculada dinamicamente ao MFC](module-states-of-a-regular-dll-dynamically-linked-to-mfc.md)<br/>
Descreve os Estados de módulo de uma DLL do MFC regular vinculada dinamicamente ao MFC.

[DLLs de extensão de MFC](extension-dlls-overview.md)<br/>
Explica as DLLs que normalmente implementam classes reutilizáveis derivadas das classes existentes da biblioteca Microsoft Foundation Class.

[Criando uma DLL somente de recurso](creating-a-resource-only-dll.md)<br/>
Descreve uma DLL somente de recurso, que contém apenas recursos, como ícones, bitmaps, cadeias de caracteres e caixas de diálogo.

[Recursos localizados em aplicativos MFC: DLLs satélites](localized-resources-in-mfc-applications-satellite-dlls.md)<br/>
Fornece suporte avançado para DLLs satélite, um recurso que ajuda na criação de aplicativos localizados para vários idiomas.

[Importando e exportando](importing-and-exporting.md)<br/>
Descreve a importação de símbolos públicos para um aplicativo ou a exportação de funções de uma DLL

[Tecnologia ativa e DLLs](active-technology-and-dlls.md)<br/>
Permite que os servidores de objetos sejam implementados dentro de uma DLL.

[Automação em uma DLL](automation-in-a-dll.md)<br/>
Descreve o que a opção de automação no assistente de DLL do MFC fornece.

[Convenções de nomenclatura para DLLs do MFC](../mfc/mfc-library-versions.md#mfc-static-library-naming-conventions)<br/>
Discute como as DLLs e as bibliotecas incluídas no MFC seguem uma convenção de nomenclatura estruturada.

[Chamando funções de DLL de aplicativos Visual Basic](calling-dll-functions-from-visual-basic-applications.md)<br/>
Descreve como chamar funções de DLL a partir de aplicativos do Visual Basic.

## <a name="related-sections"></a>Seções relacionadas

[Usando o MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)<br/>
Descreve as DLLs do MFC regulares, que permitem usar a biblioteca do MFC como parte de uma biblioteca de vínculo dinâmico do Windows.

[Versão da DLL do MFC](../mfc/tn033-dll-version-of-mfc.md)<br/>
Descreve como você pode usar o MFCxx. dll e o MFCxxD. dll (onde x é o número de versão do MFC) bibliotecas de vínculo dinâmico compartilhado com aplicativos MFC e DLLs de extensão MFC.
