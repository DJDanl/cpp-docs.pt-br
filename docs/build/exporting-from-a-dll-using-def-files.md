---
title: "Exportando a partir de uma DLL usando arquivos DEF | Microsoft Docs"
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
  - "arquivos def [C++], exportando a partir de DLLs"
  - "exportando DLLs [C++], arquivos DEF"
ms.assetid: 9d31eda2-184e-47de-a2ee-a93ebd603f8e
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Exportando a partir de uma DLL usando arquivos DEF
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Arquivo de definição de módulo \(.def\) é um arquivo de texto que contém uma ou mais instruções de módulo que descrevem vários atributos de uma DLL.  Se você não estiver usando a palavra\-chave **\_\_declspec\(dllexport\)** para exportar as funções de DLL, a DLL exige um arquivo .def.  
  
 Um arquivo .def mínimo deve conter as seguintes instruções de definição de módulo:  
  
-   A primeira declaração no arquivo deve ser a instrução LIBRARY.  Essa instrução identifica o arquivo .def como pertencente a uma DLL.  A instrução LIBRARY é seguida pelo nome da DLL.  O vinculador coloca esse nome na biblioteca de importação da DLL.  
  
-   A declaração EXPORTS lista os nomes e, opcionalmente, os valores ordinais das funções exportadas pela DLL.  Atribua à função um valor ordinal seguindo o nome da função com um sinal de arroba \(@\) e um número.  Ao especificar valores ordinais, eles devem estar no intervalo de 1 a N, onde N é o número de funções exportadas pela DLL.  Se você deseja exportar funções por ordinal, consulte [Exportar funções de uma DLL por ordinal em vez de por nome](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md) bem como este tópico.  
  
 Por exemplo, uma DLL que contém o código para implementar uma árvore de busca binária pode parecer com o seguinte:  
  
```  
LIBRARY   BTREE  
EXPORTS  
   Insert   @1  
   Delete   @2  
   Member   @3  
   Min   @4  
```  
  
 Se você usar o [Assistente de DLL MFC](../mfc/reference/mfc-dll-wizard.md) para criar uma DLL MFC, o assistente criará um arquivo .def de esqueleto para você e o adicionará automaticamente ao projeto.  Adicione os nomes das funções a serem exportadas para este arquivo.  Para as DLLs não MFC, você mesmo deve criar o arquivo .def e adicioná\-lo ao seu projeto.  
  
 Se você estiver exportando as funções em um arquivo C\+\+, você precisa colocar os nomes decorados no arquivo .def ou definir suas funções exportadas com ligação padrão de C usando "C" externo.  Se precisar colocar os nomes decorados no arquivo .def, você poderá obtê\-los usando a ferramenta [DUMPBIN](../build/reference/dumpbin-reference.md) ou usando a opção [\/MAP](../build/reference/map-generate-mapfile.md) do vinculador.  Observe que os nomes decorados gerados pelo compilador são específicos de compilador.  Se você colocar os nomes decorados produzidos pelo compilador do Visual C\+\+ em um arquivo .def, os aplicativos vinculados à DLL também deverão ser compilados usando\-se a mesma versão do Visual C\+\+, de forma que os nomes decorados no aplicativo correspondente sejam iguais aos nomes exportados no .def da DLL.  
  
 Se você estiver criando uma [DLL de extensão](../build/extension-dlls-overview.md) e estiver exportando usando um arquivo .def, coloque o seguinte código no início e no fim de seus arquivos de cabeçalho que contêm as classes exportadas:  
  
```  
#undef AFX_DATA  
#define AFX_DATA AFX_EXT_DATA  
// <body of your header file>  
#undef AFX_DATA  
#define AFX_DATA  
```  
  
 Essas linhas garantem que variáveis MFC usadas internamente ou que tenham sido adicionadas às suas classes sejam exportadas \(ou importadas\) de sua DLL de extensão.  Por exemplo, ao derivar uma classe usando `DECLARE_DYNAMIC`, a macro se expande para adicionar uma variável de membro `CRuntimeClass` à sua classe.  Ignorar essas quatro linhas pode fazer com que o DLL compile ou vincule incorretamente, ou cause um erro ao vincular o aplicativo do cliente a DLL.  
  
 Ao criar a DLL, o vinculador usa o arquivo .def para criar um arquivo de exportação \(.exp\) e um arquivo de biblioteca de importação \(.lib\).  O vinculador então usa o arquivo de exportação para criar o arquivo DLL.  Executáveis vinculados implicitamente ao link da DLL para a biblioteca de importações quando eles são compilados.  
  
 Observe que o próprio MFC usa arquivos .def para exportar funções e classes de MFCx0.dll.  
  
## O que você deseja fazer?  
  
-   [Exportar de uma DLL usando \_\_declspec\(dllexport\)](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportar e importar usando AFX\_EXT\_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)  
  
-   [Exportar funções de C\+\+ para uso em executáveis de linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)  
  
-   [Exportar funções de C para uso em executáveis de linguagem C ou C\+\+](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)  
  
-   [Determine o método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Importar em um aplicativo usando \_\_declspec \(dllimport\)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Inicialize um DLL](../build/initializing-a-dll.md)  
  
## Que você deseja saber mais?  
  
-   [arquivos .def](../Topic/Module-Definition%20\(.Def\)%20Files.md)  
  
-   [Regras para instruções de definição de módulo](../build/reference/rules-for-module-definition-statements.md)  
  
-   [Nomes decorados](../Topic/Decorated%20Names.md)  
  
-   [Importando e exportando funções embutidas](../Topic/Importing%20and%20Exporting%20Inline%20Functions.md)  
  
-   [Importações Mútuas](../Topic/Mutual%20Imports.md)  
  
## Consulte também  
 [Exportando a partir de uma DLL](../build/exporting-from-a-dll.md)