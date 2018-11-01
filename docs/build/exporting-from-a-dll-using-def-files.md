---
title: Exportando a partir de uma DLL usando arquivos DEF
ms.date: 11/04/2016
helpviewer_keywords:
- def files [C++], exporting from DLLs
- .def files [C++], exporting from DLLs
- exporting DLLs [C++], DEF files
ms.assetid: 9d31eda2-184e-47de-a2ee-a93ebd603f8e
ms.openlocfilehash: e4351d8eca6c6c580430aa8988344bf7f57e0a9f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50553901"
---
# <a name="exporting-from-a-dll-using-def-files"></a>Exportando a partir de uma DLL usando arquivos DEF

Um arquivo de definição de módulo (. def) é um arquivo de texto que contém uma ou mais declarações de módulo que descrevem vários atributos de uma DLL. Se você não estiver usando o **dllexport** palavra-chave para exportar funções de DLL, a DLL exige um arquivo. def.

Um arquivo. def mínimo deve conter as seguintes instruções de definição de módulo:

- A primeira instrução no arquivo deve ser a instrução LIBRARY. Essa declaração identifica o arquivo. def como pertencente a uma DLL. A instrução LIBRARY é seguida pelo nome da DLL. O vinculador coloca esse nome na biblioteca de importação da DLL.

- A declaração EXPORTS lista os nomes e, opcionalmente, os valores ordinais das funções exportadas pela DLL. Atribuir a função de um valor ordinal seguindo o nome da função com um sinal de arroba (@) e um número. Quando você especificar valores ordinais, eles devem ser no intervalo de 1 a N, onde N é o número de funções exportadas pela DLL. Se você quiser exportar funções por ordinal, consulte [exportar funções de uma DLL por Ordinal em vez de por nome](../build/exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md) , bem como neste tópico.

Por exemplo, uma DLL que contém o código para implementar uma árvore de pesquisa binária pode parecer com o seguinte:

```
LIBRARY   BTREE
EXPORTS
   Insert   @1
   Delete   @2
   Member   @3
   Min   @4
```

Se você usar o [Assistente de DLL MFC](../mfc/reference/mfc-dll-wizard.md) para criar uma DLL MFC, o assistente cria um arquivo. def de esqueleto para você e a adiciona automaticamente a seu projeto. Adicione os nomes das funções a serem exportadas para este arquivo. Para DLLs não MFC, você deve criar o arquivo. def por conta própria e adicioná-lo ao seu projeto.

Se você estiver exportando funções em um arquivo do C++, você precisa colocar os nomes decorados no arquivo. def ou definir suas funções exportadas com ligação padrão de C usando extern "C". Se você precisar colocar os nomes decorados no arquivo. def, você pode obtê-los usando o [DUMPBIN](../build/reference/dumpbin-reference.md) ferramenta ou, usando o vinculador [/Map](../build/reference/map-generate-mapfile.md) opção. Observe que os nomes decorados produzidos pelo compilador são específicos de compilador. Se você colocar os nomes decorados produzidos pelo compilador do Visual C++ em um arquivo. def, aplicativos vinculados à DLL também deverão ser compilados usando a mesma versão do Visual C++ para que os nomes decorados no aplicativo de chamada correspondam aos nomes exportados no .de da DLL arquivo de f.

Se você estiver criando um [DLL de extensão](../build/extension-dlls-overview.md), e exportar usando um arquivo. def, coloque o seguinte código no início e no final dos arquivos de cabeçalho que contêm as classes exportadas:

```
#undef AFX_DATA
#define AFX_DATA AFX_EXT_DATA
// <body of your header file>
#undef AFX_DATA
#define AFX_DATA
```

Essas linhas garantem que variáveis MFC usadas internamente ou que são adicionados às suas classes sejam exportadas (ou importados) de sua DLL de extensão do MFC. Por exemplo, ao derivar uma classe usando `DECLARE_DYNAMIC`, a macro se expande para adicionar um `CRuntimeClass` variável de membro para sua classe. Deixando essas quatro linhas pode fazer com que o DLL compile ou vincule incorretamente ou causar um erro quando o aplicativo cliente vincula-se à DLL.

Ao criar a DLL, o vinculador usa o arquivo. def para criar um arquivo de exportação (. Exp) e um arquivo de biblioteca (. lib) de importação. O vinculador, em seguida, usa o arquivo de exportação para criar o arquivo DLL. Executáveis vinculados implicitamente ao link da DLL para a biblioteca de importações quando eles são criados.

Observe que o próprio MFC usa arquivos. def para exportar funções e classes de MFCx0.dll.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando dllexport](../build/exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando AFX_EXT_CLASS](../build/exporting-and-importing-using-afx-ext-class.md)

- [Exportar funções de C++ para uso em executáveis da linguagem C](../build/exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Exportar funções de C para uso em executáveis C ou da linguagem C++](../build/exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Determinar qual método de exportação usar](../build/determining-which-exporting-method-to-use.md)

- [Importar para um aplicativo usando __declspec(dllimport)](../build/importing-into-an-application-using-declspec-dllimport.md)

- [Inicialize um DLL](../build/run-time-library-behavior.md#initializing-a-dll)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [arquivos. def](../build/reference/module-definition-dot-def-files.md)

- [Regras para instruções de definição de módulo](../build/reference/rules-for-module-definition-statements.md)

- [Nomes decorados](../build/reference/decorated-names.md)

- [Importando e exportando funções embutidas](../build/importing-and-exporting-inline-functions.md)

- [Importações mútuas](../build/mutual-imports.md)

## <a name="see-also"></a>Consulte também

[Exportando de uma DLL](../build/exporting-from-a-dll.md)