---
title: Exportando a partir de uma DLL usando arquivos DEF | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- def files [C++], exporting from DLLs
- .def files [C++], exporting from DLLs
- exporting DLLs [C++], DEF files
ms.assetid: 9d31eda2-184e-47de-a2ee-a93ebd603f8e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a870df7ea803813a8403cd807c0f0612873d4576
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32369741"
---
# <a name="exporting-from-a-dll-using-def-files"></a>Exportando a partir de uma DLL usando arquivos DEF
Um arquivo de definição de módulo (. def) é um arquivo de texto que contém uma ou mais declarações de módulo que descrevem vários atributos de uma DLL. Se você não estiver usando o **dllexport** palavra-chave para exportar as funções da DLL, a DLL requer um arquivo. def.  
  
 Um arquivo. def mínima deve conter as seguintes instruções de definição de módulo:  
  
-   A primeira instrução no arquivo deve ser a instrução de biblioteca. Essa instrução identifica o arquivo. def como pertencente a uma DLL. A instrução de biblioteca é seguida do nome da DLL. O vinculador coloca esse nome na biblioteca de importação da DLL.  
  
-   A instrução de exportações lista os nomes e, opcionalmente, os valores ordinais das funções exportadas pela DLL. Atribuir a função de um valor ordinal seguindo o nome da função com um sinal de arroba (@) e um número. Quando você especifica valores ordinais, eles devem ser no intervalo de 1 a N, onde N é o número de funções exportadas pela DLL. Se você quiser exportar funções por ordinal, consulte [funções de exportação de uma DLL por Ordinal em vez de por nome](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md) , bem como neste tópico.  
  
 Por exemplo, uma DLL que contém o código para implementar uma árvore binária pesquisa pode ter a seguinte aparência:  
  
```  
LIBRARY   BTREE  
EXPORTS  
   Insert   @1  
   Delete   @2  
   Member   @3  
   Min   @4  
```  
  
 Se você usar o [Assistente de DLL do MFC](../mfc/reference/mfc-dll-wizard.md) para criar uma DLL MFC, o assistente cria um arquivo. def esqueleto para você e a adiciona automaticamente a seu projeto. Adicione os nomes das funções a serem exportados para o arquivo. Para DLLs não MFC, você deve criar o arquivo. def por conta própria e adicioná-lo ao seu projeto.  
  
 Se você estiver exportando funções em um arquivo C++, você precisa colocar os nomes decorados no arquivo. def ou definir funções com vínculo a C padrão exportadas usando extern "C". Se você precisa colocar os nomes decorados no arquivo. def, você pode obtê-las usando o [DUMPBIN](../build/reference/dumpbin-reference.md) ferramenta ou usando o vinculador [/MAPEAR](../build/reference/map-generate-mapfile.md) opção. Observe que os nomes decorados produzidos pelo compilador são específicas do compilador. Se você colocar os nomes decorados produzidos pelo compilador do Visual C++ em um arquivo. def, aplicativos com links para a DLL devem também ser criados usando a mesma versão do Visual C++, para que os nomes decorados do aplicativo de chamada corresponderem aos nomes exportados no .de da DLL arquivo de f.  
  
 Se você estiver criando um [DLL de extensão](../build/extension-dlls-overview.md), e exportar usando um arquivo. def, coloque o seguinte código no início e término dos seus arquivos de cabeçalho que contém as classes exportadas:  
  
```  
#undef AFX_DATA  
#define AFX_DATA AFX_EXT_DATA  
// <body of your header file>  
#undef AFX_DATA  
#define AFX_DATA  
```  
  
 Essas linhas Certifique-se de que as variáveis que são usados internamente ou que são adicionados às classes do MFC são exportados (ou importados) em sua DLL de extensão do MFC. Por exemplo, ao derivar uma classe usando `DECLARE_DYNAMIC`, expande a macro para adicionar um `CRuntimeClass` variável de membro para sua classe. Omitindo estas quatro linhas pode causar a DLL compilar ou vincular incorretamente ou causar um erro quando o aplicativo cliente tem um link para a DLL.  
  
 Ao criar a DLL, o vinculador usa o arquivo. def para criar um arquivo de exportação (. Exp) e um arquivo de importação de biblioteca (. lib). Em seguida, o vinculador usa o arquivo de exportação para criar o arquivo DLL. Arquivos executáveis que vinculam implicitamente para o link DLL para a biblioteca de importação quando eles são criados.  
  
 Observe que o MFC em si usa arquivos. def para exportar classes e funções do MFCx0.dll.  
  
## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Exportar de uma DLL usando dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportar e importar usando AFX_EXT_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)  
  
-   [Exportar funções C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)  
  
-   [Exportar funções C para uso em executáveis C ou linguagem C++](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)  
  
-   [Determinar qual método de exportação a ser usado](../build/determining-which-exporting-method-to-use.md)  
  
-   [Importar para um aplicativo usando __declspec(dllimport)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Inicializar uma DLL](../build/run-time-library-behavior.md#initializing-a-dll)  
  
## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [arquivos. def](../build/reference/module-definition-dot-def-files.md)  
  
-   [Regras para instruções de definição de módulo](../build/reference/rules-for-module-definition-statements.md)  
  
-   [Nomes decorados](../build/reference/decorated-names.md)  
  
-   [Importando e exportando funções embutidas](../build/importing-and-exporting-inline-functions.md)  
  
-   [Importações mútuas](../build/mutual-imports.md)  
  
## <a name="see-also"></a>Consulte também  
 [Exportando de uma DLL](../build/exporting-from-a-dll.md)