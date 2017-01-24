---
title: "Determinando qual m&#233;todo de associa&#231;&#227;o usar | Microsoft Docs"
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
  - "vinculando explicitamente [C++]"
  - "vinculação implícita [C++]"
ms.assetid: 6b6d3fec-4711-4a30-af5b-354b965ecaec
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Determinando qual m&#233;todo de associa&#231;&#227;o usar
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Há dois tipos de vincular: vincular implícita e vincular explícito.  
  
## Vincular implícito  
 [Vincular implícito](../Topic/Linking%20Implicitly.md) ocorre quando um código de aplicativo chama uma função exportada da DLL.  Quando o código\-fonte do executável de chamada é compilado ou montado, a chamada da função da DLL gerenciar uma referência de função externos no código do objeto.  Para resolver essa referência externa, o aplicativo deve vincular com a biblioteca de arquivo de importação \(.lib\) fornecida pelo fabricante da DLL.  
  
 A biblioteca de importação contém apenas o código para carregar a DLL e implementar chamadas de funções na DLL.  Localizar uma função externa em uma biblioteca do vinculador importação informa que o código para aquela função está em uma DLL.  Para resolver referências externas a DLL, o vinculador adiciona somente as informações para o arquivo executável que diz ao sistema onde encontrar o código da DLL quando o processo é iniciada.  
  
 Quando o sistema inicia um programa que contém referências dinamicamente vinculadas, usará as informações no arquivo executável do programa para localizar as dlls necessários.  Se não puder localizar a DLL, o sistema encerra o processo e exibe uma caixa de diálogo que relata o erro.  Caso contrário, o sistema mapeia os módulos da DLL no espaço de endereço do processo.  
  
 Se algum dos DLL têm uma função de ponto de \(para inicialização e o código de término\), o sistema operacional chamará a função.  Um dos parâmetros passados para a função de ponto de código especifica um que indica que o DLL está anexando ao processo.  Se a função de ponto de não retorna TRUE, o sistema encerra o processo e relata o erro.  
  
 Finalmente, o sistema altera o código executável do processo para fornecer iniciar endereços para as funções da DLL.  
  
 Como o restante do código de um programa, o código da DLL está mapeado no espaço de endereço do processo quando o processo é iniciada e está carregado em memória apenas conforme necessário.  No resultado, os atributos de código de **PRELOAD** e de **LOADONCALL** usados pelos arquivos de .def para controlar a carga em versões anteriores do windows não têm significado.  
  
## Vincular explícito  
 A maioria dos aplicativos usam vincular implícito porque é o método vinculando o mais fácil de usar.  No entanto, há momentos em que [vincular explícito](../build/linking-explicitly.md) é necessário.  Aqui estão algumas razões comuns usar vincular explícito:  
  
-   O aplicativo não souber o nome de uma DLL que necessário carregar até o tempo de execução.  Por exemplo, o aplicativo pode precisar obter o nome da DLL e as funções exportadas de um arquivo de configuração.  
  
-   Um processo que usa vincular implícita é encerrada pelo sistema operacional se a DLL não for localizado na inicialização do processo.  Um processo que usa vincular explícito não é encerrado nessa situação e pode tentar recuperar de erro.  Por exemplo, o processo pode notificar o usuário de erro e fazer com que o usuário especifique outro caminho para a DLL.  
  
-   Um processo que usa vincular implícita é encerrado também se algum de DLL está vinculado para ter uma função de `DllMain` que falhou.  Um processo que usa vincular explícito não é encerrado nessa situação.  
  
-   Um aplicativo que vincula implicitamente em muitos DLL pode ser lento iniciar porque o windows ao carregar todas as dlls quando o aplicativo carrega.  Para melhorar o desempenho de inicialização, um aplicativo pode vincular implicitamente 2 esses DLL necessário imediatamente depois de carregar e aguarda para vincular explicitamente a outros DLL quando forem necessários.  
  
-   Vincular explícito elimina a necessidade de vincular o aplicativo com uma biblioteca de importação.  Se as alterações na DLL fazem com que os ordinais de exportação a alteração, os aplicativos que usam vincular explícito não precisam relink \(supondo que está chamando **GetProcAddress** com um nome de uma função e não com um valor ordinal\), enquanto os aplicativos que usam vincular implícito devem relink para a nova biblioteca de importação.  
  
 Aqui estão dois perigos de vincular explícito para estar ciente de:  
  
-   Se a DLL tem uma função do ponto de entrada de `DllMain` , o sistema operacional chamará a função no contexto de thread que chamou **LoadLibrary**.  A função de ponto de não é chamada se a DLL é anexado no processo devido a uma chamada anterior a **LoadLibrary** sem a chamada correspondente à função de **FreeLibrary** .  Vincular explícito pode causar problemas se a DLL está usando uma função de `DllMain` para executar a inicialização de cada thread de um processo como os threads que existem quando **LoadLibrary** \(ou `AfxLoadLibrary`\) são chamados não serão inicializados.  
  
-   Se uma DLL declara dados de estática\- extensão conforme **\_\_declspec\(thread\)**, pode causar uma falha de proteção se vinculado explicitamente.  Depois que o DLL é carregado com **LoadLibrary**, causará uma falha de proteção sempre que o código referencia esses dados. \(os dados de extensão Estática\- incluem itens estáticos globais e locais.\) Em virtude disso, quando você cria uma DLL, você deve evitar usar armazenamento de thread local ou informar usuários da DLL sobre armadilhas potenciais \(caso que tentam a carga dinâmico\).  
  
## O que você deseja fazer?  
  
-   [Link implicitamente](../Topic/Linking%20Implicitly.md)  
  
-   [Link explicitamente](../build/linking-explicitly.md)  
  
## Que você deseja saber mais?  
  
-   [O caminho de pesquisa usado pelo Windows para localizar uma DLL](../build/search-path-used-by-windows-to-locate-a-dll.md)  
  
-   [LoadLibrary e AfxLoadLibrary](../build/loadlibrary-and-afxloadlibrary.md)  
  
-   [GetProcAddress](../build/getprocaddress.md)  
  
-   [FreeLibrary e AfxFreeLibrary](../build/freelibrary-and-afxfreelibrary.md)  
  
-   [\<caps:sentence id\="tgt47" sentenceid\="8081a197f9413cac12a30b57c2612af5" class\="tgtSentence"\>Usando armazenamento de thread local em uma biblioteca de vínculo dinâmico\) nativa \(Windows SDK\)\<\/caps:sentence\>](http://msdn.microsoft.com/library/windows/desktop/ms686997)  
  
## Consulte também  
 [Vinculando um executável a uma DLL](../build/linking-an-executable-to-a-dll.md)