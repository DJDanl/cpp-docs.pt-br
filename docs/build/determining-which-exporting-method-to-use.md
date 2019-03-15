---
title: Determinar qual método de exportação usar
ms.date: 11/04/2016
helpviewer_keywords:
- __declspec(dllexport) keyword [C++]
- exporting DLLs [C++], method comparison
- def files [C++], exporting from DLLs
- .def files [C++], exporting from DLLs
ms.assetid: 66d773ed-935c-45c2-ad03-1a060874b34d
ms.openlocfilehash: 974c32cef87801599ba0d14fd146e84ad874467f
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57816289"
---
# <a name="determine-which-exporting-method-to-use"></a>Determinar qual método de exportação usar

Você pode exportar funções em qualquer uma das duas maneiras — um arquivo. def ou o `__declspec(dllexport)` palavra-chave. Para ajudá-lo a decidir qual modo é melhor para sua DLL, considere estas perguntas:

- Você planeja exportar mais funções mais tarde?

- É a sua DLL usado apenas por aplicativos que você pode recompilar ou ele é usado por aplicativos que não é possível recriar — por exemplo, os aplicativos que são criados por terceiros?

## <a name="pros-and-cons-of-using-def-files"></a>Prós e contras do uso de arquivos. def

Exportando funções em um. def arquivo lhe dá controle sobre os ordinais de exportação. Quando você adiciona uma função exportada a sua DLL, você pode atribuir um valor ordinal mais alto que qualquer outra função exportada. Quando você fizer isso, os aplicativos que usam a vinculação implícita é preciso vincular novamente com a biblioteca de importação que contém a nova função. Isso é muito conveniente se você estiver criando uma DLL para uso por vários aplicativos, pois você pode adicionar uma nova funcionalidade e também garantir que ele continue a funcionar corretamente com os aplicativos que dependem dele já. Por exemplo, as DLLs do MFC são criadas por meio de arquivos. def.

Outra vantagem de usar um arquivo. def é que você pode usar o `NONAME` atributo exportar uma função. Isso faz com que apenas o ordinal na tabela de exportações na DLL. Para DLLs que tenham um grande número de funções exportadas, usando o `NONAME` atributo pode reduzir o tamanho do arquivo DLL. Para obter informações sobre como escrever uma instrução de definição de módulo, consulte [regras para instruções de definição de módulo](reference/rules-for-module-definition-statements.md). Para obter informações sobre exportação ordinal, consulte [exportar funções de uma DLL por Ordinal em vez de por nome](exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md).

Uma desvantagem de usar um arquivo. def é que se você estiver exportando funções em um arquivo do C++, você terá que colocar os nomes decorados de. def de arquivo ou define as funções exportadas usando extern "C" para evitar a decoração de nome que é feito pelo compilador MSVC.

Se você colocar os nomes decorados no arquivo. def, você pode obtê-los usando o [DUMPBIN](reference/dumpbin-reference.md) ferramenta ou, usando o vinculador [/Map](reference/map-generate-mapfile.md) opção. Os nomes decorados produzidos pelo compilador são específicos do compilador; Portanto, se você colocar os nomes decorados produzidos pelo compilador em um arquivo. def, os aplicativos que são vinculados ao DLL também deverão ser compilados usando a mesma versão do compilador para que os nomes decorados no aplicativo de chamada corresponderem exportado nomeia i n o arquivo. def da DLL.

## <a name="pros-and-cons-of-using-declspecdllexport"></a>Prós e contras do uso de dllexport

Usando `__declspec(dllexport)` é conveniente porque você não precisa se preocupar sobre como manter um arquivo. def e obter os nomes decorados das funções exportadas. No entanto, a utilidade dessa forma de exportação é limitada pelo número de aplicativos vinculados que você está disposto a recompilar. Se você recriar a DLL com novos exportações, você precisa recompilar os aplicativos, pois os nomes decorados para funções exportadas do C++ pode ser alterado se você usar uma versão diferente do compilador para recriá-lo.

### <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando. Arquivos DEF](exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando dllexport](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções de C++ para uso em executáveis da linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Exportar funções de C para uso em executáveis C ou da linguagem C++](exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Importar para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

- [Inicialize um DLL](run-time-library-behavior.md#initializing-a-dll)

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Importando e exportando funções embutidas](importing-and-exporting-inline-functions.md)

- [Importações mútuas](mutual-imports.md)

- [Nomes decorados](reference/decorated-names.md)

## <a name="see-also"></a>Consulte também

[Exportando de uma DLL](exporting-from-a-dll.md)
