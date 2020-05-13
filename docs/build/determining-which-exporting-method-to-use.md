---
title: Determinação do método de exportação a ser usado
ms.date: 11/04/2016
helpviewer_keywords:
- __declspec(dllexport) keyword [C++]
- exporting DLLs [C++], method comparison
- def files [C++], exporting from DLLs
- .def files [C++], exporting from DLLs
ms.assetid: 66d773ed-935c-45c2-ad03-1a060874b34d
ms.openlocfilehash: 974c32cef87801599ba0d14fd146e84ad874467f
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62273731"
---
# <a name="determine-which-exporting-method-to-use"></a>Determinação do método de exportação a ser usado

Você pode exportar funções de uma das duas maneiras: um arquivo. def ou a `__declspec(dllexport)` palavra-chave. Para ajudá-lo a decidir qual é a melhor maneira para sua DLL, considere estas perguntas:

- Você planeja exportar mais funções posteriormente?

- Sua DLL é usada somente por aplicativos que você pode recompilar, ou é usado por aplicativos que você não pode recompilar — por exemplo, aplicativos que são criados por terceiros?

## <a name="pros-and-cons-of-using-def-files"></a>Prós e contras do uso de arquivos. def

A exportação de funções em um arquivo. def oferece controle sobre os ordinais de exportação. Ao adicionar uma função exportada à sua DLL, você pode atribuir a ela um valor ordinal maior do que qualquer outra função exportada. Quando você faz isso, os aplicativos que usam vinculação implícita não precisam vincular novamente com a biblioteca de importação que contém a nova função. Isso é muito conveniente se você estiver criando uma DLL para uso por muitos aplicativos, pois você pode adicionar nova funcionalidade e também garantir que ela continue funcionando corretamente com os aplicativos que já dependem dele. Por exemplo, as DLLs do MFC são criadas usando arquivos. def.

Outra vantagem de usar um arquivo. def é que você pode usar o `NONAME` atributo para exportar uma função. Isso coloca apenas o ordinal na tabela Exports na DLL. Para DLLs que têm um grande número de funções exportadas, `NONAME` o uso do atributo pode reduzir o tamanho do arquivo dll. Para obter informações sobre como escrever uma instrução de definição de módulo, consulte [regras para instruções de definição de módulo](reference/rules-for-module-definition-statements.md). Para obter informações sobre a exportação ordinal, consulte [Exportando funções de uma DLL por ordinal em vez de por nome](exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md).

Uma desvantagem de usar um arquivo. def é que, se você estiver exportando funções em um arquivo C++, precisará colocar os nomes decorados no arquivo. def ou definir as funções exportadas usando o "C" externo para evitar a decoração de nome feita pelo compilador MSVC.

Se você colocar os nomes decorados no arquivo. def, poderá obtê-los usando a ferramenta [DUMPBIN](reference/dumpbin-reference.md) ou usando a opção [/MAP](reference/map-generate-mapfile.md) do vinculador. Os nomes decorados que são produzidos pelo compilador são específicos do compilador; Portanto, se você colocar os nomes decorados que são produzidos pelo compilador em um arquivo. def, os aplicativos vinculados à DLL também devem ser criados usando a mesma versão do compilador para que os nomes decorados no aplicativo de chamada correspondam aos nomes exportados no arquivo. def da DLL.

## <a name="pros-and-cons-of-using-__declspecdllexport"></a>Prós e contras do uso de __declspec (dllexport)

Usar `__declspec(dllexport)` o é conveniente porque você não precisa se preocupar em manter um arquivo. def e obter os nomes decorados das funções exportadas. No entanto, a utilidade dessa forma de exportação é limitada pelo número de aplicativos vinculados que você está disposto a recompilar. Se você recriar a DLL com novas exportações, também precisará recompilar os aplicativos porque os nomes decorados das funções C++ exportadas poderão ser alterados se você usar uma versão diferente do compilador para recriá-lo.

### <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando. Arquivos DEF](exporting-from-a-dll-using-def-files.md)

- [Exportar de uma DLL usando __declspec (dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando o AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções C++ para uso em executáveis de linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Exportar funções C para uso em executáveis de linguagem C ou C++](exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

- [Inicializar uma DLL](run-time-library-behavior.md#initializing-a-dll)

### <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [Importação e exportação de funções embutidas](importing-and-exporting-inline-functions.md)

- [Importações mútuas](mutual-imports.md)

- [Nomes decorados](reference/decorated-names.md)

## <a name="see-also"></a>Confira também

[Exportando a partir de uma DLL](exporting-from-a-dll.md)
