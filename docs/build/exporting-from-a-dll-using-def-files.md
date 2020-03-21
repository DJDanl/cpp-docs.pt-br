---
title: Exportando a partir de uma DLL usando arquivos DEF
ms.date: 05/06/2019
helpviewer_keywords:
- def files [C++], exporting from DLLs
- .def files [C++], exporting from DLLs
- exporting DLLs [C++], DEF files
ms.assetid: 9d31eda2-184e-47de-a2ee-a93ebd603f8e
ms.openlocfilehash: 6f7d58bcb42edd89527fff41b08a15321722a6cf
ms.sourcegitcommit: 8e285a766523e653aeeb34d412dc6f615ef7b17b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/21/2020
ms.locfileid: "80078517"
---
# <a name="exporting-from-a-dll-using-def-files"></a>Exportando a partir de uma DLL usando arquivos DEF

Uma definição de módulo ou arquivo DEF (*.def) é um arquivo de texto que contém uma ou mais declarações de módulo que descrevem vários atributos de uma DLL. Se você não estiver usando a palavra-chave **__declspec (dllexport)** para exportar as funções da dll, a dll exigirá um arquivo def.

Um arquivo DEF mínimo deve conter as seguintes instruções de definição de módulo:

- A primeira instrução no arquivo deve ser a instrução de biblioteca. Essa instrução identifica o arquivo DEF como pertencente a uma DLL. A instrução de biblioteca é seguida pelo nome da DLL. O vinculador coloca esse nome na biblioteca de importação da DLL.

- A instrução Exports lista os nomes e, opcionalmente, os valores ordinais das funções exportadas pela DLL. Atribua a função um valor ordinal seguindo o nome da função com um sinal de arroba (@) e um número. Quando você especifica valores ordinais, eles devem estar no intervalo de 1 a N, em que N é o número de funções exportadas pela DLL. Se você quiser exportar funções por ordinal, consulte [Exportando funções de uma DLL por ordinal em vez de por nome](exporting-functions-from-a-dll-by-ordinal-rather-than-by-name.md) , bem como este tópico.

Por exemplo, uma DLL que contém o código para implementar uma árvore de pesquisa binária pode ser semelhante ao seguinte:

```
LIBRARY   BTREE
EXPORTS
   Insert   @1
   Delete   @2
   Member   @3
   Min   @4
```

Se você usar o [Assistente de DLL do MFC](../mfc/reference/mfc-dll-wizard.md) para criar uma DLL do MFC, o assistente criará um arquivo de definição de esqueleto para você e o adicionará automaticamente ao seu projeto. Adicione os nomes das funções a serem exportadas para esse arquivo. Para DLLs não MFC, crie o arquivo DEF por conta própria e adicione-o ao seu projeto. Em seguida, vá para **projeto** > **Propriedades** > **vinculador** > **entrada** > **arquivo de definição de módulo** e insira o nome do arquivo def. Repita essa etapa para cada configuração e plataforma, ou faça tudo de uma só vez selecionando **Configuração = todas as configurações**e **plataforma = todas as plataformas**.

Se você estiver exportando funções C++ em um arquivo, precisará posicionar os nomes decorados no arquivo def ou definir suas funções exportadas com vínculo C padrão usando o "C" externo. Se você precisar posicionar os nomes decorados no arquivo DEF, poderá obtê-los usando a ferramenta [DUMPBIN](../build/reference/dumpbin-reference.md) ou usando a opção [/MAP](../build/reference/map-generate-mapfile.md) do vinculador. Observe que os nomes decorados produzidos pelo compilador são específicos do compilador. Se você posicionar os nomes decorados produzidos pelo compilador C++ da Microsoft (MSVC) em um arquivo def, os aplicativos vinculados à sua dll também deverão ser criados usando a mesma versão do MSVC para que os nomes decorados no aplicativo de chamada correspondam aos nomes exportados no arquivo def da dll.

> [!NOTE]
> Uma DLL criada com o Visual Studio 2015 pode ser consumida por aplicativos criados com o Visual Studio 2017 ou com o Visual Studio 2019.

Se você estiver criando uma [dll de extensão](../build/extension-dlls-overview.md)e exportando usando um arquivo def, coloque o seguinte código no início e no final dos arquivos de cabeçalho que contêm as classes exportadas:

```
#undef AFX_DATA
#define AFX_DATA AFX_EXT_DATA
// <body of your header file>
#undef AFX_DATA
#define AFX_DATA
```

Essas linhas garantem que as variáveis do MFC que são usadas internamente ou que sejam adicionadas às suas classes sejam exportadas (ou importadas) de sua DLL de extensão do MFC. Por exemplo, ao derivar uma classe usando `DECLARE_DYNAMIC`, a macro se expande para adicionar uma variável de membro de `CRuntimeClass` à sua classe. Deixar essas quatro linhas pode fazer com que a DLL seja compilada ou vinculada incorretamente ou cause um erro quando o aplicativo cliente for vinculado à DLL.

Ao criar a DLL, o vinculador usa o arquivo DEF para criar um arquivo de exportação (. exp) e um arquivo de biblioteca de importação (. lib). Em seguida, o vinculador usa o arquivo de exportação para criar o arquivo DLL. Executáveis que são vinculados implicitamente ao link da DLL para a biblioteca de importação quando eles são criados.

Observe que o próprio MFC usa arquivos DEF para exportar funções e classes do MFCx0. dll.

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Exportar de uma DLL usando __declspec (dllexport)](exporting-from-a-dll-using-declspec-dllexport.md)

- [Exportar e importar usando o AFX_EXT_CLASS](exporting-and-importing-using-afx-ext-class.md)

- [Exportar C++ funções para uso em executáveis de linguagem C](exporting-cpp-functions-for-use-in-c-language-executables.md)

- [Exportar funções C para uso em executáveis C++de linguagem C ou-](exporting-c-functions-for-use-in-c-or-cpp-language-executables.md)

- [Determinar qual método de exportação usar](determining-which-exporting-method-to-use.md)

- [Importação para um aplicativo usando __declspec(dllimport)](importing-into-an-application-using-declspec-dllimport.md)

- [Inicializar uma DLL](run-time-library-behavior.md#initializing-a-dll)

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

- [arquivos. def](reference/module-definition-dot-def-files.md)

- [Regras para instruções de definição de módulo](reference/rules-for-module-definition-statements.md)

- [Nomes decorados](reference/decorated-names.md)

- [Importação e exportação de funções embutidas](importing-and-exporting-inline-functions.md)

- [Importações mútuas](mutual-imports.md)

## <a name="see-also"></a>Confira também

[Exportando de uma DLL](exporting-from-a-dll.md)
