---
title: Determinando qual método de exportação para uso | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- __declspec(dllexport) keyword [C++]
- exporting DLLs [C++], method comparison
- def files [C++], exporting from DLLs
- .def files [C++], exporting from DLLs
ms.assetid: 66d773ed-935c-45c2-ad03-1a060874b34d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 03c88cee3504d8efef8f9ca19073ed06b66f6aeb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32368753"
---
# <a name="determining-which-exporting-method-to-use"></a>Determinando qual método de exportação usar
Você pode exportar funções em uma das duas maneiras – um arquivo. def ou `__declspec(dllexport)` palavra-chave. Para ajudá-lo a decidir qual modo é melhor para a DLL, considere estas perguntas:  
  
-   Você planeja exportar mais funções mais tarde?  
  
-   É o DLL usado somente por aplicativos que você pode recriar ou ele é usado por aplicativos que não é possível recriar — por exemplo, os aplicativos que são criados por terceiros?  
  
## <a name="pros-and-cons-of-using-def-files"></a>Vantagens e desvantagens do uso de arquivos. def  
 Exportando funções em um. def arquivo lhe dá controle sobre os ordinais de exportação. Quando você adiciona uma função exportada para a DLL, você pode atribuir um valor ordinal superior qualquer outra função exportada. Quando você fizer isso, os aplicativos que usam a vinculação implícita não precisa vincular novamente com a biblioteca de importação que contém a nova função. Isso é muito conveniente, se você estiver criando uma DLL para uso por vários aplicativos, porque você pode adicionar novas funcionalidades e também, certifique-se de que ele continue a funcionar corretamente com os aplicativos que dependam dele já. Por exemplo, as DLLs MFC são criadas usando arquivos. def.  
  
 Outra vantagem de usar um arquivo. def é que você pode usar o `NONAME` atributo para exportar uma função. Isso coloca o ordinal de somente na tabela de exportações na DLL. Para DLLs que tenham um grande número de funções exportadas, usando o `NONAME` atributo pode reduzir o tamanho do arquivo DLL. Para obter informações sobre como escrever uma instrução de definição de módulo, consulte [regras para instruções de definição de módulo](../build/reference/rules-for-module-definition-statements.md). Para obter informações sobre exportação ordinal, consulte [funções de exportação de uma DLL por Ordinal em vez de por nome](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md).  
  
 Uma desvantagem de usar um arquivo. def é se você estiver exportando funções em um arquivo C++, você deverá colocar os nomes decorados em de. def arquivo ou define as funções exportadas usando extern "C" para evitar a decoração de nome que foi feito pelo compilador do Visual C++.  
  
 Se você colocar os nomes decorados no arquivo. def, você pode obtê-las usando o [DUMPBIN](../build/reference/dumpbin-reference.md) ferramenta ou usando o vinculador [/MAPEAR](../build/reference/map-generate-mapfile.md) opção. Os nomes decorados que são produzidos pelo compilador são específicas do compilador; Portanto, se você colocar os nomes decorados que são produzidos pelo compilador para um arquivo. def, os aplicativos com links para a DLL devem também é possível criar usando a mesma versão do compilador para que os nomes decorados do aplicativo de chamada corresponder a exportado nomes i n o arquivo. def da DLL.  
  
## <a name="pros-and-cons-of-using-declspecdllexport"></a>Vantagens e desvantagens do uso de dllexport  
 Usando `__declspec(dllexport)` é conveniente, pois você não precisa se preocupar sobre a manutenção de um arquivo. def e obter os nomes decorados das funções exportadas. No entanto, a utilidade dessa maneira de exportação é limitada pelo número de aplicativos vinculados que você está disposto a reconstrução. Se você recriar o DLL com exportações de novo, você também precisa recompilar os aplicativos, pois os nomes decorados para funções exportadas de C++ podem ser alterado se você usar uma versão diferente do compilador para recriá-lo.  
  
### <a name="what-do-you-want-to-do"></a>O que você deseja fazer?  
  
-   [Exportação de uma DLL usando. Arquivos DEF](../build/exporting-from-a-dll-using-def-files.md)  
  
-   [Exportar de uma DLL usando dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)  
  
-   [Exportar e importar usando AFX_EXT_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)  
  
-   [Exportar funções C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)  
  
-   [Exportar funções C para uso em executáveis C ou linguagem C++](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)  
  
-   [Importar para um aplicativo usando __declspec(dllimport)](../build/importing-into-an-application-using-declspec-dllimport.md)  
  
-   [Inicializar uma DLL](../build/run-time-library-behavior.md#initializing-a-dll)  
  
### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?  
  
-   [Importando e exportando funções embutidas](../build/importing-and-exporting-inline-functions.md)  
  
-   [Importações mútuas](../build/mutual-imports.md)  
  
-   [Nomes decorados](../build/reference/decorated-names.md)  
  
## <a name="see-also"></a>Consulte também  
 [Exportando de uma DLL](../build/exporting-from-a-dll.md)