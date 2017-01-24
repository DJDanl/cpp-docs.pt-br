---
title: "DLLs no Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "DLLs [C++]"
  - "DLLs [C++], sobre DLLs"
  - "vinculação dinâmica [C++]"
  - "arquivos executáveis [C++]"
  - "vinculando [C++], dinâmica vs. estática"
ms.assetid: 5216bca4-51e2-466b-b221-0e3e776056f0
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# DLLs no Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma biblioteca de vínculo dinâmico \(DLL\) é um arquivo executável que atua como uma biblioteca compartilhada de funções e recursos.  Vinculação dinâmica permite um executável chamar funções ou usar recursos armazenados em um arquivo separado.  Essas funções e recursos podem ser compilados e implantados separadamente dos executáveis que usá\-las.  O sistema operacional pode carregar a DLL no espaço de memória do executável quando o executável for carregado ou sob demanda no tempo de execução.  DLLs também facilitam a compartilhar funções e recursos em executáveis.  Vários aplicativos podem acessar o conteúdo de uma única cópia de uma DLL na memória ao mesmo tempo.  
  
 Cópias de vinculação estáticas de todo o objeto código em um arquivo em um executável.  Vinculação dinâmica inclui apenas as informações necessárias em tempo de execução para localizar e carregar a DLL que contém um item de dados ou uma função.  Quando você cria uma DLL, você também criar um arquivo que contém essas informações.  Quando você cria um executável que chama a DLL, o vinculador usa símbolos exportados no arquivo. lib para armazenar essas informações para o carregador.  Quando o carregador carrega uma DLL, a DLL é mapeada no espaço de memória do executável.  Uma função especial na DLL,`DllMain`é chamado para realizar qualquer inicialização requer a DLL.  
  
 O uso da vinculação dinâmica em vez da vinculação estática oferece várias vantagens.  Quando você usa DLLs, você pode economizar espaço de memória e reduzem as trocas.  Quando vários aplicativos podem usar uma única cópia de uma DLL, você pode economizar espaço em disco e fazer o download de largura de banda.  DLLs podem ser implantados e atualizados separadamente, que permite a você fornecer atualizações de software e suporte pós\-mercado sem precisar recriar e enviar todo o seu código.  DLLs são uma maneira conveniente para fornecer recursos específicos da localidade, que podem oferecer suporte a programas de vários idiomas e facilitar a criação de versões internacionais dos seus aplicativos.  
  
 Os tópicos a seguir fornecem informações detalhadas sobre como às DLLs do programa.  
  
## Nesta seção  
 [Passo a passo: criando e usando uma biblioteca de vínculo dinâmico \(C\+\+\)](../build/walkthrough-creating-and-using-a-dynamic-link-library-cpp.md)  
 Descreve como criar e usar uma DLL com o Visual Studio.  
  
 [Diferenças entre aplicativos e DLLs](../build/differences-between-applications-and-dlls.md)  
 Descreve as diferenças fundamentais entre aplicativos e DLLs.  
  
 [Vantagens de usar DLLs](../build/advantages-of-using-dlls.md)  
 Descreve as vantagens da vinculação dinâmica.  
  
 [Tipos de DLLs](../build/kinds-of-dlls.md)  
 Fornece informações sobre os diferentes tipos de DLLs que podem ser compilados.  
  
 [Perguntas frequentes sobre DLLs](../build/dll-frequently-asked-questions.md)  
 Fornece respostas para perguntas frequentes sobre DLLs.  
  
 [Vinculando um executável a uma DLL](../build/linking-an-executable-to-a-dll.md)  
 Descreve a vinculação explícita e implícita a uma DLL.  
  
 [Inicializando uma DLL](../build/initializing-a-dll.md)  
 Fala sobre o código de inicialização da DLL \(como alocação de memória\) que deve ser executado quando a DLL é carregada.  
  
 [Comportamento da biblioteca em tempo de execução](../build/run-time-library-behavior.md)  
 Descreve como a biblioteca em tempo de execução executa a sequência de inicialização da DLL.  
  
 [LoadLibrary e AfxLoadLibrary](../build/loadlibrary-and-afxloadlibrary.md)  
 Discute o uso de**LoadLibrary**e`AfxLoadLibrary`para vincular explicitamente em uma DLL em tempo de execução.  
  
 [GetProcAddress](../build/getprocaddress.md)  
 Descreve o uso de **GetProcAddress** para obter o endereço de uma função exportada na DLL.  
  
 [FreeLibrary e AfxFreeLibrary](../build/freelibrary-and-afxfreelibrary.md)  
 Descreve o uso de **FreeLibrary** e `AfxFreeLibrary` quando o módulo da DLL não é mais necessário.  
  
 [Caminho de pesquisa usado pelo Windows para localizar uma DLL](../build/search-path-used-by-windows-to-locate-a-dll.md)  
 Descreve o caminho de pesquisa que o sistema operacional Windows usa para localizar uma DLL no sistema.  
  
 [Estados de módulo de uma DLL normal vinculada dinamicamente ao MFC](../build/module-states-of-a-regular-dll-dynamically-linked-to-mfc.md)  
 Descreve os estados de módulo de uma DLL normal vinculada dinamicamente ao MFC.  
  
 [DLLs de extensão](../build/extension-dlls-overview.md)  
 Explica as DLLs que normalmente implementam classes reutilizáveis derivadas das classes existentes da biblioteca Microsoft Foundation Class.  
  
 [Criando uma DLL somente de recurso](../build/creating-a-resource-only-dll.md)  
 Descreve uma DLL somente de recurso, que contém apenas recursos, como ícones, bitmaps, cadeias de caracteres e caixas de diálogo.  
  
 [Recursos localizados em aplicativos MFC: DLLs satélite](../build/localized-resources-in-mfc-applications-satellite-dlls.md)  
 Fornece suporte avançado para DLLs satélite, um recurso que ajuda na criação de aplicativos localizados para vários idiomas.  
  
 [Importando e exportando](../build/importing-and-exporting.md)  
 Descreve a importação de símbolos públicos para um aplicativo ou a exportação de funções de uma DLL  
  
 [Tecnologia e DLLs ativas](../build/active-technology-and-dlls.md)  
 Permite que os servidores de objeto a ser implementada dentro de uma DLL.  
  
 [Automação em uma DLL](../build/automation-in-a-dll.md)  
 Descreve o que a opção de automação no assistente de DLL do MFC fornece.  
  
 [Convenções de nomenclatura para DLLs do MFC](../build/naming-conventions-for-mfc-dlls.md)  
 Discute como as DLLs e as bibliotecas incluídas no MFC seguem uma convenção de nomenclatura estruturada.  
  
 [Chamando funções de DLL de aplicativos do Visual Basic](../build/calling-dll-functions-from-visual-basic-applications.md)  
 Descreve como chamar funções de DLL a partir de aplicativos do Visual Basic.  
  
## Seções relacionadas  
 [Usando o MFC como parte de uma DLL](../mfc/tn011-using-mfc-as-part-of-a-dll.md)  
 Descreve DLLs normais, que permitem que você use a biblioteca MFC como parte de uma biblioteca de vínculo dinâmico do Windows.  
  
 [Versão da DLL do MFC](../mfc/tn033-dll-version-of-mfc.md)  
 Descreve como você pode usar as bibliotecas compartilhadas de vínculo dinâmico MFCxx.dll e MFCxxD.dll \(onde x é o número da versão do MFC\) com aplicativos do MFC e DLLs de extensão.  
  
 [\(NOTINBUILD\)Visual C\+\+ Programming Methodologies](http://msdn.microsoft.com/pt-br/0822f806-fa81-4b65-bf0f-1e2921f30c95)  
 Fornece links para tópicos que descrevem informações conceituais sobre as bibliotecas do Visual C\+\+ e tópicos que discutem várias tecnologias e técnicas de codificação.