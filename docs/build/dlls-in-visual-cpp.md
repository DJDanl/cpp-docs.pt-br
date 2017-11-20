---
title: DLLs no Visual C++ | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- executable files [C++]
- dynamic linking [C++]
- linking [C++], dynamic vs. static
- DLLs [C++]
- DLLs [C++], about DLLs
ms.assetid: 5216bca4-51e2-466b-b221-0e3e776056f0
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: debf3f934f7b9ad5f4c8dd337b03234cb25f7f22
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="dlls-in-visual-c"></a>DLLs no Visual C++  
  
No Windows, uma biblioteca de vínculo dinâmico (DLL) é um tipo de arquivo executável que atua como uma biblioteca compartilhada de funções e recursos. Vinculação dinâmica é um recurso de sistema operacional que permite que um executável chamar funções ou usar os recursos armazenados em um arquivo separado. Essas funções e recursos podem ser compilados e implantados separadamente dos executáveis que usá-los. Uma DLL não é um executável autônomo; ele é executado no contexto de um aplicativo que o chama. O sistema operacional pode carregar a DLL no espaço de memória do aplicativo quando o aplicativo é carregado (*vinculação implícita*), ou sob demanda em tempo de execução (*vinculando explicitamente*). DLLs também facilitam o compartilhamento de funções e recursos em executáveis. Vários aplicativos podem acessar o conteúdo de uma única cópia de uma DLL na memória ao mesmo tempo.  
  
## <a name="differences-between-dynamic-linking-and-static-linking"></a>Diferenças entre a vinculação dinâmica e a vinculação estática  
  
Vinculação estática copia todo o código de objeto em uma biblioteca estática para os executáveis que usá-la quando eles são criados. Vinculação dinâmica inclui apenas as informações necessárias pelo Windows em tempo de execução para localizar e carregar a DLL que contém um item de dados ou uma função. Quando você criar uma DLL, você também criar uma biblioteca de importação que contém essas informações. Quando você cria um executável que chama o DLL, o vinculador usa os símbolos exportados na biblioteca de importação para armazenar essas informações para o carregador do Windows. Quando o carregador carrega uma DLL, a DLL é mapeada para o espaço de memória do seu aplicativo. Se estiver presente, um especial de função na DLL, `DllMain`, é chamado para executar qualquer inicialização exige que a DLL.  
  
<a name="differences-between-applications-and-dlls"></a>  
  
## <a name="differences-between-applications-and-dlls"></a>Diferenças entre aplicativos e DLLs  
  
Apesar de DLLs e aplicativos são ambos os módulos de executáveis, elas diferem de várias maneiras. Para o usuário final, a diferença mais óbvia é DLLs não são aplicativos que podem ser executados diretamente. Do ponto de vista do sistema, há duas diferenças fundamentais entre aplicativos e DLLs:  
  
-   Um aplicativo pode ter várias instâncias em execução no sistema ao mesmo tempo, enquanto que uma DLL pode ter apenas uma instância.  
  
-   Um aplicativo pode ser carregado como um processo que pode ter elementos como uma pilha, segmentos de execução, a memória global, identificadores de arquivos e uma fila de mensagens, mas não de uma DLL.  
  
<a name="advantages-of-using-dlls"></a>  
  
## <a name="advantages-of-using-dlls"></a>Vantagens de usar DLLs  
  
Vinculação dinâmica em vez de vinculação estática de código e recursos oferece várias vantagens. Quando você usar DLLs, você pode economizar espaço de memória e reduzir a troca. Quando vários aplicativos podem usar uma única cópia de uma DLL, você pode economizar espaço em disco e faça o download de largura de banda. DLLs podem ser implantadas e atualizado separadamente, que permite que você fornecer o mercado After suporte e atualizações de software sem a necessidade de recriar e enviar todo o seu código. DLLs são uma maneira conveniente para fornecer recursos específicos da localidade, que podem oferecer suporte a vários idiomas programas e facilitam a criação de versões internacionais de seus aplicativos. Vinculando explicitamente pode permitir que seu aplicativo descobrir e carregar DLLs em tempo de execução, como extensões que fornecem novos recursos.  
  
Vinculação dinâmica tem as seguintes vantagens:  
  
-   Vinculação dinâmica economiza memória e reduz a troca. Muitos processos podem usar uma DLL simultaneamente, compartilhando uma única cópia das partes de uma DLL na memória somente leitura. Por outro lado, cada aplicativo criado usando uma biblioteca estaticamente vinculada tem uma cópia completa do código de biblioteca que o Windows deve carregar na memória.  
  
-   Vinculação dinâmica economiza largura de banda e espaço em disco. Muitos aplicativos podem compartilhar uma única cópia da DLL no disco. Por outro lado, cada aplicativo criado usando uma biblioteca de vínculo estático tem o código de biblioteca vinculado em sua imagem executável, que usa mais espaço em disco e leva mais largura de banda para transferir.  
  
-   Correções de segurança de manutenção, e os upgrades podem ser mais fácil. Quando seus aplicativos usam funções comuns em uma DLL, desde que os argumentos de função e valores de retorno não forem alterados, você pode implementar correções de bugs e implantar atualizações para a DLL. Quando DLLs são atualizadas, os aplicativos que utilizam não precisam ser recompilado ou vinculados novamente, e eles usarão a nova DLL assim que ele é implantado. Por outro lado, correções feitas no código do objeto vinculado estaticamente precisam vincular novamente e reimplantar todos os aplicativos que o utiliza.  
  
-   Você pode usar DLLs para oferecer suporte de mercado After. Por exemplo, um driver de vídeo DLL pode ser modificado para dar suporte a uma exibição que não estava disponível quando o aplicativo foi enviado. Você pode usar vinculando explicitamente ao carregar extensões de aplicativo como DLLs e adicionar novas funcionalidades ao seu aplicativo sem recriar ou reimplantação.  
  
-   Vinculação dinâmica torna mais fácil dar suporte a aplicativos escritos em linguagens de programação diferentes. Programas escritos em linguagens de programação diferentes podem chamar a mesma função DLL, contanto que os programas siga a convenção de chamada da função. Os programas e a função DLL devem ser compatíveis das seguintes maneiras: a ordem na qual a função espera os argumentos a ser inserido na pilha, se a função ou o aplicativo é responsável pela limpeza da pilha e se os argumentos são passados em registros.  
  
-   Vinculação dinâmica fornece um mecanismo para estender as classes de biblioteca do MFC. Você pode derivar de classes de classes MFC existentes e colocá-los em uma DLL de extensão do MFC para uso por aplicativos MFC.  
  
-   Vinculação dinâmica facilita a criação de versões internacionais do seu aplicativo. Colocando recursos específicos de localidade em uma DLL, é muito mais fácil de criar versões internacionais de um aplicativo. Em vez de envio de várias versões localizadas do seu aplicativo, você pode colocar as imagens para cada idioma e cadeias de caracteres em uma DLL de recurso separado e, em seguida, o aplicativo pode carregar os recursos apropriados para essa localidade em tempo de execução.   
  
 Uma desvantagem potencial para usar DLLs é que o aplicativo não é autônomo; ele depende da existência de um módulo separado de DLL que você deve implantar ou verificar por conta própria como parte de sua instalação.  
  
  
## <a name="more-information-on-how-to-create-and-use-dlls"></a>Para obter mais informações sobre como criar e usar DLLs  
  
Os tópicos a seguir fornecem informações detalhadas sobre como a DLLs do programa em Visual C++.  
  
 [Instruções passo a passo: criando e usando uma biblioteca de vínculo dinâmico (C++)](../build/walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)  
 Descreve como criar e usar uma DLL com o Visual Studio.  
  
 [Tipos de DLLs](../build/kinds-of-dlls.md)  
 Fornece informações sobre os diferentes tipos de DLLs que podem ser compilados.  
  
 [Perguntas frequentes sobre DLL](../build/dll-frequently-asked-questions.md)  
 Fornece respostas para perguntas frequentes sobre DLLs.  
  
 [Vincular um executável a uma DLL](../build/linking-an-executable-to-a-dll.md)  
 Descreve a vinculação explícita e implícita a uma DLL.  
  
 [Inicializar uma DLL](../build/run-time-library-behavior.md#initializing-a-dll)  
 Discute o código de inicialização da DLL que deve executar quando o DLL for carregada.  
  
 [Comportamento de DLLs e da biblioteca em tempo de execução do Visual C++](../build/run-time-library-behavior.md)  
 Descreve como a biblioteca em tempo de execução executa a sequência de inicialização da DLL.  
  
 [LoadLibrary e AfxLoadLibrary](../build/loadlibrary-and-afxloadlibrary.md)  
 Discute o uso de **LoadLibrary** e `AfxLoadLibrary` explicitamente vincular a uma DLL em tempo de execução.  
  
 [GetProcAddress](../build/getprocaddress.md)  
 Discute o uso de **GetProcAddress** para obter o endereço de uma função exportada na DLL.  
  
 [FreeLibrary e AfxFreeLibrary](../build/freelibrary-and-afxfreelibrary.md)  
 Discute o uso de **FreeLibrary** e `AfxFreeLibrary` quando o módulo DLL não é mais necessário.  
  
 [Caminho de pesquisa usado pelo Windows para localizar uma DLL](../build/search-path-used-by-windows-to-locate-a-dll.md)  
 Descreve o caminho de pesquisa que usa o sistema operacional Windows para localizar uma DLL no sistema.  
  
 [Estados de módulo de uma DLL MFC regular vinculada dinamicamente ao MFC](../build/module-states-of-a-regular-dll-dynamically-linked-to-mfc.md)  
 Descreve os estados de módulo de uma expressão de que dll MFC vinculada dinamicamente a MFC.  
  
 [DLLs de extensão de MFC](../build/extension-dlls-overview.md)  
 Explica as DLLs que normalmente implementam classes reutilizáveis derivadas das classes existentes da biblioteca Microsoft Foundation Class.  
  
 [Criando uma DLL somente de recurso](../build/creating-a-resource-only-dll.md)  
 Descreve uma DLL somente de recurso, que contém apenas recursos, como ícones, bitmaps, cadeias de caracteres e caixas de diálogo.  
  
 [Recursos localizados em aplicativos MFC: DLLs satélites](../build/localized-resources-in-mfc-applications-satellite-dlls.md)  
 Fornece suporte avançado para DLLs satélite, um recurso que ajuda na criação de aplicativos localizados para vários idiomas.  
  
 [Importando e exportando](../build/importing-and-exporting.md)  
 Descreve a importação de símbolos públicos para um aplicativo ou a exportação de funções de uma DLL  
  
 [Tecnologia ativa e DLLs](../build/active-technology-and-dlls.md)  
 Permite que os servidores de objeto a ser implementada dentro de uma DLL.  
  
 [Automação em uma DLL](../build/automation-in-a-dll.md)  
 Descreve o que a opção de automação no assistente de DLL do MFC fornece.  
  
 [Convenções de nomenclatura para DLLs do MFC](../build/naming-conventions-for-mfc-dlls.md)  
 Discute como as DLLs e as bibliotecas incluídas no MFC seguem uma convenção de nomenclatura estruturada.  
  
 [Chamando funções DLL a partir de aplicativos do Visual Basic](../build/calling-dll-functions-from-visual-basic-applications.md)  
 Descreve como chamar funções de DLL a partir de aplicativos do Visual Basic.  
  
## <a name="related-sections"></a>Seções relacionadas  
  
 [Usando MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)  
 Descreve a DLLs normais do MFC, que permitem que você use a biblioteca do MFC como parte de uma biblioteca de vínculo dinâmico do Windows.  
  
 [Versão de DLL do MFC](../mfc/tn033-dll-version-of-mfc.md)  
 Descreve como você pode usar o MFCxx.dll e MFCxxD.dll (onde x é o número de versão do MFC) compartilhado bibliotecas de vínculo dinâmico com aplicativos MFC e DLLs de extensão do MFC.  
