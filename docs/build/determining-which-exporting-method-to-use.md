---
title: "Determinando qual m&#233;todo de exporta&#231;&#227;o usar | Microsoft Docs"
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
  - "Arquivos .def [C++], exportando a partir de DLLs"
  - "Palavra-chave __declspec(dllexport) [C++]"
  - "arquivos def [C++], exportando a partir de DLLs"
  - "exportando DLLs [C++], comparação de métodos"
ms.assetid: 66d773ed-935c-45c2-ad03-1a060874b34d
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Determinando qual m&#233;todo de exporta&#231;&#227;o usar
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode exportar funções em qualquer um de dois modos \- um arquivo .def ou da palavra\-chave de `__declspec(dllexport)` .  Para ajudá\-lo a decidir qual modo é melhor para o DLL, considere essas perguntas:  
  
-   Você planeja exportar posteriormente mais funções?  
  
-   O DLL só é usado por aplicativos que você pode recriar ou, ele é usado por aplicativos que você não pode reconstrução\- para o exemplo, os aplicativos que são criados por terceiros?  
  
## Os profissionais \- e \- em relação ao uso de arquivo .def  
 Exportar funções em um arquivo .def fornece controle sobre os ordinais de exportação.  Quando você adiciona uma função exportada para o DLL, você pode atribuir um valor ordinal mais alto do que a outra função exportada.  Quando você fizer isso, os aplicativos que usam vincular implícita não precisam relink com a biblioteca de importação que contém a nova função.  Isso é muito conveniente se você estiver criando uma DLL para o uso de muitos aplicativos porque você pode adicionar nova funcionalidade e também assegurar que continua funcionando corretamente com os aplicativos já que confiarem nela.  Por exemplo, as dlls de MFC são criados usando arquivos de .def.  
  
 Outra vantagem de usar um arquivo .def é que você pode usar o atributo de `NONAME` para exportar uma função.  Isso coloca somente o ordinal na tabela de exportações na DLL.  Para dlls que têm um número grande de funções exportadas, usar o atributo de `NONAME` pode reduzir o tamanho do arquivo de DLL.  Para obter informações sobre como gravar uma instrução de definição de módulo, consulte [Regras para instruções de definição do módulo](../build/reference/rules-for-module-definition-statements.md).  Para obter informações sobre a exportação ordinal, consulte [Exportando funções a partir de uma DLL por ordinal e não por nome](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md).  
  
 Uma desvantagem de usar um arquivo .def é que se você estiver exportando funções no arquivo criando c, é necessário colocar os nomes decorados no arquivo .def ou definir as funções exportadas usando “C” 2.0 extern para evitar a decoração do nome que é feito pelo compilador do Visual C\+\+.  
  
 Se você colocar os nomes decorados arquivo .def no, você pode obtê\-lo usando a ferramenta de [DUMPBIN](../build/reference/dumpbin-reference.md) ou usando a opção de [\/MAP](../build/reference/map-generate-mapfile.md) do vinculador.  Os nomes decorados que são gerados pelo compilador são completo específicos; em virtude disso, se você colocar os nomes decorados que são gerados pelo compilador em um arquivo .def, os aplicativos que vinculam a DLL também devem ser compilados usando a mesma versão do compilador de forma que os nomes decorados no aplicativo de chamada correspondem aos nomes exportados no arquivo .def da DLL.  
  
## Os profissionais \- e \- contra de usar \_\_declspec \(dllexport\)  
 Usar `__declspec(dllexport)` é conveniente pois você não precisa se preocupar sobre a manutenção de um arquivo .def e a obtenção dos nomes de funções decorados exportadas.  No entanto, a utilidade dessa maneira de exportar é delimitada pelo número de aplicativos vinculados que está disposto a recriação.  Se você recria a DLL com novos exportações, também é necessário recriar os aplicativos porque os nomes decorados para funções exportadas C\+\+ podem ser alteradas se você usar uma versão diferente do compilador para recriar o.  
  
### O que você deseja fazer?  
  
-   [Exportação de uma DLL usando arquivos de .DEF](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportar de uma DLL usando \_\_declspec\(dllexport\)](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportar e importar usando AFX\_EXT\_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)  
  
-   [Exportar funções de C\+\+ para uso em executáveis de linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)  
  
-   [Exportar funções de C para uso em executáveis de linguagem C ou C\+\+](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)  
  
-   [Importar em um aplicativo usando \_\_declspec \(dllimport\)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Inicialize um DLL](../build/initializing-a-dll.md)  
  
### Que você deseja saber mais?  
  
-   [Importando e exportando funções embutidas](../Topic/Importing%20and%20Exporting%20Inline%20Functions.md)  
  
-   [Importações Mútuas](../Topic/Mutual%20Imports.md)  
  
-   [Nomes decorados](../Topic/Decorated%20Names.md)  
  
## Consulte também  
 [Exportando a partir de uma DLL](../build/exporting-from-a-dll.md)